function [allLayers,allRoughs] =  loopCppWrapperCustomXYSingle(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params)


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
            output = zeros(8,2);
            sRough = 0.0;
            [output,sRough] = testDLL_mex(params,nba,nbs,i,cLibName,cfunctionName);
            
            output = reshape(output,2,8)'; % convert to 3 x from top down and transpose 
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
           
            %coder.extrinsic('testDLL_mex');
            % call mex function % params,nba,nbs,numberOfContrasts,output,subrough,libName,functionName);
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
 

% % if customFiles has multiple elements, then do this
%     % TALK WITH MARTYN ABOUT THIS
% % if length(customFiles) > 1
% %     % create a cell array of same size as customFiles
% %     customModels = cell(1,length(customFiles));
% %     for i=1:length(customModels)
% %         customModels(i) = customFiles{i}{2}; % load the custom function names into it
% %     end
% 
% %     % load all the functions from DLL based on the customModels
% 
% 
% 
% 
% % elsefunction [allLayers,allRoughs] =  loopCppWrapperCustomXYPoints(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
% shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params)
% 
% 
%     coder.extrinsic('testDLL_mex');
%     allLayers = cell(numberOfContrasts,1);
%     for i = 1:numberOfContrasts
%         allLayers{i} = [1 ; 1];
%     end
%     coder.varsize('allLayers{:}',[1000,5],[1,1]);
%     
%         
%     allRoughs = zeros(numberOfContrasts,1);
%     cfunctionName =[customFiles{1}{1},0]; %; % dll name must be same as function name
%     cLibName = [customFiles{1}{3},0]; %customFiles{1}{3};
%  
%     numberOfContrasts = int32(numberOfContrasts);
% %     strLibName = string(LibName);
% %     strfunctionName = string(functionName);
%     if coder.target('MEX')
%         
%         for i = 1:numberOfContrasts
%             % call mex function % params,nba,nbs,numberOfContrasts,output,subrough,libName,functionName);
%             %coder.extrinsic('testDLL_mex');
%             output = zeros(8,2);
%             sRough = 0.0;
%             [output,sRough] = testDLL_mex(params,nba,nbs,i,cLibName,cfunctionName);
%             
%             output = reshape(output,3,8)'; % convert to 3 x from top down and transpose 
%             mask = (output >= 0) & (output <= 2.6e-100); % mask the zeros/extremely small positive useless nums or use ...
%             %mask = (abs(output) <= 2.6e-100);
%             output(mask) = NaN;
%             output = rmmissing(output);
% 
%             allLayers{i} = output;
%             allRoughs(i) = sRough;
% 
%         end
%         
%     end
%     
% 
% 
%     
%     
%    if coder.target('MATLAB')
%         
%         for i = 1:numberOfContrasts
%             % call mex function % params,nba,nbs,numberOfContrasts,output,subrough,libName,functionName);
%             %coder.extrinsic('testDLL_mex');
%             [output,sRough] = testDLL_mex(params,nba,nbs,i,cLibName,cfunctionName);
% 
%             output = reshape(output,3,8)'; % convert to 3 x from top down and transpose 
%             mask = (output >= 0) & (output <= 2.6e-100); % mask the zeros/extremely small positive useless nums or use ...
%             %mask = (abs(output) <= 2.6e-100);
%             output(mask) = NaN;
%             output = rmmissing(output);
% 
%             allLayers{i} = output;
%             allRoughs(i) = sRough;
% 
%         end
%    end
% 
% 
% % 
% %     
% end 
%  

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
%     % if there is only 1 function 
    
% end

% assumin only one custom function