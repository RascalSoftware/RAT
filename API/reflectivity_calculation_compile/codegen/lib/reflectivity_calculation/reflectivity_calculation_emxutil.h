/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation_emxutil.h
 *
 * Code generation for function 'reflectivity_calculation_emxutil'
 *
 */

#ifndef REFLECTIVITY_CALCULATION_EMXUTIL_H
#define REFLECTIVITY_CALCULATION_EMXUTIL_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"

/* Function Declarations */
extern void emxCopyStruct_cell_wrap_11(cell_wrap_11 *dst, const cell_wrap_11
  *src);
extern void emxCopyStruct_cell_wrap_12(cell_wrap_12 *dst, const cell_wrap_12
  *src);
extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_cell_wrap_11(emxArray_cell_wrap_11 *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_cell_wrap_12(emxArray_cell_wrap_12 *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_cell_wrap_14(emxArray_cell_wrap_14 *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_int16_T(emxArray_int16_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxFreeStruct_cell_13(cell_13 *pStruct);
extern void emxFreeStruct_struct4_T(struct4_T *pStruct);
extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
extern void emxFree_cell_wrap_11(emxArray_cell_wrap_11 **pEmxArray);
extern void emxFree_cell_wrap_12(emxArray_cell_wrap_12 **pEmxArray);
extern void emxFree_cell_wrap_14(emxArray_cell_wrap_14 **pEmxArray);
extern void emxFree_int16_T(emxArray_int16_T **pEmxArray);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_int8_T(emxArray_int8_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInitStruct_cell_13(cell_13 *pStruct);
extern void emxInitStruct_struct4_T(struct4_T *pStruct);
extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int numDimensions);
extern void emxInit_cell_wrap_11(emxArray_cell_wrap_11 **pEmxArray, int
  numDimensions);
extern void emxInit_cell_wrap_12(emxArray_cell_wrap_12 **pEmxArray, int
  numDimensions);
extern void emxInit_cell_wrap_14(emxArray_cell_wrap_14 **pEmxArray, int
  numDimensions);
extern void emxInit_int16_T(emxArray_int16_T **pEmxArray, int numDimensions);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_int8_T(emxArray_int8_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

/* End of code generation (reflectivity_calculation_emxutil.h) */
