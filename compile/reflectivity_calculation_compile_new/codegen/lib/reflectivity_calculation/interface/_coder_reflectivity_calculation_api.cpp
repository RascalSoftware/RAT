//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// _coder_reflectivity_calculation_api.cpp
//
// Code generation for function 'reflectivity_calculation'
//

// Include files
#include "_coder_reflectivity_calculation_api.h"
#include "_coder_reflectivity_calculation_mex.h"
#include "coder_array_mex.h"
#include "coder_bounded_array.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131610U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "reflectivity_calculation",                           // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret_data[], int32_T ret_size[2]);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<char_T, 2U> &ret);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2]);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y);

static const mxArray *b_emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static const mxArray *b_emlrt_marshallOut(const coder::array<real_T, 1U> &u);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *problemDef,
                             const char_T *identifier, struct0_T *y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct0_T *y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct2_T *y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *controls,
                             const char_T *identifier, struct2_T *y);

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *problemDef_cells,
                             const char_T *identifier, cell_6 *y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, cell_6 *y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<cell_wrap_0, 2U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[2]);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct3_T *y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<cell_wrap_1, 2U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<char_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<cell_wrap_2, 2U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<cell_wrap_3, 1U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             real_T y_data[], int32_T y_size[2]);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<cell_wrap_4, 2U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<cell_wrap_5, 2U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             cell_wrap_4 y[3]);

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *problemDef_limits,
                             const char_T *identifier, struct1_T *y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct1_T *y);

static const mxArray *emlrt_marshallOut(const struct4_T *u);

static const mxArray *emlrt_marshallOut(const real_T u);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static const mxArray *emlrt_marshallOut(const coder::array<cell_wrap_7, 1U> &u);

static const mxArray *emlrt_marshallOut(const coder::array<cell_wrap_8, 1U> &u);

static const mxArray *emlrt_marshallOut(const cell_9 *u);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u);

static const mxArray *emlrt_marshallOut(const struct5_T *u);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2]{1, 2};
  real_T(*r)[2];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<char_T, 2U> &ret)
{
  static const int32_T dims[2]{1, -1};
  int32_T iv[2];
  const boolean_T bv[2]{false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret.set_size(iv[0], iv[1]);
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret[0], 1, false);
  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2]{1, 10};
  int32_T iv[2];
  const boolean_T bv[2]{false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y)
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const coder::array<real_T, 1U> &u)
{
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(
                      1, ((coder::array<real_T, 1U> *)&u)->size()));
  for (int32_T i{0}; i < u.size(0); i++) {
    emlrtSetCell(y, i, emlrt_marshallOut(u[i]));
  }
  return y;
}

