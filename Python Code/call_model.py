#%%generating cmd command
# from glob import glob

# l = glob('C:/Users/leo97/OneDrive/Área de Trabalho/Dissertação/Git/C Code/*.c')
# for a in l:
#     print(a[64:])

# cd C:\Users\leo97\OneDrive\Área de Trabalho\Dissertação\Git\C Code
# gcc -shared -o model.so aevSPLap.c BDCreator_func.c casorandom.c cc.c combineVectorElements.c CreaPoQunniforme.c Edade.c eml_rand.c eml_rand_mcg16807_stateful.c eml_rand_mt19937ar_stateful.c eml_rand_shr3cong_stateful.c favalia.c funcionCPrO.c funcionDia.c getTime.c main.c main_UCI_func.c mean.c model_data.c model_emxAPI.c model_emxutil.c model_initialize.c model_rtwutil.c model_terminate.c nullAssignment.c obsIQ.c obsIQini.c rand.c randi.c randperm.c rdivide_helper.c rem.c repmat.c sch.c sort1.c sortIdx.c std.c sum.c tic.c timeKeeper.c toc.c
#%% Load model
import pandas as pd
from ctypes import CDLL, c_void_p, c_int, c_double, c_uint8, POINTER, byref
from time import time
from config import dll, hosp_csv_folder, k0, k1, k2, k3, numIQ, numIC, taxC, taxE, taxEQ, py_ProbXEst, genToWidth, generations, keeppriority, headers
import datetime
import json

def _get_shape(filename, shape=None):
    df = pd.read_csv(hosp_csv_folder + filename + ".csv", header=None, skiprows=int(headers[filename]['header']), index_col=headers[filename]['index'])
    if shape is not None:
        return df.shape[shape]
    return df.shape


def get_hospital_csv_values():
    return {
        'NumSalOp': _get_shape('S', 0),     # Numero de Salones de operaciones

        'NumCPO':   _get_shape('CPO', 0),   # Numero de camas Post - Operatorias
        'NumCPrO':  _get_shape('CPrO', 0),  # Numero de camas Pre - Operatorias
        'NumCR':    _get_shape('CR', 0),    # Numero de camas Recuperacion

        'NumMedEsp':_get_shape('ME', 0),    # Numero de Medicos Especialistas
        'NumAsist': _get_shape('MA', 0),    # Numero de Medico Asistentes
        'NumAnest': _get_shape('MAn', 0),   # Numero de Anestesistas
    }


def initialize_model():
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
    model.model_initialize()

    return model

def run_model():
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


    #   Initialize the application.
    #   You do not need to do this more than one time.
    model = initialize_model()

    def read_c_csv(filepath, header, index_col=None):
        df = pd.read_csv(filepath, header=None, skiprows=int(header), index_col=index_col)
        flat = df.values.flatten()
        arr = (c_int * df.size)(*flat)

        c_mat = model.emxCreate_int32_T(df.shape[0], df.shape[1])

        model.int_array_to_emxArray(arr, c_mat, df.size)

        return c_mat, df.shape

    csvs = {}

    for filename, header_dict in headers.items():
        data, shape = read_c_csv(
            hosp_csv_folder + filename + ".csv", header=header_dict['header'], index_col=header_dict['index'])
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

    model.emxDestroyArray_int32_T(csvs['S']['data'])
    model.emxDestroyArray_int32_T(csvs['ME']['data'])
    model.emxDestroyArray_int32_T(csvs['MAn']['data'])
    model.emxDestroyArray_int32_T(csvs['MA']['data'])
    model.emxDestroyArray_int32_T(csvs['DispMExD']['data'])
    model.emxDestroyArray_int32_T(csvs['Dia']['data'])
    model.emxDestroyArray_int32_T(csvs['Data']['data'])
    model.emxDestroyArray_int32_T(csvs['CR']['data'])
    model.emxDestroyArray_int32_T(csvs['CPrO']['data'])
    model.emxDestroyArray_int32_T(csvs['CPO']['data'])
    model.emxDestroyArray_int32_T(csvs['RO']['data'])
    model.emxDestroyArray_int32_T(csvs['CP']['data'])
    model.emxDestroyArray_int32_T(c_queue)

    model.emxDestroyArray_real_T(ProbXEst)

    model.model_terminate()

    total_time = time() - inicio

    print('Tempo total: ' + str(total_time) + ' segundos')
    return queue, total_time

def generate_calendar():
    Data = pd.read_csv(hosp_csv_folder + "Data.csv", header=0)
    schedule = pd.read_csv(hosp_csv_folder + "schedule_dirty.csv", header=0, index_col=0)

    schedule.index = Data.apply(lambda row: datetime.datetime(year=row['Ano'],month=row['Mes'],hour=row['Hora']-1,day=row['Dia']), axis=1)

    def get_equipment_events(equipment_schedule):
        sched_gb = equipment_schedule.groupby([(equipment_schedule.ne(equipment_schedule.shift())).cumsum()])
        sched = sched_gb.agg(title=lambda group: 'Operacao ' + str(max(group)), start=lambda group: str(min(group.index)), end=lambda group: str(max(group.index + pd.to_timedelta(1,unit='h'))))
        sched = sched[sched['title'].ne('Operacao 0')]
        sched = sched.apply(pd.Series.to_json, axis=1)
        return pd.DataFrame([['x']*len(sched)],columns=list(sched), index=[equipment_schedule.name])
    
    events = pd.DataFrame()
    for equipment in schedule.columns:
        events = events.append(get_equipment_events(schedule[equipment]))

    events_json = '['
    calendar_details = {}

    event_id = 0
    for event in events.columns:
        event_id += 1
        events_json += event[:-1] + ',"id":'+str(event_id)+',"url":"http://127.0.0.1:5000/calendar_details/' + str(event_id) + '"},'
        equipments = events[event].dropna()
        calendar_details[event_id] = list(equipments.index)

    events_json = events_json[:-1] + ']'
    return events_json, json.dumps(calendar_details)


events_json, details_json = generate_calendar()

with open('C:\\Users\\leo97\\OneDrive\\Área de Trabalho\\Dissertação\\Git\\CSVs\\events.json', 'w') as f:
    f.write(events_json)
with open('C:\\Users\\leo97\\OneDrive\\Área de Trabalho\\Dissertação\\Git\\CSVs\\details.json', 'w') as f:
    f.write(details_json)
