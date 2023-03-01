function [problemDef,problemDef_cells,problemDef_limits,priors,controls] = RatParseClassToStructs_new(inputProblemDef,inputControls)

% Breaks up the classes into the relevant structures for inputting into C

% Put the extracted fields into a cell array...
% Structure of problemDef_cells array.
%
% {1} - inputProblemDef.contrastRepeatSLDs
%       {1 x nContrasts} array of cells
%       Each cell is {1 x 2 double}.
%
% {2} - inputProblemDef.allData
%       {1 x nContrasts} array of cells
%       Each cell is {Inf x 3 double}
%
% {3} - inputProblemDef.dataLimits
%       {1 x nContrasts} array of cells
%       Each cell is {1 x 2 double}
%
% {4} - inputProblemDef.simLimits
%       {1 x nContrasts} array of cells
%       Each cell is {1 x 2 double}
%
% {5} - inputProblemDef.contrastLayers
%       {1 x nContrasts} array of cells
%       Each cell is {1 x Inf double}
%
% {6} - inputProblemDef.layersDetails
%       {n x 1} array of cells
%       Each cell is (1 x 5 double}
%
% {7} - inputProblemDef.paramNames
%       {1 x nParams} array of cells
%       Each cell is {1 x Inf char}
%
% {8} - inputProblemDef.backgroundsNames
%       {1 x nBackgrounds} array of cells
%       Each cell is {1 x Inf char}
% 
% {9} - inputProblemDef.scalefactorNames
%       {1 x nScales} array of cells
%       Each cell is {1 x Inf char}
% 
% {10}- inputProblemDef.qzshiftNames
%       {1 x nShifts} array of cells
%       Each cell is {1 x Inf char}
% 
% {11}- inputProblemDef.nbairNames
%       {1 x nNba} array of cells
%       Each cell is {1 x Inf char}
% 
% {12}- inputProblemDef.nbsrNames
%       {1 x nNba} array of cells
%       Each cell is {1 x Inf char}
% 
% {13}- inputProblemDef.resolNames
%       {1 x nNba} array of cells
%       Each cell is {1 x Inf char}
%
% {14} - inputProblemDef.customFiles
%          array of cells
%       Each cell is {fName, lang, path}

 
% First parse the class to a structure variable.

inputStruct = inputProblemDef.toStruct();

%Start by removing the cell arrays
repeatLayers = inputStruct.contrastRepeatSLDs; %*****
allData = inputStruct.allData;
dataLimits = inputStruct.dataLimits;
simLimits = inputStruct.simLimits;
contrastLayers = inputStruct.contrastLayers;
layersDetails = inputStruct.layersDetails;
paramNames = inputStruct.paramNames;
paramPriors = inputStruct.paramPriors;
backsNames = inputStruct.backParNames;
backsPriors = inputStruct.backsPriors; % 
sfNames = inputStruct.scalefactorNames;
scalesPriors = inputStruct.scalefactorPriors;
shiftsNames = inputStruct.qzshiftNames; % TODO
shiftPriors = inputStruct.qzshiftPriors;
nbaNames = inputStruct.nbairNames;
nbaPriors = inputStruct.nbaPriors;
nbsNames = inputStruct.nbsubNames;
nbsPriors = inputStruct.nbsPriors;
resolNames = inputStruct.resolParNames;         % ******* ToDo
resolParPriors = inputStruct.resolParPriors;
customFiles = inputStruct.files;

% If any of the contrastLayers are empty, replace the empty cells by zero
% thickness layers
for i = 1:length(contrastLayers)
    thisLayers = contrastLayers{i};
    if isempty(thisLayers)
        thisLayers = 0;
        contrastLayers{i} = thisLayers;
    end
end

% Do the same for layersDetails
if isempty(layersDetails)
    layersDetails = {0};
end

% When there are custom files, we need to strip the file extension
% from the filename if it's present
for i = 1:length(customFiles)
    thisCustomFileCell = customFiles{i};
    [~,name,~] = fileparts(thisCustomFileCell{1});
    thisCustomFileCell{1} = name;
    customFiles{i} = thisCustomFileCell;
end

% Pull out all the cell arrays (except priors) into one array
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
problemDef_cells{14} = customFiles';

% Fix for cell array bug with custom layers - is this needed still??
if strcmpi(inputStruct.modelType,'custom layers') || strcmpi(inputStruct.modelType,'custom xy')
    for i = 1:length(problemDef_cells{5})
        problemDef_cells{5}{i} = 0;
    end
    
    problemDef_cells{6} = {0};
    
end

% Also the custom files array..
if isempty(problemDef_cells{14})
    problemDef_cells{14} = {{'','',''}};
end

