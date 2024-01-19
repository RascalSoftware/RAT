function [problemStruct,fitNames] = fitsetup(problemStruct,problemCells,problemLimits,controls)

if isfield(controls,'checks')
    checks = controls.checks;
else
    checks.fitParam = ones(length(problemStruct.params),1);
    checks.fitBackgroundParam = ones(length(problemStruct.backgroundParams),1);
    checks.fitQzshift = ones(length(problemStruct.qzshifts),1);
    checks.fitScalefactor = ones(length(problemStruct.scalefactors),1);
    checks.fitBulkIn = ones(length(problemStruct.bulkIn),1);
    checks.fitBulkOut = ones(length(problemStruct.bulkOut),1);
    checks.fitResolutionParam = ones(length(problemStruct.resolutionParams),1);
end

[problemStruct,fitNames] = packParams(problemStruct,problemCells,problemLimits,checks);

end
