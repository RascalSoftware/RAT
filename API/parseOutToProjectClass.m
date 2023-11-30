function outProblemDef = parseOutToProjectClass(problemDefInput,outProblemStruct)

%Reconstruct the problemDef class as an output
%Using the outputs from the calculation(s)
outProblemDef = problemDefInput;

%(1) Parameters
params = outProblemStruct.params;
for i = 1:length(params)
    outProblemDef.setParameterValue(i,params(i));
end

%(2) Backgrounds
backgroundParams = outProblemStruct.backgroundParams;
for i = 1:length(backgroundParams)
    outProblemDef.setBackgroundParamValue(i,backgroundParams(i));
end

%(3) Scalefactors
scalefactors = outProblemStruct.scalefactors;
for i = 1:length(scalefactors)
    outProblemDef.setScalefactor(i,'value',scalefactors(i));
end

%(4) Qzshifts
qzshifts = outProblemStruct.qzshifts;
for i = 1:length(qzshifts)
    outProblemDef.setQzshift(i,'value',qzshifts(i));
end

%(5) Bulk In
bulkIns = outProblemStruct.bulkIn;
for i = 1:length(bulkIns)
    outProblemDef.setBulkIn(i,'value',bulkIns(i));
end

%(6) Bulk Out
bulkOuts = outProblemStruct.bulkOut;
for i = 1:length(bulkOuts)
    outProblemDef.setBulkOut(i,'value',bulkOuts(i));
end

%(7) Resolutions
resolutionParams = outProblemStruct.resolutionParams;
for i = 1:length(resolutionParams)
    outProblemDef.setResolutionParam(i,'value',resolutionParams(i));
end

% (8) Domain ratio
if strcmpi(outProblemStruct.TF,'domains')
    domainRatios = outProblemStruct.domainRatio;
    for i = 1:length(domainRatios)
        outProblemDef.setDomainRatio(i,'value',domainRatios(i));
    end
end
