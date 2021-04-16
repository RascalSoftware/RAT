//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  strcmp.cpp
//
//  Code generation for function 'strcmp'
//


// Include files
#include "strcmp.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo w_emlrtRSI = { 63,  // lineNo
  "strcmp",                            // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/strcmp.m"// pathName 
};

static emlrtRSInfo x_emlrtRSI = { 138, // lineNo
  "loc_strcmp",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/strcmp.m"// pathName 
};

static emlrtRSInfo y_emlrtRSI = { 216, // lineNo
  "charcmp",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/strcmp.m"// pathName 
};

static emlrtRTEInfo ob_emlrtRTEI = { 15,// lineNo
  9,                                   // colNo
  "assertSupportedString",             // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/assertSupportedString.m"// pName 
};

// Function Definitions
boolean_T b_strcmp(const emlrtStack *sp, const coder::array<char_T, 2U> &a)
{
  boolean_T b_bool;
  static const char_T cv[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
    '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
    '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
    '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?',
    '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']',
    '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{',
    '|', '}', '~', '\x7f' };

  static const char_T cv1[13] = { 'a', 'i', 'r', '/', 's', 'u', 'b', 's', 't',
    'r', 'a', 't', 'e' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &w_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &x_emlrtRSI;
  b_bool = false;
  if (a.size(1) == 13) {
    int32_T kstr;
    kstr = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (kstr < 13) {
        int32_T i;
        c_st.site = &y_emlrtRSI;
        i = static_cast<uint8_T>(a[kstr]);
        if (i > 127) {
          emlrtErrorWithMessageIdR2018a(&c_st, &ob_emlrtRTEI,
            "Coder:toolbox:unsupportedString", "Coder:toolbox:unsupportedString",
            2, 12, 127);
        }

        if (cv[i] != cv[static_cast<int32_T>(cv1[kstr])]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

// End of code generation (strcmp.cpp)
