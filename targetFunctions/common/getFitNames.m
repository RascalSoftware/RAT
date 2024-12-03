function fitNames = getFitNames(problemStruct)

    % Note that this order of parameters fields is hard-coded by this
    % routine, packParams, and packParamsPriors
    fields = {"params", "backgroundParams", "scalefactors", "qzshifts",...
        "bulkIns", "bulkOuts", "resolutionParams", "domainRatios"};

    numberOfFitted = 0;
    for i = 1:length(fields)
        numberOfFitted = numberOfFitted + sum(problemStruct.checks.(fields{i}));
    end

    fitNames = cell(numberOfFitted,1);
    for i = 1:numberOfFitted
        fitNames{i} = '';
    end
    
    fitCounter = 1;

    for i = 1:length(fields)
        fitIndices = find(problemStruct.checks.(fields{i}));
        for n = 1:length(fitIndices)
            fitNames{fitCounter} = problemStruct.names.(fields{i}){fitIndices(n)};
            fitCounter = fitCounter + 1;
        end
    end

end
