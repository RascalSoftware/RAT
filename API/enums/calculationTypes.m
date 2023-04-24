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
        NonPolarised ('non polarised')
        Absorption ('absorption')
        Domains ('domains')
        OilWater ('oil water')
        Magnetic ('magnetic')
        MagneticDomains ('magnetic domains')
    end
end