//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// calcEllipsoid.cpp
//
// Code generation for function 'calcEllipsoid'
//

// Include files
#include "calcEllipsoid.h"
#include "RATMain_rtwutil.h"
#include "cov.h"
#include "det.h"
#include "eml_mtimes_helper.h"
#include "gamma.h"
#include "ifWhileCond.h"
#include "mean.h"
#include "mrdivide_helper.h"
#include "mtimes.h"
#include "rcond.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  double calcEllipsoid(const ::coder::array<double, 2U> &u, double VS, ::coder::
                       array<double, 2U> &B, ::coder::array<double, 2U> &mu,
                       double VE_data[], int VE_size[2])
  {
    ::coder::array<double, 2U> C;
    ::coder::array<double, 2U> b_u;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> y;
    ::coder::array<boolean_T, 2U> c_y_data;
    ::coder::array<boolean_T, 2U> d_y_data;
    double d1;
    double y_data;
    int b_flag;
    boolean_T b_y_data;

    //  Calculate a bounding ellipsoid for a set of points u.
    //
    //  Parameters
    //  ----------
    //  u : array
    //      Array of points to contain in the ellipsoid.
    //      Nxndims array where N is the number point and ndims is the
    //      number of dimensions.
    //  VS : float
    //      The minimum volume that the bounding ellipsoid should have.
    //
    //  Returns
    //  -------
    //  B : array
    //      Bounding matrix for ellipsoid including scale factor for minimum volume.
    //  mu : float
    //      The centroid of the ellipsoid.
    //  VE : float
    //      The volume of the ellipsoid.
    //  flag : bool
    //      Equals 1 if the ellipsoid cannot be drawn (too few points or bad condition number).
    //  default values
    B.set_size(0, 0);
    mu.set_size(0, 0);
    VE_size[0] = 0;
    VE_size[1] = 0;
    b_flag = 0;

    //  extract number of points and number of dimensions
    //  check that total number of points is large enough
    if (static_cast<unsigned int>(u.size(0)) < static_cast<unsigned int>(u.size
         (1)) + 1U) {
      b_flag = 1;
    } else {
      double d;
      double x;

      //  constant factor for volume of ellipsoid
      d = 0.5 * static_cast<double>(u.size(1));
      d1 = d + 1.0;
      coder::b_gamma(d1);

      //  calculate covariance matrix and centroid
      coder::cov(u, C);
      coder::mean(u, mu);

      //  check condition number of C (eps = 2.2204e-16)
      x = coder::rcond(C);
      if ((x < 2.2204460492503131E-16) || std::isnan(x)) {
        b_flag = 1;
      } else {
        double fB;
        double fV_data;
        int b_loop_ub;
        int i;
        int loop_ub;

        //  find scale factor for bounding ellipsoid E
        fB = 0.0;
        i = u.size(0);
        loop_ub = u.size(1);
        b_loop_ub = u.size(1);
        for (int b_i{0}; b_i < i; b_i++) {
          int y_size[2];
          int c_loop_ub;
          if (u.size(1) == mu.size(1)) {
            b_u.set_size(1, u.size(1));
            for (int i1{0}; i1 < loop_ub; i1++) {
              b_u[b_u.size(0) * i1] = u[b_i + u.size(0) * i1] - mu[mu.size(0) *
                i1];
            }

            coder::internal::mrdiv(b_u, C, r);
          } else {
            binary_expand_op(r, u, b_i, mu, C);
          }

          if (u.size(1) == mu.size(1)) {
            b_u.set_size(1, u.size(1));
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              b_u[b_u.size(0) * i1] = u[b_i + u.size(0) * i1] - mu[mu.size(0) *
                i1];
            }

            coder::internal::blas::mtimes(r, b_u, (double *)&y_data, y_size);
          } else {
            binary_expand_op((double *)&y_data, r, u, b_i, mu, y_size);
          }

          c_loop_ub = y_size[1];
          for (int i1{0}; i1 < c_loop_ub; i1++) {
            int d_loop_ub;
            d_loop_ub = y_size[0];
            for (int i2{0}; i2 < d_loop_ub; i2++) {
              b_y_data = (y_data > fB);
            }
          }

          c_y_data.set(&b_y_data, y_size[0], y_size[1]);
          if (coder::internal::b_ifWhileCond(c_y_data)) {
            fB = y_data;
          }
        }

        //  calculate volume of bounding ellipsoid E
        y.set_size(C.size(0), C.size(1));
        loop_ub = C.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = C.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            y[i1 + y.size(0) * i] = fB * C[i1 + C.size(0) * i];
          }
        }

        VE_size[0] = 1;
        VE_size[1] = 1;
        x = rt_powd_snf(3.1415926535897931, d) / d1 * std::sqrt(coder::det(y));
        VE_data[0] = x;

        //  expand volume of bounding ellipsoid to VS if necessary
        fV_data = 1.0;
        b_y_data = (x < VS);
        d_y_data.set(&b_y_data, 1, 1);
        if (coder::internal::b_ifWhileCond(d_y_data)) {
          //  the original implementation calculates this as
          // fV = (VS/VE)^(2/ndims);
          //  however when compiled to C++,
          //  MATLAB Coder does not compile the code for fractional powers of matrices.
          //  so we must replace it with the explicit calculation:
          fV_data = std::log(VS / x) * (2.0 / static_cast<double>(u.size(1)));
          fV_data = std::exp(fV_data);
          VE_size[0] = 1;
          VE_size[1] = 1;
          VE_data[0] = VS;
        }

        //  scale C to get bounding matrix B
        //  Again emphasise the scalar for the inner mutiplication
        //  matlab error in compiled code.....
        //
        //  Error using eml_mtimes_helper>dynamic_size_checks
        //  Inner dimensions must agree. Generated code for a general matrix multiplication at this call site. If this should have been a scalar times a variable-size matrix, the
        //  scalar input must be fixed-size.
        //
        //  Error in eml_mtimes_helper (line 69)
        //      dynamic_size_checks(a, b, innerDimA, innerDimB);
        //
        //  Error in calcEllipsoid (line 73)
        //  B = fV * fB * C;
        x = fV_data * fB;
        B.set_size(C.size(0), C.size(1));
        loop_ub = C.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = C.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            B[i1 + B.size(0) * i] = x * C[i1 + C.size(0) * i];
          }
        }
      }
    }

    return b_flag;
  }
}

// End of code generation (calcEllipsoid.cpp)
