/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * dev_custlay_paraContrasts_emxutil.c
 *
 * Code generation for function 'dev_custlay_paraContrasts_emxutil'
 *
 */

/* Include files */
#include "dev_custlay_paraContrasts_emxutil.h"
#include "dev_custlay_paraContrasts_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void emxCopyStruct_cell_wrap_6(const emlrtStack *sp, cell_wrap_6 *dst,
                               const cell_wrap_6 *src,
                               const emlrtRTEInfo *srcLocation)
{
  emxCopy_char_T(sp, &dst->f1, &src->f1, srcLocation);
}

void emxCopy_char_T(const emlrtStack *sp, emxArray_char_T **dst,
                    emxArray_char_T *const *src,
                    const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T numElDst;
  int32_T numElSrc;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }
  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }
  emxEnsureCapacity_char_T(sp, *dst, numElDst, srcLocation);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

void emxEnsureCapacity_boolean_T(const emlrtStack *sp,
                                 emxArray_boolean_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(boolean_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(boolean_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_cell_wrap_0(const emlrtStack *sp,
                                   emxArray_cell_wrap_0 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_0));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_0) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_0 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_cell_wrap_1(const emlrtStack *sp,
                                   emxArray_cell_wrap_1 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_1));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_1) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_1 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_1(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_1(sp, emxArray, oldNumel, newNumel, srcLocation);
  }
}

void emxEnsureCapacity_cell_wrap_10(const emlrtStack *sp,
                                    emxArray_cell_wrap_10 *emxArray,
                                    int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_10));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_10) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_10 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_10(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_10(sp, emxArray, oldNumel, newNumel, srcLocation);
  }
}

void emxEnsureCapacity_cell_wrap_11(const emlrtStack *sp,
                                    emxArray_cell_wrap_11 *emxArray,
                                    int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_11));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_11) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_11 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_11(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_11(sp, emxArray, oldNumel, newNumel, srcLocation);
  }
}

void emxEnsureCapacity_cell_wrap_13(const emlrtStack *sp,
                                    emxArray_cell_wrap_13 *emxArray,
                                    int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_13));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_13) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_13 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_cell_wrap_16(const emlrtStack *sp,
                                    emxArray_cell_wrap_16 *emxArray,
                                    int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_16));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_16) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_16 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_16(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_16(sp, emxArray, oldNumel, newNumel, srcLocation);
  }
}

void emxEnsureCapacity_cell_wrap_2(const emlrtStack *sp,
                                   emxArray_cell_wrap_2 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_2));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_2) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_2 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxExpand_cell_wrap_2(emxArray, oldNumel, newNumel);
  }
}

void emxEnsureCapacity_cell_wrap_3(const emlrtStack *sp,
                                   emxArray_cell_wrap_3 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_3));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_3) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_3 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_3(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_3(sp, emxArray, oldNumel, newNumel, srcLocation);
  }
}

void emxEnsureCapacity_cell_wrap_4(const emlrtStack *sp,
                                   emxArray_cell_wrap_4 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_4));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_4) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_4 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxExpand_cell_wrap_4(emxArray, oldNumel, newNumel);
  }
}

void emxEnsureCapacity_cell_wrap_5(const emlrtStack *sp,
                                   emxArray_cell_wrap_5 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_5));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_5) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_5 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_5(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_5(sp, emxArray, oldNumel, newNumel, srcLocation);
  }
}

void emxEnsureCapacity_cell_wrap_6(const emlrtStack *sp,
                                   emxArray_cell_wrap_6 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_6));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_6) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_6 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_6(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_6(sp, emxArray, oldNumel, newNumel, srcLocation);
  }
}

void emxEnsureCapacity_cell_wrap_7(const emlrtStack *sp,
                                   emxArray_cell_wrap_7 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_7));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_7) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_7 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_7(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_7(sp, emxArray, oldNumel, newNumel, srcLocation);
  }
}

