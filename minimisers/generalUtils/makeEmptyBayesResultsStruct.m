function bayesResults = makeEmptyBayesResultsStruct(nContrasts,isDomains,nChains)
    % A function to make an empty container to hold the results of a Bayesian calculation.
    %
    % Parameters
    % ----------
    % nContrasts : int
    %     The number of contrasts.
    % isDomains : bool
    %     Whether the calculation is a domains calculation.
    % nChains : int
    %     The number of chains in the calculation.
    %
    % Returns
    % -------
    % bayesResults : struct
    %     A struct with the following fields:
    % 
    %     - predictionIntervals: [1×1 struct]
    %     - confidenceIntervals: [1×1 struct]
    %     - dreamParams: [1×1 struct]
    %     - dreamOutput: [1×1 struct]
    %     - nestedSamplerOutput: [1×1 struct]
    %     - chain: [array of double]
    
    % Make the individual structs....
    % (1) bayesResults.predictionIntervals  
    reflectivityIntervals = cell(nContrasts,1);
    reflectivityIntervalsCell = ones(5,1);
    for i = 1:nContrasts
        reflectivityIntervals{i} = reflectivityIntervalsCell;
    end
    coder.varsize('reflectivityIntervals{:}',[5 1e4],[0 1]);

    sldIntervalsCell = ones(5,1);
    if isDomains
        sldIntervals = cell(nContrasts,2);
        for i = 1:nContrasts
            sldIntervals{i,1} = sldIntervalsCell;
            sldIntervals{i,2} = sldIntervalsCell;
        end
    else
        sldIntervals = cell(nContrasts,1);
        for i = 1:nContrasts
            sldIntervals{i} = sldIntervalsCell;
        end
    end
    coder.varsize('sldIntervals{:}',[5 1e4],[0 1]);
    
    reflectivityXData = cell(nContrasts,1);
    xDataCell = ones(1,3);
    for i = 1:nContrasts
        reflectivityXData{i} = xDataCell;
    end
    coder.varsize('reflectivityXData{:}',[1 1e4],[0 1]);

    sldXDataCell = ones(1,3);
    if isDomains
        sldXData = cell(nContrasts,2);
        for i = 1:nContrasts
            sldXData{i,1} = sldXDataCell;
            sldXData{i,2} = sldXDataCell;
        end
    else
        sldXData = cell(nContrasts,1);
        for i = 1:nContrasts
            sldXData{i} = sldXDataCell;
        end
    end
    coder.varsize('sldXData{:}',[1 1e4],[0 1]);
    
    sampleChi = zeros(1,1);
    coder.varsize('sampleChi',[1e7 1],[1 0]);
    
    predictionIntervals = struct('reflectivity',{reflectivityIntervals}, ...
        'sld',{sldIntervals},'sampleChi',sampleChi);
    
    % ------------------------------------------------------------------
    % (2) bayesResults.confidenceIntervals
    
    percentile95 = zeros(2,1);
    coder.varsize('percentile95',[2 1e3],[0 1]);
    
    percentile65 = zeros(2,1);
    coder.varsize('percentile65',[2 1e3],[0 1]);
    
    mean = zeros(1,1);
    coder.varsize('mean',[1 1e3],[0 1]);
    
    confidenceIntervals = struct('percentile95',percentile95, ...
        'percentile65',percentile65,'mean',mean);
    
    % -------------------------------------------------------------------
    % (3) bayesResults.dreamParams
        
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
    % (4) bayesResults.dreamOutput

    allChains = ones(1,3);
    coder.varsize('allChains',[1e4 50 50],[1 1 1]);

    outlierChains = ones(1,2);
    coder.varsize('outlierChains',[1e3 1e3],[1 1]);
    
    iteration = 0;
    
    AR = zeros(1,2);
    coder.varsize('AR',[1e3 1e3],[1 1]);
    
    R_stat = zeros(1,2);
    coder.varsize('R_stat',[1e3 1e3],[1 1]);
    
    CR = zeros(1,2);
    coder.varsize('CR',[1e3 1e3],[1 1]);
    
    dreamOutput = struct('allChains', allChains, ...
                     'outlierChains', outlierChains,...
                           'runtime', 100,...
                         'iteration', iteration,...
                                'AR', AR,...
                            'R_stat', R_stat,...
                                'CR', CR);
    
    % -------------------------------------------------------------------
    % (5) bayesResults.nestedSamplerOutput
    
    % Nested Sampler
    LogZ = 0;
    LogZErr = 0;
    
    nestSamples = zeros(1,2);
    coder.varsize('nestSamples');
    
    postSamples = zeros(1,2);
    coder.varsize('postSamples');
    
    nestedSamplerOutput = struct('LogZ',LogZ,'LogZErr',LogZErr,...
    'nestSamples',nestSamples,'postSamples',postSamples);
    
    % ------------------------------------------------------------------
    % (6) chain
    
    chain = zeros(1,2);
    coder.varsize('chain',[1e6 1e3],[1 1]);
    
    % -------------------------------------------------------------------
    % Make the final structure...
    bayesResults = struct('predictionIntervals', predictionIntervals,...
                          'confidenceIntervals', confidenceIntervals,...
                          'dreamParams', dreamParams,...
                          'dreamOutput', dreamOutput,...
                          'nestedSamplerOutput', nestedSamplerOutput,...
                          'chain',chain);

end
