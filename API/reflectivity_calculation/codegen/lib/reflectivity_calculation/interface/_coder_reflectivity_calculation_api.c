/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_reflectivity_calculation_api.c
 *
 * Code generation for function '_coder_reflectivity_calculation_api'
 *
 */

/* Include files */
#include <string.h>
#include "tmwtypes.h"
#include "_coder_reflectivity_calculation_api.h"
#include "_coder_reflectivity_calculation_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131482U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "reflectivity_calculation",          /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const cell_7 u);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp, const
  emxArray_cell_wrap_5 *u);
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y);
static const mxArray *d_emlrt_marshallOut(const emlrtStack *sp, const
  emxArray_cell_wrap_6 *u);
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *problemDef,
  const char_T *identifier, struct0_T *y);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct4_T *u);
static void emxEnsureCapacity_cell_wrap_0(emxArray_cell_wrap_0 *emxArray,
  int32_T oldNumel);
static void emxEnsureCapacity_cell_wrap_1(const emlrtStack *sp,
  emxArray_cell_wrap_1 *emxArray, int32_T oldNumel);
static void emxEnsureCapacity_cell_wrap_2(emxArray_cell_wrap_2 *emxArray,
  int32_T oldNumel);
static void emxEnsureCapacity_cell_wrap_3(const emlrtStack *sp,
  emxArray_cell_wrap_3 *emxArray, int32_T oldNumel);
static void emxEnsureCapacity_char_T(emxArray_char_T *emxArray, int32_T oldNumel);
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel);
static void emxExpand_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1
  *emxArray, int32_T fromIndex, int32_T toIndex);
static void emxExpand_cell_wrap_2(emxArray_cell_wrap_2 *emxArray, int32_T
  fromIndex, int32_T toIndex);
static void emxExpand_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3
  *emxArray, int32_T fromIndex, int32_T toIndex);
static void emxFreeStruct_cell_4(cell_4 *pStruct);
static void emxFreeStruct_cell_7(cell_7 *pStruct);
static void emxFreeStruct_cell_wrap_1(cell_wrap_1 *pStruct);
static void emxFreeStruct_cell_wrap_3(cell_wrap_3 *pStruct);
static void emxFreeStruct_cell_wrap_5(cell_wrap_5 *pStruct);
static void emxFreeStruct_cell_wrap_6(cell_wrap_6 *pStruct);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxFreeStruct_struct1_T(struct1_T *pStruct);
static void emxFreeStruct_struct2_T(struct2_T *pStruct);
static void emxFreeStruct_struct3_T(struct3_T *pStruct);
static void emxFreeStruct_struct4_T(struct4_T *pStruct);
static void emxFreeStruct_struct5_T(struct5_T *pStruct);
static void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray);
static void emxFree_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray);
static void emxFree_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray);
static void emxFree_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray);
static void emxFree_cell_wrap_5(emxArray_cell_wrap_5 **pEmxArray);
static void emxFree_cell_wrap_6(emxArray_cell_wrap_6 **pEmxArray);
static void emxFree_char_T(emxArray_char_T **pEmxArray);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInitStruct_cell_4(const emlrtStack *sp, cell_4 *pStruct,
  boolean_T doPush);
static void emxInitStruct_cell_7(const emlrtStack *sp, cell_7 *pStruct,
  boolean_T doPush);
static void emxInitStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *pStruct,
  boolean_T doPush);
static void emxInitStruct_cell_wrap_2(cell_wrap_2 *pStruct);
static void emxInitStruct_cell_wrap_3(const emlrtStack *sp, cell_wrap_3 *pStruct,
  boolean_T doPush);
static void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct,
  boolean_T doPush);
static void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct,
  boolean_T doPush);
static void emxInitStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct,
  boolean_T doPush);
static void emxInitStruct_struct3_T(const emlrtStack *sp, struct3_T *pStruct,
  boolean_T doPush);
static void emxInitStruct_struct4_T(const emlrtStack *sp, struct4_T *pStruct,
  boolean_T doPush);
static void emxInitStruct_struct5_T(const emlrtStack *sp, struct5_T *pStruct,
  boolean_T doPush);
static void emxInit_cell_wrap_0(const emlrtStack *sp, emxArray_cell_wrap_0
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_cell_wrap_2(const emlrtStack *sp, emxArray_cell_wrap_2
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_cell_wrap_5(const emlrtStack *sp, emxArray_cell_wrap_5
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_cell_wrap_6(const emlrtStack *sp, emxArray_cell_wrap_6
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void emxTrim_cell_wrap_1(emxArray_cell_wrap_1 *emxArray, int32_T
  fromIndex, int32_T toIndex);
static void emxTrim_cell_wrap_3(emxArray_cell_wrap_3 *emxArray, int32_T
  fromIndex, int32_T toIndex);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *problemDef_cells, const char_T *identifier, cell_4 *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_4 *y);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_0 *y);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_1 *y);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_2 *y);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2]);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_3 *y);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *problemDef_limits, const char_T *identifier, struct1_T *y);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *controls,
  const char_T *identifier, struct2_T *y);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret);
