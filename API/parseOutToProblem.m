function outProblemDef = parseOutToProblem(inProblem,problemDefCells,problemDefLimits,result,controls)

%Reconstruct the problemDef class as an output
%Using the outputs from the calculation(s)
outProblemDef = problemDef;
checks = controls.checks;

%(1) Parameters
pars = inProblem.params;
numberOfParameters = length(pars);

outProblemDef.nParams = numberOfParameters;
outProblemDef.params = pars;

names = problemDefCells{7};
outProblemDef.paramNames = names;

limits = problemDefLimits.params;

for i = 1:numberOfParameters
    outProblemDef.paramConstr{i} = limits(i,:);
end

outProblemDef.paramFitYesNo = checks.params_fitYesNo;



%(2) Backgrounds
backs = inProblem.backs;
numberOfBacks = length(backs);

outProblemDef.nBackgrounds = numberOfBacks;
outProblemDef.backgrounds = backs;

backNames = problemDefCells{8};
outProblemDef.backgroundNames = backNames;

backsLimits = problemDefLimits.backs;
for i = 1:numberOfBacks
    outProblemDef.backgroundConstr{i} = limits(i,:);
end

outProblemDef.backgroundFitYesNo = checks.backs_fitYesNo;



%(3) Scalefactors
scales = inProblem.sf;
numberOfScales = length(scales);

outProblemDef.nScalefactors = numberOfScales;
outProblemDef.scalefactors = scales;

scaleNames = problemDefCells{9};
outProblemDef.scalefactorNames = scaleNames;

scaleLimits = problemDefLimits.scales;
for i = 1:numberOfScales
    outProblemDef.scalefactorConstr{i} = scaleLimits(i,:);
end

outProblemDef.scalefactorFitYesNo = checks.scales_fitYesNo;


%(4) Qzshifts
shifts = inProblem.shifts;
numberOfShifts = length(shifts);

outProblemDef.nQzshifts = numberOfShifts;
outProblemDef.qzshifts = shifts;

shiftNames = problemDefCells{10};
outProblemDef.qzshiftNames = shiftNames;

shiftLimits = problemDefLimits.shifts;
for i = 1:numberOfShifts
    outProblemDef.qzshiftConstr{i} = shiftLimits(i,:);
end
outProblemDef.qzshiftFitYesNo = checks.shifts_fitYesNo;


%(4) Nbairs
nbairs = inProblem.nba;
numberOfNbairs = length(nbairs);

outProblemDef.nNbairs = numberOfNbairs;
outProblemDef.nbairs = nbairs;

nbairNames = problemDefCells{11};
outProblemDef.nbairNames = nbairNames;

nbairLimits = problemDefLimits.nba;
for i = 1:numberOfNbairs
    outProblemDef.nbairConstr{i} = nbairLimits(i,:);
end
outProblemDef.nbairFitYesNo = checks.nbairs_fitYesNo;


%(5) Nbsubs
nbsubs = inProblem.nbs;
numberOfNbsubs = length(nbsubs);

outProblemDef.nNbsubs = numberOfNbsubs;
outProblemDef.nbsubs = nbsubs;

nbsubsNames = problemDefCells{12};
outProblemDef.nbsubNames = nbsubsNames;

nbsubLimits = problemDefLimits.nbs;
for i = 1:numberOfNbsubs
    outProblemDef.nbsubConstr{i} = nbsubLimits(i,:);
end
outProblemDef.nbsubFitYesNo = checks.nbsubs_fitYesNo;


%(5) Resolutions
resol = inProblem.res;
numberOfResols = length(resol);

outProblemDef.nResolutions = numberOfResols;
outProblemDef.resolutions = resol;

resolNames = problemDefCells{13};
outProblemDef.resolutionNames = resolNames;

resolLimits = problemDefLimits.res;
for i = 1:numberOfResols
    outProblemDef.resolutionConstr{i} = resolLimits(i,:);
end
outProblemDef.resolutionFitYesNo = checks.resol_fitYesNo;


%Contrasts.
% These we can just build from the relevant problemDefCells
% by doing the opposite of the input class parsing...

% problemDefCells{1} = repeatLayers;
% problemDefCells{2} = allData;
% problemDefCells{3} = dataLimits;
% problemDefCells{4} = simLimits;
% problemDefCells{5} = contrastLayers;
% problemDefCells{6} = layersDetails;
% problemDefCells{7} = paramNames;
% problemDefCells{8} = backsNames;
% problemDefCells{9} = sfNames;
% problemDefCells{10} = shiftsNames;
% problemDefCells{11} = nbaNames;
% problemDefCells{12} = nbsNames;
% problemDefCells{13} = resolNames;

disp('debug');






end