/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * _coder_reflectivity_calculation_api.c
 *
 * Code generation for function '_coder_reflectivity_calculation_api'
 *
 */

/* Include files */
#include "_coder_reflectivity_calculation_api.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_mexutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo gt_emlrtRTEI = {
    1,                                     /* lineNo */
    1,                                     /* colNo */
    "_coder_reflectivity_calculation_api", /* fName */
    ""                                     /* pName */
};

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_cell_wrap_4 *y);

static void ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y_data[], int32_T y_size[2]);

static const mxArray *c_emlrt_marshallOut(const struct4_T *u);

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_cell_wrap_5 *y);

static const mxArray *d_emlrt_marshallOut(const cell_11 u);

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_char_T *y);

static const mxArray *e_emlrt_marshallOut(const emxArray_cell_wrap_9 *u);

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_cell_wrap_6 *y);

static const mxArray *f_emlrt_marshallOut(const emxArray_cell_wrap_10 *u);

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_cell_wrap_7 *y);

static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                cell_wrap_6 y[3]);

static void hb_emlrt_marshallIn(const emlrtStack *sp,
                                const mxArray *problemDef_limits,
                                const char_T *identifier, struct1_T *y);

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct1_T *y);

static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_real_T *y);

static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *controls,
                                const char_T *identifier, struct2_T *y);

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *problemDef,
                               const char_T *identifier, struct0_T *y);

static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct2_T *y);

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct0_T *y);

static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct3_T *y);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_char_T *y);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void q_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *problemDef_cells,
                               const char_T *identifier, cell_8 *y);

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, cell_8 *y);

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_0 *y);

static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_1 *y);

static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_char_T *ret);

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_2 *y);

static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret_data[], int32_T ret_size[2]);

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y_data[], int32_T y_size[2]);

static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_3 *y);

static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret_data[], int32_T ret_size[2]);

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_char_T *ret);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_cell_wrap_4 *y)
{
  cell_wrap_4 *y_data;
  emlrtMsgIdentifier thisId;
  int32_T n;
  int32_T sizes;
  char_T str[11];
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  b = true;
  n = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 1U, &n, &b, &sizes);
  n = y->size[0];
  y->size[0] = sizes;
  emxEnsureCapacity_cell_wrap_4(sp, y, n, (emlrtRTEInfo *)NULL);
  y_data = y->data;
  for (n = 0; n < sizes; n++) {
    sprintf(&str[0], "%d", n + 1);
    thisId.fIdentifier = &str[0];
    bb_emlrt_marshallIn(sp,
                        emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, n)),
                        &thisId, y_data[n].f1.data, y_data[n].f1.size);
  }
  emlrtDestroyArray(&u);
}

