classdef contrastsClass < baseContrasts

    % This class holds the parameters for each contrast used in the
    % simulation


    methods   
        function obj = contrastsClass(calcType)
            % Class Constructor
            % The (optional) inputs are logical flags to state whether
            % or not this is a domains calculation and wheter or not this
            % is an oil-water calculation.
            %
            % contrasts = contrastsClass()
            arguments
                calcType.domains {mustBeA(calcType.domains,'logical')} = false
                calcType.oilWater {mustBeA(calcType.oilWater,'logical')} = false
            end

            obj@baseContrasts(calcType.domains, calcType.oilWater)
        end
        
        function names = getDisplayNames(obj)
            names = ["Name"; "Data"; "Background"; "Bulk in"; "Bulk out"; "Scalefactor"; "Resolution"; "Resample"; "Model"];
            if obj.domainsCalc
                names = [names(1:end-1); "Domain Ratio"; names(end)];
            end
            if obj.oilWaterCalc
                names = [names(1:2); "Oil Chi Data"; names(3:end)];
            end
        end

        function obj = updateDataName(obj, nameChange)
            % Update the "data" parameter in a contrast if the name is
            % changed in the data class.           
            % This function is only really called from projectClass if a
            % data name has been updated. It looks through the 'data'
            % field of the contrasts and if it matches nameChange.oldName
            % then this is updated to nameChange.newName
            %
            % contrasts.updateDataName(nameChange)            
            oldName = nameChange.oldName;
            newName = nameChange.newName;
            
            for i = 1:obj.numberOfContrasts
                thisContrast = obj.contrasts{i};
                if strcmpi(oldName,thisContrast.data)
                    obj.contrasts{i}.data = newName;
                end
            end
            
        end
        
        function contrastStruct = toStruct(obj, allowedNames, modelType, dataTable)
            % Convert the contrasts class to a struct.
            % This routine builds on that in the base class by dealing with
            % the additional properties defined in this subclass.
            % The expected input is the allowed names for each parameter,
            % the model type and the data table from the data class.
            %
            % contrasts.toStruct(allowedNames, 'standard layers', dataTable)

            % Call superclass version for common properties
            contrastStruct = toStruct@baseContrasts(obj, allowedNames, modelType);

            % Now deal with additional properties in this class
            nContrasts = obj.numberOfContrasts;
            contrastBacks = cell(1,nContrasts);
            contrastDomainRatios = zeros(1,nContrasts);
            contrastShifts = ones(1,nContrasts);
            contrastScales = ones(1,nContrasts);
            contrastRes = ones(1,nContrasts);
            resample = ones(1,nContrasts);

            dataPresent = zeros(1,nContrasts);
            dataLimits = cell(1,nContrasts);
            simLimits = cell(1,nContrasts);
            allData = cell(1,nContrasts);

            oilChiDataPresent = zeros(1,nContrasts);
            allOilChiData = cell(1,nContrasts);

            for i = 1:nContrasts

                thisContrast = obj.contrasts{i};

                if isfield(thisContrast, 'domainRatio')
                    contrastDomainRatios(i) = find(strcmpi(thisContrast.domainRatio,allowedNames.domainRatioNames));
                end

                contrastBacks{i} =  [find(strcmpi(thisContrast.background,allowedNames.backsNames)), 1];
                contrastShifts(i) = 1;  %Todo
                contrastScales(i) = find(strcmpi(thisContrast.scalefactor,allowedNames.scalefacNames));
                contrastRes(i) = find(strcmpi(thisContrast.resolution,allowedNames.resolsNames));
                resample(i) = thisContrast.resample;

                thisDataVal = find(strcmpi(thisContrast.data,allowedNames.dataNames));
                if ~isempty(thisDataVal)
                    actualData = dataTable{thisDataVal,2}{:};
                    if ~isempty(actualData)
                        dataPresent(i) = 1;
                    end
                    thisDataLimit = dataTable{thisDataVal,3}{:};
                    if isempty(thisDataLimit)
                        thisDataLimit = [0 0];
                    end
                    dataLimits{i} = thisDataLimit;
                    simLimits{i} = dataTable{thisDataVal,4}{:};
                    allData{i} = dataTable{thisDataVal,2}{:};
                else
                    dataLimits{i} = [0 0];
                    simLimits{i} = [0 0];
                    allData{i} = [0 0 0];
                end
            end

            if obj.oilWaterCalc
                for i = 1:nContrasts    
                    thisContrast = obj.contrasts{i};
                    thisOilChiDataVal = find(strcmpi(thisContrast.oilChiData,allowedNames.dataNames));
                    if ~isempty(thisOilChiDataVal)
                        actualOilChiData = dataTable{thisOilChiDataVal,2}{:};
                        if ~isempty(actualOilChiData)
                            oilChiDataPresent(i) = 1;
                        end
                        allOilChiData{i} = dataTable{thisOilChiDataVal,2}{:};
                    else
                        allOilChiData{i} = [0 0 0];
                    end
                end
            end

            contrastStruct.contrastDomainRatios = contrastDomainRatios;
            contrastStruct.contrastBacks = contrastBacks;
            contrastStruct.contrastShifts = contrastShifts;
            contrastStruct.contrastScales = contrastScales;
            contrastStruct.contrastRes = contrastRes;
            contrastStruct.resample = resample;
            contrastStruct.dataPresent = dataPresent;
            contrastStruct.dataLimits = dataLimits;
            contrastStruct.simLimits = simLimits;
            contrastStruct.allData = allData;
            contrastStruct.oilChiDataPresent = oilChiDataPresent;
            contrastStruct.allOilChiData = allOilChiData;

        end

        function inputBlock = parseContrastInput(obj, allowedNames, inputValues)
            % Parse the parameters given for the contrast, assigning
            % default values to those unspecified and ensuring specified
            % values are of the correct type, and included in the list of
            % allowed names where necessary.
            %
            % contrastsClass.parseContrastInput(allowedNames, ...
            %                                   'name', 'Contrast Name', ...
            %                                   'background', 'Background H2O')        
            defaultName = '';
            defaultBack = '';
            defaultData = '';   
            defaultNba = '';
            defaultNbs = '';
            defaultScalefac = '';
            defaultResol = '';
            defaultResample = false;
        
            expectedBacks = cellstr(allowedNames.backsNames);
            expectedData = cellstr(allowedNames.dataNames);
            expectedBulkin = cellstr(allowedNames.bulkInNames);
            expectedBulkout = cellstr(allowedNames.bulkOutNames);
            expectedResols = cellstr(allowedNames.resolsNames);
            expectedScalefac = cellstr(allowedNames.scalefacNames);

            p = inputParser;
            addParameter(p,'name',          defaultName,        @isText);
            addParameter(p,'data',          defaultData,        @(x) any(validatestring(x,expectedData)));

            if obj.oilWaterCalc
                defaultOilChiData = '';
                addParameter(p,'oilChiData',    defaultOilChiData,  @(x) any(validatestring(x,expectedData)));
            end

            addParameter(p,'background',    defaultBack,        @(x) any(validatestring(x,expectedBacks)));
            addParameter(p,'nba',           defaultNba,         @(x) any(validatestring(x,expectedBulkin)));
            addParameter(p,'nbs',           defaultNbs,         @(x) any(validatestring(x,expectedBulkout)));
            addParameter(p,'scalefactor',   defaultScalefac,    @(x) any(validatestring(x,expectedScalefac)));
            addParameter(p,'resolution',    defaultResol,       @(x) any(validatestring(x,expectedResols)));
            addParameter(p,'resample',      defaultResample,    @islogical);

            if obj.domainsCalc
                defaultDomainRatio = '';
                expectedDomainRatio = cellstr(allowedNames.domainRatioNames);
                addParameter(p,'domainRatio',   defaultDomainRatio, @(x) any(validatestring(x,expectedDomainRatio)));
            end

            parse(p, inputValues{:});
            inputBlock = p.Results;
        
        end
    end
end


