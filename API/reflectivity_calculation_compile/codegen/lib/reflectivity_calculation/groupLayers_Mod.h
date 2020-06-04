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
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"

/* Function Declarations */
extern void groupLayers_Mod(const double allLayers[10], double allRoughs, const
  char geometry[13], double nbair, double nbsubs, double outLayers_data[], int
  outLayers_size[2], double *outSsubs);

#endif

/* End of code generation (groupLayers_Mod.h) */
