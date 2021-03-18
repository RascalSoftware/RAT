classdef exampleClass < exampleClass1 & matlab.mixin.CustomDisplay
    
    properties
        myParameter1;
        myParameter2;
        myParameter3;
        myParameter4;
    end
    
    
    methods
        function obj = exampleClass()
           obj.myParameter1 = {{10 20 30} {1 2 3 ; 4 5 6}};
           obj.myParameter2 = 20;
           
           obj.myParameter3 = [1 2 3 4 5];
           obj.myParameter4 = [1 2 3];
             
        end
        
    end
    
    
    methods (Access = protected)
        function group = getPropertyGroup1(obj)
            masterPropList = struct('myParameter1',{obj.myParameter1},...
                'myParameter2', obj.myParameter2);
            if isscalar(obj)
                group = matlab.mixin.util.PropertyGroup(masterPropList);
            else
                group = getPropertyGroup1@matlab.mixin.CustomDisplay(obj);
            end
        end
        
        function group = getPropertyGroup2(obj)
            masterPropList = struct('myParameter3',{obj.myParameter3},...
                'myParameter4', obj.myParameter4);
            if isscalar(obj)
                group = matlab.mixin.util.PropertyGroup(masterPropList);
            else
                group = getPropertyGroup2@matlab.mixin.CustomDisplay(obj);
            end
        end
        
        
        function displayScalarObject(obj)
             startProps = getPropertyGroup1(obj);
             endProps = getPropertyGroup2(obj);
             
             matlab.mixin.CustomDisplay.displayPropertyGroups(obj,startProps);
             fprintf('    Parameters: \n');
             disp(obj.T);
             matlab.mixin.CustomDisplay.displayPropertyGroups(obj,endProps);
        end
        
        
        
    end
    
end
   
   
   
    
