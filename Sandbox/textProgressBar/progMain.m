clear; clc


message = 'Testing';
pct = 0;

fprintf('Test run pf progress bar: ');
textProgressBar('init',-1);
for i = 0.01:0.01:1
    textProgressBar(message,i);
    pause(0.01);
end
textProgressBar('end',1);

fprintf('\n Second test run pf progress bar: ');
textProgressBar('init',-1);
for i = 0.01:0.01:1
    textProgressBar(message,i);
    pause(0.01);
end
textProgressBar('end',1);
