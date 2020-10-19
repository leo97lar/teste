#%%generating cmd command
# from glob import glob

# l = glob('C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/C Code/*.c')
# for a in l:
#     print(a[64:])

# gcc -shared -o model.so aevSPLap.c BDCreator_func.c casorandom.c cc.c combineVectorElements.c CreaPoQunniforme.c Edade.c eml_rand.c eml_rand_mcg16807_stateful.c eml_rand_mt19937ar_stateful.c eml_rand_shr3cong_stateful.c favalia.c funcionCPrO.c funcionDia.c getTime.c main.c main_UCI_func.c mean.c model_data.c model_emxAPI.c model_emxutil.c model_initialize.c model_rtwutil.c model_terminate.c nullAssignment.c obsIQ.c obsIQini.c rand.c randi.c randperm.c rdivide_helper.c rem.c repmat.c sch.c sort1.c sortIdx.c std.c sum.c tic.c timeKeeper.c toc.c
#%%
from ctypes import CDLL, c_void_p, c_int, c_double, c_uint8, byref
from time import time

inicio = time()

dll = 'C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/C Code/teste.so'

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


#%%
import pandas as pd
# 	emxArray_int32_T* CP, * RO, * CPO, * CPrO, * CR, * Data, * Dia, * DispMExD, * MA, * MAn, * ME, * S;
# 	emxArray_real_T* ProbXEst;
# 	boolean_T keeppriority;
# 	int TipoOp, NumEsp, NumTOp, NumSalOp, NumCPO, NumCPrO, NumCR, NumMedEsp, NumEspxE, NumAsist, NumAnest, numIQ, numIC, genToWidth, generations;
# 	double k0, k1, k2, k3, taxC, taxE, taxEQ;

# 	/* Initialize the application.
# 	   You do not need to do this more than one time. */
# 	model_initialize();
model.model_initialize()

def read_c_csv(filepath):
    df = pd.read_csv(filepath, header=None)
    flat = df.values.flatten()
    arr = (c_int * df.size)(*flat)

    c_mat = model.emxCreate_int32_T(df.shape[0], df.shape[1])

    model.int_array_to_emxArray(arr, c_mat, df.size)

    return c_mat, df.shape

# 	CP = read_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/CP.csv");
CP, CP_shape = read_c_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/CP.csv")
# 	RO = read_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/RO.csv");
RO, RO_shape = read_c_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/RO.csv")
# 	CPO = read_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/CPO.csv");
CPO, CPO_shape = read_c_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/CPO.csv")
# 	CPrO = read_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/CPrO.csv");
CPrO, CPrO_shape = read_c_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/CPrO.csv")
# 	CR = read_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/CR.csv");
CR, CR_shape = read_c_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/CR.csv")
# 	Data = read_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/Data.csv");
Data, _ = read_c_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/Data.csv")
# 	Dia = read_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/Dia.csv");
Dia, _ = read_c_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/Dia.csv")
# 	DispMExD = read_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/DispMExD.csv");
DispMExD, _ = read_c_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/DispMExD.csv")
# 	MA = read_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/MA.csv");
MA, MA_shape = read_c_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/MA.csv")
# 	MAn = read_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/MAn.csv");
MAn, MAn_shape = read_c_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/MAn.csv")
# 	ME = read_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/ME.csv");
ME, ME_shape = read_c_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/ME.csv")
# 	S = read_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/S.csv");
S, S_shape = read_c_csv("C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/CSVs/S.csv")



# 	// Variables de Interes

# 	TipoOp = RO->size[0];// Tipos de operaciones
TipoOp = RO_shape[0]
# 	NumEsp = ME->size[1];// Numero de Especialidades
NumEsp = ME_shape[1]
# 	NumTOp = CP->size[0];// Numero Total de Operaciones
NumTOp = CP_shape[0]

# 	// Recursos materiales
# 	NumSalOp = S->size[0];// Numero de Salones de operaciones
NumSalOp = S_shape[0]
# 	NumCPO = CPO->size[0];// Numero de camas Post - Operatorias
NumCPO = CPO_shape[0]
# 	NumCPrO = CPrO->size[0];// Numero de camas Pre - Operatorias
NumCPrO = CPrO_shape[0]
# 	NumCR = CR->size[0];// Numero de camas Recuperacion
NumCR = CR_shape[0]

