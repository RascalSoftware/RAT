/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation_emxutil.c
 *
 * Code generation for function 'reflectivity_calculation_emxutil'
 *
 */

/* Include files */
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_emxutil.h"

/* Function Declarations */
static void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T * const *src);
static void emxExpand_cell_wrap_1(emxArray_cell_wrap_1 *emxArray, int fromIndex,
  int toIndex);
static void emxExpand_cell_wrap_5(emxArray_cell_wrap_5 *emxArray, int fromIndex,
  int toIndex);
static void emxExpand_cell_wrap_6(emxArray_cell_wrap_6 *emxArray, int fromIndex,
  int toIndex);
static void emxExpand_cell_wrap_8(emxArray_cell_wrap_8 *emxArray, int fromIndex,
  int toIndex);
static void emxExpand_cell_wrap_9(emxArray_cell_wrap_9 *emxArray, int fromIndex,
  int toIndex);
static void emxFreeStruct_cell_wrap_1(cell_wrap_1 *pStruct);
static void emxFreeStruct_cell_wrap_3(cell_wrap_3 *pStruct);
static void emxFreeStruct_cell_wrap_5(cell_wrap_5 *pStruct);
static void emxFreeStruct_cell_wrap_6(cell_wrap_6 *pStruct);
static void emxFreeStruct_cell_wrap_8(cell_wrap_8 *pStruct);
static void emxFreeStruct_cell_wrap_9(cell_wrap_9 *pStruct);
static void emxFreeStruct_struct3_T(struct3_T *pStruct);
static void emxFreeStruct_struct5_T(struct5_T *pStruct);
static void emxInitStruct_cell_wrap_1(cell_wrap_1 *pStruct);
static void emxInitStruct_cell_wrap_5(cell_wrap_5 *pStruct);
static void emxInitStruct_cell_wrap_6(cell_wrap_6 *pStruct);
static void emxInitStruct_cell_wrap_8(cell_wrap_8 *pStruct);
static void emxInitStruct_cell_wrap_9(cell_wrap_9 *pStruct);
static void emxInitStruct_struct3_T(struct3_T *pStruct);
static void emxInitStruct_struct5_T(struct5_T *pStruct);
static void emxTrim_cell_wrap_1(emxArray_cell_wrap_1 *emxArray, int fromIndex,
  int toIndex);
static void emxTrim_cell_wrap_5(emxArray_cell_wrap_5 *emxArray, int fromIndex,
  int toIndex);
static void emxTrim_cell_wrap_6(emxArray_cell_wrap_6 *emxArray, int fromIndex,
  int toIndex);
static void emxTrim_cell_wrap_8(emxArray_cell_wrap_8 *emxArray, int fromIndex,
  int toIndex);
static void emxTrim_cell_wrap_9(emxArray_cell_wrap_9 *emxArray, int fromIndex,
  int toIndex);

/* Function Definitions */
static void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T * const *src)
{
  int numElDst;
  int numElSrc;
  int i;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }

  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }

  emxEnsureCapacity_real_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

static void emxExpand_cell_wrap_1(emxArray_cell_wrap_1 *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_1(&emxArray->data[i]);
  }
}

static void emxExpand_cell_wrap_5(emxArray_cell_wrap_5 *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_5(&emxArray->data[i]);
  }
}

static void emxExpand_cell_wrap_6(emxArray_cell_wrap_6 *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_6(&emxArray->data[i]);
  }
}

static void emxExpand_cell_wrap_8(emxArray_cell_wrap_8 *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_8(&emxArray->data[i]);
  }
}

static void emxExpand_cell_wrap_9(emxArray_cell_wrap_9 *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_9(&emxArray->data[i]);
  }
}

static void emxFreeStruct_cell_wrap_1(cell_wrap_1 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

static void emxFreeStruct_cell_wrap_3(cell_wrap_3 *pStruct)
{
  emxFree_char_T(&pStruct->f1);
}

static void emxFreeStruct_cell_wrap_5(cell_wrap_5 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

static void emxFreeStruct_cell_wrap_6(cell_wrap_6 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

static void emxFreeStruct_cell_wrap_8(cell_wrap_8 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

static void emxFreeStruct_cell_wrap_9(cell_wrap_9 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

static void emxFreeStruct_struct3_T(struct3_T *pStruct)
{
  emxFree_real_T(&pStruct->params_fitYesNo);
  emxFree_real_T(&pStruct->backs_fitYesNo);
  emxFree_real_T(&pStruct->shifts_fitYesNo);
  emxFree_real_T(&pStruct->scales_fitYesNo);
  emxFree_real_T(&pStruct->nbairs_fitYesNo);
  emxFree_real_T(&pStruct->nbsubs_fitYesNo);
  emxFree_real_T(&pStruct->resol_fitYesNo);
}

static void emxFreeStruct_struct5_T(struct5_T *pStruct)
{
  emxFree_real_T(&pStruct->all_chis);
}

static void emxInitStruct_cell_wrap_1(cell_wrap_1 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 2);
}

static void emxInitStruct_cell_wrap_5(cell_wrap_5 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 2);
}

static void emxInitStruct_cell_wrap_6(cell_wrap_6 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 2);
}

static void emxInitStruct_cell_wrap_8(cell_wrap_8 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 1);
}

static void emxInitStruct_cell_wrap_9(cell_wrap_9 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 2);
}

