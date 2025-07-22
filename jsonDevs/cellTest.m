

clc

% Make up our dummy struct, containing cell arrays of equal size....
myDat.simulation = {rand(10,2) ; rand(10,2)};
myDat.data = {rand(10,3) ; rand(10,3)};

jMyDat = jsondecode(jsonencode(myDat));
myDat
jMyDat


% Make up our dummy struct, containing cell arrays of edifferent size....
myDat2.simulation = {rand(13,2) ; rand(10,2)};
myDat2.data = {rand(13,3) ; rand(10,3)};

jMyDat2 = jsondecode(jsonencode(myDat2))
myDat2
jMyDat2