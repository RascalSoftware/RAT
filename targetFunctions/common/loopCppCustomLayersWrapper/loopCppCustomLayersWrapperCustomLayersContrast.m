function [allLayers,allRoughs] =  loopCppCustomLayersWrapperCustomLayersContrast (cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params)
% This is the function that deals with the *C++ Custom User Scripts*.
% This calls a mex called **testDLL_mex** which is a wrapper for the C++ class Library in **libManager.h**.
% Library Class uses **dylib.hpp** to load the dynamic library at runtime. The dynamic library would be the 
% user's custom c++ script compiled into a **DLL/dylib/.so** file.
%
%     INPUTS:
%
%        * cBacks  :         Which background value is associated with each contrast
%        * cShifts  :        Which qz_shift value is associated with each contrast
%        * cScales  :        Which scalefactor value is associated with each contrast
%        * cNbas  :          Which NBa value is associated with each contrast
%        * cNbss  :          Which Nbs value is associated with each contrast
%        * cRes  :           Which resolution value is associated with each contrast
%        * backs  :          List of all background values.
%        * shifts  :         List of all qz-shift values
%        * sf :              List of all scalefactor values
%        * nba :             List of all nba values
%        * nbs :             List of all nbs values
%        * res :             List of all resolution values
%        * cCustFiles :      
%        * numberOfContrasts : Number of contrasts
%        * customFiles :      Cell of all custom user script files
%        * params :           Structure of all parameters
%
%
%     OUTPUTS:
%
%        * allLayers :        Cell of all layers
%        * allRoughs :        Cell of all roughnesses
%



    coder.extrinsic('testDLL_mex');
    allLayers = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        allLayers{i} = [1 ; 1];
    end
    coder.varsize('allLayers{:}',[1000,5],[1,1]);
    
        
    allRoughs = zeros(numberOfContrasts,1);
    cfunctionName =[customFiles{1}{1},0]; %; % dll name must be same as function name
    cLibName = [customFiles{1}{3},0]; %customFiles{1}{3};
 
    numberOfContrasts = int32(numberOfContrasts);
%     strLibName = string(LibName);
%     strfunctionName = string(functionName);
    if coder.target('MEX')
        
        for i = 1:numberOfContrasts
            % call mex function % params,nba,nbs,numberOfContrasts,output,subrough,libName,functionName);
            %coder.extrinsic('testDLL_mex');
            output = zeros(8,3);
            sRough = 0.0;
            [output,sRough] = testDLL_mex(params,nba,nbs,i,cLibName,cfunctionName);
            
            output = reshape(output,3,8)'; % convert to 3 x from top down and transpose 
            mask = (output >= 0) & (output <= 2.6e-100); % mask the zeros/extremely small positive useless nums or use ...
            %mask = (abs(output) <= 2.6e-100);
            output(mask) = NaN;
            output = rmmissing(output);

            allLayers{i} = output;
            allRoughs(i) = sRough;

        end
        
    end
    


    
    
   if coder.target('MATLAB')
        
        for i = 1:numberOfContrasts
            % call mex function % params,nba,nbs,numberOfContrasts,output,subrough,libName,functionName);
            %coder.extrinsic('testDLL_mex');
            [output,sRough] = testDLL_mex(params,nba,nbs,i,cLibName,cfunctionName);

            output = reshape(output,3,8)'; % convert to 3 x from top down and transpose 
            mask = (output >= 0) & (output <= 2.6e-100); % mask the zeros/extremely small positive useless nums or use ...
            %mask = (abs(output) <= 2.6e-100);
            output(mask) = NaN;
            output = rmmissing(output);

            allLayers{i} = output;
            allRoughs(i) = sRough;

        end
   end



    
end 
 

% if customFiles has multiple elements, then do this
    % TALK WITH MARTYN ABOUT THIS
% if length(customFiles) > 1
%     % create a cell array of same size as customFiles
%     customModels = cell(1,length(customFiles));
%     for i=1:length(customModels)
%         customModels(i) = customFiles{i}{2}; % load the custom function names into it
%     end

%     % load all the functions from DLL based on the customModels




% else
%     % if there is only 1 function 
    
% end

% assumin only one custom function