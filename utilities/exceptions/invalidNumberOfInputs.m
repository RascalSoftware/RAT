classdef invalidNumberOfInputs < MException
    methods
        function obj = invalidNumberOfInputs(message)
            arguments
                message {mustBeTextScalar} = "Invalid number of inputs for this routine"
            end
            obj = obj@MException('RAT:InvalidNumberOfInputs', message);
        end
    end
end