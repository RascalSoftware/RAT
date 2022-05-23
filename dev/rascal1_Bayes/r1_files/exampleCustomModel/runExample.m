
% path = fullfile(pwd,'exampleCustomModel');
% addpath(path);

path = fullfile('..','mcmcstat');
addpath(path);

path = fullfile('..','mcmcstat','private_dir');
addpath(path);

addpath('../');

%old_Inter_SAM_script;
problem = r1ToProjectClass('rascal_twoGaussModel.mat');

% Fix r1 to project class bug with resol....
problem.setResolPar(1,'fit',true);
problem.setResolPar(1,'value',0.041)

controls = controlsDef();
controls.nsimu = 5000;
controls.repeats = 3;

output = runR2withR1Bayes(problem,controls);



