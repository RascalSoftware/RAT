function ret = mycode
%MYMCODE Summary of this function goes here
%   Detailed explanation goes here

coder.cinclude('<functional>');
coder.cinclude('myclass.h');

p = coder.opaque('MyClass','NULL','HeaderFile','myclass.h');
p = coder.ceval('MyClass');

a = int32(5);

ret = coder.nullcopy(int32(0));
ret = coder.ceval('std::mem_fn(&MyClass::mymethod)',p,a);
end