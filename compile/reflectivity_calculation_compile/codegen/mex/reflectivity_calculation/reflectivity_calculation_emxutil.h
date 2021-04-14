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

#pragma once

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "reflectivity_calculation_types.h"

/* Function Declarations */
void emxCopyStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *dst, const
  cell_wrap_1 *src, const emlrtRTEInfo *srcLocation);
void emxCopyStruct_cell_wrap_12(const emlrtStack *sp, cell_wrap_12 *dst, const
  cell_wrap_12 *src, const emlrtRTEInfo *srcLocation);
void emxCopyStruct_cell_wrap_4(const emlrtStack *sp, cell_wrap_4 *dst, const
  cell_wrap_4 *src, const emlrtRTEInfo *srcLocation);
void emxCopyStruct_cell_wrap_5(const emlrtStack *sp, cell_wrap_5 *dst, const
  cell_wrap_5 *src, const emlrtRTEInfo *srcLocation);
void emxCopyStruct_cell_wrap_7(const emlrtStack *sp, cell_wrap_7 *dst, const
  cell_wrap_7 *src, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_boolean_T(const emlrtStack *sp, emxArray_boolean_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_cell_wrap_0(const emlrtStack *sp, emxArray_cell_wrap_0
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_cell_wrap_10(const emlrtStack *sp, emxArray_cell_wrap_10 *
  emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_cell_wrap_11(const emlrtStack *sp, emxArray_cell_wrap_11 *
  emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_cell_wrap_12(const emlrtStack *sp, emxArray_cell_wrap_12 *
  emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_cell_wrap_16(const emlrtStack *sp, emxArray_cell_wrap_16 *
  emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_cell_wrap_17(const emlrtStack *sp, emxArray_cell_wrap_17 *
  emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_cell_wrap_18(const emlrtStack *sp, emxArray_cell_wrap_18 *
  emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_cell_wrap_2(const emlrtStack *sp, emxArray_cell_wrap_2
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_cell_wrap_4(const emlrtStack *sp, emxArray_cell_wrap_4
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_cell_wrap_5(const emlrtStack *sp, emxArray_cell_wrap_5
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_cell_wrap_7(const emlrtStack *sp, emxArray_cell_wrap_7
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_cell_wrap_9(const emlrtStack *sp, emxArray_cell_wrap_9
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_char_T(const emlrtStack *sp, emxArray_char_T *emxArray,
  int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_creal_T(const emlrtStack *sp, emxArray_creal_T *emxArray,
  int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T *emxArray,
  int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_int8_T(const emlrtStack *sp, emxArray_int8_T *emxArray,
  int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
  int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_uint32_T(const emlrtStack *sp, emxArray_uint32_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxFreeStruct_cell_15(cell_15 *pStruct);
void emxFreeStruct_cell_20(cell_20 *pStruct);
void emxFreeStruct_cell_6(cell_6 *pStruct);
void emxFreeStruct_cell_8(cell_8 *pStruct);
void emxFreeStruct_struct0_T(struct0_T *pStruct);
void emxFreeStruct_struct1_T(struct1_T *pStruct);
void emxFreeStruct_struct2_T(struct2_T *pStruct);
void emxFreeStruct_struct4_T(struct4_T *pStruct);
void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray);
void emxFree_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray);
void emxFree_cell_wrap_10(emxArray_cell_wrap_10 **pEmxArray);
void emxFree_cell_wrap_11(emxArray_cell_wrap_11 **pEmxArray);
void emxFree_cell_wrap_12(emxArray_cell_wrap_12 **pEmxArray);
void emxFree_cell_wrap_16(emxArray_cell_wrap_16 **pEmxArray);
void emxFree_cell_wrap_17(emxArray_cell_wrap_17 **pEmxArray);
void emxFree_cell_wrap_18(emxArray_cell_wrap_18 **pEmxArray);
void emxFree_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray);
void emxFree_cell_wrap_4(emxArray_cell_wrap_4 **pEmxArray);
void emxFree_cell_wrap_5(emxArray_cell_wrap_5 **pEmxArray);
void emxFree_cell_wrap_7(emxArray_cell_wrap_7 **pEmxArray);
void emxFree_cell_wrap_9(emxArray_cell_wrap_9 **pEmxArray);
void emxFree_char_T(emxArray_char_T **pEmxArray);
void emxFree_creal_T(emxArray_creal_T **pEmxArray);
void emxFree_int32_T(emxArray_int32_T **pEmxArray);
void emxFree_int8_T(emxArray_int8_T **pEmxArray);
void emxFree_real_T(emxArray_real_T **pEmxArray);
void emxFree_uint32_T(emxArray_uint32_T **pEmxArray);
void emxInitStruct_cell_15(const emlrtStack *sp, cell_15 *pStruct, const
  emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInitStruct_cell_20(const emlrtStack *sp, cell_20 *pStruct, const
  emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInitStruct_cell_6(const emlrtStack *sp, cell_6 *pStruct, const
  emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInitStruct_cell_8(const emlrtStack *sp, cell_8 *pStruct, const
  emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct, const
  emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct, const
  emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInitStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct, const
  emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInitStruct_struct4_T(const emlrtStack *sp, struct4_T *pStruct, const
  emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInit_cell_wrap_0(const emlrtStack *sp, emxArray_cell_wrap_0 **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInit_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInit_cell_wrap_10(const emlrtStack *sp, emxArray_cell_wrap_10
  **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
void emxInit_cell_wrap_11(const emlrtStack *sp, emxArray_cell_wrap_11
  **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
void emxInit_cell_wrap_12(const emlrtStack *sp, emxArray_cell_wrap_12
  **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
void emxInit_cell_wrap_16(const emlrtStack *sp, emxArray_cell_wrap_16
  **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
void emxInit_cell_wrap_17(const emlrtStack *sp, emxArray_cell_wrap_17
  **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
void emxInit_cell_wrap_18(const emlrtStack *sp, emxArray_cell_wrap_18
  **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
void emxInit_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3 **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInit_cell_wrap_4(const emlrtStack *sp, emxArray_cell_wrap_4 **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInit_cell_wrap_5(const emlrtStack *sp, emxArray_cell_wrap_5 **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInit_cell_wrap_7(const emlrtStack *sp, emxArray_cell_wrap_7 **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInit_cell_wrap_9(const emlrtStack *sp, emxArray_cell_wrap_9 **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray, int32_T
                    numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                    doPush);
void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray, int32_T
                     numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                     doPush);
void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray, int32_T
                     numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                     doPush);
void emxInit_int8_T(const emlrtStack *sp, emxArray_int8_T **pEmxArray, int32_T
                    numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                    doPush);
void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray, int32_T
                    numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                    doPush);
void emxInit_uint32_T(const emlrtStack *sp, emxArray_uint32_T **pEmxArray,
                      int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                      boolean_T doPush);

/* End of code generation (reflectivity_calculation_emxutil.h) */
