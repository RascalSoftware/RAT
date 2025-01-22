function [outQzshift,outScalefactor,outBulkIn,outBulkOut] = backSort(contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,qzshifts,scalefactors,bulkIn,bulkOut)
    % Distributes the background and shift values among the different contrasts
    %
    % INPUTS:
    %    * contrastQzshifts: Which qz_shift value is associated with each contrast
    %    * contrastScalefactors: Which scalefactor value is associated with each contrast
    %    * contrastBulkIns: Which BulkIn value is associated with each contrast
    %    * contrastBulkOuts: Which BulkOut value is associated with each contrast
    %    * qzshifts: List of all qzshift values
    %    * scalefactors: List of all scalefactor values
    %    * bulkIn: List of all bulkIn values
    %    * bulkOut: List of all bulkOut values
    % 
    % OUTPUTS:
    %    * outQzshift: list of actual qzshift values for each contrast      
    %    * outScalefactor: list of actual scalefactor values for each contrast     
    %    * outBulkIn: list of actual bulkIn values for each contrast     
    %    * outBulkOut: list of actual bulkOut values for each contrast
    
        outQzshift = qzshifts(contrastQzshifts);        
        outScalefactor = scalefactors(contrastScalefactors);        
        outBulkIn = bulkIn(contrastBulkIns);
        outBulkOut = bulkOut(contrastBulkOuts);

end
