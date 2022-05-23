% create a function that takes two .mat files,a name  and puts them into a struct called 'data' like this:

% load_data(file1,file2,name)
% data.(nameInputs).file1
% data.(nameOutputs).file2

function data = StructsINOUTS(file1,file2)
    
    data.file1 = load(file1);
    data.file2 = load(file2);

    
        
end 

% 
% function [data] = load_data(file1, file2)
%     
%     % load the data
%     data1 = load(file1);
%     data2 = load(file2);
%     
%     % create a struct called 'data'
%     data = struct;
%     
%     % add the data from the first file to the struct
%     data.data1 = data1;
%     
%     % add the data from the second file to the struct
%     data.data2 = data2;
%     
% end
% 
% function createStruct()
%     
%     % load the data
%  
% 
% 
% 
%     % create a struct containing 'backSortInputs.mat' as a struct 
%     % and 'backSortOutputs.mat' as a struct
%     backSortInputsStruct = ins.inputs;
%     backSortOutputsStruct = outs.outputs;
% 
%     % save the structs
%     save('backSortInputsStruct.mat', 'backSortInputsStruct');
%     save('backSortOutputsStruct.mat', 'backSortOutputsStruct');
% 
% end