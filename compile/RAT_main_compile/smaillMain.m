inputArgs = load('inputArgs');
i = inputArgs.inputArgs;

problemDef = i.problemDef;
problemDef_cells = i.problemDef_cells;
problemDef_limits = i.problemDef_limits;
priors = i.priors;
controls = i.controls;

[outProblemStruct,problem,result,bayesResults] = RAT_main(problemDef,problemDef_cells,problemDef_limits,controls,priors);


