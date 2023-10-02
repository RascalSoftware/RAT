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
action = controls.proc;
switch lower(action)
    case 'calculate' %Just a single reflectivity calculation
        [problem,results] = reflectivityCalculationWrapper(problemDef,problemDefCells,problemDefLimits,controls);
        outProblemDef = problemDef;
        bayesResults = [];
    case 'simplex'
        if ~strcmpi(controls.display,'off')
            sendTextOutput(sprintf('\nRunning simplex\n\n'));
        end
        [outProblemDef,problem,results] = runSimplex(problemDef,problemDefCells,problemDefLimits,controls);
        bayesResults = [];
    case 'de'
        if ~strcmpi(controls.display,'off')
            sendTextOutput(sprintf('\nRunning Differential Evolution\n\n'));
        end
        [outProblemDef,problem,results] = runDE(problemDef,problemDefCells,problemDefLimits,controls);
        bayesResults = [];
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