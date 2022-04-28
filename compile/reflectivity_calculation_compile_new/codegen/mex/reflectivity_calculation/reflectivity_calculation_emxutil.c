/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * reflectivity_calculation_emxutil.c
 *
 * Code generation for function 'reflectivity_calculation_emxutil'
 *
 */

/* Include files */
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void emxCopyMatrix_cell_wrap_6(const emlrtStack *sp, cell_wrap_6 dst[3],
                               const cell_wrap_6 src[3],
                               const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = 0; i < 3; i++) {
    emxCopyStruct_cell_wrap_6(sp, &dst[i], &src[i], srcLocation);
  }
}

void emxCopyStruct_cell_wrap_14(const emlrtStack *sp, cell_wrap_14 *dst,
                                const cell_wrap_14 *src,
                                const emlrtRTEInfo *srcLocation)
{
  emxCopy_real_T(sp, &dst->f1, &src->f1, srcLocation);
}

void emxCopyStruct_cell_wrap_5(const emlrtStack *sp, cell_wrap_5 *dst,
                               const cell_wrap_5 *src,
                               const emlrtRTEInfo *srcLocation)
{
  emxCopy_char_T(sp, &dst->f1, &src->f1, srcLocation);
}

void emxCopyStruct_cell_wrap_6(const emlrtStack *sp, cell_wrap_6 *dst,
                               const cell_wrap_6 *src,
                               const emlrtRTEInfo *srcLocation)
{
  emxCopy_char_T(sp, &dst->f1, &src->f1, srcLocation);
}

void emxCopyStruct_cell_wrap_7(const emlrtStack *sp, cell_wrap_7 *dst,
                               const cell_wrap_7 *src,
                               const emlrtRTEInfo *srcLocation)
{
  emxCopyMatrix_cell_wrap_6(sp, dst->f1, src->f1, srcLocation);
}

void emxCopyStruct_cell_wrap_9(const emlrtStack *sp, cell_wrap_9 *dst,
                               const cell_wrap_9 *src,
                               const emlrtRTEInfo *srcLocation)
{
  emxCopy_real_T(sp, &dst->f1, &src->f1, srcLocation);
}

void emxCopyStruct_struct5_T(const emlrtStack *sp, struct5_T *dst,
                             const struct5_T *src,
                             const emlrtRTEInfo *srcLocation)
{
  emxCopy_real_T(sp, &dst->all_chis, &src->all_chis, srcLocation);
  dst->sum_chi = src->sum_chi;
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

void emxCopy_real_T(const emlrtStack *sp, emxArray_real_T **dst,
                    emxArray_real_T *const *src,
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
  emxEnsureCapacity_real_T(sp, *dst, numElDst, srcLocation);
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
    emxTrim_cell_wrap_1(sp, emxArray, newNumel, oldNumel);
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
    emxTrim_cell_wrap_10(sp, emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_10(sp, emxArray, oldNumel, newNumel, srcLocation);
  }
}

void emxEnsureCapacity_cell_wrap_12(const emlrtStack *sp,
                                    emxArray_cell_wrap_12 *emxArray,
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
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_12));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_12) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_12 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_12(sp, emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_12(sp, emxArray, oldNumel, newNumel, srcLocation);
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
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_13(sp, emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_13(sp, emxArray, oldNumel, newNumel, srcLocation);
  }
}

void emxEnsureCapacity_cell_wrap_14(const emlrtStack *sp,
                                    emxArray_cell_wrap_14 *emxArray,
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
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_14));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_14) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_14 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_14(sp, emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_14(sp, emxArray, oldNumel, newNumel, srcLocation);
  }
}

void emxEnsureCapacity_cell_wrap_17(const emlrtStack *sp,
                                    emxArray_cell_wrap_17 *emxArray,
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
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_17));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_17) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_17 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
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

void emxEnsureCapacity_cell_wrap_27(const emlrtStack *sp,
                                    emxArray_cell_wrap_27 *emxArray,
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
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_27));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_27) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_27 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_cell_wrap_28(const emlrtStack *sp,
                                    emxArray_cell_wrap_28 *emxArray,
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
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_28));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_28) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_28 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_28(sp, emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_28(sp, emxArray, oldNumel, newNumel, srcLocation);
  }
}

