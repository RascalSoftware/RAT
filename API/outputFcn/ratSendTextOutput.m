function ratSendTextOutput(text,in2)

ratOut = getappdata(0,'ratOut');
outputClass = ratOut{1};
outputClass.customEventData.textUpdate = text;
outputClass.triggerEvent;

end