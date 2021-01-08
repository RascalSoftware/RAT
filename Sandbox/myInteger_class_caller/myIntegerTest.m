function out = myIntegerTest(value)
%#codegen

if coder.target("MATLAB")
    out = value;
else
    
    out = 0;
    sourceFile1 = 'MyIntegerWrapper.cpp';
    sourceFile2 = 'MyInteger.cpp';
    coder.updateBuildInfo('addSourceFiles',sourceFile1);
    coder.updateBuildInfo('addSourceFiles',sourceFile2);

    myIntegerPtr = coder.opaque('myIntegerType','HeaderFile','MyIntegerWrapper.h');
    myIntegerPtr = coder.ceval('MyInteger_constructor');
    
    coder.ceval('set_wrapper',myIntegerPtr,value);
    out = coder.ceval('get_wrapper',myIntegerPtr);
end

end
