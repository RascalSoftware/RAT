//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  reflectivity_calculation_gpu_emxutil.cu
//
//  Code generation for function 'reflectivity_calculation_gpu_emxutil'
//


// Include files
#include "reflectivity_calculation_gpu_emxutil.h"
#include "reflectivity_calculation_gpu.h"
#include "reflectivity_calculation_gpu_data.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Declarations
static void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T * const *src);
static void emxExpand_cell_wrap_11(emxArray_cell_wrap_11 *emxArray, int32_T
  fromIndex, int32_T toIndex);
static void emxExpand_cell_wrap_12(emxArray_cell_wrap_12 *emxArray, int32_T
  fromIndex, int32_T toIndex);
static void emxExpand_cell_wrap_14(emxArray_cell_wrap_14 *emxArray, int32_T
  fromIndex, int32_T toIndex);
static void emxExpand_cell_wrap_15(emxArray_cell_wrap_15 *emxArray, int32_T
  fromIndex, int32_T toIndex);
static void emxExpand_cell_wrap_17(emxArray_cell_wrap_17 *emxArray, int32_T
  fromIndex, int32_T toIndex);
static void emxFreeStruct_cell_wrap_11(cell_wrap_11 *pStruct);
static void emxFreeStruct_cell_wrap_12(cell_wrap_12 *pStruct);
static void emxFreeStruct_cell_wrap_17(cell_wrap_17 *pStruct);
static void emxFreeStruct_struct5_T(struct5_T *pStruct);
static void emxInitStruct_cell_wrap_11(cell_wrap_11 *pStruct, boolean_T doPush);
static void emxInitStruct_cell_wrap_12(cell_wrap_12 *pStruct, boolean_T doPush);
static void emxInitStruct_cell_wrap_14(cell_wrap_14 *pStruct);
static void emxInitStruct_cell_wrap_15(cell_wrap_15 *pStruct);
static void emxInitStruct_cell_wrap_17(cell_wrap_17 *pStruct, boolean_T doPush);
static void emxInitStruct_struct5_T(struct5_T *pStruct, boolean_T doPush);
static void emxTrim_cell_wrap_11(emxArray_cell_wrap_11 *emxArray, int32_T
  fromIndex, int32_T toIndex);
static void emxTrim_cell_wrap_12(emxArray_cell_wrap_12 *emxArray, int32_T
  fromIndex, int32_T toIndex);
static void emxTrim_cell_wrap_17(emxArray_cell_wrap_17 *emxArray, int32_T
  fromIndex, int32_T toIndex);

