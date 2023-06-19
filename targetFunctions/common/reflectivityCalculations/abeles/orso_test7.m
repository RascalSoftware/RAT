



layers = [0.00e+00 0.0e+00 0.00e+00 0
1.20e+03 4.66e+00 1.60e-02 1.00e+01
0.00e+00 6.36e+00 0.00e+00 3.00e+00];

layers(:,2) = layers(:,2) .* 1e-6;
layers(:,3) = layers(:,3) .* 1e-6;

data = dlmread('test7.dat');

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