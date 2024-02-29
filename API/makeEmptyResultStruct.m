function result = makeEmptyResultStruct(nContrasts,nPars,domains)
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
    %          allLayers: [nContrastsx1 cell]
    % calculationResults: [1x1 struct]
    %     contrastParams: [1x1 struct]
    %        bestFitPars: [1xnPars double]
    %           fitNames: [nParsx1 cell]
    
    % -----------------------------------------------------------
    % Make the individual structs....
    % (1) result.calculationResults

    allChis = zeros(nContrasts,1);
    coder.varsize('allChis',[1e7 1],[1 0]);
    
    sumChi = 0;
        
    calculationResults = struct('allChis', allChis, 'sumChi', sumChi);
    
    % --------------------------------------------------------------------
    % (2) result.contrastParams

    ssubs = zeros(nContrasts,1);
    coder.varsize('ssubs',[10000 1],[1 0]);
    backgroundParams = zeros(nContrasts,1);
    coder.varsize('backgroundParams',[10000 1],[1 0]);
    qzshifts = zeros(nContrasts,1);
    coder.varsize('qzshifts',[10000 1],[1 0]);
    scalefactors = zeros(nContrasts,1);
    coder.varsize('scalefactors',[10000 1],[1 0]);
    bulkIn = zeros(nContrasts,1);
    coder.varsize('bulkIn',[10000 1],[1 0]);
    bulkOut = zeros(nContrasts,1);
    coder.varsize('bulkOut',[10000 1],[1 0]);
    resolutionParams = zeros(nContrasts,1);
    coder.varsize('resolutionParams',[10000 1],[1 0]);
    allSubRough = zeros(nContrasts,1);
    coder.varsize('allSubRough',[10000 1],[1 0]);
    resample = zeros(1, nContrasts);
    coder.varsize('resample',[1 10000],[0 1]);
        
    contrastParams = struct('ssubs',ssubs, ...
                            'backgroundParams', backgroundParams, ...
                            'qzshifts', qzshifts, ...
                            'scalefactors', scalefactors, ...
                            'bulkIn', bulkIn, ...
                            'bulkOut', bulkOut, ...
                            'resolutionParams', resolutionParams, ...
                            'allSubRough', allSubRough, ...
                            'resample', resample);
    
    % -------------------------------------------------------------------
    % Make the final structure...

    reflectivity = cell(nContrasts,1);
    refCell = [1 1 ; 1 1];
    coder.varsize('refCell',[10000 2],[1 0]);
    for i = 1:nContrasts
        reflectivity{i} = refCell;
    end
    
    simulation = cell(nContrasts,1);
    simCell = [1 1 ; 1 1];
    coder.varsize('simCell',[10000 2],[1 0]);
    for i = 1:nContrasts
        simulation{i} = simCell;
    end
    
    shiftedData = cell(nContrasts,1);
    shiftCell = [1 1 1 ; 1 1 1];
    coder.varsize('shiftCell',[10000 3],[1 0]);
    for i = 1:nContrasts
        shiftedData{i} = shiftCell;
    end
    
    if domains
        layerSlds = cell(nContrasts,2);
        domainLayerSldCell = [1 1 1 ; 1 1 1];
        coder.varsize('domainLayerSldCell',[10000 6],[1 1]);
        for i = 1:nContrasts
            layerSlds{i,1} = domainLayerSldCell;
            layerSlds{i,2} = domainLayerSldCell;
        end
    else
        layerSlds = cell(nContrasts,1);
        layerSldCell = [1 1 1 ; 1 1 1];
        coder.varsize('layerSldCell',[10000 6],[1 1]);
        for i = 1:nContrasts
            layerSlds{i} = layerSldCell;
        end
    end
    

    if domains
        sldProfiles = cell(nContrasts,2);
        domainSldProfileCell = [1 1 ; 1 1];
        coder.varsize('domainSldProfileCell',[10000 inf],[1 1]);
        for i = 1:nContrasts
            sldProfiles{i,1} = domainSldProfileCell;
            sldProfiles{i,2} = domainSldProfileCell;
        end
    else
        sldProfiles = cell(nContrasts,1);
        sldProfileCell = [1 1 ; 1 1];
        coder.varsize('sldProfileCell',[10000 2],[1 0]);
        for i = 1:nContrasts
            sldProfiles{i,1} = sldProfileCell;
        end
    end   

    if domains
        allLayers = cell(nContrasts,2);
        domainAllLayersCell = [1 1 1; 1 1 1];
        coder.varsize('domainAllLayersCell',[10000 3],[1 0]);
        for i = 1:nContrasts
            allLayers{i,1} = domainAllLayersCell;
            allLayers{i,2} = domainAllLayersCell;
        end
    else
        allLayers = cell(nContrasts,1);
        allLayersCell = [1 1 1; 1 1 1];
        coder.varsize('allLayersCell',[10000 3],[1 0]);
        for i = 1:nContrasts
            allLayers{i} = allLayersCell;
        end
    end
    
    bestFitPars = zeros(1,nPars);
    coder.varsize('bestFitPars',[1 10000],[0 1]);
    
    fitNames = cell(nPars,1);
    fitNamesChar = '';
    coder.varsize('fitNamesChar',[1 1000],[0 1]);
    for i = 1:nPars
        fitNames{i} = fitNamesChar;
    end

    result = struct('reflectivity', {reflectivity}, ...
                    'simulation', {simulation}, ...
                    'shiftedData', {shiftedData}, ...
                    'layerSlds', {layerSlds}, ...
                    'sldProfiles', {sldProfiles}, ...
                    'allLayers', {allLayers}, ...
                    'calculationResults', calculationResults, ...
                    'contrastParams', contrastParams, ...
                    'bestFitPars', bestFitPars, ...
                    'fitNames', {fitNames});

end
