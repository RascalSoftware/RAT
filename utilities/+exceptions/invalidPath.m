classdef invalidPath < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:InvalidPath';
    end
    methods
        function obj = invalidPath(message)
            arguments
                message {mustBeTextScalar} = 'The given value is not a valid or existing path'
            end
            obj = obj@MException(exceptions.invalidPath.errorID, message);
        end
    end
end