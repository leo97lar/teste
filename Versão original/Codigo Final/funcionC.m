function [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,SA,AA,AnA,IniRP,EndRP,EndRPxD,CPOA,IniCPO,EndCPO,CRA,IniCR,EndCR,contDia] = ...
    funcionC(PCPO,PCR,H,EndRP,TimeUsoCPO,TimeUsoCR,PME,PMA,PMAn,PS,CPrOA,IniCPrOA,EndCPrOA,EndCPrOAxD,NumRec, PCPrO, Dia,UltPosRecXDia, ...
    TimeUsoCPrO, TimeUsoS,contDia,filCPrO,tempUltPosRecXDia,EA,SA,AA,AnA,IniRP,EndRPxD)

flag=true;

while flag
        [~,C]=find(PCPO~=0);  % Posibles camas a usar
        IniCPO = EndRP+1;
        EndCPO = EndRP+TimeUsoCPO;
        auxH = H(IniCPO:EndCPO,sum(NumRec(1:5))+C);
        [~,auxC] = find(sum (auxH,1)==0);

        [~,R]=find(PCR~=0);  % Posibles camas a usar
        auxHR = H(EndCPO+1:EndCPO+TimeUsoCR,sum(NumRec(1:6))+R);
        [~,auxR] = find(sum (auxHR,1)==0);

        if isempty(auxC) || isempty(auxR)

            [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD, contDia,filCPrO,tempUltPosRecXDia ] = ...
                funcionCPrO( CPrOA, NumRec, PCPrO,PME,PS,Dia, UltPosRecXDia, TimeUsoCPrO, ...
                TimeUsoS,contDia,filCPrO,tempUltPosRecXDia);
            [ EA,SA,AA,AnA,IniRP,EndRP,EndRPxD,CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,contDia,filCPrO] = ...
                funcionRP( PME,PMA,PMAn,PS,CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,NumRec, PCPrO, Dia,...
                UltPosRecXDia, TimeUsoCPrO, TimeUsoS,contDia,filCPrO,tempUltPosRecXDia);

        else
            CPOA = C(auxC(1));
            CRA = R(auxR(1));
            IniCR = EndCPO+1;
            EndCR = EndCPO+TimeUsoCR;
            flag=false;
        end

end




end