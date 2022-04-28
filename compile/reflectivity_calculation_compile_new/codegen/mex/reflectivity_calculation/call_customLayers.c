/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * call_customLayers.c
 *
 * Code generation for function 'call_customLayers'
 *
 */

/* Include files */
#include "call_customLayers.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_mexutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo th_emlrtRSI = {
    52,                  /* lineNo */
    "call_customLayers", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m" /* pathName */
};

static emlrtMCInfo emlrtMCI = {
    44,                       /* lineNo */
    5,                        /* colNo */
    "callMatlabCustomLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callMatlabFunction/callMatlabCustomLayers.m" /* pName */
};

static emlrtMCInfo b_emlrtMCI = {
    51,                       /* lineNo */
    9,                        /* colNo */
    "callMatlabCustomLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callMatlabFunction/callMatlabCustomLayers.m" /* pName */
};

static emlrtBCInfo aq_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    59,                  /* lineNo */
    42,                  /* colNo */
    "output",            /* aName */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo bq_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    60,                  /* lineNo */
    42,                  /* colNo */
    "output",            /* aName */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo cq_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    63,                  /* lineNo */
    34,                  /* colNo */
    "output",            /* aName */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo dq_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    63,                  /* lineNo */
    36,                  /* colNo */
    "output",            /* aName */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo eq_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    64,                  /* lineNo */
    42,                  /* colNo */
    "output",            /* aName */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo fq_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    65,                  /* lineNo */
    39,                  /* colNo */
    "output",            /* aName */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo gq_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    65,                  /* lineNo */
    41,                  /* colNo */
    "output",            /* aName */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m", /* pName */
    0                                       /* checkKind */
};

static emlrtECInfo bb_emlrtECI = {
    -1,                  /* nDims */
    59,                  /* lineNo */
    13,                  /* colNo */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m" /* pName */
};

static emlrtECInfo cb_emlrtECI = {
    -1,                  /* nDims */
    60,                  /* lineNo */
    13,                  /* colNo */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m" /* pName */
};

static emlrtBCInfo hq_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    42,                       /* lineNo */
    14,                       /* colNo */
    "bulkOuts",               /* aName */
    "callMatlabCustomLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callMatlabFunction/callMatlabCustomLayers.m", /* pName */
    0                                              /* checkKind */
};

static emlrtDCInfo jc_emlrtDCI = {
    41,                       /* lineNo */
    5,                        /* colNo */
    "callMatlabCustomLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callMatlabFunction/callMatlabCustomLayers.m", /* pName */
    1                                              /* checkKind */
};

static emlrtBCInfo iq_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    64,                  /* lineNo */
    40,                  /* colNo */
    "output",            /* aName */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo jq_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    73,                  /* lineNo */
    30,                  /* colNo */
    "newOutLayers",      /* aName */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m", /* pName */
    0                                       /* checkKind */
};

static emlrtDCInfo kc_emlrtDCI = {
    52,                       /* lineNo */
    20,                       /* colNo */
    "callMatlabCustomLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callMatlabFunction/callMatlabCustomLayers.m", /* pName */
    1                                              /* checkKind */
};

static emlrtDCInfo lc_emlrtDCI = {
    52,                       /* lineNo */
    20,                       /* colNo */
    "callMatlabCustomLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callMatlabFunction/callMatlabCustomLayers.m", /* pName */
    4                                              /* checkKind */
};

static emlrtBCInfo vx_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    72,                  /* lineNo */
    37,                  /* colNo */
    "newSld",            /* aName */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m", /* pName */
    0                                       /* checkKind */
};

static emlrtRTEInfo qo_emlrtRTEI = {
    41,                       /* lineNo */
    5,                        /* colNo */
    "callMatlabCustomLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callMatlabFunction/callMatlabCustomLayers.m" /* pName */
};

static emlrtRTEInfo ro_emlrtRTEI = {
    58,                  /* lineNo */
    13,                  /* colNo */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m" /* pName */
};

static emlrtRTEInfo so_emlrtRTEI = {
    75,                  /* lineNo */
    13,                  /* colNo */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m" /* pName */
};

