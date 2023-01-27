//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: abeles_paraPoints.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "abeles_paraPoints.h"
#include "exp.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_rtwutil.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>

// Function Definitions
//
// nbair = nbairs(thisCont);
//  nbsub = nbsubs(thisCont);
//  ssub = ssubs(thisCont);
//  nrepeats = nrepeatss(thisCont);
//  resol = resols(thisCont);
//
// Arguments    : const ::coder::array<real_T, 1U> &x
//                const ::coder::array<real_T, 2U> &sld
//                real_T nbair
//                real_T nbsub
//                real_T nrepeats
//                real_T rsub
//                real_T layers
//                real_T points
//                ::coder::array<real_T, 1U> &out
// Return Type  : void
//
namespace RAT
{
  void abeles_paraPoints(const ::coder::array<real_T, 1U> &x, const ::coder::
    array<real_T, 2U> &sld, real_T nbair, real_T nbsub, real_T nrepeats, real_T
    rsub, real_T layers, real_T points, ::coder::array<real_T, 1U> &out)
  {
    creal_T MI[2][2];
    creal_T b_MI[2][2];
    creal_T N_tmp;
    creal_T b_N_tmp;
    creal_T beta;
    creal_T blast;
    creal_T den;
    creal_T num;
    creal_T pair;
    creal_T pimag;
    creal_T plast;
    creal_T psub;
    creal_T quo;
    creal_T rij;
    real_T a_tmp;
    real_T ai;
    real_T ar;
    real_T bi;
    real_T brm;
    real_T im;
    real_T plast_re;
    real_T preal;
    real_T preal_tmp;
    real_T re;
    real_T rho;
    real_T rough;
    real_T snair;
    real_T snlay;
    real_T snsub;
    real_T theta;
    real_T thick;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T nl;
    int32_T reploop;
    int32_T ub_loop;
    out.set_size(static_cast<int32_T>(points));

    // pi = 3.141592653589;
    snair = 1.0 - nbair * 0.377451863036739;
    snsub = 1.0 - nbsub * 0.377451863036739;
    ub_loop = static_cast<int32_T>(points) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(quo,den,num,MI,rij,beta,pimag,preal,snlay,rough,rho,thick,blast,plast,pair,psub,theta,a_tmp,preal_tmp,i,i1,reploop,nl,re,im,ar,ai,N_tmp,bi,plast_re,b_N_tmp,i2,brm,b_MI)

    for (int32_T loop = 0; loop <= ub_loop; loop++) {
      theta = std::asin(x[loop] * 1.54 / 12.566370614359172);
      a_tmp = std::cos(theta);
      preal_tmp = snair * snair * (a_tmp * a_tmp);
      preal = snsub * snsub - preal_tmp;
      psub.re = preal;
      psub.im = preal * 0.0;
      coder::internal::scalar::b_sqrt(&psub);
      a_tmp = snair * std::sin(theta);
      pair.re = a_tmp;
      pair.im = a_tmp * 0.0;
      plast = pair;
      blast.re = 0.0;
      blast.im = 0.0;
      MI[0][0].re = 1.0;
      MI[0][0].im = 0.0;
      MI[1][1].re = 1.0;
      MI[1][1].im = 0.0;
      MI[1][0].re = 0.0;
      MI[1][0].im = 0.0;
      MI[0][1].re = 0.0;
      MI[0][1].im = 0.0;
      i = static_cast<int32_T>(nrepeats);
      if (i - 1 >= 0) {
        i1 = static_cast<int32_T>(layers);
      }

      for (reploop = 0; reploop < i; reploop++) {
        for (nl = 0; nl < i1; nl++) {
          thick = sld[nl];
          rho = sld[nl + sld.size(0)];
          rough = sld[nl + sld.size(0) * 2];
          snlay = 1.0 - rho * 0.377451863036739;
          preal = snlay * snlay - preal_tmp;
          pimag.re = preal;
          pimag.im = preal * 0.0;
          coder::internal::scalar::b_sqrt(&pimag);
          beta.re = 4.0799904592075231 * thick * pimag.re;
          beta.im = 4.0799904592075231 * thick * pimag.im;
          re = -78.956835208714864 * plast.re;
          im = -78.956835208714864 * plast.im;
          a_tmp = rough * rough;
          ar = (re * pimag.re - im * pimag.im) * a_tmp;
          ai = (re * pimag.im + im * pimag.re) * a_tmp;
          if (ai == 0.0) {
            N_tmp.re = ar / 2.3716;
            N_tmp.im = 0.0;
          } else if (ar == 0.0) {
            N_tmp.re = 0.0;
            N_tmp.im = ai / 2.3716;
          } else {
            N_tmp.re = ar / 2.3716;
            N_tmp.im = ai / 2.3716;
          }

          coder::b_exp(&N_tmp);
          ar = plast.re - pimag.re;
          ai = plast.im - pimag.im;
          im = plast.re + pimag.re;
          bi = plast.im + pimag.im;
          if (bi == 0.0) {
            if (ai == 0.0) {
              plast_re = ar / im;
              a_tmp = 0.0;
            } else if (ar == 0.0) {
              plast_re = 0.0;
              a_tmp = ai / im;
            } else {
              plast_re = ar / im;
              a_tmp = ai / im;
            }
          } else if (im == 0.0) {
            if (ar == 0.0) {
              plast_re = ai / bi;
              a_tmp = 0.0;
            } else if (ai == 0.0) {
              plast_re = 0.0;
              a_tmp = -(ar / bi);
            } else {
              plast_re = ai / bi;
              a_tmp = -(ar / bi);
            }
          } else {
            brm = std::abs(im);
            a_tmp = std::abs(bi);
            if (brm > a_tmp) {
              re = bi / im;
              a_tmp = im + re * bi;
              plast_re = (ar + re * ai) / a_tmp;
              a_tmp = (ai - re * ar) / a_tmp;
            } else if (a_tmp == brm) {
              if (im > 0.0) {
                re = 0.5;
              } else {
                re = -0.5;
              }

              if (bi > 0.0) {
                a_tmp = 0.5;
              } else {
                a_tmp = -0.5;
              }

              plast_re = (ar * re + ai * a_tmp) / brm;
              a_tmp = (ai * re - ar * a_tmp) / brm;
            } else {
              re = im / bi;
              a_tmp = bi + re * im;
              plast_re = (re * ar + ai) / a_tmp;
              a_tmp = (re * ai - ar) / a_tmp;
            }
          }

          rij.re = plast_re * N_tmp.re - a_tmp * N_tmp.im;
          rij.im = plast_re * N_tmp.im + a_tmp * N_tmp.re;
          b_N_tmp.re = blast.re * 0.0 - blast.im;
          b_N_tmp.im = blast.re + blast.im * 0.0;
          coder::b_exp(&b_N_tmp);
          N_tmp.re = -blast.re * 0.0 - (-blast.im);
          N_tmp.im = -blast.re + -blast.im * 0.0;
          coder::b_exp(&N_tmp);
          a_tmp = rij.re * N_tmp.re - rij.im * N_tmp.im;
          re = rij.re * N_tmp.im + rij.im * N_tmp.re;
          im = rij.re * b_N_tmp.re - rij.im * b_N_tmp.im;
          bi = rij.re * b_N_tmp.im + rij.im * b_N_tmp.re;
          plast = pimag;
          blast = beta;
          for (i2 = 0; i2 < 2; i2++) {
            brm = MI[0][i2].re;
            ai = MI[0][i2].im;
            plast_re = MI[1][i2].re;
            ar = MI[1][i2].im;
            b_MI[0][i2].re = (brm * b_N_tmp.re - ai * b_N_tmp.im) + (plast_re *
              a_tmp - ar * re);
            b_MI[0][i2].im = (brm * b_N_tmp.im + ai * b_N_tmp.re) + (plast_re *
              re + ar * a_tmp);
            b_MI[1][i2].re = (brm * im - ai * bi) + (plast_re * N_tmp.re - ar *
              N_tmp.im);
            b_MI[1][i2].im = (brm * bi + ai * im) + (plast_re * N_tmp.im + ar *
              N_tmp.re);
          }

          MI[0][0] = b_MI[0][0];
          MI[0][1] = b_MI[0][1];
          MI[1][0] = b_MI[1][0];
          MI[1][1] = b_MI[1][1];
        }
      }

      re = -78.956835208714864 * plast.re;
      im = -78.956835208714864 * plast.im;
      a_tmp = rsub * rsub;
      ar = (re * psub.re - im * psub.im) * a_tmp;
      ai = (re * psub.im + im * psub.re) * a_tmp;
      if (ai == 0.0) {
        N_tmp.re = ar / 2.3716;
        N_tmp.im = 0.0;
      } else if (ar == 0.0) {
        N_tmp.re = 0.0;
        N_tmp.im = ai / 2.3716;
      } else {
        N_tmp.re = ar / 2.3716;
        N_tmp.im = ai / 2.3716;
      }

      coder::b_exp(&N_tmp);
      ar = plast.re - psub.re;
      ai = plast.im - psub.im;
      im = plast.re + psub.re;
      bi = plast.im + psub.im;
      if (bi == 0.0) {
        if (ai == 0.0) {
          plast_re = ar / im;
          a_tmp = 0.0;
        } else if (ar == 0.0) {
          plast_re = 0.0;
          a_tmp = ai / im;
        } else {
          plast_re = ar / im;
          a_tmp = ai / im;
        }
      } else if (im == 0.0) {
        if (ar == 0.0) {
          plast_re = ai / bi;
          a_tmp = 0.0;
        } else if (ai == 0.0) {
          plast_re = 0.0;
          a_tmp = -(ar / bi);
        } else {
          plast_re = ai / bi;
          a_tmp = -(ar / bi);
        }
      } else {
        brm = std::abs(im);
        a_tmp = std::abs(bi);
        if (brm > a_tmp) {
          re = bi / im;
          a_tmp = im + re * bi;
          plast_re = (ar + re * ai) / a_tmp;
          a_tmp = (ai - re * ar) / a_tmp;
        } else if (a_tmp == brm) {
          if (im > 0.0) {
            re = 0.5;
          } else {
            re = -0.5;
          }

          if (bi > 0.0) {
            a_tmp = 0.5;
          } else {
            a_tmp = -0.5;
          }

          plast_re = (ar * re + ai * a_tmp) / brm;
          a_tmp = (ai * re - ar * a_tmp) / brm;
        } else {
          re = im / bi;
          a_tmp = bi + re * im;
          plast_re = (re * ar + ai) / a_tmp;
          a_tmp = (re * ai - ar) / a_tmp;
        }
      }

      rij.re = plast_re * N_tmp.re - a_tmp * N_tmp.im;
      rij.im = plast_re * N_tmp.im + a_tmp * N_tmp.re;
      b_N_tmp.re = blast.re * 0.0 - blast.im;
      b_N_tmp.im = blast.re + blast.im * 0.0;
      coder::b_exp(&b_N_tmp);
      N_tmp.re = -blast.re * 0.0 - (-blast.im);
      N_tmp.im = -blast.re + -blast.im * 0.0;
      coder::b_exp(&N_tmp);
      a_tmp = rij.re * N_tmp.re - rij.im * N_tmp.im;
      re = rij.re * N_tmp.im + rij.im * N_tmp.re;
      im = rij.re * b_N_tmp.re - rij.im * b_N_tmp.im;
      bi = rij.re * b_N_tmp.im + rij.im * b_N_tmp.re;
      for (i = 0; i < 2; i++) {
        brm = MI[0][i].re;
        ai = MI[0][i].im;
        plast_re = MI[1][i].re;
        ar = MI[1][i].im;
        b_MI[0][i].re = (brm * b_N_tmp.re - ai * b_N_tmp.im) + (plast_re * a_tmp
          - ar * re);
        b_MI[0][i].im = (brm * b_N_tmp.im + ai * b_N_tmp.re) + (plast_re * re +
          ar * a_tmp);
        b_MI[1][i].re = (brm * im - ai * bi) + (plast_re * N_tmp.re - ar *
          N_tmp.im);
        b_MI[1][i].im = (brm * bi + ai * im) + (plast_re * N_tmp.im + ar *
          N_tmp.re);
      }

      num.re = b_MI[0][1].re * b_MI[0][1].re - b_MI[0][1].im * -b_MI[0][1].im;
      num.im = b_MI[0][1].re * -b_MI[0][1].im + b_MI[0][1].im * b_MI[0][1].re;
      den.re = b_MI[0][0].re * b_MI[0][0].re - b_MI[0][0].im * -b_MI[0][0].im;
      den.im = b_MI[0][0].re * -b_MI[0][0].im + b_MI[0][0].im * b_MI[0][0].re;
      if (den.im == 0.0) {
        if (num.im == 0.0) {
          quo.re = num.re / den.re;
          quo.im = 0.0;
        } else if (num.re == 0.0) {
          quo.re = 0.0;
          quo.im = num.im / den.re;
        } else {
          quo.re = num.re / den.re;
          quo.im = num.im / den.re;
        }
      } else if (den.re == 0.0) {
        if (num.re == 0.0) {
          quo.re = num.im / den.im;
          quo.im = 0.0;
        } else if (num.im == 0.0) {
          quo.re = 0.0;
          quo.im = -(num.re / den.im);
        } else {
          quo.re = num.im / den.im;
          quo.im = -(num.re / den.im);
        }
      } else {
        brm = std::abs(den.re);
        a_tmp = std::abs(den.im);
        if (brm > a_tmp) {
          re = den.im / den.re;
          a_tmp = den.re + re * den.im;
          quo.re = (num.re + re * num.im) / a_tmp;
          quo.im = (num.im - re * num.re) / a_tmp;
        } else if (a_tmp == brm) {
          if (den.re > 0.0) {
            re = 0.5;
          } else {
            re = -0.5;
          }

          if (den.im > 0.0) {
            a_tmp = 0.5;
          } else {
            a_tmp = -0.5;
          }

          quo.re = (num.re * re + num.im * a_tmp) / brm;
          quo.im = (num.im * re - num.re * a_tmp) / brm;
        } else {
          re = den.re / den.im;
          a_tmp = den.im + re * den.re;
          quo.re = (re * num.re + num.im) / a_tmp;
          quo.im = (re * num.im - num.re) / a_tmp;
        }
      }

      out[loop] = rt_hypotd_snf(quo.re, quo.im);
    }
  }
}

//
// File trailer for abeles_paraPoints.cpp
//
// [EOF]
//
