function [ IQact ] = actIQ(IQ,IC,taxAct)
%UNTITLED5 Summary of this function goes here
%   Detailed explanation goes here

%Convertir de numerico a representacion binaria.

num2bin = zeros(size(IC,1)*size(IC,2),size(IC,1));

for i=1:size(num2bin,1)
    num2bin(i,IC(i))=1;
end

IQact = (1-taxAct)*IQ+taxAct*num2bin;

end

