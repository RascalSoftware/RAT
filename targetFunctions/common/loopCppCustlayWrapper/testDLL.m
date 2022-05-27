function [allLayersArr,allRoughsArr] = testDLL(params,nba,nbs,numberOfContrasts,libraryName,functionName)


    coder.cinclude('<functional>');
    coder.cinclude('<string>');
    coder.cinclude('<iostream>');
    coder.cinclude('<map>');
    coder.cinclude('<vector>');
    coder.cinclude('libManager.h');
    coder.cinclude('<tuple>');
    coder.updateBuildInfo('addLinkFlags','-ldl');

    %,functionName,libName,
    %coder.rowMajor; % matlab is col major so for right array sizes and to match with C we need to convert to rowMajor 
%     clibraryName = char(libraryName) ;
%     cfunctionName = char(functionName) ;
    


    % declare allLayerArr and allRoughArr using coder.varsize 
    % so that they can be used in the function
    % allLayesArr must be an array of variable size
    % allRoughsArr must be a double
    output = zeros(8,3);
     %coder.varsize('allLayersArr',[1 8]);
    subRough =0.0;
    
    %cfunctionName(isstrprop(cfunctionName,'digit')) = [];
    p = coder.opaque('Library','NULL','HeaderFile','libManager.h');
    p = coder.ceval('Library');
    %coder.ceval('std::mem_fn(&Library::loadInfo)',p,[clibraryName,'0'],[cfunctionName,'0']);
    
    
    % bulk in - 1xn
    % bulk out - 1xn
    % params - 1xn

    coder.ceval('std::mem_fn(&Library::loadRunner)',p,coder.ref(params),coder.ref(nba),coder.ref(nbs)...
    ,numberOfContrasts,coder.wref(output),coder.wref(subRough),libraryName,functionName);
    
    allLayersArr = output;
    allRoughsArr = subRough;
    



end