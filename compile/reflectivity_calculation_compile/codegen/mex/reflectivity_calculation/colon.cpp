//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  colon.cpp
//
//  Code generation for function 'colon'
//


// Include files
#include "colon.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRTEInfo ph_emlrtRTEI = { 279,// lineNo
  14,                                  // colNo
  "colon",                             // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"// pName
};

// Function Definitions
void eml_float_colon(const emlrtStack *sp, real_T a, real_T d, real_T b, coder::
                     array<real_T, 2U> &y)
{
  real_T ndbl;
  real_T apnd;
  real_T cdiff;
  int32_T n;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  ndbl = muDoubleScalarFloor((b - a) / d + 0.5);
  apnd = a + ndbl * d;
  if (d > 0.0) {
    cdiff = apnd - b;
  } else {
    cdiff = b - apnd;
  }

  if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarMax
      (muDoubleScalarAbs(a), muDoubleScalarAbs(b))) {
    ndbl++;
    apnd = b;
  } else if (cdiff > 0.0) {
    apnd = a + (ndbl - 1.0) * d;
  } else {
    ndbl++;
  }

  if (ndbl >= 0.0) {
    n = static_cast<int32_T>(ndbl);
  } else {
    n = 0;
  }

  st.site = &rf_emlrtRSI;
  if (ndbl > 2.147483647E+9) {
    emlrtErrorWithMessageIdR2018a(&st, &ub_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      "Coder:MATLAB:pmaxsize", 0);
  }

  y.set_size((&ph_emlrtRTEI), sp, 1, n);
  if (n > 0) {
    y[0] = a;
    if (n > 1) {
      int32_T nm1d2;
      y[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (int32_T k = 0; k <= nm1d2 - 2; k++) {
        ndbl = (static_cast<real_T>(k) + 1.0) * d;
        y[k + 1] = a + ndbl;
        y[(n - k) - 2] = apnd - ndbl;
      }

      if (nm1d2 << 1 == n - 1) {
        y[nm1d2] = (a + apnd) / 2.0;
      } else {
        ndbl = static_cast<real_T>(nm1d2) * d;
        y[nm1d2] = a + ndbl;
        y[nm1d2 + 1] = apnd - ndbl;
      }
    }
  }
}

// End of code generation (colon.cpp)