void emxEnsureCapacity_cell_wrap_9(const emlrtStack *sp,
                                   emxArray_cell_wrap_9 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_9));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_9) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_9 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_9(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_9(sp, emxArray, oldNumel, newNumel, srcLocation);
  }
}

void emxEnsureCapacity_char_T(const emlrtStack *sp, emxArray_char_T *emxArray,
                              int32_T oldNumel, const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(char_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(char_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (char_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_creal_T(const emlrtStack *sp, emxArray_creal_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(creal_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(creal_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (creal_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(int32_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int32_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel, const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(real_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxExpand_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_1(sp, &emxArray->data[i], srcLocation, false);
  }
}

void emxExpand_cell_wrap_10(const emlrtStack *sp,
                            emxArray_cell_wrap_10 *emxArray, int32_T fromIndex,
                            int32_T toIndex, const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_10(sp, &emxArray->data[i], srcLocation, false);
  }
}

void emxExpand_cell_wrap_11(const emlrtStack *sp,
                            emxArray_cell_wrap_11 *emxArray, int32_T fromIndex,
                            int32_T toIndex, const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_11(sp, &emxArray->data[i], srcLocation, false);
  }
}

void emxExpand_cell_wrap_16(const emlrtStack *sp,
                            emxArray_cell_wrap_16 *emxArray, int32_T fromIndex,
                            int32_T toIndex, const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_16(sp, &emxArray->data[i], srcLocation, false);
  }
}

void emxExpand_cell_wrap_2(emxArray_cell_wrap_2 *emxArray, int32_T fromIndex,
                           int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_2(&emxArray->data[i]);
  }
}

void emxExpand_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_3(sp, &emxArray->data[i], srcLocation, false);
  }
}

void emxExpand_cell_wrap_4(emxArray_cell_wrap_4 *emxArray, int32_T fromIndex,
                           int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_4(&emxArray->data[i]);
  }
}

void emxExpand_cell_wrap_5(const emlrtStack *sp, emxArray_cell_wrap_5 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_5(sp, &emxArray->data[i], srcLocation, false);
  }
}

void emxExpand_cell_wrap_6(const emlrtStack *sp, emxArray_cell_wrap_6 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_6(sp, &emxArray->data[i], srcLocation, false);
  }
}

void emxExpand_cell_wrap_7(const emlrtStack *sp, emxArray_cell_wrap_7 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_7(sp, &emxArray->data[i], srcLocation, false);
  }
}

void emxExpand_cell_wrap_9(const emlrtStack *sp, emxArray_cell_wrap_9 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_9(sp, &emxArray->data[i], srcLocation, false);
  }
}

void emxFreeMatrix_cell_wrap_6(cell_wrap_6 pMatrix[3])
{
  int32_T i;
  for (i = 0; i < 3; i++) {
    emxFreeStruct_cell_wrap_6(&pMatrix[i]);
  }
}

