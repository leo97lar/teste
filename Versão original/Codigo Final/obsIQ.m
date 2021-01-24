function [ newIC ] = obsIQ( IQ,numIQ,numObsIQ )
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here,
numGen=size(IQ,1)/numIQ;

List = zeros(numGen,numObsIQ);
newIC = repmat(List,1,numIQ);

for k=1:numIQ
    
    Q = IQ((k-1)*numGen+1:k*numGen,:);

    for u=1:numObsIQ

        Obs = zeros(size(Q));
        Qtem = Q;

        for i=1:numGen

           idx=find(Qtem(i,:)~=0);
           Qtem2=Qtem(i,idx);
           r=rand;
                      
           for j=1:length(Qtem2)
               if sum(Qtem2(1:j))>r
                   Obs(i,idx(j))=1;
                   Qtem = Qtem.*(1./(1-Qtem(:,idx(j))));
                   Qtem(:,idx(j))=0;
                   break
               elseif sum(Qtem2(1:j))<=r && sum(Qtem2(1:j+1))>r
                   Obs(i,idx(j+1))=1;
                   Qtem = Qtem.*(1./(1-Qtem(:,idx(j+1))));
                   Qtem(:,idx(j+1))=0;
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

