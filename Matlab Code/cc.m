function [ newIC ] = cc( IC,numIC,taxC,NumTOp)
 
        
        newIC = zeros(NumTOp,numIC, 'int32');
        flag=false;
        j=1;
%       SOMENTE OS PESOS E FUNÇÕES DE ATIVAÇÃO CUJOS NEURONIOS ESTEJAM ATIVADOS SERÃO ATUALIZADOS COM CROSSOVER.
        while j<=numIC/2
            
            while true
                % parâmetros para o cruzamento
                escolhidos=randi(numIC,2,1); 
                escolhido_1 = int32(IC(:,min(escolhidos)));    %  1º indivíduo escolhido


                escolhidos=randi(numIC,2,1); 
                escolhido_2 = int32(IC(:,min(escolhidos)));    %  2º indivíduo escolhido
                if sum((escolhido_1==escolhido_2),1)~=NumTOp
                    break;
                end
            
            end
                        
            cc=rand;
            
            
            if cc < taxC
            
                % Cruzamiento
            
                mskReal = int32(round(rand(NumTOp,1))); % quais parâmetros reais serão alterados
                
                tempF1 = escolhido_1.*mskReal;
                tempF1(tempF1==0) = [];

                tempF2 = escolhido_2.*mskReal;
                tempF2(tempF2==0) = [];

                [~,idx2] = sort(escolhido_2,'ascend');
                [~,idx1] = sort(escolhido_1,'ascend');

                [~,idxx1] = sort(idx2(tempF1),'ascend');
                [~,idxx2] = sort(idx1(tempF2),'ascend');

                escolhido_1(mskReal~=0)=tempF1(idxx1);
                escolhido_2(mskReal~=0)=tempF2(idxx2);
            end
            
            if j==1
                newIC(:,j-1+j:2*j)=[escolhido_1,escolhido_2];
                j=j+1;
            else
                for k=1:(j-1)*2
                    if sum((escolhido_1==newIC(:,k)),1)==NumTOp || sum((escolhido_2==newIC(:,k)),1)==NumTOp
                       flag=true;
                       break;
                    end
                end
                if flag
                    flag=false;
                else
                    newIC(:,j-1+j:2*j)=[escolhido_1,escolhido_2];
                    j=j+1;
                end
            end
       end  
end

