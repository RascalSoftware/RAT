function octaveCaller()

debug = 0;

if coder.target("MATLAB")
    disp('debug');
    
else
    path = '/home/arwel/Documents/RascalDev/RAT/Sandbox/octaveCaller_new2';

    includePath1 = '/usr/include/octave-5.2.0/octave';
    includePath2 = '/usr/share/octave/5.2.0/etc/tests';
    
    linkPath1 = '/usr/lib64/octave/5.2.0/octave/';
    linkFile1 = 'liboctave.so';
    linkFile2 = 'liboctinterp.so';
    
    sourceFile1 = 'simpleOctave.cpp';
    %sourceFile2 = 'mexCallOctave.cpp';
   
    libPriority = '';
    libPreCompiled = true;
    libLinkOnly = true;
    
    coder.updateBuildInfo('addSourcePaths',path);
   
    coder.updateBuildInfo('addIncludePaths',includePath1);
    coder.updateBuildInfo('addIncludePaths',includePath2);
    
    coder.updateBuildInfo('addLinkObjects',linkFile1,linkPath1,libPriority,libPreCompiled,libLinkOnly);
    coder.updateBuildInfo('addLinkObjects',linkFile2,linkPath1,libPriority,libPreCompiled,libLinkOnly);
    
    coder.updateBuildInfo('addSourceFiles',sourceFile1);
    %coder.updateBuildInfo('addSourceFiles',sourceFile2);
    
    coder.ceval('simpleOctave');
    
end
    
    
    
    
    
    