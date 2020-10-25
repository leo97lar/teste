function [ IQ ] = CreaPoQunniforme( NumTOp,ctdadIQ )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

Qini = ones(NumTOp,NumTOp)/double(NumTOp);
IQ=repmat(Qini,ctdadIQ,1);

end

