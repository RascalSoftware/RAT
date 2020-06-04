function runFit_yamm

%   Runs an MCMC analysis of a fit to a 
%   D2O calibration using the 'yamm' toolbox.
%   Then, does a direct calculation of the 
%   Posterior distributions on a grid
%   before numerically marginalising.
%   Plots the posteriors together for 
%   comparison.



global verbose
verbose = 1;

addpath('yamm-master/src');


dat = dlmread('f82395c.dat');
data.ydata = dat;
data.debug = 0;

background = 2e-6;
scalefactor = 0.09;
roughness = 5;
pars = [roughness, background,scalefactor];
names = {'roughness', 'background', 'scalefactor'};

lims = [1 7;
        1e-7 1e-5;
        0.07 0.14];

prior = {};
for i = 1:length(names);
    prior{i,1} = names{i};
    prior{i,2} = 'uniform';
    prior{i,3} = lims(i,1);
    prior{i,4} = lims(i,2);
    prior{i,5} = 'cyclic';
end

model = 'not needed';
likelihood= @fitfun;
extraparams =[];

[post_samples, logPsamples] = mcmc_sampler(data, likelihood, ...
          model, prior, extraparams);%'Nstretch',10,'Nmcmc',5000,'temperature',0.5,'NensembleStretch',5);
      

figure(3); clf

for i = 1:3;
    subplot(2,2,i);
    [n,x] = hist(post_samples(:,i),30);
    n = n./ max(n);
    bar(x,n);
end

ng = 30;
roughness = linspace(1,7,ng);
background = linspace(5e-8,7e-6,ng);
scalefac = linspace(0.05,0.15,ng);

problem = getappdata(0,'problem');
data.problem = problem;

for i = 1:ng
    for j = 1:ng
        for k = 1:ng;
            pars = {roughness(i) background(j) scalefac(k)};
            val = fitfun(data,[],[],pars);
            grid(i,j,k) = exp(val);
        end
    end
end

fullgrid = grid;

mask = [1 0 0];
for i = 1:3
    if mask(i) == 0;
        grid = trapz(grid,i);
    end
end
grid = squeeze(grid);
grid = grid / max(grid);
figure(3)
subplot(2,2,1); hold on;
plot(roughness,grid);


grid = fullgrid;
mask = [0 1 0];
for i = 1:3
    if mask(i) == 0;
        grid = trapz(grid,i);
    end
end
grid = squeeze(grid);
grid = grid / max(grid);
figure(3);
subplot(2,2,2); hold on;
plot(background,grid);

grid = fullgrid;
mask = [0 0 1];
for i = 1:3
    if mask(i) == 0;
        grid = trapz(grid,i);
    end
end
grid = squeeze(grid);
grid = grid / max(grid);
figure(3);
subplot(2,2,3); hold on;
plot(scalefac,grid);


end

%-------------------------------------------------------


function chi = fitfun(data,model,parnames,pars);

%debug = 0;

roughness = pars{1};
background = pars{2};
scalefactor = pars{3};

dat = data.ydata;
debug = data.debug;

xdata = dat(:,1);
ydata = dat(:,2)./scalefactor;
error = dat(:,3)./scalefactor;

%simRef = abeles_loop_2(simXdata(:),slds(:),nbairs(:),nbsubs(:), repeats(:), resolutions(:), ssubs(:));
xdata = {xdata'};
sld = {[0 0 0]};

Fit = abeles_loop_2(xdata(:),sld,0,6.35e-6,1,0.01,roughness);
%Fit = abeles_new_2(xdata,[0 0 0],0,6.35e-6,roughness,1,1,0.01);
Fit = Fit{:};
Fit = Fit + background;
%chi = (1/length(ydata)-3)*sum(((ydata-Fit)./error).^2);
chi = chi_squared(Fit,ydata,3,error);
chi = -chi/2;

switch debug
    case 1
        figure(1)
        clf
        errorbar(xdata,ydata,error,'bo');
        hold on
        plot(xdata,Fit,'k-');
        set(gca,'YScale','log')
        set(gca,'XScale','log')
        hold off
        drawnow
end

end





function chi2 = chi_squared(fit,y,P,eb)

N = max(size(y));
if N <= P
    N = (P + 1);
end
terms = ((y-fit)./eb).^2;
n = find(terms == Inf);
terms(n) = 0;
chi2 = 1/(N-P)*sum(terms);


end