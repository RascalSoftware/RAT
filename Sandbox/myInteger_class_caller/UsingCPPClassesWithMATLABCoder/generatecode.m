load('configmexexe.mat')

codegen -config configmex persontest -args {coder.typeof('a',[1 1024],[0 1]),int16(0)}
[name,age] = persontest_mex('McAwesome',int16(15))

codegen -config configexe persontest -args {coder.typeof('a',[1 1024],[0 1]),int16(0)}
!persontest