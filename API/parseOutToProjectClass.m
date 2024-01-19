function project = parseOutToProjectClass(project,problemDefStruct)

%Reconstruct the problemDef class as an output
%Using the outputs from the calculation(s)

%(1) Parameters
params = problemDefStruct.params;
for i = 1:length(params)
    project.setParameterValue(i,params(i));
end

%(2) Backgrounds
backgroundParams = problemDefStruct.backgroundParams;
for i = 1:length(backgroundParams)
    project.setBackgroundParamValue(i,backgroundParams(i));
end

%(3) Scalefactors
scalefactors = problemDefStruct.scalefactors;
for i = 1:length(scalefactors)
    project.setScalefactor(i,'value',scalefactors(i));
end

%(4) Qzshifts
qzshifts = problemDefStruct.qzshifts;
for i = 1:length(qzshifts)
    project.setQzshift(i,'value',qzshifts(i));
end

%(5) Bulk In
bulkIns = problemDefStruct.bulkIn;
for i = 1:length(bulkIns)
    project.setBulkIn(i,'value',bulkIns(i));
end

%(6) Bulk Out
bulkOuts = problemDefStruct.bulkOut;
for i = 1:length(bulkOuts)
    project.setBulkOut(i,'value',bulkOuts(i));
end

%(7) Resolutions
resolutionParams = problemDefStruct.resolutionParams;
for i = 1:length(resolutionParams)
    project.setResolutionParam(i,'value',resolutionParams(i));
end

% (8) Domain ratio
if strcmpi(problemDefStruct.TF,'domains')
    domainRatios = problemDefStruct.domainRatio;
    for i = 1:length(domainRatios)
        project.setDomainRatio(i,'value',domainRatios(i));
    end
end
