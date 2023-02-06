function newR1Problem = projectClassToR1(r2Problem,varargin)

% Takes an instance of project class and makes this into an r1 type struct.
% Also creates the datafiles directory and saves the data if asked...

% Now work through updating the values in the r1 struct with equivalent
% values in the r2 projectClass


%% Work out inputs and create directories if necessary
if ~isempty(varargin)
    pars = parametersClass.parseParameterInput(varargin);
    
    % Use the named r1Problem
    r1Problem = pars.r1Problem;
    if isfield(r1Problem,'empty')                % No r1Problem supplied
        r1Problem = load('defaultProject.mat');
        r1Problem = r1Problem.problem;
    end
    
    saveTheProject = pars.saveProject;
    fileName = pars.fileName;
    
    % (1) Check the directory exists
    % Check if the required directory exists....
    dirName = pars.dirName;
    dirPath = pars.dirPath;
    fullName = fullfile(dirPath,dirName);
    if ~exist(fullName,'dir') && saveTheProject
        warning('Required directory %s does not exist. Creating it',fullName);
        % Directory does not exist
        % Go to the specified path
        % and make the project directories.
        cd(dirPath);
        mkdir(dirName);
        originalDir = pwd;
        cd(dirName);
        if ~exist('datafiles','dir')
            mkdir('datafiles');
        end
    end
end




%% Geometry and exp type block
% Get parameters from R2
geometry = r2Problem.Geometry;
type = r2Problem.ModelType;
name = r2Problem.experimentName;

% Put these into the R1 struct..
r1Problem.name = name;
r1Problem.module.type = type;
r1Problem.module.experiment_type = geometry;

%% Parameter Names, values, limits and check boxes
r2ParamStruct = r2Problem.parameters.toStruct;

paramNames = r2ParamStruct.paramNames;
nParams = r2ParamStruct.nParams;
paramConstr = r2ParamStruct.paramConstr;
fitYesNo = r2ParamStruct.fitYesNo;
paramValues = r2ParamStruct.params;

r1Problem.params = paramValues;
r1Problem.paramnames = paramNames;

theseConstr = [];
for i = 1:nParams
    theseConstr(i,:) = paramConstr{i};
end

r1Problem.constr = theseConstr;
r1Problem.fityesno = fitYesNo;

%% Qz shifts



r1Problem.numberOfShifts = 1;
r1Problem.shiftsNames = {'Shift 1'};
r1Problem.shifts_horisontal = 0;
r1Problem.numberOfShifts = 1;
r1Problem.shifts_constr = [-1e-4 1e-4];
r1Problem.shifts_fityesno = 0;

%% Scalefactors....
r2ScalesStruct = r2Problem.scalefactors.toStruct();

scalesNames = r2ScalesStruct.paramNames;
nScales = r2ScalesStruct.nParams;
scalesConstr = r2ScalesStruct.paramConstr;
fitYesNo = r2ScalesStruct.fitYesNo;
scalesValues = r2ScalesStruct.params;

r1Problem.scalesNames = scalesNames;
r1Problem.scalefac = scalesValues;
r1Problem.numberOfScales = nScales;

theseConstr = [];
for i = 1:nScales
    theseConstr(i,:) = scalesConstr{i};
end

r1Problem.scale_constr = theseConstr;
r1Problem.scalefac_fityesno = fitYesNo;

%% Bulk in
r2BulkInStruct = r2Problem.bulkIn.toStruct();

bulkInNames = r2BulkInStruct.paramNames;
nbulkIn = r2BulkInStruct.nParams;
bulkInConstr = r2BulkInStruct.paramConstr;
bulkInFitYesNo = r2BulkInStruct.fitYesNo;
bulkInValues = r2BulkInStruct.params;

r1Problem.nbaNames = bulkInNames;
r1Problem.nba = bulkInValues;
r1Problem.numberOfNbas = nbulkIn;

theseConstr = [];
for i = 1:nbulkIn
    theseConstr(i,:) = bulkInConstr{i};
end

r1Problem.nbairs_constr = theseConstr;
r1Problem.nbairs_fityesno = bulkInFitYesNo;


%% Bulk out
r2BulkOutStruct = r2Problem.bulkOut.toStruct();

