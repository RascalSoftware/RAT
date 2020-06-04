/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custlay_single_emxutil.h
 *
 * Code generation for function 'standardTF_custlay_single_emxutil'
 *
 */

#ifndef STANDARDTF_CUSTLAY_SINGLE_EMXUTIL_H
#define STANDARDTF_CUSTLAY_SINGLE_EMXUTIL_H

/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
#include "standardTF_custlay_single_types.h"

/* Function Declarations */
extern void emxEnsureCapacity(emxArray__common *emxArray, int oldNumel, int
  elementSize);
extern void emxEnsureCapacity_cell_wrap_3(emxArray_cell_wrap_3 *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_cell_wrap_4(emxArray_cell_wrap_4 *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_cell_wrap_5(emxArray_cell_wrap_5 *emxArray, int
  oldNumel);
extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
extern void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray);
extern void emxFree_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray);
extern void emxFree_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray);
extern void emxFree_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray);
extern void emxFree_cell_wrap_4(emxArray_cell_wrap_4 **pEmxArray);
extern void emxFree_cell_wrap_5(emxArray_cell_wrap_5 **pEmxArray);
extern void emxFree_char_T(emxArray_char_T **pEmxArray);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int numDimensions);
extern void emxInit_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray, int
  numDimensions);
extern void emxInit_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray, int
  numDimensions);
extern void emxInit_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray, int
  numDimensions);
extern void emxInit_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray, int
  numDimensions);
extern void emxInit_cell_wrap_4(emxArray_cell_wrap_4 **pEmxArray, int
  numDimensions);
extern void emxInit_cell_wrap_5(emxArray_cell_wrap_5 **pEmxArray, int
  numDimensions);
extern void emxInit_char_T(emxArray_char_T **pEmxArray, int numDimensions);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_real_T1(emxArray_real_T **pEmxArray, int numDimensions);

#endif

/* End of code generation (standardTF_custlay_single_emxutil.h) */
