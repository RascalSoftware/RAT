/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_callParaMatalbCustlay_api.c
 *
 * Code generation for function '_coder_callParaMatalbCustlay_api'
 *
 */

/* Include files */
#include "_coder_callParaMatalbCustlay_api.h"
#include "callParaMatalbCustlay.h"
#include "callParaMatalbCustlay_data.h"
#include "callParaMatalbCustlay_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                char_T y[15]);

static void ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                char_T ret[16]);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct0_T *y);

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                char_T y[9]);

static void bc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[8]);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3]);

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                char_T y[14]);

static void cc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                char_T ret[13]);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[10]);

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                char_T y[17]);

static void dc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[15]);

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                cell_wrap_3 y[3]);

static void ec_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[3]);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *problemDef,
                             const char_T *identifier, struct0_T *y);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[16]);

static cell_wrap_3 fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                       const emlrtMsgIdentifier *parentId);

static void fc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[30]);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[8]);

static cell_wrap_4 gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                       const emlrtMsgIdentifier *parentId);

static void gc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[6]);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[13]);

static cell_wrap_5 hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                       const emlrtMsgIdentifier *parentId);

static void hc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[2]);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[15]);

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                char_T y[7]);

static void ic_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[438]);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3]);

static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                cell_wrap_5 y[3]);

static void jc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[291]);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[30]);

static cell_wrap_6 kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                       const emlrtMsgIdentifier *parentId);

static void kc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[312]);

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[6]);

static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId, cell_7 *y);

static void lc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                char_T ret[19]);

static void m_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *problemDef_cells,
                               const char_T *identifier, cell_8 *y);

static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId, cell_7 *y);

static void mc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                char_T ret[11]);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, cell_8 *y);

static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                char_T y[6]);

static void nc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                char_T ret[15]);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               cell_wrap_0 y[3]);

static void ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                char_T y[62]);

static void oc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[9]);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2]);

static void pb_emlrt_marshallIn(const emlrtStack *sp,
                                const mxArray *problemDef_limits,
                                const char_T *identifier, struct1_T *y);

static void pc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                char_T ret[14]);

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, cell_1 *y);

static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct1_T *y);

static void qc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                char_T ret[17]);

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[438]);

static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[16]);

static void rc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[7]);

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[291]);

static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *controls,
                                const char_T *identifier, struct2_T *y);

static void sc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[6]);

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[312]);

static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct2_T *y);

static void tc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                char_T ret[62]);

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3]);

static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                char_T y[4]);

static void uc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[16]);

static real_T v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct3_T *y);

static void vc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[4]);

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, cell_2 *y);

static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[3]);

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[19]);

static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                char_T ret[10]);

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[11]);

