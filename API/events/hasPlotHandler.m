function state = hasPlotHandler()
    % Checks if a function is listening for the plot event 
    %
    % state = hasPlotHandler();
    persistent helper;

    initialised = false;
    state = false;
    coder.extrinsic('eventManager.hasEvent')
    if coder.target('MATLAB') || coder.target('MEX')
        if eventManager.hasEvent(coderEnums.eventTypes.Plot)
            state = true;
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
            state = coder.ceval('std::mem_fn(&eventHelper::hasPlotHandler)', helper);
        end
    end
end
