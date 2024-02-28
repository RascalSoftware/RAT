% This allow enums to be used by coder without redefinition or hardcoding
classdef coderEnums
    properties (Constant)
        eventTypes = eventTypes.toStruct()
    end
    methods (Static)
        function initialize() 
            % initializes enum struct field as a coder const like so 
            % coder.const(coderEnums.procedures.Dream);
            props = properties(coderEnums);
            for i = 1:length(props)
                constProp = props{i};
                names = fieldnames(coderEnums.(constProp));
                for j = 1:numel(names)
                    coder.const(coderEnums.(constProp).(names{j}));
                end
            end
        end
    end
end