static real_T yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                char_T y[15])
{
  nc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[16])
{
  static const int32_T dims[2] = {1, 16};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 16);
  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
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
  c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                     (const char_T *)"contrastBacks")),
      &thisId, y->contrastBacks);
  thisId.fIdentifier = "contrastBacksType";
  c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                     (const char_T *)"contrastBacksType")),
      &thisId, y->contrastBacksType);
  thisId.fIdentifier = "TF";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                                    (const char_T *)"TF")),
                     &thisId, y->TF);
  thisId.fIdentifier = "resample";
  c_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 3, (const char_T *)"resample")),
                     &thisId, y->resample);
  thisId.fIdentifier = "dataPresent";
  c_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 4, (const char_T *)"dataPresent")),
                     &thisId, y->dataPresent);
  thisId.fIdentifier = "numberOfContrasts";
  y->numberOfContrasts = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 5,
                                     (const char_T *)"numberOfContrasts")),
      &thisId);
  thisId.fIdentifier = "geometry";
  f_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 6, (const char_T *)"geometry")),
                     &thisId, y->geometry);
  thisId.fIdentifier = "contrastShifts";
  c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 7,
                                     (const char_T *)"contrastShifts")),
      &thisId, y->contrastShifts);
  thisId.fIdentifier = "contrastScales";
  c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 8,
                                     (const char_T *)"contrastScales")),
      &thisId, y->contrastScales);
  thisId.fIdentifier = "contrastNbas";
  c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 9,
                                     (const char_T *)"contrastNbas")),
      &thisId, y->contrastNbas);
  thisId.fIdentifier = "contrastNbss";
  c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 10,
                                     (const char_T *)"contrastNbss")),
      &thisId, y->contrastNbss);
  thisId.fIdentifier = "contrastRes";
  c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 11,
                                     (const char_T *)"contrastRes")),
      &thisId, y->contrastRes);
  thisId.fIdentifier = "backs";
  c_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 12,
                                                    (const char_T *)"backs")),
                     &thisId, y->backs);
  thisId.fIdentifier = "shifts";
  y->shifts =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 13, (const char_T *)"shifts")),
                         &thisId);
  thisId.fIdentifier = "sf";
  y->sf = e_emlrt_marshallIn(sp,
                             emlrtAlias(emlrtGetFieldR2017b(
                                 (emlrtCTX)sp, u, 0, 14, (const char_T *)"sf")),
                             &thisId);
  thisId.fIdentifier = "nba";
  y->nba =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 15,
                                                        (const char_T *)"nba")),
                         &thisId);
  thisId.fIdentifier = "nbs";
  c_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 16,
                                                    (const char_T *)"nbs")),
                     &thisId, y->nbs);
  thisId.fIdentifier = "res";
  y->res =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 17,
                                                        (const char_T *)"res")),
                         &thisId);
  thisId.fIdentifier = "params";
  g_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 18,
                                                    (const char_T *)"params")),
                     &thisId, y->params);
  thisId.fIdentifier = "numberOfLayers";
  y->numberOfLayers = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 19,
                                     (const char_T *)"numberOfLayers")),
      &thisId);
  thisId.fIdentifier = "modelType";
  h_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 20, (const char_T *)"modelType")),
                     &thisId, y->modelType);
  thisId.fIdentifier = "contrastCustomFiles";
  c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 21,
                                     (const char_T *)"contrastCustomFiles")),
      &thisId, y->contrastCustomFiles);
  thisId.fIdentifier = "fitpars";
  i_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 22,
                                                    (const char_T *)"fitpars")),
                     &thisId, y->fitpars);
  thisId.fIdentifier = "otherpars";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 23, (const char_T *)"otherpars")),
                     &thisId, y->otherpars);
  thisId.fIdentifier = "fitconstr";
  k_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 24, (const char_T *)"fitconstr")),
                     &thisId, y->fitconstr);
  thisId.fIdentifier = "otherconstr";
  l_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 25,
                                     (const char_T *)"otherconstr")),
      &thisId, y->otherconstr);
  emlrtDestroyArray(&u);
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId, char_T y[9])
{
  oc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void bc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[8])
{
  static const int32_T dims[2] = {1, 8};
  real_T(*r)[8];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[8])emlrtMxGetData(src);
  for (i = 0; i < 8; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3])
{
  wb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                char_T y[14])
{
  pc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void cc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[13])
{
  static const int32_T dims[2] = {1, 13};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 13);
  emlrtDestroyArray(&src);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[10])
{
  xb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                char_T y[17])
{
  qc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void dc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[15])
{
  static const int32_T dims[2] = {1, 15};
  real_T(*r)[15];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[15])emlrtMxGetData(src);
  for (i = 0; i < 15; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = yb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                cell_wrap_3 y[3])
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  char_T str[11];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  bv[0] = false;
  iv[1] = 3;
  bv[1] = false;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0]);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y[0].f1);
  sprintf(&str[0], "%d", 2);
  thisId.fIdentifier = &str[0];
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                     &thisId, y[1].f1);
  sprintf(&str[0], "%d", 3);
  thisId.fIdentifier = &str[0];
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)),
                     &thisId, y[2].f1);
  emlrtDestroyArray(&u);
}

static void ec_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[3])
{
  static const int32_T dims = 3;
  real_T(*r)[3];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  r = (real_T(*)[3])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *problemDef,
                             const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(problemDef), &thisId, y);
  emlrtDestroyArray(&problemDef);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[16])
{
  ac_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static cell_wrap_3 fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                       const emlrtMsgIdentifier *parentId)
{
  cell_wrap_3 y;
  emlrtMsgIdentifier thisId;
  int32_T i;
  char_T str[11];
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  i = 1;
  b = false;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 1U, &i, &b);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y.f1);
  emlrtDestroyArray(&u);
  return y;
}

