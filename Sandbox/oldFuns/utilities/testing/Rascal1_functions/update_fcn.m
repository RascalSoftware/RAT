function update_fcn()

problem = getappdata(0,'problem');
checks = data_getChecked();
problem.include_data = checks;
setappdata(0,'problem',problem);

reflectivity_calculation();
rascal_plotting();

