//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
  void simplexXTransform(const ::coder::array<real_T, 1U> &x, const ::coder::
    array<real_T, 1U> &params_LB, const ::coder::array<real_T, 1U> &params_UB,
    const ::coder::array<real_T, 1U> &params_BoundClass, ::coder::array<real_T,
    1U> &xtrans)
  {
    int32_T i;
    int32_T loop_ub;

    //  converts unconstrained variables into their original domains
    xtrans.set_size(x.size(0));
    loop_ub = x.size(0);
    for (i = 0; i < loop_ub; i++) {
      xtrans[i] = x[i];
    }

    i = x.size(0);
    for (int32_T b_i{0}; b_i < i; b_i++) {
      switch (static_cast<int32_T>(params_BoundClass[b_i])) {
       case 1:
        //  lower bound only
        xtrans[b_i] = params_LB[b_i] + x[b_i] * x[b_i];
        break;

       case 2:
        //  upper bound only
        xtrans[b_i] = params_UB[b_i] - x[b_i] * x[b_i];
        break;

       case 3:
        //  lower and upper bounds
        xtrans[b_i] = (std::sin(x[b_i]) + 1.0) / 2.0;
        xtrans[b_i] = xtrans[b_i] * (params_UB[b_i] - params_LB[b_i]) +
          params_LB[b_i];
        break;

       default:
        //  unconstrained variable. xtrans(i) is set.
        break;
      }
    }
  }
}

// End of code generation (simplexXTransform.cpp)
