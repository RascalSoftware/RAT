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
    "789ce553414ec240141d0c1a372a2e3c05098368625ca240241634d02091181dca171ae7cf90e954caca1318afe1115c7a248f202d140b4953a3918d2f99fcbe"
    "bccebcf7ffb42455ada50821db93f5fe44c8db0609b0352d2433ab6b6411cb7a2aa6865827e9857da999dfcb8c5b5268f0f494088630dfd993680b26b4391e02",
    "51e048fe08bd40b9b739983642334aea3ec34a449a135ff29f4f07603d345d246ae07c25e45112ccc3c7474cbfe96fcee339661e9925bd53bea1038940991a01"
    "a72569b908423bb4c11c8bf1123cd246d1a49aa93ee88a2b2c6d4be1504b224a419169ceba65d1b7059c32ce41dd5aaea3251a6c0ccaa11a47658fe190431d46",
    "496fe730d2bff7cbfef712fa0f754bf640e5ecc947a004e3390ea2af07911c773fccb18cb81c2142bfd71ffa85e79f25f8857aa76ab42757ef3a8a7239b9685a"
    "2b9a46f184360af9429e512d25ef4a8f02f260658339d16c38283a1d540e93e6b4f3cddc71ffef16d90cea78f7a2edd755f985f82f7eabfadf4ca3757d8cbdb6",
    "2a5e1d1e79fb072dccd7cf23392e137c92729018fed7e77f026de49274", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1744U, &nameCaptureInfo);
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
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExampleNew/matlabEngineCaller_cust"
    "omLayers.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738045.65688657411));
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
