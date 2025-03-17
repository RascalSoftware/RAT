function [problemStruct,fitNames,fitPriors] = packParamsPriors(problemStruct,limits,priors)
% Pack the parameters into an array of those being fitted.
%
% Parameters
% ----------
% problemStruct : struct
%     The project struct.
% problemLimits : struct
%     The limits for each parameter.
% priors : array
%     The priors of each parameter.
%
% Returns
% -------
% problemStruct : struct
%     The project struct with fit information.
% fitNames : array
%     The names of the parameters being fit.
% fitPriors : array
%     The priors of each fit parameter.


    % We need to pack the parameters into an array consisting of those
    % that are being fitted.

    % Note that this order of parameters fields is hard-coded by this
    % routine, packParams, unpackParams, and getFitNames
    fields = {"params", "backgroundParams", "scalefactors", "bulkIns",...
        "bulkOuts", "resolutionParams", "domainRatios"};

    numberOfFitted = 0;
    for i = 1:length(fields)
        numberOfFitted = numberOfFitted + sum(problemStruct.checks.(fields{i}));
    end

    fitParams = zeros(1, numberOfFitted);
    fitLimits = zeros(numberOfFitted, 2);

    fitNames = cell(numberOfFitted, 1);
    fitPriors = zeros(numberOfFitted, 2);

    fitCounter = 1;

    for i = 1:length(fields)
        fitIndices = find(problemStruct.checks.(fields{i}));

        for n = 1:length(fitIndices)
            fitParams(fitCounter) = problemStruct.(fields{i})(fitIndices(n));
            fitLimits(fitCounter,1) = limits.(fields{i})(fitIndices(n),1);
            fitLimits(fitCounter,2) = limits.(fields{i})(fitIndices(n),2);        
            fitNames{fitCounter} = problemStruct.names.(fields{i}){fitIndices(n)};
            thisPrior = priors.(fields{i}){fitIndices(n)};
            if (strcmpi(thisPrior{2},'gaussian'))
                thisGausPrior = [thisPrior{3} thisPrior{4}];
            else
                thisGausPrior = [0 Inf];
            end
            fitPriors(fitCounter,:) = thisGausPrior; 
            fitCounter = fitCounter + 1;
        end
    end
    
    problemStruct.fitParams = fitParams;
    problemStruct.fitLimits = fitLimits;

end
