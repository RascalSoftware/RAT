//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// resolutionPolly.cpp
//
// Code generation for function 'resolutionPolly'
//

// Include files
#include "resolutionPolly.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void resolutionPolly(const ::coder::array<double, 1U> &xdata, const ::coder::
                       array<double, 1U> &rawSimulation, const ::coder::array<
                       double, 1U> &resolutionValues, double points, ::coder::
                       array<double, 1U> &simulation)
  {
    int i;
    int loop_ub_tmp;

    //  Apply resolution correction
    loop_ub_tmp = static_cast<int>(points);
    simulation.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      simulation[i] = 0.0;
    }

    for (int j{0}; j < loop_ub_tmp; j++) {
      double sumg;
      int ilow;
      sumg = 0.0;
      ilow = static_cast<int>(std::fmax(-10.0, -(static_cast<double>(j) + 1.0) +
        1.0));
      i = static_cast<int>(std::fmin(10.0, points - (static_cast<double>(j) +
        1.0)) + (1.0 - static_cast<double>(ilow)));
      for (int b_i{0}; b_i < i; b_i++) {
        double a;
        double g;
        int a_tmp;
        a_tmp = static_cast<int>((static_cast<double>(j) + 1.0) + static_cast<
          double>(ilow + b_i)) - 1;
        a = (xdata[a_tmp] - xdata[j]) / (resolutionValues[j] * xdata[j]);
        g = std::exp(-(a * a));
        sumg += g;
        simulation[j] = simulation[j] + rawSimulation[a_tmp] * g;
      }

      simulation[j] = simulation[j] / sumg;
    }
  }
}

// End of code generation (resolutionPolly.cpp)
