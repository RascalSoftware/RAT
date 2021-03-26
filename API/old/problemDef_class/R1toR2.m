function [problemDef,controls] = R1toR2(r1Problem)


%start by making empty default R2 functions.
problemDef = makeProblemDef();
%controls = makeControls();

%Load in the R1 problem....
r1Problem = load(r1Problem);
problem = r1Problem.problem;


numberOfContrasts = length(problem.simLimits);

problemDef.numberOfContrasts = numberOfContrasts;
problemDef.resample = zeros(1,numberOfContrasts);
problemDef.geometry = problem.module.experiment_type;
problemDef.nbairs = []; %These should be 
problemDef.nbsubs = []; %created by packparams?? 
problemDef.contrastBacks = problem.contrastBacks;
problemDef.contrastShifts = problem.contrastShifts;
problemDef.contrastScales = problem.contrastScales;
problemDef.contrastNbas = problem.contrastNbas;
problemDef.contrastNbss = problem.contrastNbss;
problemDef.contrastRes = problem.contrastResolutions;
problemDef.backs = problem.backs;
problemDef.backsNames = problem.backsNames;
problemDef.shifts = problem.shifts_horisontal;
problemDef.shiftsNames = problem.shiftsNames;
problemDef.sf = problem.scalefac;
problemDef.sfNames = problem.scalesNames;
problemDef.nba = problem.nba;
problemDef.nbaNames = problem.nbaNames;
problemDef.nbs = problem.nbs;
problemDef.nbsNames = problem.nbsNames;
problemDef.res = problem.resolution;
problemDef.resolNames = problem.resolNames;
problemDef.dataPresent = problem.dataPresent;
problemDef.allData = problem.data;
problemDef.dataLimits = problem.dataLimits;
problemDef.simLimits = problem.simLimits;
problemDef.repeatLayers = problem.repeatLayers;
problemDef.nParams = length(problem.params);
problemDef.params = problem.params;
problemDef.paramNames = problem.paramnames;
problemDef.contrastLayers = problem.contrastLayers;
problemDef.numberOfLayers = problem.numberOfLayers;
%problemDef.layersDetails = problem.layersDetails;
problemDef.whichType = []; %Er.... what's this???
problemDef.fileHandle = '';
problemDef.lang = 'matlab';
problemDef.module = '';
problemDef.fitNames = {''};


%Some extra work to be done with layers
%details because they are a different format.
for i = 1:length(problem.layersDetails);
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
    
    problemDef.layersDetails{i} = newLayer;
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
    problemDef.contrastLayers{i} = newContrastLayer;
end


problemDef.limits.params = problem.constr;
problemDef.limits.backs = problem.backs_constr;
problemDef.limits.scales = problem.scale_constr;
problemDef.limits.shifts = problem.shifts_constr;
problemDef.limits.nba = problem.nbairs_constr;
problemDef.limits.nbs = problem.nbsubs_constr;
problemDef.limits.res = problem.resolution_constr;

controls.TF = 'standardTF';
controls.Para = 'single';
controls.proc = 'calculate';
controls.tfType = 'stanLay';
controls.lang = 'matlab';


controls.algArgs.maxInter = Inf;
controls.algArgs.tolFun = 1.0000e-06;
controls.algArgs.tolX = 1.0000e-06;
controls.maxFunEvals = Inf;

controls.checks.params_fitYesNo = problem.fityesno;
controls.checks.backs_fitYesNo = problem.backgrounds_fityesno;
controls.checks.shifts_fitYesNo = problem.shifts_fityesno;
controls.checks.scales_fitYesNo = problem.scalefac_fityesno;
controls.checks.nbairs_fitYesNo = problem.nbairs_fityesno;
controls.checks.nbsubs_fitYesNo = problem.nbsubs_fityesno;
controls.checks.resol_fitYesNo = problem.resolution_fityesno;


end



function problemDef = makeProblemDef()

%Make a default 'blank' version of R2 problemDef....

problemDef.resample = 0;
problemDef.numberOfContrasts = 1;
problemDef.geometry = 'Air / Liquid (or solid)';
problemDef.nbairs = 0;
problemDef.nbsubs = 6.35e-6;
problemDef.contrastBacks = 1;
problemDef.contrastShifts = 1;
problemDef.contrastScales = 1;
problemDef.contrastNbas = 1;
problemDef.contrastNbss = 1;
problemDef.contrastRes = 1;
problemDef.backs = 2e-6;
problemDef.backsNames = {'Background 1'};
problemDef.shifts = 0;
problemDef.shiftsNames = {'qshift 1'};
problemDef.sf = 1;
problemDef.sfNames = {'Scalefactor 1'};
problemDef.nba = 0;
problemDef.nbaNames = {'Air'};
problemDef.nbs = 6.3500e-06;
problemDef.nbsNames = {'D2O'};
problemDef.res = 0.0300;
problemDef.resolNames = {'Resolution 1'};
problemDef.dataPresent = 0;
problemDef.allData = {[]};
problemDef.dataLimits = {[0 0]};
problemDef.simLimits = {[0.001 0.5]};
problemDef.repeatLayers = {[0 1]};
problemDef.nParams = 0;
problemDef.params = [];
problemDef.paramNames = {''};
problemDef.contrastLayers = {[1 4]  [1 4]  [2 3]  [2 3]  [1 3]  [1 3]  [2 4]};
problemDef.numberOfLayers = 0;
problemDef.layersDetails = {[]};
problemDef.whichType = 1;
problemDef.fileHandle = '';
problemDef.lang = '';
problemDef.module = '';

problemDef.limits.params = [-Inf Inf];
problemDef.limits.backs = [-Inf Inf];
problemDef.limits.scales = [-Inf Inf];
problemDef.limits.shifts = [-Inf Inf];
problemDef.limits.nba = [-Inf Inf];
problemDef.limits.nbs = [-Inf Inf];
problemDef.limits.res = [-Inf Inf];

end




