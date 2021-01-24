function [contDia,tempUltPosRecXDia,DispME] = funcionDia( NumRec,PCPrO, Dia,UltPosRecXDia, TimeUsoCPrO, TimeUsoS,contDia,DispMExD)
% NumCPrO: Numero de camas PreOperatorias.
% PCPrO: Posibles camas PreOperatorias para esa operacion.
% Dia: Matriz con el cosecutivo de dias y el dia de la semana. Ademas tiene
% los indices donde empieza y termina cada dia de la matriz Data(Ver main_UCI).
% UltPosRecXDia: Ultima posicion asignado del recurso por Dia.
% Time: El tiempo de uso de la Cama PrO mas el tiempo de operacion.
% contDia: Contador de dia.

flag=true;

while flag==true
    if Dia(contDia,3)==0
            contDia = contDia + 1;
    else
        auxUPxR = UltPosRecXDia(contDia,1:NumRec(1));  % Selecciono los ultimas posiciones a partir de donde se pueden usar las camas.
        minP = Dia(contDia,4)-Dia(contDia,3)+1-(TimeUsoCPrO+TimeUsoS); % Posicion maxima a partir de la cual se puede colocar la Operacion
        
        auxUPxS = UltPosRecXDia(contDia,sum(NumRec(1:2))+1:sum(NumRec(1:3)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S.
        [~,c]=find(Dia(contDia,4)-Dia(contDia,3)+1-auxUPxS>=TimeUsoS);            
        
        if sum(minP>=auxUPxR(PCPrO==1))~=0 && ~isempty(c)           % Compruebo que cabe en alguna pocision de las posibles, si no cabe incremento el dia.
            tempUltPosRecXDia = auxUPxR;
            flag=false;
        else
            contDia = contDia + 1;
        end
  
    end
    
end

switch Dia(contDia,2)
    case 2
        DispME=DispMExD(1,:);    
    case 3
        DispME=DispMExD(2,:);
    case 4
        DispME=DispMExD(3,:);
    case 5
        DispME=DispMExD(4,:);
    case 6
        DispME=DispMExD(5,:);
    case 7
        DispME=DispMExD(6,:);
end
    
  
end