static real_T x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2] = { 1, 2 };

  real_T (*r0)[2];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r0 = (real_T (*)[2])emlrtMxGetData(src);
  ret[0] = (*r0)[0];
  ret[1] = (*r0)[1];
  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[28] = { "contrastBacks", "contrastBacksType",
    "TF", "resample", "dataPresent", "numberOfContrasts", "geometry",
    "contrastShifts", "contrastScales", "contrastNbas", "contrastNbss",
    "contrastRes", "backs", "shifts", "sf", "nba", "nbs", "res", "params",
    "numberOfLayers", "modelType", "modelFilename", "path", "modelLanguage",
    "fitpars", "otherpars", "fitconstr", "otherconstr" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 28, fieldNames, 0U, &dims);
  thisId.fIdentifier = "contrastBacks";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "contrastBacks")), &thisId, y->contrastBacks);
  thisId.fIdentifier = "contrastBacksType";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "contrastBacksType")), &thisId, y->contrastBacksType);
  thisId.fIdentifier = "TF";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "TF")),
                     &thisId, y->TF);
  thisId.fIdentifier = "resample";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "resample")),
                     &thisId, y->resample);
  thisId.fIdentifier = "dataPresent";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "dataPresent")), &thisId, y->dataPresent);
  thisId.fIdentifier = "numberOfContrasts";
  y->numberOfContrasts = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b
    (sp, u, 0, 5, "numberOfContrasts")), &thisId);
  thisId.fIdentifier = "geometry";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6, "geometry")),
                     &thisId, y->geometry);
  thisId.fIdentifier = "contrastShifts";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7,
    "contrastShifts")), &thisId, y->contrastShifts);
  thisId.fIdentifier = "contrastScales";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "contrastScales")), &thisId, y->contrastScales);
  thisId.fIdentifier = "contrastNbas";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "contrastNbas")), &thisId, y->contrastNbas);
  thisId.fIdentifier = "contrastNbss";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10,
    "contrastNbss")), &thisId, y->contrastNbss);
  thisId.fIdentifier = "contrastRes";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 11,
    "contrastRes")), &thisId, y->contrastRes);
  thisId.fIdentifier = "backs";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 12, "backs")),
                     &thisId, y->backs);
  thisId.fIdentifier = "shifts";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 13, "shifts")),
                     &thisId, y->shifts);
  thisId.fIdentifier = "sf";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 14, "sf")),
                     &thisId, y->sf);
  thisId.fIdentifier = "nba";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 15, "nba")),
                     &thisId, y->nba);
  thisId.fIdentifier = "nbs";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 16, "nbs")),
                     &thisId, y->nbs);
  thisId.fIdentifier = "res";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 17, "res")),
                     &thisId, y->res);
  thisId.fIdentifier = "params";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 18, "params")),
                     &thisId, y->params);
  thisId.fIdentifier = "numberOfLayers";
  y->numberOfLayers = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 19, "numberOfLayers")), &thisId);
  thisId.fIdentifier = "modelType";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 20,
    "modelType")), &thisId, y->modelType);
  thisId.fIdentifier = "modelFilename";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 21,
    "modelFilename")), &thisId, y->modelFilename);
  thisId.fIdentifier = "path";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 22, "path")),
                     &thisId, y->path);
  thisId.fIdentifier = "modelLanguage";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 23,
    "modelLanguage")), &thisId, y->modelLanguage);
  thisId.fIdentifier = "fitpars";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 24, "fitpars")),
                     &thisId, y->fitpars);
  thisId.fIdentifier = "otherpars";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 25,
    "otherpars")), &thisId, y->otherpars);
  thisId.fIdentifier = "fitconstr";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 26,
    "fitconstr")), &thisId, y->fitconstr);
  thisId.fIdentifier = "otherconstr";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 27,
    "otherconstr")), &thisId, y->otherconstr);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const cell_7 u)
{
  const mxArray *y;
  int32_T iv4[2];
  emxArray_real_T *b_u;
  int32_T i5;
  int32_T loop_ub;
  const mxArray *b_y;
  real_T c_u;
  const mxArray *c_y;
  const mxArray *m1;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  y = NULL;
  iv4[0] = 1;
  iv4[1] = 6;
  emxInit_real_T(sp, &b_u, 1, true);
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, iv4));
  emlrtSetCell(y, 0, c_emlrt_marshallOut(sp, u.f1));
  emlrtSetCell(y, 1, c_emlrt_marshallOut(sp, u.f2));
  emlrtSetCell(y, 2, d_emlrt_marshallOut(sp, u.f3));
  emlrtSetCell(y, 3, d_emlrt_marshallOut(sp, u.f4));
  emlrtSetCell(y, 4, c_emlrt_marshallOut(sp, u.f5));
  i5 = b_u->size[0];
  b_u->size[0] = u.f6->size[0];
  emxEnsureCapacity_real_T(b_u, i5);
  loop_ub = u.f6->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_u->data[i5] = u.f6->data[i5];
  }

  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(1, *(int32_T (*)[1])u.f6->size));
  i5 = 0;
  loop_ub = u.f6->size[0];
  while (i5 < loop_ub) {
    c_u = b_u->data[i5];
    c_y = NULL;
    m1 = emlrtCreateDoubleScalar(c_u);
    emlrtAssign(&c_y, m1);
    emlrtSetCell(b_y, i5, c_y);
    i5++;
  }

  emxFree_real_T(&b_u);
  emlrtSetCell(y, 5, b_y);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, 3 };

  const boolean_T bv8[2] = { true, false };

  int32_T iv8[2];
  int32_T i13;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv8[0],
    iv8);
  i13 = ret->size[0] * ret->size[1];
  ret->size[0] = iv8[0];
  ret->size[1] = iv8[1];
  emxEnsureCapacity_real_T(ret, i13);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp, const
  emxArray_cell_wrap_5 *u)
{
  const mxArray *y;
  int32_T i6;
  int32_T n;
  emxArray_real_T *b_u;
  int32_T i7;
  int32_T loop_ub;
  const mxArray *b_y;
  const mxArray *m2;
  real_T *pData;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(1, *(int32_T (*)[1])u->size));
  i6 = 0;
  n = u->size[0];
  emxInit_real_T(sp, &b_u, 2, true);
  while (i6 < n) {
    i7 = b_u->size[0] * b_u->size[1];
    b_u->size[0] = u->data[i6].f1->size[0];
    b_u->size[1] = 2;
    emxEnsureCapacity_real_T(b_u, i7);
    loop_ub = u->data[i6].f1->size[0] * u->data[i6].f1->size[1];
    for (i7 = 0; i7 < loop_ub; i7++) {
      b_u->data[i7] = u->data[i6].f1->data[i7];
    }

    b_y = NULL;
    m2 = emlrtCreateNumericArray(2, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
      mxREAL);
    pData = emlrtMxGetPr(m2);
    i7 = 0;
    for (loop_ub = 0; loop_ub < b_u->size[0]; loop_ub++) {
      pData[i7] = b_u->data[loop_ub];
      i7++;
    }

    for (loop_ub = 0; loop_ub < b_u->size[0]; loop_ub++) {
      pData[i7] = b_u->data[loop_ub + b_u->size[0]];
      i7++;
    }

    emlrtAssign(&b_y, m2);
    emlrtSetCell(y, i6, b_y);
    i6++;
  }

  emxFree_real_T(&b_u);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = { 1, 5 };

  const boolean_T bv9[2] = { false, true };

  int32_T iv9[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv9[0],
    iv9);
  ret_size[0] = iv9[0];
  ret_size[1] = iv9[1];
  emlrtImportArrayR2015b(sp, src, (void *)ret_data, 8, false);
  emlrtDestroyArray(&src);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y)
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *d_emlrt_marshallOut(const emlrtStack *sp, const
  emxArray_cell_wrap_6 *u)
{
  const mxArray *y;
  int32_T i8;
  int32_T n;
  emxArray_real_T *b_u;
  int32_T i9;
  int32_T loop_ub;
  const mxArray *b_y;
  const mxArray *m3;
  real_T *pData;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(1, *(int32_T (*)[1])u->size));
  i8 = 0;
  n = u->size[0];
  emxInit_real_T(sp, &b_u, 2, true);
  while (i8 < n) {
    i9 = b_u->size[0] * b_u->size[1];
    b_u->size[0] = u->data[i8].f1->size[0];
    b_u->size[1] = 3;
    emxEnsureCapacity_real_T(b_u, i9);
    loop_ub = u->data[i8].f1->size[0] * u->data[i8].f1->size[1];
    for (i9 = 0; i9 < loop_ub; i9++) {
      b_u->data[i9] = u->data[i8].f1->data[i9];
    }

    b_y = NULL;
    m3 = emlrtCreateNumericArray(2, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
      mxREAL);
    pData = emlrtMxGetPr(m3);
    i9 = 0;
    for (loop_ub = 0; loop_ub < b_u->size[0]; loop_ub++) {
      pData[i9] = b_u->data[loop_ub];
      i9++;
    }

    for (loop_ub = 0; loop_ub < b_u->size[0]; loop_ub++) {
      pData[i9] = b_u->data[loop_ub + b_u->size[0]];
      i9++;
    }

    for (loop_ub = 0; loop_ub < b_u->size[0]; loop_ub++) {
      pData[i9] = b_u->data[loop_ub + (b_u->size[0] << 1)];
      i9++;
    }

    emlrtAssign(&b_y, m3);
    emlrtSetCell(y, i8, b_y);
    i8++;
  }

  emxFree_real_T(&b_u);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, 2 };

  const boolean_T bv10[2] = { true, false };

  int32_T iv10[2];
  int32_T i14;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv10[0],
    iv10);
  i14 = ret->size[0] * ret->size[1];
  ret->size[0] = iv10[0];
  ret->size[1] = iv10[1];
  emxEnsureCapacity_real_T(ret, i14);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = x_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *problemDef,
  const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(problemDef), &thisId, y);
  emlrtDestroyArray(&problemDef);
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct4_T *u)
{
  const mxArray *y;
  emxArray_real_T *b_u;
  static const char * sv0[9] = { "ssubs", "backgrounds", "qshifts",
    "scalefactors", "nbairs", "nbsubs", "resolutions", "calculations",
    "allSubRough" };

  int32_T i4;
  int32_T loop_ub;
  const mxArray *b_y;
  const mxArray *m0;
  real_T *pData;
  static const char * sv1[2] = { "all_chis", "sum_chi" };

  const mxArray *c_y;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_u, 1, true);
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 9, sv0));
  i4 = b_u->size[0];
  b_u->size[0] = u->ssubs->size[0];
  emxEnsureCapacity_real_T(b_u, i4);
  loop_ub = u->ssubs->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_u->data[i4] = u->ssubs->data[i4];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i4 = 0;
  for (loop_ub = 0; loop_ub < u->ssubs->size[0]; loop_ub++) {
    pData[i4] = u->ssubs->data[loop_ub];
    i4++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "ssubs", b_y, 0);
  i4 = b_u->size[0];
  b_u->size[0] = u->backgrounds->size[0];
  emxEnsureCapacity_real_T(b_u, i4);
  loop_ub = u->backgrounds->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_u->data[i4] = u->backgrounds->data[i4];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i4 = 0;
  for (loop_ub = 0; loop_ub < u->backgrounds->size[0]; loop_ub++) {
    pData[i4] = u->backgrounds->data[loop_ub];
    i4++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "backgrounds", b_y, 1);
  i4 = b_u->size[0];
  b_u->size[0] = u->qshifts->size[0];
  emxEnsureCapacity_real_T(b_u, i4);
  loop_ub = u->qshifts->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_u->data[i4] = u->qshifts->data[i4];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i4 = 0;
  for (loop_ub = 0; loop_ub < u->qshifts->size[0]; loop_ub++) {
    pData[i4] = u->qshifts->data[loop_ub];
    i4++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "qshifts", b_y, 2);
  i4 = b_u->size[0];
  b_u->size[0] = u->scalefactors->size[0];
  emxEnsureCapacity_real_T(b_u, i4);
  loop_ub = u->scalefactors->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_u->data[i4] = u->scalefactors->data[i4];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i4 = 0;
  for (loop_ub = 0; loop_ub < u->scalefactors->size[0]; loop_ub++) {
    pData[i4] = u->scalefactors->data[loop_ub];
    i4++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "scalefactors", b_y, 3);
  i4 = b_u->size[0];
  b_u->size[0] = u->nbairs->size[0];
  emxEnsureCapacity_real_T(b_u, i4);
  loop_ub = u->nbairs->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_u->data[i4] = u->nbairs->data[i4];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i4 = 0;
  for (loop_ub = 0; loop_ub < u->nbairs->size[0]; loop_ub++) {
    pData[i4] = u->nbairs->data[loop_ub];
    i4++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "nbairs", b_y, 4);
  i4 = b_u->size[0];
  b_u->size[0] = u->nbsubs->size[0];
  emxEnsureCapacity_real_T(b_u, i4);
  loop_ub = u->nbsubs->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_u->data[i4] = u->nbsubs->data[i4];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i4 = 0;
  for (loop_ub = 0; loop_ub < u->nbsubs->size[0]; loop_ub++) {
    pData[i4] = u->nbsubs->data[loop_ub];
    i4++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "nbsubs", b_y, 5);
  i4 = b_u->size[0];
  b_u->size[0] = u->resolutions->size[0];
  emxEnsureCapacity_real_T(b_u, i4);
  loop_ub = u->resolutions->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_u->data[i4] = u->resolutions->data[i4];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i4 = 0;
  for (loop_ub = 0; loop_ub < u->resolutions->size[0]; loop_ub++) {
    pData[i4] = u->resolutions->data[loop_ub];
    i4++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "resolutions", b_y, 6);
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 2, sv1));
  i4 = b_u->size[0];
  b_u->size[0] = u->calculations.all_chis->size[0];
  emxEnsureCapacity_real_T(b_u, i4);
  loop_ub = u->calculations.all_chis->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_u->data[i4] = u->calculations.all_chis->data[i4];
  }

  c_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i4 = 0;
  for (loop_ub = 0; loop_ub < u->calculations.all_chis->size[0]; loop_ub++) {
    pData[i4] = u->calculations.all_chis->data[loop_ub];
    i4++;
  }

  emlrtAssign(&c_y, m0);
  emlrtSetFieldR2017b(b_y, 0, "all_chis", c_y, 0);
  c_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->calculations.sum_chi);
  emlrtAssign(&c_y, m0);
  emlrtSetFieldR2017b(b_y, 0, "sum_chi", c_y, 1);
  emlrtSetFieldR2017b(y, 0, "calculations", b_y, 7);
  i4 = b_u->size[0];
  b_u->size[0] = u->allSubRough->size[0];
  emxEnsureCapacity_real_T(b_u, i4);
  loop_ub = u->allSubRough->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_u->data[i4] = u->allSubRough->data[i4];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i4 = 0;
  loop_ub = 0;
  emxFree_real_T(&b_u);
  while (loop_ub < u->allSubRough->size[0]) {
    pData[i4] = u->allSubRough->data[loop_ub];
    i4++;
    loop_ub++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "allSubRough", b_y, 8);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static void emxEnsureCapacity_cell_wrap_0(emxArray_cell_wrap_0 *emxArray,
  int32_T oldNumel)
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

    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_0));
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

