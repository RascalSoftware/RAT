classdef invalidInput < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:InvalidInput';
    end
    methods
        function obj = invalidInput(message)
            arguments
                message {mustBeTextScalar} = "The input to this routine is invalid"
            end
            obj = obj@MException(invalidInput.errorID, message);
        end
    end
end