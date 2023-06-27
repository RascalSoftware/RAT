
function [output,subRough] = ozoneDomains_Si(params,bulkIn,bulkOut,contrast,domainNo)

% Split out the params....

% {'Oxide thick',   10,         20,     50,     true}
%           {'Oxide SLD'      3e-6,       3.4e-6, 4e-6,   true}
%           {'Layer thick',   10,         300,    500,    true}
%           {'Layer SLD',     1e-6,       2e-6,   4e-6,   true}
%           {'Layer rough',   5,          10,     20,     true}
%           {'Domain d L1',   10,         20,     30,     true}
%           {'Domain rho l1', -0.5e-6,    1e-6,   3e-6,   true}
%           {'Domain sig l1', 3,          5,      9,      true}
%           {'Water lay d',   5,          15,     20,     true}
%           {'Domain d L2',   10,         20,     30,     true}
%           {'Domain rho l2', 1e-6,       2e-6,   6e-6,   true}
%           {'Domain sig l2', 3,          5,      9,      true}
%     };

subRough = params(1);
oxThick = params(2);
layThick = params(3);
laySLD = params(4);
layRough = params(5);
dom1_d = params(6);
dom1_rho = params(7);
dom1_sig = params(8);
waterLayD = params(9);
dom2_d = params(6);
dom2_rho = params(7);
dom2_sig = params(8);
nRepeats = params(9);

oxide = [oxThick, 3.41e-6, subRough];

% Make up the sample depending on the domain
if domainNo == 1
    % One single bulk Matrix
    domainLayer = [layThick, laySLD, layRough];

else
    % domain stacks....

    % make the individual layers...
    domLay1 = [dom1_d, dom1_rho, dom1_sig];
    domWatLay = [waterLayD, bulkOut(contrast), dom1_sig];
    domLay2 = [dom2_d, dom2_rho, dom2_sig];
    domStack = [domLay1; domWatLay; domLay2];

    nRepeats = round(nRepeats);
    domainTotal = domStack;
    for i = 1:nRepeats
        domainTotal = [domainTotal ; domStack];
    end

    domainLayer = domainTotal;
end

output  = [oxide ; domainLayer];

end