static void emxEnsureCapacity_cell_wrap_1(const emlrtStack *sp,
  emxArray_cell_wrap_1 *emxArray, int32_T oldNumel)
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

    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_1));
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
  } else {
    if (oldNumel < newNumel) {
      emxExpand_cell_wrap_1(sp, emxArray, oldNumel, newNumel);
    }
  }
}

static void emxEnsureCapacity_cell_wrap_2(emxArray_cell_wrap_2 *emxArray,
  int32_T oldNumel)
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

    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_2));
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

static void emxEnsureCapacity_cell_wrap_3(const emlrtStack *sp,
  emxArray_cell_wrap_3 *emxArray, int32_T oldNumel)
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

    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_3));
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
  } else {
    if (oldNumel < newNumel) {
      emxExpand_cell_wrap_3(sp, emxArray, oldNumel, newNumel);
    }
  }
}

static void emxEnsureCapacity_char_T(emxArray_char_T *emxArray, int32_T oldNumel)
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

    newData = emlrtCallocMex((uint32_T)i, sizeof(char_T));
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

static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel)
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

    newData = emlrtCallocMex((uint32_T)i, sizeof(real_T));
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

static void emxExpand_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1
  *emxArray, int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_1(sp, &emxArray->data[i], false);
  }
}

static void emxExpand_cell_wrap_2(emxArray_cell_wrap_2 *emxArray, int32_T
  fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_2(&emxArray->data[i]);
  }
}

