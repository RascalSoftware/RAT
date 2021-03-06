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
    "789ce553dd4ec230182d068d37285ef8142414d1c47889fc44e240030b1289d1b27dc2627fb4eb705cf108be068fe5a3b80d06836419c1c88d2769be9e9cb4e7"
    "fb4e5394aa375208a1236f7d4c109a1ea000995941d979dd43ab58d7533135c43e4aaf9c4bcdfdbee6dc105c81ab668413068b93a66016275ce9e37740126c41",
    "476006caab4541b718b4a3a4e933568b480be24bfebe3c04e3aded302487f6b2431a25411e3ebe63e64d6f98c724268fec9adeab3ee1a1608089fc048a2bc270"
    "187065e316b10d422b30c2ad928e1591035035871bca12dcc686604c70cc88a2a45fe5038b4399500af2d9706c259846c620ed243dcf16f3babf9cf73461de50",
    "378409326f798f2e39a1790a7ca0866899fbcb967dac23ae8f10a1df744bbff0fe9b04bf50efd5b5aef7d48e2d3115dec3e24649d74ad7b8552c140b042b2168"
    "5fb818180d562ec809e7c2a0f02ca83c4bcae978c3bee3fe6b061d06757c72d7f5ebaefc42fc17bf5dfd375deb3c5e31b32b4b0f1797eed97987159ab7913eee",
    "137c92fa4031fcafefff013ae58c1d", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1728U, &nameCaptureInfo);
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
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737995.439849537));
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
