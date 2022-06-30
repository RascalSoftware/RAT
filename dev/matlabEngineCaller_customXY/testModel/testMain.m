params = load('debugParams.mat');
params = params.params;

contrast = 1;
bulk_in = 2.073e-6;
bulk_out = 6.35e-6;
[output,subrough] = matlabEngineCaller_customXY(params,bulk_in,bulk_out,contrast);

figure(1); clf
plot(output(:,1),output(:,2));
