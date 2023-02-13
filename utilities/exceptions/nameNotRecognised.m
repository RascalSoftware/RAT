classdef nameNotRecognised < MException
    methods
        function obj = nameNotRecognised(message)
            arguments
                message {mustBeTextScalar} = "The given name is not recognised"
            end
            obj = obj@MException('RAT:NameNotRecognised', message);
        end
    end
end