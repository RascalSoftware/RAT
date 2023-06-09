function [output,sub_rough] = simpleAbsCustomBilayer(params,bulk_in,bulk_out,contrast)

% Simple example of custom layers with Absorption
sub_rough = params(1);
lay1_thick = params(2);
lay1_SLD_Re = params(3);
lay1_SLD_Im = params(4);
lay1_Rough = params(5);

lay2_thick = params(6);
lay2_SLD_Re = params(7);
lay2_SLD_Im = params(8);
lay2_Rough = params(9);

% Make the layers..
layer_1 = [lay1_thick lay1_SLD_Re lay1_SLD_Im lay1_Rough];
layer_2 = [lay2_thick lay2_SLD_Re lay2_SLD_Im lay2_Rough];

% Group them....
output = [layer_1 ; layer_2];

end