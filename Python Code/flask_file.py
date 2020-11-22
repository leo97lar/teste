from flask import Flask, render_template, redirect
from random import shuffle
from call_model import run_model, get_hospital_values
from threading import Thread
from collections import deque

app = Flask(__name__)

running_thread = None
q = deque( maxlen=3 )



def model_wrapper():
    global running_thread
    if not (running_thread and running_thread.is_alive()):
        running_thread = Thread(target=run_model)
        running_thread.start()

@app.route("/")
def render_index():
    html_file = "index.html"
    return render_template(html_file)


@app.route("/fila")
def render_fila():
    html_file = "fila.html"
    fila = list(range(100))
    shuffle(fila)
    return render_template(html_file, fila=fila, run_model=model_wrapper, running_thread=running_thread)


@app.route("/hospital")
def render_hospital():
    html_file = "hospital.html"
    return render_template(html_file)


@app.route("/teste")
def render_teste():
    html_file = "teste.html"
    return render_template(html_file, run_model=model_wrapper, hosp_values=get_hospital_values())

# @app.route("/numero/<int:x>")
# def mostrar_numero(x):
#     return "x = " + str(x)

# return redirect("/outrapagina")


app.run(port=5000, debug=True)
