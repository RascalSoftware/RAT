/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation_emxAPI.c
 *
 * Code generation for function 'reflectivity_calculation_emxAPI'
 *
 */

/* Include files */
#include <stdlib.h>
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_emxAPI.h"
#include "reflectivity_calculation_emxutil.h"
#include <string.h>

/* Function Definitions */
emxArray_cell_wrap_11 *emxCreateND_cell_wrap_11(int numDimensions, int *size)
{
  emxArray_cell_wrap_11 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_11(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_11 *)calloc((unsigned int)numEl, sizeof(cell_wrap_11));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_12 *emxCreateND_cell_wrap_12(int numDimensions, int *size)
{
  emxArray_cell_wrap_12 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_12(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_12 *)calloc((unsigned int)numEl, sizeof(cell_wrap_12));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size)
{
  emxArray_real_T *emx;
  int numEl;
  int i;
  emxInit_real_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (double *)calloc((unsigned int)numEl, sizeof(double));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_11 *emxCreateWrapperND_cell_wrap_11(cell_wrap_11 *data, int
  numDimensions, int *size)
{
  emxArray_cell_wrap_11 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_11(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

emxArray_cell_wrap_12 *emxCreateWrapperND_cell_wrap_12(cell_wrap_12 *data, int
  numDimensions, int *size)
{
  emxArray_cell_wrap_12 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_12(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

emxArray_real_T *emxCreateWrapperND_real_T(double *data, int numDimensions, int *
  size)
{
  emxArray_real_T *emx;
  int numEl;
  int i;
  emxInit_real_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

emxArray_cell_wrap_11 *emxCreateWrapper_cell_wrap_11(cell_wrap_11 *data, int
  rows, int cols)
{
  emxArray_cell_wrap_11 *emx;
  emxInit_cell_wrap_11(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

emxArray_cell_wrap_12 *emxCreateWrapper_cell_wrap_12(cell_wrap_12 *data, int
  rows, int cols)
{
  emxArray_cell_wrap_12 *emx;
  emxInit_cell_wrap_12(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols)
{
  emxArray_real_T *emx;
  emxInit_real_T(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

emxArray_cell_wrap_11 *emxCreate_cell_wrap_11(int rows, int cols)
{
  emxArray_cell_wrap_11 *emx;
  int numEl;
  emxInit_cell_wrap_11(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (cell_wrap_11 *)calloc((unsigned int)numEl, sizeof(cell_wrap_11));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_12 *emxCreate_cell_wrap_12(int rows, int cols)
{
  emxArray_cell_wrap_12 *emx;
  int numEl;
  emxInit_cell_wrap_12(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (cell_wrap_12 *)calloc((unsigned int)numEl, sizeof(cell_wrap_12));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_real_T *emxCreate_real_T(int rows, int cols)
{
  emxArray_real_T *emx;
  int numEl;
  emxInit_real_T(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (double *)calloc((unsigned int)numEl, sizeof(double));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

void emxDestroyArray_cell_wrap_11(emxArray_cell_wrap_11 *emxArray)
{
  emxFree_cell_wrap_11(&emxArray);
}

void emxDestroyArray_cell_wrap_12(emxArray_cell_wrap_12 *emxArray)
{
  emxFree_cell_wrap_12(&emxArray);
}

void emxDestroyArray_real_T(emxArray_real_T *emxArray)
{
  emxFree_real_T(&emxArray);
}

void emxDestroy_cell_13(cell_13 emxArray)
{
  emxFreeStruct_cell_13(&emxArray);
}

void emxDestroy_struct4_T(struct4_T emxArray)
{
  emxFreeStruct_struct4_T(&emxArray);
}

void emxInit_cell_13(cell_13 *pStruct)
{
  emxInitStruct_cell_13(pStruct);
}

void emxInit_struct4_T(struct4_T *pStruct)
{
  emxInitStruct_struct4_T(pStruct);
}

/* End of code generation (reflectivity_calculation_emxAPI.c) */
