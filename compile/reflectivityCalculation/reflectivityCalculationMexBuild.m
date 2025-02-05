% reflectivityCalculationMexBuild   
% 
% Generates MEX-function (reflectivityCalculation_mex) from reflectivityCalculation.

% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.GenerateReport = true;
cfg.EnableJIT = false;
cfg.EnableOpenMP = true;
cfg.TargetLang = 'C++';

% Define the input argument types..
ARGS = makeCompileArgs();

includeDirs = getappdata(0,'includeDirs');
includes = cell(length(includeDirs)*2, 1);
includes(1:2:end) = {'-I'};
includes(2:2:end) = includeDirs;
codegen('reflectivityCalculation', '-globals', '{"DEBUG", 0}', '-config', cfg, '-args',  ARGS{1}, includes{:});
