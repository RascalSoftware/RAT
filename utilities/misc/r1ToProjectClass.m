function thisProjectClass = r1ToProjectClass(r1Problem)
% Converts r1 struct to projectClass. The function converts r1 structs into projectClass.
% The functions takes the path of the r1 struct .mat file and outputs a projectClass
%
% problem = r1ToProjectClass('DSPCBilayerStructInput.mat');

% Load r1problem
problem = load(r1Problem).problem;

% Select name
if iscell(problem.name)
    projectName = problem.name{:};
else
    projectName = problem.name;
end

% Check options are valid and make empty instance of projectClass
invalidModelMessage = sprintf('modelType must be a modelTypes enum or one of the following strings (%s)', ...
                             strjoin(modelTypes.values(), ', '));

% Rascal name for custom XY differs from RAT
if strcmpi(problem.module.type,'custom XY profile')
    problem.module.type = 'custom xy';
end

problem.module.type = validateOption(problem.module.type, 'modelTypes', invalidModelMessage).value;
thisProjectClass = createProject(name=projectName, model=problem.module.type);

% Set geometry
if strcmpi(problem.module.experiment_type, 'Air / Liquid (or solid)')
    thisProjectClass.setGeometry(geometryOptions.AirSubstrate.value);
else
    thisProjectClass.setGeometry(geometryOptions.SubstrateLiquid.value);
end

% Set parameters block
problem.constr = fixNonFitConstrs(length(problem.params), problem.paramnames, problem.constr, problem.params, problem.fityesno);
for i = 2:length(problem.params)
    % addParameter <- (name, min, value, max, fit)
    thisProjectClass.addParameter(problem.paramnames{i},...
        problem.constr(i,1),...
        problem.params(i),...
        problem.constr(i,2),...
        logical(problem.fityesno(i)));
end

% Set substrate roughness parameters
thisProjectClass.setParameter(1, ...
    'min', problem.constr(1,1)', ...
    'max', problem.constr(1,2)', ...
    'value', problem.params(1), ...
    'fit', logical(problem.fityesno(1)), ...
    'name', problem.paramnames{1});

switch lower(problem.module.type)
    case modelTypes.StandardLayers.value
        % Set layers (if standard layers)
        for i = 1:problem.numberOfLayers
            % Select Layer
            thisLayer = problem.layersDetails{i};
            % Get name, thickness, sld, roughness, hydration & hydrate with
            thisName = thisLayer{5};
            thisThick = problem.paramnames{convertToDouble(thisLayer{1})};
            thisSld = problem.paramnames{convertToDouble(thisLayer{2})};
            thisRough = problem.paramnames{convertToDouble(thisLayer{3})};
            thisHydrWhat = thisLayer{6};
            thisHydrPar = thisLayer{4};
            % Create layer
            if isempty(thisHydrPar)
                thisLayer = {thisName, thisThick, thisSld, thisRough};
            else
                thisHydr = problem.paramnames{convertToDouble(thisLayer{4})};
                thisLayer = {thisName, thisThick, thisSld, thisRough, thisHydr, thisHydrWhat};
            end
            % Add layer
            thisProjectClass.addLayer(thisLayer);
        end
    otherwise
        % Set custom file name
        customFile = problem.module.name;
        [~,modelName,~] = fileparts(customFile);
        thisProjectClass.addCustomFile(modelName, ...
            customFile, ...
            supportedLanguages.Matlab.value);
end

% Remove defaults
thisProjectClass.removeBackgroundParam(1);
thisProjectClass.removeBackground(1);
thisProjectClass.removeBulkIn(1);
thisProjectClass.removeBulkOut(1);
thisProjectClass.removeScalefactor(1);

% Set backgrounds
backParamNames = num2cell(arrayfun(@(i) sprintf("Backs parameter %d", i), 1:problem.numberOfBacks));
problem.backs_constr = fixNonFitConstrs(problem.numberOfBacks, backParamNames, problem.backs_constr, problem.backs, problem.backgrounds_fityesno);
for i = 1:problem.numberOfBacks
    % Add backgrounds parameter
    % addBackgroundParam <- (name, min, value, max, fit)
    thisProjectClass.addBackgroundParam(backParamNames{i}, ...
        problem.backs_constr(i,1), ...
        problem.backs(i), ...
        problem.backs_constr(i,2), ...
        logical(problem.backgrounds_fityesno(i)));
    % Add background
    thisProjectClass.addBackground(problem.backsNames{i}, ...
        allowedTypes.Constant.value, ...
        backParamNames{i});
end

