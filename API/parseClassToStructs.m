function [problemDefStruct,problemDefCells,problemDefLimits,priors,controls] = parseClassToStructs(problemDefInput,inputControls)

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
% {6} - inputProblemDef.layerDetails
%       {n x 1} array of cells
%       Each cell is (1 x 5 double}
%
% {7} - inputProblemDef.paramNames
%       {1 x nParams} array of cells
%       Each cell is {1 x Inf char}
%
% {8} - inputProblemDef.backgroundParamNames
%       {1 x nBackgroundParams} array of cells
%       Each cell is {1 x Inf char}
% 
% {9} - inputProblemDef.scalefactorNames
%       {1 x nScalefactors} array of cells
%       Each cell is {1 x Inf char}
% 
% {10}- inputProblemDef.qzshiftNames
%       {1 x nQzshifts} array of cells
%       Each cell is {1 x Inf char}
% 
% {11}- inputProblemDef.bulkInNames
%       {1 x nBulkIn} array of cells
%       Each cell is {1 x Inf char}
% 
% {12}- inputProblemDef.bulkOutNames
%       {1 x nBulkOut} array of cells
%       Each cell is {1 x Inf char}
% 
% {13}- inputProblemDef.resolutionParamNames
%       {1 x nResolutionParams} array of cells
%       Each cell is {1 x Inf char}
%
% {14} - inputProblemDef.customFiles
%        {1 x nCustomFiles} array of cells
%        Each cell is {1 x Inf char}
%
% {15} - inputProblemDef.backgroundTypes
%        {1 x nBackgrounds} array of cells
%        Each cell is {1 x Inf char}
%
% {16} - inputProblemDef.resolutionTypes
%        {1 x nResolutions} array of cells
%        Each cell is {1 x Inf char}
%
% {17} - inputProblemDef.allOilChiData
%        {1 x nContrasts} array of cells
%        Each cell is {Inf x 3 double}
%
% {18} - inputProblemDef.domainContrastRepeatSLDs
%        {1 x nDomainContrasts} array of cells
%        Each cell is {1 x 2 double}.
%
% {19} - inputProblemDef.domainContrastLayers
%        {1 x nDomainContrasts} array of cells
%        Each cell is {1 x Inf double}
% 
% {20} - inputProblemDef.domainRatioNames
%        {1 x nDomainRatios} array of cells
%        Each cell is {1 x Inf char}

 
% First parse the class to a structure variable.
inputStruct = problemDefInput.toStruct();

%% Start by removing the cell arrays
contrastLayers = inputStruct.contrastLayers;
layerDetails = inputStruct.layerDetails;

% If any of the contrastLayers are empty, replace the empty cells by zero
% thickness layers
for i = 1:length(contrastLayers)
    thisLayer = contrastLayers{i};
    if isempty(thisLayer)
        contrastLayers{i} = 0;
    end
end

% Do the same for layerDetails
if isempty(layerDetails)
    layerDetails = {0};
end

