clear


a = load('configmexexe.mat');
a = a.a;

%codegen -config a.configmex myIntegerTest -args {coder.typeof(0.0,[1 1],[0 0])}

codegen myIntegerTest -args {coder.typeof(0.0,[1 1],[0 0])}
