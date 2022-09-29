% test script for DR section

A_count = load('A-count.mat');
A_count = A_count.A_count;

invR = load('invR.mat');
invR = invR.invR;

npar = load('npar.mat');
npar = npar.npar;

trypath = load('trypath.mat');
trypath = trypath.trypath;

alpha = alphaTest(trypath, 3, invR, npar);

