function [output,subRough] = callCppFunction(pointer, params, bulkIn, bulkOut, contrast, domain)
    coder.cinclude('<functional>');
    coder.cinclude('classHandle.hpp')
    
    callbackHandle = coder.opaque('ClassHandle<CallbackInterface> *','NULL');
    callbackHandle = coder.ceval('convertString2HandlePtr<CallbackInterface>', pointer);

    callback = coder.opaque('CallbackInterface *','NULL');
    callback = coder.ceval('std::mem_fn(&ClassHandle<CallbackInterface>::ptr)', callbackHandle);
       
    subRough = 0.0;
    outputSize = [0, 0];
    
    paramsArray = coder.opaque('std::vector<double>');
    paramsArray = coder.ceval('convertPtr2Vector', coder.ref(params), numel(params));

    bulkInArray = coder.opaque('std::vector<double>');
    bulkInArray = coder.ceval('convertPtr2Vector', coder.ref(bulkIn), numel(bulkIn));
 
    bulkOutArray = coder.opaque('std::vector<double>');
    bulkOutArray = coder.ceval('convertPtr2Vector', coder.ref(bulkOut), numel(bulkOut));

    outArray = coder.opaque('std::vector<double>', '{}');

    % domain should either before 0 or 1. A value less than zero indicates no domains  
    if (domain < 0)
        coder.ceval(['std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<double>&, int, ' ...
                     'std::vector<double>&, double*, double*)>(&CallbackInterface::invoke)'], ...
                     callback, paramsArray, bulkInArray, bulkOutArray, contrast, outArray, ...
                     coder.wref(outputSize), coder.wref(subRough));
    else
        coder.ceval(['std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<double>&, int, int, ' ...
                     'std::vector<double>&, double*, double*)>(&CallbackInterface::invoke)'], ...
                     callback, paramsArray, bulkInArray, bulkOutArray, contrast, domain, outArray, ...
                     coder.wref(outputSize), coder.wref(subRough)); 
    end
    
    
    size = int32(outputSize(1) * outputSize(2));
    tempOutput = zeros(1, size);
    actualSize = 0;
    actualSize = coder.ceval('convertVector2Ptr', outArray, coder.wref(tempOutput));

    if size ~= actualSize
        error('The output of the custom function with size %d does not match the specified size (%d x %d).', actualSize, outputSize(2), outputSize(1))
    end
    output = reshape(tempOutput, [outputSize(2), outputSize(1)])';
end
