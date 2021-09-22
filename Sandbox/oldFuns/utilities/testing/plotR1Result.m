function plotR1Result(problem)


data  = problem.shifted_data;
ref = problem.calculations.reflectivity;
sld = problem.calculations.slds;
figure(2); clf; hold on
subplot(1,2,1); hold on
for i = 1:length(data)
    thisDat = data{i};
    thisRef = ref{i};
    if i > 1
        mult = 2^(5*i);
    else
        mult = 1;
    end
    
    thisDat(:,2) = thisDat(:,2) ./ mult;
    thisDat(:,3) = thisDat(:,3) ./ mult;
    thisRef(:,2) = thisRef(:,2) ./ mult;
    errorbar(thisDat(:,1),thisDat(:,2),thisDat(:,3));
    plot(thisRef(:,1),thisRef(:,2));
end
set(gca,'YScale','log','XScale','log');

subplot(1,2,2); hold on
for i = 1:length(sld)
    thisSld = sld{i};
    plot(thisSld(:,1), thisSld(:,2));
end


end
