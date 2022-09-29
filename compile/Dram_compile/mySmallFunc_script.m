% MYSMALLFUNC_SCRIPT   Generate static library mySmallFunc from mySmallFunc.
% 
% Script generated from project 'mySmallFunc.prj' on 21-Sep-2022.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('lib','ecoder',false);
cfg.GenerateReport = true;
cfg.ReportPotentialDifferences = false;
cfg.GenCodeOnly = true;

%% Define argument types for entry-point 'mySmallFunc'.
ARGS = cell(1,1);
ARGS{1} = cell(1,1);
ARGS_1_1 = struct;
ARG = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_1.priorNames = coder.typeof({ARG}, [Inf  1],[1 0]);
ARG = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_1.priorVals = coder.typeof({ARG}, [Inf  3],[1 0]);
ARGS{1}{1} = coder.typeof(ARGS_1_1);

%% Invoke MATLAB Coder.
codegen -config cfg mySmallFunc -args ARGS{1}

