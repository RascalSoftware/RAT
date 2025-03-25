function xtrans = simplexXTransform(x,params)
% Convert unconstrained variables into their original domains.
%
% Parameters
% ----------
% x : vector
%     The point to transform.
% params : struct
%     Parameter fit information.
%
% Returns
% -------
% xtrans : vector
%     The point ``x`` transformed for the parameter bounds.
%
xtrans = x;
for i = 1:length(x)
  switch params.BoundClass(i)
    case 1
      % lower bound only
      xtrans(i) = params.LB(i) + x(i).^2;
    case 2
      % upper bound only
      xtrans(i) = params.UB(i) - x(i).^2;
    case 3
      % lower and upper bounds
      xtrans(i) = 0.5*(sin(x(i))+1);
      xtrans(i) = xtrans(i)*(params.UB(i) - params.LB(i)) + params.LB(i);
    case 0
      % unconstrained variable. xtrans(i) is set.
  end
end
