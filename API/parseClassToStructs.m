function [problemStruct,problemCells,problemLimits,priors,controls] = parseClassToStructs(project,inputControls)

% Breaks up the classes into the relevant structures for inputting into C

% Put the extracted fields into a cell array...
% Structure of problemCells array.
%
% {1} - inputProblem.contrastRepeatSLDs
%       {1 x nContrasts} array of cells
%       Each cell is {1 x 2 double}.
%
% {2} - inputProblem.contrastData
%       {1 x nContrasts} array of cells
%       Each cell is {Inf x 6 double}
%
% {3} - inputProblem.dataLimits
%       {1 x nContrasts} array of cells
%       Each cell is {1 x 2 double}
%
% {4} - inputProblem.simLimits
%       {1 x nContrasts} array of cells
%       Each cell is {1 x 2 double}
%
% {5} - inputProblem.contrastLayers
%       {1 x nContrasts} array of cells
%       Each cell is {1 x Inf double}
%
% {6} - inputProblem.layerDetails
%       {n x 1} array of cells
%       Each cell is (1 x 5 double}
%
% {7} - inputProblem.paramNames
%       {1 x nParams} array of cells
%       Each cell is {1 x Inf char}
%
% {8} - inputProblem.backgroundParamNames
%       {1 x nBackgroundParams} array of cells
%       Each cell is {1 x Inf char}
% 
% {9} - inputProblem.scalefactorNames
%       {1 x nScalefactors} array of cells
%       Each cell is {1 x Inf char}
% 
% {10}- inputProblem.qzshiftNames
%       {1 x nQzshifts} array of cells
%       Each cell is {1 x Inf char}
% 
% {11}- inputProblem.bulkInNames
%       {1 x nBulkIn} array of cells
%       Each cell is {1 x Inf char}
% 
% {12}- inputProblem.bulkOutNames
%       {1 x nBulkOut} array of cells
%       Each cell is {1 x Inf char}
% 
% {13}- inputProblem.resolutionParamNames
%       {1 x nResolutionParams} array of cells
%       Each cell is {1 x Inf char}
%
% {14} - inputProblem.customFiles
%        {1 x nCustomFiles} array of cells
%        Each cell is {1 x Inf char}
%
% {15} - inputProblem.backgroundTypes
%        {1 x nBackgrounds} array of cells
%        Each cell is {1 x Inf char}
%
% {16} - inputProblem.resolutionTypes
%        {1 x nResolutions} array of cells
%        Each cell is {1 x Inf char}
%
% {17} - inputProblem.oilChiData
%        {1 x nContrasts} array of cells
%        Each cell is {Inf x 3 double}
%
% {18} - inputProblem.domainContrastRepeatSLDs
%        {1 x nDomainContrasts} array of cells
%        Each cell is {1 x 2 double}.
%
% {19} - inputProblem.domainContrastLayers
%        {1 x nDomainContrasts} array of cells
%        Each cell is {1 x Inf double}
% 
% {20} - inputProblem.domainRatioNames
%        {1 x nDomainRatios} array of cells
%        Each cell is {1 x Inf char}
%
% {21} - inputProblem.contrastNames
%        {1 x nContrasts} array of cells
%        Each cell is {1 x Inf char}

 
%% First parse the class to a structure variable.
inputStruct = project.toStruct();

% Make the contrast data array up to six columns,
% adding columns of zeros if necessary
inputData = cell(1, length(inputStruct.contrastData));
for i = 1:length(inputStruct.contrastData)
    contrastData = inputStruct.contrastData{i};
    inputData{i} = [contrastData zeros(size(contrastData,1), 6-size(contrastData,2))];
end

