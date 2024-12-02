function [problemStruct,result] = runSimplex(problemStruct,problemLimits,controls)

[problemStruct,~] = fitsetup(problemStruct,problemLimits);

maxIter = controls.maxIterations;
tolFun = controls.funcTolerance;
tolX = controls.xTolerance;
maxFunEvals = controls.maxFuncEvals;
display = controls.display;

switch display
    case coderEnums.displayOptions.Off
        dis = 'none';
    case coderEnums.displayOptions.Iter
        dis = 'iter';
    case coderEnums.displayOptions.Notify
        dis = 'notify';
    case coderEnums.displayOptions.Final
        dis = 'final';
    otherwise
        dis = 'final';
end

options = optimset('MaxIter',maxIter,'TolFun',tolFun,'TolX',tolX,'MaxFunEvals',maxFunEvals);

x0 = problemStruct.fitParams;
LB = problemStruct.fitLimits(:,1);
UB = problemStruct.fitLimits(:,2);

% size checks
xsize = size(x0);
x0 = x0(:);
n=length(x0);

if isempty(LB)
  LB = repmat(-inf,n,1);
else
  LB = LB(:);
end
if isempty(UB)
  UB = inf(n,1);
else
  UB = UB(:);
end

% stuff into a struct to pass around
params.args = [];%varargin;
params.LB = LB;
params.UB = UB;
params.fun = '';%problemStruct.modelFilename;%fun;

% 0 --> unconstrained variable
% 1 --> lower bound only
% 2 --> upper bound only
% 3 --> dual finite bounds
params.BoundClass = zeros(n,1);
for i=1:n
  k = isfinite(LB(i)) + 2*isfinite(UB(i));
  params.BoundClass(i) = k;
  if (k==3) && (LB(i)==UB(i))
    error 'Bounds must be distinct if both are supplied.'
  end
end

% transform starting values into their unconstrained
% surrogates. Check for infeasible starting guesses.
x0u = x0;
for i = 1:n
  switch params.BoundClass(i)
    case 1
      % lower bound only
      if x0(i)<=LB(i)
        % infeasible starting value. Use bound.
        x0u(i) = 0;
      else
        x0u(i) = sqrt(x0(i) - LB(i));
      end
    case 2
      % upper bound only
      if x0(i)>=UB(i)
        % infeasible starting value. use bound.
        x0u(i) = 0;
      else
        x0u(i) = sqrt(UB(i) - x0(i));
      end
    case 3
      % lower and upper bounds
      if x0(i)<=LB(i)
        % infeasible starting value
        x0u(i) = -pi/2;
      elseif x0(i)>=UB(i)
        % infeasible starting value
        x0u(i) = pi/2;
      else
        x0u(i) = 2*(x0(i) - LB(i))/(UB(i)-LB(i)) - 1;
        x0u(i) = asin(max(-1,min(1,x0u(i))));
      end
    case 0
      % unconstrained variable. x0u(i) is set.
  end
end

% now we can call fminsearch, but with our own
% intra-objective function.

[xu,~,~,~] = fMinSearch(@simplexIntrafun,x0u,options,dis,problemStruct,controls,params);

%[xu,fval,exitflag,output] = simplex(@simplexIntrafun,x0u,problemStruct,controls,options,params,300);

% undo the variable transformations into the original space
x = simplexXTransform(xu,params);

% final reshape
%x = reshape(x,xsize);

problemStruct.fitParams = x;
problemStruct = unpackParams(problemStruct);
result = reflectivityCalculation(problemStruct,controls);

end
