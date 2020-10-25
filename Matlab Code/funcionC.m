function [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,SA,AA,AnA,IniRP,EndRP,EndRPxD,CPOA,IniCPO,EndCPO,CRA,IniCR,EndCR,contDia] = ...
    funcionC(PCPO,PCR,H,EndRP,TimeUsoCPO,TimeUsoCR,PME,PMA,PMAn,PS,CPrOA,IniCPrOA,EndCPrOA,EndCPrOAxD,NumRec, PCPrO, Dia,UltPosRecXDia, ...
    TimeUsoCPrO, TimeUsoS,contDia,filCPrO,tempUltPosRecXDia,EA,SA,AA,AnA,IniRP,EndRPxD,DispMExD,DispME,uCPrODisp)


while true
        [~,C]=find(PCPO~=0);  % Posibles camas a usar
        IniCPO = EndRP+1;
        EndCPO = EndRP+TimeUsoCPO;
        auxH = H(IniCPO:EndCPO,sum(NumRec(1:5))+C);
        [~,auxC] = find(sum(auxH,1)==0);

        [~,R]=find(PCR~=0);  % Posibles camas a usar
        auxHR = H(EndCPO+1:EndCPO+TimeUsoCR,sum(NumRec(1:6))+R);
        [~,auxR] = find(sum(auxHR,1)==0);

        if isempty(auxC) || isempty(auxR)
            CPOA = C(auxC(1));

%            [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,AA,AnA,SA,IniSA,EndSA,EndRPxD,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,contDia ] = ...
%                funcionCPrO(NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,H,Dia,UltPosRecXDia, ...
%                TimeUsoCPrO, TimeUsoS,TimeUsoCPO,TimeUsoCR,contDia,tempUltPosRecXDia,DispMExD,DispME);
%            [ EA,SA,AA,AnA,IniRP,EndRP,EndRPxD,CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,contDia,filCPrO] = ...
%                funcionRP( CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,SA,IniSA,EndSA,CPOA,IniCPOA,EndCPOA,CRA, ...
%                IniCRA,EndCRA,NumRec,PCPrO,PME, PMA,PMAn,PS,PCPO,PCR,Dia,UltPosRecXDia,TimeUsoCPrO, ...
%                TimeUsoS,TimeUsoCPO,TimeUsoCR,contDia,tempUltPosRecXDia,uCPrODisp);

        else
            CPOA = C(auxC(1));
            CRA = R(auxR(1));
            IniCR = EndCPO+1;
            EndCR = EndCPO+TimeUsoCR;
            break
        end

end




end