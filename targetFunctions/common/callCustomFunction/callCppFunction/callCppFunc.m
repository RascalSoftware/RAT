
function [output,subRough] = callCppFunc(params,nba,nbs,numberOfContrasts,libraryName,functionName)

    % Use 3rd party 'dylib.hpp' to implement a cross-platform Cpp runtime
    % class loader.... https://github.com/martin-olivier/dylib

    coder.cinclude('<functional>');
    coder.cinclude('<string>');
    coder.cinclude('<iostream>');
    coder.cinclude('<map>');
    coder.cinclude('<vector>');
    coder.cinclude('libManager.h');
    coder.cinclude('<tuple>');
    coder.updateBuildInfo('addLinkFlags','-ldl');

    tempOutput = zeros(3,1000);
    subRough = 0.0;
    nLayers = 0;
    % coder.varsize('output',[1000 1],[1 0]);

    p = coder.opaque('Library','NULL','HeaderFile','libManager.h');
    % Make an instance 
    p = coder.ceval('Library');

    % We need to add a null terminator to the library names in order for
    % them to match C/C++ format. See....
    % https://uk.mathworks.com/help/coder/ug/c-strings-for-null-terminated-matlab-strings.html
    libraryName = [libraryName,0];
    functionName = [functionName,0];

    % call the class method in libManager.h
    coder.ceval('std::mem_fn(&Library::loadRunner)',p,coder.ref(params),coder.ref(nba),coder.ref(nbs)...
        ,numberOfContrasts,coder.wref(tempOutput),coder.wref(subRough),coder.wref(nLayers),libraryName,functionName);

    output = tempOutput(:,1:nLayers)';
end




