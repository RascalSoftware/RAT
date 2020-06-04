function output = runMultiNest()


problem = [];
problem.calcFun = @linearFitFun;

data = dlmread('linearData.dat');
problem.data = data;

fit_params = [0.5 0.5];
problem.fitpars = fit_params;
lims = [0 20 ; 0 20];
problem.lims = lims;

names = {'m' , 'c'};

prior = {};
for i = 1:length(names);
    prior{i,1} = names{i};
    prior{i,2} = 'uniform';
    prior{i,3} = lims(i,1);
    prior{i,4} = lims(i,2);
    prior{i,5} = 'fixed';
    thisGroup = {names{i}, 'uniform', lims(i,1), lims(i,2), 'fixed'};
    prior{i} = [thisGroup{1}];
end

%prior = prior';

%Tuning Parameters
model.ssfun = @linearFitFun;
Nlive = 150;
tolerance = 0.1;
likelihood = @linearFitFun;
model = @linearFitFun;
Nmcmc = 0;
extraparams = [];

[logZ, nest_samples, post_samples, H] = nested_sampler(data, Nlive, Nmcmc, ...
  tolerance, likelihood, model, prior, extraparams);


output.logZ = logZ;
output.H = H;
output.err = sqrt(H/length(nest_samples));
output.nest_samples = nest_samples;
output.post_samples = post_samples;
output.names = names;
output.lims = lims;

chain = output.post_samples;
limits = output.lims;
names = output.names;



%---------------------------------------------------


