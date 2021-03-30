//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  _coder_reflectivity_calculation_api.cpp
//
//  Code generation for function '_coder_reflectivity_calculation_api'
//


// Include files
#include "_coder_reflectivity_calculation_api.h"
#include "callReflectivity.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"
#include "standardTF_stanlay_paraAll.h"
#include "sum.h"

// Function Declarations
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const cell_8 *u);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<char_T, 2U> &ret);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y);
static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp, const coder::
  array<cell_wrap_7, 1U> &u);
static real_T cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<char_T, 2U> &y);
static const mxArray *d_emlrt_marshallOut(const emlrtStack *sp, const coder::
  array<cell_wrap_1, 1U> &u);
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<char_T, 2U> &ret);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *problemDef,
  const char_T *identifier, struct0_T *y);
static const mxArray *emlrt_marshallOut(const struct4_T *u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<char_T, 2U> &y);
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y);
static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *problemDef_cells, const char_T *identifier, cell_6 *y);
static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_6 *y);
static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<cell_wrap_0, 2U> &y);
static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<cell_wrap_1, 2U> &y);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<cell_wrap_2, 2U> &y);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<cell_wrap_3, 1U> &y);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<cell_wrap_4, 2U> &y);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<cell_wrap_5, 2U> &y);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *problemDef_limits, const char_T *identifier, struct1_T *y);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y);
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *controls,
  const char_T *identifier, struct2_T *y);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y);

