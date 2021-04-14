/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_matlabEngineCaller_customXY_info.c
 *
 * Code generation for function '_coder_matlabEngineCaller_customXY_info'
 *
 */

/* Include files */
#include "_coder_matlabEngineCaller_customXY_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[5] = {
    "789ce553d14ec230142d068d2f283ef8152414d1c4f88880910868604194182ddb15167b5bb215184f26fe80af7e829fe327b90d8683b88c60f4c59334772767"
    "edb9f73425894a2d4108d971d7cb33216f5bc4476a5a487a5637c82296f544440db049920bfb1233bfd719d7a550e0a829110c61bed390680a2694361900b1c0",
    "967c0486af3c9a1c3413a11926758fe159489a134ff2be8b7dd09f9a432456dffeea9087899f87878f8879932be6811179a497f44ef98ef6250265d618382d49"
    "7d8820944d1bccd6192fc188360a1a6d326174a5439129ceba65d133051419e7605185e3b2c370c0a10ee36f7eb8d787b692d8bec962683ee787f3edc7cc17e8",
    "ba34c0ca9aee255b82f12c07d153fd501f0f6bf6b18ca83e02047eef6bfa05e79fc7f8057aa7526dbb573bb42dcaa57b91b456d0aa8553dac8e7f239469594dc"
    "bb4f40eeaf8c9f13cd0441d16950598ccb6977c5bea3de678a6cfb75b277d9f6ea5ff905f82f7e7ff5deb46aebf6048db655b83e3a760e0e5b98ab5f84fab88a",
    "f189eb8344f0df3eff13fb648426", "" };

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
    "matlabEngineCaller_customXY"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew/matlabEngineCaller_customXY.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738057.38450231485));
  xResult = emlrtCreateStructMatrix(1, 1, 4, propFieldName);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.8.0.1380330 (R2020a) Update 2"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_matlabEngineCaller_customXY_info.c) */
