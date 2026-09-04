% Compile script for dynamic library wrapper mex function
clear wrapperMex;

args = {};
if isunix
    args = {'-ldl'};
end

flags = '';
if ismac && strcmp(computer('arch'), 'maca64')
    flags = 'LDFLAGS=$LDFLAGS -ld_classic';
end
includeDirs = getappdata(0,'includeDirs');
includes = strcat(repmat({'-I'}, 1,length(includeDirs)), includeDirs);
mex(includes{:}, flags,  "wrapperMex.cpp", args{:});
disp("wrapperMex compiled successfully");
