/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * erf.c
 *
 * Code generation for function 'erf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_stanlay_parallel.h"
#include "erf.h"
#include "eml_int_forloop_overflow_check.h"
#include "standardTF_stanlay_parallel_emxutil.h"
#include "standardTF_stanlay_parallel_data.h"

/* Variable Definitions */
static emlrtRSInfo nb_emlrtRSI = { 9,  /* lineNo */
  "erf",                               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/specfun/erf.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 12, /* lineNo */
  "eml_erfcore",                       /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/specfun/private/eml_erfcore.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 53, /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

static emlrtRTEInfo s_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "erf",                               /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/specfun/erf.m"/* pName */
};

/* Function Definitions */
void b_erf(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  emxArray_real_T *b_x;
  int32_T ub_loop;
  int32_T loop_ub;
  boolean_T overflow;
  int32_T k;
  real_T absx;
  real_T s;
  real_T S;
  real_T R;
  int32_T eint;
  int32_T e;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_x, 2, &s_emlrtRTEI, true);
  st.site = &nb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  ub_loop = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = x->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)b_x, ub_loop, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  loop_ub = x->size[0] * x->size[1];
  for (ub_loop = 0; ub_loop < loop_ub; ub_loop++) {
    b_x->data[ub_loop] = x->data[ub_loop];
  }

  ub_loop = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)y, ub_loop, (int32_T)sizeof
                    (real_T), &s_emlrtRTEI);
  ub_loop = x->size[1];
  c_st.site = &pb_emlrtRSI;
  overflow = ((!(1 > x->size[1])) && (x->size[1] > 2147483646));
  if (overflow) {
    d_st.site = &eb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  emlrtEnterParallelRegion(&b_st, omp_in_parallel());
  emlrtPushJmpBuf(&b_st, &emlrtJBStack);

#pragma omp parallel for \
 num_threads(emlrtAllocRegionTLSs(b_st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(absx,s,S,R,e) \
 firstprivate(eint)

  for (k = 1; k <= ub_loop; k++) {
    /* ========================== COPYRIGHT NOTICE ============================ */
    /*  The algorithms for calculating ERF(X) and ERFC(X) are derived           */
    /*  from FDLIBM, which has the following notice:                            */
    /*                                                                          */
    /*  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.       */
    /*                                                                          */
    /*  Developed at SunSoft, a Sun Microsystems, Inc. business.                */
    /*  Permission to use, copy, modify, and distribute this                    */
    /*  software is freely granted, provided that this notice                   */
    /*  is preserved.                                                           */
    /* =============================    END    ================================ */
    absx = muDoubleScalarAbs(b_x->data[k - 1]);
    if (muDoubleScalarIsNaN(b_x->data[k - 1])) {
      s = b_x->data[k - 1];
    } else if (muDoubleScalarIsInf(b_x->data[k - 1])) {
      if (b_x->data[k - 1] < 0.0) {
        s = -1.0;
      } else {
        s = 1.0;
      }
    } else if (absx < 0.84375) {
      if (absx < 3.7252902984619141E-9) {
        if (absx < 2.8480945388892178E-306) {
          s = 0.125 * (8.0 * b_x->data[k - 1] + 1.0270333367641007 * b_x->data[k
                       - 1]);
        } else {
          s = b_x->data[k - 1] + 0.12837916709551259 * b_x->data[k - 1];
        }
      } else {
        s = b_x->data[k - 1] * b_x->data[k - 1];
        s = b_x->data[k - 1] + b_x->data[k - 1] * ((0.12837916709551256 + s *
          (-0.3250421072470015 + s * (-0.02848174957559851 + s *
          (-0.0057702702964894416 + s * -2.3763016656650163E-5)))) / (1.0 + s *
          (0.39791722395915535 + s * (0.0650222499887673 + s *
          (0.0050813062818757656 + s * (0.00013249473800432164 + s *
          -3.9602282787753681E-6))))));
      }
    } else if (absx < 1.25) {
      S = -0.0023621185607526594 + (absx - 1.0) * (0.41485611868374833 + (absx -
        1.0) * (-0.37220787603570132 + (absx - 1.0) * (0.31834661990116175 +
        (absx - 1.0) * (-0.11089469428239668 + (absx - 1.0) *
                        (0.035478304325618236 + (absx - 1.0) *
                         -0.0021663755948687908)))));
      s = 1.0 + (absx - 1.0) * (0.10642088040084423 + (absx - 1.0) *
        (0.540397917702171 + (absx - 1.0) * (0.071828654414196266 + (absx - 1.0)
        * (0.12617121980876164 + (absx - 1.0) * (0.013637083912029051 + (absx -
        1.0) * 0.011984499846799107)))));
      if (b_x->data[k - 1] >= 0.0) {
        s = 0.84506291151046753 + S / s;
      } else {
        s = -0.84506291151046753 - S / s;
      }
    } else if (absx > 6.0) {
      if (b_x->data[k - 1] < 0.0) {
        s = -1.0;
      } else {
        s = 1.0;
      }
    } else {
      s = 1.0 / (absx * absx);
      if (absx < 2.8571434020996094) {
        R = -0.0098649440348471482 + s * (-0.69385857270718176 + s *
          (-10.558626225323291 + s * (-62.375332450326006 + s *
          (-162.39666946257347 + s * (-184.60509290671104 + s *
          (-81.2874355063066 + s * -9.8143293441691455))))));
        S = 1.0 + s * (19.651271667439257 + s * (137.65775414351904 + s *
          (434.56587747522923 + s * (645.38727173326788 + s *
          (429.00814002756783 + s * (108.63500554177944 + s *
          (6.5702497703192817 + s * -0.0604244152148581)))))));
      } else {
        R = -0.0098649429247001 + s * (-0.799283237680523 + s *
          (-17.757954917754752 + s * (-160.63638485582192 + s *
          (-637.56644336838963 + s * (-1025.0951316110772 + s *
          -483.5191916086514)))));
        S = 1.0 + s * (30.338060743482458 + s * (325.79251299657392 + s *
          (1536.729586084437 + s * (3199.8582195085955 + s * (2553.0504064331644
          + s * (474.52854120695537 + s * -22.440952446585818))))));
      }

      if ((!muDoubleScalarIsInf(absx)) && (!muDoubleScalarIsNaN(absx))) {
        s = frexp(absx, &eint);
        e = eint;
      } else {
        s = absx;
        e = 0;
      }

      s = muDoubleScalarFloor(s * 2.097152E+6) / 2.097152E+6 *
        muDoubleScalarPower(2.0, e);
      s = muDoubleScalarExp(-s * s - 0.5625) * muDoubleScalarExp((s - absx) * (s
        + absx) + R / S) / absx;
      if (b_x->data[k - 1] < 0.0) {
        s--;
      } else {
        s = 1.0 - s;
      }
    }

    y->data[k - 1] = s;
  }

  emlrtPopJmpBuf(&b_st, &emlrtJBStack);
  emlrtExitParallelRegion(&b_st, omp_in_parallel());
  emxFree_real_T(&b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (erf.c) */
