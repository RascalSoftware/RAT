function result = makeEmptyResultStruct(nContrasts,nParams,domains)
    % A function to make an empty container to hold the results of
    % reflectivity calculations. The struct has the following format:
    %
    % nParams = number of fitted parameters
    % nContrasts = number of contrasts
    % nDomains = number of domains - 1 for normal, 2 for domains
    %
    % result =
    % 
    %   struct with fields:
    % 
    %       reflectivity: [nContrastsx1 cell]
    %         simulation: [nContrastsx1 cell]
    %        shiftedData: [nContrastsx1 cell]
    %        backgrounds: [nContrastsx1 cell]
    %        resolutions: [nContrastsx1 cell]
    %          layerSlds: [nContrastsxnDomains cell]
    %        sldProfiles: [nContrastsxnDomains cell]
    %    resampledLayers: [nContrastsxnDomains cell]
    % calculationResults: [1x1 struct]
    %     contrastParams: [1x1 struct]
    %          fitParams: [1xnParams double]
    %           fitNames: [nParamsx1 cell]
    
    % -----------------------------------------------------------
    maxArraySize = 10000;

    % Make the individual structs:
    %
    % (1) result.calculationResults

    chiValues = zeros(nContrasts,1);
    coder.varsize('chiValues',[maxArraySize 1],[1 0]);
    
    sumChi = 0;
        
    calculationResults = struct('chiValues', chiValues, 'sumChi', sumChi);
    
    % --------------------------------------------------------------------
    % (2) result.contrastParams

    scalefactors = zeros(nContrasts,1);
    coder.varsize('scalefactors',[maxArraySize 1],[1 0]);
    bulkIn = zeros(nContrasts,1);
    coder.varsize('bulkIn',[maxArraySize 1],[1 0]);
    bulkOut = zeros(nContrasts,1);
    coder.varsize('bulkOut',[maxArraySize 1],[1 0]);
    subRoughs = zeros(nContrasts,1);
    coder.varsize('subRoughs',[maxArraySize 1],[1 0]);
    resample = zeros(1, nContrasts);
    coder.varsize('resample',[1 maxArraySize],[0 1]);
        
    contrastParams = struct('scalefactors', scalefactors, ...
                            'bulkIn', bulkIn, ...
                            'bulkOut', bulkOut, ...
                            'subRoughs', subRoughs, ...
                            'resample', resample);
    
    % -------------------------------------------------------------------
    % Make the final structure...

    reflectivity = cell(nContrasts,1);
    refCell = ones(2,2);
    for i = 1:nContrasts
        reflectivity{i} = refCell;
    end
    coder.varsize('reflectivity{:}',[maxArraySize 2],[1 0]);
    
    simulation = cell(nContrasts,1);
    simCell = ones(2,2);
    for i = 1:nContrasts
        simulation{i} = simCell;
    end
    coder.varsize('simulation{:}',[maxArraySize 2],[1 0]);
    
    shiftedData = cell(nContrasts,1);
    shiftCell = ones(2,3);
    for i = 1:nContrasts
        shiftedData{i} = shiftCell;
    end
    coder.varsize('shiftedData{:}',[maxArraySize 3],[1 0]);

    backgrounds = cell(nContrasts,1);
    backgroundCell = ones(2,3);
    for i = 1:nContrasts
        backgrounds{i} = backgroundCell;
    end
    coder.varsize('backgrounds{:}',[maxArraySize 3],[1 0]);

    resolutions = cell(nContrasts,1);
    resolutionCell = ones(2,2);
    for i = 1:nContrasts
        resolutions{i} = resolutionCell;
    end
    coder.varsize('resolutions{:}',[maxArraySize 2],[1 0]);

    layerSldCell = ones(2,3);
    if domains
        layerSlds = cell(nContrasts,2);
        for i = 1:nContrasts
            layerSlds{i,1} = layerSldCell;
            layerSlds{i,2} = layerSldCell;
        end
    else
        layerSlds = cell(nContrasts,1);
        for i = 1:nContrasts
            layerSlds{i} = layerSldCell;
        end
    end
    coder.varsize('layerSlds{:}',[maxArraySize 4],[1 1]);
    
    sldProfileCell = ones(2,2);
    if domains
        sldProfiles = cell(nContrasts,2);
        for i = 1:nContrasts
            sldProfiles{i,1} = sldProfileCell;
            sldProfiles{i,2} = sldProfileCell;
        end
    else
        sldProfiles = cell(nContrasts,1);
        for i = 1:nContrasts
            sldProfiles{i} = sldProfileCell;
        end
    end
    coder.varsize('sldProfiles{:}',[maxArraySize 3],[1 1]);

    resampledLayersCell = ones(2,3);
    if domains
        resampledLayers = cell(nContrasts,2);
        for i = 1:nContrasts
            resampledLayers{i,1} = resampledLayersCell;
            resampledLayers{i,2} = resampledLayersCell;
        end
    else
        resampledLayers = cell(nContrasts,1);
        for i = 1:nContrasts
            resampledLayers{i} = resampledLayersCell;
        end
    end
    coder.varsize('resampledLayers{:}',[maxArraySize 4],[1 1]);
    
    fitParams = zeros(1,nParams);
    coder.varsize('fitParams',[1 maxArraySize],[0 1]);
    
    fitNames = cell(nParams,1);
    for i = 1:nParams
        fitNames{i} = '';
    end
    coder.varsize('fitNames{:}',[1 maxArraySize],[0 1]);

    result = struct('reflectivity', {reflectivity}, ...
                    'simulation', {simulation}, ...
                    'shiftedData', {shiftedData}, ...
                    'backgrounds', {backgrounds}, ...
                    'resolutions', {resolutions}, ...
                    'layerSlds', {layerSlds}, ...
                    'sldProfiles', {sldProfiles}, ...
                    'resampledLayers', {resampledLayers}, ...
                    'calculationResults', calculationResults, ...
                    'contrastParams', contrastParams, ...
                    'fitParams', fitParams, ...
                    'fitNames', {fitNames});

end
