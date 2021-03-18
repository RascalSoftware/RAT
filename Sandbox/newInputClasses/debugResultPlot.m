
shifted_data = result.shifted_data;
reflect = result.reflectivity;
sldProfiles = result.sldProfiles;

nContrasts = length(shifted_data);

figure(1);clf; hold on


for i = 1:nContrasts
    
    thisData = shifted_data{i};
    thisSLD = sldProfiles{i};
    thisReflect = reflect{i};
    
    subplot(1,2,1); hold on
    errorbar(thisData(:,1),thisData(:,2),thisData(:,3),'.')
    hold on
    plot(thisReflect(:,1),thisReflect(:,2))
    set(gca,'YScale','log','XScale','log');
    
    subplot(1,2,2); hold on
    plot(thisSLD(:,1),thisSLD(:,2))
    
    
end

disp('debug');