//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sld_convolute.cpp
//
// Code generation for function 'sld_convolute'
//

// Include files
#include "sld_convolute.h"
#include "anyNonFinite.h"
#include "eml_int_forloop_overflow_check.h"
#include "interp1.h"
#include "linspace.h"
#include "rt_nonfinite.h"
#include "sld_convolute_data.h"
#include "sum.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    28,              // lineNo
    "sld_convolute", // fcnName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    29,              // lineNo
    "sld_convolute", // fcnName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    30,              // lineNo
    "sld_convolute", // fcnName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    38,              // lineNo
    "sld_convolute", // fcnName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    39,              // lineNo
    "sld_convolute", // fcnName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    40,              // lineNo
    "sld_convolute", // fcnName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    51,              // lineNo
    "sld_convolute", // fcnName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    53,              // lineNo
    "sld_convolute", // fcnName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    64,              // lineNo
    "sld_convolute", // fcnName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    65,              // lineNo
    "sld_convolute", // fcnName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    70,              // lineNo
    "sld_convolute", // fcnName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pathName
};

static emlrtRSInfo l_emlrtRSI{
    94,              // lineNo
    "sld_convolute", // fcnName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pathName
};

static emlrtRSInfo x_emlrtRSI{
    22,    // lineNo
    "cat", // fcnName
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/cat.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    96,         // lineNo
    "cat_impl", // fcnName
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/cat.m" // pathName
};

static emlrtRSInfo ob_emlrtRSI{
    59,     // lineNo
    "conv", // fcnName
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/conv.m" // pathName
};

static emlrtRSInfo pb_emlrtRSI{
    50,     // lineNo
    "conv", // fcnName
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/conv.m" // pathName
};

static emlrtRSInfo qb_emlrtRSI{
    45,     // lineNo
    "conv", // fcnName
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/conv.m" // pathName
};

static emlrtRSInfo rb_emlrtRSI{
    44,     // lineNo
    "conv", // fcnName
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/conv.m" // pathName
};

static emlrtRSInfo vb_emlrtRSI{
    138,        // lineNo
    "convSame", // fcnName
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/conv.m" // pathName
};

static emlrtRSInfo wb_emlrtRSI{
    144,        // lineNo
    "convSame", // fcnName
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/conv.m" // pathName
};

static emlrtRSInfo xb_emlrtRSI{
    142,        // lineNo
    "convSame", // fcnName
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/conv.m" // pathName
};

static emlrtRSInfo yb_emlrtRSI{
    148,        // lineNo
    "convSame", // fcnName
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/datafun/conv.m" // pathName
};

static emlrtRTEInfo emlrtRTEI{
    271,                   // lineNo
    27,                    // colNo
    "check_non_axis_size", // fName
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/cat.m" // pName
};

static emlrtBCInfo
    emlrtBCI{
        -1,              // iFirst
        -1,              // iLast
        93,              // lineNo
        24,              // colNo
        "fConv",         // aName
        "sld_convolute", // fName
        "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
        "collaboration/Fits/first AA dppc original "
        "data/compile/sld_convolute.m", // pName
        0                               // checkKind
    };

static emlrtBCInfo
    b_emlrtBCI{
        -1,              // iFirst
        -1,              // iLast
        93,              // lineNo
        16,              // colNo
        "fConv",         // aName
        "sld_convolute", // fName
        "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
        "collaboration/Fits/first AA dppc original "
        "data/compile/sld_convolute.m", // pName
        0                               // checkKind
    };

static emlrtBCInfo
    c_emlrtBCI{
        -1,              // iFirst
        -1,              // iLast
        92,              // lineNo
        26,              // colNo
        "padNewX",       // aName
        "sld_convolute", // fName
        "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
        "collaboration/Fits/first AA dppc original "
        "data/compile/sld_convolute.m", // pName
        0                               // checkKind
    };

static emlrtBCInfo
    d_emlrtBCI{
        -1,              // iFirst
        -1,              // iLast
        92,              // lineNo
        18,              // colNo
        "padNewX",       // aName
        "sld_convolute", // fName
        "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
        "collaboration/Fits/first AA dppc original "
        "data/compile/sld_convolute.m", // pName
        0                               // checkKind
    };

