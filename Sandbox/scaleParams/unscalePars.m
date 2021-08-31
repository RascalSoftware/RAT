function unscaledParams = unscalePars(scaledParams,limits) 

% Change scaled parameters from a range 0 - 1 back to their original
% values
unscaledParams = (scaledParams(:).*(limits(:,2)-limits(:,1)))+limits(:,1);

% Reshape back to a row vector
unscaledParams = reshape(unscaledParams,1,[]);

