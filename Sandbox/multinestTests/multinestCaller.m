function res = multinestCaller()


    path = '//home/arwel/Documents/RascalDev/RAT/Sandbox/multinestTests';
    
    coder.updateBuildInfo('addSourcePaths',path);    
    coder.cinclude('mainRoutine.c');
    coder.cinclude('LogLike.c');  
    coder.cinclude('dumper.c');  
    
    libPriority = '';
    libPreCompiled = true;
    libLinkOnly = true;
    
    linkPath1 = '/usr/local/lib/';
    linkPath2 = '/usr/local/MATLAB/R2016b/bin/glnxa64/';
    linkPath3 = '/home/arwel/Documents/RascalDev/RAT/Sandbox/multinestTests';
    pw = '/usr/lib64/';
    
    coder.updateBuildInfo('addIncludePaths',linkPath1);
    coder.updateBuildInfo('addIncludePaths',linkPath2);
    coder.updateBuildInfo('addLinkObjects','libmultinest.so.3.10',linkPath3,libPriority,libPreCompiled,libLinkOnly);
    

    coder.ceval('mainRoutine',0,[]);

    res = [];

end











%     %incPath2 = '/usr/include/openmpi';
%     linkPath1 = '/home/arwel/Documents/coding/multinestEdits/eggboxOnly/MultiNest_v3.10_eggboxOnly/multinest_eggboxOnly/lib';    
%     linkFile1 = 'libmultinest.so';
% 
%   
%     source1 = 'mainRoutine.h';
% %    source2 = 'multinest.h';
% %     source3 = 'dumper.h';
%    source4 = 'LogLike.h';    
%     source5 = 'mainRoutine.c';
%     source6 = 'multinest.c';
% %     source7 = 'dumper.c';
%    source8 = 'LogLike.c';
%     
%     
%     libPriority = '';
%     libPreCompiled = true;
%     libLinkOnly = true;

%     coder.updateBuildInfo('addIncludePaths',linkPath1);
%     coder.updateBuildInfo('addLinkObjects',linkFile1,linkPath1,libPriority,libPreCompiled,libLinkOnly);
