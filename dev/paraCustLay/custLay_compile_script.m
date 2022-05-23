% dev_custLay_paraContrasts_COMPILE_SCRIPT   Generate MEX-function
%  reflectivity_calculation_mex from reflectivity_calculation.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.GenerateReport = true;
cfg.EnableJIT = false;  % MUST be false for OpenMP
cfg.EnableOpenMP = true;
% cfg.TargetLang = 'C++';
% cfg.TargetLangStandard = 'C++11 (ISO)';

% Define the input argument types..
ARGS = makeCompileArgs();

%% Invoke MATLAB Coder.
codegen -config cfg dev_custlay_paraContrasts -args ARGS{1}