void emxEnsureCapacity_cell_wrap_29(const emlrtStack *sp,
                                    emxArray_cell_wrap_29 *emxArray,
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
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_29));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_29) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_29 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_29(sp, emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_29(sp, emxArray, oldNumel, newNumel, srcLocation);
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
    emxTrim_cell_wrap_3(sp, emxArray, newNumel, oldNumel);
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
    emxTrim_cell_wrap_5(sp, emxArray, newNumel, oldNumel);
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
    emxTrim_cell_wrap_6(sp, emxArray, newNumel, oldNumel);
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
    emxTrim_cell_wrap_7(sp, emxArray, newNumel, oldNumel);
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
    emxTrim_cell_wrap_9(sp, emxArray, newNumel, oldNumel);
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

void emxEnsureCapacity_int8_T(const emlrtStack *sp, emxArray_int8_T *emxArray,
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
    newData = emlrtCallocMex((uint32_T)i, sizeof(int8_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int8_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (int8_T *)newData;
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
    emxInitStruct_cell_wrap_1(sp, &emxArray->data[i], srcLocation);
  }
}

void emxExpand_cell_wrap_10(const emlrtStack *sp,
                            emxArray_cell_wrap_10 *emxArray, int32_T fromIndex,
                            int32_T toIndex, const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_10(sp, &emxArray->data[i], srcLocation);
  }
}

void emxExpand_cell_wrap_12(const emlrtStack *sp,
                            emxArray_cell_wrap_12 *emxArray, int32_T fromIndex,
                            int32_T toIndex, const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_12(sp, &emxArray->data[i], srcLocation);
  }
}

void emxExpand_cell_wrap_13(const emlrtStack *sp,
                            emxArray_cell_wrap_13 *emxArray, int32_T fromIndex,
                            int32_T toIndex, const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_13(sp, &emxArray->data[i], srcLocation);
  }
}

void emxExpand_cell_wrap_14(const emlrtStack *sp,
                            emxArray_cell_wrap_14 *emxArray, int32_T fromIndex,
                            int32_T toIndex, const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_14(sp, &emxArray->data[i], srcLocation);
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

void emxExpand_cell_wrap_28(const emlrtStack *sp,
                            emxArray_cell_wrap_28 *emxArray, int32_T fromIndex,
                            int32_T toIndex, const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_28(sp, &emxArray->data[i], srcLocation);
  }
}

void emxExpand_cell_wrap_29(const emlrtStack *sp,
                            emxArray_cell_wrap_29 *emxArray, int32_T fromIndex,
                            int32_T toIndex, const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_29(sp, &emxArray->data[i], srcLocation);
  }
}

void emxExpand_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_3(sp, &emxArray->data[i], srcLocation);
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
    emxInitStruct_cell_wrap_5(sp, &emxArray->data[i], srcLocation);
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
    emxInitStruct_cell_wrap_7(sp, &emxArray->data[i], srcLocation);
  }
}

void emxExpand_cell_wrap_9(const emlrtStack *sp, emxArray_cell_wrap_9 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_9(sp, &emxArray->data[i], srcLocation);
  }
}

void emxFreeMatrix_cell_wrap_6(const emlrtStack *sp, cell_wrap_6 pMatrix[3])
{
  int32_T i;
  for (i = 0; i < 3; i++) {
    emxFreeStruct_cell_wrap_6(sp, &pMatrix[i]);
  }
}

void emxFreeStruct_cell_11(const emlrtStack *sp, cell_11 *pStruct)
{
  emxFree_cell_wrap_9(sp, &pStruct->f1);
  emxFree_cell_wrap_9(sp, &pStruct->f2);
  emxFree_cell_wrap_10(sp, &pStruct->f3);
  emxFree_cell_wrap_10(sp, &pStruct->f4);
  emxFree_cell_wrap_9(sp, &pStruct->f5);
  emxFree_cell_wrap_10(sp, &pStruct->f6);
}

void emxFreeStruct_cell_16(const emlrtStack *sp, cell_16 *pStruct)
{
  emxFree_cell_wrap_0(sp, &pStruct->f1);
  emxFree_cell_wrap_14(sp, &pStruct->f2);
  emxFree_cell_wrap_0(sp, &pStruct->f3);
  emxFree_cell_wrap_14(sp, &pStruct->f4);
  emxFree_cell_wrap_14(sp, &pStruct->f5);
  emxFree_cell_wrap_14(sp, &pStruct->f6);
  emxFree_cell_wrap_5(sp, &pStruct->f7);
  emxFree_cell_wrap_6(sp, &pStruct->f8);
  emxFree_cell_wrap_6(sp, &pStruct->f9);
  emxFree_cell_wrap_6(sp, &pStruct->f10);
  emxFree_cell_wrap_6(sp, &pStruct->f11);
  emxFree_cell_wrap_6(sp, &pStruct->f12);
  emxFree_cell_wrap_6(sp, &pStruct->f13);
  emxFree_cell_wrap_7(sp, &pStruct->f14);
}

void emxFreeStruct_cell_19(const emlrtStack *sp, cell_19 *pStruct)
{
  emxFree_real_T(sp, &pStruct->f1);
}

