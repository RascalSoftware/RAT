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
extern emxArray_cell_wrap_0 *emxCreateND_cell_wrap_0(int numDimensions, int
  *size);
extern emxArray_cell_wrap_1 *emxCreateND_cell_wrap_1(int numDimensions, int
  *size);
extern emxArray_cell_wrap_2 *emxCreateND_cell_wrap_2(int numDimensions, int
  *size);
extern emxArray_cell_wrap_3 *emxCreateND_cell_wrap_3(int numDimensions, int
  *size);
extern emxArray_cell_wrap_5 *emxCreateND_cell_wrap_5(int numDimensions, int
  *size);
extern emxArray_cell_wrap_6 *emxCreateND_cell_wrap_6(int numDimensions, int
  *size);
extern emxArray_char_T *emxCreateND_char_T(int numDimensions, int *size);
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size);
extern emxArray_cell_wrap_0 *emxCreateWrapperND_cell_wrap_0(cell_wrap_0 *data,
  int numDimensions, int *size);
extern emxArray_cell_wrap_1 *emxCreateWrapperND_cell_wrap_1(cell_wrap_1 *data,
  int numDimensions, int *size);
extern emxArray_cell_wrap_2 *emxCreateWrapperND_cell_wrap_2(cell_wrap_2 *data,
  int numDimensions, int *size);
extern emxArray_cell_wrap_3 *emxCreateWrapperND_cell_wrap_3(cell_wrap_3 *data,
  int numDimensions, int *size);
extern emxArray_cell_wrap_5 *emxCreateWrapperND_cell_wrap_5(cell_wrap_5 *data,
  int numDimensions, int *size);
extern emxArray_cell_wrap_6 *emxCreateWrapperND_cell_wrap_6(cell_wrap_6 *data,
  int numDimensions, int *size);
extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
  int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, int *size);
extern emxArray_cell_wrap_0 *emxCreateWrapper_cell_wrap_0(cell_wrap_0 *data, int
  rows, int cols);
extern emxArray_cell_wrap_1 *emxCreateWrapper_cell_wrap_1(cell_wrap_1 *data, int
  rows, int cols);
extern emxArray_cell_wrap_2 *emxCreateWrapper_cell_wrap_2(cell_wrap_2 *data, int
  rows, int cols);
extern emxArray_cell_wrap_3 *emxCreateWrapper_cell_wrap_3(cell_wrap_3 *data, int
  rows, int cols);
extern emxArray_cell_wrap_5 *emxCreateWrapper_cell_wrap_5(cell_wrap_5 *data, int
  rows, int cols);
extern emxArray_cell_wrap_6 *emxCreateWrapper_cell_wrap_6(cell_wrap_6 *data, int
  rows, int cols);
extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_cell_wrap_0 *emxCreate_cell_wrap_0(int rows, int cols);
extern emxArray_cell_wrap_1 *emxCreate_cell_wrap_1(int rows, int cols);
extern emxArray_cell_wrap_2 *emxCreate_cell_wrap_2(int rows, int cols);
extern emxArray_cell_wrap_3 *emxCreate_cell_wrap_3(int rows, int cols);
extern emxArray_cell_wrap_5 *emxCreate_cell_wrap_5(int rows, int cols);
extern emxArray_cell_wrap_6 *emxCreate_cell_wrap_6(int rows, int cols);
extern emxArray_char_T *emxCreate_char_T(int rows, int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern void emxDestroyArray_cell_wrap_0(emxArray_cell_wrap_0 *emxArray);
extern void emxDestroyArray_cell_wrap_1(emxArray_cell_wrap_1 *emxArray);
extern void emxDestroyArray_cell_wrap_2(emxArray_cell_wrap_2 *emxArray);
extern void emxDestroyArray_cell_wrap_3(emxArray_cell_wrap_3 *emxArray);
extern void emxDestroyArray_cell_wrap_5(emxArray_cell_wrap_5 *emxArray);
extern void emxDestroyArray_cell_wrap_6(emxArray_cell_wrap_6 *emxArray);
extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxDestroy_cell_4(cell_4 emxArray);
extern void emxDestroy_cell_7(cell_7 emxArray);
extern void emxDestroy_struct0_T(struct0_T emxArray);
extern void emxDestroy_struct1_T(struct1_T emxArray);
extern void emxDestroy_struct2_T(struct2_T emxArray);
extern void emxDestroy_struct4_T(struct4_T emxArray);
extern void emxInit_cell_4(cell_4 *pStruct);
extern void emxInit_cell_7(cell_7 *pStruct);
extern void emxInit_struct0_T(struct0_T *pStruct);
extern void emxInit_struct1_T(struct1_T *pStruct);
extern void emxInit_struct2_T(struct2_T *pStruct);
extern void emxInit_struct4_T(struct4_T *pStruct);

#endif

/* End of code generation (reflectivity_calculation_emxAPI.h) */
