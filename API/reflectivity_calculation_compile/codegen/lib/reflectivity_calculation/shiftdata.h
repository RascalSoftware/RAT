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
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"

/* Function Declarations */
extern void shiftdata(double scalefac, double horshift, double dataPresent,
                      double data[153], const double dataLimits[2], double
                      shifted_data_data[], int shifted_data_size[2]);

#endif

/* End of code generation (shiftdata.h) */
