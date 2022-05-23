function [outProblemDef,problem,results,bayesResults] = RAT_main(problemDef,problemDef_cells,problemDef_limits,priors,controls)


result = cell(6,1);
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
                 'allSubRough',preAlloc);

% Make empty bayes results even though we may not fill it (for output purposes)
bayesResults.res = [];
bayesResults.chain = [];
bayesResults.s2chain = [];
bayesResults.ssChain = [];
bayesResults.bestPars = [];

%Decide what we are doing....
action = controls.proc;
switch action
    case 'calculate' %Just a single reflectivity calculation
        [problem,results] = singleCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
        outProblemDef = problemDef;
    case 'simplex'
        if ~strcmpi(controls.display,'off')
            ratSendTextOutput(sprintf('\nRunning simplex\n\n'));
        end
        [outProblemDef,problem,results] = runSimplex(problemDef,problemDef_cells,problemDef_limits,controls);
    case 'DE'
        if ~strcmpi(controls.display,'off')
            ratSendTextOutput(sprintf('\nRunning Differential Evolution\n\n'));
        end
        [outProblemDef,problem,results] = runDE(problemDef,problemDef_cells,problemDef_limits,controls);
    case 'bayes'
        if ~strcmpi(controls.display,'off')
            ratSendTextOutput(sprintf('\nRunning DRAM\n\n'));
        end        
        [outProblemDef,problem,results,bayesResults] = runDram(problemDef,problemDef_cells,problemDef_limits,priors,controls);

    case 'NS'
        if ~strcmpi(controls.display,'off')
            ratSendTextOutput(sprintf('\nRunning Nested Sampler\n\n'));
        end            
        [outProblemDef,problem,results,bayesResults] = runNestedSampler(problemDef,problemDef_cells,problemDef_limits,controls);
        
    case 'paramonte'
        
        
end

end