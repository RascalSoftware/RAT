function problemStruct = unpackParams(problemStruct)

    %Unpack the params out of the fitParams and otherParams arrays
    %back into problem.params  
    
    unpacked_counter = 1;
    packed_counter = 1;
    uppars_counter = 1;
    
    uppars = zeros(1,length(problemStruct.params));
    for i = 1:length(problemStruct.checks.params)
        if problemStruct.checks.params(i) == 1
            uppars(uppars_counter) = problemStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemStruct.params = uppars;

    %Also the backgrounds
    uppars = zeros(1,length(problemStruct.backgroundParams));
    uppars_counter = 1;
    for i = 1:length(problemStruct.checks.backgroundParams)
        if problemStruct.checks.backgroundParams(i) == 1
            uppars(uppars_counter) = problemStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemStruct.backgroundParams = uppars;

    %Scalefactors
    uppars = zeros(1,length(problemStruct.scalefactors));
    uppars_counter = 1;
    for i = 1:length(problemStruct.checks.scalefactors)
        if problemStruct.checks.scalefactors(i) == 1
            uppars(uppars_counter) = problemStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemStruct.scalefactors = uppars;

    %qzshifts
    uppars = zeros(1,length(problemStruct.qzshifts));
    uppars_counter = 1;
    for i = 1:length(problemStruct.checks.qzshifts)
        if problemStruct.checks.qzshifts(i) == 1
            uppars(uppars_counter) = problemStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemStruct.qzshifts = uppars;

    %Bulk In
    uppars = zeros(1,length(problemStruct.bulkIns));
    uppars_counter = 1;
    for i = 1:length(problemStruct.checks.bulkIns)
        if problemStruct.checks.bulkIns(i) == 1
            uppars(uppars_counter) = problemStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemStruct.bulkIns = uppars;

    %Bulk Out
    uppars = zeros(1,length(problemStruct.bulkOuts));
    uppars_counter = 1;
    for i = 1:length(problemStruct.checks.bulkOuts)
        if problemStruct.checks.bulkOuts(i) == 1
            uppars(uppars_counter) = problemStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemStruct.bulkOuts = uppars;

    %Resolutions
    uppars = zeros(1,length(problemStruct.resolutionParams));
    uppars_counter = 1;
    for i = 1:length(problemStruct.checks.resolutionParams)
        if problemStruct.checks.resolutionParams(i) == 1
            uppars(uppars_counter) = problemStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemStruct.resolutionParams = uppars;

    %Domain Ratios
    uppars = zeros(1,length(problemStruct.domainRatios));
    uppars_counter = 1;
    for i = 1:length(problemStruct.checks.domainRatios)
        if problemStruct.checks.domainRatios(i) == 1
            uppars(uppars_counter) = problemStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemStruct.domainRatios = uppars;

end
