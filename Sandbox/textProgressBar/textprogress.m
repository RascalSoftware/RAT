function textprogress(pct,curm,rejectpct)

persistent lastNchar lasttime starttime

if isempty(lastNchar)||pct==0
    lasttime=cputime-10;starttime=cputime;lastNchar=0;
    pct=1e-16;
end
if pct==1
    fprintf('%s',repmat(char(8),1,lastNchar));lastNchar=0;
    return
end
if (cputime-lasttime>0.1)

    ETA=datestr((cputime-starttime)*(1-pct)/(pct*60*60*24),13);
    progressmsg=[183-uint8((1:40)<=(pct*40)).*(183-'*') ''];
    %progressmsg=['-'-uint8((1:40)<=(pct*40)).*('-'-'') ''];
    %progressmsg=[uint8((1:40)<=(pct*40)).*'#' ''];
    curmtxt=sprintf('% 9.3g\n',curm(1:min(end,20),1));
    %curmtxt=mat2str(curm);
    progressmsg=sprintf('\nGWMCMC %5.1f%% [%s] %s\n%3.0f%% rejected\n%s\n',pct*100,progressmsg,ETA,rejectpct*100,curmtxt);

    fprintf('%s%s',repmat(char(8),1,lastNchar),progressmsg);
    drawnow;lasttime=cputime;
    lastNchar=length(progressmsg);
end