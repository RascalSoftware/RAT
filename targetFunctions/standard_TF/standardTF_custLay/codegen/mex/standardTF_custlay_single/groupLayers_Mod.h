/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * groupLayers_Mod.h
 *
 * Code generation for function 'groupLayers_Mod'
 *
 */

#ifndef GROUPLAYERS_MOD_H
#define GROUPLAYERS_MOD_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "standardTF_custlay_single_types.h"

/* Function Declarations */
extern void groupLayers_Mod(const emlrtStack *sp, const emxArray_real_T
  *allLayers, real_T allRoughs, const emxArray_char_T *geometry, emxArray_real_T
  *outLayers, real_T *outSsubs);

#endif

/* End of code generation (groupLayers_Mod.h) */
