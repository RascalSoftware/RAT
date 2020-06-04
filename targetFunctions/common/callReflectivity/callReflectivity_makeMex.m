% UNTITLED   Generate static library callReflectivity from callReflectivity.
% 
% Script generated from project 'callReflectivity.prj' on 09-Apr-2017.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('lib','ecoder',false);
cfg.GenerateReport = true;
cfg.GenCodeOnly = true;

%% Define argument types for entry-point 'callReflectivity'.
ARGS = cell(1,1);
ARGS{1} = cell(9,1);
ARGS{1}{1} = coder.typeof(0);
ARGS{1}{2} = coder.typeof(0);
ARGS{1}{3} = coder.typeof(0,[1 2]);
ARGS{1}{4} = coder.typeof(0,[1 2]);
ARGS{1}{5} = coder.typeof(0,[Inf  3],[1 0]);
ARGS{1}{6} = coder.typeof(0,[Inf  3],[1 0]);
ARGS{1}{7} = coder.typeof(0);
ARGS{1}{8} = coder.typeof(0);
ARGS{1}{9} = coder.typeof(0);

%% Invoke MATLAB Coder.
codegen -config cfg callReflectivity -args ARGS{1}