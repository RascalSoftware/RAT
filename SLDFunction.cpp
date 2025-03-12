//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// SLDFunction.cpp
//
// Code generation for function 'SLDFunction'
//

// Include files
#include "SLDFunction.h"
#include "abs.h"
#include "find.h"
#include "ifWhileCond.h"
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const double in3_data[], const int &in3_size);
  static void binary_expand_op(::coder::array<double, 2U> &in1, const double
    in2_data[], const int &in3_size, const ::coder::array<double, 2U> &in4);
  static void c_binary_expand_op(::coder::array<double, 2U> &in1, const double
    in2_data[], const int &in3_size, const ::coder::array<double, 2U> &in4);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const double in3_data[], const int &in3_size)
  {
    ::coder::array<double, 1U> b_in2;
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    if (in3_size == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3_size;
    }

    b_in2.set_size(loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in3_size != 1);
    for (int i{0}; i < loop_ub; i++) {
      b_in2[i] = in2[i * stride_0_0] - in3_data[i * stride_1_0];
    }

    coder::b_abs(b_in2, in1);
  }

  static void binary_expand_op(::coder::array<double, 2U> &in1, const double
    in2_data[], const int &in3_size, const ::coder::array<double, 2U> &in4)
  {
    int b_loop_ub;
    int loop_ub;
    if (in4.size(0) == 1) {
      loop_ub = in3_size;
    } else {
      loop_ub = in4.size(0);
    }

    in1.set_size(loop_ub, in4.size(1));
    b_loop_ub = in4.size(1);
    for (int i{0}; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        in1[in1.size(0) * i] = in2_data[0] + in4[in4.size(0) * i];
      }
    }
  }

  static void c_binary_expand_op(::coder::array<double, 2U> &in1, const double
    in2_data[], const int &in3_size, const ::coder::array<double, 2U> &in4)
  {
    int b_loop_ub;
    int loop_ub;
    if (in4.size(0) == 1) {
      loop_ub = in3_size;
    } else {
      loop_ub = in4.size(0);
    }

    in1.set_size(loop_ub, in4.size(1));
    b_loop_ub = in4.size(1);
    for (int i{0}; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        in1[in1.size(0) * i] = in2_data[0] - in4[in4.size(0) * i];
      }
    }
  }

  void SLDFunction(double x, const ::coder::array<double, 2U> &SLD, ::coder::
                   array<double, 2U> &sldVal)
  {
    ::coder::array<double, 2U> deltaY;
    ::coder::array<double, 2U> r1;
    ::coder::array<double, 1U> aboveY;
    ::coder::array<double, 1U> b_aboveY;
    ::coder::array<double, 1U> r;
    ::coder::array<int, 1U> where;
    ::coder::array<boolean_T, 1U> b_SLD;
    int below_data;
    int below_size;
    int loop_ub;

    //  sldVal = SLDFunction(x,SLD)
    //  SLD = [x rho;....xn rho]
    //    x = value in Angstrom.
    //
    //  This function returns the SLD (y) value associated with the
    //  supplied value of x. SLD is a two column, XY array defining an
    //  SLD profile. This function interpolates the SLD profile
    //  to return the SLD at the specific value of X. X can be a vector of
    //  multiple points.
    //
    //  (c) Arwel Hughes 2019.
    //  Last modified - AVH, 26/11/19.
    //  global sldProfile
    //
    //  SLD = sldProfile;
    // SLD = getappdata(0,'SLDFunctionSLD');
    b_SLD.set_size(SLD.size(0));
    loop_ub = SLD.size(0);
    for (int i{0}; i < loop_ub; i++) {
      b_SLD[i] = (SLD[i] == x);
    }

    coder::eml_find(b_SLD, where);
    if (where.size(0) != 0) {
      int stride_1_0;
      aboveY.set_size(where.size(0));
      loop_ub = where.size(0);
      for (int i{0}; i < loop_ub; i++) {
        aboveY[i] = SLD[(where[i] + SLD.size(0)) - 1];
      }

      stride_1_0 = where.size(0);
      sldVal.set_size(where.size(0), 1);
      for (int i{0}; i < stride_1_0; i++) {
        sldVal[i] = aboveY[i];
      }
    } else {
      double belowY_data;
      double x_data;
      int stride_1_0;
      b_SLD.set_size(SLD.size(0));
      loop_ub = SLD.size(0);
      for (int i{0}; i < loop_ub; i++) {
        b_SLD[i] = (x > SLD[i]);
      }

      below_size = coder::b_eml_find(b_SLD, (int *)&below_data);
      b_SLD.set_size(SLD.size(0));
      loop_ub = SLD.size(0);
      for (int i{0}; i < loop_ub; i++) {
        b_SLD[i] = (x < SLD[i]);
      }

      coder::c_eml_find(b_SLD, where);
      for (int i{0}; i < below_size; i++) {
        belowY_data = SLD[(below_data + SLD.size(0)) - 1];
      }

      b_aboveY.set_size(where.size(0));
      loop_ub = where.size(0);
      for (int i{0}; i < loop_ub; i++) {
        b_aboveY[i] = SLD[(where[i] + SLD.size(0)) - 1];
      }

      if (b_aboveY.size(0) == below_size) {
        aboveY.set_size(b_aboveY.size(0));
        loop_ub = b_aboveY.size(0);
        for (int i{0}; i < loop_ub; i++) {
          aboveY[0] = b_aboveY[0] - belowY_data;
        }

        coder::b_abs(aboveY, r);
      } else {
        binary_expand_op(r, b_aboveY, (const double *)&belowY_data, below_size);
      }

      if (where.size(0) == below_size) {
        aboveY.set_size(where.size(0));
        loop_ub = where.size(0);
        for (int i{0}; i < loop_ub; i++) {
          aboveY[0] = SLD[where[0] - 1] - SLD[below_data - 1];
        }

        coder::internal::mrdiv(r, aboveY, r1);
      } else {
        binary_expand_op(r1, r, SLD, where, (const int *)&below_data, below_size);
      }

      for (int i{0}; i < below_size; i++) {
        x_data = x - SLD[below_data - 1];
      }

      deltaY.set_size(below_size, r1.size(1));
      loop_ub = r1.size(1);
      for (int i{0}; i < loop_ub; i++) {
        for (stride_1_0 = 0; stride_1_0 < below_size; stride_1_0++) {
          deltaY[deltaY.size(0) * i] = x_data * r1[r1.size(0) * i];
        }
      }

      if (b_aboveY.size(0) == 1) {
        loop_ub = below_size;
      } else {
        loop_ub = b_aboveY.size(0);
      }

      b_SLD.set_size(loop_ub);
      stride_1_0 = (b_aboveY.size(0) != 1);
      for (int i{0}; i < loop_ub; i++) {
        b_SLD[i] = (belowY_data < b_aboveY[i * stride_1_0]);
      }

      if (coder::internal::ifWhileCond(b_SLD)) {
        if (below_size == deltaY.size(0)) {
          sldVal.set_size(below_size, deltaY.size(1));
          loop_ub = deltaY.size(1);
          for (int i{0}; i < loop_ub; i++) {
            for (stride_1_0 = 0; stride_1_0 < below_size; stride_1_0++) {
              sldVal[sldVal.size(0) * i] = belowY_data + deltaY[deltaY.size(0) *
                i];
            }
          }
        } else {
          binary_expand_op(sldVal, (const double *)&belowY_data, below_size,
                           deltaY);
        }
      } else if (below_size == deltaY.size(0)) {
        sldVal.set_size(below_size, deltaY.size(1));
        loop_ub = deltaY.size(1);
        for (int i{0}; i < loop_ub; i++) {
          for (stride_1_0 = 0; stride_1_0 < below_size; stride_1_0++) {
            sldVal[sldVal.size(0) * i] = belowY_data - deltaY[deltaY.size(0) * i];
          }
        }
      } else {
        c_binary_expand_op(sldVal, (const double *)&belowY_data, below_size,
                           deltaY);
      }
    }
  }
}

// End of code generation (SLDFunction.cpp)
