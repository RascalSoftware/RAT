//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  _coder_reflectivity_calculation_gpu_api.cu
//
//  Code generation for function '_coder_reflectivity_calculation_gpu_api'
//


// Include files
#include "_coder_reflectivity_calculation_gpu_api.h"
#include "reflectivity_calculation_gpu.h"
#include "reflectivity_calculation_gpu_data.h"
#include "reflectivity_calculation_gpu_emxutil.h"
#include "rt_nonfinite.h"

// Function Declarations
static void ab_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[14]);
static void ac_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[6]);
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, struct0_T *y);
static const mxArray *b_emlrt_marshallOut(const cell_13 u);
static void bb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[21]);
static char_T bc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static void c_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[7]);
static void cb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_4 y[2]);
static void cc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[64]);
static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[10]);
static void db_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_5 y[1]);
static void dc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static real_T e_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static void eb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_6 y[1]);
static void ec_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[153]);
static void emlrt_marshallIn(const mxArray *problemDef, const char_T *identifier,
  struct0_T *y);
static const mxArray *emlrt_marshallOut(const struct4_T *u);
static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[13]);
static void fb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_7 y[1]);
static void fc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[5]);
static void g_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[2]);
static void gb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[3]);
static void gc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[19]);
static void h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[10]);
static cell_8 hb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static void hc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[11]);
static void i_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[6]);
static void ib_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[4]);
static void ic_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[20]);
static char_T j_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static void jb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_9 y[1]);
static void jc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[15]);
static void k_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[64]);
static void kb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[12]);
static void kc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[22]);
static void l_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static void lb_emlrt_marshallIn(const mxArray *problemDef_limits, const char_T
  *identifier, struct1_T *y);
static void lc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[14]);
static void m_emlrt_marshallIn(const mxArray *problemDef_cells, const char_T
  *identifier, cell_10 *y);
static void mb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, struct1_T *y);
static void mc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[21]);
static void n_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_10 *y);
static void nb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[20]);
static void nc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[3]);
static void o_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_0 y[7]);
static void ob_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[4]);
static void oc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[4]);
static void p_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_1 y[7]);
static void pb_emlrt_marshallIn(const mxArray *controls, const char_T
  *identifier, struct2_T *y);
static void pc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[12]);
static void q_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[153]);
static void qb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, struct2_T *y);
static void qc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[20]);
static void r_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_2 y[4]);
static void rb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[9]);
static void rc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[4]);
static void s_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[5]);
static void sb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, struct3_T *y);
static void sc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[9]);
static void t_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_3 *y);
static void tb_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[7]);
static void u_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[19]);
static void ub_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[10]);
static void v_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[11]);
static real_T vb_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static void w_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[20]);
static void wb_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[13]);
static void x_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[15]);
static void xb_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[2]);
static void y_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[22]);
static void yb_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[10]);

