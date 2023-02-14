classdef customFileClass < handle
    
    % A container class for holding custom files for either
    % models, backgrounds or resolutions.

    properties
        fileTable = table
    end

    properties(Access = private, Constant, Hidden)
        duplicateNameMessage = "Duplicate custom file names are not allowed"
        invalidLanguageMessage = "Language must be: matlab, python, or cpp"
    end

    properties(Access = private, Constant)
        supportedLanguages = {'matlab', 'python', 'cpp'}
    end

    properties (Access = private)
        autoFileNameCounter
    end

    properties (Dependent, SetAccess = private)
        fileCount
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
            obj.fileTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            obj.autoFileNameCounter = 1;

            if ~isempty(varargin)
                obj.addCustomFile(varargin{:});
            end          
        end

        function count = get.fileCount(obj)
            count = height(obj.fileTable);
        end

        function obj = addCustomFile(obj,varargin)
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
                nameVal = obj.autoFileNameCounter();
                newName = sprintf('New custom file %d', nameVal);
                
                newRow = {newName, "", "matlab", "pwd"};
                appendNewRow(obj,newRow);

            else
                
                inputs = varargin{:};

                % Check length of added data
                switch length(inputs)
                    
                    case 1

                        % One input supplied - assume just name provided
                        newName = inputs{1};
                        if ~ischar(newName)
                            throw(invalidType('Single input is expected to be a custom object name'));
                        end
                        
                        newRow = {newName,"","matlab","pwd"};
                        appendNewRow(obj,newRow);
                        
                    case 2

                        % Two inputs suppled - assume both name and
                        % filename supplied;
                        newName = string(inputs{1});
                        newFile = string(inputs{2});

                        newRow = {newName,newFile,"matlab","pwd"};
                        appendNewRow(obj,newRow);
                        
                    case 4

                        % Four inputs = assume all inputs supplied
                        newName = string(inputs{1});
                        newFile = string(inputs{2});
                        newLang = string(inputs{3});
                        newPath = string(inputs{4});
                        
                        newRow = {newName, newFile, newLang, newPath};
                        appendNewRow(obj,newRow);
                        
                    otherwise

                        % Other length of inputs is not recognised
                        throw(invalidNumberOfInputs('Unrecognised input into addCustomFile'));
                        
                end
            end
            
        end
        
        function obj = setCustomFile(obj, varargin)
            % Change the value of a given parameter in the file table.
            % The expected inputs are the row of the file entry of
            % interest (given either by name of index), and key-value pairs
            % of the parameter(s) to change. The values of the keys are:
            % "Name", "Filename", "Language", and "Path".
            % NOTE changing the path using this routine is not implemented
            %
            % customFiles.setcustomFile(1, "Name", "New Name",...
            %                           "Language", "Octave")
            inputs = varargin{:};
            customNames = obj.getCustomNames;
            
            % Always need three or more inputs to set data value
            if length(inputs) < 3
                throw(invalidNumberOfInputs('At least three inputs expected into ''setCustomFile'''));
            end
                
            % First input needs to be a data number or name
            whichCustom = inputs{1};
            if isnumeric(whichCustom)
                if (whichCustom > obj.fileCount) || (whichCustom < 1)
                    throw(indexOutOfRange(sprintf('The index %d is not within the range 1 - %d', whichCustom, obj.fileCount)));
                end
            elseif ischar(whichCustom)
                if ~strcmpi(whichCustom,customNames)
                    throw(nameNotRecognised(sprintf('Custom file object name %s not recognised', whichCustom)));
                else
                    whichCustom = find(strcmpi(whichCustom,customNames));
                end
            end
            
            % Parse the remaining name value pairs to see what is 
            % being set and make sure the data is of the correct size
            % and type.
            toBeParsed = inputs(2:end);

            % Make an 'inputParser' object...
            p = inputParser;

            addParameter(p,'name','', @(x) isstring(x) || ischar(x))
            addParameter(p,'filename','', @(x) isstring(x) || ischar(x))
            addParameter(p,'language','', @(x) isstring(x) || ischar(x))
            addParameter(p,'path','', @(x) isstring(x) || ischar(x)) 
            parse(p,toBeParsed{:});
                
            results = p.Results;
            
            % Any fields in results that are not empty are being set,
            % so call the relevant set method for these (which will carry
            % out some additional checks)
            if ~isempty(results.filename)
                obj.setFileName(whichCustom,results.filename);
            end
            
            if ~isempty(results.language)
                obj.setCustomLanguage(whichCustom,results.language);
            end
            
            if ~isempty(results.path)
                % NOT IMPLEMENTED
                obj.setCustomPath(whichCustom,results.path);
            end
            
            if ~isempty(results.name)
                obj.setCustomName(whichCustom,results.name);
            end            

        end

        function removeCustomFile(obj, row)
            % Removes a file entry from the file table. The expected input
            % is an integer or array of integers, i.e., an input such as
            % [1 3] leads to multiple rows being removed from the table
            %
            % customFiles.removeCustomFile(2)
            tab = obj.fileTable;
            tab(row,:) = [];
            obj.fileTable = tab;
        end

        function names = getCustomNames(obj)
            % Get a string array of the names of each of the custom file
            % objects defined in the class.
            %
            % customFiles.getLayersNames()
            names = obj.fileTable{:,1};  
        end

        function displayCustomFileObject(obj)
            % Display the file table.
            %
            % customFiles.displayCustomFileObject()            
            fprintf('    Custom Files: ------------------------------------------------------------------------------------------------------ \n\n');
            
            tab = obj.fileTable;
            
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
                        fileNameString = "No File";
                    else
                        fileNameString = string(thisCustomFile);
                    end
                    
                    thisFileLanguage = thisRow{1,3}{:};
                    if isempty(thisFileLanguage)
                        fileLanguageString = "-";
                    else
                        fileLanguageString = thisFileLanguage;
                    end
                    
                    thisFilePath = thisRow{1,4}{:};
                    if isempty(thisFilePath)
                        filePathString = "pwd";
                    else
                        thisFilePath = char(thisFilePath);
                        if length(thisFilePath) > 10
                            thisFilePath = ['...' thisFilePath(end-10:end)];
                        end
                        filePathString = string(thisFilePath);
                    end
                    
                    newDisplayRow = {nameString, fileNameString, fileLanguageString, filePathString};
                    displayTable(i,:) = newDisplayRow;
                    
                end
            end

            disp(displayTable);
            fprintf('\n');
 
        end
        
        function fileStruct = toStruct(obj)
            % Convert the custom files class to a struct
            %
            % customFiles.toStruct()
            numberOfFiles = obj.fileCount;
            
            if numberOfFiles > 0
                filesList = cell(numberOfFiles, 1);
                for i = 1:numberOfFiles
                    thisRow = obj.fileTable{i,:};
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

        function obj = appendNewRow(obj,newRow)
            % Appends a row to the layers table. The expected input is
            % a length four cell array.
            %
            % customFiles.appendNewRow({'New Row','file.m','matlab','pwd'});
            tab = obj.fileTable;
            newName = newRow{1};
            if any(strcmpi(newName,tab{:,1}))
                throw(duplicateName(obj.duplicateNameMessage));
            end
            
            % Carry out checks of Data type and ranges
            fileName = newRow{2};
            language = newRow{3};
            path = newRow{4};

            if ~strcmpi(language, obj.supportedLanguages)
                throw(invalidOption(obj.invalidLanguageMessage));
            end

            row = {newName, fileName, language, path};
            tab = [tab ; row];
            obj.fileTable = tab;
            obj.autoFileNameCounter = obj.autoFileNameCounter + 1;
            
        end

        function obj = setCustomLanguage(obj,whichCustom,lang)
           % Check whether a specified language is supported, and set the
           % file entry if so.
           if ~strcmpi(lang, obj.supportedLanguages)
               throw(invalidOption(obj.invalidLanguageMessage));
           end
           
           obj.fileTable{whichCustom,3} = {lang};
        end
        
        
        function obj = setCustomName(obj,whichCustom,name) 
            % Check a potential new name is already
            % specified, and set it if not

            % Name must not be an existing name
            existingNames = obj.fileTable{:,1};
            if any(strcmpi(name,existingNames))
                throw(duplicateName(obj.duplicateNameMessage));
            end
            
            % Set the relevant name
            obj.fileTable{whichCustom,1} = {name};
        end
        
        
        function obj = setFileName(obj,whichCustom,name)
            % Set a new filename
            obj.fileTable{whichCustom,2} = {name};  
        end

    end
    
end
    
