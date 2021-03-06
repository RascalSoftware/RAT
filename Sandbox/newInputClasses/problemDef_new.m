classdef problemDef_new < standardParameters & handle & matlab.mixin.CustomDisplay
    
    properties
        name = 'testProblem';
        experimentType = 'standard';
        experimentGeometry = 'substrate/liquid';
    end
    
    methods
        function obj = problemDef_new()
            disp('debug');
            
        end
    end
    
    %Display Methods
    methods (Access = protected)
        
    end
end
