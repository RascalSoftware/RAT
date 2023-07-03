% Compile script for eventManager dynamic library and mex function

clear eventManagerInterface;
args = {};
if ismac
%     mbuild eventManager.cpp CMDLINE150='' CMDLINE200='$LD $LDFLAGS $OBJS $LINKOPTIM $LINKEXPORT $CLIBS $LINKLIBS -o $EXE' LDEXT='.dylib' LDTYPE='-dynamiclib' LDFLAGS='-arch x86_64 -mmacosx-version-min=$SDKVER -Wl,-syslibroot,$ISYSROOT $LDTYPE $LINKEXPORT -framework CoreFoundation -install_name "@loader_path/$EXENAME$LDEXT"'
elseif isunix
    mbuild eventManager.cpp CXXFLAGS="-fPIC $CXXFLAGS" LDTYPE="-shared" LDEXT=".so";
    args = {'-ldl'};
elseif ispc
    mbuild eventManager.cpp LINKFLAGS="$LINKFLAGS /DLL" LDEXT=".dll" CMDLINE250="mt";
else
    error('Platform not supported');
end
disp("eventManager dynamic library built successfully" + newline);

includeDirs = getappdata(0,'includeDirs');
includes = strcat(repmat({'-I'}, 1,length(includeDirs)), includeDirs);
mex(includes{:}, "eventManagerInterface.cpp", args{:});
