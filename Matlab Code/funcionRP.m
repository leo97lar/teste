function [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,SA,AA,AnA,IniSA,EndSA,EndRPxD,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,contDia] = ...
        funcionRP( CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,SA,IniSA,EndSA,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,NumRec,PCPrO,PME,...
        PMA,PMAn,PS,PCPO,PCR,H,Dia,UltPosRecXDia,TimeUsoCPrO, TimeUsoS,TimeUsoCPO,TimeUsoCR,...
        contDia,tempUltPosRecXDia,DispMExD,DispME)

% funcionRP: Funcion recursos paralelos.
% Asigna los recursos paralelos a utilizar en la Operacion (ME,MA,MAN,S).

uno = 1;
EA = zeros(1,uno, 'int32');
SA = zeros(1,uno, 'int32');

while true

        auxUPxA = UltPosRecXDia(contDia,sum(NumRec(1:3))+1:sum(NumRec(1:4)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los A.
        [~,allA]=find(PMA(1:end-1)~=0);                               % Busco los posibles Asistentes a usar.
        [~,A]=find(auxUPxA(allA)<=EndCPrOAxD);                        % Veo, dentro de los posibles, cuales estan libre en ese tiempo.

        auxUPxAn = UltPosRecXDia(contDia,sum(NumRec(1:4))+1:sum(NumRec(1:5)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los An.
        [~,allAn]=find(PMAn(1:end-1)~=0);                             % Busco los posibles Anestesistas a usar.
        [~,An]=find(auxUPxAn(allAn)<=EndCPrOAxD);                     % Veo, dentro de los posibles, cuales estan libre en ese tiempo.

        if size(A,2)<PMA(end)||size(An,2)<PMAn(end)

            [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,AA,AnA,SA,IniSA,EndSA,EndRPxD,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,contDia ] = ...
                funcionCPrO( NumRec, PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,H,Dia,UltPosRecXDia, TimeUsoCPrO, TimeUsoS,TimeUsoCPO,TimeUsoCR,contDia,tempUltPosRecXDia,DispMExD,DispME);

        else
  
            ADisp = allA(A);
            diff=EndCPrOAxD-auxUPxA(ADisp);
            [~,idx] = sort(diff,'descend');
            sortA = ADisp(idx);
            AA = int32(sortA(1:PMA(end)));

            AnDisp = allAn(An);
            diff=EndCPrOAxD-auxUPxAn(AnDisp);
            [~,idx] = sort(diff,'descend');
            sortAn = AnDisp(idx);
            AnA = int32(sortAn(1:PME(end)));

            EndRPxD = EndCPrOAxD+TimeUsoS;
            
            break

        end
    
end    
 
end

