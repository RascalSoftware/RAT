classdef invalidType < MException
    methods
        function obj = invalidType(message)
            arguments
                message {mustBeTextScalar} = "The given value is not a valid type for this variable"
            end
            obj = obj@MException('RAT:InvalidType', message);
        end
    end
end