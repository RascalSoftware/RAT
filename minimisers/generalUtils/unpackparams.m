function problemDef = unpackparams(problemDef,controls);

%Unpack the params out of the fitparsma and otherparams arrays
%back into problem.params

%problem = getappdata(0,'problem');


unpacked_counter = 1;
packed_counter = 1;
uppars_counter = 1;

uppars = zeros(1,length(problemDef.params));
for i = 1:length(controls.checks.params_fitYesNo)
    if controls.checks.params_fitYesNo(i) == 1
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
uppars = zeros(1,length(problemDef.backs));
uppars_counter = 1;
for i = 1:length(controls.checks.backs_fitYesNo)
    if controls.checks.backs_fitYesNo(i) == 1
        uppars(uppars_counter) = problemDef.fitpars(unpacked_counter);
        unpacked_counter = unpacked_counter + 1;
        uppars_counter = uppars_counter + 1;
    else
        uppars(uppars_counter) = problemDef.otherpars(packed_counter);
        packed_counter = packed_counter + 1;
        uppars_counter = uppars_counter + 1;
    end
end
problemDef.backs = uppars;

%Scalefactors
uppars = zeros(1,length(problemDef.sf));
uppars_counter = 1;
for i = 1:length(controls.checks.scales_fitYesNo)
    if controls.checks.scales_fitYesNo(i) == 1
        uppars(uppars_counter) = problemDef.fitpars(unpacked_counter);
        unpacked_counter = unpacked_counter + 1;
        uppars_counter = uppars_counter + 1;
    else
        uppars(uppars_counter) = problemDef.otherpars(packed_counter);
        packed_counter = packed_counter + 1;
        uppars_counter = uppars_counter + 1;
    end
end
problemDef.sf = uppars;


%qshifts
uppars = zeros(1,length(problemDef.shifts));
uppars_counter = 1;
for i = 1:length(controls.checks.shifts_fitYesNo)
    if controls.checks.shifts_fitYesNo(i) == 1
        uppars(uppars_counter) = problemDef.fitpars(unpacked_counter);
        unpacked_counter = unpacked_counter + 1;
        uppars_counter = uppars_counter + 1;
    else
        uppars(uppars_counter) = problemDef.otherpars(packed_counter);
        packed_counter = packed_counter + 1;
        uppars_counter = uppars_counter + 1;
    end
end
problemDef.shifts = uppars;



%Nbairs
uppars = zeros(1,length(problemDef.nba));
uppars_counter = 1;
for i = 1:length(controls.checks.nbairs_fitYesNo)
    if controls.checks.nbairs_fitYesNo(i) == 1
        uppars(uppars_counter) = problemDef.fitpars(unpacked_counter);
        unpacked_counter = unpacked_counter + 1;
        uppars_counter = uppars_counter + 1;
    else
        uppars(uppars_counter) = problemDef.otherpars(packed_counter);
        packed_counter = packed_counter + 1;
        uppars_counter = uppars_counter + 1;
    end
end
problemDef.nba = uppars;


%Nbsubs
uppars = zeros(1,length(problemDef.nbs));
uppars_counter = 1;
for i = 1:length(controls.checks.nbsubs_fitYesNo)
    if controls.checks.nbsubs_fitYesNo(i) == 1
        uppars(uppars_counter) = problemDef.fitpars(unpacked_counter);
        unpacked_counter = unpacked_counter + 1;
        uppars_counter = uppars_counter + 1;
    else
        uppars(uppars_counter) = problemDef.otherpars(packed_counter);
        packed_counter = packed_counter + 1;
        uppars_counter = uppars_counter + 1;
    end
end
problemDef.nbs = uppars;


%Finally resolutions
uppars = zeros(1,length(problemDef.res));
uppars_counter = 1;
for i = 1:length(controls.checks.resol_fitYesNo)
    if controls.checks.resol_fitYesNo(i) == 1
        uppars(uppars_counter) = problemDef.fitpars(unpacked_counter);
        unpacked_counter = unpacked_counter + 1;
        uppars_counter = uppars_counter + 1;
    else
        uppars(uppars_counter) = problemDef.otherpars(packed_counter);
        packed_counter = packed_counter + 1;
        uppars_counter = uppars_counter + 1;
    end
end
problemDef.res = uppars;


%setappdata(0,'problem',problem);