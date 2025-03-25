//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// abelesParallelPoints.cpp
//
// Code generation for function 'abelesParallelPoints'
//

// Include files
#include "abelesParallelPoints.h"
#include "RATMain_data.h"
#include "RATMain_rtwutil.h"
#include "exp.h"
#include "findkn.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void abelesParallelPoints(const ::coder::array<double, 1U> &q, double N, const
    ::coder::array<double, 1U> &layersThick, const ::coder::array<creal_T, 1U>
    &layersRho, const ::coder::array<double, 1U> &layersSigma, ::coder::array<
    double, 1U> &ref)
  {
    creal_T M_n[2][2];
    creal_T M_res[2][2];
    creal_T M_tot[2][2];
    creal_T M_n_tmp;
    creal_T beta;
    creal_T bulkInSLD;
    creal_T denom1;
    creal_T denom_n;
    creal_T err1;
    creal_T err_n;
    creal_T k1;
    creal_T kn_ptr;
    creal_T knp1;
    creal_T layersRho1;
    creal_T layersRho2;
    creal_T nom1;
    creal_T nom_n;
    creal_T r01;
    creal_T r_n_np1;
    creal_T sld_1;
    creal_T sld_np1;
    double M_tot_re_tmp;
    double R;
    double b_M_tot_re_tmp;
    double b_nom_n_tmp;
    double bim;
    double brm;
    double denom1_tmp;
    double denom_n_tmp;
    double k0;
    double layersSigma2;
    double nom1_re;
    double nom1_tmp;
    double nom_n_tmp;
    double sigmasqrd;
    int i1;
    int i2;
    int loop_ub;
    int n;
    ref.set_size(q.size(0));
    loop_ub = q.size(0);
    for (int i{0}; i < loop_ub; i++) {
      ref[i] = 0.0;
    }

    layersRho1 = layersRho[0];
    layersRho2 = layersRho[1];
    layersSigma2 = layersSigma[1];
    loop_ub = q.size(0) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(beta,r_n_np1,err_n,sigmasqrd,denom_n,nom_n,knp1,sld_np1,R,kn_ptr,r01,err1,denom1,nom1,k1,sld_1,k0,bulkInSLD,M_res,M_n,M_tot,nom1_tmp,denom1_tmp,nom1_re,i1,n,nom_n_tmp,b_nom_n_tmp,denom_n_tmp,bim,M_n_tmp,brm,i2,M_tot_re_tmp,b_M_tot_re_tmp)

    for (int points = 0; points <= loop_ub; points++) {
      M_res[0][0].re = 0.0;
      M_res[0][0].im = 0.0;
      M_res[0][1].re = 0.0;
      M_res[0][1].im = 0.0;
      bulkInSLD.re = layersRho1.re;
      bulkInSLD.im = layersRho1.im + 1.0E-30;
      k0 = 0.5 * q[points];

      //  Find k1..
      sld_1.re = layersRho2.re - layersRho1.re;
      sld_1.im = layersRho2.im - (layersRho1.im + 1.0E-30);
      k1 = findkn(k0, sld_1);

      //  Find r01
      nom1_tmp = k0 - k1.re;
      denom1_tmp = k0 + k1.re;
      sigmasqrd = layersSigma2 * layersSigma2;
      err1.re = sigmasqrd * (k0 * (-2.0 * k1.re));
      err1.im = sigmasqrd * (k0 * (-2.0 * k1.im));
      coder::b_exp(err1);
      if (k1.im == 0.0) {
        nom1_re = nom1_tmp / denom1_tmp;
        denom1_tmp = 0.0;
      } else if (denom1_tmp == 0.0) {
        if (nom1_tmp == 0.0) {
          nom1_re = (0.0 - k1.im) / k1.im;
          denom1_tmp = 0.0;
        } else if (0.0 - k1.im == 0.0) {
          nom1_re = 0.0;
          denom1_tmp = -(nom1_tmp / k1.im);
        } else {
          nom1_re = (0.0 - k1.im) / k1.im;
          denom1_tmp = -(nom1_tmp / k1.im);
        }
      } else {
        brm = std::abs(denom1_tmp);
        bim = std::abs(k1.im);
        if (brm > bim) {
          brm = k1.im / denom1_tmp;
          bim = denom1_tmp + brm * k1.im;
          nom1_re = (nom1_tmp + brm * (0.0 - k1.im)) / bim;
          denom1_tmp = ((0.0 - k1.im) - brm * nom1_tmp) / bim;
        } else if (bim == brm) {
          if (denom1_tmp > 0.0) {
            bim = 0.5;
          } else {
            bim = -0.5;
          }

          if (k1.im > 0.0) {
            denom1_tmp = 0.5;
          } else {
            denom1_tmp = -0.5;
          }

          nom1_re = (nom1_tmp * bim + (0.0 - k1.im) * denom1_tmp) / brm;
          denom1_tmp = ((0.0 - k1.im) * bim - nom1_tmp * denom1_tmp) / brm;
        } else {
          brm = denom1_tmp / k1.im;
          bim = k1.im + brm * denom1_tmp;
          nom1_re = (brm * nom1_tmp + (0.0 - k1.im)) / bim;
          denom1_tmp = (brm * (0.0 - k1.im) - nom1_tmp) / bim;
        }
      }

      r01.re = nom1_re * err1.re - denom1_tmp * err1.im;
      r01.im = nom1_re * err1.im + denom1_tmp * err1.re;

      //  Generate the M1 matrix:
      M_tot[0][0].re = 1.0;
      M_tot[0][0].im = 0.0;
      M_tot[1][0] = r01;
      M_tot[0][1] = r01;
      M_tot[1][1].re = 1.0;
      M_tot[1][1].im = 0.0;
      kn_ptr = k1;
      i1 = static_cast<int>((N - 1.0) - 1.0);
      for (n = 0; n < i1; n++) {
        //  Find kn and k_n+1 (ex. k1 and k2 for n=1): _/
        sld_np1.re = layersRho[n + 2].re - bulkInSLD.re;
        sld_np1.im = layersRho[n + 2].im - bulkInSLD.im;
        knp1 = findkn(k0, sld_np1);

        //  Find r_n,n+1:
        nom_n_tmp = kn_ptr.re - knp1.re;
        b_nom_n_tmp = kn_ptr.im - knp1.im;
        nom1_tmp = kn_ptr.re + knp1.re;
        denom_n_tmp = kn_ptr.im + knp1.im;
        denom1_tmp = layersSigma[n + 2];
        sigmasqrd = denom1_tmp * denom1_tmp;
        denom1_tmp = -2.0 * kn_ptr.re;
        bim = -2.0 * kn_ptr.im;
        err_n.re = sigmasqrd * (denom1_tmp * knp1.re - bim * knp1.im);
        err_n.im = sigmasqrd * (denom1_tmp * knp1.im + bim * knp1.re);
        coder::b_exp(err_n);
        if (denom_n_tmp == 0.0) {
          if (b_nom_n_tmp == 0.0) {
            nom1_re = nom_n_tmp / nom1_tmp;
            denom1_tmp = 0.0;
          } else if (nom_n_tmp == 0.0) {
            nom1_re = 0.0;
            denom1_tmp = b_nom_n_tmp / nom1_tmp;
          } else {
            nom1_re = nom_n_tmp / nom1_tmp;
            denom1_tmp = b_nom_n_tmp / nom1_tmp;
          }
        } else if (nom1_tmp == 0.0) {
          if (nom_n_tmp == 0.0) {
            nom1_re = b_nom_n_tmp / denom_n_tmp;
            denom1_tmp = 0.0;
          } else if (b_nom_n_tmp == 0.0) {
            nom1_re = 0.0;
            denom1_tmp = -(nom_n_tmp / denom_n_tmp);
          } else {
            nom1_re = b_nom_n_tmp / denom_n_tmp;
            denom1_tmp = -(nom_n_tmp / denom_n_tmp);
          }
        } else {
          brm = std::abs(nom1_tmp);
          bim = std::abs(denom_n_tmp);
          if (brm > bim) {
            brm = denom_n_tmp / nom1_tmp;
            bim = nom1_tmp + brm * denom_n_tmp;
            nom1_re = (nom_n_tmp + brm * b_nom_n_tmp) / bim;
            denom1_tmp = (b_nom_n_tmp - brm * nom_n_tmp) / bim;
          } else if (bim == brm) {
            if (nom1_tmp > 0.0) {
              bim = 0.5;
            } else {
              bim = -0.5;
            }

            if (denom_n_tmp > 0.0) {
              denom1_tmp = 0.5;
            } else {
              denom1_tmp = -0.5;
            }

            nom1_re = (nom_n_tmp * bim + b_nom_n_tmp * denom1_tmp) / brm;
            denom1_tmp = (b_nom_n_tmp * bim - nom_n_tmp * denom1_tmp) / brm;
          } else {
            brm = nom1_tmp / denom_n_tmp;
            bim = denom_n_tmp + brm * nom1_tmp;
            nom1_re = (brm * nom_n_tmp + b_nom_n_tmp) / bim;
            denom1_tmp = (brm * b_nom_n_tmp - nom_n_tmp) / bim;
          }
        }

        r_n_np1.re = nom1_re * err_n.re - denom1_tmp * err_n.im;
        r_n_np1.im = nom1_re * err_n.im + denom1_tmp * err_n.re;

        //  Find the Phase Factor = (k_n * d_n)
        denom1_tmp = layersThick[n + 1];
        bim = denom1_tmp * kn_ptr.re;
        denom1_tmp *= kn_ptr.im;
        beta.re = bim * 0.0 - denom1_tmp;
        beta.im = bim + denom1_tmp * 0.0;

        //  Create the M_n matrix: _/
        M_n_tmp = beta;
        coder::b_exp(M_n_tmp);
        M_n[0][0] = M_n_tmp;
        M_n[1][0].re = r_n_np1.re * M_n_tmp.re - r_n_np1.im * M_n_tmp.im;
        M_n[1][0].im = r_n_np1.re * M_n_tmp.im + r_n_np1.im * M_n_tmp.re;
        M_n_tmp.re = -beta.re;
        M_n_tmp.im = -beta.im;
        coder::b_exp(M_n_tmp);
        M_n[0][1].re = r_n_np1.re * M_n_tmp.re - r_n_np1.im * M_n_tmp.im;
        M_n[0][1].im = r_n_np1.re * M_n_tmp.im + r_n_np1.im * M_n_tmp.re;

        //  Multiply the matrices
        denom1_tmp = M_n[0][0].re;
        nom1_re = M_n[0][0].im;
        bim = M_n[0][1].re;
        nom1_tmp = M_n[0][1].im;
        brm = M_n[1][0].re;
        denom_n_tmp = M_n[1][0].im;
        for (i2 = 0; i2 < 2; i2++) {
          nom_n_tmp = M_tot[0][i2].re;
          b_nom_n_tmp = M_tot[0][i2].im;
          M_tot_re_tmp = M_tot[1][i2].re;
          b_M_tot_re_tmp = M_tot[1][i2].im;
          M_res[0][i2].re = (nom_n_tmp * denom1_tmp - b_nom_n_tmp * nom1_re) +
            (M_tot_re_tmp * bim - b_M_tot_re_tmp * nom1_tmp);
          M_res[0][i2].im = (nom_n_tmp * nom1_re + b_nom_n_tmp * denom1_tmp) +
            (M_tot_re_tmp * nom1_tmp + b_M_tot_re_tmp * bim);
          M_res[1][i2].re = (nom_n_tmp * brm - b_nom_n_tmp * denom_n_tmp) +
            (M_tot_re_tmp * M_n_tmp.re - b_M_tot_re_tmp * M_n_tmp.im);
          M_res[1][i2].im = (nom_n_tmp * denom_n_tmp + b_nom_n_tmp * brm) +
            (M_tot_re_tmp * M_n_tmp.im + b_M_tot_re_tmp * M_n_tmp.re);
        }

        //  Reassign the values back to M_tot:
        M_tot[0][0] = M_res[0][0];
        M_tot[0][1] = M_res[0][1];
        M_tot[1][0] = M_res[1][0];
        M_tot[1][1] = M_res[1][1];

        //  Point to k_n+1 and sld_n+1 via kn_ptr sld_n_ptr:
        kn_ptr = knp1;
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
        bim = std::abs(M_res[0][0].im);
        if (brm > bim) {
          brm = M_res[0][0].im / M_res[0][0].re;
          bim = M_res[0][0].re + brm * M_res[0][0].im;
          M_n_tmp.re = (M_res[0][1].re + brm * M_res[0][1].im) / bim;
          M_n_tmp.im = (M_res[0][1].im - brm * M_res[0][1].re) / bim;
        } else if (bim == brm) {
          if (M_res[0][0].re > 0.0) {
            bim = 0.5;
          } else {
            bim = -0.5;
          }

          if (M_res[0][0].im > 0.0) {
            denom1_tmp = 0.5;
          } else {
            denom1_tmp = -0.5;
          }

          M_n_tmp.re = (M_res[0][1].re * bim + M_res[0][1].im * denom1_tmp) /
            brm;
          M_n_tmp.im = (M_res[0][1].im * bim - M_res[0][1].re * denom1_tmp) /
            brm;
        } else {
          brm = M_res[0][0].re / M_res[0][0].im;
          bim = M_res[0][0].im + brm * M_res[0][0].re;
          M_n_tmp.re = (brm * M_res[0][1].re + M_res[0][1].im) / bim;
          M_n_tmp.im = (brm * M_res[0][1].im - M_res[0][1].re) / bim;
        }
      }

      R = rt_hypotd_snf(M_n_tmp.re, M_n_tmp.im);
      ref[points] = R * R;
    }
  }
}

// End of code generation (abelesParallelPoints.cpp)
