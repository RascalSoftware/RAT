//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// matlabEngineCaller_customLayers.cpp
//
// Code generation for function 'matlabEngineCaller_customLayers'
//

// Include files
#include "matlabEngineCaller_customLayers.h"
#include "matlabEngineCaller_customLayers_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtBCInfo emlrtBCI{
    -1,                                // iFirst
    -1,                                // iLast
    15,                                // lineNo
    17,                                // colNo
    "params",                          // aName
    "matlabEngineCaller_customLayers", // fName
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m", // pName
    0                                    // checkKind
};

static emlrtRTEInfo emlrtRTEI{
    95,                                // lineNo
    17,                                // colNo
    "matlabEngineCaller_customLayers", // fName
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m" // pName
};

static emlrtDCInfo emlrtDCI{
    94,                                // lineNo
    24,                                // colNo
    "matlabEngineCaller_customLayers", // fName
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m", // pName
    1                                    // checkKind
};

static emlrtDCInfo b_emlrtDCI{
    94,                                // lineNo
    9,                                 // colNo
    "matlabEngineCaller_customLayers", // fName
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m", // pName
    1                                    // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    1,                                 // iFirst
    300,                               // iLast
    96,                                // lineNo
    23,                                // colNo
    "outp",                            // aName
    "matlabEngineCaller_customLayers", // fName
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m", // pName
    0                                    // checkKind
};

static emlrtBCInfo c_emlrtBCI{
    -1,                                // iFirst
    -1,                                // iLast
    97,                                // lineNo
    13,                                // colNo
    "output",                          // aName
    "matlabEngineCaller_customLayers", // fName
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m", // pName
    0                                    // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    1,                                 // iFirst
    3,                                 // iLast
    97,                                // lineNo
    13,                                // colNo
    "output",                          // aName
    "matlabEngineCaller_customLayers", // fName
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m", // pName
    3                                    // checkKind
};

static emlrtRTEInfo b_emlrtRTEI{
    14,                                // lineNo
    1,                                 // colNo
    "matlabEngineCaller_customLayers", // fName
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m" // pName
};

static emlrtRTEInfo c_emlrtRTEI{
    19,                                // lineNo
    1,                                 // colNo
    "matlabEngineCaller_customLayers", // fName
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m" // pName
};

static emlrtRTEInfo d_emlrtRTEI{
    84,                                // lineNo
    34,                                // colNo
    "matlabEngineCaller_customLayers", // fName
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m" // pName
};

static emlrtRTEInfo e_emlrtRTEI{
    105,                               // lineNo
    9,                                 // colNo
    "matlabEngineCaller_customLayers", // fName
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m" // pName
};

static emlrtRTEInfo f_emlrtRTEI{
    94,                                // lineNo
    9,                                 // colNo
    "matlabEngineCaller_customLayers", // fName
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m" // pName
};

