
% Main for compile....
nbair = 2.073e-6;
nbsub = 6.35e-6;
srough = 5;

layers = [ 0     nbair  3
          100    1.00e-6   3
          100    4e-6      3
          0      nbsub  srough ];

q = linspace(0.01,0.5,500);

% Run the new calculation:
N = 4;

thick = layers(:,1);
sld = layers(:,2);
sig = layers(:,3);
% im = zeros(length(thick),1);
% imSld = [thick sld im sig];

refNew = abeles_reflect_matlab_mex(q,N,thick,sld,sig);


figure(1); clf
semilogy(q,refNew)