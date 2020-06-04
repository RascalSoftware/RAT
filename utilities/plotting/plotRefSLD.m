function plotRefSLD(outProblem,result)




reflectivity = result.reflectivity;
shifted_data = result.shifted_data;
slds = result.sldProfiles;

numberOfContrasts = length(reflectivity);

%figure(1); clf;
subplot(1,2,1);
set(gca,'YScale','log','XScale','log');
hold on
for i = 1:numberOfContrasts   
   thisRef = reflectivity{i};
   thisData = shifted_data{i};
   if i == 1
       mult = 1;
   else
       mult = 2^(4*i);
   end
   errorbar(thisData(:,1),thisData(:,2)./mult,thisData(:,3)./mult,'.','MarkerSize',2.5);
   plot(thisRef(:,1),thisRef(:,2)./mult,'-','LineWidth',2);
end

subplot(1,2,2);
hold on

for i = 1:numberOfContrasts
    thisSLD = slds{i};
    plot(thisSLD(:,1),thisSLD(:,2),'-');
end


end