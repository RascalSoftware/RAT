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
#include "emlrt.h"
#include "rt_nonfinite.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[5] = {
    "789ce553cb4ec240149d1a346e505cf8052e4d3a8826c665058c4440030d1289d1a1bd42e33c703a4059f909fe824b3fc9cf91168a85d8946064e34926b727a7"
    "33e7de3319a4952a1a426867bc0e5e117adf4201d2938232d3ba81e6b1a86b3135c4264acdedd3a67e6f536e09aec05313c20983d94e5b308713aecc510f9004",
    "57d001d881f2e450301d06f528a9fa8c5d44a419f125ff3bdf05ebb9de674876ddef0e69940479f8f88c9937b5641e2f31796416f456f11e7705034ce410282e"
    "08abcf802b17d7886b115a8001ae1926ae136eb78587195194b48bbce370c8134a4162c586458fb01e852a0c7ff8e1c1eabb4ab03219817475b630a7f7cb39f7",
    "13e60c754bd82075677cd99213aa53e01dd58df4f1b8621f8b88eb2344e8f7b1a25f78fe65825fa8b74ae5e6f88afbaec4548c2f14570cb36c9ce35a2e9bcb12"
    "ac84a0febd02a3c13a0c72c2876150781294ce9272da5db2efb8779a46db411ded5d37fdba2ebf10ffc56f5defcd2c37eece98dd94c6edc9a97774dc60d9ea55",
    "a48f9b049fa43e500cffebf3bf00a232853f", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1720U, &nameCaptureInfo);
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
    "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew/matlabEngineCaller_customLayers.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738057.402337963));
  xResult = emlrtCreateStructMatrix(1, 1, 4, propFieldName);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.8.0.1380330 (R2020a) Update 2"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_matlabEngineCaller_customLayers_info.c) */
