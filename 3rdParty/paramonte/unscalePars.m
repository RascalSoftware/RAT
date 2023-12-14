function problem = unscalePars(problem) 

limits = problem.fitLimits;
scaled = problem.fitParams;

unscaled = (scaled.*(limits(:,2)-limits(:,1)))+limits(:,1);

problem.fitParams = unscaled;

end
