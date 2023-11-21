% REFLECTIVITY_CALCULATION_CODEONLY_SCRIPT   Generate static library
%  reflectivityCalculation from reflectivityCalculation.
% 
% Script generated from project 'reflectivityCalculation.prj' on 07-Jul-2021.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
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
%cfg.MATLABSourceComments = true;
cfg.CodeFormattingTool = 'MathWorks';
cfg.RunInitializeFcn = false;
cfg.DataTypeReplacement = 'CoderTypeDefs';

ARGS = makeCompileArgs();

%% Invoke MATLAB Coder.
includeDirs = getappdata(0,'includeDirs');
includes = cell(length(includeDirs)*2, 1);
includes(1:2:end) = {'-I'};
includes(2:2:end) = includeDirs;
codegen('reflectivityCalculation', '-config', cfg, '-args',  ARGS{1}, includes{:});
