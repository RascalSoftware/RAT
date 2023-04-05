classdef domains < domainsClass
    
    methods

        function obj = domains(experimentName)
            % Creates a project object for non polarised neutrons with
            % samples consisting of domains which are larger than the
            % beam lateral coherence length.
            % The only argument is the experiment name which is a char
            % array, which is optional
            %
            % problem = domains('New experiment');
            arguments
                experimentName {mustBeTextScalar} = ''
            end

            % Call domainsClass constructor
            obj@domainsClass(experimentName);
            obj.calculationType = calculationTypes.Domains.value;
        end
        
    end

end