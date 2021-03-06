% UNTITLED   Generate static library chiSquared from chiSquared.
% 
% Script generated from project 'chiSquared.prj' on 09-Apr-2017.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('lib','ecoder',false);
cfg.GenerateReport = true;
cfg.GenCodeOnly = true;

%% Define argument types for entry-point 'chiSquared'.
ARGS = cell(1,1);
ARGS{1} = cell(3,1);
ARGS{1}{1} = coder.typeof(0,[Inf  3],[1 0]);
ARGS{1}{2} = coder.typeof(0,[Inf  2],[1 0]);
ARGS{1}{3} = coder.typeof(0);

%% Invoke MATLAB Coder.
codegen -config cfg chiSquared -args ARGS{1}