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
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14]);
static void ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[6]);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const cell_13 u);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[21]);
static void bc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7]);
static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp, const
  emxArray_cell_wrap_11 *u);
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_4 y[2]);
static void cc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[64]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[10]);
static const mxArray *d_emlrt_marshallOut(const emlrtStack *sp, const
  emxArray_cell_wrap_12 *u);
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_5 y[1]);
static void dc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_6 y[1]);
static void ec_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[153]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *problemDef,
  const char_T *identifier, struct0_T *y);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct4_T *u);
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel);
static void emxFreeStruct_cell_13(cell_13 *pStruct);
static void emxFreeStruct_cell_wrap_11(cell_wrap_11 *pStruct);
static void emxFreeStruct_cell_wrap_12(cell_wrap_12 *pStruct);
static void emxFreeStruct_struct4_T(struct4_T *pStruct);
static void emxFreeStruct_struct5_T(struct5_T *pStruct);
static void emxFree_cell_wrap_11(emxArray_cell_wrap_11 **pEmxArray);
static void emxFree_cell_wrap_12(emxArray_cell_wrap_12 **pEmxArray);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInitStruct_cell_13(const emlrtStack *sp, cell_13 *pStruct,
  boolean_T doPush);
static void emxInitStruct_struct4_T(const emlrtStack *sp, struct4_T *pStruct,
  boolean_T doPush);
static void emxInitStruct_struct5_T(const emlrtStack *sp, struct5_T *pStruct,
  boolean_T doPush);
static void emxInit_cell_wrap_11(const emlrtStack *sp, emxArray_cell_wrap_11
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_cell_wrap_12(const emlrtStack *sp, emxArray_cell_wrap_12
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[13]);
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_7 y[1]);
static void fc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[3]);
static void gc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[19]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[10]);
static cell_8 hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void hc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[11]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[6]);
static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[4]);
static void ic_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[20]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_9 y[1]);
static void jc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[15]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[64]);
static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[12]);
static void kc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[22]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *problemDef_limits, const char_T *identifier, struct1_T *y);
static void lc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *problemDef_cells, const char_T *identifier, cell_10 *y);
static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static void mc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[21]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_10 *y);
static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[20]);
static void nc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[3]);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_0 y[7]);
static void ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4]);
static void oc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[4]);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_1 y[7]);
static void pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *controls,
  const char_T *identifier, struct2_T *y);
