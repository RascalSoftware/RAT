classdef hydrationTypes < customEnum
    methods (Static)
        function v = values()
            v = customEnum.values('hydrationTypes');
        end
        
        function e = fromValue(value)
            e = customEnum.fromValue('hydrationTypes', value);
        end
    end

    enumeration
        None ('none')
        BulkIn ('bulk in')
        BulkOut ('bulk out')
        Oil ('oil')
    end
end