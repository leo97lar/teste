function [ schedule,DiaOp,EspMedOp ] = casorandom(NumTOp,H,NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,Dia,UltPosRecXDia,TimeUsoRec,DispMExD)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
%    NCPrO  |    NME    |     NS    |     NA    |     NAn    |    NCPO     |   NCR
%  Col 1-20 | Col 21-50 | Col 51-62 | Col 63-87 | Col 88-112 | Col 113-132 | Col 133-172

DiaOp = zeros(NumTOp,1, 'int32');
EspMedOp = zeros(NumTOp,2, 'int32');

for i=1:NumTOp
      
    contDia = int32(2);
        
    [contDia,tempUltPosRecXDia,DispME] = funcionDia( NumRec,PCPrO(i,:), Dia,UltPosRecXDia,...
        TimeUsoRec(i,1),TimeUsoRec(i,2),contDia,DispMExD);
    
    [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,AA,AnA,SA,IniSA,EndSA,EndRPxD,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,contDia] = ...
        funcionCPrO( NumRec,PCPrO(i,:), PME(i,:),PMA(i,:),PMAn(i,:),PS(i,:),PCPO(i,:),PCR(i,:),H,Dia, UltPosRecXDia,...
        TimeUsoRec(i,1), TimeUsoRec(i,2),TimeUsoRec(i,6),TimeUsoRec(i,7),contDia,tempUltPosRecXDia,DispMExD,DispME);
    
    DiaOp(i)=contDia;
    
    H(IniCPrOA:EndCPrOA,CPrOA)=i;
    UltPosRecXDia(contDia,CPrOA)=EndCPrOAxD;
    
    H(IniSA:EndSA,NumRec(1)+NumRec(2)+int32(SA))=i;
    UltPosRecXDia(contDia,NumRec(1)+NumRec(2)+int32(SA))=EndRPxD;
    
    for j=1:size(EA,2)
        
        H(IniSA:EndSA,NumRec(1)+EA(j))=i;
        UltPosRecXDia(contDia,NumRec(1)+EA(j))=EndRPxD;
        
        EspMedOp(i,j)=PME(i,EA(j));
       
    end
    
    for j=1:size(AA,2)
        
        H(IniSA:EndSA,NumRec(1)+NumRec(2)+NumRec(3)+AA(j))=i;
        UltPosRecXDia(contDia,NumRec(1)+NumRec(2)+NumRec(3)+AA(j))=EndRPxD;
       
    end
    
    for j=1:size(AnA,2)
        
        H(IniSA:EndSA,NumRec(1)+NumRec(2)+NumRec(3)+NumRec(4)+AnA(j))=i;
        UltPosRecXDia(contDia,NumRec(1)+NumRec(2)+NumRec(3)+NumRec(4)+AnA(j))=EndRPxD;
       
    end
    
    if IniCPOA == 0
        H(IniCRA:EndCRA,sum(NumRec(1:6))+CRA)=i;
    else
        H(IniCPOA:EndCPOA,sum(NumRec(1:5))+CPOA)=i;
        H(IniCRA:EndCRA,sum(NumRec(1:6))+CRA)=i;
    end
    
    
end
    
   schedule=H;

end

