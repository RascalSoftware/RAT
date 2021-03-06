% UNTITLED   Generate static library backSort from backSort.
% 
% Script generated from project 'backSort.prj' on 09-Apr-2017.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('lib','ecoder',false);
cfg.GenerateReport = true;
cfg.GenCodeOnly = false;

%% Define argument types for entry-point 'backSort'.
ARGS = cell(1,1);
ARGS{1} = cell(12,1);
ARGS{1}{1} = coder.typeof(0);
ARGS{1}{2} = coder.typeof(0);
ARGS{1}{3} = coder.typeof(0);
ARGS{1}{4} = coder.typeof(0);
ARGS{1}{5} = coder.typeof(0);
ARGS{1}{6} = coder.typeof(0);
ARGS{1}{7} = coder.typeof(0,[1 Inf],[0 1]);
ARGS{1}{8} = coder.typeof(0,[1 Inf],[0 1]);
ARGS{1}{9} = coder.typeof(0,[1 Inf],[0 1]);
ARGS{1}{10} = coder.typeof(0,[1 Inf],[0 1]);
ARGS{1}{11} = coder.typeof(0,[1 Inf],[0 1]);
ARGS{1}{12} = coder.typeof(0,[1 Inf],[0 1]);

%% Invoke MATLAB Coder.
codegen -config cfg backSort -args ARGS{1}