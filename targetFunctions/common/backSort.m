function [qzshift,scalefactor,bulkIn,bulkOut] = backSort(qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex,qzshiftValues,scalefactorValues,bulkInValues,bulkOutValues)
    % Distributes the background and shift values among the different contrasts
    %
    % INPUTS:
    %    * qzshiftIndex: Index of the qzshift value associated with this contrast
    %    * scalefactorIndex: Index of the scalefactor value  associated with this contrast
    %    * bulkInIndex: Index of the BulkIn value associated with this contrast
    %    * bulkOutIndex: Index of the BulkOut value associated with this contrast
    %    * qzshiftValues: List of all qzshift values
    %    * scalefactorValues: List of all scalefactor values
    %    * bulkInValues: List of all bulk In values
    %    * bulkOutValues: List of all bulk Out values
    % 
    % OUTPUTS:
    %    * qzshift: qzshift value for this contrast      
    %    * scalefactor: scalefactor value for this contrast     
    %    * bulkIn: bulk In value for this contrast     
    %    * bulkOut: bulk Out value for this contrast
    
        qzshift = qzshiftValues(qzshiftIndex);        
        scalefactor = scalefactorValues(scalefactorIndex);        
        bulkIn = bulkInValues(bulkInIndex);
        bulkOut = bulkOutValues(bulkOutIndex);

end
