function bayesResults = makeEmptyBayesResultsStruct(nContrasts,isDomains,nChains)
    % A function to make an empty container to hold the results of bayes
    % calculations. The struct has the following format:
    %
    % nParams = number of fitted parameters
    % nContrasts = number of contrasts
    %
    % bayesResults = 
    % 
    %   struct with fields:
    % 
    %         bestFitMean: [1×1 struct]
    % predictionIntervals: [1×1 struct]
    % confidenceIntervals: [1×1 struct]
    %           allChains: [1×1 struct]
    %         dreamParams: [1×1 struct]
    %         dreamOutput: [1×1 struct]
    % nestedSamplerOutput: [1×1 struct]
    %               chain: [1000000xnParams double]
    
    % -----------------------------------------------------------
    % Make the individual structs....
    % (1) bayesResults.bestFitMean
    
    reflectivity = cell(nContrasts, 1);
    reflectivityCell = [1 1 1];
    coder.varsize('reflectivityCell',[1e7 4],[1 1]);
    for i = 1:nContrasts
        reflectivity{i} = reflectivityCell;
    end
    
    if isDomains
        sld = cell(nContrasts,2);
        sldCell = [1 1; 1 1];
        coder.varsize('sldCell',[1e7 3],[1 1]); 
        for i = 1:nContrasts
            sld{i,1} = sldCell;
            sld{i,2} = sldCell;
        end
    else
        sld = cell(nContrasts, 1);
        sldCell = [1 1];
        coder.varsize('sldCell',[1e7 3],[1 1]);
        for i = 1:nContrasts
            sld{i} = sldCell;
        end
    end
    
    chi = 0;
    
    data = cell(nContrasts, 1);
    dataCell = [1 1 1];
    coder.varsize('dataCell',[1e7 5],[1 1]);
    for i = 1:nContrasts
        data{i} = dataCell;
    end
    
    bestFitMean = struct('reflectivity',{reflectivity},'sld',{sld},'chi',chi,'data',{data});
    
    % --------------------------------------------------------------------
    % (2) bayesResults.predictionIntervals
    
    reflectivityIntervals = cell(nContrasts,1);
    reflectivityIntervalsCell = [1 1 1];
    coder.varsize('reflectivityIntervalsCell',[5 1e4],[1 1]);
    for i = 1:nContrasts
        reflectivityIntervals{i} = reflectivityIntervalsCell;
    end

    if isDomains
        sldIntervals = cell(nContrasts,2);
        sldIntervalsCell = [1 1 1];
        coder.varsize('sldIntervalsCell',[5 1e4],[1 1]);
        for i = 1:nContrasts
            sldIntervals{i,1} = sldIntervalsCell;
            sldIntervals{i,2} = sldIntervalsCell;
        end
    else
        sldIntervals = cell(nContrasts,1);
        sldIntervalsCell = [1 1 1];
        coder.varsize('sldIntervalsCell',[5 1e4],[1 1]);
        for i = 1:nContrasts
            sldIntervals{i} = sldIntervalsCell;
        end
    end
    
    reflectivityXData = cell(nContrasts,1);
    xDataCell = [1 1 1];
    coder.varsize('xDataCell',[1e4 1e4],[1 1]);
    for i = 1:nContrasts
        reflectivityXData{i} = xDataCell;
    end
    
    if isDomains
        sldXData = cell(nContrasts,2);
        sldXDataCell = [1 1 1; 1 1 1];
        coder.varsize('sldXDataCell',[2 1e4],[1 1]); 
        for i = 1:nContrasts
            sldXData{i,1} = sldXDataCell;
            sldXData{i,2} = sldXDataCell;
        end
    else
        sldXData = cell(nContrasts,1);
        sldXDataCell = [1 1 1];
        coder.varsize('sldXDataCell',[2 1e4],[1 1]);
        for i = 1:nContrasts
            sldXData{i} = sldXDataCell;
        end
    end
    
    sampleChi = zeros(1,1);
    coder.varsize('sampleChi',[1e7 1],[1 0]);
    
    predictionIntervals = struct('reflectivity',{reflectivityIntervals}, ...
        'sld',{sldIntervals},'reflectivityXData',{reflectivityXData}, ...
        'sldXData',{sldXData},'sampleChi',sampleChi);
    
    % ------------------------------------------------------------------
    % (3) bayesResults.confidenceIntervals
    
    percentile95 = zeros(2,1);
    coder.varsize('percentile95',[2 1e3],[0 1]);
    
    percentile65 = zeros(2,1);
    coder.varsize('percentile65',[2 1e3],[0 1]);
    
    mean = zeros(1,1);
    coder.varsize('mean',[1 1e3],[0 1]);
    
    confidenceIntervals = struct('percentile95',percentile95, ...
        'percentile65',percentile65,'mean',mean);
    
    % -------------------------------------------------------------------
    % (4) bayesResults.dreamParams
        
    R = zeros(nChains,nChains);
    coder.varsize('R',[1e4 1e4],[1 1]);
    
    dreamParams = struct('nParams', 17,...
                         'nChains', 10,...
                    'nGenerations', 1000,...
                        'parallel', false,...
                             'CPU', 1,...
                 'jumpProbability', 0.5000,...
                      'pUnitGamma', 0.2000,...
                             'nCR', 3,...
                           'delta', 3,...
                           'steps', 50,...
                            'zeta', 1.0000e-12,...
                         'outlier', 'iqr',...
                        'adaptPCR', false,...
                        'thinning', 1,...
                             'ABC', false,...
                       'epsilon', 0.0250,...
                              'IO', false,...
                     'storeOutput', false,...
                               'R', R);

    % -------------------------------------------------------------------
    % (5) bayesResults.dreamOutput

    allChains = [1 1 1];
    coder.varsize('allChains',[1e4 50 50],[1 1 1]);

    outlierChains = [1 1];
    coder.varsize('outlierChains',[1e3 1e3],[1 1]);
    
    iteration = 0;
    
    AR = [0 0];
    coder.varsize('AR',[1e3 1e3],[1 1]);
    
    R_stat = [0 0];
    coder.varsize('R_stat',[1e3 1e3],[1 1]);
    
    CR = [0 0];
    coder.varsize('CR',[1e3 1e3],[1 1]);
    
    dreamOutput = struct('allChains', allChains, ...
                     'outlierChains', outlierChains,...
                           'runtime', 100,...
                         'iteration', iteration,...
                       'modelOutput', 0,...
                                'AR', AR,...
                            'R_stat', R_stat,...
                                'CR', CR);
    
    % -------------------------------------------------------------------
    % (6) bayesResults.nestedSamplerOutput
    
    % Nested Sampler
    LogZ = 0;
    
    nestSamples = [0 0];
    coder.varsize('nestSamples');
    
    postSamples = [0 0];
    coder.varsize('postSamples');
    
    nestedSamplerOutput = struct('LogZ',LogZ,'nestSamples',...
        nestSamples,'postSamples',postSamples);
    
    % ------------------------------------------------------------------
    % (7) chain
    
    chain = [0 0];
    coder.varsize('chain',[1e6 1e3],[1 1]);
    
    % -------------------------------------------------------------------
    % Make the final structure...
    bayesResults = struct('bestFitMean',bestFitMean,...
                          'predictionIntervals', predictionIntervals,...
                          'confidenceIntervals', confidenceIntervals,...
                          'dreamParams', dreamParams,...
                          'dreamOutput', dreamOutput,...
                          'nestedSamplerOutput', nestedSamplerOutput,...
                          'chain',chain);

end
