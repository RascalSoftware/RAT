function outProblemDef = RATparseOutToProblemDef2(problemDefInput,outProblemStruct,problem,result)


%Reconstruct the problemDef class as an output
%Using the outputs from the calculation(s)
outProblemDef = problemDefInput;

%(1) Parameters
pars = outProblemStruct.params;
outProblemDef.params = pars;

%(2) Backgrounds
backs = outProblemStruct.backs;
outProblemDef.backgrounds = backs;

%(3) Scalefactors
scales = outProblemStruct.sf;
outProblemDef.scalefactors = scales;

%(4) Qzshifts
shifts = outProblemStruct.shifts;
outProblemDef.qzshifts = shifts;

%(4) Nbairs
nbairs = outProblemStruct.nba;
outProblemDef.nbairs = nbairs;

%(5) Nbsubs
nbsubs = outProblemStruct.nbs;
outProblemDef.nbsubs = nbsubs;

%(5) Resolutions
resol = outProblemStruct.res;

outProblemDef.resolutions = resol;

% resolNames = problemDef_cells{13};
% outProblemDef.resolutionNames = resolNames;
% 
% resolLimits = problemDef_limits.res;
% for i = 1:numberOfResols
%     outProblemDef.resolutionConstr{i} = resolLimits(i,:)



end