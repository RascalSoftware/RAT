classdef customFileClass < handle
    
    % A container class for holding custom files for either
    % models, backgrounds or resolutions.

    properties
        fileTable = table;
    end

    properties (Access = private)
        autoFileNameCounter;
    end

    properties (Dependent, SetAccess = private)
        fileCount;
    end
    
    methods
        
        function obj = customFileClass(varargin)
            
            if ~isempty(varargin)
                startCell = varargin{:};
                nStartRows = 1;
            else
                startCell = [];
                nStartRows = 0;
            end
            
            sz = [nStartRows 4];
            varTypes = {'string','string','string','string'};
            varNames = {'Name','Filename','Language','path'};
            obj.fileTable = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            obj.autoFileNameCounter = 1;

            if ~isempty(startCell)
                obj.fileTable(1,:) = startCell;%{'Substrate Roughness',1 3 5,true,'uniform',0,Inf};
            end
            
        end

        function count = get.fileCount(obj)
            count = height(obj.fileTable);
        end

        function obj = addFile(obj,varargin)
            
            if isempty(varargin)
                
                % Nothing supplied - add empty data row
                nameVal = obj.autoFileNameCounter();
                newName = sprintf('New custom file %d', nameVal);
                
                newRow = {newName, "", "Octave", "pwd"};
                appendNewRow(obj,newRow);
            else
                
                inputs = varargin;
                
                % Check length of added data
                switch length(inputs)
                    
                    case 1
                        
                        % One input supplied - assume just name provided
                        newName = inputs{1};
                        if ~ischar(newName)
                            error('Single input is expected to be a custom object name');
                        end
                        
                        newRow = {newName,"","matlab","pwd"};
                        appendNewRow(obj,newRow);%,newUserDataRow);
                        
                    case 2
                        
                        % Two inputs suppled - assume both name and
                        % filename supplied;
                        newName = string(inputs{1});
                        newFile = string(inputs{2});
                        
                        
                        
                        newRow = {newName, newFile,"octave","pwd"};
                        appendNewRow(obj,newRow);% ,newUserDataRow);
                        
                    case 4
                        % Four inputs = assume all inputs supplied
                        newName = string(inputs{1});
                        newFile = string(inputs{2});
                        newLang = string(inputs{3});
                        newPath = string(inputs{4});
                        
                        newRow = {newName, newFile, newLang, newPath };
                        appendNewRow(obj,newRow);
                        
                    otherwise
                        
                        % Other length of inputs is not recognised
                        error('Unrecognised input into addData');
                        
                end
            end
            
        end
        
        function obj = setCustomFile(obj, varargin)
           
            % Set the value of an existing custom file object
            inputs = varargin{:};
            customNames = obj.fileTable{:,1};
            
            % Always need three or more inputs to set data value
            if length(inputs) < 3
                error('At least three inputs expected into ''setCustomFile''');
            end
                
            % First input needs to be a data number or name
            whichCustom = inputs{1};
            if isnumeric(whichCustom)
                if (whichCustom > obj.fileCount) || (whichCustom < 1)
                    error('Custom file object %d is not recognised', whichCustom);
                end
            elseif ischar(whichCustom)
                if ~strcmpi(whichCustom,customNames)
                    error('Data name %s not recognised', whichCustom);
                end
            end
            
            % Parse the remaining name value pairs to see what is 
            % being set and make sure the data is of the correct size
            % and type.
            toBeParsed = inputs(2:end);
            
           

            % Make an 'iputParser' object...
            p = inputParser;
            
%             % dataRange and simRange need to be [1 x 2] arrays
%             isDimsRanges = @(x)all(size(x) == [1,2]);
            
%             % Data needs to be an [n x >3] array
%             isDimsData = @(x) size(x,2) > 3;

            addParameter(p,'name','', @(x) isstring(x) || ischar(x))
            addParameter(p,'filename','', @(x) isstring(x) || ischar(x))
            addParameter(p,'language','', @(x) isstring(x) || ischar(x))
            addParameter(p,'path','', @(x) isstring(x) || ischar(x)) 
            parse(p,toBeParsed{:});
                
            results = p.Results;
            
            % Any fields in results that are not empty are being set,
            % so call the relevant set method for these (which will carry
            % out some additional checks)
            
            % Pass numeric identifyer for data into subfunctions
            if ~isnumeric(whichCustom)
                whichCustom = find(strcmpi(whichCustom,customNames));
            end
            
            if ~isempty(results.filename)
                obj.setFileName(whichCustom,results.filename);
            end
            
            if ~isempty(results.language)
                obj.setCustomLanguage(whichCustom,results.language);
            end
            
            if ~isempty(results.path)
                obj.setCustomPath(whichCustom,results.path);
            end
            
            if ~isempty(results.name)
                obj.setCustomName(whichCustom,results.name);
            end            

        end
        
