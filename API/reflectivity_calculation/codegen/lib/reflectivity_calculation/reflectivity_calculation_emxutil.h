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
extern void emxCopyStruct_cell_wrap_5(cell_wrap_5 *dst, const cell_wrap_5 *src);
extern void emxCopyStruct_cell_wrap_6(cell_wrap_6 *dst, const cell_wrap_6 *src);
extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_cell_wrap_1(emxArray_cell_wrap_1 *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_cell_wrap_13(emxArray_cell_wrap_13 *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_cell_wrap_5(emxArray_cell_wrap_5 *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_cell_wrap_6(emxArray_cell_wrap_6 *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_cell_wrap_8(emxArray_cell_wrap_8 *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_cell_wrap_9(emxArray_cell_wrap_9 *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_int16_T(emxArray_int16_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_uint32_T(emxArray_uint32_T *emxArray, int oldNumel);
extern void emxFreeStruct_cell_4(cell_4 *pStruct);
extern void emxFreeStruct_cell_7(cell_7 *pStruct);
extern void emxFreeStruct_struct0_T(struct0_T *pStruct);
extern void emxFreeStruct_struct1_T(struct1_T *pStruct);
extern void emxFreeStruct_struct2_T(struct2_T *pStruct);
extern void emxFreeStruct_struct4_T(struct4_T *pStruct);
extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
extern void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray);
extern void emxFree_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray);
extern void emxFree_cell_wrap_13(emxArray_cell_wrap_13 **pEmxArray);
extern void emxFree_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray);
extern void emxFree_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray);
extern void emxFree_cell_wrap_5(emxArray_cell_wrap_5 **pEmxArray);
extern void emxFree_cell_wrap_6(emxArray_cell_wrap_6 **pEmxArray);
extern void emxFree_cell_wrap_8(emxArray_cell_wrap_8 **pEmxArray);
extern void emxFree_cell_wrap_9(emxArray_cell_wrap_9 **pEmxArray);
extern void emxFree_char_T(emxArray_char_T **pEmxArray);
extern void emxFree_int16_T(emxArray_int16_T **pEmxArray);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_int8_T(emxArray_int8_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxFree_uint32_T(emxArray_uint32_T **pEmxArray);
extern void emxInitStruct_cell_4(cell_4 *pStruct);
extern void emxInitStruct_cell_7(cell_7 *pStruct);
extern void emxInitStruct_struct0_T(struct0_T *pStruct);
extern void emxInitStruct_struct1_T(struct1_T *pStruct);
extern void emxInitStruct_struct2_T(struct2_T *pStruct);
extern void emxInitStruct_struct4_T(struct4_T *pStruct);
extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int numDimensions);
extern void emxInit_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray, int
  numDimensions);
extern void emxInit_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray, int
  numDimensions);
extern void emxInit_cell_wrap_13(emxArray_cell_wrap_13 **pEmxArray, int
  numDimensions);
extern void emxInit_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray, int
  numDimensions);
extern void emxInit_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray, int
  numDimensions);
extern void emxInit_cell_wrap_5(emxArray_cell_wrap_5 **pEmxArray, int
  numDimensions);
extern void emxInit_cell_wrap_6(emxArray_cell_wrap_6 **pEmxArray, int
  numDimensions);
extern void emxInit_cell_wrap_8(emxArray_cell_wrap_8 **pEmxArray, int
  numDimensions);
extern void emxInit_cell_wrap_9(emxArray_cell_wrap_9 **pEmxArray, int
  numDimensions);
extern void emxInit_char_T(emxArray_char_T **pEmxArray, int numDimensions);
extern void emxInit_int16_T(emxArray_int16_T **pEmxArray, int numDimensions);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_int8_T(emxArray_int8_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_uint32_T(emxArray_uint32_T **pEmxArray, int numDimensions);

#endif

/* End of code generation (reflectivity_calculation_emxutil.h) */
