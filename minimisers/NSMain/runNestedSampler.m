function  [problemDef,outProblem,result,bayesResults] = runNestedSampler(problemDef,problemDef_cells,problemDef_limits,controls)
debug = 0;

checks = controls.checks;
[problemDef,fitNames] = packparams(problemDef,problemDef_cells,problemDef_limits,checks);

switch debug
    case 0
        
        %First deal with priors.
        %Make uniform priors from the
        %min/max limits for now.
        prior = {};
        %fitnames = problemDef_cells{14};
        %names = problemDef_cells{14};
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
        tolerance = 1;
        likelihood = @NSIntraFun;
        %model = problemDef_cells;
        Nmcmc = controls.nmcmc;
        data = {problemDef ; controls ; problemDef_limits ; problemDef_cells};
        
        [logZ, nest_samples, post_samples, H] = nested_sampler(data, Nlive, Nmcmc, ...
            tolerance, likelihood, model, prior, []);
        
    otherwise
        %Debug
        testRes = load('testRes');
        testRes = testRes.testRes;
        nest_samples = testRes.nest_samples;
        problemDef = testRes.problemDef;
        problemDef_cells = testRes.problemDef_cells;
        problemDef_limits = testRes.problemDef_limits;
        controls = testRes.controls;
        logZ = 1;
end

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
bayesOutputs.data = problemDef_cells{2};
bayesOutputs.results.logZ = logZ;
bayesOutputs.results.mean = mean(chain);

allProblem = data;

[problemDef,outProblem,result,bayesResults] = processBayes_newMethod(bayesOutputs,allProblem);

% result.logX = logZ;
% result.nest_samples = nest_samples;
% result.post_samples = post_samples;
% result.fitNames = fitNames;
%xy_result = parseBayesResults(nest_samples,problemDef,problemDef_cells,problemDef_limits,controls);
%result.xyResults = xy_result;

end
