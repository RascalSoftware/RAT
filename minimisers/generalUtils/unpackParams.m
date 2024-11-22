function problemStruct = unpackParams(problemStruct,checks)

    %Unpack the params out of the fitParams and otherParams arrays
    %back into problem.params
    
    %problem = getappdata(0,'problem');
    
    
    unpacked_counter = 1;
    packed_counter = 1;
    uppars_counter = 1;
    
    uppars = zeros(1,length(problemStruct.params));
    for i = 1:length(checks.fitParam)
        if checks.fitParam(i) == 1
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
    for i = 1:length(checks.fitBackgroundParam)
        if checks.fitBackgroundParam(i) == 1
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
    for i = 1:length(checks.fitScalefactor)
        if checks.fitScalefactor(i) == 1
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
    for i = 1:length(checks.fitQzshift)
        if checks.fitQzshift(i) == 1
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
    uppars = zeros(1,length(problemStruct.bulkIn));
    uppars_counter = 1;
    for i = 1:length(checks.fitBulkIn)
        if checks.fitBulkIn(i) == 1
            uppars(uppars_counter) = problemStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemStruct.bulkIn = uppars;
    
    
    %Bulk Out
    uppars = zeros(1,length(problemStruct.bulkOut));
    uppars_counter = 1;
    for i = 1:length(checks.fitBulkOut)
        if checks.fitBulkOut(i) == 1
            uppars(uppars_counter) = problemStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemStruct.bulkOut = uppars;
    
    
    %Resolutions
    uppars = zeros(1,length(problemStruct.resolutionParams));
    uppars_counter = 1;
    for i = 1:length(checks.fitResolutionParam)
        if checks.fitResolutionParam(i) == 1
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
    uppars = zeros(1,length(problemStruct.domainRatio));
    uppars_counter = 1;
    for i = 1:length(checks.fitDomainRatio)
        if checks.fitDomainRatio(i) == 1
            uppars(uppars_counter) = problemStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemStruct.domainRatio = uppars;

end
