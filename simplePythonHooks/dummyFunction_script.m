% DUMMYFUNCTION_SCRIPT   Generate static library dummyFunction from
%  dummyFunction.
% 
% Script generated from project 'dummyFunction.prj' on 20-Mar-2023.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.EmbeddedCodeConfig'.
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

%% Define argument types for entry-point 'dummyFunction'.
ARGS = cell(1,1);
ARGS{1} = cell(2,1);
ARGS_1_1 = struct;
ARGS_1_1.numbers = coder.typeof(0,[1 5]);
ARGS_1_1.chars = coder.typeof('X',[1 11]);
ARGS{1}{1} = coder.typeof(ARGS_1_1);
ARGS_1_2 = cell([1 2]);
ARGS_1_2_1 = cell([1 2]);
ARG_1 = coder.typeof(0);
ARGS_1_2_1{1} = coder.typeof({ARG_1}, [2 3]);
ARG_2 = coder.typeof('X',[1 1000],[0 1]);
ARGS_1_2_1{2} = coder.typeof({ARG_2}, [1 3]);
ARGS_1_2{1} = coder.typeof(ARGS_1_2_1,[1 2]);
ARGS_1_2{1} = ARGS_1_2{1}.makeHeterogeneous();
ARGS_1_2_2 = cell([1 2]);
ARGS_1_2_2{1} = coder.typeof(0,[5 5]);
ARGS_1_2_2{2} = coder.typeof(0,[10 10]);
ARGS_1_2{2} = coder.typeof(ARGS_1_2_2,[1 2]);
ARGS_1_2{2} = ARGS_1_2{2}.makeHeterogeneous();
ARGS{1}{2} = coder.typeof(ARGS_1_2,[1 2]);
ARGS{1}{2} = ARGS{1}{2}.makeHeterogeneous();

%% Invoke MATLAB Coder.
codegen -config cfg dummyFunction -args ARGS{1}

