dll = 'C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/C Code/model.so'
csv_folder = 'C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/'

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

keeppriority = False