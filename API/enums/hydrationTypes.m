classdef hydrationTypes < customEnum
    % Options for the 'hydrate with' parameter of a Layer.
    methods (Static)
        function s = toStruct()
            s = customEnum.toStruct(mfilename('class'));
        end
        
        function v = values()
            v = customEnum.values(mfilename('class'));
        end
        
        function e = fromValue(value)
            e = customEnum.fromValue(mfilename('class'), value);
        end
    end

    enumeration
        BulkIn ('bulk in')
        BulkOut ('bulk out')
    end
end
