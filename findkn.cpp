//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// findkn.cpp
//
// Code generation for function 'findkn'
//

// Include files
#include "findkn.h"
#include "RATMain_data.h"
#include "exp.h"
#include "rt_nonfinite.h"
#include "sqrt.h"

// Function Definitions
namespace RAT
{
  creal_T findkn(double k0, const creal_T sld)
  {
    creal_T dc;
    creal_T dc1;
    creal_T kn;
    double k0_im;
    double k0_re;
    double re;

    //  sqrt function with branch cut in zarg from 0 to infinity along a ray
    //  at angle theta (in radians) measured from the +x axis in the usual way,
    //  with -pi<=theta<=pi.  theta = pi is the usual square root.
    //  for zarg on the +x axis, sqrt behavior is conserved,
    //  i.e. sqrtbc(theta,zarg) is positive and real for any theta.
    //
    //  y = sqrtbc(theta,zarg)
    dc.re = 0.0;
    dc.im = -0.78539816339744828;
    coder::b_exp(dc);
    dc1.re = 0.0;
    dc1.im = 1.5707963267948966;
    coder::b_exp(dc1);
    k0_re = k0 * k0 - 12.566370614359172 * sld.re;
    k0_im = 0.0 - 12.566370614359172 * sld.im;
    re = k0_re * dc1.re - k0_im * dc1.im;
    k0_re = k0_re * dc1.im + k0_im * dc1.re;
    dc1.re = re;
    dc1.im = k0_re;
    coder::internal::scalar::d_sqrt(&dc1);
    kn.re = dc.re * dc1.re - dc.im * dc1.im;
    kn.im = dc.re * dc1.im + dc.im * dc1.re;

    //  translations:  sqrtbc(theta, z-b) has branch cut in the z plane from
    //  branch point z = b out to infinity, along a ray at angle theta.
    //
    //  for the usual square root with branch cut along -x,
    //  the real part of sqrt(z) is positive (or 0) for all z.
    //  for the modified square root with branch cut along +x,
    //  the imaginary part of sqrt(z) is positive (or 0) for all z.
    return kn;
  }
}

// End of code generation (findkn.cpp)
