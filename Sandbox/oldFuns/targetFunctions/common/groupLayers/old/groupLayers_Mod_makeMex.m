% UNTITLED   Generate static library groupLayers_Mod from groupLayers_Mod.
% 
% Script generated from project 'groupLayers_Mod.prj' on 09-Apr-2017.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('lib','ecoder',false);
cfg.GenerateReport = true;
cfg.GenCodeOnly = true;

%% Define argument types for entry-point 'groupLayers_Mod'.
ARGS = cell(1,1);
ARGS{1} = cell(5,1);
ARGS{1}{1} = coder.typeof(0,[Inf  5],[1 1]);
ARGS{1}{2} = coder.typeof(0);
ARGS{1}{3} = coder.typeof('X',[1 Inf],[0 1]);
ARGS{1}{4} = coder.typeof(0);
ARGS{1}{5} = coder.typeof(0);

%% Invoke MATLAB Coder.
codegen -config cfg groupLayers_Mod -args ARGS{1}