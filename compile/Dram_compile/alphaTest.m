function alpha = alphaTest(trypath, A_count, invR, npar, stage)

%global A_count invR npar

alpha = alphafun(trypath,stage);




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function y=alphafun(cellIn,stage)
% alphafun(x,y1,y2,y3,...)
% recursive acceptance function for delayed rejection
% x.p, y1.p, ... contain the parameter value
% x.ss, y1.ss, ... the sum of squares
% x.a, y1.a, ... past alpha probabilities

% ML 2003

%global A_count npar
A_count = A_count+1;
y = 0;

%stage = length(cellIn) - 1; % The stage we're in, elements in varargin - 1
stage = stage - 1;
% recursively compute past alphas
coder.varsize('a1');
coder.varsize('a2');
a1 = 1; a2=1;
for kk=1:stage-1
%  a1 = a1*(1-varargin{k+1}.a); % already have these alphas
% Thanks to E. Prudencio for pointing out an error here
  ind = getConstIndex(kk);
  a1 = a1*(1-alphafun({cellIn{1:(ind+1)}},stage));
  a2 = a2*(1-alphafun({cellIn{(stage+1):-1:(stage+1-ind)}},stage));
  if  a2==0  % we will came back with prob 1
    y = 0;
    return
  end
end
y = lfun(cellIn{1},cellIn{stage});
for kk=1:stage
    ind = getConstIndex(kk);
    y = y + qfun(ind,cellIn);
end
y = min(1, exp(y).*a2./a1);

end

function ind = getConstIndex(n)
        
        %    tab = zeros(1,10);
        %    for l = 1:length(tab)
        %        tab(l) = l;
        %    end
        if n==1
            ind = coder.const(1);
        elseif n==2
            ind = coder.const(2);
        elseif n==3
            ind = coder.const(3);
        elseif n==4
            ind = coder.const(4);
        else
            ind = coder.const(5);
        end
end

%************************************************************%
function z=qfun(iq,qfunin)

%global npar;

% Gaussian n:th stage log proposal ratio
% log of q_i(y_n,..,y_n-j) / q_i(x,y_1,...,y_j)

% ----------------------------------
% Try to pre set variables to get past 'non constant expression'
% error in coder.....
% coder.varsize('y1',[100 100],[1 1]);
% coder.varsize('y2',[100 100],[1 1]);
% coder.varsize('y3',[100 100],[1 1]);
% coder.varsize('y4',[100 100],[1 1]);
% coder.varsize('z',[100 100],[1 1]);
% coder.varsize('iR',[100,100],[1 1]);

y1 = zeros(1,npar);
y2 = zeros(1,npar);
y3 = zeros(1,npar);
y4 = zeros(1,npar);
iR = zeros(npar,npar);
z = 0;
% -----------------------------

stage = length(qfunin)-1;
if stage == iq
  z = 0;                                % we are symmetric
else
  iR = invR{iq};                        % proposal^(-1/2)
  y1 = qfunin{1}.p;           % y1
  y2 = qfunin{iq+1}.p;        % y_i
  y3 = qfunin{stage+1}.p;     % y_n
  y4 = qfunin{stage-iq+1}.p;  % y_(n-i)
  
  coder.varsize('firstPar',[1 1],[0 0]);
  coder.varsize('secondPar',[1 1],[0 0]);
  
  firstPar = 0;     % Essentially typeDefs
  secondPar = 0;
  
  firstPar = norm((y4-y3)*iR);
  secondPar = norm((y2-y1)*iR);
  
  %z = -0.5*(norm((y4-y3)*iR)^2-norm((y2-y1)*iR)^2);
  coder.varsize('z',[1 1],[0 0]);
  z = -0.5*(firstPar^2 - secondPar^2);
end

end
%************************************************************%
function z=lfun(x,y)
% log posterior ratio,  log( pi(y)/pi(x) * p(y)/p(x) )
z = -0.5*( sum((y.ss./y.s2-x.ss./x.s2)) + y.pri - x.pri );
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

end
