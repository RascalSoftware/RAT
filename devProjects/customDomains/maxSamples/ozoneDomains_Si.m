
function [output,subRough] = ozoneDomains_Si(params,bulkIn,bulkOut,contrast,domainNo)

% Split out the params....

%      1    "Substrate Roughness"         1         28.872          30    true 
%      2    "Oxide thick"                10         10.017          50    true 
%      3    "Layer thick"               150            500         700    true 
%      4    "Layer SLD"               1e-06          1e-06       4e-06    true 
%      5    "Layer rough"                 5         5.1083          20    true 
%      6    "Domain d L1"                10         18.623          30    true 
%      7    "Domain rho l1"          -5e-07    -1.1932e-07       3e-06    true 
%      8    "Domain sig l1"               3              9           9    true 
%      9    "Water lay d"                 5            7.5          20    true 
%     10    "Domain d L2"                10         13.303          30    true 
%     11    "Domain rho l2"           1e-06     1.8854e-06       6e-06    true 
%     12    "Domain sig l2"               3         5.7261           9    true 
%     13    "Dom nRepeats"                1         15.327          30    true 
%     14    "water layer sld"        -5e-07          3e-06    6.35e-06    true 



subRough = params(1);
oxThick = params(2);
layThick = params(3);
laySLD = params(4);
layRough = params(5);
dom1_d = params(6);
dom1_rho = params(7);
dom1_sig = params(8);
waterLayD = params(9);
dom2_d = params(10);
dom2_rho = params(11);
dom2_sig = params(12);
nRepeats = params(13);
watLayerSLD = params(14);

oxide = [oxThick, 3.41e-6, subRough];

% Make up the sample depending on the domain
if domainNo == 1
    % One single bulk Matrix
    domainLayer = [layThick, laySLD, layRough];

else
    % domain stacks....

    % make the individual layers...
    domLay1 = [dom1_d, dom1_rho, dom1_sig];
    domWatLay = [waterLayD, watLayerSLD, dom1_sig];
    domLay2 = [dom2_d, dom2_rho, dom2_sig];
    domStack = [domLay1; domWatLay; domLay2];

    nRepeats = round(nRepeats);
    domainTotal = domStack;
    for i = 1:nRepeats
        domainTotal = [domainTotal ; domStack];
    end

    domainLayer = domainTotal;
end

output  = [domainLayer ; oxide];

end