classdef notImplemented < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:notImplemented';
    end
    methods
        function obj = notImplemented(message)
            arguments
                message {mustBeTextScalar} = 'This functionality is not yet supported'
            end
            obj = obj@MException(exceptions.duplicateName.errorID, message);
        end
    end
end