// Function Definitions
static void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T * const *src)
{
  int32_T numElDst;
  int32_T numElSrc;
  int32_T i;
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

static void emxExpand_cell_wrap_11(emxArray_cell_wrap_11 *emxArray, int32_T
  fromIndex, int32_T toIndex)
{
  for (int32_T i = 0; i < toIndex - fromIndex; i++) {
    emxInitStruct_cell_wrap_11(&emxArray->data[fromIndex + i], false);
  }
}

static void emxExpand_cell_wrap_12(emxArray_cell_wrap_12 *emxArray, int32_T
  fromIndex, int32_T toIndex)
{
  for (int32_T i = 0; i < toIndex - fromIndex; i++) {
    emxInitStruct_cell_wrap_12(&emxArray->data[fromIndex + i], false);
  }
}

static void emxExpand_cell_wrap_14(emxArray_cell_wrap_14 *emxArray, int32_T
  fromIndex, int32_T toIndex)
{
  for (int32_T i = 0; i < toIndex - fromIndex; i++) {
    emxInitStruct_cell_wrap_14(&emxArray->data[fromIndex + i]);
  }
}

static void emxExpand_cell_wrap_15(emxArray_cell_wrap_15 *emxArray, int32_T
  fromIndex, int32_T toIndex)
{
  for (int32_T i = 0; i < toIndex - fromIndex; i++) {
    emxInitStruct_cell_wrap_15(&emxArray->data[fromIndex + i]);
  }
}

static void emxExpand_cell_wrap_17(emxArray_cell_wrap_17 *emxArray, int32_T
  fromIndex, int32_T toIndex)
{
  for (int32_T i = 0; i < toIndex - fromIndex; i++) {
    emxInitStruct_cell_wrap_17(&emxArray->data[fromIndex + i], false);
  }
}

static void emxFreeStruct_cell_wrap_11(cell_wrap_11 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

static void emxFreeStruct_cell_wrap_12(cell_wrap_12 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

static void emxFreeStruct_cell_wrap_17(cell_wrap_17 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

static void emxFreeStruct_struct5_T(struct5_T *pStruct)
{
  emxFree_real_T(&pStruct->all_chis);
}

static void emxInitStruct_cell_wrap_11(cell_wrap_11 *pStruct, boolean_T doPush)
{
  emxInit_real_T(&pStruct->f1, 2, doPush);
}

static void emxInitStruct_cell_wrap_12(cell_wrap_12 *pStruct, boolean_T doPush)
{
  emxInit_real_T(&pStruct->f1, 2, doPush);
}

static void emxInitStruct_cell_wrap_14(cell_wrap_14 *pStruct)
{
  pStruct->f1.size[0] = 0;
  pStruct->f1.size[1] = 0;
}

static void emxInitStruct_cell_wrap_15(cell_wrap_15 *pStruct)
{
  pStruct->f1.size[0] = 0;
  pStruct->f1.size[1] = 0;
}

static void emxInitStruct_cell_wrap_17(cell_wrap_17 *pStruct, boolean_T doPush)
{
  emxInit_real_T(&pStruct->f1, 2, doPush);
}

static void emxInitStruct_struct5_T(struct5_T *pStruct, boolean_T doPush)
{
  emxInit_real_T(&pStruct->all_chis, 1, doPush);
}

static void emxTrim_cell_wrap_11(emxArray_cell_wrap_11 *emxArray, int32_T
  fromIndex, int32_T toIndex)
{
  for (int32_T i = 0; i < toIndex - fromIndex; i++) {
    emxFreeStruct_cell_wrap_11(&emxArray->data[fromIndex + i]);
  }
}

static void emxTrim_cell_wrap_12(emxArray_cell_wrap_12 *emxArray, int32_T
  fromIndex, int32_T toIndex)
{
  for (int32_T i = 0; i < toIndex - fromIndex; i++) {
    emxFreeStruct_cell_wrap_12(&emxArray->data[fromIndex + i]);
  }
}

static void emxTrim_cell_wrap_17(emxArray_cell_wrap_17 *emxArray, int32_T
  fromIndex, int32_T toIndex)
{
  for (int32_T i = 0; i < toIndex - fromIndex; i++) {
    emxFreeStruct_cell_wrap_17(&emxArray->data[fromIndex + i]);
  }
}

void emxCopyStruct_cell_wrap_11(cell_wrap_11 *dst, const cell_wrap_11 *src)
{
  emxCopy_real_T(&dst->f1, &src->f1);
}

void emxCopyStruct_cell_wrap_12(cell_wrap_12 *dst, const cell_wrap_12 *src)
{
  emxCopy_real_T(&dst->f1, &src->f1);
}

void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
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

    newData = emlrtCallocMex(static_cast<uint32_T>(i), sizeof(boolean_T));
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

void emxEnsureCapacity_cell_wrap_11(emxArray_cell_wrap_11 *emxArray, int32_T
  oldNumel)
{
  int32_T newNumel;
  int32_T i;
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

    newData = emlrtCallocMex(static_cast<uint32_T>(i), sizeof(cell_wrap_11));
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
  } else {
    if (oldNumel < newNumel) {
      emxExpand_cell_wrap_11(emxArray, oldNumel, newNumel);
    }
  }
}

void emxEnsureCapacity_cell_wrap_12(emxArray_cell_wrap_12 *emxArray, int32_T
  oldNumel)
{
  int32_T newNumel;
  int32_T i;
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

    newData = emlrtCallocMex(static_cast<uint32_T>(i), sizeof(cell_wrap_12));
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
    emxTrim_cell_wrap_12(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_cell_wrap_12(emxArray, oldNumel, newNumel);
    }
  }
}

void emxEnsureCapacity_cell_wrap_14(emxArray_cell_wrap_14 *emxArray, int32_T
  oldNumel)
{
  int32_T newNumel;
  int32_T i;
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

    newData = emlrtCallocMex(static_cast<uint32_T>(i), sizeof(cell_wrap_14));
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
    emxExpand_cell_wrap_14(emxArray, oldNumel, newNumel);
  }
}

void emxEnsureCapacity_cell_wrap_15(emxArray_cell_wrap_15 *emxArray, int32_T
  oldNumel)
{
  int32_T newNumel;
  int32_T i;
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

    newData = emlrtCallocMex(static_cast<uint32_T>(i), sizeof(cell_wrap_15));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_15) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }

    emxArray->data = (cell_wrap_15 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxExpand_cell_wrap_15(emxArray, oldNumel, newNumel);
  }
}