static void fc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[30])
{
  static const int32_T dims[2] = {15, 2};
  real_T(*r)[30];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[30])emlrtMxGetData(src);
  for (i = 0; i < 30; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[8])
{
  bc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static cell_wrap_4 gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                       const emlrtMsgIdentifier *parentId)
{
  cell_wrap_4 y;
  emlrtMsgIdentifier thisId;
  int32_T i;
  char_T str[11];
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  i = 1;
  b = false;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 1U, &i, &b);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y.f1);
  emlrtDestroyArray(&u);
  return y;
}

static void gc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[6])
{
  static const int32_T dims[2] = {3, 2};
  real_T(*r)[6];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[6])emlrtMxGetData(src);
  for (i = 0; i < 6; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[13])
{
  cc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static cell_wrap_5 hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                       const emlrtMsgIdentifier *parentId)
{
  cell_wrap_5 y;
  emlrtMsgIdentifier thisId;
  int32_T i;
  char_T str[11];
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  i = 1;
  b = false;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 1U, &i, &b);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  ib_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                      &thisId, y.f1);
  emlrtDestroyArray(&u);
  return y;
}

static void hc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2] = {1, 2};
  real_T(*r)[2];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[15])
{
  dc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId, char_T y[7])
{
  rc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ic_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[438])
{
  static const int32_T dims[2] = {146, 3};
  real_T(*r)[438];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[438])emlrtMxGetData(src);
  for (i = 0; i < 438; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3])
{
  ec_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                cell_wrap_5 y[3])
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  char_T str[11];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  bv[0] = false;
  iv[1] = 3;
  bv[1] = false;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0]);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  ib_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                      &thisId, y[0].f1);
  sprintf(&str[0], "%d", 2);
  thisId.fIdentifier = &str[0];
  ib_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                      &thisId, y[1].f1);
  sprintf(&str[0], "%d", 3);
  thisId.fIdentifier = &str[0];
  ib_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)),
                      &thisId, y[2].f1);
  emlrtDestroyArray(&u);
}

static void jc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[291])
{
  static const int32_T dims[2] = {97, 3};
  real_T(*r)[291];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[291])emlrtMxGetData(src);
  for (i = 0; i < 291; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[30])
{
  fc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static cell_wrap_6 kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                       const emlrtMsgIdentifier *parentId)
{
  cell_wrap_6 y;
  emlrtMsgIdentifier thisId;
  int32_T i;
  char_T str[11];
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  i = 1;
  b = false;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 1U, &i, &b);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y.f1);
  emlrtDestroyArray(&u);
  return y;
}

static void kc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[312])
{
  static const int32_T dims[2] = {104, 3};
  real_T(*r)[312];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[312])emlrtMxGetData(src);
  for (i = 0; i < 312; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[6])
{
  gc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId, cell_7 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T i;
  char_T str[11];
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  i = 1;
  b = false;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 1U, &i, &b);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  mb_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)), &thisId, y);
  emlrtDestroyArray(&u);
}

static void lc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[19])
{
  static const int32_T dims[2] = {1, 19};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 19);
  emlrtDestroyArray(&src);
}

static void m_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *problemDef_cells,
                               const char_T *identifier, cell_8 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  n_emlrt_marshallIn(sp, emlrtAlias(problemDef_cells), &thisId, y);
  emlrtDestroyArray(&problemDef_cells);
}

static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId, cell_7 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  bv[0] = false;
  iv[1] = 3;
  bv[1] = false;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0]);
  thisId.fIdentifier = "1";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y->f1);
  thisId.fIdentifier = "2";
  nb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                      &thisId, y->f2);
  thisId.fIdentifier = "3";
  ob_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)),
                      &thisId, y->f3);
  emlrtDestroyArray(&u);
}

