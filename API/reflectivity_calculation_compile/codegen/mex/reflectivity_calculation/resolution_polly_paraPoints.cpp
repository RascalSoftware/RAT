//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  resolution_polly_paraPoints.cpp
//
//  Code generation for function 'resolution_polly_paraPoints'
//


// Include files
#include "resolution_polly_paraPoints.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include "sum.h"

// Variable Definitions
static emlrtRSInfo dg_emlrtRSI = { 26, // lineNo
  "resolution_polly_paraPoints",       // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly_paraPoints.m"// pathName 
};

static emlrtRTEInfo xb_emlrtRTEI = { 25,// lineNo
  13,                                  // colNo
  "resolution_polly_paraPoints",       // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly_paraPoints.m"// pName 
};

static emlrtBCInfo mh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  10,                                  // lineNo
  5,                                   // colNo
  "dummydata",                         // aName
  "resolution_polly_paraPoints",       // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo nh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  31,                                  // lineNo
  24,                                  // colNo
  "dummydata",                         // aName
  "resolution_polly_paraPoints",       // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo oh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  31,                                  // lineNo
  9,                                   // colNo
  "dummydata",                         // aName
  "resolution_polly_paraPoints",       // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ph_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  26,                                  // lineNo
  22,                                  // colNo
  "xdata",                             // aName
  "resolution_polly_paraPoints",       // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo qh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  26,                                  // lineNo
  33,                                  // colNo
  "xdata",                             // aName
  "resolution_polly_paraPoints",       // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo rh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  28,                                  // lineNo
  24,                                  // colNo
  "dummydata",                         // aName
  "resolution_polly_paraPoints",       // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo sh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  28,                                  // lineNo
  39,                                  // colNo
  "dummyref",                          // aName
  "resolution_polly_paraPoints",       // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo th_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  28,                                  // lineNo
  9,                                   // colNo
  "dummydata",                         // aName
  "resolution_polly_paraPoints",       // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo ci_emlrtRTEI = { 5,// lineNo
  1,                                   // colNo
  "resolution_polly_paraPoints",       // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly_paraPoints.m"// pName 
};

static emlrtRTEInfo di_emlrtRTEI = { 6,// lineNo
  1,                                   // colNo
  "resolution_polly_paraPoints",       // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly_paraPoints.m"// pName 
};

// Function Definitions
void resolution_polly_paraPoints(const emlrtStack *sp, const coder::array<real_T,
  1U> &xdata, const coder::array<real_T, 1U> &ydata, real_T res, real_T points,
  coder::array<real_T, 1U> &out)
{
  int32_T loop_ub;
  int32_T i;
  coder::array<real_T, 1U> dummyref;
  int32_T b_loop_ub;
  int32_T j;
  real_T g;
  int32_T b_i;
  int32_T ilow;
  real_T sumg;
  int32_T i1;
  int32_T i2;
  int32_T c_i;
  emlrtStack st;
  emlrtStack b_st;
  boolean_T emlrtHadParallelError = false;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  res += 0.0001;
  loop_ub = static_cast<int32_T>(points);
  out.set_size((&ci_emlrtRTEI), sp, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    out[i] = 0.0;
  }

  dummyref.set_size((&di_emlrtRTEI), sp, ydata.size(0));
  b_loop_ub = ydata.size(0);
  for (i = 0; i < b_loop_ub; i++) {
    dummyref[i] = ydata[i];
  }

  loop_ub--;
  emlrtEnterParallelRegion(sp, omp_in_parallel());

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(g,b_i,ilow,sumg,b_st,i1,i2,c_i) \
 firstprivate(st,emlrtHadParallelError)

  {
    try {
      st.prev = sp;
      st.tls = emlrtAllocTLS((emlrtStack *)sp, omp_get_thread_num());
      st.site = NULL;
      b_st.prev = &st;
      b_st.tls = st.tls;
    } catch (...) {
      emlrtHadParallelError = true;
    }

#pragma omp for nowait

    for (j = 0; j <= loop_ub; j++) {
      if (emlrtHadParallelError)
        continue;
      try {
        sumg = 0.0;
        i1 = static_cast<int32_T>(j + 1U);
        if ((i1 < 1) || (i1 > out.size(0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, out.size(0), &mh_emlrtBCI, &st);
        }

        out[i1 - 1] = 0.0;
        if (j + 1U > 10U) {
          ilow = -10;
        } else {
          ilow = static_cast<int32_T>(-(static_cast<real_T>(j) + 1.0)) + 1;
        }

        if (static_cast<real_T>(j) + 1.0 < points - 10.0) {
          g = 10.0;
        } else {
          g = points - (static_cast<real_T>(j) + 1.0);
        }

        //     try
        i2 = static_cast<int32_T>(g + (1.0 - static_cast<real_T>(ilow)));
        emlrtForLoopVectorCheckR2012b(static_cast<real_T>(ilow), 1.0, g,
          mxDOUBLE_CLASS, i2, &xb_emlrtRTEI, &st);
        for (c_i = 0; c_i < i2; c_i++) {
          b_i = ilow + c_i;
          b_st.site = &dg_emlrtRSI;
          b_i = static_cast<int32_T>((static_cast<real_T>(j) + 1.0) +
            static_cast<real_T>(b_i));
          if ((b_i < 1) || (b_i > xdata.size(0))) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, xdata.size(0), &ph_emlrtBCI,
              &b_st);
          }

          if (i1 > xdata.size(0)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, xdata.size(0), &qh_emlrtBCI,
              &b_st);
          }

          g = (xdata[b_i - 1] - xdata[i1 - 1]) / (res * xdata[i1 - 1]);
          g = muDoubleScalarExp(-(g * g));
          sumg += g;
          if (i1 > out.size(0)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, out.size(0), &rh_emlrtBCI, &st);
          }

          if (b_i > dummyref.size(0)) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, dummyref.size(0), &sh_emlrtBCI,
              &st);
          }

          if (i1 > out.size(0)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, out.size(0), &th_emlrtBCI, &st);
          }

          out[i1 - 1] = out[i1 - 1] + dummyref[b_i - 1] * g;
        }

        if (sumg != 0.0) {
          if (i1 > out.size(0)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, out.size(0), &nh_emlrtBCI, &st);
          }

          if (i1 > out.size(0)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, out.size(0), &oh_emlrtBCI, &st);
          }

          out[i1 - 1] = out[i1 - 1] / sumg;
        }

        //      catch
        //          disp('debug!');
        //      end
      } catch (...) {
        emlrtHadParallelError = true;
      }
    }
  }

  emlrtExitParallelRegion(sp, omp_in_parallel());
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (resolution_polly_paraPoints.cpp)
