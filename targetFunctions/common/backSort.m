function [outBackground,outQzshift,outScalefactor,outBulkIn,outBulkOut,outResolution] = backSort(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutions,backs,qzshifts,scalefactor,bulkIn,bulkOut,res)
%     Distributes the background and shift values among the different contrasts
%
%     USAGE::
%
%         [backg,qzshift,scalefactor,nba,nbs,resol] = backsort(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutions,backs,shifts,scalefactor,nba,nbs,res)
%
%     INPUTS:
%        * contrastBackgrounds  :     Which backround value is associated with each contrast
%        * contrastQzshifts  :        Which qz_shift value is associated with each contrast
%        * contrastScalefactors  :    Which scalefactor value is associated with each contrast
%        * contrastBulkIns  :         Which NBa value is associated with each contrast
%        * contrastBulkOuts  :        Which Nbs value is associated with each contrast
%        * contrastResolutions  :     Which resolution value is associated with each contrast
%        * backs  :                   List of all background values.
%        * shifts  :                  List of all qzshift values
%        * scalefactor :              List of all scalefactor values
%        * bulkIn :                   List of all bulkIn values
%        * bulkOut :                  List of all bulkOut values
%        * res :                      List of all resolution values
% 
%     OUTPUTS:
%        * backgs : list of actual background values for each contrast
%        * qzshifts : list of actual shift values for each contrast      
%        * scalefactors : list of actual shift values for each contrast     
%        * nbas : list of actual shift values for each contrast     
%        * nbss : list of actual shift values for each contrast
%        * nbss : list of actual shift values for each contrast  
% 
% 
    
    
    
    
    
        
        
            %for i = 1:nc
            %thisBack = contrastBackgrounds(i);
            outBackground = backs(contrastBackgrounds);
            
            %thisShift = contrastQzshifts(i);
            outQzshift = qzshifts(contrastQzshifts);
            
            %thisScale = contrastScalefactors(i);
            outScalefactor = scalefactor(contrastScalefactors);
            
            %thisNbair = contrastBulkIns(i);
            outBulkIn = bulkIn(contrastBulkIns);
            
            %thisNbsub = contrastBulkOuts(i);
            outBulkOut = bulkOut(contrastBulkOuts);
            
            %thisResol = contrastResolutions(i);
            if contrastResolutions ~= -1
                outResolution = res(contrastResolutions);
            else
                outResolution = -1;     % Negative value means we have a data resolution..
            end
            %end
           
            
    end