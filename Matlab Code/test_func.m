clear variables;
close all;
clc;

tic;


    %% En la base de datos
    % CP: Caracteristicas de los pacientes. En las filas los pacientes y en las columnas:
    % [Fecha de Entrada, Estado del Paciente, Tipo de Operacion, Edad, Tiempo PreOperatorio, Tiempo PostOperatorio, Tiempo Recuperacion].
    % 
    % RO: Operaciones quirurgicas con sus caracteristicas. En las columnas los tipos de operaciones y en las columnas:
    % [Num Operación, Especialidad, Complejidad, Tiempo, Ctd Medicos, Ctd Ayudantes, Ctdad Anestesistas].
    % 
    % CPrO: Cama Pre-Operacion X Especialidad. "1" Habilitado para especialidad.
    % S: Salas X Especialidad. "1" Habilitado para especialidad.
    % CPO: Cama Post-Operacion X Especialidad. "1" Habilitado para especialidad.
    % CR: Cama Recuperacion X Especialidad. "1" Habilitado para especialidad.
    % 
    % ME: Medicos Especialistas X Especialidad. Diferente de "0" Habilitado para la especialidad siendo "1" Especialista, "2" con 
    % conicimientos suficientes pero con poca practica y "3" solo habilitado para operaciones de bajo riesgo.
    % MA: Medicos Asistentes X Especialidad
    % Man: Medicos Anestesistas X Especialidad
    % 
    % Data: Matriz con las fechas divididas por las horas (step=30min) y el dia de la semana desde 01/01/2017-31/12/2018. 
    % Solo estan los dias y horarios donde es posible colocar pacientes.
    % [Dia,mes,año,Hora].
    % 
    % Dia: Matriz con el cosecutivo de dias y el dia de la semana. Ademas tiene
    % los indices donde empieza y termina cada dia de la matriz Data.
    % [Consecutivo de dias, Dia de la semana, inicio en Data, final en Data].



coder.varsize('file.CP',        [inf 8],    [1 0])
coder.varsize('file.RO',        [inf 7],    [1 0])
coder.varsize('file.CPO',       [inf inf],  [1 1])
coder.varsize('file.CPrO',      [inf inf],  [1 1])
coder.varsize('file.CR',        [inf inf],  [1 1])
coder.varsize('file.Data',      [inf 5],    [1 0])
coder.varsize('file.Dia',       [inf 4],    [1 0])
coder.varsize('file.DispMExD',  [6 inf],    [0 1])
coder.varsize('file.MA',        [inf inf],  [1 1])
coder.varsize('file.MAn',       [inf inf],  [1 1])
coder.varsize('file.ME',        [inf inf],  [1 1])
coder.varsize('file.S',         [inf inf],  [1 1])

file=load('C:\Users\leo97\OneDrive\Área de Trabalho\Dissertação\Git\Matlab Code\BD_UCIFINAL.mat');
CP = int32(file.CP);
RO = int32(file.RO);
CPO = int32(file.CPO);
CPrO = int32(file.CPrO);
CR = int32(file.CR);
Data = int32(file.Data);
Dia = int32(file.Dia);
DispMExD = int32(file.DispMExD);
MA = int32(file.MA);
MAn = int32(file.MAn);
ME = int32(file.ME);
S = int32(file.S);

%% Variables de Interes

TipoOp = int32(size(RO,1));         % Tipos de operaciones
NumEsp = int32(size(ME,2));         % Numero de Especialidades
NumTOp = int32(size(CP,1));         % Numero Total de Operaciones

% Recursos materiales
NumSalOp = int32(size(S,1));        % Numero de Salones de operaciones
NumCPO = int32(size(CPO,1));        % Numero de camas Post-Operatorias
NumCPrO = int32(size(CPrO,1));      % Numero de camas Pre-Operatorias
NumCR = int32(size(CR,1));          % Numero de camas Recuperacion

NumMedEsp = int32(size(ME,1));      % Numero de Medicos Especialistas
NumEspxE = int32(NumMedEsp/NumEsp); % Numero de Especialistas por Especialidad
NumAsist = int32(size(MA,1));       % Numero de Medico Asistentes
NumAnest = int32(size(MAn,1));      % Numero de Anestesistas

%% Variables del model
k0=0;
k1=0;
k2=0;
k3=0;

numIQ=int32(5);                   % Numero de individuos cuanticos.
numIC=int32(20);                  % Numero de individuos clasicos.
taxC = 0.9;                % Tasa de cruzamiento
taxE = 50;                 % Tasa de elitismo [%]   
taxEQ = 10;

ProbXEst=[10;20;40;20;10];
genToWidth=int32(5);                % Número de gerações de espera antes de reduzir a largura dos indivíduos quânticos
generations=int32(50);             % Número de gerações

keeppriority = false;

main_UCI_func(CP,RO,CPO,CPrO,CR,Data,Dia,DispMExD,MA,MAn,ME,S,TipoOp,NumEsp,NumTOp,NumSalOp,NumCPO,NumCPrO,NumCR,NumMedEsp,NumEspxE,NumAsist,NumAnest,...
    k0,k1,k2,k3,numIQ,numIC,taxC,taxE,taxEQ,ProbXEst,genToWidth,generations,keeppriority)