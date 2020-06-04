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
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"

/* Function Declarations */
extern void makeSLDProfiles(double nbair, double nbsub, const double sld_data[],
  double ssub, const double repeats[2], emxArray_real_T *sldProfile);

#endif

/* End of code generation (makeSLDProfiles.h) */
