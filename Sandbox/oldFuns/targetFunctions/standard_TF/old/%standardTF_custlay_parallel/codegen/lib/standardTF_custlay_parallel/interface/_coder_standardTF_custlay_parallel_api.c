/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_standardTF_custlay_parallel_api.c
 *
 * Code generation for function '_coder_standardTF_custlay_parallel_api'
 *
 */

/* Include files */
#include "tmwtypes.h"
#include "_coder_standardTF_custlay_parallel_api.h"
#include "_coder_standardTF_custlay_parallel_mex.h"

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray__common*/

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif                                 /*typedef_emxArray__common*/

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131435U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "standardTF_custlay_parallel",       /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *b_emlrt_marshallOut(const emxArray_cell_wrap_3 *u);
static real_T bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *numberOfContrasts, const char_T *identifier);
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *d_emlrt_marshallOut(const emxArray_cell_wrap_3 *u);
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *geometry,
  const char_T *identifier, emxArray_char_T *y);
static const mxArray *e_emlrt_marshallOut(const emxArray_cell_wrap_1 *u);
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *resam, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize);
static void emxEnsureCapacity_cell_wrap_1(const emlrtStack *sp,
  emxArray_cell_wrap_1 *emxArray, int32_T oldNumel);
static void emxExpand_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1
  *emxArray, int32_T fromIndex, int32_T toIndex);
static void emxFreeStruct_cell_wrap_1(cell_wrap_1 *pStruct);
static void emxFreeStruct_cell_wrap_3(cell_wrap_3 *pStruct);
static void emxFreeStruct_cell_wrap_4(cell_wrap_4 *pStruct);
static void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray);
static void emxFree_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray);
static void emxFree_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray);
static void emxFree_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray);
static void emxFree_cell_wrap_4(emxArray_cell_wrap_4 **pEmxArray);
static void emxFree_char_T(emxArray_char_T **pEmxArray);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInitStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *pStruct,
  boolean_T doPush);
static void emxInit_cell_wrap_0(const emlrtStack *sp, emxArray_cell_wrap_0
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_cell_wrap_2(const emlrtStack *sp, emxArray_cell_wrap_2
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_cell_wrap_4(const emlrtStack *sp, emxArray_cell_wrap_4
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void emxInit_real_T1(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void emxTrim_cell_wrap_1(emxArray_cell_wrap_1 *emxArray, int32_T
  fromIndex, int32_T toIndex);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y);
static const mxArray *f_emlrt_marshallOut(const emxArray_real_T *u);
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nbairs,
  const char_T *identifier, emxArray_real_T *y);
static const mxArray *g_emlrt_marshallOut(const emxArray_cell_wrap_1 *u);
static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *h_emlrt_marshallOut(const emxArray_cell_wrap_3 *u);
static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *repeats,
  const char_T *identifier, emxArray_cell_wrap_0 *y);
static const mxArray *i_emlrt_marshallOut(const emlrtStack *sp, const
  emxArray_cell_wrap_4 *u);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_0 *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *allData,
  const char_T *identifier, emxArray_cell_wrap_1 *y);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_1 *y);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *dataLimits,
  const char_T *identifier, emxArray_cell_wrap_0 *y);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_0 *y);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *simLimits,
  const char_T *identifier, emxArray_cell_wrap_0 *y);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_0 *y);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *repeatLayers,
  const char_T *identifier, emxArray_cell_wrap_0 *y);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_0 *y);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *contrastLayers, const char_T *identifier, emxArray_cell_wrap_2 *y);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_2 *y);
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *layersDetails, const char_T *identifier);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[1] = { -1 };

  boolean_T bv6[1] = { true };

  int32_T iv7[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv6[0],
    iv7);
  ret->size[0] = iv7[0];
  ret->allocatedSize = ret->size[0];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_cell_wrap_3 *u)
{
  const mxArray *y;
  int32_T i6;
  int32_T n;
  const cell_wrap_3 *r0;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, *(int32_T (*)[2])u->size));
  i6 = 0;
  n = u->size[0];
  while (i6 < n) {
    r0 = &u->data[i6];
    emlrtSetCell(y, i6, c_emlrt_marshallOut(r0->f1));
    i6++;
  }

  return y;
}

