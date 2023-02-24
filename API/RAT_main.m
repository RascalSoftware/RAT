function [outProblemDef,problem,results,bayesResults] = RAT_main(problemDef,problemDef_cells,problemDef_limits,controls,priors)


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

outProblemDef = problemDef;

%Decide what we are doing....
action = controls.proc;
switch lower(action)
    case 'calculate' %Just a single reflectivity calculation
        [problem,results] = singleCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
        outProblemDef = problemDef;
    case 'simplex'
        if ~strcmpi(controls.display,'off')
            ratSendTextOutput(sprintf('\nRunning simplex\n\n'));
        end
        [outProblemDef,problem,results] = runSimplex_mex(problemDef,problemDef_cells,problemDef_limits,controls);
    case 'de'
        if ~strcmpi(controls.display,'off')
            ratSendTextOutput(sprintf('\nRunning Differential Evolution\n\n'));
        end
        [outProblemDef,problem,results] = runDE_mex(problemDef,problemDef_cells,problemDef_limits,controls);
    case 'bayes'
        if ~strcmpi(controls.display,'off')
            ratSendTextOutput(sprintf('\nRunning DRAM\n\n'));
        end        
        [outProblemDef,problem,results,bayesResults] = runDram(problemDef,problemDef_cells,problemDef_limits,controls,priors);
    case 'ns'
        if ~strcmpi(controls.display,'off')
            ratSendTextOutput(sprintf('\nRunning Nested Sampler\n\n'));
        end            
        [outProblemDef,problem,results,bayesResults] = runNestedSampler(problemDef,problemDef_cells,problemDef_limits,controls);   
    case 'dream'
        if ~strcmpi(controls.display,'off')
            ratSendTextOutput(sprintf('\nRunning DREAM\n\n'));
        end
        
        % DEV and debug - this will be moved to controls...
%         dreamC.nSamples = 100000;           % Total number of samples
%         dreamC.nChains = 10;                % Number of MCMC chains..
%         dreamC.lambda = 0.5;                % Jump probabilities
%         dreamC.p_unit_gamma = 0.2;
%         dreamC.boundHandling = 'fold';      % Boundary handling
%         dreamC.prior = true;

        [outProblemDef,problem,results,bayesResults] = runDREAM(problemDef,problemDef_cells,problemDef_limits,controls,priors);
end

end