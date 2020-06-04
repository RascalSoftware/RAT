/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation_emxAPI.h
 *
 * Code generation for function 'reflectivity_calculation_emxAPI'
 *
 */

#ifndef REFLECTIVITY_CALCULATION_EMXAPI_H
#define REFLECTIVITY_CALCULATION_EMXAPI_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"

/* Function Declarations */
extern emxArray_cell_wrap_11 *emxCreateND_cell_wrap_11(int numDimensions, int
  *size);
extern emxArray_cell_wrap_12 *emxCreateND_cell_wrap_12(int numDimensions, int
  *size);
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size);
extern emxArray_cell_wrap_11 *emxCreateWrapperND_cell_wrap_11(cell_wrap_11 *data,
  int numDimensions, int *size);
extern emxArray_cell_wrap_12 *emxCreateWrapperND_cell_wrap_12(cell_wrap_12 *data,
  int numDimensions, int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, int *size);
extern emxArray_cell_wrap_11 *emxCreateWrapper_cell_wrap_11(cell_wrap_11 *data,
  int rows, int cols);
extern emxArray_cell_wrap_12 *emxCreateWrapper_cell_wrap_12(cell_wrap_12 *data,
  int rows, int cols);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_cell_wrap_11 *emxCreate_cell_wrap_11(int rows, int cols);
extern emxArray_cell_wrap_12 *emxCreate_cell_wrap_12(int rows, int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern void emxDestroyArray_cell_wrap_11(emxArray_cell_wrap_11 *emxArray);
extern void emxDestroyArray_cell_wrap_12(emxArray_cell_wrap_12 *emxArray);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxDestroy_cell_13(cell_13 emxArray);
extern void emxDestroy_struct4_T(struct4_T emxArray);
extern void emxInit_cell_13(cell_13 *pStruct);
extern void emxInit_struct4_T(struct4_T *pStruct);

#endif

/* End of code generation (reflectivity_calculation_emxAPI.h) */
