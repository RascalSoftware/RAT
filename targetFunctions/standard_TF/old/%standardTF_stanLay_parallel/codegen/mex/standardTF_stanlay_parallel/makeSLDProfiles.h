/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * makeSLDProfiles.h
 *
 * Code generation for function 'makeSLDProfiles'
 *
 */

#ifndef MAKESLDPROFILES_H
#define MAKESLDPROFILES_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "standardTF_stanlay_parallel_types.h"

/* Function Declarations */
extern void makeSLDProfiles(const emlrtStack *sp, real_T nbair, real_T nbsub,
  const emxArray_real_T *sld, real_T ssub, const real_T repeats[2],
  emxArray_real_T *sldProfile);

#endif

/* End of code generation (makeSLDProfiles.h) */
