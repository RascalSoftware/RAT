function [out, srough] = customFileWrapper(fname,params,bulkIn,bulkOut,contrast)

[out,srough] = feval(fname,params,bulkIn,bulkOut,contrast);
    

end