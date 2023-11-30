function problemDef = unpackParams(problemDef,controls)

    %Unpack the params out of the fitparsma and otherparams arrays
    %back into problem.params
    
    %problem = getappdata(0,'problem');
    
    
    unpacked_counter = 1;
    packed_counter = 1;
    uppars_counter = 1;
    
    uppars = zeros(1,length(problemDef.params));
    for i = 1:length(controls.checks.fitParam)
        if controls.checks.fitParam(i) == 1
            uppars(uppars_counter) = problemDef.fitpars(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDef.otherpars(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDef.params = uppars;
    
    
    %Also the backgrounds
    uppars = zeros(1,length(problemDef.backgroundParams));
    uppars_counter = 1;
    for i = 1:length(controls.checks.fitBackgroundParam)
        if controls.checks.fitBackgroundParam(i) == 1
            uppars(uppars_counter) = problemDef.fitpars(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDef.otherpars(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDef.backgroundParams = uppars;
    
    %Scalefactors
    uppars = zeros(1,length(problemDef.scalefactors));
    uppars_counter = 1;
    for i = 1:length(controls.checks.fitScalefactor)
        if controls.checks.fitScalefactor(i) == 1
            uppars(uppars_counter) = problemDef.fitpars(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDef.otherpars(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDef.scalefactors = uppars;
    
    
    %qshifts
    uppars = zeros(1,length(problemDef.qzshifts));
    uppars_counter = 1;
    for i = 1:length(controls.checks.fitQzshift)
        if controls.checks.fitQzshift(i) == 1
            uppars(uppars_counter) = problemDef.fitpars(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDef.otherpars(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDef.qzshifts = uppars;
    
    
    
    %Bulk In
    uppars = zeros(1,length(problemDef.bulkIn));
    uppars_counter = 1;
    for i = 1:length(controls.checks.fitBulkIn)
        if controls.checks.fitBulkIn(i) == 1
            uppars(uppars_counter) = problemDef.fitpars(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDef.otherpars(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDef.bulkIn = uppars;
    
    
    %Bulk Out
    uppars = zeros(1,length(problemDef.bulkOut));
    uppars_counter = 1;
    for i = 1:length(controls.checks.fitBulkOut)
        if controls.checks.fitBulkOut(i) == 1
            uppars(uppars_counter) = problemDef.fitpars(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDef.otherpars(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDef.bulkOut = uppars;
    
    
    %Resolutions
    uppars = zeros(1,length(problemDef.resolutionParams));
    uppars_counter = 1;
    for i = 1:length(controls.checks.fitResolutionParam)
        if controls.checks.fitResolutionParam(i) == 1
            uppars(uppars_counter) = problemDef.fitpars(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDef.otherpars(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDef.resolutionParams = uppars;
    
    
    %Domain Ratios
    uppars = zeros(1,length(problemDef.domainRatio));
    uppars_counter = 1;
    for i = 1:length(controls.checks.fitDomainRatio)
        if controls.checks.fitDomainRatio(i) == 1
            uppars(uppars_counter) = problemDef.fitpars(unpacked_counter);
            unpacked_counter = unpacked_counter + 1;
            uppars_counter = uppars_counter + 1;
        else
            uppars(uppars_counter) = problemDef.otherpars(packed_counter);
            packed_counter = packed_counter + 1;
            uppars_counter = uppars_counter + 1;
        end
    end
    problemDef.domainRatio = uppars;

end
