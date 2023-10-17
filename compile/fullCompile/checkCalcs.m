
% Check SLD calcs...

figure(1);
clf
hold on;

for i = 1:numberOfContrasts
    nRuns = size(sld_yVals{i},1);
    thisX = sld_xVals{i};
    for n = 1:nRuns
        thisY = sld_yVals{i}(n,:);
        plot(thisX,thisY);
    end
end

