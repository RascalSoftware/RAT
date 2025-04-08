classdef (Abstract) baseContrasts < handle  
    % This class is the base class for ``contrastsClass`` and ``domainContrastsClass``. It holds the common 
    % methods used by both to add, remove and update contrasts. This class is expected to be called via inheritance and 
    % not directly.
    % 
    % Parameters
    % ----------
    % isDomains : logical, default: false
    %     Indicates if the contrast object is for a domains project.
    %
    % Attributes
    % ----------
    % contrasts : cell
    %     A cell containing an the contrast entries.

    properties
        contrasts = {}
    end

    properties (Access = protected)
        contrastAutoNameCounter
    end

    properties (SetAccess = immutable)
        isDomains
    end

    properties (Dependent, SetAccess = private)
        numberOfContrasts
        displayNames
    end

    properties(Access = protected, Constant, Hidden)
        invalidTypeMessage = sprintf('Model type must be a modelTypes enum or one of the following strings (%s)', ...
                                     strjoin(modelTypes.values(), ', '))
        rowHeaders = struct('key', ["Name"; "Data"; "Background"; "Background Action"; "Bulk in"; "Bulk out"; "Scalefactor"; "Resolution"; "Resample"; "Repeat Layers"; "Domain Ratio"; "Model"], ...
                            'field', ["name"; "data"; "background"; "backgroundAction"; "bulkIn"; "bulkOut"; "scalefactor"; "resolution"; "resample"; "repeatLayers"; "domainRatio"; "model"])
    end

    methods (Abstract)
        getDisplayNames
        parseContrastInput
        setDefaultValues
    end

    methods
        
        function obj = baseContrasts(isDomains)
            arguments
                isDomains {mustBeA(isDomains,'logical')} = false
            end

            obj.isDomains = isDomains;
            obj.contrastAutoNameCounter = 1;
        end

        function count = get.numberOfContrasts(obj)
            count = length(obj.contrasts);
        end
        
        function names = get.displayNames(obj)
            names = obj.getDisplayNames();
        end

        function names = getNames(obj)
            % Returns a N x 1 cell array of names of the contrasts in the object. 
            % 
            % Returns
            % -------
            % names : cell
            %     A cell array which contains the names of contrast entries.
            nContrasts = obj.numberOfContrasts;
            names = cell(nContrasts, 1);
            for i = 1:nContrasts
                names{i} = obj.contrasts{i}.name;
            end
        end

        function obj = addContrast(obj, allowedNames, options)
            % Add a new contrast to the class
            %
            % Examples
            % --------
            % To add a new contrast with name only.
            % 
            % >>> allowedNames = project.getAllAllowedNames();
            % >>> contrasts.addContrast(allowedNames, name='new contrast');
            % 
            % To add a new contrast with other properties.
            % 
            % >>> contrasts.addContrast(allowedNames, name='new contrast', bulkIn='Silicon', bulkOut='D2O', background='D2O Background', ...
            %                           resolution='Resolution 1', scalefactor='Scalefactor 1', data='DSPC Bilayer D2O', model={'Oxide', 'Bilayer tails'});
            %
            % Domain ratio can be added only for domains project.
            % 
            % >>> contrasts.addContrast(allowedNames, name='new contrast', domainRatio='Domain Ratio 1', model={'Domains 1', 'Domains 2'});
            %  
            % Parameters
            % ----------
            % allowedNames: struct
            %     A struct containing the valid names that can be referenced in the contrast.
            % varargin
            %    Keyword/value pair to properties to update for the specific contrast.
            %       * name (char array or string, default: '') the name of the contrast.
            %       * data (char array or string, default: '') the name of the dataset parameter used by the contrast.
            %       * background (char array or string, default: '') the name of the background parameter for the contrast.
            %       * backgroundAction (backgroundActions, default: backgroundActions.Add)  BackgroundActions Whether the background should be added ('add') or subtracted ('subtract') from the data.
            %       * bulkIn (char array or string, default: '') the name of the bulk-in parameter which defines the SLD of the interface between the first layer and the environment.
            %       * bulkOut (char array or string, default: '') the name of the bulk-out parameter which defines the SLD of the interface between the last layer and the environment.
            %       * scalefactor (char array or string, default: '') the name of the scalefactor which defines how much the data for this contrast should be scaled.
            %       * resolution (char array or string, default: '') the name of the instrument resolution for this contrast.
            %       * resample (logical, default: false) whether adaptive resampling should be used for interface microslicing.
            %       * repeatLayers (whole number, default: 1) indicates the number of times the layers should be repeated, this is only available for standard layers.
            %       * domainRatio (char array or string, default: '') the name of the domain ratio parameter.
            %       * model (cell) if this is a standard layers model, this should be a list of layer names that make up the slab model for this contrast.
            %                      For a domains standard layers model, this should be a list of domain contrast names for this contrast.
            %                      For custom models, this should be the custom file name for the custom model function.
            arguments
                obj
                allowedNames
                options.name
                options.data
                options.background
                options.backgroundAction
                options.bulkIn
                options.bulkOut
                options.scalefactor
                options.resolution
                options.resample
                options.repeatLayers
                options.domainRatio
                options.model
            end

            if isempty(fields(options))
                % No input at all
                contrastName = sprintf('New contrast %d', obj.contrastAutoNameCounter);
                inputVals = {'name', contrastName};                
            else
                % Everything else
                inputVals = namedargs2cell(options);
            end
            
            thisContrast = obj.parseContrastInput(allowedNames, inputVals);
            thisContrast = obj.setDefaultValues(thisContrast);

            obj.contrasts{end+1} = thisContrast;
            obj.contrastAutoNameCounter = obj.contrastAutoNameCounter + 1;
        
        end

        function obj = removeContrast(obj, row)
            % Removes a given contrast from the project.
            %
            % Examples
            % --------
            % To remove the second contrast in the table (contrast in row 2).  
            % 
            % >>> contrasts.removeContrast(2);
            % 
            % To remove contrast with a specific name.
            % 
            % >>> contrasts.removeContrast('contrast 1');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the contrast to remove. If it is text, 
            %     it is the name of the contrast to remove.
            if isText(row)
                contrastNames = obj.getNames();
                row = find(strcmpi(contrastNames,row));
                
                % Throw an error if the name is not matched
                if isempty(row)
                    throw(exceptions.nameNotRecognised('Contrast name not found'));
                end
            end
           
            % Check to make sure the number is in range
            if row < 1 || row > obj.numberOfContrasts
                throw(exceptions.indexOutOfRange(sprintf('Specified contrast %d is not in range 1 - %d', row, obj.numberOfContrasts)));
            end

            % Remove the contrast from the contrasts cell array
            obj.contrasts(row) = [];

        end

        function obj = setContrastModel(obj, row, allowedNames, model)
            % Updates the model of an existing contrast.
            %
            % Examples
            % --------
            % To change the model of the second contrast in the object.
            % 
            % >>> contrasts.setContrastModel(2, allowedNames, 'Oxide Model'});
            %
            % To change the properties of a contrast called 'Contrast 1'.
            % 
            % >>> contrasts.setContrastModel('Contrast 1', allowedNames, {'Domains 1', 'Domains 2'});
            %  
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the contrast to update. If it is text, 
            %     it is the name of the contrast to update.
            % allowedNames: struct
            %     A struct containing the valid names that can be referenced in the contrast.
            % model: char array or string or cell string
            %     If this is a standard layers model, this should be a list of layer names that make up the slab model for this contrast.
            %     For a domains standard layers model, this should be a list of domain contrast names for this contrast.
            %     For custom models, this should be the custom file name for the custom model function.
            obj.setContrast(row, allowedNames, 'model', model);

        end

        function obj = setContrast(obj, row, allowedNames, options)
            % General purpose method for updating properties of an existing contrast.
            %
            % Examples
            % --------
            % To change the properties of the second contrast in the object.
            % 
            % >>> contrasts.setContrast(2, allowedNames, name='new contrast', bulkIn='Silicon', bulkOut='D2O', background='D2O Background', ...
            %                           resolution='Resolution 1', scalefactor='Scalefactor 1', data='DSPC Bilayer D2O', model='Oxide Model'});
            %
            % To change the properties of a contrast called 'Contrast 1'.
            % 
            % >>> contrasts.setContrast('Contrast 1', allowedNames, name='new contrast', domainRatio='Domain Ratio 1', model={'Domains 1', 'Domains 2'});
            %  
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the contrast to update. If it is text, 
            %     it is the name of the contrast to update.
            % allowedNames: struct
            %     A struct containing the valid names that can be referenced in the contrast.
            % options
            %    Keyword/value pair to properties to update for the specific contrast.
            %       * name (char array or string, default: '') the name of the contrast.
            %       * data (char array or string, default: '') the name of the dataset parameter used by the contrast.
            %       * background (char array or string, default: '') the name of the background parameter for the contrast.
            %       * backgroundAction (backgroundActions, default: backgroundActions.Add)  BackgroundActions Whether the background should be added ('add') or subtracted ('subtract') from the data.
            %       * bulkIn (char array or string, default: '') the name of the bulk-in parameter which defines the SLD of the interface between the first layer and the environment.
            %       * bulkOut (char array or string, default: '') the name of the bulk-out parameter which defines the SLD of the interface between the last layer and the environment.
            %       * scalefactor (char array or string, default: '') the name of the scalefactor which defines how much the data for this contrast should be scaled.
            %       * resolution (char array or string, default: '') the name of the instrument resolution for this contrast.
            %       * resample (logical, default: false) whether adaptive resampling should be used for interface microslicing.
            %       * repeatLayers (whole number, default: 1) indicates the number of times the layers should be repeated, this is only available for standard layers.
            %       * domainRatio (char array or string, default: '') the name of the domain ratio parameter.
            %       * model (char array or string or cell string) if this is a normal standard layers model, this should be a list of layer names that make up the slab model for this contrast.
            %                      For a domains standard layers model, this should be a list of domain contrast names for this contrast.
            %                      For custom models, this should be the custom file name for the custom model function.
            arguments
                obj
                row
                allowedNames
                options.name
                options.data
                options.background
                options.backgroundAction
                options.bulkIn
                options.bulkOut
                options.scalefactor
                options.resolution
                options.resample
                options.repeatLayers
                options.domainRatio
                options.model
            end

            % Find if we are referencing an existing contrast
            if isnumeric(row) && all(mod(row, 1) == 0)
                if (row < 1 || row > obj.numberOfContrasts)
                    throw(exceptions.indexOutOfRange(sprintf('Contrast index %d is out of range 1 - %d', row, obj.numberOfContrasts)));
                end
                contrastIndex = row;
            elseif isText(row)
                present = strcmpi(row, obj.getNames());
                if ~any(present)
                    throw(exceptions.nameNotRecognised(sprintf('Contrast %s is not recognised',row)));
                end
                contrastIndex = find(present, 1);
            else
                throw(exceptions.invalidType('Row should be a text or whole number.'));
            end

            thisContrast = obj.contrasts{contrastIndex};

            % Check to see if the inputs are valid
            % Raise a warning if we try to set the model as this should be
            % done elsewhere
            inputBlock = parseContrastInput(obj, allowedNames, namedargs2cell(options));
            
            if isfield(inputBlock, 'name') && ~isempty(inputBlock.name)
                thisContrast.name = inputBlock.name;
            end

            if isfield(inputBlock, 'data') && ~isempty(inputBlock.data)
                thisContrast.data = inputBlock.data;
            end
            
            if isfield(inputBlock, 'background') && ~isempty(inputBlock.background)
                thisContrast.background = inputBlock.background;
            end

            if isfield(inputBlock, 'backgroundAction') && ~isempty(inputBlock.backgroundAction)
                thisContrast.backgroundAction = validateOption(inputBlock.backgroundAction, 'backgroundActions',...
                    sprintf('backgroundAction must be a actions enum or one of the following strings (%s)', strjoin(backgroundActions.values(), ', '))).value;
            end
            
            if isfield(inputBlock, 'bulkIn') && ~isempty(inputBlock.bulkIn)
                thisContrast.bulkIn = inputBlock.bulkIn;
            end
            
            if isfield(inputBlock, 'bulkOut') && ~isempty(inputBlock.bulkOut)
                thisContrast.bulkOut = inputBlock.bulkOut;
            end

            if isfield(inputBlock, 'scalefactor') && ~isempty(inputBlock.scalefactor)
                thisContrast.scalefactor = inputBlock.scalefactor;
            end
            
            if isfield(inputBlock, 'resolution') && ~isempty(inputBlock.resolution)
                thisContrast.resolution = inputBlock.resolution;
            end
            
            if isfield(inputBlock, 'resample') && ~isempty(inputBlock.resample)
                thisContrast.resample = inputBlock.resample;
            end
            
            if isfield(inputBlock, 'repeatLayers') && ~isempty(inputBlock.repeatLayers)
                thisContrast.repeatLayers = inputBlock.repeatLayers;
            end

            if isfield(inputBlock, 'domainRatio') && ~isempty(inputBlock.domainRatio)
                thisContrast.domainRatio = inputBlock.domainRatio;
            end

            if isfield(inputBlock, 'model') && ~isempty(inputBlock.model)
                thisContrast.model = cellstr(inputBlock.model);
            end

            obj.contrasts{contrastIndex} = thisContrast;
            
        end

        function contrastStruct = toStruct(obj)
            % Converts the base contrasts class to a struct.
            % 
            % Returns
            % -------
            % contrastStruct : struct
            %     A struct which contains the properties for all the contrast entries.
            nContrasts = obj.numberOfContrasts;
            contrastNames = cell(1,nContrasts);
                        
            for i = 1:nContrasts
                contrastNames{i} = obj.contrasts{i}.name;
            end

            contrastStruct.contrastNames = contrastNames;
            contrastStruct.numberOfContrasts = nContrasts;
            
        end

        function displayContrastsObject(obj)
            % Prints the contrasts object to the console in a tabular format.
            rowNames = obj.displayNames;
            nContrasts = obj.numberOfContrasts;
            maxModelSize = 1;
            
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};
                thisModel = thisContrast.model;
                if length(thisModel) > maxModelSize
                    maxModelSize = length(thisModel);
                end
            end

            numNamedRows = length(rowNames);
            modelRows = cell((maxModelSize-1),1);
            if ~isempty(modelRows)
                for n = 1:length(modelRows)
                    modelRows{n} = '';
                end
            end

            p = [rowNames ; modelRows];
            totalRows = length(p);
            contrastsCell = cell(totalRows,nContrasts);
            
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};
                n = 1;

                % Loop over all fields excluding the model
                for j = 1:length(rowNames)-1
                    field = obj.rowHeaders.field(obj.rowHeaders.key == rowNames{j});
                    contrastsCell(n,i) = {thisContrast.(field)};
                    n = n + 1;
                end
                
                % Deal with the model explicitly
                thisModel = thisContrast.model;
                if isempty(thisModel)
                    contrastsCell(numNamedRows,i) = {' '};
                else
                    for n = 1:length(thisModel)
                        contrastsCell(numNamedRows+(n-1),i) = {thisModel(n)};
                    end
                end

            end
            
            sz = size(contrastsCell);
            varTypes = cell(1,nContrasts);
            varNames = cell(1,nContrasts);
            for i = 1:nContrasts
                varNames{i} = num2str(i);
                varTypes{i} = 'string';
            end

            thisTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            
            % Make sure that there are no empty cells - make them empty
            % char arrays or they will not be valid table elements
            for n = 1:sz(1)
                for m = 1:sz(2)
                    if (isempty(contrastsCell{n,m}))
                        contrastsCell{n,m} = '';
                    end
                end
            end
            thisTable(:,:) = contrastsCell;
            valTable = table(p);
            totalTable = [valTable thisTable];
            disp(totalTable);
        end

    end
end
