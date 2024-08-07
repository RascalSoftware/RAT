function textProgressBar(curm, pct, varargin)
    %  Draws a progress bar in the console. The inputs are the message (char array) and 
    %  percentage progress expressed as a decimal (i.e., between 0 and 1).
    %  Optionally a boolean value can be provided to disable the progress
    %  bar.
    %
    %  textProgressBar("DREAM", 0.5, false)
    persistent lastNchar
    persistent display
    
    if ~isempty(varargin)
        display = varargin{1};
    elseif isempty(display)
        display = true;
    end
    
    if ~display
        return;
    end
    
    strDotsMax = 40;
    
    if pct == 0
        %fprintf('\n');
        lastNchar = 0;
        return;
    end
    
    if lastNchar==0 && pct>=1
        return 
    end
    
    if isempty(lastNchar)
        lastNchar = 0;
    end
    
    nDots = floor(pct * strDotsMax);
    progressmsg = ['[' repmat('*',1,nDots) repmat('.',1,strDotsMax-nDots) ']'];
    
    progressmsg=sprintf('\n%s %5.1f%% %s',curm,fix(pct*1000)/10,progressmsg);
    
    fprintf('%s%s',repmat(sprintf('\b'),1,lastNchar),progressmsg);
    drawnow
    lastNchar=length(progressmsg);
    
    if pct == 1
        fprintf('\n');
        lastNchar = 0;
        return;
    end
end
