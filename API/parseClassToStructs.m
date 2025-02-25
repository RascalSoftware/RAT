function [problemStruct,problemLimits,controls] = parseClassToStructs(project,inputControls)

% Breaks up the classes into the relevant structures for inputting into C
 
% First convert the class to a structure variable.
inputStruct = project.toStruct();

% Make the contrast data array up to six columns,
% adding columns of zeros if necessary
inputData = cell(1, length(inputStruct.contrastData));
for i = 1:length(inputStruct.contrastData)
    contrastData = inputStruct.contrastData{i};
    inputData{i} = [contrastData zeros(size(contrastData,1), 6-size(contrastData,2))];
end

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
            contrastData = inputData(i);
            backgroundData = inputStruct.allData{backgroundDataIndex};
            contrastData = insertDataBackgroundIntoContrastData(contrastData,backgroundData);
            inputData(i) = contrastData;

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

resolutionParamNames = inputStruct.resolutionParamNames;
contrastResolutionTypes = cell(1, length(contrastResolutions));
contrastResolutionParams = cell(1, length(contrastResolutions));

for i = 1:length(contrastResolutions)
    % Check the type of the resolution that each contrast is pointing to.
    % If it is a constant, point to the number of the corresponding
    % resolution param. If it's data, then set it to -1
    thisResol = contrastResolutions(i);                                  % Which resolution
    contrastResolutionTypes{i} = inputStruct.resolutionTypes{thisResol}; % What type is it?
    
    if strcmpi(contrastResolutionTypes{i},'data')
        % Resolution is in the datafile.
        % Set contrastResolutionParams as empty
        contrastResolutionParams{i} = [];
    else
        % Resolution is a resolutionParam, the name of which should
        % be in the first column of resolutionValues
        whichResolutionParamName = inputStruct.resolutionValues{thisResol,1};
        
        % Find which resolutionParam this is, and set contrastResolutionParams to this number
        contrastResolutionParams{i} = find(strcmpi(whichResolutionParamName,resolutionParamNames));
    end
end
        

%% Now make the limits array
for i = 1:length(inputStruct.paramLimits)
    problemLimits.params(i,:) = inputStruct.paramLimits{i};
end

for i = 1:length(inputStruct.backgroundParamLimits)
    problemLimits.backgroundParams(i,:) = inputStruct.backgroundParamLimits{i};
end

for i = 1:length(inputStruct.scalefactorLimits)
    problemLimits.scalefactors(i,:) = inputStruct.scalefactorLimits{i};
end

for i = 1:length(inputStruct.qzshiftLimits)
    problemLimits.qzshifts(i,:) = inputStruct.qzshiftLimits{i};
end

for i = 1:length(inputStruct.bulkInLimits)
    problemLimits.bulkIns(i,:) = inputStruct.bulkInLimits{i};
end

for i = 1:length(inputStruct.bulkOutLimits)
    problemLimits.bulkOuts(i,:) = inputStruct.bulkOutLimits{i};
end

for i = 1:length(inputStruct.resolutionParamLimits)
    problemLimits.resolutionParams(i,:) = inputStruct.resolutionParamLimits{i};
end

if isa(project, 'domainsClass')
    for i = 1:length(inputStruct.domainRatioLimits)
        problemLimits.domainRatios(i,:) = inputStruct.domainRatioLimits{i};
    end
else
    problemLimits.domainRatios = ones(0,2);
end


%% Make the problemStruct structure from the remaining inputs

