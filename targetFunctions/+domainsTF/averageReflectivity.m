function [totReflect,totSimul] = averageReflectivity(reflect1,reflect2,Simul1,Simul2,domainRatio)

% Calculates the avereaged reflectivity for domains samples (incoherent
% sum)

refY1 = reflect1(:,2);
refY2 = reflect2(:,2);

simY1 = Simul1(:,2);
simY2 = Simul2(:,2);

averageRefY = (domainRatio * refY1) + ((1 - domainRatio) * refY2);
averageSimY = (domainRatio * simY1) + ((1 - domainRatio) * simY2);

totReflect = [reflect1(:,1) averageRefY(:)];
totSimul = [Simul1(:,1) averageSimY(:)];

end
