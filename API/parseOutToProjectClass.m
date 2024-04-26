function project = parseOutToProjectClass(project,problemStruct)

%Reconstruct the project class as an output
%Using the outputs from the calculation(s)

%(1) Parameters
params = problemStruct.params;
for i = 1:length(params)
    project.setParameterValue(i,params(i));
end

%(2) Backgrounds
backgroundParams = problemStruct.backgroundParams;
for i = 1:length(backgroundParams)
    project.setBackgroundParamValue(i,backgroundParams(i));
end

%(3) Scalefactors
scalefactors = problemStruct.scalefactors;
for i = 1:length(scalefactors)
    project.setScalefactor(i,'value',scalefactors(i));
end

%(4) Bulk In
bulkIns = problemStruct.bulkIn;
for i = 1:length(bulkIns)
    project.setBulkIn(i,'value',bulkIns(i));
end

%(5) Bulk Out
bulkOuts = problemStruct.bulkOut;
for i = 1:length(bulkOuts)
    project.setBulkOut(i,'value',bulkOuts(i));
end

%(6) Resolutions
resolutionParams = problemStruct.resolutionParams;
for i = 1:length(resolutionParams)
    project.setResolutionParam(i,'value',resolutionParams(i));
end

% (7) Domain ratio
if strcmpi(problemStruct.TF, calculationTypes.Domains.value)
    domainRatios = problemStruct.domainRatio;
    for i = 1:length(domainRatios)
        project.setDomainRatio(i,'value',domainRatios(i));
    end
end
