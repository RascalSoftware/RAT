
% Make up some simple inputs...
numbersList = [1 2 3 4 5];
charsArray = 'Hello world';

inStruct.numbers = numbersList;
inStruct.chars = charsArray;

firstArray = {{1 2 3 ; 4 5 6},{'rod','jane','freddy'}};
secondArray = {rand(5),rand(10)};

inArray = {firstArray secondArray};


[outStruct,outArray] = dummyFunction(inStruct,inArray);