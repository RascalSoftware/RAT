function xtrans = simplex_xtransform(x,params);
% converts unconstrained variables into their original domains

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
      xtrans(i) = (sin(x(i))+1)/2;
      xtrans(i) = xtrans(i)*(params.UB(i) - params.LB(i)) + params.LB(i);
    case 0
      % unconstrained variable. xtrans(i) is set.
  end
end