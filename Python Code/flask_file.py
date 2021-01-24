from flask import Flask, render_template, redirect, request, jsonify
from random import shuffle
from call_model import run_model, get_hospital_csv_values
from threading import Thread
from collections import deque
from config import hosp_csv_folder, test_csv_folder, last_csv_folder
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

@app.route('/calendar')
def calendar():
    return render_template("fila.html")


@app.route('/data')
def return_data():
    start_date = request.args.get('start', '')
    end_date = request.args.get('end', '')

    with open(hosp_csv_folder + "events.json", "r") as input_data:
        return input_data.read()

def move_hosp_files(source, dest):
    hosp_path = {
        'last':last_csv_folder,
        'hosp':hosp_csv_folder,
        'test':test_csv_folder,
    }
    rmtree(hosp_path[dest])
    copy_tree(hosp_path[source], hosp_path[dest])


def del_doc(doc_type, doc_id):
    csv_file = test_csv_folder + med_type_to_csv[doc_type]
    med_df = pd.read_csv(csv_file, index_col=0)
    med_df = med_df.drop(doc_id)
    med_df.to_csv(csv_file)
    if doc_type == 'especialista':
        csv_file = test_csv_folder + 'DispMExD.csv'
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
        hosp_values = get_hospital_csv_values()
    if command == 'last run':
        pass
    return hosp_values


def model_wrapper():
    global running_thread
    if not (running_thread and running_thread.is_alive()):
        running_thread = Thread(target=run_model)
        running_thread.start()

def get_header(csv_file):
    return list(pd.read_csv(csv_file, index_col=0).columns)

def get_index(csv_file):
    return list(pd.read_csv(csv_file, index_col=0).index)


def run_test_model():
    model_wrapper()


@app.route('/')
def render_index():
    html_file = 'index.html'
    return render_template(html_file)


@app.route('/fila')
def render_fila():
    html_file = 'fila.html'
    fila = list(range(100))
    shuffle(fila)
    return render_template(html_file, fila=fila, run_model=model_wrapper, running_thread=running_thread)


@app.route('/hospital')
def render_hospital():
    html_file = 'hospital.html'
    return render_template(html_file)


@app.route('/teste')
def render_teste():
    html_file = 'teste.html'
    return render_template(html_file, get_hospital_values=get_hospital_values)


@app.route('/novo_medico/<string:tipo>')
def render_novo_medico(tipo):
    html_file = 'novo medico.html'
    csv_file = test_csv_folder + med_type_to_csv[tipo]
    return render_template(html_file, get_hospital_values=get_hospital_values, tipo=tipo, especialidades=get_header(csv_file))


@app.route('/remover_medico/<string:tipo>', methods=["POST","GET"])
def render_remover_medico(tipo):
    html_file = 'remover medico.html'
    csv_file = test_csv_folder + med_type_to_csv[tipo]
    if request.method == "GET":
        return render_template(html_file, get_hospital_values=get_hospital_values, tipo=tipo, medicos=get_index(csv_file))
    else:
        del_doc(tipo, request.form['medicos'])
        return redirect('/teste')

@app.route('/run_model/<string:page>')
def render_run_model(page):
    run_model()
    return redirect('/' + page)


app.run(port=5000, debug=True)
