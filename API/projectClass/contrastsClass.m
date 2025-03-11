classdef contrastsClass < baseContrasts

    % This class holds the parameters for each contrast used in the
    % simulation


    methods   
        function obj = contrastsClass(calcType)
            % Class Constructor
            % The (optional) inputs is a logical flag to state whether
            % or not this is a domains calculation.
            %
            % contrasts = contrastsClass()
            arguments
                calcType.domains {mustBeA(calcType.domains,'logical')} = false
            end

            obj@baseContrasts(calcType.domains)
        end

        function names = getDisplayNames(obj)
            names = ["Name"; "Data"; "Background"; "Background Action"; "Bulk in"; "Bulk out"; "Scalefactor"; "Resolution"; "Resample"; "Model"];
            if obj.domainsCalc
                names = [names(1:end-1); "Domain Ratio"; names(end)];
            end
        end

        function obj = updateDataName(obj, nameChange)
            % Update the "data" parameter in a contrast if the name is
            % changed in the data class.           
            % This function is only really called from projectClass if a
            % data name has been updated. It looks through the 'data'
            % field of the contrasts and if it matches nameChange.oldName
            % then this is updated to nameChange.newName
            %
            % contrasts.updateDataName(nameChange)            
            oldName = nameChange.oldName;
            newName = nameChange.newName;
            
            for i = 1:obj.numberOfContrasts
                thisContrast = obj.contrasts{i};
                if strcmpi(oldName,thisContrast.data)
                    obj.contrasts{i}.data = newName;
                end
            end
            
        end
        
        function contrastStruct = toStruct(obj, allowedNames, modelType, dataTable)
            % Convert the contrasts class to a struct.
            % This routine builds on that in the base class by dealing with
            % the additional properties defined in this subclass.
            % The expected input is the allowed names for each parameter,
            % the model type and the data table from the data class.
            %
            % contrasts.toStruct(allowedNames, 'standard layers', dataTable)

            % Call superclass version for common properties
            contrastStruct = toStruct@baseContrasts(obj);

            % Now deal with additional properties in this class
            nContrasts = obj.numberOfContrasts;
            contrastLayers = cell(1,nContrasts);
            contrastCustomFile = ones(1,nContrasts);
            contrastBackgrounds = ones(1,nContrasts);
            contrastBackgroundActions = cell(1,nContrasts);
            contrastBulkIns = ones(1,nContrasts);
            contrastBulkOuts = ones(1,nContrasts);
            contrastDomainRatios = zeros(1,nContrasts);
            contrastScalefactors = ones(1,nContrasts);
            contrastResolutions = ones(1,nContrasts);
            resample = ones(1,nContrasts);

            dataPresent = zeros(1,nContrasts);
            dataLimits = cell(1,nContrasts);
            simulationLimits = cell(1,nContrasts);
            contrastData = cell(1,nContrasts);

            for i = 1:nContrasts

                thisContrast = obj.contrasts{i};

                modelType = validateOption(modelType, 'modelTypes', obj.invalidTypeMessage).value;
                switch modelType
                    case modelTypes.StandardLayers.value
                        thisModel = thisContrast.model;
                        thisArray = ones(1, length(thisModel));
                        if obj.domainsCalc
                            for n = 1:length(thisModel)
                                thisLayerNum = find(strcmpi(thisModel{n}, allowedNames.domainContrastNames));
                                thisArray(n) = thisLayerNum;
                            end
                        else
                            for n = 1:length(thisModel)
                                thisLayerNum = find(strcmpi(thisModel{n}, allowedNames.layerNames));
                                thisArray(n) = thisLayerNum;
                            end
                        end
                        contrastLayers{i} = thisArray;
                        contrastCustomFile(i) = NaN;
                    otherwise
                        contrastLayers{i} = [];
                        whichFile = thisContrast.model;
                        thisContrastFileNum = find(strcmpi(whichFile, allowedNames.customFileNames));
                        contrastCustomFile(i) = thisContrastFileNum;
                end

                if isfield(thisContrast, 'domainRatio')
                    contrastDomainRatios(i) = find(strcmpi(thisContrast.domainRatio,allowedNames.domainRatioNames));
                else
                    contrastDomainRatios(i) = -1;
                end

                contrastBackgrounds(i) = find(strcmpi(thisContrast.background,allowedNames.backgroundNames));
                contrastBackgroundActions{i} = thisContrast.backgroundAction;
                contrastBulkIns(i) = find(strcmpi(thisContrast.bulkIn,allowedNames.bulkInNames));
                contrastBulkOuts(i) = find(strcmpi(thisContrast.bulkOut,allowedNames.bulkOutNames));
                contrastScalefactors(i) = find(strcmpi(thisContrast.scalefactor,allowedNames.scalefactorNames));
                contrastResolutions(i) = find(strcmpi(thisContrast.resolution,allowedNames.resolutionNames));
                resample(i) = thisContrast.resample;

                thisDataVal = find(strcmpi(thisContrast.data,allowedNames.dataNames));
                if ~isempty(thisDataVal)
                    actualData = dataTable{thisDataVal,2}{:};
                    if ~isempty(actualData)
                        dataPresent(i) = 1;
                    end
                    thisDataLimit = dataTable{thisDataVal,3}{:};
                    if isempty(thisDataLimit)
                        thisDataLimit = [0 0];
                    end
                    dataLimits{i} = thisDataLimit;
                    simulationLimits{i} = dataTable{thisDataVal,4}{:};
                    contrastData{i} = dataTable{thisDataVal,2}{:};
                else
                    dataLimits{i} = [0 0];
                    simulationLimits{i} = [0 0];
                    contrastData{i} = [0 0 0];
                end
            end

            contrastStruct.contrastLayers = contrastLayers;
            contrastStruct.contrastCustomFile = contrastCustomFile;
            contrastStruct.contrastDomainRatios = contrastDomainRatios;
            contrastStruct.contrastBackgrounds = contrastBackgrounds;
            contrastStruct.contrastBackgroundActions = contrastBackgroundActions;
            contrastStruct.contrastBulkIns = contrastBulkIns;
            contrastStruct.contrastBulkOuts = contrastBulkOuts;
            contrastStruct.contrastScalefactors = contrastScalefactors;
            contrastStruct.contrastResolutions = contrastResolutions;
            contrastStruct.contrastData = contrastData;
            contrastStruct.dataPresent = dataPresent;
            contrastStruct.dataLimits = dataLimits;
            contrastStruct.simulationLimits = simulationLimits;
            contrastStruct.resample = resample;

        end

        function inputBlock = parseContrastInput(obj, allowedNames, inputValues)
            % Parse the parameters given for the contrast, assigning
            % default values to those unspecified and ensuring specified
            % values are of the correct type, and included in the list of
            % allowed names where necessary.
            %
            % contrastsClass.parseContrastInput(allowedNames, ...
            %                                   'name', 'Contrast Name', ...
            %                                   'background', 'Background H2O')        
            defaultName = '';
            defaultBackground = '';
            defaultBackgroundAction = '';
            defaultData = '';   
            defaultBulkIn = '';
            defaultBulkOut = '';
            defaultScalefactor = '';
            defaultResolution = '';
            defaultResample = [];
            defaultModel = '';
        
            expectedBackground = cellstr(allowedNames.backgroundNames);
            expectedData = cellstr(allowedNames.dataNames);
            expectedBulkIn = cellstr(allowedNames.bulkInNames);
            expectedBulkOut = cellstr(allowedNames.bulkOutNames);
            expectedScalefactor = cellstr(allowedNames.scalefactorNames);
            expectedResolution = cellstr(allowedNames.resolutionNames);

            p = inputParser;
            p.PartialMatching = false;

            addParameter(p,'name',          defaultName,        @isText);
            addParameter(p,'data',          defaultData,        @isText);
            addParameter(p,'background',       defaultBackground,         @isText);
            addParameter(p,'backgroundAction', defaultBackgroundAction,   @(x) isText(x) || isenum(x))
            addParameter(p,'bulkIn',           defaultBulkIn,             @isText);
            addParameter(p,'bulkOut',          defaultBulkOut,            @isText);
            addParameter(p,'scalefactor',      defaultScalefactor,        @isText);
            addParameter(p,'resolution',       defaultResolution,         @isText);
            addParameter(p,'resample',         defaultResample,           @islogical);

            if obj.domainsCalc
                defaultDomainRatio = '';
                expectedDomainRatio = cellstr(allowedNames.domainRatioNames);
                addParameter(p,'domainRatio',   defaultDomainRatio,       @isText);
            end

            addParameter(p,'model',            defaultModel);
            
            parse(p, inputValues{:});
            inputBlock = p.Results;
            inputBlock.data = obj.validateExactString(inputBlock.data, expectedData);
            inputBlock.background = obj.validateExactString(inputBlock.background, expectedBackground);
            inputBlock.bulkIn = obj.validateExactString(inputBlock.bulkIn, expectedBulkIn);
            inputBlock.bulkOut = obj.validateExactString(inputBlock.bulkOut, expectedBulkOut);
            inputBlock.scalefactor = obj.validateExactString(inputBlock.scalefactor, expectedScalefactor);
            inputBlock.resolution = obj.validateExactString(inputBlock.resolution, expectedResolution);
            inputBlock.model = obj.validateContrastModel(inputBlock.model, allowedNames);
            if obj.domainsCalc
                inputBlock.domainRatio = obj.validateExactString(inputBlock.domainRatio, expectedDomainRatio);
            end
        end

    end

    methods(Access = private)

        function output = validateExactString(~, input, allowedNames)
            if isempty(input)
                output = '';
                return
            end
            found = strcmpi(input, allowedNames);
            if ~any(found)
                throw(exceptions.nameNotRecognised(sprintf('The input "%s" is not recognised. The allowed names are: "%s".', input, strjoin(allowedNames, '", "'))));
            end
            output = allowedNames{find(found, 1)};
        end

        function model = validateContrastModel(obj, input, allowedNames)
            if isempty(input)
                model = '';
                return
            end
            
            inputArray = cellstr(input);

            % Check the input is as expected - modelNames tells us what the
            % model type is
            if all(size(allowedNames.modelNames) == size(allowedNames.customFileNames)) && all(cellfun(@strcmp, allowedNames.modelNames, allowedNames.customFileNames))
                if length(inputArray) > 1
                    throw(exceptions.invalidValue('Only one model value is allowed for custom models'));
                end
            elseif obj.domainsCalc && all(size(allowedNames.modelNames) == size(allowedNames.domainContrastNames)) && all(cellfun(@strcmp, allowedNames.modelNames, allowedNames.domainContrastNames))
                if length(inputArray) ~= 2
                    throw(exceptions.invalidValue('Exactly two model values are required for ''standard layers'' with domains'));
                end
            end

            modelSize = length(inputArray);
            model = cell(1, modelSize);
            modelNames = cellstr(allowedNames.modelNames);
            for i = 1:modelSize 
                found = strcmpi(inputArray{i}, modelNames);
                if ~any(found)
                    throw(exceptions.nameNotRecognised(sprintf('Model component name "%s" is not recognised. The allowed names are: "%s".', inputArray{i}, strjoin(allowedNames.modelNames, '", "'))));
                end
                model{i} = modelNames{find(found, 1)};
            end
        end

    end

    methods(Static)

        function contrast = setDefaultValues(contrast)
            % Set non-empty default values when adding a contrast.
            if ~isempty(contrast.model)
                contrast.model = cellstr(contrast.model);
            end

            if isempty(contrast.backgroundAction)
                contrast.backgroundAction = actions.Add.value;
            else
                contrast.backgroundAction = validateOption(contrast.backgroundAction, 'actions',...
                        sprintf('backgroundAction must be a actions enum or one of the following strings (%s)', strjoin(actions.values(), ', '))).value;
            end

            if isempty(contrast.resample)
                contrast.resample = false;
            end

        end

    end

end