void emxFreeStruct_cell_18(cell_18 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

void emxFreeStruct_cell_8(cell_8 *pStruct)
{
  emxFree_cell_wrap_0(&pStruct->f1);
  emxFree_cell_wrap_1(&pStruct->f2);
  emxFree_cell_wrap_0(&pStruct->f3);
  emxFree_cell_wrap_2(&pStruct->f4);
  emxFree_cell_wrap_3(&pStruct->f5);
  emxFree_cell_wrap_4(&pStruct->f6);
  emxFree_cell_wrap_5(&pStruct->f7);
  emxFree_cell_wrap_6(&pStruct->f8);
  emxFree_cell_wrap_6(&pStruct->f9);
  emxFree_cell_wrap_6(&pStruct->f10);
  emxFree_cell_wrap_6(&pStruct->f11);
  emxFree_cell_wrap_6(&pStruct->f12);
  emxFree_cell_wrap_6(&pStruct->f13);
  emxFree_cell_wrap_7(&pStruct->f14);
}

void emxFreeStruct_cell_wrap_1(cell_wrap_1 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

void emxFreeStruct_cell_wrap_10(cell_wrap_10 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

void emxFreeStruct_cell_wrap_11(cell_wrap_11 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

void emxFreeStruct_cell_wrap_16(cell_wrap_16 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

void emxFreeStruct_cell_wrap_3(cell_wrap_3 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

void emxFreeStruct_cell_wrap_5(cell_wrap_5 *pStruct)
{
  emxFree_char_T(&pStruct->f1);
}

void emxFreeStruct_cell_wrap_6(cell_wrap_6 *pStruct)
{
  emxFree_char_T(&pStruct->f1);
}

void emxFreeStruct_cell_wrap_7(cell_wrap_7 *pStruct)
{
  emxFreeMatrix_cell_wrap_6(pStruct->f1);
}

void emxFreeStruct_cell_wrap_9(cell_wrap_9 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
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
  emxFree_real_T(&pStruct->contrastCustomFiles);
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
  emxFreeStruct_struct3_T(&pStruct->checks);
}

void emxFreeStruct_struct3_T(struct3_T *pStruct)
{
  emxFree_real_T(&pStruct->params_fitYesNo);
  emxFree_real_T(&pStruct->backs_fitYesNo);
  emxFree_real_T(&pStruct->shifts_fitYesNo);
  emxFree_real_T(&pStruct->scales_fitYesNo);
  emxFree_real_T(&pStruct->nbairs_fitYesNo);
  emxFree_real_T(&pStruct->nbsubs_fitYesNo);
  emxFree_real_T(&pStruct->resol_fitYesNo);
}

void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_0 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_0 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_0 *)NULL;
  }
}

void emxFree_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray)
{
  int32_T i;
  int32_T numEl;
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
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_1 *)NULL;
  }
}

void emxFree_cell_wrap_10(emxArray_cell_wrap_10 **pEmxArray)
{
  int32_T i;
  int32_T numEl;
  if (*pEmxArray != (emxArray_cell_wrap_10 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_10 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_10(&(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_10 *)NULL;
  }
}

void emxFree_cell_wrap_11(emxArray_cell_wrap_11 **pEmxArray)
{
  int32_T i;
  int32_T numEl;
  if (*pEmxArray != (emxArray_cell_wrap_11 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_11 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_11(&(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_11 *)NULL;
  }
}

void emxFree_cell_wrap_13(emxArray_cell_wrap_13 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_13 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_13 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_13 *)NULL;
  }
}

void emxFree_cell_wrap_16(emxArray_cell_wrap_16 **pEmxArray)
{
  int32_T i;
  int32_T numEl;
  if (*pEmxArray != (emxArray_cell_wrap_16 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_16 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_16(&(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_16 *)NULL;
  }
}

void emxFree_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_2 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_2 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_2 *)NULL;
  }
}

void emxFree_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray)
{
  int32_T i;
  int32_T numEl;
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
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_3 *)NULL;
  }
}

void emxFree_cell_wrap_4(emxArray_cell_wrap_4 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_4 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_4 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_4 *)NULL;
  }
}

void emxFree_cell_wrap_5(emxArray_cell_wrap_5 **pEmxArray)
{
  int32_T i;
  int32_T numEl;
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
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_5 *)NULL;
  }
}

void emxFree_cell_wrap_6(emxArray_cell_wrap_6 **pEmxArray)
{
  int32_T i;
  int32_T numEl;
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
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_6 *)NULL;
  }
}

void emxFree_cell_wrap_7(emxArray_cell_wrap_7 **pEmxArray)
{
  int32_T i;
  int32_T numEl;
  if (*pEmxArray != (emxArray_cell_wrap_7 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_7 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_7(&(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_7 *)NULL;
  }
}

void emxFree_cell_wrap_9(emxArray_cell_wrap_9 **pEmxArray)
{
  int32_T i;
  int32_T numEl;
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
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_9 *)NULL;
  }
}

void emxFree_char_T(emxArray_char_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_char_T *)NULL;
  }
}

