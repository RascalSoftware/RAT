% UNTITLED   Generate static library makeSLDProfiles from makeSLDProfiles.
% 
% Script generated from project 'makeSLDProfiles.prj' on 09-Apr-2017.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('lib','ecoder',false);
cfg.GenerateReport = true;
cfg.GenCodeOnly = true;

%% Define argument types for entry-point 'makeSLDProfiles'.
ARGS = cell(1,1);
ARGS{1} = cell(5,1);
ARGS{1}{1} = coder.typeof(0);
ARGS{1}{2} = coder.typeof(0);
ARGS{1}{3} = coder.typeof(0,[Inf  5],[1 0]);
ARGS{1}{4} = coder.typeof(0);
ARGS{1}{5} = coder.typeof(0,[1 2]);

%% Invoke MATLAB Coder.
codegen -config cfg makeSLDProfiles -args ARGS{1}