% Set bulk in params
problem.nbairs_constr = fixNonFitConstrs(problem.numberOfNbas, problem.nbaNames, problem.nbairs_constr, problem.nba, problem.nbairs_fityesno);
for i = 1:problem.numberOfNbas
    % addBulkIn <- (name, min, value, max, fit)
    % RasCAL-1 let you not bother with constraints for non-fit parameters,
    % so adjust constraints to avoid an error if needed
    thisProjectClass.addBulkIn(problem.nbaNames{i}, ...
        problem.nbairs_constr(i,1), ...
        problem.nba(i), ...
        problem.nbairs_constr(i,2), ...
        logical(problem.nbairs_fityesno(i)));
end

% Set bulk out params
problem.nbsubs_constr = fixNonFitConstrs(problem.numberOfNbss, problem.nbsNames, problem.nbsubs_constr, problem.nbs, problem.nbsubs_fityesno);
for i = 1:problem.numberOfNbss
    % addBulkOut <- (name, min, value, max, fit)
    thisProjectClass.addBulkOut(problem.nbsNames{i}, ...
        problem.nbsubs_constr(i,1), ...
        problem.nbs(i), ...
        problem.nbsubs_constr(i,2), ...
        logical(problem.nbsubs_fityesno(i)));
end

% Set scalefactors
problem.scale_constr = fixNonFitConstrs(problem.numberOfScales, problem.scalesNames, problem.scale_constr, problem.scalefac, problem.scalefac_fityesno);
for i = 1:problem.numberOfScales
    % addScalefactor <- (name, min, value, max, fit)
    thisProjectClass.addScalefactor(problem.scalesNames{i}, ...
        problem.scale_constr(i,1), ...
        problem.scalefac(i), ...
        problem.scale_constr(i,2), ...
        logical(problem.scalefac_fityesno(i)));
end

% Set data
dataFiles = problem.data;
for i = 1:length(dataFiles)
    thisData = dataFiles{i};
    [~,thisDataFile,~] = fileparts(problem.contrastFiles{i});
    thisDataName = thisDataFile;
    thisProjectClass.addData(thisDataName,thisData);
    thisProjectClass.setData(i, ...
        'dataRange', problem.dataLimits{i} , ...
        'simRange', problem.simLimits{i});
end

% Create contrasts
for i = 1:problem.numberOfContrasts
    thisName = char(problem.contrastNames{i});
    thisBackgroundNumber = problem.contrastBacks(i);
    thisBackground = char(thisProjectClass.background.backgrounds.varTable{thisBackgroundNumber,1});

    thisResol = problem.resolNames{problem.contrastResolutions(i)};
    thisScale = problem.scalesNames{problem.contrastScales(i)};
    thisNbs = problem.nbsNames{problem.contrastNbss(i)};
    thisNba = problem.nbaNames{problem.contrastNbas(i)};
    thisData = thisProjectClass.data.varTable{i+1,1};

    thisProjectClass.addContrast('name', thisName,...
        'backGround', thisBackground,...
        'resolution', thisResol,...
        'scalefactor', thisScale,...
        'bulkOut', thisNbs,...
        'bulkIn', thisNba,...
        'data', char(thisData));
end

% Set model for each contrast
switch lower(problem.module.type)
    case modelTypes.StandardLayers.value
        for i = 1:problem.numberOfContrasts
            thisContrastLayers = str2num(problem.contrastLayers{i});
            thisLayersList = {};
            for n = 1:length(thisContrastLayers)
                thisLayersList{n} = problem.layersDetails{thisContrastLayers(n)}{5};
            end
            thisProjectClass.setContrastModel(i, thisLayersList);
        end
    otherwise
        for i = 1:problem.numberOfContrasts
            thisProjectClass.setContrastModel(i, modelName);
        end
end

    function output = convertToDouble(input)
        if isText(input)
            input = str2double(input);
        end
        output = input;
    end
end

function new_constrs = fixNonFitConstrs(num_items, names, constrs, vals, fits)
% RasCAL-1 let you not bother with constraints for non-fit parameters,
% so this function adjusts the constraints to avoid an error if needed.
for i = 1:num_items
    new_constrs = constrs;
    if ~fits(i)
        new_constrs(i, :) = [min(constrs(i, 1), vals(i)) max(constrs(i, 2), vals(i))];
        if new_constrs(i) ~= constrs(i)
            warning("Non-fit parameter %s has invalid constraints, these" + ...
                "have been adjusted to satisfy the current value of the parameter.", ...
                names{i})
        end
    end
end
end
