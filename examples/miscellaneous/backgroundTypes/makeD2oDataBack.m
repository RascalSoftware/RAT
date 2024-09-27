

% Make a dummy background datasets for this problem .....



% Get the D2O data....
d2o_dat = readmatrix('DSPC_D2O.dat');

% Use the x value....
backgroundX = d2o_dat(:,1);
backValue = 2e-6;   % A typical vlue from the existing background....

% Make a background set...
dummyBackValues = ones(numel(backgroundX),1) .* backValue;

% Add Gaussian white noise to this....
% for i = 1:numel(dummyBackValues)
%     dummyBackValues(i) = dummyBackValues(i)
backNoise = normrnd(mean(dummyBackValues),5e-8,[numel(dummyBackValues),1]);
backError = normrnd(mean(dummyBackValues),1e-8,[numel(dummyBackValues),1]);
dummyBackValues = dummyBackValues + backNoise;

figure(1); clf
errorbar(d2o_dat(:,1),d2o_dat(:,2)./0.1,d2o_dat(:,3)./0.1,'bo');
hold on
errorbar(d2o_dat(:,1),dummyBackValues,backError,'ro');
set(gca,'YScale','log');

% Put these together into a dummy background dataset.....
dummyBack_d2o = [d2o_dat(:,1) dummyBackValues(:) backError(:)];
writematrix(dummyBack_d2o,'d2o_background_data.dat','FileType','text','Delimiter','\t');













