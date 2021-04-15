% UNTITLED   Generate static library unpackPars from unpackPars.
% 
% Script generated from project 'unpackPars.prj' on 09-Apr-2017.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('lib','ecoder',false);
cfg.GenerateReport = true;
cfg.GenCodeOnly = true;

%% Invoke MATLAB Coder.
codegen -config cfg unpackPars