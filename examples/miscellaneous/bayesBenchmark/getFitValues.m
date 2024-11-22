function [fitPars,fitNames,fitConstr] = getFitValues(inputProblem,controls)

[problemStruct,problemLimits,~,controls] = parseClassToStructs(inputProblem,controls);

[problemStruct,fitNames] = packParams(problemStruct,problemLimits,controls.checks);

fitPars = problemStruct.fitParams;
fitConstr = problemStruct.fitLimits;

end