static void mc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[11])
{
  static const int32_T dims[2] = {1, 11};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 11);
  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, cell_8 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  bv[0] = false;
  iv[1] = 14;
  bv[1] = false;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0]);
  thisId.fIdentifier = "1";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y->f1);
  thisId.fIdentifier = "2";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                     &thisId, &y->f2);
  thisId.fIdentifier = "3";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)),
                     &thisId, y->f3);
  thisId.fIdentifier = "4";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 3)),
                     &thisId, y->f4);
  thisId.fIdentifier = "5";
  u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 4)),
                     &thisId, y->f5);
  thisId.fIdentifier = "6";
  y->f6[0] = v_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 5)), &thisId);
  thisId.fIdentifier = "7";
  w_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 6)),
                     &thisId, &y->f7);
  thisId.fIdentifier = "8";
  eb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 7)),
                      &thisId, y->f8);
  thisId.fIdentifier = "9";
  y->f9[0] = fb_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 8)), &thisId);
  thisId.fIdentifier = "10";
  y->f10[0] = gb_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 9)), &thisId);
  thisId.fIdentifier = "11";
  y->f11[0] = hb_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 10)), &thisId);
  thisId.fIdentifier = "12";
  jb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 11)),
                      &thisId, y->f12);
  thisId.fIdentifier = "13";
  y->f13[0] = kb_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 12)), &thisId);
  thisId.fIdentifier = "14";
  lb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 13)),
                      &thisId, &y->f14[0]);
  emlrtDestroyArray(&u);
}

static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId, char_T y[6])
{
  sc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void nc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[15])
{
  static const int32_T dims[2] = {1, 15};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 15);
  emlrtDestroyArray(&src);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               cell_wrap_0 y[3])
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  char_T str[11];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  bv[0] = false;
  iv[1] = 3;
  bv[1] = false;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0]);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y[0].f1);
  sprintf(&str[0], "%d", 2);
  thisId.fIdentifier = &str[0];
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                     &thisId, y[1].f1);
  sprintf(&str[0], "%d", 3);
  thisId.fIdentifier = &str[0];
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)),
                     &thisId, y[2].f1);
  emlrtDestroyArray(&u);
}

static void ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                char_T y[62])
{
  tc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void oc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[9])
{
  static const int32_T dims[2] = {1, 9};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 9);
  emlrtDestroyArray(&src);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2])
{
  hc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void pb_emlrt_marshallIn(const emlrtStack *sp,
                                const mxArray *problemDef_limits,
                                const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  qb_emlrt_marshallIn(sp, emlrtAlias(problemDef_limits), &thisId, y);
  emlrtDestroyArray(&problemDef_limits);
}

static void pc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = {1, 14};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 14);
  emlrtDestroyArray(&src);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, cell_1 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  bv[0] = false;
  iv[1] = 3;
  bv[1] = false;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0]);
  thisId.fIdentifier = "1";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y->f1);
  thisId.fIdentifier = "2";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                     &thisId, y->f2);
  thisId.fIdentifier = "3";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)),
                     &thisId, y->f3);
  emlrtDestroyArray(&u);
}

static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
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
  rb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                                     (const char_T *)"params")),
                      &thisId, y->params);
  thisId.fIdentifier = "backs";
  l_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                                    (const char_T *)"backs")),
                     &thisId, y->backs);
  thisId.fIdentifier = "scales";
  p_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                                    (const char_T *)"scales")),
                     &thisId, y->scales);
  thisId.fIdentifier = "shifts";
  p_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 3,
                                                    (const char_T *)"shifts")),
                     &thisId, y->shifts);
  thisId.fIdentifier = "nba";
  p_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 4,
                                                    (const char_T *)"nba")),
                     &thisId, y->nba);
  thisId.fIdentifier = "nbs";
  l_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 5,
                                                    (const char_T *)"nbs")),
                     &thisId, y->nbs);
  thisId.fIdentifier = "res";
  p_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 6,
                                                    (const char_T *)"res")),
                     &thisId, y->res);
  emlrtDestroyArray(&u);
}

static void qc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[17])
{
  static const int32_T dims[2] = {1, 17};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 17);
  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[438])
{
  ic_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                real_T y[16])
{
  uc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void rc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[7])
{
  static const int32_T dims[2] = {1, 7};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 7);
  emlrtDestroyArray(&src);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[291])
{
  jc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *controls,
                                const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  tb_emlrt_marshallIn(sp, emlrtAlias(controls), &thisId, y);
  emlrtDestroyArray(&controls);
}

