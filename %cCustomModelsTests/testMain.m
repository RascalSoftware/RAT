
clc
params = [3.735 20 0.2 55 0.2 0.1 4 3];
nba = 2.073e-6;
nbs  = [0 0 0];
numberOfContrasts = int32(3);

libraryName = 'customBilayer';
functionName = 'customBilayer';

% Initial load...
[output,rough] = testDLL_mex(params,nba,nbs,numberOfContrasts,libraryName,functionName);

profile on
for i = 1:100
    [output,rough] = testDLL_mex(params,nba,nbs,numberOfContrasts,libraryName,functionName);
end
profile off

fprintf('Final outputted value of rough %g \n',rough);

