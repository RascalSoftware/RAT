function t = detectFile(dirName)

period = 3; %seconds between directory checks
timeout = 500; %seconds before function termination
dirLength = length(dir(dirName));
t = timer('TimerFcn', {@timerCallback, dirName, dirLength}, 'Period', period,'TaskstoExecute', uint8(timeout/period), 'executionmode', 'fixedrate');
start(t)

end

function timerCallback(src, eventdata, dirName, dirLength)
persistent my_dirLength;
persistent my_beginFlag;

if isempty(my_beginFlag)
      my_dirLength = dirLength;
      my_beginFlag = 0;
end

if length(dir(dirName)) > my_dirLength
    disp('A new file is available')
    my_dirLength = length(dir(dirName));
    list = dir(dirName);
    names = {list.name};
    newFile = names(end);
    src.userData = newFile;
    processFile(newFile);
    disp(newFile);
else
    disp('No new files')
end

end



function processFile(filename)

b = fullfile('updateDir',filename);
fid = fopen(b{1});
a = cell(1,1);
a(1) = {fgetl(fid)};
disp(a(1));
fclose(fid);

end