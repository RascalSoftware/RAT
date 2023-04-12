inputArgs = load('inputArgs');
i = inputArgs.inputArgs;

problemDef = i.problemDef;
problemDefCells = i.problemDefCells;
problemDefLimits = i.problemDefLimits;
priors = i.priors;
controls = i.controls;

[outProblemStruct,problem,result,bayesResults] = RAT_main(problemDef,problemDefCells,problemDefLimits,controls,priors);


