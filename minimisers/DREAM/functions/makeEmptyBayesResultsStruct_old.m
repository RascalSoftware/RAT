function bayesResults = makeEmptyBayesResultsStruct(nPars,nChains)

% A function to make an empty container to hold the results of bayes
% calculations. The struct has the following format:
%
% nPar = number of fitted parameters
% nCon = number of contrasts
%
% bayesResults:-
%
% bayesResults.bayesRes 
% bayesResults.chain 
% bayesResults.s2chain 
% bayesResults.ssChain 
% bayesResults.bestPars 
% 
%          bayesRes: [1×1 struct]
%             chain: [Inf×nPar double]
%           s2chain: []
%           sschain: []
%     bestPars_Mean: [1 x nPar double]
%      bestFitsMean: [1×1 struct]
%          predlims: [1×1 struct]
%       parConfInts: [1×1 struct]

% bayesRes:
%   outputDream: [struct]
%outputParamonte: [struct]
%          mean: [1 x nPar double ]
%     allChains: [2000 × nPar+2 × nChains double]
%     
%
% bestFitsMean
%      Ref: {nCon×1 cell}
%      Sld: {nCon×1 cell}
%      chi: 49.7163
%     data: {nCon×1 cell}
%
% predlims:
%     refPredInts: {nCon×1 cell}
%     sldPredInts: 0
%        refXdata: {nCon×1 cell}
%        sldXdata: {3×1 cell}
%       sampleChi: [1000×1 double]
%
% parConfInts:
%     par95: [2×nPar double]
%     par65: [2xnPar double]
%      mean: [1 x nPar]


% -------------------------------------

maxNpar = 1000;
maxNContrasts = 100;


% (1) bayesRes
mean = zeros(1,1);
coder.varsize('mean',[1 maxNpar],[0 1]);

allChains = zeros(1,1,1);
coder.varsize('allChains',[1e4 maxNpar 1000],[1 1 1]);

bayesRes = struct('mean',mean,'allChains',allChains);


% (2) chain....
chain = zeros(1,1);
coder.varsize('chain',[1e7, maxNpar],[1 1]);


% (3) s2chain
s2chain = zeros(1,1);
coder.varsize('s2chain',[1e7, maxNpar],[1 1]);

% (4) sscahin
sschain = zeros(1,1);
coder.varsize('sschain',[1e7, maxNpar],[1 1]);

% (5) bestParsMean
bestPars_Mean = zeros(1,1);
coder.varsize('bestPars_Mean',[1 maxNpar],[0 1]);

% (6) bestFitsMean
Ref = cell(1,maxNContrasts);
coder.varsize('Ref',[1 maxNContrasts],[1 1]);
coder.varsize('Ref{:}',[1e7 3],[1 1]);

Sld = cell(1,maxNContrasts);
coder.varsize('Sld',[1 maxNContrasts],[1 1]);
coder.varsize('Sld{:}',[1e7 3],[1 1]);

chi = 0;

data = cell(1,maxNContrasts);
coder.varsize('data',[1 maxNContrasts],[1 1]);
coder.varsize('data{:}',[1e7 5],[1 1]);

bestFitsMean = struct('Ref',Ref,'Sld',Sld,'chi',chi,'data',data);

% (7) predlims...
refPredInts = cell(1,1);
coder.varsize('refPredInts',[maxNContrasts 1],[1 0]);
coder.varsize('refPredInts{:}',[5 1e4],[0 1]);

% sldPredInts = cell(1,1);
% coder.varsize('sldPredInts',[maxNContrasts 1],[1 0]);
% coder.varsize('sldPredInts{:}',[5 1e4],[0 1]);
sldPredInts = 0;

refXData = cell(1,1);
refXData{1} = zeros(1,1);
coder.varsize('refXdata',[maxNContrasts 1],[1 0]);
coder.varsize('refXData{;}',[1 1e4],[0 1]);

sldXData = cell(1,1);
sldXData{1} = zeros(1,1);
coder.varsize('sldXdata',[maxNContrasts 1],[1 0]);
coder.varsize('refXData{;}',[1 1e4],[0 1]);

sampleChi = zeros(1,1);
coder.varsize('sampleChi',[1e7 1],[1 0]);

predlims = struct('refPredInts',refPredInts,'sldPredInts',sldPredInts,...
    'refXData',refXData,'sldXData',sldXData,'sampleChi',sampleChi);

% (8) parConfInts
%     par95: [2×nPar double]
%     par65: [2xnPar double]
%      mean: [1 x nPar]

par95 = zeros(1,1);
coder.varsize('par95',[2 maxNpar],[0 1]);

par65 = zeros(1,1);
coder.varsize('par65',[2 maxNpar],[0 1]);

mean = zeros(1,1);
coder.varsize('mean',[1 maxNpar],[0 1]);

parConfInts = struct('par95',par95,'par65',par65,'mean',mean);
% (9)   bayesRes.dreamOutput
Meas_info = struct('Y',0,'N',0);

% dreamOutput

R = [1,1];
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

bayesRes.dreamOutput = DREAMPar;



% Make the whole struct
bayesResults = struct('bayesRes',bayesRes,'chain',chain,'s2chain',s2chain,...
    'bestPars_Mean',bestPars_Mean,'bestFitsMean',bestFitsMean,'predlims',predlims,...
    'parConfInts',parConfInts);















end