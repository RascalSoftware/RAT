function newR1Problem = projectClassToR1(r2Problem, varargin)
% Converts projectClass to r1 struct. Also creates the datafiles directory and saves the 
% data if asked. The functions takes in a projectClass and other optional arguments then 
% outputs r1 struct. The optional arguments are:
%
% r1Problem (struct):    The r1 struct which is updated with equivalent projectClass values. 
%                        [default] defaultProject.mat.
% dirName (char):        The directory where the files are saved. 
%                        [default] newDirectory.
% dirPath (char):        The path where the new directory is created. 
%                        [default] current directory (pwd).
% saveproject (logical): A boolean that determines if files are saved. 
%                        [default] true.
% fileName (char): The filename of the resulting r1 struct. 
%                  [default] newFile appended with current timestamp.
%
% r1Struct = projectClassToR1(pClass, 'saveProject', false);

if ~isempty(varargin)
    pars = parseR1Problem(varargin{:});
    saveTheProject = pars.saveProject;
    fileName = pars.fileName;
    dirName = pars.dirName;
    dirPath = pars.dirPath;
    fullName = fullfile(dirPath, dirName);
    originalDir = pwd;

    r1Problem = pars.r1Problem;
    if isfield(r1Problem,'empty')
        % load default project if r1Problem not provided
        r1Problem = load('defaultProject.mat').problem;
    end

    if ~exist(fullName,'dir') && saveTheProject
        % Create directory if it does not exist
        mkdir(fullName, 'datafiles');
    end
end

% Set name, type and experiment_type
r1Problem.name = r2Problem.experimentName;
r1Problem.module.type = r2Problem.modelType;
r1Problem.module.experiment_type = r2Problem.geometry;

% Set parameter names, values, limits and check boxes
r2ParamStruct = r2Problem.parameters.toStruct();
r1Problem.params = r2ParamStruct.values;
r1Problem.paramnames = r2ParamStruct.names;
r1Problem.constr = vertcat(r2ParamStruct.limits{:});
r1Problem.fityesno = r2ParamStruct.fit;

% Set qz shifts
r1Problem.numberOfShifts = 1;
r1Problem.shiftsNames = {'Shift 1'};
[r1Problem.shifts_horisontal, r1Problem.shifts_fityesno] = deal(0);
r1Problem.shifts_constr = [-1e-4 1e-4];

% Set scalefactors
r2ScalesStruct = r2Problem.scalefactors.toStruct();
r1Problem.scalesNames = r2ScalesStruct.names;
r1Problem.scalefac = r2ScalesStruct.values;
r1Problem.numberOfScales = length(r2ScalesStruct.names);
r1Problem.scale_constr = vertcat(r2ScalesStruct.limits{:});
r1Problem.scalefac_fityesno = r2ScalesStruct.fit;

% Set bulk in
r2BulkInStruct = r2Problem.bulkIn.toStruct();
r1Problem.nbaNames = r2BulkInStruct.names;
r1Problem.nba = r2BulkInStruct.values;
r1Problem.numberOfNbas = length(r2BulkInStruct.names);
r1Problem.nbairs_constr = vertcat(r2BulkInStruct.limits{:});
r1Problem.nbairs_fityesno = r2BulkInStruct.fit;

% Set bulk out
r2BulkOutStruct = r2Problem.bulkOut.toStruct();
r1Problem.nbsNames = r2BulkOutStruct.names;
r1Problem.nbs = r2BulkOutStruct.values;
r1Problem.numberOfNbss = length(r2BulkOutStruct.names);
r1Problem.nbsubs_constr = vertcat(r2BulkOutStruct.limits{:});
r1Problem.nbsubs_fityesno = r2BulkOutStruct.fit;

% Set resolutions (only use resolutionparams - more advanced resolutions
% unavaliable in R1)
r2ResolStruct = r2Problem.resolution.toStruct();
r1Problem.resolNames = r2ResolStruct.resolutionParamNames;
r1Problem.resolution = r2ResolStruct.resolutionParamValues;
r1Problem.numberOfResolutions = length(r2ResolStruct.resolutionParamNames);
r1Problem.reslution_constr = vertcat(r2ResolStruct.resolutionParamLimits{:});
r1Problem.resolution_fityesno = r2ResolStruct.fitResolutionParam;

% Set Backgrounds
r2BackStruct = r2Problem.background.toStruct();
r1Problem.backsNames = r2BackStruct.backgroundParamNames;
r1Problem.backs = r2BackStruct.backgroundParamValues;
r1Problem.numberOfBacks = length(r2BackStruct.backgroundParamNames);
r1Problem.backs_constr = vertcat(r2BackStruct.backgroundParamLimits{:});
r1Problem.backgrounds_fityesno = r2BackStruct.fitBackgroundParam;