static void ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret)
{
  static const int32_T dims[2] = {-1, 2};
  real_T *ret_data;
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {true, false};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y_data[], int32_T y_size[2])
{
  xb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static const mxArray *c_emlrt_marshallOut(const struct4_T *u)
{
  static const char_T *sv[10] = {
      "ssubs",  "backgrounds", "qshifts",      "scalefactors", "nbairs",
      "nbsubs", "resolutions", "calculations", "allSubRough",  "resample"};
  static const char_T *sv1[2] = {"all_chis", "sum_chi"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 10, (const char_T **)&sv[0]));
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ssubs",
                      b_emlrt_marshallOut(u->ssubs), 0);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"backgrounds",
                      b_emlrt_marshallOut(u->backgrounds), 1);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"qshifts",
                      b_emlrt_marshallOut(u->qshifts), 2);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"scalefactors",
                      b_emlrt_marshallOut(u->scalefactors), 3);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"nbairs",
                      b_emlrt_marshallOut(u->nbairs), 4);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"nbsubs",
                      b_emlrt_marshallOut(u->nbsubs), 5);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"resolutions",
                      b_emlrt_marshallOut(u->resolutions), 6);
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv1[0]));
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"all_chis",
                      b_emlrt_marshallOut(u->calculations.all_chis), 0);
  c_y = NULL;
  m = emlrtCreateDoubleScalar(u->calculations.sum_chi);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"sum_chi", c_y, 1);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"calculations", b_y, 7);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"allSubRough",
                      b_emlrt_marshallOut(u->allSubRough), 8);
  d_y = NULL;
  iv[0] = u->resample->size[0];
  iv[1] = u->resample->size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < u->resample->size[1]; b_i++) {
    for (c_i = 0; c_i < u->resample->size[0]; c_i++) {
      pData[i] = u->resample->data[c_i + u->resample->size[0] * b_i];
      i++;
    }
  }
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"resample", d_y, 9);
  return y;
}

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_cell_wrap_5 *y)
{
  static const boolean_T bv[2] = {false, true};
  cell_wrap_5 *y_data;
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  int32_T sizes[2];
  int32_T i;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0], &sizes[0]);
  i = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_cell_wrap_5(sp, y, i, (emlrtRTEInfo *)NULL);
  y_data = y->data;
  for (i = 0; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    db_emlrt_marshallIn(sp,
                        emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                        &thisId, y_data[i].f1);
  }
  emlrtDestroyArray(&u);
}

static const mxArray *d_emlrt_marshallOut(const cell_11 u)
{
  const mxArray *y;
  int32_T iv[2];
  y = NULL;
  iv[0] = 1;
  iv[1] = 6;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv[0]));
  emlrtSetCell(y, 0, e_emlrt_marshallOut(u.f1));
  emlrtSetCell(y, 1, e_emlrt_marshallOut(u.f2));
  emlrtSetCell(y, 2, f_emlrt_marshallOut(u.f3));
  emlrtSetCell(y, 3, f_emlrt_marshallOut(u.f4));
  emlrtSetCell(y, 4, e_emlrt_marshallOut(u.f5));
  emlrtSetCell(y, 5, f_emlrt_marshallOut(u.f6));
  return y;
}

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_char_T *y)
{
  yb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *e_emlrt_marshallOut(const emxArray_cell_wrap_9 *u)
{
  const cell_wrap_9 *u_data;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  u_data = u->data;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(1, &u->size[0]));
  if (0 < u->size[0]) {
    iv[1] = 2;
  }
  for (i = 0; i < u->size[0]; i++) {
    b_y = NULL;
    iv[0] = u_data[i].f1->size[0];
    m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    i1 = 0;
    for (b_i = 0; b_i < u_data[i].f1->size[0]; b_i++) {
      pData[i1] = u_data[i].f1->data[b_i];
      i1++;
    }
    for (b_i = 0; b_i < u_data[i].f1->size[0]; b_i++) {
      pData[i1] = u_data[i].f1->data[b_i + u_data[i].f1->size[0]];
      i1++;
    }
    emlrtAssign(&b_y, m);
    emlrtSetCell(y, i, b_y);
  }
  return y;
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_cell_wrap_6 *y)
{
  static const boolean_T bv[2] = {false, true};
  cell_wrap_6 *y_data;
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  int32_T sizes[2];
  int32_T i;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0], &sizes[0]);
  i = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_cell_wrap_6(sp, y, i, (emlrtRTEInfo *)NULL);
  y_data = y->data;
  for (i = 0; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    o_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                       &thisId, y_data[i].f1);
  }
  emlrtDestroyArray(&u);
}

