classdef customModelClass < handle

    % A general class containing methods for running user defined custom
    % models. This version contains direct calls to the base Matlab

    properties

    end

    methods (Static)

        function [allLayers,allRoughs] = processCustomLayers(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params,useImaginary)

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
            coder.varsize('tempAllLayers{:}',[10000 6],[1 1]);


            for i = 1:numberOfContrasts     % TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..

                % Choose which custom file is associated with this contrast
                functionHandle = customFiles{cCustFiles(i)};

                % Find values of 'bulkIn' and 'bulkOut' for this
                % contrast...
                [~,~,~,bulkIn,bulkOut,~] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);

                thisContrastLayers = [1 1 1]; % typeDef
                coder.varsize('thisContrastLayers',[10000, 6],[1 1]);

                if isnan(str2double(functionHandle))
                    [thisContrastLayers,allRoughs(i)] = callMatlabFunction(params,i,functionHandle,bulkIn,bulkOut,numberOfContrasts,0);
                else
                    [thisContrastLayers, allRoughs(i)] = callCppFunction(params, bulkIn, bulkOut, i, -1, functionHandle);
                end

                % If the output layers has 5 columns, then we need to do
                % the hydration correction (the user has not done it in the
                % custom function). Do that here....
                if ~useImaginary
                   thisContrastLayers = applyHydrationReal(thisContrastLayers,bulkIn,bulkOut);
                else
                   thisContrastLayers = applyHydrationImag(thisContrastLayers,bulkIn,bulkOut);
                end

                tempAllLayers{i} = thisContrastLayers;
            end

            allLayers = tempAllLayers;

        end

        function [allSLDs,allRoughs] = processCustomXY(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params)

            % Top-level function for processing custom XY profiles for all the
            % contrasts.

            % Do some pre-definitions to keep the compiler happy...
            tempAllSLDs = cell(numberOfContrasts,1);
            allSLDs = cell(numberOfContrasts,1);
            allRoughs = zeros(numberOfContrasts,1);

            for i = 1:numberOfContrasts
                allSLDs{i} = [1,1];    % Type def as double (size not important)
                tempAllSLDs{i} = [0 0];
            end
            coder.varsize('tempAllSLDs{:}',[10000 3],[1 1]);    % 3 columns to allow for potential imaginary curve

            for i = 1:numberOfContrasts     % TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..

                % Choose which custom file is associated with this contrast
                functionHandle = customFiles{cCustFiles(i)};

                % Find values of 'bulkIn' and 'bulkOut' for this
                % contrast...
                [~,~,~,bulkIn,bulkOut,~] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);

                if isnan(str2double(functionHandle))
                    [tempAllSLDs{i}, allRoughs(i)] = callMatlabFunction(params,i,functionHandle,bulkIn,bulkOut,numberOfContrasts,0);
                else
                    [tempAllSLDs{i}, allRoughs(i)] = callCppFunction(params, bulkIn, bulkOut, i, -1, functionHandle);
                end
            end

            allSLDs = tempAllSLDs;
        end

        function [allLayers,allRoughs] = processCustomLayersDomains(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params,useImaginary)

            % Top-level function for processing custom layers for all the
            % contrasts.

            % Do some pre-definitions to keep the compiler happy...
            %totNumCalcs = numberOfContrasts * 2;
            tempAllLayers = cell(numberOfContrasts,2);
            allLayers = cell(numberOfContrasts,2);
            allRoughs = zeros(numberOfContrasts,1);

            for i = 1:numberOfContrasts
                allLayers{i,1} = [1 , 1];    % Type def as double (size not important)
                allLayers{i,2} = [1 , 1];
                tempAllLayers{i,1} = [0 0 0 0 0];
                tempAllLayers{i,2} = [0 0 0 0 0];
            end
            coder.varsize('tempAllLayers{:}',[10000 6],[1 1]);
            coder.varsize('allLayers{:}',[10000 6],[1 1]);

            for i = 1:numberOfContrasts

                % Choose which custom file is associated with this contrast
                functionHandle = customFiles{cCustFiles(i)};

                % Find values of 'bulkIn' and 'bulkOut' for this
                % contrast...
                [~,~,~,bulkIn,bulkOut,~] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),...
                    cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);

                thisContrastLayers1 = [1 1 1]; % typeDef
                coder.varsize('thisContrastLayers1',[10000, 6],[1 1]);

                thisContrastLayers2 = [1 1 1]; % typeDef
                coder.varsize('thisContrastLayers2',[10000, 6],[1 1]);

                if isnan(str2double(functionHandle))
                    [thisContrastLayers1, allRoughs(i)] = callMatlabFunction(params,i,functionHandle,bulkIn,bulkOut,numberOfContrasts,1);
                    [thisContrastLayers2, ~] = callMatlabFunction(params,i,functionHandle,bulkIn,bulkOut,numberOfContrasts,2);
                else
                    [thisContrastLayers1, allRoughs(i)] = callCppFunction(params, bulkIn, bulkOut, i, 0, functionHandle);
                    [thisContrastLayers2, ~] = callCppFunction(params, bulkIn, bulkOut, i, 1, functionHandle);
                end

                % If the output layers has 5 columns, then we need to do
                % the hydration correction (the user has not done it in the
                % custom function). Do that here....
                if ~useImaginary
                   thisContrastLayers1 = applyHydrationReal(thisContrastLayers1,bulkIn,bulkOut);
                   thisContrastLayers2 = applyHydrationReal(thisContrastLayers2,bulkIn,bulkOut);
                else
                   thisContrastLayers1 = applyHydrationImag(thisContrastLayers1,bulkIn,bulkOut);
                   thisContrastLayers2 = applyHydrationImag(thisContrastLayers2,bulkIn,bulkOut);
                end

                tempAllLayers{i,1} = thisContrastLayers1;
                tempAllLayers{i,2} = thisContrastLayers2;
            end
        
            allLayers = tempAllLayers;

        end

        function [allSLDs,allRoughs] = processCustomXYDomains(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params)

            % Top-level function for processing custom XY profiles for all the
            % contrasts.

            % Do some pre-definitions to keep the compiler happy...
            tempAllSLDs = cell(numberOfContrasts,2);
            allSLDs = cell(numberOfContrasts,2);
            allRoughs = zeros(numberOfContrasts,1);

            for i = 1:numberOfContrasts
                allSLDs{i,1} = [1,1];    % Type def as double (size not important)
                allSLDs{i,2} = [1,1];
                tempAllSLDs{i,1} = [0 0];
                tempAllSLDs{i,2} = [0 0];
            end
            coder.varsize('tempAllSLDs{:}',[10000 3],[1 1]);    % 3 columns to allow for potential imaginary curve

            for i = 1:numberOfContrasts     % TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..

                % Choose which custom file is associated with this contrast
                functionHandle = customFiles{cCustFiles(i)};

                % Find values of 'bulkIn' and 'bulkOut' for this contrast...
                [~,~,~,bulkIn,bulkOut,~] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);

                if isnan(str2double(functionHandle))
                    [tempAllSLDs{i, 1}, allRoughs(i)] = callMatlabFunction(params,i,functionHandle,bulkIn,bulkOut,numberOfContrasts,1);
                    [tempAllSLDs{i, 2}, ~] = callMatlabFunction(params,i,functionHandle,bulkIn,bulkOut,numberOfContrasts,2);
                else
                    [tempAllSLDs{i, 1}, allRoughs(i)] = callCppFunction(params, bulkIn, bulkOut, i, 0, functionHandle);
                    [tempAllSLDs{i, 2}, ~] = callCppFunction(params, bulkIn, bulkOut, i, 1, functionHandle);
                end
            end

            allSLDs = tempAllSLDs;
        end
        
    end
end
