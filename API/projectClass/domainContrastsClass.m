classdef domainContrastsClass < baseContrasts

    % A simplified version of the contrast class that allows specification
    % of the model only (i.e. with no data). This is used for domains
    % calculations.
                
    methods

        function names = getDisplayNames(obj)
            names = ["Name"; "Bulk in"; "Bulk out"; "Model"];
        end

        function inputBlock = parseContrastInput(~, allowedNames, inputValues)
            % Parse the parameters given for the contrast, assigning
            % default values to those unspecified and ensuring specified
            % values are of the correct type, and included in the list of
            % allowed names where necessary.
            %
            % contrastsClass.parseContrastInput(allowedNames, ...
            %                                   'name', 'Contrast Name', ...
            %                                   'nba', 'Silicon')        
            defaultName = '';
            defaultNba = '';
            defaultNbs = '';
        
            expectedBulkin = cellstr(allowedNames.bulkInNames);
            expectedBulkout = cellstr(allowedNames.bulkOutNames);
        
            p = inputParser;
            addParameter(p,'name',          defaultName,        @isText);
            addParameter(p,'nba',           defaultNba,         @(x) any(validatestring(x,expectedBulkin)));
            addParameter(p,'nbs',           defaultNbs,         @(x) any(validatestring(x,expectedBulkout)));
                
            parse(p, inputValues{:});
            inputBlock = p.Results;

        end
    end
end