static emlrtBCInfo
    e_emlrtBCI{
        -1,              // iFirst
        -1,              // iLast
        61,              // lineNo
        22,              // colNo
        "newSldY",       // aName
        "sld_convolute", // fName
        "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
        "collaboration/Fits/first AA dppc original "
        "data/compile/sld_convolute.m", // pName
        0                               // checkKind
    };

static emlrtDCInfo
    emlrtDCI{
        54,              // lineNo
        15,              // colNo
        "sld_convolute", // fName
        "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
        "collaboration/Fits/first AA dppc original "
        "data/compile/sld_convolute.m", // pName
        1                               // checkKind
    };

static emlrtBCInfo
    f_emlrtBCI{
        -1,              // iFirst
        -1,              // iLast
        52,              // lineNo
        37,              // colNo
        "newSldX",       // aName
        "sld_convolute", // fName
        "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
        "collaboration/Fits/first AA dppc original "
        "data/compile/sld_convolute.m", // pName
        0                               // checkKind
    };

static emlrtBCInfo
    g_emlrtBCI{
        -1,              // iFirst
        -1,              // iLast
        50,              // lineNo
        42,              // colNo
        "newSldX",       // aName
        "sld_convolute", // fName
        "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
        "collaboration/Fits/first AA dppc original "
        "data/compile/sld_convolute.m", // pName
        0                               // checkKind
    };

static emlrtBCInfo
    h_emlrtBCI{
        -1,              // iFirst
        -1,              // iLast
        46,              // lineNo
        32,              // colNo
        "newSldX",       // aName
        "sld_convolute", // fName
        "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
        "collaboration/Fits/first AA dppc original "
        "data/compile/sld_convolute.m", // pName
        0                               // checkKind
    };

static emlrtBCInfo
    i_emlrtBCI{
        -1,              // iFirst
        -1,              // iLast
        46,              // lineNo
        21,              // colNo
        "newSldX",       // aName
        "sld_convolute", // fName
        "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
        "collaboration/Fits/first AA dppc original "
        "data/compile/sld_convolute.m", // pName
        0                               // checkKind
    };

static emlrtBCInfo
    j_emlrtBCI{
        -1,              // iFirst
        -1,              // iLast
        45,              // lineNo
        18,              // colNo
        "newSldY",       // aName
        "sld_convolute", // fName
        "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
        "collaboration/Fits/first AA dppc original "
        "data/compile/sld_convolute.m", // pName
        0                               // checkKind
    };

static emlrtBCInfo
    k_emlrtBCI{
        -1,              // iFirst
        -1,              // iLast
        37,              // lineNo
        13,              // colNo
        "filt_y",        // aName
        "sld_convolute", // fName
        "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
        "collaboration/Fits/first AA dppc original "
        "data/compile/sld_convolute.m", // pName
        0                               // checkKind
    };

static emlrtBCInfo
    l_emlrtBCI{
        -1,              // iFirst
        -1,              // iLast
        36,              // lineNo
        13,              // colNo
        "filt_x",        // aName
        "sld_convolute", // fName
        "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
        "collaboration/Fits/first AA dppc original "
        "data/compile/sld_convolute.m", // pName
        0                               // checkKind
    };

static emlrtBCInfo
    m_emlrtBCI{
        -1,              // iFirst
        -1,              // iLast
        27,              // lineNo
        12,              // colNo
        "sld_x",         // aName
        "sld_convolute", // fName
        "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
        "collaboration/Fits/first AA dppc original "
        "data/compile/sld_convolute.m", // pName
        0                               // checkKind
    };

static emlrtBCInfo
    n_emlrtBCI{
        -1,              // iFirst
        -1,              // iLast
        26,              // lineNo
        12,              // colNo
        "sld_x",         // aName
        "sld_convolute", // fName
        "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
        "collaboration/Fits/first AA dppc original "
        "data/compile/sld_convolute.m", // pName
        0                               // checkKind
    };

static emlrtRTEInfo i_emlrtRTEI{
    23,              // lineNo
    9,               // colNo
    "sld_convolute", // fName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pName
};

static emlrtRTEInfo j_emlrtRTEI{
    24,              // lineNo
    9,               // colNo
    "sld_convolute", // fName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pName
};

