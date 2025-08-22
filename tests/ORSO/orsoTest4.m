function out = orsoTest4()
% ORSO validation Test4 - Reflectivity plus resolution...

layers = dlmread('test0.layers');

% Change the units to Å
layers(:,2) = layers(:,2) .* 1e-6;
layers(:,3) = layers(:,3) .* 1e-6;

% Read in the data.....
data = dlmread('test4.dat');
datResol = data(:,4);

% Group the Layers
thick = layers(:,1);
sld = complex(layers(:,2),layers(:,3));
rough = layers(:,4);

% Calculate reflectivity....
q = data(:,1);
N = size(layers,1);
ref = abelesSingle(q,N,thick,sld,rough);

% Apply resolution....
resol = datResol;
ref = resolutionPolly(q,ref,resol,length(q));
%ref = dataResolutionPolly(q,ref,datResol,length(q));

% Plot the comparison....
figure(1); clf
semilogy(q,ref,'k-','LineWidth',2)
hold on
plot(data(:,1),data(:,2),'ro')

% Calculate the output....
out = sum(sum((data(:,2) - ref).^2));

