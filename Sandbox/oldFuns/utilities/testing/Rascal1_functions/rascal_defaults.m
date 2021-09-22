function problem = rascal_defaults(problem);

%

problem.algorithm = 'simplex';
problem.eb = 0;
problem.plotType = 2;
problem.dataShiftValue = 0;

% numberOfBacks = problem.numberOfBacks;
% problem.backgrounds_fityesno =zeros(numberOfBacks,1);
% numberOfShifts = problem.numberOfShifts;
% problem.shifts_fityesno = zeros(numberOfShifts,1);
% numberOfScales = problem.numberOfScales;
% problem.scalefac_fityesno = zeros(numberOfScales,1);
% numberOfNbas = problem.numberOfNbas;
% problem.nbairs_fityesno = zeros(numberOfNbas,1);
% numberOfNbss = problem.numberOfNbss;
% problem.nbsubs_fityesno = zeros(numberOfNbss,1);
% numberOfResolutions = problem.numberOfResolutions;
% problem.resolution_fityesno = zeros(numberOfResolutions,1);
problem.q4 = 'no';

% for i = 1:problem.numberOfContrasts;
%     %problem.include_data(i) = 1;
%     switch problem.dataPresent(i)
%         case 1
%             problem.fitlowrange(i) = 0;%problem.data{i}(1,1);
%             problem.fithirange(i) = 1;%problem.data{1}(1,end);
%         otherwise
%             problem.fitlowrange(i) = 0;
%             problem.fithirange(i) = 1;
%     end
% end

%Deal with changed format for 'repeat layers' field....
% if (~any(ismember(fields(problem),'repeatLayers')) && strcmp(problem.module.type,'Standard Layers'));
%     for i = 1:problem.numberOfContrasts
%         problem.repeatLayers{i} = [0 1];
%     end
% end


%Deal with the fact that fittable resolution may have been absent in previous
%versions
if ~any(ismember(fields(problem),'resolution_constr'))
    numberOfResolutions = length(problem.resolution);
    problem.numberOfResolutions = numberOfResolutions;
    for i = 1:numberOfResolutions
        problem.resolution_constr(i,1) = 0.01;
        problem.resolution_constr(i,2) = 0.05;
        problem.resolution_fityesno(i) = 0;
        problem.resolNames{i} = ['Resolution ' num2str(i)];
    end
    
    for i = 1:problem.numberOfContrasts
        problem.contrastResolutions(i) = 1;
    end
end

if ~any(ismember(fields(problem),'useReducedChiSq'))
    problem.useReducedChiSquared = 1;
end

if strcmp(problem.module.type,'Standard Layers')
    for i = 1:problem.numberOfContrasts
        thisRepeats =  problem.repeatLayers{i};
        if length(thisRepeats) < 2
            problem.repeatLayers{i} = [0 1];
        end
    end
end


fitopts = getappdata(0,'fittingOptions');
if isempty(fitopts);
    fitopts.simplex.TargetChi = 1;
    fitopts.simplex.MaxFunEvals = 1e6;
    fitopts.simplex.stopTolParam = 1e-7;
    fitopts.simplex.stopFunTol = 1e-7;

    fitopts.cmaes.TargetChi = 1;
    fitopts.cmaes.MaxFunEval = 1e4;
    fitopts.cmaes.StopTolX = 1e-6;
    fitopts.cmaes.StopTolFun = 1e-6;
    fitopts.cmaes.PopSize= 50;
    fitopts.cmaes.Maxdp = inf;
    fitopts.cmaes.Mindp = 0;
    fitopts.cmaes.RecombW = 1;
    
    fitopts.DE.CrossOverProb = 0.8;
    fitopts.DE.ValueToReach = 1;
    fitopts.DE.PopSize = 50;
    fitopts.DE.StepSIze = 0.8;
    fitopts.DE.Strategy = 1;
end

if ~any(strcmp('simLimits',fields(problem))) 
    for n = 1:problem.numberOfContrasts
        problem.simLimits{n} = [0.007 0.5];
    end
end

if ~any(strcmp('simNPoints',fields(problem))) 
    for n = 1:problem.numberOfContrasts
        problem.simNPoints(n) = 500;
    end
end

setappdata(0,'fittingOptions',fitopts);
setappdata(0,'problem',problem);



