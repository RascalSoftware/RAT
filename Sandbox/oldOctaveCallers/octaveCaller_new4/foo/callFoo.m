function y = callFoo        %#codegen

y = 0.0;
if coder.target('MATLAB')
    y = 10 + 20;
else
    coder.updateBuildInfo('addSourceFiles','foo.cpp');
    coder.cinclude('foo.h');
    y = coder.ceval('foo',10,20);
end
end





