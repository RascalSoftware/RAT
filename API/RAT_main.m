function [outProblemDef,problem,results] = RAT_main(problemDef,problemDef_cells,problemDef_limits,controls)


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


%Decide what we are doing....
action = controls.proc;
switch action
    case 'calculate' %Just a single reflectivity calculation
        [problem,results] = singleCalculation(problemDef,problemDef_cells,problemDef_limits,controls);
        outProblemDef = problemDef;
    case 'simplex'
        [outProblemDef,problem,results] = runSimplex(problemDef,problemDef_cells,problemDef_limits,controls);
    case 'DE'
        [outProblemDef,problem,results] = runDE(problemDef,problemDef_cells,problemDef_limits,controls);
    case 'bayes'
        [outProblemDef,results] = runDram(problemDef,problemDef_cells,problemDef_limits,controls);
    case 'NS'
        [outProblemDef,results] = runNestedSampler(problemDef,problemDef_cells,problemDef_limits,controls);
end

%disp('debug: RAT_main');


end