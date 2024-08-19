function [fitPars,fitNames,fitConstr] = getFitValues(inputProblem,controls)

[problemStruct,problemCells,problemLimits,~,controls] = parseClassToStructs(inputProblem,controls);

[problemStruct,fitNames] = packParams(problemStruct,problemCells,problemLimits,controls.checks);

fitPars = problemStruct.fitParams;
fitConstr = problemStruct.fitLimits;

end