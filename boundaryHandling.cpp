//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<int, 1U> &in2, const ::coder::array<double, 2U> &in3, const ::coder::
    array<double, 1U> &in4, const ::coder::array<double, 2U> &in5);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<int, 1U> &in2, const ::coder::array<double, 2U> &in3, const ::coder::
    array<double, 1U> &in4, const ::coder::array<double, 2U> &in5)
  {
    int loop_ub_tmp;
    int stride_0_0_tmp;
    int stride_1_0;
    stride_0_0_tmp = (in2.size(0) != 1);
    stride_1_0 = (in4.size(0) != 1);
    if (in2.size(0) == 1) {
      loop_ub_tmp = in4.size(0);
    } else {
      loop_ub_tmp = in2.size(0);
    }

    if (loop_ub_tmp == 1) {
      loop_ub_tmp = in2.size(0);
    }

    for (int i{0}; i < loop_ub_tmp; i++) {
      int i1;
      i1 = in2[i * stride_0_0_tmp] - 1;
      in1[in2[i] - 1] = in3[i1] + in4[i * stride_1_0] * (in5[i1] - in3[i1]);
    }
  }

  void boundaryHandling(::coder::array<double, 2U> &x, const ::coder::array<
                        double, 2U> &paramInfo_min, const ::coder::array<double,
                        2U> &paramInfo_max, const char
                        paramInfo_boundhandling_data[], const int
                        paramInfo_boundhandling_size[2])
  {
    ::coder::array<double, 2U> min_d;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 1U> b_min_d;
    ::coder::array<int, 1U> ii_low;
    ::coder::array<int, 1U> ii_up;
    ::coder::array<boolean_T, 2U> b_x;
    double b_ii_low[2];
    int b_loop_ub;
    int i;
    int loop_ub;

    //  Check whether parameter values remain within prior bounds, and handle ones outside.
    //
    //  Parameters
    //  ----------
    //  x : array
    //      The parameter values.
    //  paramInfo : struct
    //      Ranges, priors and boundary handling for each parameter.
    //  First determine the size of new
    //  Now replicate min and max
    coder::repmat(paramInfo_min, static_cast<double>(x.size(0)), r);
    min_d.set_size(r.size(0), r.size(1));
    loop_ub = r.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        min_d[i1 + min_d.size(0) * i] = r[i1 + r.size(0) * i];
      }
    }

    coder::repmat(paramInfo_max, static_cast<double>(x.size(0)), r);

    //  Now find which elements of x are smaller than their respective bound
    if ((x.size(0) == min_d.size(0)) && (x.size(1) == min_d.size(1))) {
      b_x.set_size(x.size(0), x.size(1));
      loop_ub = x.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = x.size(0);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          b_x[i1 + b_x.size(0) * i] = (x[i1 + x.size(0) * i] < min_d[i1 +
            min_d.size(0) * i]);
        }
      }

      coder::f_eml_find(b_x, ii_up);
    } else {
      c_binary_expand_op(ii_up, x, min_d);
    }

    ii_low.set_size(ii_up.size(0));
    loop_ub = ii_up.size(0);
    for (i = 0; i < loop_ub; i++) {
      ii_low[i] = ii_up[i];
    }

    //  Now find which elements of x are larger than their respective bound
    if ((x.size(0) == r.size(0)) && (x.size(1) == r.size(1))) {
      b_x.set_size(x.size(0), x.size(1));
      loop_ub = x.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = x.size(0);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          b_x[i1 + b_x.size(0) * i] = (x[i1 + x.size(0) * i] > r[i1 + r.size(0) *
            i]);
        }
      }

      coder::f_eml_find(b_x, ii_up);
    } else {
      binary_expand_op(ii_up, x, r);
    }

    //  Reflection
    if (coder::internal::eb_strcmp(paramInfo_boundhandling_data,
         paramInfo_boundhandling_size)) {
      //  reflect in min
      b_min_d.set_size(ii_low.size(0));
      loop_ub = ii_low.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_min_d[i] = 2.0 * min_d[ii_low[i] - 1] - x[ii_low[i] - 1];
      }

      loop_ub = b_min_d.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[ii_low[i] - 1] = b_min_d[i];
      }

      //  reflect in max
      b_min_d.set_size(ii_up.size(0));
      loop_ub = ii_up.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_min_d[i] = 2.0 * r[ii_up[i] - 1] - x[ii_up[i] - 1];
      }

      loop_ub = b_min_d.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[ii_up[i] - 1] = b_min_d[i];
      }
    }

    //  Bound
    if (coder::internal::fb_strcmp(paramInfo_boundhandling_data,
         paramInfo_boundhandling_size)) {
      //  set lower values to min
      loop_ub = ii_low.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[ii_low[i] - 1] = min_d[ii_low[i] - 1];
      }

      //  set upper values to max
      loop_ub = ii_up.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[ii_up[i] - 1] = r[ii_up[i] - 1];
      }
    }

    //  Folding
    if (coder::internal::gb_strcmp(paramInfo_boundhandling_data,
         paramInfo_boundhandling_size)) {
      //  Fold parameter space lower values
      b_min_d.set_size(ii_low.size(0));
      loop_ub = ii_low.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_min_d[i] = r[ii_low[i] - 1] - (min_d[ii_low[i] - 1] - x[ii_low[i] - 1]);
      }

      loop_ub = b_min_d.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[ii_low[i] - 1] = b_min_d[i];
      }

      //  Fold parameter space upper values
      b_min_d.set_size(ii_up.size(0));
      loop_ub = ii_up.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_min_d[i] = min_d[ii_up[i] - 1] + (x[ii_up[i] - 1] - r[ii_up[i] - 1]);
      }

      loop_ub = b_min_d.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[ii_up[i] - 1] = b_min_d[i];
      }
    }

    //  Now double check in case elements are still out of bound -- this is
    //  theoretically possible if values are very small or large
    //  Now double check if all elements are within bounds
    if ((x.size(0) == min_d.size(0)) && (x.size(1) == min_d.size(1))) {
      b_x.set_size(x.size(0), x.size(1));
      loop_ub = x.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = x.size(0);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          b_x[i1 + b_x.size(0) * i] = (x[i1 + x.size(0) * i] < min_d[i1 +
            min_d.size(0) * i]);
        }
      }

      coder::f_eml_find(b_x, ii_up);
    } else {
      c_binary_expand_op(ii_up, x, min_d);
    }

    ii_low.set_size(ii_up.size(0));
    loop_ub = ii_up.size(0);
    for (i = 0; i < loop_ub; i++) {
      ii_low[i] = ii_up[i];
    }

    b_ii_low[0] = ii_low.size(0);
    b_ii_low[1] = 1.0;
    coder::b_rand(b_ii_low, b_min_d);
    if (b_min_d.size(0) == 1) {
      i = ii_low.size(0);
    } else {
      i = b_min_d.size(0);
    }

    if ((b_min_d.size(0) == ii_low.size(0)) && (ii_low.size(0) == i)) {
      loop_ub = ii_low.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[ii_low[i] - 1] = min_d[ii_low[i] - 1] + b_min_d[i] * (r[ii_low[i] - 1]
          - min_d[ii_low[i] - 1]);
      }
    } else {
      binary_expand_op(x, ii_low, min_d, b_min_d, r);
    }

    if ((x.size(0) == r.size(0)) && (x.size(1) == r.size(1))) {
      b_x.set_size(x.size(0), x.size(1));
      loop_ub = x.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = x.size(0);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          b_x[i1 + b_x.size(0) * i] = (x[i1 + x.size(0) * i] > r[i1 + r.size(0) *
            i]);
        }
      }

      coder::f_eml_find(b_x, ii_up);
    } else {
      binary_expand_op(ii_up, x, r);
    }

    b_ii_low[0] = ii_up.size(0);
    b_ii_low[1] = 1.0;
    coder::b_rand(b_ii_low, b_min_d);
    if (b_min_d.size(0) == 1) {
      i = ii_up.size(0);
    } else {
      i = b_min_d.size(0);
    }

    if ((b_min_d.size(0) == ii_up.size(0)) && (ii_up.size(0) == i)) {
      loop_ub = ii_up.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[ii_up[i] - 1] = min_d[ii_up[i] - 1] + b_min_d[i] * (r[ii_up[i] - 1] -
          min_d[ii_up[i] - 1]);
      }
    } else {
      binary_expand_op(x, ii_up, min_d, b_min_d, r);
    }
  }
}

// End of code generation (boundaryHandling.cpp)