static void emxExpand_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3
  *emxArray, int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_3(sp, &emxArray->data[i], false);
  }
}

static void emxFreeStruct_cell_4(cell_4 *pStruct)
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

static void emxFreeStruct_cell_7(cell_7 *pStruct)
{
  emxFree_cell_wrap_5(&pStruct->f1);
  emxFree_cell_wrap_5(&pStruct->f2);
  emxFree_cell_wrap_6(&pStruct->f3);
  emxFree_cell_wrap_6(&pStruct->f4);
  emxFree_cell_wrap_5(&pStruct->f5);
  emxFree_real_T(&pStruct->f6);
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

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
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

static void emxFreeStruct_struct1_T(struct1_T *pStruct)
{
  emxFree_real_T(&pStruct->params);
  emxFree_real_T(&pStruct->backs);
  emxFree_real_T(&pStruct->scales);
  emxFree_real_T(&pStruct->shifts);
  emxFree_real_T(&pStruct->nba);
  emxFree_real_T(&pStruct->nbs);
  emxFree_real_T(&pStruct->res);
}

static void emxFreeStruct_struct2_T(struct2_T *pStruct)
{
  emxFree_char_T(&pStruct->para);
  emxFree_char_T(&pStruct->proc);
  emxFree_char_T(&pStruct->display);
  emxFree_real_T(&pStruct->strategy);
  emxFreeStruct_struct3_T(&pStruct->checks);
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

static void emxFreeStruct_struct4_T(struct4_T *pStruct)
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

static void emxFreeStruct_struct5_T(struct5_T *pStruct)
{
  emxFree_real_T(&pStruct->all_chis);
}

static void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_0 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_0 *)NULL) && (*pEmxArray)->canFreeData)
    {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
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
        emlrtFreeMex((*pEmxArray)->data);
      }
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_1 *)NULL;
  }
}

