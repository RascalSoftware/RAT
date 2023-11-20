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
problem.module.type = validateOption(problem.module.type, 'modelTypes', invalidModelMessage).value;

thisProjectClass = createProject(name=projectName, model=problem.module.type);

% Set geometry
if strcmpi(problem.module.experiment_type, 'Air / Liquid (or solid)')
    thisProjectClass.setGeometry(geometryOptions.AirSubstrate.value);
else
    thisProjectClass.setGeometry(geometryOptions.SubstrateLiquid.value);
end

% Set parameters block
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
            supportedLanguages.Matlab.value, ...
            'pwd');
end

% Remove defaults
thisProjectClass.removeBacksPar(1);
thisProjectClass.removeBackground(1);
thisProjectClass.removeBulkIn(1);
thisProjectClass.removeBulkOut(1);
thisProjectClass.removeScalefactor(1);

% Set backgrounds
for i = 1:problem.numberOfBacks
    backName = sprintf('Backs parameter %d',i);
    % Add backgrounds parameter
    % addBacksPar <- (name, min, value, max, fit)
    thisProjectClass.addBacksPar(backName, ...
        problem.backs_constr(i,1), ...
        problem.backs(i), ...
        problem.backs_constr(i,2), ...
        logical(problem.backgrounds_fityesno(i)));
    % Add background
    thisProjectClass.addBackground(problem.backsNames{i}, ...
        allowedTypes.Constant.value, ...
        backName);
end

% Set bulk in params
for i = 1:problem.numberOfNbas
    % addBulkIn <- (name, min, value, max, fit)
    thisProjectClass.addBulkIn(problem.nbaNames{i}, ...
        problem.nbairs_constr(i,1), ...
        problem.nba(i), ...
        problem.nbairs_constr(i,2), ...
        logical(problem.nbairs_fityesno(i)));
end

% Set bulk out params
for i = 1:problem.numberOfNbss
    % addBulkOut <- (name, min, value, max, fit)
    thisProjectClass.addBulkOut(problem.nbsNames{i}, ...
        problem.nbsubs_constr(i,1), ...
        problem.nbs(i), ...
        problem.nbsubs_constr(i,2), ...
        logical(problem.nbsubs_fityesno(i)));
end

% Set scalefactors
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
    thisName = char(problem.contrastNames{1});
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
        'nbs', thisNbs,...
        'nba', thisNba,...
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