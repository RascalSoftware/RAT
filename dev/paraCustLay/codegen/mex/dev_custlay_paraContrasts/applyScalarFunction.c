/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * applyScalarFunction.c
 *
 * Code generation for function 'applyScalarFunction'
 *
 */

/* Include files */
#include "applyScalarFunction.h"
#include "dev_custlay_paraContrasts_data.h"
#include "dev_custlay_paraContrasts_emxutil.h"
#include "dev_custlay_paraContrasts_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <math.h>

/* Variable Definitions */
static emlrtRSInfo ic_emlrtRSI = {
    60,                    /* lineNo */
    "applyScalarFunction", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunction.m" /* pathName */
};

static emlrtRTEInfo pd_emlrtRTEI = {
    30,                    /* lineNo */
    21,                    /* colNo */
    "applyScalarFunction", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunction.m" /* pName */
};

/* Function Definitions */
void applyScalarFunction(const emlrtStack *sp, const emxArray_real_T *x,
                         emxArray_real_T *z1)
{
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T R;
  real_T S;
  real_T absx;
  real_T d;
  real_T s;
  int32_T b;
  int32_T eint;
  int32_T k;
  int32_T ub_loop;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  ub_loop = z1->size[0] * z1->size[1];
  z1->size[0] = 1;
  z1->size[1] = x->size[1];
  emxEnsureCapacity_real_T(sp, z1, ub_loop, &pd_emlrtRTEI);
  st.site = &ic_emlrtRSI;
  if ((1 <= x->size[1]) && (x->size[1] > 2147483646)) {
    b_st.site = &wb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  ub_loop = x->size[1] - 1;
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
#pragma omp parallel num_threads(emlrtAllocRegionTLSs(                         \
    sp->tls, omp_in_parallel(), omp_get_max_threads(),                         \
    omp_get_num_procs())) private(c_st, emlrtJBEnviron, d, absx, s, S, R,      \
                                  eint, b) firstprivate(emlrtHadParallelError)
  {
    if (setjmp(emlrtJBEnviron) == 0) {

      c_st.prev = sp;
      c_st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
      c_st.site = NULL;
      emlrtSetJmpBuf(&c_st, &emlrtJBEnviron);
    } else {
      emlrtHadParallelError = true;
    }
#pragma omp for nowait
    for (k = 0; k <= ub_loop; k++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(emlrtJBEnviron) == 0) {

        /* ========================== COPYRIGHT NOTICE
         * ============================ */
        /*  The algorithms for calculating ERF(X) and ERFC(X) are derived */
        /*  from FDLIBM, which has the following notice: */
        /*                                                                          */
        /*  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved. */
        /*                                                                          */
        /*  Developed at SunSoft, a Sun Microsystems, Inc. business. */
        /*  Permission to use, copy, modify, and distribute this */
        /*  software is freely granted, provided that this notice */
        /*  is preserved. */
        /* =============================    END
         * ================================ */
        d = x->data[k];
        absx = muDoubleScalarAbs(d);
        if (muDoubleScalarIsNaN(d)) {
          z1->data[k] = d;
        } else if (muDoubleScalarIsInf(d)) {
          if (d < 0.0) {
            z1->data[k] = -1.0;
          } else {
            z1->data[k] = 1.0;
          }
        } else if (absx < 0.84375) {
          if (absx < 3.7252902984619141E-9) {
            if (absx < 2.8480945388892178E-306) {
              z1->data[k] = 0.125 * (8.0 * d + 1.0270333367641007 * d);
            } else {
              z1->data[k] = d + 0.12837916709551259 * d;
            }
          } else {
            s = d * d;
            z1->data[k] =
                d + d * ((s * (s * (s * (s * -2.3763016656650163E-5 +
                                         -0.0057702702964894416) +
                                    -0.02848174957559851) +
                               -0.3250421072470015) +
                          0.12837916709551256) /
                         (s * (s * (s * (s * (s * -3.9602282787753681E-6 +
                                              0.00013249473800432164) +
                                         0.0050813062818757656) +
                                    0.0650222499887673) +
                               0.39791722395915535) +
                          1.0));
          }
        } else if (absx < 1.25) {
          S = (absx - 1.0) *
                  ((absx - 1.0) *
                       ((absx - 1.0) *
                            ((absx - 1.0) *
                                 ((absx - 1.0) *
                                      ((absx - 1.0) * -0.0021663755948687908 +
                                       0.035478304325618236) +
                                  -0.11089469428239668) +
                             0.31834661990116175) +
                        -0.37220787603570132) +
                   0.41485611868374833) +
              -0.0023621185607526594;
          s = (absx - 1.0) *
                  ((absx - 1.0) *
                       ((absx - 1.0) *
                            ((absx - 1.0) *
                                 ((absx - 1.0) *
                                      ((absx - 1.0) * 0.011984499846799107 +
                                       0.013637083912029051) +
                                  0.12617121980876164) +
                             0.071828654414196266) +
                        0.540397917702171) +
                   0.10642088040084423) +
              1.0;
          if (d >= 0.0) {
            z1->data[k] = S / s + 0.84506291151046753;
          } else {
            z1->data[k] = -0.84506291151046753 - S / s;
          }
        } else if (absx > 6.0) {
          if (d < 0.0) {
            z1->data[k] = -1.0;
          } else {
            z1->data[k] = 1.0;
          }
        } else {
          s = 1.0 / (absx * absx);
          if (absx < 2.8571434020996094) {
            R = s * (s * (s * (s * (s * (s * (s * -9.8143293441691455 +
                                              -81.2874355063066) +
                                         -184.60509290671104) +
                                    -162.39666946257347) +
                               -62.375332450326006) +
                          -10.558626225323291) +
                     -0.69385857270718176) +
                -0.0098649440348471482;
            S = s * (s * (s * (s * (s * (s * (s * (s * -0.0604244152148581 +
                                                   6.5702497703192817) +
                                              108.63500554177944) +
                                         429.00814002756783) +
                                    645.38727173326788) +
                               434.56587747522923) +
                          137.65775414351904) +
                     19.651271667439257) +
                1.0;
          } else {
            R = s * (s * (s * (s * (s * (s * -483.5191916086514 +
                                         -1025.0951316110772) +
                                    -637.56644336838963) +
                               -160.63638485582192) +
                          -17.757954917754752) +
                     -0.799283237680523) +
                -0.0098649429247001;
            S = s * (s * (s * (s * (s * (s * (s * -22.440952446585818 +
                                              474.52854120695537) +
                                         2553.0504064331644) +
                                    3199.8582195085955) +
                               1536.729586084437) +
                          325.79251299657392) +
                     30.338060743482458) +
                1.0;
          }
          if (!muDoubleScalarIsNaN(absx)) {
            s = frexp(absx, &eint);
            b = eint;
          } else {
            s = absx;
            b = 0;
          }
          s = muDoubleScalarFloor(s * 2.097152E+6) / 2.097152E+6 *
              muDoubleScalarPower(2.0, b);
          s = muDoubleScalarExp(-s * s - 0.5625) *
              muDoubleScalarExp((s - absx) * (s + absx) + R / S) / absx;
          if (d < 0.0) {
            z1->data[k] = s - 1.0;
          } else {
            z1->data[k] = 1.0 - s;
          }
        }
      } else {
        emlrtHadParallelError = true;
      }
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
}

/* End of code generation (applyScalarFunction.c) */
