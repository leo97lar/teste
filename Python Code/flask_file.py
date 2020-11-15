from flask import Flask, render_template, redirect
from random import shuffle

app = Flask(__name__)

@app.route("/")
def render_index():
    html_file = "index.html"
    # html_path = "./templates/"
    # with open(html_path + html_file, 'r') as f:
    #     html_str = f.read()
    # return html_str
    return render_template(html_file)

@app.route("/fila")
def render_fila():
    html_file = "fila.html"
    fila = list(range(100))
    shuffle(fila)
    fila_html = '<p>'
    fila_html += '</p>\n\t\t\t\t<p>'.join(map(str,fila))
    fila_html += '</p>'
    #<p>{{teste}}</p>
    # html_path = "./templates/"
    # with open(html_path + html_file, 'r') as f:
    #     html_str = f.read()
    # return html_str
    return render_template(html_file, fila=fila)

@app.route("/hospital")
def render_hospital():
    html_file = "hospital.html"
    # html_path = "./templates/"
    # with open(html_path + html_file, 'r') as f:
    #     html_str = f.read()
    # return html_str
    return render_template(html_file)


@app.route("/teste")
def render_teste():
    html_file = "teste.html"
    # html_path = "./templates/"
    # with open(html_path + html_file, 'r') as f:
    #     html_str = f.read()
    # return html_str
    return render_template(html_file)

# @app.route("/numero/<int:x>")
# def mostrar_numero(x):
#     return "x = " + str(x)

# return redirect("/outrapagina")

# return render_template("templates\index.html")

# with open(html, 'r') as f:
#     print(f.read())

app.run(port=5000, debug=True)