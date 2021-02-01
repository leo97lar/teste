from flask import Flask, render_template, redirect, request, jsonify
from random import shuffle
from call_model import run_model, get_hospital_csv_values
from threading import Thread
from collections import deque
from config import get_csv_folder
import pandas as pd
from distutils.dir_util import copy_tree
from shutil import rmtree
import json

app = Flask(__name__)

running_thread = None
q = deque( maxlen=3 )

hosp_values = None

med_type_to_csv = {
    'especialista': 'ME.csv',
    'assistente': 'MA.csv',
    'anestesista': 'MAn.csv',
}

dados_medico = {}

@app.route('/fila')
def render_fila():
    html_file = 'fila.html'
    return render_template(html_file, run_model=model_wrapper, running_thread=running_thread)

@app.route('/calendar_details/<int:event_id>')
def calendar_details(event_id):
    with open(get_csv_folder('hosp') + 'details.json', 'r') as f:
        details = json.load(f)[str(event_id)]
    op_id = details['op_id']
    equips = details['equips']
    return render_template("details.html", details=equips, run_model=model_wrapper, running_thread=running_thread, title=op_id, event_id=event_id)


@app.route('/data')
@app.route('/calendar_details/data')
def return_data():
    # start_date = request.args.get('start', '')
    # end_date = request.args.get('end', '')

    with open(get_csv_folder('hosp') + "events.json", "r") as input_data:
        return input_data.read()

def move_hosp_files(source, dest):
    rmtree(get_csv_folder(dest))
    copy_tree(get_csv_folder(source), get_csv_folder(dest))

def build_line(index, data, columns):
    data = [{k:v for k,v in data.items() if k in columns}]
    return pd.DataFrame(data, index=[index])

def build_DispMExD_column(data):
    return pd.Series([data['Seg'], data['Ter'], data['Qua'], data['Qui'], data['Sex'], data['Sab']])

def add_doc(doc_type, doc_data):
    csv_file = get_csv_folder('test') + med_type_to_csv[doc_type]
    med_df = pd.read_csv(csv_file, index_col=0)

    new_line = build_line(index=doc_data['med_id'], data=doc_data, columns=get_header(csv_file))
    med_df = pd.concat([med_df, new_line])

    med_df.to_csv(csv_file)
    if doc_type == 'especialista':
        csv_file = get_csv_folder('test') + 'DispMExD.csv'
        time_df = pd.read_csv(csv_file, index_col=0)

        new_col = build_DispMExD_column(doc_data)
        time_df = time_df.insert(len(time_df.columns), doc_data['med_id'], value=new_col)

        time_df.to_csv(csv_file)

def del_doc(doc_type, doc_id):
    csv_file = get_csv_folder('test') + med_type_to_csv[doc_type]
    med_df = pd.read_csv(csv_file, index_col=0)
    med_df = med_df.drop(doc_id)
    med_df.to_csv(csv_file)
    if doc_type == 'especialista':
        csv_file = get_csv_folder('test') + 'DispMExD.csv'
        time_df = pd.read_csv(csv_file, index_col=0)
        time_df = time_df.drop(doc_id, axis=1)
        time_df.to_csv(csv_file)

def button_click():
    pass

@app.route('/set_hospital/<string:key>/<string:change>')
def set_hospital_value(key, change):
    global hosp_values
    if hosp_values is None:
        return redirect('/teste')
    if  key == 'all':
        get_hospital_values(change)
    if change == '+':
        hosp_values[key] = hosp_values[key] + 1
    elif change == '-':
        hosp_values[key] = hosp_values[key] - 1
    else:
        hosp_values[key] = hosp_values[key]
        pass
    return redirect('/teste')


def get_hospital_values(command=None):
    global hosp_values
    if hosp_values is None or command == 'reset':
        hosp_values = get_hospital_csv_values('test')
    if command == 'last run':
        pass
    return hosp_values


def model_wrapper(folder_type):
    global running_thread
    if not (running_thread and running_thread.is_alive()):
        running_thread = Thread(target=run_model, args=[folder_type])
        running_thread.start()

def get_header(csv_file):
    return list(pd.read_csv(csv_file, index_col=0).columns)

def get_index(csv_file):
    return list(pd.read_csv(csv_file, index_col=0).index)


@app.route('/')
def render_index():
    html_file = 'index.html'
    return render_template(html_file)


@app.route('/hospital')
def render_hospital():
    html_file = 'hospital.html'
    return render_template(html_file)


@app.route('/teste')
def render_teste():
    html_file = 'teste.html'
    return render_template(html_file, get_hospital_values=get_hospital_values)

@app.route('/alterar_dados_medico/<string:dados_json>/<string:page>')
def alterar_dados_medico(dados_json, page):
    global dados_medico
    dados_medico = json.loads(dados_json)
    return redirect('/' + page)

def ask_info(tipo, med_id=False):
    global dados_medico
    html_file = 'novo medico.html'
    csv_file = get_csv_folder('test') + med_type_to_csv[tipo]
    return render_template(html_file, get_hospital_values=get_hospital_values, tipo=tipo, especialidades=get_header(csv_file), dados=dados_medico, med_id=med_id)

# @app.route('/novo_medico/<string:tipo>/<string:dados>')
@app.route('/novo_medico/<string:tipo>', methods=['GET', 'POST'])
def render_novo_medico(tipo, dados=None):
    global dados_medico
    if request.method == 'GET':
        return ask_info(tipo)
    for k,v in dict(request.form).items():
        dados_medico[k] = v
    if tipo == 'especialista' and 'seg' not in dados_medico:
        return ask_info(tipo, dados_medico['med_id'])
    else:
        add_doc(tipo, dados_medico)
        dados_medico = dict()
        return redirect('/teste')



@app.route('/remover_medico/<string:tipo>', methods=["POST","GET"])
def render_remover_medico(tipo):
    html_file = 'remover medico.html'
    csv_file = get_csv_folder('test') + med_type_to_csv[tipo]
    if request.method == "GET":
        return render_template(html_file, get_hospital_values=get_hospital_values, tipo=tipo, medicos=get_index(csv_file))
    else:
        del_doc(tipo, request.form['medicos'])
        return redirect('/teste')

@app.route('/run_model/<string:page>')
def render_run_model(page):
    folder_type = {
        'fila':'hosp',
    }
    redirect_page = {

    }
    model_wrapper(folder_type[page])
    return redirect('/' + redirect_page.get(page, page))


app.run(port=5000, debug=True)
