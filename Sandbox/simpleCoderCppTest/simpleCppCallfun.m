function out = simpleCppCallfun(input)

if coder.target('MATLAB')
    out = input * 2;
else
    out = 0;
    sourceFile = 'simpleCppFunc.h';
    coder.updateBuildInfo('addSourceFiles',sourceFile);
    coder.ceval('simpleCppFunc',input,coder.wref(out));
end
