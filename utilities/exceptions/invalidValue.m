classdef invalidValue < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:InvalidValue';
    end
    methods
        function obj = invalidValue(message)
            arguments
                message {mustBeTextScalar} = 'The input has a correct type but an incorrect value'
            end
            obj = obj@MException(invalidValue.errorID, message);
        end
    end
end