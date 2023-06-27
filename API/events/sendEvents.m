function sendEvents(eventType, data)
    persistent initialised;

    if isempty(initialised)
        initialised = false;
    end

    if coder.target('MATLAB')
         if strcmpi(eventType, 'message')
             fprintf("%s", data);
         end
    else
        coder.cinclude('eventHelper.hpp');
        coder.updateBuildInfo('addLinkFlags','-ldl');
        
        % Declaration for coder
        p = coder.opaque('eventHelper','NULL','HeaderFile','eventHelper.hpp');
        complete = false;        
        
        % Make an instance 
        p = coder.ceval('eventHelper');
        complete = coder.ceval('std::mem_fn(&eventHelper::init)', p);
        if complete
            if strcmpi(eventType, 'message')
                coder.ceval('std::mem_fn(&eventHelper::sendMessage)', p, [data,0]);
            elseif strcmpi(eventType, 'plot')
                result = data{1};
                temp = result{1}; % reflectivity
    
                nContrast = length(temp);
                colSize = size(temp{1}, 2);
                nReflect = length(temp{1});
                reflect = zeros(nReflect, 2 * nContrast);
                for i=1:nContrast 
                    reflect(:, (colSize*i)-(colSize-1):(colSize*i)) = temp{i}; 
                end
    
                temp = result{3}; % shifted data
                colSize = size(temp{1}, 2);
                nShiftedData = length(temp{1});
                shiftedData = zeros(nShiftedData, colSize * nContrast);
                for i=1:nContrast 
                    shiftedData(:, (colSize*i)-(colSize-1):(colSize*i)) = temp{i}; 
                end
    
                temp = result{5}; % Sld profiles
                colSize = size(temp{1}, 2);
                nSldProfiles = length(temp{1});
                sldProfiles = zeros(nSldProfiles, colSize * nContrast);
                for i=1:nContrast 
                    sldProfiles(:, (colSize*i)-(colSize-1):(colSize*i)) = temp{i};
                end
    
                temp = result{6}; % All Layers
                nLayers = length(temp{1});
                layers = zeros(nLayers, nContrast);
                for i=1:nContrast 
                    layers(:, i) = temp{i}';
                end
                
                ssubs = data{2}; % ssubs
    
                problemDef = data{3};
                modelType = [problemDef.modelType, 0];
                resample = problemDef.resample;
                dataPresent = problemDef.dataPresent;
                
                coder.ceval('std::mem_fn(&eventHelper::updatePlot)', p, nContrast, reflect, nReflect, shiftedData, ...
                            nShiftedData, sldProfiles, nSldProfiles, layers, nLayers, ssubs, resample, dataPresent, ...
                            modelType);
            end
            initialised = false;
        else
            if ~initialised
                fprintf(2, "\neventManager library cannot be loaded. Check that the dynamic library is present in the compile/events folder.\n");
                initialised = true;
            end
            
            if strcmpi(eventType, 'message')
                fprintf("%s", data);    
            end
        end
    end
end
