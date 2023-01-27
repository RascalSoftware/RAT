//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: abeles_single.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "abeles_single.h"
#include "exp.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_rtwutil.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "coder_array.h"
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
  void abeles_single(const ::coder::array<real_T, 1U> &x, const ::coder::array<
                     real_T, 2U> &sld, real_T nbair, real_T nbsub, real_T
                     nrepeats, real_T rsub, real_T layers, real_T points, ::
                     coder::array<real_T, 1U> &out)
  {
    creal_T MI[2][2];
    creal_T N_tmp;
    creal_T b_N_tmp;
    creal_T pimag;
    creal_T psub;
    real_T ar_tmp;
    real_T snair;
    real_T snsub;
    int32_T i;
    int32_T i1;
    int32_T i2;
    i = static_cast<int32_T>(points);
    out.set_size(i);

    // pi = 3.141592653589;
    snair = 1.0 - nbair * 0.377451863036739;
    snsub = 1.0 - nbsub * 0.377451863036739;
    if (i - 1 >= 0) {
      i1 = static_cast<int32_T>(nrepeats);
      if (i1 - 1 >= 0) {
        i2 = static_cast<int32_T>(layers);
      }

      ar_tmp = rsub * rsub;
    }

    for (int32_T loop{0}; loop < i; loop++) {
      creal_T b_MI[2][2];
      real_T MI_im;
      real_T MI_re;
      real_T bim;
      real_T blast_im;
      real_T blast_re;
      real_T brm;
      real_T d;
      real_T d1;
      real_T im;
      real_T plast_im;
      real_T plast_re;
      real_T psub_tmp_tmp;
      real_T re;
      real_T rij_im;
      real_T rij_re;
      real_T theta;
      theta = std::asin(x[loop] * 1.54 / 12.566370614359172);
      MI_re = std::cos(theta);
      psub_tmp_tmp = snair * snair * (MI_re * MI_re);
      MI_re = snsub * snsub - psub_tmp_tmp;
      psub.re = MI_re;
      psub.im = MI_re * 0.0;
      coder::internal::scalar::b_sqrt(&psub);
      MI_re = snair * std::sin(theta);
      plast_re = MI_re;
      plast_im = MI_re * 0.0;
      blast_re = 0.0;
      blast_im = 0.0;
      MI[0][0].re = 1.0;
      MI[0][0].im = 0.0;
      MI[1][1].re = 1.0;
      MI[1][1].im = 0.0;
      MI[1][0].re = 0.0;
      MI[1][0].im = 0.0;
      MI[0][1].re = 0.0;
      MI[0][1].im = 0.0;
      for (int32_T reploop{0}; reploop < i1; reploop++) {
        for (int32_T nl{0}; nl < i2; nl++) {
          real_T rough;
          real_T snlay;
          rough = sld[nl + sld.size(0) * 2];
          snlay = 1.0 - sld[nl + sld.size(0)] * 0.377451863036739;
          MI_re = snlay * snlay - psub_tmp_tmp;
          pimag.re = MI_re;
          pimag.im = MI_re * 0.0;
          coder::internal::scalar::b_sqrt(&pimag);
          re = -78.956835208714864 * plast_re;
          im = -78.956835208714864 * plast_im;
          MI_re = rough * rough;
          MI_im = (re * pimag.re - im * pimag.im) * MI_re;
          im = (re * pimag.im + im * pimag.re) * MI_re;
          if (im == 0.0) {
            N_tmp.re = MI_im / 2.3716;
            N_tmp.im = 0.0;
          } else if (MI_im == 0.0) {
            N_tmp.re = 0.0;
            N_tmp.im = im / 2.3716;
          } else {
            N_tmp.re = MI_im / 2.3716;
            N_tmp.im = im / 2.3716;
          }

          coder::b_exp(&N_tmp);
          MI_im = plast_re - pimag.re;
          im = plast_im - pimag.im;
          MI_re = plast_re + pimag.re;
          re = plast_im + pimag.im;
          if (re == 0.0) {
            if (im == 0.0) {
              plast_re = MI_im / MI_re;
              plast_im = 0.0;
            } else if (MI_im == 0.0) {
              plast_re = 0.0;
              plast_im = im / MI_re;
            } else {
              plast_re = MI_im / MI_re;
              plast_im = im / MI_re;
            }
          } else if (MI_re == 0.0) {
            if (MI_im == 0.0) {
              plast_re = im / re;
              plast_im = 0.0;
            } else if (im == 0.0) {
              plast_re = 0.0;
              plast_im = -(MI_im / re);
            } else {
              plast_re = im / re;
              plast_im = -(MI_im / re);
            }
          } else {
            brm = std::abs(MI_re);
            bim = std::abs(re);
            if (brm > bim) {
              bim = re / MI_re;
              MI_re += bim * re;
              plast_re = (MI_im + bim * im) / MI_re;
              plast_im = (im - bim * MI_im) / MI_re;
            } else if (bim == brm) {
              if (MI_re > 0.0) {
                bim = 0.5;
              } else {
                bim = -0.5;
              }

              if (re > 0.0) {
                MI_re = 0.5;
              } else {
                MI_re = -0.5;
              }

              plast_re = (MI_im * bim + im * MI_re) / brm;
              plast_im = (im * bim - MI_im * MI_re) / brm;
            } else {
              bim = MI_re / re;
              MI_re = re + bim * MI_re;
              plast_re = (bim * MI_im + im) / MI_re;
              plast_im = (bim * im - MI_im) / MI_re;
            }
          }

          rij_re = plast_re * N_tmp.re - plast_im * N_tmp.im;
          rij_im = plast_re * N_tmp.im + plast_im * N_tmp.re;
          b_N_tmp.re = blast_re * 0.0 - blast_im;
          b_N_tmp.im = blast_re + blast_im * 0.0;
          coder::b_exp(&b_N_tmp);
          N_tmp.re = -blast_re * 0.0 - (-blast_im);
          N_tmp.im = -blast_re + -blast_im * 0.0;
          coder::b_exp(&N_tmp);
          brm = rij_re * N_tmp.re - rij_im * N_tmp.im;
          d = rij_re * N_tmp.im + rij_im * N_tmp.re;
          d1 = rij_re * b_N_tmp.re - rij_im * b_N_tmp.im;
          MI_re = rij_re * b_N_tmp.im + rij_im * b_N_tmp.re;
          plast_re = pimag.re;
          plast_im = pimag.im;
          blast_re = 4.0799904592075231 * sld[nl] * pimag.re;
          blast_im = 4.0799904592075231 * sld[nl] * pimag.im;
          for (int32_T i3{0}; i3 < 2; i3++) {
            re = MI[0][i3].re;
            im = MI[0][i3].im;
            MI_im = MI[1][i3].re;
            bim = MI[1][i3].im;
            b_MI[0][i3].re = (re * b_N_tmp.re - im * b_N_tmp.im) + (MI_im * brm
              - bim * d);
            b_MI[0][i3].im = (re * b_N_tmp.im + im * b_N_tmp.re) + (MI_im * d +
              bim * brm);
            b_MI[1][i3].re = (re * d1 - im * MI_re) + (MI_im * N_tmp.re - bim *
              N_tmp.im);
            b_MI[1][i3].im = (re * MI_re + im * d1) + (MI_im * N_tmp.im + bim *
              N_tmp.re);
          }

          MI[0][0] = b_MI[0][0];
          MI[0][1] = b_MI[0][1];
          MI[1][0] = b_MI[1][0];
          MI[1][1] = b_MI[1][1];
        }
      }

      re = -78.956835208714864 * plast_re;
      im = -78.956835208714864 * plast_im;
      MI_im = (re * psub.re - im * psub.im) * ar_tmp;
      im = (re * psub.im + im * psub.re) * ar_tmp;
      if (im == 0.0) {
        N_tmp.re = MI_im / 2.3716;
        N_tmp.im = 0.0;
      } else if (MI_im == 0.0) {
        N_tmp.re = 0.0;
        N_tmp.im = im / 2.3716;
      } else {
        N_tmp.re = MI_im / 2.3716;
        N_tmp.im = im / 2.3716;
      }

      coder::b_exp(&N_tmp);
      MI_im = plast_re - psub.re;
      im = plast_im - psub.im;
      MI_re = plast_re + psub.re;
      re = plast_im + psub.im;
      if (re == 0.0) {
        if (im == 0.0) {
          plast_re = MI_im / MI_re;
          plast_im = 0.0;
        } else if (MI_im == 0.0) {
          plast_re = 0.0;
          plast_im = im / MI_re;
        } else {
          plast_re = MI_im / MI_re;
          plast_im = im / MI_re;
        }
      } else if (MI_re == 0.0) {
        if (MI_im == 0.0) {
          plast_re = im / re;
          plast_im = 0.0;
        } else if (im == 0.0) {
          plast_re = 0.0;
          plast_im = -(MI_im / re);
        } else {
          plast_re = im / re;
          plast_im = -(MI_im / re);
        }
      } else {
        brm = std::abs(MI_re);
        bim = std::abs(re);
        if (brm > bim) {
          bim = re / MI_re;
          MI_re += bim * re;
          plast_re = (MI_im + bim * im) / MI_re;
          plast_im = (im - bim * MI_im) / MI_re;
        } else if (bim == brm) {
          if (MI_re > 0.0) {
            bim = 0.5;
          } else {
            bim = -0.5;
          }

          if (re > 0.0) {
            MI_re = 0.5;
          } else {
            MI_re = -0.5;
          }

          plast_re = (MI_im * bim + im * MI_re) / brm;
          plast_im = (im * bim - MI_im * MI_re) / brm;
        } else {
          bim = MI_re / re;
          MI_re = re + bim * MI_re;
          plast_re = (bim * MI_im + im) / MI_re;
          plast_im = (bim * im - MI_im) / MI_re;
        }
      }

      rij_re = plast_re * N_tmp.re - plast_im * N_tmp.im;
      rij_im = plast_re * N_tmp.im + plast_im * N_tmp.re;
      b_N_tmp.re = blast_re * 0.0 - blast_im;
      b_N_tmp.im = blast_re + blast_im * 0.0;
      coder::b_exp(&b_N_tmp);
      N_tmp.re = -blast_re * 0.0 - (-blast_im);
      N_tmp.im = -blast_re + -blast_im * 0.0;
      coder::b_exp(&N_tmp);
      brm = rij_re * N_tmp.re - rij_im * N_tmp.im;
      d = rij_re * N_tmp.im + rij_im * N_tmp.re;
      d1 = rij_re * b_N_tmp.re - rij_im * b_N_tmp.im;
      MI_re = rij_re * b_N_tmp.im + rij_im * b_N_tmp.re;
      for (int32_T i3{0}; i3 < 2; i3++) {
        re = MI[0][i3].re;
        im = MI[0][i3].im;
        MI_im = MI[1][i3].re;
        bim = MI[1][i3].im;
        b_MI[0][i3].re = (re * b_N_tmp.re - im * b_N_tmp.im) + (MI_im * brm -
          bim * d);
        b_MI[0][i3].im = (re * b_N_tmp.im + im * b_N_tmp.re) + (MI_im * d + bim *
          brm);
        b_MI[1][i3].re = (re * d1 - im * MI_re) + (MI_im * N_tmp.re - bim *
          N_tmp.im);
        b_MI[1][i3].im = (re * MI_re + im * d1) + (MI_im * N_tmp.im + bim *
          N_tmp.re);
      }

      im = b_MI[0][1].re * b_MI[0][1].re - b_MI[0][1].im * -b_MI[0][1].im;
      MI_im = b_MI[0][1].re * -b_MI[0][1].im + b_MI[0][1].im * b_MI[0][1].re;
      MI_re = b_MI[0][0].re * b_MI[0][0].re - b_MI[0][0].im * -b_MI[0][0].im;
      re = b_MI[0][0].re * -b_MI[0][0].im + b_MI[0][0].im * b_MI[0][0].re;
      if (re == 0.0) {
        if (MI_im == 0.0) {
          N_tmp.re = im / MI_re;
          N_tmp.im = 0.0;
        } else if (im == 0.0) {
          N_tmp.re = 0.0;
          N_tmp.im = MI_im / MI_re;
        } else {
          N_tmp.re = im / MI_re;
          N_tmp.im = MI_im / MI_re;
        }
      } else if (MI_re == 0.0) {
        if (im == 0.0) {
          N_tmp.re = MI_im / re;
          N_tmp.im = 0.0;
        } else if (MI_im == 0.0) {
          N_tmp.re = 0.0;
          N_tmp.im = -(im / re);
        } else {
          N_tmp.re = MI_im / re;
          N_tmp.im = -(im / re);
        }
      } else {
        brm = std::abs(MI_re);
        bim = std::abs(re);
        if (brm > bim) {
          bim = re / MI_re;
          MI_re += bim * re;
          N_tmp.re = (im + bim * MI_im) / MI_re;
          N_tmp.im = (MI_im - bim * im) / MI_re;
        } else if (bim == brm) {
          if (MI_re > 0.0) {
            bim = 0.5;
          } else {
            bim = -0.5;
          }

          if (re > 0.0) {
            MI_re = 0.5;
          } else {
            MI_re = -0.5;
          }

          N_tmp.re = (im * bim + MI_im * MI_re) / brm;
          N_tmp.im = (MI_im * bim - im * MI_re) / brm;
        } else {
          bim = MI_re / re;
          MI_re = re + bim * MI_re;
          N_tmp.re = (bim * im + MI_im) / MI_re;
          N_tmp.im = (bim * MI_im - im) / MI_re;
        }
      }

      out[loop] = rt_hypotd_snf(N_tmp.re, N_tmp.im);
    }
  }
}

//
// File trailer for abeles_single.cpp
//
// [EOF]
//