static void pc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[12]);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[153]);
static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static void qc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[20]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_2 y[4]);
static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[7]);
static void rc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4]);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5]);
static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y);
static void sc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[7]);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_3 *y);
static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7]);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[19]);
static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[10]);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[11]);
static real_T vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[20]);
static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[13]);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[15]);
static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[22]);
static void yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[10]);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14])
{
  lc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[6])
{
  static const int32_T dims[2] = { 1, 6 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 6);
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
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6, "geometry")),
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
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 12, "backs")),
                     &thisId, y->backs);
  thisId.fIdentifier = "shifts";
  y->shifts = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 13,
    "shifts")), &thisId);
  thisId.fIdentifier = "sf";
  y->sf = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 14,
    "sf")), &thisId);
  thisId.fIdentifier = "nba";
  y->nba = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 15,
    "nba")), &thisId);
  thisId.fIdentifier = "nbs";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 16, "nbs")),
                     &thisId, y->nbs);
  thisId.fIdentifier = "res";
  y->res = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 17,
    "res")), &thisId);
  thisId.fIdentifier = "params";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 18, "params")),
                     &thisId, y->params);
  thisId.fIdentifier = "numberOfLayers";
  y->numberOfLayers = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 19, "numberOfLayers")), &thisId);
  thisId.fIdentifier = "modelType";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 20,
    "modelType")), &thisId, y->modelType);
  thisId.fIdentifier = "modelFilename";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 21,
    "modelFilename")), &thisId);
  thisId.fIdentifier = "path";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 22, "path")),
                     &thisId, y->path);
  thisId.fIdentifier = "modelLanguage";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 23,
    "modelLanguage")), &thisId);
  thisId.fIdentifier = "fitpars";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 24, "fitpars")),
                     &thisId);
  thisId.fIdentifier = "otherpars";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 25,
    "otherpars")), &thisId);
  thisId.fIdentifier = "fitconstr";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 26,
    "fitconstr")), &thisId);
  thisId.fIdentifier = "otherconstr";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 27,
    "otherconstr")), &thisId);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const cell_13 u)
{
  const mxArray *y;
  int32_T iv11[2];
  emxArray_real_T *b_u;
  int32_T i3;
  int32_T loop_ub;
  const mxArray *b_y;
  real_T c_u;
  const mxArray *c_y;
  const mxArray *m1;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  y = NULL;
  iv11[0] = 1;
  iv11[1] = 6;
  emxInit_real_T(sp, &b_u, 1, true);
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, iv11));
  emlrtSetCell(y, 0, c_emlrt_marshallOut(sp, u.f1));
  emlrtSetCell(y, 1, c_emlrt_marshallOut(sp, u.f2));
  emlrtSetCell(y, 2, d_emlrt_marshallOut(sp, u.f3));
  emlrtSetCell(y, 3, d_emlrt_marshallOut(sp, u.f4));
  emlrtSetCell(y, 4, c_emlrt_marshallOut(sp, u.f5));
  i3 = b_u->size[0];
  b_u->size[0] = u.f6->size[0];
  emxEnsureCapacity_real_T(b_u, i3);
  loop_ub = u.f6->size[0];
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_u->data[i3] = u.f6->data[i3];
  }

  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(1, *(int32_T (*)[1])u.f6->size));
  i3 = 0;
  loop_ub = u.f6->size[0];
  while (i3 < loop_ub) {
    c_u = b_u->data[i3];
    c_y = NULL;
    m1 = emlrtCreateDoubleScalar(c_u);
    emlrtAssign(&c_y, m1);
    emlrtSetCell(b_y, i3, c_y);
    i3++;
  }

  emxFree_real_T(&b_u);
  emlrtSetCell(y, 5, b_y);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[21])
{
  mc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void bc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtDestroyArray(&src);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7])
{
  tb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp, const
  emxArray_cell_wrap_11 *u)
{
  const mxArray *y;
  int32_T i4;
  int32_T n;
  emxArray_real_T *b_u;
  int32_T i5;
  int32_T loop_ub;
  const mxArray *b_y;
  const mxArray *m2;
  real_T *pData;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(1, *(int32_T (*)[1])u->size));
  i4 = 0;
  n = u->size[0];
  emxInit_real_T(sp, &b_u, 2, true);
  while (i4 < n) {
    i5 = b_u->size[0] * b_u->size[1];
    b_u->size[0] = u->data[i4].f1->size[0];
    b_u->size[1] = 2;
    emxEnsureCapacity_real_T(b_u, i5);
    loop_ub = u->data[i4].f1->size[0] * u->data[i4].f1->size[1];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_u->data[i5] = u->data[i4].f1->data[i5];
    }

    b_y = NULL;
    m2 = emlrtCreateNumericArray(2, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
      mxREAL);
    pData = emlrtMxGetPr(m2);
    i5 = 0;
    for (loop_ub = 0; loop_ub < b_u->size[0]; loop_ub++) {
      pData[i5] = b_u->data[loop_ub];
      i5++;
    }

    for (loop_ub = 0; loop_ub < b_u->size[0]; loop_ub++) {
      pData[i5] = b_u->data[loop_ub + b_u->size[0]];
      i5++;
    }

    emlrtAssign(&b_y, m2);
    emlrtSetCell(y, i4, b_y);
    i4++;
  }

  emxFree_real_T(&b_u);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_4 y[2])
{
  emlrtMsgIdentifier thisId;
  int32_T iv5[2];
  boolean_T bv5[2];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv5[0] = 1;
  bv5[0] = false;
  iv5[1] = 2;
  bv5[1] = false;
  emlrtCheckCell(sp, parentId, u, 2U, iv5, bv5);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  x_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 0)), &thisId,
                     y[0].f1);
  sprintf(&str[0], "%d", 2);
  thisId.fIdentifier = &str[0];
  x_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 1)), &thisId,
                     y[1].f1);
  emlrtDestroyArray(&u);
}

