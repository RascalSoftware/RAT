classdef customFileClass < tableUtilities
    
    % A container class for holding custom files for either
    % models, backgrounds or resolutions.

    properties(Access = private, Constant, Hidden)
        invalidLanguageMessage = sprintf('Language must be a supportedLanguages enum or one of the following strings (%s)', ...
                                         strjoin(supportedLanguages.values(), ', '))
    end
    
    methods
        
        function obj = customFileClass(varargin)
            % Construct a custom file class containing either an empty
            % table or one with a single row.
            % No input is required for an empty table, otherwise the
            % parameters for the first row should be provided.
            %
            % customFiles = customFileClass()           
            sz = [0 4];
            varTypes = {'string','string','string','string'};
            varNames = {'Name','Filename','Language','Path'};
            obj.varTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);

            if ~isempty(varargin)
                obj.addCustomFile(varargin{:});
            end          
        end

        function obj = addCustomFile(obj, varargin)
            % Add an entry to the file table.
            % A custom file entry can be added with no parameters, just the
            % name of the custom file entry, the name of the entry
            % alongside a filename, or can be fully defined by specifying
            % the name of the custom file entry, filename, language, and
            % file path
            %
            % customFiles.addCustomFile()
            % customFiles.addCustomFile('New Row')
            % customFiles.addCustomFile('New Row', 'file.m')
            % customFiles.addCustomFile('New Row', 'file.m', 'matlab', 'pwd')
            if isempty(varargin)
                
                % Nothing supplied - add empty data row
                nameVal = obj.autoNameCounter();
                newName = sprintf('New custom file %d', nameVal);
                
                newRow = {newName, '', supportedLanguages.Matlab.value, 'pwd'};

            else
                
                inputs = varargin;

                % Check length of added data
                switch length(inputs)
                    
                    case 1

                        % One input supplied - assume just name provided
                        newName = inputs{1};
                        if ~isText(newName)
                            throw(invalidType('Single input is expected to be a custom object name'));
                        end
                        
                        newRow = {newName, '', supportedLanguages.Matlab.value, 'pwd'};
                        
                    case 2

                        % Two inputs suppled - assume both name and
                        % filename supplied;
                        newName = char(inputs{1});
                        newFile = char(inputs{2});

                        newRow = {newName, newFile, supportedLanguages.Matlab.value, 'pwd'};
                        
                    case 4

                        % Four inputs = assume all inputs supplied
                        newName = char(inputs{1});
                        newFile = char(inputs{2});
                        newLang = char(inputs{3});
                        newPath = char(inputs{4});
                        
                        newRow = {newName, newFile, newLang, newPath};
                        
                    otherwise

                        % Other length of inputs is not recognised
                        throw(invalidNumberOfInputs('Unrecognised input into addCustomFile'));
                        
                end
            end

            % Check language is valid, then add the new entry
            newRow{3} = validateOption(newRow{3}, 'supportedLanguages', obj.invalidLanguageMessage).value;
            obj.addRow(newRow{:});

        end
        
        function obj = setCustomFile(obj, row, varargin)
            % Change the value of a given parameter in the file table.
            % The expected inputs are the row of the file entry of
            % interest (given either by name of index), and key-value pairs
            % of the parameter(s) to change. The values of the keys are:
            % "Name", "Filename", "Language", and "Path".
            % NOTE changing the path using this routine is not implemented
            %
            % customFiles.setcustomFile(1, 'Name', 'New Name',...
            %                           'Language', 'Octave')
            customNames = obj.getNames;
            
            % Always need three or more inputs to set data value
            if length(varargin) < 2 || mod(length(varargin), 2) ~= 0
                throw(invalidNumberOfInputs('The input to ''setCustomFile'' should be a file entry and a set of name-value pairs'));
            end
                
            % First input needs to be a data number or name
            if isnumeric(row)
                if (row > obj.rowCount) || (row < 1)
                    throw(indexOutOfRange(sprintf('The index %d is not within the range 1 - %d', row, obj.rowCount)));
                end
            elseif isText(row)
                row = obj.findRowIndex(row, customNames, sprintf('Custom file object name %s not recognised', row));
            end
            
            % Parse the name value pairs to see what is being set and make
            % sure the data is of the correct size and type.

            % Make an 'inputParser' object...
            p = inputParser;

            addParameter(p,'name','', @(x) isText(x))
            addParameter(p,'filename','', @(x) isText(x))
            addParameter(p,'language','', @(x) isText(x) || isenum(x))
            addParameter(p,'path','', @(x) isText(x)) 
            parse(p, varargin{:});
                
            results = p.Results;
            
            % Any fields in results that are not empty are being set,
            % so call the relevant set method for these (which will carry
            % out some additional checks)
            if ~isempty(results.filename)
                obj.setFileName(row,results.filename);
            end
            
            if ~isempty(results.language)
                results.language = validateOption(results.language, 'supportedLanguages', obj.invalidLanguageMessage).value;
                obj.setCustomLanguage(row, results.language);
            end
            
            if ~isempty(results.path)
                % NOT IMPLEMENTED
                obj.setCustomPath(row,results.path);
            end
            
            if ~isempty(results.name)
                obj.setCustomName(row,results.name);
            end            

        end

        function displayTable(obj)
            % Display the file table.
            %
            % customFiles.displayCustomFileObject()
            tab = obj.varTable;
            
            sz = [1,4];
            displayVarTypes = {'string','string','string','string'}; 
            displayVarNames = {'Name','Filename','Language','Path'};
            displayTable = table('Size',sz,'VariableTypes',displayVarTypes,'VariableNames',displayVarNames);
            
            tableSize = size(tab);
            
            if tableSize(1) == 0
                displayTable(1,:) = {'','','',''};
            else
                
                for i = 1:tableSize(1)
                    thisRow = tab(i,:);
                    
                    nameString = thisRow{1,1};
                    
                    thisCustomFile = thisRow{1,2}{:};
                    if isempty(thisCustomFile)
                        fileNameString = 'No File';
                    else
                        fileNameString = char(thisCustomFile);
                    end
                    
                    thisFileLanguage = thisRow{1,3}{:};
                    if isempty(thisFileLanguage)
                        fileLanguageString = '-';
                    else
                        fileLanguageString = thisFileLanguage;
                    end
                    
                    thisFilePath = thisRow{1,4}{:};
                    if isempty(thisFilePath)
                        thisFilePath = 'pwd';
                    else
                        thisFilePath = char(thisFilePath);
                        if length(thisFilePath) > 10
                            thisFilePath = ['...' thisFilePath(end-10:end)];
                        end
                    end
                    newDisplayRow = {nameString, fileNameString, fileLanguageString, thisFilePath};
                    displayTable(i,:) = newDisplayRow;
                    
                end
            end

            disp(displayTable);
        end
        
        function fileStruct = toStruct(obj)
            % Convert the custom files class to a struct
            %
            % customFiles.toStruct()
            numberOfFiles = obj.rowCount;
            
            if numberOfFiles > 0
                filesList = cell(numberOfFiles, 1);
                for i = 1:numberOfFiles
                    thisRow = obj.varTable{i,:};
                    thisFile = thisRow{2};
                    thisType = thisRow{3};
                    thisPath = thisRow{4};
                    
                    if strcmpi(thisPath,'pwd')
                        thisPath = pwd;
                    end
                    filesList{i} = {thisFile, thisType, thisPath};
                end
                fileStruct.files = filesList;
            else
                fileStruct.files = {};
            end
        end

    end

    methods(Access = protected)

        function obj = setCustomLanguage(obj, row, language)
           % Check whether a specified language is supported, and set the
           % file entry if so.
           obj.varTable{row, 3} = {validateOption(language, 'supportedLanguages', obj.invalidLanguageMessage).value};
        end 
        
        function obj = setCustomName(obj, whichCustom, name) 
            % Check a potential new name is already
            % specified, and set it if not

            % Name must not be an existing name
            existingNames = obj.varTable{:,1};
            if any(strcmpi(name,existingNames))
                throw(duplicateName('Duplicate custom file names are not allowed'));
            end
            
            % Set the relevant name
            obj.varTable{whichCustom,1} = {name};
        end
        
        function obj = setFileName(obj,whichCustom,name)
            % Set a new filename
            obj.varTable{whichCustom,2} = {name};  
        end

    end
    
end
    
