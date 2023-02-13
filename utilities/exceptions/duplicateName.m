classdef duplicateName < MException
    methods
        function obj = duplicateName(message)
            arguments
                message {mustBeTextScalar} = "The given name has already been used"
            end
            obj = obj@MException('RAT:DuplicateName', message);
        end
    end
end