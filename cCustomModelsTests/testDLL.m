% This file is used to generate the mex function that deals with CPP custom layer functionality.


function [output,subRough] = testDLL(params,nba,nbs,numberOfContrasts,libraryName,functionName)


    coder.cinclude('<functional>');
    coder.cinclude('<string>');
    coder.cinclude('<iostream>');
    coder.cinclude('<map>');
    coder.cinclude('<vector>');
    coder.cinclude('libManager.h');
    coder.cinclude('<tuple>');
    coder.updateBuildInfo('addLinkFlags','-ldl');

    % Need to find a way to make this work with 100000,3
    output = 0.0; %zeros(1000,3);
    subRough = 0.0;
    coder.varsize('output',[1000 1],[1 0]);

    p = coder.opaque('Library','NULL','HeaderFile','libManager.h');
    % Make an instance 
    p = coder.ceval('Library');
    %coder.ceval('std::mem_fn(&Library::loadInfo)',p,[clibraryName,'0'],[cfunctionName,'0']);
    
    fprintf('Library Name from testDLL: %s \n',libraryName);

    % We need to add a null terminator to the library names in order for
    % them to match C/C++ format. See....
    % https://uk.mathworks.com/help/coder/ug/c-strings-for-null-terminated-matlab-strings.html
    libraryName = [libraryName,0];
    functionName = [functionName,0];

    % bulk in - 1xn
    % bulk out - 1xn
    % params - 1xn
    % call the class method in libManager.h
    coder.ceval('std::mem_fn(&Library::loadRunner)',p,coder.ref(params),coder.ref(nba),coder.ref(nbs)...
        ,numberOfContrasts,coder.wref(output),coder.wref(subRough),libraryName,functionName);

    fprintf('subRough in testDLL is %g \n', subRough);
    fprintf('output 1  is %g \n',output(1));    
end



% Disregard this ghost code
    %,functionName,libName,
    %coder.rowMajor; % matlab is col major so for right array sizes and to match with C we need to convert to rowMajor 
%     clibraryName = char(libraryName) ;
%     cfunctionName = char(functionName) ;
    


    % declare allLayerArr and allRoughArr using coder.varsize 
    % so that they can be used in the function
    % allLayesArr must be an array of variable size
    % allRoughsArr must be a double