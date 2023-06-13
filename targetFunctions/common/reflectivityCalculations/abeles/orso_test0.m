


% Test0 Layers...
layers = [0.000000000000000000e+00 2.069999999999999840e+00 0.000000000000000000e+00 0.000000000000000000e+00
1.000000000000000000e+02 3.450000000000000178e+00 1.000000000000000056e-01 3.000000000000000000e+00
2.000000000000000000e+02 5.000000000000000000e+00 1.000000000000000021e-02 1.000000000000000000e+00
0.000000000000000000e+00 6.000000000000000000e+00 0.000000000000000000e+00 5.000000000000000000e+00];

layers(:,2) = layers(:,2) .* 1e-6;
layers(:,3) = layers(:,3) .* 1e-6;

data = dlmread('test0.dat');

thick = layers(:,1);
sld = complex(layers(:,2),layers(:,3));
rough = layers(:,4);

q = data(:,1);
N = size(layers,1);
ref = abelesSingle(q,N,thick,sld,rough);

% Plot the comparison....
figure(1); clf
semilogy(q,ref,'k-','LineWidth',2)
hold on
plot(data(:,1),data(:,2),'r.')


