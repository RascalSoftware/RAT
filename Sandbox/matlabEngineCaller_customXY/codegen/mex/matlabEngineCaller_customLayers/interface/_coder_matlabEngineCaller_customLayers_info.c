/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_matlabEngineCaller_customLayers_info.c
 *
 * Code generation for function '_coder_matlabEngineCaller_customLayers_info'
 *
 */

/* Include files */
#include "_coder_matlabEngineCaller_customLayers_info.h"
#include "covrt.h"
#include "emlrt.h"
#include "matlabEngineCaller_customLayers_data.h"
#include "rt_nonfinite.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[5] = {
    "789ce553cb4ec240149d1a346e505cf815240ca28971590123b1a08106abc4e8d05e69e33cccb46059f9096efd043fc7851f645b281692a604231b4f32b93d39"
    "e99c73efcd20a5d15410423bc1f97a45e87d0b45c84f0a2a4ceb069ac7a2aea4d4189b2837f79f32f57b9b7253700f7c6f42386130fbd312cce1847bfaf81990",
    "0457d0115891f2e850d01d069d2469858c9d25a41909a5f0bb6a83f9d41932246df727214d92681e213e53facd2d390f9a328fc282deabdf615b30c044be00c5"
    "35610e1970cfc56de29a84d66084dbaa8e3b845b7de163463c4afa753e70385409a520efcda1eb0966dca46b1a1983744b2cd99fffcbfef633fa8b755358204b",
    "4eb064c9092d51e003cf4ee4785831c722d272c488fd3e56f48bef3fcff08bf55e433382d50e5d89a90816899baaaea9a7b85d2957ca047b42d0709fc068748a"
    "d19c70311e149e0caac4b2e6b4bb64eeb4f79947db511def5d1a615d975f8cffe2b7aef7a66bdddb13661952bd3e3af60f0ebbacdcba48e4b8caf0c9ca8152f8",
    "5fdfff0dbb9d84b5", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1712U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * epFieldName[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  mxArray *xInputs;
  const char * propFieldName[4] = { "Version", "ResolvedFunctions",
    "EntryPoints", "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, epFieldName);
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString(
    "matlabEngineCaller_customLayers"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller_customXY/matlabEngineCaller_customLayers.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738042.62636574078));
  xResult = emlrtCreateStructMatrix(1, 1, 4, propFieldName);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.8.0.1380330 (R2020a) Update 2"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "CoverageInfo", covrtSerializeInstanceData
                (&emlrtCoverageInstance));
  return xResult;
}

/* End of code generation (_coder_matlabEngineCaller_customLayers_info.c) */