void emxFree_creal_T(emxArray_creal_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_creal_T *)NULL) {
    if (((*pEmxArray)->data != (creal_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_creal_T *)NULL;
  }
}

void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int32_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

void emxInitMatrix_cell_wrap_6(const emlrtStack *sp, cell_wrap_6 pMatrix[3],
                               const emlrtRTEInfo *srcLocation,
                               boolean_T doPush)
{
  int32_T i;
  for (i = 0; i < 3; i++) {
    emxInitStruct_cell_wrap_6(sp, &pMatrix[i], srcLocation, doPush);
  }
}

void emxInitStruct_cell_18(const emlrtStack *sp, cell_18 *pStruct,
                           const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, doPush);
}

void emxInitStruct_cell_8(const emlrtStack *sp, cell_8 *pStruct,
                          const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxInit_cell_wrap_0(sp, &pStruct->f1, 2, srcLocation, doPush);
  emxInit_cell_wrap_1(sp, &pStruct->f2, 2, srcLocation, doPush);
  emxInit_cell_wrap_0(sp, &pStruct->f3, 2, srcLocation, doPush);
  emxInit_cell_wrap_2(sp, &pStruct->f4, 2, srcLocation, doPush);
  emxInit_cell_wrap_3(sp, &pStruct->f5, 2, srcLocation, doPush);
  emxInit_cell_wrap_4(sp, &pStruct->f6, 1, srcLocation, doPush);
  emxInit_cell_wrap_5(sp, &pStruct->f7, 2, srcLocation, doPush);
  emxInit_cell_wrap_6(sp, &pStruct->f8, 2, srcLocation, doPush);
  emxInit_cell_wrap_6(sp, &pStruct->f9, 2, srcLocation, doPush);
  emxInit_cell_wrap_6(sp, &pStruct->f10, 2, srcLocation, doPush);
  emxInit_cell_wrap_6(sp, &pStruct->f11, 2, srcLocation, doPush);
  emxInit_cell_wrap_6(sp, &pStruct->f12, 2, srcLocation, doPush);
  emxInit_cell_wrap_6(sp, &pStruct->f13, 2, srcLocation, doPush);
  emxInit_cell_wrap_7(sp, &pStruct->f14, 2, srcLocation, doPush);
}

void emxInitStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *pStruct,
                               const emlrtRTEInfo *srcLocation,
                               boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, doPush);
}

void emxInitStruct_cell_wrap_10(const emlrtStack *sp, cell_wrap_10 *pStruct,
                                const emlrtRTEInfo *srcLocation,
                                boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, doPush);
}

void emxInitStruct_cell_wrap_11(const emlrtStack *sp, cell_wrap_11 *pStruct,
                                const emlrtRTEInfo *srcLocation,
                                boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, doPush);
}

void emxInitStruct_cell_wrap_16(const emlrtStack *sp, cell_wrap_16 *pStruct,
                                const emlrtRTEInfo *srcLocation,
                                boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, doPush);
}

void emxInitStruct_cell_wrap_2(cell_wrap_2 *pStruct)
{
  pStruct->f1.size[0] = 0;
  pStruct->f1.size[1] = 0;
}

void emxInitStruct_cell_wrap_3(const emlrtStack *sp, cell_wrap_3 *pStruct,
                               const emlrtRTEInfo *srcLocation,
                               boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, doPush);
}

void emxInitStruct_cell_wrap_4(cell_wrap_4 *pStruct)
{
  pStruct->f1.size[0] = 0;
  pStruct->f1.size[1] = 0;
}

void emxInitStruct_cell_wrap_5(const emlrtStack *sp, cell_wrap_5 *pStruct,
                               const emlrtRTEInfo *srcLocation,
                               boolean_T doPush)
{
  emxInit_char_T(sp, &pStruct->f1, 2, srcLocation, doPush);
}