void emxFreeStruct_cell_8(const emlrtStack *sp, cell_8 *pStruct)
{
  emxFree_cell_wrap_0(sp, &pStruct->f1);
  emxFree_cell_wrap_1(sp, &pStruct->f2);
  emxFree_cell_wrap_0(sp, &pStruct->f3);
  emxFree_cell_wrap_2(sp, &pStruct->f4);
  emxFree_cell_wrap_3(sp, &pStruct->f5);
  emxFree_cell_wrap_4(sp, &pStruct->f6);
  emxFree_cell_wrap_5(sp, &pStruct->f7);
  emxFree_cell_wrap_6(sp, &pStruct->f8);
  emxFree_cell_wrap_6(sp, &pStruct->f9);
  emxFree_cell_wrap_6(sp, &pStruct->f10);
  emxFree_cell_wrap_6(sp, &pStruct->f11);
  emxFree_cell_wrap_6(sp, &pStruct->f12);
  emxFree_cell_wrap_6(sp, &pStruct->f13);
  emxFree_cell_wrap_7(sp, &pStruct->f14);
}

void emxFreeStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *pStruct)
{
  emxFree_real_T(sp, &pStruct->f1);
}

void emxFreeStruct_cell_wrap_10(const emlrtStack *sp, cell_wrap_10 *pStruct)
{
  emxFree_real_T(sp, &pStruct->f1);
}

void emxFreeStruct_cell_wrap_12(const emlrtStack *sp, cell_wrap_12 *pStruct)
{
  emxFree_real_T(sp, &pStruct->f1);
}

void emxFreeStruct_cell_wrap_13(const emlrtStack *sp, cell_wrap_13 *pStruct)
{
  emxFree_real_T(sp, &pStruct->f1);
}

void emxFreeStruct_cell_wrap_14(const emlrtStack *sp, cell_wrap_14 *pStruct)
{
  emxFree_real_T(sp, &pStruct->f1);
}

void emxFreeStruct_cell_wrap_28(const emlrtStack *sp, cell_wrap_28 *pStruct)
{
  emxFree_real_T(sp, &pStruct->f1);
}

void emxFreeStruct_cell_wrap_29(const emlrtStack *sp, cell_wrap_29 *pStruct)
{
  emxFree_real_T(sp, &pStruct->f1);
}

void emxFreeStruct_cell_wrap_3(const emlrtStack *sp, cell_wrap_3 *pStruct)
{
  emxFree_real_T(sp, &pStruct->f1);
}

void emxFreeStruct_cell_wrap_5(const emlrtStack *sp, cell_wrap_5 *pStruct)
{
  emxFree_char_T(sp, &pStruct->f1);
}

void emxFreeStruct_cell_wrap_6(const emlrtStack *sp, cell_wrap_6 *pStruct)
{
  emxFree_char_T(sp, &pStruct->f1);
}

void emxFreeStruct_cell_wrap_7(const emlrtStack *sp, cell_wrap_7 *pStruct)
{
  emxFreeMatrix_cell_wrap_6(sp, pStruct->f1);
}

void emxFreeStruct_cell_wrap_9(const emlrtStack *sp, cell_wrap_9 *pStruct)
{
  emxFree_real_T(sp, &pStruct->f1);
}

void emxFreeStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct)
{
  emxFree_real_T(sp, &pStruct->contrastBacks);
  emxFree_real_T(sp, &pStruct->contrastBacksType);
  emxFree_char_T(sp, &pStruct->TF);
  emxFree_real_T(sp, &pStruct->resample);
  emxFree_real_T(sp, &pStruct->dataPresent);
  emxFree_char_T(sp, &pStruct->geometry);
  emxFree_real_T(sp, &pStruct->contrastShifts);
  emxFree_real_T(sp, &pStruct->contrastScales);
  emxFree_real_T(sp, &pStruct->contrastNbas);
  emxFree_real_T(sp, &pStruct->contrastNbss);
  emxFree_real_T(sp, &pStruct->contrastRes);
  emxFree_real_T(sp, &pStruct->backs);
  emxFree_real_T(sp, &pStruct->shifts);
  emxFree_real_T(sp, &pStruct->sf);
  emxFree_real_T(sp, &pStruct->nba);
  emxFree_real_T(sp, &pStruct->nbs);
  emxFree_real_T(sp, &pStruct->res);
  emxFree_real_T(sp, &pStruct->params);
  emxFree_char_T(sp, &pStruct->modelType);
  emxFree_real_T(sp, &pStruct->contrastCustomFiles);
  emxFree_real_T(sp, &pStruct->fitpars);
  emxFree_real_T(sp, &pStruct->otherpars);
  emxFree_real_T(sp, &pStruct->fitconstr);
  emxFree_real_T(sp, &pStruct->otherconstr);
}

void emxFreeStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct)
{
  emxFree_real_T(sp, &pStruct->params);
  emxFree_real_T(sp, &pStruct->backs);
  emxFree_real_T(sp, &pStruct->scales);
  emxFree_real_T(sp, &pStruct->shifts);
  emxFree_real_T(sp, &pStruct->nba);
  emxFree_real_T(sp, &pStruct->nbs);
  emxFree_real_T(sp, &pStruct->res);
}

void emxFreeStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct)
{
  emxFree_char_T(sp, &pStruct->para);
  emxFree_char_T(sp, &pStruct->proc);
  emxFree_char_T(sp, &pStruct->display);
  emxFreeStruct_struct3_T(sp, &pStruct->checks);
}

void emxFreeStruct_struct3_T(const emlrtStack *sp, struct3_T *pStruct)
{
  emxFree_real_T(sp, &pStruct->params_fitYesNo);
  emxFree_real_T(sp, &pStruct->backs_fitYesNo);
  emxFree_real_T(sp, &pStruct->shifts_fitYesNo);
  emxFree_real_T(sp, &pStruct->scales_fitYesNo);
  emxFree_real_T(sp, &pStruct->nbairs_fitYesNo);
  emxFree_real_T(sp, &pStruct->nbsubs_fitYesNo);
  emxFree_real_T(sp, &pStruct->resol_fitYesNo);
}

void emxFreeStruct_struct4_T(const emlrtStack *sp, struct4_T *pStruct)
{
  emxFree_real_T(sp, &pStruct->ssubs);
  emxFree_real_T(sp, &pStruct->backgrounds);
  emxFree_real_T(sp, &pStruct->qshifts);
  emxFree_real_T(sp, &pStruct->scalefactors);
  emxFree_real_T(sp, &pStruct->nbairs);
  emxFree_real_T(sp, &pStruct->nbsubs);
  emxFree_real_T(sp, &pStruct->resolutions);
  emxFreeStruct_struct5_T(sp, &pStruct->calculations);
  emxFree_real_T(sp, &pStruct->allSubRough);
  emxFree_real_T(sp, &pStruct->resample);
}

void emxFreeStruct_struct5_T(const emlrtStack *sp, struct5_T *pStruct)
{
  emxFree_real_T(sp, &pStruct->all_chis);
}

void emxFreeStruct_struct_T(const emlrtStack *sp, struct_T *pStruct)
{
  emxFree_real_T(sp, &pStruct->ssubs);
  emxFree_real_T(sp, &pStruct->backgrounds);
  emxFree_real_T(sp, &pStruct->qshifts);
  emxFree_real_T(sp, &pStruct->scalefactors);
  emxFree_real_T(sp, &pStruct->nbairs);
  emxFree_real_T(sp, &pStruct->nbsubs);
  emxFree_real_T(sp, &pStruct->resolutions);
  emxFreeStruct_struct5_T(sp, &pStruct->calculations);
  emxFree_real_T(sp, &pStruct->allSubRough);
  emxFree_real_T(sp, &pStruct->resample);
}

void emxFree_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

void emxFree_cell_wrap_0(const emlrtStack *sp, emxArray_cell_wrap_0 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_0 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_0 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_0 *)NULL;
  }
}

void emxFree_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 **pEmxArray)
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
        emxFreeStruct_cell_wrap_1(sp, &(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_1 *)NULL;
  }
}

void emxFree_cell_wrap_10(const emlrtStack *sp,
                          emxArray_cell_wrap_10 **pEmxArray)
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
        emxFreeStruct_cell_wrap_10(sp, &(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_10 *)NULL;
  }
}

void emxFree_cell_wrap_12(const emlrtStack *sp,
                          emxArray_cell_wrap_12 **pEmxArray)
{
  int32_T i;
  int32_T numEl;
  if (*pEmxArray != (emxArray_cell_wrap_12 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_12 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_12(sp, &(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_12 *)NULL;
  }
}

void emxFree_cell_wrap_13(const emlrtStack *sp,
                          emxArray_cell_wrap_13 **pEmxArray)
{
  int32_T i;
  int32_T numEl;
  if (*pEmxArray != (emxArray_cell_wrap_13 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_13 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_13(sp, &(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_13 *)NULL;
  }
}

void emxFree_cell_wrap_14(const emlrtStack *sp,
                          emxArray_cell_wrap_14 **pEmxArray)
{
  int32_T i;
  int32_T numEl;
  if (*pEmxArray != (emxArray_cell_wrap_14 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_14 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_14(sp, &(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_14 *)NULL;
  }
}

void emxFree_cell_wrap_17(const emlrtStack *sp,
                          emxArray_cell_wrap_17 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_17 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_17 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_17 *)NULL;
  }
}

void emxFree_cell_wrap_2(const emlrtStack *sp, emxArray_cell_wrap_2 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_2 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_2 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_2 *)NULL;
  }
}

void emxFree_cell_wrap_27(const emlrtStack *sp,
                          emxArray_cell_wrap_27 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_27 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_27 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_27 *)NULL;
  }
}

