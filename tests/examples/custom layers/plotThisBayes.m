
%results = result;
sf = results.contrastParams.scalefactors;

figure(30); clf; subplot(1,2,1); box on
bayesShadedPlot_dev(problem,result,sf,'q4',false,'fit','mean','KeepAxes',true);%,'range',0.95);

subplot(1,2,2);
bayesSLDShadedPlot(problem,results,'fit','mean','KeepAxes',true)