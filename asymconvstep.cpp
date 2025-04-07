//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// asymconvstep.cpp
//
// Code generation for function 'asymconvstep'
//

// Include files
#include "asymconvstep.h"
#include "eml_mtimes_helper.h"
#include "erf.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void asymconvstep(const ::coder::array<double, 2U> &x, double xw, double xcen,
                    double s1, double s2, double h, ::coder::array<double, 2U>
                    &f)
  {
    ::coder::array<double, 2U> b_r;
    ::coder::array<double, 2U> b_x;
    ::coder::array<double, 2U> r1;
    double a;
    double aFactor;
    double bFactor;
    double l;
    double r;
    int loop_ub;

    //  Produces a step function convoluted with different error functions
    //  on each side.
    //  Convstep (x,xw,xcen,s1,s2,h)
    //        x = vector of x values
    //       xw = Width of step function
    //     xcen = Centre point of step function
    //        s1 = Roughness parameter of left side
    //        s2 = Roughness parameter of right side
    //        h = Height of step function.
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
    r = xcen + 0.5 * xw;
    l = xcen - 0.5 * xw;
    aFactor = 1.4142135623730951 * s1;
    bFactor = 1.4142135623730951 * s2;
    a = 0.5 * h;
    b_x.set_size(1, x.size(1));
    loop_ub = x.size(1);
    for (int i{0}; i < loop_ub; i++) {
      b_x[i] = (x[i] - l) / aFactor;
    }

    coder::b_erf(b_x, b_r);
    b_x.set_size(1, x.size(1));
    loop_ub = x.size(1);
    for (int i{0}; i < loop_ub; i++) {
      b_x[i] = (x[i] - r) / bFactor;
    }

    coder::b_erf(b_x, r1);
    if (b_r.size(1) == r1.size(1)) {
      f.set_size(1, b_r.size(1));
      loop_ub = b_r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        f[i] = a * (b_r[i] - r1[i]);
      }
    } else {
      binary_expand_op(f, a, b_r, r1);
    }
  }

  void asymconvstep(const ::coder::array<double, 2U> &x, double xw, double xcen,
                    double s1, double s2, ::coder::array<double, 2U> &f)
  {
    ::coder::array<double, 2U> b_r;
    ::coder::array<double, 2U> b_x;
    ::coder::array<double, 2U> r1;
    double aFactor;
    double bFactor;
    double l;
    double r;
    int loop_ub;

    //  Produces a step function convoluted with different error functions
    //  on each side.
    //  Convstep (x,xw,xcen,s1,s2,h)
    //        x = vector of x values
    //       xw = Width of step function
    //     xcen = Centre point of step function
    //        s1 = Roughness parameter of left side
    //        s2 = Roughness parameter of right side
    //        h = Height of step function.
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
    r = xcen + 0.5 * xw;
    l = xcen - 0.5 * xw;
    aFactor = 1.4142135623730951 * s1;
    bFactor = 1.4142135623730951 * s2;
    b_x.set_size(1, x.size(1));
    loop_ub = x.size(1);
    for (int i{0}; i < loop_ub; i++) {
      b_x[i] = (x[i] - l) / aFactor;
    }

    coder::b_erf(b_x, b_r);
    b_x.set_size(1, x.size(1));
    loop_ub = x.size(1);
    for (int i{0}; i < loop_ub; i++) {
      b_x[i] = (x[i] - r) / bFactor;
    }

    coder::b_erf(b_x, r1);
    if (b_r.size(1) == r1.size(1)) {
      f.set_size(1, b_r.size(1));
      loop_ub = b_r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        f[i] = 0.0 * (b_r[i] - r1[i]);
      }
    } else {
      binary_expand_op(f, b_r, r1);
    }
  }
}

// End of code generation (asymconvstep.cpp)
