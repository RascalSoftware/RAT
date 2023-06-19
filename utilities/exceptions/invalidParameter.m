classdef invalidParameter < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:InvalidParameter';
    end
    methods
        function obj = invalidParameter(message)
            arguments
                message {mustBeTextScalar} = 'Incorrect parameter passed for selected procedure'
            end
            obj = obj@MException(invalidParameter.errorID, message);
        end
    end
end