void emxInitStruct_cell_wrap_6(const emlrtStack *sp, cell_wrap_6 *pStruct,
                               const emlrtRTEInfo *srcLocation,
                               boolean_T doPush)
{
  emxInit_char_T(sp, &pStruct->f1, 2, srcLocation, doPush);
}

void emxInitStruct_cell_wrap_7(const emlrtStack *sp, cell_wrap_7 *pStruct,
                               const emlrtRTEInfo *srcLocation,
                               boolean_T doPush)
{
  emxInitMatrix_cell_wrap_6(sp, pStruct->f1, srcLocation, doPush);
}

void emxInitStruct_cell_wrap_9(const emlrtStack *sp, cell_wrap_9 *pStruct,
                               const emlrtRTEInfo *srcLocation,
                               boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, doPush);
}

void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct,
                             const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->contrastBacks, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->contrastBacksType, 2, srcLocation, doPush);
  emxInit_char_T(sp, &pStruct->TF, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->resample, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->dataPresent, 2, srcLocation, doPush);
  emxInit_char_T(sp, &pStruct->geometry, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->contrastShifts, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->contrastScales, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->contrastNbas, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->contrastNbss, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->contrastRes, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->backs, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->shifts, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->sf, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->nba, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->nbs, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->res, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->params, 2, srcLocation, doPush);
  emxInit_char_T(sp, &pStruct->modelType, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->contrastCustomFiles, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->fitpars, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->otherpars, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->fitconstr, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->otherconstr, 2, srcLocation, doPush);
}

void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct,
                             const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->params, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->backs, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->scales, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->shifts, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->nba, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->nbs, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->res, 2, srcLocation, doPush);
}

void emxInitStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct,
                             const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxInit_char_T(sp, &pStruct->para, 2, srcLocation, doPush);
  emxInit_char_T(sp, &pStruct->proc, 2, srcLocation, doPush);
  emxInit_char_T(sp, &pStruct->display, 2, srcLocation, doPush);
  emxInitStruct_struct3_T(sp, &pStruct->checks, srcLocation, doPush);
}

void emxInitStruct_struct3_T(const emlrtStack *sp, struct3_T *pStruct,
                             const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->params_fitYesNo, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->backs_fitYesNo, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->shifts_fitYesNo, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->scales_fitYesNo, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->nbairs_fitYesNo, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->nbsubs_fitYesNo, 2, srcLocation, doPush);
  emxInit_real_T(sp, &pStruct->resol_fitYesNo, 2, srcLocation, doPush);
}

