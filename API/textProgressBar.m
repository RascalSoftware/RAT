function textProgressBar(curm,pct)

persistent lastNchar

strDotsMax = 40;

if strcmpi(curm,'init')
    %fprintf('\n');
    lastNchar = 0;
    return;
end

if strcmpi(curm,'end')
    fprintf('\n');
    return;
end

if isempty(lastNchar)
    lastNchar = 0;
end

%curm = 'progress';

nDots = floor(pct * strDotsMax);
progressmsg = ['[' repmat('*',1,nDots) repmat('.',1,strDotsMax-nDots) ']'];

% progressmsg=[183-uint16((1:40)<=(pct*40)).*(183-'*') ''];
% %curmtxt=sprintf('% 9.3g\n',curm(1:min(end,20),1));
progressmsg=sprintf('\n %s %5.1f%% %s',curm,(pct*100),progressmsg);

fprintf('%s%s',repmat(sprintf('\b'),1,lastNchar),progressmsg);
drawnow
lastNchar=length(progressmsg);

end

%     c = 50;
%     strDotsMax = 20;
%     nDots = floor(c/*strDotsMax);
%     dotOut = ['[' repmat('*',1,nDots) repmat('.',1,strDotsMax-nDots) ']']