% RATMAin_COMPILE_SCRIPT   Generate MEX-function
%  RATMain_mex from RATMain.

% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.GenerateReport = true;
cfg.EnableJIT = false;
cfg.EnableOpenMP = true;
cfg.TargetLang = 'C++';
% cfg.TargetLangStandard = 'C++11 (ISO)';

% Define the input argument types..
ARGS = makeCompileArgsFull();

includeDirs = getappdata(0,'includeDirs');
includes = cell(length(includeDirs)*2, 1);
includes(1:2:end) = {'-I'};
includes(2:2:end) = includeDirs;
codegen('RATMain', '-config', cfg, '-args',  ARGS{1}, includes{:});