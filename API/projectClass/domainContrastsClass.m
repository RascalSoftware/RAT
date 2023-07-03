classdef domainContrastsClass < baseContrasts

    % A simplified version of the contrast class that allows specification
    % of the model only (i.e. with no data). This is used for domains
    % calculations.
                
    methods

        function names = getDisplayNames(obj)
            names = ["Name"; "Model"];
        end

        function inputBlock = parseContrastInput(~, ~, inputValues)
            % Parse the parameters given for the contrast, assigning
            % default values to those unspecified and ensuring specified
            % values are of the correct type, and included in the list of
            % allowed names where necessary.
            %
            % contrastsClass.parseContrastInput('name', 'Contrast Name')        
            defaultName = '';
        
            p = inputParser;
            addParameter(p,'name',          defaultName,        @isText);
                
            parse(p, inputValues{:});
            inputBlock = p.Results;
        end
    end
end
