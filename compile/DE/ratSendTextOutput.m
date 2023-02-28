function sendTextOutput(outText)

% This is an overloaded version of 'sendTextOutput' for the compile.
% The 'real' one is the output class. We will think of a better solution
% later on.
% if isnumeric(outText)
%     outText = sprintf('%g',outText);
% end

fprintf('%s \n',outText);

end