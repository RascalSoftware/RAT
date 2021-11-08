% A class to start, close and use matlab Engine for C


% The class has a constructor, a destructor and a method to start and close Matlab Engine


% The class has a method to execute a command in Matlab Engine


% The class has a method to execute a command in Matlab Engine and get the result


classdef MatlabEngine < handle
    properties
        engine
        isStarted
    end
    
    methods
        function obj = MatlabEngine()
            obj.engine = @matlabEngineCaller_customLayers;
            obj.isStarted = false;
        end
%         function startEngine(obj,params,contrast,funcName,funcPath,bulkIn,bulkOut)
%             contrast = -1;
%             [~,~]= obj.engine(params,contrast,funcName,funcPath,bulkIn,bulkOut);
%             obj.isStarted = true;  
%         end
        
        function startEngine(obj)
            if obj.isStarted
                obj.isStarted = true; 

            else
                [~,~]= obj.engine(0,-1,'dummy','matlabroot',0,0);
                obj.isStarted = true;               
            end
        end
        
        
        
        function closeEngine(obj)
            if obj.isStarted
                [~,~]=obj.engine(0,-2,'dummy','matlabroot',0,0);
                obj.isStarted = false;
            else
                obj.isStarted = false;
            end
      
        end
        
        function [output,sRough]= execute(obj, params,contrast,funcName,funcPath,bulkIn,bulkOut)
            if obj.isStarted
                [output,sRough] = obj.engine(params,contrast,funcName,funcPath,bulkIn,bulkOut);
            else
                error('Matlab Engine is not started');
            end
        end
        

    end
end



        % if we want this explicityly
        %function start(obj)
        %    if ~obj.isStarted
        %        obj.engine = matlab.engine.EngOpens();
        %        obj.isStarted = true;
        %    end
        %end