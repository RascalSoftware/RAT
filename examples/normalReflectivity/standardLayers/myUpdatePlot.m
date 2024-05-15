function myUpdatePlot(varargin)

persistent h

if isempty(h)
    h = figure(2);
end

figure(h); 
subplot(1,2,1); cla
subplot(1,2,2); cla
plotRefSLDHelper(varargin{:});

end

