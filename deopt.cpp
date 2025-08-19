//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// deopt.cpp
//
// Code generation for function 'deopt'
//

// Include files
#include "deopt.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "hasPlotHandler.h"
#include "ifWhileCond.h"
#include "isRATStopped.h"
#include "leftWin.h"
#include "mergesort.h"
#include "rand.h"
#include "randperm.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "runDE.h"
#include "sprintf.h"
#include "strcmp.h"
#include "triggerEvent.h"
#include "validate_print_arguments.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, int in2, const
    h_struct_T &in3, const ::coder::array<double, 2U> &in4);
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, double in3, const ::coder::array<double, 2U> &in4,
    const ::coder::array<double, 2U> &in5);
  static void c_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, double in3, const ::coder::array<double, 2U> &in4,
    const ::coder::array<double, 2U> &in5);
  static void h_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<boolean_T, 2U> &in3, const ::
    coder::array<double, 2U> &in4, double in5, const ::coder::array<double, 2U>
    &in6, const ::coder::array<double, 2U> &in7, const ::coder::array<boolean_T,
    2U> &in8);
  static void i_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<boolean_T, 2U> &in3, double in4,
    const ::coder::array<double, 2U> &in5, const ::coder::array<double, 2U> &in6,
    const ::coder::array<double, 2U> &in7, const ::coder::array<boolean_T, 2U>
    &in8);
  static void j_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<boolean_T, 2U> &in3, const ::
    coder::array<double, 2U> &in4, const ::coder::array<double, 2U> &in5, const ::
    coder::array<double, 2U> &in6, const ::coder::array<double, 2U> &in7, double
    in8, const ::coder::array<boolean_T, 2U> &in9);
  static void k_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<boolean_T, 2U> &in3, const ::
    coder::array<double, 2U> &in4, const ::coder::array<double, 2U> &in5, const ::
    coder::array<double, 2U> &in6, const ::coder::array<double, 2U> &in7, const ::
    coder::array<boolean_T, 2U> &in8);
  static void l_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<boolean_T, 2U> &in3, const ::
    coder::array<double, 2U> &in4, const ::coder::array<double, 2U> &in5, const ::
    coder::array<double, 2U> &in6, double in7, const ::coder::array<boolean_T,
    2U> &in8);
  static void m_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<boolean_T, 2U> &in3, const ::
    coder::array<boolean_T, 2U> &in4);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, int in2, const
    h_struct_T &in3, const ::coder::array<double, 2U> &in4)
  {
    int loop_ub;
    int stride_0_1_tmp;
    int stride_1_1;
    int stride_2_1;
    stride_0_1_tmp = (in3.FVr_minbound.size(1) != 1);
    stride_1_1 = (in4.size(1) != 1);
    stride_2_1 = (in3.FVr_maxbound.size(1) != 1);
    loop_ub = in1.size(1);
    for (int i{0}; i < loop_ub; i++) {
      double d;
      d = in3.FVr_minbound[i * stride_0_1_tmp];
      in1[in2 + in1.size(0) * i] = d + in4[in4.size(0) * (i * stride_1_1)] *
        (in3.FVr_maxbound[i * stride_2_1] - d);
    }
  }

  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, double in3, const ::coder::array<double, 2U> &in4,
    const ::coder::array<double, 2U> &in5)
  {
    int aux_0_1;
    int aux_1_1;
    int aux_2_1;
    int b_loop_ub;
    int i;
    int loop_ub;
    int stride_0_0;
    int stride_0_1;
    int stride_1_0;
    int stride_1_1;
    int stride_2_0;
    int stride_2_1;
    if (in5.size(0) == 1) {
      i = in4.size(0);
    } else {
      i = in5.size(0);
    }

    if (i == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = i;
    }

    in1.set_size(loop_ub, in1.size(1));
    if (in5.size(1) == 1) {
      i = in4.size(1);
    } else {
      i = in5.size(1);
    }

    if (i == 1) {
      b_loop_ub = in2.size(1);
    } else {
      b_loop_ub = i;
    }

    in1.set_size(in1.size(0), b_loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_0 = (in4.size(0) != 1);
    stride_1_1 = (in4.size(1) != 1);
    stride_2_0 = (in5.size(0) != 1);
    stride_2_1 = (in5.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    aux_2_1 = 0;
    for (i = 0; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        in1[i1 + in1.size(0) * i] = in2[i1 * stride_0_0 + in2.size(0) * aux_0_1]
          + in3 * (in4[i1 * stride_1_0 + in4.size(0) * aux_1_1] - in5[i1 *
                   stride_2_0 + in5.size(0) * aux_2_1]);
      }

      aux_2_1 += stride_2_1;
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }
  }

  static void c_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, double in3, const ::coder::array<double, 2U> &in4,
    const ::coder::array<double, 2U> &in5)
  {
    int aux_0_1;
    int aux_1_1;
    int aux_2_1;
    int aux_3_1_tmp;
    int b_loop_ub;
    int i;
    int loop_ub;
    int stride_0_0_tmp;
    int stride_0_1_tmp;
    int stride_1_0;
    int stride_1_1;
    int stride_2_0;
    int stride_2_1;
    if (in2.size(0) == 1) {
      if (in5.size(0) == 1) {
        i = in4.size(0);
      } else {
        i = in5.size(0);
      }
    } else {
      i = in2.size(0);
    }

    if (i == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = i;
    }

    in1.set_size(loop_ub, in1.size(1));
    if (in2.size(1) == 1) {
      if (in5.size(1) == 1) {
        i = in4.size(1);
      } else {
        i = in5.size(1);
      }
    } else {
      i = in2.size(1);
    }

    if (i == 1) {
      b_loop_ub = in2.size(1);
    } else {
      b_loop_ub = i;
    }

    in1.set_size(in1.size(0), b_loop_ub);
    stride_0_0_tmp = (in2.size(0) != 1);
    stride_0_1_tmp = (in2.size(1) != 1);
    stride_1_0 = (in4.size(0) != 1);
    stride_1_1 = (in4.size(1) != 1);
    stride_2_0 = (in5.size(0) != 1);
    stride_2_1 = (in5.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    aux_2_1 = 0;
    aux_3_1_tmp = 0;
    for (i = 0; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        double d;
        d = in2[i1 * stride_0_0_tmp + in2.size(0) * aux_0_1];
        in1[i1 + in1.size(0) * i] = d + in3 * ((in4[i1 * stride_1_0 + in4.size(0)
          * aux_1_1] + in5[i1 * stride_2_0 + in5.size(0) * aux_2_1]) - 2.0 * d);
      }

      aux_3_1_tmp += stride_0_1_tmp;
      aux_2_1 += stride_2_1;
      aux_1_1 += stride_1_1;
      aux_0_1 = aux_3_1_tmp;
    }
  }

  static void h_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<boolean_T, 2U> &in3, const ::
    coder::array<double, 2U> &in4, double in5, const ::coder::array<double, 2U>
    &in6, const ::coder::array<double, 2U> &in7, const ::coder::array<boolean_T,
    2U> &in8)
  {
    int aux_0_1;
    int aux_1_1;
    int aux_2_1;
    int aux_3_1;
    int aux_4_1;
    int aux_5_1;
    int b_loop_ub;
    int i;
    int loop_ub;
    int stride_0_0;
    int stride_0_1;
    int stride_1_0;
    int stride_1_1;
    int stride_2_0;
    int stride_2_1;
    int stride_3_0;
    int stride_3_1;
    int stride_4_0;
    int stride_4_1;
    int stride_5_0;
    int stride_5_1;
    if (in7.size(0) == 1) {
      i = in6.size(0);
    } else {
      i = in7.size(0);
    }

    if (in8.size(0) == 1) {
      if (i == 1) {
        i = in4.size(0);
      }
    } else {
      i = in8.size(0);
    }

    if (i == 1) {
      if (in3.size(0) == 1) {
        loop_ub = in2.size(0);
      } else {
        loop_ub = in3.size(0);
      }
    } else {
      loop_ub = i;
    }

    in1.set_size(loop_ub, in1.size(1));
    if (in7.size(1) == 1) {
      i = in6.size(1);
    } else {
      i = in7.size(1);
    }

    if (in8.size(1) == 1) {
      if (i == 1) {
        i = in4.size(1);
      }
    } else {
      i = in8.size(1);
    }

    if (i == 1) {
      if (in3.size(1) == 1) {
        b_loop_ub = in2.size(1);
      } else {
        b_loop_ub = in3.size(1);
      }
    } else {
      b_loop_ub = i;
    }

    in1.set_size(in1.size(0), b_loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_0 = (in3.size(0) != 1);
    stride_1_1 = (in3.size(1) != 1);
    stride_2_0 = (in4.size(0) != 1);
    stride_2_1 = (in4.size(1) != 1);
    stride_3_0 = (in6.size(0) != 1);
    stride_3_1 = (in6.size(1) != 1);
    stride_4_0 = (in7.size(0) != 1);
    stride_4_1 = (in7.size(1) != 1);
    stride_5_0 = (in8.size(0) != 1);
    stride_5_1 = (in8.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    aux_2_1 = 0;
    aux_3_1 = 0;
    aux_4_1 = 0;
    aux_5_1 = 0;
    for (i = 0; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        in1[i1 + in1.size(0) * i] = in2[i1 * stride_0_0 + in2.size(0) * aux_0_1]
          * static_cast<double>(in3[i1 * stride_1_0 + in3.size(0) * aux_1_1]) +
          (in4[i1 * stride_2_0 + in4.size(0) * aux_2_1] + in5 * (in6[i1 *
            stride_3_0 + in6.size(0) * aux_3_1] - in7[i1 * stride_4_0 + in7.size
            (0) * aux_4_1])) * static_cast<double>(in8[i1 * stride_5_0 +
          in8.size(0) * aux_5_1]);
      }

      aux_5_1 += stride_5_1;
      aux_4_1 += stride_4_1;
      aux_3_1 += stride_3_1;
      aux_2_1 += stride_2_1;
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }
  }

  static void i_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<boolean_T, 2U> &in3, double in4,
    const ::coder::array<double, 2U> &in5, const ::coder::array<double, 2U> &in6,
    const ::coder::array<double, 2U> &in7, const ::coder::array<boolean_T, 2U>
    &in8)
  {
    int aux_0_1;
    int aux_1_1;
    int aux_3_1;
    int aux_4_1_tmp;
    int aux_5_1;
    int aux_6_1;
    int aux_7_1;
    int b_loop_ub;
    int i;
    int i1;
    int loop_ub;
    int stride_0_0_tmp;
    int stride_0_1_tmp;
    int stride_1_0;
    int stride_1_1;
    int stride_3_0;
    int stride_3_1;
    int stride_5_0;
    int stride_5_1;
    int stride_6_0;
    int stride_6_1;
    int stride_7_0;
    int stride_7_1;
    if (in2.size(0) == 1) {
      i = in5.size(0);
    } else {
      i = in2.size(0);
    }

    if (in7.size(0) == 1) {
      i1 = in6.size(0);
    } else {
      i1 = in7.size(0);
    }

    if (in8.size(0) == 1) {
      if (i1 == 1) {
        if (i == 1) {
          i = in2.size(0);
        }
      } else {
        i = i1;
      }
    } else {
      i = in8.size(0);
    }

    if (i == 1) {
      if (in3.size(0) == 1) {
        loop_ub = in2.size(0);
      } else {
        loop_ub = in3.size(0);
      }
    } else {
      loop_ub = i;
    }

    in1.set_size(loop_ub, in1.size(1));
    if (in2.size(1) == 1) {
      i = in5.size(1);
    } else {
      i = in2.size(1);
    }

    if (in7.size(1) == 1) {
      i1 = in6.size(1);
    } else {
      i1 = in7.size(1);
    }

    if (in8.size(1) == 1) {
      if (i1 == 1) {
        if (i == 1) {
          i = in2.size(1);
        }
      } else {
        i = i1;
      }
    } else {
      i = in8.size(1);
    }

    if (i == 1) {
      if (in3.size(1) == 1) {
        b_loop_ub = in2.size(1);
      } else {
        b_loop_ub = in3.size(1);
      }
    } else {
      b_loop_ub = i;
    }

    in1.set_size(in1.size(0), b_loop_ub);
    stride_0_0_tmp = (in2.size(0) != 1);
    stride_0_1_tmp = (in2.size(1) != 1);
    stride_1_0 = (in3.size(0) != 1);
    stride_1_1 = (in3.size(1) != 1);
    stride_3_0 = (in5.size(0) != 1);
    stride_3_1 = (in5.size(1) != 1);
    stride_5_0 = (in6.size(0) != 1);
    stride_5_1 = (in6.size(1) != 1);
    stride_6_0 = (in7.size(0) != 1);
    stride_6_1 = (in7.size(1) != 1);
    stride_7_0 = (in8.size(0) != 1);
    stride_7_1 = (in8.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    aux_3_1 = 0;
    aux_4_1_tmp = 0;
    aux_5_1 = 0;
    aux_6_1 = 0;
    aux_7_1 = 0;
    for (i = 0; i < b_loop_ub; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        double d;
        d = in2[i1 * stride_0_0_tmp + in2.size(0) * aux_0_1];
        in1[i1 + in1.size(0) * i] = d * static_cast<double>(in3[i1 * stride_1_0
          + in3.size(0) * aux_1_1]) + ((d + in4 * (in5[i1 * stride_3_0 +
          in5.size(0) * aux_3_1] - d)) + in4 * (in6[i1 * stride_5_0 + in6.size(0)
          * aux_5_1] - in7[i1 * stride_6_0 + in7.size(0) * aux_6_1])) *
          static_cast<double>(in8[i1 * stride_7_0 + in8.size(0) * aux_7_1]);
      }

      aux_7_1 += stride_7_1;
      aux_6_1 += stride_6_1;
      aux_5_1 += stride_5_1;
      aux_4_1_tmp += stride_0_1_tmp;
      aux_3_1 += stride_3_1;
      aux_1_1 += stride_1_1;
      aux_0_1 = aux_4_1_tmp;
    }
  }

  static void j_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<boolean_T, 2U> &in3, const ::
    coder::array<double, 2U> &in4, const ::coder::array<double, 2U> &in5, const ::
    coder::array<double, 2U> &in6, const ::coder::array<double, 2U> &in7, double
    in8, const ::coder::array<boolean_T, 2U> &in9)
  {
    int aux_0_1;
    int aux_1_1;
    int aux_2_1;
    int aux_3_1;
    int aux_4_1;
    int aux_5_1;
    int aux_6_1;
    int b_loop_ub;
    int i;
    int loop_ub;
    int stride_0_0;
    int stride_0_1;
    int stride_1_0;
    int stride_1_1;
    int stride_2_0;
    int stride_2_1;
    int stride_3_0;
    int stride_3_1;
    int stride_4_0;
    int stride_4_1;
    int stride_5_0;
    int stride_5_1;
    int stride_6_0;
    int stride_6_1;
    if (in7.size(0) == 1) {
      if (in6.size(0) == 1) {
        i = in5.size(0);
      } else {
        i = in6.size(0);
      }
    } else {
      i = in7.size(0);
    }

    if (in9.size(0) == 1) {
      if (i == 1) {
        i = in4.size(0);
      }
    } else {
      i = in9.size(0);
    }

    if (i == 1) {
      if (in3.size(0) == 1) {
        loop_ub = in2.size(0);
      } else {
        loop_ub = in3.size(0);
      }
    } else {
      loop_ub = i;
    }

    in1.set_size(loop_ub, in1.size(1));
    if (in7.size(1) == 1) {
      if (in6.size(1) == 1) {
        i = in5.size(1);
      } else {
        i = in6.size(1);
      }
    } else {
      i = in7.size(1);
    }

    if (in9.size(1) == 1) {
      if (i == 1) {
        i = in4.size(1);
      }
    } else {
      i = in9.size(1);
    }

    if (i == 1) {
      if (in3.size(1) == 1) {
        b_loop_ub = in2.size(1);
      } else {
        b_loop_ub = in3.size(1);
      }
    } else {
      b_loop_ub = i;
    }

    in1.set_size(in1.size(0), b_loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_0 = (in3.size(0) != 1);
    stride_1_1 = (in3.size(1) != 1);
    stride_2_0 = (in4.size(0) != 1);
    stride_2_1 = (in4.size(1) != 1);
    stride_3_0 = (in5.size(0) != 1);
    stride_3_1 = (in5.size(1) != 1);
    stride_4_0 = (in6.size(0) != 1);
    stride_4_1 = (in6.size(1) != 1);
    stride_5_0 = (in7.size(0) != 1);
    stride_5_1 = (in7.size(1) != 1);
    stride_6_0 = (in9.size(0) != 1);
    stride_6_1 = (in9.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    aux_2_1 = 0;
    aux_3_1 = 0;
    aux_4_1 = 0;
    aux_5_1 = 0;
    aux_6_1 = 0;
    for (i = 0; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        in1[i1 + in1.size(0) * i] = in2[i1 * stride_0_0 + in2.size(0) * aux_0_1]
          * static_cast<double>(in3[i1 * stride_1_0 + in3.size(0) * aux_1_1]) +
          (in4[i1 * stride_2_0 + in4.size(0) * aux_2_1] + (in5[i1 * stride_3_0 +
            in5.size(0) * aux_3_1] - in6[i1 * stride_4_0 + in6.size(0) * aux_4_1])
           * (9.9999999999988987E-5 * in7[i1 * stride_5_0 + in7.size(0) *
              aux_5_1] + in8)) * static_cast<double>(in9[i1 * stride_6_0 +
          in9.size(0) * aux_6_1]);
      }

      aux_6_1 += stride_6_1;
      aux_5_1 += stride_5_1;
      aux_4_1 += stride_4_1;
      aux_3_1 += stride_3_1;
      aux_2_1 += stride_2_1;
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }
  }

  static void k_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<boolean_T, 2U> &in3, const ::
    coder::array<double, 2U> &in4, const ::coder::array<double, 2U> &in5, const ::
    coder::array<double, 2U> &in6, const ::coder::array<double, 2U> &in7, const ::
    coder::array<boolean_T, 2U> &in8)
  {
    int aux_0_1;
    int aux_1_1;
    int aux_2_1;
    int aux_3_1;
    int aux_4_1;
    int aux_5_1;
    int aux_6_1;
    int b_loop_ub;
    int i;
    int loop_ub;
    int stride_0_0;
    int stride_0_1;
    int stride_1_0;
    int stride_1_1;
    int stride_2_0;
    int stride_2_1;
    int stride_3_0;
    int stride_3_1;
    int stride_4_0;
    int stride_4_1;
    int stride_5_0;
    int stride_5_1;
    int stride_6_0;
    int stride_6_1;
    if (in7.size(0) == 1) {
      if (in6.size(0) == 1) {
        i = in5.size(0);
      } else {
        i = in6.size(0);
      }
    } else {
      i = in7.size(0);
    }

    if (in8.size(0) == 1) {
      if (i == 1) {
        i = in4.size(0);
      }
    } else {
      i = in8.size(0);
    }

    if (i == 1) {
      if (in3.size(0) == 1) {
        loop_ub = in2.size(0);
      } else {
        loop_ub = in3.size(0);
      }
    } else {
      loop_ub = i;
    }

    in1.set_size(loop_ub, in1.size(1));
    if (in7.size(1) == 1) {
      if (in6.size(1) == 1) {
        i = in5.size(1);
      } else {
        i = in6.size(1);
      }
    } else {
      i = in7.size(1);
    }

    if (in8.size(1) == 1) {
      if (i == 1) {
        i = in4.size(1);
      }
    } else {
      i = in8.size(1);
    }

    if (i == 1) {
      if (in3.size(1) == 1) {
        b_loop_ub = in2.size(1);
      } else {
        b_loop_ub = in3.size(1);
      }
    } else {
      b_loop_ub = i;
    }

    in1.set_size(in1.size(0), b_loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_0 = (in3.size(0) != 1);
    stride_1_1 = (in3.size(1) != 1);
    stride_2_0 = (in4.size(0) != 1);
    stride_2_1 = (in4.size(1) != 1);
    stride_3_0 = (in5.size(0) != 1);
    stride_3_1 = (in5.size(1) != 1);
    stride_4_0 = (in6.size(0) != 1);
    stride_4_1 = (in6.size(1) != 1);
    stride_5_0 = (in7.size(0) != 1);
    stride_5_1 = (in7.size(1) != 1);
    stride_6_0 = (in8.size(0) != 1);
    stride_6_1 = (in8.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    aux_2_1 = 0;
    aux_3_1 = 0;
    aux_4_1 = 0;
    aux_5_1 = 0;
    aux_6_1 = 0;
    for (i = 0; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        in1[i1 + in1.size(0) * i] = in2[i1 * stride_0_0 + in2.size(0) * aux_0_1]
          * static_cast<double>(in3[i1 * stride_1_0 + in3.size(0) * aux_1_1]) +
          (in4[i1 * stride_2_0 + in4.size(0) * aux_2_1] + (in5[i1 * stride_3_0 +
            in5.size(0) * aux_3_1] - in6[i1 * stride_4_0 + in6.size(0) * aux_4_1])
           * in7[i1 * stride_5_0 + in7.size(0) * aux_5_1]) * static_cast<double>
          (in8[i1 * stride_6_0 + in8.size(0) * aux_6_1]);
      }

      aux_6_1 += stride_6_1;
      aux_5_1 += stride_5_1;
      aux_4_1 += stride_4_1;
      aux_3_1 += stride_3_1;
      aux_2_1 += stride_2_1;
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }
  }

  static void l_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<boolean_T, 2U> &in3, const ::
    coder::array<double, 2U> &in4, const ::coder::array<double, 2U> &in5, const ::
    coder::array<double, 2U> &in6, double in7, const ::coder::array<boolean_T,
    2U> &in8)
  {
    int aux_0_1;
    int aux_1_1;
    int aux_2_1;
    int aux_3_1;
    int aux_4_1;
    int aux_5_1;
    int b_loop_ub;
    int i;
    int loop_ub;
    int stride_0_0;
    int stride_0_1;
    int stride_1_0;
    int stride_1_1;
    int stride_2_0;
    int stride_2_1;
    int stride_3_0;
    int stride_3_1;
    int stride_4_0;
    int stride_4_1;
    int stride_5_0;
    int stride_5_1;
    if (in6.size(0) == 1) {
      i = in5.size(0);
    } else {
      i = in6.size(0);
    }

    if (in8.size(0) == 1) {
      if (i == 1) {
        i = in4.size(0);
      }
    } else {
      i = in8.size(0);
    }

    if (i == 1) {
      if (in3.size(0) == 1) {
        loop_ub = in2.size(0);
      } else {
        loop_ub = in3.size(0);
      }
    } else {
      loop_ub = i;
    }

    in1.set_size(loop_ub, in1.size(1));
    if (in6.size(1) == 1) {
      i = in5.size(1);
    } else {
      i = in6.size(1);
    }

    if (in8.size(1) == 1) {
      if (i == 1) {
        i = in4.size(1);
      }
    } else {
      i = in8.size(1);
    }

    if (i == 1) {
      if (in3.size(1) == 1) {
        b_loop_ub = in2.size(1);
      } else {
        b_loop_ub = in3.size(1);
      }
    } else {
      b_loop_ub = i;
    }

    in1.set_size(in1.size(0), b_loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_0 = (in3.size(0) != 1);
    stride_1_1 = (in3.size(1) != 1);
    stride_2_0 = (in4.size(0) != 1);
    stride_2_1 = (in4.size(1) != 1);
    stride_3_0 = (in5.size(0) != 1);
    stride_3_1 = (in5.size(1) != 1);
    stride_4_0 = (in6.size(0) != 1);
    stride_4_1 = (in6.size(1) != 1);
    stride_5_0 = (in8.size(0) != 1);
    stride_5_1 = (in8.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    aux_2_1 = 0;
    aux_3_1 = 0;
    aux_4_1 = 0;
    aux_5_1 = 0;
    for (i = 0; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        in1[i1 + in1.size(0) * i] = in2[i1 * stride_0_0 + in2.size(0) * aux_0_1]
          * static_cast<double>(in3[i1 * stride_1_0 + in3.size(0) * aux_1_1]) +
          (in4[i1 * stride_2_0 + in4.size(0) * aux_2_1] + (in5[i1 * stride_3_0 +
            in5.size(0) * aux_3_1] - in6[i1 * stride_4_0 + in6.size(0) * aux_4_1])
           * in7) * static_cast<double>(in8[i1 * stride_5_0 + in8.size(0) *
          aux_5_1]);
      }

      aux_5_1 += stride_5_1;
      aux_4_1 += stride_4_1;
      aux_3_1 += stride_3_1;
      aux_2_1 += stride_2_1;
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }
  }

  static void m_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<boolean_T, 2U> &in3, const ::
    coder::array<boolean_T, 2U> &in4)
  {
    ::coder::array<double, 2U> b_in2;
    int aux_0_1;
    int aux_1_1;
    int aux_2_1;
    int aux_3_1;
    int b_loop_ub;
    int i;
    int loop_ub;
    int stride_0_0;
    int stride_0_1;
    int stride_1_0;
    int stride_1_1;
    int stride_2_0;
    int stride_2_1;
    int stride_3_0;
    int stride_3_1;
    if (in4.size(0) == 1) {
      i = in1.size(0);
    } else {
      i = in4.size(0);
    }

    if (i == 1) {
      if (in3.size(0) == 1) {
        loop_ub = in2.size(0);
      } else {
        loop_ub = in3.size(0);
      }
    } else {
      loop_ub = i;
    }

    if (in4.size(1) == 1) {
      i = in1.size(1);
    } else {
      i = in4.size(1);
    }

    if (i == 1) {
      if (in3.size(1) == 1) {
        b_loop_ub = in2.size(1);
      } else {
        b_loop_ub = in3.size(1);
      }
    } else {
      b_loop_ub = i;
    }

    b_in2.set_size(loop_ub, b_loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_0 = (in3.size(0) != 1);
    stride_1_1 = (in3.size(1) != 1);
    stride_2_0 = (in1.size(0) != 1);
    stride_2_1 = (in1.size(1) != 1);
    stride_3_0 = (in4.size(0) != 1);
    stride_3_1 = (in4.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    aux_2_1 = 0;
    aux_3_1 = 0;
    for (i = 0; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        b_in2[i1 + b_in2.size(0) * i] = in2[i1 * stride_0_0 + in2.size(0) *
          aux_0_1] * static_cast<double>(in3[i1 * stride_1_0 + in3.size(0) *
          aux_1_1]) + in1[i1 * stride_2_0 + in1.size(0) * aux_2_1] *
          static_cast<double>(in4[i1 * stride_3_0 + in4.size(0) * aux_3_1]);
      }

      aux_3_1 += stride_3_1;
      aux_2_1 += stride_2_1;
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }

    in1.set_size(b_in2.size(0), b_in2.size(1));
    loop_ub = b_in2.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b_in2.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        in1[i1 + in1.size(0) * i] = b_in2[i1 + b_in2.size(0) * i];
      }
    }
  }

  void deopt(const ProblemDefinition &problem, const char
             controls_parallel_data[], const int controls_parallel_size[2],
             double controls_numSimulationPoints, double
             controls_resampleMinAngle, double controls_resampleNPoints, const
             char controls_display_data[], const int controls_display_size[2],
             double controls_updateFreq, double controls_updatePlotFreq,
             boolean_T controls_calcSLD, const char controls_IPCFilePath_data[],
             const int controls_IPCFilePath_size[2], const h_struct_T &S_struct,
             ::coder::array<double, 2U> &FVr_bestmem)
  {
    ::coder::array<j_struct_T, 1U> S_val;
    ::coder::array<double, 2U> FM_bm;
    ::coder::array<double, 2U> FM_origin;
    ::coder::array<double, 2U> FM_pm1;
    ::coder::array<double, 2U> FM_pm2;
    ::coder::array<double, 2U> FM_pm3;
    ::coder::array<double, 2U> FM_pm5;
    ::coder::array<double, 2U> FM_pop;
    ::coder::array<double, 2U> FM_ui;
    ::coder::array<double, 2U> FVr_a1;
    ::coder::array<double, 2U> FVr_a2;
    ::coder::array<double, 2U> FVr_a3;
    ::coder::array<double, 2U> FVr_a4;
    ::coder::array<double, 2U> FVr_a5;
    ::coder::array<double, 2U> FVr_bestmemit;
    ::coder::array<double, 2U> FVr_rt;
    ::coder::array<double, 2U> b;
    ::coder::array<double, 2U> b_FM_pop;
    ::coder::array<double, 1U> b_b;
    ::coder::array<double, 1U> f1;
    ::coder::array<char, 2U> charStr;
    ::coder::array<boolean_T, 2U> FM_mpo;
    ::coder::array<boolean_T, 2U> FM_mui;
    ::coder::array<boolean_T, 1U> b_tmp_data;
    ProblemDefinition b_problem;
    b_struct_T a__1;
    b_struct_T a__2;
    b_struct_T a__3;
    b_struct_T result;
    double validatedHoleFilling[5];
    double F_CR;
    double I_D;
    double I_NP;
    double I_iter;
    double I_itermax;
    double I_strategy;
    double S_bestval_FVr_oa;
    double S_tempval_FVr_ca;
    double S_tempval_FVr_oa;
    double S_tempval_I_no;
    double a;
    double b_expl_temp;
    double c_expl_temp;
    double d;
    double d1;
    double d2;
    double expl_temp;
    double fWeight;
    unsigned int I_best_index;
    int b_loop_ub_tmp;
    int c_loop_ub_tmp;
    int i;
    int i1;
    int loop_ub;
    int loop_ub_tmp;
    boolean_T doPlotEvent;
    boolean_T exitg1;
    boolean_T tmp_data;

    //  following comments are from the original source code:
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  Author:           Rainer Storn, Ken Price, Arnold Neumaier, Jim Van Zandt
    //  Description:      Minimization of a user-supplied function with respect to x(1:I_D),
    //                    using the differential evolution (DE) algorithm.
    //                    DE works best if [FVr_minbound,FVr_maxbound] covers the region where the
    //                    global minimum is expected. DE is also somewhat sensitive to
    //                    the choice of the stepsize fWeight. A good initial guess is to
    //                    choose fWeight from interval [0.5, 1], e.g. 0.8. F_CR, the crossover
    //                    probability constant from interval [0, 1] helps to maintain
    //                    the diversity of the population but should be close to 1 for most.
    //                    practical cases. Only separable problems do better with CR close to 0.
    //                    If the parameters are correlated, high values of F_CR work better.
    //                    The reverse is true for no correlation.
    //
    //                    The number of population members I_NP is also not very critical. A
    //                    good initial guess is 10*I_D. Depending on the difficulty of the
    //                    problem I_NP can be lower than 10*I_D or must be higher than 10*I_D
    //                    to achieve convergence.
    //
    //                    deopt is a vectorized variant of DE which, however, has a
    //                    property which differs from the original version of DE:
    //                    The random selection of vectors is performed by shuffling the
    //                    population array. Hence a certain vector can't be chosen twice
    //                    in the same term of the perturbation expression.
    //                    Due to the vectorized expressions deopt executes fairly fast
    //                    in MATLAB's interpreter environment.
    //
    //                    ---------members of S_struct----------------------------------------------------
    //                    F_VTR        (I)    "Value To Reach". deopt will stop its minimization
    //                                        if either the maximum number of iterations "I_itermax"
    //                                        is reached or the best parameter vector "FVr_bestmem"
    //                                        has found a value f(FVr_bestmem,y) <= F_VTR.
    //                    FVr_minbound (I)    Vector of lower bounds FVr_minbound(1) ... FVr_minbound(I_D)
    //                                        of initial population.
    //                                        *** note: these are not bound constraints!! ***
    //                    FVr_maxbound (I)    Vector of upper bounds FVr_maxbound(1) ... FVr_maxbound(I_D)
    //                                        of initial population.
    //                    I_D          (I)    Number of parameters of the objective function.
    //                    I_NP         (I)    Number of population members.
    //                    I_itermax    (I)    Maximum number of iterations (generations).
    //                    fWeight     (I)    DE-stepsize fWeight from interval [0, 2].
    //                    F_CR         (I)    Crossover probability constant from interval [0, 1].
    //                    I_strategy   (I)    1 --> DE/rand/1
    //                                        2 --> DE/local-to-best/1
    //                                        3 --> DE/best/1 with jitter
    //                                        4 --> DE/rand/1 with per-vector-dither
    //                                        5 --> DE/rand/1 with per-generation-dither
    //                                        6 --> DE/rand/1 either-or-algorithm
    //                    I_refresh     (I)   Intermediate output will be produced after "I_refresh"
    //                                        iterations. No intermediate output will be produced
    //                                        if I_refresh is < 1.
    //
    //  Note:
    //  This program is free software; you can redistribute it and/or modify
    //  it under the terms of the GNU General Public License as published by
    //  the Free Software Foundation; either version 1, or (at your option)
    //  any later version.
    //
    //  This program is distributed in the hope that it will be useful,
    //  but WITHOUT ANY WARRANTY; without even the implied warranty of
    //  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    //  GNU General Public License for more details. A copy of the GNU
    //  General Public License can be obtained from the
    //  Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  Minimise a user-supplied function with the differential evolution algorithm.
    //
    //  Parameters
    //  ----------
    //  fname : string
    //      string naming a function to minimise.
    //  problem : struct
    //      the Project struct.
    //  controls : struct
    //      the Controls struct.
    //  S_struct : struct
    //      problem data vector (data and controls).
    //
    //  Returns
    //  -------
    //  FVr_bestmem : vector
    //      a vector of the best parameter values.
    //  problem : struct
    //      the Project struct.
    //
    // -----This is just for notational convenience and to keep the code uncluttered.--------
    //  stopflag = 0;
    I_NP = S_struct.I_NP;
    fWeight = S_struct.fWeight;
    F_CR = S_struct.F_CR;
    I_D = S_struct.I_D;
    I_itermax = S_struct.I_itermax;
    I_strategy = S_struct.I_strategy;
    doPlotEvent = hasPlotHandler();

    // -----Check input variables---------------------------------------------
    if (S_struct.I_NP < 5.0) {
      I_NP = 5.0;
      e_triggerEvent();
    }

    if ((S_struct.F_CR < 0.0) || (S_struct.F_CR > 1.0)) {
      F_CR = 0.5;
      f_triggerEvent();
    }

    if (S_struct.I_itermax <= 0.0) {
      I_itermax = 200.0;
      g_triggerEvent();
    }

    // -----Initialize population and some arrays-------------------------------
    loop_ub_tmp = static_cast<int>(I_NP);
    b_loop_ub_tmp = static_cast<int>(S_struct.I_D);
    FM_pop.set_size(loop_ub_tmp, b_loop_ub_tmp);

    // initialise FM_pop to gain speed
    // ----FM_pop is a matrix of size I_NPx(I_D+1). It will be initialized------
    // ----with random values between the min and max values of the-------------
    // ----parameters-----------------------------------------------------------
    if (S_struct.FVr_maxbound.size(1) == 1) {
      i = S_struct.FVr_minbound.size(1);
    } else {
      i = S_struct.FVr_maxbound.size(1);
    }

    for (int k{0}; k < loop_ub_tmp; k++) {
      coder::b_rand(I_D, FVr_a1);
      if (FVr_a1.size(1) == 1) {
        i1 = i;
      } else {
        i1 = FVr_a1.size(1);
      }

      if ((S_struct.FVr_maxbound.size(1) == S_struct.FVr_minbound.size(1)) &&
          (FVr_a1.size(1) == i) && (S_struct.FVr_minbound.size(1) == i1)) {
        loop_ub = FM_pop.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          d = S_struct.FVr_minbound[i1];
          FM_pop[k + FM_pop.size(0) * i1] = d + FVr_a1[FVr_a1.size(0) * i1] *
            (S_struct.FVr_maxbound[i1] - d);
        }
      } else {
        binary_expand_op(FM_pop, k, S_struct, FVr_a1);
      }
    }

    //  number of function evaluations
    // ------Evaluate the best member after initialization----------------------
    coder::repmat(I_NP, S_val);
    I_best_index = 1U;

    //  start with first population member
    b_FM_pop.set_size(1, FM_pop.size(1));
    loop_ub = FM_pop.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_FM_pop[i] = FM_pop[FM_pop.size(0) * i];
    }

    b_problem = problem;
    intrafun(b_FM_pop, b_problem, controls_parallel_data, controls_parallel_size,
             controls_numSimulationPoints, controls_resampleMinAngle,
             controls_resampleNPoints, controls_calcSLD, a__1, a, d1, d2);
    S_val[0].FVr_oa = d2;
    S_val[0].I_no = d1;
    S_bestval_FVr_oa = S_val[0].FVr_oa;

    //  best objective function value so far
    c_loop_ub_tmp = static_cast<int>(I_NP - 1.0);
    loop_ub = FM_pop.size(1);
    for (int k{0}; k < c_loop_ub_tmp; k++) {
      //  check the remaining members
      b_FM_pop.set_size(1, FM_pop.size(1));
      for (i = 0; i < loop_ub; i++) {
        b_FM_pop[i] = FM_pop[(k + FM_pop.size(0) * i) + 1];
      }

      b_problem = problem;
      intrafun(b_FM_pop, b_problem, controls_parallel_data,
               controls_parallel_size, controls_numSimulationPoints,
               controls_resampleMinAngle, controls_resampleNPoints,
               controls_calcSLD, a__2, a, d1, d2);
      S_val[k + 1].FVr_oa = d2;
      S_val[k + 1].I_no = d1;
      if (leftWin(S_val[k + 1].I_no, S_val[k + 1].FVr_oa, S_bestval_FVr_oa) ==
          1.0) {
        I_best_index = static_cast<unsigned int>(k) + 2U;

        //  save its location
        S_bestval_FVr_oa = S_val[k + 1].FVr_oa;
      }
    }

    FVr_bestmemit.set_size(1, FM_pop.size(1));
    loop_ub = FM_pop.size(1);
    for (i = 0; i < loop_ub; i++) {
      FVr_bestmemit[i] = FM_pop[(static_cast<int>(I_best_index) + FM_pop.size(0)
        * i) - 1];
    }

    //  best member of current iteration
    //  best member ever
    // ------DE-Minimization---------------------------------------------
    // ------FM_popold is the population which has to compete. It is--------
    // ------static through one iteration. FM_pop is the newly--------------
    // ------emerging population.----------------------------------------
    //  initialise population matrix 1
    //  initialise population matrix 2
    //  initialise population matrix 3
    //  initialise population matrix 4
    //  initialise population matrix 5
    FM_bm.set_size(loop_ub_tmp, b_loop_ub_tmp);

    //  initialise FVr_bestmember  matrix
    //  intermediate population of perturbed vectors
    //  mask for intermediate population
    //  mask for old population
    //  rotating index array (size I_NP)
    //  rotating index array (size I_D)
    //  another rotating index array
    //  rotating index array for exponential crossover
    //  index array
    FVr_bestmem.set_size(1, b_loop_ub_tmp);
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        FM_bm[i1 + FM_bm.size(0) * i] = 0.0;
      }

      FVr_bestmem[i] = 0.0;
    }

    //
    // FM_pop = zeros(I_NP,2);
    I_iter = 0.0;
    if (S_bestval_FVr_oa <= S_struct.F_VTR) {
      //  In this case the while loop should never run so reset
      //  the best result to the initial value
      FVr_bestmem.set_size(1, problem.params.size(1));
      loop_ub = problem.params.size(1);
      for (i = 0; i < loop_ub; i++) {
        FVr_bestmem[i] = problem.params[i];
      }
    } else {
      if (coder::internal::cb_strcmp(controls_display_data,
           controls_display_size)) {
        //  This should ensure the first result is printed.
        coder::internal::validate_print_arguments(0.0, S_bestval_FVr_oa,
          S_struct.fWeight, F_CR, I_NP, validatedHoleFilling);
        coder::snPrint(0.0, validatedHoleFilling[1], validatedHoleFilling[2],
                       validatedHoleFilling[3], validatedHoleFilling[4], charStr);
        triggerEvent(charStr);
      }

      I_iter = 1.0;
    }

    exitg1 = false;
    while ((!exitg1) && ((I_iter < I_itermax) && (S_bestval_FVr_oa >
             S_struct.F_VTR))) {
      double p[4];
      int iv[4];
      int b_FVr_a1;
      int d_loop_ub_tmp;

      //  save the old population
      // S_struct.FM_pop = FM_pop;
      coder::b_rand(p);
      iv[0] = 0;
      iv[1] = 0;
      iv[2] = 0;
      iv[3] = 0;
      coder::internal::b_mergesort(iv, p);
      p[0] = iv[0];
      p[1] = iv[1];
      p[2] = iv[2];
      p[3] = iv[3];

      //  index pointer array
      coder::randperm(I_NP, FVr_a1);

      //  shuffle locations of vectors
      //  rotate indices by ind(1) positions
      d_loop_ub_tmp = static_cast<int>(I_NP - 1.0) + 1;
      FVr_a2.set_size(1, d_loop_ub_tmp);
      for (i = 0; i <= c_loop_ub_tmp; i++) {
        FVr_a2[FVr_a2.size(0) * i] = FVr_a1[static_cast<int>(rt_remd_snf(
          static_cast<double>(i) + p[0], I_NP) + 1.0) - 1];
      }

      //  rotate vector locations
      FVr_a3.set_size(1, d_loop_ub_tmp);
      for (i = 0; i <= c_loop_ub_tmp; i++) {
        FVr_a3[FVr_a3.size(0) * i] = FVr_a2[static_cast<int>(rt_remd_snf(
          static_cast<double>(i) + p[1], I_NP) + 1.0) - 1];
      }

      FVr_a4.set_size(1, d_loop_ub_tmp);
      for (i = 0; i <= c_loop_ub_tmp; i++) {
        FVr_a4[FVr_a4.size(0) * i] = FVr_a3[static_cast<int>(rt_remd_snf(
          static_cast<double>(i) + p[2], I_NP) + 1.0) - 1];
      }

      FVr_rt.set_size(1, d_loop_ub_tmp);
      for (i = 0; i <= c_loop_ub_tmp; i++) {
        FVr_rt[i] = rt_remd_snf(static_cast<double>(i) + p[3], I_NP);
      }

      FVr_a5.set_size(1, FVr_rt.size(1));
      loop_ub = FVr_rt.size(1);
      for (i = 0; i < loop_ub; i++) {
        FVr_a5[FVr_a5.size(0) * i] = FVr_a4[static_cast<int>(FVr_rt[i] + 1.0) -
          1];
      }

      b_FVr_a1 = FVr_a1.size(1);
      FM_pm1.set_size(FVr_a1.size(1), FM_pop.size(1));
      loop_ub = FM_pop.size(1);
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < b_FVr_a1; i1++) {
          FM_pm1[i1 + FM_pm1.size(0) * i] = FM_pop[(static_cast<int>(FVr_a1[i1])
            + FM_pop.size(0) * i) - 1];
        }
      }

      //  shuffled population 1
      FM_pm2.set_size(d_loop_ub_tmp, FM_pop.size(1));
      loop_ub = FM_pop.size(1);
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < d_loop_ub_tmp; i1++) {
          FM_pm2[i1 + FM_pm2.size(0) * i] = FM_pop[(static_cast<int>(FVr_a2[i1])
            + FM_pop.size(0) * i) - 1];
        }
      }

      //  shuffled population 2
      FM_pm3.set_size(d_loop_ub_tmp, FM_pop.size(1));
      loop_ub = FM_pop.size(1);
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < d_loop_ub_tmp; i1++) {
          FM_pm3[i1 + FM_pm3.size(0) * i] = FM_pop[(static_cast<int>(FVr_a3[i1])
            + FM_pop.size(0) * i) - 1];
        }
      }

      //  shuffled population 3
      //  shuffled population 4
      b_FVr_a1 = FVr_rt.size(1);
      FM_pm5.set_size(FVr_rt.size(1), FM_pop.size(1));
      loop_ub = FM_pop.size(1);
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < b_FVr_a1; i1++) {
          FM_pm5[i1 + FM_pm5.size(0) * i] = FM_pop[(static_cast<int>(FVr_a5[i1])
            + FM_pop.size(0) * i) - 1];
        }
      }

      //  shuffled population 5
      for (int k{0}; k < loop_ub_tmp; k++) {
        //  population filled with the best member
        loop_ub = FM_bm.size(1);
        for (i = 0; i < loop_ub; i++) {
          FM_bm[k + FM_bm.size(0) * i] = FVr_bestmemit[i];
        }

        //  of the last iteration
      }

      coder::b_rand(I_NP, I_D, b);
      FM_mui.set_size(b.size(0), b.size(1));
      loop_ub = b.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_FVr_a1 = b.size(0);
        for (i1 = 0; i1 < b_FVr_a1; i1++) {
          FM_mui[i1 + FM_mui.size(0) * i] = (b[i1 + b.size(0) * i] < F_CR);
        }
      }

      //  all random numbers < F_CR are 1, 0 otherwise
      // ----Insert this if you want exponential crossover.----------------
      // FM_mui = sort(FM_mui');	  % transpose, collect 1's in each column
      // for k  = 1:I_NP
      //   n = floor(rand*I_D);
      //   if (n > 0)
      //      FVr_rtd     = rem(FVr_rotd+n,I_D);
      //      FM_mui(:,k) = FM_mui(FVr_rtd+1,k); %rotate column k by n
      //   end
      // end
      // FM_mui = FM_mui';			  % transpose back
      // ----End: exponential crossover------------------------------------
      FM_mpo.set_size(FM_mui.size(0), FM_mui.size(1));
      loop_ub = FM_mui.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_FVr_a1 = FM_mui.size(0);
        for (i1 = 0; i1 < b_FVr_a1; i1++) {
          FM_mpo[i1 + FM_mpo.size(0) * i] = (static_cast<double>(FM_mui[i1 +
            FM_mui.size(0) * i]) < 0.5);
        }
      }

      //  inverse mask to FM_mui
      FM_origin.set_size(loop_ub_tmp, 2);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          FM_origin[i1 + FM_origin.size(0) * i] = 0.0;
        }
      }

      if (I_strategy == 1.0) {
        int i2;
        int i3;

        // fprintf('Iteration: %d,  Best: %f,  fWeight: %f,  F_CR: %f,  I_NP: %d\n',I_iter,S_bestval.FVr_oa(1),fWeight,F_CR,I_NP));rategy == 1)                             % DE/rand/1
        //  differential variation
        if (FM_pm1.size(1) == 1) {
          i = FM_pm2.size(1);
        } else {
          i = FM_pm1.size(1);
        }

        if (FM_pm3.size(1) == 1) {
          i1 = i;
        } else {
          i1 = FM_pm3.size(1);
        }

        if (FM_pm3.size(0) == 1) {
          loop_ub = FM_pm1.size(0);
        } else {
          loop_ub = FM_pm3.size(0);
        }

        if (FM_pop.size(1) == 1) {
          i2 = FM_mpo.size(1);
        } else {
          i2 = FM_pop.size(1);
        }

        if (i1 == 1) {
          i3 = FM_mui.size(1);
        } else {
          i3 = i1;
        }

        if ((FM_pop.size(1) == FM_mpo.size(1)) && (FM_pm1.size(0) == FM_pm2.size
             (0)) && (FM_pm1.size(1) == FM_pm2.size(1)) && (FM_pm3.size(0) ==
             FM_pm1.size(0)) && (FM_pm3.size(1) == i) && (loop_ub == FM_mui.size
             (0)) && (i1 == FM_mui.size(1)) && (FM_pop.size(0) == FM_mui.size(0))
            && (i2 == i3)) {
          FM_ui.set_size(FM_pop.size(0), FM_pop.size(1));
          loop_ub = FM_pop.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_FVr_a1 = FM_pop.size(0);
            for (i1 = 0; i1 < b_FVr_a1; i1++) {
              FM_ui[i1 + FM_ui.size(0) * i] = FM_pop[i1 + FM_pop.size(0) * i] *
                static_cast<double>(FM_mpo[i1 + FM_mpo.size(0) * i]) +
                (FM_pm3[i1 + FM_pm3.size(0) * i] + fWeight * (FM_pm1[i1 +
                  FM_pm1.size(0) * i] - FM_pm2[i1 + FM_pm2.size(0) * i])) *
                static_cast<double>(FM_mui[i1 + FM_mui.size(0) * i]);
            }
          }
        } else {
          h_binary_expand_op(FM_ui, FM_pop, FM_mpo, FM_pm3, fWeight, FM_pm1,
                             FM_pm2, FM_mui);
        }

        //  crossover
        FM_origin.set_size(FM_pm3.size(0), FM_pm3.size(1));
        loop_ub = FM_pm3.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_FVr_a1 = FM_pm3.size(0);
          for (i1 = 0; i1 < b_FVr_a1; i1++) {
            FM_origin[i1 + FM_origin.size(0) * i] = FM_pm3[i1 + FM_pm3.size(0) *
              i];
          }
        }
      } else if (I_strategy == 2.0) {
        int i2;
        int i3;

        //  DE/local-to-best/1
        if (FM_bm.size(1) == 1) {
          i = FM_pop.size(1);
        } else {
          i = FM_bm.size(1);
        }

        if (FM_pop.size(1) == 1) {
          i1 = i;
        } else {
          i1 = FM_pop.size(1);
        }

        if (FM_pm1.size(1) == 1) {
          b_FVr_a1 = FM_pm2.size(1);
        } else {
          b_FVr_a1 = FM_pm1.size(1);
        }

        if (i1 == 1) {
          d_loop_ub_tmp = b_FVr_a1;
        } else {
          d_loop_ub_tmp = i1;
        }

        if (FM_pop.size(0) == 1) {
          loop_ub = FM_pm1.size(0);
        } else {
          loop_ub = FM_pop.size(0);
        }

        if (FM_pop.size(1) == 1) {
          i2 = FM_mpo.size(1);
        } else {
          i2 = FM_pop.size(1);
        }

        if (d_loop_ub_tmp == 1) {
          i3 = FM_mui.size(1);
        } else {
          i3 = d_loop_ub_tmp;
        }

        if ((FM_pop.size(1) == FM_mpo.size(1)) && (FM_bm.size(1) == FM_pop.size
             (1)) && (FM_pop.size(0) == FM_bm.size(0)) && (FM_pop.size(1) == i) &&
            (FM_pm1.size(0) == FM_pm2.size(0)) && (FM_pm1.size(1) == FM_pm2.size
             (1)) && (FM_pop.size(0) == FM_pm1.size(0)) && (i1 == b_FVr_a1) &&
            (loop_ub == FM_mui.size(0)) && (d_loop_ub_tmp == FM_mui.size(1)) &&
            (FM_pop.size(0) == FM_mui.size(0)) && (i2 == i3)) {
          FM_ui.set_size(FM_pop.size(0), FM_pop.size(1));
          loop_ub = FM_pop.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_FVr_a1 = FM_pop.size(0);
            for (i1 = 0; i1 < b_FVr_a1; i1++) {
              d = FM_pop[i1 + FM_pop.size(0) * i];
              FM_ui[i1 + FM_ui.size(0) * i] = d * static_cast<double>(FM_mpo[i1
                + FM_mpo.size(0) * i]) + ((d + fWeight * (FM_bm[i1 + FM_bm.size
                (0) * i] - d)) + fWeight * (FM_pm1[i1 + FM_pm1.size(0) * i] -
                FM_pm2[i1 + FM_pm2.size(0) * i])) * static_cast<double>
                (FM_mui[i1 + FM_mui.size(0) * i]);
            }
          }
        } else {
          i_binary_expand_op(FM_ui, FM_pop, FM_mpo, fWeight, FM_bm, FM_pm1,
                             FM_pm2, FM_mui);
        }

        FM_origin.set_size(FM_pop.size(0), FM_pop.size(1));
        loop_ub = FM_pop.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_FVr_a1 = FM_pop.size(0);
          for (i1 = 0; i1 < b_FVr_a1; i1++) {
            FM_origin[i1 + FM_origin.size(0) * i] = FM_pop[i1 + FM_pop.size(0) *
              i];
          }
        }
      } else if (I_strategy == 3.0) {
        int i2;

        //  DE/best/1 with jitter
        coder::b_rand(I_NP, I_D, b);
        if (FM_pm1.size(1) == 1) {
          i = FM_pm2.size(1);
        } else {
          i = FM_pm1.size(1);
        }

        if (i == 1) {
          i1 = b.size(1);
        } else {
          i1 = i;
        }

        if (FM_bm.size(1) == 1) {
          b_FVr_a1 = i1;
        } else {
          b_FVr_a1 = FM_bm.size(1);
        }

        if (FM_pop.size(1) == 1) {
          loop_ub = FM_mpo.size(1);
        } else {
          loop_ub = FM_pop.size(1);
        }

        if (b_FVr_a1 == 1) {
          i2 = FM_mui.size(1);
        } else {
          i2 = b_FVr_a1;
        }

        if ((FM_pop.size(1) == FM_mpo.size(1)) && (FM_pm1.size(0) == FM_pm2.size
             (0)) && (FM_pm1.size(1) == FM_pm2.size(1)) && (FM_pm1.size(0) ==
             b.size(0)) && (i == b.size(1)) && (FM_bm.size(0) == b.size(0)) &&
            (FM_bm.size(1) == i1) && (FM_bm.size(0) == FM_mui.size(0)) &&
            (b_FVr_a1 == FM_mui.size(1)) && (FM_pop.size(0) == FM_mui.size(0)) &&
            (loop_ub == i2)) {
          FM_ui.set_size(FM_pop.size(0), FM_pop.size(1));
          loop_ub = FM_pop.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_FVr_a1 = FM_pop.size(0);
            for (i1 = 0; i1 < b_FVr_a1; i1++) {
              FM_ui[i1 + FM_ui.size(0) * i] = FM_pop[i1 + FM_pop.size(0) * i] *
                static_cast<double>(FM_mpo[i1 + FM_mpo.size(0) * i]) + (FM_bm[i1
                + FM_bm.size(0) * i] + (FM_pm1[i1 + FM_pm1.size(0) * i] -
                FM_pm2[i1 + FM_pm2.size(0) * i]) * (9.9999999999988987E-5 * b[i1
                + b.size(0) * i] + fWeight)) * static_cast<double>(FM_mui[i1 +
                FM_mui.size(0) * i]);
            }
          }
        } else {
          j_binary_expand_op(FM_ui, FM_pop, FM_mpo, FM_bm, FM_pm1, FM_pm2, b,
                             fWeight, FM_mui);
        }

        FM_origin.set_size(FM_bm.size(0), FM_bm.size(1));
        loop_ub = FM_bm.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_FVr_a1 = FM_bm.size(0);
          for (i1 = 0; i1 < b_FVr_a1; i1++) {
            FM_origin[i1 + FM_origin.size(0) * i] = FM_bm[i1 + FM_bm.size(0) * i];
          }
        }
      } else if (I_strategy == 4.0) {
        int i2;
        int i3;

        //  DE/rand/1 with per-vector-dither
        coder::b_rand(I_NP, b_b);
        f1.set_size(b_b.size(0));
        loop_ub = b_b.size(0);
        for (i = 0; i < loop_ub; i++) {
          f1[i] = (1.0 - fWeight) * b_b[i] + fWeight;
        }

        for (int k{0}; k < b_loop_ub_tmp; k++) {
          loop_ub = FM_pm5.size(0);
          for (i = 0; i < loop_ub; i++) {
            FM_pm5[i + FM_pm5.size(0) * k] = f1[i];
          }
        }

        //  differential variation
        FM_origin.set_size(FM_pm3.size(0), FM_pm3.size(1));
        loop_ub = FM_pm3.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_FVr_a1 = FM_pm3.size(0);
          for (i1 = 0; i1 < b_FVr_a1; i1++) {
            FM_origin[i1 + FM_origin.size(0) * i] = FM_pm3[i1 + FM_pm3.size(0) *
              i];
          }
        }

        if (FM_pm1.size(1) == 1) {
          i = FM_pm2.size(1);
        } else {
          i = FM_pm1.size(1);
        }

        if (FM_pm1.size(0) == 1) {
          i1 = FM_pm5.size(0);
        } else {
          i1 = FM_pm1.size(0);
        }

        if (i == 1) {
          b_FVr_a1 = FM_pm5.size(1);
        } else {
          b_FVr_a1 = i;
        }

        if (FM_pm3.size(1) == 1) {
          d_loop_ub_tmp = b_FVr_a1;
        } else {
          d_loop_ub_tmp = FM_pm3.size(1);
        }

        if (FM_pm3.size(0) == 1) {
          loop_ub = i1;
        } else {
          loop_ub = FM_pm3.size(0);
        }

        if (FM_pop.size(1) == 1) {
          i2 = FM_mpo.size(1);
        } else {
          i2 = FM_pop.size(1);
        }

        if (d_loop_ub_tmp == 1) {
          i3 = FM_mui.size(1);
        } else {
          i3 = d_loop_ub_tmp;
        }

        if ((FM_pop.size(1) == FM_mpo.size(1)) && (FM_pm1.size(0) == FM_pm2.size
             (0)) && (FM_pm1.size(1) == FM_pm2.size(1)) && (FM_pm1.size(0) ==
             FM_pm5.size(0)) && (i == FM_pm5.size(1)) && (FM_pm3.size(0) == i1) &&
            (FM_pm3.size(1) == b_FVr_a1) && (loop_ub == FM_mui.size(0)) &&
            (d_loop_ub_tmp == FM_mui.size(1)) && (FM_pop.size(0) == FM_mui.size
             (0)) && (i2 == i3)) {
          FM_ui.set_size(FM_pop.size(0), FM_pop.size(1));
          loop_ub = FM_pop.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_FVr_a1 = FM_pop.size(0);
            for (i1 = 0; i1 < b_FVr_a1; i1++) {
              FM_ui[i1 + FM_ui.size(0) * i] = FM_pop[i1 + FM_pop.size(0) * i] *
                static_cast<double>(FM_mpo[i1 + FM_mpo.size(0) * i]) +
                (FM_pm3[i1 + FM_pm3.size(0) * i] + (FM_pm1[i1 + FM_pm1.size(0) *
                  i] - FM_pm2[i1 + FM_pm2.size(0) * i]) * FM_pm5[i1 +
                 FM_pm5.size(0) * i]) * static_cast<double>(FM_mui[i1 +
                FM_mui.size(0) * i]);
            }
          }
        } else {
          k_binary_expand_op(FM_ui, FM_pop, FM_mpo, FM_pm3, FM_pm1, FM_pm2,
                             FM_pm5, FM_mui);
        }

        //  crossover
      } else if (I_strategy == 5.0) {
        int i2;
        int i3;

        //  DE/rand/1 with per-vector-dither
        a = (1.0 - fWeight) * coder::b_rand() + fWeight;

        //  differential variation
        FM_origin.set_size(FM_pm3.size(0), FM_pm3.size(1));
        loop_ub = FM_pm3.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_FVr_a1 = FM_pm3.size(0);
          for (i1 = 0; i1 < b_FVr_a1; i1++) {
            FM_origin[i1 + FM_origin.size(0) * i] = FM_pm3[i1 + FM_pm3.size(0) *
              i];
          }
        }

        if (FM_pm1.size(1) == 1) {
          i = FM_pm2.size(1);
        } else {
          i = FM_pm1.size(1);
        }

        if (FM_pm3.size(1) == 1) {
          i1 = i;
        } else {
          i1 = FM_pm3.size(1);
        }

        if (FM_pm3.size(0) == 1) {
          loop_ub = FM_pm1.size(0);
        } else {
          loop_ub = FM_pm3.size(0);
        }

        if (FM_pop.size(1) == 1) {
          i2 = FM_mpo.size(1);
        } else {
          i2 = FM_pop.size(1);
        }

        if (i1 == 1) {
          i3 = FM_mui.size(1);
        } else {
          i3 = i1;
        }

        if ((FM_pop.size(1) == FM_mpo.size(1)) && (FM_pm1.size(0) == FM_pm2.size
             (0)) && (FM_pm1.size(1) == FM_pm2.size(1)) && (FM_pm3.size(0) ==
             FM_pm1.size(0)) && (FM_pm3.size(1) == i) && (loop_ub == FM_mui.size
             (0)) && (i1 == FM_mui.size(1)) && (FM_pop.size(0) == FM_mui.size(0))
            && (i2 == i3)) {
          FM_ui.set_size(FM_pop.size(0), FM_pop.size(1));
          loop_ub = FM_pop.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_FVr_a1 = FM_pop.size(0);
            for (i1 = 0; i1 < b_FVr_a1; i1++) {
              FM_ui[i1 + FM_ui.size(0) * i] = FM_pop[i1 + FM_pop.size(0) * i] *
                static_cast<double>(FM_mpo[i1 + FM_mpo.size(0) * i]) +
                (FM_pm3[i1 + FM_pm3.size(0) * i] + (FM_pm1[i1 + FM_pm1.size(0) *
                  i] - FM_pm2[i1 + FM_pm2.size(0) * i]) * a) * static_cast<
                double>(FM_mui[i1 + FM_mui.size(0) * i]);
            }
          }
        } else {
          l_binary_expand_op(FM_ui, FM_pop, FM_mpo, FM_pm3, FM_pm1, FM_pm2, a,
                             FM_mui);
        }

        //  crossover
      } else {
        //  either-or-algorithm
        if (coder::b_rand() < 0.5) {
          //  Pmu = 0.5
          if (FM_pm1.size(1) == 1) {
            i = FM_pm2.size(1);
          } else {
            i = FM_pm1.size(1);
          }

          if ((FM_pm1.size(0) == FM_pm2.size(0)) && (FM_pm1.size(1) ==
               FM_pm2.size(1)) && (FM_pm3.size(0) == FM_pm1.size(0)) &&
              (FM_pm3.size(1) == i)) {
            FM_ui.set_size(FM_pm3.size(0), FM_pm3.size(1));
            loop_ub = FM_pm3.size(1);
            for (i = 0; i < loop_ub; i++) {
              b_FVr_a1 = FM_pm3.size(0);
              for (i1 = 0; i1 < b_FVr_a1; i1++) {
                FM_ui[i1 + FM_ui.size(0) * i] = FM_pm3[i1 + FM_pm3.size(0) * i]
                  + fWeight * (FM_pm1[i1 + FM_pm1.size(0) * i] - FM_pm2[i1 +
                               FM_pm2.size(0) * i]);
              }
            }
          } else {
            binary_expand_op(FM_ui, FM_pm3, fWeight, FM_pm1, FM_pm2);
          }

          //  differential variation
          FM_origin.set_size(FM_pm3.size(0), FM_pm3.size(1));
          loop_ub = FM_pm3.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_FVr_a1 = FM_pm3.size(0);
            for (i1 = 0; i1 < b_FVr_a1; i1++) {
              FM_origin[i1 + FM_origin.size(0) * i] = FM_pm3[i1 + FM_pm3.size(0)
                * i];
            }
          }
        } else {
          //  use F-K-Rule: K = 0.5(F+1)
          a = 0.5 * (fWeight + 1.0);
          if (FM_pm1.size(1) == 1) {
            i = FM_pm2.size(1);
          } else {
            i = FM_pm1.size(1);
          }

          if (FM_pm1.size(0) == 1) {
            i1 = FM_pm3.size(0);
          } else {
            i1 = FM_pm1.size(0);
          }

          if (i == 1) {
            loop_ub = FM_pm3.size(1);
          } else {
            loop_ub = i;
          }

          if ((FM_pm1.size(0) == FM_pm2.size(0)) && (FM_pm1.size(1) ==
               FM_pm2.size(1)) && (FM_pm1.size(0) == FM_pm3.size(0)) && (i ==
               FM_pm3.size(1)) && (FM_pm3.size(0) == i1) && (FM_pm3.size(1) ==
               loop_ub)) {
            FM_ui.set_size(FM_pm3.size(0), FM_pm3.size(1));
            loop_ub = FM_pm3.size(1);
            for (i = 0; i < loop_ub; i++) {
              b_FVr_a1 = FM_pm3.size(0);
              for (i1 = 0; i1 < b_FVr_a1; i1++) {
                d = FM_pm3[i1 + FM_pm3.size(0) * i];
                FM_ui[i1 + FM_ui.size(0) * i] = d + a * ((FM_pm1[i1 +
                  FM_pm1.size(0) * i] + FM_pm2[i1 + FM_pm2.size(0) * i]) - 2.0 *
                  d);
              }
            }
          } else {
            c_binary_expand_op(FM_ui, FM_pm3, a, FM_pm1, FM_pm2);
          }
        }

        if (FM_pop.size(1) == 1) {
          i = FM_mpo.size(1);
        } else {
          i = FM_pop.size(1);
        }

        if (FM_ui.size(1) == 1) {
          i1 = FM_mui.size(1);
        } else {
          i1 = FM_ui.size(1);
        }

        if ((FM_pop.size(1) == FM_mpo.size(1)) && (FM_ui.size(0) == FM_mui.size
             (0)) && (FM_ui.size(1) == FM_mui.size(1)) && (FM_pop.size(0) ==
             FM_mui.size(0)) && (i == i1)) {
          FM_ui.set_size(FM_pop.size(0), FM_pop.size(1));
          loop_ub = FM_pop.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_FVr_a1 = FM_pop.size(0);
            for (i1 = 0; i1 < b_FVr_a1; i1++) {
              FM_ui[i1 + FM_ui.size(0) * i] = FM_pop[i1 + FM_pop.size(0) * i] *
                static_cast<double>(FM_mpo[i1 + FM_mpo.size(0) * i]) + FM_ui[i1
                + FM_ui.size(0) * i] * static_cast<double>(FM_mui[i1 +
                FM_mui.size(0) * i]);
            }
          }
        } else {
          m_binary_expand_op(FM_ui, FM_pop, FM_mpo, FM_mui);
        }

        //  crossover
      }

      // -----Optional parent+child selection-----------------------------------------
      // -----Select which vectors are allowed to enter the new population------------
      for (int k{0}; k < loop_ub_tmp; k++) {
        // =====Only use this if boundary constraints are needed==================
        for (int j{0}; j < b_loop_ub_tmp; j++) {
          // ----boundary constraints via bounce back-------
          d = FM_ui[k + FM_ui.size(0) * j];
          a = S_struct.FVr_maxbound[j];
          if (d > a) {
            d = a + coder::b_rand() * (FM_origin[k + FM_origin.size(0) * j] - a);
            FM_ui[k + FM_ui.size(0) * j] = d;
          }

          a = S_struct.FVr_minbound[j];
          if (d < a) {
            d = a + coder::b_rand() * (FM_origin[k + FM_origin.size(0) * j] - a);
            FM_ui[k + FM_ui.size(0) * j] = d;
          }
        }

        // =====End boundary constraints==========================================
        loop_ub = FM_ui.size(1);
        b_FM_pop.set_size(1, FM_ui.size(1));
        for (i = 0; i < loop_ub; i++) {
          b_FM_pop[i] = FM_ui[k + FM_ui.size(0) * i];
        }

        b_problem = problem;
        intrafun(b_FM_pop, b_problem, controls_parallel_data,
                 controls_parallel_size, controls_numSimulationPoints,
                 controls_resampleMinAngle, controls_resampleNPoints,
                 controls_calcSLD, a__3, S_tempval_FVr_ca, S_tempval_I_no,
                 S_tempval_FVr_oa);

        //  check cost of competitor
        if (leftWin(S_tempval_I_no, S_tempval_FVr_oa, S_val[k].FVr_oa) == 1.0) {
          loop_ub = FM_pop.size(1);
          for (i = 0; i < loop_ub; i++) {
            FM_pop[k + FM_pop.size(0) * i] = FM_ui[k + FM_ui.size(0) * i];
          }

          //  replace old vector with new one (for new iteration)
          S_val[k].I_no = S_tempval_I_no;
          S_val[k].FVr_oa = S_tempval_FVr_oa;

          //  save value in "cost array"
          // ----we update S_bestval only in case of success to save time-----------
          if (leftWin(S_tempval_I_no, S_tempval_FVr_oa, S_bestval_FVr_oa) == 1.0)
          {
            S_bestval_FVr_oa = S_tempval_FVr_oa;

            //  new best value
            loop_ub = FM_ui.size(1);
            FVr_bestmem.set_size(1, FM_ui.size(1));
            for (i = 0; i < loop_ub; i++) {
              FVr_bestmem[i] = FM_ui[k + FM_ui.size(0) * i];
            }

            //  new best parameter vector ever
          }
        }
      }

      //  for k = 1:NP
      FVr_bestmemit.set_size(1, FVr_bestmem.size(1));
      loop_ub = FVr_bestmem.size(1);
      for (i = 0; i < loop_ub; i++) {
        FVr_bestmemit[i] = FVr_bestmem[i];
      }

      //  freeze the best member of this iteration for the coming
      //  iteration. This is needed for some of the strategies.
      // ----Output section----------------------------------------------------------
      if (((rt_remd_snf(I_iter, 1.0) == 0.0) || (I_iter == 1.0)) && coder::
          internal::cb_strcmp(controls_display_data, controls_display_size) &&
          (rt_remd_snf(I_iter, controls_updateFreq) == 0.0)) {
        coder::internal::validate_print_arguments(I_iter, S_bestval_FVr_oa,
          fWeight, F_CR, I_NP, validatedHoleFilling);
        coder::snPrint(validatedHoleFilling[0], validatedHoleFilling[1],
                       validatedHoleFilling[2], validatedHoleFilling[3],
                       validatedHoleFilling[4], charStr);
        triggerEvent(charStr);

        // disp(S_bestval);
        // var(FM_pop)
        //         format long e;
        //         for n=1:I_D
        //            fprintf('best(%d) = %g\n',n,FVr_bestmem(n));
        //         end
        //          if (I_plotting == 1)
        //             PlotIt(FVr_bestmem,problem);
        //          end
        //         stopflag = 0;
      }

      //  Trigger the output event...
      if (doPlotEvent && (rt_remd_snf(I_iter, controls_updatePlotFreq) == 0.0))
      {
        b_problem = problem;
        intrafun(FVr_bestmem, b_problem, controls_parallel_data,
                 controls_parallel_size, controls_numSimulationPoints,
                 controls_resampleMinAngle, controls_resampleNPoints, true,
                 result, expl_temp, b_expl_temp, c_expl_temp);
        controls_calcSLD = false;
        b_triggerEvent(result, problem.TF.data, problem.TF.size,
                       problem.resample, problem.dataPresent,
                       problem.modelType.data, problem.modelType.size,
                       problem.names.contrasts);
      }

      b_FVr_a1 = isRATStopped(controls_IPCFilePath_data,
        controls_IPCFilePath_size, (boolean_T *)&tmp_data);
      b_tmp_data.set(&tmp_data, b_FVr_a1);
      if (coder::internal::ifWhileCond(b_tmp_data)) {
        if (!coder::internal::d_strcmp(controls_display_data,
             controls_display_size)) {
          h_triggerEvent();
        }

        exitg1 = true;
      } else {
        //    if stopflag == 0
        I_iter++;

        //    else
        //        I_iter = I_itermax + 1;
        //    end
      }
    }

    // ---end while ((I_iter < I_itermax) ...
    if (coder::internal::cb_strcmp(controls_display_data, controls_display_size)
        && (rt_remd_snf(I_iter - 1.0, controls_updateFreq) != 0.0)) {
      //  This should ensure the final result is printed at the end of a run irrespective of update frequency
      coder::internal::validate_print_arguments(I_iter - 1.0, S_bestval_FVr_oa,
        S_struct.fWeight, F_CR, I_NP, validatedHoleFilling);
      coder::snPrint(validatedHoleFilling[0], validatedHoleFilling[1],
                     validatedHoleFilling[2], validatedHoleFilling[3],
                     validatedHoleFilling[4], charStr);
      triggerEvent(charStr);
    }

    if (doPlotEvent && (rt_remd_snf(I_iter - 1.0, controls_updatePlotFreq) !=
                        0.0)) {
      //  This should ensure the final result is always plotted irrespective of update frequency
      b_problem = problem;
      intrafun(FVr_bestmem, b_problem, controls_parallel_data,
               controls_parallel_size, controls_numSimulationPoints,
               controls_resampleMinAngle, controls_resampleNPoints, true, result,
               expl_temp, b_expl_temp, c_expl_temp);
      b_triggerEvent(result, problem.TF.data, problem.TF.size, problem.resample,
                     problem.dataPresent, problem.modelType.data,
                     problem.modelType.size, problem.names.contrasts);
    }
  }
}

// End of code generation (deopt.cpp)
