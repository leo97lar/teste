function main_UCI_func(CP,RO,CPO,CPrO,CR,Data,Dia,DispMExD,MA,MAn,ME,S,TipoOp,NumEsp,NumTOp,NumSalOp,NumCPO,NumCPrO,NumCR,NumMedEsp,NumEspxE,NumAsist,NumAnest,...
    k0,k1,k2,k3,numIQ,numIC,taxC,taxE,taxEQ,ProbXEst,genToWidth,generations,keeppriority)
    tic;


    coder.varsize('CP',        [inf 8],    [1 0])
    coder.varsize('RO',        [inf 7],    [1 0])
    coder.varsize('CPO',       [inf inf],  [1 1])
    coder.varsize('CPrO',      [inf inf],  [1 1])
    coder.varsize('CR',        [inf inf],  [1 1])
    coder.varsize('Data',      [inf 5],    [1 0])
    coder.varsize('Dia',       [inf 4],    [1 0])
    coder.varsize('DispMExD',  [6 inf],    [0 1])
    coder.varsize('MA',        [inf inf],  [1 1])
    coder.varsize('MAn',       [inf inf],  [1 1])
    coder.varsize('ME',        [inf inf],  [1 1])
    coder.varsize('S',         [inf inf],  [1 1])


    %% Matriz de Horario. En las filas los dias

    NumRec = [NumCPrO NumMedEsp NumSalOp NumAsist NumAnest NumCPO NumCR];              % Numero de recursos
    H = zeros(size(Data,1),sum(NumRec), 'int32');                                               % Schedule completo
    UltPosRecXDia = zeros(size(Dia,1),size(H,2), 'int32');                                      % Ultima posicion asignado del recurso por Dia

    %% Matriz con el tiempo de uso necesario de todos los recursos

    %Cama Pre-OP,Sala de Operación, Medicos Especialistas, Medicos Asistentes, Medicos Anstesistas, Cama Post-OP, Cama Recuperacion. 

    TimeUsoRec = zeros(NumTOp, 7, 'int32');
    TimeUsoRec(:,1) = CP(:,6);       % Tiempo de uso cama Pre-Operatoria
    TimeUsoRec(:,2) = RO(CP(:,4),4); % Tiempo de uso Salon de operacion
    TimeUsoRec(:,3) = TimeUsoRec(:,2);  % Tiempo de uso Medico Especialista
    TimeUsoRec(:,4) = TimeUsoRec(:,2);  % Tiempo de uso Medico Asistente
    TimeUsoRec(:,5) = TimeUsoRec(:,2);  % Tiempo de uso Medico Anestesista
    TimeUsoRec(:,6:7) = CP(:,7:8);   % Tiempo de uso cama Post-Operatoria y Recuperacion

    PME = [ME(:,RO(CP(:,4),2))' RO(CP(:,4),5)];      % Posibles Medicos Especialistas X Operacion. | Cantidad necesaria de Medicos Especialistas

    PMA = [MA(:,RO(CP(:,4),2))' RO(CP(:,4),6)];      % Posibles Medicos Asistentes X Operacion. | Cantidad necesaria de Medicos Asistentes

    PMAn = [MAn(:,RO(CP(:,4),2))' RO(CP(:,4),7)];    % Posibles Medicos Anestesistas X Operacion. | Cantidad necesaria de Medicos Anestesistas

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

    [ fitnessB,TtB,NOFPB,TmNOFPB,NOE2B,NOE3B] = favalia(scheduleB,DiaOpB,EP,EspMedOpB,k0,k1,k2,k3);

    fprintf('Fitness: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t NOE2: %10.5f - \t NOE3: %10.5f \n',fitnessB,TtB,NOFPB,TmNOFPB,NOE2B,NOE3B);

    toc;
    %% Reorganizando la lista de espera

    NAWD = ((max(CP(:,2),[],1)-CP(:,2))+1).*(360./EP); % Ajuste de la lista de espera dependiente del estado del paciente y el tiempo de entrada a la lista.

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

    allfitness = [fitness,Tt,NOFP,TmNOFP,NOE2,NOE3];

    [bestexperimento, trace] = aevSPLap(NumTOp,numIC,numIQ,taxC,taxE,taxEQ,NumRec,NewPCPrO,NewPME,NewPMA,NewPMAn,NewPS,NewPCPO,NewPCR,Dia,Data,...
        NewTimeUsoRec,ProbXEst,allfitness,generations,genToWidth,DispMExD,NewEP,k0,k1,k2,k3,keeppriority);

    toc;
    
    PLOTT_func(trace, bestexperimento)
end