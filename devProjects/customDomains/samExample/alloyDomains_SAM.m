
function [output,subRough] = alloyDomains_SAM(params,bulkIn,bulkOut,contrast,domain)

% Simple custom model for testing incoherent summing...
% Simple two layer of permalloy / gold, with up/down domains..

% Split up the parameters....
subRough = params(1);
alloyThick = params(2);
alloySldUpRe = params(3);
alloySldUpIm = params(4);
alloySldDnRe = params(5);
alloySldDnIm = params(6);
alloyRough = params(7);
goldThick = params(8);
goldSldRe = params(9);
goldSldIm = params(10);
goldRough = params(11);
samTailsThick = params(12);
samTailsSLD = params(13);
samHeadThick = params(14);
samHeadSLD = params(15);
samHeadHydration = params(16);
samCoverage = params(17);
samRough = params(18);

% Make the layers....
% (1) Metals
alloyUp = [alloyThick, alloySldUpRe, alloySldUpIm, alloyRough];
alloyDn = [alloyThick, alloySldDnRe, alloySldDnIm, alloyRough];
gold = [goldThick, goldSldRe, goldSldIm, goldRough];

% Sam....
% Head hydration....
samHeadSLD = (samHeadHydration * bulkOut(contrast)) + (samHeadSLD * (1 - samHeadHydration));

% Overall coverage....
samTailsSLD = (samTailsSLD * samCoverage) + ((1 - samCoverage) * bulkOut(contrast));
samHeadSLD = (samHeadSLD * samCoverage) + ((1 - samCoverage) * bulkOut(contrast));

% SAM layers....
samTails = [samTailsThick, samTailsSLD, 0, samRough];
samHead = [samHeadThick, samHeadSLD, 0, samRough];

% Make the model dependiong on which domain we are looking at..
if domain==1
    output = [alloyUp ; gold; samTails; samHead];
else
    output = [alloyDn ; gold; samTails; samHead];
end

end