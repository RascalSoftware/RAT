clear

pars = load('pars.mat');
pars = pars.pars;

signal = pars.signal;
filter = pars.filter;

res = sld_convolute(signal,filter);