static const mxArray *f_emlrt_marshallOut(const emxArray_cell_wrap_10 *u)
{
  const cell_wrap_10 *u_data;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  u_data = u->data;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(1, &u->size[0]));
  if (0 < u->size[0]) {
    iv[1] = 3;
  }
  for (i = 0; i < u->size[0]; i++) {
    b_y = NULL;
    iv[0] = u_data[i].f1->size[0];
    m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    i1 = 0;
    for (b_i = 0; b_i < u_data[i].f1->size[0]; b_i++) {
      pData[i1] = u_data[i].f1->data[b_i];
      i1++;
    }
    for (b_i = 0; b_i < u_data[i].f1->size[0]; b_i++) {
      pData[i1] = u_data[i].f1->data[b_i + u_data[i].f1->size[0]];
      i1++;
    }
    for (b_i = 0; b_i < u_data[i].f1->size[0]; b_i++) {
      pData[i1] = u_data[i].f1->data[b_i + u_data[i].f1->size[0] * 2];
      i1++;
    }
    emlrtAssign(&b_y, m);
    emlrtSetCell(y, i, b_y);
  }
  return y;
}

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_cell_wrap_7 *y)
{
  static const boolean_T bv[2] = {false, true};
  cell_wrap_7 *y_data;
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  int32_T sizes[2];
  int32_T i;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0], &sizes[0]);
  i = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_cell_wrap_7(sp, y, i, (emlrtRTEInfo *)NULL);
  y_data = y->data;
  for (i = 0; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    gb_emlrt_marshallIn(sp,
                        emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                        &thisId, y_data[i].f1);
  }
  emlrtDestroyArray(&u);
}

static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                cell_wrap_6 y[3])
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  char_T str[11];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  bv[0] = false;
  iv[0] = 1;
  bv[1] = false;
  iv[1] = 3;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0]);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y[0].f1);
  sprintf(&str[0], "%d", 2);
  thisId.fIdentifier = &str[0];
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                     &thisId, y[1].f1);
  sprintf(&str[0], "%d", 3);
  thisId.fIdentifier = &str[0];
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)),
                     &thisId, y[2].f1);
  emlrtDestroyArray(&u);
}

static void hb_emlrt_marshallIn(const emlrtStack *sp,
                                const mxArray *problemDef_limits,
                                const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  ib_emlrt_marshallIn(sp, emlrtAlias(problemDef_limits), &thisId, y);
  emlrtDestroyArray(&problemDef_limits);
}

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct1_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[7] = {"params", "backs", "scales", "shifts",
                                        "nba",    "nbs",   "res"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 7,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "params";
  jb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                                     (const char_T *)"params")),
                      &thisId, y->params);
  thisId.fIdentifier = "backs";
  jb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                                     (const char_T *)"backs")),
                      &thisId, y->backs);
  thisId.fIdentifier = "scales";
  jb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                                     (const char_T *)"scales")),
                      &thisId, y->scales);
  thisId.fIdentifier = "shifts";
  jb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 3,
                                                     (const char_T *)"shifts")),
                      &thisId, y->shifts);
  thisId.fIdentifier = "nba";
  jb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 4,
                                                     (const char_T *)"nba")),
                      &thisId, y->nba);
  thisId.fIdentifier = "nbs";
  jb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 5,
                                                     (const char_T *)"nbs")),
                      &thisId, y->nbs);
  thisId.fIdentifier = "res";
  jb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 6,
                                                     (const char_T *)"res")),
                      &thisId, y->res);
  emlrtDestroyArray(&u);
}

static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_real_T *y)
{
  ac_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *controls,
                                const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  lb_emlrt_marshallIn(sp, emlrtAlias(controls), &thisId, y);
  emlrtDestroyArray(&controls);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *problemDef,
                               const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  m_emlrt_marshallIn(sp, emlrtAlias(problemDef), &thisId, y);
  emlrtDestroyArray(&problemDef);
}

