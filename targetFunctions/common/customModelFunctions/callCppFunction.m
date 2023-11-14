function [output,subRough] = callCppFunction(params, nba, nbs, contrast, domain, pointer)
    coder.cinclude('<functional>');
    coder.cinclude('classHandle.hpp')
    
    callbackHandle = coder.opaque('ClassHandle<CallbackInterface> *','NULL');
    callbackHandle = coder.ceval('convertString2HandlePtr<CallbackInterface>', pointer);

    callback = coder.opaque('CallbackInterface *','NULL');
    callback = coder.ceval('std::mem_fn(&ClassHandle<CallbackInterface>::ptr)', callbackHandle);
       
    tempOutput = zeros(1, 6000); % This is not ideal, it needs to be fixed 
    subRough = 0.0;
    outputSize = [0, 0];
    
    % domain should either before 0 or 1. A value less than zero indicates no domains  
    if (domain < 0)
        coder.ceval('std::mem_fn<void(double*, double*, double*, int, double*, double*, double*)>(&CallbackInterface::invoke)', ...
              callback, coder.ref(params), coder.ref(nba), coder.ref(nbs), contrast, coder.wref(tempOutput), ...
              coder.wref(outputSize), coder.wref(subRough));
    else
        coder.ceval('std::mem_fn<void(double*, double*, double*, int, int, double*, double*, double*)>(&CallbackInterface::invoke)', ...
            callback, coder.ref(params), coder.ref(nba), coder.ref(nbs), contrast, domain, coder.wref(tempOutput), ...
            coder.wref(outputSize), coder.wref(subRough)); 
    end

    size = outputSize(1) * outputSize(2);
    output = reshape(tempOutput(1, 1:size), [outputSize(2), outputSize(1)])';
end
