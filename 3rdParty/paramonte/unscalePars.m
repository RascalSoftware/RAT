function problemStruct = unscalePars(problemStruct) 

limits = problemStruct.fitLimits;
scaled = problemStruct.fitParams;

unscaled = (scaled.*(limits(:,2)-limits(:,1)))+limits(:,1);

problemStruct.fitParams = unscaled;

end
