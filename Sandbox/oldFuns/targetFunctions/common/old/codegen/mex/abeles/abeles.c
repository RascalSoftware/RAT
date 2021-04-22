/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * abeles.c
 *
 * Code generation for function 'abeles'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "abeles.h"
#include "_coder_abeles_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131482U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "abeles",                            /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

static emlrtRSInfo emlrtRSI = { 20,    /* lineNo */
  "abeles",                            /* fcnName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m"/* pathName */
};

emlrtRSInfo b_emlrtRSI = { 21,         /* lineNo */
  "abeles",                            /* fcnName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m"/* pathName */
};

emlrtRSInfo c_emlrtRSI = { 32,         /* lineNo */
  "abeles",                            /* fcnName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m"/* pathName */
};

emlrtRSInfo d_emlrtRSI = { 48,         /* lineNo */
  "abeles",                            /* fcnName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m"/* pathName */
};

emlrtRSInfo e_emlrtRSI = { 45,         /* lineNo */
  "mpower",                            /* fcnName */
  "/usr/local/MATLAB/R2019a/toolbox/eml/lib/matlab/ops/mpower.m"/* pathName */
};

emlrtRSInfo f_emlrtRSI = { 55,         /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2019a/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 3,   /* lineNo */
  7,                                   /* colNo */
  "abeles",                            /* fName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_abeles_api",                 /* fName */
  ""                                   /* pName */
};