void emxFree_cell_wrap_28(const emlrtStack *sp,
                          emxArray_cell_wrap_28 **pEmxArray)
{
  int32_T i;
  int32_T numEl;
  if (*pEmxArray != (emxArray_cell_wrap_28 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_28 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_28(sp, &(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_28 *)NULL;
  }
}

void emxFree_cell_wrap_29(const emlrtStack *sp,
                          emxArray_cell_wrap_29 **pEmxArray)
{
  int32_T i;
  int32_T numEl;
  if (*pEmxArray != (emxArray_cell_wrap_29 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_29 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_29(sp, &(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_29 *)NULL;
  }
}

void emxFree_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3 **pEmxArray)
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
        emxFreeStruct_cell_wrap_3(sp, &(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_3 *)NULL;
  }
}

void emxFree_cell_wrap_4(const emlrtStack *sp, emxArray_cell_wrap_4 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_4 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_4 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_4 *)NULL;
  }
}

void emxFree_cell_wrap_5(const emlrtStack *sp, emxArray_cell_wrap_5 **pEmxArray)
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
        emxFreeStruct_cell_wrap_5(sp, &(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_5 *)NULL;
  }
}

void emxFree_cell_wrap_6(const emlrtStack *sp, emxArray_cell_wrap_6 **pEmxArray)
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
        emxFreeStruct_cell_wrap_6(sp, &(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_6 *)NULL;
  }
}

void emxFree_cell_wrap_7(const emlrtStack *sp, emxArray_cell_wrap_7 **pEmxArray)
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
        emxFreeStruct_cell_wrap_7(sp, &(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_7 *)NULL;
  }
}

void emxFree_cell_wrap_9(const emlrtStack *sp, emxArray_cell_wrap_9 **pEmxArray)
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
        emxFreeStruct_cell_wrap_9(sp, &(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_9 *)NULL;
  }
}

void emxFree_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_char_T *)NULL;
  }
}

void emxFree_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_creal_T *)NULL) {
    if (((*pEmxArray)->data != (creal_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_creal_T *)NULL;
  }
}

void emxFree_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int32_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

void emxFree_int8_T(const emlrtStack *sp, emxArray_int8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int8_T *)NULL) {
    if (((*pEmxArray)->data != (int8_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_int8_T *)NULL;
  }
}

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
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

void emxInitStruct_cell_11(const emlrtStack *sp, cell_11 *pStruct,
                           const emlrtRTEInfo *srcLocation)
{
  emxInit_cell_wrap_9(sp, &pStruct->f1, srcLocation);
  emxInit_cell_wrap_9(sp, &pStruct->f2, srcLocation);
  emxInit_cell_wrap_10(sp, &pStruct->f3, srcLocation);
  emxInit_cell_wrap_10(sp, &pStruct->f4, srcLocation);
  emxInit_cell_wrap_9(sp, &pStruct->f5, srcLocation);
  emxInit_cell_wrap_10(sp, &pStruct->f6, srcLocation);
}

void emxInitStruct_cell_16(const emlrtStack *sp, cell_16 *pStruct,
                           const emlrtRTEInfo *srcLocation)
{
  emxInit_cell_wrap_0(sp, &pStruct->f1, srcLocation);
  emxInit_cell_wrap_14(sp, &pStruct->f2, 2, srcLocation);
  emxInit_cell_wrap_0(sp, &pStruct->f3, srcLocation);
  emxInit_cell_wrap_14(sp, &pStruct->f4, 2, srcLocation);
  emxInit_cell_wrap_14(sp, &pStruct->f5, 2, srcLocation);
  emxInit_cell_wrap_14(sp, &pStruct->f6, 1, srcLocation);
  emxInit_cell_wrap_5(sp, &pStruct->f7, srcLocation);
  emxInit_cell_wrap_6(sp, &pStruct->f8, srcLocation);
  emxInit_cell_wrap_6(sp, &pStruct->f9, srcLocation);
  emxInit_cell_wrap_6(sp, &pStruct->f10, srcLocation);
  emxInit_cell_wrap_6(sp, &pStruct->f11, srcLocation);
  emxInit_cell_wrap_6(sp, &pStruct->f12, srcLocation);
  emxInit_cell_wrap_6(sp, &pStruct->f13, srcLocation);
  emxInit_cell_wrap_7(sp, &pStruct->f14, srcLocation);
}

void emxInitStruct_cell_19(const emlrtStack *sp, cell_19 *pStruct,
                           const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, true);
}

