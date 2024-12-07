function [problemStruct,fitNames] = packParams(problemStruct,limits)

    % We need to pack the parameters into separate vectors of those that
    % are being fitted, and those that are held constant.

    % Note that this order of parameters fields is hard-coded by this
    % routine, packParamsPriors, unpackParams, and getFitNames
    fields = {"params", "backgroundParams", "scalefactors", "qzshifts",...
        "bulkIns", "bulkOuts", "resolutionParams", "domainRatios"};

    numberOfFitted = 0;
    numberOfTotal = 0;
    for i = 1:length(fields)
        numberOfFitted = numberOfFitted + sum(problemStruct.checks.(fields{i}));
        numberOfTotal = numberOfTotal + length(problemStruct.(fields{i}));
    end
       
    fitParams = zeros(1, numberOfFitted);
    otherParams = zeros(1, (numberOfTotal-numberOfFitted));
    fitLimits = zeros(numberOfFitted,2);
    otherLimits = zeros((numberOfTotal-numberOfFitted),2);

    fitNames = cell(numberOfFitted,1);
    for i = 1:numberOfFitted
        fitNames{i} = '';
    end
    
    fitCounter = 1;
    otherCounter = 1;

    for i = 1:length(fields)
        fitIndices = find(problemStruct.checks.(fields{i}));
        otherIndices = find(~problemStruct.checks.(fields{i}));
        
        for j = 1:length(fitIndices)
            fitParams(fitCounter) = problemStruct.(fields{i})(fitIndices(j));
            fitLimits(fitCounter,1) = limits.(fields{i})(fitIndices(j),1);
            fitLimits(fitCounter,2) = limits.(fields{i})(fitIndices(j),2);        
            fitNames{fitCounter} = problemStruct.names.(fields{i}){fitIndices(j)};
            fitCounter = fitCounter + 1;
        end

        for j = 1:length(otherIndices)
            otherParams(otherCounter) = problemStruct.(fields{i})(otherIndices(j));
            otherLimits(otherCounter,1) = limits.(fields{i})(otherIndices(j),1);
            otherLimits(otherCounter,2) = limits.(fields{i})(otherIndices(j),2);
            otherCounter = otherCounter + 1;
        end
    end
    
    problemStruct.fitParams = fitParams;
    problemStruct.otherParams = otherParams;
    problemStruct.fitLimits = fitLimits;
    problemStruct.otherLimits = otherLimits;

end