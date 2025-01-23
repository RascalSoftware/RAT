function plotChain(results)
  % convenience function for nicer chain plots

  mcmcplot(results.chain, [], results.fitNames, 'chainpanel')

end
