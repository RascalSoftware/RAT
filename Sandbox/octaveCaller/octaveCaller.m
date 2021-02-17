function octaveCaller()


if coder.target('MATLAB')
    disp('no matlab version');
    return
else
    
    path = '/home/arwel/Documents/RascalDev/RAT/Sandbox/octaveCaller';
    
    incPath1 = '/usr/include/octave-5.2.0/octave';
    incPath2 = '/usr/share/octave/5.2.0/etc/tests';
    
    linkPath1 = '/usr/lib64/octave/5.2.0/';
    linkFile1 = 'liboctave.so';
    linkFile2 = 'liboctinterp.so';
    
    source1 = '/home/arwel/Documents/RascalDev/RAT/Sandbox/octaveCaller/functionOctave_new.cpp';

    libPriority = '';
    libPreCompiled = true;
    libLinkOnly = true;

    coder.updateBuildInfo('addSourceFiles',source1);
    coder.updateBuildInfo('addSourcePaths',path);
    coder.updateBuildInfo('addIncludePaths',incPath1);
    coder.updateBuildInfo('addIncludePaths',incPath2);
    coder.updateBuildInfo('addLinkObjects',linkFile1,linkPath1,libPriority,libPreCompiled,libLinkOnly);
    coder.updateBuildInfo('addLinkObjects',linkFile2,linkPath1,libPriority,libPreCompiled,libLinkOnly);
    
    
    coder.ceval('octaveCallerFunction');%, params, paramsLen, funName, pathCall, bulkIn, bulkOut, contrast, coder.wref(outp), coder.wref(nLayers));
end

end