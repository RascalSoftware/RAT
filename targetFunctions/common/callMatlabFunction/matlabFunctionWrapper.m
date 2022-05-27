function output = matlabFunctionWrapper(funcName,params,bulkIn,bulkOut,contrast)

output = feval(funcName,params,bulkIn,bulkOut,contrast);

end
 
