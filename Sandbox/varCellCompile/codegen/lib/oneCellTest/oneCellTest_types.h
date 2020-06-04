/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * oneCellTest_types.h
 *
 * Code generation for function 'oneCellTest'
 *
 */

#ifndef ONECELLTEST_TYPES_H
#define ONECELLTEST_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T_10x3
#define struct_emxArray_real_T_10x3

struct emxArray_real_T_10x3
{
  double data[30];
  int size[2];
};

#endif                                 /*struct_emxArray_real_T_10x3*/

#ifndef typedef_emxArray_real_T_10x3
#define typedef_emxArray_real_T_10x3

typedef struct emxArray_real_T_10x3 emxArray_real_T_10x3;

#endif                                 /*typedef_emxArray_real_T_10x3*/

#ifndef struct_sug7NIB4YxuPRsLoDxIYVxG
#define struct_sug7NIB4YxuPRsLoDxIYVxG

struct sug7NIB4YxuPRsLoDxIYVxG
{
  emxArray_real_T_10x3 f1;
};

#endif                                 /*struct_sug7NIB4YxuPRsLoDxIYVxG*/

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0

typedef struct sug7NIB4YxuPRsLoDxIYVxG cell_wrap_0;

#endif                                 /*typedef_cell_wrap_0*/

#ifndef struct_emxArray_cell_wrap_0
#define struct_emxArray_cell_wrap_0

struct emxArray_cell_wrap_0
{
  cell_wrap_0 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_cell_wrap_0*/

#ifndef typedef_emxArray_cell_wrap_0
#define typedef_emxArray_cell_wrap_0

typedef struct emxArray_cell_wrap_0 emxArray_cell_wrap_0;

#endif                                 /*typedef_emxArray_cell_wrap_0*/
#endif

/* End of code generation (oneCellTest_types.h) */
