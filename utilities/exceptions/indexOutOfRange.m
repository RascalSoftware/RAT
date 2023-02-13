classdef indexOutOfRange < MException
    methods
        function obj = indexOutOfRange(message)
            arguments
                message {mustBeTextScalar} = "The given index is out of range"
            end
            obj = obj@MException('RAT:IndexOutOfRange', message);
        end
    end
end