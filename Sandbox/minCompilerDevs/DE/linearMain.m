clear
dat = dlmread('linearData.dat');

pars = [0.4 0.1];
constr = [0.1 1 ; 0.1 1];

problem.data = dat;
problem.fitpars = pars;
problem.line = [];
problem.fitconstr = constr;

%necessary to define all struct fields fr codegen
controls = []
;problem.S_struct.I_lentol   = [1];
problem.S_struct.FVr_x      = [1];
problem.S_struct.FVr_lim_up = [1];
problem.S_struct.FVr_lim_lo = [1];

problem.S_struct.I_NP         = 20;
problem.S_struct.F_weight     = [1];
problem.S_struct.F_CR         = [1];
problem.S_struct.I_D          = length(problem.fitpars);
problem.S_struct.FVr_minbound = problem.fitconstr(:,1);
problem.S_struct.FVr_maxbound = problem.fitconstr(:,2);
problem.S_struct.I_bnd_constr = problem.fitconstr;
problem.S_struct.I_itermax    = 1000;
problem.S_struct.F_VTR        = 1;
problem.S_struct.I_strategy   = 5;
problem.S_struct.I_refresh    = 1;
problem.S_struct.I_plotting   = 0;


problem = linear_DE_new_test(problem,controls);
