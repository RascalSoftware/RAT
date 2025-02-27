function [problemStruct,fitNames] = fitsetup(problemStruct,problemLimits)

if ~isfield(problemStruct,'checks')
    problemStruct.checks.params = ones(length(problemStruct.params),1);
    problemStruct.checks.backgroundParams = ones(length(problemStruct.backgroundParams),1);
    problemStruct.checks.scalefactors = ones(length(problemStruct.scalefactors),1);
    problemStruct.checks.bulkIns = ones(length(problemStruct.bulkIns),1);
    problemStruct.checks.bulkOuts = ones(length(problemStruct.bulkOuts),1);
    problemStruct.checks.resolutionParams = ones(length(problemStruct.resolutionParams),1);
end

[problemStruct,fitNames] = packParams(problemStruct,problemLimits);

end
