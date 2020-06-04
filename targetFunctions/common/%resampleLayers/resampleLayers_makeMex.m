% UNTITLED   Generate static library resampleLayers from resampleLayers.
% 
% Script generated from project 'resampleLayers.prj' on 09-Apr-2017.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('lib','ecoder',false);
cfg.GenerateReport = true;
cfg.GenCodeOnly = true;

%% Define argument types for entry-point 'resampleLayers'.
ARGS = cell(1,1);
ARGS{1} = cell(1,1);
ARGS{1}{1} = coder.typeof(0,[Inf  2],[1 0]);

%% Invoke MATLAB Coder.
codegen -config cfg resampleLayers -args ARGS{1}