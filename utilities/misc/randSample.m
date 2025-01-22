function outputSample = randSample(population, numItems, weights)
  % Take a random sample of values.
  % 
  % Parameters
  % ----------
  % population : vector or int
  %   if a vector, sample k values from the vector without replacement.
  %   if an int, sample k values from 1:n without replacement.
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

  if numItems > length(population)
    error("numItems is larger than the number of items in the population.")
  end

  % create vector for results
  outputSample = zeros(1, numItems);

  if nargs == 3

    if length(weights) ~= length(population)
      error("Weights and population must be the same length.")
    end

    for i = 1:numItems
      % we generate weighted random integers by creating bins from our weights
      % and discretizing a random number in [0, 1] to those bins
      weights = normalize(weights, 'norm', 1);
      bins = [0, cumsum(weights)];
      bins(end) = 1;  % ensure final bin is 1 as normalize is not always exact

      randomIndex = discretize(rand(1), bins);

      outputSample(i) = population(randomIndex);
      population(randomIndex) = [];
      weights(randomIndex) = [];
    end

  % we can generate unweighted numbers far more efficiently
  else
    % for large numbers of items it's more efficient to randomise the array
    % and return the first numItems items
    if 4*numItems > length(population)
      population = population(randperm(length(population)));
      outputSample = population(1:numItems);
    % else, just generate random integers and pick items from the population
    else
      for i = 1:numItems
        randomIndex = randi(length(population));
        outputSample(i) = population(randomIndex);
        population(randomIndex) = [];
      end
    end

  end
end

