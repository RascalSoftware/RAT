//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// randSample.cpp
//
// Code generation for function 'randSample'
//

// Include files
#include "randSample.h"
#include "discretize.h"
#include "normalize.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void randSample(real_T numItems, const real_T weights[2], ::coder::array<
                  real_T, 2U> &outputSample)
  {
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 2U> randomIndices;
    real_T bins[3];
    real_T b_dv[2];
    int32_T loop_ub;

    //  Take a random sample of values.
    //  GPL-licensed replacement for `randsample` from Statistics and Machine
    //  Learning Toolbox.
    //
    //  Note that unweighted sampling is *without* replacement, and weighted
    //  sampling is *with* replacement!
    //
    //  Parameters
    //  ----------
    //  population : vector or int
    //    if a vector, sample k values from the vector.
    //    if an int, sample k values from 1:n.
    //  numItems : int
    //    the number of items to sample.
    //  weights : vector, optional
    //    a weight vector, where the i'th index of ``weights`` is the
    //    weight for the i'th member of the population.
    //
    //  Returns
    //  -------
    //  outputSample : vector
    //    The resulting sample of values.
    //
    //  if the user is trying to get multiple items from a single-integer array,
    //  assume that they want to sample between 1 and n
    //  we generate weighted random integers with replacement by creating bins from our weights
    //  and discretizing random numbers in [0, 1] to those bins
    bins[0] = 0.0;
    coder::normalize(weights, b_dv);
    bins[1] = b_dv[0];
    bins[2] = 1.0;

    //  ensure final bin is 1 as normalize is not always exact
    coder::b_rand(numItems, r);
    coder::b_discretize(r, bins, randomIndices);
    outputSample.set_size(1, randomIndices.size(1));
    loop_ub = randomIndices.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      outputSample[i] = static_cast<int8_T>(static_cast<int32_T>(randomIndices[i])
        - 1);
    }
  }

  void randSample(real_T population_data[], const int32_T population_size[2],
                  real_T numItems, const real_T weights_data[], ::coder::array<
                  real_T, 2U> &outputSample)
  {
    ::coder::array<real_T, 2U> randomIndices;
    ::coder::array<real_T, 2U> y;
    real_T bins_data[4];
    real_T x_data[3];
    int32_T x_size[2];
    int32_T i;
    int32_T loop_ub;

    //  Take a random sample of values.
    //  GPL-licensed replacement for `randsample` from Statistics and Machine
    //  Learning Toolbox.
    //
    //  Note that unweighted sampling is *without* replacement, and weighted
    //  sampling is *with* replacement!
    //
    //  Parameters
    //  ----------
    //  population : vector or int
    //    if a vector, sample k values from the vector.
    //    if an int, sample k values from 1:n.
    //  numItems : int
    //    the number of items to sample.
    //  weights : vector, optional
    //    a weight vector, where the i'th index of ``weights`` is the
    //    weight for the i'th member of the population.
    //
    //  Returns
    //  -------
    //  outputSample : vector
    //    The resulting sample of values.
    //
    //  if the user is trying to get multiple items from a single-integer array,
    //  assume that they want to sample between 1 and n
    if ((population_size[1] == 1) && (numItems > 1.0)) {
      if (std::isnan(population_data[0])) {
        y.set_size(1, 1);
        y[0] = rtNaN;
      } else if (population_data[0] < 1.0) {
        y.set_size(1, 0);
      } else if (std::isinf(population_data[0]) && (1.0 == population_data[0]))
      {
        y.set_size(1, 1);
        y[0] = rtNaN;
      } else {
        loop_ub = static_cast<int32_T>(std::floor(population_data[0] - 1.0));
        y.set_size(1, loop_ub + 1);
        for (i = 0; i <= loop_ub; i++) {
          y[i] = static_cast<real_T>(i) + 1.0;
        }
      }

      loop_ub = y.size(1);
      for (i = 0; i < loop_ub; i++) {
        population_data[i] = y[i];
      }
    }

    //  we generate weighted random integers with replacement by creating bins from our weights
    //  and discretizing random numbers in [0, 1] to those bins
    coder::normalize(weights_data, x_data, x_size);
    x_data[1] += x_data[0];
    bins_data[0] = 0.0;
    bins_data[1] = x_data[0];
    bins_data[2] = x_data[1];
    bins_data[3] = 1.0;

    //  ensure final bin is 1 as normalize is not always exact
    coder::b_rand(numItems, y);
    coder::discretize(y, bins_data, randomIndices);
    outputSample.set_size(1, randomIndices.size(1));
    loop_ub = randomIndices.size(1);
    for (i = 0; i < loop_ub; i++) {
      outputSample[i] = population_data[static_cast<int32_T>(randomIndices[i]) -
        1];
    }
  }
}

// End of code generation (randSample.cpp)
