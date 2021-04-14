/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * acos.c
 *
 * Code generation for function 'acos'
 *
 */

/* Include files */
#include "acos.h"
#include "complexTimes.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"
#include "sqrt.h"

/* Variable Definitions */
static emlrtRSInfo re_emlrtRSI = { 17, /* lineNo */
  "acos",                              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/acos.m"/* pathName */
};

/* Function Definitions */
void b_acos(const emlrtStack *sp, emxArray_creal_T *x)
{
  int32_T nx;
  boolean_T overflow;
  int32_T k;
  creal_T v;
  creal_T u;
  real_T t3;
  real_T ci;
  real_T t4;
  real_T t;
  real_T sai;
  real_T scaleA;
  real_T sbr;
  real_T sbi;
  real_T scaleB;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &re_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x->size[0];
  b_st.site = &qe_emlrtRSI;
  overflow = ((1 <= x->size[0]) && (x->size[0] > 2147483646));
  if (overflow) {
    c_st.site = &yb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k < nx; k++) {
    if ((x->data[k].im == 0.0) && (!(muDoubleScalarAbs(x->data[k].re) > 1.0))) {
      x->data[k].re = muDoubleScalarAcos(x->data[k].re);
      x->data[k].im = 0.0;
    } else {
      v.re = x->data[k].re + 1.0;
      v.im = x->data[k].im;
      b_sqrt(&v);
      u.re = 1.0 - x->data[k].re;
      u.im = 0.0 - x->data[k].im;
      b_sqrt(&u);
      if ((-v.im == 0.0) && (u.im == 0.0)) {
        ci = 0.0;
      } else {
        t3 = v.re * u.im;
        t4 = -v.im * u.re;
        ci = t3 + t4;
        if ((muDoubleScalarIsInf(ci) || muDoubleScalarIsNaN(ci)) &&
            (!muDoubleScalarIsNaN(v.re)) && (!muDoubleScalarIsNaN(-v.im)) &&
            (!muDoubleScalarIsNaN(u.re)) && (!muDoubleScalarIsNaN(u.im))) {
          t = v.re;
          sai = -v.im;
          scaleA = rescale(&t, &sai);
          sbr = u.re;
          sbi = u.im;
          scaleB = rescale(&sbr, &sbi);
          if ((!muDoubleScalarIsInf(scaleA)) && (!muDoubleScalarIsNaN(scaleA)) &&
              ((!muDoubleScalarIsInf(scaleB)) && (!muDoubleScalarIsNaN(scaleB))))
          {
            overflow = true;
          } else {
            overflow = false;
          }

          if (muDoubleScalarIsNaN(ci) || (muDoubleScalarIsInf(ci) && overflow))
          {
            ci = t * sbi + sai * sbr;
            if (ci != 0.0) {
              ci = ci * scaleA * scaleB;
            } else {
              if ((muDoubleScalarIsInf(scaleA) && ((u.re == 0.0) || (u.im == 0.0)))
                  || (muDoubleScalarIsInf(scaleB) && ((v.re == 0.0) || (-v.im ==
                     0.0)))) {
                if (muDoubleScalarIsNaN(t3)) {
                  t3 = 0.0;
                }

                if (muDoubleScalarIsNaN(t4)) {
                  t4 = 0.0;
                }

                ci = t3 + t4;
              }
            }
          }
        }
      }

      overflow = (ci < 0.0);
      if (overflow) {
        ci = -ci;
      }

      if (ci >= 2.68435456E+8) {
        ci = muDoubleScalarLog(ci) + 0.69314718055994529;
      } else if (ci > 2.0) {
        ci = muDoubleScalarLog(2.0 * ci + 1.0 / (muDoubleScalarSqrt(ci * ci +
          1.0) + ci));
      } else {
        t = ci * ci;
        ci += t / (muDoubleScalarSqrt(t + 1.0) + 1.0);
        t = muDoubleScalarAbs(ci);
        if ((t > 4.503599627370496E+15) || (muDoubleScalarIsInf(ci) ||
             muDoubleScalarIsNaN(ci))) {
          ci++;
          ci = muDoubleScalarLog(ci);
        } else {
          if (!(t < 2.2204460492503131E-16)) {
            ci = muDoubleScalarLog(ci + 1.0) * (ci / ((ci + 1.0) - 1.0));
          }
        }
      }

      if (overflow) {
        ci = -ci;
      }

      x->data[k].re = 2.0 * muDoubleScalarAtan2(u.re, v.re);
      x->data[k].im = ci;
    }
  }
}

/* End of code generation (acos.c) */
