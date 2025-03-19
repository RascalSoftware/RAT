function problemStruct = packParams(problemStruct,limits)
% Pack the parameters into an array of those being fitted.
%
% Parameters
% ----------
% problemStruct : struct
%     The project struct.
% problemLimits : struct
%     The limits for each parameter.
%
% Returns
% -------
% problemStruct : struct
%     The project struct with fit information.
% fitNames : array
%     The names of the parameters being fit.

    % Note that this order of parameters fields is hard-coded by this
    % routine, packParamsPriors, unpackParams, and getFitNames
    fields = {"params", "backgroundParams", "scalefactors", "bulkIns",...
        "bulkOuts", "resolutionParams", "domainRatios"};

    numberOfFitted = 0;
    for i = 1:length(fields)
        numberOfFitted = numberOfFitted + sum(problemStruct.checks.(fields{i}));
    end
       
    fitParams = zeros(1, numberOfFitted);
    fitLimits = zeros(numberOfFitted, 2);
    
    fitCounter = 1;

    for i = 1:length(fields)
        fitIndices = find(problemStruct.checks.(fields{i}));

        for j = 1:length(fitIndices)
            fitParams(fitCounter) = problemStruct.(fields{i})(fitIndices(j));
            fitLimits(fitCounter,1) = limits.(fields{i})(fitIndices(j),1);
            fitLimits(fitCounter,2) = limits.(fields{i})(fitIndices(j),2);
            fitCounter = fitCounter + 1;
        end
    end
    
    problemStruct.fitParams = fitParams;
    problemStruct.fitLimits = fitLimits;

end