bulkOutNames = r2BulkOutStruct.paramNames;
nbulkOut = r2BulkOutStruct.nParams;
bulkOutConstr = r2BulkOutStruct.paramConstr;
bulkOutFitYesNo = r2BulkOutStruct.fitYesNo;
bulkOutValues = r2BulkOutStruct.params;

r1Problem.nbsNames = bulkOutNames;
r1Problem.nbs = bulkOutValues;
r1Problem.numberOfNbss = nbulkOut;

theseConstr = [];
for i = 1:nScales
    theseConstr(i,:) = bulkOutConstr{i};
end

r1Problem.nbsubs_constr = theseConstr;
r1Problem.nbsubs_fityesno = bulkOutFitYesNo;

%% Resolutions
r2ResolStruct = r2Problem.resolution.toStruct();

% Only use resolpars - don't have more advanced resolutions in R1...
resolNames = r2ResolStruct.resolParNames;
nResols = r2ResolStruct.nResolPars;
resolConstr = r2ResolStruct.resolParConstr;
resolFitYesNo = r2ResolStruct.resolFitYesNo;
resolValues = r2ResolStruct.resolPars;

r1Problem.resolNames = resolNames;
r1Problem.resolution = resolValues;
r1Problem.numberOfResolutions = nResols;

theseConstr = [];
for i = 1:nResols
    theseConstr(i,:) = resolConstr{i};
end

r1Problem.reslution_constr = theseConstr;
r1Problem.resolution_fityesno = resolFitYesNo;


%% Backgrounds...
r2BackStruct = r2Problem.background.toStruct();

% Only use resolpars - don't have more advanced resolutions in R1...
backsNames = r2BackStruct.backParNames;
nBacks = r2BackStruct.nBackPars;
backsConstr = r2BackStruct.backParconstr;
backsFitYesNo = r2BackStruct.backParFitYesNo;
backsValues = r2BackStruct.backParVals;

r1Problem.backsNames = backsNames;
r1Problem.backs = backsValues;
r1Problem.numberOfBacks = nBacks;

theseConstr = [];
for i = 1:nBacks
    theseConstr(i,:) = backsConstr{i};
end

r1Problem.backs_constr = theseConstr;
r1Problem.backgrounds_fityesno = backsFitYesNo;


%% Now, if it is Standard Layers, deal with the layers....
if strcmpi(type,'standard layers')
    
    allLayers = r2Problem.layers;
    layersTable = table2cell(allLayers.layersTable);
    numberOfLayers = size(layersTable,1);
    
    for i = 1:numberOfLayers
        thisLayer = layersTable(i,:);
        
        thisLayerName = char(thisLayer{1});
        thisLayerThick = char(thisLayer{2});
        thisLayerSLD = char(thisLayer{3});
        thisLayerRough = char(thisLayer{4});
        thisLayerHydr = char(thisLayer{5});
        thisLayerHydrWhat = char(thisLayer{6});
        
        thisThickInd = find(strcmpi(thisLayerThick,r1Problem.paramnames));
        thisSLDInd = find(strcmpi(thisLayerSLD,r1Problem.paramnames));
        thisRoughInd = find(strcmpi(thisLayerRough,r1Problem.paramnames));
        thisHydrInd = find(strcmpi(thisLayerHydr,r1Problem.paramnames));
        
        if strcmpi(thisLayerHydrWhat,'bulk out')
            hydrWhat = 'bulk out';
        else
            hydrWhat = 'bulk in';
        end
        
        newLayerCell = {thisThickInd,thisSLDInd,thisRoughInd,thisHydrInd,thisLayerName,hydrWhat};
        newLayersDetails{i} = newLayerCell;
        layersNames{i} = thisLayerName;
    end

else
    % If it's not layers, then set up the relevant custom model..
    newLayersDetails = {};
    numberOfLayers = 0;
    
    % Get the custom file name..
    customFiles = r2Problem.customFile.toStruct().files{:};
    customFiles = customFiles(1,:); % Only ever 1 custom file in R1
    customFileName = customFiles{1};
    
    cd(originalDir);
    copyfile(customFileName,dirName);
    cd(dirName);
    
    
end

