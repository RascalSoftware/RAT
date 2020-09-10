/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * matlabEngineCaller_customLayers_emxAPI.h
 *
 * Code generation for function 'matlabEngineCaller_customLayers_emxAPI'
 *
 */

#ifndef MATLABENGINECALLER_CUSTOMLAYERS_EMXAPI_H
#define MATLABENGINECALLER_CUSTOMLAYERS_EMXAPI_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "matlabEngineCaller_customLayers_types.h"

/* Function Declarations */
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, const int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, const int *size);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

/* End of code generation (matlabEngineCaller_customLayers_emxAPI.h) */
