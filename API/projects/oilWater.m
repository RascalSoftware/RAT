classdef oilWater < projectClass
    
    methods

        function obj = oilWater(experimentName)
            % Creates a project object for non polarised neutrons.
            % The only argument is the experiment name which is a char
            % array, which is optional
            %
            % problem = oilWater('New experiment');
            arguments
                experimentName {mustBeTextScalar} = ''
            end

            % Call projectClass constructor
            obj@projectClass(experimentName);

            % Set values for oil water calculations
            obj.calculationType = calculationTypes.OilWater.value;

            % What values should we have for these?
            obj.addParam('Oil Thickness');
            obj.addParam('Oil Roughness');
        end
        
    end

end