static emlrtDCInfo emlrtDCI = { 3,     /* lineNo */
  13,                                  /* colNo */
  "abeles",                            /* fName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 3,   /* lineNo */
  13,                                  /* colNo */
  "abeles",                            /* fName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 10,  /* lineNo */
  17,                                  /* colNo */
  "abeles",                            /* fName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = { 10,/* lineNo */
  15,                                  /* colNo */
  "abeles",                            /* fName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  11,                                  /* colNo */
  "x",                                 /* aName */
  "abeles",                            /* fName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = { 26,/* lineNo */
  19,                                  /* colNo */
  "abeles",                            /* fName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 27,/* lineNo */
  18,                                  /* colNo */
  "abeles",                            /* fName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m"/* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  25,                                  /* colNo */
  "sld",                               /* aName */
  "abeles",                            /* fName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  23,                                  /* colNo */
  "sld",                               /* aName */
  "abeles",                            /* fName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  25,                                  /* colNo */
  "sld",                               /* aName */
  "abeles",                            /* fName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo f_emlrtRTEI = { 13,/* lineNo */
  9,                                   /* colNo */
  "asin",                              /* fName */
  "/usr/local/MATLAB/R2019a/toolbox/eml/lib/matlab/elfun/asin.m"/* pName */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  5,                                   /* colNo */
  "out",                               /* aName */
  "abeles",                            /* fName */
  "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m",/* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void b_sqrt(creal_T *x);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *sld, const
  char_T *identifier, emxArray_creal_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_creal_T *y);
static creal_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nbair,
  const char_T *identifier);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *x, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void emxEnsureCapacity_creal_T(const emlrtStack *sp, emxArray_creal_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
static void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
static void emxFree_creal_T(emxArray_creal_T **pEmxArray);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
static creal_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nrepeats,
  const char_T *identifier);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_creal_T *ret);
static creal_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void b_sqrt(creal_T *x)
{
  real_T xr;
  real_T xi;
  real_T yr;
  real_T absxr;
  xr = x->re;
  xi = x->im;
  if (xi == 0.0) {
    if (xr < 0.0) {
      yr = 0.0;
      xr = muDoubleScalarSqrt(-xr);
    } else {
      yr = muDoubleScalarSqrt(xr);
      xr = 0.0;
    }
  } else if (xr == 0.0) {
    if (xi < 0.0) {
      yr = muDoubleScalarSqrt(-xi / 2.0);
      xr = -yr;
    } else {
      yr = muDoubleScalarSqrt(xi / 2.0);
      xr = yr;
    }
  } else if (muDoubleScalarIsNaN(xr)) {
    yr = xr;
  } else if (muDoubleScalarIsNaN(xi)) {
    yr = xi;
    xr = xi;
  } else if (muDoubleScalarIsInf(xi)) {
    yr = muDoubleScalarAbs(xi);
    xr = xi;
  } else if (muDoubleScalarIsInf(xr)) {
    if (xr < 0.0) {
      yr = 0.0;
      xr = xi * -xr;
    } else {
      yr = xr;
      xr = 0.0;
    }
  } else {
    absxr = muDoubleScalarAbs(xr);
    yr = muDoubleScalarAbs(xi);
    if ((absxr > 4.4942328371557893E+307) || (yr > 4.4942328371557893E+307)) {
      absxr *= 0.5;
      yr = muDoubleScalarHypot(absxr, yr * 0.5);
      if (yr > absxr) {
        yr = muDoubleScalarSqrt(yr) * muDoubleScalarSqrt(1.0 + absxr / yr);
      } else {
        yr = muDoubleScalarSqrt(yr) * 1.4142135623730951;
      }
    } else {
      yr = muDoubleScalarSqrt((muDoubleScalarHypot(absxr, yr) + absxr) * 0.5);
    }

    if (xr > 0.0) {
      xr = 0.5 * (xi / yr);
    } else {
      if (xi < 0.0) {
        xr = -yr;
      } else {
        xr = yr;
      }

      yr = 0.5 * (xi / xr);
    }
  }

  x->re = yr;
  x->im = xr;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *sld, const
  char_T *identifier, emxArray_creal_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(sld), &thisId, y);
  emlrtDestroyArray(&sld);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_creal_T *y)
{
  j_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static creal_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nbair,
  const char_T *identifier)
{
  creal_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(nbair), &thisId);
  emlrtDestroyArray(&nbair);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *x, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(x), &thisId, y);
  emlrtDestroyArray(&x);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[1] = { 0 };

  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m0, &u->data[0]);
  emlrtSetDimensions((mxArray *)m0, u->size, 1);
  emlrtAssign(&y, m0);
  return y;
}

static void emxEnsureCapacity_creal_T(const emlrtStack *sp, emxArray_creal_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)newNumel, (uint32_T)
      emxArray->size[i], srcLocation, sp);
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

    newData = emlrtCallocMex((uint32_T)i, sizeof(creal_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, sp);
    }

    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(creal_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }

    emxArray->data = (creal_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)newNumel, (uint32_T)
      emxArray->size[i], srcLocation, sp);
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
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, sp);
    }

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

static void emxFree_creal_T(emxArray_creal_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_creal_T *)NULL) {
    if (((*pEmxArray)->data != (creal_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_creal_T *)NULL;
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

static void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxArray_creal_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_creal_T *)emlrtMallocMex(sizeof(emxArray_creal_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, sp);
  }

  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_creal_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (creal_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, sp);
  }

  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, sp);
  }

  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, sp);
  }

  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static creal_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  creal_T y;
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nrepeats,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(nrepeats), &thisId);
  emlrtDestroyArray(&nrepeats);
  return y;
}

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv0[2] = { false, true };

  int32_T iv1[2];
  int32_T i5;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv1);
  ret->allocatedSize = iv1[0] * iv1[1];
  i5 = ret->size[0] * ret->size[1];
  ret->size[0] = iv1[0];
  ret->size[1] = iv1[1];
  emxEnsureCapacity_real_T(sp, ret, i5, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_creal_T *ret)
{
  static const int32_T dims[2] = { -1, 3 };

  const boolean_T bv1[2] = { true, false };

  int32_T iv2[2];
  int32_T i6;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", true, 2U, dims, &bv1[0],
    iv2);
  i6 = ret->size[0] * ret->size[1];
  ret->size[0] = iv2[0];
  ret->size[1] = iv2[1];
  emxEnsureCapacity_creal_T(sp, ret, i6, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, true);
  emlrtDestroyArray(&src);
}

static creal_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  creal_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", true, 0U, &dims);
  emlrtImportArrayR2015b(sp, src, &ret, 8, true);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void abeles(const emlrtStack *sp, const emxArray_real_T *x, const
            emxArray_creal_T *sld, const creal_T nbair, const creal_T nbsub,
            real_T nrepeats, real_T ssub, real_T layers, real_T points,
            emxArray_real_T *out)
{
  real_T d0;
  creal_T snair;
  creal_T snsub;
  int32_T ub_loop;
  int32_T i0;
  int32_T loop;
  creal_T R;
  creal_T num;
  creal_T MI[4];
  creal_T beta;
  creal_T pimag;
  creal_T blast;
  creal_T psub;
  real_T theta;
  creal_T N[4];
  int32_T i1;
  int32_T i2;
  real_T a_tmp;
  real_T snsub_im_tmp;
  real_T snair_re_tmp;
  real_T snair_im_tmp;
  real_T snsub_re_tmp;
  real_T snsub_re;
  real_T snsub_im;
  int32_T reploop;
  int32_T nl;
  int32_T i3;
  int32_T i4;
  real_T ar;
  real_T num_re;
  creal_T b_MI[4];
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  jmp_buf b_emlrtJBEnviron;
  emlrtStack b_st;
  boolean_T emlrtHadParallelError = false;
  if (!(points >= 0.0)) {
    emlrtNonNegativeCheckR2012b(points, &emlrtDCI, sp);
  }

  d0 = (int32_T)muDoubleScalarFloor(points);
  if (points != d0) {
    emlrtIntegerCheckR2012b(points, &b_emlrtDCI, sp);
  }

  snair.re = 1.0 - nbair.re * 0.377451863036739;
  snair.im = 0.0 - nbair.im * 0.377451863036739;
  snsub.re = 1.0 - nbsub.re * 0.377451863036739;
  snsub.im = 0.0 - nbsub.im * 0.377451863036739;
  if (points != d0) {
    emlrtIntegerCheckR2012b(points, &c_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, points, mxDOUBLE_CLASS, (int32_T)
    points, &c_emlrtRTEI, sp);
  ub_loop = out->size[0];
  i0 = (int32_T)points;
  out->size[0] = i0;
  emxEnsureCapacity_real_T(sp, out, ub_loop, &emlrtRTEI);
  ub_loop = i0 - 1;
  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(R,num,MI,beta,pimag,blast,psub,theta,N,b_emlrtJBEnviron,b_st,i1,i2,a_tmp,snsub_im_tmp,snair_re_tmp,snair_im_tmp,snsub_re_tmp,snsub_re,snsub_im,reploop,nl,i3,i4,ar,num_re,b_MI) \
 firstprivate(st,emlrtHadParallelError)

  {
    if (setjmp(b_emlrtJBEnviron) == 0) {
      st.prev = sp;
      st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
      st.site = NULL;
      emlrtSetJmpBuf(&st, &b_emlrtJBEnviron);
      b_st.prev = &st;
      b_st.tls = st.tls;
    } else {
      emlrtHadParallelError = true;
    }

#pragma omp for nowait

    for (loop = 0; loop <= ub_loop; loop++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(b_emlrtJBEnviron) == 0) {
        i1 = x->size[1];
        i2 = 1 + loop;
        if ((i2 < 1) || (i2 > i1)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &emlrtBCI, &st);
        }

        MI[0].re = 1.0;
        MI[0].im = 0.0;
        MI[1].re = 0.0;
        MI[1].im = 0.0;
        MI[2].re = 0.0;
        MI[2].im = 0.0;
        MI[3].re = 1.0;
        MI[3].im = 0.0;
        b_st.site = &emlrtRSI;
        theta = x->data[loop] * 1.54 / 12.566370614359172;
        if ((theta < -1.0) || (theta > 1.0)) {
          emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
            "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
            3, 4, 4, "asin");
        }

        theta = muDoubleScalarAsin(theta);
        a_tmp = muDoubleScalarCos(theta);
        snsub_im_tmp = snsub.re * snsub.im;
        snair_re_tmp = snair.re * snair.re - snair.im * snair.im;
        snair_im_tmp = snair.re * snair.im;
        snair_im_tmp += snair_im_tmp;
        snsub_re_tmp = a_tmp * a_tmp;
        snsub_re = (snsub.re * snsub.re - snsub.im * snsub.im) - snair_re_tmp *
          snsub_re_tmp;
        snsub_im = (snsub_im_tmp + snsub_im_tmp) - snair_im_tmp * snsub_re_tmp;
        psub.re = snsub_re - snsub_im * 0.0;
        psub.im = snsub_re * 0.0 + snsub_im;
        b_sqrt(&psub);
        snsub_re_tmp = muDoubleScalarSin(theta);
        snsub_im = snsub_re_tmp * snair.re;
        snsub_im_tmp = snsub_re_tmp * snair.im;
        num.re = snsub_im - snsub_im_tmp * 0.0;
        num.im = snsub_im * 0.0 + snsub_im_tmp;
        blast.re = 0.0;
        blast.im = 0.0;
        i1 = (int32_T)nrepeats;
        emlrtForLoopVectorCheckR2012b(1.0, 1.0, nrepeats, mxDOUBLE_CLASS,
          (int32_T)nrepeats, &d_emlrtRTEI, &st);
        for (reploop = 0; reploop < i1; reploop++) {
          i2 = (int32_T)layers;
          emlrtForLoopVectorCheckR2012b(1.0, 1.0, layers, mxDOUBLE_CLASS,
            (int32_T)layers, &e_emlrtRTEI, &st);
          for (nl = 0; nl < i2; nl++) {
            i3 = sld->size[0];
            i4 = 1 + nl;
            if ((i4 < 1) || (i4 > i3)) {
              emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &b_emlrtBCI, &st);
            }

            i3 = sld->size[0];
            i4 = 1 + nl;
            if ((i4 < 1) || (i4 > i3)) {
              emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &c_emlrtBCI, &st);
            }

            i3 = sld->size[0];
            i4 = 1 + nl;
            if ((i4 < 1) || (i4 > i3)) {
              emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &d_emlrtBCI, &st);
            }

            R.re = 1.0 - sld->data[nl + sld->size[0]].re * 0.377451863036739;
            R.im = 0.0 - sld->data[nl + sld->size[0]].im * 0.377451863036739;
            snsub_im = R.re * R.re - R.im * R.im;
            snsub_im_tmp = R.re * R.im;
            snsub_re_tmp = a_tmp * a_tmp;
            R.re = snsub_im - snair_re_tmp * snsub_re_tmp;
            R.im = (snsub_im_tmp + snsub_im_tmp) - snair_im_tmp * snsub_re_tmp;
            pimag.re = R.re - R.im * 0.0;
            pimag.im = R.re * 0.0 + R.im;
            b_sqrt(&pimag);
            snsub_im = 4.0799904592075231 * sld->data[nl].re;
            snsub_im_tmp = 4.0799904592075231 * sld->data[nl].im;
            beta.re = snsub_im * pimag.re - snsub_im_tmp * pimag.im;
            beta.im = snsub_im * pimag.im + snsub_im_tmp * pimag.re;
            snsub_im = -78.956835208714864 * num.re;
            snsub_im_tmp = -78.956835208714864 * num.im;
            snsub_re_tmp = snsub_im * pimag.re - snsub_im_tmp * pimag.im;
            snsub_im_tmp = snsub_im * pimag.im + snsub_im_tmp * pimag.re;
            theta = sld->data[nl + (sld->size[0] << 1)].re * sld->data[nl +
              (sld->size[0] << 1)].re - sld->data[nl + (sld->size[0] << 1)].im *
              sld->data[nl + (sld->size[0] << 1)].im;
            snsub_re = sld->data[nl + (sld->size[0] << 1)].re * sld->data[nl +
              (sld->size[0] << 1)].im + sld->data[nl + (sld->size[0] << 1)].im *
              sld->data[nl + (sld->size[0] << 1)].re;
            snsub_im = snsub_re_tmp * theta - snsub_im_tmp * snsub_re;
            snsub_im_tmp = snsub_re_tmp * snsub_re + snsub_im_tmp * theta;
            if (snsub_im_tmp == 0.0) {
              R.re = snsub_im / 2.3716;
              R.im = 0.0;
            } else if (snsub_im == 0.0) {
              R.re = 0.0;
              R.im = snsub_im_tmp / 2.3716;
            } else {
              R.re = snsub_im / 2.3716;
              R.im = snsub_im_tmp / 2.3716;
            }

            if (R.im == 0.0) {
              snsub_im = R.re;
              R.re = muDoubleScalarExp(snsub_im);
              R.im = 0.0;
            } else if (muDoubleScalarIsInf(R.im) && muDoubleScalarIsInf(R.re) &&
                       (R.re < 0.0)) {
              R.re = 0.0;
              R.im = 0.0;
            } else {
              theta = muDoubleScalarExp(R.re / 2.0);
              snsub_re_tmp = R.im;
              snsub_im_tmp = R.im;
              R.re = theta * (theta * muDoubleScalarCos(snsub_re_tmp));
              R.im = theta * (theta * muDoubleScalarSin(snsub_im_tmp));
            }

            ar = num.re - pimag.re;
            theta = num.im - pimag.im;
            snsub_im = num.re + pimag.re;
            snsub_im_tmp = num.im + pimag.im;
            if (snsub_im_tmp == 0.0) {
              if (theta == 0.0) {
                num_re = ar / snsub_im;
                snsub_re = 0.0;
              } else if (ar == 0.0) {
                num_re = 0.0;
                snsub_re = theta / snsub_im;
              } else {
                num_re = ar / snsub_im;
                snsub_re = theta / snsub_im;
              }
            } else if (snsub_im == 0.0) {
              if (ar == 0.0) {
                num_re = theta / snsub_im_tmp;
                snsub_re = 0.0;
              } else if (theta == 0.0) {
                num_re = 0.0;
                snsub_re = -(ar / snsub_im_tmp);
              } else {
                num_re = theta / snsub_im_tmp;
                snsub_re = -(ar / snsub_im_tmp);
              }
            } else {
              snsub_re = muDoubleScalarAbs(snsub_im);
              snsub_re_tmp = muDoubleScalarAbs(snsub_im_tmp);
              if (snsub_re > snsub_re_tmp) {
                snsub_re_tmp = snsub_im_tmp / snsub_im;
                snsub_im += snsub_re_tmp * snsub_im_tmp;
                num_re = (ar + snsub_re_tmp * theta) / snsub_im;
                snsub_re = (theta - snsub_re_tmp * ar) / snsub_im;
              } else if (snsub_re_tmp == snsub_re) {
                if (snsub_im > 0.0) {
                  snsub_re_tmp = 0.5;
                } else {
                  snsub_re_tmp = -0.5;
                }

                if (snsub_im_tmp > 0.0) {
                  snsub_im = 0.5;
                } else {
                  snsub_im = -0.5;
                }

                num_re = (ar * snsub_re_tmp + theta * snsub_im) / snsub_re;
                snsub_re = (theta * snsub_re_tmp - ar * snsub_im) / snsub_re;
              } else {
                snsub_re_tmp = snsub_im / snsub_im_tmp;
                snsub_im = snsub_im_tmp + snsub_re_tmp * snsub_im;
                num_re = (snsub_re_tmp * ar + theta) / snsub_im;
                snsub_re = (snsub_re_tmp * theta - ar) / snsub_im;
              }
            }

            snsub_im = R.re;
            snsub_re_tmp = R.im;
            R.re = num_re * snsub_im - snsub_re * snsub_re_tmp;
            R.im = num_re * snsub_re_tmp + snsub_re * snsub_im;
            snsub_im = blast.re * 0.0 - blast.im;
            snsub_im_tmp = blast.re + blast.im * 0.0;
            if (snsub_im_tmp == 0.0) {
              N[0].re = muDoubleScalarExp(snsub_im);
              N[0].im = 0.0;
            } else if (muDoubleScalarIsInf(snsub_im_tmp) && muDoubleScalarIsInf
                       (snsub_im) && (snsub_im < 0.0)) {
              N[0].re = 0.0;
              N[0].im = 0.0;
            } else {
              theta = muDoubleScalarExp(snsub_im / 2.0);
              N[0].re = theta * (theta * muDoubleScalarCos(snsub_im_tmp));
              N[0].im = theta * (theta * muDoubleScalarSin(snsub_im_tmp));
            }

            num.re = -blast.re * 0.0 - (-blast.im);
            num.im = -blast.re + -blast.im * 0.0;
            if (num.im == 0.0) {
              num_re = num.re;
              num.re = muDoubleScalarExp(num_re);
              num.im = 0.0;
            } else if (muDoubleScalarIsInf(num.im) && muDoubleScalarIsInf(num.re)
                       && (num.re < 0.0)) {
              num.re = 0.0;
              num.im = 0.0;
            } else {
              theta = muDoubleScalarExp(num.re / 2.0);
              snsub_re = num.im;
              snsub_im = num.im;
              num.re = theta * (theta * muDoubleScalarCos(snsub_re));
              num.im = theta * (theta * muDoubleScalarSin(snsub_im));
            }

            N[1].re = R.re * num.re - R.im * num.im;
            N[1].im = R.re * num.im + R.im * num.re;
            num.re = -blast.re * 0.0 - (-blast.im);
            num.im = -blast.re + -blast.im * 0.0;
            if (num.im == 0.0) {
              N[3].re = muDoubleScalarExp(num.re);
              N[3].im = 0.0;
            } else if (muDoubleScalarIsInf(num.im) && muDoubleScalarIsInf(num.re)
                       && (num.re < 0.0)) {
              N[3].re = 0.0;
              N[3].im = 0.0;
            } else {
              theta = muDoubleScalarExp(num.re / 2.0);
              N[3].re = theta * (theta * muDoubleScalarCos(num.im));
              N[3].im = theta * (theta * muDoubleScalarSin(num.im));
            }

            snsub_im = blast.re * 0.0 - blast.im;
            snsub_im_tmp = blast.re + blast.im * 0.0;
            if (snsub_im_tmp == 0.0) {
              num.re = muDoubleScalarExp(snsub_im);
              num.im = 0.0;
            } else if (muDoubleScalarIsInf(snsub_im_tmp) && muDoubleScalarIsInf
                       (snsub_im) && (snsub_im < 0.0)) {
              num.re = 0.0;
              num.im = 0.0;
            } else {
              theta = muDoubleScalarExp(snsub_im / 2.0);
              num.re = theta * (theta * muDoubleScalarCos(snsub_im_tmp));
              num.im = theta * (theta * muDoubleScalarSin(snsub_im_tmp));
            }

            N[2].re = R.re * num.re - R.im * num.im;
            N[2].im = R.re * num.im + R.im * num.re;
            num = pimag;
            blast = beta;
            for (i3 = 0; i3 < 2; i3++) {
              b_MI[i3].re = (MI[i3].re * N[0].re - MI[i3].im * N[0].im) + (MI[i3
                + 2].re * N[1].re - MI[i3 + 2].im * N[1].im);
              b_MI[i3].im = (MI[i3].re * N[0].im + MI[i3].im * N[0].re) + (MI[i3
                + 2].re * N[1].im + MI[i3 + 2].im * N[1].re);
              b_MI[i3 + 2].re = (MI[i3].re * N[2].re - MI[i3].im * N[2].im) +
                (MI[i3 + 2].re * N[3].re - MI[i3 + 2].im * N[3].im);
              b_MI[i3 + 2].im = (MI[i3].re * N[2].im + MI[i3].im * N[2].re) +
                (MI[i3 + 2].re * N[3].im + MI[i3 + 2].im * N[3].re);
            }

            memcpy(&MI[0], &b_MI[0], sizeof(creal_T) << 2);
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(&st);
            }
          }

          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }

        snsub_im_tmp = -78.956835208714864 * num.re;
        snsub_re_tmp = -78.956835208714864 * num.im;
        snsub_im = ssub * ssub;
        ar = (snsub_im_tmp * psub.re - snsub_re_tmp * psub.im) * snsub_im;
        theta = (snsub_im_tmp * psub.im + snsub_re_tmp * psub.re) * snsub_im;
        if (theta == 0.0) {
          R.re = ar / 2.3716;
          R.im = 0.0;
        } else if (ar == 0.0) {
          R.re = 0.0;
          R.im = theta / 2.3716;
        } else {
          R.re = ar / 2.3716;
          R.im = theta / 2.3716;
        }

        if (R.im == 0.0) {
          snsub_im = R.re;
          R.re = muDoubleScalarExp(snsub_im);
          R.im = 0.0;
        } else if (muDoubleScalarIsInf(R.im) && muDoubleScalarIsInf(R.re) &&
                   (R.re < 0.0)) {
          R.re = 0.0;
          R.im = 0.0;
        } else {
          theta = muDoubleScalarExp(R.re / 2.0);
          snsub_re_tmp = R.im;
          snsub_im_tmp = R.im;
          R.re = theta * (theta * muDoubleScalarCos(snsub_re_tmp));
          R.im = theta * (theta * muDoubleScalarSin(snsub_im_tmp));
        }

        ar = num.re - psub.re;
        theta = num.im - psub.im;
        snsub_im = num.re + psub.re;
        snsub_im_tmp = num.im + psub.im;
        if (snsub_im_tmp == 0.0) {
          if (theta == 0.0) {
            num_re = ar / snsub_im;
            snsub_re = 0.0;
          } else if (ar == 0.0) {
            num_re = 0.0;
            snsub_re = theta / snsub_im;
          } else {
            num_re = ar / snsub_im;
            snsub_re = theta / snsub_im;
          }
        } else if (snsub_im == 0.0) {
          if (ar == 0.0) {
            num_re = theta / snsub_im_tmp;
            snsub_re = 0.0;
          } else if (theta == 0.0) {
            num_re = 0.0;
            snsub_re = -(ar / snsub_im_tmp);
          } else {
            num_re = theta / snsub_im_tmp;
            snsub_re = -(ar / snsub_im_tmp);
          }
        } else {
          snsub_re = muDoubleScalarAbs(snsub_im);
          snsub_re_tmp = muDoubleScalarAbs(snsub_im_tmp);
          if (snsub_re > snsub_re_tmp) {
            snsub_re_tmp = snsub_im_tmp / snsub_im;
            snsub_im += snsub_re_tmp * snsub_im_tmp;
            num_re = (ar + snsub_re_tmp * theta) / snsub_im;
            snsub_re = (theta - snsub_re_tmp * ar) / snsub_im;
          } else if (snsub_re_tmp == snsub_re) {
            if (snsub_im > 0.0) {
              snsub_re_tmp = 0.5;
            } else {
              snsub_re_tmp = -0.5;
            }

            if (snsub_im_tmp > 0.0) {
              snsub_im = 0.5;
            } else {
              snsub_im = -0.5;
            }

            num_re = (ar * snsub_re_tmp + theta * snsub_im) / snsub_re;
            snsub_re = (theta * snsub_re_tmp - ar * snsub_im) / snsub_re;
          } else {
            snsub_re_tmp = snsub_im / snsub_im_tmp;
            snsub_im = snsub_im_tmp + snsub_re_tmp * snsub_im;
            num_re = (snsub_re_tmp * ar + theta) / snsub_im;
            snsub_re = (snsub_re_tmp * theta - ar) / snsub_im;
          }
        }

        snsub_im = R.re;
        snsub_re_tmp = R.im;
        R.re = num_re * snsub_im - snsub_re * snsub_re_tmp;
        R.im = num_re * snsub_re_tmp + snsub_re * snsub_im;
        snsub_im_tmp = blast.re * 0.0 - blast.im;
        snsub_re_tmp = blast.re + blast.im * 0.0;
        if (snsub_re_tmp == 0.0) {
          N[0].re = muDoubleScalarExp(snsub_im_tmp);
          N[0].im = 0.0;
        } else if (muDoubleScalarIsInf(snsub_re_tmp) && muDoubleScalarIsInf
                   (snsub_im_tmp) && (snsub_im_tmp < 0.0)) {
          N[0].re = 0.0;
          N[0].im = 0.0;
        } else {
          theta = muDoubleScalarExp(snsub_im_tmp / 2.0);
          N[0].re = theta * (theta * muDoubleScalarCos(snsub_re_tmp));
          N[0].im = theta * (theta * muDoubleScalarSin(snsub_re_tmp));
        }

        num.re = -blast.re * 0.0 - (-blast.im);
        num.im = -blast.re + -blast.im * 0.0;
        if (num.im == 0.0) {
          num_re = num.re;
          num.re = muDoubleScalarExp(num_re);
          num.im = 0.0;
        } else if (muDoubleScalarIsInf(num.im) && muDoubleScalarIsInf(num.re) &&
                   (num.re < 0.0)) {
          num.re = 0.0;
          num.im = 0.0;
        } else {
          theta = muDoubleScalarExp(num.re / 2.0);
          snsub_re = num.im;
          snsub_im = num.im;
          num.re = theta * (theta * muDoubleScalarCos(snsub_re));
          num.im = theta * (theta * muDoubleScalarSin(snsub_im));
        }

        N[1].re = R.re * num.re - R.im * num.im;
        N[1].im = R.re * num.im + R.im * num.re;
        num.re = -blast.re * 0.0 - (-blast.im);
        num.im = -blast.re + -blast.im * 0.0;
        if (num.im == 0.0) {
          N[3].re = muDoubleScalarExp(num.re);
          N[3].im = 0.0;
        } else if (muDoubleScalarIsInf(num.im) && muDoubleScalarIsInf(num.re) &&
                   (num.re < 0.0)) {
          N[3].re = 0.0;
          N[3].im = 0.0;
        } else {
          theta = muDoubleScalarExp(num.re / 2.0);
          N[3].re = theta * (theta * muDoubleScalarCos(num.im));
          N[3].im = theta * (theta * muDoubleScalarSin(num.im));
        }

        if (snsub_re_tmp == 0.0) {
          num.re = muDoubleScalarExp(snsub_im_tmp);
          num.im = 0.0;
        } else if (muDoubleScalarIsInf(snsub_re_tmp) && muDoubleScalarIsInf
                   (snsub_im_tmp) && (snsub_im_tmp < 0.0)) {
          num.re = 0.0;
          num.im = 0.0;
        } else {
          theta = muDoubleScalarExp(snsub_im_tmp / 2.0);
          num.re = theta * (theta * muDoubleScalarCos(snsub_re_tmp));
          num.im = theta * (theta * muDoubleScalarSin(snsub_re_tmp));
        }

        N[2].re = R.re * num.re - R.im * num.im;
        N[2].im = R.re * num.im + R.im * num.re;
        for (i1 = 0; i1 < 2; i1++) {
          b_MI[i1].re = (MI[i1].re * N[0].re - MI[i1].im * N[0].im) + (MI[i1 + 2]
            .re * N[1].re - MI[i1 + 2].im * N[1].im);
          b_MI[i1].im = (MI[i1].re * N[0].im + MI[i1].im * N[0].re) + (MI[i1 + 2]
            .re * N[1].im + MI[i1 + 2].im * N[1].re);
          b_MI[i1 + 2].re = (MI[i1].re * N[2].re - MI[i1].im * N[2].im) + (MI[i1
            + 2].re * N[3].re - MI[i1 + 2].im * N[3].im);
          b_MI[i1 + 2].im = (MI[i1].re * N[2].im + MI[i1].im * N[2].re) + (MI[i1
            + 2].re * N[3].im + MI[i1 + 2].im * N[3].re);
        }

        memcpy(&MI[0], &b_MI[0], sizeof(creal_T) << 2);
        num.re = MI[1].re * MI[1].re - MI[1].im * -MI[1].im;
        num.im = MI[1].re * -MI[1].im + MI[1].im * MI[1].re;
        snsub_im = MI[0].re * MI[0].re - MI[0].im * -MI[0].im;
        snsub_im_tmp = MI[0].re * -MI[0].im + MI[0].im * MI[0].re;
        if (snsub_im_tmp == 0.0) {
          if (num.im == 0.0) {
            R.re = num.re / snsub_im;
            R.im = 0.0;
          } else if (num.re == 0.0) {
            R.re = 0.0;
            R.im = num.im / snsub_im;
          } else {
            R.re = num.re / snsub_im;
            R.im = num.im / snsub_im;
          }
        } else if (snsub_im == 0.0) {
          if (num.re == 0.0) {
            R.re = num.im / snsub_im_tmp;
            R.im = 0.0;
          } else if (num.im == 0.0) {
            R.re = 0.0;
            R.im = -(num.re / snsub_im_tmp);
          } else {
            R.re = num.im / snsub_im_tmp;
            R.im = -(num.re / snsub_im_tmp);
          }
        } else {
          snsub_re = muDoubleScalarAbs(snsub_im);
          snsub_re_tmp = muDoubleScalarAbs(snsub_im_tmp);
          if (snsub_re > snsub_re_tmp) {
            snsub_re_tmp = snsub_im_tmp / snsub_im;
            snsub_im += snsub_re_tmp * snsub_im_tmp;
            R.re = (num.re + snsub_re_tmp * num.im) / snsub_im;
            R.im = (num.im - snsub_re_tmp * num.re) / snsub_im;
          } else if (snsub_re_tmp == snsub_re) {
            if (snsub_im > 0.0) {
              snsub_re_tmp = 0.5;
            } else {
              snsub_re_tmp = -0.5;
            }

            if (snsub_im_tmp > 0.0) {
              snsub_im = 0.5;
            } else {
              snsub_im = -0.5;
            }

            R.re = (num.re * snsub_re_tmp + num.im * snsub_im) / snsub_re;
            R.im = (num.im * snsub_re_tmp - num.re * snsub_im) / snsub_re;
          } else {
            snsub_re_tmp = snsub_im / snsub_im_tmp;
            snsub_im = snsub_im_tmp + snsub_re_tmp * snsub_im;
            R.re = (snsub_re_tmp * num.re + num.im) / snsub_im;
            R.im = (snsub_re_tmp * num.im - num.re) / snsub_im;
          }
        }

        i1 = out->size[0];
        i2 = (int32_T)(1U + loop);
        if ((i2 < 1) || (i2 > i1)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &e_emlrtBCI, &st);
        }

        out->data[i2 - 1] = R.re * R.re - R.im * R.im;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      } else {
        emlrtHadParallelError = true;
      }
    }
  }

  emlrtPopJmpBuf(sp, &emlrtJBStack);
  emlrtExitParallelRegion(sp, omp_in_parallel());
}

void abeles_api(const mxArray * const prhs[8], int32_T nlhs, const mxArray *
                plhs[1])
{
  emxArray_real_T *x;
  emxArray_creal_T *sld;
  emxArray_real_T *out;
  creal_T nbair;
  creal_T nbsub;
  real_T nrepeats;
  real_T ssub;
  real_T layers;
  real_T points;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &x, 2, &b_emlrtRTEI, true);
  emxInit_creal_T(&st, &sld, 2, &b_emlrtRTEI, true);
  emxInit_real_T(&st, &out, 1, &b_emlrtRTEI, true);

  /* Marshall function inputs */
  x->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "x", x);
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "sld", sld);
  nbair = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "nbair");
  nbsub = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "nbsub");
  nrepeats = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "nrepeats");
  ssub = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "ssub");
  layers = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "layers");
  points = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "points");

  /* Invoke the target function */
  abeles(&st, x, sld, nbair, nbsub, nrepeats, ssub, layers, points, out);

  /* Marshall function outputs */
  out->canFreeData = false;
  plhs[0] = emlrt_marshallOut(out);
  emxFree_real_T(&out);
  emxFree_creal_T(&sld);
  emxFree_real_T(&x);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void abeles_atexit(void)
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
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void abeles_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void abeles_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 8);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("abeles"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(8.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/arwel/Desktop/Rascal2019/Sandbox/newAbeles/newAbeles/abeles.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737887.47159722226));
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.6.0.1072779 (R2019a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[43] = {
    "789ced5d5b8c2bc959f686ddb09b286040b0d964037b36081d083abedb339100df6fe3eb7866ec9993dd99b6ddb67ba62f9eeeb6c7332f38124279206279c913"
    "12fb801044422c4fac0021077888481e9755b4801409212484788894483c70b1dddd73a67a5d6bef74b93cddfe7fe99c9af6efaeaffcebafafaafebab99ecb15",
    "9f73b95c3f31fdf73bbf39fdefdbb32797eb332e4ddc7afa09172a66fd737a5a303d1bf282eb79e4bde774bcdfd79f5b92a8b223557be039912d0d84262b4f1f"
    "4446606fb3694b022732a27a70dd675d32ab48fc906dcf351d8e670f38812d48771eb2dcf44148df51dd3ecc54b3bf133db675511b082eb9a73c2b2e7ff7c1a5",
    "db67267f8cf9fdcfaf689f34c63e6e93fe69ea0d4f4f12580f235fb1bc27c92a17aad4f7ec334a8be1fd5edfaea7c688eda634f288ec55acc9f2ac72e72f669e"
    "3c119e95fb6d4cb93eb962b95fc494fb253d8d229f16f5c7ac9e7e564fa37a1ad2d3d7f4f437f4f4f5a851de334c7956b5f3274dcfaedbef691aa12f5dcddc8b",
    "165e5b1a3479969c1fc5b178a8fe69aed098bad240913dbc34751d4f31765088c53dfb331f623caa24f133276205dec3734d8fc0a83cd3f4487dc5a35968e643"
    "335966a755fdc89c1af2d2ad878ddffbfafbefc7e8e169b22d78234c7eabfaddcf61f0dc26bdef86edf90257ed812f156bd432ddeb705b384e3f2b476509ceb2",
    "72b830cfb4f2b76bfded63cab5aabf7dc2f46c88d10eb8914f23512d0dddf2fa1893ffaa76fb050cbedba46f49ede98fe7a69d0a5964f8279c121f70bc9a13a7"
    "dd0a56e65a1be3fd8945bc37b078a87e45bf517a8cccb63d736be9ff7f494f0cdb79ccb69bbb1445fefa07d7ff427b60f7f6e0ea247e787333ea45cafd412ae5",
    "4fb442fbcc4e1cda834db70767987291f5b738b17e3d6e1ce2d6359c32fdc93237b26bbf7ee5f1e1bdfc80e5a77f780c1bdd1d1f9e61ca45ce0fa2dffa950cf0"
    "b8dd79bcd4baa8e7e474ab93561b8196af1a8a1f17e319e0f1ade0f1719a188fbf80c173eb1a3d3c63dbf84c0c8b87eaefef07881b407cc621785679fc673178",
    "6e93fedabb2bf67289ab72961515317c186e9e64b22ee0f14dd75fbaf1195f544b9f407c46ff7c62110fe2336bc79bcbb6e0417c864cfeef60de5fd58e794cfe"
    "6e93de727bf0a8c3ab46e7d745d9efa2952829bf7b1983e736e94dedc06c769b9153dd8df1ff03f493d9bf0f91be6128fae3c0c90f8ebf037cff50f97ed5fe7f",
    "2c2876a4bc97ab798fc3958aafd08d8582bc0bf87e7beaf154c6c5e8b271c7aaf6fa8ce9d965fa9ea1e71451eba5aab3155c9b8bef58f58f1c160fd57fccfe40"
    "871bb1edbe34750f0f62a90dc4795c7f5a7fe51f81e7d78447ab5f9f095c5cd72ebb1c9f38485cec5fc6bb071787a924f0fcb6f23c0e8fdcfc6b879b0e6a7a76",
    "8ddb27b178a8de0aaf6b16d23c01f8dc1978b4faedc34b36d51fb694ddc65540922a4acd17383e713987cfdfc5bcbfaa1df731f9bb4d7a727cfea8c3c98adae1"
    "d0df71862927d9780d432c6efff3183cb7493f35c6e9d408a71d49e625a97f2a0d59b9c34b57a7add93e0aebfd79b3e0ca6308a9b8fdc9123c437fcf75379a1b",
    "7d84e53610c7f9eb7f7b01e2380fb53d58b57fafeca546a9e4cd4d253ff2078b7e6fa21af37953ce690fbe8f797f553b8e31f9bb4dfaf5d5eb471ffd85d31ecb"
    "f75999ae9f66888d079e373dbb6ebfa76966bddd59bae179054e6cb3a39ca82edd0fb76a39a24bca61e8ad8d139e0814fde2dd1f7e00e303bbb707b5eb3e2784",
    "2ef7eb3eaed90ee64eaa95a26fe8a078cfdb98f7b7b8de4ec5eb9838feb2f6a4d563e633e310c75f9c1a02711f3a7810c72793fff731ef433f7ff1ef5dcd4f73"
    "d4ce5398fe7081196dae1d78a0717f74dfd5dc46b4e3fee317befa3d88f3d89dff8f65265b1b3687cdc83e9b4c5d0ba1ddfa310bfc0ffc6ffa3e3aef4b97ff39",
    "11f87f19ff73226dfe9ffcd5cb2f01ffdb9dffbbcc71a41ca8972e23cd989a0831e5201bac3a68df2dccfb2e4e0d41fcef8c21c6eb1f377e6f15efe3aee779db"
    "225e148b87ea6d14ef8338fd1af1204e4f267f1bf2f90d2b4bca40407f072e9ebe96fdb89337a2f334fa26357eef0cf8d9b60fdb9eb3b0de7ebbd267e4ce40f4",
    "ccac443d6ef3e710b7b73fcfab61bfb09fac677a2701e966a8168574d1a73a88e7dfc1bc0ffb6aeffaddb37db55fc3e4b7aabd1e63f0dc26bd69fd0bd3eff3d7"
    "714e64e4ebdabcc54b0fc496ca4922a979e39f5c522e43dfd1714f7b8cd89e3604a4d66f3e5d826fe8adf617b086d4677629fa55b5fe1f10d7b17bfb906e28f1",
    "4635b357aa1d26b3859c2cef662ba283e23a13ccfb50af5141fd3042acbdf82206cf6dd29bdb8ba1c4b563b2cc5ca7794655599113bbf3ef6d6a7dbfd5f1e4d1"
    "123c436fd98f16188eee399baef18f9ad02ed8bd5db8c9670389c37e43a836cbed58a3932d8e8472d639ed82d5fa7c80c9df6dd25b1f376811a2d30e2f31eae9",
    "ed0882ee3eafafc0b93c16f19cbfcf1bcee559271e9ccb43267fabbc5fc5e4ef36e9adf3be28a925a6549673d3aadd35c24694fdef98d83cc0b2f39639456444"
    "977de70112583c546feddcfca98da88f07c730dfbb463c5abc7e191b9485e07523e8dd97fd83848fdd1d0a259773781dea2f2aa8bffd22b1731ae07c651c1eaa",
    "87f395ef8d37976dc183f395c9e40ffdfac5a921b87efd1893dfaa76fb3c06cf6dd22f8ce73ce9f092a459c0ae719d32160fd55b8deb7c49b398676eb1690b40"
    "b1ffff4d5807647ffe6ff6c29586c8abed9a24a4066236d04cc5f30e9ae7b5ebbde8b8766b557ffb34a6dcc6face06f2a971fff9eb7a6adc8f1bd3d33d3d35ee",
    "4337ee478feba9716f7a5a4fb3c4e6057ecaf4ec327dcfd0cf36b9092a27b08abea14dff7c53f3c256db8fe2123c437fff7ec7872c467bfcf02ffff55d183fd8"
    "bdfda8c4dbb5d1c9752fed2bdcf8f3bdc850ac26230e5a473ac1bcbfc17542cbebf1a396240892a86df05590dfd3c794772dfb06a295e83c1d9721cea47f3eb1",
    "880771a6b5e3cd655bf020ce44267fbb8e33ce30e522eb6f416afbc6186576da837de78bd77b4f33cbcf768dcd6cb481fb1ebe75f84b102fb23b8f27b2a324d3"
    "2d8d8414130fd4774bf1beaf9f77d0fa4fa8bfa8a0fef698583ffe550c9edba4ff503f3e29090c27a6645942d6bbe2c635b4f689d965be003120ddf982bffc4f",
    "58ff6f7bfee78b425bb890d9623f515777a441bb733ce01cd48f877abcb8fca8df2589f5e797dfdb353beb4061edda9fcf62f150bdb573200c2bd13cef27fae2"
    "afbd097c6e773ebfaae794347f7194f677e41a3f3c2fe7c59b6a02f87cabf87cfc6cbe16f6f56a02fb7a17a786c0be5e3a78b0af974cfe10d74105774fcb1893",
    "dfaa76fa1c06cf6dd22f5ef76944efedbb6ea7b404cfd0935af769f80c457ff9c37ffe2ec4f1edcef7cdd84d754fe814b287b9d849219108aa3b7d09d67d6e1d"
    "dfbf85c96f553bfd3206cf6dd22f3af70d3dd028275678a6c5eadf7f2871fd8945fcaf2cc137f444ce895a6850eaf7b9c3f96f6bc4a3d53e0c2a89c42892a8f7",
    "4b07213652ea058a85c88583e24213ccfb50af5141fdf05721eebf221ec4fd49e169b22d7810f72793ff04f33ef03b2aa81f3e715c1ce8befc0f71a0c5e58738"
    "101d3c880391c9dfaeebf271718fb5ecd3baddff1b22d6bfff310cbe5bd7b424745f9a553cdafdfb18160fd55b890f4e6db4897bd9619dfe1af168f17aff6074",
    "1e29ab9570a4cc1cd4ce0fe4cc754b74d03a4da8bfa8aceb5cb75730786e937e713fde6079fbcee71697e0197a52fd78c36728c673c2dff813e07bbbf3fd8e5c"
    "50986aab785c6f1e379af17838d8e9b2c0f75bc7f76f61f283f95c4d2616f1b7302e08f3b96bc483f95c32f94f30ef43bd46655df1fe87324ed854bc1fc609a4",
    "f134d9163c182790c91fe2fda82c8cf78f8d787f98dab93ccaa5acce52bbc6fb69ac079ed988fe7ae028c4fbd788478bd7839954a7e70de7cecba9404ead5445"
    "719848c2fead2da8bf337928eb760c96b76fbc9ff6ba1dc367e8f9cbe42ffef5df81ef1f2adfaf7a6fd7cea050f31e05ca31391748898dfc7e58dc0fbb80efb7",
    "8def21deaf09c4fb57fb3d10efdf2c1ec4fbc9e43fc1bc0ff51a15a78f133615ef877102693c4db6050fc60964f2ff36e6fd55edd8c1e4ef36e9c9d6e347b34b"
    "5b5a92d0e7d9d1a9a639d5387133f301c6bd5d2962f30170afbb26f6bb171aee755f271edceb4e267fe0fdc5bfebe3f17e2eaafd91a5c8fb9c38b32df0fe47f1",
    "fed446c0fb8ec2a315f7098d8a7cfa62d83ecf851ba37c5bf607c55a38ed1cde87fa8bcabaf67dc13d8b383c540ff72cde1b6f2edb8207f72c92c9dfa9fdfe33"
    "4cb989fae3a442ac9fffe3183cb7ae915966da168e88f1ffb2f5a5ad29c1ce5252fd8414160fd55be927e836a2ccf3934f7df625e079bbf3fc4de628efef2583",
    "0783aaefcacf5d170f43859e83781eea2f2aa8bf7df996c771f1a255edf4690c9edba49f356006a7cf6453bc6ef55e967d2c1eaa9ff945e5be8ed197b921a3b2"
    "9e3b46dbc0bafe3fabbf02f11cbbf33c5f2b75bdc7fb01df41e8e866d82ee7773a57a283e239509f17a786a0fef7daa6f7eb767889518bd3cf785dbfa976e01d",
    "8b78052c1eaab73a0e7c6630daebbd26df04feb73fff0f7702c1089bdf2b7792bbea4984d92f2438c141fbba9c1acfc1f5cbd7338f5b8bced3499558fbf0790c"
    "bedba45fbcbeb377dd97b4059e765ddf49ebde4fc3afe616a37aef67f477ffe9cbd03e3cd4f661d5753e7ea63ef2291de52852daed063297a37def75cbe59cf6",
    "01eaf1e2f2a37ef76a9494dfbd8cc1739bf40b793fd5b52ddfe7b178a8deaa9f1886a23f7e9cfce0f83b10f7b73bdfc7826247ca7bb99af7385ca9f80add5828"
    "c8bb80efb78bef5f23c6f7ab8e434d7c3f6af34cffda6fdffe7d0e8b87eaadfa896ea80d9c0b1b7dfa01f4ef1f2cdfaf5aef94962f70d8e83413bbecce412522",
    "9f1c0d770f1c14ffb7eb796d67987291f5b708b1f53acbee63312edcb2ebbafc18160fd55b3aefe3d975cd34791cce675b231e2d1e67986cfce4ea22cb1d1513"
    "033e1e1793914a29093ceefcfa3b9387721fcbedb58a9679de2cb8f21842aadf5e5c8267e889cdf7e83e43314e13857396edcff7de5036bc93b8aafbbdf1ab2b",
    "dedbe783c9ee0daccfdc3abe7f0b931f9ccfa6c9c422fe169ee304e7b3ad110fce672393ff04f33ed46b541ee67d2ce4c609f78d07c1386171f9619c40070fc6"
    "0964f2b76b7cff6b9872adea6fb873708cf59b8fef7e382e44b534a6a5aeb8fe9cd19fb3c4da852f60cae536e94ded82dce6865c9b3dedb17c9f9d2dc4b76bfc",
    "a8627a36e3197aabed026ab027023d1e1bbff7f5f7617c60f776a124307bfe8e57120f8f2bacbcb757a8d7db3907b50b76afc7b8b8c95ad6f7bb7c512d25373e"
    "80f37d7078a81ecef7b937de5cb6050fcef72193bfdddb85334cf9c8fa5d80583bf01a06cf6dd22f8813b1a37e4212fa8cca4d997953ed80d5fde3352c1eaa27",
    "b1ee1f3118f5f301a36ffefdcf00ffdb9dff7bedbe7cd2b849b5ba916421721d1830b12af0ffb6f17f8cd8faff9fc6e0b94d7a13ff4f7fbdf6b95dd78baee17c"
    "a8857e323514ed7bda5ffdef36f0bcdd79be1b39612bd5deb07d993b4f1cf4eba952bf2ea69cc3f313ccfbabdaf129267fb7494fa4fe3e9a9fe2c289dd8a3455",
    "24a7ccaf70d26aebe5c9fae13eecf3b58807fb7c49e369b22d78b0cf974cfe13ccfbc0ffa8a0e7373f3bdf07373fbdaafd1e9b9e5da6ef19fa45eb4ae39cc8c8"
    "a645534e594f4acbafb086a47f6f04ac275d231eadf142baa1c41bd5cc5ea97698cc1672b2bc9bad8819e7b41756cf896330f9bb4d7a32ed85d6fb4b635b0dda",
    "ed460dc60d16f160dc401a4f936dc183710399fc9dda0ee0facd6b594f143d8c6a7f1c523b5f82692af3d4aef305312c1eaab7b25f716aa30dec579c4ce07c89"
    "87cbfbabf6ff2f9bcd7627d86f960f2a35b92af93219be1074d0bc30d45f54d6752f00ac0bc5e1a17a58177a6fbcb96c0b1eac0b25933ff03f2aa8bf791fc8be",
    "61a3976fdffd61c52578869ed4be61c36728f6f77f0fcefdb73fdf9f8732d56ebb7a94db4d977cbb47cd6aa8dba938e8fc08e07b54707c6f751ef8750c9edba4"
    "5f7ebe90f6bd87320f6c755fc0e1127c43bf86f34768f7ff61fe778d78d4ce67cf9f576ed4c4def1a5df77c47547bb99d17edd41eb45a13e2f4e0d41fd2f44ac",
    "7df82206cf6dd29bdb87a1c4b563b2cc5ca7794655599113bbf3ef6d6a5c60d57f8e96e0197acbfeb3c07094cf1d1fffa809ed81dddb839b7c369038ec37846a"
    "b3dc8e353ad9e248283be8de48680f16a786a0fe47eefca087121fbaeffc00c48716971fe24374f0203e44267fbb9e2b87e39f55fded5398721beb7c2ac8a7f9",
    "e83c19e7b4d495d4d3b89e6675bdfe3cd69f5d093dd5df1b27a8ad1362475ae408d609e1e38e531b6d22ee08f7d0ac118f56bb70edad378adc55391f2e48dc55"
    "cebf133cbcf639689f00d45f54507f7bfd818c030c968779e255c70186cf501c07fcd6fffc2df0bdddf93ed7c9777cd982ba53677c9747ad929769647b70efd8",
    "d6f1fd5b98fce01e1a4d2616f1b7f0be0a98375e231edc434326ff09e67da8d7a83ccc7b68c88d13ee1b0f8271c2e2f2c338810e1e8c13c8e40ff57871f951bf"
    "7b4c2cce8fbbffc6ad6b3885133b2efbc6f913583c547fdf71e3f40fcfdc46d4cf031abffbc30f80cfedcee7a151914f5f0cdbe7b97063946fcbfea0580ba781",
    "cfd7c8e777eaafd457661f9d0a2a27b0caed21d12eda7eb747ac1fff390c9edba437f5e39b3ca33cd1aca0e9edda8f2f61f150bde5f67f66318f6631baeb3ec7"
    "cdbff91ec473eccefbf1f3da65ae2ac673c2499a511bd9fa79661477d0fc2ed4e3c5e5c7dd3f3fc6e44783f73991e7443dd06fd7795ebafea2598cb2bf845ffc",
    "ea7bc0fb6bc2a3c6fb4d26a6c44bc1ca90dfa98aaaba53bfb8bc04dedf32de7f16bf81733eef8707e77c92c6d3645bf0e09c4f32f9db9defdfc2946f55bfc3f1"
    "9eb1cedf8b7c6aacd337d6f3a7b5d4a5df1fbfe01ef90db50ffab840b5ed78606f099ea127351e50e9df13f97fbffdebd03e3cd4f661d5f140bf9b533aa15175",
    "e8df4d4d3d3192b84c1ff20edaff6bf7f6e10c533eb27e57201607fa0206cf6dd22fe27bb527b34a4fe2db2e72f1ffe74dcfcfcaa3695a3d4676ddc1b3ba5fbc"
    "8ac543f564fce5d6621b58371c7d9afa3b98ffb53bff17db47bbe5d2ce2093ceb74b9752b97298bc0938e83c20e0ffc5e547fdae4a8cffef792ef49cff070a7b",
    "2ab39dd9df1bebf7dbe59e78cd5fee588c7aff7ff207ed3f82febfddf9bfdf1c96fcbbfe1a5ff3358af1d6ae37d496920e380ffaff01773c61dd",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 116760U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (abeles.c) */
