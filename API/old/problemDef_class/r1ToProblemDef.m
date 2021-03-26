function [thisProblemDef,thisControlsDef] = r1ToProblemDef(r1Problem)

%--------------------------------------------------------------------------
%
%               Copies a Rascal 1 project to new
%               problemDef class for use in RAT.
%               Also makes the controls block
%
%--------------------------------------------------------------------------



%start by making empty default problemDef class.
thisProblemDef = problemDef();
thisControlsDef = controlsDef();
%controls = makeControls();

%Load in the R1 problem....
r1Problem = load(r1Problem);
problem = r1Problem.problem;


numberOfContrasts = length(problem.simLimits);

thisProblemDef.numberOfContrasts = numberOfContrasts;
thisProblemDef.resample = zeros(1,numberOfContrasts);
oldGeometry = problem.module.experiment_type;

if strcmpi(oldGeometry,'Air / Liquid (or solid)')
    thisProblemDef.experimentGeometry = 'air/substrate';
else
    thisProblemDef.experimentGeometry = 'substrate/liquid';
end

thisProblemDef.nBackgrounds = length(problem.backs);
thisProblemDef.backgrounds = problem.backs;
thisProblemDef.backgroundNames = problem.backsNames;
for n = 1:length(problem.backs)
    thisProblemDef.backgroundConstr{n} = problem.backs_constr(n,:);
end

thisProblemDef.nQzshifts = length(problem.shifts_horisontal);
thisProblemDef.qzshifts = problem.shifts_horisontal;
thisProblemDef.qzshiftNames = problem.shiftsNames;
for n = 1:length(problem.shifts_horisontal)
    thisProblemDef.qzshiftConstr{n} = problem.shifts_constr(n,:);
end

thisProblemDef.nScalefactors = length(problem.scalefac);
thisProblemDef.scalefactors = problem.scalefac;
thisProblemDef.scalefactorNames = problem.scalesNames;
for n = 1:length(problem.scalefac)
    thisProblemDef.scalefactorConstr{n} = problem.scale_constr(n,:);
end

thisProblemDef.nNbairs = length(problem.nba);
thisProblemDef.nbairs = problem.nba;
thisProblemDef.nbairNames = problem.nbaNames;
for n = 1:length(problem.nba)
    thisProblemDef.nbairConstr{n} = problem.nbairs_constr(n,:);
end

thisProblemDef.nNbsubs = length(problem.nbs);
thisProblemDef.nbsubs = problem.nbs;
thisProblemDef.nbsubNames = problem.nbsNames;
for n = 1:length(problem.nbs)
    thisProblemDef.nbsubConstr{n} = problem.nbsubs_constr(n,:);
end

thisProblemDef.nResolutions = length(problem.resolution);
thisProblemDef.resolutions = problem.resolution;
thisProblemDef.resolutionNames = problem.resolNames;
for n = 1:length(problem.resolution)
    thisProblemDef.resolutionConstr{n} = problem.resolution_constr(n,:);
end


thisProblemDef.dataPresent = problem.dataPresent;
thisProblemDef.allData = problem.data;
thisProblemDef.dataLimits = problem.dataLimits;
thisProblemDef.simLimits = problem.simLimits;
for i = 1:length(problem.repeatLayers)
    thisProblemDef.contrastRepeatSLDs{i} = problem.repeatLayers{i};
end
thisProblemDef.nParams = length(problem.params);
thisProblemDef.params = problem.params;
thisProblemDef.paramNames = problem.paramnames;
thisProblemDef.contrastLayers = problem.contrastLayers;
thisProblemDef.numberOfLayers = problem.numberOfLayers;
%problemDef.layersDetails = problem.layersDetails;
%thisProblemDef.whichType = []; %Er.... what's this???
% thisProblemDef.modelFilename = '';
% thisProblemDef.modelLanguage = 'matlab';

%Use the new method for backgrounds
theseCBacks = problem.contrastBacks;
newCbacks = cell(1,length(theseCBacks));
for i = 1:length(theseCBacks)
    newCbacks{i} = [theseCBacks(i) 1];