static real_T bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *numberOfContrasts, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(numberOfContrasts), &thisId);
  emlrtDestroyArray(&numberOfContrasts);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m1;
  real_T *pData;
  int32_T i7;
  int32_T i;
  int32_T b_i;
  y = NULL;
  m1 = emlrtCreateNumericArray(2, *(int32_T (*)[1])u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = (real_T *)mxGetPr(m1);
  i7 = 0;
  for (i = 0; i < 2; i++) {
    for (b_i = 0; b_i < u->size[0]; b_i++) {
      pData[i7] = u->data[b_i + u->size[0] * i];
      i7++;
    }
  }

  emlrtAssign(&y, m1);
  return y;
}

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  boolean_T bv7[2] = { false, true };

  int32_T iv8[2];
  int32_T i15;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims, &bv7[0],
    iv8);
  i15 = ret->size[0] * ret->size[1];
  ret->size[0] = iv8[0];
  ret->size[1] = iv8[1];
  emxEnsureCapacity((emxArray__common *)ret, i15, (int32_T)sizeof(char_T));
  emlrtImportArrayR2015b(sp, src, ret->data, 1, false);
  emlrtDestroyArray(&src);
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *d_emlrt_marshallOut(const emxArray_cell_wrap_3 *u)
{
  const mxArray *y;
  int32_T i8;
  int32_T n;
  const cell_wrap_3 *r1;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, *(int32_T (*)[2])u->size));
  i8 = 0;
  n = u->size[0];
  while (i8 < n) {
    r1 = &u->data[i8];
    emlrtSetCell(y, i8, c_emlrt_marshallOut(r1->f1));
    i8++;
  }

  return y;
}

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  boolean_T bv8[2] = { false, true };

  int32_T iv9[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv8[0],
    iv9);
  ret->size[0] = iv9[0];
  ret->size[1] = iv9[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *geometry,
  const char_T *identifier, emxArray_char_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(geometry), &thisId, y);
  emlrtDestroyArray(&geometry);
}

static const mxArray *e_emlrt_marshallOut(const emxArray_cell_wrap_1 *u)
{
  const mxArray *y;
  int32_T i9;
  int32_T n;
  const cell_wrap_1 *r2;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, *(int32_T (*)[2])u->size));
  i9 = 0;
  n = u->size[0];
  while (i9 < n) {
    r2 = &u->data[i9];
    emlrtSetCell(y, i9, f_emlrt_marshallOut(r2->f1));
    i9++;
  }

  return y;
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2] = { 1, 2 };

  int32_T i16;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i16 = 0; i16 < 2; i16++) {
    ret[i16] = (*(real_T (*)[2])mxGetData(src))[i16];
  }

  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *resam, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(resam), &thisId, y);
  emlrtDestroyArray(&resam);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv6[1] = { 0 };

  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv6, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m0, u->size, 1);
  emlrtAssign(&y, m0);
  return y;
}

static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize)
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

    newData = emlrtCallocMex((uint32_T)i, (uint32_T)elementSize);
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, (uint32_T)(elementSize * oldNumel));
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }

    emxArray->data = newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void emxEnsureCapacity_cell_wrap_1(const emlrtStack *sp,
  emxArray_cell_wrap_1 *emxArray, int32_T oldNumel)
{
  int32_T elementSize;
  int32_T newNumel;
  int32_T i;
  void *newData;
  elementSize = (int32_T)sizeof(cell_wrap_1);
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

    newData = emlrtCallocMex((uint32_T)i, (uint32_T)elementSize);
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, (uint32_T)(elementSize * oldNumel));
      if (emxArray->canFreeData) {
        emlrtFreeMex((void *)emxArray->data);
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
      emxExpand_cell_wrap_1(sp, emxArray, oldNumel, newNumel);
    }
  }
}

static void emxExpand_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1
  *emxArray, int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_1(sp, &emxArray->data[i], false);
  }
}

