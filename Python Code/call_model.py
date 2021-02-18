#%%generating cmd command
# from glob import glob

# l = glob('D:/Dissertacao/Git/C Code/*.c')
# for a in l:
#     print(a[64:])

# cd D:\Dissertacao\Git\C Code
# gcc -shared -o model.so aevSPLap.c BDCreator_func.c casorandom.c cc.c combineVectorElements.c CreaPoQunniforme.c Edade.c eml_rand.c eml_rand_mcg16807_stateful.c eml_rand_mt19937ar_stateful.c eml_rand_shr3cong_stateful.c favalia.c funcionCPrO.c funcionDia.c getTime.c main.c main_UCI_func.c mean.c model_data.c model_emxAPI.c model_emxutil.c model_initialize.c model_rtwutil.c model_terminate.c nullAssignment.c obsIQ.c obsIQini.c rand.c randi.c randperm.c rdivide_helper.c rem.c repmat.c sch.c sort1.c sortIdx.c std.c sum.c tic.c timeKeeper.c toc.c
#%% Load model
import pandas as pd
from ctypes import CDLL, c_void_p, c_int, c_double, c_uint8, c_char_p, POINTER, byref
from time import time
from global_config import dll, saves_folder, k0, k1, k2, k3, numIQ, numIC, taxC, taxE, taxEQ, py_ProbXEst, genToWidth, generations, keeppriority, csv_index, url, schedule_csv, c_schedule, c_results, model_config
import datetime
import json


def _get_shape(filename, csv_folder, shape=None):
    df = pd.read_csv(csv_folder + filename + ".csv", header=None, skiprows=1
    , index_col=csv_index[filename])
    if shape is not None:
        return df.shape[shape]
    return df.shape


def get_hospital_csv_values(save_name):
    csv_folder = saves_folder + save_name + '/'
    return {
        # Numero de Salones de operaciones
        'NumSalOp': _get_shape('S', csv_folder, 0),

        # Numero de camas Post - Operatorias
        'NumCPO':   _get_shape('CPO', csv_folder, 0),
        # Numero de camas Pre - Operatorias
        'NumCPrO':  _get_shape('CPrO', csv_folder, 0),
        # Numero de camas Recuperacion
        'NumCR':    _get_shape('CR', csv_folder, 0),

        # Numero de Medicos Especialistas
        'NumMedEsp': _get_shape('ME', csv_folder, 0),
        # Numero de Medico Asistentes
        'NumAsist': _get_shape('MA', csv_folder, 0),
        # Numero de Anestesistas
        'NumAnest': _get_shape('MAn', csv_folder, 0),
    }

def get_header(csv_file):
    return list(pd.read_csv(csv_file, index_col=0).columns)

def generate_calendar(csv_folder):
    Data = pd.read_csv(csv_folder + "Data.csv", header=0)
    schedule = pd.read_csv(
        csv_folder + c_schedule, header=0, index_col=0)

    #schedule data order as decided by the original codes author
    data_order = ['CPrO', 'ME', 'S', 'MA', 'MAn', 'CPO', 'CR']

    headers = map(lambda x: pd.read_csv(csv_folder + x + '.csv', index_col=csv_index[x]).index, data_order)
    new_header = [item for sublist in headers for item in sublist]
    schedule.columns = new_header
    schedule.to_csv(csv_folder + schedule_csv)

    schedule.index = list(Data.apply(lambda row: datetime.datetime(
        year=row['Ano'], month=row['Mes'], hour=row['Hora']-1, day=row['Dia']), axis=1))[:len(schedule.index)]

    def get_equipment_events(equipment_schedule):
        sched_gb = equipment_schedule.groupby(
            [(equipment_schedule.ne(equipment_schedule.shift())).cumsum()])
        sched = sched_gb.agg(title=lambda group: 'Operacao ' + str(max(group)), start=lambda group: str(
            min(group.index)), end=lambda group: str(max(group.index + pd.to_timedelta(1, unit='h'))))
        sched = sched[sched['title'].ne('Operacao 0')]
        sched = sched.apply(pd.Series.to_json, axis=1)
        return pd.DataFrame([['x']*len(sched)], columns=list(sched), index=[equipment_schedule.name])

    events = pd.DataFrame()
    for equipment in schedule.columns:
        events = events.append(get_equipment_events(schedule[equipment]))

    events_json = '['
    calendar_details = {}

    event_id = 0
    for event in events.columns:
        event_id += 1
        events_json += event[:-1] + f',"id":{event_id},"url":"{url}/calendar_details/{event_id}' + '"},'
        equipments = events[event].dropna()
        calendar_details[event_id] = {'op_id':json.loads(event)['title'], 'equips':list(equipments.index)}

    events_json = events_json[:-1] + ']'
    details_json = json.dumps(calendar_details)

    with open(csv_folder + 'events.json', 'w') as f:
        f.write(events_json)
    with open(csv_folder + 'details.json', 'w') as f:
        f.write(details_json)

