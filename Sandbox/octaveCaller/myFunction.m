function out = myFunction(params,bulkIn,bulkOut)


fprintf('bulkIn is %d \n',bulkIn);
fprintf('bulkOut is %d \n',bulkOut);

%out = params(1);
out = [1 2 3  ; params(1) params(2) params(3) ; 5 6 7];

endfunction