%% Pull out all the cell arrays (except priors) into one array
problemCells{1} = inputStruct.contrastRepeatSLDs;
problemCells{2} = inputData;
problemCells{3} = inputStruct.dataLimits;
problemCells{4} = inputStruct.simLimits;
problemCells{5} = inputStruct.contrastLayers;
problemCells{6} = inputStruct.layerDetails;
problemCells{7} = inputStruct.paramNames;
problemCells{8} = inputStruct.backgroundParamNames;
problemCells{9} = inputStruct.scalefactorNames;
problemCells{10} = inputStruct.qzshiftNames;
problemCells{11} = inputStruct.bulkInNames;
problemCells{12} = inputStruct.bulkOutNames;
problemCells{13} = inputStruct.resolutionParamNames;
problemCells{14} = inputStruct.files;
problemCells{15} = cellstr(inputStruct.backgroundTypes');
problemCells{16} = cellstr(inputStruct.resolutionTypes');
problemCells{17} = inputStruct.oilChiData;
problemCells{18} = cell(1, 0);
problemCells{19} = cell(1, 0);
problemCells{20} = cell(1, 0);
problemCells{20} = cell(1, 0);
problemCells{21} = inputStruct.contrastNames;

% Now deal with domains cell arrays
if isa(project, 'domainsClass') && isa(project.domainContrasts, 'domainContrastsClass')
    
    problemCells{18} = inputStruct.domainContrastRepeatSLDs;
    problemCells{19} = inputStruct.domainContrastLayers;
end

if isa(project, 'domainsClass')
    problemCells{20} = inputStruct.domainRatioNames;
end

% Also the custom files array..
if isempty(problemCells{14})
    problemCells{14} = {''};
end


%% Put the priors into their own array
priors.param = inputStruct.paramPriors;
priors.backgroundParam = inputStruct.backgroundParamPriors;
priors.resolutionParam = inputStruct.resolutionParamPriors;
priors.bulkIn = inputStruct.bulkInPriors;
priors.bulkOut = inputStruct.bulkOutPriors;
priors.qzshift = inputStruct.qzshiftPriors;
priors.scalefactor = inputStruct.scalefactorPriors;
if isa(project, 'domainsClass')
    priors.domainRatio = inputStruct.domainRatioPriors;
else
    priors.domainRatio = cell(0,1);
end

priorFields = fieldnames(priors);
totalNumber = 0;
for i=1:length(priorFields)
    totalNumber = totalNumber + size(priors.(priorFields{i}), 1);
end

priorsCell = cell(totalNumber,4);
cellCount = 1;

for i=1:length(priorFields)
    currentPrior = priorFields{i};
    for j = 1:size(priors.(currentPrior), 1)
        priorsCell{cellCount,1} = priors.(currentPrior){j}{1};
       
        % Check prior type.....
        thisType = priors.(currentPrior){j}{2};

        if strcmpi(thisType, priorTypes.Uniform.value)
            priorType = 1;
        elseif strcmpi(thisType, priorTypes.Gaussian.value)
            priorType = 2;
        else
            priorType = 3;
        end
        priorsCell{cellCount,2} = priorType;

        priorsCell{cellCount,3} = priors.(currentPrior){j}{3};
        priorsCell{cellCount,4} = priors.(currentPrior){j}{4};
        cellCount = cellCount + 1;
    end
end

priors.priorNames = priorsCell(:, 1);
priors.priorValues = cell2mat(priorsCell(:, 2:end));


%% Deal with backgrounds and resolutions
backgroundActions = zeros(1, length(inputStruct.contrastBackgrounds));
for i = 1:length(inputStruct.contrastBackgrounds)

    if strcmpi(inputStruct.contrastBackgroundActions{i}, actions.Add)
        backgroundActions(i) = 1;
    else
        backgroundActions(i) = 2;
    end

end

% Convert contrastBackgrounds to parameter indices or data
contrastBackgrounds = inputStruct.contrastBackgrounds;
backgroundTypes = inputStruct.backgroundTypes;

backgroundParamNames = inputStruct.backgroundParamNames;

% Make the contrastBackgroundParams array and set all elements to -Inf.
% Dowstream this is makes it easy to identify unused elements...
contrastBackgroundParams = ones(length(contrastBackgrounds), 5) * -Inf;
contrastBackgroundTypes = cell(1, length(contrastBackgrounds));

for i = 1:length(contrastBackgrounds)
    % Check the type of the background that each contrast is pointing to.
    % If it is a constant, point to the number of the corresponding
    % background param.
    thisBack = contrastBackgrounds(i);      % Which background
    backgroundType = backgroundTypes{thisBack};   % What type is it?
    contrastBackgroundTypes{i} = backgroundType;

    switch backgroundType

        case allowedTypes.Data.value
            % Background is in a datafile.
            % Also need to find the index of the relevant datafile, and add the
            % relevant data as columns 5 and 6 of the contrast data. Finally,
            % deal with the optional background offset if present, and set
            % this as the (optional) second parameter in this row....
    
            % Find corresponding background value
            backgroundDatafileName = inputStruct.backgroundValues{thisBack,1};
            backgroundDataOffset = inputStruct.backgroundValues{thisBack,2};
    
            % Find the index of this data name in the string array...
            backgroundDataIndex = find(strcmp(backgroundDatafileName,inputStruct.dataNames));
    
            if isempty(backgroundDataIndex)
                error('Data background %s not found',backgroundDatafileName);
            else
                % We need at add the background data as columns 5 and 6 on to
                % the data array of this contrast.
                contrastData = problemCells{2}(i);
                backgroundData = inputStruct.allData{backgroundDataIndex};
                contrastData = addDataBackgroundToContrastData(contrastData,backgroundData);
                problemCells{2}(i) = contrastData;
    
                % Also add the index of the data offset to the array...
                contrastBackgroundParams(i,1) = find(strcmpi(backgroundDataOffset,backgroundParamNames));
            end

        case allowedTypes.Constant.value
            % Background is a backgroundParam, the name of which should
            % be in the first column of backgroundValues
            whichBackgroundParamName = inputStruct.backgroundValues{thisBack,1};
    
            % Find which backgroundParam this is, and set contrastBackgroundParams to this number
            contrastBackgroundParams(i,1) = find(strcmpi(whichBackgroundParamName,backgroundParamNames));

        case allowedTypes.Function.value
            % Background is a background function
    
            % Get the corresponding function name...
            backgroundFuncfileName = inputStruct.backgroundValues{thisBack,1};
    
            % Find the index of this data name in the string array...
            thisFuncBack = find(strcmp(backgroundFuncfileName,inputStruct.fileNames));
            contrastBackgroundParams(i,1) = thisFuncBack;
    
            % Now find the indices of any defined parameters...
            allVals = inputStruct.backgroundValues(thisBack,2:end);
            defined = find(~(cellfun(@(x) isequal(x,""),allVals)));  
            for n = 1:numel(defined)
                % Find the relevant background for each..
                thisBackParamName = allVals{n};
                thisParamIndex = find(strcmpi(thisBackParamName,backgroundParamNames));
                contrastBackgroundParams(i,n+1) = thisParamIndex;
            end
            
        otherwise
            error('The background type "%s" is not supported', backgroundType);
    end
end

% Here we need to do the same with the contrastResolutions array
contrastResolutions = inputStruct.contrastResolutions;
resolutionTypes = inputStruct.resolutionTypes;

resolutionParamNames = inputStruct.resolutionParamNames;
contrastResolutionParams = zeros(1, length(contrastResolutions));

for i = 1:length(contrastResolutions)
    % Check the type of the resolution that each contrast is pointing to.
    % If it is a constant, point to the number of the corresponding
    % resolution param. If it's data, then set it to -1
    thisResol = contrastResolutions(i);      % Which resolution
    thisType = resolutionTypes{thisResol};   % What type is it?
    
    if strcmpi(thisType,'data')
        % Resolution is in the datafile. Set contrastResolutionParams to -1
        contrastResolutionParams(i) = -1;
    else
        % Resolution is a resolutionParam, the name of which should
        % be in the first column of resolutionValues
        whichResolutionParamName = inputStruct.resolutionValues{thisResol,1};
        
        % Find which resolutionParam this is, and set contrastResolutionParams to this number
        contrastResolutionParams(i) = find(strcmpi(whichResolutionParamName,resolutionParamNames));
    end
end
        

%% Now make the limits array
for i = 1:length(inputStruct.paramLimits)
    problemLimits.param(i,:) = inputStruct.paramLimits{i};
end

for i = 1:length(inputStruct.backgroundParamLimits)
    problemLimits.backgroundParam(i,:) = inputStruct.backgroundParamLimits{i};
end

for i = 1:length(inputStruct.scalefactorLimits)
    problemLimits.scalefactor(i,:) = inputStruct.scalefactorLimits{i};
end

for i = 1:length(inputStruct.qzshiftLimits)
    problemLimits.qzshift(i,:) = inputStruct.qzshiftLimits{i};
end

for i = 1:length(inputStruct.bulkInLimits)
    problemLimits.bulkIn(i,:) = inputStruct.bulkInLimits{i};
end

for i = 1:length(inputStruct.bulkOutLimits)
    problemLimits.bulkOut(i,:) = inputStruct.bulkOutLimits{i};
end

for i = 1:length(inputStruct.resolutionParamLimits)
    problemLimits.resolutionParam(i,:) = inputStruct.resolutionParamLimits{i};
end

if isa(project, 'domainsClass')
    for i = 1:length(inputStruct.domainRatioLimits)
        problemLimits.domainRatio(i,:) = inputStruct.domainRatioLimits{i};
    end
else
    problemLimits.domainRatio = ones(0,2);
end


%% Make the problemStruct structure from the remaining inputs

problemStruct.TF = inputStruct.TF;
problemStruct.resample = inputStruct.resample;
problemStruct.dataPresent = inputStruct.dataPresent;
problemStruct.oilChiDataPresent = inputStruct.oilChiDataPresent;
problemStruct.numberOfContrasts = inputStruct.numberOfContrasts;
problemStruct.geometry = inputStruct.geometry;
problemStruct.useImaginary = inputStruct.useImaginary;
problemStruct.contrastBackgroundParams = contrastBackgroundParams;
problemStruct.contrastBackgroundTypes = contrastBackgroundTypes;
problemStruct.contrastBackgroundActions = backgroundActions;
problemStruct.contrastQzshifts = inputStruct.contrastQzshifts;
problemStruct.contrastScalefactors = inputStruct.contrastScalefactors;
problemStruct.contrastBulkIns = inputStruct.contrastBulkIns;
problemStruct.contrastBulkOuts = inputStruct.contrastBulkOuts;
problemStruct.contrastResolutionParams = contrastResolutionParams;
problemStruct.backgroundParams = inputStruct.backgroundParamValues; %inputStruct.backgrounds;       % **** note backPar workaround (todo) ****
problemStruct.qzshifts = inputStruct.qzshiftValues;
problemStruct.scalefactors = inputStruct.scalefactorValues;
problemStruct.bulkIn = inputStruct.bulkInValues;
problemStruct.bulkOut = inputStruct.bulkOutValues;
problemStruct.resolutionParams = inputStruct.resolutionParamValues; %inputStruct.resolutions;           % **** note resolutionParam workaround (todo) ****          
problemStruct.params = inputStruct.paramValues;
problemStruct.numberOfLayers = inputStruct.numberOfLayers;
problemStruct.modelType = inputStruct.modelType;
problemStruct.contrastCustomFiles = inputStruct.contrastCustomFile;

% Add the domains parameters, using dummy values if this is not a domains
% calculation
problemStruct.contrastDomainRatios = inputStruct.contrastDomainRatios;

if isa(project, 'domainsClass')
    problemStruct.domainRatio = inputStruct.domainRatioValues;
else
    problemStruct.domainRatio = ones(1,0);
end

if isa(project, 'domainsClass') && isa(project.domainContrasts, 'domainContrastsClass')
    problemStruct.numberOfDomainContrasts = inputStruct.numberOfDomainContrasts;
else
    problemStruct.numberOfDomainContrasts = 0;
end    

% Initialise the lists of fitting parameters    
problemStruct.fitParams = [];
problemStruct.otherParams = [];
problemStruct.fitLimits = [];
problemStruct.otherLimits = [];

% Make sure the indices cannot lie outside of the arrays
checkIndices(problemStruct)

%% Now deal with the controls class
controls.procedure = inputControls.procedure;
controls.parallel = inputControls.parallel;
controls.resampleMinAngle = inputControls.resampleMinAngle;
controls.resampleNPoints = inputControls.resampleNPoints;
controls.calcSldDuringFit = inputControls.calcSldDuringFit;
controls.display = inputControls.display;
controls.xTolerance = inputControls.xTolerance;
controls.funcTolerance = inputControls.funcTolerance;
controls.maxFuncEvals = inputControls.maxFuncEvals;
controls.maxIterations = inputControls.maxIterations;
controls.updateFreq = inputControls.updateFreq;
controls.updatePlotFreq = inputControls.updatePlotFreq;
controls.populationSize = inputControls.populationSize;
controls.fWeight = inputControls.fWeight;
controls.crossoverProbability = inputControls.crossoverProbability;
controls.strategy = inputControls.strategy;
controls.targetValue = inputControls.targetValue;
controls.numGenerations = inputControls.numGenerations;
controls.nLive = inputControls.nLive;
controls.nMCMC = inputControls.nMCMC;
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
if isa(project, 'domainsClass')
    checks.fitDomainRatio = inputStruct.fitDomainRatio;
else
    checks.fitDomainRatio = ones(1,0);
end

controls.checks = checks;
controls.IPCFilePath = inputControls.getIPCFilePath();

%% Finally, populate the fitParams, otherParams, fitLimits, otherLimits arrays
[problemStruct,~] = packParams(problemStruct,problemCells,problemLimits,controls.checks);

end