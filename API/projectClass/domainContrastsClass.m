classdef domainContrastsClass < baseContrasts

    % A simplified version of the contrast class that allows specification
    % of the model only (i.e. with no data). This is used for domains
    % calculations.
                
    methods

        function names = getDisplayNames(~)
            names = ["Name"; "Model"];
        end

        function contrastStruct = toStruct(obj, allowedNames, ~, ~)
            % Converts the domains contrasts class to a struct.
            % 
            % Parameters
            % ----------
            % allowedNames: struct
            %     A struct containing the valid names that can be referenced in the contrast.
            % 
            % Returns
            % -------
            % contrastStruct : struct
            %     A struct which contains the properties for all the contrast entries.
            contrastStruct = toStruct@baseContrasts(obj);

            nContrasts = obj.numberOfContrasts;
            contrastLayers = cell(1,nContrasts);

            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};
                thisModel = thisContrast.model;
                thisLayerArray = ones(1, length(thisModel));
                for n = 1:length(thisModel)
                    thisLayer = thisModel{n};
                    thisLayerNum = find(strcmpi(thisLayer, allowedNames.layerNames));
                    thisLayerArray(n) = thisLayerNum;
                end
                contrastLayers{i} = thisLayerArray;
            end
            contrastStruct.contrastLayers = contrastLayers;
        end

        function inputBlock = parseContrastInput(obj, allowedNames, inputValues)
            % Parse the parameters given for the contrast, assigning
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
            %     A struct containing properties of the contrast with empty fields set to default.      
            defaultName = '';
            defaultModel = '';

            expectedModel = cellstr(allowedNames.domainModelNames);

            p = inputParser;
            p.PartialMatching = false;

            addParameter(p,'name',  defaultName,  @isText);
            addParameter(p,'model', defaultModel)          

            parse(p, inputValues{:});
            inputBlock = p.Results;

            inputBlock.model = obj.validateDomainContrastModel(inputBlock.model, expectedModel);

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
            %     A struct containing properties of the contrast with empty fields set to a default.
            if ~isempty(contrast.model)
                contrast.model = cellstr(contrast.model);
            end
        end
    end

    methods(Access = private)

        function model = validateDomainContrastModel(~, input, allowedModelNames)
            % Validates domain contrast model.
            % 
            % Parameters
            % ----------
            % input: string or char array or cell string
            %     The name(s) in the domain contrast model.
            % allowedNames: struct
            %     A struct containing the valid names that can be referenced in the domain contrast.
            % 
            % Returns
            % -------
            % model: cell string
            %     The validated name(s) in the domain contrast model.
            if isempty(input)
                model = '';
                return
            end
            
            inputArray = cellstr(input);
            modelSize = length(inputArray);
            model = cell(1, modelSize);
            for i = 1:modelSize 
                found = strcmpi(inputArray{i}, allowedModelNames);
                if ~any(found)
                    throw(exceptions.nameNotRecognised(sprintf('Model component name "%s" is not recognised. The allowed names are: "%s".', inputArray{i}, strjoin(allowedModelNames, '", "'))));
                end
                model{i} = allowedModelNames{find(found, 1)};
            end
        end

    end

end
