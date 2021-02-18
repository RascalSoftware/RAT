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
    "789ce553cb4ec240149d1a346e505cf815240ca28971590123b1a0810689c4e8d05e69e33cccb4c5b272e7563fc34ff1b36c0bc5426c4a30b2f12493dbd39b99"
    "73ee990c521a4d0521b413acd71784deb75084fca4a0c2b46ea0792cf695941a6313e5e6f62953bdb729370477c17727841306b39da6603627dcd5c74f802438",
    "828ec08c3a0f3605dd66d0499256c8d859a23523612bfcae5a603c763c86a4e57c3ba44912e511e23365dedc92791829791416fafdfa2db604034ce433505c13"
    "86c780bb0e6e13c720b40623dc5675dc21dc1c081f33e25232a8f3a1cda14a2805f9c3af3bc3735cc1343206e994d8dc5cfe2fe7dacf982bee1bc20459b283cb",
    "959cd012053e74ad848ffb157d2c22cd478c58ef6345bdf8fcf30cbdb8df6f68bde04a3d47622a820bc44d55d7d453dcae942b65825d2168788fc068b48a514e"
    "b818078527419558564ebb4bfa4e7b9779b41dd5f1de652facebd28bf15ff4d6f5de74ad7b73c2cc9e54af8f8efd83c32e2bb72e123eae3274b27ca014fed7e7",
    "7f0124a5804c", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1704U, &nameCaptureInfo);
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
    "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/matlabEngineCaller_customLayers.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738010.63421296293));
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
