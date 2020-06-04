function runFit_MCMCstat

%   Runs an MCMC analysis of a fit to a
%   D2O calibration using the MCMC stat.
%   Then, does a direct calculation of the
%   Posterior distributions on a grid
%   before numerically marginalising.
%   Plots the posteriors together for
%   comparison.

clear

global verbose
verbose = 1;

addpath('mcmcstat');

dat = dlmread('f82395c.dat');
data.xdata = dat(:,1);
data.ydata = dat(:,2);
data.sigma = dat(:,3);

background = 2e-6;
scalefactor = 0.09;
roughness = 5;
params = {
    {'Roughness', 4, 0}
    {'Background', 1e-7, 0}
    {'Scalefactor', 0.1,0}
    };
fitNames = {'roughness', 'background', 'scalefactor'};

lims = [1 7;
    1e-7 1e-5;
    0.07 0.14];

%First deal with priors.
%Make uniform priors from the
%min/max limits for now.
prior = {};

for i = 1:length(fitNames)
    prior{i,1} = fitNames{i};
    prior{i,2} = 'uniform';
    prior{i,3} = lims(i,1);
    prior{i,4} = lims(i,2);
    prior{i,5} = 0;
    prior{i,6} = Inf;
    thisGroup = {fitNames{i}, 'uniform', lims(i,1), lims(i,2), 0,Inf};
    prior{i} = [thisGroup{1}];
end

options.nsimu = 7000;


%Tuning Parameters - fixed for now
model.ssfun = @MCMC_Intrafun;
% Nlive = 5000;% controls.Nlive;
% tolerance = 1;
% likelihood = @NS_Intrafun;
% %model = problemDef_cells;
% Nmcmc = 200;% controls.nmcmc;
%data = {problemDef ; controls ; problemDef_limits ; problemDef_cells};

res = [];
for i = 1:3;
    [res,chain,s2chain,sschain] = mcmcrun(model, data, params, options, res);
end

figure(3); clf

for i = 1:3
    subplot(2,2,i);
    [n,x] = hist(chain(:,i),30);
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
        for k = 1:ng
            pars = [roughness(i), background(j), scalefac(k)];
            %val = fitfun(data,[],[],pars);
            val = MCMC_Intrafun(pars,data);
            val = val / -2;
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

legend({'MCMC','DirectCalculation'});


end

%-------------------------------------------------------
function LogLike = MCMC_Intrafun(pars,data)


%First calculate chisquared

chisq = fitfun(data,[],[],pars);
LogLike = log(exp(-chisq/2));
LogLike = -2*LogLike;

end


%---------------------------------------------------------




function chi = fitfun(data,model,parnames,pars)

debug = 0;

roughness = pars(1);
background = pars(2);
scalefactor = pars(3);

dat = data.ydata;

xdata = data.xdata;%dat(:,1);
ydata = data.ydata./scalefactor;
error = data.sigma./scalefactor;

%simRef = abeles_loop_2(simXdata(:),slds(:),nbairs(:),nbsubs(:), repeats(:), resolutions(:), ssubs(:));
xdata = {xdata'};
sld = {[0 0 0]};

Fit = abeles_loop_2(xdata(:),sld,0,6.35e-6,1,0.01,roughness);
%Fit = abeles_new_2(xdata,[0 0 0],0,6.35e-6,roughness,1,1,0.01);
Fit = Fit{:};
Fit = Fit + background;
%chi = (1/length(ydata)-3)*sum(((ydata-Fit)./error).^2);
chi = chi_squared(Fit,ydata,3,error);


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