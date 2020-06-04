/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_linear_DE_new_test_api.c
 *
 * Code generation for function '_coder_linear_DE_new_test_api'
 *
 */

/* Include files */
#include "tmwtypes.h"
#include "_coder_linear_DE_new_test_api.h"
#include "_coder_linear_DE_new_test_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131435U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "linear_DE_new_test",                /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[15]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *problem, const
  char_T *identifier, struct0_T *y);
static const mxArray *emlrt_marshallOut(const struct0_T *u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *controls,
  const char_T *identifier);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[15]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4]);
static real_T p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[5] = { "data", "fitpars", "line", "fitconstr",
    "S_struct" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 5, fieldNames, 0U, &dims);
  thisId.fIdentifier = "data";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "data")),
                     &thisId, y->data);
  thisId.fIdentifier = "fitpars";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "fitpars")),
                     &thisId, y->fitpars);
  thisId.fIdentifier = "line";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "line")),
                     &thisId);
  thisId.fIdentifier = "fitconstr";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "fitconstr")),
                     &thisId, y->fitconstr);
  thisId.fIdentifier = "S_struct";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "S_struct")),
                     &thisId, &y->S_struct);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[15])
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *problem, const
  char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(problem), &thisId, y);
  emlrtDestroyArray(&problem);
}

