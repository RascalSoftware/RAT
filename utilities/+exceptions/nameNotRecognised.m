classdef nameNotRecognised < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:NameNotRecognised';
    end
    methods
        function obj = nameNotRecognised(message)
            arguments
                message {mustBeTextScalar} = 'The given name is not recognised'
            end
            obj = obj@MException(exceptions.nameNotRecognised.errorID, message);
        end
    end
end