function out = orsoTest2()
% ORSO validation Test2

layers = dlmread('test2.layers');

% Need at least one layer....
layers = [layers(1,:) ; [0 0 0 0] ; layers(2,:)];

% Change the units to Å
layers(:,2) = layers(:,2) .* 1e-6;
layers(:,3) = layers(:,3) .* 1e-6;

% Read in the data.....
data = dlmread('test2.dat');

% Group the Layers
thick = layers(:,1);
sld = complex(layers(:,2),layers(:,3));
rough = layers(:,4);




% Calculate reflectivity...
q = data(:,1);
N = size(layers,1);
ref = abelesSingle(q,N,thick,sld,rough);

% Plot the comparison....
figure(1); clf
semilogy(q,ref,'k-','LineWidth',2)
hold on
plot(data(:,1),data(:,2),'r.')

% Calculate the output....
out = sum(sum((data(:,2) - ref).^2));

