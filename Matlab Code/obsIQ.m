function [ newIC ] = obsIQ( IQ,numIQ,numObsIQ )
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here,
numGen=size(IQ,1)/numIQ;

List = zeros(numGen,numObsIQ, 'int32');
newIC = repmat(List,1,numIQ);

for k=1:numIQ
    
    Q = IQ((k-1)*numGen+1:k*numGen,:);

    for u=1:numObsIQ

        Obs = zeros(size(Q), 'int32');
        Qtem = Q;

        for i=1:numGen

           idx=find(Qtem(i,:)~=0);
           Qtem2=Qtem(i,idx);
           r=rand;
                      
           for j=1:length(Qtem2)
               if sum(Qtem2(1:j),2)>r
                   Obs(i,idx(j))=int32(1);
                   Qtem = (Qtem).*repmat((1./(1-Qtem(:,idx(j)))), 1, size(Qtem, 2));
                   Qtem(:,idx(j))=0;
                   break
               elseif sum(Qtem2(1:j),2)<=r && sum(Qtem2(1:j+1),2)>r
                   Obs(i,idx(j+1))=int32(1);
                   Qtem = Qtem.*repmat((1./(1-Qtem(:,idx(j+1)))), 1, size(Qtem, 2));
                   Qtem(:,idx(j+1))=0;
                   break
               end
           end

        end

    [List(:,u),~]=find(Obs'==1);

    end

newIC(:,(k-1)*numObsIQ+1:k*numObsIQ) = List;
List = zeros(numGen,numObsIQ, 'int32');

end

end

