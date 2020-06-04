function [backg,qshift,sf,nba,nbs,resol] = backSort(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res)

%Distributes the background and shift values among the different contrasts.
%
%[backgs,qshifts,sfs,nbas,nbss,resols] = backSort(nc,cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res)
% Inputs:
%       nc = number of contrasts (double)
%       cBacks = Which backround value is associated with each contrast?
%       cShifts = Which qz_shift value is associated with each contrast?
%       cScales = Which scalefactor value is associated with each contrast?
%       cNba = Which NBa value is associated with each contrast?
%       cNbs = Which Nbs value is associated with each contrast?
%       cRes = Which resolution value is associated with each contrast?
%       backs = List of all background values.
%       shifts = List of all qz-shift values
%       sf = List of all scalefactor values
%       nba = List of all nba values
%       nbs = List of all nbs values
%       res = List of all resolution values
%
% Outputs:
%       backgs = list of actual background values for each contrast
%       qshifts = list of actual shift values for each contrast      
%       sfs = list of actual shift values for each contrast     
%       nbas = list of actual shift values for each contrast     
%       nbss = list of actual shift values for each contrast
%       nbss = list of actual shift values for each contrast  


% backgs = 0;%zeros(1,nc);
% qshifts = 0;%zeros(1,nc);
% sfs = 0;%zeros(1,nc);
% nbas = 0;%zeros(1,nc);
% nbss = 0;%zeros(1,nc);
% resols = 0;%zeros(1,nc);



%for i = 1:nc
    %thisBack = cBacks(i);
    backg = backs(cBacks);
    
    %thisShift = cShifts(i);
    qshift = shifts(cShifts);
    
    %thisScale = cScales(i);
    sf = sf(cScales);
    
    %thisNbair = cNbas(i);
    nba = nba(cNbas);
    
    %thisNbsub = cNbss(i);
    nbs = nbs(cNbss);
    
    %thisResol = cRes(i);
    resol = res(cRes);
%end
   
    
end
    
    
    
    