static emlrtRTEInfo k_emlrtRTEI{
    33,              // lineNo
    10,              // colNo
    "sld_convolute", // fName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pName
};

static emlrtRTEInfo l_emlrtRTEI{
    34,              // lineNo
    10,              // colNo
    "sld_convolute", // fName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pName
};

static emlrtRTEInfo m_emlrtRTEI{
    57,              // lineNo
    1,               // colNo
    "sld_convolute", // fName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pName
};

static emlrtRTEInfo n_emlrtRTEI{
    62,              // lineNo
    1,               // colNo
    "sld_convolute", // fName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pName
};

static emlrtRTEInfo o_emlrtRTEI{
    66,              // lineNo
    1,               // colNo
    "sld_convolute", // fName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pName
};

static emlrtRTEInfo p_emlrtRTEI{
    67,              // lineNo
    1,               // colNo
    "sld_convolute", // fName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pName
};

static emlrtRTEInfo q_emlrtRTEI{
    70,              // lineNo
    1,               // colNo
    "sld_convolute", // fName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pName
};

static emlrtRTEInfo r_emlrtRTEI{
    75,              // lineNo
    1,               // colNo
    "sld_convolute", // fName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pName
};

static emlrtRTEInfo s_emlrtRTEI{
    92,              // lineNo
    1,               // colNo
    "sld_convolute", // fName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pName
};

static emlrtRTEInfo t_emlrtRTEI{
    94,              // lineNo
    1,               // colNo
    "sld_convolute", // fName
    "/Users/arwel/Documents/gwaith/MD_bilayers_work/ALC "
    "collaboration/Fits/first AA dppc original data/compile/sld_convolute.m" // pName
};

// Function Definitions
emlrtCTX emlrtGetRootTLSGlobal()
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

