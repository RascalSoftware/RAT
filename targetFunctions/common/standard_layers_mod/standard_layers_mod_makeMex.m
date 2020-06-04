% UNTITLED   Generate static library standard_layers_mod from
%  standard_layers_mod.
% 
% Script generated from project 'standard_layers_mod.prj' on 09-Apr-2017.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('lib','ecoder',false);
cfg.GenerateReport = true;
cfg.GenCodeOnly = true;

%% Define argument types for entry-point 'standard_layers_mod'.
ARGS = cell(1,1);
ARGS{1} = cell(4,1);
ARGS{1}{1} = coder.typeof(0,[1 Inf],[0 1]);
ARGS{1}{2} = coder.typeof(0,[1 2]);
ARGS{1}{3} = coder.typeof(0);
ARG = coder.typeof(0,[1 5]);
ARGS{1}{4} = coder.typeof({ARG}, [1 Inf],[0 1]);

%% Invoke MATLAB Coder.
codegen -config cfg standard_layers_mod -args ARGS{1}