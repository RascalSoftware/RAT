function bayesResults = makeEmptyBayesResultsStruct(nPars,nContrasts,isDomains,nChains)
    % A function to make an empty container to hold the results of bayes
    % calculations. The struct has the following format:
    %
    % nPar = number of fitted parameters
    % nContrasts = number of contrasts
    %
    % bayesResults = 
    % 
    %   struct with fields:
    % 
    %     bestFitsMean: [1×1 struct]
    %         predlims: [1×1 struct]
    %      parConfInts: [1×1 struct]
    %         bestPars: [1xnPars double]
    %         bayesRes: [1×1 struct]
    %            chain: [1000000xnPars double]
    
    % -----------------------------------------------------------
    % Make the individual structs....
    % (1) bayesResults.bestFitsMean
    
    ref = cell(nContrasts, 1);
    refCell = [1 1 1];
    coder.varsize('refCell',[1e7 4],[1 1]);
    for i = 1:nContrasts
        ref{i} = refCell;
    end
    
    if isDomains
        sld = cell(nContrasts,2);
        sldCell2 = [1 1; 1 1];
        coder.varsize('sldCell2',[1e7 3],[1 1]); 
        for i = 1:nContrasts
            sld{i,1} = sldCell2;
            sld{i,2} = sldCell2;
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
    
    bestFitsMean = struct('ref',{ref},'sld',{sld},'chi',chi,'data',{data});
    
    % --------------------------------------------------------------------
    % (2) bayesResults.predlims
    
    refPredInts = cell(nContrasts,1);
    refPredIntsCell = [1 1 1];
    coder.varsize('refPredIntsCell',[5 1e4],[1 1]);
    for i = 1:nContrasts
        refPredInts{i} = refPredIntsCell;
    end
    
    sldPredInts = cell(nContrasts,1);
    sldPredIntsCell = [1 1 1];
    coder.varsize('sldPredIntsCell',[5 1e4],[1 1]);
    for i = 1:nContrasts
        sldPredInts{i} = sldPredIntsCell;
    end
    
    refXdata = cell(nContrasts,1);
    xDataCell = [1 1 1];
    coder.varsize('xDataCell',[1e4 1e4],[1 1]);
    for i = 1:nContrasts
        refXdata{i} = xDataCell;
    end
    
    if isDomains
        sldXdata = cell(nContrasts,2);
        sldDataCell2 = [1 1 1 ; 1 1 1];
        coder.varsize('sldDataCell',[1 1e4],[1 1]); 
        for i = 1:nContrasts
            sldXdata{i,1} = sldDataCell2;
            sldXdata{i,2} = sldDataCell2;
        end
    else
        sldXdata = cell(nContrasts,1);
        sldDataCell = [1 1 1];
        coder.varsize('sldDataCell',[1 1e4],[1 1]);
        for i = 1:nContrasts
            sldXdata{i} = sldDataCell;
        end
    end
    
    sampleChi = zeros(1,1);
    coder.varsize('sampleChi',[1e7 1],[1 0]);
    
    predlims = struct('refPredInts',{refPredInts},'sldPredInts',{sldPredInts},...
        'refXdata',{refXdata},'sldXdata',{sldXdata},'sampleChi',sampleChi);
    
    % ------------------------------------------------------------------
    % (3) bayesResults.parConfInts
    
    par95 = zeros(2,1);
    coder.varsize('par95',[2 nPars],[0 1]);
    
    par65 = zeros(2,1);
    coder.varsize('par65',[2 nPars],[0 1]);
    
    mean = zeros(1,1);
    coder.varsize('mean',[1 nPars],[0 1]);
    
    parConfInts = struct('par95',par95,'par65',par65,'mean',mean);
    
    % -------------------------------------------------------------------
    % (4) bayesResults.bestPars
    
    bestPars = 1;
    coder.varsize('bestPars',[1 nPars],[0 1]);
    
    % -------------------------------------------------------------------
    % (5) bayesResults.bayesRes
    
    outlier = [1 1];
    coder.varsize('outlier',[nPars nPars],[1 1]);
    
    R = zeros(nChains,nChains);
    coder.varsize('R',[1e4 1e4],[1 1]);
    
    DREAMPar = struct('d', 17,...
                 'N', 10,...
                 'T', 1000,...
          'parallel', 'no',...
               'CPU', 1,...
            'lambda', 0.5000,...
        'pUnitGamma', 0.2000,...
               'nCR', 3,...
             'delta', 3,...
             'steps', 50,...
              'zeta', 1.0000e-12,...
           'outlier', 'iqr',...
         'adapt_pCR', 'no',...
          'thinning', 1,...
           'epsilon', 0.0250,...
               'ABC', 'no',...
                'IO', 'no',...
            'modout', 'no',...
           'restart', 'no',...
              'save', 'no',...
                 'R', R);
    
    Meas_info = struct('Y',0,'N',0);
    
    iteration = 0;
    iloc = 0;
    
    AR = [0 0];
    coder.varsize('AR',[nPars nPars],[1 1]);
    
    R_stat = [0 0];
    coder.varsize('R_stat',[nPars nPars],[1 1]);
    
    CR = [0 0];
    coder.varsize('CR',[nPars nPars],[1 1]);
    
    dreamOutput = struct('outlier', outlier,...
            'RunTime', 100,...
            'DREAMPar', DREAMPar,...
            'Meas_info', Meas_info,...
            'iteration', iteration,...
            'iloc', iloc,...
            'fx', 0,...
            'AR', AR,...
            'R_stat', R_stat,...
            'CR',CR);
    
    
    allChains = [1 1 1];
    coder.varsize('allChains',[1e4 50 50],[1 1 1]);
    
    % Nested Sampler
    LogZ = 0;
    
    nestSamples = [0 0];
    coder.varsize('nestSamples');
    
    postSamples = [0 0];
    coder.varsize('postSamples');
    
    nestOutput = struct('LogZ',LogZ,'nestSamples',...
        nestSamples,'postSamples',postSamples);
    
    bayesRes = struct('allChains', allChains,...
                      'dreamOutput', dreamOutput,...
                      'nestOutput', nestOutput);
    
    % ------------------------------------------------------------------
    % (6) chain
    
    chain = [0 0];
    coder.varsize('chain',[1e6 nPars],[1 1]);
    
    % -------------------------------------------------------------------
    % Make the final structure...
    bayesResults = struct('bestFitsMean',bestFitsMean,...
                          'predlims', predlims,...
                          'parConfInts', parConfInts,...
                          'bestPars', bestPars,...
                          'bayesRes', bayesRes,...
                          'chain',chain);
end