// Function Definitions
static void ab_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[14])
{
  lc_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ac_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[6])
{
  static const int32_T dims[2] = { 1, 6 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
    dims);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 6);
  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, struct0_T *y)
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
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 28, fieldNames, 0U,
    &dims);
  thisId.fIdentifier = "contrastBacks";
  c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0,
    "contrastBacks")), &thisId, y->contrastBacks);
  thisId.fIdentifier = "contrastBacksType";
  c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1,
    "contrastBacksType")), &thisId, y->contrastBacksType);
  thisId.fIdentifier = "TF";
  d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2,
    "TF")), &thisId, y->TF);
  thisId.fIdentifier = "resample";
  c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 3,
    "resample")), &thisId, y->resample);
  thisId.fIdentifier = "dataPresent";
  c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 4,
    "dataPresent")), &thisId, y->dataPresent);
  thisId.fIdentifier = "numberOfContrasts";
  y->numberOfContrasts = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 5, "numberOfContrasts")), &thisId);
  thisId.fIdentifier = "geometry";
  f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 6,
    "geometry")), &thisId, y->geometry);
  thisId.fIdentifier = "contrastShifts";
  c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 7,
    "contrastShifts")), &thisId, y->contrastShifts);
  thisId.fIdentifier = "contrastScales";
  c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 8,
    "contrastScales")), &thisId, y->contrastScales);
  thisId.fIdentifier = "contrastNbas";
  c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 9,
    "contrastNbas")), &thisId, y->contrastNbas);
  thisId.fIdentifier = "contrastNbss";
  c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 10,
    "contrastNbss")), &thisId, y->contrastNbss);
  thisId.fIdentifier = "contrastRes";
  c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 11,
    "contrastRes")), &thisId, y->contrastRes);
  thisId.fIdentifier = "backs";
  g_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 12,
    "backs")), &thisId, y->backs);
  thisId.fIdentifier = "shifts";
  y->shifts = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 13, "shifts")), &thisId);
  thisId.fIdentifier = "sf";
  y->sf = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal,
    u, 0, 14, "sf")), &thisId);
  thisId.fIdentifier = "nba";
  y->nba = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal,
    u, 0, 15, "nba")), &thisId);
  thisId.fIdentifier = "nbs";
  g_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 16,
    "nbs")), &thisId, y->nbs);
  thisId.fIdentifier = "res";
  y->res = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal,
    u, 0, 17, "res")), &thisId);
  thisId.fIdentifier = "params";
  h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 18,
    "params")), &thisId, y->params);
  thisId.fIdentifier = "numberOfLayers";
  y->numberOfLayers = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 19, "numberOfLayers")), &thisId);
  thisId.fIdentifier = "modelType";
  i_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 20,
    "modelType")), &thisId, y->modelType);
  thisId.fIdentifier = "modelFilename";
  y->modelFilename = j_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 21, "modelFilename")), &thisId);
  thisId.fIdentifier = "path";
  k_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 22,
    "path")), &thisId, y->path);
  thisId.fIdentifier = "modelLanguage";
  i_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 23,
    "modelLanguage")), &thisId, y->modelLanguage);
  thisId.fIdentifier = "fitpars";
  l_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 24,
    "fitpars")), &thisId);
  thisId.fIdentifier = "otherpars";
  l_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 25,
    "otherpars")), &thisId);
  thisId.fIdentifier = "fitconstr";
  l_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 26,
    "fitconstr")), &thisId);
  thisId.fIdentifier = "otherconstr";
  l_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 27,
    "otherconstr")), &thisId);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const cell_13 u)
{
  const mxArray *y;
  int32_T iv[2];
  int32_T i;
  emxArray_cell_wrap_11 *b_u;
  const mxArray *b_y;
  int32_T n;
  emxArray_real_T *c_u;
  int32_T i1;
  emxArray_cell_wrap_11 *d_u;
  const mxArray *c_y;
  const mxArray *m;
  real_T *pData;
  emxArray_real_T *e_u;
  int32_T loopUpperBound;
  int32_T b_i;
  int32_T c_i;
  emxArray_cell_wrap_12 *f_u;
  emxArray_real_T *g_u;
  emxArray_cell_wrap_12 *h_u;
  emxArray_real_T *i_u;
  emxArray_cell_wrap_11 *j_u;
  emxArray_real_T *k_u;
  emxArray_real_T *l_u;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  y = NULL;
  for (i = 0; i < 2; i++) {
    iv[i] = 5 * i + 1;
  }

  emxInit_cell_wrap_11(&b_u, 1, true);
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, iv));
  i = b_u->size[0];
  b_u->size[0] = u.f1->size[0];
  emxEnsureCapacity_cell_wrap_11(b_u, i);
  for (i = 0; i < u.f1->size[0]; i++) {
    emxCopyStruct_cell_wrap_11(&b_u->data[i], &u.f1->data[i]);
  }

  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(1, *(int32_T (*)[1])u.f1->size));
  n = u.f1->size[0] - 1;
  emxInit_real_T(&c_u, 2, true);
  for (i = 0; i <= n; i++) {
    i1 = c_u->size[0] * c_u->size[1];
    c_u->size[0] = b_u->data[i].f1->size[0];
    c_u->size[1] = 2;
    emxEnsureCapacity_real_T(c_u, i1);
    for (i1 = 0; i1 < b_u->data[i].f1->size[0] * b_u->data[i].f1->size[1]; i1++)
    {
      c_u->data[i1] = b_u->data[i].f1->data[i1];
    }

    c_y = NULL;
    for (i1 = 0; i1 < 2; i1++) {
      iv[i1] = c_u->size[i1];
    }

    m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    i1 = 0;
    loopUpperBound = c_u->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < loopUpperBound; c_i++) {
        pData[i1] = c_u->data[c_i + c_u->size[0] * b_i];
        i1++;
      }
    }

    emlrtAssign(&c_y, m);
    emlrtSetCell(b_y, i, c_y);
  }

  emxFree_real_T(&c_u);
  emxFree_cell_wrap_11(&b_u);
  emxInit_cell_wrap_11(&d_u, 1, true);
  emlrtSetCell(y, 0, b_y);
  i = d_u->size[0];
  d_u->size[0] = u.f2->size[0];
  emxEnsureCapacity_cell_wrap_11(d_u, i);
  for (i = 0; i < u.f2->size[0]; i++) {
    emxCopyStruct_cell_wrap_11(&d_u->data[i], &u.f2->data[i]);
  }

  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(1, *(int32_T (*)[1])u.f2->size));
  n = u.f2->size[0] - 1;
  emxInit_real_T(&e_u, 2, true);
  for (i = 0; i <= n; i++) {
    i1 = e_u->size[0] * e_u->size[1];
    e_u->size[0] = d_u->data[i].f1->size[0];
    e_u->size[1] = 2;
    emxEnsureCapacity_real_T(e_u, i1);
    for (i1 = 0; i1 < d_u->data[i].f1->size[0] * d_u->data[i].f1->size[1]; i1++)
    {
      e_u->data[i1] = d_u->data[i].f1->data[i1];
    }

    c_y = NULL;
    for (i1 = 0; i1 < 2; i1++) {
      iv[i1] = e_u->size[i1];
    }

    m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    i1 = 0;
    loopUpperBound = e_u->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < loopUpperBound; c_i++) {
        pData[i1] = e_u->data[c_i + e_u->size[0] * b_i];
        i1++;
      }
    }

    emlrtAssign(&c_y, m);
    emlrtSetCell(b_y, i, c_y);
  }

  emxFree_real_T(&e_u);
  emxFree_cell_wrap_11(&d_u);
  emxInit_cell_wrap_12(&f_u, 1, true);
  emlrtSetCell(y, 1, b_y);
  i = f_u->size[0];
  f_u->size[0] = u.f3->size[0];
  emxEnsureCapacity_cell_wrap_12(f_u, i);
  for (i = 0; i < u.f3->size[0]; i++) {
    emxCopyStruct_cell_wrap_12(&f_u->data[i], &u.f3->data[i]);
  }

  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(1, *(int32_T (*)[1])u.f3->size));
  n = u.f3->size[0] - 1;
  emxInit_real_T(&g_u, 2, true);
  for (i = 0; i <= n; i++) {
    i1 = g_u->size[0] * g_u->size[1];
    g_u->size[0] = f_u->data[i].f1->size[0];
    g_u->size[1] = 3;
    emxEnsureCapacity_real_T(g_u, i1);
    for (i1 = 0; i1 < f_u->data[i].f1->size[0] * f_u->data[i].f1->size[1]; i1++)
    {
      g_u->data[i1] = f_u->data[i].f1->data[i1];
    }

    c_y = NULL;
    for (i1 = 0; i1 < 2; i1++) {
      iv[i1] = g_u->size[i1];
    }

    m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    i1 = 0;
    loopUpperBound = g_u->size[0];
    for (b_i = 0; b_i < 3; b_i++) {
      for (c_i = 0; c_i < loopUpperBound; c_i++) {
        pData[i1] = g_u->data[c_i + g_u->size[0] * b_i];
        i1++;
      }
    }

    emlrtAssign(&c_y, m);
    emlrtSetCell(b_y, i, c_y);
  }

  emxFree_real_T(&g_u);
  emxFree_cell_wrap_12(&f_u);
  emxInit_cell_wrap_12(&h_u, 1, true);
  emlrtSetCell(y, 2, b_y);
  i = h_u->size[0];
  h_u->size[0] = u.f4->size[0];
  emxEnsureCapacity_cell_wrap_12(h_u, i);
  for (i = 0; i < u.f4->size[0]; i++) {
    emxCopyStruct_cell_wrap_12(&h_u->data[i], &u.f4->data[i]);
  }

  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(1, *(int32_T (*)[1])u.f4->size));
  n = u.f4->size[0] - 1;
  emxInit_real_T(&i_u, 2, true);
  for (i = 0; i <= n; i++) {
    i1 = i_u->size[0] * i_u->size[1];
    i_u->size[0] = h_u->data[i].f1->size[0];
    i_u->size[1] = 3;
    emxEnsureCapacity_real_T(i_u, i1);
    for (i1 = 0; i1 < h_u->data[i].f1->size[0] * h_u->data[i].f1->size[1]; i1++)
    {
      i_u->data[i1] = h_u->data[i].f1->data[i1];
    }

    c_y = NULL;
    for (i1 = 0; i1 < 2; i1++) {
      iv[i1] = i_u->size[i1];
    }

    m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    i1 = 0;
    loopUpperBound = i_u->size[0];
    for (b_i = 0; b_i < 3; b_i++) {
      for (c_i = 0; c_i < loopUpperBound; c_i++) {
        pData[i1] = i_u->data[c_i + i_u->size[0] * b_i];
        i1++;
      }
    }

    emlrtAssign(&c_y, m);
    emlrtSetCell(b_y, i, c_y);
  }

  emxFree_real_T(&i_u);
  emxFree_cell_wrap_12(&h_u);
  emxInit_cell_wrap_11(&j_u, 1, true);
  emlrtSetCell(y, 3, b_y);
  i = j_u->size[0];
  j_u->size[0] = u.f5->size[0];
  emxEnsureCapacity_cell_wrap_11(j_u, i);
  for (i = 0; i < u.f5->size[0]; i++) {
    emxCopyStruct_cell_wrap_11(&j_u->data[i], &u.f5->data[i]);
  }

  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(1, *(int32_T (*)[1])u.f5->size));
  n = u.f5->size[0] - 1;
  emxInit_real_T(&k_u, 2, true);
  for (i = 0; i <= n; i++) {
    i1 = k_u->size[0] * k_u->size[1];
    k_u->size[0] = j_u->data[i].f1->size[0];
    k_u->size[1] = 2;
    emxEnsureCapacity_real_T(k_u, i1);
    for (i1 = 0; i1 < j_u->data[i].f1->size[0] * j_u->data[i].f1->size[1]; i1++)
    {
      k_u->data[i1] = j_u->data[i].f1->data[i1];
    }

    c_y = NULL;
    for (i1 = 0; i1 < 2; i1++) {
      iv[i1] = k_u->size[i1];
    }

    m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    i1 = 0;
    loopUpperBound = k_u->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < loopUpperBound; c_i++) {
        pData[i1] = k_u->data[c_i + k_u->size[0] * b_i];
        i1++;
      }
    }

    emlrtAssign(&c_y, m);
    emlrtSetCell(b_y, i, c_y);
  }

  emxFree_real_T(&k_u);
  emxFree_cell_wrap_11(&j_u);
  emxInit_real_T(&l_u, 1, true);
  emlrtSetCell(y, 4, b_y);
  i = l_u->size[0];
  l_u->size[0] = u.f6->size[0];
  emxEnsureCapacity_real_T(l_u, i);
  for (i = 0; i < u.f6->size[0]; i++) {
    l_u->data[i] = u.f6->data[i];
  }

  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(1, *(int32_T (*)[1])u.f6->size));
  n = u.f6->size[0] - 1;
  for (i = 0; i <= n; i++) {
    real_T m_u;
    const mxArray *m1;
    m_u = l_u->data[i];
    c_y = NULL;
    m1 = emlrtCreateDoubleScalar(m_u);
    emlrtAssign(&c_y, m1);
    emlrtSetCell(b_y, i, c_y);
  }

  emxFree_real_T(&l_u);
  emlrtSetCell(y, 5, b_y);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return y;
}

