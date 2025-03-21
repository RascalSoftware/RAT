function [problemStruct,result] = runDE(problemStruct,controls)
    % Run the differential evolution algorithm for a given problem and controls.
    %
    % Parameters
    % ----------
    % problemStruct : struct
    %     the Project struct.
    % controls : struct
    %     the Controls struct.
    %
    % Returns
    % -------
    % problemStruct : struct
    %     the output project struct.
    % result : struct
    %     the calculation and optimisation results object.
    %
    F_VTR = controls.targetValue; %Value to reach
    I_D = length(problemStruct.fitParams);
    
    FVr_minbound = problemStruct.fitLimits(:,1)';
    FVr_maxbound = problemStruct.fitLimits(:,2)';
    I_bnd_constr = 1;  %1: use bounds as bound constraints, 0: no bound constraints
    
    % I_NP            number of population members
    I_NP = controls.populationSize; 
    
    % I_itermax       maximum number of iterations (generations)
    I_itermax = controls.numGenerations;
    
    % fWeight        DE-stepsize fWeight ex [0, 2]
    fWeight = controls.fWeight; 
    
    % F_CR            crossover probability constant ex [0, 1]
    F_CR = controls.crossoverProbability; 
    
    % I_strategy     1 --> DE/rand/1:
    %                      the classical version of DE.
    %                2 --> DE/local-to-best/1:
    %                      a version which has been used by quite a number
    %                      of scientists. Attempts a balance between robustness
    %                      and fast convergence.
    %                3 --> DE/best/1 with jitter:
    %                      taylored for small population sizes and fast convergence.
    %                      Dimensionality should not be too high.
    %                4 --> DE/rand/1 with per-vector-dither:
    %                      Classical DE with dither to become even more robust.
    %                5 --> DE/rand/1 with per-generation-dither:
    %                      Classical DE with dither to become even more robust.
    %                      Choosing fWeight = 0.3 is a good start here.
    %                6 --> DE/rand/1 either-or-algorithm:
    %                      Alternates between differential mutation and three-point-
    %                      recombination.           
    
    I_strategy = controls.strategy;
    
    % I_refresh     intermediate output will be produced after "I_refresh"
    %               iterations. No intermediate output will be produced
    %               if I_refresh is < 1
    I_refresh = 1;
    
    % I_plotting    Will use plotting if set to 1. Will skip plotting otherwise.
    I_plotting = 0;
    
    %-----Definition of tolerance scheme--------------------------------------
    %-----The scheme is sampled at I_lentol points----------------------------
    I_lentol   = 50;
    FVr_x      = linspace(-1,1,I_lentol); %ordinate running from -1 to +1
    FVr_lim_up = ones(1,I_lentol);   %upper limit is 1
    FVr_lim_lo = -ones(1,I_lentol);  %lower limit is -1
    
    %Tell compiler abut variable sizes
    coder.varsize('S_struct.FVr_bestmem',[1 Inf],[0 1]);
    
    %-----tie all important values to a structure that can be passed along----
    S_struct.I_lentol   = I_lentol;
    S_struct.FVr_x      = FVr_x;
    S_struct.FVr_lim_up = FVr_lim_up;
    S_struct.FVr_lim_lo = FVr_lim_lo;
    
    S_struct.I_NP         = I_NP;
    S_struct.fWeight     = fWeight;
    S_struct.F_CR         = F_CR;
    S_struct.I_D          = I_D;
    S_struct.FVr_minbound = FVr_minbound;
    S_struct.FVr_maxbound = FVr_maxbound;
    S_struct.I_bnd_constr = I_bnd_constr;
    S_struct.I_itermax    = I_itermax;
    S_struct.F_VTR        = F_VTR;
    S_struct.I_strategy   = I_strategy;
    S_struct.I_refresh    = I_refresh;
    S_struct.I_plotting   = I_plotting;
    S_struct.FM_pop = zeros(I_NP,2);
    S_struct.FVr_bestmem = [0 0];
    
    [res,problemStruct] = deopt(@intrafun,problemStruct,controls,S_struct);
    problemStruct.fitParams = res;
    problemStruct = unpackParams(problemStruct);
    result = reflectivityCalculation(problemStruct,controls);
    
    if ~strcmpi(controls.display, coderEnums.displayOptions.Off)
        triggerEvent(coderEnums.eventTypes.Message, sprintf('Final chi squared is %g\n',result.calculationResults.sumChi));
    end

end


function [S_MSE,result] = intrafun(p,problemStruct,controls)
    
    problemStruct.fitParams = p;
    problemStruct = unpackParams(problemStruct);
    result = reflectivityCalculation(problemStruct,controls);
    fval = result.calculationResults.sumChi;
    
    S_MSE.I_nc      = 0; %no constraints                 THESE FIRST FEW VALS MAY BE WRONG
    S_MSE.FVr_ca    = 0; %no constraint array
    S_MSE.I_no      = 1; %number of objectives (costs)
    S_MSE.FVr_oa = fval;

end
