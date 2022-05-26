% CUSTOMBILAYER_SCRIPT   Generate static library customBilayer from
%  customBilayer.
% 
% Script generated from project 'customBilayer.prj' on 04-Mar-2022.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('lib','ecoder',false);
cfg.TargetLang = 'C++';
cfg.GenerateReport = true;
cfg.ReportPotentialDifferences = false;
cfg.GenCodeOnly = true;
cfg.MaxIdLength = 1024;

%% Define argument types for entry-point 'customBilayer'.
ARGS = cell(1,1);
ARGS{1} = cell(4,1);
ARGS{1}{1} = coder.typeof(0,[Inf  1],[1 0]);
ARGS{1}{2} = coder.typeof(0);
ARGS{1}{3} = coder.typeof(0,[Inf  1],[1 0]);
ARGS{1}{4} = coder.typeof(0);

%% Invoke MATLAB Coder.
codegen -config cfg customBilayer -args ARGS{1}

