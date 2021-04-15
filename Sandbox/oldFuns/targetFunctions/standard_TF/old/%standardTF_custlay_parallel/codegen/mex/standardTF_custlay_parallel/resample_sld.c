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
#include "standardTF_custlay_parallel.h"
#include "resample_sld.h"
#include "standardTF_custlay_parallel_emxutil.h"
#include "interp1.h"
#include "indexShapeCheck.h"
#include "standardTF_custlay_parallel_data.h"

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

static emlrtRTEInfo x_emlrtRTEI = { 1, /* lineNo */
  34,                                  /* colNo */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 3, /* lineNo */
  1,                                   /* colNo */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 4,/* lineNo */
  1,                                   /* colNo */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 6,/* lineNo */
  1,                                   /* colNo */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 7,/* lineNo */
  1,                                   /* colNo */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 22,/* lineNo */
  13,                                  /* colNo */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m"/* pName */
};

static emlrtBCInfo gd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  9,                                   /* colNo */
  "x",                                 /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  17,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  27,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  24,                                  /* colNo */
  "x",                                 /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  24,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  24,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  45,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  24,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  46,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { 1,  /* iFirst */
  10000,                               /* iLast */
  36,                                  /* lineNo */
  15,                                  /* colNo */
  "x_new",                             /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  20,                                  /* colNo */
  "x_new",                             /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  35,                                  /* colNo */
  "x_new",                             /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  20,                                  /* colNo */
  "y_new",                             /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  13,                                  /* colNo */
  "x_new_tot",                         /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  13,                                  /* colNo */
  "y_new_tot",                         /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  5,                                   /* colNo */
  "x_new_tot",                         /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  5,                                   /* colNo */
  "y_new_tot",                         /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  26,                                  /* colNo */
  "prof",                              /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  38,                                  /* colNo */
  "x",                                 /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  9,                                   /* colNo */
  "x_new",                             /* aName */
  "resample_sld",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resample_sld.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = { -1, /* iFirst */
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
  int32_T i13;
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
  int32_T i14;
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
  real_T c_x[2];
  int32_T nm1d2;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T b1;
  int32_T iv6[2];
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
  emxInit_real_T1(sp, &x, 1, &y_emlrtRTEI, true);
  idx = sld->size[0];
  i13 = x->size[0];
  x->size[0] = idx;
  emxEnsureCapacity(sp, (emxArray__common *)x, i13, (int32_T)sizeof(real_T),
                    &x_emlrtRTEI);
  for (i13 = 0; i13 < idx; i13++) {
    x->data[i13] = sld->data[i13];
  }

  emxInit_real_T1(sp, &prof, 1, &ab_emlrtRTEI, true);
  idx = sld->size[0];
  i13 = prof->size[0];
  prof->size[0] = idx;
  emxEnsureCapacity(sp, (emxArray__common *)prof, i13, (int32_T)sizeof(real_T),
                    &x_emlrtRTEI);
  for (i13 = 0; i13 < idx; i13++) {
    prof->data[i13] = sld->data[i13 + sld->size[0]];
  }

  emxInit_real_T(sp, &x_new, 2, &bb_emlrtRTEI, true);
  i13 = x_new->size[0] * x_new->size[1];
  x_new->size[0] = 10000;
  x_new->size[1] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)x_new, i13, (int32_T)sizeof(real_T),
                    &x_emlrtRTEI);
  for (i13 = 0; i13 < 10000; i13++) {
    x_new->data[i13] = 0.0;
  }

  emxInit_real_T(sp, &y_new, 2, &cb_emlrtRTEI, true);
  i13 = y_new->size[0] * y_new->size[1];
  y_new->size[0] = 10000;
  y_new->size[1] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)y_new, i13, (int32_T)sizeof(real_T),
                    &x_emlrtRTEI);
  for (i13 = 0; i13 < 10000; i13++) {
    y_new->data[i13] = 0.0;
  }

  i13 = sld->size[0];
  if (!(1 <= i13)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i13, &gd_emlrtBCI, sp);
  }

  count = 1U;
  i = 0;
  emxInit_real_T(sp, &newsteps, 2, &db_emlrtRTEI, true);
  emxInit_real_T(sp, &varargin_2, 2, &x_emlrtRTEI, true);
  emxInit_real_T(sp, &b_x_new, 2, &x_emlrtRTEI, true);
  emxInit_real_T(sp, &b_y_new, 2, &x_emlrtRTEI, true);
  do {
    exitg2 = 0;
    i13 = sld->size[0];
    if (i + 2 < i13) {
      i13 = sld->size[0];
      i14 = sld->size[0];
      if (!((i + 2 >= 1) && (i + 2 <= i13))) {
        emlrtDynamicBoundsCheckR2012b(i + 2, 1, i13, &hd_emlrtBCI, sp);
      }

      if (!((i + 1 >= 1) && (i + 1 <= i14))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i14, &id_emlrtBCI, sp);
      }

      i13 = i + 1;
      this_step = sld->data[(i + sld->size[0]) + 1] - sld->data[(i13 + sld->
        size[0]) - 1];
      if (muDoubleScalarAbs(this_step) < 1.0) {
        /* Keep original points */
        i13 = sld->size[0];
        if (!((i + 2 >= 1) && (i + 2 <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, i13, &jd_emlrtBCI, sp);
        }

        i13 = 10000 * x_new->size[1];
        i14 = (int32_T)count;
        if (!((i14 >= 1) && (i14 <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, i13, &ae_emlrtBCI, sp);
        }

        x_new->data[i14 - 1] = sld->data[i + 1];
        i13 = sld->size[0];
        if (!((i + 2 >= 1) && (i + 2 <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, i13, &kd_emlrtBCI, sp);
        }

        i13 = 10000 * y_new->size[1];
        i14 = (int32_T)count;
        if (!((i14 >= 1) && (i14 <= i13))) {
          emlrtDynamicBoundsCheckR2012b(i14, 1, i13, &be_emlrtBCI, sp);
        }

        y_new->data[i14 - 1] = sld->data[(i + sld->size[0]) + 1];
        count++;
        i++;
      } else {
        if (this_step > 0.0) {
          st.site = &ec_emlrtRSI;
          i13 = sld->size[0];
          if (!((i + 1 >= 1) && (i + 1 <= i13))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, i13, &ld_emlrtBCI, &st);
          }

          i13 = i + 1;
          a = sld->data[(i13 + sld->size[0]) - 1];
          i13 = sld->size[0];
          if (!((i + 2 >= 1) && (i + 2 <= i13))) {
            emlrtDynamicBoundsCheckR2012b(i + 2, 1, i13, &md_emlrtBCI, &st);
          }

          this_step = sld->data[(i + sld->size[0]) + 1];
          if (muDoubleScalarIsNaN(a) || muDoubleScalarIsNaN(this_step)) {
            i13 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 1;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i13, (int32_T)
                              sizeof(real_T), &x_emlrtRTEI);
            newsteps->data[0] = rtNaN;
          } else if (sld->data[(i + sld->size[0]) + 1] < sld->data[i + sld->
                     size[0]]) {
            i13 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 0;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i13, (int32_T)
                              sizeof(real_T), &x_emlrtRTEI);
          } else if ((muDoubleScalarIsInf(a) || muDoubleScalarIsInf(this_step)) &&
                     (sld->data[i + sld->size[0]] == sld->data[(i + sld->size[0])
                      + 1])) {
            i13 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 1;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i13, (int32_T)
                              sizeof(real_T), &x_emlrtRTEI);
            newsteps->data[0] = rtNaN;
          } else if (muDoubleScalarFloor(a) == sld->data[i + sld->size[0]]) {
            this_step = sld->data[i + sld->size[0]];
            apnd = sld->data[(i + sld->size[0]) + 1];
            i13 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = (int32_T)muDoubleScalarFloor(apnd - this_step) +
              1;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i13, (int32_T)
                              sizeof(real_T), &x_emlrtRTEI);
            idx = (int32_T)muDoubleScalarFloor(apnd - this_step);
            for (i13 = 0; i13 <= idx; i13++) {
              newsteps->data[newsteps->size[0] * i13] = this_step + (real_T)i13;
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
              emlrtErrorWithMessageIdR2012b(&c_st, &ic_emlrtRTEI,
                "Coder:MATLAB:pmaxsize", 0);
            }

            i13 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = idx;
            emxEnsureCapacity(&b_st, (emxArray__common *)newsteps, i13, (int32_T)
                              sizeof(real_T), &x_emlrtRTEI);
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
          st.site = &dc_emlrtRSI;
          i13 = sld->size[0];
          if (!((i + 1 >= 1) && (i + 1 <= i13))) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, i13, &nd_emlrtBCI, &st);
          }

          i13 = i + 1;
          a = sld->data[(i13 + sld->size[0]) - 1];
          i13 = sld->size[0];
          if (!((i + 2 >= 1) && (i + 2 <= i13))) {
            emlrtDynamicBoundsCheckR2012b(i + 2, 1, i13, &od_emlrtBCI, &st);
          }

          this_step = sld->data[(i + sld->size[0]) + 1];
          if (muDoubleScalarIsNaN(a) || muDoubleScalarIsNaN(this_step)) {
            i13 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 1;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i13, (int32_T)
                              sizeof(real_T), &x_emlrtRTEI);
            newsteps->data[0] = rtNaN;
          } else if (sld->data[i + sld->size[0]] < sld->data[(i + sld->size[0])
                     + 1]) {
            i13 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 0;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i13, (int32_T)
                              sizeof(real_T), &x_emlrtRTEI);
          } else if ((muDoubleScalarIsInf(a) || muDoubleScalarIsInf(this_step)) &&
                     (sld->data[i + sld->size[0]] == sld->data[(i + sld->size[0])
                      + 1])) {
            i13 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = 1;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i13, (int32_T)
                              sizeof(real_T), &x_emlrtRTEI);
            newsteps->data[0] = rtNaN;
          } else if (muDoubleScalarFloor(a) == sld->data[i + sld->size[0]]) {
            this_step = sld->data[i + sld->size[0]];
            apnd = sld->data[(i + sld->size[0]) + 1];
            i13 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = (int32_T)muDoubleScalarFloor(-(apnd - this_step))
              + 1;
            emxEnsureCapacity(&st, (emxArray__common *)newsteps, i13, (int32_T)
                              sizeof(real_T), &x_emlrtRTEI);
            idx = (int32_T)muDoubleScalarFloor(-(apnd - this_step));
            for (i13 = 0; i13 <= idx; i13++) {
              newsteps->data[newsteps->size[0] * i13] = this_step - (real_T)i13;
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
              emlrtErrorWithMessageIdR2012b(&c_st, &ic_emlrtRTEI,
                "Coder:MATLAB:pmaxsize", 0);
            }

            i13 = newsteps->size[0] * newsteps->size[1];
            newsteps->size[0] = 1;
            newsteps->size[1] = idx;
            emxEnsureCapacity(&b_st, (emxArray__common *)newsteps, i13, (int32_T)
                              sizeof(real_T), &x_emlrtRTEI);
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

        st.site = &cc_emlrtRSI;
        i13 = sld->size[0];
        b_st.site = &l_emlrtRSI;
        if (!(i13 != 1)) {
          emlrtErrorWithMessageIdR2012b(&b_st, &bc_emlrtRTEI,
            "Coder:FE:PotentialVectorVector", 0);
        }

        st.site = &cc_emlrtRSI;
        i13 = sld->size[0];
        b_st.site = &l_emlrtRSI;
        if (!(i13 != 1)) {
          emlrtErrorWithMessageIdR2012b(&b_st, &bc_emlrtRTEI,
            "Coder:FE:PotentialVectorVector", 0);
        }

        i13 = sld->size[0];
        i14 = sld->size[0];
        for (nx = 0; nx < 2; nx++) {
          idx = (nx + i) + 1;
          if (!((idx >= 1) && (idx <= i13))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i13, &xd_emlrtBCI, sp);
          }

          b_prof[nx] = prof->data[idx - 1];
        }

        for (i13 = 0; i13 < 2; i13++) {
          nx = (i13 + i) + 1;
          if (!((nx >= 1) && (nx <= i14))) {
            emlrtDynamicBoundsCheckR2012b(nx, 1, i14, &yd_emlrtBCI, sp);
          }

          c_x[i13] = x->data[nx - 1];
        }

        st.site = &cc_emlrtRSI;
        interp1(&st, b_prof, c_x, newsteps, varargin_2);
        st.site = &bc_emlrtRSI;
        b_st.site = &nc_emlrtRSI;
        c_st.site = &n_emlrtRSI;
        b1 = (varargin_2->size[1] == 0);
        if (!b1) {
          emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        if (!(varargin_2->size[1] == 0)) {
          nx = varargin_2->size[1];
        } else {
          nx = 0;
        }

        i13 = b_x_new->size[0] * b_x_new->size[1];
        b_x_new->size[0] = 10000;
        b_x_new->size[1] = x_new->size[1] + nx;
        emxEnsureCapacity(&b_st, (emxArray__common *)b_x_new, i13, (int32_T)
                          sizeof(real_T), &x_emlrtRTEI);
        idx = x_new->size[1];
        for (i13 = 0; i13 < idx; i13++) {
          for (i14 = 0; i14 < 10000; i14++) {
            b_x_new->data[i14 + b_x_new->size[0] * i13] = x_new->data[i14 +
              x_new->size[0] * i13];
          }
        }

        for (i13 = 0; i13 < nx; i13++) {
          for (i14 = 0; i14 < 10000; i14++) {
            b_x_new->data[i14 + b_x_new->size[0] * (i13 + x_new->size[1])] =
              varargin_2->data[i14 + 10000 * i13];
          }
        }

        i13 = x_new->size[0] * x_new->size[1];
        x_new->size[0] = 10000;
        x_new->size[1] = b_x_new->size[1];
        emxEnsureCapacity(&b_st, (emxArray__common *)x_new, i13, (int32_T)sizeof
                          (real_T), &x_emlrtRTEI);
        idx = b_x_new->size[1];
        for (i13 = 0; i13 < idx; i13++) {
          for (i14 = 0; i14 < 10000; i14++) {
            x_new->data[i14 + x_new->size[0] * i13] = b_x_new->data[i14 +
              b_x_new->size[0] * i13];
          }
        }

        st.site = &ac_emlrtRSI;
        b_st.site = &nc_emlrtRSI;
        c_st.site = &n_emlrtRSI;
        b1 = (newsteps->size[1] == 0);
        if (!b1) {
          emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        if (!(newsteps->size[1] == 0)) {
          nx = newsteps->size[1];
        } else {
          nx = 0;
        }

        i13 = b_y_new->size[0] * b_y_new->size[1];
        b_y_new->size[0] = 10000;
        b_y_new->size[1] = y_new->size[1] + nx;
        emxEnsureCapacity(&b_st, (emxArray__common *)b_y_new, i13, (int32_T)
                          sizeof(real_T), &x_emlrtRTEI);
        idx = y_new->size[1];
        for (i13 = 0; i13 < idx; i13++) {
          for (i14 = 0; i14 < 10000; i14++) {
            b_y_new->data[i14 + b_y_new->size[0] * i13] = y_new->data[i14 +
              y_new->size[0] * i13];
          }
        }

        for (i13 = 0; i13 < nx; i13++) {
          for (i14 = 0; i14 < 10000; i14++) {
            b_y_new->data[i14 + b_y_new->size[0] * (i13 + y_new->size[1])] =
              newsteps->data[i14 + 10000 * i13];
          }
        }

        i13 = y_new->size[0] * y_new->size[1];
        y_new->size[0] = 10000;
        y_new->size[1] = b_y_new->size[1];
        emxEnsureCapacity(&b_st, (emxArray__common *)y_new, i13, (int32_T)sizeof
                          (real_T), &x_emlrtRTEI);
        idx = b_y_new->size[1];
        for (i13 = 0; i13 < idx; i13++) {
          for (i14 = 0; i14 < 10000; i14++) {
            y_new->data[i14 + y_new->size[0] * i13] = b_y_new->data[i14 +
              b_y_new->size[0] * i13];
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

  /* x_new_tot = x_new(:); */
  /* y_new_tot = y_new(:); */
  i13 = (int32_T)count;
  if (!((i13 >= 1) && (i13 <= 10000))) {
    emlrtDynamicBoundsCheckR2012b(i13, 1, 10000, &pd_emlrtBCI, sp);
  }

  /* Make it into a 'histogram' */
  i13 = x_new_tot->size[0];
  x_new_tot->size[0] = (int32_T)count;
  emxEnsureCapacity(sp, (emxArray__common *)x_new_tot, i13, (int32_T)sizeof
                    (real_T), &x_emlrtRTEI);
  idx = (int32_T)count;
  for (i13 = 0; i13 < idx; i13++) {
    x_new_tot->data[i13] = 0.0;
  }

  i13 = y_new_tot->size[0];
  y_new_tot->size[0] = (int32_T)count;
  emxEnsureCapacity(sp, (emxArray__common *)y_new_tot, i13, (int32_T)sizeof
                    (real_T), &x_emlrtRTEI);
  idx = (int32_T)count;
  for (i13 = 0; i13 < idx; i13++) {
    y_new_tot->data[i13] = 0.0;
  }

  i = 1;
  while (i - 1 <= (int32_T)count - 2) {
    i13 = (int32_T)count;
    i14 = 1 + i;
    if (!((i14 >= 1) && (i14 <= i13))) {
      emlrtDynamicBoundsCheckR2012b(i14, 1, i13, &qd_emlrtBCI, sp);
    }

    i13 = (int32_T)count;
    if (!((i >= 1) && (i <= i13))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i13, &rd_emlrtBCI, sp);
    }

    i13 = x_new_tot->size[0];
    if (!((i >= 1) && (i <= i13))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i13, &vd_emlrtBCI, sp);
    }

    x_new_tot->data[i - 1] = x_new->data[i] - x_new->data[i - 1];
    i13 = (int32_T)count;
    if (!((i >= 1) && (i <= i13))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i13, &sd_emlrtBCI, sp);
    }

    i13 = y_new_tot->size[0];
    if (!((i >= 1) && (i <= i13))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i13, &wd_emlrtBCI, sp);
    }

    y_new_tot->data[i - 1] = y_new->data[i - 1];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&y_new);
  emxFree_real_T(&x_new);
  emxInit_boolean_T(sp, &b_x, 1, &x_emlrtRTEI, true);

  /* Remove any zero thickness layers... */
  st.site = &yb_emlrtRSI;
  i13 = b_x->size[0];
  b_x->size[0] = x_new_tot->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)b_x, i13, (int32_T)sizeof(boolean_T),
                    &x_emlrtRTEI);
  idx = x_new_tot->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    b_x->data[i13] = (x_new_tot->data[i13] != 0.0);
  }

  emxInit_int32_T(&st, &ii, 1, &w_emlrtRTEI, true);
  b_st.site = &oc_emlrtRSI;
  nx = b_x->size[0];
  idx = 0;
  i13 = ii->size[0];
  ii->size[0] = b_x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof(int32_T),
                    &x_emlrtRTEI);
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
    emlrtErrorWithMessageIdR2012b(&b_st, &hc_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (b_x->size[0] == 1) {
    if (idx == 0) {
      i13 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i13, (int32_T)sizeof
                        (int32_T), &x_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i13 = 0;
    } else {
      i13 = idx;
    }

    iv6[0] = 1;
    iv6[1] = i13;
    c_st.site = &qc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv6);
    i14 = ii->size[0];
    ii->size[0] = i13;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, i14, (int32_T)sizeof
                      (int32_T), &r_emlrtRTEI);
  }

  emxFree_boolean_T(&b_x);
  i13 = x->size[0];
  x->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i13, (int32_T)sizeof(real_T),
                    &x_emlrtRTEI);
  idx = ii->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    x->data[i13] = ii->data[i13];
  }

  emxFree_int32_T(&ii);
  emxInit_real_T1(&st, &b_x_new_tot, 1, &x_emlrtRTEI, true);
  nm1d2 = x_new_tot->size[0];
  i13 = b_x_new_tot->size[0];
  b_x_new_tot->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_x_new_tot, i13, (int32_T)sizeof
                    (real_T), &x_emlrtRTEI);
  idx = x->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    i14 = (int32_T)x->data[i13];
    if (!((i14 >= 1) && (i14 <= nm1d2))) {
      emlrtDynamicBoundsCheckR2012b(i14, 1, nm1d2, &td_emlrtBCI, sp);
    }

    b_x_new_tot->data[i13] = x_new_tot->data[i14 - 1];
  }

  i13 = x_new_tot->size[0];
  x_new_tot->size[0] = b_x_new_tot->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)x_new_tot, i13, (int32_T)sizeof
                    (real_T), &x_emlrtRTEI);
  idx = b_x_new_tot->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    x_new_tot->data[i13] = b_x_new_tot->data[i13];
  }

  emxFree_real_T(&b_x_new_tot);
  emxInit_real_T1(sp, &b_y_new_tot, 1, &x_emlrtRTEI, true);
  nm1d2 = y_new_tot->size[0];
  i13 = b_y_new_tot->size[0];
  b_y_new_tot->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_y_new_tot, i13, (int32_T)sizeof
                    (real_T), &x_emlrtRTEI);
  idx = x->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    i14 = (int32_T)x->data[i13];
    if (!((i14 >= 1) && (i14 <= nm1d2))) {
      emlrtDynamicBoundsCheckR2012b(i14, 1, nm1d2, &ud_emlrtBCI, sp);
    }

    b_y_new_tot->data[i13] = y_new_tot->data[i14 - 1];
  }

  emxFree_real_T(&x);
  i13 = y_new_tot->size[0];
  y_new_tot->size[0] = b_y_new_tot->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)y_new_tot, i13, (int32_T)sizeof
                    (real_T), &x_emlrtRTEI);
  idx = b_y_new_tot->size[0];
  for (i13 = 0; i13 < idx; i13++) {
    y_new_tot->data[i13] = b_y_new_tot->data[i13];
  }

  emxFree_real_T(&b_y_new_tot);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (resample_sld.c) */
