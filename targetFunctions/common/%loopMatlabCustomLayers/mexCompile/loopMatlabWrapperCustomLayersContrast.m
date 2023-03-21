function [allLayers, allRoughs] = loopMatlabWrapperCustomLayersContrast(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
     shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params)
% This function takes care of MATLAB Custom Layers from the User.
% This function in essence calls an feval to compute matlab function.
%
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
% .. warning:: MEX version of relfectivity calulation uses a Matlab runtime to make feval work but if you compile to C++ source code, Coder won't compile as there is no
%              MATLAB runtime. This is a known issue. Hence, MATLAB Engine class that can open a MATLAB session externally is recommended and this is yet to done.
% 
% .. warning:: **BUG**: The function name must be fixed from loopMatalb to loopMatlab but it works as it now.
 
 % Wrapper function for calling 'loopMatlabCustomLayers'. This wrapper is
 % necessary to deal with typedef problems for the coder if feval is used
 % directly from the main function
 tempAllLayers = cell(numberOfContrasts,1);
 allLayers = cell(numberOfContrasts,1);
 allRoughs = zeros(numberOfContrasts,1);
 
 for i = 1:numberOfContrasts
     allLayers{i} = [1 , 1];    % Type def as double (size not important)
     tempAllLayers{i} = [0 0 0 0 0];
 end
 coder.varsize('tempAllLayers{:}',[10000 5],[1 1]);
 
 % Call the Matlab parallel loop for the custom models.....
 % We do this using feval, which automatically makes this function call
 % only extrinsic... the loop is then handled in the matlab file (using 
 % parallel computing toolbox)
 [tempAllLayers, tempAllRoughs] = feval('loopMatlabCustomLayers',cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
     shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params);
 
 % All the following is intended to be casting from mxArray's to doubles.
 % I'm not sure if all of this is necessary, but it compiles...
 for i = 1:numberOfContrasts
     tempOut = tempAllLayers{i};
     n = [0 0];
     n = size(tempOut);
     newOut = zeros(n);
     newOut = tempOut;
     allLayers{i} = newOut;
 end
 
 %allLayers = tempAllLayers;
 allRoughs = tempAllRoughs;
 
end
 