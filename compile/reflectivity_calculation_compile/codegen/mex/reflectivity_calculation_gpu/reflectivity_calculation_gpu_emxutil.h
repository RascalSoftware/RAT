//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  reflectivity_calculation_gpu_emxutil.h
//
//  Code generation for function 'reflectivity_calculation_gpu_emxutil'
//


#pragma once

// Include files
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "reflectivity_calculation_gpu_types.h"

// Custom Header Code
#ifdef __CUDA_ARCH__
#undef printf
#endif

// Function Declarations
CODEGEN_EXPORT_SYM void emxCopyStruct_cell_wrap_11(cell_wrap_11 *dst, const
  cell_wrap_11 *src);
CODEGEN_EXPORT_SYM void emxCopyStruct_cell_wrap_12(cell_wrap_12 *dst, const
  cell_wrap_12 *src);
CODEGEN_EXPORT_SYM void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray,
  int32_T oldNumel);
CODEGEN_EXPORT_SYM void emxEnsureCapacity_cell_wrap_11(emxArray_cell_wrap_11
  *emxArray, int32_T oldNumel);
CODEGEN_EXPORT_SYM void emxEnsureCapacity_cell_wrap_12(emxArray_cell_wrap_12
  *emxArray, int32_T oldNumel);
CODEGEN_EXPORT_SYM void emxEnsureCapacity_cell_wrap_14(emxArray_cell_wrap_14
  *emxArray, int32_T oldNumel);
CODEGEN_EXPORT_SYM void emxEnsureCapacity_cell_wrap_15(emxArray_cell_wrap_15
  *emxArray, int32_T oldNumel);
CODEGEN_EXPORT_SYM void emxEnsureCapacity_cell_wrap_17(emxArray_cell_wrap_17
  *emxArray, int32_T oldNumel);
CODEGEN_EXPORT_SYM void emxEnsureCapacity_creal_T(emxArray_creal_T *emxArray,
  int32_T oldNumel);
CODEGEN_EXPORT_SYM void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray,
  int32_T oldNumel);
CODEGEN_EXPORT_SYM void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray,
  int32_T oldNumel);
CODEGEN_EXPORT_SYM void emxEnsureCapacity_real_T(emxArray_real_T *emxArray,
  int32_T oldNumel);
CODEGEN_EXPORT_SYM void emxFreeStruct_cell_13(cell_13 *pStruct);
CODEGEN_EXPORT_SYM void emxFreeStruct_struct4_T(struct4_T *pStruct);
CODEGEN_EXPORT_SYM void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
CODEGEN_EXPORT_SYM void emxFree_cell_wrap_11(emxArray_cell_wrap_11 **pEmxArray);
CODEGEN_EXPORT_SYM void emxFree_cell_wrap_12(emxArray_cell_wrap_12 **pEmxArray);
CODEGEN_EXPORT_SYM void emxFree_cell_wrap_14(emxArray_cell_wrap_14 **pEmxArray);
CODEGEN_EXPORT_SYM void emxFree_cell_wrap_15(emxArray_cell_wrap_15 **pEmxArray);
CODEGEN_EXPORT_SYM void emxFree_cell_wrap_17(emxArray_cell_wrap_17 **pEmxArray);
CODEGEN_EXPORT_SYM void emxFree_creal_T(emxArray_creal_T **pEmxArray);
CODEGEN_EXPORT_SYM void emxFree_int32_T(emxArray_int32_T **pEmxArray);
CODEGEN_EXPORT_SYM void emxFree_int8_T(emxArray_int8_T **pEmxArray);
CODEGEN_EXPORT_SYM void emxFree_real_T(emxArray_real_T **pEmxArray);
CODEGEN_EXPORT_SYM void emxInitStruct_cell_13(cell_13 *pStruct, boolean_T doPush);
CODEGEN_EXPORT_SYM void emxInitStruct_struct4_T(struct4_T *pStruct, boolean_T
  doPush);
CODEGEN_EXPORT_SYM void emxInit_boolean_T(emxArray_boolean_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
CODEGEN_EXPORT_SYM void emxInit_cell_wrap_11(emxArray_cell_wrap_11 **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
CODEGEN_EXPORT_SYM void emxInit_cell_wrap_12(emxArray_cell_wrap_12 **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
CODEGEN_EXPORT_SYM void emxInit_cell_wrap_14(emxArray_cell_wrap_14 **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
CODEGEN_EXPORT_SYM void emxInit_cell_wrap_15(emxArray_cell_wrap_15 **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
CODEGEN_EXPORT_SYM void emxInit_cell_wrap_17(emxArray_cell_wrap_17 **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
CODEGEN_EXPORT_SYM void emxInit_creal_T(emxArray_creal_T **pEmxArray, int32_T
  numDimensions, boolean_T doPush);
CODEGEN_EXPORT_SYM void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T
  numDimensions, boolean_T doPush);
CODEGEN_EXPORT_SYM void emxInit_int8_T(emxArray_int8_T **pEmxArray, int32_T
  numDimensions, boolean_T doPush);
CODEGEN_EXPORT_SYM void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T
  numDimensions, boolean_T doPush);

// End of code generation (reflectivity_calculation_gpu_emxutil.h)
