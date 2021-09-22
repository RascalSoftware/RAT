function [problemDef,fitNames] = fitsetup(problemDef,problemDef_cells,problemDef_limits,controls)

if isfield(controls,'checks')
    checks = controls.checks;
else
    checks.params_fitYesNo = ones(length(problemDef.params),1);
    checks.backs_fitYesNo = ones(length(problemDef.backs),1);
    checks.shifts_fitYesNo = ones(length(problemDef.shifts),1);
    checks.scales_fitYesNo = ones(length(problemDef.sf),1);
    checks.nbairs_fitYesNo = ones(length(problemDef.nba),1);
    checks.nbsubs_fitYesNo = ones(length(problemDef.nbs),1);
    checks.resol_fitYesNo = ones(length(problemDef.res),1);
end



[problemDef,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,checks);


%Check the bounds on all the selected
% out = checkBounds(problemDef,controls);
% if strcmp(out{1},'fail')
%     return
% end




