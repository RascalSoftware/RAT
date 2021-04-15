/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanlay_single_emxAPI.c
 *
 * Code generation for function 'standardTF_stanlay_single_emxAPI'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_stanlay_single.h"
#include "standardTF_stanlay_single_emxAPI.h"
#include "standardTF_stanlay_single_emxutil.h"

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

emxArray_cell_wrap_4 *emxCreateND_cell_wrap_4(int numDimensions, int *size)
{
  emxArray_cell_wrap_4 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_4(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_4 *)calloc((unsigned int)numEl, sizeof(cell_wrap_4));
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
  emxInit_real_T1(&emx, numDimensions);
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

emxArray_cell_wrap_4 *emxCreateWrapperND_cell_wrap_4(cell_wrap_4 *data, int
  numDimensions, int *size)
{
  emxArray_cell_wrap_4 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_4(&emx, numDimensions);
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
  emxInit_real_T1(&emx, numDimensions);
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
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_cell_wrap_0(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

emxArray_cell_wrap_1 *emxCreateWrapper_cell_wrap_1(cell_wrap_1 *data, int rows,
  int cols)
{
  emxArray_cell_wrap_1 *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_cell_wrap_1(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

emxArray_cell_wrap_2 *emxCreateWrapper_cell_wrap_2(cell_wrap_2 *data, int rows,
  int cols)
{
  emxArray_cell_wrap_2 *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_cell_wrap_2(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

emxArray_cell_wrap_3 *emxCreateWrapper_cell_wrap_3(cell_wrap_3 *data, int rows,
  int cols)
{
  emxArray_cell_wrap_3 *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_cell_wrap_3(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

emxArray_cell_wrap_4 *emxCreateWrapper_cell_wrap_4(cell_wrap_4 *data, int rows,
  int cols)
{
  emxArray_cell_wrap_4 *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_cell_wrap_4(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

emxArray_cell_wrap_5 *emxCreateWrapper_cell_wrap_5(cell_wrap_5 *data, int rows,
  int cols)
{
  emxArray_cell_wrap_5 *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_cell_wrap_5(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols)
{
  emxArray_char_T *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_char_T(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols)
{
  emxArray_real_T *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_real_T1(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

emxArray_cell_wrap_0 *emxCreate_cell_wrap_0(int rows, int cols)
{
  emxArray_cell_wrap_0 *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_cell_wrap_0(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_0 *)calloc((unsigned int)numEl, sizeof(cell_wrap_0));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_1 *emxCreate_cell_wrap_1(int rows, int cols)
{
  emxArray_cell_wrap_1 *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_cell_wrap_1(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_1 *)calloc((unsigned int)numEl, sizeof(cell_wrap_1));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_2 *emxCreate_cell_wrap_2(int rows, int cols)
{
  emxArray_cell_wrap_2 *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_cell_wrap_2(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_2 *)calloc((unsigned int)numEl, sizeof(cell_wrap_2));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_3 *emxCreate_cell_wrap_3(int rows, int cols)
{
  emxArray_cell_wrap_3 *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_cell_wrap_3(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_3 *)calloc((unsigned int)numEl, sizeof(cell_wrap_3));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_4 *emxCreate_cell_wrap_4(int rows, int cols)
{
  emxArray_cell_wrap_4 *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_cell_wrap_4(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_4 *)calloc((unsigned int)numEl, sizeof(cell_wrap_4));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_cell_wrap_5 *emxCreate_cell_wrap_5(int rows, int cols)
{
  emxArray_cell_wrap_5 *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_cell_wrap_5(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_5 *)calloc((unsigned int)numEl, sizeof(cell_wrap_5));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_char_T *emxCreate_char_T(int rows, int cols)
{
  emxArray_char_T *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_char_T(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (char *)calloc((unsigned int)numEl, sizeof(char));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_real_T *emxCreate_real_T(int rows, int cols)
{
  emxArray_real_T *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_real_T1(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

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

void emxDestroyArray_cell_wrap_4(emxArray_cell_wrap_4 *emxArray)
{
  emxFree_cell_wrap_4(&emxArray);
}

void emxDestroyArray_cell_wrap_5(emxArray_cell_wrap_5 *emxArray)
{
  emxFree_cell_wrap_5(&emxArray);
}

void emxDestroyArray_char_T(emxArray_char_T *emxArray)
{
  emxFree_char_T(&emxArray);
}

void emxDestroyArray_real_T(emxArray_real_T *emxArray)
{
  emxFree_real_T(&emxArray);
}

void emxInitArray_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray, int
  numDimensions)
{
  emxInit_cell_wrap_0(pEmxArray, numDimensions);
}

void emxInitArray_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray, int
  numDimensions)
{
  emxInit_cell_wrap_1(pEmxArray, numDimensions);
}

void emxInitArray_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray, int
  numDimensions)
{
  emxInit_cell_wrap_2(pEmxArray, numDimensions);
}

void emxInitArray_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray, int
  numDimensions)
{
  emxInit_cell_wrap_3(pEmxArray, numDimensions);
}

void emxInitArray_cell_wrap_4(emxArray_cell_wrap_4 **pEmxArray, int
  numDimensions)
{
  emxInit_cell_wrap_4(pEmxArray, numDimensions);
}

void emxInitArray_cell_wrap_5(emxArray_cell_wrap_5 **pEmxArray, int
  numDimensions)
{
  emxInit_cell_wrap_5(pEmxArray, numDimensions);
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxInit_real_T1(pEmxArray, numDimensions);
}

/* End of code generation (standardTF_stanlay_single_emxAPI.c) */
