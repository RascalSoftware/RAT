function problemDefStruct = unpackParams(problemDefStruct,controls)

    %Unpack the params out of the fitParams and otherParams arrays
    %back into problem.params
    
    %problem = getappdata(0,'problem');
    
    
    unpacked_counter = 1;
    packed_counter = 1;
    uppars_counter = 1;
    
    uppars = zeros(1,length(problemDefStruct.params));
    for i = 1:length(controls.checks.fitParam)
        if controls.checks.fitParam(i) == 1
            uppars(uppars_counter) = problemDefStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDefStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDefStruct.params = uppars;
    
    
    %Also the backgrounds
    uppars = zeros(1,length(problemDefStruct.backgroundParams));
    uppars_counter = 1;
    for i = 1:length(controls.checks.fitBackgroundParam)
        if controls.checks.fitBackgroundParam(i) == 1
            uppars(uppars_counter) = problemDefStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDefStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDefStruct.backgroundParams = uppars;
    
    %Scalefactors
    uppars = zeros(1,length(problemDefStruct.scalefactors));
    uppars_counter = 1;
    for i = 1:length(controls.checks.fitScalefactor)
        if controls.checks.fitScalefactor(i) == 1
            uppars(uppars_counter) = problemDefStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDefStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDefStruct.scalefactors = uppars;
    
    
    %qzshifts
    uppars = zeros(1,length(problemDefStruct.qzshifts));
    uppars_counter = 1;
    for i = 1:length(controls.checks.fitQzshift)
        if controls.checks.fitQzshift(i) == 1
            uppars(uppars_counter) = problemDefStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDefStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDefStruct.qzshifts = uppars;
    
    
    
    %Bulk In
    uppars = zeros(1,length(problemDefStruct.bulkIn));
    uppars_counter = 1;
    for i = 1:length(controls.checks.fitBulkIn)
        if controls.checks.fitBulkIn(i) == 1
            uppars(uppars_counter) = problemDefStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDefStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDefStruct.bulkIn = uppars;
    
    
    %Bulk Out
    uppars = zeros(1,length(problemDefStruct.bulkOut));
    uppars_counter = 1;
    for i = 1:length(controls.checks.fitBulkOut)
        if controls.checks.fitBulkOut(i) == 1
            uppars(uppars_counter) = problemDefStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDefStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDefStruct.bulkOut = uppars;
    
    
    %Resolutions
    uppars = zeros(1,length(problemDefStruct.resolutionParams));
    uppars_counter = 1;
    for i = 1:length(controls.checks.fitResolutionParam)
        if controls.checks.fitResolutionParam(i) == 1
            uppars(uppars_counter) = problemDefStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDefStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDefStruct.resolutionParams = uppars;
    
    
    %Domain Ratios
    uppars = zeros(1,length(problemDefStruct.domainRatio));
    uppars_counter = 1;
    for i = 1:length(controls.checks.fitDomainRatio)
        if controls.checks.fitDomainRatio(i) == 1
            uppars(uppars_counter) = problemDefStruct.fitParams(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDefStruct.otherParams(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDefStruct.domainRatio = uppars;

end