static void cc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[64])
{
  static const int32_T dims[2] = { 1, 64 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 64);
  emlrtDestroyArray(&src);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[10])
{
  ub_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *d_emlrt_marshallOut(const emlrtStack *sp, const
  emxArray_cell_wrap_12 *u)
{
  const mxArray *y;
  int32_T i6;
  int32_T n;
  emxArray_real_T *b_u;
  int32_T i7;
  int32_T loop_ub;
  const mxArray *b_y;
  const mxArray *m3;
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
    b_u->size[1] = 3;
    emxEnsureCapacity_real_T(b_u, i7);
    loop_ub = u->data[i6].f1->size[0] * u->data[i6].f1->size[1];
    for (i7 = 0; i7 < loop_ub; i7++) {
      b_u->data[i7] = u->data[i6].f1->data[i7];
    }

    b_y = NULL;
    m3 = emlrtCreateNumericArray(2, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
      mxREAL);
    pData = emlrtMxGetPr(m3);
    i7 = 0;
    for (loop_ub = 0; loop_ub < b_u->size[0]; loop_ub++) {
      pData[i7] = b_u->data[loop_ub];
      i7++;
    }

    for (loop_ub = 0; loop_ub < b_u->size[0]; loop_ub++) {
      pData[i7] = b_u->data[loop_ub + b_u->size[0]];
      i7++;
    }

    for (loop_ub = 0; loop_ub < b_u->size[0]; loop_ub++) {
      pData[i7] = b_u->data[loop_ub + (b_u->size[0] << 1)];
      i7++;
    }

    emlrtAssign(&b_y, m3);
    emlrtSetCell(y, i6, b_y);
    i6++;
  }

  emxFree_real_T(&b_u);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_5 y[1])
{
  emlrtMsgIdentifier thisId;
  int32_T iv6[1];
  boolean_T bv6[1];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv6[0] = 1;
  bv6[0] = false;
  emlrtCheckCell(sp, parentId, u, 1U, iv6, bv6);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 0)), &thisId,
                     y[0].f1);
  emlrtDestroyArray(&u);
}

static void dc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = vb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_6 y[1])
{
  emlrtMsgIdentifier thisId;
  int32_T iv7[1];
  boolean_T bv7[1];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv7[0] = 1;
  bv7[0] = false;
  emlrtCheckCell(sp, parentId, u, 1U, iv7, bv7);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  v_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 0)), &thisId,
                     y[0].f1);
  emlrtDestroyArray(&u);
}

