//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  shiftdata.cpp
//
//  Code generation for function 'shiftdata'
//


// Include files
#include "shiftdata.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "sum.h"

// Variable Definitions
static emlrtRSInfo kf_emlrtRSI = { 24, // lineNo
  "shiftdata",                         // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"// pathName 
};

static emlrtRSInfo lf_emlrtRSI = { 31, // lineNo
  "shiftdata",                         // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"// pathName 
};

static emlrtBCInfo hk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  26,                                  // lineNo
  24,                                  // colNo
  "lowIndex",                          // aName
  "shiftdata",                         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo xb_emlrtDCI = { 12, // lineNo
  8,                                   // colNo
  "shiftdata",                         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",// pName 
  1                                    // checkKind
};

static emlrtECInfo x_emlrtECI = { -1,  // nDims
  17,                                  // lineNo
  9,                                   // colNo
  "shiftdata",                         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"// pName 
};

static emlrtECInfo y_emlrtECI = { -1,  // nDims
  18,                                  // lineNo
  9,                                   // colNo
  "shiftdata",                         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"// pName 
};

static emlrtECInfo ab_emlrtECI = { -1, // nDims
  19,                                  // lineNo
  9,                                   // colNo
  "shiftdata",                         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"// pName 
};

static emlrtBCInfo ik_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  38,                                  // lineNo
  29,                                  // colNo
  "data",                              // aName
  "shiftdata",                         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo jk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  38,                                  // lineNo
  38,                                  // colNo
  "data",                              // aName
  "shiftdata",                         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo gk_emlrtRTEI = { 17,// lineNo
  21,                                  // colNo
  "shiftdata",                         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"// pName 
};

static emlrtRTEInfo hk_emlrtRTEI = { 18,// lineNo
  21,                                  // colNo
  "shiftdata",                         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"// pName 
};

static emlrtRTEInfo ik_emlrtRTEI = { 19,// lineNo
  21,                                  // colNo
  "shiftdata",                         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"// pName 
};

static emlrtRTEInfo jk_emlrtRTEI = { 24,// lineNo
  25,                                  // colNo
  "shiftdata",                         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"// pName 
};

static emlrtRTEInfo kk_emlrtRTEI = { 24,// lineNo
  9,                                   // colNo
  "shiftdata",                         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"// pName 
};

static emlrtRTEInfo lk_emlrtRTEI = { 31,// lineNo
  24,                                  // colNo
  "shiftdata",                         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"// pName 
};

static emlrtRTEInfo mk_emlrtRTEI = { 31,// lineNo
  9,                                   // colNo
  "shiftdata",                         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"// pName 
};

static emlrtRTEInfo nk_emlrtRTEI = { 38,// lineNo
  24,                                  // colNo
  "shiftdata",                         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"// pName 
};

