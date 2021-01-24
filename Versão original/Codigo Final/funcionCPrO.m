function [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,AA,AnA,SA,IniSA,EndSA,EndRPxD,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,contDia] = ...
    funcionCPrO(NumRec, PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,H,Dia,UltPosRecXDia, TimeUsoCPrO, TimeUsoS,TimeUsoCPO,TimeUsoCR,contDia,...
    tempUltPosRecXDia,DispMExD,DispME)

flag = true;
while flag
   
        auxUPxR = tempUltPosRecXDia;                    % Selecciono los ultimas posiciones a partir de donde se pueden usar las camas.
        [~,C]=find(PCPrO~=0);                                          % Busco las posibles camas a usar.
        minP = Dia(contDia,4)-Dia(contDia,3)+1-(TimeUsoCPrO+TimeUsoS); % Posicion maxima a partir de la cual se puede colocar la Operacion.
        [~,allC]=find(auxUPxR(C)<=minP);                               % Veo en cuales es posible asignar la operacion.
        
        if isempty(allC)       % Si no es posible asignar ninguna cama incremento el contDia e llamo a funcionDia
            contDia = contDia + 1;
            [contDia,tempUltPosRecXDia,DispME] = funcionDia( NumRec,PCPrO, Dia,UltPosRecXDia,TimeUsoCPrO,TimeUsoS,contDia,DispMExD);
        else
            [~,u]=unique(auxUPxR(C(allC)));
            uCPrODisp=C(allC(u));
            
            
            
            auxUPxE = UltPosRecXDia(contDia,NumRec(1)+1:sum(NumRec(1:2)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los ME.
            auxPME=PME(1:end-1).*DispME;
            [~,allE]=find(auxPME~=0);                               % Busco los posibles Especialistas a usar.
            
            auxUPxA = UltPosRecXDia(contDia,sum(NumRec(1:3))+1:sum(NumRec(1:4)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los A.
            [~,allA]=find(PMA(1:end-1)~=0);                               % Busco los posibles Asistentes a usar.
        
            auxUPxAn = UltPosRecXDia(contDia,sum(NumRec(1:4))+1:sum(NumRec(1:5)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los An.
            [~,allAn]=find(PMAn(1:end-1)~=0);                             % Busco los posibles Anestesistas a usar.
            
            auxUPxS = UltPosRecXDia(contDia,sum(NumRec(1:2))+1:sum(NumRec(1:3)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S.
            [~,allS]=find(PS(1:end)~=0);                                % Busco los posibles Salones a usar.
            
            %auxUPxCPO = UltPosRecXDia(contDia,NumRec(1:5)+1:sum(NumRec(1:6)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los ME.
            [~,allCPO]=find(PCPO(1:end)~=0);                               % Busco los posibles Especialistas a usar.
                
            %auxUPxCR = UltPosRecXDia(contDia,sum(NumRec(1:6))+1:sum(NumRec(1:7)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S.
            [~,allCR]=find(PCR(1:end)~=0);                                % Busco los posibles Salones a usar.
            temCPrO=[];
            
            for j=1:length(uCPrODisp)
                
                EndCPrOAxD = auxUPxR(uCPrODisp(j))+TimeUsoCPrO;
                EndRPxD = EndCPrOAxD+TimeUsoS;
                
                [~,E]=find(auxUPxE(allE)<=EndCPrOAxD);                        % Veo, dentro de los posibles, cuales estan libre en ese tiempo.
                [~,A]=find(auxUPxA(allA)<=EndCPrOAxD);                        % Veo, dentro de los posibles, cuales estan libre en ese tiempo.
                [~,An]=find(auxUPxAn(allAn)<=EndCPrOAxD);                     % Veo, dentro de los posibles, cuales estan libre en ese tiempo.
                [~,S]=find(auxUPxS(allS)<=EndCPrOAxD);                        % Veo, dentro de los posibles, cuales estan libre en ese tiempo.        
            
                if TimeUsoCPO == 0
                    CPO=0;
                    IniCR=Dia(contDia,3)+EndCPrOAxD+TimeUsoS;
                    [~,CR]=find(sum(H(IniCR:IniCR+TimeUsoCR-1,sum(NumRec(1:6))+allCR))==0);
                else
                    IniCPO=Dia(contDia,3)+EndCPrOAxD+TimeUsoS;
                    EndCPO=IniCPO+TimeUsoCPO-1;
                    [~,CPO]=find(sum(H(IniCPO:EndCPO,sum(NumRec(1:5))+allCPO))==0);                        % Veo, dentro de los posibles, cuales estan libre en ese tiempo.
                    [~,CR]=find(sum(H(EndCPO+1:EndCPO+TimeUsoCR,sum(NumRec(1:6))+allCR))==0);
                    
                end
                
                if ~isempty(CPO)&&~isempty(CR)&&~isempty(S)&&size(E,2)>=PME(end)&&size(A,2)>=PMA(end)&&size(An,2)>=PMAn(end)
                    temCPrO = uCPrODisp(j);
                    break;
                end
                                      
            end

            if isempty(temCPrO)
                
                tempUltPosRecXDia = tempUltPosRecXDia+1;
                                
            else
                
                CPrOA = temCPrO;
                IniCPrOA = Dia(contDia,3)+auxUPxR(CPrOA);
                EndCPrOA = IniCPrOA + TimeUsoCPrO-1;
                
                SA = allS(S(1));
                IniSA = EndCPrOA+1;
                EndSA = IniSA+TimeUsoS-1;
                
                EA = allE(E(1:PME(end)));
                
                AA = allA(A(1:PMA(end)));
                
                AnA = allAn(An(1:PMAn(end)));
                
                if TimeUsoCPO==0
                    CPOA = 0;
                    IniCPOA = 0;
                    EndCPOA = 0;
                    
                    CRA = allCR(CR(1));
                    IniCRA = EndSA+1;
                    EndCRA = IniCRA + TimeUsoCR-1;
                else
                    CPOA = allCPO(CPO(1));
                    IniCPOA = EndSA+1;
                    EndCPOA = IniCPOA + TimeUsoCPO-1;

                    CRA = allCR(CR(1));
                    IniCRA = EndCPOA+1;
                    EndCRA = IniCRA + TimeUsoCR-1;
                end
                                                
                flag = false;
            end
            
        end
    
end

end