// Function Definitions
void matlabEngineCaller_customLayers(
    const emlrtStack *sp, const coder::array<real_T, 2U> &params,
    real_T contrast, const coder::array<char_T, 2U> &funcName,
    const coder::array<char_T, 2U> &funcPath, real_T bulkIn, real_T bulkOut,
    coder::array<real_T, 2U> &output, real_T *sRough)
{
  static const char_T cv1[34]{'(', 'p', 'a', 'r', 'a', 'm', 's', ',', 'b',
                              'u', 'l', 'k', '_', 'i', 'n', ',', 'b', 'u',
                              'l', 'k', '_', 'o', 'u', 't', ',', 'c', 'o',
                              'n', 't', 'r', 'a', 's', 't', ')'};
  static const char_T cv[17]{'[', 't', 'o', 't', 'a', 'l', ',', 'l', 'a',
                             'y', 'e', 'r', 's', ']', ' ', '=', ' '};
  coder::array<real_T, 2U> b_params;
  coder::array<char_T, 2U> funName;
  coder::array<char_T, 2U> pathCall;
  real_T outp[300];
  real_T nLayers;
  int32_T colCount;
  int32_T i;
  int32_T loop_ub;
  uint32_T rowCount;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 0);
  //  Evaluate matlab function from compiled mex using an external Matlab
  //  engine. This version uses the Matlab Engine API for C
  //  (https://uk.mathworks.com/help/matlab/calling-matlab-engine-from-c-programs-1.html)
  //  In reality, we want to be using a Class via the Matleb engine API for C++
  //  (https://uk.mathworks.com/help/matlab/matlab_external/matlab-engine-api-for-c.html)
  //  Irrespective of we use Matlab or Mex, we need the same calling string.
  //  We put together the Matlab command string that that we will excecute
  funName.set_size(&b_emlrtRTEI, sp, 1, funcName.size(1) + 51);
  for (i = 0; i < 17; i++) {
    funName[i] = cv[i];
  }
  loop_ub = funcName.size(1);
  for (i = 0; i < loop_ub; i++) {
    funName[i + 17] = funcName[i];
  }
  for (i = 0; i < 34; i++) {
    funName[(i + funcName.size(1)) + 17] = cv1[i];
  }
  if (1 > params.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, params.size(1), &emlrtBCI,
                                  (emlrtCTX)sp);
  }
  *sRough = params[0];
  //  Also make a commans string to change the Matlab Path to the location of
  //  the Matlab function
  pathCall.set_size(&c_emlrtRTEI, sp, 1, funcPath.size(1) + 6);
  pathCall[0] = 'c';
  pathCall[1] = 'd';
  pathCall[2] = ' ';
  pathCall[3] = '\'';
  loop_ub = funcPath.size(1);
  for (i = 0; i < loop_ub; i++) {
    pathCall[i + 4] = funcPath[i];
  }
  pathCall[funcPath.size(1) + 4] = '\'';
  pathCall[funcPath.size(1) + 5] = ';';
  //  If not compiled, excecute our custom function from Matlab
  covrtLogIf(&emlrtCoverageInstance, 0, 0, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 5);
  //  Matlab coder will compile from here
  //  Path to the engine 'h' files. This is always relative to the base
  //  Matlab path on any system
  //  Link path to the Matlab shared libraries. This will vary depending on
  //  the OS
  //  The libraries we need
  //  The source file including Path
  // source2 =
  // '/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabCallFun.h';
  // source1 = 'matlabCallFun.c';
  // source2 = 'matlabCallFun.h';
  // coder.cinclude(source2);
  // coder.updateBuildInfo('addSourceFiles',source2);
  // coder.updateBuildInfo('addIncludePaths',incPath2);
  // Need to reserve some meory for the referencenced variables
  b_params.set_size(&d_emlrtRTEI, sp, 1, params.size(1));
  loop_ub = params.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_params[i] = params[i];
  }
  i = params.size(1);
  if (params.size(1) > 32767) {
    i = 32767;
  }
  matlabCallFun(&b_params[0], static_cast<int16_T>(i), &funName[0],
                &pathCall[0], bulkIn, bulkOut, contrast, &outp[0], &nLayers);
  rowCount = 1U;
  colCount = 1;
  // reshape the output to [layers * 3] array
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 3, nLayers >= 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 6);
    i = static_cast<int32_T>(muDoubleScalarFloor(nLayers));
    if (nLayers != i) {
      emlrtIntegerCheckR2012b(nLayers, &emlrtDCI, (emlrtCTX)sp);
    }
    loop_ub = static_cast<int32_T>(nLayers);
    output.set_size(&f_emlrtRTEI, sp, loop_ub, 3);
    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(nLayers, &b_emlrtDCI, (emlrtCTX)sp);
    }
    loop_ub *= 3;
    for (i = 0; i < loop_ub; i++) {
      output[i] = 0.0;
    }
    real_T d;
    d = nLayers * 3.0;
    i = static_cast<int32_T>(d);
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, d, mxDOUBLE_CLASS,
                                  static_cast<int32_T>(d), &emlrtRTEI,
                                  (emlrtCTX)sp);
    for (loop_ub = 0; loop_ub < i; loop_ub++) {
      covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 7);
      if ((static_cast<int32_T>(loop_ub + 1U) < 1) ||
          (static_cast<int32_T>(loop_ub + 1U) > 300)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(loop_ub + 1U), 1,
                                      300, &b_emlrtBCI, (emlrtCTX)sp);
      }
      if ((static_cast<int32_T>(rowCount) < 1) ||
          (static_cast<int32_T>(rowCount) > output.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(rowCount), 1,
                                      output.size(0), &c_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (colCount > 3) {
        emlrtDynamicBoundsCheckR2012b(4, 1, 3, &d_emlrtBCI, (emlrtCTX)sp);
      }
      output[(static_cast<int32_T>(rowCount) +
              output.size(0) * (colCount - 1)) -
             1] = outp[loop_ub];
      // Make use of Matlab linear indexing.
      rowCount++;
      if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 4,
                     rowCount == static_cast<uint32_T>(nLayers) + 1U)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0, 8);
        rowCount = 1U;
        colCount++;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 0);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 9);
    output.set_size(&e_emlrtRTEI, sp, 1, 3);
    output[0] = 1.0;
    output[1] = 1.0;
    output[2] = 1.0;
    *sRough = 1.0;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (matlabEngineCaller_customLayers.cpp)
