function [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,SA,AA,AnA,IniSA,EndSA,EndRPxD,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,contDia] = ...
        funcionRP( CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,SA,IniSA,EndSA,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,NumRec,PCPrO,PME,...
        PMA,PMAn,PS,PCPO,PCR,Dia,UltPosRecXDia,TimeUsoCPrO, TimeUsoS,TimeUsoCPO,TimeUsoCR,...
        contDia,tempUltPosRecXDia,uCPrODisp)

% funcionRP: Funcion recursos paralelos.
% Asigna los recursos paralelos a utilizar en la Operacion (ME,MA,MAN,S).

flag = true;
while flag

        auxUPxA = UltPosRecXDia(contDia,sum(NumRec(1:3))+1:sum(NumRec(1:4)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los A.
        [~,allA]=find(PMA(1:end-1)~=0);                               % Busco los posibles Asistentes a usar.
        [~,A]=find(auxUPxA(allA)<=EndCPrOAxD);                        % Veo, dentro de los posibles, cuales estan libre en ese tiempo.

        auxUPxAn = UltPosRecXDia(contDia,sum(NumRec(1:4))+1:sum(NumRec(1:5)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los An.
        [~,allAn]=find(PMAn(1:end-1)~=0);                             % Busco los posibles Anestesistas a usar.
        [~,An]=find(auxUPxAn(allAn)<=EndCPrOAxD);                     % Veo, dentro de los posibles, cuales estan libre en ese tiempo.

        if size(A,2)<PMA(end)||size(An,2)<PMAn(end)

            [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,SA,IniSA,EndSA,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,contDia,tempUltPosRecXDia,uCPrODisp ] = ...
                funcionCPrO( CPrOA, NumRec, PCPrO,PME,PS,PCPO,PCR,Dia,UltPosRecXDia, TimeUsoCPrO, TimeUsoS,TimeUsoCPO,TimeUsoCR,contDia,tempUltPosRecXDia,uCPrODisp);

        else
  

            ADisp = allA(A);
            diff=EndCPrOAxD-auxUPxA(ADisp);
            [~,idx] = sort(diff,'descend');
            sortA = ADisp(idx);
            AA = sortA(1:PMA(end));

            AnDisp = allAn(An);
            diff=EndCPrOAxD-auxUPxAn(AnDisp);
            [~,idx] = sort(diff,'descend');
            sortAn = AnDisp(idx);
            AnA = sortAn(1:PME(end));

            EndRPxD = EndCPrOAxD+TimeUsoS;
            
            flag = false;


        end
    
end    
 
end

