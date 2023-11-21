function [problemDef,fitNames] = fitsetup(problemDef,problemDefCells,problemDefLimits,controls)

if isfield(controls,'checks')
    checks = controls.checks;
else
    checks.fitParams = ones(length(problemDef.params),1);
    checks.fitBacks = ones(length(problemDef.backs),1);
    checks.fitShifts = ones(length(problemDef.shifts),1);
    checks.fitScales = ones(length(problemDef.sf),1);
    checks.fitNbairs = ones(length(problemDef.nba),1);
    checks.fitNbsubs = ones(length(problemDef.nbs),1);
    checks.fitResol = ones(length(problemDef.res),1);
end



[problemDef,fitNames] = packparams(problemDef,problemDefCells,problemDefLimits,checks);


%Check the bounds on all the selected
% out = checkBounds(problemDef,controls);
% if strcmp(out{1},'fail')
%     return
% end