void emxEnsureCapacity_cell_wrap_17(emxArray_cell_wrap_17 *emxArray, int32_T
  oldNumel)
{
  int32_T newNumel;
  int32_T i;
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

    newData = emlrtCallocMex(static_cast<uint32_T>(i), sizeof(cell_wrap_17));
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

  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_17(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_cell_wrap_17(emxArray, oldNumel, newNumel);
    }
  }
}

void emxEnsureCapacity_creal_T(emxArray_creal_T *emxArray, int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
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

    newData = emlrtCallocMex(static_cast<uint32_T>(i), sizeof(creal_T));
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

void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
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

    newData = emlrtCallocMex(static_cast<uint32_T>(i), sizeof(int32_T));
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

void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
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

    newData = emlrtCallocMex(static_cast<uint32_T>(i), sizeof(int8_T));
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

void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
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

    newData = emlrtCallocMex(static_cast<uint32_T>(i), sizeof(real_T));
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

void emxFreeStruct_cell_13(cell_13 *pStruct)
{
  emxFree_cell_wrap_11(&pStruct->f1);
  emxFree_cell_wrap_11(&pStruct->f2);
  emxFree_cell_wrap_12(&pStruct->f3);
  emxFree_cell_wrap_12(&pStruct->f4);
  emxFree_cell_wrap_11(&pStruct->f5);
  emxFree_real_T(&pStruct->f6);
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
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

void emxFree_cell_wrap_11(emxArray_cell_wrap_11 **pEmxArray)
{
  int32_T numEl;
  if (*pEmxArray != (emxArray_cell_wrap_11 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_11 *)NULL) {
      int32_T i;
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

void emxFree_cell_wrap_12(emxArray_cell_wrap_12 **pEmxArray)
{
  int32_T numEl;
  if (*pEmxArray != (emxArray_cell_wrap_12 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_12 *)NULL) {
      int32_T i;
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_12(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_12 *)NULL;
  }
}

void emxFree_cell_wrap_14(emxArray_cell_wrap_14 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_14 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_14 *)NULL) && (*pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_14 *)NULL;
  }
}

void emxFree_cell_wrap_15(emxArray_cell_wrap_15 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_15 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_15 *)NULL) && (*pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_15 *)NULL;
  }
}

