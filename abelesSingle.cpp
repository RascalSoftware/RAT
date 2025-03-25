//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include "findkn.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void abelesSingle(const ::coder::array<double, 1U> &q, double N, const ::coder::
                    array<double, 1U> &layersThick, const ::coder::array<creal_T,
                    1U> &layersRho, const ::coder::array<double, 1U>
                    &layersSigma, ::coder::array<double, 1U> &ref)
  {
    creal_T M_n[2][2];
    creal_T M_res[2][2];
    creal_T M_tot[2][2];
    creal_T M_n_tmp;
    creal_T b_layersRho;
    double M_n_tmp_tmp;
    double bulkInSLD_im;
    double bulkInSLD_re;
    int i;
    int i1;
    int loop_ub;

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
    if (i - 1 >= 0) {
      bulkInSLD_re = layersRho[0].re;
      bulkInSLD_im = layersRho[0].im + 1.0E-30;
      b_layersRho.re = layersRho[1].re - layersRho[0].re;
      b_layersRho.im = layersRho[1].im - (layersRho[0].im + 1.0E-30);
      M_n_tmp_tmp = layersSigma[1] * layersSigma[1];
      i1 = static_cast<int>((N - 1.0) - 1.0);
    }

    for (int points{0}; points < i; points++) {
      creal_T k1;
      double ar;
      double br;
      double brm;
      double k0;
      double k0_im;
      double k0_re;
      double kn_ptr_im;
      double kn_ptr_re;
      double r01_im;
      double r01_re;
      k0 = 0.5 * q[points];

      //  Find k1..
      k1 = findkn(k0, b_layersRho);

      //  Find r01
      M_n_tmp.re = M_n_tmp_tmp * (k0 * (-2.0 * k1.re));
      M_n_tmp.im = M_n_tmp_tmp * (k0 * (-2.0 * k1.im));
      coder::b_exp(M_n_tmp);
      ar = k0 - k1.re;
      br = k0 + k1.re;
      if (k1.im == 0.0) {
        k0_re = ar / br;
        k0_im = 0.0;
      } else if (br == 0.0) {
        if (ar == 0.0) {
          k0_re = (0.0 - k1.im) / k1.im;
          k0_im = 0.0;
        } else if (0.0 - k1.im == 0.0) {
          k0_re = 0.0;
          k0_im = -(ar / k1.im);
        } else {
          k0_re = (0.0 - k1.im) / k1.im;
          k0_im = -(ar / k1.im);
        }
      } else {
        brm = std::abs(br);
        k0_im = std::abs(k1.im);
        if (brm > k0_im) {
          brm = k1.im / br;
          k0_im = br + brm * k1.im;
          k0_re = (ar + brm * (0.0 - k1.im)) / k0_im;
          k0_im = ((0.0 - k1.im) - brm * ar) / k0_im;
        } else if (k0_im == brm) {
          if (br > 0.0) {
            br = 0.5;
          } else {
            br = -0.5;
          }

          if (k1.im > 0.0) {
            k0_im = 0.5;
          } else {
            k0_im = -0.5;
          }

          k0_re = (ar * br + (0.0 - k1.im) * k0_im) / brm;
          k0_im = ((0.0 - k1.im) * br - ar * k0_im) / brm;
        } else {
          brm = br / k1.im;
          k0_im = k1.im + brm * br;
          k0_re = (brm * ar + (0.0 - k1.im)) / k0_im;
          k0_im = (brm * (0.0 - k1.im) - ar) / k0_im;
        }
      }

      r01_re = k0_re * M_n_tmp.re - k0_im * M_n_tmp.im;
      r01_im = k0_re * M_n_tmp.im + k0_im * M_n_tmp.re;

      //  Generate the M1 matrix:
      M_tot[0][0].re = 1.0;
      M_tot[0][0].im = 0.0;
      M_tot[1][0].re = r01_re;
      M_tot[1][0].im = r01_im;
      M_tot[0][1].re = r01_re;
      M_tot[0][1].im = r01_im;
      M_tot[1][1].re = 1.0;
      M_tot[1][1].im = 0.0;
      kn_ptr_re = k1.re;
      kn_ptr_im = k1.im;
      for (int n{0}; n < i1; n++) {
        creal_T c_layersRho;
        creal_T knp1;
        double ai;
        double b_kn_ptr_re;
        double beta_im;
        double beta_re;
        double d;
        double d1;
        double d2;
        double r_n_np1_im;
        double r_n_np1_re;

        //  Find kn and k_n+1 (ex. k1 and k2 for n=1): _/
        c_layersRho.re = layersRho[n + 2].re - bulkInSLD_re;
        c_layersRho.im = layersRho[n + 2].im - bulkInSLD_im;
        knp1 = findkn(k0, c_layersRho);

        //  Find r_n,n+1:
        k0_im = -2.0 * kn_ptr_re;
        k0_re = -2.0 * kn_ptr_im;
        br = layersSigma[n + 2];
        br *= br;
        M_n_tmp.re = br * (k0_im * knp1.re - k0_re * knp1.im);
        M_n_tmp.im = br * (k0_im * knp1.im + k0_re * knp1.re);
        coder::b_exp(M_n_tmp);
        ar = kn_ptr_re - knp1.re;
        ai = kn_ptr_im - knp1.im;
        br = kn_ptr_re + knp1.re;
        k0_re = kn_ptr_im + knp1.im;
        if (k0_re == 0.0) {
          if (ai == 0.0) {
            b_kn_ptr_re = ar / br;
            k0_im = 0.0;
          } else if (ar == 0.0) {
            b_kn_ptr_re = 0.0;
            k0_im = ai / br;
          } else {
            b_kn_ptr_re = ar / br;
            k0_im = ai / br;
          }
        } else if (br == 0.0) {
          if (ar == 0.0) {
            b_kn_ptr_re = ai / k0_re;
            k0_im = 0.0;
          } else if (ai == 0.0) {
            b_kn_ptr_re = 0.0;
            k0_im = -(ar / k0_re);
          } else {
            b_kn_ptr_re = ai / k0_re;
            k0_im = -(ar / k0_re);
          }
        } else {
          brm = std::abs(br);
          k0_im = std::abs(k0_re);
          if (brm > k0_im) {
            brm = k0_re / br;
            k0_im = br + brm * k0_re;
            b_kn_ptr_re = (ar + brm * ai) / k0_im;
            k0_im = (ai - brm * ar) / k0_im;
          } else if (k0_im == brm) {
            if (br > 0.0) {
              br = 0.5;
            } else {
              br = -0.5;
            }

            if (k0_re > 0.0) {
              k0_im = 0.5;
            } else {
              k0_im = -0.5;
            }

            b_kn_ptr_re = (ar * br + ai * k0_im) / brm;
            k0_im = (ai * br - ar * k0_im) / brm;
          } else {
            brm = br / k0_re;
            k0_im = k0_re + brm * br;
            b_kn_ptr_re = (brm * ar + ai) / k0_im;
            k0_im = (brm * ai - ar) / k0_im;
          }
        }

        r_n_np1_re = b_kn_ptr_re * M_n_tmp.re - k0_im * M_n_tmp.im;
        r_n_np1_im = b_kn_ptr_re * M_n_tmp.im + k0_im * M_n_tmp.re;

        //  Find the Phase Factor = (k_n * d_n)
        k0_im = layersThick[n + 1];
        kn_ptr_re *= k0_im;
        kn_ptr_im *= k0_im;
        beta_re = kn_ptr_re * 0.0 - kn_ptr_im;
        beta_im = kn_ptr_re + kn_ptr_im * 0.0;

        //  Create the M_n matrix: _/
        M_n_tmp.re = beta_re;
        M_n_tmp.im = beta_im;
        coder::b_exp(M_n_tmp);
        M_n[0][0] = M_n_tmp;
        M_n[1][0].re = r_n_np1_re * M_n_tmp.re - r_n_np1_im * M_n_tmp.im;
        M_n[1][0].im = r_n_np1_re * M_n_tmp.im + r_n_np1_im * M_n_tmp.re;
        M_n_tmp.re = -beta_re;
        M_n_tmp.im = -beta_im;
        coder::b_exp(M_n_tmp);

        //  Multiply the matrices
        d = M_n[0][0].re;
        d1 = M_n[0][0].im;
        d2 = r_n_np1_re * M_n_tmp.re - r_n_np1_im * M_n_tmp.im;
        k0_im = r_n_np1_re * M_n_tmp.im + r_n_np1_im * M_n_tmp.re;
        k0_re = M_n[1][0].re;
        br = M_n[1][0].im;
        for (loop_ub = 0; loop_ub < 2; loop_ub++) {
          brm = M_tot[0][loop_ub].re;
          ai = M_tot[0][loop_ub].im;
          ar = M_tot[1][loop_ub].re;
          b_kn_ptr_re = M_tot[1][loop_ub].im;
          M_res[0][loop_ub].re = (brm * d - ai * d1) + (ar * d2 - b_kn_ptr_re *
            k0_im);
          M_res[0][loop_ub].im = (brm * d1 + ai * d) + (ar * k0_im + b_kn_ptr_re
            * d2);
          M_res[1][loop_ub].re = (brm * k0_re - ai * br) + (ar * M_n_tmp.re -
            b_kn_ptr_re * M_n_tmp.im);
          M_res[1][loop_ub].im = (brm * br + ai * k0_re) + (ar * M_n_tmp.im +
            b_kn_ptr_re * M_n_tmp.re);
        }

        //  Reassign the values back to M_tot:
        M_tot[0][0] = M_res[0][0];
        M_tot[0][1] = M_res[0][1];
        M_tot[1][0] = M_res[1][0];
        M_tot[1][1] = M_res[1][1];

        //  Point to k_n+1 and sld_n+1 via kn_ptr sld_n_ptr:
        kn_ptr_re = knp1.re;
        kn_ptr_im = knp1.im;
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
            br = 0.5;
          } else {
            br = -0.5;
          }

          if (M_res[0][0].im > 0.0) {
            k0_im = 0.5;
          } else {
            k0_im = -0.5;
          }

          M_n_tmp.re = (M_res[0][1].re * br + M_res[0][1].im * k0_im) / brm;
          M_n_tmp.im = (M_res[0][1].im * br - M_res[0][1].re * k0_im) / brm;
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
