//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sld_convolute_initialize.cpp
//
// Code generation for function 'sld_convolute_initialize'
//

// Include files
#include "sld_convolute_initialize.h"
#include "_coder_sld_convolute_mex.h"
#include "rt_nonfinite.h"
#include "sld_convolute_data.h"

// Variable Definitions
static const volatile char_T *emlrtBreakCheckR2012bFlagVar{nullptr};

// Function Definitions
void sld_convolute_initialize()
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

// End of code generation (sld_convolute_initialize.cpp)