static emlrtRTEInfo to_emlrtRTEI = {
    12,                       /* lineNo */
    5,                        /* colNo */
    "callMatlabCustomLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callMatlabFunction/callMatlabCustomLayers.m" /* pName */
};

static emlrtRTEInfo ur_emlrtRTEI = {
    69,                  /* lineNo */
    21,                  /* colNo */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m" /* pName */
};

static emlrtRTEInfo vr_emlrtRTEI = {
    67,                  /* lineNo */
    21,                  /* colNo */
    "call_customLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callCustomLayers/call_customLayers.m" /* pName */
};

static emlrtRSInfo fj_emlrtRSI = {
    44,                       /* lineNo */
    "callMatlabCustomLayers", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callMatlabFunction/callMatlabCustomLayers.m" /* pathName */
};

static emlrtRSInfo gj_emlrtRSI = {
    51,                       /* lineNo */
    "callMatlabCustomLayers", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callMatlabFunction/callMatlabCustomLayers.m" /* pathName */
};

static emlrtRSInfo rj_emlrtRSI = {
    56,                       /* lineNo */
    "callMatlabCustomLayers", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callMatlabFunction/callMatlabCustomLayers.m" /* pathName */
};

static emlrtRSInfo sj_emlrtRSI = {
    57,                       /* lineNo */
    "callMatlabCustomLayers", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "callMatlabFunction/callMatlabCustomLayers.m" /* pathName */
};

/* Function Declarations */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tempRough,
                                 const char_T *identifier);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tempOut,
                               const char_T *identifier, emxArray_real_T *y);

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *a__output_of_size_,
                             const char_T *identifier, real_T y[2]);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void feval(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                  const mxArray *m2, const mxArray *m3, const mxArray *m4,
                  emlrtMCInfo *location, const mxArray **r, const mxArray **r1);

static const mxArray *size(const emlrtStack *sp, const mxArray *m1,
                           emlrtMCInfo *location);

/* Function Definitions */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tempRough,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(tempRough), &thisId);
  emlrtDestroyArray(&tempRough);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tempOut,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(tempOut), &thisId, y);
  emlrtDestroyArray(&tempOut);
}

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *a__output_of_size_,
                             const char_T *identifier, real_T y[2])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_size_), &thisId, y);
  emlrtDestroyArray(&a__output_of_size_);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  pb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void feval(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                  const mxArray *m2, const mxArray *m3, const mxArray *m4,
                  emlrtMCInfo *location, const mxArray **r, const mxArray **r1)
{
  const mxArray *pArrays[5];
  const mxArray *mv[2];
  pArrays[0] = m;
  pArrays[1] = m1;
  pArrays[2] = m2;
  pArrays[3] = m3;
  pArrays[4] = m4;
  emlrtAssign(r,
              emlrtCallMATLABR2012b((emlrtCTX)sp, 2, &mv[0], 5, &pArrays[0],
                                    (const char_T *)"feval", true, location));
  emlrtAssign(r1, mv[1]);
}

static const mxArray *size(const emlrtStack *sp, const mxArray *m1,
                           emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 1, &pArray,
                               (const char_T *)"size", true, location);
}

