classdef invalidType < MException
    methods
        function obj = invalidType(message)
            obj = obj@MException('RAT:InvalidType', message);
        end
    end
end