function outProblemDef = RATparseOutToProblemDef(inProblem,problemDef_cells,problemDef_limits,result,controls)

%Reconstruct the problemDef class as an output
%Using the outputs from the calculation(s)
outProblemDef = problemDef;
checks = controls.checks;

%(1) Parameters
pars = inProblem.params;
numberOfParameters = length(pars);

outProblemDef.nParams = numberOfParameters;
outProblemDef.params = pars;

names = problemDef_cells{7};
outProblemDef.paramNames = names;

limits = problemDef_limits.params;

for i = 1:numberOfParameters
    outProblemDef.paramConstr{i} = limits(i,:);
end

outProblemDef.paramFitYesNo = checks.params_fitYesNo;



%(2) Backgrounds
backs = inProblem.backs;
numberOfBacks = length(backs);

outProblemDef.nBackgrounds = numberOfBacks;
outProblemDef.backgrounds = backs;

backNames = problemDef_cells{8};
outProblemDef.backgroundNames = backNames;

backsLimits = problemDef_limits.backs;
for i = 1:numberOfBacks
    outProblemDef.backgroundConstr{i} = limits(i,:);
end

outProblemDef.backgroundFitYesNo = checks.backs_fitYesNo;



%(3) Scalefactors
scales = inProblem.sf;
numberOfScales = length(scales);

outProblemDef.nScalefactors = numberOfScales;
outProblemDef.scalefactors = scales;

scaleNames = problemDef_cells{9};
outProblemDef.scalefactorNames = scaleNames;

scaleLimits = problemDef_limits.scales;
for i = 1:numberOfScales
    outProblemDef.scalefactorConstr{i} = scaleLimits(i,:);
end

outProblemDef.scalefactorFitYesNo = checks.scales_fitYesNo;


%(4) Qzshifts
shifts = inProblem.shifts;
numberOfShifts = length(shifts);

outProblemDef.nQzshifts = numberOfShifts;
outProblemDef.qzshifts = shifts;

shiftNames = problemDef_cells{10};
outProblemDef.qzshiftNames = shiftNames;

shiftLimits = problemDef_limits.shifts;
for i = 1:numberOfShifts
    outProblemDef.qzshiftConstr{i} = shiftLimits(i,:);
end
outProblemDef.qzshiftFitYesNo = checks.shifts_fitYesNo;


%(4) Nbairs
nbairs = inProblem.nba;
numberOfNbairs = length(nbairs);

outProblemDef.nNbairs = numberOfNbairs;
outProblemDef.nbairs = nbairs;

nbairNames = problemDef_cells{11};
outProblemDef.nbairNames = nbairNames;

nbairLimits = problemDef_limits.nba;
for i = 1:numberOfNbairs
    outProblemDef.nbairConstr{i} = nbairLimits(i,:);
end
outProblemDef.nbairFitYesNo = checks.nbairs_fitYesNo;


%(5) Nbsubs
nbsubs = inProblem.nbs;
numberOfNbsubs = length(nbsubs);

outProblemDef.nNbsubs = numberOfNbsubs;
outProblemDef.nbsubs = nbsubs;

nbsubsNames = problemDef_cells{12};
outProblemDef.nbsubNames = nbsubsNames;

nbsubLimits = problemDef_limits.nbs;
for i = 1:numberOfNbsubs
    outProblemDef.nbsubConstr{i} = nbsubLimits(i,:);
end
outProblemDef.nbsubFitYesNo = checks.nbsubs_fitYesNo;


%(5) Resolutions
resol = inProblem.res;
numberOfResols = length(resol);

outProblemDef.nResolutions = numberOfResols;
outProblemDef.resolutions = resol;

resolNames = problemDef_cells{13};
outProblemDef.resolutionNames = resolNames;

resolLimits = problemDef_limits.res;
for i = 1:numberOfResols
    outProblemDef.resolutionConstr{i} = resolLimits(i,:);
end
outProblemDef.resolutionFitYesNo = checks.resol_fitYesNo;


%Contrasts.
% These we can just build from the relevant problemDef_cells
% by doing the opposite of the input class parsing...

% problemDef_cells{1} = repeatLayers;
% problemDef_cells{2} = allData;
% problemDef_cells{3} = dataLimits;
% problemDef_cells{4} = simLimits;
% problemDef_cells{5} = contrastLayers;
% problemDef_cells{6} = layersDetails;
% problemDef_cells{7} = paramNames;
% problemDef_cells{8} = backsNames;
% problemDef_cells{9} = sfNames;
% problemDef_cells{10} = shiftsNames;
% problemDef_cells{11} = nbaNames;
% problemDef_cells{12} = nbsNames;
% problemDef_cells{13} = resolNames;

disp('debug');






end