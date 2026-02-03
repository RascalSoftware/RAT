function [output, varargout] = callCppFunction(pointer, varargin)
    % Calls a Cpp custom function stored at the given pointer address. 
    %
    % data = callCppFunction(pointer, xdata, params)
    % [output, subRough] = callCppFunction(pointer, params, bulkIn ,bulkOut, contrast, domains);

    coder.cinclude('<functional>');
    coder.cinclude('classHandle.hpp')
    
    callbackHandle = coder.opaque('ClassHandle<CallbackInterface> *','NULL');
    callbackHandle = coder.ceval('convertString2HandlePtr<CallbackInterface>', pointer, numel(pointer));

    callback = coder.opaque('CallbackInterface *','NULL');
    callback = coder.ceval('std::mem_fn(&ClassHandle<CallbackInterface>::ptr)', callbackHandle);
       
    subRough = 0.0;
    actualSize = 0;
    outputSize = [0, 0];

    outArray = coder.opaque('std::vector<double>', '{}');

    if numel(varargin) == 2
        xdata = varargin{1};
        params = varargin{2};
        
        dataArray = coder.opaque('std::vector<double>');
        dataArray = coder.ceval('convertPtr2Vector', coder.ref(xdata), numel(xdata));

        paramsArray = coder.opaque('std::vector<double>');
        paramsArray = coder.ceval('convertPtr2Vector', coder.ref(params), numel(params));

        coder.ceval('std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<double>&)>(&CallbackInterface::invoke)', callback, dataArray, paramsArray, outArray);
        actualSize = coder.ceval('getVectorSize', outArray);

        output = zeros(actualSize, 1);
        coder.ceval('convertVector2Ptr', outArray, coder.wref(output));
    else
        params = varargin{1};
        bulkIn = varargin{2};
        bulkOut = varargin{3};
        contrast = varargin{4};
        domains = varargin{5};

        paramsArray = coder.opaque('std::vector<double>');
        paramsArray = coder.ceval('convertPtr2Vector', coder.ref(params), numel(params));
    
        bulkInArray = coder.opaque('std::vector<double>');
        bulkInArray = coder.ceval('convertPtr2Vector', coder.ref(bulkIn), numel(bulkIn));
     
        bulkOutArray = coder.opaque('std::vector<double>');
        bulkOutArray = coder.ceval('convertPtr2Vector', coder.ref(bulkOut), numel(bulkOut));

        % domain should either be 1 or 2. A value less than 1 indicates no domains
        if (domains < 1)
            coder.ceval(['std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<double>&, int, ' ...
                        'std::vector<double>&, double*, double*)>(&CallbackInterface::invoke)'], ...
                         callback, paramsArray, bulkInArray, bulkOutArray, contrast, outArray, ...
                        coder.wref(outputSize), coder.wref(subRough));
        else
            coder.ceval(['std::mem_fn<void(std::vector<double>&, std::vector<double>&, std::vector<double>&, int, int, ' ...
                         'std::vector<double>&, double*, double*)>(&CallbackInterface::invoke)'], ...
                         callback, paramsArray, bulkInArray, bulkOutArray, contrast, domains, outArray, ...
                         coder.wref(outputSize), coder.wref(subRough)); 
        end
        size = int32(outputSize(1) * outputSize(2));
        actualSize = coder.ceval('getVectorSize', outArray);
        tempOutput = zeros(1, actualSize);
        coder.ceval('convertVector2Ptr', outArray, coder.wref(tempOutput));

        if size ~= actualSize
            coderException(coderEnums.errorCodes.domainError, 'The output of the custom function with size %.0f does not match the specified size (%.0f x %.0f).', actualSize, outputSize(1), outputSize(2));
        end
        varargout{1} = subRough;
        output = reshape(tempOutput, [outputSize(2), outputSize(1)])';
    end
    
end
