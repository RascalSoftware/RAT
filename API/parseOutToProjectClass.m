function outProblemDef = parseOutToProjectClass(problemDefInput,outProblemStruct)


%Reconstruct the problemDef class as an output
%Using the outputs from the calculation(s)
outProblemDef = problemDefInput;

%(1) Parameters
pars = outProblemStruct.params;
for i = 1:length(pars)
    outProblemDef.setParameterValue(i,pars(i));
end

%(2) Backgrounds
backs = outProblemStruct.backs;
for i = 1:length(backs)
    outProblemDef.setBacksParValue(i,backs(i));
end

%(3) Scalefactors
scales = outProblemStruct.sf;
for i = 1:length(scales)
    outProblemDef.setScalefactor(i,'value',scales(i));
end

%(4) Qzshifts
% shifts = outProblemStruct.shifts;
% outProblemDef.qzshifts = shifts;

%(4) Nbairs
nbairs = outProblemStruct.nba;
for i = 1:length(nbairs)
    outProblemDef.setBulkIn(i,'value',nbairs(i));
end

%(5) Nbsubs
nbsubs = outProblemStruct.nbs;
for i = 1:length(nbsubs)
    outProblemDef.setBulkOut(i,'value',nbsubs(i));
end

%(5) Resolutions
resol = outProblemStruct.res;
for i = 1:length(resol)
    outProblemDef.setResolPar(i,'value',resol(i));
end

% (6) Domain ratio
if strcmpi(outProblemStruct.TF,'domains')
    domainRatios = outProblemStruct.domainRatio;
    for i = 1:length(domainRatios)
        outProblemDef.setDomainRatio(i,'value',domainRatios(i));
    end
end
