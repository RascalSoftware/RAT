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
#include "eye.h"
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
    ::coder::array<creal_T, 1U> sld;
    ::coder::array<double, 1U> nextSigmaSquared;
    creal_T M[2][2];
    creal_T a_exp_beta;
    creal_T b_erf;
    creal_T b_inv_exp_beta;
    creal_T beta;
    creal_T c_exp_beta;
    creal_T d_inv_exp_beta;
    creal_T denominator;
    creal_T exp_beta;
    creal_T inv_exp_beta;
    creal_T kn;
    creal_T knp1;
    creal_T numerator;
    creal_T r_n;
    double R;
    double b_denominator_tmp;
    double b_numerator_tmp;
    double brm;
    double denominator_tmp;
    double im;
    double k0;
    double numerator_tmp;
    double re;
    double s;
    int i;
    int i1;
    int i3;
    int loop_ub;
    int n;

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
      double varargin_1;
      varargin_1 = layersSigma[i + i1];
      nextSigmaSquared[i1] = varargin_1 * varargin_1;
    }

    loop_ub = q.size(0) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(d_inv_exp_beta,c_exp_beta,b_inv_exp_beta,a_exp_beta,inv_exp_beta,exp_beta,r_n,b_erf,denominator,numerator,beta,knp1,R,kn,k0,M,i3,n,numerator_tmp,b_numerator_tmp,denominator_tmp,b_denominator_tmp,re,im,brm,s)

    for (int points = 0; points <= loop_ub; points++) {
      coder::eye(M);
      k0 = 0.5 * q[points];
      kn.re = k0;
      kn.im = 0.0;
      i3 = static_cast<int>(N - 1.0);
      for (n = 0; n < i3; n++) {
        knp1 = findkn(k0, sld[n]);

        //  Find the Phase Factor = (k_n * d_n)
        beta.re = layersThick[n] * kn.re;
        beta.im = layersThick[n] * kn.im;
        numerator_tmp = knp1.re - kn.re;
        b_numerator_tmp = knp1.im - kn.im;
        denominator_tmp = knp1.re + kn.re;
        b_denominator_tmp = knp1.im + kn.im;
        re = -2.0 * knp1.re;
        im = -2.0 * knp1.im;
        b_erf.re = nextSigmaSquared[n] * (re * kn.re - im * kn.im);
        b_erf.im = nextSigmaSquared[n] * (re * kn.im + im * kn.re);
        coder::b_exp(b_erf);
        if (b_denominator_tmp == 0.0) {
          if (b_numerator_tmp == 0.0) {
            im = numerator_tmp / denominator_tmp;
            re = 0.0;
          } else if (numerator_tmp == 0.0) {
            im = 0.0;
            re = b_numerator_tmp / denominator_tmp;
          } else {
            im = numerator_tmp / denominator_tmp;
            re = b_numerator_tmp / denominator_tmp;
          }
        } else if (denominator_tmp == 0.0) {
          if (numerator_tmp == 0.0) {
            im = b_numerator_tmp / b_denominator_tmp;
            re = 0.0;
          } else if (b_numerator_tmp == 0.0) {
            im = 0.0;
            re = -(numerator_tmp / b_denominator_tmp);
          } else {
            im = b_numerator_tmp / b_denominator_tmp;
            re = -(numerator_tmp / b_denominator_tmp);
          }
        } else {
          brm = std::abs(denominator_tmp);
          re = std::abs(b_denominator_tmp);
          if (brm > re) {
            s = b_denominator_tmp / denominator_tmp;
            re = denominator_tmp + s * b_denominator_tmp;
            im = (numerator_tmp + s * b_numerator_tmp) / re;
            re = (b_numerator_tmp - s * numerator_tmp) / re;
          } else if (re == brm) {
            if (denominator_tmp > 0.0) {
              s = 0.5;
            } else {
              s = -0.5;
            }

            if (b_denominator_tmp > 0.0) {
              re = 0.5;
            } else {
              re = -0.5;
            }

            im = (numerator_tmp * s + b_numerator_tmp * re) / brm;
            re = (b_numerator_tmp * s - numerator_tmp * re) / brm;
          } else {
            s = denominator_tmp / b_denominator_tmp;
            re = b_denominator_tmp + s * denominator_tmp;
            im = (s * numerator_tmp + b_numerator_tmp) / re;
            re = (s * b_numerator_tmp - numerator_tmp) / re;
          }
        }

        r_n.re = im * b_erf.re - re * b_erf.im;
        r_n.im = im * b_erf.im + re * b_erf.re;

        //  Multiply system transfer matrix by the layer transfer matrix
        //  Coder behaves better if you just do it manually
        //  rather than M = M * M_n;
        //  we'll denote the entries M = [a b; c d]
        re = 0.0 * beta.re;
        exp_beta.re = re - beta.im;
        im = 0.0 * beta.im;
        exp_beta.im = im + beta.re;
        coder::b_exp(exp_beta);
        inv_exp_beta.re = re - (-beta.im);
        inv_exp_beta.im = im - beta.re;
        coder::b_exp(inv_exp_beta);
        a_exp_beta.re = M[0][0].re * exp_beta.re - M[0][0].im * exp_beta.im;
        a_exp_beta.im = M[0][0].re * exp_beta.im + M[0][0].im * exp_beta.re;
        b_inv_exp_beta.re = M[1][0].re * inv_exp_beta.re - M[1][0].im *
          inv_exp_beta.im;
        b_inv_exp_beta.im = M[1][0].re * inv_exp_beta.im + M[1][0].im *
          inv_exp_beta.re;
        c_exp_beta.re = M[0][1].re * exp_beta.re - M[0][1].im * exp_beta.im;
        c_exp_beta.im = M[0][1].re * exp_beta.im + M[0][1].im * exp_beta.re;
        d_inv_exp_beta.re = M[1][1].re * inv_exp_beta.re - M[1][1].im *
          inv_exp_beta.im;
        d_inv_exp_beta.im = M[1][1].re * inv_exp_beta.im + M[1][1].im *
          inv_exp_beta.re;
        M[0][0].re = a_exp_beta.re + (r_n.re * b_inv_exp_beta.re - r_n.im *
          b_inv_exp_beta.im);
        M[0][0].im = a_exp_beta.im + (r_n.re * b_inv_exp_beta.im + r_n.im *
          b_inv_exp_beta.re);
        M[1][0].re = (r_n.re * a_exp_beta.re - r_n.im * a_exp_beta.im) +
          b_inv_exp_beta.re;
        M[1][0].im = (r_n.re * a_exp_beta.im + r_n.im * a_exp_beta.re) +
          b_inv_exp_beta.im;
        M[0][1].re = c_exp_beta.re + (r_n.re * d_inv_exp_beta.re - r_n.im *
          d_inv_exp_beta.im);
        M[0][1].im = c_exp_beta.im + (r_n.re * d_inv_exp_beta.im + r_n.im *
          d_inv_exp_beta.re);
        M[1][1].re = (r_n.re * c_exp_beta.re - r_n.im * c_exp_beta.im) +
          d_inv_exp_beta.re;
        M[1][1].im = (r_n.re * c_exp_beta.im + r_n.im * c_exp_beta.re) +
          d_inv_exp_beta.im;

        //  Set value of kn for the next layer
        kn = knp1;
      }

      if (M[0][0].im == 0.0) {
        if (M[0][1].im == 0.0) {
          im = M[0][1].re / M[0][0].re;
          re = 0.0;
        } else if (M[0][1].re == 0.0) {
          im = 0.0;
          re = M[0][1].im / M[0][0].re;
        } else {
          im = M[0][1].re / M[0][0].re;
          re = M[0][1].im / M[0][0].re;
        }
      } else if (M[0][0].re == 0.0) {
        if (M[0][1].re == 0.0) {
          im = M[0][1].im / M[0][0].im;
          re = 0.0;
        } else if (M[0][1].im == 0.0) {
          im = 0.0;
          re = -(M[0][1].re / M[0][0].im);
        } else {
          im = M[0][1].im / M[0][0].im;
          re = -(M[0][1].re / M[0][0].im);
        }
      } else {
        brm = std::abs(M[0][0].re);
        re = std::abs(M[0][0].im);
        if (brm > re) {
          s = M[0][0].im / M[0][0].re;
          re = M[0][0].re + s * M[0][0].im;
          im = (M[0][1].re + s * M[0][1].im) / re;
          re = (M[0][1].im - s * M[0][1].re) / re;
        } else if (re == brm) {
          if (M[0][0].re > 0.0) {
            s = 0.5;
          } else {
            s = -0.5;
          }

          if (M[0][0].im > 0.0) {
            re = 0.5;
          } else {
            re = -0.5;
          }

          im = (M[0][1].re * s + M[0][1].im * re) / brm;
          re = (M[0][1].im * s - M[0][1].re * re) / brm;
        } else {
          s = M[0][0].re / M[0][0].im;
          re = M[0][0].im + s * M[0][0].re;
          im = (s * M[0][1].re + M[0][1].im) / re;
          re = (s * M[0][1].im - M[0][1].re) / re;
        }
      }

      R = rt_hypotd_snf(im, re);
      ref[points] = R * R;
    }
  }
}

// End of code generation (abelesParallelPoints.cpp)
