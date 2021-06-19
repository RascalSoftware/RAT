intParams = load('intParams');

intParams = intParams.intParams;

bilayerSLD = intParams.bilayerSLD;
z = intParams.z;

new = interpolateOnToZ(bilayerSLD(:,1),bilayerSLD(:,2),z);





