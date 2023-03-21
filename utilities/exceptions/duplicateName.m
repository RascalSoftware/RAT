classdef duplicateName < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:DuplicateName';
    end
    methods
        function obj = duplicateName(message)
            arguments
                message {mustBeTextScalar} = 'The given name has already been used'
            end
            obj = obj@MException(duplicateName.errorID, message);
        end
    end
end