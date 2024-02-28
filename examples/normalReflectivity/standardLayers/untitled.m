function untitled(event)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
if event.percent == 0
    % The very first time we don't need to delete the old text
    fprintf('Last processed sample: %5d', fix(event.percent*100));
else
    % Each \b removes one character from the previous fprintf.
    fprintf('\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bLast processed sample: %5d', fix(event.percent*100));
end
end