static void emxFreeStruct_cell_wrap_1(cell_wrap_1 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

static void emxFreeStruct_cell_wrap_3(cell_wrap_3 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

static void emxFreeStruct_cell_wrap_4(cell_wrap_4 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

static void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_0 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_0 *)NULL) && (*pEmxArray)->canFreeData)
    {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_0 *)NULL;
  }
}

static void emxFree_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray)
{
  int32_T numEl;
  int32_T i;
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
        emlrtFreeMex((void *)(*pEmxArray)->data);
      }
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_1 *)NULL;
  }
}

static void emxFree_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_2 *)NULL) {
    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_2 *)NULL;
  }
}

static void emxFree_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray)
{
  int32_T numEl;
  int32_T i;
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
        emlrtFreeMex((void *)(*pEmxArray)->data);
      }
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_3 *)NULL;
  }
}

static void emxFree_cell_wrap_4(emxArray_cell_wrap_4 **pEmxArray)
{
  int32_T numEl;
  int32_T i;
  if (*pEmxArray != (emxArray_cell_wrap_4 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_4 *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_4(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((void *)(*pEmxArray)->data);
      }
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_4 *)NULL;
  }
}

static void emxFree_char_T(emxArray_char_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_char_T *)NULL;
  }
}

static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

static void emxInitStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *pStruct,
  boolean_T doPush)
{
  emxInit_real_T1(sp, &pStruct->f1, 2, doPush);
}

static void emxInit_cell_wrap_0(const emlrtStack *sp, emxArray_cell_wrap_0
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_0 *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_cell_wrap_0 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_0));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_cell_wrap_0);
  }

  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_0 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_1 *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_cell_wrap_1 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_1));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_cell_wrap_1);
  }

  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_1 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_cell_wrap_2(const emlrtStack *sp, emxArray_cell_wrap_2
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_2 *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_cell_wrap_2 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_2));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_cell_wrap_2);
  }

  emxArray = *pEmxArray;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_3 *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_cell_wrap_3 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_3));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_cell_wrap_3);
  }

  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_3 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_cell_wrap_4(const emlrtStack *sp, emxArray_cell_wrap_4
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_4 *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_cell_wrap_4 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_4));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_cell_wrap_4);
  }

  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_4 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_char_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T *)emlrtMallocMex(sizeof(emxArray_char_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_char_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_real_T1(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxTrim_cell_wrap_1(emxArray_cell_wrap_1 *emxArray, int32_T
  fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_1(&emxArray->data[i]);
  }
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y)
{
  cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *f_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m2;
  real_T *pData;
  int32_T i10;
  int32_T i;
  int32_T b_i;
  y = NULL;
  m2 = emlrtCreateNumericArray(2, *(int32_T (*)[1])u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = (real_T *)mxGetPr(m2);
  i10 = 0;
  for (i = 0; i < 3; i++) {
    for (b_i = 0; b_i < u->size[0]; b_i++) {
      pData[i10] = u->data[b_i + u->size[0] * i];
      i10++;
    }
  }

  emlrtAssign(&y, m2);
  return y;
}

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, 3 };

  boolean_T bv9[2] = { true, false };

  int32_T iv10[2];
  int32_T i17;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv9[0],
    iv10);
  i17 = ret->size[0] * ret->size[1];
  ret->size[0] = iv10[0];
  ret->size[1] = iv10[1];
  emxEnsureCapacity((emxArray__common *)ret, i17, (int32_T)sizeof(real_T));
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nbairs,
  const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(nbairs), &thisId, y);
  emlrtDestroyArray(&nbairs);
}

static const mxArray *g_emlrt_marshallOut(const emxArray_cell_wrap_1 *u)
{
  const mxArray *y;
  int32_T i11;
  int32_T n;
  const cell_wrap_1 *r3;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, *(int32_T (*)[2])u->size));
  i11 = 0;
  n = u->size[0];
  while (i11 < n) {
    r3 = &u->data[i11];
    emlrtSetCell(y, i11, f_emlrt_marshallOut(r3->f1));
    i11++;
  }

  return y;
}

