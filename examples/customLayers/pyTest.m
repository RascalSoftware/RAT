

fname = 'customBilayer';

mod = py.importlib.import_module(fname); 

%     sub_rough = params[0]
%     oxide_thick = params[1]
%     oxide_hydration = params[2]
%     lipidAPM = params[3]
%     headHydration = params[4]
%     bilayerHydration = params[5]
%     bilayerRough = params[6]
%     waterThick = params[7]

py.importlib.reload(mod);


params = [10 30 30 50 30 10 3 20];
bulk_in = 2.07e-6;
bulk_out = 6.35e-6;
contrast = int32(1);

%out = mod.customBilayer(params,bulk_in,bulk_out,contrast);
params = [3,10,30,50,10,0,3,10];
bulk_in = 2.07e-6;
bulk_out = 6.35e-6;
out = mod.customBilayer(params,1,1,1);
