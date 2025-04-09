classdef errorCodes < customEnum
  % Internal error codes for MATLAB Coder exceptions (see compile/exceptions/coderException.m).
   methods (Static)
        function s = toStruct()
            s = customEnum.toStruct(mfilename('class'));
        end
        
        function v = values()
            v = customEnum.values(mfilename('class'));
        end
        
        function e = fromValue(value)
            e = customEnum.fromValue(mfilename('class'), value);
        end
    end

    enumeration
        unknown (0)
        invalidOption (1)
        domainError (2)
    end
end
