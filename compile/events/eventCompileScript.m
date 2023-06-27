% Compile script for eventManager dynamic library and mex function

clear mex;
if ismac
%     mbuild EventManager.cpp CMDLINE150='' CMDLINE200='$LD $LDFLAGS $OBJS $LINKOPTIM $LINKEXPORT $CLIBS $LINKLIBS -o $EXE' LDEXT='.dylib' LDTYPE='-dynamiclib' LDFLAGS='-arch x86_64 -mmacosx-version-min=$SDKVER -Wl,-syslibroot,$ISYSROOT $LDTYPE $LINKEXPORT -framework CoreFoundation -install_name "@loader_path/$EXENAME$LDEXT"'
elseif isunix
    mbuild EventManager.cpp CFLAGS="-fPIC $CFLAGS" LDTYPE="-shared" LDEXT=".so"
elseif ispc
    mbuild EventManager.cpp LINKFLAGS="$LINKFLAGS /DLL" LDEXT=".dll" CMDLINE250="mt"
else
    error('Platform not supported')
end
disp('EventManager dynamic library built successfully')

mex eventManagerInterface.cpp -L. -lEventManager
