function triggerEvent(eventType, data)
    % Triggers the event type with the given data. The supported event types are
    % 'message', 'plot', and 'progress'. The data for message is a char
    % array, for the plot it is a cell array containing the result cell, 
    % contrastParams.ssubs and problemStruct, and for progress data is cell
    % array contain the progress message and precentage.
    % 
    % triggerEvent('message', 'Hello world');
    persistent notified;
    persistent helper;

    initialised = false;
    hasPlotHandler = false;

    if isempty(notified)
        notified = false;
    end

    if coder.target('MATLAB')
         if strcmpi(eventType, 'message')
             fprintf("%s", data);
         elseif strcmpi(eventType, 'progress')
             textProgressBar(data{1}, data{2});
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
            if strcmpi(eventType, 'message')
                coder.ceval('std::mem_fn(&eventHelper::sendMessage)', helper, [data,0]);
            elseif strcmpi(eventType, 'progress')
                coder.ceval('std::mem_fn(&eventHelper::updateProgress)', helper, [data{1},0], data{2});
            elseif strcmpi(eventType, 'plot')
                hasPlotHandler = coder.ceval('std::mem_fn(&eventHelper::hasPlotHandler)', helper);
                if ~hasPlotHandler
                    return;
                end
                result = data{1};
                problemStruct = data{2};
                ssubs = result.contrastParams.ssubs;
                nContrast = length(result.reflectivity);
                [reflect, nReflect] = packCellArray(result.reflectivity, 1);
                [shiftedData, nShiftedData] = packCellArray(result.shiftedData, 1);
                [sldProfiles, nSldProfiles] = packCellArray(result.sldProfiles, 1);
                [layers, nLayers] = packCellArray(result.allLayers, 1);
                
                switch problemStruct.TF
                    case 'domains'
                        [sldProfiles2, nSldProfiles2] = packCellArray(result.sldProfiles, 2);
                        [layers2, nLayers2] = packCellArray(result.allLayers, 2);
                    otherwise 
                        sldProfiles2 = coder.nullcopy(zeros(0));
                        nSldProfiles2 =  coder.nullcopy(zeros(0));
                        layers2 =  coder.nullcopy(zeros(0));
                        nLayers2 = coder.nullcopy(zeros(0));
                end
   
                modelType = [problemStruct.modelType, 0];
                resample = problemStruct.resample;
                dataPresent = problemStruct.dataPresent;
                
                coder.ceval('std::mem_fn(&eventHelper::updatePlot)', helper, nContrast, reflect, nReflect, shiftedData, ...
                            nShiftedData, sldProfiles, nSldProfiles, layers, nLayers, sldProfiles2, nSldProfiles2, layers2, ...
                            nLayers2, ssubs, resample, dataPresent, modelType);
            end
            notified = false;
        else
            % This avoids printing the error message multiple times during the optimization.
            if ~notified
                fprintf(2, "\neventManager library could be loaded. Check that the dynamic library is present in the compile/events folder.\n");
                notified = true;
            end
            
            if strcmpi(eventType, 'message')
                fprintf("%s", data);    
            end
        end
    end
end


function [packedArray, counts] = packCellArray(cellArray, col)
    % Packs a specified column of a cell array with different sized arrays into a 
    % single row array and an array of counts for each cell. For the example below 
    % reflect will be [1, 2, 3, 4, 5, 6, 7] and nReflect will be [3, 4]
    % 
    % [reflect, nReflect] = packCellArray({[1; 2; 3], [4; 5; 6; 7]}, 1);
    rowSize = 0;
    nCells = size(cellArray, 1);
    
    counts = zeros(nCells, 1);
    for i=1:nCells
        counts(i) = size(cellArray{i, col}, 1) * size(cellArray{i, col}, 2);
        rowSize = rowSize + counts(i);
    end
    
    packedArray = zeros(rowSize, 1);
    start = 1;
    for i=1:nCells
        stop = start + counts(i);
        packedArray(start:stop-1, :) = reshape(cellArray{i, col}, [], 1);
        start = stop;
    end
end