void emxInitStruct_cell_8(const emlrtStack *sp, cell_8 *pStruct,
                          const emlrtRTEInfo *srcLocation)
{
  emxInit_cell_wrap_0(sp, &pStruct->f1, srcLocation);
  emxInit_cell_wrap_1(sp, &pStruct->f2, srcLocation);
  emxInit_cell_wrap_0(sp, &pStruct->f3, srcLocation);
  emxInit_cell_wrap_2(sp, &pStruct->f4, srcLocation);
  emxInit_cell_wrap_3(sp, &pStruct->f5, srcLocation);
  emxInit_cell_wrap_4(sp, &pStruct->f6, srcLocation);
  emxInit_cell_wrap_5(sp, &pStruct->f7, srcLocation);
  emxInit_cell_wrap_6(sp, &pStruct->f8, srcLocation);
  emxInit_cell_wrap_6(sp, &pStruct->f9, srcLocation);
  emxInit_cell_wrap_6(sp, &pStruct->f10, srcLocation);
  emxInit_cell_wrap_6(sp, &pStruct->f11, srcLocation);
  emxInit_cell_wrap_6(sp, &pStruct->f12, srcLocation);
  emxInit_cell_wrap_6(sp, &pStruct->f13, srcLocation);
  emxInit_cell_wrap_7(sp, &pStruct->f14, srcLocation);
}

void emxInitStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *pStruct,
                               const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, false);
}

void emxInitStruct_cell_wrap_10(const emlrtStack *sp, cell_wrap_10 *pStruct,
                                const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, false);
}

void emxInitStruct_cell_wrap_12(const emlrtStack *sp, cell_wrap_12 *pStruct,
                                const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, false);
}

void emxInitStruct_cell_wrap_13(const emlrtStack *sp, cell_wrap_13 *pStruct,
                                const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, false);
}

void emxInitStruct_cell_wrap_14(const emlrtStack *sp, cell_wrap_14 *pStruct,
                                const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, false);
}

void emxInitStruct_cell_wrap_2(cell_wrap_2 *pStruct)
{
  pStruct->f1.size[0] = 0;
  pStruct->f1.size[1] = 0;
}

void emxInitStruct_cell_wrap_28(const emlrtStack *sp, cell_wrap_28 *pStruct,
                                const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, false);
}

void emxInitStruct_cell_wrap_29(const emlrtStack *sp, cell_wrap_29 *pStruct,
                                const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, false);
}

void emxInitStruct_cell_wrap_3(const emlrtStack *sp, cell_wrap_3 *pStruct,
                               const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, false);
}

void emxInitStruct_cell_wrap_4(cell_wrap_4 *pStruct)
{
  pStruct->f1.size[0] = 0;
  pStruct->f1.size[1] = 0;
}

void emxInitStruct_cell_wrap_5(const emlrtStack *sp, cell_wrap_5 *pStruct,
                               const emlrtRTEInfo *srcLocation)
{
  emxInit_char_T(sp, &pStruct->f1, srcLocation, false);
}

void emxInitStruct_cell_wrap_6(const emlrtStack *sp, cell_wrap_6 *pStruct,
                               const emlrtRTEInfo *srcLocation,
                               boolean_T doPush)
{
  emxInit_char_T(sp, &pStruct->f1, srcLocation, doPush);
}

void emxInitStruct_cell_wrap_7(const emlrtStack *sp, cell_wrap_7 *pStruct,
                               const emlrtRTEInfo *srcLocation)
{
  emxInitMatrix_cell_wrap_6(sp, pStruct->f1, srcLocation, false);
}

void emxInitStruct_cell_wrap_9(const emlrtStack *sp, cell_wrap_9 *pStruct,
                               const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->f1, 2, srcLocation, false);
}

void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct,
                             const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->contrastBacks, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->contrastBacksType, 2, srcLocation, true);
  emxInit_char_T(sp, &pStruct->TF, srcLocation, true);
  emxInit_real_T(sp, &pStruct->resample, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->dataPresent, 2, srcLocation, true);
  emxInit_char_T(sp, &pStruct->geometry, srcLocation, true);
  emxInit_real_T(sp, &pStruct->contrastShifts, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->contrastScales, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->contrastNbas, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->contrastNbss, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->contrastRes, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->backs, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->shifts, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->sf, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->nba, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->nbs, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->res, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->params, 2, srcLocation, true);
  emxInit_char_T(sp, &pStruct->modelType, srcLocation, true);
  emxInit_real_T(sp, &pStruct->contrastCustomFiles, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->fitpars, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->otherpars, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->fitconstr, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->otherconstr, 2, srcLocation, true);
}

void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct,
                             const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->params, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->backs, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->scales, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->shifts, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->nba, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->nbs, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->res, 2, srcLocation, true);
}

void emxInitStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct,
                             const emlrtRTEInfo *srcLocation)
{
  emxInit_char_T(sp, &pStruct->para, srcLocation, true);
  emxInit_char_T(sp, &pStruct->proc, srcLocation, true);
  emxInit_char_T(sp, &pStruct->display, srcLocation, true);
  emxInitStruct_struct3_T(sp, &pStruct->checks, srcLocation);
}

void emxInitStruct_struct3_T(const emlrtStack *sp, struct3_T *pStruct,
                             const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->params_fitYesNo, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->backs_fitYesNo, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->shifts_fitYesNo, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->scales_fitYesNo, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->nbairs_fitYesNo, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->nbsubs_fitYesNo, 2, srcLocation, true);
  emxInit_real_T(sp, &pStruct->resol_fitYesNo, 2, srcLocation, true);
}

