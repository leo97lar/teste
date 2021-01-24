clear variables;
close all;
clc;

tic;

load('BD_UCIFINAL.mat')

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

%% Variables de Interes

TipoOp = size(RO,1);         % Tipos de operaciones
NumEsp = size(ME,2);         % Numero de Especialidades
NumTOp = size(CP,1);         % Numero Total de Operaciones

% Recursos materiales
NumSalOp = size(S,1);        % Numero de Salones de operaciones
NumCPO = size(CPO,1);        % Numero de camas Post-Operatorias
NumCPrO = size(CPrO,1);      % Numero de camas Pre-Operatorias
NumCR = size(CR,1);          % Numero de camas Recuperacion

NumMedEsp = size(ME,1);      % Numero de Medicos Especialistas
NumEspxE = NumMedEsp/NumEsp; % Numero de Especialistas por Especialidad
NumAsist = size(MA,1);       % Numero de Medico Asistentes
NumAnest = size(MAn,1);      % Numero de Anestesistas

k0=0;
k1=0;
k2=0;
k3=0;

%% Matriz de Horario. En las filas los dias

NumRec = [NumCPrO NumMedEsp NumSalOp NumAsist NumAnest NumCPO NumCR];              % Numemero de recursos
H = zeros(size(Data,1),sum(NumRec));                                               % Schedule completo
UltPosRecXDia = zeros(size(Dia,1),size(H,2));                                      % Ultima posicion asignado del recurso por Dia

%% Matriz con el tiempo de uso necesario de todos los recursos

%Cama Pre-OP,Sala de Operación, Medicos Especialistas, Medicos Asistentes, Medicos Anstesistas, Cama Post-OP, Cama Recuperacion. 

TimeUsoRec(:,1) = CP(:,6);       % Tiempo de uso cama Pre-Operatoria
TimeUsoRec(:,2) = RO(CP(:,4),4); % Tiempo de uso Salon de operacion
TimeUsoRec(:,3) = TimeUsoRec(:,2);  % Tiempo de uso Medico Especialista
TimeUsoRec(:,4) = TimeUsoRec(:,2);  % Tiempo de uso Medico Asistente
TimeUsoRec(:,5) = TimeUsoRec(:,2);  % Tiempo de uso Medico Anestesista
TimeUsoRec(:,6:7) = CP(:,7:8);   % Tiempo de uso cama Post-Operatoria y Recuperacion

PME = ME(:,RO(CP(:,4),2))';      % Posibles Medicos Especialistas X Operacion.
PME(:,end+1) = RO(CP(:,4),5);    % Cantidad necesaria de Medicos Especialistas

PMA = MA(:,RO(CP(:,4),2))';      % Posibles Medicos Asistentes X Operacion.
PMA(:,end+1) = RO(CP(:,4),6);    % Cantidad necesaria de Medicos Asistentes

PMAn = MAn(:,RO(CP(:,4),2))';    % Posibles Medicos Anestesistas X Operacion.
PMAn(:,end+1) = RO(CP(:,4),7);   % Cantidad necesaria de Medicos Anestesistas

CxO = RO(CP(:,4),3);             % Complejidad de la Operacion

for i=1:NumTOp
    
    if CxO(i)==1     % Si la operacion es de alto riesgo quitar los Medicos de nivel 3 como opcion
        
        idx= PME(i,1:end-1)==3;
        PME(i,idx)=0;
        
        idx= PMA(i,1:end-1)==3;
        PMA(i,idx)=0;
        
        idx=PMAn(i,1:end-1)==3;
        PMAn(i,idx)=0;
        
    end
    
    
end

PCPrO = CPrO(:,RO(CP(:,4),2))'; % Posibles Camas PreOperatorias X Operacion.
PS = S(:,RO(CP(:,4),2))';       % Posibles Salon X Operacion.
PCPO = CPO(:,RO(CP(:,4),2))';   % Posibles Camas PostOperatorias X Operacion.
PCR = CR(:,RO(CP(:,4),2))';     % Posibles Camas de Recuperacion X Operacion.

EP = CP(:,3);                   % Estado del paciente.
%% Caso Base

[ scheduleB,DiaOpB,EspMedOpB ] = casorandom( NumTOp,H,NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,Dia,UltPosRecXDia,TimeUsoRec,DispMExD);

[ fitnessB,TtB,NOFPB,TmNOFPB,NOE2B,NOE3B] = favalia( scheduleB,DiaOpB,EP,EspMedOpB,k0,k1,k2,k3);

fprintf('Fitness: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t NOE2: %10.5f - \t NOE3: %10.5f \n',fitnessB,TtB,NOFPB,TmNOFPB,NOE2B,NOE3B);

toc;
%% Reorganizando la lista de espera

NAWD = ((max(CP(:,2))-CP(:,2))+1).*(360./EP); % Ajuste de la lista de espera dependiente del estado del paciente y el tiempo de entrada a la lista.

[~,idx] = sort(NAWD(:,1),'descend');

NewCP = CP(idx,:);                           % Organizo la Lista de Espera

NewTimeUsoRec = TimeUsoRec(idx,:);       

NewPME = PME(idx,:);      % Posibles Medicos Especialistas X Operacion.
NewPMA = PMA(idx,:);      % Posibles Medicos Asistentes X Operacion.
NewPMAn = PMAn(idx,:);    % Posibles Medicos Anestesistas X Operacion.

NewPCPrO = PCPrO(idx,:); % Posibles Camas PreOperatorias X Operacion.
NewPS = PS(idx,:);       % Posibles Salon X Operacion.
NewPCPO = PCPO(idx,:);   % Posibles Camas PostOperatorias X Operacion.
NewPCR = PCR(idx,:);     % Posibles Camas de Recuperacion X Operacion.

NewEP = EP(idx);  
%% Caso Base


[ schedule,DiaOp,EspMedOp ] = casorandom( NumTOp,H,NumRec,NewPCPrO,NewPME,NewPMA,NewPMAn,NewPS,NewPCPO,NewPCR,Dia,UltPosRecXDia,NewTimeUsoRec,DispMExD);

[fitness,Tt,NOFP,TmNOFP,NOE2,NOE3] = favalia( schedule,DiaOp,NewEP,EspMedOp,k0,k1,k2,k3 );

fprintf('Fitness: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t NOE2: %10.5f - \t NOE3: %10.5f \n',fitness,Tt,NOFP,TmNOFP,NOE2,NOE3);

toc;
%% AE

numIQ=5;                   % Numero de individuos cuanticos.
numIC=20;                  % Numero de individuos clasicos.
taxC = 0.9;                % Tasa de cruzamiento
taxE = 50;                 % Tasa de elitismo [%]   
taxEQ = 10;

ProbXEst=[10;20;40;20;10];
genToWidth=5;                % Número de gerações de espera antes de reduzir a largura dos indivíduos quânticos
generations=100;             % Número de gerações

allfitness = [fitness,Tt,NOFP,TmNOFP,NOE2,NOE3];

[bestexperimento, trace] = aevSPLap(NumTOp,numIC, numIQ,taxC,taxE,taxEQ,NumRec,NewPCPrO,NewPME,NewPMA,NewPMAn,NewPS,NewPCPO,NewPCR,Dia,Data,...
    NewTimeUsoRec,ProbXEst,allfitness,generations,genToWidth,DispMExD,NewEP,k0,k1,k2,k3);

toc;