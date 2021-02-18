from flask import Flask, render_template, redirect, request, jsonify
from random import shuffle
from call_model import run_model, get_hospital_csv_values
from threading import Thread
from global_config import saves_folder, port, main_save, weekdays, c_schedule, c_results, model_config
import pandas as pd
from distutils.dir_util import copy_tree
from shutil import rmtree
import json
import os
import os.path

app = Flask(__name__)
os.environ['PYDEVD_UNBLOCK_THREADS_TIMEOUT'] = '3'
os.environ['PYDEVD_WARN_EVALUATION_TIMEOUT'] = '60'

running_thread = None

hosp_values = None

med_type_to_csv = {
    'especialista': 'ME.csv',
    'assistente': 'MA.csv',
    'anestesista': 'MAn.csv',
}

cama_type_to_csv = {
    'pre': 'CPrO.csv',
    'pos': 'CPO.csv',
    'rep': 'CR.csv',
    'sala': 'S.csv',
}

dados_medico = {}

last_opened = {'with_hosp':'hosp', 'no_hosp':''}

@app.route('/fila')
@app.route('/')
def render_fila():
    html_file = 'fila.html'
    return render_template(html_file, run_model=model_wrapper, running_thread=running_thread)

@app.route('/calendar_details/<int:event_id>')
def calendar_details(event_id):
    with open(saves_folder + main_save + '/details.json', 'r') as f:
        details = json.load(f)[str(event_id)]
    op_id = details['op_id']
    equips = details['equips']
    return render_template("details.html", details=equips, run_model=model_wrapper, running_thread=running_thread, title=op_id, event_id=event_id)

@app.route('/data')
@app.route('/calendar_details/data')
def return_data():
    # start_date = request.args.get('start', '')
    # end_date = request.args.get('end', '')

    with open(saves_folder + main_save + '/events.json', 'r') as input_data:
        return input_data.read()

def move_hosp_files(source, dest):
    try:
        rmtree(saves_folder + dest + '/')
    except:
        pass
    os.mkdir(saves_folder + dest + '/')
    copy_tree(saves_folder + source + '/', saves_folder + dest + '/')

def build_line(index, data, columns):
    data = [{k:v for k,v in data.items() if k in columns}]
    return pd.DataFrame(data, index=[index])

def build_DispMExD_column(data):
    col = map(lambda x: int(data[x]), weekdays)
    return pd.Series(col)

def add_doc(doc_type, doc_data, csv_file):
    med_df = pd.read_csv(csv_file, index_col=0)

    new_line = build_line(index=doc_data['med_id'], data=doc_data, columns=get_header(csv_file))
    med_df = pd.concat([med_df, new_line])

    med_df.to_csv(csv_file)
    if doc_type == 'especialista':
        csv_file = saves_folder + 'test' + '/DispMExD.csv'
        time_df = pd.read_csv(csv_file, index_col=0)

        new_col = build_DispMExD_column(doc_data)
        time_df.insert(len(time_df.columns), doc_data['med_id'], value=new_col)

        time_df.to_csv(csv_file)

def del_doc(doc_type, doc_id, csv_file):
    med_df = pd.read_csv(csv_file, index_col=0)
    med_df = med_df.drop(doc_id)
    med_df.to_csv(csv_file)
    if doc_type == 'especialista':
        csv_file = saves_folder + 'test' + '/DispMExD.csv'
        time_df = pd.read_csv(csv_file, index_col=0)
        time_df = time_df.drop(doc_id, axis=1)
        time_df.to_csv(csv_file)

def add_cama(cama_type, cama_data, csv_file):
    cama_df = pd.read_csv(csv_file, index_col=0)

    columns = get_header(csv_file)
    fill_checkbox(cama_data, columns)

    new_line = build_line(index=cama_data['cama_id'], data=cama_data, columns=columns)
    cama_df = pd.concat([cama_df, new_line])

    cama_df.to_csv(csv_file)

def del_cama(cama_type, cama_id, csv_file):
    cama_df = pd.read_csv(csv_file, index_col=0)
    cama_df = cama_df.drop(cama_id)
    cama_df.to_csv(csv_file)

def get_hospital_values(command=None):
    global hosp_values
    if hosp_values is None or command == 'reset':
        hosp_values = get_hospital_csv_values('test')
    if command == 'last run':
        pass
    return hosp_values

def model_wrapper(save_name):
    global running_thread
    if not (running_thread and running_thread.is_alive()):
        running_thread = Thread(target=run_model, args=[save_name])
        running_thread.start()

def get_header(csv_file):
    return list(pd.read_csv(csv_file, index_col=0).columns)

def get_index(csv_file):
    return list(pd.read_csv(csv_file, index_col=0).index)


@app.route('/hospital')
def render_hospital():
    html_file = 'hospital.html'
    return render_template(html_file, get_hospital_values=get_hospital_values)

@app.route('/comparar', methods=['GET', 'POST'])
def render_comparar():
    html_file = 'comparar.html'
    if request.method == 'GET':
        return render_template(html_file, saves=[], error_message='')

    saves = [request.form.get('save1', False), request.form.get('save2', False)]
    if not all(saves):
        return render_template(html_file, saves=[], error_message='')
    else:
        error_message = ''
        for save in saves:
            if not os.path.isfile(saves_folder + save + '/' + c_schedule):
                error_message += f'A pasta "{save}" não é válida ou o modelo não terminou de rodar.\n'
            if error_message != '':
                return render_template(html_file, saves=[], error_message=error_message)
        save_results = {}
        save_config = {}
        for save in saves:
            with open(saves_folder + save + '/' + c_results) as f:
                save_results[save] = json.load(f)
            with open(saves_folder + save + '/' + model_config) as f:
                save_config[save] = json.load(f)

        return render_template(html_file, saves=saves, result=save_results, config=save_config)


