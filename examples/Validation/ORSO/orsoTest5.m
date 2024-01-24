function out = orsoTest5()
% ORSO validation Test4 - Reflectivity plus resolution...

layers = dlmread('test1.layers');

% Change the units to Å
layers(:,2) = layers(:,2) .* 1e-6;
layers(:,3) = layers(:,3) .* 1e-6;

% Read in the data.....
data = dlmread('test5.dat');

% Group the Layers
thick = layers(:,1);
sld = complex(layers(:,2),layers(:,3));
rough = layers(:,4);

% Calculate reflectivity....
q = data(:,1);
N = size(layers,1);
ref = abelesSingle(q,N,thick,sld,rough);

% Apply resolution....
FWHM = 2 * sqrt(2 * log(2)); % FWHM for Gaussian function
resol = 0.05 / FWHM;
ref = resolutionPolly(q,ref,resol,length(q));
%ref = smeared_abeles_constant(q,ref,resol);

% Plot the comparison....
figure(1); clf
semilogy(q,ref,'k-','LineWidth',2)
hold on
plot(data(:,1),data(:,2),'r.')

% Calculate the output....
out = sum(sum((data(:,2) - ref).^2));

