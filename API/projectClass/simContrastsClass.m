classdef simContrastsClass < baseContrasts

    % A simplified version of the contrast class that allows specification
    % of the model only (i.e. with no data). This is used for domains
    % calculations.
                
    methods
                
        function obj = setContrast(obj, row, allowedNames, varargin)
            % Set a value within a contrast.
            % The expected input is the contrast (specified either by name
            % or index), the allowed values for all parameters and a
            % set of key-value pairs for the parameter values to be
            % changed.
            %
            % contrasts.setContrast(1, allowedNames, ...
            %                       'name', 'New contrast name', ... 
            %                       'nba', 'Silicon')

            % Find if we are referencing an existing contrast
            if isnumeric(row)
                if (row < 1 || row > obj.numberOfContrasts)
                    throw(indexOutOfRange(sprintf('Contrast number %d is out of range 1 - %d', row, obj.numberOfContrasts)));
                end
                contrastIndex = row;
                
            elseif isText(row)
                [present,idx] = ismember(row, obj.getAllContrastNames());
                if ~present
                    throw(nameNotRecognised(sprintf('Contrast %s is not recognised',row)));
                end
                contrastIndex = idx;
                
            end

            thisContrast = obj.contrasts{contrastIndex};

            % Check to see if the inputs are valid
            % Raise a warning if we try to set the model as this should be
            % done elsewhere
            inputBlock = obj.parseContrastInput(allowedNames, obj.domainsCalc, varargin);
                        
            if ~isempty(inputBlock.name)
                thisContrast.name = inputBlock.name;
            end
            
            if ~isempty(inputBlock.nba)
                thisContrast.nba = inputBlock.nba;
            end
            
            if ~isempty(inputBlock.nbs)
                thisContrast.nbs = inputBlock.nbs;
            end
            
            obj.contrasts{contrastIndex} = thisContrast;
            
        end

        function contrastStruct = toStruct(obj, allowedNames, modelType, ~)
            % Convert the contrasts class to a struct.
            % The expected input is the allowed names for each parameter,
            % the model type and the data table from the data class.
            %
            % contrasts.toStruct(allowedNames, 'standard layers', dataTable)
            nContrasts = obj.numberOfContrasts;
            contrastLayers = cell(1,nContrasts);
            contrastNbas = ones(1,nContrasts);
            contrastNbss = ones(1,nContrasts);
            contrastCustomFile = ones(1,nContrasts);
            contrastNames = cell(1,nContrasts);
            contrastRepeatSLDs = cell(1,nContrasts);
            
            for i = 1:nContrasts

                thisContrast = obj.contrasts{i};
                
                contrastNbas(i) = find(strcmpi(thisContrast.nba,allowedNames.bulkInNames));
                contrastNbss(i) = find(strcmpi(thisContrast.nbs,allowedNames.bulkOutNames));
                contrastRepeatSLDs{i} = [0 1]; % todo
                contrastNames{i} = thisContrast.name;

                modelType = validateOption(modelType, 'modelTypes', obj.invalidTypeMessage).value;
                switch modelType
                    case modelTypes.StandardLayers.value
                        thisModel = thisContrast.model;
                        thisLayerArray = ones(1, length(thisModel));
                        for n = 1:length(thisModel)
                            thisLayer = thisModel{n};
                            thisLayerNum = find(strcmpi(thisLayer, allowedNames.layersNames));
                            thisLayerArray(n) = thisLayerNum;
                        end
                        contrastLayers{i} = thisLayerArray;
                        contrastCustomFile(i) = NaN;
                    otherwise
                        contrastLayers{i} = {};
                        whichFile = thisContrast.model;
                        thisContrastFileNum = find(strcmpi(whichFile, allowedNames.customNames));
                        contrastCustomFile(i) = thisContrastFileNum;
                end
                
            end
            
            contrastStruct.contrastNbas = contrastNbas;
            contrastStruct.contrastNbss = contrastNbss;
            contrastStruct.contrastLayers = contrastLayers;
            contrastStruct.contrastRepeatSLDs = contrastRepeatSLDs;
            contrastStruct.contrastCustomFile = contrastCustomFile;
            contrastStruct.numberOfContrasts = nContrasts;
            
        end
        
        function displayContrastsObject(obj)
            % Display the contrasts object as a table.
            %
            % contrasts.displayContrastsObject()           
            nContrasts = obj.numberOfContrasts;
            maxModelSize = 1;
            
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};
                thisModel = thisContrast.model;
                if length(thisModel) > maxModelSize
                    maxModelSize = length(thisModel);
                end
            end

            val = ["name";"Bulk in";"Bulk out";"Model"];

            numNamedCols = length(val);
            modelRows = cell((maxModelSize-1), 1);
            if ~isempty(modelRows)
                for n = 1:length(modelRows)
                    modelRows{n} = '';
                end
            end

            p = [val ; modelRows];
            totalRows = length(p);
            contrastsCell = cell(totalRows,nContrasts);
            
            for i = 1:nContrasts
                thisContrast = obj.contrasts{i};
                contrastsCell(1,i) = {thisContrast.name};
                contrastsCell(2,i) = {thisContrast.nba};
                contrastsCell(3,i) = {thisContrast.nbs};
                
                thisModel = thisContrast.model;
                if isempty(thisModel)
                    contrastsCell(numNamedCols,i) = {' '};
                else
                    for n = 1:length(thisModel)
                        contrastsCell(numNamedCols+(n-1),i) = {thisModel(n)};
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
            fprintf('    Constrasts: ---------------------------------------------------------------------------------------------- \n\n');
            disp(totalTable);
        end

    end
    
    methods(Static)

        function inputBlock = parseContrastInput(allowedNames, ~, inputValues)
            % Parse the parameters given for the contrast, assigning
            % default values to those unspecified and ensuring specified
            % values are of the correct type, and included in the list of
            % allowed names where necessary.
            %
            % contrastsClass.parseContrastInput(allowedNames, ...
            %                                   domainsCalc, ...
            %                                   'name', 'Contrast Name', ...
            %                                   'nba', 'Silicon')        
            defaultName = '';
            defaultNba = '';
            defaultNbs = '';
        
            expectedBulkin = cellstr(allowedNames.bulkInNames);
            expectedBulkout = cellstr(allowedNames.bulkOutNames);
        
            p = inputParser;
            addParameter(p,'name',          defaultName,        @isText);
            addParameter(p,'nba',           defaultNba,         @(x) any(validatestring(x,expectedBulkin)));
            addParameter(p,'nbs',           defaultNbs,         @(x) any(validatestring(x,expectedBulkout)));
                
            parse(p, inputValues{:});
            inputBlock = p.Results;

        end

    end
end


