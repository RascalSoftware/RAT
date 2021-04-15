function [output,sRough] = callTestFun(funcName,params,bulkIn,bulkOut,contrast)



% if isempty(fileHandle)
%     
%     dotM = strfind(funcName,'.m');
%     if ~isempty(dotM)
%         funcName = funcName(1:dotM-1);
%     end
%     
%     fullFunc = [path funcName];
%     fileHandle = str2func(fullFunc);
% end
%      
if coder.target('MATLAB')   

    ff = [funcName '(params,bulkIn,bulkOut,contrast)'];
    [output,sRough] = eval(ff);
    
else
    
    %ff = [funcName '(params,bulkIn,bulkOut,contrast)'];
    [output,sRough] = feval(funcName,params,bulkIn,bulkOut,contrast);
     
end

end