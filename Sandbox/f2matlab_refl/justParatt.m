%function [out,x,sld,nbair,nbsub,ssub,nrepeats,restype]=comp(out,x,sld,nbair,nbsub,ssub,nrepeats,restype(varargin),;


function out = comp(x,sld,nbair,nbsub,nrepeats,ssub,layers,points)

persistent beta blast c0 c1 ci den dummydata g i ihi ilow j lam loop m mi n nl num pair pi pimag plast  preal psub q quo reploop resol rfac rho rij rimaj rough size_ml snair snlay snsub theta thick twopi ; 
% persistent resollayers,points;
 if isempty(size_ml), size_ml=0; end;
 if isempty(i), i=0; end;
 if isempty(layers), layers=0; end;
 if isempty(points), points=0; end;
 if isempty(j), j=0; end;
 if isempty(reploop), reploop=0; end;
 if isempty(c0), c0=0; end;
 if isempty(c1), c1=0; end;
 if isempty(ci), ci=0; end;
 if isempty(beta), beta=0; end;
 if isempty(rij), rij=0; end;
 if isempty(n), n=zeros(2,2); end;
 if isempty(m), m=zeros(2,2); end;
 if isempty(mi), mi=zeros(2,2); end;
 if isempty(rimaj), rimaj=0; end;
 if isempty(blast), blast=0; end;
 if isempty(num), num=0; end;
 if isempty(den), den=0; end;
 if isempty(quo), quo=0; end;
 if isempty(pimag), pimag=0; end;
 if isempty(pair), pair=0; end;
 if isempty(psub), psub=0; end;
 if isempty(plast), plast=0; end;
 if isempty(pi), pi=0; end;
 if isempty(twopi), twopi=0; end;
 if isempty(loop), loop=0; end;
 if isempty(nl), nl=0; end;
 if isempty(lam), lam=0; end;
 if isempty(ilow), ilow=0; end;
 if isempty(ihi), ihi=0; end;
 if isempty(thick), thick=0; end;
 if isempty(q), q=0; end;
 if isempty(theta), theta=0; end;
 if isempty(rho), rho=0; end;
 if isempty(rough), rough=0; end;
 if isempty(resol), resol=0; end;
 if isempty(preal), preal=0; end;
 if isempty(snair), snair=0; end;
 if isempty(snsub), snsub=0; end;
 if isempty(snlay), snlay=0; end;
 if isempty(rfac), rfac=0; end;

x_orig=x;x_shape=[points,1];x=reshape([x_orig(1:min(prod(x_shape),numel(x_orig))),zeros(1,max(0,prod(x_shape)-numel(x_orig)))],x_shape);
sld_orig=sld;sld_shape=[layers,3];sld=reshape([sld_orig(1:min(prod(sld_shape),numel(sld_orig))),zeros(1,max(0,prod(sld_shape)-numel(sld_orig)))],sld_shape);
,nbair,nbsub,ssub;
 if isempty(dummydata), dummydata=zeros(points,1); end;
 if isempty(g), g=zeros(points,1); end;


c0 = complex(0 , 0);
c1 = complex(1 , 0);
ci = complex(0 , 1);
lam = 1.54;
pi = 3.141592653589;
rfac =((4.*pi).*(4.*pi))./2;
twopi = 2.*pi;
snair =(1.0 - real(nbair.*((lam.*lam) ./ twopi)));
snsub =(1.0 - real(nbsub.*((lam.*lam) ./ twopi)));


for loop = 1 : points;
q = x(loop,1);
theta = asin(q.*lam ./(4.*pi));
preal =((snsub).*(snsub)) -((snair).*(snair)).*(cos(theta).^2);
psub = sqrt(preal.*c1);
pair = snair.*sin(theta).*c1;
plast = pair;
blast = 0.0;
rlast = sld(1,3);
mi(1 , 1) = c1;
mi(2 , 2) = c1;
mi(1 , 2) = c0;
mi(2 , 1) = c0;
for reploop = 1: nrepeats;
for nl = 1 : layers;
thick = sld(nl,1);
rho = sld(nl,2);
rough = sld(nl,3);


snlay =(1 - real(rho.*((lam.*lam) ./ twopi)));
preal =(snlay.*snlay) -(snair.*snair) .*cos(theta).^2;
pimag = sqrt(preal.*c1);
beta =(twopi ./ lam).*thick.*pimag;
rij = complex(plast - pimag) ./ complex(plast + pimag);
rij = rij .* exp(-rfac.*plast.*pimag.*(rough.*rough)./(lam.*lam));
n(1 , 1) = exp(blast.*ci);
n(2 , 1) = rij .* exp( - blast.*ci);
n(2 , 2) = exp( - blast.*ci);
n(1 , 2) = rij .* exp(blast.*ci);
plast = pimag;
blast = beta;
rlast = rough;
[mi , m]=mcopy(mi , m);
[m , n , mi]=mmult(m , n , mi);
end; nl = layers+1;
end; reploop = fix(nrepeats+1);
rij =(complex(plast - psub)) ./(complex(plast + psub));
rij = rij .* exp(-rfac.*plast.*psub.*(ssub.*ssub)./(lam.*lam));
n(1 , 1) = exp(blast.*ci);
n(2 , 1) = rij.*exp( - blast.*ci);
n(2 , 2) = exp( - blast.*ci);
n(1 , 2) = rij.*exp(blast.*ci);
[mi , m]=mcopy(mi , m);
[m , n , mi]=mmult(m , n , mi);
num = mi(2 , 1).*conj(mi(2 , 1));
den = mi(1 , 1).*conj(mi(1 , 1));
[num , den , quo]=cdiv(num , den , quo);
out(loop,1) = quo;
end; loop = points+1;


return;
end %subroutine


function [a1 , a2 , a3]=mmult(a1 , a2 , a3,varargin);
% SUBROUTINE FOR MATRIX MUTIPLICATION

a1_orig=a1;a1_shape=[2 , 2];a1=reshape([a1_orig(1:min(prod(a1_shape),numel(a1_orig))),zeros(1,max(0,prod(a1_shape)-numel(a1_orig)))],a1_shape);
a2_orig=a2;a2_shape=[2 , 2];a2=reshape([a2_orig(1:min(prod(a2_shape),numel(a2_orig))),zeros(1,max(0,prod(a2_shape)-numel(a2_orig)))],a2_shape);
a3_orig=a3;a3_shape=[2 , 2];a3=reshape([a3_orig(1:min(prod(a3_shape),numel(a3_orig))),zeros(1,max(0,prod(a3_shape)-numel(a3_orig)))],a3_shape);
a3(1 , 1) = a1(1 , 1).*a2(1 , 1) + a1(1 , 2).*a2(2 , 1);
a3(1 , 2) = a1(1 , 1).*a2(1 , 2) + a1(1 , 2).*a2(2 , 2);
a3(2 , 1) = a1(2 , 1).*a2(1 , 1) + a1(2 , 2).*a2(2 , 1);
a3(2 , 2) = a1(2 , 1).*a2(1 , 2) + a1(2 , 2).*a2(2 , 2);
a1_orig(1:min(prod(a1_shape),numel(a1_orig)))=a1(1:min(prod(a1_shape),numel(a1_orig)));a1=a1_orig;
a2_orig(1:min(prod(a2_shape),numel(a2_orig)))=a2(1:min(prod(a2_shape),numel(a2_orig)));a2=a2_orig;
a3_orig(1:min(prod(a3_shape),numel(a3_orig)))=a3(1:min(prod(a3_shape),numel(a3_orig)));a3=a3_orig;
return;
end
function [a1 , a2]=mcopy(a1 , a2,varargin);
% SUBROUTINE TO COPY A MATRIX

a1_orig=a1;a1_shape=[2 , 2];a1=reshape([a1_orig(1:min(prod(a1_shape),numel(a1_orig))),zeros(1,max(0,prod(a1_shape)-numel(a1_orig)))],a1_shape);
a2_orig=a2;a2_shape=[2 , 2];a2=reshape([a2_orig(1:min(prod(a2_shape),numel(a2_orig))),zeros(1,max(0,prod(a2_shape)-numel(a2_orig)))],a2_shape);
a2(1 , 1) = a1(1 , 1);
a2(1 , 2) = a1(1 , 2);
a2(2 , 1) = a1(2 , 1);
a2(2 , 2) = a1(2 , 2);
a1_orig(1:min(prod(a1_shape),numel(a1_orig)))=a1(1:min(prod(a1_shape),numel(a1_orig)));a1=a1_orig;
a2_orig(1:min(prod(a2_shape),numel(a2_orig)))=a2(1:min(prod(a2_shape),numel(a2_orig)));a2=a2_orig;
return;
end %subroutine

% ----- -----------------------------
function [num , den , quo]=cdiv(num , den , quo,varargin);
% SUBROUTINE TO DIVIDE COMPLEX NUMBERS
% AND TRAP DIVIDE CHECKS
persistent c0 c1 ; 

 if isempty(c1), c1=0; end;
 if isempty(c0), c0=0; end;
c1 = complex(1.0 , 0.0);
c0 = complex(0.0 , 0.0);
if(den==num);
quo = c1;
return;
end;
if(den==c0 );
quo = c0;
return;
end;
quo = num ./ den;
return;
end %subroutine

