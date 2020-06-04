/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_standardTF_custlay_single_api.c
 *
 * Code generation for function '_coder_standardTF_custlay_single_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "_coder_standardTF_custlay_single_api.h"
#include "standardTF_custlay_single_emxutil.h"
#include "standardTF_custlay_single_data.h"

/* Variable Definitions */
static emlrtRTEInfo ob_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "_coder_standardTF_custlay_single_api",/* fName */
  ""                                   /* pName */
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
static const mxArray *e_emlrt_marshallOut(const emxArray_cell_wrap_4 *u);
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *resam, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y);
static const mxArray *f_emlrt_marshallOut(const emxArray_real_T *u);
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[153]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nbairs,
  const char_T *identifier, emxArray_real_T *y);
static const mxArray *g_emlrt_marshallOut(const emxArray_cell_wrap_4 *u);
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
  emxArray_cell_wrap_5 *u);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_0 *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *allData,
  const char_T *identifier, emxArray_cell_wrap_1 *y);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_1 *y);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[153]);
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

  int32_T iv17[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv6[0],
    iv17);
  ret->size[0] = iv17[0];
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
  int32_T i24;
  int32_T n;
  const cell_wrap_3 *r5;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, *(int32_T (*)[2])u->size));
  i24 = 0;
  n = u->size[0];
  while (i24 < n) {
    r5 = &u->data[i24];
    emlrtSetCell(y, i24, c_emlrt_marshallOut(r5->f1));
    i24++;
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
  int32_T i25;
  int32_T i;
  int32_T b_i;
  y = NULL;
  m1 = emlrtCreateNumericArray(2, *(int32_T (*)[1])u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = (real_T *)mxGetPr(m1);
  i25 = 0;
  for (i = 0; i < 2; i++) {
    for (b_i = 0; b_i < u->size[0]; b_i++) {
      pData[i25] = u->data[b_i + u->size[0] * i];
      i25++;
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

  int32_T iv18[2];
  int32_T i33;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims, &bv7[0],
    iv18);
  i33 = ret->size[0] * ret->size[1];
  ret->size[0] = iv18[0];
  ret->size[1] = iv18[1];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i33, (int32_T)sizeof(char_T),
                    (emlrtRTEInfo *)NULL);
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
  int32_T i26;
  int32_T n;
  const cell_wrap_3 *r6;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, *(int32_T (*)[2])u->size));
  i26 = 0;
  n = u->size[0];
  while (i26 < n) {
    r6 = &u->data[i26];
    emlrtSetCell(y, i26, c_emlrt_marshallOut(r6->f1));
    i26++;
  }

  return y;
}

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  boolean_T bv8[2] = { false, true };

  int32_T iv19[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv8[0],
    iv19);
  ret->size[0] = iv19[0];
  ret->size[1] = iv19[1];
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

static const mxArray *e_emlrt_marshallOut(const emxArray_cell_wrap_4 *u)
{
  const mxArray *y;
  int32_T i27;
  int32_T n;
  const cell_wrap_4 *r7;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, *(int32_T (*)[2])u->size));
  i27 = 0;
  n = u->size[0];
  while (i27 < n) {
    r7 = &u->data[i27];
    emlrtSetCell(y, i27, f_emlrt_marshallOut(r7->f1));
    i27++;
  }

  return y;
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2] = { 1, 2 };

  int32_T i34;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i34 = 0; i34 < 2; i34++) {
    ret[i34] = (*(real_T (*)[2])mxGetData(src))[i34];
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
  static const int32_T iv16[1] = { 0 };

  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv16, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m0, u->size, 1);
  emlrtAssign(&y, m0);
  return y;
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
  int32_T i28;
  int32_T i;
  int32_T b_i;
  y = NULL;
  m2 = emlrtCreateNumericArray(2, *(int32_T (*)[1])u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = (real_T *)mxGetPr(m2);
  i28 = 0;
  for (i = 0; i < 3; i++) {
    for (b_i = 0; b_i < u->size[0]; b_i++) {
      pData[i28] = u->data[b_i + u->size[0] * i];
      i28++;
    }
  }

  emlrtAssign(&y, m2);
  return y;
}

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[153])
{
  static const int32_T dims[2] = { 51, 3 };

  int32_T i35;
  int32_T i36;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i35 = 0; i35 < 3; i35++) {
    for (i36 = 0; i36 < 51; i36++) {
      ret[i36 + 51 * i35] = (*(real_T (*)[153])mxGetData(src))[i36 + 51 * i35];
    }
  }

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