static void emxFree_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_2 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_2 *)NULL) && (*pEmxArray)->canFreeData)
    {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
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
        emlrtFreeMex((*pEmxArray)->data);
      }
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_3 *)NULL;
  }
}

static void emxFree_cell_wrap_5(emxArray_cell_wrap_5 **pEmxArray)
{
  int32_T numEl;
  int32_T i;
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

static void emxFree_cell_wrap_6(emxArray_cell_wrap_6 **pEmxArray)
{
  int32_T numEl;
  int32_T i;
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

static void emxFree_char_T(emxArray_char_T **pEmxArray)
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

static void emxFree_real_T(emxArray_real_T **pEmxArray)
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

static void emxInitStruct_cell_4(const emlrtStack *sp, cell_4 *pStruct,
  boolean_T doPush)
{
  emxInit_cell_wrap_0(sp, &pStruct->f1, 2, doPush);
  emxInit_cell_wrap_1(sp, &pStruct->f2, 2, doPush);
  emxInit_cell_wrap_0(sp, &pStruct->f3, 2, doPush);
  emxInit_cell_wrap_0(sp, &pStruct->f4, 2, doPush);
  emxInit_cell_wrap_0(sp, &pStruct->f5, 2, doPush);
  emxInit_cell_wrap_2(sp, &pStruct->f6, 1, doPush);
  emxInit_cell_wrap_3(sp, &pStruct->f7, 2, doPush);
  emxInit_cell_wrap_3(sp, &pStruct->f8, 2, doPush);
  emxInit_cell_wrap_3(sp, &pStruct->f9, 2, doPush);
  emxInit_cell_wrap_3(sp, &pStruct->f10, 2, doPush);
  emxInit_cell_wrap_3(sp, &pStruct->f11, 2, doPush);
  emxInit_cell_wrap_3(sp, &pStruct->f12, 2, doPush);
  emxInit_cell_wrap_3(sp, &pStruct->f13, 2, doPush);
}

static void emxInitStruct_cell_7(const emlrtStack *sp, cell_7 *pStruct,
  boolean_T doPush)
{
  emxInit_cell_wrap_5(sp, &pStruct->f1, 1, doPush);
  emxInit_cell_wrap_5(sp, &pStruct->f2, 1, doPush);
  emxInit_cell_wrap_6(sp, &pStruct->f3, 1, doPush);
  emxInit_cell_wrap_6(sp, &pStruct->f4, 1, doPush);
  emxInit_cell_wrap_5(sp, &pStruct->f5, 1, doPush);
  emxInit_real_T(sp, &pStruct->f6, 1, doPush);
}

static void emxInitStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *pStruct,
  boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->f1, 2, doPush);
}

static void emxInitStruct_cell_wrap_2(cell_wrap_2 *pStruct)
{
  pStruct->f1.size[0] = 0;
  pStruct->f1.size[1] = 0;
}

static void emxInitStruct_cell_wrap_3(const emlrtStack *sp, cell_wrap_3 *pStruct,
  boolean_T doPush)
{
  emxInit_char_T(sp, &pStruct->f1, 2, doPush);
}