static void sc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[6])
{
  static const int32_T dims[2] = {1, 6};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 6);
  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[312])
{
  kc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
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
  nb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                                     (const char_T *)"para")),
                      &thisId, y->para);
  thisId.fIdentifier = "proc";
  bb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                                     (const char_T *)"proc")),
                      &thisId, y->proc);
  thisId.fIdentifier = "display";
  ub_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b(
                          (emlrtCTX)sp, u, 0, 2, (const char_T *)"display")),
                      &thisId, y->display);
  thisId.fIdentifier = "tolX";
  y->tolX =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 3, (const char_T *)"tolX")),
                         &thisId);
  thisId.fIdentifier = "tolFun";
  y->tolFun =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 4, (const char_T *)"tolFun")),
                         &thisId);
  thisId.fIdentifier = "maxFunEvals";
  y->maxFunEvals = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 5,
                                     (const char_T *)"maxFunEvals")),
      &thisId);
  thisId.fIdentifier = "maxIter";
  y->maxIter =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 6, (const char_T *)"maxIter")),
                         &thisId);
  thisId.fIdentifier = "populationSize";
  y->populationSize = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 7,
                                     (const char_T *)"populationSize")),
      &thisId);
  thisId.fIdentifier = "F_weight";
  y->F_weight = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 8,
                                     (const char_T *)"F_weight")),
      &thisId);
  thisId.fIdentifier = "F_CR";
  y->F_CR =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 9, (const char_T *)"F_CR")),
                         &thisId);
  thisId.fIdentifier = "VTR";
  y->VTR =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 10,
                                                        (const char_T *)"VTR")),
                         &thisId);
  thisId.fIdentifier = "numGen";
  y->numGen =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 11, (const char_T *)"numGen")),
                         &thisId);
  thisId.fIdentifier = "strategy";
  y->strategy = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 12,
                                     (const char_T *)"strategy")),
      &thisId);
  thisId.fIdentifier = "Nlive";
  y->Nlive =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 13, (const char_T *)"Nlive")),
                         &thisId);
  thisId.fIdentifier = "nmcmc";
  y->nmcmc =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 14, (const char_T *)"nmcmc")),
                         &thisId);
  thisId.fIdentifier = "propScale";
  y->propScale = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 15,
                                     (const char_T *)"propScale")),
      &thisId);
  thisId.fIdentifier = "nsTolerance";
  y->nsTolerance = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 16,
                                     (const char_T *)"nsTolerance")),
      &thisId);
  thisId.fIdentifier = "calcSld";
  y->calcSld = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 17,
                                     (const char_T *)"calcSld")),
      &thisId);
  thisId.fIdentifier = "repeats";
  y->repeats = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 18,
                                     (const char_T *)"repeats")),
      &thisId);
  thisId.fIdentifier = "nsimu";
  y->nsimu =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 19, (const char_T *)"nsimu")),
                         &thisId);
  thisId.fIdentifier = "burnin";
  y->burnin =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 20, (const char_T *)"burnin")),
                         &thisId);
  thisId.fIdentifier = "resamPars";
  p_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 21, (const char_T *)"resamPars")),
                     &thisId, y->resamPars);
  thisId.fIdentifier = "updateFreq";
  y->updateFreq = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 22,
                                     (const char_T *)"updateFreq")),
      &thisId);
  thisId.fIdentifier = "updatePlotFreq";
  y->updatePlotFreq = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 23,
                                     (const char_T *)"updatePlotFreq")),
      &thisId);
  thisId.fIdentifier = "checks";
  vb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 24,
                                                     (const char_T *)"checks")),
                      &thisId, &y->checks);
  emlrtDestroyArray(&u);
}

