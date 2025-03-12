function [reflectivity,simulation] = averageReflectivity(reflectivity1,reflectivity2,simulation1,simulation2,domainRatio)
% Calculates the averaged reflectivity for domains samples (incoherent
% sum)

refY1 = reflectivity1(:,2);
refY2 = reflectivity2(:,2);

simY1 = simulation1(:,2);
simY2 = simulation2(:,2);

averageRefY = (domainRatio * refY1) + ((1 - domainRatio) * refY2);
averageSimY = (domainRatio * simY1) + ((1 - domainRatio) * simY2);

reflectivity = [reflectivity1(:,1) averageRefY(:)];
simulation = [simulation1(:,1) averageSimY(:)];

end
