classdef unrecognizedR1Problem < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:unrecognizedR1Problem';
    end
    methods
        function obj = unrecognizedR1Problem(message)
            arguments
                message {mustBeTextScalar} = 'R1Problem does not have right format'
            end
            obj = obj@MException(unrecognizedR1Problem.errorID, message);
        end
    end
end