void emxInitStruct_struct4_T(const emlrtStack *sp, struct4_T *pStruct,
                             const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->ssubs, 1, srcLocation, true);
  emxInit_real_T(sp, &pStruct->backgrounds, 1, srcLocation, true);
  emxInit_real_T(sp, &pStruct->qshifts, 1, srcLocation, true);
  emxInit_real_T(sp, &pStruct->scalefactors, 1, srcLocation, true);
  emxInit_real_T(sp, &pStruct->nbairs, 1, srcLocation, true);
  emxInit_real_T(sp, &pStruct->nbsubs, 1, srcLocation, true);
  emxInit_real_T(sp, &pStruct->resolutions, 1, srcLocation, true);
  emxInitStruct_struct5_T(sp, &pStruct->calculations, srcLocation);
  emxInit_real_T(sp, &pStruct->allSubRough, 1, srcLocation, true);
  emxInit_real_T(sp, &pStruct->resample, 2, srcLocation, true);
}

void emxInitStruct_struct5_T(const emlrtStack *sp, struct5_T *pStruct,
                             const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->all_chis, 1, srcLocation, true);
}

void emxInitStruct_struct_T(const emlrtStack *sp, struct_T *pStruct,
                            const emlrtRTEInfo *srcLocation)
{
  emxInit_real_T(sp, &pStruct->ssubs, 1, srcLocation, true);
  emxInit_real_T(sp, &pStruct->backgrounds, 1, srcLocation, true);
  emxInit_real_T(sp, &pStruct->qshifts, 1, srcLocation, true);
  emxInit_real_T(sp, &pStruct->scalefactors, 1, srcLocation, true);
  emxInit_real_T(sp, &pStruct->nbairs, 1, srcLocation, true);
  emxInit_real_T(sp, &pStruct->nbsubs, 1, srcLocation, true);
  emxInit_real_T(sp, &pStruct->resolutions, 1, srcLocation, true);
  emxInitStruct_struct5_T(sp, &pStruct->calculations, srcLocation);
  emxInit_real_T(sp, &pStruct->allSubRough, 1, srcLocation, true);
  emxInit_real_T(sp, &pStruct->resample, 2, srcLocation, true);
}

