function [problemStruct,fitNames] = packParams(problemStruct,limits)

    % We need to pack the parameters into an array consisting of those
    % that are being fitted.

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

    fitNames = cell(numberOfFitted, 1);
    for i = 1:numberOfFitted
        fitNames{i} = '';
    end
    
    fitCounter = 1;

    for i = 1:length(fields)
        fitIndices = find(problemStruct.checks.(fields{i}));

        for j = 1:length(fitIndices)
            fitParams(fitCounter) = problemStruct.(fields{i})(fitIndices(j));
            fitLimits(fitCounter,1) = limits.(fields{i})(fitIndices(j),1);
            fitLimits(fitCounter,2) = limits.(fields{i})(fitIndices(j),2);        
            fitNames{fitCounter} = problemStruct.names.(fields{i}){fitIndices(j)};
            fitCounter = fitCounter + 1;
        end
    end
    
    problemStruct.fitParams = fitParams;
    problemStruct.fitLimits = fitLimits;

end
