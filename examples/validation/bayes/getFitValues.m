function [fitPars,fitNames,fitConstr] = getFitValues(inputProblem,controls)

[problemDefStruct,problemDefCells,problemDefLimits,~,controls] = parseClassToStructs(inputProblem,controls);

[problemDefStruct,fitNames] = packParams(problemDefStruct,problemDefCells,problemDefLimits,controls.checks);

fitPars = problemDefStruct.fitParams;
fitConstr = problemDefStruct.fitLimits;

end