% ``customFileClass`` manages the custom files for the project. It provides methods to add, update and remove custom files.
% Each custom file is stored as a row in a table and consists of a name, the filename of the custom file, the language of the 
% file, the path where the file is located, and the name of the function in the file to call.
%
% Examples
% --------
% If no arguments are provided, the object is created with an empty table.
% 
% >>> file = customFileClass();
% 
% Otherwise, the arguments are used to create the first custom file.
% 
% >>> file = customFileClass('custom file 1', 'customBilayer.m', 'matlab');
%
% Parameters
% ----------
% name : string or char array, default: ''
%     The name of this custom file object.
% filename : string or char array, default: ''
%     The name of the file containing the custom function.
% language : supportedLanguages, default: supportedLanguages.Matlab
%     What language the custom function is written in: 'matlab', 'python', or 'cpp' (via a dynamic library) 
% path : string or char array, default: ''
%     The path to the custom file.
% functionName : string or char array, default: ''
%     The name of the custom function within the file.
%
% Attributes
% ----------
% varTable : table
%     A table object that contains the custom file entries entries.

classdef customFileClass < tableUtilities
   properties (SetAccess = private, Hidden = true)
        wrappers = {}
        canShowWarning = false; % ensures conflict warning only shows once if no change occurs
   end

    properties(Access = private, Constant, Hidden)
        invalidLanguageMessage = sprintf('Language must be a supportedLanguages enum or one of the following strings (%s)', ...
                                         strjoin(supportedLanguages.values(), ', ')) 
         
    end
    
    methods
        
        function obj = customFileClass(name, filename, language, path, functionName)
            arguments
                name {mustBeTextScalar} = ''
                filename {mustBeTextScalar} = ''
                language  = supportedLanguages.Matlab
                path {mustBeTextScalar} = ''
                functionName {mustBeTextScalar} = '' 
            end         
            sz = [0 5];
            varTypes = {'string','string','string','string','string'};
            varNames = {'Name','Filename','Function Name','Language','Path'};
            obj.varTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);

            if ~isempty(name)
                obj.addCustomFile(name, filename, language, path, functionName);
            end          
        end

        function obj = addCustomFile(obj, name, filename, language, path, functionName)
            % Adds a new custom file to the file table. For MATLAB, the provided file must 
            % be in the matlab path when running.
            % 
            % Examples
            % --------
            % To add a new custom file entry with name only.
            % 
            % >>> file.addCustomFile('custom file 1');
            % 
            % To add custom file with name, and filename.
            % 
            % >>> file.addCustomFile('custom file 1', 'customBilayer.m');
            % 
            % To add a Python custom files.
            % 
            % >>> file.addCustomFile('custom file 1', 'customBilayer.py', 'python', 'C:/stuff', 'custom_bilayer);
            % 
            % Parameters
            % ----------
            % name : string or char array, default: auto-generated name
            %     The name of this custom file object.
            % filename : string or char array, default: ''
            %     The name of the file containing the custom function.
            % language : supportedLanguages, default: supportedLanguages.Matlab
            %     What language the custom function is written in: 'matlab', 'python', or 'cpp' (via a dynamic library) 
            % path : string or char array, default: ''
            %     The path to the custom file.
            % functionName : string or char array, default: ''
            %     The name of the custom function within the file.
            arguments
                obj
                name {mustBeTextScalar} = ''
                filename {mustBeTextScalar} = ''
                language  = supportedLanguages.Matlab
                path {mustBeTextScalar} = ''
                functionName {mustBeTextScalar} = '' 
            end
            newName = name;
            newFile = filename;
            newLang = language;
            newPath = path;
            newFunc = functionName;
            
            if isempty(name)
                % Nothing supplied - add empty data row
                nameVal = obj.autoNameCounter();
                newName = sprintf('New custom file %d', nameVal);
            end

            % Check language is valid, then add the new entry
            newLang = validateOption(newLang, 'supportedLanguages', obj.invalidLanguageMessage).value;
            newFile = obj.addFileExtension(newFile, newLang);
            newFunc = obj.validateFunctionName(newFile, newFunc, newLang);           
            obj.addRow(newName, newFile, newFunc, newLang, obj.validatePath(newPath));
            obj.canShowWarning = true;
        end

        function obj = removeCustomFile(obj, row)
            % Removes a given custom file from the table.
            %
            % Examples
            % --------
            % To remove the second custom file in the table (custom file in row 2).  
            % 
            % >>> file.removeCustomFile(2);
            % 
            % To remove custom file with a specific name.
            % 
            % >>> file.removeCustomFile('custom file 1');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the custom file to remove. If it is text, 
            %     it is the name of the custom file to remove.
            obj.removeRow(row);
        end

        function obj = setCustomFile(obj, row, options)
            % General purpose method for updating properties of an existing custom file.
            %
            % Examples
            % --------
            % To change the name and filename of the second custom file in the table (custom file in row 2).
            % 
            % >>> file.setCustomFile(2, name='custom file 1', filename='customFunction.m');
            % 
            % To change the properties of a custom file called 'custom file 1'.
            % 
            % >>> file.setCustomFile('custom file 1', name='new custom file', filename='customFunction.py', language='python');
            % 
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the custom file to update. If it is text, 
            %     it is the name of the custom file to update.
            % options
            %    Keyword/value pair to properties to update for the specific custom file.
            %       * name (char array or string, default: '') the new name of the custom file.
            %       * filename (char array or string, default: '') the new filename of the custom file.
            %       * language (supportedLanguages, default: supportedLanguages.empty()) the new language of the custom file.
            %       * path (char array or string, default: '') the new path of the custom file.
            %       * functionName (char array or string, default: ') the new function name of the custom file.
            arguments
                obj
                row
                options.name {mustBeTextScalar} = ''
                options.filename {mustBeTextScalar} = ''
                options.language = supportedLanguages.empty()
                options.path {mustBeTextScalar} = ''
                options.functionName {mustBeTextScalar} = '' 
            end            
                           
            % First input needs to be a data number or name
            row = obj.getValidRow(row);
            
            if isempty(options.name)
                options.name = obj.varTable{row, 1}{:};
            end
            
            if isempty(options.filename)
                options.filename = obj.varTable{row, 2}{:};
            end
            
            if isempty(options.language)
                options.language = obj.varTable{row, 4}{:};
            end
            
            if isempty(options.path)
                options.path = obj.varTable{row, 5}{:};
            end

            if isempty(options.functionName)
                options.functionName = obj.varTable{row, 3}{:};
            end
            options.language = validateOption(options.language, 'supportedLanguages', obj.invalidLanguageMessage).value;
            obj.setName(row, options.name); 
            obj.varTable{row, 2} = {obj.addFileExtension(options.filename, options.language)};
            obj.varTable{row, 4} = {options.language};
            obj.varTable{row, 5} = {obj.validatePath(options.path)};
            obj.varTable{row, 3} = {obj.validateFunctionName(options.filename, options.functionName, options.language)};
            obj.canShowWarning = true;
        end

        function displayTable(obj)
            % Prints the custom file table to the console.
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
            % Converts the customFileClass into a structure array.
            %
            % Returns
            % -------
            % fileStruct : struct
            %     A struct which contains the properties for all the custom files.
            fileStruct.files = cell(1, 0);
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
                        elseif ~isempty(thisPath) && ~strcmp(foundPath, libpath) && isfile(libpath) && obj.canShowWarning  
                            % This warning should only show if there is a difference between the specified custom file and
                            % the file on the search path. If the specified file does not exist the one found in the search path will 
                            % be used with no warning.  
                            msg = ['The Matlab custom file (%s) on the search path does not match the specified path (%s). ' ...
                                   'The file on the search path will be used, if this is expected ignore this warning, ' ...
                                   'otherwise set the current directory to the directory with the desired file i.e. ' ...
                                   'cd("%s")'];
                            warning(msg, strrep(foundPath, '\', '/'), strrep(libpath, '\', '/'), strrep(what(thisPath).path, '\', '/'));
                            obj.canShowWarning = false;
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
    
    methods(Hidden)
        function delete(obj)
            % Destroys the wrappers
            for i=1:length(obj.wrappers) 
                delete(obj.wrappers{i});
            end
            obj.wrappers = {};
        end
    end

    methods(Access = protected)
        function obj = setName(obj, row, name) 
            % Sets the name of an existing custom file entry.
            % 
            % Examples
            % --------
            % To change the name of the second custom file in the table (custom file in row 2)
            % 
            % >>> file.setName(2, 'custom file 1');
            % 
            % To change the name of a custom file called 'custom file 1' to 'new custom file'
            % 
            % >>> file.setName('custom file 1', 'new custom file');
            %
            % Parameters
            % ----------
            % row : string or char array or whole number
            %     If ``row`` is an integer, it is the row number of the custom file to update. If it is text, 
            %     it is the name of the custom file to update.
            % name : string or char array
            %     The new name of the custom file.

            % Name must not be an existing name
            existingNames = obj.varTable{:,1};
            existingNames(row) = [];
            if any(strcmpi(name,existingNames))
                throw(exceptions.duplicateName('Duplicate custom file names are not allowed'));
            end
            
            % Set the relevant name
            obj.varTable{row, 1} = {name};
        end
    end

    methods(Access = private)
        function path = validatePath(~, path)
            % Validates custom file path exists.
            %
            % Parameters
            % ----------
            % path : string or char array
            %     The file path of a custom file entry.
            %
            % Returns
            % -------
            % path : string or char array
            %     The file path of a custom file entry.
            if ~isempty(path) && ~exist(path, 'dir')
                throw(exceptions.invalidPath(sprintf('The given path (%s) is not a valid directory', path)));
            end
        end
        
        function filename = addFileExtension(~, filename, language)
            % Adds a file extension to the matlab and python filename if it is missing.
            %
            % Examples
            % --------
            % This will add the extension '.py' to the filename 'file'
            % 
            % >>> fileWithExt = obj.addFileExtension('file', 'python')
            % 
            % Parameters
            % ----------
            % filename : string or char array
            %     The filename of a custom file entry with or without extension.
            % language : string or char array
            %     The file language of a custom file entry.
            % 
            % Returns
            % -------
            % filename : string or char array
            %     The custom filename with extension.
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

        function newFunctionName = validateFunctionName(~, filename, functionName, language)
            % Validates a function name is the same as filename for matlab
            % functions if a function name is provided.
            %
            % Examples
            % --------
            % The snippet below will raise a warning as the function name "results" does not match "file.m".
            %  
            % >>> functionName = obj.validateFunctionName('file.m', 'results', 'matlab')
            % 
            % The snippet below will return "file" as the function name.
            %  
            % >>> functionName = obj.validateFunctionName('file.m', '', 'matlab')            
            % 
            % Parameters
            % ----------
            % filename : string or char array
            %     The filename of a custom file entry.
            % functionName : string or char array
            %     The function name of a custom file entry.
            % language : string or char array
            %     The language of a custom file entry. 
            % 
            % Returns
            % -------
            % newFunctionName : string or char array
            %     The valid function name for the given filename.
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
    