static void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct,
  boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->contrastBacks, 2, doPush);
  emxInit_real_T(sp, &pStruct->contrastBacksType, 2, doPush);
  emxInit_char_T(sp, &pStruct->TF, 2, doPush);
  emxInit_real_T(sp, &pStruct->resample, 2, doPush);
  emxInit_real_T(sp, &pStruct->dataPresent, 2, doPush);
  emxInit_char_T(sp, &pStruct->geometry, 2, doPush);
  emxInit_real_T(sp, &pStruct->contrastShifts, 2, doPush);
  emxInit_real_T(sp, &pStruct->contrastScales, 2, doPush);
  emxInit_real_T(sp, &pStruct->contrastNbas, 2, doPush);
  emxInit_real_T(sp, &pStruct->contrastNbss, 2, doPush);
  emxInit_real_T(sp, &pStruct->contrastRes, 2, doPush);
  emxInit_real_T(sp, &pStruct->backs, 2, doPush);
  emxInit_real_T(sp, &pStruct->shifts, 2, doPush);
  emxInit_real_T(sp, &pStruct->sf, 2, doPush);
  emxInit_real_T(sp, &pStruct->nba, 2, doPush);
  emxInit_real_T(sp, &pStruct->nbs, 2, doPush);
  emxInit_real_T(sp, &pStruct->res, 2, doPush);
  emxInit_real_T(sp, &pStruct->params, 2, doPush);
  emxInit_char_T(sp, &pStruct->modelType, 2, doPush);
  emxInit_char_T(sp, &pStruct->modelFilename, 2, doPush);
  emxInit_char_T(sp, &pStruct->path, 2, doPush);
  emxInit_real_T(sp, &pStruct->modelLanguage, 2, doPush);
  emxInit_real_T(sp, &pStruct->fitpars, 2, doPush);
  emxInit_real_T(sp, &pStruct->otherpars, 2, doPush);
  emxInit_real_T(sp, &pStruct->fitconstr, 2, doPush);
  emxInit_real_T(sp, &pStruct->otherconstr, 2, doPush);
}

static void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct,
  boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->params, 2, doPush);
  emxInit_real_T(sp, &pStruct->backs, 2, doPush);
  emxInit_real_T(sp, &pStruct->scales, 2, doPush);
  emxInit_real_T(sp, &pStruct->shifts, 2, doPush);
  emxInit_real_T(sp, &pStruct->nba, 2, doPush);
  emxInit_real_T(sp, &pStruct->nbs, 2, doPush);
  emxInit_real_T(sp, &pStruct->res, 2, doPush);
}

static void emxInitStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct,
  boolean_T doPush)
{
  emxInit_char_T(sp, &pStruct->para, 2, doPush);
  emxInit_char_T(sp, &pStruct->proc, 2, doPush);
  emxInit_char_T(sp, &pStruct->display, 2, doPush);
  emxInit_real_T(sp, &pStruct->strategy, 2, doPush);
  emxInitStruct_struct3_T(sp, &pStruct->checks, doPush);
}

static void emxInitStruct_struct3_T(const emlrtStack *sp, struct3_T *pStruct,
  boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->params_fitYesNo, 2, doPush);
  emxInit_real_T(sp, &pStruct->backs_fitYesNo, 2, doPush);
  emxInit_real_T(sp, &pStruct->shifts_fitYesNo, 2, doPush);
  emxInit_real_T(sp, &pStruct->scales_fitYesNo, 2, doPush);
  emxInit_real_T(sp, &pStruct->nbairs_fitYesNo, 2, doPush);
  emxInit_real_T(sp, &pStruct->nbsubs_fitYesNo, 2, doPush);
  emxInit_real_T(sp, &pStruct->resol_fitYesNo, 2, doPush);
}

static void emxInitStruct_struct4_T(const emlrtStack *sp, struct4_T *pStruct,
  boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->ssubs, 1, doPush);
  emxInit_real_T(sp, &pStruct->backgrounds, 1, doPush);
  emxInit_real_T(sp, &pStruct->qshifts, 1, doPush);
  emxInit_real_T(sp, &pStruct->scalefactors, 1, doPush);
  emxInit_real_T(sp, &pStruct->nbairs, 1, doPush);
  emxInit_real_T(sp, &pStruct->nbsubs, 1, doPush);
  emxInit_real_T(sp, &pStruct->resolutions, 1, doPush);
  emxInitStruct_struct5_T(sp, &pStruct->calculations, doPush);
  emxInit_real_T(sp, &pStruct->allSubRough, 1, doPush);
}

static void emxInitStruct_struct5_T(const emlrtStack *sp, struct5_T *pStruct,
  boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->all_chis, 1, doPush);
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
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
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
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
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
  emxArray->data = (cell_wrap_2 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
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
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_cell_wrap_5(const emlrtStack *sp, emxArray_cell_wrap_5
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_5 *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_cell_wrap_5 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_5));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_cell_wrap_5);
  }

  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_5 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_cell_wrap_6(const emlrtStack *sp, emxArray_cell_wrap_6
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_6 *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_cell_wrap_6 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_6));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_cell_wrap_6);
  }

  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_6 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
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
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
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
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
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