void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray,
                       const emlrtRTEInfo *srcLocation)
{
  emxArray_boolean_T *emxArray;
  *pEmxArray =
      (emxArray_boolean_T *)emlrtMallocEmxArray(sizeof(emxArray_boolean_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_boolean_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_cell_wrap_0(const emlrtStack *sp, emxArray_cell_wrap_0 **pEmxArray,
                         const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_0 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_0 *)emlrtMallocEmxArray(sizeof(emxArray_cell_wrap_0));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_0, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_0 *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 **pEmxArray,
                         const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_1 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_1 *)emlrtMallocEmxArray(sizeof(emxArray_cell_wrap_1));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_1, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_1 *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_10(const emlrtStack *sp,
                          emxArray_cell_wrap_10 **pEmxArray,
                          const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_10 *emxArray;
  *pEmxArray = (emxArray_cell_wrap_10 *)emlrtMallocEmxArray(
      sizeof(emxArray_cell_wrap_10));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_10, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_10 *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_cell_wrap_12(const emlrtStack *sp,
                          emxArray_cell_wrap_12 **pEmxArray,
                          const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_12 *emxArray;
  *pEmxArray = (emxArray_cell_wrap_12 *)emlrtMallocEmxArray(
      sizeof(emxArray_cell_wrap_12));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_12, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_12 *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_cell_wrap_13(const emlrtStack *sp,
                          emxArray_cell_wrap_13 **pEmxArray,
                          const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_13 *emxArray;
  *pEmxArray = (emxArray_cell_wrap_13 *)emlrtMallocEmxArray(
      sizeof(emxArray_cell_wrap_13));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_13, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_13 *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_cell_wrap_14(const emlrtStack *sp,
                          emxArray_cell_wrap_14 **pEmxArray,
                          int32_T numDimensions,
                          const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_14 *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_cell_wrap_14 *)emlrtMallocEmxArray(
      sizeof(emxArray_cell_wrap_14));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_14, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_14 *)NULL;
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

void emxInit_cell_wrap_17(const emlrtStack *sp,
                          emxArray_cell_wrap_17 **pEmxArray,
                          const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_17 *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_cell_wrap_17 *)emlrtMallocEmxArray(
      sizeof(emxArray_cell_wrap_17));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_17, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_17 *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_2(const emlrtStack *sp, emxArray_cell_wrap_2 **pEmxArray,
                         const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_2 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_2 *)emlrtMallocEmxArray(sizeof(emxArray_cell_wrap_2));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_2, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_2 *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_27(const emlrtStack *sp,
                          emxArray_cell_wrap_27 **pEmxArray,
                          const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_27 *emxArray;
  *pEmxArray = (emxArray_cell_wrap_27 *)emlrtMallocEmxArray(
      sizeof(emxArray_cell_wrap_27));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_27, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_27 *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_cell_wrap_28(const emlrtStack *sp,
                          emxArray_cell_wrap_28 **pEmxArray,
                          const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_28 *emxArray;
  *pEmxArray = (emxArray_cell_wrap_28 *)emlrtMallocEmxArray(
      sizeof(emxArray_cell_wrap_28));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_28, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_28 *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_cell_wrap_29(const emlrtStack *sp,
                          emxArray_cell_wrap_29 **pEmxArray,
                          const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_29 *emxArray;
  *pEmxArray = (emxArray_cell_wrap_29 *)emlrtMallocEmxArray(
      sizeof(emxArray_cell_wrap_29));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_29, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_29 *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3 **pEmxArray,
                         const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_3 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_3 *)emlrtMallocEmxArray(sizeof(emxArray_cell_wrap_3));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_3, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_3 *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_4(const emlrtStack *sp, emxArray_cell_wrap_4 **pEmxArray,
                         const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_4 *emxArray;
  *pEmxArray =
      (emxArray_cell_wrap_4 *)emlrtMallocEmxArray(sizeof(emxArray_cell_wrap_4));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_4, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_4 *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_cell_wrap_5(const emlrtStack *sp, emxArray_cell_wrap_5 **pEmxArray,
                         const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_5 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_5 *)emlrtMallocEmxArray(sizeof(emxArray_cell_wrap_5));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_5, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_5 *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_6(const emlrtStack *sp, emxArray_cell_wrap_6 **pEmxArray,
                         const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_6 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_6 *)emlrtMallocEmxArray(sizeof(emxArray_cell_wrap_6));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_6, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_6 *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_7(const emlrtStack *sp, emxArray_cell_wrap_7 **pEmxArray,
                         const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_7 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_7 *)emlrtMallocEmxArray(sizeof(emxArray_cell_wrap_7));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_7, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_7 *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_9(const emlrtStack *sp, emxArray_cell_wrap_9 **pEmxArray,
                         const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_9 *emxArray;
  *pEmxArray =
      (emxArray_cell_wrap_9 *)emlrtMallocEmxArray(sizeof(emxArray_cell_wrap_9));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_9, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_9 *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray,
                    const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxArray_char_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T *)emlrtMallocEmxArray(sizeof(emxArray_char_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                        (void *)&emxFree_char_T, NULL, NULL,
                                        NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation)
{
  emxArray_creal_T *emxArray;
  *pEmxArray =
      (emxArray_creal_T *)emlrtMallocEmxArray(sizeof(emxArray_creal_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_creal_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (creal_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation)
{
  emxArray_int32_T *emxArray;
  *pEmxArray =
      (emxArray_int32_T *)emlrtMallocEmxArray(sizeof(emxArray_int32_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_int32_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_int8_T(const emlrtStack *sp, emxArray_int8_T **pEmxArray,
                    const emlrtRTEInfo *srcLocation)
{
  emxArray_int8_T *emxArray;
  *pEmxArray = (emxArray_int8_T *)emlrtMallocEmxArray(sizeof(emxArray_int8_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_int8_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (int8_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                    boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocEmxArray(sizeof(emxArray_real_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
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

void emxTrim_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 *emxArray,
                         int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_1(sp, &emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_10(const emlrtStack *sp, emxArray_cell_wrap_10 *emxArray,
                          int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_10(sp, &emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_12(const emlrtStack *sp, emxArray_cell_wrap_12 *emxArray,
                          int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_12(sp, &emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_13(const emlrtStack *sp, emxArray_cell_wrap_13 *emxArray,
                          int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_13(sp, &emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_14(const emlrtStack *sp, emxArray_cell_wrap_14 *emxArray,
                          int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_14(sp, &emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_28(const emlrtStack *sp, emxArray_cell_wrap_28 *emxArray,
                          int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_28(sp, &emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_29(const emlrtStack *sp, emxArray_cell_wrap_29 *emxArray,
                          int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_29(sp, &emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3 *emxArray,
                         int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_3(sp, &emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_5(const emlrtStack *sp, emxArray_cell_wrap_5 *emxArray,
                         int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_5(sp, &emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_6(const emlrtStack *sp, emxArray_cell_wrap_6 *emxArray,
                         int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_6(sp, &emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_7(const emlrtStack *sp, emxArray_cell_wrap_7 *emxArray,
                         int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_7(sp, &emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_9(const emlrtStack *sp, emxArray_cell_wrap_9 *emxArray,
                         int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_9(sp, &emxArray->data[i]);
  }
}

/* End of code generation (reflectivity_calculation_emxutil.c) */
