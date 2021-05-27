
function [out] = drPart(R,npar,oldpar,newpar,Ntry,DR_scale,parind,low,upp,thetamu,thetasig)

% Dummy parameters for checking compile from here...
dodram = 1;
accept = 0;
ss2 = 82.4;
oldprior = 0;
newprior = 0;
sigma2 = 1;
ss1 = Inf;
tst = 0;
problem = [];
data = [];
modelfun = '';
ssfun = '';

global A_count
A_count = 0; % alphafun count
RDR = cell(1,Ntry);
RDR{1} = [];

define_invR = cell(1,Ntry);
for i = 1:Ntry
    define_invR{i} = i;
end

invR = define_invR;

%invR{1} = [];
if dodram
    RDR{1} = R;
    invR{1} = R\eye(npar);
    for i=2:Ntry
        RDR{i}  = RDR{i-1}./DR_scale(min(i-1,length(DR_scale)));
        invR{i} = RDR{i}\eye(npar);
    end
    %end
    iacce = zeros(1,Ntry);
end

str = struct('p',{0},'ss',{0},'pri',{0},'s2',{0},'a',{0});
x = str;
y = str;
z = str;

%%% DR -----------------------------------------------------
if dodram == 1 && accept == 0 % & outbound == 0
    % we do a new try according to delayed rejection
    x.p   = oldpar;
    x.ss  = ss2;
    x.pri = oldprior;
    x.s2  = sigma2;
    
    y.p   = newpar;
    y.ss  = ss1;
    y.pri = newprior;
    y.s2  = sigma2;
    y.a   = tst;
    
    z = x;
    
    trypath = {x,y,z};
    itry    = 1;
    while accept == 0 && itry < Ntry
        itry = itry+1;
        z.p  = x.p + randn(1,npar)*RDR{itry};
        z.s2 = sigma2;
        if any(z.p<low(parind)) || any(z.p>upp(parind))
            z.a   = 0;
            z.pri = 0;
            z.ss  = Inf;
            trypath = {trypath{1:2},z};
            outbound = 1;
            continue
        end
        
        outbound = 0;
        z.ss = sseval(ssfun,[],z.p,parind,[],[],[],[],[]);
        z.pri = priorfun(z.p,thetamu(parind),thetasig(parind));
        trypath = {trypath{1:2},z};
        alpha = alphafun(trypath{:});
        trypath{end}.a = alpha;
        if alpha >= 1 || rand(1,1) < alpha     %  accept
            accept   = 1;
            newpar   = z.p;
            ss1      = z.ss;
            newprior = z.pri;
            iacce(itry) = iacce(itry) + 1;
        end
%         if shdebug && fix(isimu/shdebug) == isimu/shdebug
%             fprintf('try %d: pri: %g, alpha: %g\n',itry, z.pri, alpha);
%             fprintf(' p: %g\n',z.p);
%         end
    end
%     if dostats2
%         evalchain(chainind) = itry;
%     end
end % DR --------------------------------------------------------

out = 'ok';

% Original internal functions:-

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function ss = sseval(ssfun,ssstyle,theta,parind,value,local,data,problem,modelfun)
% evaluate the "sum-of-squares" function
value(parind) = theta;
%if ssstyle == 1
%  ss = feval(ssfun,value(:)',data);
%elseif ssstyle == 4
%  ss = mcmcssfun(value(:)',data,local,modelfun);
%else
%  ss = reflectivity_fitModel(value(:)',data,problem);
%end

% Just return a dummy value
ss = 1;

end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function y=alphafun(varargin)
% alphafun(x,y1,y2,y3,...)
% recursive acceptance function for delayed rejection
% x.p, y1.p, ... contain the parameter value
% x.ss, y1.ss, ... the sum of squares
% x.a, y1.a, ... past alpha probabilities

% ML 2003

%global A_count
A_count = A_count+1;
y = 0;

stage = nargin - 1; % The stage we're in, elements in varargin - 1
% recursively compute past alphas
coder.varsize('a1');
coder.varsize('a2');
a1 = 1; a2=1;
for kk=1:stage-1
%  a1 = a1*(1-varargin{k+1}.a); % already have these alphas
% Thanks to E. Prudencio for pointing out an error here
  a1 = a1*(1-alphafun(varargin{1:(kk+1)}));
  a2 = a2*(1-alphafun(varargin{(stage+1):-1:(stage+1-kk)}));
  if  a2==0  % we will came back with prob 1
    y = 0;
    return
  end
end
y = lfun(varargin{1},varargin{end});
for kk=1:stage
  y = y + qfun(kk,varargin{:});
end
y = min(1, exp(y).*a2./a1);

end
%************************************************************%
function z=qfun(iq,varargin)
% Gaussian n:th stage log proposal ratio
% log of q_i(y_n,..,y_n-j) / q_i(x,y_1,...,y_j)

% % ----------------------------------
% % Try to pre set variables to get past 'non constant expression'
% % error in coder.....
% coder.varsize('y1',[100 100]);
% coder.varsize('y2',[100 100]);
% coder.varsize('y3',[100 100]);
% coder.varsize('y4',[100 100]);
% coder.varsize('z',[100 100]);
% coder.varsize('iR',[100,100]);
% 
% y1 = zeros(1,npar);
% y2 = zeros(1,npar);
% y3 = zeros(1,npar);
% y4 = zeros(1,npar);
% iR = zeros(npar,npar);
% z = 0;
% % -----------------------------

stage = nargin-1-1;
if stage == iq
  z = 0;                                % we are symmetric
else
  iR = invR{iq};                        % proposal^(-1/2)
  y1 = varargin{1}.p;           % y1
  y2 = varargin{iq+1}.p;        % y_i
  y3 = varargin{stage+1}.p;     % y_n
  y4 = varargin{stage-iq+1}.p;  % y_(n-i)
  z = -0.5*(norm((y4-y3)*iR)^2-norm((y2-y1)*iR)^2);
end

end
%************************************************************%
function z=lfun(x,y)
% log posterior ratio,  log( pi(y)/pi(x) * p(y)/p(x) )
z = -0.5*( sum((y.ss./y.s2-x.ss./x.s2)) + y.pri - x.pri );
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

end

function out = priorfun(th,mu,sig)
  out = sum(((th-mu)./sig).^2);
end



