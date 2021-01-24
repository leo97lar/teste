function [ Edade ] = Edade( min,max,Num )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
PEd= min:1:max;

CtdPtos = max-min+1;

CtdadXStep= ((CtdPtos-1)*CtdPtos)/2;

n=1/(CtdadXStep*2);

pIni = (1-CtdadXStep*n)/CtdPtos;

ProbXEdade=pIni;

for i=1:max-min
    
    aux=ProbXEdade(end)+n;
    
    ProbXEdade=[ProbXEdade aux];
    
end

Edade = zeros(Num,1);

for i=1:Num
    
    r=rand;
    
    for j=1:length(ProbXEdade)

        if sum(ProbXEdade(1:j))<=r && sum(ProbXEdade(1:j+1))>r
            Edade(i)=PEd(j+1);
            break
        elseif ProbXEdade>r
            Edade(i)=PEd(j);
            break
        end
    end
    
    
end



end