if strcmpi(r2Problem.modelType, modelTypes.StandardLayers.value)
    % Set layers (if modelType is standard layers)
    layersTable = table2cell(r2Problem.layers.varTable);
    numberOfLayers = size(layersTable,1);
    
    for i = 1:numberOfLayers
        thisLayer = layersTable(i,:);
        thisLayerName = char(thisLayer{1});
        thisThickInd = find(strcmpi(char(thisLayer{2}), r1Problem.paramnames));
        thisSLDInd = find(strcmpi(char(thisLayer{3}), r1Problem.paramnames));
        thisRoughInd = find(strcmpi(char(thisLayer{4}), r1Problem.paramnames));
        thisHydrInd = find(strcmpi(char(thisLayer{5}), r1Problem.paramnames));
        thisLayerHydrWhat = char(thisLayer{6});

        if strcmpi(thisLayerHydrWhat, hydrationTypes.BulkOut.value)
            hydrWhat = hydrationTypes.BulkOut.value;
        else
            hydrWhat = hydrationTypes.BulkIn.value;
        end
        
        newLayersDetails{i} = {thisThickInd, thisSLDInd, thisRoughInd, thisHydrInd, thisLayerName, hydrWhat};
        layersNames{i} = thisLayerName;
    end
else
    % Set up custom model (if modelType not standard layers)
    newLayersDetails = {};
    numberOfLayers = 0;
    
    % Get the custom file name..
    customFileName = r2Problem.customFile.varTable{1, 2}; % Only ever 1 custom file in R1
    
    copyfile(fullfile(originalDir, customFileName), dirName);
end

% Set contrasts           
numberOfContrasts = r2Problem.contrasts.numberOfContrasts;
r1Problem.numberOfContrasts = numberOfContrasts;

[contrastBacks, contrastScales, contrastResolutions, contrastBulkIns, contrastBulkOuts, contrastsNumberOfLayers, forceReload, fitlowrange, fithirange] = deal(zeros(numberOfContrasts, 1));
contrastShifts = ones(numberOfContrasts, 1);
[contrastLayers, simLimits, dataLimits, data, contrastNames, contrastFiles] = deal(cell(numberOfContrasts, 1));

for i = 1:numberOfContrasts

    thisContrast = r2Problem.contrasts.contrasts{i};
    
    contrastNames{i} = thisContrast.name;
    
    % Bulk In
    bulkInLoc = strfind(r2BulkInStruct.names, thisContrast.bulkIn);
    contrastBulkIns(i) = find(not(cellfun('isempty', bulkInLoc)));
    
    % Bulk Out
    bulkOutLoc = strfind(r2BulkOutStruct.names, thisContrast.bulkOut);
    contrastBulkOuts(i) = find(not(cellfun('isempty', bulkOutLoc)));
    
    % scalefactors
    scaleLoc = strfind(r1Problem.scalesNames, thisContrast.scalefactor);
    contrastScales(i) = find(not(cellfun('isempty', scaleLoc)));
   
    % resol (find the resol name in the resolutions struct)
    resolutionNames = r2ResolStruct.resolutionNames;
    thisResolInd = find(strcmp(resolutionNames, thisContrast.resolution));
    
    % find which resolution par this is..
    thisResolutionParamName = r2ResolStruct.resolutionValues{thisResolInd, 1};
    contrastResolutions(i) = find(strcmp(r2ResolStruct.resolutionParamNames, thisResolutionParamName));
    
    % backgrounds (find the background name in the backgrounds struct)
    backgroundNames = r2BackStruct.backgroundNames;
    thisBacksInd = find(strcmp(backgroundNames, thisContrast.background));
    
    % find which backs par this is..
    thisBackgroundParamName = r2BackStruct.backgroundValues{thisBacksInd, 1};
    contrastBacks(i) = find(strcmp(r2BackStruct.backgroundParamNames, thisBackgroundParamName));

    % data
    dataTable = table2cell(r2Problem.data.varTable);
    r2DataNames = dataTable(:,1);
    r2DataNames = cellfun(@(x)char(x), r2DataNames, 'UniformOutput', false);
    thisContrastData = thisContrast.data;
    thisContrastLocation = find(strcmpi(r2DataNames,thisContrastData));
    data{i} = dataTable{thisContrastLocation,2};
    simLimits{i} = dataTable{thisContrastLocation,4};
    dataLimits{i} = dataTable{thisContrastLocation,3};
    fitlowrange(i) = dataTable{thisContrastLocation,3}(1);
    fithirange(i) = dataTable{thisContrastLocation,3}(2);
    
    if ~strcmpi(thisContrastData,'simulation')
        dataPresent(i) = 1;
        include_data(i)= 1;
        dataTypes{i} = 'Ascii File';
    else
        dataPresent(i) = 0;
        include_data(i) = 0;
        dataTypes{i} = 'Simulation';
    end
    
    if strcmpi(r2Problem.modelType, modelTypes.StandardLayers.value)
        % If modelType is StandardLayers
        % Set up the contrastLayers strings
        % Get the model for this contrast
        model = thisContrast.model;
        contrastsNumberOfLayers = length(model);
        thisLayerString = '';
        for n = 1:contrastsNumberOfLayers
            thisLay = model{n};
            thisLayNum = find(strcmpi(layersNames, thisLay));
            thisLayChar = sprintf('%s,',num2str(thisLayNum));
            thisLayerString = [thisLayerString thisLayChar];
        end
        contrastLayers{i} = thisLayerString;
        customFileName = '';
    else
        % % If modelType is NOT StandardLayers (custom model)
        whichCustom = thisContrast.model{:};
        varTable = table2cell(r2Problem.customFile.varTable);
        customNames = varTable(:,1);
        customNames = cellfun(@(x)char(x), customNames, 'UniformOutput', false);
        thisCustomLocation = find(strcmp(customNames,whichCustom));
        customFileName = char(varTable{thisCustomLocation, 2});
        contrastLayers{i} = '';
        contrastsNumberOfLayers(i) = 0;
    end
    contrastRepeatSLDs{i} = [0 1];
