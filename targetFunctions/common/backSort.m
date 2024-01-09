function [outBackgroundParam,outQzshift,outScalefactor,outBulkIn,outBulkOut,outResolutionParam] = backSort(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutions,backgroundParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams)
    % Distributes the background and shift values among the different contrasts
    %
    % USAGE::
    %
    %    [backgroundParams,qzshift,scalefactor,bulkIn,bulkOut,resolutionParams] = backsort(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutions,backs,qzshifts,scalefactor,bulkIn,bulkOut,res)
    %
    % INPUTS:
    %    * contrastBackgrounds: Which background value is associated with each contrast
    %    * contrastQzshifts: Which qz_shift value is associated with each contrast
    %    * contrastScalefactors: Which scalefactor value is associated with each contrast
    %    * contrastBulkIns: Which BulkIn value is associated with each contrast
    %    * contrastBulkOuts: Which BulkOut value is associated with each contrast
    %    * contrastResolutions: Which resolution value is associated with each contrast
    %    * backgroundParams: List of all background values.
    %    * qzshifts: List of all qzshift values
    %    * scalefactors: List of all scalefactor values
    %    * bulkIn: List of all bulkIn values
    %    * bulkOut: List of all bulkOut values
    %    * resolutionParams: List of all resolution values
    % 
    % OUTPUTS:
    %    * outBackground: list of actual background values for each contrast
    %    * outQzshift: list of actual qzshift values for each contrast      
    %    * outScalefactor: list of actual scalefactor values for each contrast     
    %    * outBulkIn: list of actual bulkIn values for each contrast     
    %    * outBulkOut: list of actual bulkOut values for each contrast
    %    * outResolution: list of actual resolution for each contrast  
    
        %for i = 1:nc
        %thisBack = contrastBackgrounds(i);
        outBackgroundParam = backgroundParams(contrastBackgrounds);
        
        %thisShift = contrastQzshifts(i);
        outQzshift = qzshifts(contrastQzshifts);
        
        %thisScale = contrastScalefactors(i);
        outScalefactor = scalefactors(contrastScalefactors);
        
        %thisBulkIn = contrastBulkIns(i);
        outBulkIn = bulkIn(contrastBulkIns);
        
        %thisBulkOut = contrastBulkOuts(i);
        outBulkOut = bulkOut(contrastBulkOuts);
        
        %thisResol = contrastResolutions(i);
        if contrastResolutions ~= -1
            outResolutionParam = resolutionParams(contrastResolutions);
        else
            outResolutionParam = -1;     % Negative value means we have a data resolution..
        end
        %end

end
