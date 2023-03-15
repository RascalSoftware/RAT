% Use this script to generate MEX  from Linux


%% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.TargetLang = 'C++';
cfg.EnableMexProfiling = true;
cfg.GenerateReport = true;
cfg.ReportPotentialDifferences = false;

%% Define argument types for entry-point 'testDLL'.
ARGS = cell(1,1);
ARGS{1} = cell(6,1);
ARGS{1}{1} = coder.typeof(0,[1 1000],[0 1]);
ARGS{1}{2} = coder.typeof(0,[1 1000],[0 1]);
ARGS{1}{3} = coder.typeof(0,[1 1000],[0 1]);
ARGS{1}{4} = coder.typeof(int32(0));
%ARGS{1}{5} = coder.newtype('string');
ARGS{1}{5} = coder.typeof('X',[1 Inf],[0 1]);
%ARGS{1}{6} = coder.newtype('string');
ARGS{1}{6} = coder.typeof('X',[1 Inf],[0 1]);


%% Invoke MATLAB Coder.
codegen -config cfg -o testDLL_mex testDLL -args ARGS{1}