void sld_convolute(const emlrtStack *sp,
                   const coder::array<real_T, 2U> &b_signal,
                   const coder::array<real_T, 2U> &filter,
                   coder::array<real_T, 2U> &res)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  coder::array<real_T, 2U> newFiltX;
  coder::array<real_T, 2U> newFiltY;
  coder::array<real_T, 2U> newSldX;
  coder::array<real_T, 2U> newSldY;
  coder::array<real_T, 2U> padNewX;
  coder::array<real_T, 2U> padRightX;
  coder::array<real_T, 1U> c_signal;
  coder::array<real_T, 1U> d_signal;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T xStep;
  real_T yFactor;
  int32_T i;
  int32_T iA0;
  int32_T n;
  int32_T nBd2;
  uint32_T padLength;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &st;
  d_st.tls = st.tls;
  e_st.prev = &c_st;
  e_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  //  -----------------------------------------------------------------
  //  This function convolutes the signal (in our case the bilayer SLD or
  //  volume) with a filter (in our case a Gaussian). Broadly speaking, the
  //  procedure is to take the Fourier transform of both curves, multiply those
  //  together, and inverse fourier transform the result, although there are a
  //  number of numerical correction steps that are required first:
  //
  //    1. Interpolate both curves onto the same x 'grid'
  //    2. Ensure that both curves are zero at each end (called 'normalisation'
  //    here)
  //    3. Pad each curve with zeros at each end, the length of which is equal
  //    to the sum of the lengths of both curves.
  //    4. Do the convolution usign Matlab's 'conv' function.
  //    5. Undo the corrections done in steps 1 to 3 on the convoluted curve to
  //    get the final result.
  //  flag for debug plot if required
  // Interpolate signals onto uniform grid....
  // sld....
  if (1 > b_signal.size(0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, b_signal.size(0), &n_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (b_signal.size(0) < 1) {
    emlrtDynamicBoundsCheckR2012b(b_signal.size(0), 1, b_signal.size(0),
                                  &m_emlrtBCI, (emlrtCTX)sp);
  }
  st.site = &emlrtRSI;
  coder::linspace(&st, b_signal[0], b_signal[b_signal.size(0) - 1],
                  static_cast<real_T>(b_signal.size(0)), newSldX);
  iA0 = b_signal.size(0);
  c_signal.set_size(&i_emlrtRTEI, sp, b_signal.size(0));
  for (i = 0; i < iA0; i++) {
    c_signal[i] = b_signal[i];
  }
  iA0 = b_signal.size(0);
  d_signal.set_size(&j_emlrtRTEI, sp, b_signal.size(0));
  for (i = 0; i < iA0; i++) {
    d_signal[i] = b_signal[i + b_signal.size(0)];
  }
  st.site = &b_emlrtRSI;
  coder::interp1(&st, c_signal, d_signal, newSldX, newSldY);
  st.site = &c_emlrtRSI;
  b_st.site = &x_emlrtRSI;
  c_st.site = &y_emlrtRSI;
  if (newSldY.size(1) != newSldX.size(1)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  // also filter....
  if (1 > filter.size(0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, filter.size(0), &l_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (filter.size(0) < 1) {
    emlrtDynamicBoundsCheckR2012b(filter.size(0), 1, filter.size(0),
                                  &k_emlrtBCI, (emlrtCTX)sp);
  }
  st.site = &d_emlrtRSI;
  coder::linspace(&st, filter[0], filter[(filter.size(0) + filter.size(0)) - 1],
                  static_cast<real_T>(filter.size(0)), newFiltX);
  iA0 = filter.size(0);
  c_signal.set_size(&k_emlrtRTEI, sp, filter.size(0));
  for (i = 0; i < iA0; i++) {
    c_signal[i] = filter[i];
  }
  iA0 = filter.size(0);
  d_signal.set_size(&l_emlrtRTEI, sp, filter.size(0));
  for (i = 0; i < iA0; i++) {
    d_signal[i] = filter[i + filter.size(0)];
  }
  st.site = &e_emlrtRSI;
  coder::interp1(&st, c_signal, d_signal, newSldX, newFiltY);
  st.site = &f_emlrtRSI;
  b_st.site = &x_emlrtRSI;
  c_st.site = &y_emlrtRSI;
  if (newFiltY.size(1) != newFiltX.size(1)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  // Need to pad the edge of the signal with zeros. Do this by padding out
  // initially with the values at the edges, then 'normalise' the
  // water regions to zero buy subtraction...
  if (1 > newSldY.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, newSldY.size(1), &j_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (2 > newSldX.size(1)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, newSldX.size(1), &i_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (1 > newSldX.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, newSldX.size(1), &h_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  xStep = muDoubleScalarAbs(newSldX[1] - newSldX[0]);
  // Do the zero padding....
  if (filter.size(0) == 0) {
    i = 0;
  } else {
    i = filter.size(0);
    i = muIntScalarMax_sint32(i, 2);
  }
  padLength = static_cast<uint32_T>(i) + newSldX.size(1);
  if (1 > newSldX.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, newSldX.size(1), &g_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  st.site = &g_emlrtRSI;
  coder::linspace(&st, static_cast<real_T>(padLength) * -xStep + newSldX[0],
                  newSldX[0] - xStep, static_cast<real_T>(padLength), newFiltX);
  if (newSldX.size(1) < 1) {
    emlrtDynamicBoundsCheckR2012b(newSldX.size(1), 1, newSldX.size(1),
                                  &f_emlrtBCI, (emlrtCTX)sp);
  }
  st.site = &h_emlrtRSI;
  coder::linspace(&st, newSldX[newSldX.size(1) - 1] + xStep,
                  static_cast<real_T>(padLength) * xStep +
                      newSldX[newSldX.size(1) - 1],
                  static_cast<real_T>(padLength), padRightX);
  if (static_cast<real_T>(padLength) != static_cast<int32_T>(padLength)) {
    emlrtIntegerCheckR2012b(static_cast<real_T>(padLength), &emlrtDCI,
                            (emlrtCTX)sp);
  }
  // Make the 'spliced' data
  padNewX.set_size(&m_emlrtRTEI, sp, 1,
                   (newFiltX.size(1) + newSldX.size(1)) + padRightX.size(1));
  iA0 = newFiltX.size(1);
  for (i = 0; i < iA0; i++) {
    padNewX[i] = newFiltX[i];
  }
  iA0 = newSldX.size(1);
  for (i = 0; i < iA0; i++) {
    padNewX[i + newFiltX.size(1)] = newSldX[i];
  }
  iA0 = padRightX.size(1);
  for (i = 0; i < iA0; i++) {
    padNewX[(i + newFiltX.size(1)) + newSldX.size(1)] = padRightX[i];
  }
  // ....'normalise' to give zero edges...
  if (1 > newSldY.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, newSldY.size(1), &e_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  xStep = newSldY[0];
  newFiltX.set_size(&n_emlrtRTEI, sp, 1,
                    (static_cast<int32_T>(padLength) + newSldY.size(1)) +
                        static_cast<int32_T>(padLength));
  iA0 = static_cast<int32_T>(padLength);
  for (i = 0; i < iA0; i++) {
    newFiltX[i] = newSldY[0] - xStep;
  }
  iA0 = newSldY.size(1);
  for (i = 0; i < iA0; i++) {
    newFiltX[i + static_cast<int32_T>(padLength)] = newSldY[i] - xStep;
  }
  iA0 = static_cast<int32_T>(padLength);
  for (i = 0; i < iA0; i++) {
    newFiltX[(i + static_cast<int32_T>(padLength)) + newSldY.size(1)] =
        newSldY[0] - xStep;
  }
  st.site = &i_emlrtRSI;
  xStep = coder::sum(&st, newFiltY);
  st.site = &j_emlrtRSI;
  yFactor = coder::sum(&st, newFiltX);
  newFiltY.set_size(&o_emlrtRTEI, sp, 1, newFiltY.size(1));
  iA0 = newFiltY.size(1) - 1;
  for (i = 0; i <= iA0; i++) {
    newFiltY[i] = newFiltY[i] / xStep;
  }
  newFiltX.set_size(&p_emlrtRTEI, sp, 1, newFiltX.size(1));
  iA0 = newFiltX.size(1) - 1;
  for (i = 0; i <= iA0; i++) {
    newFiltX[i] = newFiltX[i] / yFactor;
  }
  // Then convolute...
  st.site = &k_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  d_st.site = &qb_emlrtRSI;
  if (coder::internal::anyNonFinite(&b_st, newFiltX) ||
      coder::internal::anyNonFinite(&d_st, newFiltY)) {
    int32_T nA;
    int32_T nB;
    b_st.site = &pb_emlrtRSI;
    nA = newFiltX.size(1);
    nB = newFiltY.size(1);
    padRightX.set_size(&q_emlrtRTEI, &b_st, 1, newFiltX.size(1));
    iA0 = newFiltX.size(1);
    for (i = 0; i < iA0; i++) {
      padRightX[i] = 0.0;
    }
    if ((newFiltX.size(1) > 0) && (newFiltY.size(1) > 0)) {
      int32_T b_k;
      int32_T k;
      nBd2 = (newFiltY.size(1) >> 1) + 1;
      c_st.site = &vb_emlrtRSI;
      for (k = 0; k <= nBd2 - 2; k++) {
        iA0 = nBd2 - k;
        i = nA - iA0;
        for (b_k = 0; b_k <= i; b_k++) {
          padRightX[b_k] =
              padRightX[b_k] + newFiltY[k] * newFiltX[(iA0 + b_k) - 1];
        }
      }
      c_st.site = &wb_emlrtRSI;
      if ((nBd2 <= newFiltY.size(1)) && (newFiltY.size(1) > 2147483646)) {
        e_st.site = &o_emlrtRSI;
        coder::check_forloop_overflow_error(&e_st);
      }
      for (k = nBd2; k <= nB; k++) {
        iA0 = k - nBd2;
        i = nA - iA0;
        for (b_k = 0; b_k < i; b_k++) {
          n = iA0 + b_k;
          padRightX[n] = padRightX[n] + newFiltY[k - 1] * newFiltX[b_k];
        }
      }
    }
  } else {
    int32_T nA;
    int32_T nB;
    b_st.site = &ob_emlrtRSI;
    nA = newFiltX.size(1) + 1;
    nB = newFiltY.size(1);
    padRightX.set_size(&q_emlrtRTEI, &b_st, 1, newFiltX.size(1));
    iA0 = newFiltX.size(1);
    for (i = 0; i < iA0; i++) {
      padRightX[i] = 0.0;
    }
    if ((newFiltX.size(1) > 0) && (newFiltY.size(1) > 0)) {
      int32_T k;
      nBd2 = (newFiltY.size(1) >> 1) + 1;
      c_st.site = &vb_emlrtRSI;
      for (k = 0; k <= nBd2 - 2; k++) {
        iA0 = nBd2 - k;
        n = nA - iA0;
        c_st.site = &xb_emlrtRSI;
        if (n >= 1) {
          n_t = (ptrdiff_t)n;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          daxpy(&n_t, &newFiltY[k], &newFiltX[iA0 - 1], &incx_t, &padRightX[0],
                &incy_t);
        }
      }
      c_st.site = &wb_emlrtRSI;
      if ((nBd2 <= newFiltY.size(1)) && (newFiltY.size(1) > 2147483646)) {
        e_st.site = &o_emlrtRSI;
        coder::check_forloop_overflow_error(&e_st);
      }
      for (k = nBd2; k <= nB; k++) {
        iA0 = k - nBd2;
        n = (nA - iA0) - 1;
        c_st.site = &yb_emlrtRSI;
        if (n >= 1) {
          n_t = (ptrdiff_t)n;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          daxpy(&n_t, &newFiltY[k - 1], &newFiltX[0], &incx_t, &padRightX[iA0],
                &incy_t);
        }
      }
    }
  }
  // Finally 'denormalise' to get the result....
  // padNewY = (padNewY.*yFactor) + yDivFactor;
  padRightX.set_size(&r_emlrtRTEI, sp, 1, padRightX.size(1));
  xStep = newSldY[0];
  iA0 = padRightX.size(1) - 1;
  for (i = 0; i <= iA0; i++) {
    padRightX[i] = padRightX[i] * yFactor + xStep;
  }
  // Trim back to original size
  xStep = static_cast<real_T>(padNewX.size(1)) -
          (static_cast<real_T>(padLength) - 1.0);
  if (padLength > xStep) {
    i = 0;
    nBd2 = 0;
  } else {
    if ((static_cast<int32_T>(padLength) < 1) ||
        (static_cast<int32_T>(padLength) > padNewX.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(padLength), 1,
                                    padNewX.size(1), &d_emlrtBCI, (emlrtCTX)sp);
    }
    i = static_cast<int32_T>(padLength) - 1;
    if ((static_cast<int32_T>(xStep) < 1) ||
        (static_cast<int32_T>(xStep) > padNewX.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(xStep), 1,
                                    padNewX.size(1), &c_emlrtBCI, (emlrtCTX)sp);
    }
    nBd2 = static_cast<int32_T>(xStep);
  }
  iA0 = nBd2 - i;
  newFiltX.set_size(&s_emlrtRTEI, sp, 1, iA0);
  for (nBd2 = 0; nBd2 < iA0; nBd2++) {
    newFiltX[nBd2] = padNewX[i + nBd2] - 2.0;
  }
  // Not sure where this offset comes from - bug with the padding somewhere..
  if (padLength > xStep) {
    i = -1;
    nBd2 = -1;
  } else {
    if ((static_cast<int32_T>(padLength) < 1) ||
        (static_cast<int32_T>(padLength) > padRightX.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(padLength), 1,
                                    padRightX.size(1), &b_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = static_cast<int32_T>(padLength) - 2;
    if ((static_cast<int32_T>(xStep) < 1) ||
        (static_cast<int32_T>(xStep) > padRightX.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(xStep), 1,
                                    padRightX.size(1), &emlrtBCI, (emlrtCTX)sp);
    }
    nBd2 = static_cast<int32_T>(xStep) - 1;
  }
  st.site = &l_emlrtRSI;
  b_st.site = &x_emlrtRSI;
  c_st.site = &y_emlrtRSI;
  iA0 = nBd2 - i;
  if (iA0 != newFiltX.size(1)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  res.set_size(&t_emlrtRTEI, &b_st, newFiltX.size(1), 2);
  n = newFiltX.size(1);
  for (nBd2 = 0; nBd2 < n; nBd2++) {
    res[nBd2] = newFiltX[nBd2];
  }
  for (nBd2 = 0; nBd2 < iA0; nBd2++) {
    res[nBd2 + res.size(0)] = padRightX[(i + nBd2) + 1];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (sld_convolute.cpp)
