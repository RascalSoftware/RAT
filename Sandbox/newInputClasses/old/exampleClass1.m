classdef exampleClass1 < handle
    
   properties
      T = table; 
   end
   
   methods
   % Constructor
   function obj = exampleClass1()
       
       sz = [3 3];
       varTypes = {'double','double','double'};
       varNames = {'Min','Value','Max'};
       obj.T = table('Size',sz,'VariableTypes',varTypes,'VariableNames',varNames);
       obj.T(1,:) = {1 2 3 };
   end
    
   end
end