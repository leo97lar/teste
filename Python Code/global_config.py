dll = 'C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/C Code/model.so'

saves_folder = 'C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/saves/'

main_save = 'hosp'

weekdays = ['Seg', 'Ter', 'Qua', 'Qui', 'Sex', 'Sab']

schedule_csv = 'schedule.csv'

# Variaveis definidas em sch.c
c_schedule = 'c_schedule.csv'
c_results = 'results.json'

#   Variaveis do modelo, onde k1>k2 e k2>k3
k0 = 0
k1 = 0
k2 = 0
k3 = 0

numIQ = 5 #     Numero de individuos cuanticos.
numIC = 20 #    Numero de individuos clasicos.
taxC = 0.9 #    Tasa de cruzamiento
taxE = 50 #     Tasa de elitismo[%]
taxEQ = 10

py_ProbXEst = [10.0, 20.0, 40.0, 20.0, 10.0]

genToWidth = 5 #    Número de gerações de espera antes de reduzir a largura dos indivíduos quânticos
generations = 50 #   Número de gerações

csv_index = {
    'CP': None,
    'RO': None,
    'CPO': 0,
    'CPrO': 0,
    'CR': 0,
    'Data': None,
    'Dia': None,
    'DispMExD': 0,
    'MA': 0,
    'MAn': 0,
    'ME': 0,
    'S': 0,
}

keeppriority = False

port = 5000
url = 'http://127.0.0.1:' + str(port)