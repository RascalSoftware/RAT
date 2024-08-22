//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// abelesSingle.cpp
//
// Code generation for function 'abelesSingle'
//

// Include files
#include "abelesSingle.h"
#include "RATMain_data.h"
#include "RATMain_rtwutil.h"
#include "exp.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void abelesSingle(const ::coder::array<real_T, 1U> &q, real_T N, const ::coder::
                    array<real_T, 1U> &layers_thick, const ::coder::array<
                    creal_T, 1U> &layers_rho, const ::coder::array<real_T, 1U>
                    &layers_sig, ::coder::array<real_T, 1U> &ref)
  {
    creal_T M_n[2][2];
    creal_T M_res[2][2];
    creal_T M_tot[2][2];
    creal_T M_n_tmp;
    creal_T dc;
    real_T bulk_in_SLD_im;
    real_T bulk_in_SLD_re;
    real_T d;
    real_T k0_im;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;

    //  New Matlab version of reflectivity
    //  with complex rho...
    //  Pre-allocation
    M_res[0][0].re = 0.0;
    M_res[0][0].im = 0.0;
    M_res[0][1].re = 0.0;
    M_res[0][1].im = 0.0;
    ref.set_size(q.size(0));
    loop_ub = q.size(0);
    for (i = 0; i < loop_ub; i++) {
      ref[i] = 0.0;
    }

    i = q.size(0);
    if (0 <= i - 1) {
      bulk_in_SLD_re = layers_rho[0].re;
      bulk_in_SLD_im = layers_rho[0].im + 1.0E-30;
      k0_im = 0.0 - 12.566370614359172 * (layers_rho[1].im - (layers_rho[0].im +
        1.0E-30));
      d = layers_sig[1] * layers_sig[1];
      i1 = static_cast<int32_T>((N - 1.0) + -1.0);
    }

    for (int32_T points{0}; points < i; points++) {
      real_T ar;
      real_T br;
      real_T brm;
      real_T im;
      real_T k0;
      real_T k0_re;
      real_T k0_re_tmp;
      real_T k1_im;
      real_T k1_re;
      real_T kn_ptr_im;
      real_T kn_ptr_re;
      real_T r01_im;
      real_T r01_re;
      real_T re;
      real_T sgnbr;
      k0 = q[points] / 2.0;

      //  Find k1..
      //  sqrt function with branch cut in zarg from 0 to infinity along a ray
      //  at angle theta (in radians) measured from the +x axis in the usual way,
      //  with -pi<=theta<=pi.  theta = pi is the usual square root.
      //  for zarg on the +x axis, sqrt behavior is conserved,
      //  i.e. sqrtbc(theta,zarg) is positive and real for any theta.
      //
      //  y = sqrtbc(theta,zarg)
      dc.re = 0.0;
      dc.im = -0.78539816339744828;
      coder::b_exp(&dc);
      M_n_tmp.re = 0.0;
      M_n_tmp.im = 1.5707963267948966;
      coder::b_exp(&M_n_tmp);
      k0_re_tmp = k0 * k0;
      k0_re = k0_re_tmp - 12.566370614359172 * (layers_rho[1].re - layers_rho[0]
        .re);
      re = k0_re * M_n_tmp.re - k0_im * M_n_tmp.im;
      im = k0_re * M_n_tmp.im + k0_im * M_n_tmp.re;
      M_n_tmp.re = re;
      M_n_tmp.im = im;
      coder::internal::scalar::d_sqrt(&M_n_tmp);
      k1_re = dc.re * M_n_tmp.re - dc.im * M_n_tmp.im;
      k1_im = dc.re * M_n_tmp.im + dc.im * M_n_tmp.re;

      //  translations:  sqrtbc(theta, z-b) has branch cut in the z plane from
      //  branch point z = b out to infinity, along a ray at angle theta.
      //
      //  for the usual square root with branch cut along -x,
      //  the real part of sqrt(z) is positive (or 0) for all z.
      //  for the modified square root with branch cut along +x,
      //  the imaginary part of sqrt(z) is positive (or 0) for all z.
      //  Find r01
      dc.re = d * (k0 * (-2.0 * k1_re));
      dc.im = d * (k0 * (-2.0 * k1_im));
      coder::b_exp(&dc);
      ar = k0 - k1_re;
      br = k0 + k1_re;
      if (k1_im == 0.0) {
        k0_re = ar / br;
        im = 0.0;
      } else if (br == 0.0) {
        if (ar == 0.0) {
          k0_re = (0.0 - k1_im) / k1_im;
          im = 0.0;
        } else if (0.0 - k1_im == 0.0) {
          k0_re = 0.0;
          im = -(ar / k1_im);
        } else {
          k0_re = (0.0 - k1_im) / k1_im;
          im = -(ar / k1_im);
        }
      } else {
        brm = std::abs(br);
        im = std::abs(k1_im);
        if (brm > im) {
          brm = k1_im / br;
          im = br + brm * k1_im;
          k0_re = (ar + brm * (0.0 - k1_im)) / im;
          im = ((0.0 - k1_im) - brm * ar) / im;
        } else if (im == brm) {
          if (br > 0.0) {
            sgnbr = 0.5;
          } else {
            sgnbr = -0.5;
          }

          if (k1_im > 0.0) {
            im = 0.5;
          } else {
            im = -0.5;
          }

          k0_re = (ar * sgnbr + (0.0 - k1_im) * im) / brm;
          im = ((0.0 - k1_im) * sgnbr - ar * im) / brm;
        } else {
          brm = br / k1_im;
          im = k1_im + brm * br;
          k0_re = (brm * ar + (0.0 - k1_im)) / im;
          im = (brm * (0.0 - k1_im) - ar) / im;
        }
      }

      r01_re = k0_re * dc.re - im * dc.im;
      r01_im = k0_re * dc.im + im * dc.re;

      //  Generate the M1 matrix:
      M_tot[0][0].re = 1.0;
      M_tot[0][0].im = 0.0;
      M_tot[1][0].re = r01_re;
      M_tot[1][0].im = r01_im;
      M_tot[0][1].re = r01_re;
      M_tot[0][1].im = r01_im;
      M_tot[1][1].re = 1.0;
      M_tot[1][1].im = 0.0;
      kn_ptr_re = k1_re;
      kn_ptr_im = k1_im;
      for (int32_T n{0}; n < i1; n++) {
        real_T ai;
        real_T b_kn_ptr_re;
        real_T beta_im;
        real_T beta_re;
        real_T d1;
        real_T knp1_im;
        real_T knp1_re;
        real_T r_n_np1_im;
        real_T r_n_np1_re;

        //  Find kn and k_n+1 (ex. k1 and k2 for n=1): $/
        //  sqrt function with branch cut in zarg from 0 to infinity along a ray
        //  at angle theta (in radians) measured from the +x axis in the usual way,
        //  with -pi<=theta<=pi.  theta = pi is the usual square root.
        //  for zarg on the +x axis, sqrt behavior is conserved,
        //  i.e. sqrtbc(theta,zarg) is positive and real for any theta.
        //
        //  y = sqrtbc(theta,zarg)
        dc.re = 0.0;
        dc.im = -0.78539816339744828;
        coder::b_exp(&dc);
        M_n_tmp.re = 0.0;
        M_n_tmp.im = 1.5707963267948966;
        coder::b_exp(&M_n_tmp);
        k0_re = k0_re_tmp - 12.566370614359172 * (layers_rho[n + 2].re -
          bulk_in_SLD_re);
        im = 0.0 - 12.566370614359172 * (layers_rho[n + 2].im - bulk_in_SLD_im);
        re = k0_re * M_n_tmp.re - im * M_n_tmp.im;
        im = k0_re * M_n_tmp.im + im * M_n_tmp.re;
        M_n_tmp.re = re;
        M_n_tmp.im = im;
        coder::internal::scalar::d_sqrt(&M_n_tmp);
        knp1_re = dc.re * M_n_tmp.re - dc.im * M_n_tmp.im;
        knp1_im = dc.re * M_n_tmp.im + dc.im * M_n_tmp.re;

        //  translations:  sqrtbc(theta, z-b) has branch cut in the z plane from
        //  branch point z = b out to infinity, along a ray at angle theta.
        //
        //  for the usual square root with branch cut along -x,
        //  the real part of sqrt(z) is positive (or 0) for all z.
        //  for the modified square root with branch cut along +x,
        //  the imaginary part of sqrt(z) is positive (or 0) for all z.
        //  Find r_n,n+1:
        re = -2.0 * kn_ptr_re;
        im = -2.0 * kn_ptr_im;
        d1 = layers_sig[n + 2];
        d1 *= d1;
        dc.re = d1 * (re * knp1_re - im * knp1_im);
        dc.im = d1 * (re * knp1_im + im * knp1_re);
        coder::b_exp(&dc);
        ar = kn_ptr_re - knp1_re;
        ai = kn_ptr_im - knp1_im;
        br = kn_ptr_re + knp1_re;
        re = kn_ptr_im + knp1_im;
        if (re == 0.0) {
          if (ai == 0.0) {
            b_kn_ptr_re = ar / br;
            im = 0.0;
          } else if (ar == 0.0) {
            b_kn_ptr_re = 0.0;
            im = ai / br;
          } else {
            b_kn_ptr_re = ar / br;
            im = ai / br;
          }
        } else if (br == 0.0) {
          if (ar == 0.0) {
            b_kn_ptr_re = ai / re;
            im = 0.0;
          } else if (ai == 0.0) {
            b_kn_ptr_re = 0.0;
            im = -(ar / re);
          } else {
            b_kn_ptr_re = ai / re;
            im = -(ar / re);
          }
        } else {
          brm = std::abs(br);
          im = std::abs(re);
          if (brm > im) {
            brm = re / br;
            im = br + brm * re;
            b_kn_ptr_re = (ar + brm * ai) / im;
            im = (ai - brm * ar) / im;
          } else if (im == brm) {
            if (br > 0.0) {
              sgnbr = 0.5;
            } else {
              sgnbr = -0.5;
            }

            if (re > 0.0) {
              im = 0.5;
            } else {
              im = -0.5;
            }

            b_kn_ptr_re = (ar * sgnbr + ai * im) / brm;
            im = (ai * sgnbr - ar * im) / brm;
          } else {
            brm = br / re;
            im = re + brm * br;
            b_kn_ptr_re = (brm * ar + ai) / im;
            im = (brm * ai - ar) / im;
          }
        }

        r_n_np1_re = b_kn_ptr_re * dc.re - im * dc.im;
        r_n_np1_im = b_kn_ptr_re * dc.im + im * dc.re;

        //  Find the Phase Factor = (k_n * d_n)
        im = layers_thick[n + 1];
        kn_ptr_re *= im;
        kn_ptr_im *= im;
        beta_re = kn_ptr_re * 0.0 - kn_ptr_im;
        beta_im = kn_ptr_re + kn_ptr_im * 0.0;

        //  Create the M_n matrix: $/
        M_n_tmp.re = beta_re;
        M_n_tmp.im = beta_im;
        coder::b_exp(&M_n_tmp);
        M_n[0][0] = M_n_tmp;
        M_n[1][0].re = r_n_np1_re * M_n_tmp.re - r_n_np1_im * M_n_tmp.im;
        M_n[1][0].im = r_n_np1_re * M_n_tmp.im + r_n_np1_im * M_n_tmp.re;
        M_n_tmp.re = -beta_re;
        M_n_tmp.im = -beta_im;
        coder::b_exp(&M_n_tmp);

        //  Multiply the matrices
        d1 = M_n[0][0].re;
        b_kn_ptr_re = M_n[0][0].im;
        ar = r_n_np1_re * M_n_tmp.re - r_n_np1_im * M_n_tmp.im;
        im = r_n_np1_re * M_n_tmp.im + r_n_np1_im * M_n_tmp.re;
        re = M_n[1][0].re;
        br = M_n[1][0].im;
        for (loop_ub = 0; loop_ub < 2; loop_ub++) {
          brm = M_tot[0][loop_ub].re;
          sgnbr = M_tot[0][loop_ub].im;
          k0_re = M_tot[1][loop_ub].re;
          ai = M_tot[1][loop_ub].im;
          M_res[0][loop_ub].re = (brm * d1 - sgnbr * b_kn_ptr_re) + (k0_re * ar
            - ai * im);
          M_res[0][loop_ub].im = (brm * b_kn_ptr_re + sgnbr * d1) + (k0_re * im
            + ai * ar);
          M_res[1][loop_ub].re = (brm * re - sgnbr * br) + (k0_re * M_n_tmp.re -
            ai * M_n_tmp.im);
          M_res[1][loop_ub].im = (brm * br + sgnbr * re) + (k0_re * M_n_tmp.im +
            ai * M_n_tmp.re);
        }

        //  Reassign the values back to M_tot:
        M_tot[0][0] = M_res[0][0];
        M_tot[0][1] = M_res[0][1];
        M_tot[1][0] = M_res[1][0];
        M_tot[1][1] = M_res[1][1];

        //  Point to k_n+1 and sld_n+1 via kn_ptr sld_n_ptr:
        kn_ptr_re = knp1_re;
        kn_ptr_im = knp1_im;
      }

      if (M_res[0][0].im == 0.0) {
        if (M_res[0][1].im == 0.0) {
          M_n_tmp.re = M_res[0][1].re / M_res[0][0].re;
          M_n_tmp.im = 0.0;
        } else if (M_res[0][1].re == 0.0) {
          M_n_tmp.re = 0.0;
          M_n_tmp.im = M_res[0][1].im / M_res[0][0].re;
        } else {
          M_n_tmp.re = M_res[0][1].re / M_res[0][0].re;
          M_n_tmp.im = M_res[0][1].im / M_res[0][0].re;
        }
      } else if (M_res[0][0].re == 0.0) {
        if (M_res[0][1].re == 0.0) {
          M_n_tmp.re = M_res[0][1].im / M_res[0][0].im;
          M_n_tmp.im = 0.0;
        } else if (M_res[0][1].im == 0.0) {
          M_n_tmp.re = 0.0;
          M_n_tmp.im = -(M_res[0][1].re / M_res[0][0].im);
        } else {
          M_n_tmp.re = M_res[0][1].im / M_res[0][0].im;
          M_n_tmp.im = -(M_res[0][1].re / M_res[0][0].im);
        }
      } else {
        brm = std::abs(M_res[0][0].re);
        im = std::abs(M_res[0][0].im);
        if (brm > im) {
          brm = M_res[0][0].im / M_res[0][0].re;
          im = M_res[0][0].re + brm * M_res[0][0].im;
          M_n_tmp.re = (M_res[0][1].re + brm * M_res[0][1].im) / im;
          M_n_tmp.im = (M_res[0][1].im - brm * M_res[0][1].re) / im;
        } else if (im == brm) {
          if (M_res[0][0].re > 0.0) {
            sgnbr = 0.5;
          } else {
            sgnbr = -0.5;
          }

          if (M_res[0][0].im > 0.0) {
            im = 0.5;
          } else {
            im = -0.5;
          }

          M_n_tmp.re = (M_res[0][1].re * sgnbr + M_res[0][1].im * im) / brm;
          M_n_tmp.im = (M_res[0][1].im * sgnbr - M_res[0][1].re * im) / brm;
        } else {
          brm = M_res[0][0].re / M_res[0][0].im;
          im = M_res[0][0].im + brm * M_res[0][0].re;
          M_n_tmp.re = (brm * M_res[0][1].re + M_res[0][1].im) / im;
          M_n_tmp.im = (brm * M_res[0][1].im - M_res[0][1].re) / im;
        }
      }

      im = rt_hypotd_snf(M_n_tmp.re, M_n_tmp.im);
      ref[points] = im * im;
    }
  }
}

// End of code generation (abelesSingle.cpp)
