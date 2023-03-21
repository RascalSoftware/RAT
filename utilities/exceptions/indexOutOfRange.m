classdef indexOutOfRange < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:IndexOutOfRange';
    end
    methods
        function obj = indexOutOfRange(message)
            arguments
                message {mustBeTextScalar} = 'The given index is out of range'
            end
            obj = obj@MException(indexOutOfRange.errorID, message);
        end
    end
end