static void emxInitStruct_struct3_T(struct3_T *pStruct)
{
  emxInit_real_T(&pStruct->params_fitYesNo, 2);
  emxInit_real_T(&pStruct->backs_fitYesNo, 2);
  emxInit_real_T(&pStruct->shifts_fitYesNo, 2);
  emxInit_real_T(&pStruct->scales_fitYesNo, 2);
  emxInit_real_T(&pStruct->nbairs_fitYesNo, 2);
  emxInit_real_T(&pStruct->nbsubs_fitYesNo, 2);
  emxInit_real_T(&pStruct->resol_fitYesNo, 2);
}

static void emxInitStruct_struct5_T(struct5_T *pStruct)
{
  emxInit_real_T(&pStruct->all_chis, 1);
}

static void emxTrim_cell_wrap_1(emxArray_cell_wrap_1 *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_1(&emxArray->data[i]);
  }
}

static void emxTrim_cell_wrap_5(emxArray_cell_wrap_5 *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_5(&emxArray->data[i]);
  }
}

static void emxTrim_cell_wrap_6(emxArray_cell_wrap_6 *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_6(&emxArray->data[i]);
  }
}

static void emxTrim_cell_wrap_8(emxArray_cell_wrap_8 *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_8(&emxArray->data[i]);
  }
}

static void emxTrim_cell_wrap_9(emxArray_cell_wrap_9 *emxArray, int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_9(&emxArray->data[i]);
  }
}

void emxCopyStruct_cell_wrap_5(cell_wrap_5 *dst, const cell_wrap_5 *src)
{
  emxCopy_real_T(&dst->f1, &src->f1);
}

void emxCopyStruct_cell_wrap_6(cell_wrap_6 *dst, const cell_wrap_6 *src)
{
  emxCopy_real_T(&dst->f1, &src->f1);
}

void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(boolean_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_cell_wrap_1(emxArray_cell_wrap_1 *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(cell_wrap_1));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_1) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (cell_wrap_1 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_1(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_cell_wrap_1(emxArray, oldNumel, newNumel);
    }
  }
}

void emxEnsureCapacity_cell_wrap_13(emxArray_cell_wrap_13 *emxArray, int
  oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(cell_wrap_13));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_13) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (cell_wrap_13 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_cell_wrap_5(emxArray_cell_wrap_5 *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(cell_wrap_5));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_5) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (cell_wrap_5 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_5(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_cell_wrap_5(emxArray, oldNumel, newNumel);
    }
  }
}

void emxEnsureCapacity_cell_wrap_6(emxArray_cell_wrap_6 *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(cell_wrap_6));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_6) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (cell_wrap_6 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_6(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_cell_wrap_6(emxArray, oldNumel, newNumel);
    }
  }
}

void emxEnsureCapacity_cell_wrap_8(emxArray_cell_wrap_8 *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(cell_wrap_8));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_8) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (cell_wrap_8 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_8(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_cell_wrap_8(emxArray, oldNumel, newNumel);
    }
  }
}

void emxEnsureCapacity_cell_wrap_9(emxArray_cell_wrap_9 *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(cell_wrap_9));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_9) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (cell_wrap_9 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_9(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_cell_wrap_9(emxArray, oldNumel, newNumel);
    }
  }
}

