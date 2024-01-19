function problemStruct = scalePars(problemStruct)

limits = problemStruct.fitLimits;
vals = problemStruct.fitParams;

scaled = (vals(:) - limits(:,1))./(limits(:,2)-limits(:,1));

problemStruct.fitParams = scaled;
%problem.unscaledPars = vals;

end