def set_last_opened(new='', no_hosp='', with_hosp='hosp'):
    if new == '':
        last_opened['with_hosp'] = with_hosp
        last_opened['no_hosp'] = no_hosp
    else:
        if new != 'open':
            last_opened['with_hosp'] = new
            if new != 'hosp':
                last_opened['no_hosp'] = new

@app.route('/teste', methods=['GET', 'POST'])
@app.route('/teste/<string:folder>')
def render_teste(folder=None):
    global last_opened
    html_file = 'teste.html'
    if request.method == 'GET':
        if folder is None:
            set_last_opened()
            move_hosp_files('hosp', 'open')
            return redirect('/teste/' + 'open')
        else:
            return render_template(html_file, get_hospital_values=get_hospital_values, last_opened=last_opened, running_thread=running_thread)
    else:
        if 'open' in request.form:
            new_open = request.form['open']
            set_last_opened(new_open)
            move_hosp_files(source=new_open, dest='open')
            return redirect('/teste/' + 'open')
        elif 'save' in request.form:
            new_save = request.form['save']
            set_last_opened(new_save)
            move_hosp_files(source='open', dest=new_save)
            return redirect('/run_model/' + new_save + '/teste')


def ask_info(html_file, csv_file, tipo, med_id=False):
    global dados_medico
    return render_template(html_file, get_hospital_values=get_hospital_values, tipo=tipo, especialidades=get_header(csv_file), dados=dados_medico, med_id=med_id, weekdays=weekdays, last_opened=last_opened)

def fill_checkbox(data, keys):
    for key in keys:
        data[key] = data.get(key, False) == 'on'

@app.route('/novo_medico/<string:page>/<string:tipo>', methods=['GET', 'POST'])
def render_novo_medico(page, tipo):
    global dados_medico
    page_dict = {
        'teste':('novo medico teste.html', 'test'),
        'hospital':('novo medico hospital.html', main_save),
    }
    html_file, csv_type = page_dict[page]
    csv_file = saves_folder + csv_type + '/' + med_type_to_csv[tipo]
    if request.method == 'GET':
        return ask_info(html_file, csv_file, tipo)
    else:
        for k,v in dict(request.form).items():
            dados_medico[k] = v
        if tipo == 'especialista' and not any(map(lambda x: x in dados_medico, weekdays)):
            return ask_info(html_file, csv_file, tipo, dados_medico['med_id'])
        else:
            fill_checkbox(dados_medico, weekdays)
            add_doc(tipo, dados_medico, csv_file)
            dados_medico = dict()
            return redirect('/' + page)

@app.route('/remover_medico/<string:page>/<string:tipo>', methods=["POST","GET"])
def render_remover_medico(page, tipo):
    page_dict = {
        'teste':('remover medico teste.html', 'test'),
        'hospital':('remover medico hospital.html', main_save),
    }
    html_file, csv_type = page_dict[page]
    csv_file = saves_folder + csv_type + '/' + med_type_to_csv[tipo]
    if request.method == "GET":
        return render_template(html_file, get_hospital_values=get_hospital_values, tipo=tipo, medicos=get_index(csv_file), last_opened=last_opened)
    else:
        del_doc(tipo, request.form['medicos'], csv_file)
        return redirect('/' + page)

@app.route('/nova_cama/<string:page>/<string:tipo>', methods=['GET', 'POST'])
def render_nova_cama(page, tipo):
    page_dict = {
        'teste':('nova cama teste.html', 'test'),
        'hospital':('nova cama hospital.html', main_save),
    }
    html_file, csv_type = page_dict[page]
    csv_file = saves_folder + csv_type + '/' + cama_type_to_csv[tipo]
    if request.method == 'GET':
        return render_template(html_file, get_hospital_values=get_hospital_values, tipo=tipo, especialidades=get_header(csv_file))
    else:
        dados_cama = dict(request.form)
        add_cama(tipo, dados_cama, csv_file)
        return redirect('/' + page)

@app.route('/remover_cama/<string:page>/<string:tipo>', methods=["POST","GET"])
def render_remover_cama(page, tipo):
    page_dict = {
        'teste':('remover cama teste.html', 'test'),
        'hospital':('remover cama hospital.html', main_save),
    }
    html_file, csv_type = page_dict[page]
    csv_file = saves_folder + csv_type + '/' + cama_type_to_csv[tipo]
    if request.method == "GET":
        return render_template(html_file, get_hospital_values=get_hospital_values, tipo=tipo, camas=get_index(csv_file))
    else:
        del_cama(tipo, request.form['camas'], csv_file)
        return redirect('/' + page)

@app.route('/run_model/<string:page>')
@app.route('/run_model/<string:page>/<string:redirect_page>')
def render_run_model(page, redirect_page=None):
    save_dict = {
    }
    redirect_dict = {
        main_save: 'fila'
    }
    save_name = save_dict.get(page, page)
    redirect_page = redirect_page or redirect_dict.get(page, page)

    if os.path.isfile(saves_folder + save_name + '/' + c_schedule):
        os.remove(saves_folder + save_name + '/' + c_schedule)

    model_wrapper(save_name)
    return redirect('/' + redirect_page)

app.run(port=port, debug=True)
