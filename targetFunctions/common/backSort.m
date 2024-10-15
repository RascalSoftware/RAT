function [outQzshift,outScalefactor,outBulkIn,outBulkOut,outResolutionParam] = backSort(contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutionParams,qzshifts,scalefactors,bulkIn,bulkOut,resolutionParams)
    % Distributes the background and shift values among the different contrasts
    %
    % INPUTS:
    %    * contrastQzshifts: Which qz_shift value is associated with each contrast
    %    * contrastScalefactors: Which scalefactor value is associated with each contrast
    %    * contrastBulkIns: Which BulkIn value is associated with each contrast
    %    * contrastBulkOuts: Which BulkOut value is associated with each contrast
    %    * contrastResolutionParams: Which resolution value is associated with each contrast
    %    * qzshifts: List of all qzshift values
    %    * scalefactors: List of all scalefactor values
    %    * bulkIn: List of all bulkIn values
    %    * bulkOut: List of all bulkOut values
    %    * resolutionParams: List of all resolution parameter values
    % 
    % OUTPUTS:
    %    * outQzshift: list of actual qzshift values for each contrast      
    %    * outScalefactor: list of actual scalefactor values for each contrast     
    %    * outBulkIn: list of actual bulkIn values for each contrast     
    %    * outBulkOut: list of actual bulkOut values for each contrast
    %    * outResolution: list of actual resolution parameter for each contrast  
    
        outQzshift = qzshifts(contrastQzshifts);
        
        outScalefactor = scalefactors(contrastScalefactors);
        
        outBulkIn = bulkIn(contrastBulkIns);
        
        outBulkOut = bulkOut(contrastBulkOuts);
        
        if contrastResolutionParams ~= -1
            outResolutionParam = resolutionParams(contrastResolutionParams);
        else
            outResolutionParam = -1;     % Negative value means we have a data resolution.
        end

end
