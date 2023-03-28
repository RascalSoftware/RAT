classdef routineNotSupported < MException
    properties (Constant, Hidden)    
        errorID = 'RAT:RoutineNotSupported';
    end
    methods
        function obj = routineNotSupported(message)
            arguments
                message {mustBeTextScalar} = 'This routine is not supported'
            end
            obj = obj@MException(routineNotSupported.errorID, message);
        end
    end
end