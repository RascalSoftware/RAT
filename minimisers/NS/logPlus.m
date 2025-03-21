function logz  = logPlus(logx, logy)
% Calculate log(x+y) given logx and logy.
%
% It avoids problems of dynamic range when the
% exponentiated values of x or y are very large or small.
%
% Parameters
% ----------
% logx, logy : float
%     The two logarithmic values to add.
%
% Returns
% -------
% logz : float
%     The value of log(x+y).
%
if isinf(logx) && isinf(logy)
    logz = -inf;
    return;
end

if logx > logy
    logz = logx+log1p(exp(logy-logx));
else
    logz = logy+log1p(exp(logx-logy));
end

return
