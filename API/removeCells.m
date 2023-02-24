function [problemDef,problemDef_cells,problemDef_limits] = removeCells(problemDef,controls)

repeatLayers = problemDef.repeatLayers;
allData = problemDef.allData;
dataLimits = problemDef.dataLimits;
simLimits = problemDef.simLimits;
contrastLayers = problemDef.contrastLayers;
layersDetails = problemDef.layersDetails;
paramNames = problemDef.paramNames;
backsNames = problemDef.backsNames;
sfNames = problemDef.sfNames;
shiftsNames = problemDef.shiftsNames;
nbaNames = problemDef.nbaNames;
nbsNames = problemDef.nbsNames;
resolNames = problemDef.resolNames;
fitNames = problemDef.fitNames;


%Put the extracted fields into a cell array...
problemDef_cells{1} = repeatLayers;
problemDef_cells{2} = allData;
problemDef_cells{3} = dataLimits;
problemDef_cells{4} = simLimits;
problemDef_cells{5} = contrastLayers;
problemDef_cells{6} = layersDetails;
problemDef_cells{7} = paramNames;
problemDef_cells{8} = backsNames;
problemDef_cells{9} = sfNames;
problemDef_cells{10} = shiftsNames;
problemDef_cells{11} = nbaNames;
problemDef_cells{12} = nbsNames;
problemDef_cells{13} = resolNames;
problemDef_cells{14} = fitNames;

problemDef_limits = problemDef.limits;


fields = {'allData','dataLimits','simLimits','contrastLayers','layersDetails','repeatLayers','paramNames','backsNames','sfNames','shiftsNames','nbaNames','nbsNames','resolNames','limits','fitNames'};
problemDef = rmfield(problemDef,fields);

checks = controls.checks;

%Add the fields ready for fitting....
numberOfFitted = sum(checks.params_fitYesNo) + ...
                 sum(checks.backs_fitYesNo) + ...
                 sum(checks.scales_fitYesNo) + ...
                 sum(checks.shifts_fitYesNo) + ...
                 sum(checks.nbairs_fitYesNo) + ...
                 sum(checks.nbsubs_fitYesNo) + ...
                 sum(checks.resol_fitYesNo);
             
numberOfTotal = length(problemDef.params) + ...
                length(problemDef.backs) + ...
                length(problemDef.sf) + ...
                length(problemDef.shifts) + ...
                length(problemDef.nba) + ...
                length(problemDef.nbs) + ...
                length(problemDef.res);
   
problemDef.fitpars = zeros(numberOfFitted,1);
problemDef.otherpars = zeros((numberOfTotal-numberOfFitted),1);
problemDef.fitconstr = zeros(numberOfFitted,2);
problemDef.otherconstr = zeros((numberOfTotal-numberOfFitted),2);

end