static const mxArray *b_emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T b_i;
  int32_T i;
  y = nullptr;
  iv[0] = u.size(0);
  iv[1] = 3;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < u.size(0); b_i++) {
    pData[i] = u[b_i];
    i++;
  }
  for (b_i = 0; b_i < u.size(0); b_i++) {
    pData[i] = u[b_i + u.size(0)];
    i++;
  }
  for (b_i = 0; b_i < u.size(0); b_i++) {
    pData[i] = u[b_i + u.size(0) * 2];
    i++;
  }
  emlrtAssign(&y, m);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y)
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y)
{
  h_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{1, -1};
  int32_T iv[2];
  const boolean_T bv[2]{false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret.set_size(iv[0], iv[1]);
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret[0], 8, false);
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<cell_wrap_0, 2U> &y)
{
  static const boolean_T bv[2]{false, true};
  emlrtMsgIdentifier thisId;
  real_T dv[2];
  int32_T iv[2];
  int32_T sizes[2];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0], &sizes[0]);
  y.set_size(sizes[0], sizes[1]);
  for (int32_T i{0}; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                     &thisId, dv);
    y[i].f1[0] = dv[0];
    y[i].f1[1] = dv[1];
  }
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y)
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct3_T *y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[7]{"params_fitYesNo", "backs_fitYesNo",
                                     "shifts_fitYesNo", "scales_fitYesNo",
                                     "nbairs_fitYesNo", "nbsubs_fitYesNo",
                                     "resol_fitYesNo"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 7,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "params_fitYesNo";
  emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                     (const char_T *)"params_fitYesNo")),
      &thisId, y->params_fitYesNo);
  thisId.fIdentifier = "backs_fitYesNo";
  emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                     (const char_T *)"backs_fitYesNo")),
      &thisId, y->backs_fitYesNo);
  thisId.fIdentifier = "shifts_fitYesNo";
  emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                     (const char_T *)"shifts_fitYesNo")),
      &thisId, y->shifts_fitYesNo);
  thisId.fIdentifier = "scales_fitYesNo";
  emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 3,
                                     (const char_T *)"scales_fitYesNo")),
      &thisId, y->scales_fitYesNo);
  thisId.fIdentifier = "nbairs_fitYesNo";
  emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 4,
                                     (const char_T *)"nbairs_fitYesNo")),
      &thisId, y->nbairs_fitYesNo);
  thisId.fIdentifier = "nbsubs_fitYesNo";
  emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 5,
                                     (const char_T *)"nbsubs_fitYesNo")),
      &thisId, y->nbsubs_fitYesNo);
  thisId.fIdentifier = "resol_fitYesNo";
  emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 6,
                                     (const char_T *)"resol_fitYesNo")),
      &thisId, y->resol_fitYesNo);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct2_T *y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[22]{
      "para",        "proc",        "display",        "tolX",     "tolFun",
      "maxFunEvals", "maxIter",     "populationSize", "F_weight", "F_CR",
      "VTR",         "numGen",      "strategy",       "Nlive",    "nmcmc",
      "propScale",   "nsTolerance", "calcSld",        "repeats",  "nsimu",
      "burnin",      "checks"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 22,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "para";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                                  (const char_T *)"para")),
                   &thisId, y->para);
  thisId.fIdentifier = "proc";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                                  (const char_T *)"proc")),
                   &thisId, y->proc);
  thisId.fIdentifier = "display";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                                  (const char_T *)"display")),
                   &thisId, y->display);
  thisId.fIdentifier = "tolX";
  y->tolX =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 3,
                                                      (const char_T *)"tolX")),
                       &thisId);
  thisId.fIdentifier = "tolFun";
  y->tolFun =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b(
                           (emlrtCTX)sp, u, 0, 4, (const char_T *)"tolFun")),
                       &thisId);
  thisId.fIdentifier = "maxFunEvals";
  y->maxFunEvals = emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 5,
                                     (const char_T *)"maxFunEvals")),
      &thisId);
  thisId.fIdentifier = "maxIter";
  y->maxIter =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b(
                           (emlrtCTX)sp, u, 0, 6, (const char_T *)"maxIter")),
                       &thisId);
  thisId.fIdentifier = "populationSize";
  y->populationSize = emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 7,
                                     (const char_T *)"populationSize")),
      &thisId);
  thisId.fIdentifier = "F_weight";
  y->F_weight =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b(
                           (emlrtCTX)sp, u, 0, 8, (const char_T *)"F_weight")),
                       &thisId);
  thisId.fIdentifier = "F_CR";
  y->F_CR =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 9,
                                                      (const char_T *)"F_CR")),
                       &thisId);
  thisId.fIdentifier = "VTR";
  y->VTR = emlrt_marshallIn(sp,
                            emlrtAlias(emlrtGetFieldR2017b(
                                (emlrtCTX)sp, u, 0, 10, (const char_T *)"VTR")),
                            &thisId);
  thisId.fIdentifier = "numGen";
  y->numGen =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b(
                           (emlrtCTX)sp, u, 0, 11, (const char_T *)"numGen")),
                       &thisId);
  thisId.fIdentifier = "strategy";
  y->strategy =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b(
                           (emlrtCTX)sp, u, 0, 12, (const char_T *)"strategy")),
                       &thisId);
  thisId.fIdentifier = "Nlive";
  y->Nlive =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 13,
                                                      (const char_T *)"Nlive")),
                       &thisId);
  thisId.fIdentifier = "nmcmc";
  y->nmcmc =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 14,
                                                      (const char_T *)"nmcmc")),
                       &thisId);
  thisId.fIdentifier = "propScale";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 15,
                                                  (const char_T *)"propScale")),
                   &thisId, y->propScale);
  thisId.fIdentifier = "nsTolerance";
  y->nsTolerance = emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 16,
                                     (const char_T *)"nsTolerance")),
      &thisId);
  thisId.fIdentifier = "calcSld";
  y->calcSld =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b(
                           (emlrtCTX)sp, u, 0, 17, (const char_T *)"calcSld")),
                       &thisId);
  thisId.fIdentifier = "repeats";
  y->repeats =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b(
                           (emlrtCTX)sp, u, 0, 18, (const char_T *)"repeats")),
                       &thisId);
  thisId.fIdentifier = "nsimu";
  y->nsimu =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 19,
                                                      (const char_T *)"nsimu")),
                       &thisId);
  thisId.fIdentifier = "burnin";
  y->burnin =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b(
                           (emlrtCTX)sp, u, 0, 20, (const char_T *)"burnin")),
                       &thisId);
  thisId.fIdentifier = "checks";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 21,
                                                  (const char_T *)"checks")),
                   &thisId, &y->checks);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *controls,
                             const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(controls), &thisId, y);
  emlrtDestroyArray(&controls);
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *problemDef,
                             const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(problemDef), &thisId, y);
  emlrtDestroyArray(&problemDef);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[26]{"contrastBacks",
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
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b(
                       (emlrtCTX)sp, u, 0, 0, (const char_T *)"contrastBacks")),
                   &thisId, y->contrastBacks);
  thisId.fIdentifier = "contrastBacksType";
  emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                     (const char_T *)"contrastBacksType")),
      &thisId, y->contrastBacksType);
  thisId.fIdentifier = "TF";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                                  (const char_T *)"TF")),
                   &thisId, y->TF);
  thisId.fIdentifier = "resample";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 3,
                                                  (const char_T *)"resample")),
                   &thisId, y->resample);
  thisId.fIdentifier = "dataPresent";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b(
                       (emlrtCTX)sp, u, 0, 4, (const char_T *)"dataPresent")),
                   &thisId, y->dataPresent);
  thisId.fIdentifier = "numberOfContrasts";
  y->numberOfContrasts = emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 5,
                                     (const char_T *)"numberOfContrasts")),
      &thisId);
  thisId.fIdentifier = "geometry";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 6,
                                                  (const char_T *)"geometry")),
                   &thisId, y->geometry);
  thisId.fIdentifier = "contrastShifts";
  emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 7,
                                     (const char_T *)"contrastShifts")),
      &thisId, y->contrastShifts);
  thisId.fIdentifier = "contrastScales";
  emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 8,
                                     (const char_T *)"contrastScales")),
      &thisId, y->contrastScales);
  thisId.fIdentifier = "contrastNbas";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b(
                       (emlrtCTX)sp, u, 0, 9, (const char_T *)"contrastNbas")),
                   &thisId, y->contrastNbas);
  thisId.fIdentifier = "contrastNbss";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b(
                       (emlrtCTX)sp, u, 0, 10, (const char_T *)"contrastNbss")),
                   &thisId, y->contrastNbss);
  thisId.fIdentifier = "contrastRes";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b(
                       (emlrtCTX)sp, u, 0, 11, (const char_T *)"contrastRes")),
                   &thisId, y->contrastRes);
  thisId.fIdentifier = "backs";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 12,
                                                  (const char_T *)"backs")),
                   &thisId, y->backs);
  thisId.fIdentifier = "shifts";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 13,
                                                  (const char_T *)"shifts")),
                   &thisId, y->shifts);
  thisId.fIdentifier = "sf";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 14,
                                                  (const char_T *)"sf")),
                   &thisId, y->sf);
  thisId.fIdentifier = "nba";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 15,
                                                  (const char_T *)"nba")),
                   &thisId, y->nba);
  thisId.fIdentifier = "nbs";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 16,
                                                  (const char_T *)"nbs")),
                   &thisId, y->nbs);
  thisId.fIdentifier = "res";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 17,
                                                  (const char_T *)"res")),
                   &thisId, y->res);
  thisId.fIdentifier = "params";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 18,
                                                  (const char_T *)"params")),
                   &thisId, y->params);
  thisId.fIdentifier = "numberOfLayers";
  y->numberOfLayers = emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 19,
                                     (const char_T *)"numberOfLayers")),
      &thisId);
  thisId.fIdentifier = "modelType";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 20,
                                                  (const char_T *)"modelType")),
                   &thisId, y->modelType);
  thisId.fIdentifier = "contrastCustomFiles";
  emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 21,
                                     (const char_T *)"contrastCustomFiles")),
      &thisId, y->contrastCustomFiles);
  thisId.fIdentifier = "fitpars";
  b_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 22,
                                                    (const char_T *)"fitpars")),
                     &thisId, y->fitpars);
  thisId.fIdentifier = "otherpars";
  b_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 23, (const char_T *)"otherpars")),
                     &thisId, y->otherpars);
  thisId.fIdentifier = "fitconstr";
  b_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 24, (const char_T *)"fitconstr")),
                     &thisId, y->fitconstr);
  thisId.fIdentifier = "otherconstr";
  b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 25,
                                     (const char_T *)"otherconstr")),
      &thisId, y->otherconstr);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct1_T *y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[7]{"params", "backs", "scales", "shifts",
                                     "nba",    "nbs",   "res"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 7,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "params";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                                    (const char_T *)"params")),
                     &thisId, y->params);
  thisId.fIdentifier = "backs";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                                    (const char_T *)"backs")),
                     &thisId, y->backs);
  thisId.fIdentifier = "scales";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 2,
                                                    (const char_T *)"scales")),
                     &thisId, y->scales);
  thisId.fIdentifier = "shifts";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 3,
                                                    (const char_T *)"shifts")),
                     &thisId, y->shifts);
  thisId.fIdentifier = "nba";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 4,
                                                    (const char_T *)"nba")),
                     &thisId, y->nba);
  thisId.fIdentifier = "nbs";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 5,
                                                    (const char_T *)"nbs")),
                     &thisId, y->nbs);
  thisId.fIdentifier = "res";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 6,
                                                    (const char_T *)"res")),
                     &thisId, y->res);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *problemDef_limits,
                             const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(problemDef_limits), &thisId, y);
  emlrtDestroyArray(&problemDef_limits);
}

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *problemDef_cells,
                             const char_T *identifier, cell_6 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(problemDef_cells), &thisId, y);
  emlrtDestroyArray(&problemDef_cells);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, cell_6 *y)
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
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                   &thisId, y->f1);
  thisId.fIdentifier = "2";
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                   &thisId, y->f2);
  thisId.fIdentifier = "3";
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)),
                   &thisId, y->f3);
  thisId.fIdentifier = "4";
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 3)),
                   &thisId, y->f4);
  thisId.fIdentifier = "5";
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 4)),
                   &thisId, y->f5);
  thisId.fIdentifier = "6";
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 5)),
                   &thisId, y->f6);
  thisId.fIdentifier = "7";
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 6)),
                   &thisId, y->f7);
  thisId.fIdentifier = "8";
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 7)),
                   &thisId, y->f8);
  thisId.fIdentifier = "9";
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 8)),
                   &thisId, y->f9);
  thisId.fIdentifier = "10";
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 9)),
                   &thisId, y->f10);
  thisId.fIdentifier = "11";
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 10)),
                   &thisId, y->f11);
  thisId.fIdentifier = "12";
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 11)),
                   &thisId, y->f12);
  thisId.fIdentifier = "13";
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 12)),
                   &thisId, y->f13);
  thisId.fIdentifier = "14";
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 13)),
                   &thisId, y->f14);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             cell_wrap_4 y[3])
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
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                   &thisId, y[0].f1);
  sprintf(&str[0], "%d", 2);
  thisId.fIdentifier = &str[0];
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                   &thisId, y[1].f1);
  sprintf(&str[0], "%d", 3);
  thisId.fIdentifier = &str[0];
  emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 2)),
                   &thisId, y[2].f1);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[2])
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<char_T, 2U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<cell_wrap_1, 2U> &y)
{
  static const boolean_T bv[2]{false, true};
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  int32_T sizes[2];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0], &sizes[0]);
  y.set_size(sizes[0], sizes[1]);
  for (int32_T i{0}; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    c_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                       &thisId, y[i].f1);
  }
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<cell_wrap_5, 2U> &y)
{
  static const boolean_T bv[2]{false, true};
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  int32_T sizes[2];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0], &sizes[0]);
  y.set_size(sizes[0], sizes[1]);
  for (int32_T i{0}; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                     &thisId, y[i].f1);
  }
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<cell_wrap_4, 2U> &y)
{
  static const boolean_T bv[2]{false, true};
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  int32_T sizes[2];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0], &sizes[0]);
  y.set_size(sizes[0], sizes[1]);
  for (int32_T i{0}; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                     &thisId, y[i].f1);
  }
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<cell_wrap_2, 2U> &y)
{
  static const boolean_T bv[2]{false, true};
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  int32_T sizes[2];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0], &sizes[0]);
  y.set_size(sizes[0], sizes[1]);
  for (int32_T i{0}; i < sizes[1]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                     &thisId, y[i].f1);
  }
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<cell_wrap_3, 1U> &y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  int32_T n;
  int32_T sizes;
  char_T str[11];
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  n = -1;
  b = true;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 1U, &n, &b, &sizes);
  y.set_size(sizes);
  for (n = 0; n < sizes; n++) {
    sprintf(&str[0], "%d", n + 1);
    thisId.fIdentifier = &str[0];
    emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, n)),
                     &thisId, y[n].f1.data, iv);
    y[n].f1.size[0] = iv[0];
    y[n].f1.size[1] = iv[1];
  }
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             real_T y_data[], int32_T y_size[2])
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static const mxArray *emlrt_marshallOut(const coder::array<cell_wrap_8, 1U> &u)
{
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(
                      1, ((coder::array<cell_wrap_8, 1U> *)&u)->size()));
  for (int32_T i{0}; i < u.size(0); i++) {
    emlrtSetCell(y, i, b_emlrt_marshallOut(u[i].f1));
  }
  return y;
}