static void ec_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[153])
{
  static const int32_T dims[2] = { 51, 3 };

  real_T (*r3)[153];
  int32_T i10;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r3 = (real_T (*)[153])emlrtMxGetData(src);
  for (i10 = 0; i10 < 153; i10++) {
    ret[i10] = (*r3)[i10];
  }

  emlrtDestroyArray(&src);
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

  int32_T i2;
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
  i2 = b_u->size[0];
  b_u->size[0] = u->ssubs->size[0];
  emxEnsureCapacity_real_T(b_u, i2);
  loop_ub = u->ssubs->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_u->data[i2] = u->ssubs->data[i2];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i2 = 0;
  for (loop_ub = 0; loop_ub < u->ssubs->size[0]; loop_ub++) {
    pData[i2] = u->ssubs->data[loop_ub];
    i2++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "ssubs", b_y, 0);
  i2 = b_u->size[0];
  b_u->size[0] = u->backgrounds->size[0];
  emxEnsureCapacity_real_T(b_u, i2);
  loop_ub = u->backgrounds->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_u->data[i2] = u->backgrounds->data[i2];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i2 = 0;
  for (loop_ub = 0; loop_ub < u->backgrounds->size[0]; loop_ub++) {
    pData[i2] = u->backgrounds->data[loop_ub];
    i2++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "backgrounds", b_y, 1);
  i2 = b_u->size[0];
  b_u->size[0] = u->qshifts->size[0];
  emxEnsureCapacity_real_T(b_u, i2);
  loop_ub = u->qshifts->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_u->data[i2] = u->qshifts->data[i2];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i2 = 0;
  for (loop_ub = 0; loop_ub < u->qshifts->size[0]; loop_ub++) {
    pData[i2] = u->qshifts->data[loop_ub];
    i2++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "qshifts", b_y, 2);
  i2 = b_u->size[0];
  b_u->size[0] = u->scalefactors->size[0];
  emxEnsureCapacity_real_T(b_u, i2);
  loop_ub = u->scalefactors->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_u->data[i2] = u->scalefactors->data[i2];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i2 = 0;
  for (loop_ub = 0; loop_ub < u->scalefactors->size[0]; loop_ub++) {
    pData[i2] = u->scalefactors->data[loop_ub];
    i2++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "scalefactors", b_y, 3);
  i2 = b_u->size[0];
  b_u->size[0] = u->nbairs->size[0];
  emxEnsureCapacity_real_T(b_u, i2);
  loop_ub = u->nbairs->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_u->data[i2] = u->nbairs->data[i2];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i2 = 0;
  for (loop_ub = 0; loop_ub < u->nbairs->size[0]; loop_ub++) {
    pData[i2] = u->nbairs->data[loop_ub];
    i2++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "nbairs", b_y, 4);
  i2 = b_u->size[0];
  b_u->size[0] = u->nbsubs->size[0];
  emxEnsureCapacity_real_T(b_u, i2);
  loop_ub = u->nbsubs->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_u->data[i2] = u->nbsubs->data[i2];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i2 = 0;
  for (loop_ub = 0; loop_ub < u->nbsubs->size[0]; loop_ub++) {
    pData[i2] = u->nbsubs->data[loop_ub];
    i2++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "nbsubs", b_y, 5);
  i2 = b_u->size[0];
  b_u->size[0] = u->resolutions->size[0];
  emxEnsureCapacity_real_T(b_u, i2);
  loop_ub = u->resolutions->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_u->data[i2] = u->resolutions->data[i2];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i2 = 0;
  for (loop_ub = 0; loop_ub < u->resolutions->size[0]; loop_ub++) {
    pData[i2] = u->resolutions->data[loop_ub];
    i2++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "resolutions", b_y, 6);
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 2, sv1));
  i2 = b_u->size[0];
  b_u->size[0] = u->calculations.all_chis->size[0];
  emxEnsureCapacity_real_T(b_u, i2);
  loop_ub = u->calculations.all_chis->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_u->data[i2] = u->calculations.all_chis->data[i2];
  }

  c_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i2 = 0;
  for (loop_ub = 0; loop_ub < u->calculations.all_chis->size[0]; loop_ub++) {
    pData[i2] = u->calculations.all_chis->data[loop_ub];
    i2++;
  }

  emlrtAssign(&c_y, m0);
  emlrtSetFieldR2017b(b_y, 0, "all_chis", c_y, 0);
  c_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->calculations.sum_chi);
  emlrtAssign(&c_y, m0);
  emlrtSetFieldR2017b(b_y, 0, "sum_chi", c_y, 1);
  emlrtSetFieldR2017b(y, 0, "calculations", b_y, 7);
  i2 = b_u->size[0];
  b_u->size[0] = u->allSubRough->size[0];
  emxEnsureCapacity_real_T(b_u, i2);
  loop_ub = u->allSubRough->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_u->data[i2] = u->allSubRough->data[i2];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i2 = 0;
  loop_ub = 0;
  emxFree_real_T(&b_u);
  while (loop_ub < u->allSubRough->size[0]) {
    pData[i2] = u->allSubRough->data[loop_ub];
    i2++;
    loop_ub++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "allSubRough", b_y, 8);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
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

