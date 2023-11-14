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

if strcmpi(problemDef.TF,'domains')
    domains = true;
else
    domains = false;
end
bayesResults = makeEmptyBayesResultsStruct(1e3, problemDef.numberOfContrasts, domains, controls.nChains);
% bayesResults = struct('bayesRes',[],...
%     'chain',[],...
%     's2chain',[],...
%     'ssChain',[],...
%     'bestPars_Mean',[],...
%     'bestFitsMean',[],...
%     'predLims',[],...
%     'parConfInts',[]);

outProblemDef = problemDef;

%Decide what we are doing....
switch lower(controls.procedure)
    case 'calculate' %Just a single reflectivity calculation
        [problem,results] = reflectivityCalculation(problemDef,problemDefCells,problemDefLimits,controls);
        outProblemDef = problemDef;
    case 'simplex'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning simplex\n\n');
        end
        [outProblemDef,problem,results] = runSimplex(problemDef,problemDefCells,problemDefLimits,controls);
    case 'de'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning Differential Evolution\n\n');
        end
        [outProblemDef,problem,results] = runDE(problemDef,problemDefCells,problemDefLimits,controls);
    case 'ns'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning Nested Sampler\n\n');
        end            
        [outProblemDef,problem,results,bayesResults] = runNestedSampler(problemDef,problemDefCells,problemDefLimits,controls,priors);   
    case 'dream'
        if ~strcmpi(controls.display,'off')
            fprintf('\nRunning DREAM\n\n');
        end
        [outProblemDef,problem,results,bayesResults] = runDREAM(problemDef,problemDefCells,problemDefLimits,controls,priors);
end

end