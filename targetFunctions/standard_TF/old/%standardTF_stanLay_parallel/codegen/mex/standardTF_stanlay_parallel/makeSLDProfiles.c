/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * makeSLDProfiles.c
 *
 * Code generation for function 'makeSLDProfiles'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_stanlay_parallel.h"
#include "makeSLDProfiles.h"
#include "makeSLDProfileXY.h"

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = { 12,  /* lineNo */
  "makeSLDProfiles",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfiles.m"/* pathName */
};

/* Function Definitions */
void makeSLDProfiles(const emlrtStack *sp, real_T nbair, real_T nbsub, const
                     emxArray_real_T *sld, real_T ssub, const real_T repeats[2],
                     emxArray_real_T *sldProfile)
{
  real_T b_repeats;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (repeats[0] == 0.0) {
    b_repeats = 1.0;
  } else {
    b_repeats = repeats[1];
  }

  st.site = &p_emlrtRSI;
  makeSLDProfileXY(&st, nbair, nbsub, ssub, sld, sld->size[0], b_repeats,
                   sldProfile);
}

/* End of code generation (makeSLDProfiles.c) */
