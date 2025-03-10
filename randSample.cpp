//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include "coderException.hpp"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void randSample(double numItems, const double weights[2], ::coder::array<
                  double, 2U> &outputSample)
  {
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> randomIndices;
    double bins[3];
    double b_dv[2];
    int loop_ub;

    //  Take a random sample of values.
    //  GPL-licensed replacement for `randsample` from Statistics and Machine
    //  Learning Toolbox.
    //
    //  Note that unweighted sampling is *without* replacement, and weighted
    //  sampling is *with* replacement!
    //
    //  Parameters
    //  ----------
    //  population : vector or a whole number
    //    if a vector, sample k values from the vector.
    //    if an whole number, sample k values from 1:n.
    //  numItems : whole number
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
    for (int i{0}; i < loop_ub; i++) {
      outputSample[i] = static_cast<signed char>(static_cast<int>
        (randomIndices[i]) - 1);
    }
  }

  void randSample(double population_data[], int population_size[2], double
                  numItems, const double weights_data[], ::coder::array<double,
                  2U> &outputSample)
  {
    static const char b_cv1[47]{ 'W', 'e', 'i', 'g', 'h', 't', 's', ' ', 'a',
      'n', 'd', ' ', 'p', 'o', 'p', 'u', 'l', 'a', 't', 'i', 'o', 'n', ' ', 'm',
      'u', 's', 't', ' ', 'b', 'e', ' ', 't', 'h', 'e', ' ', 's', 'a', 'm', 'e',
      ' ', 'l', 'e', 'n', 'g', 't', 'h', '.' };

    ::coder::array<double, 2U> randomIndices;
    ::coder::array<double, 2U> y;
    double bins_data[4];
    double x_data[3];
    int x_size[2];
    int loop_ub;

    //  Take a random sample of values.
    //  GPL-licensed replacement for `randsample` from Statistics and Machine
    //  Learning Toolbox.
    //
    //  Note that unweighted sampling is *without* replacement, and weighted
    //  sampling is *with* replacement!
    //
    //  Parameters
    //  ----------
    //  population : vector or a whole number
    //    if a vector, sample k values from the vector.
    //    if an whole number, sample k values from 1:n.
    //  numItems : whole number
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
      } else {
        double d;
        d = population_data[0];
        y.set_size(1, static_cast<int>(d - 1.0) + 1);
        loop_ub = static_cast<int>(d - 1.0);
        for (int i{0}; i <= loop_ub; i++) {
          y[i] = static_cast<double>(i) + 1.0;
        }
      }

      population_size[1] = y.size(1);
      loop_ub = y.size(1);
      for (int i{0}; i < loop_ub; i++) {
        population_data[i] = y[i];
      }
    }

    if (population_size[1] != 3) {
      char b_cv[47];

      //  Ensures a proper exception is thrown in the generated C++ code.
      //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
      //  and other parameters if message is a formatspec.
      //
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
      for (int i{0}; i < 47; i++) {
        b_cv[i] = b_cv1[i];
      }

      coderException(1.0, &b_cv[0]);
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
    for (int i{0}; i < loop_ub; i++) {
      outputSample[i] = population_data[static_cast<int>(randomIndices[i]) - 1];
    }
  }
}

// End of code generation (randSample.cpp)
