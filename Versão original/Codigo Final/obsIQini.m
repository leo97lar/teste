function [ newIC ] = obsIQini( IQ,numIQ,numObsIQ,ProbXEst)
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here,
numGen=size(IQ,1)/numIQ;
Lim=zeros(1,length(ProbXEst));

for g=1:length(ProbXEst)
  Lim(g) = numGen*sum(ProbXEst(1:g))/100;
end

List = zeros(numGen,numObsIQ);
newIC = repmat(List,1,numIQ);

for k=1:numIQ
    
    Q = IQ((k-1)*numGen+1:k*numGen,:);

    for u=1:numObsIQ

        Obs = zeros(size(Q));
        Qtem = Q;

        for i=1:numGen

           if i<=Lim(1)
                   Pmax=sum(Qtem(i,1:Lim(1)));
                   
                   idx=find(Qtem(i,1:Lim(1))~=0);
                   Qtem2=Qtem(i,idx);
           elseif i>Lim(1) && i<=Lim(2)
                   Pmax=sum(Qtem(i,1:Lim(2)));
                   
                   idx=find(Qtem(i,Lim(1)+1:Lim(2))~=0);
                   idx=idx+Lim(1);
                   Qtem2=Qtem(i,idx);                   
           elseif i>Lim(2) && i<=Lim(3)
                   Pmax=sum(Qtem(i,1:Lim(3)));
                   
                   idx=find(Qtem(i,Lim(2)+1:Lim(3))~=0);
                   idx=idx+Lim(2);
                   Qtem2=Qtem(i,idx);
           elseif i>Lim(3) && i<=Lim(4)
                   Pmax=sum(Qtem(i,1:Lim(4)));
                   
                   idx=find(Qtem(i,Lim(3)+1:Lim(4))~=0);
                   idx=idx+Lim(3);
                   Qtem2=Qtem(i,idx);
           elseif i>Lim(4) && i<=Lim(5)
                   Pmax=1;
                   
                   idx=find(Qtem(i,Lim(4)+1:end)~=0);
                   idx=idx+Lim(4);
                   Qtem2=Qtem(i,idx);
           end
           
           r=Pmax*rand;
         

           for j=1:length(Qtem2)

               if sum(Qtem2(1:j))<=r && sum(Qtem2(1:j+1))>r
                   Obs(i,idx(j+1))=1;
                   Qtem = Qtem.*(1./(1-Qtem(:,idx(j+1))));
                   Qtem(:,idx(j+1))=0;
                   break
               elseif sum(Qtem2(1:j))>r
                   Obs(i,idx(j))=1;
                   Qtem = Qtem.*(1./(1-Qtem(:,idx(j))));
                   Qtem(:,idx(j))=0;
                   break
               end
           end

        end

    [List(:,u),~]=find(Obs'==1);

    end

newIC(:,(k-1)*numObsIQ+1:k*numObsIQ) = List;
List = zeros(numGen,numObsIQ);

end




end

