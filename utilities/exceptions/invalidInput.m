classdef invalidInput < MException
    methods
        function obj = invalidInput(message)
            arguments
                message {mustBeTextScalar} = "The input to this routine is invalid"
            end
            obj = obj@MException('RAT:InvalidInput', message);
        end
    end
end