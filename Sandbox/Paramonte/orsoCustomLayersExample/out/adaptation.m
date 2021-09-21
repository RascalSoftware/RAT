

fname = "ParaDRAM_run_20210917_103505_778_process_1_chain.txt";

pm = paramonte();
pmpd = pm.ParaDRAM();
chainList = pmpd.readChain(fname);
chain = chainList{1}; % Choose the contents of the read chain file in the list (in your case, there is likely only one simulation file).
chain.plot.scatter.ycolumns = "AdaptationMeasure"; ... Choose the AdaptationMeasure column of the output chain file to plot.
chain.plot.scatter.ccolumns = []; % Set the color of the points to empty from the default logLikelihood value.
chain.plot.scatter.make();
set(gca,"yscale","log");
xlabel("MCMC Sample Count");
ylabel("Proposal Adaptation Measure");