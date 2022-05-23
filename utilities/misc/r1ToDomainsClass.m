function thisProjectClass = r1ToProjectClass(r1Problem)

%Load in the R1 problem....
r1Problem = load(r1Problem);
problem = r1Problem.problem;

% Set the project name from
% the name of the r1Problem
if iscell(problem.name)
    thisName = problem.name{:};
else
    thisName = problem.name;
end

% make an empty instance of projectClass
% with this name
thisProjectClass = domainsClass(thisName);

% Start by setting the geometry
% and project type.
oldGeometry = problem.module.experiment_type;
oldType = problem.module.type;

if strcmpi(oldType,'Standard Layers')
    thisProjectClass.setModelType('standard layers');
elseif strcmpi(oldType,'Custom Layers')
    thisProjectClass.setModelType('custom layers');
else
    thisProjectClass.setModelType('custom xy');
end
    

if strcmpi(oldGeometry,'Air / Liquid (or solid)')
    thisProjectClass.setGeometry('air/substrate');
else
    thisProjectClass.setGeometry('substrate/liquid');
end

% Now set the parameters block
numberOfParams = length(problem.params);

for i = 2:numberOfParams
    thisName = problem.paramnames{i};
    thisMin = problem.constr(i,1);
    thisValue = problem.params(i);
    thisMax = problem.constr(i,2);
    thisFit = problem.fityesno(i);
    
    if thisFit == 1
        thisFit = true;
    else
        thisFit = false;
    end
    
    thisParam = {thisName thisMin thisValue thisMax thisFit};
    thisProjectClass.addParam(thisParam);
end

% Also set the substrate roughness parameters
thisMin = problem.constr(1,1);
thisMax = problem.constr(1,2);
thisVal = problem.params(1);
thisName = problem.paramnames{1};
thisFit = logical(problem.fityesno(1));
thisProjectClass.setParameter(1,'min',thisMin','max',thisMax','value',thisVal,'fit',thisFit,'name',thisName);

% If we have a standard layers problem, set the layers block
switch lower(oldType)
    case 'standard layers'
      
        disp('debug');
        nLayers = problem.numberOfLayers;
        
        for i = 1:nLayers
            thisLayer = problem.layersDetails{i};
            thisName = thisLayer{5};
            
            thisThickNum = thisLayer{1};%str2double(thisLayer{1});
            thisThick = problem.paramnames{thisThickNum};
            
            thisSldNum = thisLayer{2};%str2double(thisLayer{2});
            thisSld = problem.paramnames{thisSldNum};
            
            thisRoughNum = thisLayer{3};%str2double(thisLayer{3});
            thisRough = problem.paramnames{thisRoughNum};
            
            thisHydrPar = thisLayer{4};
            if isempty(thisHydrPar)
                thisHydr = '';
            else
                thisHydrNum = thisHydrPar;%str2double(thisLayer{4});
                thisHydr = problem.paramnames{thisHydrNum};
            end
            
            thisHydrWhat = thisLayer{6};
            if isempty(thisHydrPar)
                thisLayer = {thisName, thisThick, thisSld, thisRough};%, thisHydr, thisHydrWhat};
            else    
                thisLayer = {thisName, thisThick, thisSld, thisRough, thisHydr, thisHydrWhat};
            end
            thisProjectClass.addLayer(thisLayer); 
        end 
    otherwise
        % Need the name of the custom file...
        customFile = problem.module.name;
        [~,modelName,~] = fileparts(customFile);
        
        thisProjectClass.addCustomFile({modelName,customFile,'matlab','pwd'});
        
end


% Backgrounds
nBackgrounds = problem.numberOfBacks;

% First make the backsPars:
% Remove the default backs par first
thisProjectClass.removeBacksPar(1);

% Also remove the default background
thisProjectClass.removeBackground(1);

for i = 1:nBackgrounds
    % Add backgrounds parameter
    thisName = sprintf('Backs parameter %d',i);
    thisMin = problem.backs_constr(i,1);
    thisMax = problem.backs_constr(i,2);
    thisVal = problem.backs(i);
    thisFit = logical(problem.backgrounds_fityesno(i));
    thisProjectClass.addBacksPar(thisName, thisMin, thisVal, thisMax, thisFit);
    
    % Now add the backgrounds themselves
    thisBackgroundName = problem.backsNames{i};
    thisProjectClass.addBackground(thisBackgroundName,'constant',thisName);
