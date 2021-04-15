/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * resample_sld.c
 *
 * Code generation for function 'resample_sld'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "resample_sld.h"
#include "standardTF_custlay_single_emxutil.h"
#include "interp1.h"
#include "indexShapeCheck.h"
#include "standardTF_custlay_single_data.h"

/* Variable Definitions */
static emlrtRSInfo yb_emlrtRSI = { 48, /* lineNo */
  "resample_sld",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 28, /* lineNo */
  "resample_sld",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 27, /* lineNo */
  "resample_sld",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 26, /* lineNo */
  "resample_sld",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 24, /* lineNo */
  "resample_sld",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 22, /* lineNo */
  "resample_sld",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 25, /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRTEInfo w_emlrtRTEI = { 1, /* lineNo */
  34,                                  /* colNo */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 3, /* lineNo */
  1,                                   /* colNo */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 4, /* lineNo */
  1,                                   /* colNo */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 6,/* lineNo */
  1,                                   /* colNo */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 7,/* lineNo */
  1,                                   /* colNo */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 22,/* lineNo */
  13,                                  /* colNo */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pName */
};

static emlrtBCInfo hd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  9,                                   /* colNo */
  "x",                                 /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  17,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  27,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  24,                                  /* colNo */
  "x",                                 /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  24,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  24,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  45,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  24,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  46,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { 1,  /* iFirst */
  10000,                               /* iLast */
  36,                                  /* lineNo */
  15,                                  /* colNo */
  "x_new",                             /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  20,                                  /* colNo */
  "x_new",                             /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  35,                                  /* colNo */
  "x_new",                             /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  20,                                  /* colNo */
  "y_new",                             /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  13,                                  /* colNo */
  "x_new_tot",                         /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  13,                                  /* colNo */
  "y_new_tot",                         /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  5,                                   /* colNo */
  "x_new_tot",                         /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  5,                                   /* colNo */
  "y_new_tot",                         /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  26,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  38,                                  /* colNo */
  "x",                                 /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  9,                                   /* colNo */
  "x_new",                             /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  9,                                   /* colNo */
  "y_new",                             /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void resample_sld(const emlrtStack *sp, const emxArray_real_T *sld,
                  emxArray_real_T *x_new_tot, emxArray_real_T *y_new_tot)
{
  emxArray_real_T *x;
  int32_T idx;
  int32_T i10;
  emxArray_real_T *prof;
  emxArray_real_T *x_new;
  emxArray_real_T *y_new;
  uint32_T count;
  int32_T i;
  emxArray_real_T *newsteps;
  emxArray_real_T *varargin_2;
  emxArray_real_T *b_x_new;
  emxArray_real_T *b_y_new;
  int32_T exitg2;
  int32_T i11;
  real_T this_step;
  real_T a;
  real_T apnd;
  real_T cdiff;
  real_T absa;
  real_T absb;
  emxArray_boolean_T *b_x;
  emxArray_int32_T *ii;
  int32_T nx;
  real_T b_prof[2];
  int32_T nm1d2;
  real_T c_x[2];
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T b1;
  int32_T iv8[2];
  emxArray_real_T *b_x_new_tot;
  emxArray_real_T *b_y_new_tot;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T1(sp, &x, 1, &x_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 9U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 0U);
  idx = sld->size[0];
  i10 = x->size[0];
  x->size[0] = idx;
  emxEnsureCapacity(sp, (emxArray__common *)x, i10, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  for (i10 = 0; i10 < idx; i10++) {
    x->data[i10] = sld->data[i10];
  }

  emxInit_real_T1(sp, &prof, 1, &y_emlrtRTEI, true);
  idx = sld->size[0];
  i10 = prof->size[0];
  prof->size[0] = idx;
  emxEnsureCapacity(sp, (emxArray__common *)prof, i10, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  for (i10 = 0; i10 < idx; i10++) {
    prof->data[i10] = sld->data[i10 + sld->size[0]];
  }

  emxInit_real_T(sp, &x_new, 2, &ab_emlrtRTEI, true);
  i10 = x_new->size[0] * x_new->size[1];
  x_new->size[0] = 10000;
  x_new->size[1] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)x_new, i10, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  for (i10 = 0; i10 < 10000; i10++) {
    x_new->data[i10] = 0.0;
  }

  emxInit_real_T(sp, &y_new, 2, &bb_emlrtRTEI, true);
  i10 = y_new->size[0] * y_new->size[1];
  y_new->size[0] = 10000;
  y_new->size[1] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)y_new, i10, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  for (i10 = 0; i10 < 10000; i10++) {
    y_new->data[i10] = 0.0;
  }

  i10 = sld->size[0];
  if (!(1 <= i10)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i10, &hd_emlrtBCI, sp);
  }

  count = 1U;
  i = 0;
  emxInit_real_T(sp, &newsteps, 2, &cb_emlrtRTEI, true);
  emxInit_real_T(sp, &varargin_2, 2, &w_emlrtRTEI, true);
  emxInit_real_T(sp, &b_x_new, 2, &w_emlrtRTEI, true);
  emxInit_real_T(sp, &b_y_new, 2, &w_emlrtRTEI, true);
  do {
    exitg2 = 0;
    i10 = sld->size[0];
    if (covrtLogWhile(&emlrtCoverageInstance, 9U, 0U, 0, i + 2 < i10)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 1U);
      i10 = sld->size[0];
      i11 = sld->size[0];
      if (!((i + 2 >= 1) && (i + 2 <= i10))) {
        emlrtDynamicBoundsCheckR2012b(i + 2, 1, i10, &id_emlrtBCI, sp);
      }

      if (!((i + 1 >= 1) && (i + 1 <= i11))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i11, &jd_emlrtBCI, sp);
      }

      i10 = i + 1;
      this_step = sld->data[(i + sld->size[0]) + 1] - sld->data[(i10 + sld->
        size[0]) - 1];
      if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 0, muDoubleScalarAbs
                     (this_step) < 1.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 2U);

        /* Keep original points */
        i10 = sld->size[0];
        if (!((i + 2 >= 1) && (i + 2 <= i10))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, i10, &kd_emlrtBCI, sp);
        }

        i10 = 10000 * x_new->size[1];
        i11 = (int32_T)count;
        if (!((i11 >= 1) && (i11 <= i10))) {
          emlrtDynamicBoundsCheckR2012b(i11, 1, i10, &be_emlrtBCI, sp);
        }

        x_new->data[i11 - 1] = sld->data[i + 1];
        i10 = sld->size[0];
        if (!((i + 2 >= 1) && (i + 2 <= i10))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, i10, &ld_emlrtBCI, sp);
        }

        i10 = 10000 * y_new->size[1];
        i11 = (int32_T)count;
        if (!((i11 >= 1) && (i11 <= i10))) {
          emlrtDynamicBoundsCheckR2012b(i11, 1, i10, &ce_emlrtBCI, sp);
        }

        y_new->data[i11 - 1] = sld->data[(i + sld->size[0]) + 1];
        count++;
        i++;
      } else {
        if (covrtLogIf(&emlrtCoverageInstance, 9U, 0U, 1, this_step > 0.0)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 3U);
          st.site = &ec_emlrtRSI;
          i10 = sld->size[0];
          if (!((i + 1 >= 1) && (i + 1 <= i10))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, i10, &md_emlrtBCI, &st);
          }

          i10 = i + 1;
          a = sld->data[(i10 + sld->size[0]) - 1];
          i10 = sld->size[0];
          if (!((i + 2 >= 1) && (i + 2 <= i10))) {
            emlrtDynamicBoundsCheckR2012b(i + 2, 1, i10, &nd_emlrtBCI, &st);
          }

          this_step = sld->data[(i + sld->size[0]) + 1];
          if (muDoubleScalarIsNaN(a) || muDoubleScalarIsNaN(this_step)) {
            i10 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 1;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i10, (int32_T)
                              sizeof(real_T), &w_emlrtRTEI);
            newsteps->data[0] = rtNaN;
          } else if (sld->data[(i + sld->size[0]) + 1] < sld->data[i + sld->
                     size[0]]) {
            i10 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 0;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i10, (int32_T)
                              sizeof(real_T), &w_emlrtRTEI);
          } else if ((muDoubleScalarIsInf(a) || muDoubleScalarIsInf(this_step)) &&
                     (sld->data[i + sld->size[0]] == sld->data[(i + sld->size[0])
                      + 1])) {
            i10 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 1;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i10, (int32_T)
                              sizeof(real_T), &w_emlrtRTEI);
            newsteps->data[0] = rtNaN;
          } else if (muDoubleScalarFloor(a) == sld->data[i + sld->size[0]]) {
            this_step = sld->data[i + sld->size[0]];
            apnd = sld->data[(i + sld->size[0]) + 1];
            i10 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = (int32_T)muDoubleScalarFloor(apnd - this_step) +
              1;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i10, (int32_T)
                              sizeof(real_T), &w_emlrtRTEI);
            idx = (int32_T)muDoubleScalarFloor(apnd - this_step);
            for (i10 = 0; i10 <= idx; i10++) {
              newsteps->data[newsteps->size[0] * i10] = this_step + (real_T)i10;
            }
          } else {
            b_st.site = &fc_emlrtRSI;
            this_step = muDoubleScalarFloor((sld->data[(i + sld->size[0]) + 1] -
              sld->data[i + sld->size[0]]) + 0.5);
            apnd = sld->data[i + sld->size[0]] + this_step;
            cdiff = apnd - sld->data[(i + sld->size[0]) + 1];
            absa = muDoubleScalarAbs(sld->data[i + sld->size[0]]);
            absb = muDoubleScalarAbs(sld->data[(i + sld->size[0]) + 1]);
            if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 *
                muDoubleScalarMax(absa, absb)) {
              this_step++;
              apnd = sld->data[(i + sld->size[0]) + 1];
            } else if (cdiff > 0.0) {
              apnd = sld->data[i + sld->size[0]] + (this_step - 1.0);
            } else {
              this_step++;
            }

            if (this_step >= 0.0) {
              idx = (int32_T)this_step;
            } else {
              idx = 0;
            }

            c_st.site = &gc_emlrtRSI;
            if (2.147483647E+9 < this_step) {
              emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
                "Coder:MATLAB:pmaxsize", 0);
            }

            i10 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = idx;
            emxEnsureCapacity(&b_st, (emxArray__common *)newsteps, i10, (int32_T)
                              sizeof(real_T), &w_emlrtRTEI);
            if (idx > 0) {
              newsteps->data[0] = sld->data[i + sld->size[0]];
              if (idx > 1) {
                newsteps->data[idx - 1] = apnd;
                nm1d2 = (idx - 1) / 2;
                c_st.site = &hc_emlrtRSI;
                for (nx = 1; nx < nm1d2; nx++) {
                  newsteps->data[nx] = a + (real_T)nx;
                  newsteps->data[(idx - nx) - 1] = apnd - (real_T)nx;
                }

                if (nm1d2 << 1 == idx - 1) {
                  newsteps->data[nm1d2] = (sld->data[i + sld->size[0]] + apnd) /
                    2.0;
                } else {
                  newsteps->data[nm1d2] = sld->data[i + sld->size[0]] + (real_T)
                    nm1d2;
                  newsteps->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
                }
              }
            }
          }
        } else {
          covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 4U);
          st.site = &dc_emlrtRSI;
          i10 = sld->size[0];
          if (!((i + 1 >= 1) && (i + 1 <= i10))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, i10, &od_emlrtBCI, &st);
          }

          i10 = i + 1;
          a = sld->data[(i10 + sld->size[0]) - 1];
          i10 = sld->size[0];
          if (!((i + 2 >= 1) && (i + 2 <= i10))) {
            emlrtDynamicBoundsCheckR2012b(i + 2, 1, i10, &pd_emlrtBCI, &st);
          }

          this_step = sld->data[(i + sld->size[0]) + 1];
          if (muDoubleScalarIsNaN(a) || muDoubleScalarIsNaN(this_step)) {
            i10 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 1;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i10, (int32_T)
                              sizeof(real_T), &w_emlrtRTEI);
            newsteps->data[0] = rtNaN;
          } else if (sld->data[i + sld->size[0]] < sld->data[(i + sld->size[0])
                     + 1]) {
            i10 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 0;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i10, (int32_T)
                              sizeof(real_T), &w_emlrtRTEI);
          } else if ((muDoubleScalarIsInf(a) || muDoubleScalarIsInf(this_step)) &&
                     (sld->data[i + sld->size[0]] == sld->data[(i + sld->size[0])
                      + 1])) {
            i10 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 1;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i10, (int32_T)
                              sizeof(real_T), &w_emlrtRTEI);
            newsteps->data[0] = rtNaN;
          } else if (muDoubleScalarFloor(a) == sld->data[i + sld->size[0]]) {
            this_step = sld->data[i + sld->size[0]];
            apnd = sld->data[(i + sld->size[0]) + 1];
            i10 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = (int32_T)muDoubleScalarFloor(-(apnd - this_step))
              + 1;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i10, (int32_T)
                              sizeof(real_T), &w_emlrtRTEI);
            idx = (int32_T)muDoubleScalarFloor(-(apnd - this_step));
            for (i10 = 0; i10 <= idx; i10++) {
              newsteps->data[newsteps->size[0] * i10] = this_step - (real_T)i10;
            }
          } else {
            b_st.site = &fc_emlrtRSI;
            this_step = muDoubleScalarFloor((sld->data[(i + sld->size[0]) + 1] -
              sld->data[i + sld->size[0]]) / -1.0 + 0.5);
            apnd = sld->data[i + sld->size[0]] + -this_step;
            cdiff = sld->data[(i + sld->size[0]) + 1] - apnd;
            absa = muDoubleScalarAbs(sld->data[i + sld->size[0]]);
            absb = muDoubleScalarAbs(sld->data[(i + sld->size[0]) + 1]);
            if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 *
                muDoubleScalarMax(absa, absb)) {
              this_step++;
              apnd = sld->data[(i + sld->size[0]) + 1];
            } else if (cdiff > 0.0) {
              apnd = sld->data[i + sld->size[0]] + -(this_step - 1.0);
            } else {
              this_step++;
            }

            if (this_step >= 0.0) {
              idx = (int32_T)this_step;
            } else {
              idx = 0;
            }

            c_st.site = &gc_emlrtRSI;
            if (2.147483647E+9 < this_step) {
              emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
                "Coder:MATLAB:pmaxsize", 0);
            }

            i10 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = idx;
            emxEnsureCapacity(&b_st, (emxArray__common *)newsteps, i10, (int32_T)
                              sizeof(real_T), &w_emlrtRTEI);
            if (idx > 0) {
              newsteps->data[0] = sld->data[i + sld->size[0]];
              if (idx > 1) {
                newsteps->data[idx - 1] = apnd;
                nm1d2 = (idx - 1) / 2;
                c_st.site = &hc_emlrtRSI;
                for (nx = 1; nx < nm1d2; nx++) {
                  newsteps->data[nx] = a + -(real_T)nx;
                  newsteps->data[(idx - nx) - 1] = apnd - (-(real_T)nx);
                }

                if (nm1d2 << 1 == idx - 1) {
                  newsteps->data[nm1d2] = (sld->data[i + sld->size[0]] + apnd) /
                    2.0;
                } else {
                  newsteps->data[nm1d2] = sld->data[i + sld->size[0]] + -(real_T)
                    nm1d2;
                  newsteps->data[nm1d2 + 1] = apnd - (-(real_T)nm1d2);
                }
              }
            }
          }
        }

        covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 5U);
        st.site = &cc_emlrtRSI;
        i10 = sld->size[0];
        b_st.site = &l_emlrtRSI;
        if (!(i10 != 1)) {
          emlrtErrorWithMessageIdR2012b(&b_st, &sb_emlrtRTEI,
            "Coder:FE:PotentialVectorVector", 0);
        }

        st.site = &cc_emlrtRSI;
        i10 = sld->size[0];
        b_st.site = &l_emlrtRSI;
        if (!(i10 != 1)) {
          emlrtErrorWithMessageIdR2012b(&b_st, &sb_emlrtRTEI,
            "Coder:FE:PotentialVectorVector", 0);
        }

        i10 = sld->size[0];
        i11 = sld->size[0];
        for (nx = 0; nx < 2; nx++) {
          idx = (nx + i) + 1;
          if (!((idx >= 1) && (idx <= i10))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i10, &yd_emlrtBCI, sp);
          }

          b_prof[nx] = prof->data[idx - 1];
        }

        for (i10 = 0; i10 < 2; i10++) {
          nx = (i10 + i) + 1;
          if (!((nx >= 1) && (nx <= i11))) {
            emlrtDynamicBoundsCheckR2012b(nx, 1, i11, &ae_emlrtBCI, sp);
          }

          c_x[i10] = x->data[nx - 1];
        }

        st.site = &cc_emlrtRSI;
        interp1(&st, b_prof, c_x, newsteps, varargin_2);
        st.site = &bc_emlrtRSI;
        b_st.site = &nc_emlrtRSI;
        c_st.site = &n_emlrtRSI;
        b1 = (varargin_2->size[1] == 0);
        if (!b1) {
          emlrtErrorWithMessageIdR2012b(&c_st, &rb_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        if (!(varargin_2->size[1] == 0)) {
          nx = varargin_2->size[1];
        } else {
          nx = 0;
        }

        i10 = b_x_new->size[0] * b_x_new->size[1];
        b_x_new->size[0] = 10000;
        b_x_new->size[1] = x_new->size[1] + nx;
        emxEnsureCapacity(&b_st, (emxArray__common *)b_x_new, i10, (int32_T)
                          sizeof(real_T), &w_emlrtRTEI);
        idx = x_new->size[1];
        for (i10 = 0; i10 < idx; i10++) {
          for (i11 = 0; i11 < 10000; i11++) {
            b_x_new->data[i11 + b_x_new->size[0] * i10] = x_new->data[i11 +
              x_new->size[0] * i10];
          }
        }

        for (i10 = 0; i10 < nx; i10++) {
          for (i11 = 0; i11 < 10000; i11++) {
            b_x_new->data[i11 + b_x_new->size[0] * (i10 + x_new->size[1])] =
              varargin_2->data[i11 + 10000 * i10];
          }
        }

        i10 = x_new->size[0] * x_new->size[1];
        x_new->size[0] = 10000;
        x_new->size[1] = b_x_new->size[1];
        emxEnsureCapacity(&b_st, (emxArray__common *)x_new, i10, (int32_T)sizeof
                          (real_T), &w_emlrtRTEI);
        idx = b_x_new->size[1];
        for (i10 = 0; i10 < idx; i10++) {
          for (i11 = 0; i11 < 10000; i11++) {
            x_new->data[i11 + x_new->size[0] * i10] = b_x_new->data[i11 +
              b_x_new->size[0] * i10];
          }
        }

        st.site = &ac_emlrtRSI;
        b_st.site = &nc_emlrtRSI;
        c_st.site = &n_emlrtRSI;
        b1 = (newsteps->size[1] == 0);
        if (!b1) {
          emlrtErrorWithMessageIdR2012b(&c_st, &rb_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        if (!(newsteps->size[1] == 0)) {
          nx = newsteps->size[1];
        } else {
          nx = 0;
        }

        i10 = b_y_new->size[0] * b_y_new->size[1];
        b_y_new->size[0] = 10000;
        b_y_new->size[1] = y_new->size[1] + nx;
        emxEnsureCapacity(&b_st, (emxArray__common *)b_y_new, i10, (int32_T)
                          sizeof(real_T), &w_emlrtRTEI);
        idx = y_new->size[1];
        for (i10 = 0; i10 < idx; i10++) {
          for (i11 = 0; i11 < 10000; i11++) {
            b_y_new->data[i11 + b_y_new->size[0] * i10] = y_new->data[i11 +
              y_new->size[0] * i10];
          }
        }

        for (i10 = 0; i10 < nx; i10++) {
          for (i11 = 0; i11 < 10000; i11++) {
            b_y_new->data[i11 + b_y_new->size[0] * (i10 + y_new->size[1])] =
              newsteps->data[i11 + 10000 * i10];
          }
        }

        i10 = y_new->size[0] * y_new->size[1];
        y_new->size[0] = 10000;
        y_new->size[1] = b_y_new->size[1];
        emxEnsureCapacity(&b_st, (emxArray__common *)y_new, i10, (int32_T)sizeof
                          (real_T), &w_emlrtRTEI);
        idx = b_y_new->size[1];
        for (i10 = 0; i10 < idx; i10++) {
          for (i11 = 0; i11 < 10000; i11++) {
            y_new->data[i11 + y_new->size[0] * i10] = b_y_new->data[i11 +
              b_y_new->size[0] * i10];
          }
        }

        idx = muIntScalarMax_sint32(10000, x_new->size[1]);
        count = (uint32_T)idx;
        i++;
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    } else {
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  emxFree_real_T(&b_y_new);
  emxFree_real_T(&b_x_new);
  emxFree_real_T(&varargin_2);
  emxFree_real_T(&newsteps);
  emxFree_real_T(&prof);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 6U);

  /* x_new_tot = x_new(:); */
  /* y_new_tot = y_new(:); */
  i10 = (int32_T)count;
  if (!((i10 >= 1) && (i10 <= 10000))) {
    emlrtDynamicBoundsCheckR2012b(i10, 1, 10000, &qd_emlrtBCI, sp);
  }

  /* Make it into a 'histogram' */
  i10 = x_new_tot->size[0];
  x_new_tot->size[0] = (int32_T)count;
  emxEnsureCapacity(sp, (emxArray__common *)x_new_tot, i10, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  idx = (int32_T)count;
  for (i10 = 0; i10 < idx; i10++) {
    x_new_tot->data[i10] = 0.0;
  }

  i10 = y_new_tot->size[0];
  y_new_tot->size[0] = (int32_T)count;
  emxEnsureCapacity(sp, (emxArray__common *)y_new_tot, i10, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  idx = (int32_T)count;
  for (i10 = 0; i10 < idx; i10++) {
    y_new_tot->data[i10] = 0.0;
  }

  i = 1;
  while (i - 1 <= (int32_T)count - 2) {
    covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 7U);
    i10 = (int32_T)count;
    i11 = 1 + i;
    if (!((i11 >= 1) && (i11 <= i10))) {
      emlrtDynamicBoundsCheckR2012b(i11, 1, i10, &rd_emlrtBCI, sp);
    }

    i10 = (int32_T)count;
    if (!((i >= 1) && (i <= i10))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i10, &sd_emlrtBCI, sp);
    }

    i10 = x_new_tot->size[0];
    if (!((i >= 1) && (i <= i10))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i10, &wd_emlrtBCI, sp);
    }

    x_new_tot->data[i - 1] = x_new->data[i] - x_new->data[i - 1];
    i10 = (int32_T)count;
    if (!((i >= 1) && (i <= i10))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i10, &td_emlrtBCI, sp);
    }

    i10 = y_new_tot->size[0];
    if (!((i >= 1) && (i <= i10))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i10, &xd_emlrtBCI, sp);
    }

    y_new_tot->data[i - 1] = y_new->data[i - 1];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&y_new);
  emxFree_real_T(&x_new);
  emxInit_boolean_T(sp, &b_x, 1, &w_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 9U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 9U, 8U);

  /* Remove any zero thickness layers... */
  st.site = &yb_emlrtRSI;
  i10 = b_x->size[0];
  b_x->size[0] = x_new_tot->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)b_x, i10, (int32_T)sizeof(boolean_T),
                    &w_emlrtRTEI);
  idx = x_new_tot->size[0];
  for (i10 = 0; i10 < idx; i10++) {
    b_x->data[i10] = (x_new_tot->data[i10] != 0.0);
  }

  emxInit_int32_T(&st, &ii, 1, &v_emlrtRTEI, true);
  b_st.site = &oc_emlrtRSI;
  nx = b_x->size[0];
  idx = 0;
  i10 = ii->size[0];
  ii->size[0] = b_x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i10, (int32_T)sizeof(int32_T),
                    &w_emlrtRTEI);
  c_st.site = &pc_emlrtRSI;
  nm1d2 = 1;
  exitg1 = false;
  while ((!exitg1) && (nm1d2 <= nx)) {
    guard1 = false;
    if (b_x->data[nm1d2 - 1]) {
      idx++;
      ii->data[idx - 1] = nm1d2;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      nm1d2++;
    }
  }

  if (!(idx <= b_x->size[0])) {
    emlrtErrorWithMessageIdR2012b(&b_st, &yb_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (b_x->size[0] == 1) {
    if (idx == 0) {
      i10 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i10, (int32_T)sizeof
                        (int32_T), &w_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i10 = 0;
    } else {
      i10 = idx;
    }

    iv8[0] = 1;
    iv8[1] = i10;
    c_st.site = &qc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv8);
    i11 = ii->size[0];
    ii->size[0] = i10;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, i11, (int32_T)sizeof
                      (int32_T), &b_emlrtRTEI);
  }

  emxFree_boolean_T(&b_x);
  i10 = x->size[0];
  x->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i10, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  idx = ii->size[0];
  for (i10 = 0; i10 < idx; i10++) {
    x->data[i10] = ii->data[i10];
  }

  emxFree_int32_T(&ii);
  emxInit_real_T1(&st, &b_x_new_tot, 1, &w_emlrtRTEI, true);
  nm1d2 = x_new_tot->size[0];
  i10 = b_x_new_tot->size[0];
  b_x_new_tot->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_x_new_tot, i10, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  idx = x->size[0];
  for (i10 = 0; i10 < idx; i10++) {
    i11 = (int32_T)x->data[i10];
    if (!((i11 >= 1) && (i11 <= nm1d2))) {
      emlrtDynamicBoundsCheckR2012b(i11, 1, nm1d2, &ud_emlrtBCI, sp);
    }

    b_x_new_tot->data[i10] = x_new_tot->data[i11 - 1];
  }

  i10 = x_new_tot->size[0];
  x_new_tot->size[0] = b_x_new_tot->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)x_new_tot, i10, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  idx = b_x_new_tot->size[0];
  for (i10 = 0; i10 < idx; i10++) {
    x_new_tot->data[i10] = b_x_new_tot->data[i10];
  }

  emxFree_real_T(&b_x_new_tot);
  emxInit_real_T1(sp, &b_y_new_tot, 1, &w_emlrtRTEI, true);
  nm1d2 = y_new_tot->size[0];
  i10 = b_y_new_tot->size[0];
  b_y_new_tot->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_y_new_tot, i10, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  idx = x->size[0];
  for (i10 = 0; i10 < idx; i10++) {
    i11 = (int32_T)x->data[i10];
    if (!((i11 >= 1) && (i11 <= nm1d2))) {
      emlrtDynamicBoundsCheckR2012b(i11, 1, nm1d2, &vd_emlrtBCI, sp);
    }

    b_y_new_tot->data[i10] = y_new_tot->data[i11 - 1];
  }

  emxFree_real_T(&x);
  i10 = y_new_tot->size[0];
  y_new_tot->size[0] = b_y_new_tot->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)y_new_tot, i10, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  idx = b_y_new_tot->size[0];
  for (i10 = 0; i10 < idx; i10++) {
    y_new_tot->data[i10] = b_y_new_tot->data[i10];
  }

  emxFree_real_T(&b_y_new_tot);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (resample_sld.c) */
