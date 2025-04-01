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
#include "eye.h"
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
    ::coder::array<creal_T, 1U> sld;
    ::coder::array<double, 1U> nextSigmaSquared;
    creal_T b_layersRho;
    creal_T exp_beta;
    creal_T inv_exp_beta;
    double varargin_1;
    int i;
    int i1;
    int i3;
    int loop_ub;

    //  Vectorised version of reflectivity with complex rho
    ref.set_size(q.size(0));
    loop_ub = q.size(0);
    for (i = 0; i < loop_ub; i++) {
      ref[i] = 0.0;
    }

    //  SLD is always relative to bulk in value
    if (layersRho.size(0) < 2) {
      i = 0;
      i1 = 0;
    } else {
      i = 1;
      i1 = layersRho.size(0);
    }

    loop_ub = i1 - i;
    sld.set_size(loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      int i2;
      i2 = i + i1;
      sld[i1].re = layersRho[i2].re - layersRho[0].re;
      sld[i1].im = layersRho[i2].im - layersRho[0].im;
    }

    //  Always need the next sigma squared value for layers 1:end-1
    if (layersSigma.size(0) < 2) {
      i = 0;
      i1 = 0;
    } else {
      i = 1;
      i1 = layersSigma.size(0);
    }

    loop_ub = i1 - i;
    nextSigmaSquared.set_size(loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1 = layersSigma[i + i1];
      nextSigmaSquared[i1] = varargin_1 * varargin_1;
    }

    i = q.size(0);
    if (i - 1 >= 0) {
      i3 = static_cast<int>(N - 1.0);
    }

    for (int points{0}; points < i; points++) {
      creal_T M[2][2];
      double brm;
      double im;
      double k0;
      double kn_im;
      double kn_re;
      coder::eye(M);
      k0 = 0.5 * q[points];
      kn_re = k0;
      kn_im = 0.0;
      for (int n{0}; n < i3; n++) {
        creal_T knp1;
        double a_exp_beta_im;
        double a_exp_beta_re;
        double ai;
        double ar;
        double b_inv_exp_beta_im;
        double b_inv_exp_beta_re;
        double beta_im;
        double beta_re;
        double bi;
        double br;
        double c_exp_beta_im;
        double c_exp_beta_re;
        double d_inv_exp_beta_im;
        double d_inv_exp_beta_re;
        double knp1_re;
        double r_n_im;
        double r_n_re;
        knp1 = findkn(k0, sld[n]);

        //  Find the Phase Factor = (k_n * d_n)
        beta_re = layersThick[n] * kn_re;
        beta_im = layersThick[n] * kn_im;
        varargin_1 = -2.0 * knp1.re;
        im = -2.0 * knp1.im;
        b_layersRho.re = nextSigmaSquared[n] * (varargin_1 * kn_re - im * kn_im);
        b_layersRho.im = nextSigmaSquared[n] * (varargin_1 * kn_im + im * kn_re);
        coder::b_exp(b_layersRho);
        ar = knp1.re - kn_re;
        ai = knp1.im - kn_im;
        br = knp1.re + kn_re;
        bi = knp1.im + kn_im;
        if (bi == 0.0) {
          if (ai == 0.0) {
            knp1_re = ar / br;
            varargin_1 = 0.0;
          } else if (ar == 0.0) {
            knp1_re = 0.0;
            varargin_1 = ai / br;
          } else {
            knp1_re = ar / br;
            varargin_1 = ai / br;
          }
        } else if (br == 0.0) {
          if (ar == 0.0) {
            knp1_re = ai / bi;
            varargin_1 = 0.0;
          } else if (ai == 0.0) {
            knp1_re = 0.0;
            varargin_1 = -(ar / bi);
          } else {
            knp1_re = ai / bi;
            varargin_1 = -(ar / bi);
          }
        } else {
          brm = std::abs(br);
          varargin_1 = std::abs(bi);
          if (brm > varargin_1) {
            im = bi / br;
            varargin_1 = br + im * bi;
            knp1_re = (ar + im * ai) / varargin_1;
            varargin_1 = (ai - im * ar) / varargin_1;
          } else if (varargin_1 == brm) {
            if (br > 0.0) {
              im = 0.5;
            } else {
              im = -0.5;
            }

            if (bi > 0.0) {
              varargin_1 = 0.5;
            } else {
              varargin_1 = -0.5;
            }

            knp1_re = (ar * im + ai * varargin_1) / brm;
            varargin_1 = (ai * im - ar * varargin_1) / brm;
          } else {
            im = br / bi;
            varargin_1 = bi + im * br;
            knp1_re = (im * ar + ai) / varargin_1;
            varargin_1 = (im * ai - ar) / varargin_1;
          }
        }

        r_n_re = knp1_re * b_layersRho.re - varargin_1 * b_layersRho.im;
        r_n_im = knp1_re * b_layersRho.im + varargin_1 * b_layersRho.re;

        //  Multiply system transfer matrix by the layer transfer matrix
        //  Coder behaves better if you just do it manually
        //  rather than M = M * M_n;
        //  we'll denote the entries M = [a b; c d]
        exp_beta.re = 0.0 * beta_re - beta_im;
        exp_beta.im = 0.0 * beta_im + beta_re;
        coder::b_exp(exp_beta);
        inv_exp_beta.re = 0.0 * beta_re - (-beta_im);
        inv_exp_beta.im = 0.0 * beta_im - beta_re;
        coder::b_exp(inv_exp_beta);
        a_exp_beta_re = M[0][0].re * exp_beta.re - M[0][0].im * exp_beta.im;
        a_exp_beta_im = M[0][0].re * exp_beta.im + M[0][0].im * exp_beta.re;
        b_inv_exp_beta_re = M[1][0].re * inv_exp_beta.re - M[1][0].im *
          inv_exp_beta.im;
        b_inv_exp_beta_im = M[1][0].re * inv_exp_beta.im + M[1][0].im *
          inv_exp_beta.re;
        c_exp_beta_re = M[0][1].re * exp_beta.re - M[0][1].im * exp_beta.im;
        c_exp_beta_im = M[0][1].re * exp_beta.im + M[0][1].im * exp_beta.re;
        d_inv_exp_beta_re = M[1][1].re * inv_exp_beta.re - M[1][1].im *
          inv_exp_beta.im;
        d_inv_exp_beta_im = M[1][1].re * inv_exp_beta.im + M[1][1].im *
          inv_exp_beta.re;
        M[0][0].re = a_exp_beta_re + (r_n_re * b_inv_exp_beta_re - r_n_im *
          b_inv_exp_beta_im);
        M[0][0].im = a_exp_beta_im + (r_n_re * b_inv_exp_beta_im + r_n_im *
          b_inv_exp_beta_re);
        M[1][0].re = (r_n_re * a_exp_beta_re - r_n_im * a_exp_beta_im) +
          b_inv_exp_beta_re;
        M[1][0].im = (r_n_re * a_exp_beta_im + r_n_im * a_exp_beta_re) +
          b_inv_exp_beta_im;
        M[0][1].re = c_exp_beta_re + (r_n_re * d_inv_exp_beta_re - r_n_im *
          d_inv_exp_beta_im);
        M[0][1].im = c_exp_beta_im + (r_n_re * d_inv_exp_beta_im + r_n_im *
          d_inv_exp_beta_re);
        M[1][1].re = (r_n_re * c_exp_beta_re - r_n_im * c_exp_beta_im) +
          d_inv_exp_beta_re;
        M[1][1].im = (r_n_re * c_exp_beta_im + r_n_im * c_exp_beta_re) +
          d_inv_exp_beta_im;

        //  Set value of kn for the next layer
        kn_re = knp1.re;
        kn_im = knp1.im;
      }

      if (M[0][0].im == 0.0) {
        if (M[0][1].im == 0.0) {
          b_layersRho.re = M[0][1].re / M[0][0].re;
          b_layersRho.im = 0.0;
        } else if (M[0][1].re == 0.0) {
          b_layersRho.re = 0.0;
          b_layersRho.im = M[0][1].im / M[0][0].re;
        } else {
          b_layersRho.re = M[0][1].re / M[0][0].re;
          b_layersRho.im = M[0][1].im / M[0][0].re;
        }
      } else if (M[0][0].re == 0.0) {
        if (M[0][1].re == 0.0) {
          b_layersRho.re = M[0][1].im / M[0][0].im;
          b_layersRho.im = 0.0;
        } else if (M[0][1].im == 0.0) {
          b_layersRho.re = 0.0;
          b_layersRho.im = -(M[0][1].re / M[0][0].im);
        } else {
          b_layersRho.re = M[0][1].im / M[0][0].im;
          b_layersRho.im = -(M[0][1].re / M[0][0].im);
        }
      } else {
        brm = std::abs(M[0][0].re);
        varargin_1 = std::abs(M[0][0].im);
        if (brm > varargin_1) {
          im = M[0][0].im / M[0][0].re;
          varargin_1 = M[0][0].re + im * M[0][0].im;
          b_layersRho.re = (M[0][1].re + im * M[0][1].im) / varargin_1;
          b_layersRho.im = (M[0][1].im - im * M[0][1].re) / varargin_1;
        } else if (varargin_1 == brm) {
          if (M[0][0].re > 0.0) {
            im = 0.5;
          } else {
            im = -0.5;
          }

          if (M[0][0].im > 0.0) {
            varargin_1 = 0.5;
          } else {
            varargin_1 = -0.5;
          }

          b_layersRho.re = (M[0][1].re * im + M[0][1].im * varargin_1) / brm;
          b_layersRho.im = (M[0][1].im * im - M[0][1].re * varargin_1) / brm;
        } else {
          im = M[0][0].re / M[0][0].im;
          varargin_1 = M[0][0].im + im * M[0][0].re;
          b_layersRho.re = (im * M[0][1].re + M[0][1].im) / varargin_1;
          b_layersRho.im = (im * M[0][1].im - M[0][1].re) / varargin_1;
        }
      }

      varargin_1 = rt_hypotd_snf(b_layersRho.re, b_layersRho.im);
      ref[points] = varargin_1 * varargin_1;
    }
  }
}

// End of code generation (abelesSingle.cpp)
