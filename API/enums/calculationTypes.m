classdef calculationTypes < customEnum
    methods (Static)
        function v = values()
            v = customEnum.values('calculationTypes');
        end
        
        function e = fromValue(value)
            e = customEnum.fromValue('calculationTypes', value);
        end
    end

    enumeration
        Standard ('standard')
        Absorption ('absorption')
        Domains ('domains')
        OilWater ('oilWater')
        Magnetic ('magnetic')
        MagneticDomains ('magneticDomains')
    end
end