static void bb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[21])
{
  mc_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static char_T bc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  char_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 0U,
    &dims);
  emlrtImportCharR2015b(emlrtRootTLSGlobal, src, &ret);
  emlrtDestroyArray(&src);
  return ret;
}

static void c_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[7])
{
  tb_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void cb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_4 y[2])
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  boolean_T bv[2];
  int32_T i;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (i = 0; i < 2; i++) {
    iv[i] = i + 1;
    bv[i] = false;
  }

  emlrtCheckCell(emlrtRootTLSGlobal, parentId, u, 2U, iv, bv);
  for (i = 0; i < 2; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    x_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u,
      i)), &thisId, y[i].f1);
  }

  emlrtDestroyArray(&u);
}

static void cc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[64])
{
  static const int32_T dims[2] = { 1, 64 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
    dims);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 64);
  emlrtDestroyArray(&src);
}

static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[10])
{
  ub_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void db_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_5 y[1])
{
  emlrtMsgIdentifier thisId;
  int32_T iv[1];
  boolean_T bv[1];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  bv[0] = false;
  emlrtCheckCell(emlrtRootTLSGlobal, parentId, u, 1U, iv, bv);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  f_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 0)),
                     &thisId, y[0].f1);
  emlrtDestroyArray(&u);
}

static void dc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  static const int32_T dims[2] = { 0, 0 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    dims);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static real_T e_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  real_T y;
  y = vb_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void eb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_6 y[1])
{
  emlrtMsgIdentifier thisId;
  int32_T iv[1];
  boolean_T bv[1];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  bv[0] = false;
  emlrtCheckCell(emlrtRootTLSGlobal, parentId, u, 1U, iv, bv);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  v_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 0)),
                     &thisId, y[0].f1);
  emlrtDestroyArray(&u);
}