void emxEnsureCapacity_int16_T(emxArray_int16_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(short));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(short) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (short *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(int));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (int *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(signed char));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(signed char) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (signed char *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(double));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(double) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (double *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_uint32_T(emxArray_uint32_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(unsigned int));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(unsigned int) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (unsigned int *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxFreeStruct_cell_4(cell_4 *pStruct)
{
  emxFree_cell_wrap_0(&pStruct->f1);
  emxFree_cell_wrap_1(&pStruct->f2);
  emxFree_cell_wrap_0(&pStruct->f3);
  emxFree_cell_wrap_0(&pStruct->f4);
  emxFree_cell_wrap_0(&pStruct->f5);
  emxFree_cell_wrap_2(&pStruct->f6);
  emxFree_cell_wrap_3(&pStruct->f7);
  emxFree_cell_wrap_3(&pStruct->f8);
  emxFree_cell_wrap_3(&pStruct->f9);
  emxFree_cell_wrap_3(&pStruct->f10);
  emxFree_cell_wrap_3(&pStruct->f11);
  emxFree_cell_wrap_3(&pStruct->f12);
  emxFree_cell_wrap_3(&pStruct->f13);
}

void emxFreeStruct_cell_7(cell_7 *pStruct)
{
  emxFree_cell_wrap_5(&pStruct->f1);
  emxFree_cell_wrap_5(&pStruct->f2);
  emxFree_cell_wrap_6(&pStruct->f3);
  emxFree_cell_wrap_6(&pStruct->f4);
  emxFree_cell_wrap_5(&pStruct->f5);
  emxFree_real_T(&pStruct->f6);
}

void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_real_T(&pStruct->contrastBacks);
  emxFree_real_T(&pStruct->contrastBacksType);
  emxFree_char_T(&pStruct->TF);
  emxFree_real_T(&pStruct->resample);
  emxFree_real_T(&pStruct->dataPresent);
  emxFree_char_T(&pStruct->geometry);
  emxFree_real_T(&pStruct->contrastShifts);
  emxFree_real_T(&pStruct->contrastScales);
  emxFree_real_T(&pStruct->contrastNbas);
  emxFree_real_T(&pStruct->contrastNbss);
  emxFree_real_T(&pStruct->contrastRes);
  emxFree_real_T(&pStruct->backs);
  emxFree_real_T(&pStruct->shifts);
  emxFree_real_T(&pStruct->sf);
  emxFree_real_T(&pStruct->nba);
  emxFree_real_T(&pStruct->nbs);
  emxFree_real_T(&pStruct->res);
  emxFree_real_T(&pStruct->params);
  emxFree_char_T(&pStruct->modelType);
  emxFree_char_T(&pStruct->modelFilename);
  emxFree_char_T(&pStruct->path);
  emxFree_real_T(&pStruct->modelLanguage);
  emxFree_real_T(&pStruct->fitpars);
  emxFree_real_T(&pStruct->otherpars);
  emxFree_real_T(&pStruct->fitconstr);
  emxFree_real_T(&pStruct->otherconstr);
}

void emxFreeStruct_struct1_T(struct1_T *pStruct)
{
  emxFree_real_T(&pStruct->params);
  emxFree_real_T(&pStruct->backs);
  emxFree_real_T(&pStruct->scales);
  emxFree_real_T(&pStruct->shifts);
  emxFree_real_T(&pStruct->nba);
  emxFree_real_T(&pStruct->nbs);
  emxFree_real_T(&pStruct->res);
}

void emxFreeStruct_struct2_T(struct2_T *pStruct)
{
  emxFree_char_T(&pStruct->para);
  emxFree_char_T(&pStruct->proc);
  emxFree_char_T(&pStruct->display);
  emxFree_real_T(&pStruct->strategy);
  emxFreeStruct_struct3_T(&pStruct->checks);
}

void emxFreeStruct_struct4_T(struct4_T *pStruct)
{
  emxFree_real_T(&pStruct->ssubs);
  emxFree_real_T(&pStruct->backgrounds);
  emxFree_real_T(&pStruct->qshifts);
  emxFree_real_T(&pStruct->scalefactors);
  emxFree_real_T(&pStruct->nbairs);
  emxFree_real_T(&pStruct->nbsubs);
  emxFree_real_T(&pStruct->resolutions);
  emxFreeStruct_struct5_T(&pStruct->calculations);
  emxFree_real_T(&pStruct->allSubRough);
}

void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) && (*pEmxArray)->canFreeData)
    {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_0 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_0 *)NULL) && (*pEmxArray)->canFreeData)
    {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_0 *)NULL;
  }
}

void emxFree_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (emxArray_cell_wrap_1 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_1 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_1(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_1 *)NULL;
  }
}

void emxFree_cell_wrap_13(emxArray_cell_wrap_13 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_13 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_13 *)NULL) && (*pEmxArray)
        ->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_13 *)NULL;
  }
}

void emxFree_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_2 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_2 *)NULL) && (*pEmxArray)->canFreeData)
    {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_2 *)NULL;
  }
}