// Function Definitions
void shiftdata(const emlrtStack *sp, real_T scalefac, real_T horshift, real_T
               dataPresent, coder::array<real_T, 2U> &data, const real_T
               dataLimits[2])
{
  int32_T nx;
  coder::array<real_T, 1U> lowIndex;
  coder::array<boolean_T, 1U> x;
  coder::array<int32_T, 1U> ii;
  int32_T iv[2];
  coder::array<real_T, 2U> b_data;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  // Shifts the data according to scale factor
  //  scalefac = problem.scalefactors;
  //  horshift = problem.qshifts;
  //  numberOfContrasts = problem.numberOfContrasts;
  //  dataPresent = problem.dataPresent;
  //  allData = problem.data;
  //  dataLimits = problem.dataLimits;
  // shifted_data = cell(1,numberOfContrasts);
  if (dataPresent != static_cast<int32_T>(muDoubleScalarFloor(dataPresent))) {
    emlrtIntegerCheckR2012b(dataPresent, &xb_emlrtDCI, sp);
  }

  switch (static_cast<int32_T>(dataPresent)) {
   case 1:
    {
      int32_T i;
      int32_T idx;
      int32_T b_ii;
      boolean_T exitg1;
      int32_T b_lowIndex;
      if (scalefac == 0.0) {
        scalefac = 1.0E-30;
      }

      emlrtSubAssignSizeCheckR2012b(data.size(), 1, data.size(), 1, &x_emlrtECI,
        sp);
      nx = data.size(0) - 1;
      lowIndex.set_size((&gk_emlrtRTEI), sp, (nx + 1));
      for (i = 0; i <= nx; i++) {
        lowIndex[i] = data[i] + horshift;
      }

      nx = lowIndex.size(0);
      for (i = 0; i < nx; i++) {
        data[i] = lowIndex[i];
      }

      nx = data.size(0);
      lowIndex.set_size((&hk_emlrtRTEI), sp, nx);
      for (i = 0; i < nx; i++) {
        lowIndex[i] = data[i + data.size(0)] / scalefac;
      }

      emlrtSubAssignSizeCheckR2012b(data.size(), 1, lowIndex.size(), 1,
        &y_emlrtECI, sp);
      nx = lowIndex.size(0);
      for (i = 0; i < nx; i++) {
        data[i + data.size(0)] = lowIndex[i];
      }

      nx = data.size(0);
      lowIndex.set_size((&ik_emlrtRTEI), sp, nx);
      for (i = 0; i < nx; i++) {
        lowIndex[i] = data[i + data.size(0) * 2] / scalefac;
      }

      emlrtSubAssignSizeCheckR2012b(data.size(), 1, lowIndex.size(), 1,
        &ab_emlrtECI, sp);
      nx = lowIndex.size(0);
      for (i = 0; i < nx; i++) {
        data[i + data.size(0) * 2] = lowIndex[i];
      }

      st.site = &kf_emlrtRSI;
      nx = data.size(0);
      x.set_size((&jk_emlrtRTEI), (&st), nx);
      for (i = 0; i < nx; i++) {
        x[i] = (data[i] < dataLimits[0]);
      }

      b_st.site = &nd_emlrtRSI;
      nx = x.size(0);
      c_st.site = &od_emlrtRSI;
      idx = 0;
      ii.set_size((&eg_emlrtRTEI), (&c_st), x.size(0));
      d_st.site = &pd_emlrtRSI;
      if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
        e_st.site = &vb_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      b_ii = 0;
      exitg1 = false;
      while ((!exitg1) && (b_ii <= nx - 1)) {
        if (x[b_ii]) {
          idx++;
          ii[idx - 1] = b_ii + 1;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            b_ii++;
          }
        } else {
          b_ii++;
        }
      }

      if (idx > x.size(0)) {
        emlrtErrorWithMessageIdR2018a(&c_st, &pb_emlrtRTEI,
          "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
      }

      if (x.size(0) == 1) {
        if (idx == 0) {
          ii.set_size((&fg_emlrtRTEI), (&c_st), 0);
        }
      } else {
        if (1 > idx) {
          i = 0;
        } else {
          i = idx;
        }

        iv[0] = 1;
        iv[1] = i;
        d_st.site = &qd_emlrtRSI;
        indexShapeCheck(&d_st, ii.size(0), iv);
        ii.set_size((&fg_emlrtRTEI), (&c_st), i);
      }

      lowIndex.set_size((&kk_emlrtRTEI), (&st), ii.size(0));
      nx = ii.size(0);
      for (i = 0; i < nx; i++) {
        lowIndex[i] = ii[i];
      }

      if (lowIndex.size(0) != 0) {
        if (lowIndex.size(0) < 1) {
          emlrtDynamicBoundsCheckR2012b(lowIndex.size(0), 1, lowIndex.size(0),
            &hk_emlrtBCI, sp);
        }

        b_lowIndex = static_cast<int32_T>(lowIndex[lowIndex.size(0) - 1]);
      } else {
        b_lowIndex = 1;
      }

      st.site = &lf_emlrtRSI;
      nx = data.size(0);
      x.set_size((&lk_emlrtRTEI), (&st), nx);
      for (i = 0; i < nx; i++) {
        x[i] = (data[i] > dataLimits[1]);
      }

      b_st.site = &nd_emlrtRSI;
      nx = x.size(0);
      c_st.site = &od_emlrtRSI;
      idx = 0;
      ii.set_size((&eg_emlrtRTEI), (&c_st), x.size(0));
      d_st.site = &pd_emlrtRSI;
      if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
        e_st.site = &vb_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      b_ii = 0;
      exitg1 = false;
      while ((!exitg1) && (b_ii <= nx - 1)) {
        if (x[b_ii]) {
          idx++;
          ii[idx - 1] = b_ii + 1;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            b_ii++;
          }
        } else {
          b_ii++;
        }
      }

      if (idx > x.size(0)) {
        emlrtErrorWithMessageIdR2018a(&c_st, &pb_emlrtRTEI,
          "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
      }

      if (x.size(0) == 1) {
        if (idx == 0) {
          ii.set_size((&fg_emlrtRTEI), (&c_st), 0);
        }
      } else {
        if (1 > idx) {
          i = 0;
        } else {
          i = idx;
        }

        iv[0] = 1;
        iv[1] = i;
        d_st.site = &qd_emlrtRSI;
        indexShapeCheck(&d_st, ii.size(0), iv);
        ii.set_size((&fg_emlrtRTEI), (&c_st), i);
      }

      lowIndex.set_size((&mk_emlrtRTEI), (&st), ii.size(0));
      nx = ii.size(0);
      for (i = 0; i < nx; i++) {
        lowIndex[i] = ii[i];
      }

      if (lowIndex.size(0) != 0) {
        nx = static_cast<int32_T>(lowIndex[0]);
      } else {
        nx = data.size(0);
      }

      if (b_lowIndex > nx) {
        i = 0;
        nx = 0;
      } else {
        i = data.size(0);
        if ((b_lowIndex < 1) || (b_lowIndex > i)) {
          emlrtDynamicBoundsCheckR2012b(b_lowIndex, 1, i, &ik_emlrtBCI, sp);
        }

        i = b_lowIndex - 1;
        b_ii = data.size(0);
        if ((nx < 1) || (nx > b_ii)) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, b_ii, &jk_emlrtBCI, sp);
        }
      }

      nx -= i;
      b_data.set_size((&nk_emlrtRTEI), sp, nx, 3);
      for (b_ii = 0; b_ii < 3; b_ii++) {
        for (idx = 0; idx < nx; idx++) {
          b_data[idx + b_data.size(0) * b_ii] = data[(i + idx) + data.size(0) *
            b_ii];
        }
      }

      data.set_size((&nk_emlrtRTEI), sp, b_data.size(0), 3);
      nx = b_data.size(0);
      for (i = 0; i < 3; i++) {
        for (b_ii = 0; b_ii < nx; b_ii++) {
          data[b_ii + data.size(0) * i] = b_data[b_ii + b_data.size(0) * i];
        }
      }
    }
    break;
  }

  //  function Ref = makeFresnelData(problem,contrast)
  //
  //      this_data = problem.shifted_data{contrast};
  //      xdata = this_data(:,1);
  //      nbair = problem.nbairs(contrast);
  //      nbsub = problem.nbsubs(contrast);
  //      slds = [0 0 0];
  //      resol = problem.resolution;
  //      resolType = problem.resolType;
  //      %abeles(xdata,SLDs,nbair,nbsub,ssub,nrepeats,sinter,resol)
  //      %Ref = abeles_new_2(xdata,slds,nbair,nbsub,s_sub,repeats,
  //      Ref = abeles_new_2(xdata,slds,nbair,nbsub,0,1,resolType,resol);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (shiftdata.cpp)