problemStruct.TF = inputStruct.TF;
problemStruct.resample = inputStruct.resample;
problemStruct.data = inputData;
problemStruct.dataPresent = inputStruct.dataPresent;
problemStruct.dataLimits = inputStruct.dataLimits;
problemStruct.simulationLimits = inputStruct.simLimits;
problemStruct.oilChiDataPresent = inputStruct.oilChiDataPresent;
problemStruct.numberOfContrasts = inputStruct.numberOfContrasts;
problemStruct.geometry = inputStruct.geometry;
problemStruct.useImaginary = inputStruct.useImaginary;
problemStruct.repeatLayers = inputStruct.contrastRepeatSLDs;
problemStruct.contrastBackgroundParams = contrastBackgroundParams;
problemStruct.contrastBackgroundTypes = contrastBackgroundTypes;
problemStruct.contrastBackgroundActions = inputStruct.contrastBackgroundActions;
problemStruct.contrastQzshifts = inputStruct.contrastQzshifts;
problemStruct.contrastScalefactors = inputStruct.contrastScalefactors;
problemStruct.contrastBulkIns = inputStruct.contrastBulkIns;
problemStruct.contrastBulkOuts = inputStruct.contrastBulkOuts;
problemStruct.contrastResolutionParams = contrastResolutionParams;
problemStruct.contrastResolutionTypes = contrastResolutionTypes;
problemStruct.backgroundParams = inputStruct.backgroundParamValues;
problemStruct.qzshifts = inputStruct.qzshiftValues;
problemStruct.scalefactors = inputStruct.scalefactorValues;
problemStruct.bulkIns = inputStruct.bulkInValues;
problemStruct.bulkOuts = inputStruct.bulkOutValues;
problemStruct.resolutionParams = inputStruct.resolutionParamValues;
problemStruct.params = inputStruct.paramValues;
problemStruct.numberOfLayers = inputStruct.numberOfLayers;
problemStruct.contrastLayers = inputStruct.contrastLayers;
problemStruct.layersDetails = inputStruct.layerDetails;
problemStruct.customFiles = inputStruct.files;
problemStruct.modelType = inputStruct.modelType;
problemStruct.contrastCustomFiles = inputStruct.contrastCustomFile;

% Add the domains parameters, using dummy values if this is not a domains
% calculation
problemStruct.contrastDomainRatios = inputStruct.contrastDomainRatios;

if isa(project, 'domainsClass')
    problemStruct.domainRatios = inputStruct.domainRatioValues;
else
    problemStruct.domainRatios = ones(1,0);
end

if isa(project, 'domainsClass') && isa(project.domainContrasts, 'domainContrastsClass')
    problemStruct.numberOfDomainContrasts = inputStruct.numberOfDomainContrasts;
    problemStruct.domainContrastLayers = inputStruct.domainContrastLayers;
else
    problemStruct.numberOfDomainContrasts = 0;
    problemStruct.domainContrastLayers = cell(1, 0);
end

% Initialise the lists of fitting parameters    
problemStruct.fitParams = [];
problemStruct.fitLimits = [];

%% Put the priors into their fields

priorFields = ["paramPriors", "backgroundParamPriors", ...
               "scalefactorPriors","qzshiftPriors", "bulkInPriors", ...
               "bulkOutPriors", "resolutionParamPriors"];

if isa(project, 'domainsClass')
    priorFields(end+1) = "domainRatioPriors";
end

totalNumber = 0;
for i=1:length(priorFields)
    totalNumber = totalNumber + size(inputStruct.(priorFields{i}), 1);
end

priorsCell = cell(totalNumber,4);
cellCount = 1;

for i=1:length(priorFields)
    currentPrior = priorFields{i};
    for j = 1:size(inputStruct.(currentPrior), 1)
        priorsCell{cellCount,1} = inputStruct.(currentPrior){j}{1};
       
        % Check prior type
        thisType = inputStruct.(currentPrior){j}{2};

        if strcmpi(thisType, priorTypes.Uniform.value)
            priorType = 1;
        elseif strcmpi(thisType, priorTypes.Gaussian.value)
            priorType = 2;
        else
            priorType = 3;
        end
        priorsCell{cellCount,2} = priorType;

        priorsCell{cellCount,3} = inputStruct.(currentPrior){j}{3};
        priorsCell{cellCount,4} = inputStruct.(currentPrior){j}{4};
        cellCount = cellCount + 1;
    end
end

problemStruct.priorNames = priorsCell(:, 1);
problemStruct.priorValues = cell2mat(priorsCell(:, 2:end));

%% Add structs for parameter names and fits

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
problemStruct.names.contrasts = inputStruct.contrastNames;

% Record lists of parameter fits
problemStruct.checks.params = inputStruct.fitParam;
problemStruct.checks.backgroundParams = inputStruct.fitBackgroundParam;
problemStruct.checks.scalefactors = inputStruct.fitScalefactor;
problemStruct.checks.qzshifts = inputStruct.fitQzshift;
problemStruct.checks.bulkIns = inputStruct.fitBulkIn;
problemStruct.checks.bulkOuts = inputStruct.fitBulkOut;
problemStruct.checks.resolutionParams = inputStruct.fitResolutionParam;
if isa(project, 'domainsClass')
    problemStruct.checks.domainRatios = inputStruct.fitDomainRatio;
else
    problemStruct.checks.domainRatios = ones(1,0);
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
controls.IPCFilePath = inputControls.getIPCFilePath();

%% Finally, populate the fitParams and fitLimits arrays
[problemStruct,~] = packParams(problemStruct,problemLimits);

end
