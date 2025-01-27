function outputSample = randSample(population, numItems, weights)
  % Take a random sample of values.
  % GPL-licensed replacement for `randsample` from Statistics and Machine
  % Learning Toolbox.
  % 
  % Note that unweighted sampling is *without* replacement, and weighted
  % sampling is *with* replacement!
  % 
  % Parameters
  % ----------
  % population : vector or int
  %   if a vector, sample k values from the vector.
  %   if an int, sample k values from 1:n.
  % numItems : int
  %   the number of items to sample.
  % weights : vector
  %   a weight vector, where the i'th index of ``weights`` is the 
  %   weight for the i'th member of the population.
  %
  % Returns
  % -------
  % outputSample : vector
  %   The resulting sample of values.
  %

  % if the user is trying to get multiple items from a single-integer array,
  % assume that they want to sample between 1 and n
  arguments
    population (1,:) double
    numItems int16
    weights (1,:) double = []
  end

  if isscalar(population) && numItems > 1
    population = 1:population;
  end

  if isempty(weights)
    if numItems > length(population)
      coderException(coderEnums.errorCodes.invalidOption, 'numItems is larger than the number of items in the population.')
    end
      % to generate unweighted numbers without replacement, we just randomise
      % the array and take the first numItems items
      population = population(randperm(length(population)));
      outputSample = population(1:numItems);
  else
    if length(weights) ~= length(population)
      coderException(coderEnums.errorCodes.invalidOption, 'Weights and population must be the same length.')
    end

    % we generate weighted random integers by creating bins from our weights
    % and discretizing random numbers in [0, 1] to those bins
    weights = normalize(weights, 'norm', 1);
    bins = [0, cumsum(weights)];
    bins(end) = 1;  % ensure final bin is 1 as normalize is not always exact

    randomIndices = discretize(rand(1, numItems), bins);

    outputSample = population(randomIndices);

  end
end
