function ratSendTextOutput(outText)

% This is an overloaded version of 'ratSendTextOutput' for the compile.
% The 'real' one is the output class. We will think of a better solution
% later on.
% if isnumeric(outText)
%     outText = sprintf('%g',outText);
% end

fprintf('%s \n',outText);

end