classdef magnetic < projectClass
    
    methods

        function obj = magnetic(experimentName)
            % Creates a project object for polarised neutrons
            % including absorption.
            % The only argument is the experiment name which is a char
            % array, which is optional
            %
            % problem = magnetic('New experiment');
            arguments
                experimentName {mustBeTextScalar} = ''
            end

            % Call projectClass constructor
            obj@projectClass(experimentName);

            % Set values for polarised neutrons including absorption
            obj.calculationType = calculationTypes.Magnetic.value;
            obj.layers = layersClass({'SLD Real', 'SLD Imaginary', 'SLD Magnetic Real', 'SLD Magnetic Imaginary'});

        end
        
    end

end