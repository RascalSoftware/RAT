//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  interp1.cpp
//
//  Code generation for function 'interp1'
//


// Include files
#include "interp1.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sld_convolute.h"
#include "sld_convolute_data.h"

// Variable Definitions
static emlrtRSInfo p_emlrtRSI = { 39,  // lineNo
  "interp1",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

static emlrtRSInfo q_emlrtRSI = { 162, // lineNo
  "interp1_work",                      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

static emlrtRSInfo r_emlrtRSI = { 171, // lineNo
  "interp1_work",                      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

static emlrtRSInfo s_emlrtRSI = { 179, // lineNo
  "interp1_work",                      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

static emlrtRSInfo t_emlrtRSI = { 182, // lineNo
  "interp1_work",                      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

static emlrtRSInfo u_emlrtRSI = { 222, // lineNo
  "interp1_work",                      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

static emlrtRSInfo w_emlrtRSI = { 582, // lineNo
  "interp1Linear",                     // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/polyfun/interp1.m"// pathName 
};

static emlrtRTEInfo c_emlrtRTEI = { 184,// lineNo
  13,                                  // colNo
  "interp1_work",                      // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName
};

static emlrtRTEInfo d_emlrtRTEI = { 164,// lineNo
  13,                                  // colNo
  "interp1_work",                      // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName
};

static emlrtRTEInfo e_emlrtRTEI = { 153,// lineNo
  15,                                  // colNo
  "interp1_work",                      // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName
};

static emlrtRTEInfo f_emlrtRTEI = { 137,// lineNo
  23,                                  // colNo
  "interp1_work",                      // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName
};

static emlrtRTEInfo w_emlrtRTEI = { 39,// lineNo
  46,                                  // colNo
  "interp1",                           // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName
};

static emlrtRTEInfo x_emlrtRTEI = { 40,// lineNo
  13,                                  // colNo
  "interp1",                           // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName
};

static emlrtRTEInfo y_emlrtRTEI = { 39,// lineNo
  9,                                   // colNo
  "interp1",                           // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName
};

// Function Declarations
static void interp1Linear(const emlrtStack *sp, const coder::array<real_T, 1U>
  &y, const coder::array<real_T, 2U> &xi, coder::array<real_T, 2U> &yi, const
  coder::array<real_T, 1U> &varargin_1);

// Function Definitions
static void interp1Linear(const emlrtStack *sp, const coder::array<real_T, 1U>
  &y, const coder::array<real_T, 2U> &xi, coder::array<real_T, 2U> &yi, const
  coder::array<real_T, 1U> &varargin_1)
{
  real_T minx;
  real_T maxx;
  int32_T ub_loop;
  real_T r_tmp;
  int32_T high_i;
  int32_T low_i;
  int32_T low_ip1;
  int32_T mid_i;
  real_T r;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  minx = varargin_1[0];
  maxx = varargin_1[varargin_1.size(0) - 1];
  st.site = &w_emlrtRSI;
  if ((1 <= xi.size(1)) && (xi.size(1) > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  ub_loop = xi.size(1) - 1;
  emlrtEnterParallelRegion(sp, omp_in_parallel());

#pragma omp parallel for \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(r_tmp,high_i,low_i,low_ip1,mid_i,r)

  for (int32_T k = 0; k <= ub_loop; k++) {
    r_tmp = xi[k];
    if (muDoubleScalarIsNaN(r_tmp)) {
      yi[k] = rtNaN;
    } else {
      if ((!(r_tmp > maxx)) && (!(r_tmp < minx))) {
        high_i = varargin_1.size(0);
        low_i = 1;
        low_ip1 = 2;
        while (high_i > low_ip1) {
          mid_i = (low_i >> 1) + (high_i >> 1);
          if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
            mid_i++;
          }

          if (xi[k] >= varargin_1[mid_i - 1]) {
            low_i = mid_i;
            low_ip1 = mid_i + 1;
          } else {
            high_i = mid_i;
          }
        }

        r_tmp = varargin_1[low_i - 1];
        r = (xi[k] - r_tmp) / (varargin_1[low_i] - r_tmp);
        if (r == 0.0) {
          yi[k] = y[low_i - 1];
        } else if (r == 1.0) {
          yi[k] = y[low_i];
        } else {
          r_tmp = y[low_i - 1];
          if (r_tmp == y[low_i]) {
            yi[k] = r_tmp;
          } else {
            yi[k] = (1.0 - r) * r_tmp + r * y[low_i];
          }
        }
      }
    }
  }

  emlrtExitParallelRegion(sp, omp_in_parallel());
}

void interp1(const emlrtStack *sp, const coder::array<real_T, 1U> &varargin_1,
             const coder::array<real_T, 1U> &varargin_2, const coder::array<
             real_T, 2U> &varargin_3, coder::array<real_T, 2U> &Vq)
{
  coder::array<real_T, 1U> y;
  int32_T n;
  int32_T nd2;
  coder::array<real_T, 1U> x;
  int32_T nx;
  uint32_T outsize_idx_1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &p_emlrtRSI;
  y.set_size((&w_emlrtRTEI), (&st), varargin_2.size(0));
  n = varargin_2.size(0);
  for (nd2 = 0; nd2 < n; nd2++) {
    y[nd2] = varargin_2[nd2];
  }

  x.set_size((&x_emlrtRTEI), (&st), varargin_1.size(0));
  n = varargin_1.size(0);
  for (nd2 = 0; nd2 < n; nd2++) {
    x[nd2] = varargin_1[nd2];
  }

  nx = varargin_1.size(0);
  if (varargin_1.size(0) != varargin_2.size(0)) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
      "Coder:MATLAB:interp1_YInvalidNumRows",
      "Coder:MATLAB:interp1_YInvalidNumRows", 0);
  }

  outsize_idx_1 = static_cast<uint32_T>(varargin_3.size(1));
  if (varargin_1.size(0) <= 1) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
      "MATLAB:interp1:NotEnoughPts", "MATLAB:interp1:NotEnoughPts", 0);
  }

  Vq.set_size((&y_emlrtRTEI), (&st), 1, (static_cast<int32_T>(outsize_idx_1)));
  n = static_cast<int32_T>(outsize_idx_1);
  for (nd2 = 0; nd2 < n; nd2++) {
    Vq[nd2] = rtNaN;
  }

  if (varargin_3.size(1) != 0) {
    int32_T k;
    b_st.site = &q_emlrtRSI;
    if (varargin_1.size(0) > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    k = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (k <= nx - 1) {
        if (muDoubleScalarIsNaN(varargin_1[k])) {
          emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
            "MATLAB:interp1:NaNinX", "MATLAB:interp1:NaNinX", 0);
        } else {
          k++;
        }
      } else {
        if (varargin_1[1] < varargin_1[0]) {
          int32_T b_j1;
          real_T xtmp;
          n = nx >> 1;
          b_st.site = &r_emlrtRSI;
          for (b_j1 = 0; b_j1 < n; b_j1++) {
            xtmp = x[b_j1];
            nd2 = (nx - b_j1) - 1;
            x[b_j1] = x[nd2];
            x[nd2] = xtmp;
          }

          b_st.site = &s_emlrtRSI;
          if ((varargin_2.size(0) != 0) && (varargin_2.size(0) > 1)) {
            n = varargin_2.size(0) - 1;
            nd2 = varargin_2.size(0) >> 1;
            for (k = 0; k < nd2; k++) {
              xtmp = y[k];
              b_j1 = n - k;
              y[k] = y[b_j1];
              y[b_j1] = xtmp;
            }
          }
        }

        b_st.site = &t_emlrtRSI;
        if ((2 <= nx) && (nx > 2147483646)) {
          c_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (k = 2; k <= nx; k++) {
          if (x[k - 1] <= x[k - 2]) {
            emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
              "Coder:toolbox:interp1_nonMonotonicX",
              "Coder:toolbox:interp1_nonMonotonicX", 0);
          }
        }

        b_st.site = &u_emlrtRSI;
        interp1Linear(&b_st, y, varargin_3, Vq, x);
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (interp1.cpp)
