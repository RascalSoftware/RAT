clear

NSResults = load('NSResults.mat');
NSResults = NSResults.result;

allProblem = NSResults.allProblem;
bayesOutputs = rmfield(NSResults,'allProblem');

[problemDef,outProblem,result,bayesResults] = processBayes_newMethod(bayesOutputs,allProblem);
