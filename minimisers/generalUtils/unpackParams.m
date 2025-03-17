function problemStruct = unpackParams(problemStruct)
% Unpack params out of fitParams and back into problem.params.
%
% Parameters
% ----------
% problemStruct : struct
%     The project struct.
%
% Returns
% -------
% problemStruct : struct
%     The project struct with unpacked fit information.
 
    % Note that this order of parameters fields is hard-coded by this
    % routine, packParams, packParamsPriors, and getFitNames
    fields = {"params", "backgroundParams", "scalefactors", "bulkIns",...
        "bulkOuts", "resolutionParams", "domainRatios"};

    fitCounter = 1;
 
    for i = 1:length(fields)
        fitIndices = find(problemStruct.checks.(fields{i}));

        for j = 1:length(fitIndices)
            problemStruct.(fields{i})(fitIndices(j)) = problemStruct.fitParams(fitCounter);
            fitCounter = fitCounter + 1;
        end
    end
    
end
