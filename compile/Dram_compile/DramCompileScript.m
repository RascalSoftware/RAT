%% Compile script for the Simplex (fminsearch)

% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.GenerateReport = true;
cfg.EnableJIT = false;
cfg.EnableOpenMP = true;
% cfg.TargetLang = 'C++';
% cfg.TargetLangStandard = 'C++11 (ISO)';

%%
% Define the input argument types..
ARGS = makeCompileArgs();


%% Invoke MATLAB Coder.
codegen -config cfg runDram -args ARGS{1}