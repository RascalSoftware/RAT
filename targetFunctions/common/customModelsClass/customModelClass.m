classdef customModelClass < handle

    % A general class containing methods for running user defined custom
    % models. This version contains direct calls to the base Matlab

    properties

    end

    methods (Static)

        function [allLayers,allRoughs] = processCustomLayers(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                                    shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params)

        % Top-level function for processing custom layers for all the
        % contrasts. 

        % Do some pre-definitions to keep the compiler happy...
        tempAllLayers = cell(numberOfContrasts,1);
        allLayers = cell(numberOfContrasts,1);
        allRoughs = zeros(numberOfContrasts,1);

        for i = 1:numberOfContrasts
            allLayers{i} = [1 , 1];    % Type def as double (size not important)
            tempAllLayers{i} = [0 0 0 0 0];
        end
        coder.varsize('tempAllLayers{:}',[10000 5],[1 1]);


        for i = 1:numberOfContrasts     % TODO - will be 'parfor' subject to further upstream checks..

                % Choose which custom file is associated with this contrast
                thisCustomModel = customFiles{cCustFiles(i)};

                % Check what language it is....
                thisLanguage = thisCustomModel{2};

                % ... and path
                thisPath = thisCustomModel{3};

                % ....also file.
                thisFile = thisCustomModel{1};

                % Find values of 'bulkIn' and 'bulkOut' for thid
                % contrast...
                [~,~,~,bulkIn,bulkOut,~] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);

                switch thisLanguage
                    case 'matlab'
                       [tempAllLayers{i},allRoughs(i)] = callMatlabCustomFunction(params,i,thisFile,thisPath,bulkIn,bulkOut,numberOfContrasts);
                    case 'cpp'   
                       [tempAllLayers{i},allRoughs(i)] = callCppFunc(params,bulkIn,bulkOut,i,thisFile,thisFile);
                    case 'python'
                       [tempAllLayers(i),allRoughs(i)] = pythonCustomFunctionWrapper(thisFile,params,bulkIn,bulkOut,i);
                end
        end

        allLayers = tempAllLayers;

        end


        function [allSLDs,allRoughs] = processCustomXY(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                                    shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params,parallelFlag)

        % Top-level function for processing custom XY profiles for all the
        % contrasts. 

        % Do some pre-definitions to keep the compiler happy...
        tempAllSLDs = cell(numberOfContrasts,1);
        allSLDs = cell(numberOfContrasts,1);
        allRoughs = zeros(numberOfContrasts,1);

        for i = 1:numberOfContrasts
            allSLDs{i} = [1 , 1];    % Type def as double (size not important)
            tempAllSLDs{i} = [0 0];
        end
        coder.varsize('tempAllSLDs{:}',[10000 2],[1 0]);

            for i = 1:numberOfContrasts     % TODO - will be 'parfor' subject to further upstream checks..

                % Choose which custom file is associated with this contrast
                thisCustomModel = customFiles{cCustFiles(i)};

                % Check what language it is....
                thisLanguage = thisCustomModel{2};

                % ... and path
                thisPath = thisCustomModel{3};

                % ....also file.
                thisFile = thisCustomModel{1};

                % Find values of 'bulkIn' and 'bulkOut' for thid
                % contrast...
                [~,~,~,bulkIn,bulkOut,~] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);

                switch thisLanguage
                    case 'matlab'
                       [tempAllSLDs{i},allRoughs(i)] = callMatlabCustomFunction(params,i,thisFile,thisPath,bulkIn,bulkOut,numberOfContrasts);
                        % case 'cpp'
                        %     [tempAllLayers(i),allRoughs(i)] = obj.cppCustomLayers(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                        %        shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params,para,i,numberOfContrasts);
                        % case 'python'
                        %      [tempAllLayers(i),allRoughs(i)] = obj.pythonCustomLayers(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                        %            shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params,para,i,numberOfContrasts);
                end
            end
       
        allSLDs = tempAllSLDs;
        end
     end
end
