function [ Edade ] = Edade( min,max,Num )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
PEd= min:1:max;

CtdPtos = max-min+1;

CtdadXStep= ((CtdPtos-1)*CtdPtos)/2;

n=1/(CtdadXStep*2);

pIni = (1-CtdadXStep*n)/CtdPtos;
pFim = pIni+n*(max-min);
ProbXEdade = linspace(double(pIni), double(pFim), double(CtdPtos));

Edade = zeros(Num,1);

for i=1:Num
    
    r=rand;
    
    for j=1:length(ProbXEdade)

        if sum(ProbXEdade(1:j),2)<=r && sum(ProbXEdade(1:j+1),2)>r
            Edade(i)=PEd(j+1);
            break
        elseif ProbXEdade>r
            Edade(i)=PEd(j);
            break
        end
    end
    
    
end



end

