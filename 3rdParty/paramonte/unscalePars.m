function problem = unscalePars(problem) 

limits = problem.fitconstr;
scaled = problem.fitpars;

unscaled = (scaled.*(limits(:,2)-limits(:,1)))+limits(:,1);

problem.fitpars = unscaled;