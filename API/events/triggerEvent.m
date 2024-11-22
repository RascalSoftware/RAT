function triggerEvent(eventType, varargin)
    % Triggers the event type with the given varargin. The supported event types are
    % 0, 1, and 2. 
    % * The input for the message event is a char array, 
    % * The inputs for the plot event are the result struct, problem struct and cell 
    % * The inputs for progress events are the message (char array) and 
    %   percentage progress expressed as a decimal (i.e., between 0 and 1).
    % 
    % triggerEvent(coderEnums.eventTypes.Message, 'Hello world');
    % triggerEvent(coderEnums.eventTypes.Plot, result, problemStruct);
    % triggerEvent(coderEnums.eventTypes.Progress, 'Hello world', 0.5);
    persistent notified;
    persistent helper;

    initialised = false;
    hasPlotHandler = false;

    if isempty(notified)
        notified = false;
    end
    coder.extrinsic('textProgressBar');
    coder.extrinsic('eventManager.notify')
    if coder.target('MATLAB') || coder.target('MEX')
        if eventType == coderEnums.eventTypes.Message
            fprintf("%s", varargin{1});
        elseif eventType == coderEnums.eventTypes.Progress
            textProgressBar(varargin{1}, varargin{2});
        elseif eventType == coderEnums.eventTypes.Plot
            result = varargin{1};
            problemStruct = varargin{2};
            plotData.reflectivity = result.reflectivity;
            plotData.shiftedData = result.shiftedData;
            plotData.sldProfiles = result.sldProfiles;
            plotData.resampledLayers = result.resampledLayers;
            plotData.subRoughs = result.contrastParams.subRoughs;
            plotData.resample = problemStruct.resample;
            plotData.dataPresent = problemStruct.dataPresent;
            plotData.modelType = problemStruct.modelType;
            plotData.contrastNames = problemStruct.contrastNames;
             
            eventManager.notify(eventType, plotData);
        end
    else       
        coder.cinclude('eventHelper.hpp');
        coder.updateBuildInfo('addLinkFlags','-ldl');
        if isempty(helper)       
            % Declaration for coder
            helper = coder.opaque('eventHelper','NULL','HeaderFile','eventHelper.hpp');
    
            % Make an instance 
            helper = coder.ceval('eventHelper');
            path = [getenv('RAT_PATH'), 0];
            coder.ceval('std::mem_fn(&eventHelper::init)', helper, path);
        end
        
        initialised = coder.ceval('std::mem_fn(&eventHelper::isInitialised)', helper);
        if initialised
            if eventType == coderEnums.eventTypes.Message
                coder.ceval('std::mem_fn(&eventHelper::sendMessage)', helper, [varargin{1},0]);
            elseif eventType == coderEnums.eventTypes.Progress
                coder.ceval('std::mem_fn(&eventHelper::updateProgress)', helper, [varargin{1},0], varargin{2});
            elseif eventType == coderEnums.eventTypes.Plot
                hasPlotHandler = coder.ceval('std::mem_fn(&eventHelper::hasPlotHandler)', helper);
                if ~hasPlotHandler
                    return;
                end

                result = varargin{1};
                problemStruct = varargin{2};
                subRoughs = result.contrastParams.subRoughs;
                nContrast = length(result.reflectivity);
                [reflect, nReflect] = packCellArray(result.reflectivity, 1);
                [shiftedData, nShiftedData] = packCellArray(result.shiftedData, 1);
                [sldProfiles, nSldProfiles] = packCellArray(result.sldProfiles, 1);
                [layers, nLayers] = packCellArray(result.resampledLayers, 1);
                names = problemStruct.contrastNames;
                contrastNames = strjoin(names, '');
                nContrastNames = strlength(names);

                switch problemStruct.TF
                    case coderEnums.calculationTypes.Domains
                        [sldProfiles2, nSldProfiles2] = packCellArray(result.sldProfiles, 2);
                        [layers2, nLayers2] = packCellArray(result.resampledLayers, 2);
                    otherwise 
                        sldProfiles2 = coder.nullcopy(zeros(0));
                        nSldProfiles2 = coder.nullcopy(zeros(0));
                        layers2 = coder.nullcopy(zeros(0));
                        nLayers2 = coder.nullcopy(zeros(0));
                end
   
                modelType = [problemStruct.modelType, 0];
                resample = problemStruct.resample;
                dataPresent = problemStruct.dataPresent;
                
                coder.ceval('std::mem_fn(&eventHelper::updatePlot)', helper, nContrast, reflect, nReflect, shiftedData, ...
                            nShiftedData, sldProfiles, nSldProfiles, layers, nLayers, sldProfiles2, nSldProfiles2, layers2, ...
                            nLayers2, subRoughs, resample, dataPresent, modelType, contrastNames, nContrastNames);
            end
            notified = false;
        else
            % This avoids printing the error message multiple times during the optimization.
            if ~notified
                fprintf(2, "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
                notified = true;
            end
            
            if eventType == coderEnums.eventTypes.Message
                fprintf("%s", varargin{1});    
            end
        end
    end
end


function [packedArray, dims] = packCellArray(cellArray, col)
    % Packs a specified column of a cell array with different sized arrays into a 
    % single row array and an array of the dimensions for each cell. For the example 
    % below packedArray will be [1, 2, 3, 4, 5, 6, 7] and dims will be [3, 1, 4, 1]
    % 
    % [packedArray, dims] = packCellArray({[1; 2; 3], [4; 5; 6; 7]}, 1);
    rowSize = 0; 
    nCells = size(cellArray, 1);
    
    dims = zeros(nCells*2, 1);
    for i=1:nCells
        shape = size(cellArray{i, col});
        index = 2*i-1;
        dims(index:index+1, :) = shape;
        rowSize = rowSize + prod(shape);
    end
    
    start = 1;
    packedArray = zeros(rowSize, 1);
    for i=1:nCells
        index = 2*i-1;
        stop = start + prod(dims(index:index+1, 1));
        packedArray(start:stop-1, :) = reshape(cellArray{i, col}, [], 1);
        start = stop;
    end
end
