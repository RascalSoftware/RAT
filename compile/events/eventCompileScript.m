% Compile script for eventManager dynamic library and mex function

clear eventManagerInterface;
args = {};
if ismac
    % Need to check whether it's Apple or Intel Silicon....
    [~,result] = system('uname -v');
    is_m1_mac = any(strfind(result,'ARM64'));
    if is_m1_mac
        mbuild eventManager.cpp CMDLINE150='' CMDLINE200='$LD $LDFLAGS $OBJS $LINKOPTIM $LINKEXPORT $CLIBS $LINKLIBS -o $EXE' ...
            LDEXT='.dylib' LDTYPE='-dynamiclib' LDFLAGS='-lc++ -arch arm64 -mmacosx-version-min=$SDKVER -Wl,-syslibroot,$ISYSROOT $LDTYPE $LINKEXPORT -framework CoreFoundation -install_name "@loader_path/$EXENAME$LDEXT"'
    else
        mbuild eventManager.cpp CMDLINE150='' CMDLINE200='$LD $LDFLAGS $OBJS $LINKOPTIM $LINKEXPORT $CLIBS $LINKLIBS -o $EXE' ...
            LDEXT='.dylib' LDTYPE='-dynamiclib' LDFLAGS='-lc++ -arch x86_64 -mmacosx-version-min=$SDKVER -Wl,-syslibroot,$ISYSROOT $LDTYPE $LINKEXPORT -framework CoreFoundation -install_name "@loader_path/$EXENAME$LDEXT"'
    end
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
disp("eventManagerInterface compiled successfully" + newline);
