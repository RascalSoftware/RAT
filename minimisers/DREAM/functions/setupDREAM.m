function [outDREAMPar,paramInfo,Meas_info,chain,output,log_L,Table_gamma,iloc,iteration,...
        gen] = setupDREAM(DREAMPar,paramInfo,Meas_info)
% Initialize the main variables used in DREAM.
% 
% Parameters
% ----------
% DREAMPar : struct
%     Algorithmic control information for DREAM.
% paramInfo : struct
%     Ranges, priors and boundary handling for each parameter.
% Meas_info : struct 
%     Struct with measurements to evaluate against.
%
% Returns
% -------
% outDREAMPar : struct
%     The options for DREAMPar with defaults applied.
% paramInfo : struct
%     The input ``paramInfo`` after range validation.
% Meas_info : struct
%     The input ``Meas_info`` after validation.
% chain : array
%     The initial MCMC chain array.
% output : struct
%     The initial empty output struct.
% log_L : array
%     The initial array of log-likelihood values sampled from chains.
% Table_gamma : array
%     The initial DE jump length values for each parameter.
% iloc : int
%     The index of the current sample in the chains.
% iteration : int
%     The initial iteration number.
% gen : int
%     The number of new candidates generated this generation.

% To keep coder happy, we have to define the full version of DREAMPar here
Rr = zeros(DREAMPar.nChains,DREAMPar.nChains);
coder.varsize('Rr',[1e4 1e4],[1 1]);

outDREAMPar = struct('nParams',0,'nChains',0,'nGenerations',0,'parallel',false,'CPU',0,'jumpProbability',0,...
    'pUnitGamma',0,'nCR',0,'delta',0,'steps',0,'zeta',0,'outlier','iqr',...
    'adaptPCR',false,'thinning',0,'ABC',false,'epsilon',0,'IO',false,'storeOutput',false,'R',Rr);


% Generate new seed
rng('default');
%randn('state', sum(100*clock));     % random number generator state

% Do an initial copy of all set fields from DREAMPar to outDREAMPar....
setFieldNames = {'nParams','nChains','nGenerations','parallel','CPU','jumpProbability','pUnitGamma'};
for i = 1:length(setFieldNames)
    thisFieldName = setFieldNames{i};
    outDREAMPar.(thisFieldName) = DREAMPar.(thisFieldName);
end

% Set default values algorithmic variables DREAM - if not specified
value = {3,3,max(max(floor(DREAMPar.nGenerations/50),1),50),0.01,1e-12,'iqr',0.04,false,1,0.025};
% Name variable
name = {'nCR','delta','steps','jumpProbability','zeta','outlier','pUnitGamma','adaptPCR','thinning','epsilon'};
for j = 1 : numel(name)
    if ~isfield(DREAMPar,name{j})
        % Set variable of DREAMPar to "No"
        %evalstr = strcat('DREAMPar.',char(name(j)),'=',value(j),';'); eval(char(evalstr));
        outDREAMPar.(name{j}) = value{j}; 
    else
        outDREAMPar.(name{j}) = DREAMPar.(name{j});
    end
end

% Set default value to 'No' if not specified
default = {'ABC','parallel','IO','storeOutput'};
for j = 1 : numel(default)
    if ~isfield(DREAMPar,default{j})
        % Set variable of DREAMPar to false
        %evalstr = strcat('DREAMPar.',char(default(j)),'=false',';'); eval(evalstr);
        outDREAMPar.(default{j}) = false;
    else
        outDREAMPar.(default{j}) = DREAMPar.(default{j});
    end
end

% Matrix DREAMPar.R: Store for each chain (as row) the index of all other chains available for DE
for i = 1:outDREAMPar.nChains
    outDREAMPar.R(i,1:outDREAMPar.nChains-1) = setdiff(1:outDREAMPar.nChains,i); 
end

% Check whether parameter ranges have been defined or not
if ~isfield(paramInfo,'min')
    % Specify very large initial parameter ranges (minimum and maximum values)
    paramInfo.min = -Inf * ones ( 1 , outDREAMPar.nParams ); paramInfo.max = Inf * ones ( 1 , outDREAMPar.nParams );
end

% Initialize output information -- Outlier chains
outlierChains = [0 0];
coder.varsize('outlierChains',[1e3 1e3],[1 1]);
output.outlierChains = outlierChains;
% ..also run time
output.runtime = 0;
output.DREAMPar = outDREAMPar; 
output.Meas_info = Meas_info;
output.iteration = 1;
output.iloc = 0;
output.modelOutput = 0;

% Initialize matrix with log_likelihood of each chain
log_L = NaN(outDREAMPar.nGenerations,outDREAMPar.nChains+1);

% Initialize vector with acceptance rates
AR = NaN(floor(outDREAMPar.nGenerations/outDREAMPar.steps)+1,2);
coder.varsize('AR',[1e3 2],[1 1]);
output.AR = AR; %NaN(floor(outDREAMPar.nGenerations/outDREAMPar.steps)+1,2); 
output.AR(1,1) = outDREAMPar.nChains;

% Initialize matrix with potential scale reduction convergence diagnostic
output.R_stat = NaN(floor(outDREAMPar.nGenerations/outDREAMPar.steps)+1,outDREAMPar.nParams+1);

% Initialize matix with crossover values
output.CR = NaN(floor(outDREAMPar.nGenerations/outDREAMPar.steps)+1,outDREAMPar.nCR+1);

% Initialize array (3D-matrix) of chain trajectories
chain = NaN(outDREAMPar.nGenerations/outDREAMPar.thinning,outDREAMPar.nParams+2,outDREAMPar.nChains);

% Generate Table with jump rates (dependent on DREAMPar.nParams and DREAMPar.delta)
% More efficient to read from Table
Table_gamma = zeros(outDREAMPar.nParams,outDREAMPar.delta);
for zz = 1:outDREAMPar.delta
    Table_gamma(:,zz) = 2.38./sqrt(2 * zz * [1:outDREAMPar.nParams]');
end

% First calculate the number of calibration data measurements
Meas_info.N = Meas_info.Y;

% Initialize few important counters
iloc = 1; iteration = 2; gen = 2;

end
