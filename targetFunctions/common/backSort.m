function [backg,qshift,scalefactor,nba,nbs,resol] = backSort(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutions,backs,shifts,scalefactor,nba,nbs,res)
%     Distributes the background and shift values among the different contrasts
%
%     USAGE::
%
%         [backg,qshift,scalefactor,nba,nbs,resol] = backsort(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutions,backs,shifts,scalefactor,nba,nbs,res)
%
%     INPUTS:
%        * contrastBackgrounds  :         Which backround value is associated with each contrast
%        * contrastQzshifts  :        Which qz_shift value is associated with each contrast
%        * contrastScalefactors  :        Which scalefactor value is associated with each contrast
%        * contrastBulkIns  :          Which NBa value is associated with each contrast
%        * contrastBulkOuts  :          Which Nbs value is associated with each contrast
%        * contrastResolutions  :           Which resolution value is associated with each contrast
%        * backs  :          List of all background values.
%        * shifts  :         List of all qz-shift values
%        * scalefactor :              List of all scalefactor values
%        * nba :             List of all nba values
%        * nbs :             List of all nbs values
%        * res :             List of all resolution values
% 
%     OUTPUTS:
%        * backgs : list of actual background values for each contrast
%        * qshifts : list of actual shift values for each contrast      
%        * scalefactors : list of actual shift values for each contrast     
%        * nbas : list of actual shift values for each contrast     
%        * nbss : list of actual shift values for each contrast
%        * nbss : list of actual shift values for each contrast  
% 
% 
    
    
    
    
    
        
        
            %for i = 1:nc
            %thisBack = contrastBackgrounds(i);
            backg = backs(contrastBackgrounds);
            
            %thisShift = contrastQzshifts(i);
            qshift = shifts(contrastQzshifts);
            
            %thisScale = contrastScalefactors(i);
            scalefactor = scalefactor(contrastScalefactors);
            
            %thisNbair = contrastBulkIns(i);
            nba = nba(contrastBulkIns);
            
            %thisNbsub = contrastBulkOuts(i);
            nbs = nbs(contrastBulkOuts);
            
            %thisResol = contrastResolutions(i);
            if contrastResolutions ~= -1
                resol = res(contrastResolutions);
            else
                resol = -1;     % Negative value means we have a data resolution..
            end
            %end
           
            
    end