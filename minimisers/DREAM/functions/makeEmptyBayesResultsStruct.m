function bayesResults = makeEmptyBayesResultsStruct(nPars,nContrasts,isDomains,nChains)

% A function to make an empty container to hold the results of bayes
% calculations. The struct has the following format:
%
% nPar = number of fitted parameters
% nCon = number of contrasts
%

% bayesResults = 
% 
%   struct with fields:
% 
%     bestFitsMean: [1×1 struct]
%         predlims: [1×1 struct]
%      parConfInts: [1×1 struct]
%         bestPars: [2.1073 13.2330 10.8497 3.6010 9.9000 1.5536e-06 36.8692 5.6837 12.7974 1.8877 9.9680 1.0832e-06 1.7553e-06 1.7360e-06 6.2043e-06 2.3187e-06 -4.5679e-07]
%         bayesRes: [1×1 struct]
%            chain: [10000×17 double]

% -----------------------------------------------------------

% Make the individual structs....
% 
% (1) bayesResults.bestFitsMean
% 
%   struct with fields:
% 
%      Ref: {3×1 cell}
%      Sld: {3×1 cell}
%      chi: 64.4432
%     data: {3×1 cell}

ref = cell(nContrasts, 1);
refCell = [1 1 1];
coder.varsize('refCell',[1e7 4],[1 1]);
for i = 1:nContrasts
    ref{i} = refCell;
end
%coder.varsize('Ref',[1 maxNContrasts],[1 1]);

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
%coder.varsize('Sld',[1 maxNContrasts],[1 1]);

chi = 0;

data = cell(nContrasts, 1);
dataCell = [1 1 1];
coder.varsize('dataCell',[1e7 5],[1 1]);
for i = 1:nContrasts
    data{i} = dataCell;
end
%coder.varsize('data',[1 maxNContrasts],[1 1]);

bestFitsMean = struct('ref',{ref},'sld',{sld},'chi',chi,'data',{data});

% --------------------------------------------------------------------

% (2) bayesResults.predlims
%
%   struct with fields:
% 
%     refPredInts: {3×1 cell}
%     sldPredInts: 0
%        refXdata: {3×1 cell}
%        sldXdata: {3×1 cell}
%       sampleChi: [1000×1 double]



refPredInts = cell(nContrasts,1);
refPredIntsCell = [1 1 1];
%coder.varsize('refPredInts',[1e4 1],[1 0]);
coder.varsize('refPredIntsCell',[5 1e4],[1 1]);
for i = 1:nContrasts
    refPredInts{i} = refPredIntsCell;
end

%coder.varsize('refPredInts',[maxNContrasts 1],[1 0]);
%coder.varsize('refPredInts{:}',[5 1e4],[0 1]);

sldPredInts = cell(nContrasts,1);
sldPredIntsCell = [1 1 1];
%coder.varsize('refPredInts',[1e4 1],[1 0]);
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
%coder.varsize('refXdata',[maxNContrasts 1],[1 0]);
%coder.varsize('refXData{:}',[1 1e4],[0 1]);

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
% 
%   struct with fields:
% 
%     par95: [2×17 double]
%     par65: [2×17 double]
%      mean: [1 x n double]

par95 = zeros(2,1);
coder.varsize('par95',[2 nPars],[0 1]);

par65 = zeros(2,1);
coder.varsize('par65',[2 nPars],[0 1]);

mean = zeros(1,1);
coder.varsize('mean',[1 nPars],[0 1]);

parConfInts = struct('par95',par95,'par65',par65,'mean',mean);

% -------------------------------------------------------------------

% (4) bayesResults.bestPars

bestPars = [1];
coder.varsize('bestPars',[1 nPars],[0 1]);

% -------------------------------------------------------------------

% (5) bayesResults.bayesRes
% 
% ans = 
% 
%   struct with fields:
% 
%       allChains: [1000×19×10 double]
%     dreamOutput: [1×1 struct]
%     nsOutput = [1x1 struct]
% 
% bayesResults.bayesRes.dreamOutput
% 
%   struct with fields:
% 
%       outlier: [3×2 double]
%       RunTime: 9.1300
%      DREAMPar: [1×1 struct]
%     Meas_info: [1×1 struct]
%     iteration: 22
%          iloc: 1000
%            fx: 0
%            AR: [21×2 double]
%        R_stat: [21×18 double]
%            CR: [21×4 double]


outlier = [1 1];
coder.varsize('outlier',[nPars nPars],[1 1]);

R = zeros(nChains,nChains);
coder.varsize('R',[1e4 1e4],[1 1]);

runTime = 0;

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

fx = 0;

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
% result.logX = logZ;
% result.nest_samples = nest_samples;
% result.post_samples = post_samples;
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