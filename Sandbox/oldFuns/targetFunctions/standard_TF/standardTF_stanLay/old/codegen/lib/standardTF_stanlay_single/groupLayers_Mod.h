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
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
#include "standardTF_stanlay_single_types.h"

/* Function Declarations */
extern void groupLayers_Mod(const emxArray_real_T *allLayers, double allRoughs,
  const emxArray_char_T *geometry, double nbair, double nbsubs, emxArray_real_T *
  outLayers, double *outSsubs);

#endif

/* End of code generation (groupLayers_Mod.h) */
