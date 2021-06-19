//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// interp1.cpp
//
// Code generation for function 'interp1'
//

// Include files
#include "interp1.h"
#include "eml_int_forloop_overflow_check.h"
#include "interpolateOnToZ_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo
    o_emlrtRSI{
        38,        // lineNo
        "interp1", // fcnName
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" // pathName
    };

static emlrtRSInfo
    p_emlrtRSI{
        302,            // lineNo
        "interp1_work", // fcnName
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" // pathName
    };

static emlrtRSInfo
    q_emlrtRSI{
        204,            // lineNo
        "interp1_work", // fcnName
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" // pathName
    };

static emlrtRSInfo
    r_emlrtRSI{
        200,            // lineNo
        "interp1_work", // fcnName
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" // pathName
    };

static emlrtRSInfo
    s_emlrtRSI{
        192,            // lineNo
        "interp1_work", // fcnName
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" // pathName
    };

static emlrtRSInfo
    t_emlrtRSI{
        162,            // lineNo
        "interp1_work", // fcnName
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" // pathName
    };

static emlrtRSInfo
    v_emlrtRSI{
        666,             // lineNo
        "interp1Linear", // fcnName
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" // pathName
    };

static emlrtRTEInfo
    d_emlrtRTEI{
        206,            // lineNo
        13,             // colNo
        "interp1_work", // fName
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" // pName
    };

static emlrtRTEInfo
    e_emlrtRTEI{
        164,            // lineNo
        13,             // colNo
        "interp1_work", // fName
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" // pName
    };

static emlrtRTEInfo
    f_emlrtRTEI{
        137,            // lineNo
        23,             // colNo
        "interp1_work", // fName
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" // pName
    };

static emlrtRTEInfo
    i_emlrtRTEI{
        38,        // lineNo
        46,        // colNo
        "interp1", // fName
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" // pName
    };

static emlrtRTEInfo
    j_emlrtRTEI{
        39,        // lineNo
        13,        // colNo
        "interp1", // fName
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" // pName
    };

static emlrtRTEInfo
    k_emlrtRTEI{
        38,        // lineNo
        9,         // colNo
        "interp1", // fName
        "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" // pName
    };

// Function Declarations
namespace coder {
static void interp1Linear(const emlrtStack *sp,
                          const ::coder::array<real_T, 1U> &y,
                          const ::coder::array<real_T, 2U> &xi,
                          ::coder::array<real_T, 2U> &yi,
                          const ::coder::array<real_T, 1U> &varargin_1);

}

// Function Definitions
namespace coder {
static void interp1Linear(const emlrtStack *sp,
                          const ::coder::array<real_T, 1U> &y,
                          const ::coder::array<real_T, 2U> &xi,
                          ::coder::array<real_T, 2U> &yi,
                          const ::coder::array<real_T, 1U> &varargin_1)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T maxx;
  real_T minx;
  real_T r;
  real_T r_tmp;
  int32_T high_i;
  int32_T k;
  int32_T low_i;
  int32_T low_ip1;
  int32_T mid_i;
  int32_T ub_loop;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  minx = varargin_1[0];
  maxx = varargin_1[varargin_1.size(0) - 1];
  st.site = &v_emlrtRSI;
  if ((1 <= xi.size(1)) && (xi.size(1) > 2147483646)) {
    b_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  ub_loop = xi.size(1) - 1;
  emlrtEnterParallelRegion((emlrtCTX)sp,
                           static_cast<boolean_T>(omp_in_parallel()));
#pragma omp parallel for num_threads(emlrtAllocRegionTLSs(                     \
    sp->tls, omp_in_parallel(), omp_get_max_threads(),                         \
    omp_get_num_procs())) private(r_tmp, k, high_i, low_i, low_ip1, mid_i, r)

  for (k = 0; k <= ub_loop; k++) {
    r_tmp = xi[k];
    if (muDoubleScalarIsNaN(r_tmp)) {
      yi[k] = rtNaN;
    } else if ((!(r_tmp > maxx)) && (!(r_tmp < minx))) {
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
  emlrtExitParallelRegion((emlrtCTX)sp,
                          static_cast<boolean_T>(omp_in_parallel()));
}

void interp1(const emlrtStack *sp, const ::coder::array<real_T, 1U> &varargin_1,
             const ::coder::array<real_T, 1U> &varargin_2,
             const ::coder::array<real_T, 2U> &varargin_3,
             ::coder::array<real_T, 2U> &Vq)
{
  array<real_T, 1U> x;
  array<real_T, 1U> y;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T n;
  int32_T nd2;
  int32_T nx;
  boolean_T b;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &o_emlrtRSI;
  y.set_size(&i_emlrtRTEI, &st, varargin_2.size(0));
  n = varargin_2.size(0);
  for (nd2 = 0; nd2 < n; nd2++) {
    y[nd2] = varargin_2[nd2];
  }
  x.set_size(&j_emlrtRTEI, &st, varargin_1.size(0));
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
  Vq.set_size(&k_emlrtRTEI, &st, 1, varargin_3.size(1));
  n = varargin_3.size(1);
  for (nd2 = 0; nd2 < n; nd2++) {
    Vq[nd2] = rtNaN;
  }
  b = (varargin_3.size(1) == 0);
  if (!b) {
    int32_T k;
    b_st.site = &t_emlrtRSI;
    if ((1 <= nx) && (nx > 2147483646)) {
      c_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    k = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (k <= nx - 1) {
        if (muDoubleScalarIsNaN(varargin_1[k])) {
          emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
                                        "MATLAB:interp1:NaNinX",
                                        "MATLAB:interp1:NaNinX", 0);
        } else {
          k++;
        }
      } else {
        if (varargin_1[1] < varargin_1[0]) {
          real_T xtmp;
          int32_T b_j1;
          n = nx >> 1;
          b_st.site = &s_emlrtRSI;
          for (b_j1 = 0; b_j1 < n; b_j1++) {
            xtmp = x[b_j1];
            nd2 = (nx - b_j1) - 1;
            x[b_j1] = x[nd2];
            x[nd2] = xtmp;
          }
          b_st.site = &r_emlrtRSI;
          n = varargin_2.size(0) - 1;
          nd2 = varargin_2.size(0) >> 1;
          for (k = 0; k < nd2; k++) {
            xtmp = y[k];
            b_j1 = n - k;
            y[k] = y[b_j1];
            y[b_j1] = xtmp;
          }
        }
        b_st.site = &q_emlrtRSI;
        for (k = 2; k <= nx; k++) {
          if (x[k - 1] <= x[k - 2]) {
            emlrtErrorWithMessageIdR2018a(
                &st, &d_emlrtRTEI, "Coder:toolbox:interp1_nonMonotonicX",
                "Coder:toolbox:interp1_nonMonotonicX", 0);
          }
        }
        b_st.site = &p_emlrtRSI;
        interp1Linear(&b_st, y, varargin_3, Vq, x);
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder

// End of code generation (interp1.cpp)
