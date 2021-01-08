function octaveCaller()


% Runnink mkoctfile
%
%g++ -std=gnu++11 -I/usr/include/suitesparse -I/usr/include/octave-5.2.0/octave/.. -I/usr/include/octave-5.2.0/octave  -pthread -fopenmp -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fexceptions -fstack-protector-strong --param=ssp-buffer-size=4 -grecord-gcc-switches -m64 -mtune=generic -flto=auto -rdynamic  -fPIC -Wl,-z,relro   -o simpleOctave   -L/usr/lib64 -L/usr/lib64/octave/5.2.0 -loctinterp -loctave 









debug = 0;

if coder.target("MATLAB")
    disp('debug');
    
else
    path = '/home/arwel/Documents/RascalDev/RAT/Sandbox/octaveCaller_new2';

    includePath1 = '/usr/include/octave-5.2.0/octave';
    includePath2 = '/usr/share/octave/5.2.0/etc/tests';
    
    linkPath1 = '/usr/lib64/octave/5.2.0/octave/';
    linkPath2 = '/usr/lib64/';
    
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
    
    %coder.updateBuildInfo('addLinkObjects',linkFile1,linkPath1,libPriority,libPreCompiled,libLinkOnly);
    %coder.updateBuildInfo('addLinkObjects',linkFile2,linkPath1,libPriority,libPreCompiled,libLinkOnly);
    
    coder.updateBuildInfo('addSourceFiles',sourceFile1);
    %coder.updateBuildInfo('addSourceFiles',sourceFile2);
    
    coder.ceval('simpleOctave');
    
end
    
    
    
    
    
    