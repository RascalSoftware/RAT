classdef coderEnums
    % An Enum class which lets MATLAB Coder use Enums without redefinition or hardcoding.
    properties (Constant)
        allowedTypes = allowedTypes.toStruct()
        backgroundActions = backgroundActions.toStruct()
        boundHandlingOptions = boundHandlingOptions.toStruct()
        calculationTypes = calculationTypes.toStruct()
        errorCodes = errorCodes.toStruct()
        displayOptions = displayOptions.toStruct()
        eventTypes = eventTypes.toStruct()
        geometryOptions = geometryOptions.toStruct()
        hydrationTypes = hydrationTypes.toStruct()
        modelTypes = modelTypes.toStruct()
        parallelOptions = parallelOptions.toStruct()
        priorTypes = priorTypes.toStruct()
        procedures = procedures.toStruct()
        searchStrategy = searchStrategy.toStruct()
        supportedLanguages = supportedLanguages.toStruct()
    end
    methods (Static)
        function initialise() 
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