// Function Definitions
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv[2] = { false, true };

  int32_T iv[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret.set_size(((emlrtRTEInfo *)NULL), sp, iv[0], iv[1]);
  emlrtImportArrayR2015b(sp, src, &(ret.data())[0], 8, false);
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
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 21,
    "modelFilename")), &thisId, y->modelFilename);
  thisId.fIdentifier = "path";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 22, "path")),
                     &thisId, y->path);
  thisId.fIdentifier = "modelLanguage";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 23,
    "modelLanguage")), &thisId, y->modelLanguage);
  thisId.fIdentifier = "fitpars";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 24, "fitpars")),
                     &thisId, y->fitpars);
  thisId.fIdentifier = "otherpars";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 25,
    "otherpars")), &thisId, y->otherpars);
  thisId.fIdentifier = "fitconstr";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 26,
    "fitconstr")), &thisId, y->fitconstr);
  thisId.fIdentifier = "otherconstr";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 27,
    "otherconstr")), &thisId, y->otherconstr);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const cell_8 *u)
{
  const mxArray *y;
  int32_T iv[2];
  coder::array<real_T, 1U> b_u;
  int32_T loop_ub;
  int32_T i;
  const mxArray *b_y;
  const mxArray *c_y;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  y = NULL;
  iv[0] = 1;
  iv[1] = 6;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv[0]));
  emlrtSetCell(y, 0, c_emlrt_marshallOut(sp, u->f1));
  emlrtSetCell(y, 1, c_emlrt_marshallOut(sp, u->f2));
  emlrtSetCell(y, 2, d_emlrt_marshallOut(sp, u->f3));
  emlrtSetCell(y, 3, d_emlrt_marshallOut(sp, u->f4));
  emlrtSetCell(y, 4, c_emlrt_marshallOut(sp, u->f5));
  b_u.set_size(((emlrtRTEInfo *)NULL), sp, u->f6.size(0));
  loop_ub = u->f6.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_u[i] = u->f6[i];
  }

  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(1, ((coder::array<real_T, 1U> *)
    &u->f6)->size()));
  for (i = 0; i < u->f6.size(0); i++) {
    real_T c_u;
    const mxArray *m;
    c_u = b_u[i];
    c_y = NULL;
    m = emlrtCreateDoubleScalar(c_u);
    emlrtAssign(&c_y, m);
    emlrtSetCell(b_y, i, c_y);
  }

  emlrtSetCell(y, 5, b_y);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<char_T, 2U> &ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv[2] = { false, true };

  int32_T iv[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims, &bv[0], iv);
  ret.set_size(((emlrtRTEInfo *)NULL), sp, iv[0], iv[1]);
  emlrtImportArrayR2015b(sp, src, &(ret.data())[0], 1, false);
  emlrtDestroyArray(&src);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y)
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp, const coder::
  array<cell_wrap_7, 1U> &u)
{
  const mxArray *y;
  int32_T i;
  int32_T n;
  coder::array<real_T, 2U> b_u;
  const mxArray *b_y;
  int32_T iv[2];
  const mxArray *m;
  real_T *pData;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(1, ((coder::array<cell_wrap_7, 1U> *)
    &u)->size()));
  i = 0;
  n = u.size(0);
  while (i < n) {
    int32_T loop_ub;
    int32_T i1;
    b_u.set_size(((emlrtRTEInfo *)NULL), sp, u[i].f1.size(0), 2);
    loop_ub = u[i].f1.size(0) * u[i].f1.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_u[i1] = u[i].f1[i1];
    }

    b_y = NULL;
    iv[0] = b_u.size(0);
    iv[1] = b_u.size(1);
    m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    i1 = 0;
    for (loop_ub = 0; loop_ub < b_u.size(0); loop_ub++) {
      pData[i1] = b_u[loop_ub];
      i1++;
    }

    for (loop_ub = 0; loop_ub < b_u.size(0); loop_ub++) {
      pData[i1] = b_u[loop_ub + b_u.size(0)];
      i1++;
    }

    emlrtAssign(&b_y, m);
    emlrtSetCell(y, i, b_y);
    i++;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static real_T cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<char_T, 2U> &y)
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *d_emlrt_marshallOut(const emlrtStack *sp, const coder::
  array<cell_wrap_1, 1U> &u)
{
  const mxArray *y;
  int32_T i;
  int32_T n;
  coder::array<real_T, 2U> b_u;
  const mxArray *b_y;
  int32_T iv[2];
  const mxArray *m;
  real_T *pData;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(1, ((coder::array<cell_wrap_1, 1U> *)
    &u)->size()));
  i = 0;
  n = u.size(0);
  while (i < n) {
    int32_T loop_ub;
    int32_T i1;
    b_u.set_size(((emlrtRTEInfo *)NULL), sp, u[i].f1.size(0), 3);
    loop_ub = u[i].f1.size(0) * u[i].f1.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_u[i1] = u[i].f1[i1];
    }

    b_y = NULL;
    iv[0] = b_u.size(0);
    iv[1] = b_u.size(1);
    m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    i1 = 0;
    for (loop_ub = 0; loop_ub < b_u.size(0); loop_ub++) {
      pData[i1] = b_u[loop_ub];
      i1++;
    }

    for (loop_ub = 0; loop_ub < b_u.size(0); loop_ub++) {
      pData[i1] = b_u[loop_ub + b_u.size(0)];
      i1++;
    }

    for (loop_ub = 0; loop_ub < b_u.size(0); loop_ub++) {
      pData[i1] = b_u[loop_ub + b_u.size(0) * 2];
      i1++;
    }

    emlrtAssign(&b_y, m);
    emlrtSetCell(y, i, b_y);
    i++;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<char_T, 2U> &ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv[2] = { true, true };

  int32_T iv[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims, &bv[0], iv);
  ret.set_size(((emlrtRTEInfo *)NULL), sp, iv[0], iv[1]);
  emlrtImportArrayR2015b(sp, src, &(ret.data())[0], 1, false);
  emlrtDestroyArray(&src);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2] = { -1, -1 };

  const boolean_T bv[2] = { true, true };

  int32_T iv[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret.set_size(((emlrtRTEInfo *)NULL), sp, iv[0], iv[1]);
  emlrtImportArrayR2015b(sp, src, &(ret.data())[0], 8, false);
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *problemDef,
  const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(problemDef), &thisId, y);
  emlrtDestroyArray(&problemDef);
}

