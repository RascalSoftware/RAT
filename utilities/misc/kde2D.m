% Reference:
% Kernel density estimation via diffusion
% Z. I. Botev, J. F. Grotowski, and D. P. Kroese (2010)
% Annals of Statistics, Volume 38, Number 5, pages 2916-2957.
% from MATLAB File Exchange: https://www.mathworks.com/matlabcentral/fileexchange/17204-kernel-density-estimation
function [bandwidth,density,X,Y]=kde2D(data,n,MIN_XY,MAX_XY)
% Estimate kernel density for two-dimensional data.
%
% fast and accurate state-of-the-art bivariate kernel density estimator
% with diagonal bandwidth matrix. The kernel is assumed to be Gaussian.
% The two bandwidth parameters are chosen optimally without ever
% using/assuming a parametric model for the data or any "rules of thumb".
% Unlike many other procedures, this one is immune to accuracy failures in the estimation of
% multimodal densities with widely separated modes.
%
% Parameters
% ----------
% data : array
%     The N by 2 array of data from which the density estimate is constructed.
% n : int, optional
%     Size of the nxn grid over which density is computed.     
%     Must be a power of two; if not, then it is rounded up (to ``n=2^ceil(log2(n))``).
%     Defaults to 2^8.
% MIN_XY : array, optional
%     The minimum [x, y] over which the density is computed, in format [lower_Xlim, lower_Ylim].
%     The default limit is MIN=min(data,[],1]; range=MAX-MIN; MIN_XY = MIN-range/4
% MAX_XY : array, optional 
%     The maximum [x, y] over which the density is computed, in format [upper_Xlim, upper_Ylim].
%     The default limit is MAX=max(data,[],1]; range=MAX-MIN; MAX_XY = MAX+range/4
% 
% Returns
% -------
% bandwidth : vector
%     The optimal bandwidth in X and Y for a bivariate Gaussian kernel.
% density : vector
%     Column vector with the values of the density estimate at the grid points.
% xmesh : vector
%     The grid over which the density estimate is coputed.
% cdf : vector
%     Column vector with the values of the CDF.
%
% Examples
% --------
% >>> % generate a gaussian mixture with distant modes
%     data=[randn(500,2);
%     randn(500,1)+3.5, randn(500,1);];
%     % call the routine
%     [bandwidth,density,x,y]=kde2d(data);
%     % plot the data and the density estimate
%     contour3(x,y,density,50), hold on
%     plot(data(:,1),data(:,2),'r.','markersize',5)
%
% >>> % generate a gaussian mixture with distant modes
%     data=[randn(100,1), randn(100,1)/4;
%     randn(100,1)+18, randn(100,1);
%     randn(100,1)+15, randn(100,1)/2-18;];
%     % call the routine
%     [bandwidth,density,x,y]=kde2d(data);
%     % plot the data and the density estimate
%     surf(x,y,density,'linestyle','none'), view([0,60])
%     colormap hot, hold on, alpha(.8)
%     set(gca, 'color', 'blue');
%     plot(data(:,1),data(:,2),'w.','markersize',5)
%
% >>> x=rand(1000,1); y=sin(x*10*pi)+randn(size(x))/3; data=[x,y];
%     % apply routine
%     [bandwidth,density,x,y]=kde2d(data);
%     % plot the data and the density estimate
%     surf(x,y,density,'linestyle','none'), view([0,70])
%     colormap hot, hold on, alpha(.8)
%     set(gca, 'color', 'blue');
%     plot(data(:,1),data(:,2),'w.','markersize',5)
%
global N A2 I
if nargin<2
    n=2^8;
end
n=2^ceil(log2(n)); % round up n to the next power of 2;
N=size(data,1);
if nargin<3
    MAX=max(data,[],1); MIN=min(data,[],1); Range=MAX-MIN;
    MAX_XY=MAX+Range/2; MIN_XY=MIN-Range/2;
end
scaling=MAX_XY-MIN_XY;
if N<=size(data,2)
    error('data has to be an N by 2 array where each row represents a two dimensional observation')
end
transformed_data=(data-repmat(MIN_XY,N,1))./repmat(scaling,N,1);
%bin the data uniformly using regular grid;
initial_data=ndhist(transformed_data,n);
% discrete cosine transform of initial data
a= dct2d(initial_data);
% now compute the optimal bandwidth^2
  I=(0:n-1).^2; A2=a.^2;
 t_star=root(@(t)(t-evolve(t)),N);