# 	NumMedEsp = ME->size[0];// Numero de Medicos Especialistas
NumMedEsp = ME_shape[0]
# 	NumEspxE = NumMedEsp / NumEsp;// Numero de Especialistas por Especialidad
NumEspxE = int(NumMedEsp/NumEsp)
# 	NumAsist = MA->size[0];// Numero de Medico Asistentes
NumAsist = MA_shape[0]
# 	NumAnest = MAn->size[0];// Numero de Anestesistas
NumAnest = MAn_shape[0]

# 	//// Variables del model
# 	k0 = 0;
k0 = 0
# 	k1 = 0;
k1 = 0
# 	k2 = 0;
k2 = 0
# 	k3 = 0;
k3 = 0

# 	numIQ = 5;// Numero de individuos cuanticos.
numIQ = 5
# 	numIC = 20;// Numero de individuos clasicos.
numIC = 20
# 	taxC = 0.9;// Tasa de cruzamiento
taxC = 0.9
# 	taxE = 50;// Tasa de elitismo[%]
taxE = 50
# 	taxEQ = 10;
taxEQ = 10

# 	ProbXEst = emxCreate_real_T(5, 1);
ProbXEst = model.emxCreate_real_T(5, 1)
# 	ProbXEst->data[0] = 10.0; ProbXEst->data[1] = 20.0; ProbXEst->data[2] = 40.0; ProbXEst->data[3] = 20.0; ProbXEst->data[4] = 10.0;
data = [10.0, 20.0, 40.0, 20.0, 10.0]
c_data = (c_double * len(data))(*data)
model.real_array_to_emxArray(c_data, ProbXEst, len(data))
# 	genToWidth = 5;// Número de gerações de espera antes de reduzir a largura dos indivíduos quânticos
genToWidth = 5
# 	generations = 2;// Número de gerações
generations = 2

# 	keeppriority = false;
keeppriority = False

# 	/* Call the entry-point 'main_UCI_func'. */
# 	main_UCI_func(CP, RO, CPO, CPrO, CR, Data, Dia, DispMExD, MA, MAn, ME, S,
# 		TipoOp, NumEsp, NumTOp, NumSalOp, NumCPO, NumCPrO, NumCR,
# 		NumMedEsp, NumEspxE, NumAsist, NumAnest, k0, k1, k2, k3,
# 		numIQ, numIC, taxC, taxE, taxEQ, ProbXEst, genToWidth,
# 		generations, keeppriority);
aux = model.main_UCI_func(CP, RO, CPO, CPrO, CR, Data, Dia, DispMExD, MA, MAn, ME, S,
    TipoOp, NumEsp, NumTOp, NumSalOp, NumCPO, NumCPrO, NumCR,
    NumMedEsp, NumEspxE, NumAsist, NumAnest, k0, k1, k2, k3,
    numIQ, numIC, taxC, taxE, taxEQ, ProbXEst, genToWidth,
    generations, keeppriority)

print('\nrodou: ' + str(aux))

# 	emxDestroyArray_int32_T(S);
model.emxDestroyArray_int32_T(S)
# 	emxDestroyArray_int32_T(ME);
model.emxDestroyArray_int32_T(ME)
# 	emxDestroyArray_int32_T(MAn);
model.emxDestroyArray_int32_T(MAn)
# 	emxDestroyArray_int32_T(MA);
model.emxDestroyArray_int32_T(MA)
# 	emxDestroyArray_int32_T(DispMExD);
model.emxDestroyArray_int32_T(DispMExD)
# 	emxDestroyArray_int32_T(Dia);
model.emxDestroyArray_int32_T(Dia)
# 	emxDestroyArray_int32_T(Data);
model.emxDestroyArray_int32_T(Data)
# 	emxDestroyArray_int32_T(CR);
model.emxDestroyArray_int32_T(CR)
# 	emxDestroyArray_int32_T(CPrO);
model.emxDestroyArray_int32_T(CPrO)
# 	emxDestroyArray_int32_T(CPO);
model.emxDestroyArray_int32_T(CPO)
# 	emxDestroyArray_int32_T(RO);
model.emxDestroyArray_int32_T(RO)
# 	emxDestroyArray_int32_T(CP);
model.emxDestroyArray_int32_T(CP)

model.emxDestroyArray_real_T(ProbXEst)

# 	model_terminate();
model.model_terminate()

print('Tempo total: ' + str(time() - inicio) + ' segundos')
