//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// discretize.cpp
//
// Code generation for function 'discretize'
//

// Include files
#include "discretize.h"
#include "bsearch.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_discretize(const ::coder::array<double, 2U> &x, const double
                      edgesInput[3], ::coder::array<double, 2U> &bins)
    {
      int i;
      int nx;
      bins.set_size(1, x.size(1));
      nx = x.size(1);
      for (i = 0; i < nx; i++) {
        bins[i] = rtNaN;
      }

      nx = x.size(1);
      for (int k{0}; k < nx; k++) {
        double bGuess;
        double d;
        d = x[k];
        bGuess = std::ceil(d / edgesInput[1]);
        if ((bGuess >= 1.0) && (bGuess < 3.0)) {
          i = static_cast<int>(bGuess);
          if ((d >= edgesInput[i - 1]) && (d < edgesInput[i])) {
            bins[k] = bGuess;
          } else {
            bins[k] = internal::c_bsearch(edgesInput, d);
          }
        } else {
          bins[k] = internal::c_bsearch(edgesInput, d);
        }
      }
    }

    void discretize(const ::coder::array<double, 2U> &x, const double
                    edgesInput_data[], ::coder::array<double, 2U> &bins)
    {
      double delta;
      double leftEdge;
      int i;
      int nx;
      bins.set_size(1, x.size(1));
      nx = x.size(1);
      for (i = 0; i < nx; i++) {
        bins[i] = rtNaN;
      }

      nx = x.size(1);
      leftEdge = edgesInput_data[0];
      delta = edgesInput_data[1] - edgesInput_data[0];
      for (int k{0}; k < nx; k++) {
        double d;
        d = x[k];
        if ((d >= leftEdge) && (d <= edgesInput_data[3])) {
          double bGuess;
          bGuess = std::ceil((d - leftEdge) / delta);
          if ((bGuess >= 1.0) && (bGuess < 4.0)) {
            i = static_cast<int>(bGuess);
            if ((d >= edgesInput_data[i - 1]) && (d < edgesInput_data[i])) {
              bins[k] = bGuess;
            } else {
              bins[k] = internal::b_bsearch(edgesInput_data, d);
            }
          } else {
            bins[k] = internal::b_bsearch(edgesInput_data, d);
          }
        }
      }
    }
  }
}

// End of code generation (discretize.cpp)