static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct2_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[25] = {
      "para",        "proc",        "display",    "tolX",
      "tolFun",      "maxFunEvals", "maxIter",    "populationSize",
      "F_weight",    "F_CR",        "VTR",        "numGen",
      "strategy",    "Nlive",       "nmcmc",      "propScale",
      "nsTolerance", "calcSld",     "repeats",    "nsimu",
      "burnin",      "resamPars",   "updateFreq", "updatePlotFreq",
      "checks"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 25,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "para";
  o_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                                    (const char_T *)"para")),
                     &thisId, y->para);
  thisId.fIdentifier = "proc";
  o_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                                    (const char_T *)"proc")),
                     &thisId, y->proc);
  thisId.fIdentifier = "display";
  o_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                                    (const char_T *)"display")),
                     &thisId, y->display);
  thisId.fIdentifier = "tolX";
  y->tolX =
      d_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 3, (const char_T *)"tolX")),
                         &thisId);
  thisId.fIdentifier = "tolFun";
  y->tolFun =
      d_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 4, (const char_T *)"tolFun")),
                         &thisId);
  thisId.fIdentifier = "maxFunEvals";
  y->maxFunEvals = d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 5,
                                     (const char_T *)"maxFunEvals")),
      &thisId);
  thisId.fIdentifier = "maxIter";
  y->maxIter =
      d_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 6, (const char_T *)"maxIter")),
                         &thisId);
  thisId.fIdentifier = "populationSize";
  y->populationSize = d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 7,
                                     (const char_T *)"populationSize")),
      &thisId);
  thisId.fIdentifier = "F_weight";
  y->F_weight = d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 8,
                                     (const char_T *)"F_weight")),
      &thisId);
  thisId.fIdentifier = "F_CR";
  y->F_CR =
      d_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 9, (const char_T *)"F_CR")),
                         &thisId);
  thisId.fIdentifier = "VTR";
  y->VTR =
      d_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 10,
                                                        (const char_T *)"VTR")),
                         &thisId);
  thisId.fIdentifier = "numGen";
  y->numGen =
      d_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 11, (const char_T *)"numGen")),
                         &thisId);
  thisId.fIdentifier = "strategy";
  y->strategy = d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 12,
                                     (const char_T *)"strategy")),
      &thisId);
  thisId.fIdentifier = "Nlive";
  y->Nlive =
      d_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 13, (const char_T *)"Nlive")),
                         &thisId);
  thisId.fIdentifier = "nmcmc";
  y->nmcmc =
      d_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 14, (const char_T *)"nmcmc")),
                         &thisId);
  thisId.fIdentifier = "propScale";
  y->propScale = d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 15,
                                     (const char_T *)"propScale")),
      &thisId);
  thisId.fIdentifier = "nsTolerance";
  y->nsTolerance = d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 16,
                                     (const char_T *)"nsTolerance")),
      &thisId);
  thisId.fIdentifier = "calcSld";
  y->calcSld = d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 17,
                                     (const char_T *)"calcSld")),
      &thisId);
  thisId.fIdentifier = "repeats";
  y->repeats = d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 18,
                                     (const char_T *)"repeats")),
      &thisId);
  thisId.fIdentifier = "nsimu";
  y->nsimu =
      d_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 19, (const char_T *)"nsimu")),
                         &thisId);
  thisId.fIdentifier = "burnin";
  y->burnin =
      d_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 20, (const char_T *)"burnin")),
                         &thisId);
  thisId.fIdentifier = "resamPars";
  b_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 21, (const char_T *)"resamPars")),
                     &thisId, y->resamPars);
  thisId.fIdentifier = "updateFreq";
  y->updateFreq = d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 22,
                                     (const char_T *)"updateFreq")),
      &thisId);
  thisId.fIdentifier = "updatePlotFreq";
  y->updatePlotFreq = d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 23,
                                     (const char_T *)"updatePlotFreq")),
      &thisId);
  thisId.fIdentifier = "checks";
  mb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 24,
                                                     (const char_T *)"checks")),
                      &thisId, &y->checks);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[26] = {"contrastBacks",
                                         "contrastBacksType",
                                         "TF",
                                         "resample",
                                         "dataPresent",
                                         "numberOfContrasts",
                                         "geometry",
                                         "contrastShifts",
                                         "contrastScales",
                                         "contrastNbas",
                                         "contrastNbss",
                                         "contrastRes",
                                         "backs",
                                         "shifts",
                                         "sf",
                                         "nba",
                                         "nbs",
                                         "res",
                                         "params",
                                         "numberOfLayers",
                                         "modelType",
                                         "contrastCustomFiles",
                                         "fitpars",
                                         "otherpars",
                                         "fitconstr",
                                         "otherconstr"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 26,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "contrastBacks";
  n_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                     (const char_T *)"contrastBacks")),
      &thisId, y->contrastBacks);
  thisId.fIdentifier = "contrastBacksType";
  n_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                     (const char_T *)"contrastBacksType")),
      &thisId, y->contrastBacksType);
  thisId.fIdentifier = "TF";
  o_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                                    (const char_T *)"TF")),
                     &thisId, y->TF);
  thisId.fIdentifier = "resample";
  n_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 3, (const char_T *)"resample")),
                     &thisId, y->resample);
  thisId.fIdentifier = "dataPresent";
  n_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 4, (const char_T *)"dataPresent")),
                     &thisId, y->dataPresent);
  thisId.fIdentifier = "numberOfContrasts";
  y->numberOfContrasts = d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 5,
                                     (const char_T *)"numberOfContrasts")),
      &thisId);
  thisId.fIdentifier = "geometry";
  o_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 6, (const char_T *)"geometry")),
                     &thisId, y->geometry);
  thisId.fIdentifier = "contrastShifts";
  n_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 7,
                                     (const char_T *)"contrastShifts")),
      &thisId, y->contrastShifts);
  thisId.fIdentifier = "contrastScales";
  n_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 8,
                                     (const char_T *)"contrastScales")),
      &thisId, y->contrastScales);
  thisId.fIdentifier = "contrastNbas";
  n_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 9,
                                     (const char_T *)"contrastNbas")),
      &thisId, y->contrastNbas);
  thisId.fIdentifier = "contrastNbss";
  n_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 10,
                                     (const char_T *)"contrastNbss")),
      &thisId, y->contrastNbss);
  thisId.fIdentifier = "contrastRes";
  n_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 11,
                                     (const char_T *)"contrastRes")),
      &thisId, y->contrastRes);
  thisId.fIdentifier = "backs";
  n_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 12,
                                                    (const char_T *)"backs")),
                     &thisId, y->backs);
  thisId.fIdentifier = "shifts";
  n_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 13,
                                                    (const char_T *)"shifts")),
                     &thisId, y->shifts);
  thisId.fIdentifier = "sf";
  n_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 14,
                                                    (const char_T *)"sf")),
                     &thisId, y->sf);
  thisId.fIdentifier = "nba";
  n_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 15,
                                                    (const char_T *)"nba")),
                     &thisId, y->nba);
  thisId.fIdentifier = "nbs";
  n_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 16,
                                                    (const char_T *)"nbs")),
                     &thisId, y->nbs);
  thisId.fIdentifier = "res";
  n_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 17,
                                                    (const char_T *)"res")),
                     &thisId, y->res);
  thisId.fIdentifier = "params";
  n_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 18,
                                                    (const char_T *)"params")),
                     &thisId, y->params);
  thisId.fIdentifier = "numberOfLayers";
  y->numberOfLayers = d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 19,
                                     (const char_T *)"numberOfLayers")),
      &thisId);
  thisId.fIdentifier = "modelType";
  o_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 20, (const char_T *)"modelType")),
                     &thisId, y->modelType);
  thisId.fIdentifier = "contrastCustomFiles";
  n_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 21,
                                     (const char_T *)"contrastCustomFiles")),
      &thisId, y->contrastCustomFiles);
  thisId.fIdentifier = "fitpars";
  p_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 22,
                                                    (const char_T *)"fitpars")),
                     &thisId, y->fitpars);
  thisId.fIdentifier = "otherpars";
  p_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 23, (const char_T *)"otherpars")),
                     &thisId, y->otherpars);
  thisId.fIdentifier = "fitconstr";
  p_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 24, (const char_T *)"fitconstr")),
                     &thisId, y->fitconstr);
  thisId.fIdentifier = "otherconstr";
  p_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 25,
                                     (const char_T *)"otherconstr")),
      &thisId, y->otherconstr);
  emlrtDestroyArray(&u);
}

