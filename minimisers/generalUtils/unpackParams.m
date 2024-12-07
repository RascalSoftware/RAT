function problemStruct = unpackParams(problemStruct)

    % Unpack the params out of the fitParams and otherParams arrays
    % back into problem.params  
    
    % Note that this order of parameters fields is hard-coded by this
    % routine, packParams, packParamsPriors, and getFitNames
    fields = {"params", "backgroundParams", "scalefactors", "qzshifts",...
        "bulkIns", "bulkOuts", "resolutionParams", "domainRatios"};

    fit_counter = 1;
    other_counter = 1;
 
    for i = 1:length(fields)
        unpackedpars = zeros(1,length(problemStruct.(fields{i})));
        fitIndices = find(problemStruct.checks.(fields{i}));
        otherIndices = find(~problemStruct.checks.(fields{i}));

        for j = 1:length(fitIndices)
            unpackedpars(fitIndices(j)) = problemStruct.fitParams(fit_counter);
            fit_counter = fit_counter + 1;
        end

        for j = 1:length(otherIndices)
            unpackedpars(otherIndices(j)) = problemStruct.otherParams(other_counter);
            other_counter = other_counter + 1;
        end

        problemStruct.(fields{i}) = unpackedpars;
    end
    
end
