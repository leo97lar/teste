#%%generating cmd command
# from glob import glob

# l = glob('C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/C Code/*.c')
# for a in l:
#     print(a[64:])

# gcc -shared -o model.so aevSPLap.c BDCreator_func.c casorandom.c cc.c combineVectorElements.c CreaPoQunniforme.c Edade.c eml_rand.c eml_rand_mcg16807_stateful.c eml_rand_mt19937ar_stateful.c eml_rand_shr3cong_stateful.c favalia.c funcionCPrO.c funcionDia.c getTime.c main.c main_UCI_func.c mean.c model_data.c model_emxAPI.c model_emxutil.c model_initialize.c model_rtwutil.c model_terminate.c nullAssignment.c obsIQ.c obsIQini.c rand.c randi.c randperm.c rdivide_helper.c rem.c repmat.c sch.c sort1.c sortIdx.c std.c sum.c tic.c timeKeeper.c toc.c
#%% Load model
import pandas as pd
from ctypes import CDLL, c_void_p, c_int, c_double, c_uint8, POINTER, byref
from time import time
from config import dll, csv_folder, k0, k1, k2, k3, numIQ, numIC, taxC, taxE, taxEQ, py_ProbXEst, genToWidth, generations, keeppriority

inicio = time()

model = CDLL(dll)

model.emxCreate_int32_T.restype = c_void_p
model.emxCreate_real_T.restype = c_void_p
model.int_array_to_emxArray.argtypes = [c_void_p, c_void_p, c_int]
model.real_array_to_emxArray.argtypes = [c_void_p, c_void_p, c_int]
model.emxDestroyArray_int32_T.argtypes = [c_void_p]
model.emxDestroyArray_real_T.argtypes = [c_void_p]
model.main_UCI_func.restype = POINTER(c_int)
model.main_UCI_func.argtypes = [
    c_void_p, c_void_p, c_void_p, c_void_p, c_void_p, c_void_p, c_void_p, c_void_p, c_void_p, c_void_p, c_void_p, c_void_p,
    c_int, c_int, c_int, c_int, c_int, c_int, c_int,
    c_int, c_int, c_int, c_int, c_double, c_double, c_double, c_double,
    c_int, c_int, c_double, c_double, c_double, c_void_p, c_int,
    c_int, c_uint8,
]

#%% Load CSV


def read_c_csv(filepath, header):
    df = pd.read_csv(filepath, header=None, skiprows=int(header))
    flat = df.values.flatten()
    arr = (c_int * df.size)(*flat)

    c_mat = model.emxCreate_int32_T(df.shape[0], df.shape[1])

    model.int_array_to_emxArray(arr, c_mat, df.size)

    return c_mat, df.shape


#   Initialize the application.
#   You do not need to do this more than one time.
model.model_initialize()

files = [
    ('CP', False), ('RO', False), ('CPO', False), ('CPrO', False),
    ('CR', False), ('Data', False), ('Dia', False), ('DispMExD', False),
    ('MA', False), ('MAn', False), ('ME', False), ('S', False)
]
csvs = {}

for filename, header in files:
    data, shape = read_c_csv(csv_folder + filename + ".csv", header=header)
    csvs[filename] = {'data': data, 'shape': shape}

#%% Inicializar Variáveis

#   Variables de Interes

TipoOp = csvs['RO']['shape'][0]  # Tipos de operaciones
NumEsp = csvs['ME']['shape'][1]  # Numero de Especialidades
NumTOp = csvs['CP']['shape'][0]  # Numero Total de Operaciones

#   Recursos materiales
NumSalOp = csvs['S']['shape'][0]  # Numero de Salones de operaciones
NumCPO = csvs['CPO']['shape'][0]  # Numero de camas Post - Operatorias
NumCPrO = csvs['CPrO']['shape'][0]  # Numero de camas Pre - Operatorias
NumCR = csvs['CR']['shape'][0]  # Numero de camas Recuperacion

NumMedEsp = csvs['ME']['shape'][0]  # Numero de Medicos Especialistas
NumEspxE = int(NumMedEsp/NumEsp)  # Numero de Especialistas por Especialidad
NumAsist = csvs['MA']['shape'][0]  # Numero de Medico Asistentes
NumAnest = csvs['MAn']['shape'][0]  # Numero de Anestesistas


ProbXEst = model.emxCreate_real_T(5, 1)

c_ProbXEst = (c_double * len(py_ProbXEst))(*py_ProbXEst)
model.real_array_to_emxArray(c_ProbXEst, ProbXEst, len(py_ProbXEst))


#%% Rodar Modelo

# 	/* Call the entry-point 'main_UCI_func'. */
c_queue = model.main_UCI_func(csvs['CP']['data'], csvs['RO']['data'], csvs['CPO']['data'], csvs['CPrO']['data'], csvs['CR']['data'], csvs['Data']['data'], csvs['Dia']['data'], csvs['DispMExD']['data'], csvs['MA']['data'], csvs['MAn']['data'], csvs['ME']['data'], csvs['S']['data'],
                              TipoOp, NumEsp, NumTOp, NumSalOp, NumCPO, NumCPrO, NumCR,
                              NumMedEsp, NumEspxE, NumAsist, NumAnest, k0, k1, k2, k3,
                              numIQ, numIC, taxC, taxE, taxEQ, ProbXEst, genToWidth,
                              generations, keeppriority)

#%% Testar resultado
print('rodou: ' + str(c_queue))
a = time()
queue = [c_queue[i] for i in range(NumTOp)]

print('conversão: ' + str(time()-a) + "\n" + str(queue))

#%%Terminate model

model.emxDestroyArray_int32_T(csvs['S'])
model.emxDestroyArray_int32_T(csvs['ME'])
model.emxDestroyArray_int32_T(csvs['MAn'])
model.emxDestroyArray_int32_T(csvs['MA'])
model.emxDestroyArray_int32_T(csvs['DispMExD'])
model.emxDestroyArray_int32_T(csvs['Dia'])
model.emxDestroyArray_int32_T(csvs['Data'])
model.emxDestroyArray_int32_T(csvs['CR'])
model.emxDestroyArray_int32_T(csvs['CPrO'])
model.emxDestroyArray_int32_T(csvs['CPO'])
model.emxDestroyArray_int32_T(csvs['RO'])
model.emxDestroyArray_int32_T(csvs['CP'])
model.emxDestroyArray_int32_T(c_queue)

model.emxDestroyArray_real_T(ProbXEst)

model.model_terminate()

print('Tempo total: ' + str(time() - inicio) + ' segundos')
