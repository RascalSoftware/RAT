//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: asymconvstep.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "asymconvstep.h"
#include "eml_mtimes_helper.h"
#include "erf.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Produces a step function convoluted with differnt error functions
//  on each side.
//  Convstep (x,xw,xcen,s1,s2,h)
//        x = vector of x values
//       xw = Width of step function
//     xcen = Centre point of step function
//        s1 = Roughness parameter of left side
//        s2 = Roughness parameter of right side
//        h = Height of step function.
//
// Arguments    : const ::coder::array<real_T, 2U> &x
//                real_T xw
//                real_T xcen
//                real_T s1
//                real_T s2
//                real_T h
//                ::coder::array<real_T, 2U> &f
// Return Type  : void
//
namespace RAT
{
  void asymconvstep(const ::coder::array<real_T, 2U> &x, real_T xw, real_T xcen,
                    real_T s1, real_T s2, real_T h, ::coder::array<real_T, 2U>
                    &f)
  {
    ::coder::array<real_T, 2U> b_r;
    ::coder::array<real_T, 2U> b_x;
    ::coder::array<real_T, 2U> r1;
    real_T a;
    real_T aFactor;
    real_T bFactor;
    real_T l;
    real_T r;
    int32_T loop_ub;

    //  if length(xw) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               'xw must be single value');
    //      throw(ME);
    //  end
    //
    //  if length(xcen) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               'xcen must be single value');
    //      throw(ME);
    //  end
    //
    //  if length(s1) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               's1 must be single value');
    //      throw(ME);
    //  end
    //
    //  if length(s2) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               's2 must be single value');
    //      throw(ME);
    //  end
    r = xcen + xw / 2.0;
    l = xcen - xw / 2.0;
    aFactor = 1.4142135623730951 * s1;
    bFactor = 1.4142135623730951 * s2;
    a = h / 2.0;
    b_x.set_size(1, x.size(1));
    loop_ub = x.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      b_x[i] = (x[i] - l) / aFactor;
    }

    coder::b_erf(b_x, b_r);
    b_x.set_size(1, x.size(1));
    loop_ub = x.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      b_x[i] = (x[i] - r) / bFactor;
    }

    coder::b_erf(b_x, r1);
    if (b_r.size(1) == r1.size(1)) {
      f.set_size(1, b_r.size(1));
      loop_ub = b_r.size(1);
      for (int32_T i{0}; i < loop_ub; i++) {
        f[i] = a * (b_r[i] - r1[i]);
      }
    } else {
      binary_expand_op(f, a, b_r, r1);
    }
  }
}

//
// File trailer for asymconvstep.cpp
//
// [EOF]
//