static const mxArray *emlrt_marshallOut(const struct0_T *u)
{
  const mxArray *y;
  const mxArray *b_y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 5, 3 };

  real_T *pData;
  int32_T i;
  const mxArray *c_y;
  static const int32_T iv1[2] = { 1, 2 };

  const mxArray *d_y;
  static const int32_T iv2[2] = { 0, 0 };

  const mxArray *e_y;
  static const int32_T iv3[2] = { 2, 2 };

  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  static const int32_T iv4[1] = { 2 };

  const mxArray *p_y;
  static const int32_T iv5[1] = { 2 };

  const mxArray *q_y;
  static const int32_T iv6[2] = { 2, 2 };

  const mxArray *r_y;
  const mxArray *s_y;
  const mxArray *t_y;
  const mxArray *u_y;
  const mxArray *v_y;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  b_y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m0);
  for (i = 0; i < 15; i++) {
    pData[i] = u->data[i];
  }

  emlrtAssign(&b_y, m0);
  emlrtAddField(y, b_y, "data", 0);
  c_y = NULL;
  m0 = emlrtCreateNumericArray(2, iv1, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m0);
  for (i = 0; i < 2; i++) {
    pData[i] = u->fitpars[i];
  }

  emlrtAssign(&c_y, m0);
  emlrtAddField(y, c_y, "fitpars", 0);
  d_y = NULL;
  m0 = emlrtCreateNumericArray(2, iv2, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&d_y, m0);
  emlrtAddField(y, d_y, "line", 0);
  e_y = NULL;
  m0 = emlrtCreateNumericArray(2, iv3, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m0);
  for (i = 0; i < 4; i++) {
    pData[i] = u->fitconstr[i];
  }

  emlrtAssign(&e_y, m0);
  emlrtAddField(y, e_y, "fitconstr", 0);
  f_y = NULL;
  emlrtAssign(&f_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  g_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->S_struct.I_lentol);
  emlrtAssign(&g_y, m0);
  emlrtAddField(f_y, g_y, "I_lentol", 0);
  h_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->S_struct.FVr_x);
  emlrtAssign(&h_y, m0);
  emlrtAddField(f_y, h_y, "FVr_x", 0);
  i_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->S_struct.FVr_lim_up);
  emlrtAssign(&i_y, m0);
  emlrtAddField(f_y, i_y, "FVr_lim_up", 0);
  j_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->S_struct.FVr_lim_lo);
  emlrtAssign(&j_y, m0);
  emlrtAddField(f_y, j_y, "FVr_lim_lo", 0);
  k_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->S_struct.I_NP);
  emlrtAssign(&k_y, m0);
  emlrtAddField(f_y, k_y, "I_NP", 0);
  l_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->S_struct.F_weight);
  emlrtAssign(&l_y, m0);
  emlrtAddField(f_y, l_y, "F_weight", 0);
  m_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->S_struct.F_CR);
  emlrtAssign(&m_y, m0);
  emlrtAddField(f_y, m_y, "F_CR", 0);
  n_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->S_struct.I_D);
  emlrtAssign(&n_y, m0);
  emlrtAddField(f_y, n_y, "I_D", 0);
  o_y = NULL;
  m0 = emlrtCreateNumericArray(1, iv4, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m0);
  for (i = 0; i < 2; i++) {
    pData[i] = u->S_struct.FVr_minbound[i];
  }

  emlrtAssign(&o_y, m0);
  emlrtAddField(f_y, o_y, "FVr_minbound", 0);
  p_y = NULL;
  m0 = emlrtCreateNumericArray(1, iv5, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m0);
  for (i = 0; i < 2; i++) {
    pData[i] = u->S_struct.FVr_maxbound[i];
  }

  emlrtAssign(&p_y, m0);
  emlrtAddField(f_y, p_y, "FVr_maxbound", 0);
  q_y = NULL;
  m0 = emlrtCreateNumericArray(2, iv6, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m0);
  for (i = 0; i < 4; i++) {
    pData[i] = u->S_struct.I_bnd_constr[i];
  }

  emlrtAssign(&q_y, m0);
  emlrtAddField(f_y, q_y, "I_bnd_constr", 0);
  r_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->S_struct.I_itermax);
  emlrtAssign(&r_y, m0);
  emlrtAddField(f_y, r_y, "I_itermax", 0);
  s_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->S_struct.F_VTR);
  emlrtAssign(&s_y, m0);
  emlrtAddField(f_y, s_y, "F_VTR", 0);
  t_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->S_struct.I_strategy);
  emlrtAssign(&t_y, m0);
  emlrtAddField(f_y, t_y, "I_strategy", 0);
  u_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->S_struct.I_refresh);
  emlrtAssign(&u_y, m0);
  emlrtAddField(f_y, u_y, "I_refresh", 0);
  v_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->S_struct.I_plotting);
  emlrtAssign(&v_y, m0);
  emlrtAddField(f_y, v_y, "I_plotting", 0);
  emlrtAddField(y, f_y, "S_struct", 0);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4])
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[16] = { "I_lentol", "FVr_x", "FVr_lim_up",
    "FVr_lim_lo", "I_NP", "F_weight", "F_CR", "I_D", "FVr_minbound",
    "FVr_maxbound", "I_bnd_constr", "I_itermax", "F_VTR", "I_strategy",
    "I_refresh", "I_plotting" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 16, fieldNames, 0U, &dims);
  thisId.fIdentifier = "I_lentol";
  y->I_lentol = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "I_lentol")), &thisId);
  thisId.fIdentifier = "FVr_x";
  y->FVr_x = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "FVr_x")), &thisId);
  thisId.fIdentifier = "FVr_lim_up";
  y->FVr_lim_up = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "FVr_lim_up")), &thisId);
  thisId.fIdentifier = "FVr_lim_lo";
  y->FVr_lim_lo = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "FVr_lim_lo")), &thisId);
  thisId.fIdentifier = "I_NP";
  y->I_NP = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "I_NP")), &thisId);
  thisId.fIdentifier = "F_weight";
  y->F_weight = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "F_weight")), &thisId);
  thisId.fIdentifier = "F_CR";
  y->F_CR = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "F_CR")), &thisId);
  thisId.fIdentifier = "I_D";
  y->I_D = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "I_D")),
    &thisId);
  thisId.fIdentifier = "FVr_minbound";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "FVr_minbound")),
                     &thisId, y->FVr_minbound);
  thisId.fIdentifier = "FVr_maxbound";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "FVr_maxbound")),
                     &thisId, y->FVr_maxbound);
  thisId.fIdentifier = "I_bnd_constr";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "I_bnd_constr")),
                     &thisId, y->I_bnd_constr);
  thisId.fIdentifier = "I_itermax";
  y->I_itermax = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "I_itermax")), &thisId);
  thisId.fIdentifier = "F_VTR";
  y->F_VTR = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "F_VTR")), &thisId);
  thisId.fIdentifier = "I_strategy";
  y->I_strategy = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "I_strategy")), &thisId);
  thisId.fIdentifier = "I_refresh";
  y->I_refresh = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "I_refresh")), &thisId);
  thisId.fIdentifier = "I_plotting";
  y->I_plotting = h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "I_plotting")), &thisId);
  emlrtDestroyArray(&u);
}

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = p_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *controls,
  const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  k_emlrt_marshallIn(sp, emlrtAlias(controls), &thisId);
  emlrtDestroyArray(&controls);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[15])
{
  static const int32_T dims[2] = { 5, 3 };

  int32_T i0;
  int32_T i1;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 5; i1++) {
      ret[i1 + 5 * i0] = (*(real_T (*)[15])mxGetData(src))[i1 + 5 * i0];
    }
  }

  emlrtDestroyArray(&src);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2] = { 1, 2 };

  int32_T i2;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i2 = 0; i2 < 2; i2++) {
    ret[i2] = (*(real_T (*)[2])mxGetData(src))[i2];
  }

  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  emlrtDestroyArray(&src);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4])
{
  static const int32_T dims[2] = { 2, 2 };

  int32_T i3;
  int32_T i4;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i3 = 0; i3 < 2; i3++) {
    for (i4 = 0; i4 < 2; i4++) {
      ret[i4 + (i3 << 1)] = (*(real_T (*)[4])mxGetData(src))[i4 + (i3 << 1)];
    }
  }

  emlrtDestroyArray(&src);
}

static real_T p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[1] = { 2 };

  int32_T i5;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  for (i5 = 0; i5 < 2; i5++) {
    ret[i5] = (*(real_T (*)[2])mxGetData(src))[i5];
  }

  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  mxGetData(src);
  emlrtDestroyArray(&src);
}

void linear_DE_new_test_api(const mxArray *prhs[2], const mxArray *plhs[1])
{
  struct0_T problem;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  prhs[1] = emlrtProtectR2012b(prhs[1], 1, false, -1);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "problem", &problem);
  j_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "controls");

  /* Invoke the target function */
  linear_DE_new_test(&problem);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&problem);
}

void linear_DE_new_test_atexit(void)
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
  linear_DE_new_test_xil_terminate();
}

void linear_DE_new_test_initialize(void)
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

void linear_DE_new_test_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (_coder_linear_DE_new_test_api.c) */
