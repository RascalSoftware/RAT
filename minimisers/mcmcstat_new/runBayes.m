function output = runBayes(loop,nsimu,burnin,adaptint,params,problem)

% Clear any values from previous runs if prsent
%clear model data options

problemDef = problem{1};
controls = problem{2};
problemDef_limits = problem{3};
problemDef_cells = problem{4};

%data = problem.data;
% Arrange the data into the format mcmcstat requires 
% We have the same number of 'batches' as contrasts.
% Also need to pass problem in order to access this
% from the subfunctions.
numberOfContrasts = problemDef.numberOfContrasts;

% Pre-allocate data to keep the compiler happy
% data = cell(1,numberOfContrasts);
% structDefineType = struct('ydata',[],'problem',problem);
% for i = 1:numberOfContrasts
%     data{i} =  structDefineType;
% end

for i = 1:numberOfContrasts
    thisData = problemDef_cells{2}{i};
    data{i}.ydata = [thisData(:,1:2)];
    data{i}.problem = problem;
end

fitConstr = problemDef.fitconstr;
nPars = size(fitConstr,1);

% Make qcov based on the ranges of the parameters
for i = 1:nPars
    thisConstr = fitConstr(i,:);
    qcov(i) = (abs(thisConstr(2) - thisConstr(1))*0.01)^2;
end
qcov = diag(qcov);

% Define model and method options.
model.modelfun      = @refModel;     % will return a reflectivity curve
model.ssfun         = @fitModel;     % will return chi squared
model.nbatch        = numberOfContrasts;

options.method      = 'dram';          % adaptation method (mh, am, dr, dram)
options.nsimu       = nsimu;           % no of simulation%
options.qcov        = qcov;            % proposal covariance (not sure why 11....)

options.adaptint    = adaptint;        % adaptation interval
options.printint    = 200;             % how often to show info of acceptance ratios
options.verbosity   = 1;               % how much to show output
options.waitbar     = 1;               % show graphical waitbar
options.updatesigma = 0;               % update error variance
options.stats       = 1;               % save extra statistics in result
options.burnintime  = burnin;          % burn in time..
options.ntry = 1;

results = [];
for i = 1:loop
    fprintf('Running loop %d of %d ',i,loop);
    [results,chain,s2chain,sschain] = mcmcrun(model, data, params, options, results);
    fprintf('\n');
end

output.results = results;
output.chain = chain;
output.s2chain = s2chain;
output.sschain = sschain;
output.bestPars = results.mean;
output.data = data;


% figure(200); clf; hold on
% mcmcplot(chain,[],results,'chainpanel');
% 
% figure(201); clf; hold on
% mcmcplot(chain,[],results,'hist');
% 
% figure(202); clf; hold on
out = mcmcpred(results,chain,[],data,@refModel,700);

problemDef.fitpars = output.bestPars;
problemDef = unpackparams(problemDef,controls);
[problem,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);

output.bestFits = result{1};
output.shiftedData = problemDef_cells{2};
output.predlims = out;

% for i = 1:numberOfContrasts
%     makePredPlot(predlims{i}{:},shiftedData{i},problem,bestFits{i},problem.scalefactors(i));
% %     figure(hSld);
% %     makeSldPredPlot(outSld.predlims{i}{:},bestSld{i},hSld);
% end



end

%-------------------------------------------------------
function ss = fitModel(theta,data)

% Sum of squares function used in the calculation
% Calls reflectivity calculation and returns the value of chisquared

pars = theta;                               % Current parameter values from mcmcstat
%problem = data{1}.problem{1};               % Struct needed for the calculation
allProblem = data{1}.problem;
problemDef = allProblem{1};
controls = allProblem{2};
problemDef_limits = allProblem{3};
problemDef_cells = allProblem{4};


problemDef.fitpars = pars;
problemDef = unpackparams(problemDef,controls);
%setappdata(0,'problem',problem);
%problem = reflectivity_calculation(problem);
[problemDef,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);

%problem = getappdata(0,'problem');
ss = problemDef.calculations.sum_chi;

end


%---------------------------------------------------------
function ymod = refModel(data,theta,varargin)

% Returns the reflectivity profile. Need to do some extra work because
% 'reflectivity-calculation' adjusts the data according to scalefactor.
% We need to reverse this correction, and actually return the simulation
% corrected for the scalefactor. We have to do this because the scalefactor 
% is in itself one of our fitting parameters (no need to correct the data -
% problem.shifted_data contains the corrected data, but
% problem.data is a record of the original).

if isempty(varargin)
    contrast = 1;
else
    contrast = varargin{1};
end

if iscell(data)
    thisData = data{contrast}.ydata;
    problem = data{contrast}.problem;
else
    thisData = data.ydata;
    problem = data.problem;
end

if nargin == 4
    debugPlot = varargin{2};
else
    debugPlot = 0;
end

pars = theta;

problemDef = problem{1};
controls = problem{2};
problemDef_limits = problem{3};
problemDef_cells = problem{4};

problemDef.fitpars = pars;
problemDef = unpackparams(problemDef,controls);
[problem,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);

ySim = result{1}{contrast};

% Need to correct the simulation for the scalefactor (i.e. move the sim to
% the data, unlike what we normally do)
scale = problem.scalefactors(contrast);        
ymod = ySim(:,2).*scale;        % Do something more flashy here for multiple contrasts

% Debug plot to check that everything works..
%debugPlot = 0;
if debugPlot
    plot(thisData(:,1),thisData(:,2),'o');
    hold on
    plot(ySim(:,1),ymod,'-');
    hold off
end

end

%-------------------------------------------------------------------------

function makePredPlot(out,data,problem,bestFit,scalefac)


% figure(refFig);
% clf;
% hold on;

%data = problem.data;

thisData = data;

%figure(refFig); clf; hold on
errorbar(thisData(:,1),thisData(:,2),thisData(:,3),'.');
set(gca,'YScale','log','XScale','log');
hold on
plot(bestFit(:,1),bestFit(:,2).*scalefac,'k-');

numRanges = 1;
for i = 1:numRanges
    thisMin = out(2,:);
    thisMax = out(8,:);
    
    numPoints = size(thisData,1);
    
    plot(thisData(:,1),thisMin(1:numPoints),'-')
    plot(thisData(:,1),thisMax(1:numPoints),'-')
end

end




