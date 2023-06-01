classdef dataClass < tableUtilities
    % A container class for holding data

    properties (Access = private)   
        autoDataNameCounter = 1
        defaultSimMin = 0.005
        defaultSimMax = 0.7
    end
    
    properties (Dependent)
        dataCount
    end

    methods
        
        function obj = dataClass(varargin)
            % Creates a Data object. The argument should be contents of the first
            % dataset which should consists of a name (string), data (N by 3 array), 
            % dataRange (1 by 2 or empty array), and simRange (1 by 2 or empty array). 
            %
            % data = dataClass('data_name',  [],  [], []);
            sz = [0 4];
            varTypes = {'string','cell','cell','cell'};
            varNames = {'Name','Data','Data Range','Simulation Range'};
            obj.paramTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames); 
            obj.addData(varargin{:}); 
        end
        
        function count = get.dataCount(obj)
            count = height(obj.paramTable);
        end

        function obj = addData(obj, varargin)
            % Adds a dataset to the data table. Default values are used if no 
            % arguments are provided, otherwise a subset of the arguments can 
            % be provided.
            % The following are assumed from number of arguments: 
            % for 1 input, the name only is provided
            % for 2 inputs, the name and data are provided
            % for 4 inputs, the name, data, data range, and simulation range are provided      
            %
            % data.addData();
            % data.addData('Sim');
            % data.addData('Sim', ones(5, 3));
            % data.addData('Sim', ones(5, 3), [0.2, 0.9],  [-3, 6]);
            if isempty(varargin)
                
                % Nothing supplied - add empty data row
                newName = sprintf('New data %d', obj.autoDataNameCounter());
                
                newData = [];
                newDataRange = [];
                newSimRange = [obj.defaultSimMin, obj.defaultSimMax];

            else

                inputs = varargin;
                newName = inputs{1};

                if ~isText(newName)
                    throw(invalidType('First input is expected to be a data name'));
                end

                newData = [];
                newDataRange = [];
                newSimRange = [obj.defaultSimMin, obj.defaultSimMax];

                % Check length of added data
                switch length(inputs)
                    case 1
                    case 2
                        % Two inputs supplied - assume both name and data
                        % supplied;
                        newData = inputs{2};
                        
                        newDataX = newData(:,1);
                        newMin = newDataX(1);
                        newMax = newDataX(end);
                        
                        newDataRange = [newMin newMax];
                        newSimRange = [newMin newMax];

                    case 4
                        % Four inputs = assume data and simulation ranges also
                        % supplied
                        newData = inputs{2};                       
                        newDataRange = inputs{3};
                        if ~isempty(inputs{4})
                            newSimRange = inputs{4};
                        end

                    otherwise  
                        % Other length of inputs is not recognised
                        throw(invalidNumberOfInputs('Unrecognised input into addData'));
                      
                end
            end

            % Check data is valid and add the new entry
            newRow = {newName, newData, newDataRange, newSimRange};
            newRow = obj.validateData(newRow);
            appendNewRow(obj, newRow);

        end
        
        function nameChanged = setData(obj, row, varargin)
            % Sets the values of an existing dataset. Expects the
            % index or name of dataset and keyword/value pairs to set
            %
            % data.setData(2, 'name', 'new_name');
            dataNames = obj.paramTable{:,1};
            
            % Always need three or more inputs to set data value
            if length(varargin) < 2 || mod(length(varargin), 2) ~= 0
                throw(invalidNumberOfInputs('The input to ''setData'' should be a data entry and a set of name-value pairs'));
            end
                
            % First input needs to be a data number or name
            if isnumeric(row)
                if (row > obj.dataCount) || (row < 1)
                    throw(indexOutOfRange(sprintf('The index %d is not within the range 1 - %d', row, obj.dataCount)));
                end
            elseif isText(row)
                row = obj.findRowIndex(row, dataNames, sprintf('Data object name %s not recognised', row));
            end
            
            % Parse the name value pairs to see what is being set and make
            % sure the data is of the correct size and type.

            % Make an 'inputParser' object...
            p = inputParser;
            
            % dataRange and simRange need to be [1 x 2] arrays
            isDimsRanges = @(x)all(size(x) == [1,2]);
            
            % Data needs to be an [n x >3] array
            isDimsData = @(x) size(x,2) >= 3;

            addParameter(p,'name','', @(x) isText(x))
            addParameter(p,'data',[], @(x) isnumeric(x) && isDimsData(x))
            addParameter(p,'dataRange',[], @(x) isnumeric(x) && isDimsRanges(x))
            addParameter(p,'simRange', [], @(x) isnumeric(x) && isDimsRanges(x)) 
            parse(p,varargin{:});
                
            results = p.Results;
            
            % Any fields in results that are not empty are being set,
            % so call the relevant set method for these (which will carry
            % out some additional checks)
            
            nameChanged = []; % Flag which is passed up to the calling function (to change contrasts if necessary)
            
            if ~isempty(results.name)
                nameChanged = obj.setDataName(row,results.name);
            end
            
            if ~isempty(results.data)
                obj.paramTable{row, 2} = {results.data};
            end
            
            if ~isempty(results.dataRange)
                obj.paramTable{row, 3} = {results.dataRange};
            end
            
            if ~isempty(results.simRange)
                obj.paramTable{row, 4} = {results.simRange};
            end

        end
        
        function nameChanged = setDataName(obj, whichData, name)
            % Sets the name of an existing dataset. Expects index of data  
            % and the new name. Name must be a char and not an existing name.
            % Returns a structure with the new name and old name
            %
            % names = data.setDataName({2, 'new name'});
            if ~isText(name)
                throw(invalidType('Name must be a character array or string'));
            end
            
            existingNames = obj.getNames;
            if any(strcmpi(name,existingNames))
                throw(duplicateName('Duplicate data names are not allowed'));
            end
            
            % Set the relevant name
            nameChanged.oldName = obj.paramTable{whichData,1};
            nameChanged.newName = name;
            obj.paramTable{whichData,1} = {name};   
        end

        function displayDataObject(obj)
            % Displays the table object. The actual obj.paramTable has the 
            % format {string, cell, double, double}, but for display we 
            % make a table that is all strings.
            
            fprintf('    Data: ------------------------------------------------------------------------------------------------------ \n\n');
            
            tab = obj.paramTable;
            
            sz = [1,4];
            displayVarTypes = {'string','string','string','string'}; 
            displayVarNames = {'Name','Data','Data Range','Simulation Range'};
            displayTable = table('Size',sz,'VariableTypes',displayVarTypes,'VariableNames',displayVarNames);
            
            tableSize = size(tab);
            
            for i = 1:tableSize(1)
                thisRow = tab(i,:);
                
                nameString = thisRow{1,1};
                
                thisData = thisRow{1,2}{:};
                if isempty(thisData)
                    dataString = 'No Data';
                else
                    dataSize = size(thisData);
                    dataString = sprintf('Data array: [%d x %d]',dataSize(1),dataSize(2));
                end
                
                thisDataRange = thisRow{1,3}{:};
                if isempty(thisDataRange)
                    dataRangeString = '-';
                else
                    dataRangeString = sprintf('[ %1.4f , %1.4f ]', thisDataRange(1), thisDataRange(2));
                end
                
                thisSimRange = thisRow{1,4}{:};
                if isempty(thisSimRange)
                    simRangeString = '-';
                else
                    simRangeString = sprintf('[ %1.4f , %1.4f ]', thisSimRange(1), thisSimRange(2));
                end   
                
                newDisplayRow = {nameString, dataString, dataRangeString, simRangeString};
                displayTable(i,:) = newDisplayRow;
                
            end

            disp(displayTable);
            fprintf('\n');
        end
    end

    methods(Access = protected)

        function obj = appendNewRow(obj, row)
            % Appends a new row to the table. Expects a cell array  
            % with row values to append
            % 
            % obj.appendNewRow({'name', [], [], []})
            tab = obj.paramTable;

            % Ensure no duplicate names
            if any(strcmpi(row{1}, tab{:,1}))
                throw(duplicateName('Duplicate data names not allowed'));
            end

            tab = [tab ; row];
            obj.paramTable = tab;
            obj.autoDataNameCounter = obj.autoDataNameCounter + 1;  
        end

    end

    methods(Static, Access = protected)  
    
        function row = validateData(row)
            % Carry out checks of Data type and ranges in a table row.
            % Expects the row of the data table as input.
            %
            % row = obj.validateData(row);
            name = row{1};
            data = row{2};
            dataRange = row{3};
            simRange = row{4};
                
            if ~isempty(data)

                if ~isnumeric(data)
                    throw(invalidType('Data must be a numeric array'));
                end
                
                if ((~isnumeric(dataRange)) || any(size(dataRange) ~= [1,2]) || any(size(simRange) ~= [1,2]))
                    throw(invalidType('Data range and sim range must be [1 x 2] numeric arrays'));
                end
    
                dataX = data(:, 1);  % First column is always Q
                realDataRange = [dataX(1), dataX(end)];
                if realDataRange(1) > realDataRange(2)
                    throw(invalidValue('Data is expected to be sorted (ascending order) by the first column'));
                end
    
                if dataRange(1) < realDataRange(1)
                    warning('dataRange(1) can''t be less than min data value - resetting');
                    dataRange(1) = realDataRange(1);
                end
                
                if dataRange(2) > realDataRange(2)
                    warning('dataRange(2) can''t be more than max data value - resetting');
                    dataRange(2) = realDataRange(2);
                end
                
                if dataRange(1) > dataRange(2)
                    warning('Data range min must not be greater than max - resetting');
                    dataRange(1) = realDataRange(1);
                    dataRange(2) = realDataRange(2);
                end
                
                if simRange(1) > realDataRange(1)
                    warning('simRange(1) must be less than data range - resetting');
                    simRange(1) = realDataRange(1);
                end
                
                if simRange(2) < realDataRange(2)
                    warning('simRange(2) must be greater than data range - resetting');
                    simRange(2) = realDataRange(2);
                end

            end

            row = {{name}, {data}, {dataRange}, {simRange}};
    
        end
    end
end