static void emxFreeStruct_cell_13(cell_13 *pStruct)
{
  emxFree_cell_wrap_11(&pStruct->f1);
  emxFree_cell_wrap_11(&pStruct->f2);
  emxFree_cell_wrap_12(&pStruct->f3);
  emxFree_cell_wrap_12(&pStruct->f4);
  emxFree_cell_wrap_11(&pStruct->f5);
  emxFree_real_T(&pStruct->f6);
}

static void emxFreeStruct_cell_wrap_11(cell_wrap_11 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

static void emxFreeStruct_cell_wrap_12(cell_wrap_12 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
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

static void emxFree_cell_wrap_11(emxArray_cell_wrap_11 **pEmxArray)
{
  int32_T numEl;
  int32_T i;
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

static void emxFree_cell_wrap_12(emxArray_cell_wrap_12 **pEmxArray)
{
  int32_T numEl;
  int32_T i;
  if (*pEmxArray != (emxArray_cell_wrap_12 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_12 *)NULL) {
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

static void emxInitStruct_cell_13(const emlrtStack *sp, cell_13 *pStruct,
  boolean_T doPush)
{
  emxInit_cell_wrap_11(sp, &pStruct->f1, 1, doPush);
  emxInit_cell_wrap_11(sp, &pStruct->f2, 1, doPush);
  emxInit_cell_wrap_12(sp, &pStruct->f3, 1, doPush);
  emxInit_cell_wrap_12(sp, &pStruct->f4, 1, doPush);
  emxInit_cell_wrap_11(sp, &pStruct->f5, 1, doPush);
  emxInit_real_T(sp, &pStruct->f6, 1, doPush);
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

static void emxInit_cell_wrap_11(const emlrtStack *sp, emxArray_cell_wrap_11
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_11 *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_cell_wrap_11 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_11));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_cell_wrap_11);
  }

  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_11 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_cell_wrap_12(const emlrtStack *sp, emxArray_cell_wrap_12
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_12 *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_cell_wrap_12 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_12));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_cell_wrap_12);
  }

  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_12 *)NULL;
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

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[13])
{
  wb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_7 y[1])
{
  emlrtMsgIdentifier thisId;
  int32_T iv8[1];
  boolean_T bv8[1];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv8[0] = 1;
  bv8[0] = false;
  emlrtCheckCell(sp, parentId, u, 1U, iv8, bv8);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  gb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 0)), &thisId,
                      y[0].f1);
  emlrtDestroyArray(&u);
}

static void fc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[5])
{
  static const int32_T dims[2] = { 1, 5 };

  real_T (*r4)[5];
  int32_T i11;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r4 = (real_T (*)[5])emlrtMxGetData(src);
  for (i11 = 0; i11 < 5; i11++) {
    ret[i11] = (*r4)[i11];
  }

  emlrtDestroyArray(&src);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  xb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[3])
{
  nc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void gc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[19])
{
  static const int32_T dims[2] = { 1, 19 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 19);
  emlrtDestroyArray(&src);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[10])
{
  yb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static cell_8 hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  cell_8 y;
  emlrtMsgIdentifier thisId;
  int32_T iv9[2];
  boolean_T bv9[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv9[0] = 1;
  bv9[0] = false;
  iv9[1] = 2;
  bv9[1] = false;
  emlrtCheckCell(sp, parentId, u, 2U, iv9, bv9);
  thisId.fIdentifier = "1";
  gb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 0)), &thisId,
                      y.f1);
  thisId.fIdentifier = "2";
  ib_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 1)), &thisId,
                      y.f2);
  emlrtDestroyArray(&u);
  return y;
}

