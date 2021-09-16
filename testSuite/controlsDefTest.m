% Write Unit tests for controlsDef class
% Test each method of the class and its properties 
% under the following conditions:
% 1. The Controls class has a method that assigns an object to the class


%: Instantiate the class
control = controlsDef();

% Test 0: The Controls class has a method that assigns an object to the class

assert(strcmp(control.procedure(), 'bayes'), 'The controls class has been assigned a wrong object');
assert(strcmp(control.parallel(), 'contrasts'), 'The controls class has been assigned a wrong object');

% Test 1: Test every method of the class and its properties

control.p