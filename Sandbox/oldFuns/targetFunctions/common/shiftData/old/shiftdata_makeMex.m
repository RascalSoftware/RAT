% UNTITLED   Generate static library shiftdata from shiftdata.
% 
% Script generated from project 'shiftdata.prj' on 09-Apr-2017.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('lib','ecoder',false);
cfg.GenerateReport = true;
cfg.GenCodeOnly = true;

%% Define argument types for entry-point 'shiftdata'.
ARGS = cell(1,1);
ARGS{1} = cell(5,1);
ARGS{1}{1} = coder.typeof(0);
ARGS{1}{2} = coder.typeof(0);
ARGS{1}{3} = coder.typeof(0);
ARGS{1}{4} = coder.typeof(0,[Inf  3],[1 0]);
ARGS{1}{5} = coder.typeof(0,[1 2]);

%% Invoke MATLAB Coder.
codegen -config cfg shiftdata -args ARGS{1}