function result = makeEmptyResultStruct(nContrasts,nParams,domains)
    % A function to make an empty container to hold the results of
    % reflectivity calculations. The struct has the following format:
    %
    % nPar = number of fitted parameters
    % nContrasts = number of contrasts
    %
    % result = 
    % 
    %   struct with fields:
    % 
    %       reflectivity: [nContrastsx1 cell]
    %         simulation: [nContrastsx1 cell]
    %        shiftedData: [nContrastsx1 cell]
    %          layerSlds: [nContrastsx1 cell]
    %        sldProfiles: [nContrastsx1 cell]
    %    resampledLayers: [nContrastsx1 cell]
    % calculationResults: [1x1 struct]
    %     contrastParams: [1x1 struct]
    %          fitParams: [1xnParams double]
    %           fitNames: [nParamsx1 cell]
    
    % -----------------------------------------------------------
    % Make the individual structs....
    % (1) result.calculationResults

    chiValues = zeros(nContrasts,1);
    coder.varsize('chiValues',[1e7 1],[1 0]);
    
    sumChi = 0;
        
    calculationResults = struct('chiValues', chiValues, 'sumChi', sumChi);
    
    % --------------------------------------------------------------------
    % (2) result.contrastParams

    backgroundParams = zeros(nContrasts,1);
    coder.varsize('backgroundParams',[100 1],[1 0]);
    scalefactors = zeros(nContrasts,1);
    coder.varsize('scalefactors',[100 1],[1 0]);
    bulkIn = zeros(nContrasts,1);
    coder.varsize('bulkIn',[100 1],[1 0]);
    bulkOut = zeros(nContrasts,1);
    coder.varsize('bulkOut',[100 1],[1 0]);
    resolutionParams = zeros(nContrasts,1);
    coder.varsize('resolutionParams',[100 1],[1 0]);
    subRoughs = zeros(nContrasts,1);
    coder.varsize('subRoughs',[100 1],[1 0]);
    resample = zeros(1, nContrasts);
    coder.varsize('resample',[1 100],[0 1]);
        
    contrastParams = struct('backgroundParams', backgroundParams, ...
                            'scalefactors', scalefactors, ...
                            'bulkIn', bulkIn, ...
                            'bulkOut', bulkOut, ...
                            'resolutionParams', resolutionParams, ...
                            'subRoughs', subRoughs, ...
                            'resample', resample);
    
    % -------------------------------------------------------------------
    % Make the final structure...

    reflectivity = cell(nContrasts,1);
    refCell = [1 1; 1 1];
    coder.varsize('refCell',[10000 2],[1 0]);
    for i = 1:nContrasts
        reflectivity{i} = refCell;
    end
    
    simulation = cell(nContrasts,1);
    simCell = [1 1; 1 1];
    coder.varsize('simCell',[10000 2],[1 0]);
    for i = 1:nContrasts
        simulation{i} = simCell;
    end
    
    shiftedData = cell(nContrasts,1);
    shiftCell = [1 1 1; 1 1 1];
    coder.varsize('shiftCell',[10000 3],[1 0]);
    for i = 1:nContrasts
        shiftedData{i} = shiftCell;
    end
    
    if domains
        layerSlds = cell(nContrasts,2);
        domainLayerSldCell = [1 1 1; 1 1 1];
        coder.varsize('domainLayerSldCell',[10000 6],[1 1]);
        for i = 1:nContrasts
            layerSlds{i,1} = domainLayerSldCell;
            layerSlds{i,2} = domainLayerSldCell;
        end
    else
        layerSlds = cell(nContrasts,1);
        layerSldCell = [1 1 1; 1 1 1];
        coder.varsize('layerSldCell',[10000 6],[1 1]);
        for i = 1:nContrasts
            layerSlds{i} = layerSldCell;
        end
    end
    

    if domains
        sldProfiles = cell(nContrasts,2);
        domainSldProfileCell = [1 1; 1 1];
        coder.varsize('domainSldProfileCell',[10000 2],[1 1]);
        for i = 1:nContrasts
            sldProfiles{i,1} = domainSldProfileCell;
            sldProfiles{i,2} = domainSldProfileCell;
        end
    else
        sldProfiles = cell(nContrasts,1);
        sldProfileCell = [1 1; 1 1];
        coder.varsize('sldProfileCell',[10000 2],[1 0]);
        for i = 1:nContrasts
            sldProfiles{i,1} = sldProfileCell;
        end
    end   

    if domains
        resampledLayers = cell(nContrasts,2);
        domainResampledLayersCell = [1 1 1; 1 1 1];
        coder.varsize('domainResampledLayersCell',[10000 3],[1 0]);
        for i = 1:nContrasts
            resampledLayers{i,1} = domainResampledLayersCell;
            resampledLayers{i,2} = domainResampledLayersCell;
        end
    else
        resampledLayers = cell(nContrasts,1);
        resampledLayersCell = [1 1 1; 1 1 1];
        coder.varsize('resampledLayersCell',[10000 3],[1 0]);
        for i = 1:nContrasts
            resampledLayers{i} = resampledLayersCell;
        end
    end
    
    fitParams = zeros(1,nParams);
    coder.varsize('fitParams',[1 100],[0 1]);
    
    fitNames = cell(nParams,1);
    fitNamesChar = '';
    coder.varsize('fitNamesChar',[1 100],[0 1]);
    for i = 1:nParams
        fitNames{i} = fitNamesChar;
    end

    result = struct('reflectivity', {reflectivity}, ...
                    'simulation', {simulation}, ...
                    'shiftedData', {shiftedData}, ...
                    'layerSlds', {layerSlds}, ...
                    'sldProfiles', {sldProfiles}, ...
                    'resampledLayers', {resampledLayers}, ...
                    'calculationResults', calculationResults, ...
                    'contrastParams', contrastParams, ...
                    'fitParams', fitParams, ...
                    'fitNames', {fitNames});

end