static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct3_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[7] = {"params_fitYesNo", "backs_fitYesNo",
                                        "shifts_fitYesNo", "scales_fitYesNo",
                                        "nbairs_fitYesNo", "nbsubs_fitYesNo",
                                        "resol_fitYesNo"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 7,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "params_fitYesNo";
  n_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                     (const char_T *)"params_fitYesNo")),
      &thisId, y->params_fitYesNo);
  thisId.fIdentifier = "backs_fitYesNo";
  n_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                     (const char_T *)"backs_fitYesNo")),
      &thisId, y->backs_fitYesNo);
  thisId.fIdentifier = "shifts_fitYesNo";
  n_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                     (const char_T *)"shifts_fitYesNo")),
      &thisId, y->shifts_fitYesNo);
  thisId.fIdentifier = "scales_fitYesNo";
  n_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 3,
                                     (const char_T *)"scales_fitYesNo")),
      &thisId, y->scales_fitYesNo);
  thisId.fIdentifier = "nbairs_fitYesNo";
  n_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 4,
                                     (const char_T *)"nbairs_fitYesNo")),
      &thisId, y->nbairs_fitYesNo);
  thisId.fIdentifier = "nbsubs_fitYesNo";
  n_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 5,
                                     (const char_T *)"nbsubs_fitYesNo")),
      &thisId, y->nbsubs_fitYesNo);
  thisId.fIdentifier = "resol_fitYesNo";
  n_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 6,
                                     (const char_T *)"resol_fitYesNo")),
      &thisId, y->resol_fitYesNo);
  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  sb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_char_T *y)
{
  tb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  pb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void q_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *problemDef_cells,
                               const char_T *identifier, cell_8 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  r_emlrt_marshallIn(sp, emlrtAlias(problemDef_cells), &thisId, y);
  emlrtDestroyArray(&problemDef_cells);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, cell_8 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  bv[0] = false;
  iv[0] = 1;
  bv[1] = false;
  iv[1] = 14;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0]);
  thisId.fIdentifier = "1";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y->f1);
  thisId.fIdentifier = "2";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                     &thisId, y->f2);
  thisId.fIdentifier = "3";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)),
                     &thisId, y->f3);
  thisId.fIdentifier = "4";
  v_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 3)),
                     &thisId, y->f4);
  thisId.fIdentifier = "5";
  x_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 4)),
                     &thisId, y->f5);
  thisId.fIdentifier = "6";
  ab_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 5)),
                      &thisId, y->f6);
  thisId.fIdentifier = "7";
  cb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 6)),
                      &thisId, y->f7);
  thisId.fIdentifier = "8";
  eb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 7)),
                      &thisId, y->f8);
  thisId.fIdentifier = "9";
  eb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 8)),
                      &thisId, y->f9);
  thisId.fIdentifier = "10";
  eb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 9)),
                      &thisId, y->f10);
  thisId.fIdentifier = "11";
  eb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 10)),
                      &thisId, y->f11);
  thisId.fIdentifier = "12";
  eb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 11)),
                      &thisId, y->f12);
  thisId.fIdentifier = "13";
  eb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 12)),
                      &thisId, y->f13);
  thisId.fIdentifier = "14";
  fb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 13)),
                      &thisId, y->f14);
  emlrtDestroyArray(&u);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_0 *y)
{
  static const boolean_T bv[2] = {false, true};
  cell_wrap_0 *y_data;
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  int32_T sizes[2];
  int32_T i;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0], &sizes[0]);
  i = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_cell_wrap_0(sp, y, i, (emlrtRTEInfo *)NULL);
  y_data = y->data;
  for (i = 0; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    b_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                       &thisId, y_data[i].f1);
  }
  emlrtDestroyArray(&u);
}

