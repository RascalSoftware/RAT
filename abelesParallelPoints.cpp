//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static creal_T findkn(real_T k0, const creal_T sld);
}

// Function Definitions
namespace RAT
{
  static creal_T findkn(real_T k0, const creal_T sld)
  {
    creal_T dc;
    creal_T dc1;
    creal_T kn;
    real_T k0_im;
    real_T k0_re;
    real_T re;

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
    dc1.re = 0.0;
    dc1.im = 1.5707963267948966;
    coder::b_exp(&dc1);
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

  void abelesParallelPoints(const ::coder::array<real_T, 1U> &q, real_T N, const
    ::coder::array<real_T, 1U> &layers_thick, const ::coder::array<creal_T, 1U>
    &layers_rho, const ::coder::array<real_T, 1U> &layers_sig, ::coder::array<
    real_T, 1U> &ref)
  {
    creal_T M_n[2][2];
    creal_T M_res[2][2];
    creal_T M_tot[2][2];
    creal_T M_n_tmp;
    creal_T beta;
    creal_T bulk_in_SLD;
    creal_T denom1;
    creal_T denom_n;
    creal_T err1;
    creal_T err_n;
    creal_T k1;
    creal_T kn_ptr;
    creal_T knp1;
    creal_T nom1;
    creal_T nom_n;
    creal_T r01;
    creal_T r_n_np1;
    creal_T sld_1;
    creal_T sld_np1;
    real_T R;
    real_T brm;
    real_T d;
    real_T d1;
    real_T d2;
    real_T d3;
    real_T d4;
    real_T d5;
    real_T im;
    real_T k0;
    real_T nom_n_re;
    real_T sigmasqrd;
    real_T sigmasqrd_tmp;
    int32_T i1;
    int32_T i2;
    int32_T loop_ub;
    int32_T n;
    int32_T points;
    ref.set_size(q.size(0));
    loop_ub = q.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      ref[i] = 0.0;
    }

    loop_ub = q.size(0) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(beta,r_n_np1,err_n,sigmasqrd,denom_n,nom_n,knp1,sld_np1,r01,err1,denom1,nom1,k1,sld_1,R,k0,bulk_in_SLD,kn_ptr,M_res,M_n,M_tot,points,i1,n,nom_n_re,sigmasqrd_tmp,brm,im,M_n_tmp,d,d1,i2,d2,d3,d4,d5)

    for (points = 0; points <= loop_ub; points++) {
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
      kn_ptr.re = 0.0;
      kn_ptr.im = 0.0;
      bulk_in_SLD.re = layers_rho[0].re;
      bulk_in_SLD.im = layers_rho[0].im + 1.0E-30;
      k0 = q[points] / 2.0;
      i1 = static_cast<int32_T>(N - 1.0);
      for (n = 0; n < i1; n++) {
        if (n + 1U == 1U) {
          //  Find k1..
          sld_1.re = layers_rho[1].re - bulk_in_SLD.re;
          sld_1.im = layers_rho[1].im - bulk_in_SLD.im;
          k1 = findkn(k0, sld_1);

          //  Find r01
          nom1.re = k0 - k1.re;
          denom1.re = k0 + k1.re;
          sigmasqrd = layers_sig[1] * layers_sig[1];
          err1.re = sigmasqrd * (k0 * (-2.0 * k1.re));
          err1.im = sigmasqrd * (k0 * (-2.0 * k1.im));
          coder::b_exp(&err1);
          if (k1.im == 0.0) {
            nom_n_re = nom1.re / denom1.re;
            sigmasqrd_tmp = 0.0;
          } else if (denom1.re == 0.0) {
            if (nom1.re == 0.0) {
              nom_n_re = (0.0 - k1.im) / k1.im;
              sigmasqrd_tmp = 0.0;
            } else if (0.0 - k1.im == 0.0) {
              nom_n_re = 0.0;
              sigmasqrd_tmp = -(nom1.re / k1.im);
            } else {
              nom_n_re = (0.0 - k1.im) / k1.im;
              sigmasqrd_tmp = -(nom1.re / k1.im);
            }
          } else {
            brm = std::abs(denom1.re);
            sigmasqrd_tmp = std::abs(k1.im);
            if (brm > sigmasqrd_tmp) {
              sigmasqrd_tmp = k1.im / denom1.re;
              im = denom1.re + sigmasqrd_tmp * k1.im;
              nom_n_re = (nom1.re + sigmasqrd_tmp * (0.0 - k1.im)) / im;
              sigmasqrd_tmp = ((0.0 - k1.im) - sigmasqrd_tmp * nom1.re) / im;
            } else if (sigmasqrd_tmp == brm) {
              if (denom1.re > 0.0) {
                sigmasqrd_tmp = 0.5;
              } else {
                sigmasqrd_tmp = -0.5;
              }

              if (k1.im > 0.0) {
                im = 0.5;
              } else {
                im = -0.5;
              }

              nom_n_re = (nom1.re * sigmasqrd_tmp + (0.0 - k1.im) * im) / brm;
              sigmasqrd_tmp = ((0.0 - k1.im) * sigmasqrd_tmp - nom1.re * im) /
                brm;
            } else {
              sigmasqrd_tmp = denom1.re / k1.im;
              im = k1.im + sigmasqrd_tmp * denom1.re;
              nom_n_re = (sigmasqrd_tmp * nom1.re + (0.0 - k1.im)) / im;
              sigmasqrd_tmp = (sigmasqrd_tmp * (0.0 - k1.im) - nom1.re) / im;
            }
          }

          r01.re = nom_n_re * err1.re - sigmasqrd_tmp * err1.im;
          r01.im = nom_n_re * err1.im + sigmasqrd_tmp * err1.re;

          //  Generate the M1 matrix:
          M_tot[0][0].re = 1.0;
          M_tot[0][0].im = 0.0;
          M_tot[1][0] = r01;
          M_tot[0][1] = r01;
          M_tot[1][1].re = 1.0;
          M_tot[1][1].im = 0.0;
          kn_ptr = k1;
        } else {
          //  Find kn and k_n+1 (ex. k1 and k2 for n=1): $/
          sld_np1.re = layers_rho[n + 1].re - bulk_in_SLD.re;
          sld_np1.im = layers_rho[n + 1].im - bulk_in_SLD.im;
          knp1 = findkn(k0, sld_np1);

          //  Find r_n,n+1:
          nom_n.re = kn_ptr.re - knp1.re;
          nom_n.im = kn_ptr.im - knp1.im;
          denom_n.re = kn_ptr.re + knp1.re;
          denom_n.im = kn_ptr.im + knp1.im;
          sigmasqrd_tmp = layers_sig[n + 1];
          sigmasqrd = sigmasqrd_tmp * sigmasqrd_tmp;
          sigmasqrd_tmp = -2.0 * kn_ptr.re;
          im = -2.0 * kn_ptr.im;
          err_n.re = sigmasqrd * (sigmasqrd_tmp * knp1.re - im * knp1.im);
          err_n.im = sigmasqrd * (sigmasqrd_tmp * knp1.im + im * knp1.re);
          coder::b_exp(&err_n);
          if (denom_n.im == 0.0) {
            if (nom_n.im == 0.0) {
              nom_n_re = nom_n.re / denom_n.re;
              sigmasqrd_tmp = 0.0;
            } else if (nom_n.re == 0.0) {
              nom_n_re = 0.0;
              sigmasqrd_tmp = nom_n.im / denom_n.re;
            } else {
              nom_n_re = nom_n.re / denom_n.re;
              sigmasqrd_tmp = nom_n.im / denom_n.re;
            }
          } else if (denom_n.re == 0.0) {
            if (nom_n.re == 0.0) {
              nom_n_re = nom_n.im / denom_n.im;
              sigmasqrd_tmp = 0.0;
            } else if (nom_n.im == 0.0) {
              nom_n_re = 0.0;
              sigmasqrd_tmp = -(nom_n.re / denom_n.im);
            } else {
              nom_n_re = nom_n.im / denom_n.im;
              sigmasqrd_tmp = -(nom_n.re / denom_n.im);
            }
          } else {
            brm = std::abs(denom_n.re);
            sigmasqrd_tmp = std::abs(denom_n.im);
            if (brm > sigmasqrd_tmp) {
              sigmasqrd_tmp = denom_n.im / denom_n.re;
              im = denom_n.re + sigmasqrd_tmp * denom_n.im;
              nom_n_re = (nom_n.re + sigmasqrd_tmp * nom_n.im) / im;
              sigmasqrd_tmp = (nom_n.im - sigmasqrd_tmp * nom_n.re) / im;
            } else if (sigmasqrd_tmp == brm) {
              if (denom_n.re > 0.0) {
                sigmasqrd_tmp = 0.5;
              } else {
                sigmasqrd_tmp = -0.5;
              }

              if (denom_n.im > 0.0) {
                im = 0.5;
              } else {
                im = -0.5;
              }

              nom_n_re = (nom_n.re * sigmasqrd_tmp + nom_n.im * im) / brm;
              sigmasqrd_tmp = (nom_n.im * sigmasqrd_tmp - nom_n.re * im) / brm;
            } else {
              sigmasqrd_tmp = denom_n.re / denom_n.im;
              im = denom_n.im + sigmasqrd_tmp * denom_n.re;
              nom_n_re = (sigmasqrd_tmp * nom_n.re + nom_n.im) / im;
              sigmasqrd_tmp = (sigmasqrd_tmp * nom_n.im - nom_n.re) / im;
            }
          }

          r_n_np1.re = nom_n_re * err_n.re - sigmasqrd_tmp * err_n.im;
          r_n_np1.im = nom_n_re * err_n.im + sigmasqrd_tmp * err_n.re;

          //  Find the Phase Factor = (k_n * d_n)
          sigmasqrd_tmp = layers_thick[n] * kn_ptr.re;
          im = layers_thick[n] * kn_ptr.im;
          beta.re = sigmasqrd_tmp * 0.0 - im;
          beta.im = sigmasqrd_tmp + im * 0.0;

          //  Create the M_n matrix: $/
          M_n_tmp = beta;
          coder::b_exp(&M_n_tmp);
          M_n[0][0] = M_n_tmp;
          M_n[1][0].re = r_n_np1.re * M_n_tmp.re - r_n_np1.im * M_n_tmp.im;
          M_n[1][0].im = r_n_np1.re * M_n_tmp.im + r_n_np1.im * M_n_tmp.re;
          M_n_tmp.re = -beta.re;
          M_n_tmp.im = -beta.im;
          coder::b_exp(&M_n_tmp);
          M_n[0][1].re = r_n_np1.re * M_n_tmp.re - r_n_np1.im * M_n_tmp.im;
          M_n[0][1].im = r_n_np1.re * M_n_tmp.im + r_n_np1.im * M_n_tmp.re;

          //  Multiply the matrices
          sigmasqrd_tmp = M_n[0][0].re;
          im = M_n[0][0].im;
          brm = M_n[0][1].re;
          nom_n_re = M_n[0][1].im;
          d = M_n[1][0].re;
          d1 = M_n[1][0].im;
          for (i2 = 0; i2 < 2; i2++) {
            d2 = M_tot[0][i2].re;
            d3 = M_tot[0][i2].im;
            d4 = M_tot[1][i2].re;
            d5 = M_tot[1][i2].im;
            M_res[0][i2].re = (d2 * sigmasqrd_tmp - d3 * im) + (d4 * brm - d5 *
              nom_n_re);
            M_res[0][i2].im = (d2 * im + d3 * sigmasqrd_tmp) + (d4 * nom_n_re +
              d5 * brm);
            M_res[1][i2].re = (d2 * d - d3 * d1) + (d4 * M_n_tmp.re - d5 *
              M_n_tmp.im);
            M_res[1][i2].im = (d2 * d1 + d3 * d) + (d4 * M_n_tmp.im + d5 *
              M_n_tmp.re);
          }

          //  Reassign the values back to M_tot:
          M_tot[0][0] = M_res[0][0];
          M_tot[0][1] = M_res[0][1];
          M_tot[1][0] = M_res[1][0];
          M_tot[1][1] = M_res[1][1];

          //  Point to k_n+1 and sld_n+1 via kn_ptr sld_n_ptr:
          kn_ptr = knp1;
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
        sigmasqrd_tmp = std::abs(M_res[0][0].im);
        if (brm > sigmasqrd_tmp) {
          sigmasqrd_tmp = M_res[0][0].im / M_res[0][0].re;
          im = M_res[0][0].re + sigmasqrd_tmp * M_res[0][0].im;
          M_n_tmp.re = (M_res[0][1].re + sigmasqrd_tmp * M_res[0][1].im) / im;
          M_n_tmp.im = (M_res[0][1].im - sigmasqrd_tmp * M_res[0][1].re) / im;
        } else if (sigmasqrd_tmp == brm) {
          if (M_res[0][0].re > 0.0) {
            sigmasqrd_tmp = 0.5;
          } else {
            sigmasqrd_tmp = -0.5;
          }

          if (M_res[0][0].im > 0.0) {
            im = 0.5;
          } else {
            im = -0.5;
          }

          M_n_tmp.re = (M_res[0][1].re * sigmasqrd_tmp + M_res[0][1].im * im) /
            brm;
          M_n_tmp.im = (M_res[0][1].im * sigmasqrd_tmp - M_res[0][1].re * im) /
            brm;
        } else {
          sigmasqrd_tmp = M_res[0][0].re / M_res[0][0].im;
          im = M_res[0][0].im + sigmasqrd_tmp * M_res[0][0].re;
          M_n_tmp.re = (sigmasqrd_tmp * M_res[0][1].re + M_res[0][1].im) / im;
          M_n_tmp.im = (sigmasqrd_tmp * M_res[0][1].im - M_res[0][1].re) / im;
        }
      }

      R = rt_hypotd_snf(M_n_tmp.re, M_n_tmp.im);
      ref[points] = R * R;
    }
  }
}

// End of code generation (abelesParallelPoints.cpp)
