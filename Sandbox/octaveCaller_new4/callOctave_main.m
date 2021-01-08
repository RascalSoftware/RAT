function callOctave_main


if coder.target("MATLAB")
    disp('debug');
else
    path = '/home/arwel/Documents/RascalDev/RAT/Sandbox/octaveCaller_new4';
    
    sourceFile1 = 'callOctave.cpp';
    
    coder.updateBuildInfo('addSourcePaths',path);
    coder.updateBuildInfo('addSourceFiles',sourceFile1);
    coder.cinclude('callOctave.h');
    
    coder.ceval('callOctave');

end