function [bestexperimento, trace] = aevSPLap(NumTOp,numIC,numIQ,taxC,taxE,taxEQ,NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,Dia,Data,...
    TimeUsoRec,ProbXEst,fitnessB,generations,genToWidth,DispMExD,EP,k0,k1,k2,k3,keeppriority)

 
% INICIALIZA POPULAÇÃO QUANTICA. 

[ IQ ] = CreaPoQunniforme(NumTOp,numIQ);                 % IQ uniforme
        
% INICIALIZA POPULAÇÃO CLÁSSICA.

if (rem(numIC, numIQ) ~= 0)
    
   error('O número de indivíduos clássicos deve ser múltiplo do número de individuos quânticos');

else
    numObsIQ = numIC/numIQ;
end

tic;

if (keeppriority == true)
    [ IC ] = obsIQini( IQ,numIQ,numObsIQ,ProbXEst);        % Observaciones de los IQ garantizando que se mantengan en el rango Prioridad            
else
    [ IC ] = obsIQ( IQ,numIQ,numObsIQ);                     % Observaciones de los IQ
end

toc;

% PARÂMETROS DE INTERESSE

bestexperimento = IC(:,1);

best = zeros(NumTOp,numIC, 'int32');
bestFitness = zeros(numIC,6);

best(:,1) = int32(1:NumTOp)';
bestFitness(1,:) = fitnessB;

trace = zeros(generations,9);


% INICIALIZA LOOPING

for g = 1:generations
    
    
    fitness=zeros(numIC,6); % [fitness,NOFP,TmNOFP,NOE2,NOE3]
                
    for j=1:numIC

        [ fitness(j,1),fitness(j,2),fitness(j,3),fitness(j,4),fitness(j,5),fitness(j,6)] = sch(NumTOp,IC(:,j),NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,Dia,Data,TimeUsoRec,DispMExD,EP,k0,k1,k2,k3);

    end
    
%    save(strcat('fitness_', int2str(g),'.mat'),'fitness');
%    file = load(strcat('fitness_', int2str(g),'.mat'));
%    fitness = file.fitness;
    
    %ATUALIZA POPULAÇÃO B(T)
    if (g == 1)
        aux_classic_1 = [best(:,1), IC];
        aux_fitness_1 = [bestFitness(1,:); fitness];
        [~,idx_1] = sort(aux_fitness_1(:,1),'ascend');
        fitness_1 = aux_fitness_1(idx_1,:);
        rank_classic_1 = aux_classic_1(:,idx_1);
        
        fitness = fitness_1(1:numIC,:);
        rank_classic = rank_classic_1(:,1:numIC);
    else
        aux_classic_2 = [best(:,1:(numIC*taxE)/100), IC];
        aux_fitness_2 = [bestFitness(1:(numIC*taxE)/100,:); fitness];
        [~,idx_2] = sort(aux_fitness_2(:,1),'ascend');
        fitness_2 = aux_fitness_2(idx_2,:);
        rank_classic_2 = aux_classic_2(:,idx_2);
        
        fitness = fitness_2(1:numIC,:);
        rank_classic = rank_classic_2(:,1:numIC);
    end
        
        
    %REMOVE INDIVÍDUOS MAIS FRACOS (EXCEDENTES)

    IC = rank_classic;
    best = IC;
    bestFitness = fitness;
            
    % GUARDA MELHOR INDIVÍDUO
   
    bestexperimento = IC(:,1);

    % SALVA A GERAÇÃO, FITNESS do Melhor ind., a MÉDIA DO FITNESS e a STD DO FITNESS 
        
    trace(g,:) = [g,bestFitness(1,1),mean(bestFitness(:,1),1),std(bestFitness(:,1),1),bestFitness(1,2),bestFitness(1,3),bestFitness(1,4),bestFitness(1,5),bestFitness(1,6)];
    
    % IMPRIME STATUS DA EVOLUÇÃO
    
    fprintf('Ger: %d - \t Ini: %10.5f - \t Best: %10.5f - \t Mean: %10.5f - \t STD: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t NOE2: %10.5f - \t NOE3: %10.5f \n',...
               g,         fitnessB(1,1),      bestFitness(1,1),mean(bestFitness(:,1),1),std(bestFitness(:,1),1),bestFitness(1,2),bestFitness(1,3),bestFitness(1,4),bestFitness(1,5),bestFitness(1,6));
    
    % REPOSICIONA PULSOS DE ACORDO COM MELHORES INDIVÍDUOS
    
    if (rem(g, genToWidth) == 0)
        
        % QUANTUM UPDATE
        
        tmpColumn = randperm(numIQ-1);                                  %%%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%%
%         maximo=0.02;
%         minimo=0.002;
%         taxAct = rand;
%         taxAct = (maximo-minimo)*taxAct+minimo;

        taxAct = 0.00001;
        
        [ IQtemp ] = actIQ(IQ(1:end-NumTOp,:),IC(:,tmpColumn),taxAct); %%%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%%
        IQ(1:end-NumTOp,:)=IQtemp;                                     %%%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%%
        
        % NEW CLASSIC POPULATION
        
        if (keeppriority == true)
            [ IC ] = obsIQini( IQ,numIQ,numObsIQ,ProbXEst);        % Observaciones de los IQ garantizando que se mantengan en el rango Prioridad            
        else
            [ IC ] = obsIQ( IQ,numIQ,numObsIQ);                     % Observaciones de los IQ
        end        
                   
    else
        
        % Crossover clasico         
        [ IC ] = cc( IC,numIC,taxC,NumTOp);
        
    end

end