static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 1, 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  emlrtDestroyArray(&src);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  db_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *h_emlrt_marshallOut(const emxArray_cell_wrap_3 *u)
{
  const mxArray *y;
  int32_T i12;
  int32_T n;
  const cell_wrap_3 *r4;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, *(int32_T (*)[2])u->size));
  i12 = 0;
  n = u->size[0];
  while (i12 < n) {
    r4 = &u->data[i12];
    emlrtSetCell(y, i12, c_emlrt_marshallOut(r4->f1));
    i12++;
  }

  return y;
}

static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtDestroyArray(&src);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *repeats,
  const char_T *identifier, emxArray_cell_wrap_0 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(repeats), &thisId, y);
  emlrtDestroyArray(&repeats);
}

static const mxArray *i_emlrt_marshallOut(const emlrtStack *sp, const
  emxArray_cell_wrap_4 *u)
{
  const mxArray *y;
  emxArray_real_T *b_u;
  int32_T i13;
  int32_T n;
  emxArray_real_T *r5;
  const cell_wrap_4 *r6;
  int32_T i14;
  int32_T loop_ub;
  int32_T i;
  const mxArray *b_y;
  const mxArray *m3;
  real_T *pData;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T1(sp, &b_u, 2, true);
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, *(int32_T (*)[2])u->size));
  i13 = 0;
  n = u->size[0];
  emxInit_real_T(sp, &r5, 1, true);
  while (i13 < n) {
    r6 = &u->data[i13];
    i14 = b_u->size[0] * b_u->size[1];
    b_u->size[0] = r6->f1->size[0];
    b_u->size[1] = r6->f1->size[1];
    emxEnsureCapacity((emxArray__common *)b_u, i14, (int32_T)sizeof(real_T));
    i14 = r6->f1->size[0];
    loop_ub = r6->f1->size[1];
    i = r5->size[0];
    r5->size[0] = i14 * loop_ub;
    emxEnsureCapacity((emxArray__common *)r5, i, (int32_T)sizeof(real_T));
    loop_ub *= i14;
    for (i14 = 0; i14 < loop_ub; i14++) {
      r5->data[i14] = r6->f1->data[i14];
    }

    loop_ub = r5->size[0];
    for (i14 = 0; i14 < loop_ub; i14++) {
      b_u->data[i14] = r5->data[i14];
    }

    b_y = NULL;
    m3 = emlrtCreateNumericArray(2, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
      mxREAL);
    pData = (real_T *)mxGetPr(m3);
    i14 = 0;
    for (loop_ub = 0; loop_ub < b_u->size[1]; loop_ub++) {
      for (i = 0; i < b_u->size[0]; i++) {
        pData[i14] = b_u->data[i + b_u->size[0] * loop_ub];
        i14++;
      }
    }

    emlrtAssign(&b_y, m3);
    emlrtSetCell(y, i13, b_y);
    i13++;
  }

  emxFree_real_T(&r5);
  emxFree_real_T(&b_u);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_0 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv0[2];
  int32_T i0;
  static const boolean_T bv0[2] = { false, true };

  int32_T sizes[2];
  int32_T n;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (i0 = 0; i0 < 2; i0++) {
    iv0[i0] = 1 + -2 * i0;
  }

  emlrtCheckVsCell(sp, parentId, u, 2U, iv0, bv0, sizes);
  i0 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity((emxArray__common *)y, i0, (int32_T)sizeof(cell_wrap_0));
  n = y->size[1];
  for (i0 = 0; i0 < n; i0++) {
    sprintf(&str[0], "%d", i0 + 1);
    thisId.fIdentifier = &str[0];
    k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i0)),
                       &thisId, y->data[i0].f1);
  }

  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *allData,
  const char_T *identifier, emxArray_cell_wrap_1 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  m_emlrt_marshallIn(sp, emlrtAlias(allData), &thisId, y);
  emlrtDestroyArray(&allData);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_1 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv1[2];
  int32_T i1;
  static const boolean_T bv1[2] = { false, true };

  int32_T sizes[2];
  int32_T n;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (i1 = 0; i1 < 2; i1++) {
    iv1[i1] = 1 + -2 * i1;
  }

  emlrtCheckVsCell(sp, parentId, u, 2U, iv1, bv1, sizes);
  i1 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_cell_wrap_1(sp, y, i1);
  n = y->size[1];
  for (i1 = 0; i1 < n; i1++) {
    sprintf(&str[0], "%d", i1 + 1);
    thisId.fIdentifier = &str[0];
    n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i1)),
                       &thisId, y->data[i1].f1);
  }

  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  fb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *dataLimits,
  const char_T *identifier, emxArray_cell_wrap_0 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  p_emlrt_marshallIn(sp, emlrtAlias(dataLimits), &thisId, y);
  emlrtDestroyArray(&dataLimits);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_0 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv2[2];
  int32_T i2;
  static const boolean_T bv2[2] = { false, true };

  int32_T sizes[2];
  int32_T n;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (i2 = 0; i2 < 2; i2++) {
    iv2[i2] = 1 + -2 * i2;
  }

  emlrtCheckVsCell(sp, parentId, u, 2U, iv2, bv2, sizes);
  i2 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity((emxArray__common *)y, i2, (int32_T)sizeof(cell_wrap_0));
  n = y->size[1];
  for (i2 = 0; i2 < n; i2++) {
    sprintf(&str[0], "%d", i2 + 1);
    thisId.fIdentifier = &str[0];
    k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i2)),
                       &thisId, y->data[i2].f1);
  }

  emlrtDestroyArray(&u);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *simLimits,
  const char_T *identifier, emxArray_cell_wrap_0 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  r_emlrt_marshallIn(sp, emlrtAlias(simLimits), &thisId, y);
  emlrtDestroyArray(&simLimits);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_0 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv3[2];
  int32_T i3;
  static const boolean_T bv3[2] = { false, true };

  int32_T sizes[2];
  int32_T n;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (i3 = 0; i3 < 2; i3++) {
    iv3[i3] = 1 + -2 * i3;
  }

  emlrtCheckVsCell(sp, parentId, u, 2U, iv3, bv3, sizes);
  i3 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity((emxArray__common *)y, i3, (int32_T)sizeof(cell_wrap_0));
  n = y->size[1];
  for (i3 = 0; i3 < n; i3++) {
    sprintf(&str[0], "%d", i3 + 1);
    thisId.fIdentifier = &str[0];
    k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i3)),
                       &thisId, y->data[i3].f1);
  }

  emlrtDestroyArray(&u);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *repeatLayers,
  const char_T *identifier, emxArray_cell_wrap_0 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  t_emlrt_marshallIn(sp, emlrtAlias(repeatLayers), &thisId, y);
  emlrtDestroyArray(&repeatLayers);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_0 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv4[2];
  int32_T i4;
  static const boolean_T bv4[2] = { false, true };

  int32_T sizes[2];
  int32_T n;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (i4 = 0; i4 < 2; i4++) {
    iv4[i4] = 1 + -2 * i4;
  }

  emlrtCheckVsCell(sp, parentId, u, 2U, iv4, bv4, sizes);
  i4 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity((emxArray__common *)y, i4, (int32_T)sizeof(cell_wrap_0));
  n = y->size[1];
  for (i4 = 0; i4 < n; i4++) {
    sprintf(&str[0], "%d", i4 + 1);
    thisId.fIdentifier = &str[0];
    k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i4)),
                       &thisId, y->data[i4].f1);
  }

  emlrtDestroyArray(&u);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *contrastLayers, const char_T *identifier, emxArray_cell_wrap_2 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  v_emlrt_marshallIn(sp, emlrtAlias(contrastLayers), &thisId, y);
  emlrtDestroyArray(&contrastLayers);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_2 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv5[2];
  int32_T i5;
  static const boolean_T bv5[2] = { false, true };

  int32_T sizes[2];
  int32_T n;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (i5 = 0; i5 < 2; i5++) {
    iv5[i5] = 1 + -2 * i5;
  }

  emlrtCheckVsCell(sp, parentId, u, 2U, iv5, bv5, sizes);
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  n = y->size[1];
  for (i5 = 0; i5 < n; i5++) {
    sprintf(&str[0], "%d", i5 + 1);
    thisId.fIdentifier = &str[0];
    w_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i5)),
                       &thisId);
  }

  emlrtDestroyArray(&u);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  gb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *layersDetails, const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y_emlrt_marshallIn(sp, emlrtAlias(layersDetails), &thisId);
  emlrtDestroyArray(&layersDetails);
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  hb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

