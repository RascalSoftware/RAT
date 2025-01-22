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

  % if the user is trying to get multiple items from a single-integer array,
  % assume that they want to sample between 1 and n
  if isscalar(population) && numItems > 1
    population = 1:population;
  end

  nargs = nargin;

  if nargs > 3
    error("Too many arguments.")
  end

  if nargs == 3

    if length(weights) ~= length(population)
      error("Weights and population must be the same length.")
    end

    % we generate weighted random integers by creating bins from our weights
    % and discretizing random numbers in [0, 1] to those bins
    weights = normalize(weights, 'norm', 1);
    bins = [0, cumsum(weights)];
    bins(end) = 1;  % ensure final bin is 1 as normalize is not always exact

    randomIndices = discretize(rand(1, numItems), bins);

    outputSample = population(randomIndices);

  % we can generate unweighted numbers far more efficiently
  % just randomise the array and return the first numItems items
  else
    if numItems > length(population)
      error("numItems is larger than the number of items in the population.")
    end
      population = population(randperm(length(population)));
      outputSample = population(1:numItems);
  end
end
