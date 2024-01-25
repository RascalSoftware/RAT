
% Standard layers analysis of a DSPC floating bilayer example.

% Start by making our model....
standardLayersDSPCScript;

% This has set up the project in a variable called 'problem'...
% Display it to see what we have...
disp(problem)
input('Press return to continue....')


% Now define a controls block and run some Differential Evolution on our
% model....
controls = controlsClass();
controls.procedure = 'DE';

% Send to RAT...
[problem,results] = RAT(problem,controls);

% Plot out what we have
figure(1); clf ; hold on
plotRefSLD(problem,results);
disp(problem)

input('Press return to continue....');

% Now run a Bayesian analysis using DREAM....
controls.procedure = 'dream';
controls.adaptPCR = true;

[problem,results] = RAT(problem,controls);

% And plot our our results
plotBayes(problem,results);
disp(problem);

% and we are done........



