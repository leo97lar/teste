function BDCreator_func()
    %% Generar Base de Datos
    % Vamos a tener 15 especialidades con diferentes operaciones quirurgicas
    % (200 en total) que requieren diferentes tipos de especialistas y
    % recursos. Algunas mas complejas que otras. 25 cirujanos especializados en
    % una especialidad y con conocimientos suficientes para realizar cirujias
    % de otra especialidad. 25 anestesistas y 25 asistentes.

    tic;
    %% Variables de Entrada

    TipoOp = 200;               % Tipos de operaciones
    NumEsp = 15;                % Numero de Especialidades
    MedNecXOp = ones(TipoOp,1)*2;       % Medicos necesarios por Operacion
    AsistNecXOp = ones(TipoOp,1)*2;     % Asistentes necesarios por Operacion
    AnestNecXOp = ones(TipoOp,1)*2;     % Anestesistas necesarios por Operacion

    NumTOp = 2000;              % Numero Total de Operaciones

    % Recursos materiales
    NumSalOp = 10;              % Numero de Salones de operaciones
    NumCPO = 15;                % Numero de camas Post-Operatorias
    NumCPrO = 10;               % Numero de camas Pre-Operatorias
    NumCR = 25;                 % Numero de camas Recuperacion

    % Recursos Humanos
    NumEspxE = 2;               % Numero de Especialistas por Especialidad
    NumAsist = 10;              % Numero de Asistentes
    NumAnest = 10;              % Numero de Anestesistas

    %% Tabla de Operaciones por Especialidad

    % E  1  2  3  4  5  6  7  8  9  10  11  12  13  14 15
    % % 10  5 12  5 15 10  8  5  5   2   3  10   5   3  2

    POPE = [10;5;12;5;15;10;8;5;5;2;3;10;5;3;2]; % Vector con el porciento de tipos operaciones por especialidad
    OpXEsp = zeros(TipoOp, 1);                                 % Operaciones por especialidad
    
    filled=0;
    for i=1:length(POPE)
        ops = POPE(i)*TipoOp/100;
        OpXEsp(filled+1 : filled+ops) = i;
        filled = filled + ops;
    end

    ind=randperm(TipoOp);
    OpXEsp = OpXEsp(ind);

    %% Complejidad de la operacion

    % 1___Alta (30%)
    % 2___Media (50%)
    % 3___Baja (20%)

    PCO = [30;50;20];    % Vector con el porciento de operaciones por su complejidad
    CompOp = zeros(TipoOp, 1);                % Complejidad de la operacion

    filled=0;
    for i=1:length(PCO)

        ops = PCO(i)*TipoOp/100;
        CompOp(filled+1 : filled+ops) = i;
        filled = filled + ops;

    end

    ind=randperm(TipoOp);
    CompOp = CompOp(ind);

    %% Tiempo de Duracion de la operacion
    % 1 0,5h (15%)
    % 2 1,0h (20%)
    % 3 1,5h (25%)
    % 4 2,0h (25%)
    % 5 2,5h (15%)

    Hr = [1,2,3,4,5];
    PTO = [15;20;25;25;15]; % Vector con el porciento de operaciones por horas de duracion
    TimeOp = zeros(TipoOp, 1);                % Tiempo de operacion

    filled=0;
    for i=1:length(PTO)

        ops = PTO(i)*TipoOp/100;
        TimeOp(filled+1 : filled+ops) = Hr(i);
        filled = filled + ops;

    end
    ind=randperm(TipoOp);
    TimeOp = TimeOp(ind);

    %% Recursos necesarios
    % Especialistas
    % Asistentes
    % Anestesistas

    for i =1:TipoOp

        if CompOp(i)>=2 && TimeOp(i)<=2 % Si la complejidad es media-baja y el tiempo
        % de operacion es menor igual que dos hora solo necesito un medico
        % especialista.

            MedNecXOp(i)=1;

            if CompOp(i)==3 % Si la complejidad es baja y el tiempo de operacion  
            % es menor igual que una hora solo necesito un Asistente.

                AsistNecXOp(i)=1;

                if TimeOp(i)==1

                    AnestNecXOp(i)=1;

                end

            end

        end

        if CompOp(i)==1 && TimeOp(i)>=4 % Si la complejidad es alta y el tiempo de 
        % operacion es mayor igual que 4 horas se necesitan 3 Asistente.

            AsistNecXOp(i)=3;

        end

    end


    %% Tabla de Operaciones quirurgicas con sus caracteristicas (Tabla1)

    % Num Operación, Especialidad, Complejidad, Tiempo, Ctd Medicos, Ctd Ayudantes, Ctdad Anestesistas.

    RO = [linspace(1,TipoOp,TipoOp)',OpXEsp,CompOp,TimeOp,MedNecXOp,AsistNecXOp,AnestNecXOp];

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %% Caracteristicas de los pacientes por Operacion

    TOPP = randi([1 TipoOp],1,NumTOp)'; % Tipo de operacion por paciente
    EPP = Edade( 5,75,NumTOp);          % Edad por paciente

    % Estado del paciente

    % A 48  Si evidentemente el retraso afectara el progreso de la enfermedad
    % B 12  Si posiblemente el retraso afectara el progreso de la enfermedad
    % C  4  Si el retraso NO afectara el progreso de la enfermedad pero hay dolor severo 
    % D  2  Si el retraso NO afectara el progreso de la enfermedad pero hay dolor medio
    % E  1  Si el retraso NO afectara el progreso de la enfermedad ni hay dolor

    PE = [360,180,90,30,6];        % Posibles estados.
    PPE = [10;25;30;25;10];        % Porciento por estado del paciente
    EP = zeros(TipoOp, 1);

    filled=0;
    for i=1:length(PE)

        ops = PPE(i)*TipoOp/100;
        EP(filled+1 : filled+ops) = PE(i);
        filled = filled + ops;

    end

    ind=randperm(NumTOp);
    EP = EP(ind);

    % Tiempos de uso de salas

    TPreO = ones(NumTOp,1)*2;     % Tiempo de Preoperatorio. Caso promedio dos horas.

    for i=1:NumTOp

        if RO(TOPP(i),3)==3 && RO(TOPP(i),4)<3     % Si la complejidad es baja, el tiempo menor de 3 horas y 
            if EPP(i)>16 || EPP(i)<55                    %el paciente esta entre 16 y 55 años ==> 1 hora de PrO
                TPreO(i)=1;
            end
        elseif RO(TOPP(i),3)==1 && RO(TOPP(i),4)>2 % Si la complejidad es alta, el tiempo mayor de 3 horas ==> 4 hora de PrO
            if RO(TOPP(i),4)>3                     % Si la complejidad es alta, el tiempo igual a 3 horas  ==> 3 hora de PrO
                TPreO(i)=4;
            else
                TPreO(i)=3;
            end
        elseif RO(TOPP(i),3)==2 && RO(TOPP(i),4)>2 % Si la complejidad es media, el tiempo mayor de 2 horas y
            if EPP(i)<=16 || EPP(i)>=55                  %el paciente tiene menos de 16 años y  mas de 55 ==> 3 hora de PrO
                TPreO(i)=3;
            end

        end  


    end

    TPOstO = ones(NumTOp,1)*8;   % Tiempo de Post-Operaorio. Caso promedio 8 horas.
    TR = ones(NumTOp,1)*24;      % Tiempo de Recuperacion. Caso promedio 24 horas.


    for i=1:NumTOp

        if RO(TOPP(i),3)==3 && RO(TOPP(i),4)<3     % Si la complejidad es baja, el tiempo menor de 3 horas y 
            if EPP(i)>16 || EPP(i)<55                    %el paciente esta entre 16 y 55 años ==> 1 hora de PrO
                TPOstO(i)=0;
                TR(i)=24;
            end
        elseif RO(TOPP(i),3)==2 && RO(TOPP(i),4)>2 % Si la complejidad es alta, el tiempo mayor de 3 horas ==> 4 hora de PrO
            if EPP(i)<=16 || EPP(i)>=55            % Si la complejidad es alta, el tiempo igual a 3 horas  ==> 3 hora de PrO
                TPOstO(i)=24;
                TR(i)=72;
            else
                TPOstO(i)=24;
                TR(i)=48;
            end
        elseif RO(TOPP(i),3)==1 && RO(TOPP(i),4)>2 % Si la complejidad es media, el tiempo mayor de 2 horas y
            if EPP(i)<=16 || EPP(i)>=55            % Si la complejidad es alta, el tiempo igual a 3 horas  ==> 3 hora de PrO
                TPOstO(i)=48;
                TR(i)=96;
            else
                TPOstO(i)=48;
                TR(i)=72;
            end
        end  
     end


    % Datas de entrada
    MaxEPD = 30;                 % Maximo numero de entradas por dia
    INI = MaxEPD;                % Cantidad de entradas en el 1er dia

    aux = randi([1 MaxEPD]);

auxCExD = zeros(NumTOp,1);
auxCExD(1:2) = [INI;aux];            % Cantidad de entradas por dia
flag=1;
count = 2;

while(flag==1)
    if(sum(auxCExD) < NumTOp)
        count = count + 1;
        auxCExD(count) = randi([1 MaxEPD]);
    else
        flag=0;
    end
end
CExD = auxCExD(1:count);


    Exc = sum(CExD)-NumTOp;     % Operaciones excedentes

    CExD(1)= CExD(1)-Exc;
    ND = size(CExD,1);          % Numero de dias de entrada
    DE = zeros(NumTOp, 1);                    % Data de entrada

    filled = 0;
    for i=1:ND

        ops = CExD(i);
        DE(filled+1 : filled+ops) = i;
        filled = filled + ops;

    end

    idx=randperm(size(DE,1));

    DE=DE(idx);

    %% Tabla con las caracteristicas de los pacientes por Operacion (Tabla2)

    % Fecha de Entrada, Estado del Paciente, Tipo de Operacion, Edad, Tiempo preOperatorio, Tiempo PostOperatorio, Tiempo Recuperacion.

    aux = [DE,EP,TOPP,EPP,TPreO,TPOstO,TR];

    [~,idx] = sort(aux(:,1),'ascend');

    CP = [(1:1:size(aux,1))' aux(idx,:)];

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %% Recursos Disponibles

    % Materiales
    S = double(rand(NumSalOp,NumEsp) < 0.8);   % Salas X Especialidad. "1" Habilitado para especialidad.
    CPO = double(rand(NumCPO,NumEsp) < 0.9);   % Cama Post-Operacion X Especialidad. "1" Habilitado para especialidad.
    CPrO = double(rand(NumCPrO,NumEsp) < 0.9); % Cama Pre-Operacion X Especialidad. "1" Habilitado para especialidad.
    CR = double(rand(NumCR,NumEsp) < 0.95);    % Cama Recuperacion X Especialidad. "1" Habilitado para especialidad.

    % Humano

    aux = rand(NumEsp*NumEspxE,NumEsp);

    ME = (aux>0.6)*2;

    aux1 = aux>0.85;

    ME = ME + aux1;

    for i=1:NumEsp

        ME(i,i) = 1;
        ME(NumEsp+i,i) = 1;

    end

    DispMExD = zeros(6,NumEsp*NumEspxE);    % Disponibiidad de medico especialista por dia de a semana. No todos los medicos
                                            %trabajan todos los dias.
    DiaxEsp=[1;2;7;3;7;7;4;5;1;6;2;3;4;5;6];                                    

    for i=1:NumEsp

        [f,c]=find(ME(:,i)==1);

        switch DiaxEsp(i)

            case 1
                DispMExD(1,f)=1;
            case 2
                DispMExD(2,f)=1;
            case 3
                DispMExD(3,f)=1;
            case 4
                DispMExD(4,f)=1;
            case 5
                DispMExD(5,f)=1;
            case 6
                DispMExD(6,f)=1;
            otherwise
                DispMExD(:,f)=1;

        end

    end

    aux = rand(NumAsist,NumEsp);

    MA = (aux<0.2)*2+(aux<0.05);
    MA(MA==0)=1;

    if NumAsist~=NumAnest

        aux = rand(NumAnest,NumEsp);

    end

    MAn = (aux>0.9)*2+(aux>0.95);
    MAn(MAn==0)=1;

    [ Data, Dia ] = Calendario();


    %save('RRR.mat','CP','RO','CPrO','S','CPO','CR','ME','MA','MAn','Data','Dia','DispMExD')

    toc;
end

