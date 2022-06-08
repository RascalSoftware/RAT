cfg = coder.config('lib');
cfg.GenerateReport = true;
cfg.ReportPotentialDifferences = false;
cfg.GenCodeOnly = true;
cfg.InlineBetweenUserFunctions = 'Readability';
cfg.InlineBetweenMathWorksFunctions = 'Readability';
cfg.InlineBetweenUserAndMathWorksFunctions = 'Readability';
cfg.TargetLang = 'c++';
cfg.PreserveArrayDimensions = true;
cfg.PreserveVariableNames = 'All';
cfg.BuildConfiguration = 'Faster Builds';


ARGS = cell(1,1);
ARGS{1} = cell(3,1);
ARGS{1}{1} = coder.typeof(0,[4  1],[0 0]);
ARGS{1}{2} = coder.typeof(0);
ARGS{1}{3} = coder.typeof(0);

codegen -config cfg myFun -args ARGS{1}