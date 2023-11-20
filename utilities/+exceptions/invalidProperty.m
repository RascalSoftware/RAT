classdef invalidProperty < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:InvalidProperty';
    end
    methods
        function obj = invalidProperty(message)
            arguments
                message {mustBeTextScalar} = 'This property is not defined'
            end
            obj = obj@MException(exceptions.invalidProperty.errorID, message);
        end
    end
end