end
thisProblemDef.contrastBacks = newCbacks;
thisProblemDef.contrastShifts = problem.contrastShifts;
thisProblemDef.contrastScales = problem.contrastScales;
thisProblemDef.contrastNbas = problem.contrastNbas;
thisProblemDef.contrastNbss = problem.contrastNbss;
thisProblemDef.contrastRes = problem.contrastResolutions;

if strcmpi(problem.module.type,'standard layers')
    
    thisProblemDef.modelType = 'layers';
    
    %Some extra work to be done with layers
    %details because they are a different format.
    for i = 1:length(problem.layersDetails)
        thisLayer = problem.layersDetails{i};
        newLayer(1) = str2double(thisLayer{1});
        newLayer(2) = str2double(thisLayer{2});
        newLayer(3) = str2double(thisLayer{3});
        if isempty(thisLayer{4})
            newLayer(4) = NaN;
        else
            newLayer(4) = str2double(thisLayer{4});
        end
        
        if strcmpi(thisLayer{6},'bulk in')
            newLayer(5) = 2;
        else
            newLayer(5) = 1;
        end
        
        thisProblemDef.layersDetails{i} = newLayer;
    end
    
    %Also each contratLayers needs to change from 'cell'
    %to double, stripping out the commas.
    for i = 1:length(problem.contrastLayers)
        thisContrastLayer = problem.contrastLayers{i};
        newContrastLayer = [];
        for n = 1:length(thisContrastLayer)
            if ~strcmpi(thisContrastLayer(n),',')
                newContrastLayer(length(newContrastLayer)+1) = str2double(thisContrastLayer(n));
            end
        end
        thisProblemDef.contrastLayers{i} = newContrastLayer;
    end
    
elseif strcmpi(problem.module.type,'Custom Layers')
    thisProblemDef.modelType = 'Custom Layers';
    fname = problem.module.name;
    thisProblemDef.modelFilename = fname;
    thisProblemDef.modelLanguage = 'matlab'; %Rascal1 has no python scripting option
    
    
elseif strcmpi(problem.module.type,'Custom XY Profile')
    thisProblemDef.modelType = 'Custom XY';
    fname = problem.module.name;
    thisProblemDef.modelFilename = fname;
    thisProblemDef.modelLanguage = 'matlab'; %Rascal1 has no python scripting option
end

%Limits
for i = 1:size(problem.constr,1)
    thisProblemDef.paramConstr{i} = problem.constr(i,:);
end

for i = 1:size(problem.backs_constr,1)
    thisProblemDef.backgroundConstr{i} = problem.backs_constr(i,:);
end

for i = 1:size(problem.scale_constr,1)
    thisProblemDef.scalefactorConstr{i} = problem.scale_constr(i,:);
end

for i = 1:size(problem.shifts_constr,1)
    thisProblemDef.qzshiftConstr{i} = problem.shifts_constr(i,:);
end

for i = 1:size(problem.nbairs_constr,1)
    thisProblemDef.nbairConstr{i} = problem.nbairs_constr(i,:);
end

for i = 1:size(problem.nbsubs_constr,1)
    thisProblemDef.nbsubConstr{i} = problem.nbsubs_constr(i,:);
end

for i = 1:size(problem.resolution_constr,1)
    thisProblemDef.resolutionConstr{i} = problem.resolution_constr(i,:);
end

thisProblemDef.paramFitYesNo = problem.fityesno;
thisProblemDef.backgroundFitYesNo = problem.backgrounds_fityesno;
thisProblemDef.qzshiftFitYesNo = problem.shifts_fityesno;
thisProblemDef.scalefactorFitYesNo = problem.scalefac_fityesno;
thisProblemDef.nbairFitYesNo = problem.nbairs_fityesno;
thisProblemDef.nbsubFitYesNo = problem.nbsubs_fityesno;
thisProblemDef.resolutionFitYesNo = problem.resolution_fityesno;



% controls.TF = 'standardTF';
% controls.Para = 'single';
% controls.proc = 'calculate';
% controls.tfType = 'stanLay';
% controls.lang = 'matlab';
% 
% controls.algArgs.maxInter = Inf;
% controls.algArgs.tolFun = 1.0000e-06;
% controls.algArgs.tolX = 1.0000e-06;
% controls.algArgs.maxFunEvals = Inf;
% 


end








