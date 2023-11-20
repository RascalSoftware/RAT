function [backg,qshift,sf,nba,nbs,resol] = backSort(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res)
%     Distributes the background and shift values among the different contrasts
%
%     USAGE::
%
%         [backg,qshift,sf,nba,nbs,resol] = backsort(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res)
%
%     INPUTS:
%        * cBacks  :         Which backround value is associated with each contrast
%        * cShifts  :        Which qz_shift value is associated with each contrast
%        * cScales  :        Which scalefactor value is associated with each contrast
%        * cNbas  :          Which NBa value is associated with each contrast
%        * cNbss  :          Which Nbs value is associated with each contrast
%        * cRes  :           Which resolution value is associated with each contrast
%        * backs  :          List of all background values.
%        * shifts  :         List of all qz-shift values
%        * sf :              List of all scalefactor values
%        * nba :             List of all nba values
%        * nbs :             List of all nbs values
%        * res :             List of all resolution values
% 
%     OUTPUTS:
%        * backgs : list of actual background values for each contrast
%        * qshifts : list of actual shift values for each contrast      
%        * sfs : list of actual shift values for each contrast     
%        * nbas : list of actual shift values for each contrast     
%        * nbss : list of actual shift values for each contrast
%        * nbss : list of actual shift values for each contrast  
% 
% 
    
    
    
    
    
        
        
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
            if cRes ~= -1
                resol = res(cRes);
            else
                resol = -1;     % Negative value means we have a data resolution..
            end
            %end
           
            
    end