%         function obj = setDataRange(obj,whichData,range)
%             
%             r = [range(1) range(2)];
%             obj.dataTable{whichData,3} = {range};
%         
%         end

        function obj = setCustomLanguage(obj,whichCustom,lang)
            
           if ~strcmpi(lang,{'octave','matlab','python','cpp'})
               error('Language must be octave, matlab,cpp or python');
           end
           
           obj.fileTable{whichCustom,3} = {lang};
           
        end
        
        
        function obj = setCustomName(obj,whichCustom,name)
            
            % Name must be a char and not an existing name
            if ~ischar(name)
                error('Name must be a string / character array');
            end
            
            existingNames = obj.getCustomNames;
            if strcmpi(name,existingNames)
                error('Duplicate custom names are not allowed');
            end
            
            % Set the relevant name
            obj.fileTable{whichCustom,1} = {name};
            
        end
        
        
        function obj = setFileName(obj,whichCustom,name)
            
            % Name must be a char and not an existing name
            if ~ischar(name)
                error('Filename must be a string / character array');
            end
           
            
            % Set the relevant file name
            obj.fileTable{whichCustom,2} = {name};
            
        end
        
        
        
        
        
        function names = getCustomNames(obj)
            
           names = obj.fileTable{:,1}; 
            
        end
        
        
        function displayCustomFileObject(obj)
            
            % Display the table object. 
            
            fprintf('    Custom Files: ------------------------------------------------------------------------------------------------------ \n\n');
            
            tab = obj.fileTable;
            
            sz = [1,4];
            displayVarTypes = {'string','string','string','string'}; 
            displayVarNames = {'Name','Filename','Language','Path'};
            displayTable = table('Size',sz,'VariableTypes',displayVarTypes,'VariableNames',displayVarNames);
            
            tableSize = size(tab);
            
            if tableSize(1) == 0
                displayTable(1,:) = {"","","",""};
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
            
            numberOfFiles = obj.fileCount;
            
            if numberOfFiles > 0
                for i = 1:numberOfFiles
                    thisRow = obj.fileTable{i,:};
                    thisFile = thisRow{2};
                    thisType = thisRow{3};
                    thisPath = thisRow{4};
                    
                    if strcmpi(thisPath,'pwd')
                        thisPath = pwd;
                    end
                    filesList{i,:} = {thisFile, thisType, thisPath};
                end
                fileStruct.files = filesList;
            else
                fileStruct.files = {};
            end
            
        end
        
        function obj = appendNewRow(obj,newRow)
            
            tab = obj.fileTable;
            newName = newRow{1};
            if any(strcmpi(newName,tab{:,1}))
                error('Duplicate custom file names not allowed');
            end
            
            % Carry out checks of Data type and ranges
            fileName = newRow{2};
            language = newRow{3};
            path = newRow{4};
                
            if ~isstring(fileName)
                error('filename must be a string');
            end
            
            if ~strcmpi(language,{'matlab','octave','python','cpp'})
                error('Custom file must be matlab, octave,cpp or python');
            end
            
            if ~isstring(path)
                error('Path mjst be a string');
            end

            row = {{newName}, {fileName}, {language}, {path}};
            tab = [tab ; row];
            obj.fileTable = tab;
            obj.autoFileNameCounter = obj.autoFileNameCounter + 1;
            
        end
        
    end
    
end

function inputBlock = parseDataInput(inputVals)

    defaultName = '';
    defaultData = [];
    defaultRange = [obj.defaultSimMin obj.defaultSimMax];
    defaultSimRange = [obj.defaultSimMin obj.defaultSimMax];

    p = inputParser;
    addParameter(p,'name', defaultName, @ischar);
    addParameter(p,'data', defaultData, @isnumeric);
    addParameter(p,'data range', defaultRange, @(a) validateattributes(a,{'double'},{'size',[1 2]}));
    addParameter(p,'sim range', defaultSimRange, @(a) validateattributes(a,{'double'},{'size',[1 2]}));

    parse(p,inputVals{:});
    inputBlock = p.Results;

end

    