static void ec_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[153])
{
  static const int32_T dims[2] = { 51, 3 };

  real_T (*r)[153];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    dims);
  r = (real_T (*)[153])emlrtMxGetData(src);
  for (int32_T i = 0; i < 153; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const mxArray *problemDef, const char_T *identifier,
  struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(emlrtAlias(problemDef), &thisId, y);
  emlrtDestroyArray(&problemDef);
}

static const mxArray *emlrt_marshallOut(const struct4_T *u)
{
  const mxArray *y;
  static const char * sv[9] = { "ssubs", "backgrounds", "qshifts",
    "scalefactors", "nbairs", "nbsubs", "resolutions", "calculations",
    "allSubRough" };

  const mxArray *b_y;
  int32_T iv[1];
  const mxArray *m;
  real_T *pData;
  int32_T i;
  int32_T loopUpperBound;
  int32_T b_i;
  static const char * sv1[2] = { "all_chis", "sum_chi" };

  const mxArray *c_y;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 9, sv));
  b_y = NULL;
  iv[0] = u->ssubs->size[0];
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  loopUpperBound = u->ssubs->size[0];
  for (b_i = 0; b_i < loopUpperBound; b_i++) {
    pData[i] = u->ssubs->data[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "ssubs", b_y, 0);
  b_y = NULL;
  iv[0] = u->backgrounds->size[0];
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  loopUpperBound = u->backgrounds->size[0];
  for (b_i = 0; b_i < loopUpperBound; b_i++) {
    pData[i] = u->backgrounds->data[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "backgrounds", b_y, 1);
  b_y = NULL;
  iv[0] = u->qshifts->size[0];
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  loopUpperBound = u->qshifts->size[0];
  for (b_i = 0; b_i < loopUpperBound; b_i++) {
    pData[i] = u->qshifts->data[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "qshifts", b_y, 2);
  b_y = NULL;
  iv[0] = u->scalefactors->size[0];
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  loopUpperBound = u->scalefactors->size[0];
  for (b_i = 0; b_i < loopUpperBound; b_i++) {
    pData[i] = u->scalefactors->data[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "scalefactors", b_y, 3);
  b_y = NULL;
  iv[0] = u->nbairs->size[0];
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  loopUpperBound = u->nbairs->size[0];
  for (b_i = 0; b_i < loopUpperBound; b_i++) {
    pData[i] = u->nbairs->data[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "nbairs", b_y, 4);
  b_y = NULL;
  iv[0] = u->nbsubs->size[0];
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  loopUpperBound = u->nbsubs->size[0];
  for (b_i = 0; b_i < loopUpperBound; b_i++) {
    pData[i] = u->nbsubs->data[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "nbsubs", b_y, 5);
  b_y = NULL;
  iv[0] = u->resolutions->size[0];
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  loopUpperBound = u->resolutions->size[0];
  for (b_i = 0; b_i < loopUpperBound; b_i++) {
    pData[i] = u->resolutions->data[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "resolutions", b_y, 6);
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 2, sv1));
  c_y = NULL;
  iv[0] = u->calculations.all_chis->size[0];
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  loopUpperBound = u->calculations.all_chis->size[0];
  for (b_i = 0; b_i < loopUpperBound; b_i++) {
    pData[i] = u->calculations.all_chis->data[b_i];
    i++;
  }

  const mxArray *m1;
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(b_y, 0, "all_chis", c_y, 0);
  c_y = NULL;
  m1 = emlrtCreateDoubleScalar(u->calculations.sum_chi);
  emlrtAssign(&c_y, m1);
  emlrtSetFieldR2017b(b_y, 0, "sum_chi", c_y, 1);
  emlrtSetFieldR2017b(y, 0, "calculations", b_y, 7);
  b_y = NULL;
  iv[0] = u->allSubRough->size[0];
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  loopUpperBound = u->allSubRough->size[0];
  for (b_i = 0; b_i < loopUpperBound; b_i++) {
    pData[i] = u->allSubRough->data[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "allSubRough", b_y, 8);
  return y;
}

static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[13])
{
  wb_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void fb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_7 y[1])
{
  emlrtMsgIdentifier thisId;
  int32_T iv[1];
  boolean_T bv[1];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  bv[0] = false;
  emlrtCheckCell(emlrtRootTLSGlobal, parentId, u, 1U, iv, bv);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  gb_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 0)),
                      &thisId, y[0].f1);
  emlrtDestroyArray(&u);
}

static void fc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[5])
{
  static const int32_T dims[2] = { 1, 5 };

  real_T (*r)[5];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    dims);
  r = (real_T (*)[5])emlrtMxGetData(src);
  for (int32_T i = 0; i < 5; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void g_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[2])
{
  xb_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void gb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[3])
{
  nc_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void gc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[19])
{
  static const int32_T dims[2] = { 1, 19 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
    dims);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 19);
  emlrtDestroyArray(&src);
}

