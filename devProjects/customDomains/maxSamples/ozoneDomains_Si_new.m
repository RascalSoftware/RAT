
function [output,subRough] = ozoneDomains_Si(params,bulkIn,bulkOut,contrast,domainNo)

% Split out the params....

% params = {{'Oxide thick',   10,         20,     50,     true}
%           {'Layer thick',   10,         300,    500,    true}
%           {'Layer SLD',     1e-6,       2e-6,   4e-6,   true}
%           {'Layer rough',   5,          10,     20,     true}
%           {'Domain d L1',   10,         20,     30,     true}
%           {'Domain rho l1', -0.5e-6,    1e-6,   3e-6,   true}
%           {'Domain sig l1', 3,          5,      9,      true}
%           {'Water lay d',   5,          15,     20,     true}
%           {'Water lay rho', -0.5e-6,    3e-6,   6.35e-6,true}
%           {'Water lay sig', 3,          5,      10,     true}
%           {'Dom nRepeats',  1,          10,     30,     true}
%     };



subRough = params(1);
oxThick = params(2);
layThick = params(3);
laySLD = params(4);
layRough = params(5);
dom_d = params(6);
dom_rho = params(7);
dom_sig = params(8);
waterLayD = params(9);
waterLayRho = params(10);
waterLaySig = params(11);
nRepeats = params(12);

oxide = [oxThick, 3.41e-6, subRough];

% Make up the sample depending on the domain
if domainNo == 1
    % One single bulk Matrix
    domainLayer = [layThick, laySLD, layRough];

else
    % domain stacks....

    % make the individual layers...
    domLay1 = [dom_d, dom_rho, dom_sig];
    domWatLay = [waterLayD, waterLayRho, waterLaySig];
    domStack = [domLay1; domWatLay];

    nRepeats = round(nRepeats);
    domainTotal = domStack;
    for i = 1:nRepeats
        domainTotal = [domainTotal ; domStack];
    end

    domainLayer = domainTotal;
end

output  = [domainLayer ; oxide];

end