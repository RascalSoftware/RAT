//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  repmat.cpp
//
//  Code generation for function 'repmat'
//


// Include files
#include "repmat.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo ae_emlrtRSI = { 28, // lineNo
  "repmat",                            // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/repmat.m"// pathName
};

static emlrtRSInfo be_emlrtRSI = { 69, // lineNo
  "repmat",                            // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/repmat.m"// pathName
};

static emlrtRTEInfo rb_emlrtRTEI = { 58,// lineNo
  23,                                  // colNo
  "assertValidSizeArg",                // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"// pName 
};

static emlrtRTEInfo fh_emlrtRTEI = { 1,// lineNo
  14,                                  // colNo
  "repmat",                            // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/repmat.m"// pName
};

// Function Definitions
void repmat(const emlrtStack *sp, const real_T a[2], real_T varargin_1, coder::
            array<real_T, 2U> &b)
{
  int32_T i;
  int32_T itilerow;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ae_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((varargin_1 != varargin_1) || muDoubleScalarIsInf(varargin_1)) {
    emlrtErrorWithMessageIdR2018a(&st, &rb_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  i = static_cast<int32_T>(varargin_1);
  b.set_size((&fh_emlrtRTEI), sp, i, 2);
  st.site = &be_emlrtRSI;
  if ((1 <= i) && (i > 2147483646)) {
    b_st.site = &nb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (itilerow = 0; itilerow < i; itilerow++) {
    b[itilerow] = a[0];
  }

  st.site = &be_emlrtRSI;
  for (itilerow = 0; itilerow < i; itilerow++) {
    b[i + itilerow] = a[1];
  }
}

// End of code generation (repmat.cpp)