def generate_config(csv_folder):
    with open(csv_folder + model_config, 'w') as f:
        f.write('{"k0":%.2f,"k1":%.2f,"k2":%.2f,"k3":%.2f}'%(k0, k1, k2, k3))

def _initialize_model():
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
        c_int, c_uint8, c_char_p,
    ]
    model.model_initialize()

    return model

def _read_c_csv(model, filepath, index_col=None):
    df = pd.read_csv(filepath, header=None,
                        skiprows=1, index_col=index_col)
    flat = df.values.flatten()
    arr = (c_int * df.size)(*flat)

    c_mat = model.emxCreate_int32_T(df.shape[0], df.shape[1])

    model.int_array_to_emxArray(arr, c_mat, df.size)

    return c_mat, df.shape

def run_model(save_name):
    csv_folder = saves_folder + save_name + '/'

    inicio = time()

    #%% Load CSV

    #   Initialize the application.
    #   You do not need to do this more than one time.
    model = _initialize_model()

    csvs = {}

    for filename, index_col in csv_index.items():
        data, shape = _read_c_csv(model,
            csv_folder + filename + ".csv", index_col=index_col)
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
    # Numero de Especialistas por Especialidad
    NumEspxE = int(NumMedEsp/NumEsp)
    NumAsist = csvs['MA']['shape'][0]  # Numero de Medico Asistentes
    NumAnest = csvs['MAn']['shape'][0]  # Numero de Anestesistas

    ProbXEst = model.emxCreate_real_T(5, 1)

    c_ProbXEst = (c_double * len(py_ProbXEst))(*py_ProbXEst)
    model.real_array_to_emxArray(c_ProbXEst, ProbXEst, len(py_ProbXEst))

    schedule_path = (csv_folder + c_schedule).encode('utf-8')
    result_path = (csv_folder + c_results).encode('utf-8')

    #%% Rodar Modelo

    # 	/* Call the entry-point 'main_UCI_func'. */
    c_queue = model.main_UCI_func(csvs['CP']['data'], csvs['RO']['data'], csvs['CPO']['data'], csvs['CPrO']['data'], csvs['CR']['data'], csvs['Data']['data'], csvs['Dia']['data'], csvs['DispMExD']['data'], csvs['MA']['data'], csvs['MAn']['data'], csvs['ME']['data'], csvs['S']['data'],
                                  TipoOp, NumEsp, NumTOp, NumSalOp, NumCPO, NumCPrO, NumCR,
                                  NumMedEsp, NumEspxE, NumAsist, NumAnest, k0, k1, k2, k3,
                                  numIQ, numIC, taxC, taxE, taxEQ, ProbXEst, genToWidth,
                                  generations, keeppriority, schedule_path, result_path)

    #%% Testar resultado
    queue = [c_queue[i] for i in range(NumTOp)]

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
    # print('destroying c_queue')
    # model.emxDestroyArray_int32_T(c_queue)

    model.emxDestroyArray_real_T(ProbXEst)

    model.model_terminate()

    total_time = time() - inicio

    print('Tempo total: ' + str(total_time) + ' segundos')

    generate_calendar(csv_folder)
    generate_config(csv_folder)

    # return queue, total_time