static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  real_T *ret_data;
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_1 *y)
{
  static const boolean_T bv[2] = {false, true};
  cell_wrap_1 *y_data;
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  int32_T sizes[2];
  int32_T i;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0], &sizes[0]);
  i = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_cell_wrap_1(sp, y, i, (emlrtRTEInfo *)NULL);
  y_data = y->data;
  for (i = 0; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    u_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                       &thisId, y_data[i].f1);
  }
  emlrtDestroyArray(&u);
}

static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_char_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  int32_T iv[2];
  int32_T i;
  char_T *ret_data;
  const boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_char_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 1, false);
  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  ub_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret)
{
  static const int32_T dims[2] = {-1, 5};
  real_T *ret_data;
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_2 *y)
{
  static const boolean_T bv[2] = {false, true};
  cell_wrap_2 *y_data;
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  int32_T sizes[2];
  int32_T i;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0], &sizes[0]);
  i = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_cell_wrap_2(sp, y, i, (emlrtRTEInfo *)NULL);
  y_data = y->data;
  for (i = 0; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    w_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                       &thisId, y_data[i].f1.data, y_data[i].f1.size);
  }
  emlrtDestroyArray(&u);
}

static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = {1, 2};
  int32_T iv[2];
  const boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y_data[], int32_T y_size[2])
{
  vb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  real_T *ret_data;
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_3 *y)
{
  static const boolean_T bv[2] = {false, true};
  cell_wrap_3 *y_data;
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  int32_T sizes[2];
  int32_T i;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0], &sizes[0]);
  i = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_cell_wrap_3(sp, y, i, (emlrtRTEInfo *)NULL);
  y_data = y->data;
  for (i = 0; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    y_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                       &thisId, y_data[i].f1);
  }
  emlrtDestroyArray(&u);
}