static void hc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[11])
{
  static const int32_T dims[2] = { 1, 11 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 11);
  emlrtDestroyArray(&src);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[6])
{
  ac_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[4])
{
  oc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ic_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[20])
{
  static const int32_T dims[2] = { 1, 20 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 20);
  emlrtDestroyArray(&src);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  bc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_9 y[1])
{
  emlrtMsgIdentifier thisId;
  int32_T iv10[1];
  boolean_T bv10[1];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv10[0] = 1;
  bv10[0] = false;
  emlrtCheckCell(sp, parentId, u, 1U, iv10, bv10);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  kb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 0)), &thisId,
                      y[0].f1);
  emlrtDestroyArray(&u);
}

static void jc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[15])
{
  static const int32_T dims[2] = { 1, 15 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 15);
  emlrtDestroyArray(&src);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[64])
{
  cc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[12])
{
  pc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void kc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[22])
{
  static const int32_T dims[2] = { 1, 22 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 22);
  emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  dc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *problemDef_limits, const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  mb_emlrt_marshallIn(sp, emlrtAlias(problemDef_limits), &thisId, y);
  emlrtDestroyArray(&problemDef_limits);
}

static void lc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = { 1, 14 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 14);
  emlrtDestroyArray(&src);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *problemDef_cells, const char_T *identifier, cell_10 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  n_emlrt_marshallIn(sp, emlrtAlias(problemDef_cells), &thisId, y);
  emlrtDestroyArray(&problemDef_cells);
}

static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
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
  nb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "params")),
                      &thisId, y->params);
  thisId.fIdentifier = "backs";
  ob_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "backs")),
                      &thisId, y->backs);
  thisId.fIdentifier = "scales";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "scales")),
                     &thisId, y->scales);
  thisId.fIdentifier = "shifts";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "shifts")),
                     &thisId, y->shifts);
  thisId.fIdentifier = "nba";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4, "nba")),
                     &thisId, y->nba);
  thisId.fIdentifier = "nbs";
  ob_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5, "nbs")),
                      &thisId, y->nbs);
  thisId.fIdentifier = "res";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6, "res")),
                     &thisId, y->res);
  emlrtDestroyArray(&u);
}

static void mc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[21])
{
  static const int32_T dims[2] = { 1, 21 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 21);
  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_10 *y)
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
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 0)), &thisId,
                     y->f1);
  thisId.fIdentifier = "2";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 1)), &thisId,
                     y->f2);
  thisId.fIdentifier = "3";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 2)), &thisId,
                     y->f3);
  thisId.fIdentifier = "4";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 3)), &thisId,
                     y->f4);
  thisId.fIdentifier = "5";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 4)), &thisId,
                     y->f5);
  thisId.fIdentifier = "6";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 5)), &thisId,
                     y->f6);
  thisId.fIdentifier = "7";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 6)), &thisId,
                     &y->f7);
  thisId.fIdentifier = "8";
  cb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 7)), &thisId,
                      y->f8);
  thisId.fIdentifier = "9";
  db_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 8)), &thisId,
                      y->f9);
  thisId.fIdentifier = "10";
  eb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 9)), &thisId,
                      y->f10);
  thisId.fIdentifier = "11";
  fb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 10)), &thisId,
                      y->f11);
  thisId.fIdentifier = "12";
  y->f12 = hb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 11)),
    &thisId);
  thisId.fIdentifier = "13";
  jb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 12)), &thisId,
                      y->f13);
  emlrtDestroyArray(&u);
}

static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[20])
{
  qc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void nc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[3])
{
  static const int32_T dims[2] = { 1, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 3);
  emlrtDestroyArray(&src);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_0 y[7])
{
  emlrtMsgIdentifier thisId;
  int32_T iv1[2];
  boolean_T bv1[2];
  int32_T i0;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv1[0] = 1;
  bv1[0] = false;
  iv1[1] = 7;
  bv1[1] = false;
  emlrtCheckCell(sp, parentId, u, 2U, iv1, bv1);
  for (i0 = 0; i0 < 7; i0++) {
    sprintf(&str[0], "%d", i0 + 1);
    thisId.fIdentifier = &str[0];
    g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i0)),
                       &thisId, y[i0].f1);
  }

  emlrtDestroyArray(&u);
}

