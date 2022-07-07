function [total,layers] = debugMfile(params,bulk_in,bulk_out,contrast)

s = sum(params);
total = [s 37 38; 4 5 6; 7  8 9; 10 11 12 ; 50 60 70];
layers = size(total,1);

end
