function testMain;

global problemDef problemDef_cells problemDef_limits controls


% Load in the test inputPars
inputPars = load('inputPars');
inputPars = inputPars.inputPars;

problemDef = inputPars.problemDef;
problemDef_cells = inputPars.problemDef_cells;
problemDef_limits = inputPars.problemDef_limits;
controls = inputPars.controls;

[problem,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);


disp('debug')
problemDef = packparams(problemDef,problemDef_cells,problemDef_limits,controls.checks);

fitPars = problemDef.fitpars;

initVal = fitPars(:);
for i = 1:length(fitPars)*2
    shakeVal = randn(1,length(fitPars))./10;
    nextLine = fitPars + (shakeVal.*fitPars);
    initVal = [initVal , nextLine(:)];
end




% 
% ball = randn(length(fitPars),30)*0.1;
% ball(:,3) = ball(:,3) * 30;
% mball = bsxfun(@plus,fitPars,ball);

logpr = @(x) logPrior(x);
logl = @(x) logLike(x);


tic
m = gwmcmc(initVal,{logpr logl},30000,'burnin',0.3,'stepsize',1);
toc

disp('debug');


end



function LogLike = logLike(x)

global problemDef problemDef_cells problemDef_limits controls

problemDef.fitpars = x;
problemDef = unpackparams(problemDef,controls);

[problem,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);
chiSq = problem.calculations.sum_chi;
LogLike = log(exp(-chiSq/2));

end


function logPrior = logPrior(m)

global problemDef problemDef_cells problemDef_limits controls


% Prior information
%
% Here we formulate our prior knowledge about the model parameters. Here we use
% flat priors within a hard limits for each of the 3 model parameters.
% GWMCMC allows you to specify these kinds of priors as logical expressions.

% e.g. logprior =@(m) (m(1)>-5)&&(m(1)<0.5) && (m(2)>0)&&(m(2)<10) && (m(3)>-10)&&(m(3)<1) ;


% nPars = length(m);
% fitConstr = problemDef.fitconstr;
% fitPars = m;
% 
% for i = 1:length(fitPars)
%     thisConstr = fitConstr(i,:);
%     thisLogical = (thisConstr(1)<m(i)) && (thisConstr(2)>m(i));
% end
% 
% logPrior = any(thisLogical);
logPrior = 0;

end