% Pull out all the cell arrays (except priors) into one array
problemDefCells{1} = inputStruct.contrastRepeatSLDs;
problemDefCells{2} = inputStruct.allData;
problemDefCells{3} = inputStruct.dataLimits;
problemDefCells{4} = inputStruct.simLimits;
problemDefCells{5} = contrastLayers;
problemDefCells{6} = layerDetails;
problemDefCells{7} = inputStruct.paramNames;
problemDefCells{8} = inputStruct.backgroundParamNames;
problemDefCells{9} = inputStruct.scalefactorNames;
problemDefCells{10} = inputStruct.qzshiftNames;
problemDefCells{11} = inputStruct.bulkInNames;
problemDefCells{12} = inputStruct.bulkOutNames;
problemDefCells{13} = inputStruct.resolutionParamNames;
problemDefCells{14} = inputStruct.files;
problemDefCells{15} = cellstr(inputStruct.backgroundTypes');
problemDefCells{16} = cellstr(inputStruct.resolutionTypes');
problemDefCells{17} = inputStruct.allOilChiData;

% Now deal with domains cell arrays
if isa(problemDefInput, 'domainsClass') && isa(problemDefInput.domainContrasts, 'domainContrastsClass')

    domainContrastLayers = inputStruct.domainContrastLayers;

    % If any of the domainContrastLayers are empty, replace the empty
    % cells by zero thickness layers
    for i = 1:length(domainContrastLayers)
        thisLayer = domainContrastLayers{i};
        if isempty(thisLayer)
            domainContrastLayers{i} = 0;
        end
    end
    
    problemDefCells{18} = inputStruct.domainContrastRepeatSLDs;
    problemDefCells{19} = domainContrastLayers;
    
else

    problemDefCells{18} = cell(1,0);
    problemDefCells{19} = cell(1,0);

end

if isa(problemDefInput, 'domainsClass')
    problemDefCells{20} = inputStruct.domainRatioNames;
else
    problemDefCells{20} = cell(1,0);
end

% Fix for cell array bug with custom layers - is this needed still??
if strcmpi(inputStruct.modelType,'custom layers') || strcmpi(inputStruct.modelType,'custom xy')
    for i = 1:length(problemDefCells{5})
        problemDefCells{5}{i} = 0;
    end
    for i = 1:length(problemDefCells{19})
        problemDefCells{19}{i} = 0;
    end
    
    problemDefCells{6} = {0};
    
end

% Also the custom files array..
if isempty(problemDefCells{14})
    problemDefCells{14} = {''};
end


%% Put the priors into their own array
priors.param = inputStruct.paramPriors;
priors.backgroundParam = inputStruct.backgroundParamPriors;
priors.resolutionParam = inputStruct.resolutionParamPriors;
priors.bulkIn = inputStruct.bulkInPriors;
priors.bulkOut = inputStruct.bulkOutPriors;
priors.qzshift = inputStruct.qzshiftPriors;
priors.scalefactor = inputStruct.scalefactorPriors;
if isa(problemDefInput, 'domainsClass')
    priors.domainRatio = inputStruct.domainRatioPriors;
else
    priors.domainRatio = cell(0,1);
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
       
        % Check prior type.....
        thisType = priors.(currentPrior){j}{2};

        if strcmpi(thisType,'uniform')
            priorType = 1;
        elseif strcmpi(thisType,'gaussian')
            priorType = 2;
        else
            priorType = 3;
        end
        allPriors{cellCount,2} = priorType;

        allPriors{cellCount,3} = priors.(currentPrior){j}{3};
        allPriors{cellCount,4} = priors.(currentPrior){j}{4};
        cellCount = cellCount + 1;
    end
end

priors.priorNames = allPriors(:, 1);
priors.priorValues = cell2mat(allPriors(:, 2:end));


%% Split up the contrastBackgrounds array
contrastBackgrounds = inputStruct.contrastBackgrounds;
for i = 1:length(contrastBackgrounds)
    problemDefStruct.contrastBackgrounds(i) = contrastBackgrounds{i}(1);
    problemDefStruct.contrastBackgroundsType(i) = contrastBackgrounds{i}(2);
end
    
% Here we need to do the same with the contrastResolutions array
contrastResolutions = inputStruct.contrastResolutions;
resolutionNames = inputStruct.resolutionParamNames;
resolutionTypes = inputStruct.resolutionTypes;
contrastRes = zeros(1, length(contrastResolutions));
for i = 1:length(contrastResolutions)
    % Check the type of the resolution that each contrast is pointing to.
    % If it is a constant, point to the number of the corresponding
    % resolution par. If it's data, then set it to zero
    thisResol = contrastResolutions(i);      % Which reolution
    thisType = resolutionTypes{thisResol};   % What type is it?
    
    if strcmpi(thisType,'data')
        % Resolution is in the datafile. Set contrastRes to zero
        contrastRes(i) = -1;
    else
        % Resolution is a resolutionParam, the name of which should
        % be in the first column of resolutionValues
        whichResolutionParamName = inputStruct.resolutionValues{thisResol,1};
        
        % Find which resolutionParam this is, and set contrastRes to this number
        resolutionParamNumber = find(strcmpi(whichResolutionParamName,resolutionNames));
        contrastRes(i) = resolutionParamNumber;
    end
end
        

%% Now make the limits array
for i = 1:length(inputStruct.paramLimits)
    problemDefLimits.param(i,:) = inputStruct.paramLimits{i};
end

for i = 1:length(inputStruct.backgroundParamLimits)
    problemDefLimits.backgroundParam(i,:) = inputStruct.backgroundParamLimits{i};
end

for i = 1:length(inputStruct.scalefactorLimits)
    problemDefLimits.scalefactor(i,:) = inputStruct.scalefactorLimits{i};
end

for i = 1:length(inputStruct.qzshiftLimits)
    problemDefLimits.qzshift(i,:) = inputStruct.qzshiftLimits{i};
end

for i = 1:length(inputStruct.bulkInLimits)
    problemDefLimits.bulkIn(i,:) = inputStruct.bulkInLimits{i};
end

for i = 1:length(inputStruct.bulkOutLimits)
    problemDefLimits.bulkOut(i,:) = inputStruct.bulkOutLimits{i};
end

for i = 1:length(inputStruct.resolutionParamLimits)
    problemDefLimits.resolutionParam(i,:) = inputStruct.resolutionParamLimits{i};
end

if isa(problemDefInput, 'domainsClass')
    for i = 1:length(inputStruct.domainRatioLimits)
        problemDefLimits.domainRatio(i,:) = inputStruct.domainRatioLimits{i};
    end
else
    problemDefLimits.domainRatio = ones(0,2);
end


%% Make the problemDefStruct structure from the remaining inputs

% *************************************************************************
% NOTE - not using the more complicated background and resolution
% definitions for now - instead use the background names and
% backgroundParam values.... fix this next
% *************************************************************************


problemDefStruct.TF = inputStruct.TF;
problemDefStruct.resample = inputStruct.resample;
problemDefStruct.dataPresent = inputStruct.dataPresent;
problemDefStruct.oilChiDataPresent = inputStruct.oilChiDataPresent;
problemDefStruct.numberOfContrasts = inputStruct.numberOfContrasts;
problemDefStruct.geometry = inputStruct.geometry;
problemDefStruct.useImaginary = inputStruct.useImaginary;
%problemDefStruct.contrastBackgrounds = contrastBackgrounds;
problemDefStruct.contrastQzshifts = inputStruct.contrastQzshifts;
problemDefStruct.contrastScalefactors = inputStruct.contrastScalefactors;
problemDefStruct.contrastBulkIns = inputStruct.contrastBulkIns;
problemDefStruct.contrastBulkOuts = inputStruct.contrastBulkOuts;
problemDefStruct.contrastResolutions = contrastRes;
problemDefStruct.backgroundParams = inputStruct.backgroundParamValues; %inputStruct.backgrounds;       % **** note backPar workaround (todo) ****
problemDefStruct.qzshifts = inputStruct.qzshiftValues;
problemDefStruct.scalefactors = inputStruct.scalefactorValues;
problemDefStruct.bulkIn = inputStruct.bulkInValues;
problemDefStruct.bulkOut = inputStruct.bulkOutValues;
problemDefStruct.resolutionParams = inputStruct.resolutionParamValues; %inputStruct.resolutions;           % **** note resolutionParam workaround (todo) ****          
problemDefStruct.params = inputStruct.paramValues;
problemDefStruct.numberOfLayers = inputStruct.numberOfLayers;
problemDefStruct.modelType = inputStruct.modelType;
problemDefStruct.contrastCustomFiles = inputStruct.contrastCustomFile;

% Add the domains parameters, using dummy values if this is not a domains
% calculation
problemDefStruct.contrastDomainRatios = inputStruct.contrastDomainRatios;

if isa(problemDefInput, 'domainsClass')
    problemDefStruct.domainRatio = inputStruct.domainRatioValues;
else
    problemDefStruct.domainRatio = ones(1,0);
end

if isa(problemDefInput, 'domainsClass') && isa(problemDefInput.domainContrasts, 'domainContrastsClass')
    problemDefStruct.numberOfDomainContrasts = inputStruct.numberOfDomainContrasts;
else
    problemDefStruct.numberOfDomainContrasts = 0;
end    

% Initialise the lists of fitting parameters    
problemDefStruct.fitParams = [];
problemDefStruct.otherParams = [];
problemDefStruct.fitLimits = [];
problemDefStruct.otherLimits = [];


%% Now deal with the controls class
controls.procedure = inputControls.procedure;
controls.parallel = inputControls.parallel;
controls.resamPars = inputControls.resamPars;
controls.calcSldDuringFit = inputControls.calcSldDuringFit;
controls.display = inputControls.display;
controls.tolX = inputControls.tolX;
controls.tolFun = inputControls.tolFun;
controls.maxFunEvals = inputControls.maxFunEvals;
controls.maxIter = inputControls.maxIter;
controls.updateFreq = inputControls.updateFreq;
controls.updatePlotFreq = inputControls.updatePlotFreq;
controls.populationSize = inputControls.populationSize;
controls.fWeight = inputControls.fWeight;
controls.crossoverProbability = inputControls.crossoverProbability;
controls.strategy = inputControls.strategy;
controls.targetValue = inputControls.targetValue;
controls.numGenerations = inputControls.numGenerations;
controls.Nlive = inputControls.Nlive;
controls.Nmcmc = inputControls.Nmcmc;
controls.propScale = inputControls.propScale;
controls.nsTolerance = inputControls.nsTolerance;
controls.nSamples = inputControls.nSamples;
controls.nChains = inputControls.nChains;   
controls.jumpProbability = inputControls.jumpProbability;      
controls.pUnitGamma = inputControls.pUnitGamma;
controls.boundHandling = inputControls.boundHandling;
controls.adaptPCR = inputControls.adaptPCR;

% Also need to deal with the checks...
checks.fitParam = inputStruct.fitParam;
checks.fitBackgroundParam = inputStruct.fitBackgroundParam;
checks.fitQzshift = inputStruct.fitQzshift;
checks.fitScalefactor = inputStruct.fitScalefactor;
checks.fitBulkIn = inputStruct.fitBulkIn;
checks.fitBulkOut = inputStruct.fitBulkOut;
checks.fitResolutionParam = inputStruct.fitResolutionParam;
if isa(problemDefInput, 'domainsClass')
    checks.fitDomainRatio = inputStruct.fitDomainRatio;
else
    checks.fitDomainRatio = ones(1,0);
end

controls.checks = checks;

end