//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// calcEllipsoid.cpp
//
// Code generation for function 'calcEllipsoid'
//

// Include files
#include "calcEllipsoid.h"
#include "RATMain_data.h"
#include "RATMain_rtwutil.h"
#include "cov.h"
#include "det.h"
#include "gamma.h"
#include "ifWhileCond.h"
#include "matrix_to_integer_power.h"
#include "mean.h"
#include "mrdivide_helper.h"
#include "rcond.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <stdio.h>

// Function Definitions
namespace RAT
{
  void calcEllipsoid(const ::coder::array<real_T, 2U> &u, real_T VS, ::coder::
                     array<real_T, 2U> &B, ::coder::array<real_T, 2U> &mu,
                     real_T VE_data[], int32_T VE_size[2], real_T *flag)
  {
    ::coder::array<real_T, 2U> C;
    ::coder::array<real_T, 2U> b_u;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 2U> y;
    ::coder::array<boolean_T, 2U> b_const_data;
    real_T b;
    int32_T fV_size[2];
    int32_T b_flag;
    boolean_T const_data;

    //
    //  calculate properties of ellipsoid given a set of points u
    //
    //  Inputs:
    //     u:  Nxndims array where N is the number point and ndims is the
    //         number of dimensions
    //     VS: minimum volume that the bounding ellipsoid should have
    //
    //  Outputs:
    //     B:    bounding matrix for ellipsoid including scale factor
    //           for mininimum volume
    //     mu:   centroid
    //     VE:   volume of ellipsoid
    //     flag: = 1 if number of points too small or bounding matrix
    //           has bad condition number; otherwise = 0
    //
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  default values
    B.set_size(0, 0);
    mu.set_size(0, 0);
    VE_size[0] = 0;
    VE_size[1] = 0;
    b_flag = 0;

    //  extract number of points and number of dimensions
    //  check that total number of points is large enough
    if (static_cast<uint32_T>(u.size(0)) < u.size(1) + 1U) {
      if (DEBUG != 0.0) {
        printf("number of samples too small to calculate bounding matrix for ellipsoid\n");
        fflush(stdout);
      }

      b_flag = 1;
    } else {
      real_T x;
      int32_T i;
      int32_T loop_ub;

      //  constant factor for volume of ellipsoid
      b = static_cast<real_T>(u.size(1)) / 2.0 + 1.0;
      coder::b_gamma(&b);

      //  calculate covariance matrix and centroid
      coder::cov(u, C);
      coder::mean(u, r);
      mu.set_size(1, r.size(1));
      loop_ub = r.size(1);
      for (i = 0; i < loop_ub; i++) {
        mu[mu.size(0) * i] = r[i];
      }

      //  check condition number of C (eps = 2.2204e-16)
      x = coder::rcond(C);
      if ((x < 2.2204460492503131E-16) || std::isnan(x)) {
        if (DEBUG != 0.0) {
          printf("bad condition number!\n");
          fflush(stdout);
        }

        b_flag = 1;
      } else {
        real_T fB;
        real_T fV_data;
        int32_T b_loop_ub;
        int32_T i1;

        //  find scale factor for bounding ellipsoid E
        fB = 0.0;

        // coder.varsize('fB');
        i = u.size(0);
        for (int32_T b_i{0}; b_i < i; b_i++) {
          loop_ub = u.size(1);
          b_u.set_size(1, u.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_u[i1] = u[b_i + u.size(0) * i1] - mu[mu.size(0) * i1];
          }

          coder::internal::mrdiv(b_u, C, r);
          x = 0.0;
          loop_ub = r.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            x += r[i1] * (u[b_i + u.size(0) * i1] - mu[mu.size(0) * i1]);
          }

          if (x > fB) {
            fB = x;
          }
        }

        //  calculate volume of bounding ellipsoid E
        y.set_size(C.size(0), C.size(1));
        loop_ub = C.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = C.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            y[i1 + y.size(0) * i] = fB * C[i1 + C.size(0) * i];
          }
        }

        VE_size[0] = 1;
        VE_size[1] = 1;
        x = rt_powd_snf(3.1415926535897931, static_cast<real_T>(u.size(1)) / 2.0)
          / b * std::sqrt(coder::det(y));
        VE_data[0] = x;

        //  expand volume of bounding ellipsoid to VS if necessary
        fV_data = 1.0;
        const_data = (x < VS);
        b_const_data.set(&const_data, 1, 1);
        if (coder::internal::b_ifWhileCond(b_const_data)) {
          b = 2.0 / static_cast<real_T>(u.size(1));
          if (std::floor(b) == b) {
            x = VS / x;
            coder::matrix_to_integer_power((const real_T *)&x, b, (real_T *)
              &fV_data, fV_size);
          }

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
        //  B = fV * fB * C;
        x = fV_data * fB;
        B.set_size(C.size(0), C.size(1));
        loop_ub = C.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = C.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            B[i1 + B.size(0) * i] = x * C[i1 + C.size(0) * i];
          }
        }
      }
    }

    *flag = b_flag;
  }
}

// End of code generation (calcEllipsoid.cpp)