void emxFree_cell_wrap_17(emxArray_cell_wrap_17 **pEmxArray)
{
  int32_T numEl;
  if (*pEmxArray != (emxArray_cell_wrap_17 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_17 *)NULL) {
      int32_T i;
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_17(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_17 *)NULL;
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

void emxFree_int8_T(emxArray_int8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int8_T *)NULL) {
    if (((*pEmxArray)->data != (int8_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_int8_T *)NULL;
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

void emxInitStruct_cell_13(cell_13 *pStruct, boolean_T doPush)
{
  emxInit_cell_wrap_11(&pStruct->f1, 1, doPush);
  emxInit_cell_wrap_11(&pStruct->f2, 1, doPush);
  emxInit_cell_wrap_12(&pStruct->f3, 1, doPush);
  emxInit_cell_wrap_12(&pStruct->f4, 1, doPush);
  emxInit_cell_wrap_11(&pStruct->f5, 1, doPush);
  emxInit_real_T(&pStruct->f6, 1, doPush);
}

void emxInitStruct_struct4_T(struct4_T *pStruct, boolean_T doPush)
{
  emxInit_real_T(&pStruct->ssubs, 1, doPush);
  emxInit_real_T(&pStruct->backgrounds, 1, doPush);
  emxInit_real_T(&pStruct->qshifts, 1, doPush);
  emxInit_real_T(&pStruct->scalefactors, 1, doPush);
  emxInit_real_T(&pStruct->nbairs, 1, doPush);
  emxInit_real_T(&pStruct->nbsubs, 1, doPush);
  emxInit_real_T(&pStruct->resolutions, 1, doPush);
  emxInitStruct_struct5_T(&pStruct->calculations, doPush);
  emxInit_real_T(&pStruct->allSubRough, 1, doPush);
}

void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T numDimensions,
  boolean_T doPush)
{
  emxArray_boolean_T *emxArray;
  *pEmxArray = (emxArray_boolean_T *)emlrtMallocMex(sizeof(emxArray_boolean_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(emlrtRootTLSGlobal, (void *)pEmxArray,
      (void *)&emxFree_boolean_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_11(emxArray_cell_wrap_11 **pEmxArray, int32_T
  numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_11 *emxArray;
  *pEmxArray = (emxArray_cell_wrap_11 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_11));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(emlrtRootTLSGlobal, (void *)pEmxArray,
      (void *)&emxFree_cell_wrap_11);
  }

  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_11 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_12(emxArray_cell_wrap_12 **pEmxArray, int32_T
  numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_12 *emxArray;
  *pEmxArray = (emxArray_cell_wrap_12 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_12));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(emlrtRootTLSGlobal, (void *)pEmxArray,
      (void *)&emxFree_cell_wrap_12);
  }

  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_12 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_14(emxArray_cell_wrap_14 **pEmxArray, int32_T
  numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_14 *emxArray;
  *pEmxArray = (emxArray_cell_wrap_14 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_14));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(emlrtRootTLSGlobal, (void *)pEmxArray,
      (void *)&emxFree_cell_wrap_14);
  }

  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_14 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_15(emxArray_cell_wrap_15 **pEmxArray, int32_T
  numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_15 *emxArray;
  *pEmxArray = (emxArray_cell_wrap_15 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_15));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(emlrtRootTLSGlobal, (void *)pEmxArray,
      (void *)&emxFree_cell_wrap_15);
  }

  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_15 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_17(emxArray_cell_wrap_17 **pEmxArray, int32_T
  numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_17 *emxArray;
  *pEmxArray = (emxArray_cell_wrap_17 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_17));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(emlrtRootTLSGlobal, (void *)pEmxArray,
      (void *)&emxFree_cell_wrap_17);
  }

  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_17 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_creal_T(emxArray_creal_T **pEmxArray, int32_T numDimensions,
                     boolean_T doPush)
{
  emxArray_creal_T *emxArray;
  *pEmxArray = (emxArray_creal_T *)emlrtMallocMex(sizeof(emxArray_creal_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(emlrtRootTLSGlobal, (void *)pEmxArray,
      (void *)&emxFree_creal_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (creal_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions,
                     boolean_T doPush)
{
  emxArray_int32_T *emxArray;
  *pEmxArray = (emxArray_int32_T *)emlrtMallocMex(sizeof(emxArray_int32_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(emlrtRootTLSGlobal, (void *)pEmxArray,
      (void *)&emxFree_int32_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_int8_T(emxArray_int8_T **pEmxArray, int32_T numDimensions,
                    boolean_T doPush)
{
  emxArray_int8_T *emxArray;
  *pEmxArray = (emxArray_int8_T *)emlrtMallocMex(sizeof(emxArray_int8_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(emlrtRootTLSGlobal, (void *)pEmxArray,
      (void *)&emxFree_int8_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (int8_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions,
                    boolean_T doPush)
{
  emxArray_real_T *emxArray;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(emlrtRootTLSGlobal, (void *)pEmxArray,
      (void *)&emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

// End of code generation (reflectivity_calculation_gpu_emxutil.cu)
