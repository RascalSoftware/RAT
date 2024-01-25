
% Runs ORSO Validations.
% (For now, we exclude test 4 and test 5, as these test resolution functions
% which will diverge until phase 2 of the resolution calculations is
% implemented)

toRun = [0 1 2 3 6 7];

for i = 1:length(toRun)
    thisFile = sprintf('orso_test%d()',toRun(i));
    out = eval(thisFile);
    if out < 1e-10
        status = 'passed';
    else
        status = 'failed';
    end
    fprintf('Validation %s %s. Value = %d\n',thisFile,status,out);
end