static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = {1, 10};
  int32_T iv[2];
  const boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  wb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_char_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  int32_T iv[2];
  int32_T i;
  char_T *ret_data;
  const boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_char_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 1, false);
  emlrtDestroyArray(&src);
}

void reflectivity_calculation_api(const mxArray *const prhs[4], int32_T nlhs,
                                  const mxArray *plhs[2])
{
  cell_11 result;
  cell_8 problemDef_cells;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  struct0_T problemDef;
  struct1_T problemDef_limits;
  struct2_T controls;
  struct4_T problem;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInitStruct_struct0_T(&st, &problemDef, &gt_emlrtRTEI);
  emxInitStruct_cell_8(&st, &problemDef_cells, &gt_emlrtRTEI);
  emxInitStruct_struct1_T(&st, &problemDef_limits, &gt_emlrtRTEI);
  emxInitStruct_struct2_T(&st, &controls, &gt_emlrtRTEI);
  emxInitStruct_struct4_T(&st, &problem, &gt_emlrtRTEI);
  emxInitStruct_cell_11(&st, &result, &gt_emlrtRTEI);
  /* Marshall function inputs */
  l_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "problemDef", &problemDef);
  q_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "problemDef_cells",
                     &problemDef_cells);
  hb_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "problemDef_limits",
                      &problemDef_limits);
  kb_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "controls", &controls);
  /* Invoke the target function */
  reflectivity_calculation(&st, &problemDef, &problemDef_cells,
                           &problemDef_limits, &controls, &problem, &result);
  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(&problem);
  emxFreeStruct_struct4_T(&st, &problem);
  emxFreeStruct_struct2_T(&st, &controls);
  emxFreeStruct_struct1_T(&st, &problemDef_limits);
  emxFreeStruct_cell_8(&st, &problemDef_cells);
  emxFreeStruct_struct0_T(&st, &problemDef);
  if (nlhs > 1) {
    plhs[1] = d_emlrt_marshallOut(result);
  }
  emxFreeStruct_cell_11(&st, &result);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_reflectivity_calculation_api.c) */
