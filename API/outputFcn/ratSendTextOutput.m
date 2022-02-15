function ratSendTextOutput(text,in2)

ratOut = getappdata(0,'ratOut');
outputClass = ratOut{1};
try
    outputClass.customEventData.textUpdate = text;
    outputClass.triggerEvent;
catch
    disp(text);
end