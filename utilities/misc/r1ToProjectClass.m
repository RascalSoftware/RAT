function project = r1ToProjectClass(r1Problem)
% Converts RasCAL1 (r1) struct to an equivalent ``projectClass`` instance. The function takes the path of the 
% r1 struct .mat file.
%
% Examples
% --------
% >>> project = r1ToProjectClass('DSPCBilayerStructInput.mat');  % Load from current directory
% >>> project = r1ToProjectClass('examples/DSPCBilayerStructInput.mat');  % Load from the example subdirectory
%
% Parameters
% ----------
% r1Problem : string or char array
%    The path of a mat file that contains a RasCAL1 struct.
%
% Returns
% -------
% project : projectClass
%    An instance of the ``projectClass`` which should be equivalent to the given R1 problem.

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
project = createProject(name=projectName, model=problem.module.type);

% Set geometry
if strcmpi(problem.module.experiment_type, 'Air / Liquid (or solid)')
    project.geometry = geometryOptions.AirSubstrate.value;
else
    project.geometry = geometryOptions.SubstrateLiquid.value;
end

% Set parameters block
problem.constr = fixNonFitConstrs(length(problem.params), problem.paramnames, problem.constr, problem.params, problem.fityesno);
for i = 2:length(problem.params)
    % addParameter <- (name, min, value, max, fit)
    project.addParameter(problem.paramnames{i},...
        problem.constr(i,1),...
        problem.params(i),...
        problem.constr(i,2),...
        logical(problem.fityesno(i)));
end

% Set substrate roughness parameters
project.setParameter(1, ...
    'min', problem.constr(1,1)', ...
    'max', problem.constr(1,2)', ...
    'value', problem.params(1), ...
    'fit', logical(problem.fityesno(1)));

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
            project.addLayer(thisLayer);
        end
    otherwise
        % Set custom file name
        customFile = problem.module.name;
        [~,modelName,~] = fileparts(customFile);
        project.addCustomFile(modelName, ...
            customFile, ...
            supportedLanguages.Matlab.value);
end

% Remove defaults
project.removeBackgroundParam(1);
project.removeBackground(1);
project.removeBulkIn(1);
project.removeBulkOut(1);
project.removeScalefactor(1);

% Set backgrounds
backParamNames = num2cell(arrayfun(@(i) sprintf("Backs parameter %d", i), 1:problem.numberOfBacks));
problem.backs_constr = fixNonFitConstrs(problem.numberOfBacks, backParamNames, problem.backs_constr, problem.backs, problem.backgrounds_fityesno);
for i = 1:problem.numberOfBacks
    % Add backgrounds parameter
    % addBackgroundParam <- (name, min, value, max, fit)
    project.addBackgroundParam(backParamNames{i}, ...
        problem.backs_constr(i,1), ...
        problem.backs(i), ...
        problem.backs_constr(i,2), ...
        logical(problem.backgrounds_fityesno(i)));
    % Add background
    project.addBackground(problem.backsNames{i}, ...
        allowedTypes.Constant.value, ...
        backParamNames{i});
end

% Set bulk in params
problem.nbairs_constr = fixNonFitConstrs(problem.numberOfNbas, problem.nbaNames, problem.nbairs_constr, problem.nba, problem.nbairs_fityesno);
for i = 1:problem.numberOfNbas
    % addBulkIn <- (name, min, value, max, fit)
    % RasCAL-1 let you not bother with constraints for non-fit parameters,
    % so adjust constraints to avoid an error if needed
    project.addBulkIn(problem.nbaNames{i}, ...
        problem.nbairs_constr(i,1), ...
        problem.nba(i), ...
        problem.nbairs_constr(i,2), ...
        logical(problem.nbairs_fityesno(i)));
end

% Set bulk out params
problem.nbsubs_constr = fixNonFitConstrs(problem.numberOfNbss, problem.nbsNames, problem.nbsubs_constr, problem.nbs, problem.nbsubs_fityesno);
for i = 1:problem.numberOfNbss
    % addBulkOut <- (name, min, value, max, fit)
    project.addBulkOut(problem.nbsNames{i}, ...
        problem.nbsubs_constr(i,1), ...
        problem.nbs(i), ...
        problem.nbsubs_constr(i,2), ...
        logical(problem.nbsubs_fityesno(i)));
end

% Set scalefactors
problem.scale_constr = fixNonFitConstrs(problem.numberOfScales, problem.scalesNames, problem.scale_constr, problem.scalefac, problem.scalefac_fityesno);
for i = 1:problem.numberOfScales
    % addScalefactor <- (name, min, value, max, fit)
    project.addScalefactor(problem.scalesNames{i}, ...
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
    project.addData(thisDataName,thisData);
    project.setData(i, ...
        'dataRange', problem.dataLimits{i} , ...
        'simRange', problem.simLimits{i});
end

% Create contrasts
for i = 1:problem.numberOfContrasts
    thisName = char(problem.contrastNames{i});
    thisBackgroundNumber = problem.contrastBacks(i);
    thisBackground = char(project.background.backgrounds.varTable{thisBackgroundNumber,1});

    thisResol = problem.resolNames{problem.contrastResolutions(i)};
    thisScale = problem.scalesNames{problem.contrastScales(i)};
    thisNbs = problem.nbsNames{problem.contrastNbss(i)};
    thisNba = problem.nbaNames{problem.contrastNbas(i)};
    thisData = project.data.varTable{i+1,1};

    project.addContrast('name', thisName,...
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
            project.setContrastModel(i, thisLayersList);
        end
    otherwise
        for i = 1:problem.numberOfContrasts
            project.setContrastModel(i, modelName);
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
            warning("Non-fit parameter %s has invalid constraints, these " + ...
                "have been adjusted to satisfy the current value of the parameter.", ...
                names{i})
        end
    end
end
end