void b_call_customLayers(const emlrtStack *sp, const emxArray_real_T *params,
                         real_T contrast, const cell_wrap_6 thisCustomFile[3],
                         const emxArray_real_T *bulkIn, real_T bulkOut,
                         real_T nContrasts, emxArray_real_T *output,
                         real_T *sRough)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *bulkOuts;
  emxArray_real_T *newOutLayers;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *tempOut;
  const mxArray *tempRough;
  const mxArray *y;
  real_T n[2];
  const real_T *bulkIn_data;
  real_T d;
  real_T thisHydration;
  real_T *bulkOuts_data;
  real_T *newOutLayers_data;
  real_T *output_data;
  int32_T iv[2];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T loop_ub_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  bulkIn_data = bulkIn->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &bulkOuts, 1, &to_emlrtRTEI, true);
  /*  Call a custom layers function */
  /*  This function calls a custom model, which can be in Matlab, Python or */
  /*  Octave. The custom function is called 'custom layers', but the same */
  /*  routines are required for layers or XY, so the same function is used. */
  /*  For Matlab, the gererated C++ passes excecution back to the base Matlab */
  /*  workspace. For Octave, an embedded Octave interpreter is used. An */
  /*  embedded interpreter is also used for Python. */
  /*  TODO: Add the Octave and Python functionality. */
  /*  Split up the custom file array into name, language and path... */
  /*  Call the relevant routines depending on the language required */
  /*  */
  /*  (1) Note that in order to generate code for use outside Matlab, it is */
  /*  necessary to comment out the 'callMatlabCustomLayers' option as this  */
  /*  will throw an error. To create the source code uncomment the dummy output
   */
  /*  for 'output' and 'sRough'. To create the mexy file, comment out the */
  /*  dummy returns and uncomment 'callMatlabCustomLayers which executes the */
  /*  Matlab custom codes in the base matlab workspace using 'feval. */
  /*  This option (i.e. using 'feval') will eventually */
  /*  be replaced by a dedicated C++ class which will instantiate and call */
  /*  an external Matlab session (or the base workspace) using the 'Matlab
   * Engine  */
  /*  for C++' API...   */
  /*  https://uk.mathworks.com/help/matlab/calling-matlab-engine-from-cpp-programs.html
   */
  /*  */
  /*  (2) It is not possible to build the full Library from Coder when using the
   * Octave  */
  /*  interpreter, as there are name clashes between mex.h (Matlab) and 'oct.h'
   */
  /*  (Octave). To use Octave, comment out the Octave option, generate the code
   */
  /*  only using Matlab Coder, then manually include the Octave calling */
  /*  function, and the use external tools to build the dynamic library. */
  /*  */
  /*  (3) Embedding the Python interpreter has not yet been done */
  /*  switch lang */
  /*      case 'matlab' */
  /*  Send the calculation to the base Matlab workspace. This call must */
  /*  be commented out for source code generation or it throws and */
  /*  error, but required for mex generation.       */
  /*  Use the dummy values of 'outPut' and 'sRough' instead to keep the */
  /*  translator happy for source code generation. */
  /*  Use this line for mex generation: */
  st.site = &th_emlrtRSI;
  tempOut = NULL;
  tempRough = NULL;
  /*  Excecute a custom model function in the base Matlab workspace. */
  /*  This function uses feval to cause Matlab coder to pass excecution */
  /*  of the function named in 'fname' back to the base Matlab workspace, */
  /*  'feval' generates an automatic coder.extrinsic call. */
  /*  Use a coder.extrinsic call here, so Coder will  */
  /*  pass the excecution of the function back to the calling Matlab  */
  /*  session. There is no need to explicitly declare the extrinsic */
  /*  as Coder automatically does this when it encounters 'feval' */
  /*  https://uk.mathworks.com/help/simulink/ug/use-matlab-engine-to-execute-a-function-call-in-generated-code.html
   */
  /*  Ultimately, we will replace this with a C++ class calling a  */
  /*  separate Matlab engine so that Matlab custom model functions are  */
  /*  still usable when the generated code is used from Python. */
  /*  https://www.mathworks.com/help/matlab/calling-matlab-engine-from-cpp-programs.html
   */
  /*  Pre-define the outputs to keep the compiler happy */
  /*  Need to define the size of the outputs with coder preprocessor */
  /*  directives */
  /*  This maybe should be a 'coder.typeof' instead? */
  /*  Because it is feval, coder sends this call to */
  /*  the base Matlab workspace. The outputs of feval are mxArrays,  */
  /*  so we need to do some work afterwards casting these to doubles (below) */
  /*  For backwards compatability with Rascal1... */
  i = (int32_T)muDoubleScalarFloor(nContrasts);
  if (nContrasts != i) {
    emlrtIntegerCheckR2012b(nContrasts, &jc_emlrtDCI, &st);
  }
  loop_ub_tmp = (int32_T)nContrasts;
  i1 = bulkOuts->size[0];
  bulkOuts->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(&st, bulkOuts, i1, &qo_emlrtRTEI);
  bulkOuts_data = bulkOuts->data;
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(nContrasts, &jc_emlrtDCI, &st);
  }
  for (i = 0; i < loop_ub_tmp; i++) {
    bulkOuts_data[i] = 0.0;
  }
  if (((int32_T)contrast < 1) || ((int32_T)contrast > loop_ub_tmp)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)contrast, 1, (int32_T)nContrasts,
                                  &hq_emlrtBCI, &st);
  }
  bulkOuts_data[(int32_T)contrast - 1] = bulkOut;
  y = NULL;
  iv[0] = 1;
  iv[1] = thisCustomFile[0].f1->size[1];
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a(&st, thisCustomFile[0].f1->size[1], m,
                           &thisCustomFile[0].f1->data[0]);
  emlrtAssign(&y, m);
  b_y = NULL;
  m = emlrtCreateDoubleScalar(contrast);
  emlrtAssign(&b_y, m);
  b_st.site = &fj_emlrtRSI;
  feval(&b_st, y, emlrt_marshallOut(params), b_emlrt_marshallOut(bulkIn),
        b_emlrt_marshallOut(bulkOuts), b_y, &emlrtMCI, &tempOut, &tempRough);
  /*  Tell coder n is doubles by defining it (otherwise 'size(n)' seems to
   * return */
  /*  [mxArray mxArray] not [double double]!), fill n with the size of the
   * mxArray */
  /*  'tempOut', and use n to allocate the correct number of elements to
   * 'output' */
  /*  by filling output with zeros (i.e. output is an array of doubles) */
  b_st.site = &gj_emlrtRSI;
  emlrt_marshallIn(&b_st, size(&b_st, emlrtAlias(tempOut), &b_emlrtMCI),
                   "<output of size>", n);
  if (!(n[0] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(n[0], &lc_emlrtDCI, &st);
  }
  if (n[0] != (int32_T)muDoubleScalarFloor(n[0])) {
    emlrtIntegerCheckR2012b(n[0], &kc_emlrtDCI, &st);
  }
  if (!(n[1] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(n[1], &lc_emlrtDCI, &st);
  }
  if (n[1] != (int32_T)muDoubleScalarFloor(n[1])) {
    emlrtIntegerCheckR2012b(n[1], &kc_emlrtDCI, &st);
  }
  /*  Copy the mxArrays to our doubles arrays, which then makes coder cast */
  /*  the mxArrays to double. */
  b_st.site = &rj_emlrtRSI;
  *sRough = c_emlrt_marshallIn(&b_st, emlrtAlias(tempRough), "tempRough");
  b_st.site = &sj_emlrtRSI;
  e_emlrt_marshallIn(&b_st, emlrtAlias(tempOut), "tempOut", output);
  output_data = output->data;
  emlrtDestroyArray(&tempOut);
  emlrtDestroyArray(&tempRough);
  /*  Deal with possible 5 column outLayers (i.e. need to calculate the */
  /*  hydrated SLD manually) */
  if ((uint32_T)output->size[1] == 5U) {
    emxInit_real_T(sp, &newOutLayers, 2, &ro_emlrtRTEI, true);
    /*  we need to calculate the hydrated SLD */
    i = output->size[0];
    i1 = newOutLayers->size[0] * newOutLayers->size[1];
    newOutLayers->size[0] = output->size[0];
    newOutLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, newOutLayers, i1, &ro_emlrtRTEI);
    newOutLayers_data = newOutLayers->data;
    loop_ub_tmp = output->size[0] * 3;
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      newOutLayers_data[i1] = 0.0;
    }
    if (1 > output->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, output->size[1], &aq_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    loop_ub_tmp = output->size[0];
    emlrtSubAssignSizeCheckR2012b(&loop_ub_tmp, 1, &output->size[0], 1,
                                  &bb_emlrtECI, (emlrtCTX)sp);
    loop_ub_tmp = output->size[0];
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      newOutLayers_data[i1] = output_data[i1];
    }
    /*  Thickness' */
    if (3 > output->size[1]) {
      emlrtDynamicBoundsCheckR2012b(3, 1, output->size[1], &bq_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    emlrtSubAssignSizeCheckR2012b(&newOutLayers->size[0], 1, &output->size[0],
                                  1, &cb_emlrtECI, (emlrtCTX)sp);
    loop_ub_tmp = output->size[0];
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      newOutLayers_data[i1 + newOutLayers->size[0] * 2] =
          output_data[i1 + output->size[0] * 2];
    }
    for (b_i = 0; b_i < i; b_i++) {
      if (2 > output->size[1]) {
        emlrtDynamicBoundsCheckR2012b(2, 1, output->size[1], &dq_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (b_i + 1 > output->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, output->size[0], &cq_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (4 > output->size[1]) {
        emlrtDynamicBoundsCheckR2012b(4, 1, output->size[1], &eq_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (b_i + 1 > output->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, output->size[0], &iq_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      thisHydration = output_data[b_i + output->size[0] * 3] / 100.0;
      /*  Assume percent for backwards compatability */
      if (5 > output->size[1]) {
        emlrtDynamicBoundsCheckR2012b(5, 1, output->size[1], &gq_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (b_i + 1 > output->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, output->size[0], &fq_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (output_data[b_i + output->size[0] * 4] == 0.0) {
        /*  Bulk out */
        loop_ub_tmp = bulkIn->size[0];
        i1 = bulkOuts->size[0];
        bulkOuts->size[0] = bulkIn->size[0];
        emxEnsureCapacity_real_T(sp, bulkOuts, i1, &vr_emlrtRTEI);
        bulkOuts_data = bulkOuts->data;
        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          bulkOuts_data[i1] = bulkIn_data[i1];
        }
      } else {
        i1 = bulkOuts->size[0];
        bulkOuts->size[0] = 1;
        emxEnsureCapacity_real_T(sp, bulkOuts, i1, &ur_emlrtRTEI);
        bulkOuts_data = bulkOuts->data;
        bulkOuts_data[0] = bulkOut;
      }
      d = (1.0 - thisHydration) * output_data[b_i + output->size[0]];
      loop_ub_tmp = bulkOuts->size[0];
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        bulkOuts_data[i1] = thisHydration * bulkOuts_data[i1] + d;
      }
      if (1 > bulkOuts->size[0]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, bulkOuts->size[0], &vx_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (b_i + 1 > newOutLayers->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, newOutLayers->size[0],
                                      &jq_emlrtBCI, (emlrtCTX)sp);
      }
      newOutLayers_data[b_i + newOutLayers->size[0]] = bulkOuts_data[0];
      /*  Reassignment to keep codegen happy */
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    i = output->size[0] * output->size[1];
    output->size[0] = newOutLayers->size[0];
    output->size[1] = 3;
    emxEnsureCapacity_real_T(sp, output, i, &so_emlrtRTEI);
    output_data = output->data;
    loop_ub_tmp = newOutLayers->size[0] * 3;
    for (i = 0; i < loop_ub_tmp; i++) {
      output_data[i] = newOutLayers_data[i];
    }
    emxFree_real_T(sp, &newOutLayers);
  }
  emxFree_real_T(sp, &bulkOuts);
  /*  */
  /*  Use these dummy outputs for souce code generation: */
  /*          output = [10 1e-6 3 ; 50 2e-6 4; 100 1e-6 4]; */
  /*          sRough = 3; */
  /* case 'octave' */
  /*  Use the embedded Octave interpreter.  */
  /*  [output,layers] =
   * octaveCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut); */
  /*  */
  /* case 'python' */
  /*  This has not been implemented yet */
  /* [output,layers] =
   * pythonCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut); */
  /* end */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void call_customLayers(const emlrtStack *sp, const emxArray_real_T *params,
                       real_T contrast, const cell_wrap_6 thisCustomFile[3],
                       real_T bulkIn, real_T bulkOut, real_T nContrasts,
                       emxArray_real_T *output, real_T *sRough)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *bulkOuts;
  emxArray_real_T *newOutLayers;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *tempOut;
  const mxArray *tempRough;
  const mxArray *y;
  real_T n[2];
  real_T thisBulkHydr;
  real_T thisHydration;
  real_T *bulkOuts_data;
  real_T *newOutLayers_data;
  int32_T iv[2];
  int32_T i;
  int32_T i1;
  int32_T loop_ub_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &bulkOuts, 1, &to_emlrtRTEI, true);
  /*  Call a custom layers function */
  /*  This function calls a custom model, which can be in Matlab, Python or */
  /*  Octave. The custom function is called 'custom layers', but the same */
  /*  routines are required for layers or XY, so the same function is used. */
  /*  For Matlab, the gererated C++ passes excecution back to the base Matlab */
  /*  workspace. For Octave, an embedded Octave interpreter is used. An */
  /*  embedded interpreter is also used for Python. */
  /*  TODO: Add the Octave and Python functionality. */
  /*  Split up the custom file array into name, language and path... */
  /*  Call the relevant routines depending on the language required */
  /*  */
  /*  (1) Note that in order to generate code for use outside Matlab, it is */
  /*  necessary to comment out the 'callMatlabCustomLayers' option as this  */
  /*  will throw an error. To create the source code uncomment the dummy output
   */
  /*  for 'output' and 'sRough'. To create the mexy file, comment out the */
  /*  dummy returns and uncomment 'callMatlabCustomLayers which executes the */
  /*  Matlab custom codes in the base matlab workspace using 'feval. */
  /*  This option (i.e. using 'feval') will eventually */
  /*  be replaced by a dedicated C++ class which will instantiate and call */
  /*  an external Matlab session (or the base workspace) using the 'Matlab
   * Engine  */
  /*  for C++' API...   */
  /*  https://uk.mathworks.com/help/matlab/calling-matlab-engine-from-cpp-programs.html
   */
  /*  */
  /*  (2) It is not possible to build the full Library from Coder when using the
   * Octave  */
  /*  interpreter, as there are name clashes between mex.h (Matlab) and 'oct.h'
   */
  /*  (Octave). To use Octave, comment out the Octave option, generate the code
   */
  /*  only using Matlab Coder, then manually include the Octave calling */
  /*  function, and the use external tools to build the dynamic library. */
  /*  */
  /*  (3) Embedding the Python interpreter has not yet been done */
  /*  switch lang */
  /*      case 'matlab' */
  /*  Send the calculation to the base Matlab workspace. This call must */
  /*  be commented out for source code generation or it throws and */
  /*  error, but required for mex generation.       */
  /*  Use the dummy values of 'outPut' and 'sRough' instead to keep the */
  /*  translator happy for source code generation. */
  /*  Use this line for mex generation: */
  st.site = &th_emlrtRSI;
  tempOut = NULL;
  tempRough = NULL;
  /*  Excecute a custom model function in the base Matlab workspace. */
  /*  This function uses feval to cause Matlab coder to pass excecution */
  /*  of the function named in 'fname' back to the base Matlab workspace, */
  /*  'feval' generates an automatic coder.extrinsic call. */
  /*  Use a coder.extrinsic call here, so Coder will  */
  /*  pass the excecution of the function back to the calling Matlab  */
  /*  session. There is no need to explicitly declare the extrinsic */
  /*  as Coder automatically does this when it encounters 'feval' */
  /*  https://uk.mathworks.com/help/simulink/ug/use-matlab-engine-to-execute-a-function-call-in-generated-code.html
   */
  /*  Ultimately, we will replace this with a C++ class calling a  */
  /*  separate Matlab engine so that Matlab custom model functions are  */
  /*  still usable when the generated code is used from Python. */
  /*  https://www.mathworks.com/help/matlab/calling-matlab-engine-from-cpp-programs.html
   */
  /*  Pre-define the outputs to keep the compiler happy */
  /*  Need to define the size of the outputs with coder preprocessor */
  /*  directives */
  /*  This maybe should be a 'coder.typeof' instead? */
  /*  Because it is feval, coder sends this call to */
  /*  the base Matlab workspace. The outputs of feval are mxArrays,  */
  /*  so we need to do some work afterwards casting these to doubles (below) */
  /*  For backwards compatability with Rascal1... */
  i = (int32_T)muDoubleScalarFloor(nContrasts);
  if (nContrasts != i) {
    emlrtIntegerCheckR2012b(nContrasts, &jc_emlrtDCI, &st);
  }
  loop_ub_tmp = (int32_T)nContrasts;
  i1 = bulkOuts->size[0];
  bulkOuts->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(&st, bulkOuts, i1, &qo_emlrtRTEI);
  bulkOuts_data = bulkOuts->data;
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(nContrasts, &jc_emlrtDCI, &st);
  }
  for (i = 0; i < loop_ub_tmp; i++) {
    bulkOuts_data[i] = 0.0;
  }
  if (((int32_T)contrast < 1) || ((int32_T)contrast > loop_ub_tmp)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)contrast, 1, (int32_T)nContrasts,
                                  &hq_emlrtBCI, &st);
  }
  bulkOuts_data[(int32_T)contrast - 1] = bulkOut;
  y = NULL;
  iv[0] = 1;
  iv[1] = thisCustomFile[0].f1->size[1];
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a(&st, thisCustomFile[0].f1->size[1], m,
                           &thisCustomFile[0].f1->data[0]);
  emlrtAssign(&y, m);
  b_y = NULL;
  m = emlrtCreateDoubleScalar(bulkIn);
  emlrtAssign(&b_y, m);
  c_y = NULL;
  m = emlrtCreateDoubleScalar(contrast);
  emlrtAssign(&c_y, m);
  b_st.site = &fj_emlrtRSI;
  feval(&b_st, y, emlrt_marshallOut(params), b_y, b_emlrt_marshallOut(bulkOuts),
        c_y, &emlrtMCI, &tempOut, &tempRough);
  /*  Tell coder n is doubles by defining it (otherwise 'size(n)' seems to
   * return */
  /*  [mxArray mxArray] not [double double]!), fill n with the size of the
   * mxArray */
  /*  'tempOut', and use n to allocate the correct number of elements to
   * 'output' */
  /*  by filling output with zeros (i.e. output is an array of doubles) */
  b_st.site = &gj_emlrtRSI;
  emlrt_marshallIn(&b_st, size(&b_st, emlrtAlias(tempOut), &b_emlrtMCI),
                   "<output of size>", n);
  emxFree_real_T(&st, &bulkOuts);
  if (!(n[0] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(n[0], &lc_emlrtDCI, &st);
  }
  if (n[0] != (int32_T)muDoubleScalarFloor(n[0])) {
    emlrtIntegerCheckR2012b(n[0], &kc_emlrtDCI, &st);
  }
  if (!(n[1] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(n[1], &lc_emlrtDCI, &st);
  }
  if (n[1] != (int32_T)muDoubleScalarFloor(n[1])) {
    emlrtIntegerCheckR2012b(n[1], &kc_emlrtDCI, &st);
  }
  /*  Copy the mxArrays to our doubles arrays, which then makes coder cast */
  /*  the mxArrays to double. */
  b_st.site = &rj_emlrtRSI;
  *sRough = c_emlrt_marshallIn(&b_st, emlrtAlias(tempRough), "tempRough");
  b_st.site = &sj_emlrtRSI;
  e_emlrt_marshallIn(&b_st, emlrtAlias(tempOut), "tempOut", output);
  bulkOuts_data = output->data;
  emlrtDestroyArray(&tempOut);
  emlrtDestroyArray(&tempRough);
  /*  Deal with possible 5 column outLayers (i.e. need to calculate the */
  /*  hydrated SLD manually) */
  if ((uint32_T)output->size[1] == 5U) {
    emxInit_real_T(sp, &newOutLayers, 2, &ro_emlrtRTEI, true);
    /*  we need to calculate the hydrated SLD */
    i = output->size[0];
    i1 = newOutLayers->size[0] * newOutLayers->size[1];
    newOutLayers->size[0] = output->size[0];
    newOutLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, newOutLayers, i1, &ro_emlrtRTEI);
    newOutLayers_data = newOutLayers->data;
    loop_ub_tmp = output->size[0] * 3;
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      newOutLayers_data[i1] = 0.0;
    }
    if (1 > output->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, output->size[1], &aq_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    loop_ub_tmp = output->size[0];
    emlrtSubAssignSizeCheckR2012b(&loop_ub_tmp, 1, &output->size[0], 1,
                                  &bb_emlrtECI, (emlrtCTX)sp);
    loop_ub_tmp = output->size[0];
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      newOutLayers_data[i1] = bulkOuts_data[i1];
    }
    /*  Thickness' */
    if (3 > output->size[1]) {
      emlrtDynamicBoundsCheckR2012b(3, 1, output->size[1], &bq_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    emlrtSubAssignSizeCheckR2012b(&newOutLayers->size[0], 1, &output->size[0],
                                  1, &cb_emlrtECI, (emlrtCTX)sp);
    loop_ub_tmp = output->size[0];
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      newOutLayers_data[i1 + newOutLayers->size[0] * 2] =
          bulkOuts_data[i1 + output->size[0] * 2];
    }
    for (loop_ub_tmp = 0; loop_ub_tmp < i; loop_ub_tmp++) {
      if (2 > output->size[1]) {
        emlrtDynamicBoundsCheckR2012b(2, 1, output->size[1], &dq_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (loop_ub_tmp + 1 > output->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub_tmp + 1, 1, output->size[0],
                                      &cq_emlrtBCI, (emlrtCTX)sp);
      }
      if (4 > output->size[1]) {
        emlrtDynamicBoundsCheckR2012b(4, 1, output->size[1], &eq_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (loop_ub_tmp + 1 > output->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub_tmp + 1, 1, output->size[0],
                                      &iq_emlrtBCI, (emlrtCTX)sp);
      }
      thisHydration = bulkOuts_data[loop_ub_tmp + output->size[0] * 3] / 100.0;
      /*  Assume percent for backwards compatability */
      if (5 > output->size[1]) {
        emlrtDynamicBoundsCheckR2012b(5, 1, output->size[1], &gq_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (loop_ub_tmp + 1 > output->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub_tmp + 1, 1, output->size[0],
                                      &fq_emlrtBCI, (emlrtCTX)sp);
      }
      if (bulkOuts_data[loop_ub_tmp + output->size[0] * 4] == 0.0) {
        /*  Bulk out */
        thisBulkHydr = bulkIn;
      } else {
        thisBulkHydr = bulkOut;
      }
      if (loop_ub_tmp + 1 > newOutLayers->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub_tmp + 1, 1, newOutLayers->size[0],
                                      &jq_emlrtBCI, (emlrtCTX)sp);
      }
      newOutLayers_data[loop_ub_tmp + newOutLayers->size[0]] =
          thisHydration * thisBulkHydr +
          (1.0 - thisHydration) * bulkOuts_data[loop_ub_tmp + output->size[0]];
      /*  Reassignment to keep codegen happy */
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    i = output->size[0] * output->size[1];
    output->size[0] = newOutLayers->size[0];
    output->size[1] = 3;
    emxEnsureCapacity_real_T(sp, output, i, &so_emlrtRTEI);
    bulkOuts_data = output->data;
    loop_ub_tmp = newOutLayers->size[0] * 3;
    for (i = 0; i < loop_ub_tmp; i++) {
      bulkOuts_data[i] = newOutLayers_data[i];
    }
    emxFree_real_T(sp, &newOutLayers);
  }
  /*  */
  /*  Use these dummy outputs for souce code generation: */
  /*          output = [10 1e-6 3 ; 50 2e-6 4; 100 1e-6 4]; */
  /*          sRough = 3; */
  /* case 'octave' */
  /*  Use the embedded Octave interpreter.  */
  /*  [output,layers] =
   * octaveCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut); */
  /*  */
  /* case 'python' */
  /*  This has not been implemented yet */
  /* [output,layers] =
   * pythonCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut); */
  /* end */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (call_customLayers.c) */
