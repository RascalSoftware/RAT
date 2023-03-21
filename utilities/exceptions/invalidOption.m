classdef invalidOption < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:InvalidOption';
    end
    methods
        function obj = invalidOption(message)
            arguments
                message {mustBeTextScalar} = 'The given value is not supported'
            end
            obj = obj@MException(invalidOption.errorID, message);
        end
    end
end