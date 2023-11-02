% RATMAin_COMPILE_SCRIPT   Generate MEX-function
%  RATMain_mex from RATMain.

% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Deal with globals
global verbose DEBUG
DEBUG = 0;
verbose = 1;

%% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('lib');
cfg.GenerateReport = true;
cfg.ReportPotentialDifferences = false;
cfg.GenCodeOnly = true;
cfg.InlineBetweenUserFunctions = 'Readability';
cfg.InlineBetweenMathWorksFunctions = 'Readability';
cfg.InlineBetweenUserAndMathWorksFunctions = 'Readability';
cfg.TargetLang = 'C++';
cfg.PreserveVariableNames = 'UserNames';
cfg.CppNamespace = 'RAT';
cfg.PreserveArrayDimensions = true;
cfg.CodeFormattingTool = 'MathWorks';
cfg.RunInitializeFcn = false;
cfg.DataTypeReplacement = 'CoderTypeDefs';

%% Define the input argument types..
ARGS = makeCompileArgsFull();

%% Run the compile
includeDirs = getappdata(0,'includeDirs');
includes = cell(length(includeDirs)*2, 1);
includes(1:2:end) = {'-I'};
includes(2:2:end) = includeDirs;
codegen('RATMain', '-config', cfg, '-args',  ARGS{1}, includes{:});