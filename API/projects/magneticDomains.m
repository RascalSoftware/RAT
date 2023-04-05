classdef magneticDomains < domainsClass
    
    methods

        function obj = magneticDomains(experimentName)
            % Creates a project object for non polarised neutrons with
            % samples consisting of domains which are larger than the
            % beam lateral coherence length.
            % The only argument is the experiment name which is a char
            % array, which is optional
            %
            % problem = magneticDomains('New experiment');
            arguments
                experimentName {mustBeTextScalar} = ''
            end

            % Call projectClass constructor
            obj@domainsClass(experimentName);

            obj.calculationType = calculationTypes.MagneticDomains.value;
            obj.layers = layersClass({'SLD Real', 'SLD Imaginary', 'SLD Magnetic Real', 'SLD Magnetic Imaginary'});
        end
        
    end

end