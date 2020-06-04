/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * oneCellTest_emxAPI.h
 *
 * Code generation for function 'oneCellTest_emxAPI'
 *
 */

#ifndef ONECELLTEST_EMXAPI_H
#define ONECELLTEST_EMXAPI_H

/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "oneCellTest_types.h"

/* Function Declarations */
extern emxArray_cell_wrap_0 *emxCreateND_cell_wrap_0(int numDimensions, int
  *size);
extern emxArray_cell_wrap_0 *emxCreateWrapperND_cell_wrap_0(cell_wrap_0 *data,
  int numDimensions, int *size);
extern emxArray_cell_wrap_0 *emxCreateWrapper_cell_wrap_0(cell_wrap_0 *data, int
  rows, int cols);
extern emxArray_cell_wrap_0 *emxCreate_cell_wrap_0(int rows, int cols);
extern void emxDestroyArray_cell_wrap_0(emxArray_cell_wrap_0 *emxArray);
extern void emxInitArray_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray, int
  numDimensions);

#endif

/* End of code generation (oneCellTest_emxAPI.h) */
