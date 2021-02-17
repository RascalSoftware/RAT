% OCTAVECALLER_SCRIPT   Generate MEX-function octaveCaller_mex from
%  octaveCaller.
% 
% Script generated from project 'octaveCaller.prj' on 03-Nov-2020.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.GenerateReport = true;
cfg.LaunchReport = true;
cfg.EnableJIT = true;

%% Invoke MATLAB Coder.
codegen -config cfg octaveCaller

