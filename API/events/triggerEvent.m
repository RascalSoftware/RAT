function triggerEvent(eventType, data)
    % Triggers the event type with the given data. The supported event types are
    % 'message' and 'plot'. The data for message is a char array while for
    % the plot it is a cell array containing the result cell, problem.ssubs
    % and problemDef
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
            elseif strcmpi(eventType, 'plot')
                hasPlotHandler = coder.ceval('std::mem_fn(&eventHelper::hasPlotHandler)', helper);
                if ~hasPlotHandler
                    return;
                end
                result = data{1};
                problemDefStruct = data{3};
                nContrast = length(result{1});
                [reflect, nReflect] = packCellArray(result{1}, 1); % reflectivity
                [shiftedData, nShiftedData] = packCellArray(result{3}, 1);  
                [sldProfiles, nSldProfiles] = packCellArray(result{5}, 1);
                [layers, nLayers] = packCellArray(result{6}, 1);
                
                switch problemDefStruct.TF
                    case 'domains'
                        [sldProfiles2, nSldProfiles2] = packCellArray(result{5}, 2);
                        [layers2, nLayers2] = packCellArray(result{6}, 2);
                    otherwise 
                        sldProfiles2 = coder.nullcopy(zeros(0));
                        nSldProfiles2 =  coder.nullcopy(zeros(0));
                        layers2 =  coder.nullcopy(zeros(0));
                        nLayers2 = coder.nullcopy(zeros(0));
                end

                ssubs = data{2}; % ssubs
   
                modelType = [problemDefStruct.modelType, 0];
                resample = problemDefStruct.resample;
                dataPresent = problemDefStruct.dataPresent;
                
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
