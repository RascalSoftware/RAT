function coderException(message, varagin)
    
    if coder.target('MATLAB') || coder.target('MEX')
        error(message, varagin);
    else       
        coder.cinclude('<stdexcept>');
        coder.updateBuildInfo('addLinkFlags','-ldl');
        if isempty(helper)       
            % Declaration for coder
            helper = coder.opaque('eventHelper','NULL','HeaderFile','eventHelper.hpp');
    
            % Make an instance 
            helper = coder.ceval('eventHelper');
            path = [getenv('RAT_PATH'), 0];
            coder.ceval('std::mem_fn(&eventHelper::init)', helper, path);
        end
    end
end