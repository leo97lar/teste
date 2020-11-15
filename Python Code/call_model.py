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
model.main_UCI_func.argtypes = [
    c_void_p, c_void_p, c_void_p, c_void_p, c_void_p, c_void_p, c_void_p, c_void_p, c_void_p, c_void_p, c_void_p, c_void_p, 
    c_int, c_int, c_int, c_int, c_int, c_int, c_int, 
    c_int, c_int, c_int, c_int, c_double, c_double, c_double, c_double, 
    c_int, c_int, c_double, c_double, c_double, c_void_p, c_int, 
    c_int, c_uint8,
]

#%% Load CSV

def read_c_csv(filepath):
    df = pd.read_csv(filepath, header=None)
    flat = df.values.flatten()
    arr = (c_int * df.size)(*flat)

    c_mat = model.emxCreate_int32_T(df.shape[0], df.shape[1])

    model.int_array_to_emxArray(arr, c_mat, df.size)

    return c_mat, df.shape

#   Initialize the application.
#   You do not need to do this more than one time.
model.model_initialize()

csv_folder = 'C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/'

CP, CP_shape = read_c_csv(csv_folder + "CP.csv")
RO, RO_shape = read_c_csv(csv_folder + "RO.csv")
CPO, CPO_shape = read_c_csv(csv_folder + "CPO.csv")
CPrO, CPrO_shape = read_c_csv(csv_folder + "CPrO.csv")
CR, CR_shape = read_c_csv(csv_folder + "CR.csv")
Data, _ = read_c_csv(csv_folder + "Data.csv")
Dia, _ = read_c_csv(csv_folder + "Dia.csv")
DispMExD, _ = read_c_csv(csv_folder + "DispMExD.csv")
MA, MA_shape = read_c_csv(csv_folder + "MA.csv")
MAn, MAn_shape = read_c_csv(csv_folder + "MAn.csv")
ME, ME_shape = read_c_csv(csv_folder + "ME.csv")
S, S_shape = read_c_csv(csv_folder + "S.csv")

#%% Inicializar Variáveis

#   Variables de Interes

TipoOp = RO_shape[0] #  Tipos de operaciones
NumEsp = ME_shape[1] #  Numero de Especialidades
NumTOp = CP_shape[0] #  Numero Total de Operaciones

#   Recursos materiales
NumSalOp = S_shape[0] #     Numero de Salones de operaciones
NumCPO = CPO_shape[0] #     Numero de camas Post - Operatorias
NumCPrO = CPrO_shape[0] #   Numero de camas Pre - Operatorias
NumCR = CR_shape[0] #       Numero de camas Recuperacion

NumMedEsp = ME_shape[0] #           Numero de Medicos Especialistas
NumEspxE = int(NumMedEsp/NumEsp) #  Numero de Especialistas por Especialidad
NumAsist = MA_shape[0] #            Numero de Medico Asistentes
NumAnest = MAn_shape[0] #           Numero de Anestesistas

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

ProbXEst = model.emxCreate_real_T(5, 1)
data = [10.0, 20.0, 40.0, 20.0, 10.0]
c_data = (c_double * len(data))(*data)
model.real_array_to_emxArray(c_data, ProbXEst, len(data))

genToWidth = 5 #    Número de gerações de espera antes de reduzir a largura dos indivíduos quânticos
generations = 2 #   Número de gerações

keeppriority = False

#%% Rodar Modelo

# 	/* Call the entry-point 'main_UCI_func'. */
c_queue = model.main_UCI_func(csvs['CP']['data'], csvs['RO']['data'], csvs['CPO']['data'], csvs['CPrO']['data'], csvs['CR']['data'], csvs['Data']['data'], csvs['Dia']['data'], csvs['DispMExD']['data'], csvs['MA']['data'], csvs['MAn']['data'], csvs['ME']['data'], csvs['S']['data'],
    TipoOp, NumEsp, NumTOp, NumSalOp, NumCPO, NumCPrO, NumCR,
    NumMedEsp, NumEspxE, NumAsist, NumAnest, k0, k1, k2, k3,
    numIQ, numIC, taxC, taxE, taxEQ, ProbXEst, genToWidth,
    generations, keeppriority)

#%% Terminate model

print('rodou: ' + str(aux))

model.emxDestroyArray_int32_T(S)
model.emxDestroyArray_int32_T(ME)
model.emxDestroyArray_int32_T(MAn)
model.emxDestroyArray_int32_T(MA)
model.emxDestroyArray_int32_T(DispMExD)
model.emxDestroyArray_int32_T(Dia)
model.emxDestroyArray_int32_T(Data)
model.emxDestroyArray_int32_T(CR)
model.emxDestroyArray_int32_T(CPrO)
model.emxDestroyArray_int32_T(CPO)
model.emxDestroyArray_int32_T(RO)
model.emxDestroyArray_int32_T(CP)

model.emxDestroyArray_real_T(ProbXEst)

model.model_terminate()

print('Tempo total: ' + str(time() - inicio) + ' segundos')
