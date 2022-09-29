codegen -config:mex definedAndVariableNumInputs -args {1,2,3,4,5}
definedAndVariableNumInputs_mex(3,8,9,10,11)

codegen -config:mex definedAndVariableNumInputs_fails -args {1,2,3,4,5}
definedAndVariableNumInputs_fails_mex(3,8,9,10,11)