static const mxArray *emlrt_marshallOut(const struct4_T *u)
{
  const mxArray *y;
  static const char * sv[9] = { "ssubs", "backgrounds", "qshifts",
    "scalefactors", "nbairs", "nbsubs", "resolutions", "calculations",
    "allSubRough" };

  const coder::array<real_T, 1U> *b_u;
  const mxArray *b_y;
  const mxArray *m;
  real_T *pData;
  int32_T i;
  int32_T b_i;
  static const char * sv1[2] = { "all_chis", "sum_chi" };

  const mxArray *c_y;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 9, &sv[0]));
  b_u = &u->ssubs;
  b_y = NULL;
  m = emlrtCreateNumericArray(1, ((coder::array<real_T, 1U> *)&u->ssubs)->size(),
    mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < b_u->size(0); b_i++) {
    pData[i] = (*b_u)[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "ssubs", b_y, 0);
  b_u = &u->backgrounds;
  b_y = NULL;
  m = emlrtCreateNumericArray(1, ((coder::array<real_T, 1U> *)&u->backgrounds)
    ->size(), mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < b_u->size(0); b_i++) {
    pData[i] = (*b_u)[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "backgrounds", b_y, 1);
  b_u = &u->qshifts;
  b_y = NULL;
  m = emlrtCreateNumericArray(1, ((coder::array<real_T, 1U> *)&u->qshifts)->size
    (), mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < b_u->size(0); b_i++) {
    pData[i] = (*b_u)[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "qshifts", b_y, 2);
  b_u = &u->scalefactors;
  b_y = NULL;
  m = emlrtCreateNumericArray(1, ((coder::array<real_T, 1U> *)&u->scalefactors
    )->size(), mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < b_u->size(0); b_i++) {
    pData[i] = (*b_u)[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "scalefactors", b_y, 3);
  b_u = &u->nbairs;
  b_y = NULL;
  m = emlrtCreateNumericArray(1, ((coder::array<real_T, 1U> *)&u->nbairs)->size(),
    mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < b_u->size(0); b_i++) {
    pData[i] = (*b_u)[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "nbairs", b_y, 4);
  b_u = &u->nbsubs;
  b_y = NULL;
  m = emlrtCreateNumericArray(1, ((coder::array<real_T, 1U> *)&u->nbsubs)->size(),
    mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < b_u->size(0); b_i++) {
    pData[i] = (*b_u)[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "nbsubs", b_y, 5);
  b_u = &u->resolutions;
  b_y = NULL;
  m = emlrtCreateNumericArray(1, ((coder::array<real_T, 1U> *)&u->resolutions)
    ->size(), mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < b_u->size(0); b_i++) {
    pData[i] = (*b_u)[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "resolutions", b_y, 6);
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 2, &sv1[0]));
  b_u = &u->calculations.all_chis;
  c_y = NULL;
  m = emlrtCreateNumericArray(1, ((coder::array<real_T, 1U> *)
    &u->calculations.all_chis)->size(), mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < b_u->size(0); b_i++) {
    pData[i] = (*b_u)[b_i];
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
  b_u = &u->allSubRough;
  b_y = NULL;
  m = emlrtCreateNumericArray(1, ((coder::array<real_T, 1U> *)&u->allSubRough)
    ->size(), mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < b_u->size(0); b_i++) {
    pData[i] = (*b_u)[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "allSubRough", b_y, 8);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<char_T, 2U> &y)
{
  db_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2] = { 1, 2 };

  real_T (*r)[2];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y)
{
  eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2] = { -1, 3 };

  const boolean_T bv[2] = { true, false };

  int32_T iv[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret.set_size(((emlrtRTEInfo *)NULL), sp, iv[0], iv[1]);
  emlrtImportArrayR2015b(sp, src, &(ret.data())[0], 8, false);
  emlrtDestroyArray(&src);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *problemDef_cells, const char_T *identifier, cell_6 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  i_emlrt_marshallIn(sp, emlrtAlias(problemDef_cells), &thisId, y);
  emlrtDestroyArray(&problemDef_cells);
}

static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv[2] = { true, true };

  int32_T iv[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret.set_size(((emlrtRTEInfo *)NULL), sp, iv[0], iv[1]);
  emlrtImportArrayR2015b(sp, src, &(ret.data())[0], 8, false);
  emlrtDestroyArray(&src);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_6 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  bv[0] = false;
  iv[1] = 13;
  bv[1] = false;
  emlrtCheckCell(sp, parentId, u, 2U, &iv[0], &bv[0]);
  thisId.fIdentifier = "1";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 0)), &thisId,
                     y->f1);
  thisId.fIdentifier = "2";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 1)), &thisId,
                     y->f2);
  thisId.fIdentifier = "3";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 2)), &thisId,
                     y->f3);
  thisId.fIdentifier = "4";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 3)), &thisId,
                     y->f4);
  thisId.fIdentifier = "5";
  n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 4)), &thisId,
                     y->f5);
  thisId.fIdentifier = "6";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 5)), &thisId,
                     y->f6);
  thisId.fIdentifier = "7";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 6)), &thisId,
                     y->f7);
  thisId.fIdentifier = "8";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 7)), &thisId,
                     y->f8);
  thisId.fIdentifier = "9";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 8)), &thisId,
                     y->f9);
  thisId.fIdentifier = "10";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 9)), &thisId,
                     y->f10);
  thisId.fIdentifier = "11";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 10)), &thisId,
                     y->f11);
  thisId.fIdentifier = "12";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 11)), &thisId,
                     y->f12);
  thisId.fIdentifier = "13";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, 12)), &thisId,
                     y->f13);
  emlrtDestroyArray(&u);
}

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = { 1, 5 };

  const boolean_T bv[2] = { false, true };

  int32_T iv[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  emlrtImportArrayR2015b(sp, src, (void *)ret_data, 8, false);
  emlrtDestroyArray(&src);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<cell_wrap_0, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  static const boolean_T bv[2] = { false, true };

  int32_T sizes[2];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell(sp, parentId, u, 2U, &iv[0], &bv[0], sizes);
  y.set_size(((emlrtRTEInfo *)NULL), sp, sizes[0], sizes[1]);
  for (int32_T i = 0; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i)), &thisId,
                       y[i].f1);
  }

  emlrtDestroyArray(&u);
}