static void emxTrim_cell_wrap_3(emxArray_cell_wrap_3 *emxArray, int32_T
  fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_3(&emxArray->data[i]);
  }
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *problemDef_cells, const char_T *identifier, cell_4 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(problemDef_cells), &thisId, y);
  emlrtDestroyArray(&problemDef_cells);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_4 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv0[2];
  boolean_T bv0[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv0[0] = 1;
  bv0[0] = false;
  iv0[1] = 13;
  bv0[1] = false;
  emlrtCheckCell(sp, parentId, u, 2U, iv0, bv0);
  thisId.fIdentifier = "1";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 0)), &thisId,
                     y->f1);
  thisId.fIdentifier = "2";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 1)), &thisId,
                     y->f2);
  thisId.fIdentifier = "3";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 2)), &thisId,
                     y->f3);
  thisId.fIdentifier = "4";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 3)), &thisId,
                     y->f4);
  thisId.fIdentifier = "5";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 4)), &thisId,
                     y->f5);
  thisId.fIdentifier = "6";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 5)), &thisId,
                     y->f6);
  thisId.fIdentifier = "7";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 6)), &thisId,
                     y->f7);
  thisId.fIdentifier = "8";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 7)), &thisId,
                     y->f8);
  thisId.fIdentifier = "9";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 8)), &thisId,
                     y->f9);
  thisId.fIdentifier = "10";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 9)), &thisId,
                     y->f10);
  thisId.fIdentifier = "11";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 10)), &thisId,
                     y->f11);
  thisId.fIdentifier = "12";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 11)), &thisId,
                     y->f12);
  thisId.fIdentifier = "13";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 12)), &thisId,
                     y->f13);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_0 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv1[2];
  static const boolean_T bv1[2] = { false, true };

  int32_T sizes[2];
  int32_T i0;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv1[0] = 1;
  iv1[1] = -1;
  emlrtCheckVsCell(sp, parentId, u, 2U, iv1, bv1, sizes);
  i0 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_cell_wrap_0(y, i0);
  for (i0 = 0; i0 < sizes[1]; i0++) {
    sprintf(&str[0], "%d", i0 + 1);
    thisId.fIdentifier = &str[0];
    j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i0)),
                       &thisId, y->data[i0].f1);
  }

  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_1 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv2[2];
  static const boolean_T bv2[2] = { false, true };

  int32_T sizes[2];
  int32_T i1;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv2[0] = 1;
  iv2[1] = -1;
  emlrtCheckVsCell(sp, parentId, u, 2U, iv2, bv2, sizes);
  i1 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_cell_wrap_1(sp, y, i1);
  for (i1 = 0; i1 < sizes[1]; i1++) {
    sprintf(&str[0], "%d", i1 + 1);
    thisId.fIdentifier = &str[0];
    l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i1)),
                       &thisId, y->data[i1].f1);
  }

  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_2 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T n[1];
  boolean_T bv3[1];
  int32_T sizes[1];
  int32_T i2;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  n[0] = -1;
  bv3[0] = true;
  emlrtCheckVsCell(sp, parentId, u, 1U, n, bv3, sizes);
  i2 = y->size[0];
  y->size[0] = sizes[0];
  emxEnsureCapacity_cell_wrap_2(y, i2);
  for (i2 = 0; i2 < sizes[0]; i2++) {
    sprintf(&str[0], "%d", i2 + 1);
    thisId.fIdentifier = &str[0];
    n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i2)),
                       &thisId, y->data[i2].f1.data, y->data[i2].f1.size);
  }

  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2])
{
  cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_3 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv3[2];
  static const boolean_T bv4[2] = { false, true };

  int32_T sizes[2];
  int32_T i3;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv3[0] = 1;
  iv3[1] = -1;
  emlrtCheckVsCell(sp, parentId, u, 2U, iv3, bv4, sizes);
  i3 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_cell_wrap_3(sp, y, i3);
  for (i3 = 0; i3 < sizes[1]; i3++) {
    sprintf(&str[0], "%d", i3 + 1);
    thisId.fIdentifier = &str[0];
    d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i3)),
                       &thisId, y->data[i3].f1);
  }

  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *problemDef_limits, const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  q_emlrt_marshallIn(sp, emlrtAlias(problemDef_limits), &thisId, y);
  emlrtDestroyArray(&problemDef_limits);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[7] = { "params", "backs", "scales", "shifts",
    "nba", "nbs", "res" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 7, fieldNames, 0U, &dims);
  thisId.fIdentifier = "params";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "params")),
                     &thisId, y->params);
  thisId.fIdentifier = "backs";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "backs")),
                     &thisId, y->backs);
  thisId.fIdentifier = "scales";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "scales")),
                     &thisId, y->scales);
  thisId.fIdentifier = "shifts";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "shifts")),
                     &thisId, y->shifts);
  thisId.fIdentifier = "nba";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4, "nba")),
                     &thisId, y->nba);
  thisId.fIdentifier = "nbs";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5, "nbs")),
                     &thisId, y->nbs);
  thisId.fIdentifier = "res";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6, "res")),
                     &thisId, y->res);
  emlrtDestroyArray(&u);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  db_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *controls,
  const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  t_emlrt_marshallIn(sp, emlrtAlias(controls), &thisId, y);
  emlrtDestroyArray(&controls);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[18] = { "para", "proc", "display", "tolX",
    "tolFun", "maxFunEvals", "maxIter", "populationSize", "F_weight", "F_CR",
    "VTR", "numGen", "strategy", "Nlive", "nmcmc", "propScale", "nsTolerance",
    "checks" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 18, fieldNames, 0U, &dims);
  thisId.fIdentifier = "para";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "para")),
                     &thisId, y->para);
  thisId.fIdentifier = "proc";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "proc")),
                     &thisId, y->proc);
  thisId.fIdentifier = "display";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "display")),
                     &thisId, y->display);
  thisId.fIdentifier = "tolX";
  y->tolX = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "tolX")), &thisId);
  thisId.fIdentifier = "tolFun";
  y->tolFun = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "tolFun")), &thisId);
  thisId.fIdentifier = "maxFunEvals";
  y->maxFunEvals = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 5, "maxFunEvals")), &thisId);
  thisId.fIdentifier = "maxIter";
  y->maxIter = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "maxIter")), &thisId);
  thisId.fIdentifier = "populationSize";
  y->populationSize = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 7, "populationSize")), &thisId);
  thisId.fIdentifier = "F_weight";
  y->F_weight = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    8, "F_weight")), &thisId);
  thisId.fIdentifier = "F_CR";
  y->F_CR = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "F_CR")), &thisId);
  thisId.fIdentifier = "VTR";
  y->VTR = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10,
    "VTR")), &thisId);
  thisId.fIdentifier = "numGen";
  y->numGen = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 11,
    "numGen")), &thisId);
  thisId.fIdentifier = "strategy";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 12, "strategy")),
                     &thisId, y->strategy);
  thisId.fIdentifier = "Nlive";
  y->Nlive = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 13,
    "Nlive")), &thisId);
  thisId.fIdentifier = "nmcmc";
  y->nmcmc = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 14,
    "nmcmc")), &thisId);
  thisId.fIdentifier = "propScale";
  y->propScale = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    15, "propScale")), &thisId);
  thisId.fIdentifier = "nsTolerance";
  y->nsTolerance = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 16, "nsTolerance")), &thisId);
  thisId.fIdentifier = "checks";
  u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 17, "checks")),
                     &thisId, &y->checks);
  emlrtDestroyArray(&u);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[7] = { "params_fitYesNo", "backs_fitYesNo",
    "shifts_fitYesNo", "scales_fitYesNo", "nbairs_fitYesNo", "nbsubs_fitYesNo",
    "resol_fitYesNo" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 7, fieldNames, 0U, &dims);
  thisId.fIdentifier = "params_fitYesNo";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "params_fitYesNo")), &thisId, y->params_fitYesNo);
  thisId.fIdentifier = "backs_fitYesNo";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "backs_fitYesNo")), &thisId, y->backs_fitYesNo);
  thisId.fIdentifier = "shifts_fitYesNo";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "shifts_fitYesNo")), &thisId, y->shifts_fitYesNo);
  thisId.fIdentifier = "scales_fitYesNo";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "scales_fitYesNo")), &thisId, y->scales_fitYesNo);
  thisId.fIdentifier = "nbairs_fitYesNo";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "nbairs_fitYesNo")), &thisId, y->nbairs_fitYesNo);
  thisId.fIdentifier = "nbsubs_fitYesNo";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5,
    "nbsubs_fitYesNo")), &thisId, y->nbsubs_fitYesNo);
  thisId.fIdentifier = "resol_fitYesNo";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "resol_fitYesNo")), &thisId, y->resol_fitYesNo);
  emlrtDestroyArray(&u);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv5[2] = { false, true };

  int32_T iv5[2];
  int32_T i10;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv5[0],
    iv5);
  i10 = ret->size[0] * ret->size[1];
  ret->size[0] = iv5[0];
  ret->size[1] = iv5[1];
  emxEnsureCapacity_real_T(ret, i10);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv6[2] = { false, true };

  int32_T iv6[2];
  int32_T i11;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims, &bv6[0],
    iv6);
  i11 = ret->size[0] * ret->size[1];
  ret->size[0] = iv6[0];
  ret->size[1] = iv6[1];
  emxEnsureCapacity_char_T(ret, i11);
  emlrtImportArrayR2015b(sp, src, ret->data, 1, false);
  emlrtDestroyArray(&src);
}

