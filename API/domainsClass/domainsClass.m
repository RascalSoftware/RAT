classdef domainsClass < projectClass
    
    properties
        simContrast           % Modified contrast class with no data for domains
        reflContrast          % Class for making whole interface reflectivity
        domainRatio           % Class for specifying the ratio between domains
    end
    
    
    methods
        
        function obj = domainsClass(varargin)
            
            % Make new instances of simContrast and reflContrast
            obj.simContrast = simContrastsClass();
            
            obj.reflContrast = reflContrastsClass();
            
            obj.domainRatio = parametersClass({'Domain Ratio 1',0.4,0.5,0.6,false,'uniform',0,Inf});
            
            % Remove the 'traditional' contrast class from projectClass as
            % it is not needed (replaced by the two contrasts here)
            obj.contrasts = [];
            
            
        end
        
        
        % -------------------------------------------------------------
        %   Wrapper methods for classes in the underlying objects
        
        % ----- simContrast
        
        function obj = addSimContrast(obj, varargin)
            
            allowedNames = obj.getDomainsAllowedNames();
            obj.simContrast.addSimContrast(allowedNames,varargin);
            
        end
        
        function obj = setSimContrast(obj,varargin)
            
            % Allow setting of all parameters in terms of name value pairs.
            % First input must be contrast number or name, subsequent
            % inputs are name / value pairs for the parts involved
            
            firstInput = varargin{1};
            inputVals = varargin(2:end);
            
            contrastNames = obj.simContrast.getAllSimContrastNames();
            numberOfContrasts = obj.simContrast.numberOfContrasts;
            
            % Find if we are referencing and existing contrast
            if isnumeric(firstInput)
                if (firstInput < 1 || firstInput > numberOfContrasts)
                    error('Contrast number %d is out of range',firstInput);
                end
                thisContrast = firstInput;
                
            elseif ischar(firstInput)
                [present,idx] = ismember(firstInput, contrastNames);
                if ~present
                    error('Contrast %s is not recognised',firstInput)
                end
                thisContrast = idx;
                
            end
            
            % Get the list of allowed values depending on what is
            % set for the other contrasts.
            allowedValues = obj.getAllAllowedNames;
            
            % Call the setContrast method
            obj.simContrast.setSimContrast(thisContrast,allowedValues,inputVals);
            
        end
        
        function obj = setSimContrastModel(obj,varargin)
            
            firstInput = varargin{1};
            inputVals = varargin(2:end);
            
            simContrastNames = obj.simContrast.getAllSimContrastNames();
            numberOfContrasts = obj.simContrast.numberOfContrasts;
            
            % Find if we are referencing and existing contrast
            if isnumeric(firstInput)
                if (firstInput < 1 || firstInput > numberOfContrasts)
                    error('Contrast number %d is out of range',firstInput);
                end
                thisSimContrast = firstInput;
                
            elseif ischar(firstInput)
                [present,idx] = ismember(firstInput, simContrastNames);
                if ~present
                    error('Contrast %s is not recognised',firstInput)
                end
                thisSimContrast = idx;
                
            end
            
            % Make a different allowed list depending on whether 
            % it is custom or layers
            modelType = obj.modelType;
            
            if ~strcmpi(modelType, {'custom layers','custom xy'})
                % Standard Layers
                allowedValues = obj.layers.getLayersNames();
                inputVals = inputVals{:};
            else
                % Custom models
                allowedValues = obj.customFile.getCustomNames();
            end
            
            % Call the setContrastModel method
            obj.simContrast.setSimContrastModel(thisSimContrast, modelType, allowedValues, inputVals);

        end
        
        
        % ---------- Refl contrasts
        
        function obj = addReflContrast(obj, varargin)
            
            allowedNames = obj.getDomainsAllowedNames();
            obj.reflContrast.addReflContrast(allowedNames,varargin);
            
        end
        
        function obj = setReflContrastModel(obj,varargin)
            
            firstInput = varargin{1};
            inputVals = varargin(2:end);
            
            reflContrastNames = obj.reflContrast.getAllContrastNames();
            numberOfContrasts = obj.reflContrast.numberOfContrasts;
            
            % Find if we are referencing and existing contrast
            if isnumeric(firstInput)
                if (firstInput < 1 || firstInput > numberOfContrasts)
                    error('Contrast number %d is out of range',firstInput);
                end
                thisReflContrast = firstInput;
                
            elseif ischar(firstInput)
                [present,idx] = ismember(firstInput, reflContrastNames);
                if ~present
                    error('Contrast %s is not recognised',firstInput)
                end
                thisReflContrast = idx;
                
            end
            
            % Make a different allowed list depending on whether 
            % it is custom or layers
            modelType = lower(obj.modelType);
            
            if ~strcmpi(modelType, {'custom layers','custom xy'})
                % Standard Layers
                allowedValues = obj.layers.getLayersNames();
                inputVals = inputVals{:};
            else
                % Custom models
                allowedValues = obj.customFile.getCustomNames();
            end
            
            % Call the setContrastModel method
            obj.reflContrast.setReflContrastModel(thisReflContrast, modelType, allowedValues, inputVals);
  
        end
        
        
        function obj = setReflContrast(obj,varargin)
            
            % Allow setting of all parameters in terms of name value pairs.
            % First input must be contrast number or name, subsequent
            % inputs are name / value pairs for the parts involved
            
            firstInput = varargin{1};
            inputVals = varargin(2:end);
            
            contrastNames = obj.reflContrast.getAllContrastNames();
            numberOfContrasts = obj.reflContrast.numberOfContrasts;
            
            % Find if we are referencing and existing contrast
            if isnumeric(firstInput)
                if (firstInput < 1 || firstInput > numberOfContrasts)
                    error('Contrast number %d is out of range',firstInput);
                end
                thisContrast = firstInput;
                
            elseif ischar(firstInput)
                [present,idx] = ismember(firstInput, contrastNames);
                if ~present
                    error('Contrast %s is not recognised',firstInput)
                end
                thisContrast = idx;
                
            end
            
            % Get the list of allowed values depending on what is
            % set for the other contrasts.
            allowedValues = obj.getAllAllowedNames;
            domainNames = obj.domainRatio.getParamNames;
            allowedValues.domainRatioNames = domainNames;
            
            % Call the setContrast method
            obj.reflContrast.setReflContrast(thisContrast,allowedValues,inputVals);
            
        end
        
        
        function outStruct = toStruct(obj)
            
            % Converts the class parameters
            % into a struct array for input into
            % the RAT toolbox
            
            % Set which typr of experiment this is
            generalStruct.TF = 'domainsTF';
            
            % Add the 'general' fields
            generalStruct.modelType = lower(obj.modelType);        
            generalStruct.geometry = obj.geometry;
            
            % Parameters
            params = obj.parameters.toStruct();
            paramStruct = cell2struct(struct2cell(params),{'paramNames',...
                'nParams','paramConstr','params','paramFitYesNo','paramPriors'});
            
            % Backgrounds
            backgroundStruct = obj.background.toStruct();
            
            % Resolutions
            resolutionStruct = obj.resolution.toStruct();
            
            % Bulk in
            bulkInStruct = obj.bulkIn.toStruct();
            bulkInStruct = cell2struct(struct2cell(bulkInStruct),{'nbairNames',...
                'nNba','nbairConstr','nbairs','nbaFitYesNo','nbaPriors'});
            
            % Bulk out
            bulkOutStruct = obj.bulkOut.toStruct();
            bulkOutStruct = cell2struct(struct2cell(bulkOutStruct),{'nbsubNames',...
                'nNbs','nbsubConstr','nbsubs','nbsFitYesNo','nbsPriors'});
            
            % Scalefactors
            scalefactorStruct = obj.scalefactors.toStruct();
            scalefactorStruct = cell2struct(struct2cell(scalefactorStruct),{'scalefactorNames',...
                'nScalefcators','scalefactorConstr','scalefactors','scalefactorFitYesNo','scalefactorPriors'});
            
            % Qzshifts
            qzshiftStruct = obj.qzshifts.toStruct();
            qzshiftStruct = cell2struct(struct2cell(qzshiftStruct),{'qzshiftNames',...
                'nQzshifts','qzshiftConstr','qzshifts','qzshiftFitYesNo','qzshiftPriors'});
            
            % Layers
            layersCell = obj.layers.toStruct();
            layersStruct.numberOfLayers = size(layersCell,1);
            layersStruct.layersnames = layersCell(:,1);
            
            % parse the layers details
            layersValues = layersCell(:,2:end);
            paramNames = string(paramStruct.paramNames);
            
            switch generalStruct.modelType
                case 'standard layers'
                    numberOfLayers = layersStruct.numberOfLayers;
                    
                    if numberOfLayers > 0
                        % Standard layers with layers present
                        for i = 1:layersStruct.numberOfLayers
                            thisLayer = layersValues(i,:);
                            min = find(strcmpi(thisLayer{1},paramNames));
                            val = find(strcmpi(thisLayer{2},paramNames));
                            max = find(strcmpi(thisLayer{3},paramNames));
                            if ismissing(thisLayer(4))
                                hydr = NaN;
                            else
                                hydr = find(strcmpi(thisLayer{4},paramNames));
                            end
                            if strcmpi(thisLayer{5},'bulk in')
                                hydrWhat = 1;
                            else
                                hydrWhat = 2;
                            end
                            layersDetails{i} = [min val max hydr hydrWhat];
                        end
                        layersStruct.layersDetails = layersDetails(:);
                    else
                        % No layers present - still need to set
                        % layersDetails
                        layersStruct.layersDetails = {};
                    end
                otherwise
                    % Not standard layers experiment type
                    layersStruct.layersDetails = {};
            end
            
            % Custom files
            customFileStruct = obj.customFile.toStruct();
            
            % Contrasts.
            allNames = obj.getAllAllowedNames;
            dataTable = obj.data.dataTable;
            
            modelType = generalStruct.modelType;
            reflContrastStruct = obj.reflContrast.toStruct(allNames,modelType,dataTable);
            %simContrastStruct = obj.simContrast.toStruct(allNames,modelType,dataTable);
            
            % Merge all the outputs into one large structure
            outStruct = mergeStructs(generalStruct,...
                paramStruct,...
                backgroundStruct,...
                resolutionStruct,...
                bulkInStruct,...
                bulkOutStruct,...
                scalefactorStruct,...
                qzshiftStruct,...
                layersStruct,...
                customFileStruct,...
                simContrastStruct,...
                reflContrastStruct);
            
        end
        
    end
    
    methods (Hidden)
        
        % Overloaded methods from projectClass. Not needed for this project
        % type, so we hide them here so they do not appear in the methods list, 
        % but overload them to throw an error if they are called.
        
        function obj = getContrastClass(obj)

        end        
        
        function names = getDomainsAllowedNames(obj)
            
            % Get the names from the underlying project class...
            names = obj.getAllAllowedNames();
            
            % Get the names from the domains ratios
            domainRatioNames = obj.domainRatio.getParamNames();
            
            % Add these to the names list
            names.domainRatioNames = domainRatioNames;
            
        end
        
        function obj = setContrast(obj)
            error('''setContrast'' not a valid method for domainsClass');
        end
        
        function obj = setContrastModel(obj)
            error('''setContrastModel'' not a valid method for domainsClass');
        end
        
        function obj = addContrast(obj)
            error('''addContrastModel'' not a valid method for domainsClass');
        end

    end
    
    
    methods (Access = protected)
        
        function paramNum = findPar(obj, paramName)
            existingNames = obj.parameters.paramsTable{:,1};
            index = strcmp(paramName, existingNames);
            if isempty(index)
                paramNum = -1;
            else
                paramNum = find(index);
            end
        end
        
        % Display methods
        function group = getPropertyGroup1(obj)
            % Initial Parameters at the start of the class
            masterPropList = struct('modelType',{obj.modelType},...
                'experimentName',{obj.experimentName},...
                'geometry', obj.geometry);
            
            if isscalar(obj)
                group = matlab.mixin.util.PropertyGroup(masterPropList);
            else
                group = getPropertyGroup1@matlab.mixin.CustomDisplay(obj);
            end
        end
        
        function displayScalarObject(obj)
            % Display the whole class. Call the display methods for
            % the sub-classes where appropriate
            
            % There are two versions, depending on whether the model
            % is standard layers or custom, the difference being
            % the display of the layers table..
            
            % Display initial properties
            startProps = getPropertyGroup1(obj);
            matlab.mixin.CustomDisplay.displayPropertyGroups(obj,startProps);
            
            % Display the parameters table
            fprintf('    Parameters: ---------------------------------------------------------------------------------------------- \n\n');
            obj.parameters.displayParametersTable;
            
            % Display the layers table if not a custom model
            val = obj.modelType;
            if ~any(strcmpi(val,{'custom layers','custom xy'}))
                fprintf('    Layers: -------------------------------------------------------------------------------------------------- \n\n');
                obj.layers.displayLayersTable;
            end
            
            % Display the Bulk In table
            fprintf('    Bulk In: -------------------------------------------------------------------------------------------------- \n\n');
            obj.bulkIn.displayParametersTable;
            
            % Display the Bulk Out table
            fprintf('    Bulk Out: ------------------------------------------------------------------------------------------------- \n\n');
            obj.bulkOut.displayParametersTable;
            
            % Display the Scalefactors table
            fprintf('    Scalefactors: ------------------------------------------------------------------------------------------------- \n\n');
            obj.scalefactors.displayParametersTable;
            
            % Display the backgrounds object
            obj.background.displayBackgroundsObject;
            
            % Display the resolutions object
            obj.resolution.displayResolutionsObject;
            
            % Display the data object
            obj.data.displayDataObject;
            
            % Display custome files object
            obj.customFile.displayCustomFileObject;
            
            % Display the simContrasts object id standard layers
            if ~any(strcmpi(val,{'custom layers','custom xy'}))
                obj.simContrast.displaySimContrastsObject;
            end
            
            % Display the domains ratio contrast
            fprintf('   Domains ratios: ----------------------------------------------------------------------------------------------- \n\n');
            obj.domainRatio.displayParametersTable;
            
            % Display the reflContrasts object
            obj.reflContrast.displayReflContrastsObject;
            
        end
        
    end
    
end