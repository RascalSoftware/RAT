function triggerEvent(eventType, data)
    % Triggers the event type with the given data. The supported event types are
    % 'message' and 'plot'. The data for message is a char array while for
    % the plot it is a cell array containing the result cell, problem.ssubs
    % and problemDef
    % 
    % triggerEvent('message', 'Hello world');
    persistent notified;
    persistent helper;

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
        
        initialised = false;
        initialised = coder.ceval('std::mem_fn(&eventHelper::isInitialised)', helper);
        if initialised
            if strcmpi(eventType, 'message')
                coder.ceval('std::mem_fn(&eventHelper::sendMessage)', helper, [data,0]);
            elseif strcmpi(eventType, 'plot')
                result = data{1};
                nContrast = length(result{1});
                [reflect, nReflect] = packCellArray(result{1}); % reflectivity
                [shiftedData, nShiftedData] = packCellArray(result{3});  
                [sldProfiles, nSldProfiles] = packCellArray(result{5});
                [layers, nLayers] = packCellArray(result{6}); % All Layers
              
                ssubs = data{2}; % ssubs
   
                problemDef = data{3};
                modelType = [problemDef.modelType, 0];
                resample = problemDef.resample;
                dataPresent = problemDef.dataPresent;
                
                coder.ceval('std::mem_fn(&eventHelper::updatePlot)', helper, nContrast, reflect, nReflect, shiftedData, ...
                            nShiftedData, sldProfiles, nSldProfiles, layers, nLayers, ssubs, resample, dataPresent, ...
                            modelType);
            end
            notified = false;
        else
            % This avoids printing the error message multiple times during the optimization.
            if ~notified
                fprintf(2, "\neventManager library coult be loaded. Check that the dynamic library is present in the compile/events folder.\n");
                notified = true;
            end
            
            if strcmpi(eventType, 'message')
                fprintf("%s", data);    
            end
        end
    end
end


function [packedArray, counts] = packCellArray(cellArray)
    % Packs a cell array with different sized arrays into a single row
    % array and an array of counts for each cell. For the example below 
    % reflect will be [1, 2, 3, 4, 5, 6, 7] and nReflect will be [3, 4]
    % 
    % [reflect, nReflect] = packCellArray({[1, 2, 3], [4, 5, 6, 7]});
    rowSize = 0;
    nCells = length(cellArray);
    
    counts = zeros(nCells, 1);
    for i=1:nCells
        counts(i) = size(cellArray{i}, 1) * size(cellArray{i}, 2);
        rowSize = rowSize + counts(i);
    end
    
    packedArray = zeros(rowSize, 1);
    start = 1;
    for i=1:nCells
        stop = start + counts(i);
        packedArray(start:stop-1, :) = reshape(cellArray{i}, [], 1);
        start = stop;
    end
end