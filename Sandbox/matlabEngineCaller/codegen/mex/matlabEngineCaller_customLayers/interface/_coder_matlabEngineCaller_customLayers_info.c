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
#include "rt_nonfinite.h"
#include "matlabEngineCaller_customLayers.h"
#include "_coder_matlabEngineCaller_customLayers_info.h"
#include "matlabEngineCaller_customLayers_data.h"

/* Function Definitions */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString(
    "matlabEngineCaller_customLayers"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/matlabEngineCaller_customLayers.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737468.6921527778));
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.6.0.1072779 (R2019a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "CoverageInfo", covrtSerializeInstanceData
                (&emlrtCoverageInstance));
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[5] = {
    "789cc5535b4ec240141d0cbe3e3424c6559830a026863f2a60201662a04122f131b457689c8799b6083faec405b8103f5c81cb31b68562214e4a4cc49b34d3d3"
    "93de73efe9294ad5ea2984d0ae7f7d3e2394d94461ed4c0e94999e6b68be16f994e28c6a1da5e7de4b4df55ea6d814dc85913b01d4e6d0f0580fa40f3861306b",
    "63096673c25d63fc08488223e810ac90b9b7291836035dc440d5f6013b8b51331050c17d6900e643cb63480e9cef71691ca0a93f41bd2bf64f2fe98fa9f027b3"
    "c0772bd778201860229f80e2b2303d06dc7570933826a16518e2a666e016e1564f8c30232e25bd0aeffbce9508a5207f78746b7a8e2b984ec6209d2c9bdbeb4e",
    "31f7c6927ba9befb36da8a6f598cf4468a7ecbfab8afd0cb2cf0a6b040666d3f5c92139aa5c0fbee0025ef9d34c762a9e6882ad27bfda55ed4bf9aa017f1dd9a"
    "def123e4391253e10706d73543d74e71f330972f10ec0a4183dc00a3e17510fa840f22a3f0c4a82c5b5d3e8a376f7b1fda6af3b8eafcff9fdeaafe37436f5f15",
    "98d591dae5f1c9287fd466b9c6796c8e8b049da4399002ff75ff2fbaf1880a", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1832U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_matlabEngineCaller_customLayers_info.c) */
