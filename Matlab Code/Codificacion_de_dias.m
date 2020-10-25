% Para creer mi Horario codificado desde el 1ro de enero del 2017 hasta el 31 de diciembre del 2018
clear all;
close all;
clc;

ctddias = linspace(1,31,31);

diasBase = [ctddias ctddias(1:end-3) ctddias ctddias(1:end-1) ctddias ctddias(1:end-1) ctddias ctddias ctddias(1:end-1) ctddias ctddias(1:end-1) ctddias];

horasBase = [8 8.5 9 9.5 10 10.5 11 11.5 12 12.5 13 13.5 14 14.5 15 15.5 16 16.5 17 17.5 18 18.5 19 19.5];

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
diaSemana = reshape(repmat(diaSemana,length(horasBase),1),length(horasBase)*length(diasBase)*2,1);

Data = [dias,mes,ano,horas,diaSemana];


Data(Data(:,end)==1,:)=[];

Data(Data(:,end)==7 & Data(:,end-1)>=16,:)=[];

