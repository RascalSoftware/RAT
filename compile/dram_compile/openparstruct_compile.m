function [names,value,parind,local,upp,low,thetamu,thetasig,hyperpars] = ...
    openparstruct_compile(params,nbatch)

% This is a bespoke version of 'openparstruct' for the RAT compile.
% The original version is overly complex for our purposes, because
% it deals with local parameters and hyperparameters, and these options
% make the overall function unwieldly for compile purposes. This is a 
% stripped down version that gives the same output as the original
% function but in a neater form.

%#codegen
nParams = length(params);
names = cell(nParams,1);
value = zeros(nParams,1);
parind = zeros(nParams,1);
local = zeros(1,nParams);
low = zeros(1,nParams);
upp = zeros(1,nParams);
thetamu = zeros(1,nParams);
thetasig = zeros(1,nParams);

for i = 1:nParams
   thisParam = params{i};
   names{i} = thisParam{1};
   value(i) = thisParam{2};
   parind(i) = i;
   local(i) = 0;
   low(i) = thisParam{3};
   upp(i) = thisParam{4};
   thetamu(i) = thisParam{5};
   thetasig(i) = thisParam{6};
end

% Make empty hyperpars struct
ind = zeros(1,nParams);

hyperpars.ind = ind;
hyperpars.mu0 = [];
hyperpars.tau20 = [];
hyperpars.sig20 = [];
hyperpars.n0 = [];
hyperpars.names = {};
hyperpars.nhpar = 0;


end