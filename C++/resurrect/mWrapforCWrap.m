% This file is used to test cWrapper.cpp 
function mWrapforCWrap

    % PATHS NEEDED
    incPath1= 'C:/Program Files/MATLAB/R2021a/extern/include'

    linkPath1 = 'C:/Program Files/MATLAB/R2021a/bin/win64';
    %linkPath1 = fullfile(matlabroot,'extern','include','lib',arch,'mingw64');
    linkFile1 = 'libeng.dll';
    linkFile2 = 'libmx.dll';
    y = 0;


    % initialize the cWrapper
    %coder.updateBuildInfo('addSourceFiles','matlabCallFun.c');
    libPriority = '';
    libPreCompiled = true;
    libLinkOnly = true;





    coder.updateBuildInfo('addSourcePaths','C:\Users\oba7931403\Documents\GitHub\RAT');
    %coder.updateBuildInfo('addSourcePaths','$(START_DIR)\C');
    coder.updateBuildInfo('addIncludePaths',incPath1);
    %coder.updateBuildInfo('addIncludePaths',incPath2);
    coder.updateBuildInfo('addLinkObjects',linkFile1,linkPath1,libPriority,libPreCompiled,libLinkOnly);
    coder.updateBuildInfo('addLinkObjects',linkFile2,linkPath1,libPriority,libPreCompiled,libLinkOnly);
    
    % INCLUDE THE C FILE
    coder.updateBuildInfo('addSourceFiles','matlabCallFun.c');
    coder.updateBuildInfo('addSourceFiles','cWrapper.cpp');
    


    coder.ceval('cCaller.startEngine');

    % ENGINES REQUIREMENT

    % check how many contrasts we got 
    % check how maany computational threads we got
    numberOfEnginesRequired = 3 ; %problemDef.numberOfContrasts;
    numberOfEnginesSupported = 0;
    numberOfEnginesSupported = coder.ceval('maxNumCompThreads');

    % MATLAB ENGINE STUFF

    % open the engines in a loop with unique names to each 

    % we open engines based on our req by comparing with no of open currently

    % if there are not enough engines open, open them up but if there are more than required, close them

    % engine.startEngine(); here aling with logic
    % set up the engine pointers based on number of engines 


    persistent noOfOpenEngines;


    if isempty(noOfOpenEngines)
        noOfOpenEngines = 0;
    end


    % if numberOfEnginesRequired > numberOfEnginesSupported we cant open all of them at once 

    if numberOfEnginesRequired > numberOfEnginesSupported
        numberOfEnginesRequired = numberOfEnginesSupported;
    end



    if noOfOpenEngines < numberOfEnginesRequired
        newEnginesRequired = numberOfEnginesRequired - noOfOpenEngines;
        for i = 1:newEnginesRequired
            coder.ceval('cCaller.startEngine');
            noOfOpenEngines = noOfOpenEngines + 1;


        end
        
        

    elseif noOfOpenEngines > numberOfEnginesRequired
        EnginesToDestroy = noOfOpenEngines - numberOfEnginesRequired;
        for i = 1:EnginesToDestroy
            coder.ceval('cCaller.stopEngine');
            noOfOpenEngines = noOfOpenEngines - 1;
        end
    
    end





end