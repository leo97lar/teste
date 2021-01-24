function [bestexperimento, trace] = aevSPLap(NumTOp,numIC, numIQ,taxC,taxE,taxEQ,NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,Dia,Data,...
    TimeUsoRec,ProbXEst,fitnessB,generations,genToWidth,DispMExD,EP,k0,k1,k2,k3)

 
% INICIALIZA POPULA��O QUANTICA. 

[ IQ ] = CreaPoQunniforme(NumTOp,numIQ);                 % IQ uniforme
        
% INICIALIZA POPULA��O CL�SSICA.

if (rem(numIC, numIQ) ~= 0)
    
   error('O n�mero de indiv�duos cl�ssicos deve ser m�ltiplo do n�mero de individuos qu�nticos');

else
    numObsIQ = numIC/numIQ;
end

tic;
        
%[ IC ] = obsIQini( IQ,numIQ,numObsIQ,ProbXEst);        % Observaciones de los IQ garantizando que se mantengan en el rango Prioridad            
[ IC ] = obsIQ( IQ,numIQ,numObsIQ);                     % Observaciones de los IQ

toc;

% PAR�METROS DE INTERESSE

best = linspace(1,NumTOp,NumTOp)';
bestFitness = fitnessB;

trace = zeros(generations,9);


% INICIALIZA LOOPING

for g = 1:generations
    
    
    fitness=zeros(numIC,6); % [fitness,NOFP,TmNOFP,NOE2,NOE3]
                
    for j=1:numIC

        [ fitness(j,1),fitness(j,2),fitness(j,3),fitness(j,4),fitness(j,5),fitness(j,6)] = sch(NumTOp,IC(:,j),NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,Dia,Data,TimeUsoRec,DispMExD,EP,k0,k1,k2,k3);

    end
    
    
    %ATUALIZA POPULA��O B(T)
    
    aux_classic = [best, IC];
    aux_fitness = [bestFitness; fitness];
        
    [~,idx] = sort(aux_fitness(:,1),'ascend');
    fitness=aux_fitness(idx,:);
    rank_classic = aux_classic(:,idx);
        
    %REMOVE INDIV�DUOS MAIS FRACOS (EXCEDENTES)

    IC = rank_classic(:,1:numIC);
    best = IC;
    bestFitness = fitness(1:numIC,:);
            
    % GUARDA MELHOR INDIV�DUO
   
    bestexperimento = IC(:,1);

    % SALVA A GERA��O, FITNESS do Melhor ind., a M�DIA DO FITNESS e a STD DO FITNESS 
        
    trace(g,:) = [g,bestFitness(1,1),mean(bestFitness(:,1)),std(bestFitness(:,1)),bestFitness(1,2),bestFitness(1,3),bestFitness(1,4),bestFitness(1,5),bestFitness(1,6)];
    
    % IMPRIME STATUS DA EVOLU��O
    
    fprintf('Ger: %d - \t Ini: %10.5f - \t Best: %10.5f - \t Mean: %10.5f - \t STD: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t NOE2: %10.5f - \t NOE3: %10.5f \n',...
               g,         fitnessB(1,1),      bestFitness(1,1),mean(bestFitness(:,1)),std(bestFitness(:,1)),bestFitness(1,2),bestFitness(1,3),bestFitness(1,4),bestFitness(1,5),bestFitness(1,6));
    
    % REPOSICIONA PULSOS DE ACORDO COM MELHORES INDIV�DUOS
    
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
        
%        [ IC ] = obsIQini( IQ,numIQ,numObsIQ,ProbXEst);
        [ IC ] = obsIQ( IQ,numIQ,numObsIQ);                     % Observaciones de los IQ
        
        best = best(:,1:(numIC*taxEQ)/100);
        bestFitness = bestFitness(1:(numIC*taxEQ)/100,:);
        
                   
    else
        
        % Crossover clasico         
        [ IC ] = cc( IC,numIC,taxC,NumTOp);
        
        best = best(:,1:(numIC*taxE)/100);
        bestFitness = bestFitness(1:(numIC*taxE)/100,:);
        
    end

end
