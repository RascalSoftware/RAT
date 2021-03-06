classdef standardParameters < matlab.mixin.CustomDisplay & handle
    
    properties 
        T = table;
        showPriors = false;
    end
    
    properties (Access = private)
        paramCount
        paramAutoNameCounter

    end
    
    methods 
        function obj = standardParameters()
            
            % Constructor
            sz = [1 8];
            varTypes = {'string','double','double','double','logical','string','double','double'};
            varNames = {'Name','Min','Value','Max','Fit?','Prior Type','mu','sigma'};
            obj.T = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
            obj.T(1,:) = {'Substrate Roughness',3 4 5,true,'Gaussian',0,Inf};
            obj.paramCount = 1;
            obj.paramAutoNameCounter = 1;
        end
        
        function obj = addParam(obj,varargin)
            
            if isempty(varargin)
                % No input parameter
                % Add an empty parameter row
                name = sprintf('new parameter %d',obj.paramAutoNameCounter);
                newRow = {name,0,0,0,false,'uniform',0,Inf};     
                appendNewRow(obj,newRow);
            end
                
            if iscell(varargin) && ~isempty(varargin)
                inputCell = varargin;
                
                % First input must be a parameter name
                if ~ischar(inputCell{1})
                    error('First value must be param name');
                end
                
                inputLength = length(varargin);
    
                switch inputLength
                    
                    % If length is 1, assume name only
                    % and fill in the rest with defaults
                    case 1
                        name = varargin{1};
                        newRow = {name,1,2,3,false,'uniform',0,Inf};
                        appendNewRow(obj,newRow);
                        
                    % If length is 2, assume name an value
                    % pair. Fill in the rest automatically
                    case 2
                        name = varargin{1};
                        value = varargin{2};
                        if ~isnumeric(value)
                            error('Expecting numberic value as param 2');
                        end
                        newRow = {name,value,value,value,false,'uniform',0,Inf};
                        appendNewRow(obj,newRow);
                        
                    % If length is 4, assume we are getting the
                    % limits as well as the values
                    case 4
                        name = varargin{1};
                        values = [varargin{2} varargin{3} varargin{4}];
                        if ~isnumeric(values)
                            error('Expecting numberic valus as params 2 - 4');
                        end
                        newRow = {name,values(1),values(2),values(3),false,'uniform',0,Inf};
                        appendNewRow(obj,newRow);
                        
                    % If length is 5, then assume we are setting
                    % everything except priors
                    case 5
                        name = varargin{1};
                        values = [varargin{2} varargin{3} varargin{4}];
                        fit = varargin{5};
                        if ~isnumeric(values)
                            error('Expecting numberic valus as params 2 - 4');
                        end
                        
                        if ~islogical(fit)
                            error('Expecting logical value for param 5')
                        end
                        newRow = {name,values(1),values(2),values(3),fit,'uniform',0,Inf};
                        appendNewRow(obj,newRow);
                    
                    % If not one of these options, throw an error    
                    otherwise
                        error('Unrecognised inputs to ''addrow''');
                end
            end
        end
        
        function obj = removeParam(obj,varargin)    
            if isempty(varargin)
                error('Need to specify a parameter');
            end
            
            for i = 1:length(varargin)
                thisInput =  varargin{i};
                removeRow(obj,thisInput); 
            end
        end
        
        function obj = setValue(obj,varargin)
            tab = obj.T;
            if length(varargin) ~= 2
                error('Need p (or name) / value pair to set');
            end
            
            if ischar(varargin{1})
                name = string(varargin{1});
                row = findRowIndex(name,tab);    
            else
                row = varargin{1};
            end
            
            if ~isnumeric(varargin{2})
                error('Value must be numeric');
            end
            value = varargin{2};
            tab(row,3) = {value};
            obj.T = tab;    
        end 
        
        function obj = setName(obj,varargin)
            tab = obj.T;
            if length(varargin) ~= 2
                error('Need p (or name) / value pair to set');
            end
            
            if ischar(varargin{1})
                name = string(varargin{1});
                row = findRowIndex(name,tab);    
            else
                row = varargin{1};
            end
            
            if ~ischar(varargin{2})
                error('Name must be char');
            end
            name = varargin{2};
            tab(row,1) = {name};
            obj.T = tab;
        end
        
        function obj = setConstr(obj, varargin)
            tab = obj.T;
            if length(varargin) ~= 3 
                error('Need p (or name) / min / max set');
            end
            
            min = varargin{2};
            max = varargin{3};
            if ~(isnumeric(min) && isnumeric(max))
                error('min and max need to be numeric');
            end
            
            if ischar(varargin{1})
                name = string(varargin{1});
                row = findRowIndex(name,tab);    
            else
                row = varargin{1};
            end
            
            tab(row,2) = {min};
            tab(row,4) = {max};
            obj.T = tab;
        end
       
        
        function obj = setFit(obj, varargin)
            
            tab = obj.T;
            if length(varargin) ~= 2 
                error('Need p (or name) / val pair set');
            end
            
            if ~islogical(varargin{2})
                error('Need true or false for Fit? value');
            end
            
            if ischar(varargin{1})
                name = string(varargin{1});
                row = findRowIndex(name,tab);    
            else
                row = varargin{1};
            end
            
            tab(row,5) = varargin(2);
            obj.T = tab;
        end
        
        function set.T(obj,table)
            obj.T = table;
        end
        
        function set.showPriors(obj,flag)
           if ~islogical(flag)
               error('Show priors must be true or false');
           end
               obj.showPriors = flag;
        end
    end
   
    
    methods (Access = protected)
        
        function appendNewRow(obj,row)
            tab = obj.T;
            newName = row{1};
            if any(strcmp(newName,tab{:,1}))
                error('Duplicate parameter names not allowed');
            end
            tab = [tab ; row];
            obj.T = tab;
            obj.paramCount = obj.paramCount + 1;
            obj.paramAutoNameCounter = obj.paramAutoNameCounter + 1;
        end
        
        function removeRow(obj, row)
           tab = obj.T;
           disp('debug');
           
           if ischar(row)
               % Assume a row name
               index = strcmp(row, tab{:,1});
               if isempty(index)
                   error('Unrecognised parameter name');
               end
               row = find(index);
           end
           
           numRows = size(tab,1);
           if row == numRows
               % Removing the last row
               newTab = tab(1:end-1,:);
               
           elseif row == 1
               % Cant remove protected substrate roughness
               %newTab = tab(2:end,:);
               error('Can''t remove protected parameter ''Substrate Roughness''');
               
           else
               % Removing a row somewhere in the centre
               tab1 = tab(1:row-1,:);
               tab2 = tab(row+1:end,:);
               newTab = [tab1 ; tab2];
           end
           
            obj.T = newTab;
            obj.paramCount = obj.paramCount - 1;
 
        end
        
        
        function displayScalarObject(obj)
            array = obj.T;
            p = [1:size(array,1)];
            p = p(:);
            p = table(p);
            
            if ~obj.showPriors
                array = array(:,1:5);
            end
            all = [p array];
            disp(all);
        end
 
    end  
end

function [row] = findRowIndex(name,tab)
    index = strcmp(name, tab{:,1});
    if isempty(index)
        error('Unrecognised parameter name');
    end
    row = find(index);
end
