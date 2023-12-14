function problem = scalePars(problem)

limits = problem.fitLimits;
vals = problem.fitParams;

scaled = (vals(:) - limits(:,1))./(limits(:,2)-limits(:,1));

problem.fitParams = scaled;
%problem.unscaledPars = vals;

end