% Put the priors into their own array
priors.paramPriors = paramPriors;
priors.backsPriors = backsPriors;
priors.resolPriors = resolParPriors;
priors.nbaPriors = nbaPriors;
priors.nbsPriors = nbsPriors;
priors.shiftPriors = shiftPriors;
priors.scalesPriors = scalesPriors;

totalNumber = size(priors.paramPriors,1) + size(priors.backsPriors,1) + ...
    size(priors.resolPriors,1) + size(priors.nbaPriors,1) + size(priors.nbsPriors,1) + ...
    size(priors.shiftPriors,1) + size(priors.scalesPriors,1);

allPriors = cell(totalNumber,4);
cellCount = 1;
for i = 1:size(priors.paramPriors,1)
    allPriors{cellCount,1} = priors.paramPriors{i}{1};
    allPriors{cellCount,2} = priors.paramPriors{i}{2};
    allPriors{cellCount,3} = num2str(priors.paramPriors{i}{3});
    allPriors{cellCount,4} = num2str(priors.paramPriors{i}{4});
    cellCount = cellCount + 1;
end

for i = 1:size(priors.backsPriors,1)
    allPriors{cellCount,1} = priors.backsPriors{i}{1};
    allPriors{cellCount,2} = priors.backsPriors{i}{2};
    allPriors{cellCount,3} = num2str(priors.backsPriors{i}{3});
    allPriors{cellCount,4} = num2str(priors.backsPriors{i}{4});
    cellCount = cellCount + 1;
end

for i = 1:size(priors.resolPriors,1)
    allPriors{cellCount,1} = priors.resolPriors{i}{1};
    allPriors{cellCount,2} = priors.resolPriors{i}{2};
    allPriors{cellCount,3} = num2str(priors.resolPriors{i}{3});
    allPriors{cellCount,4} = num2str(priors.resolPriors{i}{4});
    cellCount = cellCount + 1;
end

for i = 1:size(priors.nbaPriors,1)
    allPriors{cellCount,1} = priors.nbaPriors{i}{1};
    allPriors{cellCount,2} = priors.nbaPriors{i}{2};
    allPriors{cellCount,3} = num2str(priors.nbaPriors{i}{3});
    allPriors{cellCount,4} = num2str(priors.nbaPriors{i}{4}); 
    cellCount = cellCount + 1;
end

for i = 1:size(priors.nbsPriors,1)
    allPriors{cellCount,1} = priors.nbsPriors{i}{1};
    allPriors{cellCount,2} = priors.nbsPriors{i}{2};
    allPriors{cellCount,3} = num2str(priors.nbsPriors{i}{3});
    allPriors{cellCount,4} = num2str(priors.nbsPriors{i}{4});
    cellCount = cellCount + 1;
end

for i = 1:size(priors.shiftPriors,1)
    allPriors{cellCount,1} = priors.shiftPriors{i}{1};
    allPriors{cellCount,2} = priors.shiftPriors{i}{2};
    allPriors{cellCount,3} = num2str(priors.shiftPriors{i}{3});
    allPriors{cellCount,4} = num2str(priors.shiftPriors{i}{4});
    cellCount = cellCount + 1;
end

for i = 1:size(priors.scalesPriors,1)
    allPriors{cellCount,1} = priors.scalesPriors{i}{1};
    allPriors{cellCount,2} = priors.scalesPriors{i}{2};
    allPriors{cellCount,3} = num2str(priors.scalesPriors{i}{3});
    allPriors{cellCount,4} = num2str(priors.scalesPriors{i}{4});
    cellCount = cellCount + 1;
end

priorNames = allPriors(:,1);
priorVals = allPriors(:,2:end);

priors.priorNames = priorNames;
priors.priorVals = priorVals;


%Split up the contrastBacks array
contrastBacks = inputStruct.contrastBacks;
for i = 1:length(contrastBacks)
    problemDef.contrastBacks(i) = contrastBacks{i}(1);
    problemDef.contrastBacksType(i) = contrastBacks{i}(2);
end
    
% Here we need to do the same with the contrastResolutions array
contrastResols = inputStruct.contrastRes;
resolTypes = inputStruct.resolutionTypes;
for i = 1:length(contrastResols)
    % Check the type of the resolution that each contrast is pointing to.
    % If it is a constant, point to the number of the corresponding
    % resolution par. If it's data, then set it to zero
    thisResol = contrastResols(i);      % Which reolution
    thisType = resolTypes{thisResol};   % What type is it?
    
    if strcmpi(thisType,'data')
        % Resolution is in the datafile. Set contrastRes to zero
        contrastRes(i) = -1;
    else
        % Resolution is a resolParam, the nname of which should
        % be in the first column of resolutionValues
        whichResolParName = inputStruct.resolutionValues{thisResol,1};
        
        % Find which resolPar this is, and set contrastRes to this number
        resolParNumber = find(strcmpi(whichResolParName,resolNames));
        contrastRes(i) = resolParNumber;
    end
