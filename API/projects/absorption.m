classdef absorption < projectClass
    
    methods

        function obj = absorption(experimentName)
            % Creates a project object for non polarised neutrons
            % including absorption.
            % The only argument is the experiment name which is a char
            % array, which is optional
            %
            % problem = absorption('New experiment');
            arguments
                experimentName {mustBeTextScalar} = ''
            end

            % Call projectClass constructor
            obj@projectClass(experimentName);

            % Set values for non polarised neutrons including absorption
            obj.calculationType = calculationTypes.Absorption.value;
            obj.layers = layersClass({'SLD Real', 'SLD Imaginary'});
        end
        
    end

end