function setbuildargs(buildInfo)

% Add the lib folder....
includePath = getappdata(0,'includeDir');
buildInfo.addIncludePaths(includePath);