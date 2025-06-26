function [qzshifts,scalefactors,bulkIns,bulkOuts] = backSort(qzshiftIndices,scalefactorIndices,bulkInIndices,bulkOutIndices,qzshiftValues,scalefactorValues,bulkInValues,bulkOutValues)
    % Distributes the background and shift values among the different contrasts
    %
    % INPUTS:
    %    * qzshiftIndices: Indices of the qzshift values associated with each contrast
    %    * scalefactorIndices: Indices of the scalefactor values associated with each contrast
    %    * bulkInIndices: Indices of the BulkIn values associated with each contrast
    %    * bulkOutIndices: Indices of the BulkOut values associated with each contrast
    %    * qzshiftValues: List of all qzshift values
    %    * scalefactorValues: List of all scalefactor values
    %    * bulkInValues: List of all bulk In values
    %    * bulkOutValues: List of all bulk Out values
    % 
    % OUTPUTS:
    %    * qzshifts: qzshift value for each contrast      
    %    * scalefactors: scalefactor value for each contrast     
    %    * bulkIns: bulk In value for each contrast     
    %    * bulkOuts: bulk Out value for each contrast

        qzshifts = qzshiftValues(qzshiftIndices)';
        scalefactors = scalefactorValues(scalefactorIndices)';
        bulkIns = bulkInValues(bulkInIndices)';
        bulkOuts = bulkOutValues(bulkOutIndices)';

end