static const mxArray *emlrt_marshallOut(const cell_9 *u)
{
  const mxArray *y;
  int32_T iv[2];
  y = nullptr;
  iv[0] = 1;
  iv[1] = 6;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv[0]));
  emlrtSetCell(y, 0, emlrt_marshallOut(u->f1));
  emlrtSetCell(y, 1, emlrt_marshallOut(u->f2));
  emlrtSetCell(y, 2, emlrt_marshallOut(u->f3));
  emlrtSetCell(y, 3, emlrt_marshallOut(u->f4));
  emlrtSetCell(y, 4, emlrt_marshallOut(u->f5));
  emlrtSetCell(y, 5, b_emlrt_marshallOut(u->f6));
  return y;
}

static const mxArray *emlrt_marshallOut(const struct4_T *u)
{
  static const char_T *sv[9]{"ssubs",        "backgrounds",  "qshifts",
                             "scalefactors", "nbairs",       "nbsubs",
                             "resolutions",  "calculations", "allSubRough"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&sv[0]));
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ssubs",
                      emlrt_marshallOut(u->ssubs), 0);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"backgrounds",
                      emlrt_marshallOut(u->backgrounds), 1);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"qshifts",
                      emlrt_marshallOut(u->qshifts), 2);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"scalefactors",
                      emlrt_marshallOut(u->scalefactors), 3);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"nbairs",
                      emlrt_marshallOut(u->nbairs), 4);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"nbsubs",
                      emlrt_marshallOut(u->nbsubs), 5);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"resolutions",
                      emlrt_marshallOut(u->resolutions), 6);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"calculations",
                      emlrt_marshallOut(&u->calculations), 7);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"allSubRough",
                      emlrt_marshallOut(u->allSubRough), 8);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const struct5_T *u)
{
  static const char_T *sv[2]{"all_chis", "sum_chi"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv[0]));
  emlrtSetFieldR2017b(y, 0, (const char_T *)"all_chis",
                      emlrt_marshallOut(u->all_chis), 0);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"sum_chi",
                      emlrt_marshallOut(u->sum_chi), 1);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T b_i;
  int32_T i;
  y = nullptr;
  iv[0] = u.size(0);
  iv[1] = 2;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < u.size(0); b_i++) {
    pData[i] = u[b_i];
    i++;
  }
  for (b_i = 0; b_i < u.size(0); b_i++) {
    pData[i] = u[b_i + u.size(0)];
    i++;
  }
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<cell_wrap_7, 1U> &u)
{
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(
                      1, ((coder::array<cell_wrap_7, 1U> *)&u)->size()));
  for (int32_T i{0}; i < u.size(0); i++) {
    emlrtSetCell(y, i, emlrt_marshallOut(u[i].f1));
  }
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u)
{
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T i;
  y = nullptr;
  i = u.size(0);
  m = emlrtCreateNumericArray(1, &i, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < u.size(0); b_i++) {
    pData[i] = u[b_i];
    i++;
  }
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{-1, -1};
  int32_T iv[2];
  const boolean_T bv[2]{true, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret.set_size(iv[0], iv[1]);
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret[0], 8, false);
  emlrtDestroyArray(&src);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{-1, 5};
  int32_T iv[2];
  const boolean_T bv[2]{true, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret.set_size(iv[0], iv[1]);
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret[0], 8, false);
  emlrtDestroyArray(&src);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{-1, 2};
  int32_T iv[2];
  const boolean_T bv[2]{true, false};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret.set_size(iv[0], iv[1]);
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret[0], 8, false);
  emlrtDestroyArray(&src);
}

void reflectivity_calculation_api(const mxArray *const prhs[4], int32_T nlhs,
                                  const mxArray *plhs[2])
{
  cell_6 problemDef_cells;
  cell_9 result;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  struct0_T problemDef;
  struct1_T problemDef_limits;
  struct2_T controls;
  struct4_T problem;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "problemDef", &problemDef);
  emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "problemDef_cells",
                   &problemDef_cells);
  emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "problemDef_limits",
                   &problemDef_limits);
  emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "controls", &controls);
  // Invoke the target function
  reflectivity_calculation(&problemDef, &problemDef_cells, &problemDef_limits,
                           &controls, &problem, &result);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(&problem);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(&result);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void reflectivity_calculation_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
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

void reflectivity_calculation_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void reflectivity_calculation_terminate()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (_coder_reflectivity_calculation_api.cpp)