end

% Put everything into the R1 problem
r1Problem.contrastTypes = dataTypes;
r1Problem.contrastNames = contrastNames;
r1Problem.contrastNbas = contrastBulkIns;
r1Problem.contrastNbss = contrastBulkOuts;
r1Problem.contrastScales = contrastScales;
r1Problem.contrastShifts = contrastShifts;
r1Problem.contrastResolutions = contrastResolutions;
r1Problem.contrastBacks = contrastBacks;
r1Problem.data = data;
r1Problem.include_data = include_data;
r1Problem.dataPresent = dataPresent;
r1Problem.contrastLayers = contrastLayers;
r1Problem.contrastsNumberOfLayers = contrastsNumberOfLayers;
r1Problem.layersDetails = newLayersDetails;
r1Problem.numberOfLayers = numberOfLayers;    
r1Problem.module.name = customFileName;
r1Problem.forceReload = forceReload;
r1Problem.dataLimits = dataLimits;
r1Problem.simLimits = simLimits;
r1Problem.fitlowrange = fitlowrange;
r1Problem.fithirange = fithirange;
r1Problem.repeatLayers = contrastRepeatSLDs;

% Set calculation results in the r1 model using RAT
controls = controlsClass;
controls.display = displayOptions.Off.value;
[~,results] = RAT(r2Problem, controls);

r1Problem.shifted_data = results.shiftedData;
r1Problem.calculations.Simulation = results.simulation;
r1Problem.calculations.reflectivity = results.reflectivity;
r1Problem.calculations.slds = results.sldProfiles;
r1Problem.calculations.all_chis = results.calculationResults.chiValues;
r1Problem.calculations.sum_chi = results.calculationResults.sumChi;

newR1Problem = r1Problem;

if saveTheProject
    % save new peoject if the save flag set
    % Save datafiles, set paths and data filenames
    data = r1Problem.data;
    for i = 1:length(data)
        thisData = data{i};
        thisFileName = sprintf([fileName,'Datafile%s'],num2str(i));
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

function inputBlock = parseR1Problem(varargin)

    default_r1Problem = struct('empty',0);
    default_dirName = 'newDirectory';   
    default_saveProject = true;
    default_dirPath = pwd;
    dateNow = datestr(now,'mm-dd-yyyy HH.MM.SS.FFF');
    default_fileName = sprintf('newFile%s', dateNow);

    p = inputParser;
    addParameter(p,'r1Problem',     default_r1Problem,      @isstruct);
    addParameter(p,'dirName',       default_dirName,        @isText);
    addParameter(p,'dirPath',       default_dirPath,        @isText);
    addParameter(p,'saveProject',   default_saveProject,    @islogical);
    addParameter(p,'fileName',      default_fileName,       @isText);
    
    parse(p, varargin{:});
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
            throw(exceptions.unrecognizedR1Problem);
        end
    end
    
end


function names = getR1FieldNames()

names = {
    'path'                   ;        
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
