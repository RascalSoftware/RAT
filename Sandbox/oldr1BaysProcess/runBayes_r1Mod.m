function output = runBayes_r1Mod(loop,nsimu,burnin,adaptint,params,problem)

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
data = cell(1,numberOfContrasts);
for i = 1:numberOfContrasts
    thisData = problemDef_cells{2}{i};
    data{i} = [thisData(:,1:2)];
    %data{i}.problem = problem;
end

fitConstr = problemDef.fitconstr;
nPars = size(fitConstr,1);

% Make qcov based on the ranges of the parameters
qcov = [];
for i = 1:nPars
    thisConstr = fitConstr(i,:);
    qcov(i) = (abs(thisConstr(2) - thisConstr(1))*0.01)^2;
end
qcov = diag(qcov);
%qcov = eye(nPars)*5^2;

% Define model and method options.
model.modelfun      = 'refModel';     % will return a reflectivity curve
model.ssfun         = 'reflectivity_fitModel';     % will return chi squared
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
options.ntry = 2;
options.drscale = [3 2 1];

results = [];
loop = int32(loop);
for i = 1:loop
    fprintf('Running loop %d of %d ',i,loop);
    [results,chain,s2chain,sschain] = mcmcrun_compile_r1Mod(model, data, problem, params, options, results);
    fprintf('\n');
end

output.results = results;
output.chain = chain;
output.s2chain = s2chain;
output.sschain = sschain;
%output.bestPars = results.mean;

% Existing RAT post-processing is here
%out = mcmcpred_compile(results,chain,[],data,problem,700);

% RasCAL post-processing looks like this.....
% [bestVals_max,posteriors] = makePosteriorPlots(output,params);
% %bestVals_max = output.results.mean;
% 
%     
% % Calculate the prediction intervals
% [best, intervals] = calcMCMCstatRefErrors(output.results,output.chain,bestVals_max);

% ---------------------------
% New RAT post-processing...
% ---------------------------

end






