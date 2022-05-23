//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// matlabEngineCaller_customLayers_initialize.cpp
//
// Code generation for function 'matlabEngineCaller_customLayers_initialize'
//

// Include files
#include "matlabEngineCaller_customLayers_initialize.h"
#include "_coder_matlabEngineCaller_customLayers_mex.h"
#include "matlabEngineCaller_customLayers_data.h"
#include "rt_nonfinite.h"

// Function Declarations
static void c_matlabEngineCaller_customLaye();

// Function Definitions
static void c_matlabEngineCaller_customLaye()
{
  const int32_T postfix_exprs_0_0[2]{0, -1};
  const int32_T cond_ends_0_0{1242};
  const int32_T cond_starts_0_0{1229};
  mex_InitInfAndNan();
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
                  "matlabEngineCaller_customLayers.m",
                  0U, 1U, 10U, 5U, 0U, 0U, 0U, 1U, 0U, 1U, 1U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U,
               "matlabEngineCaller_customLayers", 0, -1, 3704);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 9U, 3653, -1, 3690);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 8U, 3553, -1, 3607);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 7U, 3355, -1, 3497);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 3286, -1, 3312);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 1606, -1, 3204);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 1338, -1, 1436);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 1251, -1, 1281);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 1190, -1, 1220);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 1059, -1, 1120);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 632, -1, 910);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 972, 997, 1437, 3703);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 1002, 1015, -1, 1128);
  covrtIfInit(&emlrtCoverageInstance, 0U, 2U, 1225, 1242, -1, 1289);
  covrtIfInit(&emlrtCoverageInstance, 0U, 3U, 3260, 3277, 3640, 3698);
  covrtIfInit(&emlrtCoverageInstance, 0U, 4U, 3510, 3536, -1, 3623);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 0U, 1228, 1242, 1, 0,
                (int32_T *)&cond_starts_0_0, (int32_T *)&cond_ends_0_0, 2,
                *(int32_T(*)[2]) & postfix_exprs_0_0[0]);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 3321, 3342, 3635);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void matlabEngineCaller_customLayers_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    c_matlabEngineCaller_customLaye();
  }
}

// End of code generation (matlabEngineCaller_customLayers_initialize.cpp)
