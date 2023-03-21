
% A simple dummy 'Hello World' function in order toinvestigate how to make
% Cython connections to Coder generated Cpp.


function [outStruct,outArray] = dummyFunction(inStruct,inArray)


% Break up the input arrays
numbersList = inStruct.numbers;
charsList = inStruct.chars;

firstArray = inArray{1};
secondArray = inArray{2};


fprintf('Obligatory Hello World');


% Make the output arrays...
outStruct.numbersList = numbersList;
outStruct.charsList = charsList;

outArray = cell(1,2);
outArray{1} = firstArray;
outArray{2} = secondArray;

end