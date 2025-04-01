% ``dataClass`` manages the datasets for the project. It provides methods to add, update and remove datasets.
% Each dataset is stored as a row in a table and consists of a name, the data itself, the range of the data to use, 
% and the range for simulation. ``dataClass`` will be initialised with a default empty dataset if no arguments are 
% provided otherwise the provided arguments will be used to create the first dataset.
%
%
% Examples
% --------
% >>> data = dataClass('Data 1', data=[1, 0, 0; 2, 0, 0; 3, 0, 0; 4, 0, 0], dataRange=[2, 3], simRange=[1, 4]);
%
% Parameters
% ----------
% name : string or char array
%     The name of the dataset.
% data : float
%     3 or 4 column data for the dataset, the data should have (x, y, error) columns and may have optional resolution column.
% dataRange : float
%     The minimum and maximum range of ``data`` to use from the dataset.
% simRange : float
%     The minimum and maximum range to use for simulation.
%
% Attributes
% ----------
% varTable : table
%     A table object that contains the data entries.

classdef dataClass < tableUtilities
    properties (Constant, Hidden)
        defaultSimRange = [0.005, 0.7]
    end

    methods
        function obj = dataClass(name, data, dataRange, simRange)
            arguments
                name {mustBeTextScalar} = ''
                data {mustBeNumeric} = []
                dataRange {mustBeNumeric} = []
                simRange {mustBeNumeric} = []
            end
            sz = [0 4];
            varTypes = {'string','cell','cell','cell'};
            varNames = {'Name','Data','Data Range','Simulation Range'};
            obj.varTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames); 
            obj.addData(name, data, dataRange, simRange); 
        end

        function obj = addData(obj, name, data, dataRange, simRange)
            % Adds a new dataset to the data table.
            % 
            % Examples
            % --------
            % To add a new dataset with name only.
            % 
            % >>> data.addData('Data 1');
            % 
            % To add dataset with name and data.
            % 
            % >>> data.addData('Data 1', [1, 0, 0; 2, 0, 0; 3, 0, 0; 4, 0, 0]);
            % 
            % To add dataset with name, data and the ranges.
            % 
            % >>> data.addData('Data 1', [1, 0, 0; 2, 0, 0; 3, 0, 0; 4, 0, 0], [2, 3], [1, 4]);
            % 
            % Parameters
            % ----------
            % name : string or char array, default: auto-generated name
            %     The name of the dataset.
            % data : float, default: []
            %     3 or 4 column data for the dataset, the data should have (x, y, error) columns and may have optional resolution column.
            % dataRange : float, default: [data(1), data(end)] or [] if no data 
            %     The minimum and maximum range of ``data`` to use from the dataset. 
            % simRange : float, default: [0.005, 0.7]
            %     The minimum and maximum range to use for simulation.
            arguments
                obj
                name {mustBeTextScalar} = ''
                data {mustBeNumeric} = []
                dataRange {mustBeNumeric} = []
                simRange {mustBeNumeric} = []
            end
            newName = name;
            newData = data;
            newDataRange = dataRange;
            newSimRange = simRange;
                        
            if isempty(name)
                % Nothing supplied - add empty data row
                newName = sprintf('New data %d', obj.autoNameCounter());    
            end

            if ~isempty(data)
                newDataX = newData(:,1);
                newMin = newDataX(1);
                newMax = newDataX(end);

                if isempty(dataRange)
                    newDataRange = [newMin newMax];
                end

                if isempty(simRange)
                    newSimRange = [newMin newMax];
                end
            end
            
            if isempty(newSimRange)
                newSimRange = obj.defaultSimRange;
            end

            % Check data is valid and add the new entry
            [newDataRange, newSimRange] = obj.validateData(newData, newDataRange, newSimRange);
            obj.addRow(newName, newData, newDataRange, newSimRange);
        end

        function obj = removeData(obj, row)
            % Removes a given dataset from the table.
            %
            % Examples
            % --------
            % To remove the second dataset in the table (dataset in row 2).  
            % 
            % >>> data.removeData(2);
            % 
            % To remove dataset with a specific name.
            % 
            % >>> data.removeData('Data D2O');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the dataset to remove. If it is text, 
            %     it is the name of the dataset to remove.
            obj.removeRow(row);
        end

        function nameChanged = setData(obj, row, options)
            % General purpose method for updating properties of an existing dataset.
            %
            % Examples
            % --------
            % To change the name and data of the second dataset in the table (dataset in row 2).
            % 
            % >>> nameChanged = data.setData(2, name='Data 1', data=[1, 0, 0; 2, 0, 0; 3, 0, 0; 4, 0, 0]);
            % 
            % To change the properties of a background called 'Data 1'.
            % 
            % >>> nameChanged = data.setData('Data 1', name='Data H2O', dataRange=[2, 3]);
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the background to update. If it is text, 
            %     it is the name of the background to update.
            % options
            %    Keyword/value pair to properties to update for the specific dataset.
            %       * name (char array or string, default: '') the new name of the dataset.
            %       * data (float, default: []) the new data array.
            %       * dataRange (float, default: []) the new data range.
            %       * simRange (float, default: []) the new simulation range.
            % 
            % Returns
            % -------
            % nameChanged : struct or []
            %     A struct which contains the former name ``oldName`` and the new name ``newName`` of the dataset or 
            %     empty array if name is not changed.
            arguments
                obj
                row
                options.name {mustBeTextScalar} = ''
                options.data {mustBeNumeric} = []
                options.dataRange {mustBeNumeric} = []
                options.simRange {mustBeNumeric} = []
            end
            dataNames = obj.varTable{:,1};
               
            % First input needs to be a data number or name
            if isnumeric(row)
                if (row > obj.rowCount) || (row < 1)
                    throw(exceptions.indexOutOfRange(sprintf('The index %d is not within the range 1 - %d', row, obj.rowCount)));
                end
            elseif isText(row)
                row = obj.findRowIndex(row, dataNames, sprintf('Data object name %s not recognised', row));
            end
            
            if isempty(options.name)
                options.name = obj.varTable{row, 1}{:};
            end
            
            if isempty(options.data)
                options.data = obj.varTable{row, 2}{:};
            end
            
            if isempty(options.dataRange)
                options.dataRange = obj.varTable{row, 3}{:};
            end
            
            if isempty(options.simRange)
                options.simRange = obj.varTable{row, 4}{:};
            end
            
            nameChanged = []; % Flag which is passed up to the calling function (to change contrasts if necessary)
            
            [options.dataRange, options.simRange] = obj.validateData(options.data, options.dataRange, options.simRange);
            
            if ~strcmp(options.name, obj.varTable{row, 1}{:})
                nameChanged = obj.setName(row, options.name);
            end
            obj.varTable{row, 2} = {options.data};
            obj.varTable{row, 3} = {options.dataRange};
            obj.varTable{row, 4} = {options.simRange};
        end
        
        function dataStruct = toStruct(obj)
            % Converts the dataClass into a structure array.
            %
            % Returns
            % -------
            % dataStruct : struct
            %     A struct which contains the properties for all the datasets.
            numData = obj.rowCount;
            dataNames = cell(numData, 1);
            allData = cell(numData, 1);

            for i = 1:numData
                row = obj.varTable{i,1};
                dataNames{i} = row{1};
                allData{i} = obj.varTable{i,2};
            end

            dataStruct.dataNames = dataNames;
            dataStruct.allData = allData;
        end

        function displayTable(obj)           
            % Prints the data table to the console.
            sz = [1,4];
            displayVarTypes = {'string','string','string','string'}; 
            displayVarNames = {'Name','Data','Data Range','Simulation Range'};
            displayTable = table('Size',sz,'VariableTypes',displayVarTypes,'VariableNames',displayVarNames);
            
            tableSize = size(obj.varTable);
            
            for i = 1:tableSize(1)
                nameString = obj.varTable{i, 1};
                
                thisData = obj.varTable{i, 2}{:};
                if isempty(thisData)
                    dataString = 'No Data';
                else
                    dataSize = size(thisData);
                    dataString = sprintf('Data array: [%d x %d]',dataSize(1),dataSize(2));
                end
                
                thisDataRange = obj.varTable{i, 3}{:};
                if isempty(thisDataRange)
                    dataRangeString = '-';
                else
                    dataRangeString = sprintf('[ %1.4f , %1.4f ]', thisDataRange(1), thisDataRange(2));
                end
                
                thisSimRange = obj.varTable{i, 4}{:};
                if isempty(thisSimRange)
                    simRangeString = '-';
                else
                    simRangeString = sprintf('[ %1.4f , %1.4f ]', thisSimRange(1), thisSimRange(2));
                end   
                
                newDisplayRow = {nameString, dataString, dataRangeString, simRangeString};
                displayTable(i,:) = newDisplayRow;               
            end

            disp(displayTable);
        end
    end

    methods(Access = protected)  
        function nameChanged = setName(obj, row, name)
            % Sets the name of an existing dataset.
            %
            % Examples
            % --------
            % To change the name of the second dataset in the table (dataset in row 2)
            % 
            % >>> nameChanged = data.setName(2, 'Data SMW');
            % 
            % To change the name of a dataset called 'Data D20' to 'Data SMW'
            % 
            % >>> nameChanged = data.setName('Data D20', 'Data SMW');
            %
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the dataset to update. If it is text, 
            %     it is the name of the dataset to update.
            % name : string or char array
            %     The new name of the dataset.
            % 
            % Returns
            % -------
            % nameChanged : struct
            %     A struct which contains the former name ``oldName`` and the new name ``newName`` of the dataset.
            arguments
                obj
                row
                name {mustBeTextScalar, mustBeNonempty}
            end
            existingNames = obj.getNames;
            if any(strcmpi(name, existingNames))
                throw(exceptions.duplicateName('Duplicate data names are not allowed'));
            end
            
            % Set the relevant name
            nameChanged.oldName = obj.varTable{row, 1};
            nameChanged.newName = name;
            obj.varTable{row, 1} = {name};   
        end

        function [dataRange, simRange] = validateData(~, data, dataRange, simRange)
            % Checks the data and simulation ranges are valid. If any range is invalid, 
            % a warning is printed and the range is adjusted when possible.
            %
            % Examples
            % --------
            % [dataRange, simRange] = validateData(data, dataRange, simRange);
            %
            % Parameters
            % ----------
            % data : float
            %     The 2D data array . 
            % dataRange : float
            %     The minimum and maximum range of the data to use from the dataset.
            % simRange : float
            %     The minimum and maximum range to use for simulation.
            % 
            % Returns
            % -------
            % dataRange : float
            %     The minimum and maximum range of ``data`` to use from the dataset, adjusted if input was invalid.
            % simRange : float
            %     The minimum and maximum range to use for simulation, adjusted if input was invalid. 
            if ~isempty(data)
                % Data needs to be an [n x >3] array
                if (~isnumeric(data) || size(data, 2) < 3)
                    throw(exceptions.invalidType('Data must be a numeric array with at least 3 columns.'));
                end

                if (~isnumeric(dataRange) || any(size(dataRange) ~= [1,2]) || any(size(simRange) ~= [1,2]))
                    throw(exceptions.invalidType('Data range and sim range must be [1 x 2] numeric arrays'));
                end
    
                dataX = data(:, 1);  % First column is always Q
                realDataRange = [dataX(1), dataX(end)];
                if realDataRange(1) > realDataRange(2)
                    throw(exceptions.invalidValue('Data is expected to be sorted (ascending order) by the first column'));
                end
    
                if dataRange(1) < realDataRange(1)
                    warning('dataRange(1) can''t be less than min data value - resetting to %d', realDataRange(1));
                    dataRange(1) = realDataRange(1);
                end
                
                if dataRange(2) > realDataRange(2)
                    warning('dataRange(2) can''t be more than max data value - resetting to %d', realDataRange(2));
                    dataRange(2) = realDataRange(2);
                end
                
                if dataRange(1) > dataRange(2)
                    warning('Data range min must not be greater than max - resetting to [%d %d]', realDataRange(1), realDataRange(2));
                    dataRange(1) = realDataRange(1);
                    dataRange(2) = realDataRange(2);
                end
                
                if simRange(1) > realDataRange(1)
                    warning('simRange(1) can''t be greater than min data range - resetting to %d', realDataRange(1));
                    simRange(1) = realDataRange(1);
                end
                
                if simRange(2) < realDataRange(2)
                    warning('simRange(2) can''t be less than max data range - resetting to %d', realDataRange(2));
                    simRange(2) = realDataRange(2);
                end
            end    
        end
    end
end
