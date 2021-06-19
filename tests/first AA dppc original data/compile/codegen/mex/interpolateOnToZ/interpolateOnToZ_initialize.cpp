//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// interpolateOnToZ_initialize.cpp
//
// Code generation for function 'interpolateOnToZ_initialize'
//

// Include files
#include "interpolateOnToZ_initialize.h"
#include "_coder_interpolateOnToZ_mex.h"
#include "interpolateOnToZ_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static const volatile char_T *emlrtBreakCheckR2012bFlagVar{nullptr};

// Function Definitions
void interpolateOnToZ_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

// End of code generation (interpolateOnToZ_initialize.cpp)
