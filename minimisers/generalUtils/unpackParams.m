function problemStruct = unpackParams(problemStruct)

    % Unpack the params out of the fitParams and otherParams arrays
    % back into problem.params  
    
    % Note that this order of parameters fields is hard-coded by this
    % routine, packParams, packParamsPriors, and getFitNames
    fields = {"params", "backgroundParams", "scalefactors", "qzshifts",...
        "bulkIns", "bulkOuts", "resolutionParams", "domainRatios"};

    unpacked_counter = 1;
    packed_counter = 1;
 
    for i = 1:length(fields)
        uppars = zeros(1,length(problemStruct.(fields{i})));
        uppars_counter = 1;
        for j = 1:length(problemStruct.checks.(fields{i}))
            if problemStruct.checks.(fields{i})(j) == 1
                uppars(uppars_counter) = problemStruct.fitParams(unpacked_counter);
                unpacked_counter = unpacked_counter + 1;
                uppars_counter = uppars_counter + 1;
            else
                uppars(uppars_counter) = problemStruct.otherParams(packed_counter);
                packed_counter = packed_counter + 1;
                uppars_counter = uppars_counter + 1;
            end
        end
        problemStruct.(fields{i}) = uppars;
    end
    
end