static const mxArray *g_emlrt_marshallOut(const emxArray_cell_wrap_4 *u)
{
  const mxArray *y;
  int32_T i29;
  int32_T n;
  const cell_wrap_4 *r8;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, *(int32_T (*)[2])u->size));
  i29 = 0;
  n = u->size[0];
  while (i29 < n) {
    r8 = &u->data[i29];
    emlrtSetCell(y, i29, f_emlrt_marshallOut(r8->f1));
    i29++;
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
  int32_T i30;
  int32_T n;
  const cell_wrap_3 *r9;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, *(int32_T (*)[2])u->size));
  i30 = 0;
  n = u->size[0];
  while (i30 < n) {
    r9 = &u->data[i30];
    emlrtSetCell(y, i30, c_emlrt_marshallOut(r9->f1));
    i30++;
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
  emxArray_cell_wrap_5 *u)
{
  const mxArray *y;
  emxArray_real_T *b_u;
  int32_T i31;
  int32_T n;
  emxArray_real_T *r10;
  const cell_wrap_5 *r11;
  int32_T i32;
  int32_T loop_ub;
  int32_T i;
  const mxArray *b_y;
  const mxArray *m3;
  real_T *pData;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_u, 2, (emlrtRTEInfo *)NULL, true);
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, *(int32_T (*)[2])u->size));
  i31 = 0;
  n = u->size[0];
  emxInit_real_T1(sp, &r10, 1, (emlrtRTEInfo *)NULL, true);
  while (i31 < n) {
    r11 = &u->data[i31];
    i32 = b_u->size[0] * b_u->size[1];
    b_u->size[0] = r11->f1->size[0];
    b_u->size[1] = r11->f1->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)b_u, i32, (int32_T)sizeof(real_T),
                      (emlrtRTEInfo *)NULL);
    i32 = r11->f1->size[0];
    loop_ub = r11->f1->size[1];
    i = r10->size[0];
    r10->size[0] = i32 * loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r10, i, (int32_T)sizeof(real_T),
                      (emlrtRTEInfo *)NULL);
    loop_ub *= i32;
    for (i32 = 0; i32 < loop_ub; i32++) {
      r10->data[i32] = r11->f1->data[i32];
    }

    loop_ub = r10->size[0];
    for (i32 = 0; i32 < loop_ub; i32++) {
      b_u->data[i32] = r10->data[i32];
    }

    b_y = NULL;
    m3 = emlrtCreateNumericArray(2, *(int32_T (*)[1])b_u->size, mxDOUBLE_CLASS,
      mxREAL);
    pData = (real_T *)mxGetPr(m3);
    i32 = 0;
    for (loop_ub = 0; loop_ub < b_u->size[1]; loop_ub++) {
      for (i = 0; i < b_u->size[0]; i++) {
        pData[i32] = b_u->data[i + b_u->size[0] * loop_ub];
        i32++;
      }
    }

    emlrtAssign(&b_y, m3);
    emlrtSetCell(y, i31, b_y);
    i31++;
  }

  emxFree_real_T(&r10);
  emxFree_real_T(&b_u);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_0 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv10[2];
  int32_T i18;
  static const boolean_T bv0[2] = { false, true };

  int32_T sizes[2];
  int32_T n;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (i18 = 0; i18 < 2; i18++) {
    iv10[i18] = 1 + -2 * i18;
  }

  emlrtCheckVsCell(sp, parentId, u, 2U, iv10, bv0, sizes);
  i18 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i18, (int32_T)sizeof(cell_wrap_0),
                    (emlrtRTEInfo *)NULL);
  n = y->size[1];
  for (i18 = 0; i18 < n; i18++) {
    sprintf(&str[0], "%d", i18 + 1);
    thisId.fIdentifier = &str[0];
    k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i18)),
                       &thisId, y->data[i18].f1);
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
  int32_T iv11[2];
  int32_T i19;
  static const boolean_T bv1[2] = { false, true };

  int32_T sizes[2];
  int32_T n;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (i19 = 0; i19 < 2; i19++) {
    iv11[i19] = 1 + -2 * i19;
  }

  emlrtCheckVsCell(sp, parentId, u, 2U, iv11, bv1, sizes);
  i19 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i19, (int32_T)sizeof(cell_wrap_1),
                    (emlrtRTEInfo *)NULL);
  n = y->size[1];
  for (i19 = 0; i19 < n; i19++) {
    sprintf(&str[0], "%d", i19 + 1);
    thisId.fIdentifier = &str[0];
    n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i19)),
                       &thisId, y->data[i19].f1);
  }

  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[153])
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
  int32_T iv12[2];
  int32_T i20;
  static const boolean_T bv2[2] = { false, true };

  int32_T sizes[2];
  int32_T n;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (i20 = 0; i20 < 2; i20++) {
    iv12[i20] = 1 + -2 * i20;
  }

  emlrtCheckVsCell(sp, parentId, u, 2U, iv12, bv2, sizes);
  i20 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i20, (int32_T)sizeof(cell_wrap_0),
                    (emlrtRTEInfo *)NULL);
  n = y->size[1];
  for (i20 = 0; i20 < n; i20++) {
    sprintf(&str[0], "%d", i20 + 1);
    thisId.fIdentifier = &str[0];
    k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i20)),
                       &thisId, y->data[i20].f1);
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
  int32_T iv13[2];
  int32_T i21;
  static const boolean_T bv3[2] = { false, true };

  int32_T sizes[2];
  int32_T n;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (i21 = 0; i21 < 2; i21++) {
    iv13[i21] = 1 + -2 * i21;
  }

  emlrtCheckVsCell(sp, parentId, u, 2U, iv13, bv3, sizes);
  i21 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i21, (int32_T)sizeof(cell_wrap_0),
                    (emlrtRTEInfo *)NULL);
  n = y->size[1];
  for (i21 = 0; i21 < n; i21++) {
    sprintf(&str[0], "%d", i21 + 1);
    thisId.fIdentifier = &str[0];
    k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i21)),
                       &thisId, y->data[i21].f1);
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
  int32_T iv14[2];
  int32_T i22;
  static const boolean_T bv4[2] = { false, true };

  int32_T sizes[2];
  int32_T n;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (i22 = 0; i22 < 2; i22++) {
    iv14[i22] = 1 + -2 * i22;
  }

  emlrtCheckVsCell(sp, parentId, u, 2U, iv14, bv4, sizes);
  i22 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i22, (int32_T)sizeof(cell_wrap_0),
                    (emlrtRTEInfo *)NULL);
  n = y->size[1];
  for (i22 = 0; i22 < n; i22++) {
    sprintf(&str[0], "%d", i22 + 1);
    thisId.fIdentifier = &str[0];
    k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i22)),
                       &thisId, y->data[i22].f1);
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
  int32_T iv15[2];
  int32_T i23;
  static const boolean_T bv5[2] = { false, true };

  int32_T sizes[2];
  int32_T n;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (i23 = 0; i23 < 2; i23++) {
    iv15[i23] = 1 + -2 * i23;
  }

  emlrtCheckVsCell(sp, parentId, u, 2U, iv15, bv5, sizes);
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  n = y->size[1];
  for (i23 = 0; i23 < n; i23++) {
    sprintf(&str[0], "%d", i23 + 1);
    thisId.fIdentifier = &str[0];
    w_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i23)),
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

