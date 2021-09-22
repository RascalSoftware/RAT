function problem =  fitfinish(problem);

%Unpack the parameters
problem = unpackparams(problem);
problem = reflectivity_calculation(problem);
setappdata(0,'problem',problem);

%updateTheGraphs();
update_params();

unlockMainGuiFrame();
enableMenus();
rascalMemoryCleanup;
