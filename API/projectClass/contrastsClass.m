classdef contrastsClass < baseContrasts
    % This class holds the parameters for each contrast used in the simulation
    % 
    % Examples
    % --------
    % >>> contrasts = contrastsClass();
    % >>> contrasts = contrastsClass(true);
    % 
    % Parameters
    % ----------
    % isDomains : logical, default: false
    %     Indicates if the contrast object is for a domains project.
    %
    % Attributes
    % ----------
    % contrasts : cell
    %     A cell containing all the contrast entries.

    methods   
        function obj = contrastsClass(isDomains)
            arguments
                isDomains {mustBeA(isDomains,'logical')} = false
            end

            obj@baseContrasts(isDomains)
        end

        function names = getDisplayNames(obj)
            names = ["Name"; "Data"; "Background"; "Background Action"; "Bulk in"; "Bulk out"; "Scalefactor"; "Resolution"; "Resample"; "Repeat Layers"; "Model"];
            if obj.isDomains
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
            % Parameters
            % ----------
            % nameChange: struct
            %     A struct which contains the former name ``oldName`` and the new name ``newName`` of the dataset or 
            %     an empty array if name is not changed        
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
            % Converts the contrasts class to a struct.
            % 
            % Parameters
            % ----------
            % allowedNames: struct
            %     A struct containing the valid names that can be referenced in the contrast.
            % modelType: modelTypes
            %     The layer model type which can be 'standard layers', 'custom layers', or 'custom xy'.
            % dataTable: table
            %     A table from the dataClass.
            % 
            % Returns
            % -------
            % contrastStruct : struct
            %     A struct which contains the properties for all the contrast entries.

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
            contrastRepeatLayers = ones(1,nContrasts);

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
                        if obj.isDomains
                            for n = 1:length(thisModel)
                                thisArray(n) = obj.findParameterIndex(thisModel{n}, allowedNames.domainContrastNames, "domain contrast");
                            end
                        else
                            for n = 1:length(thisModel)
                                thisArray(n) = obj.findParameterIndex(thisModel{n}, allowedNames.layerNames, "layer");
                            end
                        end
                        contrastLayers{i} = thisArray;
                        contrastCustomFile(i) = NaN;
                    otherwise
                        contrastLayers{i} = [];
                        contrastCustomFile(i) = obj.findParameterIndex(thisContrast.model{1}, allowedNames.customFileNames, "custom file");
                end

                if isfield(thisContrast, 'domainRatio')
                    contrastDomainRatios(i) = obj.findParameterIndex(thisContrast.domainRatio, allowedNames.domainRatioNames, "domain ratio");
                else
                    contrastDomainRatios(i) = -1;
                end
                
                contrastBackgrounds(i) = obj.findParameterIndex(thisContrast.background, allowedNames.backgroundNames, "background");
                contrastBackgroundActions{i} = thisContrast.backgroundAction;
                contrastBulkIns(i) = obj.findParameterIndex(thisContrast.bulkIn, allowedNames.bulkInNames, "bulk in");
                contrastBulkOuts(i) = obj.findParameterIndex(thisContrast.bulkOut, allowedNames.bulkOutNames, "bulk out");
                contrastScalefactors(i) = obj.findParameterIndex(thisContrast.scalefactor, allowedNames.scalefactorNames, "scalefactor");
                contrastResolutions(i) = obj.findParameterIndex(thisContrast.resolution, allowedNames.resolutionNames, "resolution");
                resample(i) = thisContrast.resample;
                contrastRepeatLayers(i) = thisContrast.repeatLayers;
                
                if ~isempty(thisContrast.data)
                    thisDataVal = obj.findParameterIndex(thisContrast.data, allowedNames.dataNames, "dataset");
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
                    dataLimits{i} = [0, 0];
                    simulationLimits{i} = dataClass.defaultSimRange;
                    contrastData{i} = [0, 0, 0];
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
            contrastStruct.repeatLayers = contrastRepeatLayers;

        end

        function inputBlock = parseContrastInput(obj, allowedNames, inputValues)
            % Parses the given keyword/value pairs of properties for the contrast, assigning
            % default values to those unspecified and ensuring specified
            % values are of the correct type, and included in the list of
            % allowed names where necessary.
            % 
            % Parameters
            % ----------
            % allowedNames: struct
            %     A struct containing the valid names that can be referenced in the contrast.
            % inputValues: cell
            %     A cell containing keyword/value pairs of properties for the contrast.
            % 
            % Returns
            % -------
            % inputBlock : struct
            %     A struct containing the given properties of the contrast.
            defaultName = '';
            defaultBackground = '';
            defaultBackgroundAction = '';
            defaultData = '';   
            defaultBulkIn = '';
            defaultBulkOut = '';
            defaultScalefactor = '';
            defaultResolution = '';
            defaultResample = [];
            defaultRepeatLayers = [];
            defaultModel = '';
        
            expectedBackground = cellstr(allowedNames.backgroundNames);
            expectedData = cellstr(allowedNames.dataNames);
            expectedBulkIn = cellstr(allowedNames.bulkInNames);
            expectedBulkOut = cellstr(allowedNames.bulkOutNames);
            expectedScalefactor = cellstr(allowedNames.scalefactorNames);
            expectedResolution = cellstr(allowedNames.resolutionNames);

            p = inputParser;
            p.PartialMatching = false;

            addParameter(p,'name',             defaultName,               @isText);
            addParameter(p,'data',             defaultData,               @isText);
            addParameter(p,'background',       defaultBackground,         @isText);
            addParameter(p,'backgroundAction', defaultBackgroundAction,   @(x) isText(x) || isenum(x))
            addParameter(p,'bulkIn',           defaultBulkIn,             @isText);
            addParameter(p,'bulkOut',          defaultBulkOut,            @isText);
            addParameter(p,'scalefactor',      defaultScalefactor,        @isText);
            addParameter(p,'resolution',       defaultResolution,         @isText);
            addParameter(p,'resample',         defaultResample,           @islogical);
            addParameter(p,'repeatLayers',     defaultRepeatLayers,       @isnumeric);

            if obj.isDomains
                defaultDomainRatio = '';
                expectedDomainRatio = cellstr(allowedNames.domainRatioNames);
                addParameter(p,'domainRatio',  defaultDomainRatio,       @isText);
            end

            addParameter(p,'model',            defaultModel);
            
            parse(p, inputValues{:});
            inputBlock = p.Results;
            inputBlock.data = obj.validateExactString(inputBlock.data, expectedData, "dataset");
            inputBlock.background = obj.validateExactString(inputBlock.background, expectedBackground, "background");
            inputBlock.bulkIn = obj.validateExactString(inputBlock.bulkIn, expectedBulkIn, "bulk in");
            inputBlock.bulkOut = obj.validateExactString(inputBlock.bulkOut, expectedBulkOut, "bulk out");
            inputBlock.scalefactor = obj.validateExactString(inputBlock.scalefactor, expectedScalefactor, "scalefactor");
            inputBlock.resolution = obj.validateExactString(inputBlock.resolution, expectedResolution, "resolution");
            inputBlock.repeatLayers = obj.validatePositiveInteger(inputBlock.repeatLayers);

            if ~isfield(allowedNames, 'layerNames')  && any(inputBlock.repeatLayers ~= 1)
                warning("Repeat Layers are only supported for standard layers calculations")
            end
            
            inputBlock.model = obj.validateContrastModel(inputBlock.model, allowedNames);
            if obj.isDomains
                inputBlock.domainRatio = obj.validateExactString(inputBlock.domainRatio, expectedDomainRatio, "domain ratio");
            end
        end
        
        function contrast = setDefaultValues(~, contrast)
            % Sets default values to empty fields when adding a contrast.
            % 
            % Parameters
            % ----------
            % contrast: struct
            %     A struct containing properties of the contrast.
            % 
            % Returns
            % -------
            % contrast : struct
            %     A struct containing properties of the contrast with empty fields set to default.
            if ~isempty(contrast.model)
                contrast.model = cellstr(contrast.model);
            end

            if isempty(contrast.backgroundAction)
                contrast.backgroundAction = backgroundActions.Add.value;
            else
                contrast.backgroundAction = validateOption(contrast.backgroundAction, 'backgroundActions',...
                        sprintf('backgroundAction must be a actions enum or one of the following strings (%s)', strjoin(backgroundActions.values(), ', '))).value;
            end

            if isempty(contrast.resample)
                contrast.resample = false;
            end

            if isempty(contrast.repeatLayers)
                contrast.repeatLayers = 1;
            end

        end
    end

    methods(Access = private)
        function output = findParameterIndex(~, input, allowedNames, inputDesc)
            % Get the index of an input name in list of allowed names.
            % 
            % Parameters
            % ----------
            % input: string or char array
            %     A name to validate.
            % allowedNames: cell
            %     A cell containing the valid names.
            % inputDesc: string or char array
            %     A description of the input.
            % 
            % Returns
            % -------
            % output: whole number
            %     Index of the input name in the allowed list of names.
            if isempty(input)
                throw(exceptions.invalidValue(sprintf("All contrasts must have a valid %s.", inputDesc)));
            end
            found = strcmpi(input, allowedNames);
            if ~any(found)
                if isempty(allowedNames)
                    msg = sprintf('"%s" is not a recognised %s. Did you forget to add the %s?', input, inputDesc, inputDesc);
                else
                    msg = sprintf('"%s" is not a recognised %s. The allowed names are: "%s".', input, inputDesc, strjoin(allowedNames, '", "'));
                end
                throw(exceptions.nameNotRecognised(msg));
            end
            output = find(found, 1);
        end

        function output = validateExactString(~, input, allowedNames, inputDesc)
            % Validates input name is found in list of allowed names.
            % 
            % Parameters
            % ----------
            % input: string or char array
            %     A name to validate.
            % allowedNames: cell
            %     A cell containing the valid names.
            % inputDesc: string or char array
            %     A description of the input.
            % 
            % Returns
            % -------
            % output: string or char array
            %     The validated name.
            if isempty(input)
                output = '';
                return
            end
            found = strcmpi(input, allowedNames);
            if ~any(found)
                if isempty(allowedNames)
                    msg = sprintf('The input "%s" is not a recognised %s. Did you forget to add the %s?', input, inputDesc, inputDesc);
                else
                    msg = sprintf('The input "%s" is not a recognised %s. The allowed names are: "%s".', input, inputDesc, strjoin(allowedNames, '", "'));
                end
                throw(exceptions.nameNotRecognised(msg));
            end
            output = allowedNames{find(found, 1)};
        end

        function output = validatePositiveInteger(~, input)
            if isempty(input)
                output = [];
                return
            end
            if ~(isscalar(input) && mod(input, 1) == 0  && input > 0)
                throw(exceptions.invalidValue(sprintf('The input "%s" must be a whole number greater than zero.', input)));
            end
            output = input;
        end

        function model = validateContrastModel(obj, input, allowedNames)
            % Validates contrast model.
            % 
            % Parameters
            % ----------
            % input: string or char array or cell string
            %     The name(s) in the contrast model.
            % allowedNames: struct
            %     A struct containing the valid names that can be referenced in the contrast.
            % 
            % Returns
            % -------
            % model: cell string
            %     The validated name(s) in the contrast model.
            if isempty(input)
                model = '';
                return
            end
            
            inputArray = cellstr(input);

            % Check the input is as expected - layerNames is only present in standard layers
            if ~isfield(allowedNames, 'layerNames') 
                if isempty(allowedNames.customFileNames) 
                    throw(exceptions.invalidValue('At least one custom file must be added to the contrast model in a standard layers project. Did you forget to add the custom file?'));
                end
                  
                if length(inputArray) > 1
                    throw(exceptions.invalidValue('One custom file is required as the contrast model in a custom layers or xy project'));
                end  
            else
                if isempty(allowedNames.layerNames) && ~isempty(allowedNames.customFileNames) && any(cellfun(@(x) any(strcmp(x, allowedNames.customFileNames)), inputArray))
                    throw(exceptions.invalidValue('Custom files cannot be used in a standard layers model. Did you forget to change the model type?'));
                end

                if isempty(allowedNames.layerNames) 
                    throw(exceptions.invalidValue('At least one layer must be added to the contrast model in a standard layers project. Did you forget to add the layers?'));
                end
               
                if obj.isDomains && length(inputArray) ~= 2
                    throw(exceptions.invalidValue('Exactly two model values are required for ''standard layers'' with domains'));
                end
            end

            modelSize = length(inputArray);
            model = cell(1, modelSize);
            modelNames = cellstr(allowedNames.modelNames);
            for i = 1:modelSize 
                found = strcmpi(inputArray{i}, modelNames);
                if ~any(found)
                    throw(exceptions.nameNotRecognised(sprintf('Model component name "%s" is not recognised. The allowed names are: "%s".', inputArray{i}, strjoin(modelNames, '", "'))));
                end
                model{i} = modelNames{find(found, 1)};
            end
        end

    end

end
