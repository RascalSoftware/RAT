classdef domainContrastsClass < baseContrasts

    % A simplified version of the contrast class that allows specification
    % of the model only (i.e. with no data). This is used for domains
    % calculations.
                
    methods

        function names = getDisplayNames(~)
            names = ["Name"; "Model"];
        end

        function contrastStruct = toStruct(obj, allowedNames, ~, ~)
            % Convert the contrasts class to a struct.
            % This routine builds on that in the base class by dealing with
            % the additional properties defined in this subclass.
            % The expected input is the allowed names for each parameter.
            %
            % domainContrasts.toStruct(allowedNames, ~, ~)

            % Call superclass version for common properties
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
            % contrastsClass.parseContrastInput(~, allowedNames, 'name', 'Contrast Name')        
            defaultName = '';
            defaultModel = '';

            expectedModel = cellstr(allowedNames.domainModelNames);

            p = inputParser;
            p.PartialMatching = false;

            addParameter(p,'name',          defaultName,  @isText);
            addParameter(p,'model',         defaultModel, @(x) obj.validateDomainContrastModel(x,expectedModel));

            parse(p, inputValues{:});
            inputBlock = p.Results;
        end
    end

    methods(Access = private)

        function validateDomainContrastModel(~, model, allowedModelNames)
            modelArray = cellstr(model);
    
            for i = 1:length(modelArray)
                if ~strcmpi(modelArray{i}, allowedModelNames)
                    throw(exceptions.nameNotRecognised(sprintf('Model component name "%s" is not recognised. The allowed names are: "%s".', modelArray{i}, strjoin(allowedModelNames, '", "'))));
                end
            end
        end

    end

    methods(Static)

        function contrast = setDefaultValues(contrast)
            % Set non-empty default values when adding a contrast.
            if ~isempty(contrast.model)
                contrast.model = cellstr(contrast.model);
            end
        end

    end

end
