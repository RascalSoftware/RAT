function [problemDef,problem,result] = runSimplex(problemDef,problemDef_cells,problemDef_limits,controls)

numberOfContrasts = problemDef.numberOfContrasts;
preAlloc = zeros(numberOfContrasts,1);

result = cell(6,1);

problem = struct('ssubs',preAlloc,...
                 'backgrounds',preAlloc,...
                 'qshifts',preAlloc,...
                 'scalefactors',preAlloc,...
                 'nbairs',preAlloc,...
                 'nbsubs',preAlloc,...
                 'resolutions',preAlloc,...
                 'calculations',struct('all_chis',preAlloc,'sum_chi',0),...
                 'allSubRough',preAlloc);


[problemDef,fitNames] = fitsetup(problemDef,problemDef_cells,problemDef_limits,controls);

maxIter = controls.maxIter;
tolFun = controls.tolFun;
tolX = controls.tolX;
maxFunEvals = controls.maxFunEvals;
display = controls.display;

options = optimset('MaxIter',maxIter,'TolFun',tolFun,'TolX',tolX,'MaxFunEvals',maxFunEvals,'Display',display);

x0 = problemDef.fitpars;
LB = problemDef.fitconstr(:,1);
UB = problemDef.fitconstr(:,2);

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
  UB = repmat(inf,n,1);
else
  UB = UB(:);
end

% stuff into a struct to pass around
params.args = [];%varargin;
params.LB = LB;
params.UB = UB;
params.fun = '';%problemDef.modelFilename;%fun;

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

[xu,fval,exitflag,output] = fminsearch(@simplexIntrafun,x0u,options,problemDef,problemDef_cells,problemDef_limits,controls,params,300);

%[xu,fval,exitflag,output] = simplex(@simplexIntrafun,x0u,problemDef,problemDef_cells,problemDef_limits,controls,options,params,300);

% undo the variable transformations into the original space
x = simplex_xtransform(xu,params);

% final reshape
%x = reshape(x,xsize);

problemDef.fitpars = x;
problemDef = unpackparams(problemDef,controls);
[problem,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);

end
