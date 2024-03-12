//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// boundaryHandling.cpp
//
// Code generation for function 'boundaryHandling'
//

// Include files
#include "boundaryHandling.h"
#include "find.h"
#include "rand.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void boundaryHandling(::coder::array<real_T, 2U> &x, const ::coder::array<
                        real_T, 2U> &Par_info_min, const ::coder::array<real_T,
                        2U> &Par_info_max, const char_T
                        Par_info_boundhandling_data[], const int32_T
                        Par_info_boundhandling_size[2])
  {
    ::coder::array<real_T, 2U> max_d;
    ::coder::array<real_T, 2U> min_d;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 1U> b_max_d;
    ::coder::array<int32_T, 1U> ii_low;
    ::coder::array<int32_T, 1U> ii_up;
    ::coder::array<boolean_T, 2U> b_x;
    real_T b_ii_low[2];
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;

    //  Function to check whether parameter values remain within prior bounds
    //  First determine the size of new
    //  Now replicate min and max
    coder::repmat(Par_info_min, static_cast<real_T>(x.size(0)), min_d);
    coder::repmat(Par_info_max, static_cast<real_T>(x.size(0)), max_d);

    //  Now find which elements of x are smaller than their respective bound
    b_x.set_size(x.size(0), x.size(1));
    loop_ub = x.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = x.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_x[i1 + b_x.size(0) * i] = (x[i1 + x.size(0) * i] < min_d[i1 +
          min_d.size(0) * i]);
      }
    }

    coder::c_eml_find(b_x, ii_up);
    ii_low.set_size(ii_up.size(0));
    loop_ub = ii_up.size(0);
    for (i = 0; i < loop_ub; i++) {
      ii_low[i] = ii_up[i];
    }

    //  Now find which elements of x are larger than their respective bound
    b_x.set_size(x.size(0), x.size(1));
    loop_ub = x.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = x.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_x[i1 + b_x.size(0) * i] = (x[i1 + x.size(0) * i] > max_d[i1 +
          max_d.size(0) * i]);
      }
    }

    coder::c_eml_find(b_x, ii_up);

    //  Reflection
    if (coder::internal::x_strcmp(Par_info_boundhandling_data,
         Par_info_boundhandling_size)) {
      //  reflect in min
      b_max_d.set_size(ii_low.size(0));
      loop_ub = ii_low.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_max_d[i] = 2.0 * min_d[ii_low[i] - 1] - x[ii_low[i] - 1];
      }

      loop_ub = b_max_d.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[ii_low[i] - 1] = b_max_d[i];
      }

      //  reflect in max
      b_max_d.set_size(ii_up.size(0));
      loop_ub = ii_up.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_max_d[i] = 2.0 * max_d[ii_up[i] - 1] - x[ii_up[i] - 1];
      }

      loop_ub = b_max_d.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[ii_up[i] - 1] = b_max_d[i];
      }
    }

    //  Bound
    if (coder::internal::y_strcmp(Par_info_boundhandling_data,
         Par_info_boundhandling_size)) {
      //  set lower values to min
      loop_ub = ii_low.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[ii_low[i] - 1] = min_d[ii_low[i] - 1];
      }

      //  set upper values to max
      loop_ub = ii_up.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[ii_up[i] - 1] = max_d[ii_up[i] - 1];
      }
    }

    //  Folding
    if (coder::internal::ab_strcmp(Par_info_boundhandling_data,
         Par_info_boundhandling_size)) {
      //  Fold parameter space lower values
      b_max_d.set_size(ii_low.size(0));
      loop_ub = ii_low.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_max_d[i] = max_d[ii_low[i] - 1] - (min_d[ii_low[i] - 1] - x[ii_low[i]
          - 1]);
      }

      loop_ub = b_max_d.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[ii_low[i] - 1] = b_max_d[i];
      }

      //  Fold parameter space upper values
      b_max_d.set_size(ii_up.size(0));
      loop_ub = ii_up.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_max_d[i] = min_d[ii_up[i] - 1] + (x[ii_up[i] - 1] - max_d[ii_up[i] - 1]);
      }

      loop_ub = b_max_d.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[ii_up[i] - 1] = b_max_d[i];
      }
    }

    //  Now double check in case elements are still out of bound -- this is
    //  theoretically possible if values are very small or large
    //  Now double check if all elements are within bounds
    b_x.set_size(x.size(0), x.size(1));
    loop_ub = x.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = x.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_x[i1 + b_x.size(0) * i] = (x[i1 + x.size(0) * i] < min_d[i1 +
          min_d.size(0) * i]);
      }
    }

    coder::c_eml_find(b_x, ii_up);
    ii_low.set_size(ii_up.size(0));
    loop_ub = ii_up.size(0);
    for (i = 0; i < loop_ub; i++) {
      ii_low[i] = ii_up[i];
    }

    b_ii_low[0] = ii_low.size(0);
    b_ii_low[1] = 1.0;
    coder::b_rand(b_ii_low, r);
    loop_ub = ii_low.size(0);
    for (i = 0; i < loop_ub; i++) {
      x[ii_low[i] - 1] = min_d[ii_low[i] - 1] + r[i] * (max_d[ii_low[i] - 1] -
        min_d[ii_low[i] - 1]);
    }

    b_x.set_size(x.size(0), x.size(1));
    loop_ub = x.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = x.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_x[i1 + b_x.size(0) * i] = (x[i1 + x.size(0) * i] > max_d[i1 +
          max_d.size(0) * i]);
      }
    }

    coder::c_eml_find(b_x, ii_up);
    b_ii_low[0] = ii_up.size(0);
    b_ii_low[1] = 1.0;
    coder::b_rand(b_ii_low, r);
    loop_ub = ii_up.size(0);
    for (i = 0; i < loop_ub; i++) {
      x[ii_up[i] - 1] = min_d[ii_up[i] - 1] + r[i] * (max_d[ii_up[i] - 1] -
        min_d[ii_up[i] - 1]);
    }
  }
}

// End of code generation (boundaryHandling.cpp)
