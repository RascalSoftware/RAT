/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * callParaMatalbCustlay.c
 *
 * Code generation for function 'callParaMatalbCustlay'
 *
 */

/* Include files */
#include "callParaMatalbCustlay.h"
#include "callParaMatalbCustlay_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtMCInfo emlrtMCI =
    {
        22,                      /* lineNo */
        1,                       /* colNo */
        "callParaMatalbCustlay", /* fName */
        "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
        "callParaMatalbCustlay.m" /* pName */
};

static emlrtRSInfo emlrtRSI =
    {
        22,                      /* lineNo */
        "callParaMatalbCustlay", /* fcnName */
        "/Users/arwel/Documents/coding/RAT/dev/paraCustLay/"
        "callParaMatalbCustlay.m" /* pathName */
};

/* Function Declarations */
static const mxArray *emlrt_marshallOut(const real_T u[3]);

static void feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                  const mxArray *d, const mxArray *e, const mxArray *f,
                  const mxArray *g, const mxArray *h, const mxArray *i,
                  const mxArray *j, const mxArray *k, const mxArray *l,
                  const mxArray *m, const mxArray *n, const mxArray *o,
                  const mxArray *p, const mxArray *q, const mxArray *r,
                  emlrtMCInfo *location, const mxArray **s, const mxArray **t);

/* Function Definitions */
static const mxArray *emlrt_marshallOut(const real_T u[3])
{
  static const int32_T iv[2] = {1, 3};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u[0];
  pData[1] = u[1];
  pData[2] = u[2];
  emlrtAssign(&y, m);
  return y;
}

static void feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                  const mxArray *d, const mxArray *e, const mxArray *f,
                  const mxArray *g, const mxArray *h, const mxArray *i,
                  const mxArray *j, const mxArray *k, const mxArray *l,
                  const mxArray *m, const mxArray *n, const mxArray *o,
                  const mxArray *p, const mxArray *q, const mxArray *r,
                  emlrtMCInfo *location, const mxArray **s, const mxArray **t)
{
  const mxArray *pArrays[17];
  const mxArray *mv[2];
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  pArrays[4] = f;
  pArrays[5] = g;
  pArrays[6] = h;
  pArrays[7] = i;
  pArrays[8] = j;
  pArrays[9] = k;
  pArrays[10] = l;
  pArrays[11] = m;
  pArrays[12] = n;
  pArrays[13] = o;
  pArrays[14] = p;
  pArrays[15] = q;
  pArrays[16] = r;
  emlrtAssign(s,
              emlrtCallMATLABR2012b((emlrtCTX)sp, 2, &mv[0], 17, &pArrays[0],
                                    (const char_T *)"feval", true, location));
  emlrtAssign(t, mv[1]);
}

