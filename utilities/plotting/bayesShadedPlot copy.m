function bayesShadedPlot(h,out,data,sf,bestFit)


figure(h); clf; hold on

nbatch = length(out.predlims);
hh = zeros(nbatch,1);

np = size(out.predlims{1}{1},1);
nn = (np+1)/2; % median
np = nn-1;

for i=1:nbatch
  plimi = out.predlims{i};
  ny = size(plimi,2);
  
  datai = data{i};
  time = datai(:,1); % time is the first columd of data

  for j=1:ny
    dimc = [0.9 0.9 0.9]; % dimmest (lightest) color
    %if ny>1;subplot(ny,1,j);end
    if ~isempty(out.obslims)
      fillyy(time,out.obslims{i}{j}(1,:)./sf(i),out.obslims{i}{j}(3,:)./sf(i),dimc);
      hold on
      dimc = [0.8,0.8,0.8];
    end
    fillyy(time,plimi{j}(1,:)./sf(i),plimi{j}(2*nn-1,:)./sf(i),dimc);
    hold on
    for k=2:(nn-1)
      fillyy(time,plimi{j}(k,:)./sf(i),plimi{j}(2*nn-k,:)./sf(i),dimc.*0.9.^(k-1));
    end
    plot(time,plimi{j}(nn,:)./sf(i),'-k');
    %if adddata
      errorbar(datai(:,1),datai(:,2),datai(:,3),'.');
    %end
    %hold off
%     if nbatch > 1
%       title(sprintf('Data set %d, y[%d]',i,j));
%     elseif ny > 1
%       title(sprintf('y[%d]',j));
%     end
  end
  
end

set(gca,'YScale','log','XScale','log');





















end