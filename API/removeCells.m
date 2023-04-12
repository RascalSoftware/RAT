function [problemDef,problemDefCells,problemDefLimits] = removeCells(problemDef,controls)

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
problemDefCells{1} = repeatLayers;
problemDefCells{2} = allData;
problemDefCells{3} = dataLimits;
problemDefCells{4} = simLimits;
problemDefCells{5} = contrastLayers;
problemDefCells{6} = layersDetails;
problemDefCells{7} = paramNames;
problemDefCells{8} = backsNames;
problemDefCells{9} = sfNames;
problemDefCells{10} = shiftsNames;
problemDefCells{11} = nbaNames;
problemDefCells{12} = nbsNames;
problemDefCells{13} = resolNames;
problemDefCells{14} = fitNames;

problemDefLimits = problemDef.limits;


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