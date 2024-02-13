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
    real_T kn_ptr_im;
    real_T kn_ptr_re;
    int32_T i;
    int32_T loop_ub;

    //  New Matlab version of reflectivity
    //  with complex rho...
    //  Pre-allocation
    M_tot[0][0].re = 0.0;
    M_tot[0][0].im = 0.0;
    M_res[0][0].re = 0.0;
    M_res[0][0].im = 0.0;
    M_tot[0][1].re = 0.0;
    M_tot[0][1].im = 0.0;
    M_res[0][1].re = 0.0;
    M_res[0][1].im = 0.0;
    M_tot[1][0].re = 0.0;
    M_tot[1][0].im = 0.0;
    M_tot[1][1].re = 0.0;
    M_tot[1][1].im = 0.0;
    kn_ptr_re = 0.0;
    kn_ptr_im = 0.0;
    ref.set_size(q.size(0));
    loop_ub = q.size(0);
    for (i = 0; i < loop_ub; i++) {
      ref[i] = 0.0;
    }

    i = q.size(0);
    for (int32_T points{0}; points < i; points++) {
      real_T brm;
      real_T bulk_in_SLD_im;
      real_T bulk_in_SLD_re;
      real_T k0;
      real_T k0_im;
      real_T sgnbr;
      bulk_in_SLD_re = layers_rho[0].re;
      bulk_in_SLD_im = layers_rho[0].im + 1.0E-30;
      k0 = q[points] / 2.0;
      loop_ub = static_cast<int32_T>(N - 1.0);
      for (int32_T n{0}; n < loop_ub; n++) {
        if (n + 1U == 1U) {
          real_T ar;
          real_T br;
          real_T d;
          real_T k0_re;
          real_T k1_im;
          real_T k1_re;
          real_T r01_im;
          real_T r01_re;
          real_T re;

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
          k0_re = k0 * k0 - 12.566370614359172 * (layers_rho[1].re -
            bulk_in_SLD_re);
          k0_im = 0.0 - 12.566370614359172 * (layers_rho[1].im - bulk_in_SLD_im);
          re = k0_re * M_n_tmp.re - k0_im * M_n_tmp.im;
          k0_im = k0_re * M_n_tmp.im + k0_im * M_n_tmp.re;
          M_n_tmp.re = re;
          M_n_tmp.im = k0_im;
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
          d = layers_sig[1] * layers_sig[1];
          dc.re = d * (k0 * (-2.0 * k1_re));
          dc.im = d * (k0 * (-2.0 * k1_im));
          coder::b_exp(&dc);
          ar = k0 - k1_re;
          br = k0 + k1_re;
          if (k1_im == 0.0) {
            k0_re = ar / br;
            k0_im = 0.0;
          } else if (br == 0.0) {
            if (ar == 0.0) {
              k0_re = (0.0 - k1_im) / k1_im;
              k0_im = 0.0;
            } else if (0.0 - k1_im == 0.0) {
              k0_re = 0.0;
              k0_im = -(ar / k1_im);
            } else {
              k0_re = (0.0 - k1_im) / k1_im;
              k0_im = -(ar / k1_im);
            }
          } else {
            brm = std::abs(br);
            k0_im = std::abs(k1_im);
            if (brm > k0_im) {
              brm = k1_im / br;
              k0_im = br + brm * k1_im;
              k0_re = (ar + brm * (0.0 - k1_im)) / k0_im;
              k0_im = ((0.0 - k1_im) - brm * ar) / k0_im;
            } else if (k0_im == brm) {
              if (br > 0.0) {
                sgnbr = 0.5;
              } else {
                sgnbr = -0.5;
              }

              if (k1_im > 0.0) {
                k0_im = 0.5;
              } else {
                k0_im = -0.5;
              }

              k0_re = (ar * sgnbr + (0.0 - k1_im) * k0_im) / brm;
              k0_im = ((0.0 - k1_im) * sgnbr - ar * k0_im) / brm;
            } else {
              brm = br / k1_im;
              k0_im = k1_im + brm * br;
              k0_re = (brm * ar + (0.0 - k1_im)) / k0_im;
              k0_im = (brm * (0.0 - k1_im) - ar) / k0_im;
            }
          }

          r01_re = k0_re * dc.re - k0_im * dc.im;
          r01_im = k0_re * dc.im + k0_im * dc.re;

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
        } else {
          real_T ai;
          real_T ar;
          real_T beta_im;
          real_T beta_re;
          real_T br;
          real_T d;
          real_T d1;
          real_T k0_re;
          real_T knp1_im;
          real_T knp1_re;
          real_T r_n_np1_im;
          real_T r_n_np1_re;
          real_T re;

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
          k0_re = k0 * k0 - 12.566370614359172 * (layers_rho[n + 1].re -
            bulk_in_SLD_re);
          k0_im = 0.0 - 12.566370614359172 * (layers_rho[n + 1].im -
            bulk_in_SLD_im);
          re = k0_re * M_n_tmp.re - k0_im * M_n_tmp.im;
          k0_im = k0_re * M_n_tmp.im + k0_im * M_n_tmp.re;
          M_n_tmp.re = re;
          M_n_tmp.im = k0_im;
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
          k0_im = -2.0 * kn_ptr_im;
          d = layers_sig[n + 1];
          d *= d;
          dc.re = d * (re * knp1_re - k0_im * knp1_im);
          dc.im = d * (re * knp1_im + k0_im * knp1_re);
          coder::b_exp(&dc);
          ar = kn_ptr_re - knp1_re;
          ai = kn_ptr_im - knp1_im;
          br = kn_ptr_re + knp1_re;
          re = kn_ptr_im + knp1_im;
          if (re == 0.0) {
            if (ai == 0.0) {
              k0_re = ar / br;
              k0_im = 0.0;
            } else if (ar == 0.0) {
              k0_re = 0.0;
              k0_im = ai / br;
            } else {
              k0_re = ar / br;
              k0_im = ai / br;
            }
          } else if (br == 0.0) {
            if (ar == 0.0) {
              k0_re = ai / re;
              k0_im = 0.0;
            } else if (ai == 0.0) {
              k0_re = 0.0;
              k0_im = -(ar / re);
            } else {
              k0_re = ai / re;
              k0_im = -(ar / re);
            }
          } else {
            brm = std::abs(br);
            k0_im = std::abs(re);
            if (brm > k0_im) {
              brm = re / br;
              k0_im = br + brm * re;
              k0_re = (ar + brm * ai) / k0_im;
              k0_im = (ai - brm * ar) / k0_im;
            } else if (k0_im == brm) {
              if (br > 0.0) {
                sgnbr = 0.5;
              } else {
                sgnbr = -0.5;
              }

              if (re > 0.0) {
                k0_im = 0.5;
              } else {
                k0_im = -0.5;
              }

              k0_re = (ar * sgnbr + ai * k0_im) / brm;
              k0_im = (ai * sgnbr - ar * k0_im) / brm;
            } else {
              brm = br / re;
              k0_im = re + brm * br;
              k0_re = (brm * ar + ai) / k0_im;
              k0_im = (brm * ai - ar) / k0_im;
            }
          }

          r_n_np1_re = k0_re * dc.re - k0_im * dc.im;
          r_n_np1_im = k0_re * dc.im + k0_im * dc.re;

          //  Find the Phase Factor = (k_n * d_n)
          kn_ptr_re *= layers_thick[n];
          kn_ptr_im *= layers_thick[n];
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
          d = M_n[0][0].re;
          ar = M_n[0][0].im;
          d1 = r_n_np1_re * M_n_tmp.re - r_n_np1_im * M_n_tmp.im;
          k0_im = r_n_np1_re * M_n_tmp.im + r_n_np1_im * M_n_tmp.re;
          re = M_n[1][0].re;
          k0_re = M_n[1][0].im;
          for (int32_T i1{0}; i1 < 2; i1++) {
            br = M_tot[0][i1].re;
            brm = M_tot[0][i1].im;
            sgnbr = M_tot[1][i1].re;
            ai = M_tot[1][i1].im;
            M_res[0][i1].re = (br * d - brm * ar) + (sgnbr * d1 - ai * k0_im);
            M_res[0][i1].im = (br * ar + brm * d) + (sgnbr * k0_im + ai * d1);
            M_res[1][i1].re = (br * re - brm * k0_re) + (sgnbr * M_n_tmp.re - ai
              * M_n_tmp.im);
            M_res[1][i1].im = (br * k0_re + brm * re) + (sgnbr * M_n_tmp.im + ai
              * M_n_tmp.re);
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
        k0_im = std::abs(M_res[0][0].im);
        if (brm > k0_im) {
          brm = M_res[0][0].im / M_res[0][0].re;
          k0_im = M_res[0][0].re + brm * M_res[0][0].im;
          M_n_tmp.re = (M_res[0][1].re + brm * M_res[0][1].im) / k0_im;
          M_n_tmp.im = (M_res[0][1].im - brm * M_res[0][1].re) / k0_im;
        } else if (k0_im == brm) {
          if (M_res[0][0].re > 0.0) {
            sgnbr = 0.5;
          } else {
            sgnbr = -0.5;
          }

          if (M_res[0][0].im > 0.0) {
            k0_im = 0.5;
          } else {
            k0_im = -0.5;
          }

          M_n_tmp.re = (M_res[0][1].re * sgnbr + M_res[0][1].im * k0_im) / brm;
          M_n_tmp.im = (M_res[0][1].im * sgnbr - M_res[0][1].re * k0_im) / brm;
        } else {
          brm = M_res[0][0].re / M_res[0][0].im;
          k0_im = M_res[0][0].im + brm * M_res[0][0].re;
          M_n_tmp.re = (brm * M_res[0][1].re + M_res[0][1].im) / k0_im;
          M_n_tmp.im = (brm * M_res[0][1].im - M_res[0][1].re) / k0_im;
        }
      }

      k0_im = rt_hypotd_snf(M_n_tmp.re, M_n_tmp.im);
      ref[points] = k0_im * k0_im;
    }
  }
}

// End of code generation (abelesSingle.cpp)
