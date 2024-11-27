classdef customFileClass < tableUtilities
    
    % A container class for holding custom files for either
    % models, backgrounds or resolutions.
   properties (SetAccess = private, Hidden = true)
        wrappers = {}
   end

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
            sz = [0 5];
            varTypes = {'string','string','string','string','string'};
            varNames = {'Name','Filename','Function Name','Language','Path'};
            obj.varTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);

            if ~isempty(varargin)
                obj.addCustomFile(varargin{:});
            end          
        end

        function delete(obj)
            % Destroys the wrappers
            for i=1:length(obj.wrappers) 
                delete(obj.wrappers{i});
            end
            obj.wrappers = {};
        end

        function obj = addCustomFile(obj, varargin)
            % Add an entry to the file table.
            % A custom file entry can be added with no parameters, just the
            % name of the custom file entry, the name of the entry
            % alongside a filename, or can be fully defined by specifying
            % the name of the custom file entry, filename, language, 
            % file path, and function name. For MATLAB, the provided path must 
            % be in the matlab path
            %
            % customFiles.addCustomFile()
            % customFiles.addCustomFile('New Row')
            % customFiles.addCustomFile('New Row', 'file.m')
            % customFiles.addCustomFile('New Row', 'file.m', 'matlab')
            % customFiles.addCustomFile('New Row', 'file.py', 'python', 'C:/stuff')
            % customFiles.addCustomFile('New Row', 'file.py', 'python', 'C:/stuff', 'py_function')
            newFile = '';
            newLang = supportedLanguages.Matlab.value;
            newPath = '';
            newFunc = '';
            if isempty(varargin)
                % Nothing supplied - add empty data row
                nameVal = obj.autoNameCounter();
                newName = sprintf('New custom file %d', nameVal);
            else
                inputs = varargin;
                newName = inputs{1};
                
                if ~isText(newName)
                    throw(exceptions.invalidType('First value must be unique name identifer (text)'));
                end
                % Check length of added data
                switch length(inputs)
                    case 1   
                    case 2
                    
                        % Two inputs suppled - assume both name and filename supplied;
                        newName = inputs{1};
                        newFile = inputs{2};
                    
                    case 3

                        % Three inputs - assume all inputs except function name and path supplied
                        newName = inputs{1};
                        newFile = inputs{2};
                        newLang = inputs{3};
                        
                    case 4

                        % Four inputs - assume all inputs except function name supplied
                        newName = inputs{1};
                        newFile = inputs{2};
                        newLang = inputs{3};
                        newPath = inputs{4};

                    case 5

                        % Five inputs - assume all inputs supplied
                        newName = inputs{1};
                        newFile = inputs{2};
                        newLang = inputs{3};
                        newPath = inputs{4};
                        newFunc = inputs{5};
                        
                    otherwise

                        % Other length of inputs is not recognised
                        throw(exceptions.invalidNumberOfInputs('Unrecognised input into addCustomFile'));
                        
                end
            end

            if ~isText(newFile)
                throw(exceptions.invalidType('Second argument (Filename) must be text.'));
            end

            if ~isText(newPath)
                throw(exceptions.invalidType('Forth argument (Path) must be text.'));
            end

            if ~isText(newFunc)
                throw(exceptions.invalidType('Fifth argument (Function name) must be text.'));
            end

            % Check language is valid, then add the new entry
            newLang = validateOption(newLang, 'supportedLanguages', obj.invalidLanguageMessage).value;
            newFile = obj.addFileExtension(newFile, newLang);
            newFunc = obj.validateFunctionName(newFile, newFunc, newLang);           
            obj.addRow(newName, newFile, newFunc, newLang, obj.validatePath(newPath));            
        end
        
        function obj = setCustomFile(obj, row, varargin)
            % Change the value of a given parameter in the file table.
            % The expected inputs are the row of the file entry of
            % interest (given either by name of index), and key-value pairs
            % of the parameter(s) to change. The values of the keys are:
            % "Name", "Filename", "Language", "Path" and "functionName" if 
            % applicable.
            %
            % customFiles.setcustomFile(1, 'Name', 'New Name',...
            %                           'Language', 'Octave')
            customNames = obj.getNames;
            
            % Always need three or more inputs to set data value
            if length(varargin) < 2 || mod(length(varargin), 2) ~= 0
                throw(exceptions.invalidNumberOfInputs('The input to ''setCustomFile'' should be a file entry and a set of name-value pairs'));
            end
                
            % First input needs to be a data number or name
            if isnumeric(row)
                if (row > obj.rowCount) || (row < 1)
                    throw(exceptions.indexOutOfRange(sprintf('The index %d is not within the range 1 - %d', row, obj.rowCount)));
                end
            elseif isText(row)
                row = obj.findRowIndex(row, customNames, sprintf('Custom file object name %s not recognised', row));
            end
            
            % Parse the name value pairs to see what is being set and make
            % sure the data is of the correct size and type.

            % Make an 'inputParser' object...
            p = inputParser;
            addParameter(p, 'name', obj.varTable{row, 1}{:}, @isText)
            addParameter(p, 'filename', obj.varTable{row, 2}{:}, @isText)
            addParameter(p, 'functionName', obj.varTable{row, 3}{:}, @isText)
            addParameter(p, 'language', obj.varTable{row, 4}{:}, @(x) isText(x) || isenum(x))
            addParameter(p, 'path', obj.varTable{row, 5}{:}, @isText) 
            parse(p, varargin{:});
                
            results = p.Results;
            results.language = validateOption(results.language, 'supportedLanguages', obj.invalidLanguageMessage).value;
            obj.setCustomName(row, results.name); 
            obj.varTable{row, 2} = {obj.addFileExtension(results.filename, results.language)};
            obj.varTable{row, 4} = {results.language};
            obj.varTable{row, 5} = {obj.validatePath(results.path)};
            obj.varTable{row, 3} = {obj.validateFunctionName(results.filename, results.functionName, results.language)};
        end

        function displayTable(obj)
            % Display the file table.
            %
            % customFiles.displayCustomFileObject()
            sz = [1,5];
            displayVarTypes = {'string','string','string','string','string'}; 
            displayVarNames = {'Name','Filename','Function Name','Language','Path'};
            displayTable = table('Size',sz,'VariableTypes',displayVarTypes,'VariableNames',displayVarNames);
            
            tableSize = size(obj.varTable);
            
            if tableSize(1) == 0
                displayTable(1,:) = {'','','','',''};
            else
                
                for i = 1:tableSize(1)
                    nameString = obj.varTable{i,1};
                    
                    thisCustomFile = obj.varTable{i,2}{:};
                    if isempty(thisCustomFile)
                        fileNameString = 'No File';
                    else
                        fileNameString = char(thisCustomFile);
                    end

                    thisFunctionName = obj.varTable{i,3}{:};
                    thisFileLanguage = obj.varTable{i,4}{:};
                    if isempty(thisFunctionName) || strcmp(thisFileLanguage, supportedLanguages.Matlab.value)
                        functionNameString = '-';
                    else
                        functionNameString = thisFunctionName;
                    end

                    
                    if isempty(thisFileLanguage)
                        fileLanguageString = '-';
                    else
                        fileLanguageString = thisFileLanguage;
                    end
                    
                    thisFilePath = obj.varTable{1,5}{:};
                    if isempty(thisFilePath)
                        thisFilePath = 'pwd';
                    else
                        thisFilePath = char(thisFilePath);
                        if length(thisFilePath) > 50
                            thisFilePath = ['...' thisFilePath(end-50:end)];
                        end
                    end
                    newDisplayRow = {nameString, fileNameString, functionNameString, fileLanguageString, thisFilePath};
                    displayTable(i,:) = newDisplayRow;
                    
                end
            end

            disp(displayTable);
        end
        
        function fileStruct = toStruct(obj)
            % Convert the custom files class to a struct
            %
            % customFiles.toStruct()
            fileStruct.files = {};
            fileStruct.fileIdentifiers = {};
            numberOfFiles = obj.rowCount;      
            if numberOfFiles > 0
                filesList = cell(numberOfFiles, 1);
                for i = 1:numberOfFiles
                    thisRow = obj.varTable{i,:};
                    thisFile = thisRow{2};
                    functionName = thisRow{3};
                    thisType = thisRow{4};
                    thisPath = thisRow{5};
                    if isempty(thisPath)
                        thisPath = pwd;
                    end
            
                    libpath = fullfile(what(thisPath).path, thisFile);
                    if strcmpi(thisType, supportedLanguages.Matlab.value)
                        foundPath = which(functionName);
                        if isempty(foundPath)
                            msg = 'The Matlab custom file (%s) is not on the search path. Add the file to path and check using "which(%s)".';
                            throw(exceptions.invalidPath(sprintf(msg, strrep(libpath, '\', '/'), functionName)));
                        elseif ~isempty(thisPath) && ~strcmp(foundPath, libpath)                        
                            msg = 'The Matlab custom file (%s) on the search path does not match the given path (%s).';
                            throw(exceptions.invalidPath(sprintf(msg, strrep(foundPath, '\', '/'), strrep(libpath, '\', '/'))));
                        end
                    else
                        if ~exist(libpath, 'file')
                            msg = 'The custom file (%s) cannot be found. Check that the path and filename is correct (%s).';
                            throw(exceptions.invalidPath(sprintf(msg, thisFile, strrep(libpath, '\', '/'))));
                        end
                    end
                    wrapper = [];
                    if i <= length(obj.wrappers)
                        wrapper = obj.wrappers{i};                        
                    end
                    if isempty(wrapper) || ~strcmp(wrapper.libPath, libpath) || ~strcmp(wrapper.functionName, functionName)
                        if strcmpi(thisType, supportedLanguages.Python.value)
                            wrapper = pythonWrapper(libpath, functionName);
                            thisFile = wrapper.getHandle();
                        elseif strcmpi(thisType, supportedLanguages.Cpp.value)
                            wrapper = dyLibWrapper(libpath, functionName);
                            thisFile = wrapper.getHandle();
                        end
                        obj.wrappers{i} = wrapper;
                    else
                        thisFile = wrapper.getHandle();
                    end
                    [~, handle, ~] = fileparts(thisFile);
                    filesList{i} = handle;
                end
                fileStruct.files = filesList;
                fileStruct.fileIdentifiers = obj.varTable{:, 1};
            end
        end

    end

    methods(Access = protected)
        function obj = setCustomName(obj, whichCustom, name) 
            % Check a potential new name is already
            % specified, and set it if not

            % Name must not be an existing name
            existingNames = obj.varTable{:,1};
            existingNames(whichCustom) = [];
            if any(strcmpi(name,existingNames))
                throw(exceptions.duplicateName('Duplicate custom file names are not allowed'));
            end
            
            % Set the relevant name
            obj.varTable{whichCustom,1} = {name};
        end
    end

    methods(Static)
        function path = validatePath(path)
            % Validate a new path exists
            if ~isempty(path) && ~exist(path, 'dir')
                throw(exceptions.invalidPath(sprintf('The given path (%s) is not a valid directory', path)));
            end
        end
        
        function filename = addFileExtension(filename, language)
            % Adds a file extension to the matlab and python filename if it is
            % missing.
            %
            % fileWithExt = obj.addFileExtension('file', 'python')
            if isempty(filename)
                return
            end
            
            [~, ~, ext] = fileparts(filename);
            if isempty(ext)
                if strcmp(language, supportedLanguages.Matlab.value)
                    filename = [filename, '.m'];
                elseif strcmp(language, supportedLanguages.Python.value)
                    filename = [filename, '.py'];
                end
            end
        end

        function newFunctionName = validateFunctionName(filename, functionName, language)
            % Validates a function name is the same as filename for matlab
            % functions if a function name is provided.
            %
            % funcName = obj.validateFunctionName('file.m', 'results', 'matlab')
            [~, newFunctionName, ~] = fileparts(filename);
            if ~isempty(functionName) 
                if strcmp(language, supportedLanguages.Matlab.value)
                    if ~strcmp(functionName, newFunctionName)        
                        warning('For Matlab custom functions, the function Name must be the same as filename without .m extension.');
                    end
                else
                    newFunctionName = functionName;
                end 
            end
        end
    end
    
end
    