void standardTF_custlay_single_api(const mxArray * const prhs[31], const mxArray
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
  emxArray_cell_wrap_4 *shifted_data;
  emxArray_cell_wrap_4 *layerSlds;
  emxArray_cell_wrap_3 *sldProfiles;
  emxArray_cell_wrap_5 *allLayers;
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
  emxInit_real_T1(&st, &resam, 1, &ob_emlrtRTEI, true);
  emxInit_char_T(&st, &geometry, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &nbairs, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &nbsubs, 2, &ob_emlrtRTEI, true);
  emxInit_cell_wrap_0(&st, &repeats, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &cBacks, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &cShifts, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &cScales, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &cNbas, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &cNbss, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &cRes, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &backs, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &shifts, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &sf, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &nba, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &nbs, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &res, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &dataPresent, 2, &ob_emlrtRTEI, true);
  emxInit_cell_wrap_1(&st, &allData, 2, &ob_emlrtRTEI, true);
  emxInit_cell_wrap_0(&st, &dataLimits, 2, &ob_emlrtRTEI, true);
  emxInit_cell_wrap_0(&st, &simLimits, 2, &ob_emlrtRTEI, true);
  emxInit_cell_wrap_0(&st, &repeatLayers, 2, &ob_emlrtRTEI, true);
  emxInit_real_T(&st, &params, 2, &ob_emlrtRTEI, true);
  emxInit_cell_wrap_2(&st, &contrastLayers, 2, &ob_emlrtRTEI, true);
  emxInit_char_T(&st, &fileHandle, 2, &ob_emlrtRTEI, true);
  emxInit_char_T(&st, &path, 2, &ob_emlrtRTEI, true);
  emxInit_real_T1(&st, &outSsubs, 1, &ob_emlrtRTEI, true);
  emxInit_real_T1(&st, &backgs, 1, &ob_emlrtRTEI, true);
  emxInit_real_T1(&st, &qshifts, 1, &ob_emlrtRTEI, true);
  emxInit_real_T1(&st, &sfs, 1, &ob_emlrtRTEI, true);
  emxInit_real_T1(&st, &nbas, 1, &ob_emlrtRTEI, true);
  emxInit_real_T1(&st, &nbss, 1, &ob_emlrtRTEI, true);
  emxInit_real_T1(&st, &resols, 1, &ob_emlrtRTEI, true);
  emxInit_real_T1(&st, &chis, 1, &ob_emlrtRTEI, true);
  emxInit_cell_wrap_3(&st, &reflectivity, 2, &ob_emlrtRTEI, true);
  emxInit_cell_wrap_3(&st, &Simulation, 2, &ob_emlrtRTEI, true);
  emxInit_cell_wrap_4(&st, &shifted_data, 2, &ob_emlrtRTEI, true);
  emxInit_cell_wrap_4(&st, &layerSlds, 2, &ob_emlrtRTEI, true);
  emxInit_cell_wrap_3(&st, &sldProfiles, 2, &ob_emlrtRTEI, true);
  emxInit_cell_wrap_5(&st, &allLayers, 2, &ob_emlrtRTEI, true);
  emxInit_real_T1(&st, &allRoughs, 1, &ob_emlrtRTEI, true);

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
  standardTF_custlay_single(&st, resam, numberOfContrasts, geometry, nbairs,
    nbsubs, repeats, cBacks, cShifts, cScales, cNbas, cNbss, cRes, backs, shifts,
    sf, nba, nbs, res, dataPresent, allData, dataLimits, simLimits, repeatLayers,
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
  emxFree_cell_wrap_5(&allLayers);
  emxFree_cell_wrap_3(&sldProfiles);
  emxFree_cell_wrap_4(&layerSlds);
  emxFree_cell_wrap_4(&shifted_data);
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

/* End of code generation (_coder_standardTF_custlay_single_api.c) */
