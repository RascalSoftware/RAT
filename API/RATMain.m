function [outProblemDef,problem,results,bayesResults] = RATMain(problemDef,problemDefCells,problemDefLimits,controls,priors)


result = cell(1,1);
result{1} = {1};
results = repmat(result,1,6);

numberOfContrasts = problemDef.numberOfContrasts;
preAlloc = zeros(numberOfContrasts,1);

problem = struct('ssubs',preAlloc,...
                 'backgrounds',preAlloc,...
                 'qshifts',preAlloc,...
                 'scalefactors',preAlloc,...
                 'nbairs',preAlloc,...
                 'nbsubs',preAlloc,...
                 'resolutions',preAlloc,...
                 'calculations',struct('all_chis',preAlloc,'sum_chi',0),...
                 'allSubRough',preAlloc,...
                 'resample',preAlloc);

% Make empty bayes results even though we may not fill it (for output purposes)
% bayesResults.bayesRes = [];
% bayesResults.chain = [];
% bayesResults.s2chain = [];
% bayesResults.ssChain = [];
% bayesResults.bestPars = [];
% 
%          bayesRes: [1×1 struct]
%             chain: [50000×17 double]
%           s2chain: []
%           sschain: []
%     bestPars_Mean: [1.8344 12.4215 9.1384 3.0801 9.9080 1.4640e-06 38.0618 … ]
%      bestFitsMean: [1×1 struct]
%          predlims: [1×1 struct]
%       parConfInts: [1×1 struct]

% bestRes:
%          mean: [1.9510 12.6286 9.1443 3.4083 9.9214 1.5109e-06 37.6638 … ]
%        output: [1×1 struct]
%     allChains: [2000×19×10 double]
%
% bestFitsMean
%      Ref: {3×1 cell}
%      Sld: {3×1 cell}
%      chi: 49.7163
%     data: {3×1 cell}
%
% predlims:
%     refPredInts: {3×1 cell}
%     sldPredInts: 0
%        refXdata: {3×1 cell}
%        sldXdata: {3×1 cell}
%       sampleChi: [1000×1 double]
%
% parConfInts:
%     par95: [2×17 double]
%     par65: [2×17 double]
%      mean: [1.9510 12.6286 9.1443 3.4083 9.9214 1.5109e-06 37.6638 5.4084 … ]





% bestFitsMean:




bayesResults = struct('bayesRes',[],...
    'chain',[],...
    's2chain',[],...
    'ssChain',[],...
    'bestPars_Mean',[],...
    'bestFitsMean',[],...
    'predLims',[],...
    'parConfInts',[]);

outProblemDef = problemDef;

%Decide what we are doing....
action = controls.proc;
switch lower(action)
    case 'calculate' %Just a single reflectivity calculation
        [problem,results] = reflectivityCalculationWrapper(problemDef,problemDefCells,problemDefLimits,controls);
        outProblemDef = problemDef;
    case 'simplex'
        if ~strcmpi(controls.display,'off')
            sendTextOutput(sprintf('\nRunning simplex\n\n'));
        end
        [outProblemDef,problem,results] = runSimplex(problemDef,problemDefCells,problemDefLimits,controls);
    case 'de'
        if ~strcmpi(controls.display,'off')
            sendTextOutput(sprintf('\nRunning Differential Evolution\n\n'));
        end
        [outProblemDef,problem,results] = runDE(problemDef,problemDefCells,problemDefLimits,controls);
%     case 'ns'
%         if ~strcmpi(controls.display,'off')
%             sendTextOutput(sprintf('\nRunning Nested Sampler\n\n'));
%         end            
%         [outProblemDef,problem,results,bayesResults] = runNestedSampler(problemDef,problemDefCells,problemDefLimits,controls);   
    case 'dream'
        if ~strcmpi(controls.display,'off')
            sendTextOutput(sprintf('\nRunning DREAM\n\n'));
        end
        [outProblemDef,problem,results,bayesResults] = runDREAM(problemDef,problemDefCells,problemDefLimits,controls,priors);
end

end