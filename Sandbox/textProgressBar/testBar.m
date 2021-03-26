
clc
lastNchar = 0;

for i = 0:0.01:1
    pct = i;
    curm = 'progress';
    progressmsg=[183-uint8((1:40)<=(pct*40)).*(183-'*') ''];
    curmtxt=sprintf('% 9.3g\n',curm(1:min(end,20),1));
    progressmsg=sprintf('\n %s %5.1f%% [%s]',curm,(pct*100),progressmsg);
    fprintf('%s%s',repmat(char(8),1,lastNchar),progressmsg);
    drawnow;lasttime=cputime;
    lastNchar=length(progressmsg);
end
    
