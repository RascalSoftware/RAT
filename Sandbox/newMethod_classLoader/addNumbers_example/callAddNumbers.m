function ret = callAddNumbers(number1,number2)

if coder.target('MATLAB')
    ret = number1 + number2;
else
    coder.cinclude('<functional>');
    coder.cinclude('addNumbers.h');
    
    p = coder.opaque('addNumbers','NULL','HeaderFile','addNumbers.h');
    p = coder.ceval('addNumbers');  % Is p now an instance of the class??
    
    num1 = int32(number1);
    num2 = int32(number2);
    
    ret = coder.nullcopy(int32(0)); 
    
    % Set the numbers
    coder.ceval('std::mem_fn(&addNumbers::setNumbers)',p,num1,num2);
    
    % Call the add method - puts the result in 'answer'
    coder.ceval('std::mem_fn(&addNumbers::findSum)',p);
    
    % Get the result
    ret = coder.ceval('std::mem_fn(&addNumbers)',p.answer);
end

end