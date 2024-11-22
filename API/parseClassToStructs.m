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

% Convert contrastBackgrounds to custom file/parameter indices
numContrastBackgrounds = length(inputStruct.contrastBackgrounds);

contrastBackgroundParams = cell(1, numContrastBackgrounds);
contrastBackgroundTypes = cell(1, numContrastBackgrounds);

for i = 1:numContrastBackgrounds
    % Check the type of the background that each contrast is pointing to.
    thisBack = inputStruct.contrastBackgrounds(i);                       % Which background
    contrastBackgroundTypes{i} = inputStruct.backgroundTypes{thisBack};  % What type is it?

    switch contrastBackgroundTypes{i}

        case allowedTypes.Constant.value
            % Background is a backgroundParam, the name of which should
            % be in the first column of backgroundValues
    
            % Find which backgroundParam this is, and set contrastBackgroundParams to this number
            contrastBackgroundParams{i} = find(strcmpi(inputStruct.backgroundValues{thisBack,1}, inputStruct.backgroundParamNames));

        case allowedTypes.Data.value
            % Background is in a datafile.
            %
            % We need to find the index of the relevant datafile, and
            % append the relevant data as columns 5 and 6 of the contrast
            % data. Finally, deal with the optional background offset if
            % present, and set this as the (optional) contrastBackgroundParams
            % entry.
    
            % Find corresponding background value
            backgroundDatafileName = inputStruct.backgroundValues{thisBack,1};
            backgroundDataOffset = inputStruct.backgroundValues{thisBack,2};
    
            % Find the index of this data name in the string array
            backgroundDataIndex = find(strcmp(backgroundDatafileName,inputStruct.dataNames));
    
            if isempty(backgroundDataIndex)
                throw(exceptions.invalidValue(sprintf('Data background %s is not defined in the data table of the project', backgroundDatafileName)));
            end

            % We append the background data as columns 5 and 6 of the
            % data array of this contrast.
            contrastData = problemCells{2}(i);
            backgroundData = inputStruct.allData{backgroundDataIndex};
            contrastData = insertDataBackgroundIntoContrastData(contrastData,backgroundData);
            problemCells{2}(i) = contrastData;

            % Add the index of the optional data offset to contrastBackgroundParams
            offsetIndex = find(strcmpi(backgroundDataOffset,inputStruct.backgroundParamNames));
            if ~isempty(offsetIndex)
                contrastBackgroundParams{i} = offsetIndex;
            end

        case allowedTypes.Function.value
            % Background is a background function
            %
            % We need the index of the custom file the function is defined
            % in, alongside all of the function parameters.
    
            % Get the corresponding function name
            backgroundFuncfileName = inputStruct.backgroundValues{thisBack,1};
    
            % Find the index of this function name in the custom file array
            backgroundFunctionIndex = find(strcmp(backgroundFuncfileName,inputStruct.fileIdentifiers));

            if isempty(backgroundFunctionIndex)
                throw(exceptions.invalidValue(sprintf('Function background %s is not defined in the custom files table of the project', backgroundFuncfileName)));
            end

            contrastBackgroundParams{i}(1) = backgroundFunctionIndex;
    
            % Now find the indices of any defined background parameters
            functionParams = inputStruct.backgroundValues(thisBack,2:end);
            numDefined = length(find(~(cellfun(@(x) isequal(x,""),functionParams))));
            for n = 1:numDefined
                backgroundParamIndex = find(strcmpi(functionParams{n},inputStruct.backgroundParamNames));
                contrastBackgroundParams{i}(n+1) = backgroundParamIndex;
            end

        otherwise
            throw(exceptions.inValidOption(sprintf('The background type "%s" is not supported. Backgrounds should be either "constant", "data", or "function"', backgroundType)));
            
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
problemStruct.contrastBackgroundActions = inputStruct.contrastBackgroundActions;
problemStruct.contrastQzshifts = inputStruct.contrastQzshifts;
problemStruct.contrastScalefactors = inputStruct.contrastScalefactors;
problemStruct.contrastBulkIns = inputStruct.contrastBulkIns;
problemStruct.contrastBulkOuts = inputStruct.contrastBulkOuts;
problemStruct.contrastResolutionParams = contrastResolutionParams;
problemStruct.backgroundParams = inputStruct.backgroundParamValues;
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

% Record lists of parameter names
problemStruct.names.params = inputStruct.paramNames;
problemStruct.names.backgroundParams = inputStruct.backgroundParamNames;
problemStruct.names.scalefactors = inputStruct.scalefactorNames;
problemStruct.names.qzshifts = inputStruct.qzshiftNames;
problemStruct.names.bulkIns = inputStruct.bulkInNames;
problemStruct.names.bulkOuts = inputStruct.bulkOutNames;
problemStruct.names.resolutionParams = inputStruct.resolutionParamNames;
if isa(project, 'domainsClass')
    problemStruct.names.domainRatios = inputStruct.domainRatioNames;
else
    problemStruct.names.domainRatios = cell(1, 0);
end

% Make sure the indices cannot lie outside of the arrays
checkIndices(problemStruct, inputStruct.files);

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
[problemStruct,~] = packParams(problemStruct,problemLimits,controls.checks);

end