function [problemStruct,fitNames] = fitsetup(problemStruct,problemLimits)

if ~isfield(problemStruct,'checks')
    problemStruct.checks.fitParam = ones(length(problemStruct.params),1);
    problemStruct.checks.fitBackgroundParam = ones(length(problemStruct.backgroundParams),1);
    problemStruct.checks.fitQzshift = ones(length(problemStruct.qzshifts),1);
    problemStruct.checks.fitScalefactor = ones(length(problemStruct.scalefactors),1);
    problemStruct.checks.fitBulkIn = ones(length(problemStruct.bulkIn),1);
    problemStruct.checks.fitBulkOut = ones(length(problemStruct.bulkOut),1);
    problemStruct.checks.fitResolutionParam = ones(length(problemStruct.resolutionParams),1);
end

[problemStruct,fitNames] = packParams(problemStruct,problemLimits);

end
