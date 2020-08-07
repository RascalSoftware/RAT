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
    "789ce553cb4ec240149d1a346e505cf815240ca28971590123b1a0810689c4e8d05e69e33cccb4c5b2f213f433fc1437fe936da158884d0946369e64727b7a33"
    "73ce3d93414aa3a920847682f5f982d0db168a909f145498d60d348fc5be9252636ca2dcdc3e65aaf73ae586e02ef8ee8470c260b6d314cce684bbfaf8099004",
    "47d0119851e7c1a6a0db0c3a49d20a193b4bb466246c85df550b8cc78ec790b49c6f873449a23c427ca4cc9b5b320f23258fc242bf5fbfc5966080897c068a6b"
    "c2f01870d7c16de21884d66084dbaa8e3b849b03e163465c4a06753eb4395409a5207ff87567788e2b9846c6209d129b9bcbffe55cfb1973c57d4398204b7670",
    "b992135aa2c087ae95f071bfa28f45a4f98811ebbdafa8179f7f9ea117f7fb0dad175ca9e7484c457081b8a9ea9a7a8adb9572a54cb02b040def11188d5631ca"
    "0917e3a0f024a812cbca697749df69ef328fb6a33adebbec85755d7a31fe8bdebade9bae756f4e98d993eaf5d1b17f70d865e5d645c2c755864e960f94c2fffa",
    "fc2fb04a80da", "" };

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
  return xResult;
}

/* End of code generation (_coder_matlabEngineCaller_customLayers_info.c) */