void standardTF_custlay_parallel_api(const mxArray *prhs[31], const mxArray
  *plhs[15])
{
  emxArray_real_T *resam;
  emxArray_char_T *geometry;
  emxArray_real_T *nbairs;
  emxArray_real_T *nbsubs;
  emxArray_cell_wrap_0 *repeats;
  emxArray_real_T *cBacks;
  emxArray_real_T *cShifts;
  emxArray_real_T *cScales;
  emxArray_real_T *cNbas;
  emxArray_real_T *cNbss;
  emxArray_real_T *cRes;
  emxArray_real_T *backs;
  emxArray_real_T *shifts;
  emxArray_real_T *sf;
  emxArray_real_T *nba;
  emxArray_real_T *nbs;
  emxArray_real_T *res;
  emxArray_real_T *dataPresent;
  emxArray_cell_wrap_1 *allData;
  emxArray_cell_wrap_0 *dataLimits;
  emxArray_cell_wrap_0 *simLimits;
  emxArray_cell_wrap_0 *repeatLayers;
  emxArray_real_T *params;
  emxArray_cell_wrap_2 *contrastLayers;
  emxArray_char_T *fileHandle;
  emxArray_char_T *path;
  emxArray_real_T *outSsubs;
  emxArray_real_T *backgs;
  emxArray_real_T *qshifts;
  emxArray_real_T *sfs;
  emxArray_real_T *nbas;
  emxArray_real_T *nbss;
  emxArray_real_T *resols;
  emxArray_real_T *chis;
  emxArray_cell_wrap_3 *reflectivity;
  emxArray_cell_wrap_3 *Simulation;
  emxArray_cell_wrap_1 *shifted_data;
  emxArray_cell_wrap_1 *layerSlds;
  emxArray_cell_wrap_3 *sldProfiles;
  emxArray_cell_wrap_4 *allLayers;
  emxArray_real_T *allRoughs;
  real_T numberOfContrasts;
  real_T nParams;
  real_T numberOfLayers;
  real_T whichType;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &resam, 1, true);
  emxInit_char_T(&st, &geometry, 2, true);
  emxInit_real_T1(&st, &nbairs, 2, true);
  emxInit_real_T1(&st, &nbsubs, 2, true);
  emxInit_cell_wrap_0(&st, &repeats, 2, true);
  emxInit_real_T1(&st, &cBacks, 2, true);
  emxInit_real_T1(&st, &cShifts, 2, true);
  emxInit_real_T1(&st, &cScales, 2, true);
  emxInit_real_T1(&st, &cNbas, 2, true);
  emxInit_real_T1(&st, &cNbss, 2, true);
  emxInit_real_T1(&st, &cRes, 2, true);
  emxInit_real_T1(&st, &backs, 2, true);
  emxInit_real_T1(&st, &shifts, 2, true);
  emxInit_real_T1(&st, &sf, 2, true);
  emxInit_real_T1(&st, &nba, 2, true);
  emxInit_real_T1(&st, &nbs, 2, true);
  emxInit_real_T1(&st, &res, 2, true);
  emxInit_real_T1(&st, &dataPresent, 2, true);
  emxInit_cell_wrap_1(&st, &allData, 2, true);
  emxInit_cell_wrap_0(&st, &dataLimits, 2, true);
  emxInit_cell_wrap_0(&st, &simLimits, 2, true);
  emxInit_cell_wrap_0(&st, &repeatLayers, 2, true);
  emxInit_real_T1(&st, &params, 2, true);
  emxInit_cell_wrap_2(&st, &contrastLayers, 2, true);
  emxInit_char_T(&st, &fileHandle, 2, true);
  emxInit_char_T(&st, &path, 2, true);
  emxInit_real_T(&st, &outSsubs, 1, true);
  emxInit_real_T(&st, &backgs, 1, true);
  emxInit_real_T(&st, &qshifts, 1, true);
  emxInit_real_T(&st, &sfs, 1, true);
  emxInit_real_T(&st, &nbas, 1, true);
  emxInit_real_T(&st, &nbss, 1, true);
  emxInit_real_T(&st, &resols, 1, true);
  emxInit_real_T(&st, &chis, 1, true);
  emxInit_cell_wrap_3(&st, &reflectivity, 2, true);
  emxInit_cell_wrap_3(&st, &Simulation, 2, true);
  emxInit_cell_wrap_1(&st, &shifted_data, 2, true);
  emxInit_cell_wrap_1(&st, &layerSlds, 2, true);
  emxInit_cell_wrap_3(&st, &sldProfiles, 2, true);
  emxInit_cell_wrap_4(&st, &allLayers, 2, true);
  emxInit_real_T(&st, &allRoughs, 1, true);
  prhs[0] = emlrtProtectR2012b(prhs[0], 0, false, -1);
  prhs[3] = emlrtProtectR2012b(prhs[3], 3, false, -1);
  prhs[4] = emlrtProtectR2012b(prhs[4], 4, false, -1);
  prhs[6] = emlrtProtectR2012b(prhs[6], 6, false, -1);
  prhs[7] = emlrtProtectR2012b(prhs[7], 7, false, -1);
  prhs[8] = emlrtProtectR2012b(prhs[8], 8, false, -1);
  prhs[9] = emlrtProtectR2012b(prhs[9], 9, false, -1);
  prhs[10] = emlrtProtectR2012b(prhs[10], 10, false, -1);
  prhs[11] = emlrtProtectR2012b(prhs[11], 11, false, -1);
  prhs[12] = emlrtProtectR2012b(prhs[12], 12, false, -1);
  prhs[13] = emlrtProtectR2012b(prhs[13], 13, false, -1);
  prhs[14] = emlrtProtectR2012b(prhs[14], 14, false, -1);
  prhs[15] = emlrtProtectR2012b(prhs[15], 15, false, -1);
  prhs[16] = emlrtProtectR2012b(prhs[16], 16, false, -1);
  prhs[17] = emlrtProtectR2012b(prhs[17], 17, false, -1);
  prhs[18] = emlrtProtectR2012b(prhs[18], 18, false, -1);
  prhs[24] = emlrtProtectR2012b(prhs[24], 24, false, -1);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "resam", resam);
  numberOfContrasts = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]),
    "numberOfContrasts");
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "geometry", geometry);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "nbairs", nbairs);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "nbsubs", nbsubs);
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "repeats", repeats);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "cBacks", cBacks);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "cShifts", cShifts);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "cScales", cScales);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "cNbas", cNbas);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "cNbss", cNbss);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[11]), "cRes", cRes);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[12]), "backs", backs);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[13]), "shifts", shifts);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[14]), "sf", sf);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[15]), "nba", nba);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[16]), "nbs", nbs);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[17]), "res", res);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[18]), "dataPresent", dataPresent);
  l_emlrt_marshallIn(&st, emlrtAliasP(prhs[19]), "allData", allData);
  o_emlrt_marshallIn(&st, emlrtAliasP(prhs[20]), "dataLimits", dataLimits);
  q_emlrt_marshallIn(&st, emlrtAliasP(prhs[21]), "simLimits", simLimits);
  s_emlrt_marshallIn(&st, emlrtAliasP(prhs[22]), "repeatLayers", repeatLayers);
  nParams = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[23]), "nParams");
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[24]), "params", params);
  u_emlrt_marshallIn(&st, emlrtAliasP(prhs[25]), "contrastLayers",
                     contrastLayers);
  numberOfLayers = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[26]),
    "numberOfLayers");
  x_emlrt_marshallIn(&st, emlrtAliasP(prhs[27]), "layersDetails");
  whichType = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[28]), "whichType");
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[29]), "fileHandle", fileHandle);
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[30]), "path", path);

  /* Invoke the target function */
  standardTF_custlay_parallel(resam, numberOfContrasts, geometry, nbairs, nbsubs,
    repeats, cBacks, cShifts, cScales, cNbas, cNbss, cRes, backs, shifts, sf,
    nba, nbs, res, dataPresent, allData, dataLimits, simLimits, repeatLayers,
    nParams, params, contrastLayers, numberOfLayers, whichType, fileHandle, path,
    outSsubs, backgs, qshifts, sfs, nbas, nbss, resols, chis, reflectivity,
    Simulation, shifted_data, layerSlds, sldProfiles, allLayers, allRoughs);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(outSsubs);
  plhs[1] = emlrt_marshallOut(backgs);
  plhs[2] = emlrt_marshallOut(qshifts);
  plhs[3] = emlrt_marshallOut(sfs);
  plhs[4] = emlrt_marshallOut(nbas);
  plhs[5] = emlrt_marshallOut(nbss);
  plhs[6] = emlrt_marshallOut(resols);
  plhs[7] = emlrt_marshallOut(chis);
  plhs[8] = b_emlrt_marshallOut(reflectivity);
  plhs[9] = d_emlrt_marshallOut(Simulation);
  plhs[10] = e_emlrt_marshallOut(shifted_data);
  plhs[11] = g_emlrt_marshallOut(layerSlds);
  plhs[12] = h_emlrt_marshallOut(sldProfiles);
  plhs[13] = i_emlrt_marshallOut(&st, allLayers);
  plhs[14] = emlrt_marshallOut(allRoughs);
  allRoughs->canFreeData = false;
  emxFree_real_T(&allRoughs);
  emxFree_cell_wrap_4(&allLayers);
  emxFree_cell_wrap_3(&sldProfiles);
  emxFree_cell_wrap_1(&layerSlds);
  emxFree_cell_wrap_1(&shifted_data);
  emxFree_cell_wrap_3(&Simulation);
  emxFree_cell_wrap_3(&reflectivity);
  chis->canFreeData = false;
  emxFree_real_T(&chis);
  resols->canFreeData = false;
  emxFree_real_T(&resols);
  nbss->canFreeData = false;
  emxFree_real_T(&nbss);
  nbas->canFreeData = false;
  emxFree_real_T(&nbas);
  sfs->canFreeData = false;
  emxFree_real_T(&sfs);
  qshifts->canFreeData = false;
  emxFree_real_T(&qshifts);
  backgs->canFreeData = false;
  emxFree_real_T(&backgs);
  outSsubs->canFreeData = false;
  emxFree_real_T(&outSsubs);
  emxFree_char_T(&path);
  emxFree_char_T(&fileHandle);
  emxFree_cell_wrap_2(&contrastLayers);
  params->canFreeData = false;
  emxFree_real_T(&params);
  emxFree_cell_wrap_0(&repeatLayers);
  emxFree_cell_wrap_0(&simLimits);
  emxFree_cell_wrap_0(&dataLimits);
  emxFree_cell_wrap_1(&allData);
  dataPresent->canFreeData = false;
  emxFree_real_T(&dataPresent);
  res->canFreeData = false;
  emxFree_real_T(&res);
  nbs->canFreeData = false;
  emxFree_real_T(&nbs);
  nba->canFreeData = false;
  emxFree_real_T(&nba);
  sf->canFreeData = false;
  emxFree_real_T(&sf);
  shifts->canFreeData = false;
  emxFree_real_T(&shifts);
  backs->canFreeData = false;
  emxFree_real_T(&backs);
  cRes->canFreeData = false;
  emxFree_real_T(&cRes);
  cNbss->canFreeData = false;
  emxFree_real_T(&cNbss);
  cNbas->canFreeData = false;
  emxFree_real_T(&cNbas);
  cScales->canFreeData = false;
  emxFree_real_T(&cScales);
  cShifts->canFreeData = false;
  emxFree_real_T(&cShifts);
  cBacks->canFreeData = false;
  emxFree_real_T(&cBacks);
  emxFree_cell_wrap_0(&repeats);
  nbsubs->canFreeData = false;
  emxFree_real_T(&nbsubs);
  nbairs->canFreeData = false;
  emxFree_real_T(&nbairs);
  emxFree_char_T(&geometry);
  resam->canFreeData = false;
  emxFree_real_T(&resam);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void standardTF_custlay_parallel_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  standardTF_custlay_parallel_xil_terminate();
}

void standardTF_custlay_parallel_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void standardTF_custlay_parallel_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (_coder_standardTF_custlay_parallel_api.c) */
