%% Convert r1 struct to projectClass.
% 
% The following example shows how to convert r1 structs into projectClass.

problem = r1ToProjectClass('DSPCBilayerStructInput.mat');


%% Convert projectClass to r1 struct.
% 
% The following example shows how to convert projectClass into r1 struct.

% First load the projectClass using the following syntax
pClass = load('DSPCBilayerProjectClass.mat').thisProjectClass;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Conversion Example 1
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

r1Struct = projectClassToR1(pClass, 'saveProject', false);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Conversion Example 2 (uncomment to run)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% r1Struct = projectClassToR1(pClass,...
%                             'fileName', 'r1Struct',...
%                             'dirName', 'results');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Conversion Example 3 (uncomment, fill and run)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% r1Struct = projectClassToR1({projectClass}, ...
%                             'dirName', {dirName},...
%                             'saveProject', {true or false}, ... 
%                             'dirPath', {path},...
%                             'r1Problem', {r1StructName},...
%                             'fileName', {fileName});

