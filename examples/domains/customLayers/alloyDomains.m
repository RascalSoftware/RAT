
function [output,subRough] = alloyDomains(params,bulkIn,bulkOut,contrast,domain)

% Simple custom model for testing incoherent summing...
% Simple two layer of permalloy / gold, with up/down domains..

% Split up the parameters....
subRough = params(1);
alloyThick = params(2);
alloySLDup = params(3);
alloySLDdn = params(4);
alloyRough = params(5);
goldThick = params(6);
goldSLD = params(7);
goldRough = params(8);

% Make the layers....
alloyUp = [alloyThick, alloySLDup, alloyRough];
alloyDn = [alloyThick, alloySLDdn, alloyRough];
gold = [goldThick, goldSLD, goldRough];

% Make the model dependiong on which domain we are looking at..
if domain==1
    output = [alloyUp ; gold];
else
    output = [alloyDn ; gold];
end

end