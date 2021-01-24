function [ Data,Dia ] = Calendario()
% Genero el calendario con las fechas y los horarios desde el 1 de enero
% del 2017 hasta el 31 de diciembre del 2018. Luego elimino los domingos y
% las horas que no se trabajan los sabados.

ctddias = 1:1:31;

diasBase = [ctddias ctddias(1:end-3) ctddias ctddias(1:end-1) ctddias ctddias(1:end-1) ctddias ctddias ctddias(1:end-1) ctddias ctddias(1:end-1) ctddias];

horasBase = 1:1:24;

dias = reshape(repmat(diasBase,length(horasBase),1),length(horasBase)*length(diasBase),1);


mes = [ones(1,length(ctddias))*1, ones(1,length(ctddias(1:end-3)))*2, ones(1,length(ctddias))*3, ones(1,length(ctddias(1:end-1)))*4,...
    ones(1,length(ctddias))*5, ones(1,length(ctddias(1:end-1)))*6, ones(1,length(ctddias))*7, ones(1,length(ctddias))*8, ones(1,length(ctddias(1:end-1)))*9,...
    ones(1,length(ctddias))*10, ones(1,length(ctddias(1:end-1)))*11, ones(1,length(ctddias))*12];

mes = reshape(repmat(mes,length(horasBase),1),length(horasBase)*length(diasBase),1);


ano = [ones(length(dias),1)*2017 ;ones(length(dias),1)*2018];
mes = [mes;mes];
dias = [dias;dias];
horas = repmat(horasBase,1,length(diasBase)*2)';

diaSemana = [1 2 3 4 5 6 7];% [Dom Lun Mar Mier Jue Vier Sab]
diaSemana = repmat(diaSemana,1,105);



diaSemana = diaSemana(1:end-(length(diaSemana)-730));

Dia = [(1:1:size(diaSemana,2))' diaSemana' zeros(size(diaSemana,2),2)];

Dia(2,3) = 32;
Dia(2,4) = Dia(2,3)+12-1;

numDia = 1:1:size(Dia,1);
numDia = reshape(repmat(numDia,length(horasBase),1),length(dias),1);

Data = [dias,mes,ano,horas,numDia];

for i=3:size(Dia,1)
    
    switch Dia(i,2)
                
        case 1
                                    
        case 7
            
            Dia(i,3) = Dia(i-1,3)+24;
            Dia(i,4) = Dia(i,3)+8-1;
            
        otherwise 
            
            if Dia(i,2) == 2
                
                Dia(i,3) = Dia(i-2,3)+48;
                Dia(i,4) = Dia(i,3)+12-1;
                
                
            else
                
                Dia(i,3) = Dia(i-1,3)+24;
                Dia(i,4) = Dia(i,3)+12-1;
                
            end
            
    end
 
end



end

