dll = 'C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/C Code/model.so'
hosp_csv_folder = 'C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/'
test_csv_folder = 'C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs_test/'
last_csv_folder = 'C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs_test/'

#   Variables del model
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
generations = 2 #   Número de gerações

headers = {
    'CP': {'header':True, 'index':None},
    'RO': {'header':True, 'index':None},
    'CPO': {'header':False, 'index':None},
    'CPrO': {'header':False, 'index':None},
    'CR': {'header':False, 'index':None},
    'Data': {'header':True, 'index':None},
    'Dia': {'header':True, 'index':None},
    'DispMExD': {'header':True, 'index':0},
    'MA': {'header':True, 'index':0},
    'MAn': {'header':True, 'index':0},
    'ME': {'header':True, 'index':0},
    'S': {'header':False, 'index':None},
}

keeppriority = False