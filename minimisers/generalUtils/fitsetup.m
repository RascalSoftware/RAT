function [problemDefStruct,fitNames] = fitsetup(problemDefStruct,problemDefCells,problemDefLimits,controls)

if isfield(controls,'checks')
    checks = controls.checks;
else
    checks.fitParam = ones(length(problemDefStruct.params),1);
    checks.fitBackgroundParam = ones(length(problemDefStruct.backgroundParams),1);
    checks.fitQzshift = ones(length(problemDefStruct.qzshifts),1);
    checks.fitScalefactor = ones(length(problemDefStruct.scalefactors),1);
    checks.fitBulkIn = ones(length(problemDefStruct.bulkIn),1);
    checks.fitBulkOut = ones(length(problemDefStruct.bulkOut),1);
    checks.fitResolutionParam = ones(length(problemDefStruct.resolutionParams),1);
end

[problemDefStruct,fitNames] = packParams(problemDefStruct,problemDefCells,problemDefLimits,checks);

end
