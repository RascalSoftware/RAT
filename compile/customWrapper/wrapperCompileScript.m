% Compile script for dynamic library wrapper mex function
clear wrapperMex;

args = {};
if isunix
    args = {'-ldl'};
end
includeDirs = getappdata(0,'includeDirs');
includes = strcat(repmat({'-I'}, 1,length(includeDirs)), includeDirs);
mex(includes{:}, "wrapperMex.cpp", args{:});
disp("wrapperMex compiled successfully");
