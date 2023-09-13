function [output,subRough] = callCppFunc(params, nba, nbs, contrast, domain, pointer, colSize)
    coder.cinclude('<functional>');
    coder.cinclude('classHandle.hpp')
    
    callbackHandle = coder.opaque('ClassHandle<CallbackInterface> *','NULL');
    callbackHandle = coder.ceval('convertString2HandlePtr<CallbackInterface>', pointer);

    callback = coder.opaque('CallbackInterface *','NULL');
    callback = coder.ceval('std::mem_fn(&ClassHandle<CallbackInterface>::ptr)', callbackHandle);

    tempOutput = zeros(colSize, 1000); % This is not ideal, it needs to be fixed 
    subRough = 0.0;
    nLayers = 0;
    
    % domain should either before 0 or 1. A value less than zero indicates no domains  
    if (domain < 0)
        coder.ceval('std::mem_fn<void(double*, double*, double*, int, double*, double*, double*)>(&CallbackInterface::invoke)', ...
              callback, coder.ref(params), coder.ref(nba), coder.ref(nbs), contrast, coder.wref(tempOutput), ...
              coder.wref(subRough), coder.wref(nLayers));
    else
        coder.ceval('std::mem_fn<void(double*, double*, double*, int, int, double*, double*, double*)>(&CallbackInterface::invoke)', ...
            callback, coder.ref(params), coder.ref(nba), coder.ref(nbs), contrast, domain, coder.wref(tempOutput), ...
            coder.wref(subRough), coder.wref(nLayers)); 
    end

    output = tempOutput(:,1:nLayers)';
end
