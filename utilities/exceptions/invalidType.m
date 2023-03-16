classdef invalidType < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:InvalidType';
    end
    methods
        function obj = invalidType(message)
            arguments
                message {mustBeTextScalar} = 'The given value is not a valid type for this variable'
            end
            obj = obj@MException(invalidType.errorID, message);
        end
    end
end