static real_T x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, -1 };

  const boolean_T bv7[2] = { true, true };

  int32_T iv7[2];
  int32_T i12;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv7[0],
    iv7);
  i12 = ret->size[0] * ret->size[1];
  ret->size[0] = iv7[0];
  ret->size[1] = iv7[1];
  emxEnsureCapacity_real_T(ret, i12);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

void reflectivity_calculation_api(const mxArray * const prhs[4], int32_T nlhs,
  const mxArray *plhs[2])
{
  struct0_T problemDef;
  cell_4 problemDef_cells;
  struct1_T problemDef_limits;
  struct2_T controls;
  struct4_T problem;
  cell_7 result;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInitStruct_struct0_T(&st, &problemDef, true);
  emxInitStruct_cell_4(&st, &problemDef_cells, true);
  emxInitStruct_struct1_T(&st, &problemDef_limits, true);
  emxInitStruct_struct2_T(&st, &controls, true);
  emxInitStruct_struct4_T(&st, &problem, true);
  emxInitStruct_cell_7(&st, &result, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "problemDef", &problemDef);
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "problemDef_cells",
                     &problemDef_cells);
  p_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "problemDef_limits",
                     &problemDef_limits);
  s_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "controls", &controls);

  /* Invoke the target function */
  reflectivity_calculation(&problemDef, &problemDef_cells, &problemDef_limits,
    &controls, &problem, &result);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, &problem);
  emxFreeStruct_struct4_T(&problem);
  emxFreeStruct_struct2_T(&controls);
  emxFreeStruct_struct1_T(&problemDef_limits);
  emxFreeStruct_cell_4(&problemDef_cells);
  emxFreeStruct_struct0_T(&problemDef);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(&st, result);
  }

  emxFreeStruct_cell_7(&result);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void reflectivity_calculation_atexit(void)
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
  reflectivity_calculation_xil_terminate();
  reflectivity_calculation_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void reflectivity_calculation_initialize(void)
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

void reflectivity_calculation_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (_coder_reflectivity_calculation_api.c) */
