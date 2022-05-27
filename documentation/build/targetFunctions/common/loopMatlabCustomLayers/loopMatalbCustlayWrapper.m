function [allLayers, allRoughs] = loopMatalbCustlayWrapper(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
     shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params)
 
 %#codegen
 
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
 % paralell computing toolbox)
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
 