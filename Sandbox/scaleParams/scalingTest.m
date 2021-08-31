clear

% Make the example class
orsoDSPC_custLay_script;

% Make a controls class
mainControls = controlsDef;
mainControls.procedure = 'bayes';
maincontrols.nsimu = 4000;
mainControls.repeats = 3;

% Strip this down in to structs and arrays...
[problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(problem,mainControls);

% PAck the params to extract fitPars
[problemDef,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,controls.checks);

% Extract the fitted params and constraints..
fitPars = problemDef.fitpars;
fitConstr = problemDef.fitconstr;

% Scale the parameters...
[scaledPars,scaledConstr] = scalePars(fitPars,fitConstr);

% Now reverse it with unscaling...
unscaledPars = unscalePars(scaledPars,fitConstr);

% Check that we get the same parameters back....
status = isequal(unscaledPars,fitPars);
if status 
    valString = 'true';
else
    valString = 'false';
end
fprintf('Status of ''isequal'' for input and output is %s \n',valString);


% Now try running a Bayes which uses scaled parameters.
% Scaling happens downstream in runBayes....
[outProblemStruct,outProblem,result,bayesResults] = runDram_scaled(problemDef,problemDef_cells,problemDef_limits,priors,controls);

result = parseResultToStruct(outProblem,result);
result = mergeStructs(result,bayesResults);

result.fitNames = fitNames;

result_scaled = result;
problem_scaled = RATparseOutToProjectClass(problem,outProblemStruct,outProblem,result);

figure(1); clf;
bayesShadedPlot_dev(problem_scaled,result_scaled,'q4',true,'fit','all'); hold on
title('Scaled version');

% Now run the unscaled...
[problem_unscaled, result_unscaled] = RAT(problem,mainControls);
figure(3); clf; 
bayesShadedPlot_dev(problem_unscaled,result_unscaled,'q4',true,'fit','all'); hold on
title('Unscaled version');


figure(4) ; clf; hold on
nParams = length(fitNames);
nRows = ceil(nParams/4);

for i = 1:nParams;
    subplot(nRows,4,i);
    h = histogram(result_unscaled.chain(:,i));
    set(h,'FaceAlpha',0.5);
    hold on
    h2 = histogram(result_scaled.chain(:,i));
    set(h2,'FaceAlpha',0.5);
end
    


