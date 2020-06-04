function problem = parseProblemDefToStruct(problemDef)


if (class(problemDef)~='problemDef')
    error('Input must ba a problemDef object');
end

problemDef = problemDefArgCheck(problemDef);

%Contrasts
numberOfContrasts = problemDef.numberOfContrasts;
problem.numberOfContrasts = numberOfContrasts;
allData = problemDef.allData;
for i = 1:numberOfContrasts
   if ~isempty(allData{i})
       thisData = allData{i};
       if length(thisData) == 2
           data = loadData(thisData);
       else
           problem.allData{i} = thisData;
           problem.dataPresent(i) = 1;   
           problem.dataLimits{i} = problemDef.dataLimits{i};
           problem.simLimits{i} = problemDef.simLimits{i};   
       end
   else
       thisData{i} = [];
       problem.dataPresent(i) = 0;
   end
   %missing fromproblemDef - *************!!!!!
   problem.resample(i) = 0;
   problem.repeatLayers{i} = [0 1];
end

problem.paramConstr = problemDef.paramConstr;
problem.backgroundConstr = problemDef.backgroundConstr;
problem.scalefactorConstr = problemDef.scalefactorConstr;
problem.qzshiftConstr = problemDef.qzshiftConstr;
problem.nbairConstr = problemDef.nbairConstr;
problem.nbsubConstr = problemDef.nbsubConstr;
problem.resolutionConstr = problemDef.resolutionConstr;

problem.contrastBacks = problemDef.contrastBacks; 
problem.contrastShifts = problemDef.contrastShifts;
problem.contrastScales = problemDef.contrastScales;
problem.contrastNbas = problemDef.contrastNbas;
problem.contrastNbss = problemDef.contrastNbss;
problem.contrastRes = problemDef.contrastRes;
   
    
problem.backs = problemDef.backgrounds;
problem.backsNames = problemDef.backgroundNames;
problem.shifts = problemDef.qzshifts;
problem.shiftsNames = problemDef.qzshiftNames;
problem.sf = problemDef.scalefactors;
problem.sfNames = problemDef.scalefactorNames;
problem.nba = problemDef.nbairs;
problem.nbaNames = problemDef.nbairNames;
problem.nbs = problemDef.nbsubs;
problem.nbsNames = problemDef.nbsubNames;
problem.res = problemDef.resolutions;
problem.resolNames = problemDef.resolutionNames;

%Parameters
problem.nParams = problemDef.nParams;
problem.params = problemDef.params;
problem.paramNames = problemDef.paramNames;

%Model
if strcmpi(problemDef.modelType,'layers')
   problem.numberOfLayers= problemDef.numberOfLayers;
   problem.layersDetails = problemDef.layersDetails;
   problem.contrastLayers = problemDef.contrastLayers;
else
   problem.fileHandle = problemdef.modelFilename; 
   problem.lang = problemDef.modelLanguage; 
end

if strcmpi(problemDef.modelType,'layers')
    problem.whichType = 1;
elseif srcmpi(problemDef.modelType,'custom layers')
    problem.whichType = 2;
elseif srcmpi(problemDef.modelType,'custom xy')  
    problem.whichType = 3;
end

problem.module = problemDef.experimentType;
problem.geometry = problemDef.experimentGeometry;

end


%Missing from  
   
   
function thisData = loadData(thisData)
    error('Data loader not implemented yet. Please supply data as ascii');
end



function problemDef = problemDefArgCheck(problemDef)
    warning('no Argument checking yet, so don''t mess up or will probably segfault');
end



