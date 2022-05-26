cfg = coder.config('lib');
cfg.GenerateReport = true;
cfg.ReportPotentialDifferences = false;
cfg.GenCodeOnly = true;
cfg.InlineBetweenUserFunctions = 'never';
cfg.InlineBetweenMathWorksFunctions = 'never';
cfg.InlineBetweenUserAndMathWorksFunctions = 'never';
cfg.TargetLang = 'c++';
cfg.PreserveArrayDimensions = true;
cfg.PreserveVariableNames = 'UserNames';
cfg.ConstantFoldingTimeout = 0;
cfg.EnableMemcpy = false;
cfg.TargetLangStandard = 'C++11 (ISO)';
cfg.GenerateComments = true;
cfg.MATLABSourceComments = true;
cfg.DataTypeReplacement = 'CoderTypedefs';
cfg.BuildConfiguration = 'Debug';


ARGS = cell(1,1);
ARGS{1} = cell(4,1);
ARGS{1}{1} = coder.typeof(0,[Inf  1],[1 0]);
ARGS{1}{2} = coder.typeof(0);
ARGS{1}{3} = coder.typeof(0,[3  1],[0 0]);
ARGS{1}{4} = coder.typeof(0);

codegen -config cfg -package -lang:c++ myFun -args ARGS{1}