/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * shiftdata.h
 *
 * Code generation for function 'shiftdata'
 *
 */

#ifndef SHIFTDATA_H
#define SHIFTDATA_H

/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
#include "standardTF_stanlay_parallel_types.h"

/* Function Declarations */
extern void shiftdata(double scalefac, double horshift, double dataPresent,
                      emxArray_real_T *data, const double dataLimits[2],
                      emxArray_real_T *shifted_data);

#endif

/* End of code generation (shiftdata.h) */
