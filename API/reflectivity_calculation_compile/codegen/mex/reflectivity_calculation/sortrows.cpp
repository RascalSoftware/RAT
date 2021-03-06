//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  sortrows.cpp
//
//  Code generation for function 'sortrows'
//


// Include files
#include "sortrows.h"
#include "chiSquared.h"
#include "eml_int_forloop_overflow_check.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"
#include "sortLE.h"
#include "sum.h"

// Variable Definitions
static emlrtRSInfo me_emlrtRSI = { 24, // lineNo
  "sortrows",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"// pathName 
};

static emlrtRSInfo ne_emlrtRSI = { 27, // lineNo
  "sortrows",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"// pathName 
};

static emlrtRSInfo oe_emlrtRSI = { 28, // lineNo
  "sortrows",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"// pathName 
};

static emlrtRSInfo pe_emlrtRSI = { 95, // lineNo
  "parseSortrowsOptions",              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/parseSortrowsOptions.m"// pathName 
};

static emlrtRSInfo qe_emlrtRSI = { 82, // lineNo
  "sortIdx",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

static emlrtRSInfo re_emlrtRSI = { 86, // lineNo
  "sortIdx",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pathName 
};

static emlrtRSInfo se_emlrtRSI = { 57, // lineNo
  "mergesort",                         // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/mergesort.m"// pathName 
};

static emlrtRSInfo te_emlrtRSI = { 58, // lineNo
  "mergesort",                         // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/mergesort.m"// pathName 
};

static emlrtRSInfo ue_emlrtRSI = { 85, // lineNo
  "mergesort",                         // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/mergesort.m"// pathName 
};

static emlrtRSInfo ve_emlrtRSI = { 113,// lineNo
  "mergesort",                         // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/mergesort.m"// pathName 
};

static emlrtRSInfo ye_emlrtRSI = { 39, // lineNo
  "apply_row_permutation",             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"// pathName 
};

static emlrtRSInfo af_emlrtRSI = { 40, // lineNo
  "apply_row_permutation",             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"// pathName 
};

static emlrtRSInfo bf_emlrtRSI = { 43, // lineNo
  "apply_row_permutation",             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"// pathName 
};

static emlrtRTEInfo gj_emlrtRTEI = { 27,// lineNo
  1,                                   // colNo
  "sortrows",                          // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"// pName
};

static emlrtRTEInfo hj_emlrtRTEI = { 86,// lineNo
  15,                                  // colNo
  "sortIdx",                           // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/sortIdx.m"// pName
};

static emlrtRTEInfo ij_emlrtRTEI = { 28,// lineNo
  5,                                   // colNo
  "sortrows",                          // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sortrows.m"// pName
};

// Function Definitions
void sortrows(const emlrtStack *sp, coder::array<real_T, 2U> &y)
{
  int32_T col_data[2];
  int32_T n;
  coder::array<int32_T, 1U> idx;
  int32_T i2;
  int32_T j;
  coder::array<int32_T, 1U> iwork;
  int32_T k;
  coder::array<real_T, 1U> ycol;
  int32_T i;
  int32_T qEnd;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &me_emlrtRSI;
  b_st.site = &pe_emlrtRSI;
  col_data[0] = 1;
  col_data[1] = 2;
  st.site = &ne_emlrtRSI;
  n = y.size(0) + 1;
  idx.set_size((&gj_emlrtRTEI), (&st), y.size(0));
  i2 = y.size(0);
  for (j = 0; j < i2; j++) {
    idx[j] = 0;
  }

  if (y.size(0) == 0) {
    b_st.site = &qe_emlrtRSI;
    if ((1 <= y.size(0)) && (y.size(0) > 2147483646)) {
      c_st.site = &nb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (k = 0; k <= n - 2; k++) {
      idx[k] = k + 1;
    }
  } else {
    b_st.site = &re_emlrtRSI;
    iwork.set_size((&hj_emlrtRTEI), (&b_st), y.size(0));
    i2 = y.size(0) - 1;
    c_st.site = &se_emlrtRSI;
    if ((1 <= y.size(0) - 1) && (y.size(0) - 1 > 2147483645)) {
      d_st.site = &nb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 1; k <= i2; k += 2) {
      c_st.site = &te_emlrtRSI;
      if (sortLE(y, col_data, k, k + 1)) {
        idx[k - 1] = k;
        idx[k] = k + 1;
      } else {
        idx[k - 1] = k + 1;
        idx[k] = k;
      }
    }

    if ((y.size(0) & 1) != 0) {
      idx[y.size(0) - 1] = y.size(0);
    }

    i = 2;
    while (i < n - 1) {
      i2 = i << 1;
      j = 1;
      for (int32_T pEnd = i + 1; pEnd < n; pEnd = qEnd + i) {
        int32_T p;
        int32_T q;
        int32_T kEnd;
        p = j;
        q = pEnd;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          c_st.site = &ue_emlrtRSI;
          if (sortLE(y, col_data, idx[p - 1], idx[q - 1])) {
            iwork[k] = idx[p - 1];
            p++;
            if (p == pEnd) {
              while (q < qEnd) {
                k++;
                iwork[k] = idx[q - 1];
                q++;
              }
            }
          } else {
            iwork[k] = idx[q - 1];
            q++;
            if (q == qEnd) {
              while (p < pEnd) {
                k++;
                iwork[k] = idx[p - 1];
                p++;
              }
            }
          }

          k++;
        }

        c_st.site = &ve_emlrtRSI;
        for (k = 0; k < kEnd; k++) {
          idx[(j + k) - 1] = iwork[k];
        }

        j = qEnd;
      }

      i = i2;
    }
  }

  st.site = &oe_emlrtRSI;
  i2 = y.size(0);
  ycol.set_size((&ij_emlrtRTEI), (&st), y.size(0));
  b_st.site = &ye_emlrtRSI;
  b_st.site = &af_emlrtRSI;
  if ((1 <= i2) && (i2 > 2147483646)) {
    c_st.site = &nb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (i = 0; i < i2; i++) {
    ycol[i] = y[idx[i] - 1];
  }

  b_st.site = &bf_emlrtRSI;
  if ((1 <= i2) && (i2 > 2147483646)) {
    c_st.site = &nb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (i = 0; i < i2; i++) {
    y[i] = ycol[i];
  }

  b_st.site = &af_emlrtRSI;
  for (i = 0; i < i2; i++) {
    ycol[i] = y[(idx[i] + y.size(0)) - 1];
  }

  b_st.site = &bf_emlrtRSI;
  for (i = 0; i < i2; i++) {
    y[i + y.size(0)] = ycol[i];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (sortrows.cpp)
