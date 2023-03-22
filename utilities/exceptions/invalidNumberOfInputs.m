classdef invalidNumberOfInputs < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:InvalidNumberOfInputs';
    end
    methods
        function obj = invalidNumberOfInputs(message)
            arguments
                message {mustBeTextScalar} = 'Invalid number of inputs for this routine'
            end
            obj = obj@MException(invalidNumberOfInputs.errorID, message);
        end
    end
end