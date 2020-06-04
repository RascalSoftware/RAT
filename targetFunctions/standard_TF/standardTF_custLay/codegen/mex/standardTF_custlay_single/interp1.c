/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * interp1.c
 *
 * Code generation for function 'interp1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "interp1.h"
#include "error.h"
#include "eml_int_forloop_overflow_check.h"
#include "standardTF_custlay_single_emxutil.h"
#include "standardTF_custlay_single_data.h"

/* Variable Definitions */
static emlrtRSInfo ic_emlrtRSI = { 39, /* lineNo */
  "interp1",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 164,/* lineNo */
  "interp1",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 184,/* lineNo */
  "interp1",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 222,/* lineNo */
  "interp1",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 582,/* lineNo */
  "interp1",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pathName */
};

static emlrtRTEInfo db_emlrtRTEI = { 1,/* lineNo */
  15,                                  /* colNo */
  "interp1",                           /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/polyfun/interp1.m"/* pName */
};

/* Function Definitions */
void interp1(const emlrtStack *sp, const real_T varargin_1[2], const real_T
             varargin_2[2], const emxArray_real_T *varargin_3, emxArray_real_T
             *Vq)
{
  real_T y[2];
  real_T x[2];
  int32_T i;
  uint32_T outsize[2];
  int32_T loop_ub;
  int32_T exitg1;
  boolean_T overflow;
  real_T r;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ic_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  for (i = 0; i < 2; i++) {
    y[i] = varargin_2[i];
    x[i] = varargin_1[i];
  }

  for (i = 0; i < 2; i++) {
    outsize[i] = (uint32_T)varargin_3->size[i];
  }

  i = Vq->size[0] * Vq->size[1];
  Vq->size[0] = 1;
  Vq->size[1] = (int32_T)outsize[1];
  emxEnsureCapacity(&st, (emxArray__common *)Vq, i, (int32_T)sizeof(real_T),
                    &db_emlrtRTEI);
  loop_ub = (int32_T)outsize[1];
  for (i = 0; i < loop_ub; i++) {
    Vq->data[i] = rtNaN;
  }

  if (varargin_3->size[1] != 0) {
    i = 1;
    do {
      exitg1 = 0;
      if (i < 3) {
        if (muDoubleScalarIsNaN(varargin_1[i - 1])) {
          b_st.site = &jc_emlrtRSI;
          error(&b_st);
        } else {
          i++;
        }
      } else {
        if (varargin_1[1] < varargin_1[0]) {
          x[0] = varargin_1[1];
          x[1] = varargin_1[0];
          y[0] = varargin_2[1];
          y[1] = varargin_2[0];
        }

        if (x[1] <= x[0]) {
          b_st.site = &kc_emlrtRSI;
          b_error(&b_st);
        }

        b_st.site = &lc_emlrtRSI;
        c_st.site = &mc_emlrtRSI;
        overflow = (varargin_3->size[1] > 2147483646);
        if (overflow) {
          d_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (i = 0; i + 1 <= varargin_3->size[1]; i++) {
          r = Vq->data[i];
          if (muDoubleScalarIsNaN(varargin_3->data[i])) {
            r = rtNaN;
          } else {
            if ((!(varargin_3->data[i] > x[1])) && (!(varargin_3->data[i] < x[0])))
            {
              r = (varargin_3->data[i] - x[0]) / (x[1] - x[0]);
              if (r == 0.0) {
                r = y[0];
              } else if (r == 1.0) {
                r = y[1];
              } else if (y[0] == y[1]) {
                r = y[0];
              } else {
                r = (1.0 - r) * y[0] + r * y[1];
              }
            }
          }

          Vq->data[i] = r;
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

/* End of code generation (interp1.c) */
