classdef customModelClass < handle
    % A general class containing methods for running user defined custom
    % models. This version will contain direct calls to the base Matlab
    % workspace using 'feval' for running Matlab custom models, which causes
    % the calls to be extrinsic..
    % https://uk.mathworks.com/help/simulink/ug/use-matlab-engine-to-execute-a-function-call-in-generated-code.html
    %
    % There will be an alternative version of the class using a call to an external Matlab
    % engine for the Python API...
    % https://uk.mathworks.com/help/matlab/calling-matlab-engine-from-c-programs-1.html

    properties

    end

    methods 

        function [allLayers,allRoughs] = processCustomLayers(obj,cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                                    shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params,parallelFlag)

        % Top-level function for processing custom layers for all the
        % contrasts. Because we want to allow users to 'mix and match'
        % custom models from Cpp, Matlab or Python, we're not attempting
        % any parallelisation across custom models any more. We simply loop
        % through the contrasts and call whichever routines are applicable

        % Do some pre-definitions to keep the compiler happy...
        tempAllLayers = cell(numberOfContrasts,1);
        allLayers = cell(numberOfContrasts,1);
        allRoughs = zeros(numberOfContrasts,1);

        for i = 1:numberOfContrasts
            allLayers{i} = [1 , 1];    % Type def as double (size not important)
            tempAllLayers{i} = [0 0 0 0 0];
        end
        coder.varsize('tempAllLayers{:}',[10000 5],[1 1]);

        if parallelFlag
            parfor i = 1:numberOfContrasts
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
                       [tempAllLayers{i},allRoughs(i)] = callMatlabCustomLayers(params,i,thisFile,thisPath,bulkIn,bulkOut,numberOfContrasts)
                        % case 'cpp'
                        %     [tempAllLayers(i),allRoughs(i)] = obj.cppCustomLayers(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                        %        shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params,para,i,numberOfContrasts);
                        % case 'python'
                        %      [tempAllLayers(i),allRoughs(i)] = obj.pythonCustomLayers(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                        %            shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params,para,i,numberOfContrasts);
                end
            end
        else
            for i = 1:numberOfContrasts
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
                       [tempAllLayers{i},allRoughs(i)] = callMatlabCustomLayers(params,i,thisFile,thisPath,bulkIn,bulkOut,numberOfContrasts);
                        % case 'cpp'
                        %     [tempAllLayers(i),allRoughs(i)] = obj.cppCustomLayers(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                        %        shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params,para,i,numberOfContrasts);
                        % case 'python'
                        %      [tempAllLayers(i),allRoughs(i)] = obj.pythonCustomLayers(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                        %            shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params,para,i,numberOfContrasts);
                end
            end
        end
        allLayers = tempAllLayers;
        end


        function [allSLDs,allRoughs] = processCustomXY(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                                    shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params)

            % TODO.....


        end




%         function [allSLDs, allRoughs] = matlabCustomXY(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
%                 shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params)
% 
%             %#codegen
% 
%             % Wrapper function for calling 'loopMatlabCustomXY'. This wrapper is
%             % necessary to deal with typedef problems for the coder if feval is used
%             % directly from the main function
%             tempAllSLDs = cell(numberOfContrasts,1);
%             allSLDs = cell(numberOfContrasts,1);
%             allRoughs = zeros(numberOfContrasts,1);
% 
%             for i = 1:numberOfContrasts
%                 allSLDs{i} = [1 , 1];    % Type def as double (size not important)
%                 tempAllSLDs{i} = [0 0 0 0 0];
%             end
%             coder.varsize('tempAllSLDs{:}',[10000 5],[1 1]);
% 
%             % Call the Matlab custom model. Based on the input 'para', then
%             % we either run over all contrasts single cored (para ==
%             % false), or we ask the paralell computing toolbox to paralell
%             % over the contrasts. By using 'feval', we force these
%             % functions to run in Matlab as extrinsic calls, rather than
%             % compiling them.
%             if para
%                 [tempAllSLDs, tempAllRoughs] = feval('matlabCustomXYSingle',cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
%                     shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params);
%             else
%                 [tempAllSLDs, tempAllRoughs] = feval('matlabCustomXYParallel',cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
%                     shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params);
%             end
% 
%             % All the following is intended to be casting from mxArray's to doubles.
%             % I'm not sure if all of this is necessary, but it compiles...
%             for i = 1:numberOfContrasts
%                 tempOut = tempAllSLDs{i};
%                 n = [0 0];
%                 n = size(tempOut);
%                 newOut = zeros(n);
%                 newOut = tempOut;
%                 allSLDs{i} = newOut;
%             end
% 
%             %allLayers = tempAllLayers;
%             allRoughs = tempAllRoughs;
%         end

        % **** CPP Custom Model Methods ****

        function [allLayers,allRoughs] = callCppCustomModel(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params)

            allLayers = cell(numberOfContrasts,1);
            for i = 1:numberOfContrasts
                allLayers{i} = [1 ; 1];
            end
            coder.varsize('allLayers{:}',[1000,5],[1,1]);

            for i = 1:numberOfContrasts
                tempOut = zeros(1000,5);
                sRough = 0.0;
                % This is the function that calls the C++ header function that loads the library,function and calls it with the supplied arguments
                [tempOut,sRough,nLayers,nCols] = callExternalCpp(params,nba,nbs,i,cLibName,cfunctionName);

                if (nLayers >= 1)
                    output = zeros(nLayers,nCols);
                    for i = 1:(nLayers*nCols)
                        thisVal = tempOut(i);  %Make use of Matlab linear indexing.
                        output(rowCount,colCount) = thisVal;
                        rowCount = rowCount + 1;
                        if rowCount == (nLayers+1)
                            rowCount = 1;
                            colCount = colCount + 1;
                        end
                    end
                else
                    output = [1 1 1];
                    sRough = 1;
                end
                allLayers{i} = output;
                allRoughs(i) = sRough;
            end
        end
    end

    % ********** End Cpp Methods ***************


    % ************* Python custom model methods ************












    % ******************************************



    methods (Access=private)

        function [allLayersArr,allRoughsArr] = callExternalCpp(params,nba,nbs,numberOfContrasts,libraryName,functionName)
            coder.cinclude('<functional>');
            coder.cinclude('<string>');
            coder.cinclude('<iostream>');
            coder.cinclude('<map>');
            coder.cinclude('<vector>');
            coder.cinclude('libManager.h');
            coder.cinclude('<tuple>');
            coder.updateBuildInfo('addLinkFlags','-ldl');

            % Need to find a way to make this work with 100000,3
            output = zeros(10000,5);
            subRough = 0.0;

            %cfunctionName(isstrprop(cfunctionName,'digit')) = [];

            p = coder.opaque('Library','NULL','HeaderFile','libManager.h');
            % Make an instance
            p = coder.ceval('Library');
            %coder.ceval('std::mem_fn(&Library::loadInfo)',p,[clibraryName,'0'],[cfunctionName,'0']);

            coder.ceval('std::mem_fn(&Library::loadRunner)',p,coder.ref(params),coder.ref(nba),coder.ref(nbs)...
                ,numberOfContrasts,coder.wref(output),coder.wref(subRough),libraryName,functionName);

            allLayersArr = output;
            allRoughsArr = subRough;
        end

        function [allLayersArr,allRoughsArr] = callExternalPython(params,nba,nbs,numberOfContrasts,libraryName,functionName)
            % TODO

        end

    end
end
