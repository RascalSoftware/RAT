function  [problemDef,outProblem,result,bayesResults] = runNestedSampler(problemDef,problemDefCells,problemDefLimits,controls)

checks = controls.checks;
[problemDef,fitNames] = packparams(problemDef,problemDefCells,problemDefLimits,checks);


        
%First deal with priors.
%Make uniform priors from the
%min/max limits for now.
prior = cell(length(fitNames),5);
%fitnames = problemDefCells{14};
%names = problemDefCells{14};
lims = problemDef.fitconstr;
for i = 1:length(fitNames)
    prior{i,1} = fitNames{i};
    prior{i,2} = 'uniform';
    prior{i,3} = lims(i,1);
    prior{i,4} = lims(i,2);
    prior{i,5} = 'fixed';
    thisGroup = {fitNames{i}, 'uniform', lims(i,1), lims(i,2), 'fixed'};
    prior{i} = [thisGroup{1}];
end

%prior = prior';
%Tuning Parameters - fixed for now
model.ssfun = @NSIntraFun;
Nlive = controls.Nlive;
tolerance = controls.nsTolerance;
likelihood = @NSIntraFun;
%model = problemDefCells;
Nmcmc = controls.nmcmc;
data = {problemDef ; controls ; problemDefLimits ; problemDefCells};

[logZ, nest_samples, post_samples, H] = nested_sampler(data, Nlive, Nmcmc, ...
    tolerance, likelihood, model, prior, []);
        
%     otherwise
%         %Debug
%         testRes = load('testRes');
%         testRes = testRes.testRes;
%         nest_samples = testRes.nest_samples;
%         problemDef = testRes.problemDef;
%         problemDefCells = testRes.problemDefCells;
%         problemDefLimits = testRes.problemDefLimits;
%         controls = testRes.controls;
%         logZ = 1;
% end

% output.results = results;
% output.chain = chain;
% output.s2chain = s2chain;
% output.sschain = sschain;
% output.bestPars = results.mean;
% output.data = data;

chain = nest_samples(:,1:end-1);

bayesOutputs.bestPars = mean(chain);
bayesOutputs.chain = chain;
bayesOutputs.fitNames = fitNames;
bayesOutputs.s2chain = [];
bayesOutputs.sschain = [];
bayesOutputs.data = problemDefCells{2};
bayesOutputs.results.logZ = logZ;
bayesOutputs.results.mean = mean(chain);

allProblem = data;

[problemDef,outProblem,result,bayesResults] = processBayes(bayesOutputs,allProblem);

% result.logX = logZ;
% result.nest_samples = nest_samples;
% result.post_samples = post_samples;
% result.fitNames = fitNames;
%xy_result = parseBayesResults(nest_samples,problemDef,problemDefCells,problemDefLimits,controls);
%result.xyResults = xy_result;

end