static void ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4])
{
  rc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void oc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[4])
{
  static const int32_T dims[2] = { 1, 4 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 4);
  emlrtDestroyArray(&src);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_1 y[7])
{
  emlrtMsgIdentifier thisId;
  int32_T iv2[2];
  boolean_T bv2[2];
  int32_T i1;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv2[0] = 1;
  bv2[0] = false;
  iv2[1] = 7;
  bv2[1] = false;
  emlrtCheckCell(sp, parentId, u, 2U, iv2, bv2);
  for (i1 = 0; i1 < 7; i1++) {
    sprintf(&str[0], "%d", i1 + 1);
    thisId.fIdentifier = &str[0];
    q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i1)),
                       &thisId, y[i1].f1);
  }

  emlrtDestroyArray(&u);
}

static void pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *controls,
  const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  qb_emlrt_marshallIn(sp, emlrtAlias(controls), &thisId, y);
  emlrtDestroyArray(&controls);
}

static void pc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[12])
{
  static const int32_T dims[2] = { 1, 12 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 12);
  emlrtDestroyArray(&src);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[153])
{
  ec_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
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
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "para")),
                     &thisId, y->para);
  thisId.fIdentifier = "proc";
  rb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "proc")),
                      &thisId, y->proc);
  thisId.fIdentifier = "display";
  ib_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "display")),
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
  y->strategy = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    12, "strategy")), &thisId);
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
  sb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 17, "checks")),
                      &thisId, &y->checks);
  emlrtDestroyArray(&u);
}

static void qc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[20])
{
  static const int32_T dims[2] = { 10, 2 };

  real_T (*r5)[20];
  int32_T i12;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r5 = (real_T (*)[20])emlrtMxGetData(src);
  for (i12 = 0; i12 < 20; i12++) {
    ret[i12] = (*r5)[i12];
  }

  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_2 y[4])
{
  emlrtMsgIdentifier thisId;
  int32_T iv3[1];
  boolean_T bv3[1];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv3[0] = 4;
  bv3[0] = false;
  emlrtCheckCell(sp, parentId, u, 1U, iv3, bv3);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 0)), &thisId,
                     y[0].f1);
  sprintf(&str[0], "%d", 2);
  thisId.fIdentifier = &str[0];
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 1)), &thisId,
                     y[1].f1);
  sprintf(&str[0], "%d", 3);
  thisId.fIdentifier = &str[0];
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 2)), &thisId,
                     y[2].f1);
  sprintf(&str[0], "%d", 4);
  thisId.fIdentifier = &str[0];
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 3)), &thisId,
                     y[3].f1);
  emlrtDestroyArray(&u);
}

static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[7])
{
  sc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void rc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4])
{
  static const int32_T dims[2] = { 2, 2 };

  real_T (*r6)[4];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r6 = (real_T (*)[4])emlrtMxGetData(src);
  ret[0] = (*r6)[0];
  ret[1] = (*r6)[1];
  ret[2] = (*r6)[2];
  ret[3] = (*r6)[3];
  emlrtDestroyArray(&src);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[5])
{
  fc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
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
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "params_fitYesNo")), &thisId, y->params_fitYesNo);
  thisId.fIdentifier = "backs_fitYesNo";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "backs_fitYesNo")), &thisId, y->backs_fitYesNo);
  thisId.fIdentifier = "shifts_fitYesNo";
  y->shifts_fitYesNo = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 2, "shifts_fitYesNo")), &thisId);
  thisId.fIdentifier = "scales_fitYesNo";
  y->scales_fitYesNo = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 3, "scales_fitYesNo")), &thisId);
  thisId.fIdentifier = "nbairs_fitYesNo";
  y->nbairs_fitYesNo = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 4, "nbairs_fitYesNo")), &thisId);
  thisId.fIdentifier = "nbsubs_fitYesNo";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5,
    "nbsubs_fitYesNo")), &thisId, y->nbsubs_fitYesNo);
  thisId.fIdentifier = "resol_fitYesNo";
  y->resol_fitYesNo = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 6, "resol_fitYesNo")), &thisId);
  emlrtDestroyArray(&u);
}