%% Deal with the data and contrasts
dataClass = r2Problem.data;         % Data class object
contrasts = r2Problem.contrasts;    % Contrasts class object

% Ensure contrasts table has been built (normally only happens when
% contrast class is displayed
r2Problem.contrasts.makeContrastsTable();

numberOfContrasts = contrasts.numberOfContrasts;
r1Problem.numberOfContrasts = numberOfContrasts;

contrastBacks = zeros(numberOfContrasts,1);
contrastScales = zeros(numberOfContrasts,1);
contrastShifts = ones(numberOfContrasts,1);
contrastResolutions = zeros(numberOfContrasts,1);
contrastNbas = zeros(numberOfContrasts,1);
contrastNbss = zeros(numberOfContrasts,1);
contrastLayers = cell(numberOfContrasts,1);
contrastsNumberOfLayers = zeros(numberOfContrasts,1);
forceReload = zeros(numberOfContrasts,1);

simLimits = cell(numberOfContrasts,1);
dataLimits = cell(numberOfContrasts,1);
fitlowrange = zeros(numberOfContrasts,1);
fithirange = zeros(numberOfContrasts,1);

data = cell(numberOfContrasts,1);
contrastNames = cell(numberOfContrasts,1);
contrastFiles = cell(numberOfContrasts,1);
dataPath = {};
contrastTable = table2cell(contrasts.contrastsTable);

for i = 1:numberOfContrasts
    thisContrast = contrasts.contrasts{i};
    
    % The the relative components
    thisName = thisContrast.name;
    thisNba = thisContrast.nba;
    thisNbs = thisContrast.nbs;
    thisResol = thisContrast.resolution;
    thisScale = thisContrast.scalefactor;
    thisBack = thisContrast.background;
    
    % Get the relevant data from the r2 project
    contrastNames{i} = thisName;
    
    % Nba..
    bulkInLoc = strfind(bulkInNames,thisNba);
    bulkInIndex = find(not(cellfun('isempty',bulkInLoc)));
    contrastNbas(i) = bulkInIndex;
    
    % Nbs
    bulkOutLoc = strfind(bulkOutNames,thisNbs);
    bulkOutIndex = find(not(cellfun('isempty',bulkOutLoc)));
    contrastNbss(i) = bulkOutIndex;
    
    % Scalefactors
    scaleLoc = strfind(scalesNames,thisScale);
    scaleIndex = find(not(cellfun('isempty',scaleLoc)));
    contrastScales(i) = scaleIndex;
   
    % Resol
    % Find the resol name in the resolutions struct
    resolutionNames = r2ResolStruct.resolutionNames;
    thisResolInd = find(strcmp(resolutionNames,thisResol));
    
    % Find which resolution par this is..
    thisResolParName = r2ResolStruct.resolutionValues{thisResolInd,1};
    resolParNames = r2ResolStruct.resolParNames;    
    thisResolParInd = find(strcmp(resolParNames,thisResolParName));
    contrastResolutions(i) = thisResolParInd;
    
    % Backgrounds
    % Find the Background name in the backgrounds struct
    backgroundNames = r2BackStruct.backgroundNames;
    thisBacksInd = find(strcmp(backgroundNames,thisBack));
    
    % Find which resolution par this is..
    thisBacksParName = r2BackStruct.backgroundValues{thisBacksInd,1};
    backParNames = r2BackStruct.backParNames;    
    thisBackParInd = find(strcmp(backParNames,thisBacksParName));
    contrastBacks(i) = thisBackParInd;

    % Data
    dataTable = table2cell(dataClass.dataTable);
    r2DataNames = dataTable(:,1);
    r2DataNames = cellfun(@(x)char(x), r2DataNames, 'UniformOutput', false);
    thisContrastData = thisContrast.data;
    thisContrastLocation = find(strcmp(r2DataNames,thisContrastData));
    thisData = dataTable{thisContrastLocation,2};
    thisSimLimits = dataTable{thisContrastLocation,4};
    thisDataLimits = dataTable{thisContrastLocation,3};
    data{i} = thisData;
    simLimits{i} = thisSimLimits;
    dataLimits{i} = thisDataLimits;
    
    fitlowrange(i) = thisDataLimits(1);
    fithirange(i) = thisDataLimits(2);
    
    if ~strcmpi(thisContrastData,'simulation')
        dataPresent(i) = 1;
        include_data(i) = 1;
        dataTypes{i} = 'Ascii File';
    else
        dataPresent(i) = 0;
        include_data(i) = 0;
        dataTypes{i} = 'Simulation';
    end
    
    % Now deal with the model. Depends on whether it is standard layers or
    % a custom model.
    if strcmpi(type,'standard layers')
        % Set up the contrastLayers strings
        % Get the model for this contrast
        model = thisContrast.model;
        thisLayerString = '';
        for n = 1:length(model)
            thisLay = model{n};
            thisLayNum = find(strcmpi(layersNames,thisLay));
            thisLayChar = sprintf('%s,',num2str(thisLayNum));
            thisLayerString = [thisLayerString thisLayChar];
        end
        contrastLayers{i} = thisLayerString;
        contrastsNumberOfLayers = length(model);
        customFileName = '';
    else
        % We are using a custom model
        whichCustom = thisContrast.model{:};
        fileTable = table2cell(r2Problem.customFile.fileTable);
        customNames = fileTable(:,1);
        customNames = cellfun(@(x)char(x), customNames, 'UniformOutput', false);
        thisCustomLocation = find(strcmp(customNames,whichCustom));
        customFileName = char(fileTable{thisCustomLocation,2});
        contrastLayers{i} = '';
        contrastsNumberOfLayers(i) = 0;
    end
    contrastRepeatSLDs{i} = [0 1];
end

r1Problem.contrastTypes = dataTypes;

%%
%r1Problem.module.name = customFileName;
r1Problem.contrastNames = contrastNames;
r1Problem.contrastNbas = contrastNbas;
r1Problem.contrastNbss = contrastNbss;
r1Problem.contrastScales = contrastScales;
r1Problem.contrastShifts = contrastShifts;
r1Problem.contrastResolutions = contrastResolutions;
r1Problem.contrastBacks = contrastBacks;
r1Problem.data = data;
r1Problem.include_data = include_data;
r1Problem.dataPresent = dataPresent;
r1Problem.contrastLayers = contrastLayers;
r1Problem.contrastsNumberOfLayers = contrastsNumberOfLayers;
% Put everything into the R1 problem
r1Problem.layersDetails = newLayersDetails;
r1Problem.numberOfLayers = numberOfLayers;    
r1Problem.module.name = customFileName;
r1Problem.forceReload = forceReload;
r1Problem.dataLimits = dataLimits;
r1Problem.simLimits = simLimits;
r1Problem.fitlowrange = fitlowrange;
r1Problem.fithirange = fithirange;
r1Problem.repeatLayers = contrastRepeatSLDs;

% Finally need to actually fill in some calculation results in the r1
% model. We can do this using RAT...

controls = controlsDef;
controls.display = 'off';
[~,results] = RAT(r2Problem,controls);

r1Problem.shifted_data = results.shifted_data;
r1Problem.calculations.Simulation = results.Simulation;
r1Problem.calculations.reflectivity = results.reflectivity;
r1Problem.calculations.slds = results.sldProfiles;
r1Problem.calculations.all_chis = results.calculationResults.all_chis;
r1Problem.calculations.sum_chi = results.calculationResults.sum_chi;

newR1Problem = r1Problem;

% If the save project flag is set, then save the new peoject
if saveTheProject
    
    % Save and name the datafiles, and set the paths, data filenames in the 
    % r1problem
    
    data = r1Problem.data;
    for i = 1:length(data)
        thisData = data{i};
        thisFileName = sprintf([fileName,'_dataFile_%s'],num2str(i));
        contrastFiles{i} = thisFileName;
        fullDataFileName = fullfile(fullName,'datafiles',thisFileName);
        dlmwrite(fullDataFileName,thisData);
    end
    problem = r1Problem;
    problem.contrastFiles = contrastFiles;
    
    [p,n,e] = fileparts(fileName);
    if isempty(e)
        e = '.mat';
    end
    filename = [n,e];
    fullFileName = fullfile(fullName,filename);
    save(fullFileName,'problem');
end

end

function inputBlock = (varargin)

    default_r1Problem = struct('empty',0);
    default_dirName = 'newDirectory';   
    default_saveProject = true;
    default_dirPath = pwd;
    default_fileName = sprintf('newFile_%s',datestr(now));

    p = inputParser;
    addParameter(p,'r1Problem',     default_r1Problem,      @isstruct);
    addParameter(p,'dirName',       default_dirName,        @ischar);
    addParameter(p,'dirPath',       default_dirPath,        @ischar);
    addParameter(p,'saveProject',   default_saveProject,    @islogical);
    addParameter(p,'fileName',      default_fileName,       @ischar);
    
    inputVals = varargin{:};
    
    parse(p,inputVals{:});
    inputBlock = p.Results;
    
    % Check the r1Problem really is one by making sure it has the bare
    % minimum of field names
    if ~isequal(inputBlock.r1Problem,(struct('empty',0)))
        r1FieldNames = getR1FieldNames();
        newNames = fieldnames(inputBlock.r1Problem);
        diffs = setdiff(newNames,r1FieldNames);
        
        allowedDiffs = {'priors' ; 'resampleAngle'; 'resampleNLayers';...
            'fitpars' ; 'otherpars'; 'fitnames'};
        
        actualDiffs = intersect(diffs,allowedDiffs);
        
        if ~isequal(actualDiffs,diffs)
            error('Can''t recognise inputted r1Problem');
        end
    end
    
end


function names = getR1FieldNames()

names =     {'path'          ;        
    'name'                   ;
    'numberOfContrasts'      ;
    'module'                 ;
    'paramnames'             ;
    'constr'                 ;
    'params'                 ;
    'fityesno'               ;
    'fiterrs'                ;
    'numberOfLayers'         ;
    'layersDetails'          ;
    'numberOfBacks'          ;
    'backgrounds_fityesno'   ;
    'backsNames'             ;
    'backs_constr'           ;
    'backs'                  ;
    'numberOfShifts'         ;
    'shifts_fityesno'        ;
    'shiftsNames'            ;
    'shifts_constr'          ;
    'shifts_horisontal'      ;
    'numberOfScales'         ;
    'scalefac_fityesno'      ;
    'scalesNames'            ;
    'scale_constr'           ;
    'scalefac'               ;
    'numberOfNbas'           ;
    'nbairs_fityesno'        ;
    'nbaNames'               ;
    'nbairs_constr'          ;
    'nba'                    ;
    'numberOfNbss'           ;
    'nbsubs_fityesno'        ;
    'nbsNames'               ;
    'nbsubs_constr'          ;
    'nbs'                    ;
    'numberOfResolutions'    ;
    'resolution_fityesno'    ;
    'resolNames'             ;
    'resolution_constr'      ;
    'resolution'             ;
    'contrastTypes'          ;
    'contrastFileTypes'      ;
    'forceReload'            ;
    'simLimits'              ;
    'dataLimits'             ;
    'fitlowrange'            ;
    'fithirange'             ;
    'repeatLayers'           ;
    'datapath'               ;
    'contrastFiles'          ;
    'contrastNames'          ;
    'contrastBacks'          ;
    'contrastScales'         ;
    'contrastShifts'         ;
    'contrastResolutions'    ;
    'contrastNbas'           ;
    'contrastNbss'           ;
    'contrastLayers'         ;
    'contrastsNumberOfLayers';
    'ogDetails'              ;
    'data'                   ;
    'include_data'           ;
    'dataPresent'            ;
    'calculations'           ;
    'algorithm'              ;
    'eb'                     ;
    'plotType'               ;
    'dataShiftValue'         ;
    'q4'                     ;
    'useReducedChiSquared'   ;
    'simNPoints'             ;
    'backgrounds'            ;
    'qshifts'                ;
    'scalefactors'           ;
    'nbairs'                 ;
    'nbsubs'                 ;
    'resolutions'            ;
    'fitpars'                ;
    'otherpars'              ;
    'fitconstr'              ;
    'otherconstr'            ;
    'fitNames'               ;
    'shifted_data'           ;
    'update'                 ;
    'update_params'          ;
    'maxiter'                ;
    'Update'                 ;
    'calcSLD'                ;
    'resolType'              ;
    'resample'};

end




