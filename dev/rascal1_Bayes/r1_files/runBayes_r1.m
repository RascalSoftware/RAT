function output = runBayes_r1(loop,nsimu,burnin,params,problem)

% Again we have to modify the first part of this in order to get it to work
% with RAT. Manly so that the reflectivity calculations work with the new
% style of problemDef etc... Also had to modify the reflectivity functions
% for the same reason... otherwise it conforms to the (working!) R1 way of
% doing things....



% Clear any values from previous runs if prsent
clear model data options

% -------- Old R1 codes

% problem = getappdata(0,'problem');
% oldCalcSLD = problem.calcSLD;
% problem.calcSLD = 0;
% problem = packparams(problem);

% fitpars = problem.fitpars;
% fitNames = problem.fitNames;
% limits = problem.fitconstr;

%data = problem.data;
% Arrange the data into the format mcmcstat requires 
% We have the same number of 'batches' as contrasts.
% Also need to pass problem in order to access this
% from the subfunctions.
% numberOfContrasts = problem.numberOfContrasts;
% for i = 1:numberOfContrasts
%     thisData = problem.data{i};
%     data{i}.ydata = [thisData(:,1:2)];
%     data{i}.problem = problem;
% end

% -------- END ------------

% New R2 style codes.....
problemDef = problem{1};
problemDef_cells = problem{4};




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
    data{i}.ydata = [thisData(:,1:2)];
    data{i}.problem = problem;
end


% Define model and method options.
model.modelfun      =   @refModel;     % will return a reflectivity curve
model.ssfun         =   @fitModel;     % will return chi squared
%model.sigma2        =   1;          % initial error variance
%model.N0            =   1;             % prior (invchisq) weight for sigma2
model.nbatch        = numberOfContrasts;

options.method      = 'dram';          % adaptation method (mh, am, dr, dram)
options.nsimu       = nsimu;           % no of simulation
%options.qcov        = eye(3)*0.001;    % proposal covariance (not sure why 11....)
%options.adaptint    = adaptint;        % adaptation interval
options.printint    = 200;             % how often to show info of acceptance ratios
options.verbosity   = 1;               % how much to show output
options.waitbar     = 1;               % show graphical waitbar
options.updatesigma = 0;               % update error variance
options.stats       = 1;               % save extra statistics in result
options.burnintime  = burnin;      % burn in time..

% options.method = 'dram';
% options.nsimu = nsimu;%50000;
% options.verbosity = 1;
% options.adaptint = 500;
% options.burnintime = burnin;
% 
% model.ssfun = @MCMC_Intrafun;

res = [];
for i = 1:loop
    %bayesInfoText(sprintf('Running loop %d of %d',i,loop));
    fprintf('Running loop %d of %d \n',i,loop)
    [results,chain,s2chain,sschain] = mcmcrun(model, data, params, options, res);
end

output.results = results;
output.chain = chain;
output.s2chain = s2chain;
output.sschain = sschain;
output.bestPars = results.mean;
output.data = data;

problem.calcSLD = oldCalcSLD;
setappdata(0,'output',output);

end



% -------- Old R1 Codes ---------------
%-------------------------------------------------------
% function ss = fitModel(theta,data)
% 
% % Sum of squares function used in the calculation
% % Calls reflectivity calculation and returns the value of chisquared
% 
% pars = theta;                         % Current parameter values from mcmcstat
% problem = data{1}.problem;              % Struct needed for the calculation
% 
% problem.fitpars = pars;
% problem = unpackparams(problem);
% %setappdata(0,'problem',problem);
% problem = reflectivity_calculation(problem);
% %problem = getappdata(0,'problem');
% ss = problem.calculations.sum_chi;
% 
% end

% -------- Old R1 Codes ---------------
%---------------------------------------------------------
% function ymod = refModel(data,theta,varargin)
% 
% % Returns the reflectivity profile. Need to do some extra work because
% % 'reflectivity-calculation' adjusts the data according to scalefactor.
% % We need to reverse this correction, and actually return the simulation
% % corrected for the scalefactor. We have to do this because the scalefactor 
% % is in itself one of our fitting parameters (no need to correct the data -
% % problem.shifted_data contains the corrected data, but
% % problem.data is a record of the original).
% 
% if isempty(varargin)
%     contrast = 1;
% else
%     contrast = varargin{1};
% end
% 
% if iscell(data)
%     thisData = data{contrast}.ydata;
%     problem = data{contrast}.problem;
% else
%     thisData = data.ydata;
%     problem = data.problem;
% end
% 
% if nargin == 4
%     debugPlot = varargin{2};
% else
%     debugPlot = 0;
% end
% 
% params = theta;
% 
% problem.fitpars = params;
% problem = unpackparams(problem);
% %setappdata(0,'problem',problem);
% problem = reflectivity_calculation(problem);
% %problem = getappdata(0,'problem');
% ySim = problem.calculations.Simulation{contrast};
% 
% % Need to correct the simulation for the scalefactor (i.e. move the sim to
% % the data, unlike what we normally do)
% scale = problem.scalefactors(1);        
% ymod = ySim(:,2).*scale;        % Do something more flashy here for multiple contrasts
% 
% % Debug plot to check that everything works..
% %debugPlot = 0;
% if debugPlot
%     plot(thisData(:,1),thisData(:,2),'o');
%     hold on
%     plot(ySim(:,1),ymod,'-');
%     hold off
% end
% 
% end
% 
% % -------------------

% Adapted R2 Model......

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
    thisData = data{contrast};%.ydata;
    problem = data{contrast}.problem;
else
    thisData = data;%.ydata;
    problem = data.problem;
end

%if nargin == 4
%    debugPlot = varargin{2};
%else
    debugPlot = 0;
%end

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


% ---------------------------------

function ss = fitModel(theta,data,varargin)

% Sum of squares function used in the calculation
% Calls reflectivity calculation and returns the value of chisquared

pars = theta;                                % Current parameter values from mcmcstat
problem = data{1}.problem;               % Struct needed for the calculation
%allProblem = data{1}.problem;

problemDef = problem{1};
controls = problem{2};
problemDef_limits = problem{3};
problemDef_cells = problem{4};


problemDef.fitpars = pars;
problemDef = unpackparams(problemDef,controls);
%setappdata(0,'problem',problem);
%problem = reflectivity_calculation(problem);
[problemDef,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);

%problem = getappdata(0,'problem');
ss = problemDef.calculations.sum_chi;

end





