function [problemStruct,fitNames] = packParams(problemStruct,limits)

    % We need to pack the parameters into separate vectors of those that
    % are being fitted, and those that are held constant.

    % Note that this order of parameters fields is hard-coded by this
    % routine, packParamsPriors, and getFitNames
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
        for n = 1:length(problemStruct.checks.(fields{i}))
            if problemStruct.checks.(fields{i})(n) == 1
                fitParams(fitCounter) = problemStruct.(fields{i})(n);
                fitLimits(fitCounter,1) = limits.(fields{i})(n,1);
                fitLimits(fitCounter,2) = limits.(fields{i})(n,2);        
                fitNames{fitCounter} = problemStruct.names.(fields{i}){n};
                fitCounter = fitCounter + 1;
            else
                otherParams(otherCounter) = problemStruct.(fields{i})(n);
                otherLimits(otherCounter,1) = limits.(fields{i})(n,1);
                otherLimits(otherCounter,2) = limits.(fields{i})(n,2);
                otherCounter = otherCounter + 1;
            end
        end
    end
    
    problemStruct.fitParams = fitParams;
    problemStruct.otherParams = otherParams;
    problemStruct.fitLimits = fitLimits;
    problemStruct.otherLimits = otherLimits;

end