void emxFree_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (emxArray_cell_wrap_3 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_3 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_3(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_3 *)NULL;
  }
}

void emxFree_cell_wrap_5(emxArray_cell_wrap_5 **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (emxArray_cell_wrap_5 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_5 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_5(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_5 *)NULL;
  }
}

void emxFree_cell_wrap_6(emxArray_cell_wrap_6 **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (emxArray_cell_wrap_6 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_6 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_6(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_6 *)NULL;
  }
}

void emxFree_cell_wrap_8(emxArray_cell_wrap_8 **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (emxArray_cell_wrap_8 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_8 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_8(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_8 *)NULL;
  }
}

void emxFree_cell_wrap_9(emxArray_cell_wrap_9 **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (emxArray_cell_wrap_9 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_9 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_9(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_9 *)NULL;
  }
}

void emxFree_char_T(emxArray_char_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T *)NULL) {
    if (((*pEmxArray)->data != (char *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T *)NULL;
  }
}

void emxFree_int16_T(emxArray_int16_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int16_T *)NULL) {
    if (((*pEmxArray)->data != (short *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int16_T *)NULL;
  }
}

void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

void emxFree_int8_T(emxArray_int8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int8_T *)NULL) {
    if (((*pEmxArray)->data != (signed char *)NULL) && (*pEmxArray)->canFreeData)
    {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int8_T *)NULL;
  }
}

void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (double *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

void emxFree_uint32_T(emxArray_uint32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint32_T *)NULL) {
    if (((*pEmxArray)->data != (unsigned int *)NULL) && (*pEmxArray)
        ->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_uint32_T *)NULL;
  }
}

void emxInitStruct_cell_4(cell_4 *pStruct)
{
  emxInit_cell_wrap_0(&pStruct->f1, 2);
  emxInit_cell_wrap_1(&pStruct->f2, 2);
  emxInit_cell_wrap_0(&pStruct->f3, 2);
  emxInit_cell_wrap_0(&pStruct->f4, 2);
  emxInit_cell_wrap_0(&pStruct->f5, 2);
  emxInit_cell_wrap_2(&pStruct->f6, 1);
  emxInit_cell_wrap_3(&pStruct->f7, 2);
  emxInit_cell_wrap_3(&pStruct->f8, 2);
  emxInit_cell_wrap_3(&pStruct->f9, 2);
  emxInit_cell_wrap_3(&pStruct->f10, 2);
  emxInit_cell_wrap_3(&pStruct->f11, 2);
  emxInit_cell_wrap_3(&pStruct->f12, 2);
  emxInit_cell_wrap_3(&pStruct->f13, 2);
}

void emxInitStruct_cell_7(cell_7 *pStruct)
{
  emxInit_cell_wrap_5(&pStruct->f1, 1);
  emxInit_cell_wrap_5(&pStruct->f2, 1);
  emxInit_cell_wrap_6(&pStruct->f3, 1);
  emxInit_cell_wrap_6(&pStruct->f4, 1);
  emxInit_cell_wrap_5(&pStruct->f5, 1);
  emxInit_real_T(&pStruct->f6, 1);
}

void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_real_T(&pStruct->contrastBacks, 2);
  emxInit_real_T(&pStruct->contrastBacksType, 2);
  emxInit_char_T(&pStruct->TF, 2);
  emxInit_real_T(&pStruct->resample, 2);
  emxInit_real_T(&pStruct->dataPresent, 2);
  emxInit_char_T(&pStruct->geometry, 2);
  emxInit_real_T(&pStruct->contrastShifts, 2);
  emxInit_real_T(&pStruct->contrastScales, 2);
  emxInit_real_T(&pStruct->contrastNbas, 2);
  emxInit_real_T(&pStruct->contrastNbss, 2);
  emxInit_real_T(&pStruct->contrastRes, 2);
  emxInit_real_T(&pStruct->backs, 2);
  emxInit_real_T(&pStruct->shifts, 2);
  emxInit_real_T(&pStruct->sf, 2);
  emxInit_real_T(&pStruct->nba, 2);
  emxInit_real_T(&pStruct->nbs, 2);
  emxInit_real_T(&pStruct->res, 2);
  emxInit_real_T(&pStruct->params, 2);
  emxInit_char_T(&pStruct->modelType, 2);
  emxInit_char_T(&pStruct->modelFilename, 2);
  emxInit_char_T(&pStruct->path, 2);
  emxInit_real_T(&pStruct->modelLanguage, 2);
  emxInit_real_T(&pStruct->fitpars, 2);
  emxInit_real_T(&pStruct->otherpars, 2);
  emxInit_real_T(&pStruct->fitconstr, 2);
  emxInit_real_T(&pStruct->otherconstr, 2);
}