static void tc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[62])
{
  static const int32_T dims[2] = {1, 62};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 62);
  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3])
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  char_T str[11];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  bv[0] = false;
  iv[1] = 3;
  bv[1] = false;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0]);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  y[0] = e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)), &thisId);
  sprintf(&str[0], "%d", 2);
  thisId.fIdentifier = &str[0];
  y[1] = e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)), &thisId);
  sprintf(&str[0], "%d", 3);
  thisId.fIdentifier = &str[0];
  y[2] = e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)), &thisId);
  emlrtDestroyArray(&u);
}

static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId, char_T y[4])
{
  vc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void uc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[16])
{
  static const int32_T dims[2] = {8, 2};
  real_T(*r)[16];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[16])emlrtMxGetData(src);
  for (i = 0; i < 16; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static real_T v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  int32_T i;
  char_T str[11];
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  i = 1;
  b = false;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 1U, &i, &b);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  y = e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
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
  g_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                     (const char_T *)"params_fitYesNo")),
      &thisId, y->params_fitYesNo);
  thisId.fIdentifier = "backs_fitYesNo";
  c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                     (const char_T *)"backs_fitYesNo")),
      &thisId, y->backs_fitYesNo);
  thisId.fIdentifier = "shifts_fitYesNo";
  y->shifts_fitYesNo = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                     (const char_T *)"shifts_fitYesNo")),
      &thisId);
  thisId.fIdentifier = "scales_fitYesNo";
  y->scales_fitYesNo = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 3,
                                     (const char_T *)"scales_fitYesNo")),
      &thisId);
  thisId.fIdentifier = "nbairs_fitYesNo";
  y->nbairs_fitYesNo = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 4,
                                     (const char_T *)"nbairs_fitYesNo")),
      &thisId);
  thisId.fIdentifier = "nbsubs_fitYesNo";
  c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 5,
                                     (const char_T *)"nbsubs_fitYesNo")),
      &thisId, y->nbsubs_fitYesNo);
  thisId.fIdentifier = "resol_fitYesNo";
  y->resol_fitYesNo = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 6,
                                     (const char_T *)"resol_fitYesNo")),
      &thisId);
  emlrtDestroyArray(&u);
}

static void vc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[4])
{
  static const int32_T dims[2] = {1, 4};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 4);
  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, cell_2 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  bv[0] = false;
  iv[1] = 8;
  bv[1] = false;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0]);
  thisId.fIdentifier = "1";
  x_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y->f1);
  thisId.fIdentifier = "2";
  y_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                     &thisId, y->f2);
  thisId.fIdentifier = "3";
  ab_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)),
                      &thisId, y->f3);
  thisId.fIdentifier = "4";
  bb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 3)),
                      &thisId, y->f4);
  thisId.fIdentifier = "5";
  cb_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 4)),
                      &thisId, y->f5);
  thisId.fIdentifier = "6";
  db_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 5)),
                      &thisId, y->f6);
  thisId.fIdentifier = "7";
  db_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 6)),
                      &thisId, y->f7);
  thisId.fIdentifier = "8";
  ab_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 7)),
                      &thisId, y->f8);
  emlrtDestroyArray(&u);
}

static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[3])
{
  static const int32_T dims[2] = {1, 3};
  real_T(*r)[3];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[3])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  emlrtDestroyArray(&src);
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[19])
{
  lc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[10])
{
  static const int32_T dims[2] = {1, 10};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 10);
  emlrtDestroyArray(&src);
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[11])
{
  mc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void callParaMatalbCustlay_api(const mxArray *const prhs[4], int32_T nlhs,
                               const mxArray *plhs[2])
{
  cell_8 problemDef_cells;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *allRoughs;
  const mxArray *outLayers;
  struct0_T problemDef;
  struct1_T problemDef_limits;
  struct2_T controls;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "problemDef", &problemDef);
  m_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "problemDef_cells",
                     &problemDef_cells);
  pb_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "problemDef_limits",
                      &problemDef_limits);
  sb_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "controls", &controls);
  /* Invoke the target function */
  callParaMatalbCustlay(&st, &problemDef, &problemDef_cells, &problemDef_limits,
                        &controls, &outLayers, &allRoughs);
  /* Marshall function outputs */
  plhs[0] = outLayers;
  if (nlhs > 1) {
    plhs[1] = allRoughs;
  }
}

/* End of code generation (_coder_callParaMatalbCustlay_api.c) */
