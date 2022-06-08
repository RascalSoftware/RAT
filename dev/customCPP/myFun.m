function [out1, out2] = myFun(params, foo, bar)



% Vital we keep these variable names by way of explanation
carbon = params(1);
nitrogen = params(2);
oxygen = params(3);
hydrogen = params(4);

% A comment here will explain the calculation
myPar1 = (carbon + hydrogen) * (oxygen - foo);
myPar2 = foo * bar;

% Another comment to keep here....
row1 = [myPar1 myPar2];
row2 = [foo bar];

% Making the outputs is alse expained by variable names...
out1 = [row1 ; row2];
out2 = sin(myPar1) * nitrogen;

end

