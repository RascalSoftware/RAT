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

/* Function Definitions */
emxArray_cell_wrap_0 *emxCreateND_cell_wrap_0(int numDimensions, int *size)
{
  emxArray_cell_wrap_0 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_0(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_0 *)calloc((unsigned int)numEl, sizeof(cell_wrap_0));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_1 *emxCreateND_cell_wrap_1(int numDimensions, int *size)
{
  emxArray_cell_wrap_1 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_1(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_1 *)calloc((unsigned int)numEl, sizeof(cell_wrap_1));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_2 *emxCreateND_cell_wrap_2(int numDimensions, int *size)
{
  emxArray_cell_wrap_2 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_2(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_2 *)calloc((unsigned int)numEl, sizeof(cell_wrap_2));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_3 *emxCreateND_cell_wrap_3(int numDimensions, int *size)
{
  emxArray_cell_wrap_3 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_3(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_3 *)calloc((unsigned int)numEl, sizeof(cell_wrap_3));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_5 *emxCreateND_cell_wrap_5(int numDimensions, int *size)
{
  emxArray_cell_wrap_5 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_5(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_5 *)calloc((unsigned int)numEl, sizeof(cell_wrap_5));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_6 *emxCreateND_cell_wrap_6(int numDimensions, int *size)
{
  emxArray_cell_wrap_6 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_6(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_6 *)calloc((unsigned int)numEl, sizeof(cell_wrap_6));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_char_T *emxCreateND_char_T(int numDimensions, int *size)
{
  emxArray_char_T *emx;
  int numEl;
  int i;
  emxInit_char_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (char *)calloc((unsigned int)numEl, sizeof(char));
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

emxArray_cell_wrap_0 *emxCreateWrapperND_cell_wrap_0(cell_wrap_0 *data, int
  numDimensions, int *size)
{
  emxArray_cell_wrap_0 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_0(&emx, numDimensions);
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

emxArray_cell_wrap_1 *emxCreateWrapperND_cell_wrap_1(cell_wrap_1 *data, int
  numDimensions, int *size)
{
  emxArray_cell_wrap_1 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_1(&emx, numDimensions);
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

emxArray_cell_wrap_2 *emxCreateWrapperND_cell_wrap_2(cell_wrap_2 *data, int
  numDimensions, int *size)
{
  emxArray_cell_wrap_2 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_2(&emx, numDimensions);
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

emxArray_cell_wrap_3 *emxCreateWrapperND_cell_wrap_3(cell_wrap_3 *data, int
  numDimensions, int *size)
{
  emxArray_cell_wrap_3 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_3(&emx, numDimensions);
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

emxArray_cell_wrap_5 *emxCreateWrapperND_cell_wrap_5(cell_wrap_5 *data, int
  numDimensions, int *size)
{
  emxArray_cell_wrap_5 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_5(&emx, numDimensions);
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

emxArray_cell_wrap_6 *emxCreateWrapperND_cell_wrap_6(cell_wrap_6 *data, int
  numDimensions, int *size)
{
  emxArray_cell_wrap_6 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_6(&emx, numDimensions);
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

emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions, int
  *size)
{
  emxArray_char_T *emx;
  int numEl;
  int i;
  emxInit_char_T(&emx, numDimensions);
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

emxArray_cell_wrap_0 *emxCreateWrapper_cell_wrap_0(cell_wrap_0 *data, int rows,
  int cols)
{
  emxArray_cell_wrap_0 *emx;
  emxInit_cell_wrap_0(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

emxArray_cell_wrap_1 *emxCreateWrapper_cell_wrap_1(cell_wrap_1 *data, int rows,
  int cols)
{
  emxArray_cell_wrap_1 *emx;
  emxInit_cell_wrap_1(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

emxArray_cell_wrap_2 *emxCreateWrapper_cell_wrap_2(cell_wrap_2 *data, int rows,
  int cols)
{
  emxArray_cell_wrap_2 *emx;
  emxInit_cell_wrap_2(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

emxArray_cell_wrap_3 *emxCreateWrapper_cell_wrap_3(cell_wrap_3 *data, int rows,
  int cols)
{
  emxArray_cell_wrap_3 *emx;
  emxInit_cell_wrap_3(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

emxArray_cell_wrap_5 *emxCreateWrapper_cell_wrap_5(cell_wrap_5 *data, int rows,
  int cols)
{
  emxArray_cell_wrap_5 *emx;
  emxInit_cell_wrap_5(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

emxArray_cell_wrap_6 *emxCreateWrapper_cell_wrap_6(cell_wrap_6 *data, int rows,
  int cols)
{
  emxArray_cell_wrap_6 *emx;
  emxInit_cell_wrap_6(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols)
{
  emxArray_char_T *emx;
  emxInit_char_T(&emx, 2);
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

emxArray_cell_wrap_0 *emxCreate_cell_wrap_0(int rows, int cols)
{
  emxArray_cell_wrap_0 *emx;
  int numEl;
  emxInit_cell_wrap_0(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (cell_wrap_0 *)calloc((unsigned int)numEl, sizeof(cell_wrap_0));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_1 *emxCreate_cell_wrap_1(int rows, int cols)
{
  emxArray_cell_wrap_1 *emx;
  int numEl;
  emxInit_cell_wrap_1(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (cell_wrap_1 *)calloc((unsigned int)numEl, sizeof(cell_wrap_1));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_2 *emxCreate_cell_wrap_2(int rows, int cols)
{
  emxArray_cell_wrap_2 *emx;
  int numEl;
  emxInit_cell_wrap_2(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (cell_wrap_2 *)calloc((unsigned int)numEl, sizeof(cell_wrap_2));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_3 *emxCreate_cell_wrap_3(int rows, int cols)
{
  emxArray_cell_wrap_3 *emx;
  int numEl;
  emxInit_cell_wrap_3(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (cell_wrap_3 *)calloc((unsigned int)numEl, sizeof(cell_wrap_3));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_5 *emxCreate_cell_wrap_5(int rows, int cols)
{
  emxArray_cell_wrap_5 *emx;
  int numEl;
  emxInit_cell_wrap_5(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (cell_wrap_5 *)calloc((unsigned int)numEl, sizeof(cell_wrap_5));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_6 *emxCreate_cell_wrap_6(int rows, int cols)
{
  emxArray_cell_wrap_6 *emx;
  int numEl;
  emxInit_cell_wrap_6(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (cell_wrap_6 *)calloc((unsigned int)numEl, sizeof(cell_wrap_6));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_char_T *emxCreate_char_T(int rows, int cols)
{
  emxArray_char_T *emx;
  int numEl;
  emxInit_char_T(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (char *)calloc((unsigned int)numEl, sizeof(char));
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

void emxDestroyArray_cell_wrap_0(emxArray_cell_wrap_0 *emxArray)
{
  emxFree_cell_wrap_0(&emxArray);
}

void emxDestroyArray_cell_wrap_1(emxArray_cell_wrap_1 *emxArray)
{
  emxFree_cell_wrap_1(&emxArray);
}

void emxDestroyArray_cell_wrap_2(emxArray_cell_wrap_2 *emxArray)
{
  emxFree_cell_wrap_2(&emxArray);
}

void emxDestroyArray_cell_wrap_3(emxArray_cell_wrap_3 *emxArray)
{
  emxFree_cell_wrap_3(&emxArray);
}

void emxDestroyArray_cell_wrap_5(emxArray_cell_wrap_5 *emxArray)
{
  emxFree_cell_wrap_5(&emxArray);
}

void emxDestroyArray_cell_wrap_6(emxArray_cell_wrap_6 *emxArray)
{
  emxFree_cell_wrap_6(&emxArray);
}

void emxDestroyArray_char_T(emxArray_char_T *emxArray)
{
  emxFree_char_T(&emxArray);
}

void emxDestroyArray_real_T(emxArray_real_T *emxArray)
{
  emxFree_real_T(&emxArray);
}

void emxDestroy_cell_4(cell_4 emxArray)
{
  emxFreeStruct_cell_4(&emxArray);
}

void emxDestroy_cell_7(cell_7 emxArray)
{
  emxFreeStruct_cell_7(&emxArray);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxDestroy_struct1_T(struct1_T emxArray)
{
  emxFreeStruct_struct1_T(&emxArray);
}

void emxDestroy_struct2_T(struct2_T emxArray)
{
  emxFreeStruct_struct2_T(&emxArray);
}

void emxDestroy_struct4_T(struct4_T emxArray)
{
  emxFreeStruct_struct4_T(&emxArray);
}

void emxInit_cell_4(cell_4 *pStruct)
{
  emxInitStruct_cell_4(pStruct);
}

void emxInit_cell_7(cell_7 *pStruct)
{
  emxInitStruct_cell_7(pStruct);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void emxInit_struct1_T(struct1_T *pStruct)
{
  emxInitStruct_struct1_T(pStruct);
}

void emxInit_struct2_T(struct2_T *pStruct)
{
  emxInitStruct_struct2_T(pStruct);
}

void emxInit_struct4_T(struct4_T *pStruct)
{
  emxInitStruct_struct4_T(pStruct);
}

/* End of code generation (reflectivity_calculation_emxAPI.c) */