static void h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[10])
{
  yb_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static cell_8 hb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  cell_8 y;
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (int32_T i = 0; i < 2; i++) {
    iv[i] = i + 1;
    bv[i] = false;
  }

  emlrtCheckCell(emlrtRootTLSGlobal, parentId, u, 2U, iv, bv);
  thisId.fIdentifier = "1";
  gb_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 0)),
                      &thisId, y.f1);
  thisId.fIdentifier = "2";
  ib_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 1)),
                      &thisId, y.f2);
  emlrtDestroyArray(&u);
  return y;
}

static void hc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[11])
{
  static const int32_T dims[2] = { 1, 11 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
    dims);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 11);
  emlrtDestroyArray(&src);
}

static void i_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[6])
{
  ac_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ib_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[4])
{
  oc_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ic_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[20])
{
  static const int32_T dims[2] = { 1, 20 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
    dims);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 20);
  emlrtDestroyArray(&src);
}

static char_T j_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  char_T y;
  y = bc_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void jb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_9 y[1])
{
  emlrtMsgIdentifier thisId;
  int32_T iv[1];
  boolean_T bv[1];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  bv[0] = false;
  emlrtCheckCell(emlrtRootTLSGlobal, parentId, u, 1U, iv, bv);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  kb_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 0)),
                      &thisId, y[0].f1);
  emlrtDestroyArray(&u);
}

