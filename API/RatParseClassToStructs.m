function [problemDef,problemDef_cells,problemDef_limits,controls] = RatParseClassToStructs(inputProblemDef,inputControls)

%Breaks up the classes into the relevant structures for inputting into C
%For now, makes the 'old API' versions which are a copy of the original
%structs. This will change.

%Start by removing the cell arrays
repeatLayers = inputProblemDef.contrastRepeatSLDs;
allData = inputProblemDef.allData;
dataLimits = inputProblemDef.dataLimits;
simLimits = inputProblemDef.simLimits;
contrastLayers = inputProblemDef.contrastLayers;
layersDetails = inputProblemDef.layersDetails;
paramNames = inputProblemDef.paramNames;
backsNames = inputProblemDef.backgroundNames;
sfNames = inputProblemDef.scalefactorNames;
shiftsNames = inputProblemDef.qzshiftNames;
nbaNames = inputProblemDef.nbairNames;
nbsNames = inputProblemDef.nbsubNames;
resolNames = inputProblemDef.resolutionNames;

%***** Old API cells structure******
%Put the extracted fields into a cell array...
problemDef_cells{1} = repeatLayers;
problemDef_cells{2} = allData;
problemDef_cells{3} = dataLimits;
problemDef_cells{4} = simLimits;
problemDef_cells{5} = contrastLayers;

% Fix for cell array bug with custom layers
if strcmpi(inputProblemDef.modelType,'custom layers') || strcmpi(inputProblemDef.modelType,'Custom XY')
    for i = 1:length(problemDef_cells{5})
        problemDef_cells{5}{i} = 0;
    end
end


problemDef_cells{6} = layersDetails;
problemDef_cells{7} = paramNames;
problemDef_cells{8} = backsNames;
problemDef_cells{9} = sfNames;
problemDef_cells{10} = shiftsNames;
problemDef_cells{11} = nbaNames;
problemDef_cells{12} = nbsNames;
problemDef_cells{13} = resolNames;

%Split up the contrastBacks array
contrastBacks = inputProblemDef.contrastBacks;
for i = 1:length(contrastBacks)
    problemDef.contrastBacks(i) = contrastBacks{i}(1);
    problemDef.contrastBacksType(i) = contrastBacks{i}(2);
end
    
%Now make the limits array
for i = 1:length(inputProblemDef.paramConstr)
    problemDef_limits.params(i,:) = inputProblemDef.paramConstr{i};
end

for i = 1:length(inputProblemDef.backgroundConstr)
    problemDef_limits.backs(i,:) = inputProblemDef.backgroundConstr{i};
end

for i = 1:length(inputProblemDef.scalefactorConstr)
    problemDef_limits.scales(i,:) = inputProblemDef.scalefactorConstr{i};
end

for i = 1:length(inputProblemDef.qzshiftConstr)
    problemDef_limits.shifts(i,:) = inputProblemDef.qzshiftConstr{i};
end

for i = 1:length(inputProblemDef.nbairConstr)
    problemDef_limits.nba(i,:) = inputProblemDef.nbairConstr{i};
end

for i = 1:length(inputProblemDef.nbsubConstr)
    problemDef_limits.nbs(i,:) = inputProblemDef.nbsubConstr{i};
end

for i = 1:length(inputProblemDef.resolutionConstr)
    problemDef_limits.res(i,:) = inputProblemDef.resolutionConstr{i};
end

%Now remove all these fields from inputProblemDef
removedFields = {'contrastRepeatSLDs',...
    'allData',...
    'dataLimits',...
    'simLimits',...
    'contrastLayers',...
    'layersDetails',...
    'paramNames',...
    'backgroundNames',...
    'scalefactorNames',...
    'qzshiftNames',...
    'nbairNames',...
    'nbsubsNames',...
    'resolutionNames',...
    'paramConstr',...
    'backgroundConstr',...
    'scalefactorConstr',...
    'nbairConstr',...
    'nbsubConstr',...
    'resolutionConstr'};

