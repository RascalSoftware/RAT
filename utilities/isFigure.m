function isFigure(figure)
    % Checks whether input is either a figure object or a figure number.
    %
    % Parameters
    % ----------
    % figure : Any
    %    The input to check if it is a figure. 
    %
    % Raises
    % ------
    % Generic Error
    %    if input is not a figure or a figure number.

    if ~(isnumeric(figure) || isa(figure, 'matlab.ui.Figure'))
        error("'figure' must be a figure number or a figure object.")
    end
end
