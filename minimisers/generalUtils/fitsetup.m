function [problemDef,fitNames] = fitsetup(problemDef,problemDefCells,problemDefLimits,controls)

if isfield(controls,'checks')
    checks = controls.checks;
else
    checks.fitParam = ones(length(problemDef.params),1);
    checks.fitBackgroundParam = ones(length(problemDef.backs),1);
    checks.fitQzshift = ones(length(problemDef.qzshifts),1);
    checks.fitScalefactor = ones(length(problemDef.sf),1);
    checks.fitBulkIn = ones(length(problemDef.nba),1);
    checks.fitBulkOut = ones(length(problemDef.nbs),1);
    checks.fitResolutionParam = ones(length(problemDef.res),1);
end



[problemDef,fitNames] = packParams(problemDef,problemDefCells,problemDefLimits,checks);


%Check the bounds on all the selected
% out = checkBounds(problemDef,controls);
% if strcmp(out{1},'fail')
%     return
% end