%Make the problemDef structure from the bits left.....
problemDef.TF = 'standardTF'; %for now....
problemDef.resample = inputProblemDef.resample;
problemDef.dataPresent = inputProblemDef.dataPresent;
problemDef.numberOfContrasts = inputProblemDef.numberOfContrasts;
problemDef.geometry = inputProblemDef.experimentGeometry;
%problemDef.contrastBacks = contrastBacks;
problemDef.contrastShifts = inputProblemDef.contrastShifts;
problemDef.contrastScales = inputProblemDef.contrastScales;
problemDef.contrastNbas = inputProblemDef.contrastNbas;
problemDef.contrastNbss = inputProblemDef.contrastNbss;
problemDef.contrastRes = inputProblemDef.contrastRes;
problemDef.backs = inputProblemDef.backgrounds;
problemDef.shifts = inputProblemDef.qzshifts;
problemDef.sf = inputProblemDef.scalefactors;
problemDef.nba = inputProblemDef.nbairs;
problemDef.nbs = inputProblemDef.nbsubs;
problemDef.res = inputProblemDef.resolutions;
problemDef.params = inputProblemDef.params;
problemDef.numberOfLayers = inputProblemDef.numberOfLayers;
problemDef.modelType = inputProblemDef.modelType;
if ~isempty(inputProblemDef.modelFilename)
    [path,fname,extension] = fileparts(inputProblemDef.modelFilename);
else
    fname = '0';
end
problemDef.modelFilename = fname;
problemDef.path = pwd;
problemDef.modelLanguage = inputProblemDef.modelLanguage;
if isempty(inputProblemDef.modelLanguage)
    problemDef.modelLanguage = 'matlab';
end
    
problemDef.fitpars = [];
problemDef.otherpars = [];
problemDef.fitconstr = [];
problemDef.otherconstr = [];

%Now deal with the controls class
controls.para = inputControls.parallel;
controls.proc = inputControls.procedure;
controls.display = inputControls.display;
controls.tolX = inputControls.tolX;
controls.tolFun = inputControls.tolFun;
controls.maxFunEvals = inputControls.maxFunEvals;
controls.maxIter = inputControls.maxIter;
controls.populationSize = inputControls.populationSize;
controls.F_weight = inputControls.F_weight;
controls.F_CR = inputControls.crossoverProbability;
controls.VTR = inputControls.targetValue;
controls.numGen = inputControls.numGenerations;
controls.strategy = inputControls.strategy;
controls.Nlive = inputControls.Nlive;
controls.nmcmc = inputControls.Nmcmc;
controls.propScale = inputControls.propScale;
controls.nsTolerance = inputControls.nsTolerance;
switch inputControls.calcSldDuringFit
    case 'no'
        controls.calcSld = 0;
    otherwise
        controls.calcSld = 1;
end

%Also need to deal with the checks...

checks.params_fitYesNo = inputProblemDef.paramFitYesNo;
checks.backs_fitYesNo = inputProblemDef.backgroundFitYesNo;
checks.shifts_fitYesNo = inputProblemDef.qzshiftFitYesNo;
checks.scales_fitYesNo = inputProblemDef.scalefactorFitYesNo;
checks.nbairs_fitYesNo = inputProblemDef.nbairFitYesNo;
checks.nbsubs_fitYesNo = inputProblemDef.nbsubFitYesNo;
checks.resol_fitYesNo = inputProblemDef.resolutionFitYesNo;

controls.checks = checks;












%********* Old API problem structure******
%              resample: [7×1 double]
%     numberOfContrasts: 7
%              geometry: 'Air / Liquid (or solid)'
%                nbairs: [0 0 0 0 0 0 0]
%                nbsubs: [0 6.3500e-06 0 6.3500e-06 0 6.3500e-06 6.3500e-06]
%         contrastBacks: [2 1 2 1 2 1 1]
%        contrastShifts: [1 1 1 1 1 1 1]
%        contrastScales: [1 1 1 1 1 1 1]
%          contrastNbas: [1 1 1 1 1 1 1]
%          contrastNbss: [2 1 2 1 2 1 1]
%           contrastRes: [1 1 1 1 1 1 1]
%                 backs: [2.9718e-06 5.1473e-06]
%                shifts: 0
%                    sf: 0.2325
%                   nba: 0
%                   nbs: [6.3500e-06 0]
%                   res: 0.0300
%           dataPresent: [1 1 1 1 1 1 1]
%               nParams: 10
%                params: [6.9950 18.6911 6.9473e-06 3.0000 -2.2818e-07 7.0421 5.8839e-06 3.0000 1.8126e-06 10.0536]
%        numberOfLayers: 4
%             whichType: 1
%            fileHandle: []
%                  lang: []
%                module: []
%               fitpars: [18×1 double]
%             otherpars: [0×1 double]
%             fitconstr: [18×2 double]
%           otherconstr: [0×2 double]
%             fitConstr: [18×2 double]


%old API limits structure....
% problemDef_limits = 
% 
%   struct with fields:
% 
%     params: [10×2 double]
%      backs: [2×2 double]
%     scales: [0.1000 0.4000]
%     shifts: [-0.0300 0.0300]
%        nba: [-1.0000e-05 1.0000e-05]
%        nbs: [2×2 double]
%        res: [0.0100 0.0500]










%new API style problem struct....









end