void emxInitStruct_struct1_T(struct1_T *pStruct)
{
  emxInit_real_T(&pStruct->params, 2);
  emxInit_real_T(&pStruct->backs, 2);
  emxInit_real_T(&pStruct->scales, 2);
  emxInit_real_T(&pStruct->shifts, 2);
  emxInit_real_T(&pStruct->nba, 2);
  emxInit_real_T(&pStruct->nbs, 2);
  emxInit_real_T(&pStruct->res, 2);
}

void emxInitStruct_struct2_T(struct2_T *pStruct)
{
  emxInit_char_T(&pStruct->para, 2);
  emxInit_char_T(&pStruct->proc, 2);
  emxInit_char_T(&pStruct->display, 2);
  emxInit_real_T(&pStruct->strategy, 2);
  emxInitStruct_struct3_T(&pStruct->checks);
}

void emxInitStruct_struct4_T(struct4_T *pStruct)
{
  emxInit_real_T(&pStruct->ssubs, 1);
  emxInit_real_T(&pStruct->backgrounds, 1);
  emxInit_real_T(&pStruct->qshifts, 1);
  emxInit_real_T(&pStruct->scalefactors, 1);
  emxInit_real_T(&pStruct->nbairs, 1);
  emxInit_real_T(&pStruct->nbsubs, 1);
  emxInit_real_T(&pStruct->resolutions, 1);
  emxInitStruct_struct5_T(&pStruct->calculations);
  emxInit_real_T(&pStruct->allSubRough, 1);
}

void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int numDimensions)
{
  emxArray_boolean_T *emxArray;
  int i;
  *pEmxArray = (emxArray_boolean_T *)malloc(sizeof(emxArray_boolean_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray, int numDimensions)
{
  emxArray_cell_wrap_0 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_0 *)malloc(sizeof(emxArray_cell_wrap_0));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_0 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray, int numDimensions)
{
  emxArray_cell_wrap_1 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_1 *)malloc(sizeof(emxArray_cell_wrap_1));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_1 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_13(emxArray_cell_wrap_13 **pEmxArray, int numDimensions)
{
  emxArray_cell_wrap_13 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_13 *)malloc(sizeof(emxArray_cell_wrap_13));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_13 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray, int numDimensions)
{
  emxArray_cell_wrap_2 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_2 *)malloc(sizeof(emxArray_cell_wrap_2));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_2 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray, int numDimensions)
{
  emxArray_cell_wrap_3 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_3 *)malloc(sizeof(emxArray_cell_wrap_3));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_3 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_5(emxArray_cell_wrap_5 **pEmxArray, int numDimensions)
{
  emxArray_cell_wrap_5 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_5 *)malloc(sizeof(emxArray_cell_wrap_5));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_5 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_6(emxArray_cell_wrap_6 **pEmxArray, int numDimensions)
{
  emxArray_cell_wrap_6 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_6 *)malloc(sizeof(emxArray_cell_wrap_6));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_6 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_8(emxArray_cell_wrap_8 **pEmxArray, int numDimensions)
{
  emxArray_cell_wrap_8 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_8 *)malloc(sizeof(emxArray_cell_wrap_8));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_8 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_9(emxArray_cell_wrap_9 **pEmxArray, int numDimensions)
{
  emxArray_cell_wrap_9 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_9 *)malloc(sizeof(emxArray_cell_wrap_9));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_9 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxArray_char_T *emxArray;
  int i;
  *pEmxArray = (emxArray_char_T *)malloc(sizeof(emxArray_char_T));
  emxArray = *pEmxArray;
  emxArray->data = (char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_int16_T(emxArray_int16_T **pEmxArray, int numDimensions)
{
  emxArray_int16_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int16_T *)malloc(sizeof(emxArray_int16_T));
  emxArray = *pEmxArray;
  emxArray->data = (short *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxArray_int32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_int8_T(emxArray_int8_T **pEmxArray, int numDimensions)
{
  emxArray_int8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int8_T *)malloc(sizeof(emxArray_int8_T));
  emxArray = *pEmxArray;
  emxArray->data = (signed char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxArray_real_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (double *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_uint32_T(emxArray_uint32_T **pEmxArray, int numDimensions)
{
  emxArray_uint32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_uint32_T *)malloc(sizeof(emxArray_uint32_T));
  emxArray = *pEmxArray;
  emxArray->data = (unsigned int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/* End of code generation (reflectivity_calculation_emxutil.c) */