end


% Bulk in
% Remove the default
thisProjectClass.removeBulkIn(1);
nNba = problem.numberOfNbas;

% Add the new bulk in params
for i = 1:nNba
    thisName = problem.nbaNames{i};
    thisMin = problem.nbairs_constr(i,1);
    thisMax = problem.nbairs_constr(i,2);
    thisNba = problem.nba(i);
    thisFit = logical(problem.nbairs_fityesno(i));
    thisProjectClass.addBulkIn({thisName, thisMin, thisNba, thisMax, thisFit});
end

% Bulk out
% Remove the default
thisProjectClass.removeBulkOut(1);
nNbs = problem.numberOfNbss;

% Add the new bulk in params
for i = 1:nNbs
    thisName = problem.nbsNames{i};
    thisMin = problem.nbsubs_constr(i,1);
    thisMax = problem.nbsubs_constr(i,2);
    thisNbs = problem.nbs(i);
    thisFit = logical(problem.nbsubs_fityesno(i));
    thisProjectClass.addBulkOut({thisName, thisMin, thisNbs, thisMax, thisFit});
end

% Scalefactors
thisProjectClass.removeScalefactor(1);
nScales = problem.numberOfScales;

for i = 1:nScales
    thisName = problem.scalesNames{i};
    thisMin = problem.scale_constr(i,1);
    thisMax = problem.scale_constr(i,2);
    thisNbs = problem.scalefac(i);
    thisFit = logical(problem.scalefac_fityesno(i));
    thisProjectClass.addScalefactor({thisName, thisMin, thisNbs, thisMax, thisFit});
end

% Data block
dataFiles = problem.data;

for i = 1:length(dataFiles)
    thisData = dataFiles{i};
    thisDataName = sprintf('Datafile %d',i);
    thisProjectClass.addData(thisDataName,thisData);
    thisDataRange = problem.dataLimits{i};
    thisSimRange = problem.simLimits{i};
    thisProjectClass.setData(i,'dataRange',thisDataRange,'simRange',thisSimRange);
end

% Resolutions
%thisProjectClass.remove

% Make the contrasts
numberOfContrasts = problem.numberOfContrasts;

for i = 1:numberOfContrasts
    thisName = char(problem.contrastNames{1});
    
    thisBackgroundNumber = problem.contrastBacks(i);
    thisBackground = char(thisProjectClass.background.backgrounds.typesTable{thisBackgroundNumber,1});

    thisResolNum = problem.contrastResolutions(i);
    thisResol = problem.resolNames{thisResolNum};
    
    thisScaleNum = problem.contrastScales(i);
    thisScale = problem.scalesNames{thisScaleNum};
    
    thisNbsNum = problem.contrastNbss(i);
    thisNbs = problem.nbsNames{thisNbsNum};
    
    thisNbaNum = problem.contrastNbas(i);
    thisNba = problem.nbaNames{thisNbaNum};
    
    thisData = thisProjectClass.data.dataTable{i+1,1};
    
    thisProjectClass.addReflContrast('name', thisName,...
        'backGround', thisBackground,...
        'resolution', thisResol,...
        'scalefactor', thisScale,...
        'nbs', thisNbs,...
        'nba', thisNba,...
        'data', char(thisData));
end

% Now set the model for each of the contrasts:
switch lower(oldType)
    case 'standard layers'
        error('Standard layers in not yet implemented for domains contrasts');
%         for i = 1:numberOfContrasts
%            thisContrastLayers = str2num(problem.contrastLayers{i});
%            thisLayersList = {};
%            for n = 1:length(thisContrastLayers)
%                thisLayersList{n} = problem.layersDetails{thisContrastLayers(n)}{5};
%            end
%            thisProjectClass.setContrastModel(i,thisLayersList); 
%         end
        
    otherwise
        for i = 1:numberOfContrasts
            thisProjectClass.setReflContrastModel(i,modelName);
        end
end


disp('debug');

end