static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2] = { -1, 2 };

  const boolean_T bv[2] = { true, false };

  int32_T iv[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret.set_size(((emlrtRTEInfo *)NULL), sp, iv[0], iv[1]);
  emlrtImportArrayR2015b(sp, src, &(ret.data())[0], 8, false);
  emlrtDestroyArray(&src);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  fb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<cell_wrap_1, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  static const boolean_T bv[2] = { false, true };

  int32_T sizes[2];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell(sp, parentId, u, 2U, &iv[0], &bv[0], sizes);
  y.set_size(((emlrtRTEInfo *)NULL), sp, sizes[0], sizes[1]);
  for (int32_T i = 0; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i)), &thisId,
                       y[i].f1);
  }

  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y)
{
  gb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<cell_wrap_2, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  static const boolean_T bv[2] = { false, true };

  int32_T sizes[2];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell(sp, parentId, u, 2U, &iv[0], &bv[0], sizes);
  y.set_size(((emlrtRTEInfo *)NULL), sp, sizes[0], sizes[1]);
  for (int32_T i = 0; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i)), &thisId,
                       y[i].f1);
  }

  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y)
{
  hb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<cell_wrap_3, 1U> &y)
{
  emlrtMsgIdentifier thisId;
  int32_T n[1];
  boolean_T bv[1];
  int32_T sizes[1];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  n[0] = -1;
  bv[0] = true;
  emlrtCheckVsCell(sp, parentId, u, 1U, &n[0], &bv[0], sizes);
  y.set_size(((emlrtRTEInfo *)NULL), sp, sizes[0]);
  for (int32_T i = 0; i < sizes[0]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i)), &thisId,
                       y[i].f1.data, y[i].f1.size);
  }

  emlrtDestroyArray(&u);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2])
{
  ib_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<cell_wrap_4, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  static const boolean_T bv[2] = { false, true };

  int32_T sizes[2];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell(sp, parentId, u, 2U, &iv[0], &bv[0], sizes);
  y.set_size(((emlrtRTEInfo *)NULL), sp, sizes[0], sizes[1]);
  for (int32_T i = 0; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i)), &thisId,
                       y[i].f1);
  }

  emlrtDestroyArray(&u);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<cell_wrap_5, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  static const boolean_T bv[2] = { false, true };

  int32_T sizes[2];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell(sp, parentId, u, 2U, &iv[0], &bv[0], sizes);
  y.set_size(((emlrtRTEInfo *)NULL), sp, sizes[0], sizes[1]);
  for (int32_T i = 0; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i)), &thisId,
                       y[i].f1);
  }

  emlrtDestroyArray(&u);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *problemDef_limits, const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  u_emlrt_marshallIn(sp, emlrtAlias(problemDef_limits), &thisId, y);
  emlrtDestroyArray(&problemDef_limits);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
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
  v_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "params")),
                     &thisId, y->params);
  thisId.fIdentifier = "backs";
  v_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "backs")),
                     &thisId, y->backs);
  thisId.fIdentifier = "scales";
  v_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "scales")),
                     &thisId, y->scales);
  thisId.fIdentifier = "shifts";
  v_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "shifts")),
                     &thisId, y->shifts);
  thisId.fIdentifier = "nba";
  v_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4, "nba")),
                     &thisId, y->nba);
  thisId.fIdentifier = "nbs";
  v_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5, "nbs")),
                     &thisId, y->nbs);
  thisId.fIdentifier = "res";
  v_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6, "res")),
                     &thisId, y->res);
  emlrtDestroyArray(&u);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y)
{
  jb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *controls,
  const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  x_emlrt_marshallIn(sp, emlrtAlias(controls), &thisId, y);
  emlrtDestroyArray(&controls);
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[22] = { "para", "proc", "display", "tolX",
    "tolFun", "maxFunEvals", "maxIter", "populationSize", "F_weight", "F_CR",
    "VTR", "numGen", "strategy", "Nlive", "nmcmc", "propScale", "nsTolerance",
    "calcSld", "repeats", "nsimu", "burnin", "checks" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 22, fieldNames, 0U, &dims);
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
  thisId.fIdentifier = "calcSld";
  y->calcSld = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    17, "calcSld")), &thisId);
  thisId.fIdentifier = "repeats";
  y->repeats = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    18, "repeats")), &thisId);
  thisId.fIdentifier = "nsimu";
  y->nsimu = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 19,
    "nsimu")), &thisId);
  thisId.fIdentifier = "burnin";
  y->burnin = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 20,
    "burnin")), &thisId);
  thisId.fIdentifier = "checks";
  y_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 21, "checks")),
                     &thisId, &y->checks);
  emlrtDestroyArray(&u);
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
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

void reflectivity_calculation_api(const mxArray * const prhs[4], int32_T nlhs,
  const mxArray *plhs[2])
{
  struct0_T problemDef;
  cell_6 problemDef_cells;
  struct1_T problemDef_limits;
  struct2_T controls;
  struct4_T problem;
  cell_8 result;
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  // Marshall function inputs
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "problemDef", &problemDef);
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "problemDef_cells",
                     &problemDef_cells);
  t_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "problemDef_limits",
                     &problemDef_limits);
  w_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "controls", &controls);

  // Invoke the target function
  reflectivity_calculation(&st, &problemDef, &problemDef_cells,
    &problemDef_limits, &controls, &problem, &result);

  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(&problem);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(&st, &result);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_reflectivity_calculation_api.cpp)
