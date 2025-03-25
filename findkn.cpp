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

    //  This is the sqrt function with branch cut in subtr from 0 to infinity
    //  along a ray at angle theta = pi/2
    dc.re = -0.0;
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
    return kn;
  }
}

// End of code generation (findkn.cpp)
