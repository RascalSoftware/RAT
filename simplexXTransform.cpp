//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// simplexXTransform.cpp
//
// Code generation for function 'simplexXTransform'
//

// Include files
#include "simplexXTransform.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void simplexXTransform(const ::coder::array<double, 1U> &x, const ::coder::
    array<double, 1U> &params_LB, const ::coder::array<double, 1U> &params_UB,
    const ::coder::array<double, 1U> &params_BoundClass, ::coder::array<double,
    1U> &xtrans)
  {
    int loop_ub;

    //  Convert unconstrained variables into their original domains.
    //
    //  Parameters
    //  ----------
    //  x : vector
    //      The point to transform.
    //  params : struct
    //      Parameter fit information.
    //
    //  Returns
    //  -------
    //  xtrans : vector
    //      The point ``x`` transformed for the parameter bounds.
    //
    xtrans.set_size(x.size(0));
    loop_ub = x.size(0);
    for (int i{0}; i < loop_ub; i++) {
      xtrans[i] = x[i];
      switch (static_cast<int>(params_BoundClass[i])) {
       case 1:
        //  lower bound only
        xtrans[i] = params_LB[i] + x[i] * x[i];
        break;

       case 2:
        //  upper bound only
        xtrans[i] = params_UB[i] - x[i] * x[i];
        break;

       case 3:
        //  lower and upper bounds
        xtrans[i] = 0.5 * (std::sin(x[i]) + 1.0) * (params_UB[i] - params_LB[i])
          + params_LB[i];
        break;

       default:
        //  unconstrained variable. xtrans(i) is set.
        break;
      }
    }
  }
}

// End of code generation (simplexXTransform.cpp)
