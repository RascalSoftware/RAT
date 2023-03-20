classdef exampleFail < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:exampleFail';
    end
    methods
        function obj = exampleFail(message)
            arguments
                message {mustBeTextScalar} = "Example failed during execution"
            end
            obj = obj@MException(exampleFail.errorID, message);
        end
    end
end