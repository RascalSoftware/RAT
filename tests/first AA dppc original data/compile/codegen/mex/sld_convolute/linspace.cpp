//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  linspace.cpp
//
//  Code generation for function 'linspace'
//


// Include files
#include "linspace.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sld_convolute.h"

// Variable Definitions
static emlrtRSInfo m_emlrtRSI = { 36,  // lineNo
  "linspace",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/linspace.m"// pathName
};

static emlrtRTEInfo v_emlrtRTEI = { 36,// lineNo
  9,                                   // colNo
  "linspace",                          // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/linspace.m"// pName
};

// Function Definitions
void linspace(const emlrtStack *sp, real_T d1, real_T d2, real_T n1, coder::
              array<real_T, 2U> &y)
{
  int32_T i;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &m_emlrtRSI;
  i = static_cast<int32_T>(n1);
  y.set_size((&v_emlrtRTEI), (&st), 1, i);
  if (i >= 1) {
    int32_T y_tmp;
    y_tmp = i - 1;
    y[y_tmp] = d2;
    if (y.size(1) >= 2) {
      y[0] = d1;
      if (y.size(1) >= 3) {
        if ((d1 == -d2) && (i > 2)) {
          for (int32_T k = 2; k <= y_tmp; k++) {
            y[k - 1] = d2 * (static_cast<real_T>(((k << 1) - i) - 1) / (
              static_cast<real_T>(i) - 1.0));
          }

          if ((i & 1) == 1) {
            y[i >> 1] = 0.0;
          }
        } else if (((d1 < 0.0) != (d2 < 0.0)) && ((muDoubleScalarAbs(d1) >
                     8.9884656743115785E+307) || (muDoubleScalarAbs(d2) >
                     8.9884656743115785E+307))) {
          real_T delta1;
          real_T delta2;
          delta1 = d1 / (static_cast<real_T>(y.size(1)) - 1.0);
          delta2 = d2 / (static_cast<real_T>(y.size(1)) - 1.0);
          i = y.size(1);
          for (int32_T k = 0; k <= i - 3; k++) {
            y[k + 1] = (d1 + delta2 * (static_cast<real_T>(k) + 1.0)) - delta1 *
              (static_cast<real_T>(k) + 1.0);
          }
        } else {
          real_T delta1;
          delta1 = (d2 - d1) / (static_cast<real_T>(y.size(1)) - 1.0);
          i = y.size(1);
          for (int32_T k = 0; k <= i - 3; k++) {
            y[k + 1] = d1 + (static_cast<real_T>(k) + 1.0) * delta1;
          }
        }
      }
    }
  }
}

// End of code generation (linspace.cpp)
