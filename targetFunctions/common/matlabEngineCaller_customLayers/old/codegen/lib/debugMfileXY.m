function [total,layers] = debugMfileXY(params,bulk_in,bulk_out,contrast)

s = sum(params);
total = [s 37; 4 5; 7 8; 10 11; 50 60 ];
layers = size(total,1);

end
