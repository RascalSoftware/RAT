function defaultOutputFunction(eventrc,eventdata)

% The default RAT output function.
% This just takes the text from the event data
% and outputs this to the command window.

%disp('Hello World');

outData = eventdata.ratUpdateData;
outText = outData.textUpdate;
sprintf('%s \n',outText);

end