void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray,
                       int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                       boolean_T doPush)
{
  emxArray_boolean_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T *)emlrtMallocMex(sizeof(emxArray_boolean_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_boolean_T, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_0(const emlrtStack *sp, emxArray_cell_wrap_0 **pEmxArray,
                         int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                         boolean_T doPush)
{
  emxArray_cell_wrap_0 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_0 *)emlrtMallocMex(sizeof(emxArray_cell_wrap_0));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_0, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_0 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 **pEmxArray,
                         int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                         boolean_T doPush)
{
  emxArray_cell_wrap_1 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_1 *)emlrtMallocMex(sizeof(emxArray_cell_wrap_1));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_1, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_1 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_10(const emlrtStack *sp,
                          emxArray_cell_wrap_10 **pEmxArray,
                          int32_T numDimensions,
                          const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxArray_cell_wrap_10 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_10 *)emlrtMallocMex(sizeof(emxArray_cell_wrap_10));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_10, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_10 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_11(const emlrtStack *sp,
                          emxArray_cell_wrap_11 **pEmxArray,
                          int32_T numDimensions,
                          const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxArray_cell_wrap_11 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_11 *)emlrtMallocMex(sizeof(emxArray_cell_wrap_11));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_11, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_11 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_13(const emlrtStack *sp,
                          emxArray_cell_wrap_13 **pEmxArray,
                          int32_T numDimensions,
                          const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxArray_cell_wrap_13 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_13 *)emlrtMallocMex(sizeof(emxArray_cell_wrap_13));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_13, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_13 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_16(const emlrtStack *sp,
                          emxArray_cell_wrap_16 **pEmxArray,
                          int32_T numDimensions,
                          const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxArray_cell_wrap_16 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_16 *)emlrtMallocMex(sizeof(emxArray_cell_wrap_16));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_16, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_16 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_2(const emlrtStack *sp, emxArray_cell_wrap_2 **pEmxArray,
                         int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                         boolean_T doPush)
{
  emxArray_cell_wrap_2 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_2 *)emlrtMallocMex(sizeof(emxArray_cell_wrap_2));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_2, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_2 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3 **pEmxArray,
                         int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                         boolean_T doPush)
{
  emxArray_cell_wrap_3 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_3 *)emlrtMallocMex(sizeof(emxArray_cell_wrap_3));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_3, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_3 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_4(const emlrtStack *sp, emxArray_cell_wrap_4 **pEmxArray,
                         int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                         boolean_T doPush)
{
  emxArray_cell_wrap_4 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_4 *)emlrtMallocMex(sizeof(emxArray_cell_wrap_4));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_4, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_4 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_5(const emlrtStack *sp, emxArray_cell_wrap_5 **pEmxArray,
                         int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                         boolean_T doPush)
{
  emxArray_cell_wrap_5 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_5 *)emlrtMallocMex(sizeof(emxArray_cell_wrap_5));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_5, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_5 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_6(const emlrtStack *sp, emxArray_cell_wrap_6 **pEmxArray,
                         int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                         boolean_T doPush)
{
  emxArray_cell_wrap_6 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_6 *)emlrtMallocMex(sizeof(emxArray_cell_wrap_6));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_6, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_6 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_7(const emlrtStack *sp, emxArray_cell_wrap_7 **pEmxArray,
                         int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                         boolean_T doPush)
{
  emxArray_cell_wrap_7 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_7 *)emlrtMallocMex(sizeof(emxArray_cell_wrap_7));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_7, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_7 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_9(const emlrtStack *sp, emxArray_cell_wrap_9 **pEmxArray,
                         int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                         boolean_T doPush)
{
  emxArray_cell_wrap_9 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_9 *)emlrtMallocMex(sizeof(emxArray_cell_wrap_9));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_9, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_9 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray,
                    int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                    boolean_T doPush)
{
  emxArray_char_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T *)emlrtMallocMex(sizeof(emxArray_char_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_char_T, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray,
                     int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                     boolean_T doPush)
{
  emxArray_creal_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_creal_T *)emlrtMallocMex(sizeof(emxArray_creal_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_creal_T, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (creal_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
                     int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                     boolean_T doPush)
{
  emxArray_int32_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int32_T *)emlrtMallocMex(sizeof(emxArray_int32_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_int32_T, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                    boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_real_T, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxTrim_cell_wrap_1(emxArray_cell_wrap_1 *emxArray, int32_T fromIndex,
                         int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_1(&emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_10(emxArray_cell_wrap_10 *emxArray, int32_T fromIndex,
                          int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_10(&emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_11(emxArray_cell_wrap_11 *emxArray, int32_T fromIndex,
                          int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_11(&emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_16(emxArray_cell_wrap_16 *emxArray, int32_T fromIndex,
                          int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_16(&emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_3(emxArray_cell_wrap_3 *emxArray, int32_T fromIndex,
                         int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_3(&emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_5(emxArray_cell_wrap_5 *emxArray, int32_T fromIndex,
                         int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_5(&emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_6(emxArray_cell_wrap_6 *emxArray, int32_T fromIndex,
                         int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_6(&emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_7(emxArray_cell_wrap_7 *emxArray, int32_T fromIndex,
                         int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_7(&emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_9(emxArray_cell_wrap_9 *emxArray, int32_T fromIndex,
                         int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_9(&emxArray->data[i]);
  }
}

/* End of code generation (dev_custlay_paraContrasts_emxutil.c) */