static void jc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[15])
{
  static const int32_T dims[2] = { 1, 15 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
    dims);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 15);
  emlrtDestroyArray(&src);
}

static void k_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[64])
{
  cc_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void kb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[12])
{
  pc_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void kc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[22])
{
  static const int32_T dims[2] = { 1, 22 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
    dims);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 22);
  emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  dc_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static void lb_emlrt_marshallIn(const mxArray *problemDef_limits, const char_T
  *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  mb_emlrt_marshallIn(emlrtAlias(problemDef_limits), &thisId, y);
  emlrtDestroyArray(&problemDef_limits);
}

static void lc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[14])
{
  static const int32_T dims[2] = { 1, 14 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
    dims);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 14);
  emlrtDestroyArray(&src);
}

static void m_emlrt_marshallIn(const mxArray *problemDef_cells, const char_T
  *identifier, cell_10 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  n_emlrt_marshallIn(emlrtAlias(problemDef_cells), &thisId, y);
  emlrtDestroyArray(&problemDef_cells);
}

static void mb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[7] = { "params", "backs", "scales", "shifts",
    "nba", "nbs", "res" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 7, fieldNames, 0U,
    &dims);
  thisId.fIdentifier = "params";
  nb_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0,
    "params")), &thisId, y->params);
  thisId.fIdentifier = "backs";
  ob_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1,
    "backs")), &thisId, y->backs);
  thisId.fIdentifier = "scales";
  g_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2,
    "scales")), &thisId, y->scales);
  thisId.fIdentifier = "shifts";
  g_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 3,
    "shifts")), &thisId, y->shifts);
  thisId.fIdentifier = "nba";
  g_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 4,
    "nba")), &thisId, y->nba);
  thisId.fIdentifier = "nbs";
  ob_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 5,
    "nbs")), &thisId, y->nbs);
  thisId.fIdentifier = "res";
  g_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 6,
    "res")), &thisId, y->res);
  emlrtDestroyArray(&u);
}

static void mc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[21])
{
  static const int32_T dims[2] = { 1, 21 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
    dims);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 21);
  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_10 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (int32_T i = 0; i < 2; i++) {
    iv[i] = 12 * i + 1;
    bv[i] = false;
  }

  emlrtCheckCell(emlrtRootTLSGlobal, parentId, u, 2U, iv, bv);
  thisId.fIdentifier = "1";
  o_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 0)),
                     &thisId, y->f1);
  thisId.fIdentifier = "2";
  p_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 1)),
                     &thisId, y->f2);
  thisId.fIdentifier = "3";
  o_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 2)),
                     &thisId, y->f3);
  thisId.fIdentifier = "4";
  o_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 3)),
                     &thisId, y->f4);
  thisId.fIdentifier = "5";
  o_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 4)),
                     &thisId, y->f5);
  thisId.fIdentifier = "6";
  r_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 5)),
                     &thisId, y->f6);
  thisId.fIdentifier = "7";
  t_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 6)),
                     &thisId, &y->f7);
  thisId.fIdentifier = "8";
  cb_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 7)),
                      &thisId, y->f8);
  thisId.fIdentifier = "9";
  db_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 8)),
                      &thisId, y->f9);
  thisId.fIdentifier = "10";
  eb_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 9)),
                      &thisId, y->f10);
  thisId.fIdentifier = "11";
  fb_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u,
    10)), &thisId, y->f11);
  thisId.fIdentifier = "12";
  y->f12 = hb_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal,
    parentId, u, 11)), &thisId);
  thisId.fIdentifier = "13";
  jb_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u,
    12)), &thisId, y->f13);
  emlrtDestroyArray(&u);
}

static void nb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[20])
{
  qc_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void nc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[3])
{
  static const int32_T dims[2] = { 1, 3 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
    dims);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 3);
  emlrtDestroyArray(&src);
}

static void o_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_0 y[7])
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  boolean_T bv[2];
  int32_T i;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (i = 0; i < 2; i++) {
    iv[i] = 6 * i + 1;
    bv[i] = false;
  }

  emlrtCheckCell(emlrtRootTLSGlobal, parentId, u, 2U, iv, bv);
  for (i = 0; i < 7; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    g_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u,
      i)), &thisId, y[i].f1);
  }

  emlrtDestroyArray(&u);
}

static void ob_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[4])
{
  rc_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void oc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[4])
{
  static const int32_T dims[2] = { 1, 4 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
    dims);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 4);
  emlrtDestroyArray(&src);
}

