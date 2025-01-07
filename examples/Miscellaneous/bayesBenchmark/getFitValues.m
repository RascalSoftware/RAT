function [fitPars,fitNames,fitConstr] = getFitValues(inputProblem,controls)

[problemStruct,problemLimits,~,~] = parseClassToStructs(inputProblem,controls);

[problemStruct,fitNames] = packParams(problemStruct,problemLimits);

fitPars = problemStruct.fitParams;
fitConstr = problemStruct.fitLimits;

end