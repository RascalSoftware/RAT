function coderException(errorCode, message, varargin)
    % Ensures a proper exception is thrown in the generated C++ code.
    % The arguments should be the errorCode integer, error message as a char array (which can be a formatspec) 
    % and other parameters if message is a formatspec.
    %
    % coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
    % coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
    
    if coder.target('C++')     
        coder.cinclude('coderException.hpp');
        coder.ceval('coderException', errorCode, sprintf(message, varargin{:}));
    end
    error(message, varargin{:});
end