static void p_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_1 y[7])
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  boolean_T bv[2];
  int32_T i;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (i = 0; i < 2; i++) {
    iv[i] = 6 * i + 1;
    bv[i] = false;
  }

  emlrtCheckCell(emlrtRootTLSGlobal, parentId, u, 2U, iv, bv);
  for (i = 0; i < 7; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    q_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u,
      i)), &thisId, y[i].f1);
  }

  emlrtDestroyArray(&u);
}

static void pb_emlrt_marshallIn(const mxArray *controls, const char_T
  *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  qb_emlrt_marshallIn(emlrtAlias(controls), &thisId, y);
  emlrtDestroyArray(&controls);
}

static void pc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[12])
{
  static const int32_T dims[2] = { 1, 12 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
    dims);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 12);
  emlrtDestroyArray(&src);
}

static void q_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[153])
{
  ec_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void qb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[19] = { "para", "proc", "display", "tolX",
    "tolFun", "maxFunEvals", "maxIter", "populationSize", "F_weight", "F_CR",
    "VTR", "numGen", "strategy", "Nlive", "nmcmc", "propScale", "nsTolerance",
    "calcSld", "checks" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 19, fieldNames, 0U,
    &dims);
  thisId.fIdentifier = "para";
  i_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0,
    "para")), &thisId, y->para);
  thisId.fIdentifier = "proc";
  rb_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1,
    "proc")), &thisId, y->proc);
  thisId.fIdentifier = "display";
  ib_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2,
    "display")), &thisId, y->display);
  thisId.fIdentifier = "tolX";
  y->tolX = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal,
    u, 0, 3, "tolX")), &thisId);
  thisId.fIdentifier = "tolFun";
  y->tolFun = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 4, "tolFun")), &thisId);
  thisId.fIdentifier = "maxFunEvals";
  y->maxFunEvals = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 5, "maxFunEvals")), &thisId);
  thisId.fIdentifier = "maxIter";
  y->maxIter = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 6, "maxIter")), &thisId);
  thisId.fIdentifier = "populationSize";
  y->populationSize = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 7, "populationSize")), &thisId);
  thisId.fIdentifier = "F_weight";
  y->F_weight = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 8, "F_weight")), &thisId);
  thisId.fIdentifier = "F_CR";
  y->F_CR = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal,
    u, 0, 9, "F_CR")), &thisId);
  thisId.fIdentifier = "VTR";
  y->VTR = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal,
    u, 0, 10, "VTR")), &thisId);
  thisId.fIdentifier = "numGen";
  y->numGen = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 11, "numGen")), &thisId);
  thisId.fIdentifier = "strategy";
  y->strategy = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 12, "strategy")), &thisId);
  thisId.fIdentifier = "Nlive";
  y->Nlive = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 13, "Nlive")), &thisId);
  thisId.fIdentifier = "nmcmc";
  y->nmcmc = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 14, "nmcmc")), &thisId);
  thisId.fIdentifier = "propScale";
  y->propScale = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 15, "propScale")), &thisId);
  thisId.fIdentifier = "nsTolerance";
  y->nsTolerance = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 16, "nsTolerance")), &thisId);
  thisId.fIdentifier = "calcSld";
  y->calcSld = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 17, "calcSld")), &thisId);
  thisId.fIdentifier = "checks";
  sb_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0,
    18, "checks")), &thisId, &y->checks);
  emlrtDestroyArray(&u);
}

static void qc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[20])
{
  static const int32_T dims[2] = { 10, 2 };

  real_T (*r)[20];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    dims);
  r = (real_T (*)[20])emlrtMxGetData(src);
  for (int32_T i = 0; i < 20; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_wrap_2 y[4])
{
  emlrtMsgIdentifier thisId;
  int32_T iv[1];
  boolean_T bv[1];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 4;
  bv[0] = false;
  emlrtCheckCell(emlrtRootTLSGlobal, parentId, u, 1U, iv, bv);
  for (int32_T i = 0; i < 4; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    s_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u,
      i)), &thisId, y[i].f1);
  }

  emlrtDestroyArray(&u);
}