p_02=func([0,2],t_star);p_20=func([2,0],t_star); p_11=func([1,1],t_star);
t_y=(p_02^(3/4)/(4*pi*N*p_20^(3/4)*(p_11+sqrt(p_20*p_02))))^(1/3);
t_x=(p_20^(3/4)/(4*pi*N*p_02^(3/4)*(p_11+sqrt(p_20*p_02))))^(1/3);
% smooth the discrete cosine transform of initial data using t_star
a_t=exp(-(0:n-1)'.^2*pi^2*t_x/2)*exp(-(0:n-1).^2*pi^2*t_y/2).*a; 
% now apply the inverse discrete cosine transform
if nargout>1
    density=idct2d(a_t)*(numel(a_t)/prod(scaling));
	density(density<0)=eps; % remove any negative density values
    [X,Y]=meshgrid(MIN_XY(1):scaling(1)/(n-1):MAX_XY(1),MIN_XY(2):scaling(2)/(n-1):MAX_XY(2));
end
bandwidth=sqrt([t_x,t_y]).*scaling; 
end
%#######################################
function  [out,time]=evolve(t)
global N
Sum_func = func([0,2],t) + func([2,0],t) + 2*func([1,1],t);
time=(2*pi*N*Sum_func)^(-1/3);
out=(t-time)/time;
end
%#######################################
function out=func(s,t)
global N
if sum(s)<=4
    Sum_func=func([s(1)+1,s(2)],t)+func([s(1),s(2)+1],t); const=(1+1/2^(sum(s)+1))/3;
    time=(-2*const*K(s(1))*K(s(2))/N/Sum_func)^(1/(2+sum(s)));
    out=psi(s,time);
else
    out=psi(s,t);
end
end
%#######################################
function out=psi(s,Time)
global I A2
% s is a vector
w=exp(-I*pi^2*Time).*[1,.5*ones(1,length(I)-1)];
wx=w.*(I.^s(1));
wy=w.*(I.^s(2));
out=(-1)^sum(s)*(wy*A2*wx')*pi^(2*sum(s));
end
%#######################################
function out=K(s)
out=(-1)^s*prod((1:2:2*s-1))/sqrt(2*pi);
end
%#######################################
function data=dct2d(data)
% computes the 2 dimensional discrete cosine transform of data
% data is an nd cube
[nrows,ncols]= size(data);
if nrows~=ncols
    error('data is not a square array!')
end
% Compute weights to multiply DFT coefficients
w = [1;2*(exp(-i*(1:nrows-1)*pi/(2*nrows))).'];
weight=w(:,ones(1,ncols));
data=dct1d(dct1d(data)')';
    function transform1d=dct1d(x)
        % Re-order the elements of the columns of x
        x = [ x(1:2:end,:); x(end:-2:2,:) ];
        % Multiply FFT by weights:
        transform1d = real(weight.* fft(x));
    end
end
%#######################################
function data = idct2d(data)
% computes the 2 dimensional inverse discrete cosine transform
[nrows,ncols]=size(data);
% Compute wieghts
w = exp(i*(0:nrows-1)*pi/(2*nrows)).';
weights=w(:,ones(1,ncols));
data=idct1d(idct1d(data)');
    function out=idct1d(x)
        y = real(ifft(weights.*x));
        out = zeros(nrows,ncols);
        out(1:2:nrows,:) = y(1:nrows/2,:);
        out(2:2:nrows,:) = y(nrows:-1:nrows/2+1,:);
    end
end
%#######################################
function binned_data=ndhist(data,M)
% this function computes the histogram
% of an n-dimensional data set;
% 'data' is nrows by n columns
% M is the number of bins used in each dimension
% so that 'binned_data' is a hypercube with
% size length equal to M;
[nrows,ncols]=size(data);
bins=zeros(nrows,ncols);
for i=1:ncols
    [dum,bins(:,i)] = histc(data(:,i),[0:1/M:1],1);
    bins(:,i) = min(bins(:,i),M);
end
% Combine the  vectors of 1D bin counts into a grid of nD bin
% counts.
binned_data = accumarray(bins(all(bins>0,2),:),1/nrows,M(ones(1,ncols)));
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function t=root(f,N)
% try to find smallest root whenever there is more than one
N=50*(N<=50)+1050*(N>=1050)+N*((N<1050)&(N>50));
tol=10^-12+0.01*(N-50)/1000;
flag=0;
while flag==0
    try
        t=fzero(f,[0,tol]);
        flag=1;
    catch
        tol=min(tol*2,.1); % double search interval
    end
    if tol==.1 % if all else fails
        t=fminbnd(@(x)abs(f(x)),0,.1); flag=1;
    end
end
end