void callParaMatalbCustlay(const emlrtStack *sp, const struct0_T *problemDef,
                           const cell_8 *problemDef_cells,
                           const struct1_T *problemDef_limits,
                           const struct2_T *controls, const mxArray **outLayers,
                           const mxArray **allRoughs)
{
  static const int32_T iv[2] = {1, 22};
  static const int32_T iv2[2] = {1, 13};
  static const int32_T iv3[2] = {1, 6};
  static const int32_T iv4[2] = {1, 62};
  static const int32_T iv5[2] = {1, 8};
  static const char_T u[22] = {'l', 'o', 'o', 'p', 'M', 'a', 't', 'l',
                               'a', 'b', 'C', 'u', 's', 't', 'o', 'm',
                               'L', 'a', 'y', 'e', 'r', 's'};
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m;
  const mxArray *tempAllRoughs;
  const mxArray *tempOutLayers;
  const mxArray *y;
  real_T *pData;
  int32_T iv1[2];
  int32_T i;
  (void)problemDef_limits;
  (void)controls;
  st.prev = sp;
  st.tls = sp->tls;
  *allRoughs = NULL;
  *outLayers = NULL;
  tempOutLayers = NULL;
  tempAllRoughs = NULL;
  /*  Extract individual cell arrays */
  /*  Splits up the master input list of all arrays into separate arrays */
  /*  The min input array 'problemDef_cells' is a master array where */
  /*  all the cell arrays are grouped together. There are */
  /*  repeatLayers      - controls repeating of the layers stack */
  /*  allData           - Array of all the data arrays */
  /*  dataLimits        - Min max limits in q for the data arrays */
  /*  simLimits         - Limits in Q for the reflkectivity simulations */
  /*  Layers details    - Master array of all available layers */
  /*  contrastLayers    - Which specific combination of arrays are needed for */
  /*                      each contrast. */
  /*  Custom files      - Filenames and path for any custom files used */
  /*  Extract individual parameters from problemDef struct */
  /* Extract individual parameters from problemDef */
  /*  Call the loop custom.... */
  /*  We feval into the Matlab base workspace here, and allow the paralell
   * computing toolbox (if */
  /*  present) to loop over the function calls. */
  y = NULL;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 22, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = NULL;
  m = emlrtCreateDoubleScalar(problemDef->shifts);
  emlrtAssign(&b_y, m);
  c_y = NULL;
  m = emlrtCreateDoubleScalar(problemDef->sf);
  emlrtAssign(&c_y, m);
  d_y = NULL;
  m = emlrtCreateDoubleScalar(problemDef->nba);
  emlrtAssign(&d_y, m);
  e_y = NULL;
  m = emlrtCreateDoubleScalar(problemDef->res);
  emlrtAssign(&e_y, m);
  f_y = NULL;
  m = emlrtCreateDoubleScalar(problemDef->numberOfContrasts);
  emlrtAssign(&f_y, m);
  g_y = NULL;
  i = 1;
  emlrtAssign(&g_y, emlrtCreateCellArrayR2014a(1, &i));
  h_y = NULL;
  iv1[0] = 1;
  iv1[1] = 3;
  emlrtAssign(&h_y, emlrtCreateCellArrayR2014a(2, &iv1[0]));
  i_y = NULL;
  m = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 13, m,
                           &problemDef_cells->f14[0].f1[0]);
  emlrtAssign(&i_y, m);
  emlrtSetCell(h_y, 0, i_y);
  j_y = NULL;
  m = emlrtCreateCharArray(2, &iv3[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 6, m, &problemDef_cells->f14[0].f2[0]);
  emlrtAssign(&j_y, m);
  emlrtSetCell(h_y, 1, j_y);
  k_y = NULL;
  m = emlrtCreateCharArray(2, &iv4[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 62, m,
                           &problemDef_cells->f14[0].f3[0]);
  emlrtAssign(&k_y, m);
  emlrtSetCell(h_y, 2, k_y);
  emlrtSetCell(g_y, 0, h_y);
  l_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv5[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (i = 0; i < 8; i++) {
    pData[i] = problemDef->params[i];
  }
  emlrtAssign(&l_y, m);
  st.site = &emlrtRSI;
  feval(&st, y, emlrt_marshallOut(problemDef->contrastBacks),
        emlrt_marshallOut(problemDef->contrastShifts),
        emlrt_marshallOut(problemDef->contrastScales),
        emlrt_marshallOut(problemDef->contrastNbas),
        emlrt_marshallOut(problemDef->contrastNbss),
        emlrt_marshallOut(problemDef->contrastRes),
        emlrt_marshallOut(problemDef->backs), b_y, c_y, d_y,
        emlrt_marshallOut(problemDef->nbs), e_y,
        emlrt_marshallOut(problemDef->contrastCustomFiles), f_y, g_y, l_y,
        &emlrtMCI, &tempOutLayers, &tempAllRoughs);
  /*  May need some recasting here? */
  emlrtAssign(outLayers, emlrtAlias(tempOutLayers));
  emlrtAssign(allRoughs, emlrtAlias(tempAllRoughs));
  emlrtDestroyArray(&tempOutLayers);
  emlrtDestroyArray(&tempAllRoughs);
}

/* End of code generation (callParaMatalbCustlay.c) */