static void rb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[9])
{
  sc_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void rc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[4])
{
  static const int32_T dims[2] = { 2, 2 };

  real_T (*r)[4];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    dims);
  r = (real_T (*)[4])emlrtMxGetData(src);
  for (int32_T i = 0; i < 4; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void s_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[5])
{
  fc_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void sb_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[7] = { "params_fitYesNo", "backs_fitYesNo",
    "shifts_fitYesNo", "scales_fitYesNo", "nbairs_fitYesNo", "nbsubs_fitYesNo",
    "resol_fitYesNo" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 7, fieldNames, 0U,
    &dims);
  thisId.fIdentifier = "params_fitYesNo";
  h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0,
    "params_fitYesNo")), &thisId, y->params_fitYesNo);
  thisId.fIdentifier = "backs_fitYesNo";
  g_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1,
    "backs_fitYesNo")), &thisId, y->backs_fitYesNo);
  thisId.fIdentifier = "shifts_fitYesNo";
  y->shifts_fitYesNo = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 2, "shifts_fitYesNo")), &thisId);
  thisId.fIdentifier = "scales_fitYesNo";
  y->scales_fitYesNo = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 3, "scales_fitYesNo")), &thisId);
  thisId.fIdentifier = "nbairs_fitYesNo";
  y->nbairs_fitYesNo = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 4, "nbairs_fitYesNo")), &thisId);
  thisId.fIdentifier = "nbsubs_fitYesNo";
  g_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 5,
    "nbsubs_fitYesNo")), &thisId, y->nbsubs_fitYesNo);
  thisId.fIdentifier = "resol_fitYesNo";
  y->resol_fitYesNo = e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b
    (emlrtRootTLSGlobal, u, 0, 6, "resol_fitYesNo")), &thisId);
  emlrtDestroyArray(&u);
}

static void sc_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[9])
{
  static const int32_T dims[2] = { 1, 9 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
    dims);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 9);
  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, cell_3 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  for (int32_T i = 0; i < 2; i++) {
    iv[i] = 9 * i + 1;
    bv[i] = false;
  }

  emlrtCheckCell(emlrtRootTLSGlobal, parentId, u, 2U, iv, bv);
  thisId.fIdentifier = "1";
  u_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 0)),
                     &thisId, y->f1);
  thisId.fIdentifier = "2";
  v_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 1)),
                     &thisId, y->f2);
  thisId.fIdentifier = "3";
  w_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 2)),
                     &thisId, y->f3);
  thisId.fIdentifier = "4";
  x_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 3)),
                     &thisId, y->f4);
  thisId.fIdentifier = "5";
  y_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 4)),
                     &thisId, y->f5);
  thisId.fIdentifier = "6";
  ab_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 5)),
                      &thisId, y->f6);
  thisId.fIdentifier = "7";
  u_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 6)),
                     &thisId, y->f7);
  thisId.fIdentifier = "8";
  ab_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 7)),
                      &thisId, y->f8);
  thisId.fIdentifier = "9";
  bb_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 8)),
                      &thisId, y->f9);
  thisId.fIdentifier = "10";
  ab_emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 9)),
                      &thisId, y->f10);
  emlrtDestroyArray(&u);
}

static void tb_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[7])
{
  static const int32_T dims[2] = { 1, 7 };

  real_T (*r)[7];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    dims);
  r = (real_T (*)[7])emlrtMxGetData(src);
  for (int32_T i = 0; i < 7; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[19])
{
  gc_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ub_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[10])
{
  static const int32_T dims[2] = { 1, 10 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
    dims);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 10);
  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[11])
{
  hc_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T vb_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 0U,
    &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void w_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[20])
{
  ic_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void wb_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[13])
{
  static const int32_T dims[2] = { 1, 13 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
    dims);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 13);
  emlrtDestroyArray(&src);
}

static void x_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[15])
{
  jc_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void xb_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[2])
{
  static const int32_T dims[2] = { 1, 2 };

  real_T (*r)[2];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    dims);
  r = (real_T (*)[2])emlrtMxGetData(src);
  for (int32_T i = 0; i < 2; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void y_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[22])
{
  kc_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void yb_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[10])
{
  static const int32_T dims[2] = { 1, 10 };

  real_T (*r)[10];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    dims);
  r = (real_T (*)[10])emlrtMxGetData(src);
  for (int32_T i = 0; i < 10; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

void reflectivity_calculation_gpu_api(const mxArray * const prhs[4], int32_T
  nlhs, const mxArray *plhs[2])
{
  struct4_T problem;
  cell_13 result;
  struct0_T problemDef;
  cell_10 problemDef_cells;
  struct1_T problemDef_limits;
  struct2_T controls;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInitStruct_struct4_T(&problem, true);
  emxInitStruct_cell_13(&result, true);

  // Marshall function inputs
  emlrt_marshallIn(emlrtAliasP(prhs[0]), "problemDef", &problemDef);
  m_emlrt_marshallIn(emlrtAliasP(prhs[1]), "problemDef_cells", &problemDef_cells);
  lb_emlrt_marshallIn(emlrtAliasP(prhs[2]), "problemDef_limits",
                      &problemDef_limits);
  pb_emlrt_marshallIn(emlrtAliasP(prhs[3]), "controls", &controls);

  // Invoke the target function
  reflectivity_calculation_gpu(&problemDef, &problemDef_cells,
    &problemDef_limits, &controls, &problem, &result);

  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(&problem);
  emxFreeStruct_struct4_T(&problem);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(result);
  }

  emxFreeStruct_cell_13(&result);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

// End of code generation (_coder_reflectivity_calculation_gpu_api.cu)
