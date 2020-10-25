function [ fitness,Tt,NOFP,TmNOFP,NOE2,NOE3] = favalia( schedule,DiaOp,EP,EspMedOp,k0,k1,k2,k3 )

[f,~]=find(schedule~=0);
Tt=max(f,[],1);

EspMedOp(EspMedOp==0)=int32(5);  % Sustituyo el 0 (caso en que solo era necesario un medico) por un valor mayor para que a la hora de buscar el min no afecte el resultado.
minEsp = min(EspMedOp,[],2);

NOE2=size(find(minEsp==2),1);
NOE3=size(find(minEsp==3),1);

DifT=DiaOp-EP;

aux=find(DifT>0);
NOFP = size(aux,1);
TmNOFP = sum(DifT(aux),1)/NOFP;

fitness = Tt + k0*NOFP + k1*TmNOFP + k2*NOE2 + k3*NOE3;
end

