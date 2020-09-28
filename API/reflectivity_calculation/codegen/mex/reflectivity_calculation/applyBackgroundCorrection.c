/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * applyBackgroundCorrection.c
 *
 * Code generation for function 'applyBackgroundCorrection'
 *
 */

/* Include files */
#include "applyBackgroundCorrection.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtDCInfo tc_emlrtDCI = { 3,  /* lineNo */
  8,                                   /* colNo */
  "applyBackgroundCorrection",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo lb_emlrtECI = { -1, /* nDims */
  10,                                  /* lineNo */
  9,                                   /* colNo */
  "applyBackgroundCorrection",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m"/* pName */
};

static emlrtRTEInfo or_emlrtRTEI = { 6,/* lineNo */
  9,                                   /* colNo */
  "applyBackgroundCorrection",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m"/* pName */
};

static emlrtRTEInfo pr_emlrtRTEI = { 7,/* lineNo */
  9,                                   /* colNo */
  "applyBackgroundCorrection",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m"/* pName */
};

static emlrtRTEInfo qr_emlrtRTEI = { 10,/* lineNo */
  28,                                  /* colNo */
  "applyBackgroundCorrection",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m"/* pName */
};

/* Function Definitions */
void applyBackgroundCorrection(const emlrtStack *sp, emxArray_real_T *reflect,
  emxArray_real_T *Simul, emxArray_real_T *shifted_dat, real_T backg, real_T
  backsType)
{
  emxArray_real_T *b_shifted_dat;
  int32_T i;
  int32_T loop_ub;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (backsType != (int32_T)muDoubleScalarFloor(backsType)) {
    emlrtIntegerCheckR2012b(backsType, &tc_emlrtDCI, sp);
  }

  switch ((int32_T)backsType) {
   case 1:
    /* Add background to the simulation */
    i = reflect->size[0] * reflect->size[1];
    reflect->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflect, i, &or_emlrtRTEI);
    i = Simul->size[0] * Simul->size[1];
    Simul->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simul, i, &pr_emlrtRTEI);
    loop_ub = reflect->size[0];
    for (i = 0; i < loop_ub; i++) {
      reflect->data[i] += backg;
    }

    loop_ub = Simul->size[0];
    for (i = 0; i < loop_ub; i++) {
      Simul->data[i] += backg;
    }

    loop_ub = reflect->size[0];
    for (i = 0; i < loop_ub; i++) {
      reflect->data[i + reflect->size[0]] += backg;
    }

    loop_ub = Simul->size[0];
    for (i = 0; i < loop_ub; i++) {
      Simul->data[i + Simul->size[0]] += backg;
    }
    break;

   case 2:
    emxInit_real_T(sp, &b_shifted_dat, 1, &qr_emlrtRTEI, true);

    /*          %Subtract the background from the data.. */
    emlrtSubAssignSizeCheckR2012b(&shifted_dat->size[0], 1, &shifted_dat->size[0],
      1, &lb_emlrtECI, sp);
    loop_ub = shifted_dat->size[0] - 1;
    i = b_shifted_dat->size[0];
    b_shifted_dat->size[0] = loop_ub + 1;
    emxEnsureCapacity_real_T(sp, b_shifted_dat, i, &qr_emlrtRTEI);
    for (i = 0; i <= loop_ub; i++) {
      b_shifted_dat->data[i] = shifted_dat->data[i + shifted_dat->size[0]] -
        backg;
    }

    loop_ub = b_shifted_dat->size[0];
    for (i = 0; i < loop_ub; i++) {
      shifted_dat->data[i + shifted_dat->size[0]] = b_shifted_dat->data[i];
    }

    emxFree_real_T(&b_shifted_dat);

    /* shifted_dat(:,3) = shifted_dat(:,3) - backg;    */
    break;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (applyBackgroundCorrection.c) */
