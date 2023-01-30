% Write Unit tests for controlsDef class
% Test each method of the class and its properties 
% under the following conditions:
% 1. The Controls class has a method that assigns an object to the class


%: Instantiate the class
control = controlsDef();

% Test if set.parallel method is working
control.parallel = 'single';
assert(isequal(control.parallel, 'single'), 'set.parallel method is not working')

% Test if set.procedure method is working
control.procedure = 'simplex';
assert(isequal(control.procedure, 'simplex'), 'set.procedure method is not working')

% Test if set.calcSldDuringFit method is working
control.calcSldDuringFit = 'yes';
assert(isequal(control.calcSldDuringFit, 'yes'), 'set.calcSldDuringFit method is not working')

% Test if set.display method is working
control.display = 'iter';
assert(isequal(control.display, 'iter'), 'set.display method is not working')