static void sc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[7])
{
  static const int32_T dims[2] = { 1, 7 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 7);
  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_3 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv4[2];
  boolean_T bv4[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv4[0] = 1;
  bv4[0] = false;
  iv4[1] = 10;
  bv4[1] = false;
  emlrtCheckCell(sp, parentId, u, 2U, iv4, bv4);
  thisId.fIdentifier = "1";
  u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 0)), &thisId,
                     y->f1);
  thisId.fIdentifier = "2";
  v_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 1)), &thisId,
                     y->f2);
  thisId.fIdentifier = "3";
  w_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 2)), &thisId,
                     y->f3);
  thisId.fIdentifier = "4";
  x_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 3)), &thisId,
                     y->f4);
  thisId.fIdentifier = "5";
  y_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 4)), &thisId,
                     y->f5);
  thisId.fIdentifier = "6";
  ab_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 5)), &thisId,
                      y->f6);
  thisId.fIdentifier = "7";
  u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 6)), &thisId,
                     y->f7);
  thisId.fIdentifier = "8";
  ab_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 7)), &thisId,
                      y->f8);
  thisId.fIdentifier = "9";
  bb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 8)), &thisId,
                      y->f9);
  thisId.fIdentifier = "10";
  ab_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 9)), &thisId,
                      y->f10);
  emlrtDestroyArray(&u);
}

static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7])
{
  static const int32_T dims[2] = { 1, 7 };

  real_T (*r0)[7];
  int32_T i8;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r0 = (real_T (*)[7])emlrtMxGetData(src);
  for (i8 = 0; i8 < 7; i8++) {
    ret[i8] = (*r0)[i8];
  }

  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[19])
{
  gc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[10])
{
  static const int32_T dims[2] = { 1, 10 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 10);
  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[11])
{
  hc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[20])
{
  ic_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[13])
{
  static const int32_T dims[2] = { 1, 13 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 13);
  emlrtDestroyArray(&src);
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[15])
{
  jc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2] = { 1, 2 };

  real_T (*r1)[2];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r1 = (real_T (*)[2])emlrtMxGetData(src);
  ret[0] = (*r1)[0];
  ret[1] = (*r1)[1];
  emlrtDestroyArray(&src);
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[22])
{
  kc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[10])
{
  static const int32_T dims[2] = { 1, 10 };

  real_T (*r2)[10];
  int32_T i9;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r2 = (real_T (*)[10])emlrtMxGetData(src);
  for (i9 = 0; i9 < 10; i9++) {
    ret[i9] = (*r2)[i9];
  }

  emlrtDestroyArray(&src);
}

void reflectivity_calculation_api(const mxArray * const prhs[4], int32_T nlhs,
  const mxArray *plhs[2])
{
  struct4_T problem;
  cell_13 result;
  struct0_T problemDef;
  cell_10 problemDef_cells;
  struct1_T problemDef_limits;
  struct2_T controls;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInitStruct_struct4_T(&st, &problem, true);
  emxInitStruct_cell_13(&st, &result, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "problemDef", &problemDef);
  m_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "problemDef_cells",
                     &problemDef_cells);
  lb_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "problemDef_limits",
                      &problemDef_limits);
  pb_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "controls", &controls);

  /* Invoke the target function */
  reflectivity_calculation(&problemDef, &problemDef_cells, &problemDef_limits,
    &controls, &problem, &result);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, &problem);
  emxFreeStruct_struct4_T(&problem);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(&st, result);
  }

  emxFreeStruct_cell_13(&result);
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
