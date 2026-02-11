function out = orsoTest4(mm)
% ORSO validation Test4 - Reflectivity plus resolution...
if ~exist('mm','var')
    mm = 1
end
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
tic
for i=1:10000
ref = abelesSingle_mex(q',N,thick,layers(:,2),layers(:,3),rough);
end
toc

% Apply resolution....
resol = datResol;
%mm  = 2
%resol = repmat(log(2)*mm,1,numel(q));
tic
for i = 1:10000
    refI = resolutionPolly_mex(q',ref',resol',length(q));
%ref = resolutionPollyWithPoints(q',ref',resol',length(q),thick,sld,rough);
end
toc
tic
for i = 1:10000
    refI = resolutionPolly(q',ref',resol',length(q));
%ref = resolutionPollyWithPoints(q',ref',resol',length(q),thick,sld,rough);
end
toc
tic
for i = 1:10000
%reIf = resolutionPolly_mex(q',ref',resol',length(q));
    %refI = resolutionTrapezoidPolly_mex(q',ref',resol',length(q));
    %refI = resolutionPollyWithPoints_mex(q',ref',resol',length(q),thick,layers(:,2),layers(:,3),rough);
    refI = resolutionExpansionWithPoints_mex(q',ref',resol',length(q));    
end
toc

%ref = dataResolutionPolly(q,ref,datResol,length(q));

% Plot the comparison....
figure(1); clf
semilogy(q,refI,'k-','LineWidth',2)
hold on
plot(data(:,1),data(:,2),'ro')

% Calculate the output....
out = sum((data(:,2) - refI).^2)

