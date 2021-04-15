function [params,backs,scalefac,shifts,nba,nbs,resolution] = unpackPars(fitYN,fitPars,otherPars,backsYN, ...
    scalesYN,shiftsYN,nbairYN,nbsubYN,resYN)

%Unpack the params out of the fitpars and otherparams arrays
%back into problem.params

%problem = getappdata(0,'problem');

uppars = [];
unpacked_counter = 1;
packed_counter = 1;
for i = 1:length(fitYN)
    if fitYN(i) == 1
        uppars(length(uppars)+1) = fitPars(unpacked_counter);
        unpacked_counter = unpacked_counter + 1;
    else
        uppars(length(uppars)+1) = otherPars(packed_counter);
        packed_counter = packed_counter + 1;
    end
end

params = uppars;

uppars = [];
%Also the backgrounds
for i = 1:length(backsYN);
    if backsYN(i) == 1;
        uppars(length(uppars)+1) = fitPars(unpacked_counter);
        unpacked_counter = unpacked_counter + 1;
    else
        uppars(length(uppars)+1) = otherPars(packed_counter);
        packed_counter = packed_counter + 1;
    end
end

backs = uppars;

uppars = [];
%And scalefactors...
for i = 1:length(scalesYN)
    if scalesYN(i) == 1
        uppars(length(uppars)+1) = fitPars(unpacked_counter);
        unpacked_counter = unpacked_counter + 1;
    else
        uppars(length(uppars)+1) = otherPars(packed_counter);
        packed_counter = packed_counter + 1;
    end
end
scalefac = uppars;

uppars = [];
%Now the qshifts
for i = 1:length(shiftsYN)
    if shiftsYN(i) == 1
        uppars(length(uppars)+1) = fitPars(unpacked_counter);
        unpacked_counter = unpacked_counter + 1;
    else
        uppars(length(uppars)+1) = otherPars(packed_counter);
        packed_counter = packed_counter + 1;
    end
end
shifts = uppars;


uppars = [];
%Now the Nbairs
for i = 1:length(nbairYN);
    if nbairYN(i) == 1;
        uppars(length(uppars)+1) = fitPars(unpacked_counter);
        unpacked_counter = unpacked_counter + 1;
    else
        uppars(length(uppars)+1) = otherPars(packed_counter);
        packed_counter = packed_counter + 1;
    end
end
nba = uppars;

uppars = [];
%Now the qshifts
for i = 1:length(nbsubYN)
    if nbsubYN == 1
        uppars(length(uppars)+1) = fitPars(unpacked_counter);
        unpacked_counter = unpacked_counter + 1;
    else
        uppars(length(uppars)+1) = otherPars(packed_counter);
        packed_counter = packed_counter + 1;
    end
end
nbs = uppars;


%Finally resolutions
uppars = [];
%Now the qshifts
for i = 1:length(resYN);
    if resYN(i) == 1;
        uppars(length(uppars)+1) = fitPars(unpacked_counter);
        unpacked_counter = unpacked_counter + 1;
    else
        uppars(length(uppars)+1) = otherPars(packed_counter);
        packed_counter = packed_counter + 1;
    end
end

resolution = uppars;


%setappdata(0,'problem',problem);