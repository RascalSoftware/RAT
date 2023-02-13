classdef invalidOption < MException
    methods
        function obj = invalidOption(message)
            arguments
                message {mustBeTextScalar} = "The given value is not supported"
            end
            obj = obj@MException('RAT:InvalidOption', message);
        end
    end
end