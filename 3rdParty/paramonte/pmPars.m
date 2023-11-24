classdef pmPars < handle

    properties
    
        covMat = []
        delayedRejectionCount = []
        name = ''
        scalefactor = 1e-3
        chainSize = 10000
        chainTrim = 0.25    % Use only the last part of chain...
        mpi = false;
    
    end

end