end
        

%Now make the limits array
for i = 1:length(inputStruct.paramConstr)
    problemDef_limits.params(i,:) = inputStruct.paramConstr{i};
end

for i = 1:length(inputStruct.backParconstr)
    problemDef_limits.backs(i,:) = inputStruct.backParconstr{i};
end

for i = 1:length(inputStruct.scalefactorConstr)
    problemDef_limits.scales(i,:) = inputStruct.scalefactorConstr{i};
end

for i = 1:length(inputStruct.qzshiftConstr)
    problemDef_limits.shifts(i,:) = inputStruct.qzshiftConstr{i};
end

for i = 1:length(inputStruct.nbairConstr)
    problemDef_limits.nba(i,:) = inputStruct.nbairConstr{i};
end

for i = 1:length(inputStruct.nbsubConstr)
    problemDef_limits.nbs(i,:) = inputStruct.nbsubConstr{i};
end

for i = 1:length(inputStruct.resolParConstr)
    problemDef_limits.res(i,:) = inputStruct.resolParConstr{i};
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
    'resolutionConstr',...
    'files'};

%Make the problemDef structure from the bits left.....

% *************************************************************************
% NOTE - not using the more complicated background and resolution
% definitions for now - instead use the background names and backsPar
% values.... fix this next
% **********************************************************************8


problemDef.TF = inputStruct.TF;%'standardTF';
problemDef.resample = inputStruct.resample;
problemDef.dataPresent = inputStruct.dataPresent;
problemDef.numberOfContrasts = inputStruct.numberOfContrasts;
problemDef.geometry = inputStruct.geometry;
%problemDef.contrastBacks = contrastBacks;
problemDef.contrastShifts = inputStruct.contrastShifts;
problemDef.contrastScales = inputStruct.contrastScales;
problemDef.contrastNbas = inputStruct.contrastNbas;
problemDef.contrastNbss = inputStruct.contrastNbss;
problemDef.contrastRes = contrastRes;
problemDef.backs = inputStruct.backParVals; %inputStruct.backgrounds;       % **** note backPar workaround (todo) ****
problemDef.shifts = inputStruct.qzshifts;
problemDef.sf = inputStruct.scalefactors;
problemDef.nba = inputStruct.nbairs;
problemDef.nbs = inputStruct.nbsubs;
problemDef.res = inputStruct.resolPars; %inputStruct.resolutions;           % **** note resolPar workaround (todo) ****          
problemDef.params = inputStruct.params;
problemDef.numberOfLayers = inputStruct.numberOfLayers;
problemDef.modelType = inputStruct.modelType;
problemDef.contrastCustomFiles = inputStruct.contrastCustomFile;

% if isfield(inputStruct,'modelFilename')
%     if ~isempty(inputStruct.modelFilename)
%         [path,fname,extension] = fileparts(inputStruct.modelFilename);
%     else
%         fname = '';
%         path = pwd;
%     end
% else
%     fname = '';
%     path = pwd;
% end
%     
% problemDef.modelFilename = fname;
% problemDef.path = path;
% 
% if isfield(inputStruct,'modelLanguage')
%     if ~isempty(inputStruct.modelLanguage)
%         problemDef.modelLanguage = inputStruct.modelLanguage;
%     else
%         problemDef.modelLanguage = 'matlab';
%     end
% else
%     problemDef.modelLanguage = '';
% end
    
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

controls.resamPars = inputControls.resamPars;% [0.95 10];
controls.updateFreq = inputControls.updateFreq;
controls.updatePlotFreq = inputControls.updatePlotFreq;

controls.nSamples = inputControls.nSamples;
controls.nChains = inputControls.nChains;   
controls.lambda = inputControls.lambda;      
controls.p_unit_gamma = inputControls.p_unit_gamma;
controls.boundHandling = inputControls.boundHandling;

%Also need to deal with the checks...
checks.params_fitYesNo = inputStruct.paramFitYesNo;
checks.backs_fitYesNo = inputStruct.backParFitYesNo;
checks.shifts_fitYesNo = inputStruct.qzshiftFitYesNo;
checks.scales_fitYesNo = inputStruct.scalefactorFitYesNo;
checks.nbairs_fitYesNo = inputStruct.nbaFitYesNo;
checks.nbsubs_fitYesNo = inputStruct.nbsFitYesNo;
checks.resol_fitYesNo = inputStruct.resolFitYesNo;

controls.checks = checks;

end