classdef notImplemented < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:NotImplemented';
    end
    methods
        function obj = notImplemented(message)
            arguments
                message {mustBeTextScalar} = 'This functionality is not yet supported'
            end
            obj = obj@MException(exceptions.notImplemented.errorID, message);
        end
    end
end
