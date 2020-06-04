clear

a = load('slds');
slds = a.slds;

thisProfile = slds{1};

%out = resampleLayers(thisProfile);

out2 = resampleLayers_new(thisProfile);

%isequal(out,out2)