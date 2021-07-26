% REFLECTIVITY_CALCULATION_CODEONLY_SCRIPT   Generate static library
%  reflectivity_calculation from reflectivity_calculation.
% 
% Script generated from project 'reflectivity_calculation.prj' on 07-Jul-2021.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('lib');
cfg.GenerateReport = true;
cfg.ReportPotentialDifferences = false;
cfg.GenCodeOnly = true;
cfg.InlineBetweenUserFunctions = 'Never';
cfg.InlineBetweenMathWorksFunctions = 'Never';
cfg.InlineBetweenUserAndMathWorksFunctions = 'Never';
%cfg.DataTypeReplacement = 'CoderTypedefs';

%% Define argument types for entry-point 'reflectivity_calculation'.
ARGS = cell(1,1);
ARGS{1} = cell(4,1);
ARGS_1_1 = struct;
ARGS_1_1.contrastBacks = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.contrastBacksType = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.TF = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_1.resample = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.dataPresent = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.numberOfContrasts = coder.typeof(0);
ARGS_1_1.geometry = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_1.contrastShifts = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.contrastScales = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.contrastNbas = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.contrastNbss = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.contrastRes = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.backs = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.shifts = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.sf = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.nba = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.nbs = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.res = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.params = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.numberOfLayers = coder.typeof(0);
ARGS_1_1.modelType = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_1.contrastCustomFiles = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_1.fitpars = coder.typeof(0,[Inf Inf],[1 1]);
ARGS_1_1.otherpars = coder.typeof(0,[Inf Inf],[1 1]);
ARGS_1_1.fitconstr = coder.typeof(0,[Inf Inf],[1 1]);
ARGS_1_1.otherconstr = coder.typeof(0,[Inf Inf],[1 1]);
ARGS{1}{1} = coder.typeof(ARGS_1_1);
ARGS_1_2 = cell([1 14]);
ARG = coder.typeof(0,[1 2]);
ARGS_1_2{1} = coder.typeof({ARG}, [1 Inf],[0 1]);
ARG = coder.typeof(0,[Inf  5],[1 1]);
ARGS_1_2{2} = coder.typeof({ARG}, [1 Inf],[0 1]);
ARG = coder.typeof(0,[1 2]);
ARGS_1_2{3} = coder.typeof({ARG}, [1 Inf],[0 1]);
ARG = coder.typeof(0,[1 2]);
ARGS_1_2{4} = coder.typeof({ARG}, [1 Inf],[0 1]);
ARG = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_2{5} = coder.typeof({ARG}, [1 Inf],[0 1]);
ARG = coder.typeof(0,[1 10],[0 1]);
ARGS_1_2{6} = coder.typeof({ARG}, [Inf  1],[1 0]);
ARG = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_2{7} = coder.typeof({ARG}, [1 Inf],[0 1]);
ARG = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_2{8} = coder.typeof({ARG}, [1 Inf],[0 1]);
ARG = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_2{9} = coder.typeof({ARG}, [1 Inf],[0 1]);
ARG = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_2{10} = coder.typeof({ARG}, [1 Inf],[0 1]);
ARG = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_2{11} = coder.typeof({ARG}, [1 Inf],[0 1]);
ARG = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_2{12} = coder.typeof({ARG}, [1 Inf],[0 1]);
ARG = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_2{13} = coder.typeof({ARG}, [1 Inf],[0 1]);
ARG = coder.typeof('X',[1 Inf],[0 1]);
ARG = coder.typeof({ARG}, [1 3]);
ARGS_1_2{14} = coder.typeof({ARG}, [1 Inf],[0 1]);
ARGS{1}{2} = coder.typeof(ARGS_1_2,[1 14]);
ARGS{1}{2} = ARGS{1}{2}.makeHeterogeneous();
ARGS_1_3 = struct;
ARGS_1_3.params = coder.typeof(0,[Inf  2],[1 0]);
ARGS_1_3.backs = coder.typeof(0,[Inf  2],[1 0]);
ARGS_1_3.scales = coder.typeof(0,[Inf  2],[1 0]);
ARGS_1_3.shifts = coder.typeof(0,[Inf  2],[1 0]);
ARGS_1_3.nba = coder.typeof(0,[Inf  2],[1 0]);
ARGS_1_3.nbs = coder.typeof(0,[Inf  2],[1 0]);
ARGS_1_3.res = coder.typeof(0,[Inf  2],[1 0]);
ARGS{1}{3} = coder.typeof(ARGS_1_3);
ARGS_1_4 = struct;
ARGS_1_4.para = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_4.proc = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_4.display = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_4.tolX = coder.typeof(0);
ARGS_1_4.tolFun = coder.typeof(0);
ARGS_1_4.maxFunEvals = coder.typeof(0);
ARGS_1_4.maxIter = coder.typeof(0);
ARGS_1_4.populationSize = coder.typeof(0);
ARGS_1_4.F_weight = coder.typeof(0);
ARGS_1_4.F_CR = coder.typeof(0);
ARGS_1_4.VTR = coder.typeof(0);
ARGS_1_4.numGen = coder.typeof(0);
ARGS_1_4.strategy = coder.typeof(0);
ARGS_1_4.Nlive = coder.typeof(0);
ARGS_1_4.nmcmc = coder.typeof(0);
ARGS_1_4.propScale = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_4.nsTolerance = coder.typeof(0);
ARGS_1_4.calcSld = coder.typeof(0);
ARGS_1_4.repeats = coder.typeof(0);
ARGS_1_4.nsimu = coder.typeof(0);
ARGS_1_4.burnin = coder.typeof(0);
ARGS_1_4_checks = struct;
ARGS_1_4_checks.params_fitYesNo = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_4_checks.backs_fitYesNo = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_4_checks.shifts_fitYesNo = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_4_checks.scales_fitYesNo = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_4_checks.nbairs_fitYesNo = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_4_checks.nbsubs_fitYesNo = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_4_checks.resol_fitYesNo = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_4.checks = coder.typeof(ARGS_1_4_checks);
ARGS{1}{4} = coder.typeof(ARGS_1_4);

%% Invoke MATLAB Coder.
codegen -config cfg -lang:c++ reflectivity_calculation -args ARGS{1}

