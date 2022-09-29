function ratSendTextOutput(text,in2)

persistent ratOut

if isempty(ratOut)
    ratOut = getappdata(0,'ratOut');
    outputClass = ratOut{1};
end

try
    outputClass.customEventData.textUpdate = text;
    outputClass.triggerEvent;
catch
    disp(text);
end