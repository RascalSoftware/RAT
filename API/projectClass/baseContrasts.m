classdef (Abstract) baseContrasts < handle

    % This class holds the parameters for each contrast used in the
    % simulation
    
    properties
        contrasts = {}
    end

    properties (Access = protected)
        contrastAutoNameCounter
    end

    properties (SetAccess = immutable)
        domainsCalc
    end

    properties (Dependent, SetAccess = private)
        numberOfContrasts
    end

    properties(Access = protected, Constant, Hidden)
        invalidTypeMessage = sprintf('Model type must be a modelTypes enum or one of the following strings (%s)', ...
                                     strjoin(modelTypes.values(), ', '))
    end

    methods (Abstract)
        parseContrastInput
    end
            
    methods
        
        function obj = baseContrasts(domainsCalc)
            % Class Constructor
            % The only (optional) input is a logical flag to state whether
            % or not this is a domains calculation.
            %
            % contrasts = contrastsClass()
            arguments
                domainsCalc {mustBeA(domainsCalc,'logical')} = false
            end

            obj.domainsCalc = domainsCalc;
            obj.contrastAutoNameCounter = 1;
        end

        function count = get.numberOfContrasts(obj)
            count = length(obj.contrasts);
        end

        function obj = addContrast(obj, allowedNames, varargin)
            % Add a contrast to the class
            % A class can be added with no input parameters, just a class
            % name, or a set of key-value pairs.
            %
            % contrasts.addContrast()
            % contrasts.addContrast('New Contrast')
            % contrasts.addContrast('name', 'new contrast', ... 
            %                       'background', 'Background H2O')
            if isempty(varargin)
                % No input at all
                contrastName = sprintf('New contrast %d', obj.contrastAutoNameCounter);
                inputVals = {'name', contrastName};
                
            elseif length(varargin) == 1
                % Just name of contrast
                thisName = varargin{1};
                inputVals = {'name', thisName};
                
            else
                % Everything else
                inputVals = varargin;
            end
            
            thisContrast = obj.parseContrastInput(allowedNames, obj.domainsCalc, inputVals);
            thisContrast.model = '';
            obj.contrasts{end+1} = thisContrast;
            obj.contrastAutoNameCounter = obj.contrastAutoNameCounter + 1;
        
        end

        function obj = removeContrast(obj, row)
            % Removes a contrast from the list.
            % The contrast can be specified either by name or by index, but
            % only one contrast can be removed at a time.
            %
            % contrasts.removeContrast('Named Contrast')
            % contrasts.removeContrast(1)

            % First determine if contrast is being referenced by name or
            % number...

            % If the input is a string, find the index of the relevant
            % contrast...
            if isText(row)
                contrastNames = getAllContrastNames(obj);
                row = find(strcmp(contrastNames,row));
                
                % Throw an error if the name is not matched
                if isempty(row)
                    throw(nameNotRecognised('Contrast name not found'));
                end
            end
           
            % Check to make sure the number is in range
            if row < 1 || row > obj.numberOfContrasts
                throw(indexOutOfRange(sprintf('Specified contrast %d is not in range 1 - %d', row, obj.numberOfContrasts)));
            end

            % Remove the contrast from the contrasts cell array
            obj.contrasts(row) = [];

        end

        function obj = setContrastModel(obj, row, modelType, allowedNames, model)
            % Set the value of the model parameter in a contrast.
            % The expected input is the contrast (specified either by name
            % or index), the model type, the allowed values (either layers
            % for standard layers or custom files for custom models) and
            % either a string or cell array for the model itself.
            % Note that the model can only be set here, and not in
            % "addContrast" or "setContrast".
            %
            % contrasts.setContrastModel(1, 'standard layers', allowedNames, 'Oxide Model')
            
            % Find if we are referencing an existing contrast
            if isnumeric(row)
                if (row < 1 || row > obj.numberOfContrasts)
                    throw(indexOutOfRange(sprintf('Contrast number %d is out of range 1 - %d', row, obj.numberOfContrasts)));
                end
                contrastIndex = row; 
            elseif isText(row)
                [present,idx] = ismember(row, obj.getAllContrastNames());
                if ~present
                    throw(nameNotRecognised(sprintf('Contrast %s is not recognised', row)));
                end
                contrastIndex = idx;
            end

            % Determine which contrast is being set
            thisContrast = obj.contrasts{contrastIndex};
            modelArray = cellstr(model);

            % Check the input is as expected
            modelType = validateOption(modelType, 'modelTypes', obj.invalidTypeMessage).value;
            if any(strcmpi(modelType, {modelTypes.CustomLayers.value, modelTypes.CustomXY.value}))
                if length(modelArray) > 1
                    throw(invalidValue('Only 1 model value allowed for ''custom'''));
                end
            end

            for i = 1:length(modelArray)
                if ~strcmpi(modelArray{i}, allowedNames)
                    throw(nameNotRecognised(sprintf('Layer/Custom Name %s is not recognised', modelArray{i})));
                end
            end

            thisContrast.model = modelArray;
            obj.contrasts{contrastIndex} = thisContrast;

        end
                
        function contrastNames = getAllContrastNames(obj)
            % Get the names of all contrasts defined in the class.
            %
            % contrasts.getAllContrastNames()
            nContrasts = obj.numberOfContrasts;
            contrastNames = cell(1,nContrasts);
                        
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};
                contrastNames{i} = thisContrast.name;
            end
        end

    end
end


