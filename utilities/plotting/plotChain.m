function plotChain(result)
    % Plots MCMC chain from the result of a Bayesian RAT calculation.
    % 
    % Parameters
    % ----------
    % result : struct
    %    The result from a Bayesian RAT calculation. 
    
    mcmcplot(result.chain, [], result.fitNames, 'chainpanel')

end
