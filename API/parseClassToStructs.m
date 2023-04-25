function [problemDef,problemDefCells,problemDefLimits,priors,controls] = parseClassToStructs(inputProblemDef,inputControls)

% Breaks up the classes into the relevant structures for inputting into C

% Put the extracted fields into a cell array...
% Structure of problemDefCells array.
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
%        Each cell is {fName, lang, path}
%
% {15} - inputProblemDef.domainContrastRepeatSLDs
%        {1 x nDomainContrasts} array of cells
%        Each cell is {1 x 2 double}.
%
% {16} - inputProblemDef.domainContrastLayers
%        {1 x nDomainContrasts} array of cells
%        Each cell is {1 x Inf double}
% 
% {17}- inputProblemDef.domainRatioNames
%       {1 x nDomainRatios} array of cells
%       Each cell is {1 x Inf char}

 
% First parse the class to a structure variable.
inputStruct = inputProblemDef.toStruct();

%% Start by removing the cell arrays
contrastLayers = inputStruct.contrastLayers;
layersDetails = inputStruct.layersDetails;
customFiles = inputStruct.files;

% If any of the contrastLayers are empty, replace the empty cells by zero
% thickness layers
for i = 1:length(contrastLayers)
    thisLayers = contrastLayers{i};
    if isempty(thisLayers)
        contrastLayers{i} = 0;
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
problemDefCells{1} = inputStruct.contrastRepeatSLDs;
problemDefCells{2} = inputStruct.allData;
problemDefCells{3} = inputStruct.dataLimits;
problemDefCells{4} = inputStruct.simLimits;
problemDefCells{5} = contrastLayers;
problemDefCells{6} = layersDetails;
problemDefCells{7} = inputStruct.paramNames;
problemDefCells{8} = inputStruct.backParNames;
problemDefCells{9} = inputStruct.scalefactorNames;
problemDefCells{10} = inputStruct.qzshiftNames; % TODO
problemDefCells{11} = inputStruct.nbairNames;
problemDefCells{12} = inputStruct.nbsubNames;
problemDefCells{13} = inputStruct.resolParNames;         % ******* ToDo
problemDefCells{14} = customFiles';
problemDefCells{15} = cellstr(inputStruct.backgroundTypes');
problemDefCells{16} = cellstr(inputStruct.resolutionTypes');

% Now deal with domains cell arrays
if isa(inputProblemDef, 'domainsClass')

    domainContrastLayers = inputStruct.domainContrastLayers;

    % If any of the domainContrastLayers are empty, replace the empty
    % cells by zero thickness layers
    for i = 1:length(domainContrastLayers)
        thisLayers = domainContrastLayers{i};
        if isempty(thisLayers)
            domainContrastLayers{i} = 0;
        end
    end
    
    problemDefCells{17} = inputStruct.domainContrastRepeatSLDs;
    problemDefCells{18} = domainContrastLayers;
    problemDefCells{19} = inputStruct.domainRatioNames;
    
else

    problemDefCells{17} = cell(1,0);
    problemDefCells{18} = cell(1,0);
    problemDefCells{19} = cell(1,0);

end

% Fix for cell array bug with custom layers - is this needed still??
if strcmpi(inputStruct.modelType,'custom layers') || strcmpi(inputStruct.modelType,'custom xy')
    for i = 1:length(problemDefCells{5})
        problemDefCells{5}{i} = 0;
    end
    for i = 1:length(problemDefCells{18})
        problemDefCells{18}{i} = 0;
    end
    
    problemDefCells{6} = {0};
    
end

% Also the custom files array..
if isempty(problemDefCells{14})
    problemDefCells{14} = {{'','',''}};
end


%% Put the priors into their own array
priors.paramPriors = inputStruct.paramPriors;
priors.backsPriors = inputStruct.backsPriors;
priors.resolPriors = inputStruct.resolParPriors;
priors.nbaPriors = inputStruct.nbaPriors;
priors.nbsPriors = inputStruct.nbsPriors;
priors.shiftPriors = inputStruct.qzshiftPriors;
priors.scalesPriors = inputStruct.scalefactorPriors;
if isa(inputProblemDef, 'domainsClass')
    priors.domainRatioPriors = inputStruct.domainRatioPriors;
else
    priors.domainRatioPriors = cell(0,1);
end

priorFields = fieldnames(priors);
totalNumber = 0;
for i=1:length(priorFields)
    totalNumber = totalNumber + size(priors.(priorFields{i}), 1);
end

allPriors = cell(totalNumber,4);
cellCount = 1;

for i=1:length(priorFields)
    currentPrior = priorFields{i};
    for j = 1:size(priors.(currentPrior), 1)
        allPriors{cellCount,1} = priors.(currentPrior){j}{1};
        allPriors{cellCount,2} = priors.(currentPrior){j}{2};
        allPriors{cellCount,3} = num2str(priors.(currentPrior){j}{3});
        allPriors{cellCount,4} = num2str(priors.(currentPrior){j}{4});
        cellCount = cellCount + 1;
    end
end

priors.priorNames = allPriors(:, 1);
priors.priorVals = allPriors(:, 2:end);


%% Split up the contrastBacks array
contrastBacks = inputStruct.contrastBacks;
for i = 1:length(contrastBacks)
    problemDef.contrastBacks(i) = contrastBacks{i}(1);
    problemDef.contrastBacksType(i) = contrastBacks{i}(2);
end
    
% Here we need to do the same with the contrastResolutions array
contrastResols = inputStruct.contrastRes;
resolNames = inputStruct.resolParNames;
resolTypes = inputStruct.resolutionTypes;
contrastRes = zeros(1, length(contrastResols));
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
        

%% Now make the limits array
for i = 1:length(inputStruct.paramConstr)
    problemDefLimits.params(i,:) = inputStruct.paramConstr{i};
end

for i = 1:length(inputStruct.backParConstr)
    problemDefLimits.backs(i,:) = inputStruct.backParConstr{i};
end

for i = 1:length(inputStruct.scalefactorConstr)
    problemDefLimits.scales(i,:) = inputStruct.scalefactorConstr{i};
end

for i = 1:length(inputStruct.qzshiftConstr)
    problemDefLimits.shifts(i,:) = inputStruct.qzshiftConstr{i};
end

for i = 1:length(inputStruct.nbairConstr)
    problemDefLimits.nba(i,:) = inputStruct.nbairConstr{i};
end

for i = 1:length(inputStruct.nbsubConstr)
    problemDefLimits.nbs(i,:) = inputStruct.nbsubConstr{i};
end

for i = 1:length(inputStruct.resolParConstr)
    problemDefLimits.res(i,:) = inputStruct.resolParConstr{i};
end

if isa(inputProblemDef, 'domainsClass')
    for i = 1:length(inputStruct.domainRatioConstr)
        problemDefLimits.domainRatio(i,:) = inputStruct.domainRatioConstr{i};
    end
else
    problemDefLimits.domainRatio = ones(0,2);
end


%% Now remove all these fields from inputProblemDef
removedFields = {'contrastRepeatSLDs',...
    'domainContrastRepeatSLDs',...
    'allData',...
    'dataLimits',...
    'simLimits',...
    'contrastLayers',...
    'domainContrastLayers',...
    'layersDetails',...
    'paramNames',...
    'backgroundNames',...
    'scalefactorNames',...
    'qzshiftNames',...
    'nbairNames',...
    'nbsubsNames',...
    'resolutionNames',...
    'domainRatioNames',...
    'paramConstr',...
    'backgroundConstr',...
    'scalefactorConstr',...
    'nbairConstr',...
    'nbsubConstr',...
    'resolutionConstr',...
    'domainRatioConstr',...
    'files'};

% Make the problemDef structure from the bits left.....

% *************************************************************************
% NOTE - not using the more complicated background and resolution
% definitions for now - instead use the background names and backsPar
% values.... fix this next
% **********************************************************************8


problemDef.TF = inputStruct.TF;
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

% Add the domains parameters, using dummy values if this is not a domains
% calculation
problemDef.contrastDomainRatios = inputStruct.contrastDomainRatios;

if isa(inputProblemDef, 'domainsClass')
    problemDef.domainRatio = inputStruct.domainRatios;
    problemDef.numberOfDomainContrasts = inputStruct.numberOfDomainContrasts;
    problemDef.domainContrastNbas = inputStruct.domainContrastNbas;
    problemDef.domainContrastNbss = inputStruct.domainContrastNbss;
    problemDef.domainContrastCustomFiles = inputStruct.domainContrastCustomFile;
else
    problemDef.domainRatio = ones(1,0);
    problemDef.numberOfDomainContrasts = 0;
    problemDef.domainContrastNbas = ones(1,0);
    problemDef.domainContrastNbss = ones(1,0);
    problemDef.domainContrastCustomFiles = ones(1,0);
end    

% Initialise the lists of fitting parameters    
problemDef.fitpars = [];
problemDef.otherpars = [];
problemDef.fitconstr = [];
problemDef.otherconstr = [];


%% Now deal with the controls class
controls.para = inputControls.parallel;
controls.proc = inputControls.procedure;
controls.display = inputControls.display;
controls.tolX = inputControls.tolX;
controls.tolFun = inputControls.tolFun;
controls.maxFunEvals = inputControls.maxFunEvals;
controls.maxIter = inputControls.maxIter;
controls.populationSize = inputControls.populationSize;
controls.fWeight = inputControls.fWeight;
controls.F_CR = inputControls.crossoverProbability;
controls.VTR = inputControls.targetValue;
controls.numGen = inputControls.numGenerations;
controls.strategy = inputControls.strategy;
controls.Nlive = inputControls.Nlive;
controls.nmcmc = inputControls.Nmcmc;
controls.propScale = inputControls.propScale;
controls.nsTolerance = inputControls.nsTolerance;
%controls.calcSld = inputControls.calcSldDuringFit;

% **** calcSld is now logical ****
if inputControls.calcSldDuringFit
    controls.calcSld = 1;
else
    controls.calcSld = 0;
end

controls.resamPars = inputControls.resamPars;
controls.updateFreq = inputControls.updateFreq;
controls.updatePlotFreq = inputControls.updatePlotFreq;

controls.nSamples = inputControls.nSamples;
controls.nChains = inputControls.nChains;   
controls.lambda = inputControls.lambda;      
controls.pUnitGamma = inputControls.pUnitGamma;
controls.boundHandling = inputControls.boundHandling;

% Also need to deal with the checks...
checks.params_fitYesNo = inputStruct.paramFitYesNo;
checks.backs_fitYesNo = inputStruct.backParFitYesNo;
checks.shifts_fitYesNo = inputStruct.qzshiftFitYesNo;
checks.scales_fitYesNo = inputStruct.scalefactorFitYesNo;
checks.nbairs_fitYesNo = inputStruct.nbaFitYesNo;
checks.nbsubs_fitYesNo = inputStruct.nbsFitYesNo;
checks.resol_fitYesNo = inputStruct.resolFitYesNo;
if isa(inputProblemDef, 'domainsClass')
    checks.domainRatio_fitYesNo = inputStruct.domainRatioFitYesNo;
else
    checks.domainRatio_fitYesNo = ones(1,0);
end

controls.checks = checks;

end