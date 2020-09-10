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
    "789ce553cb4ec240149d1a346e505cf815240ca28971590123b1a0810689c4e8d05e69e33cccb4c5b2f213f433fc14fd2bdb42b1109b128c6c3cc9e4f6f466e6"
    "9c7b26839446534108ed04ebf305a1b72d14213f29a830ad1b681e8b7d25a5c6d844b9b97dca54ef75ca0dc15df0dd09e184c16ca72998cd0977f5f11320098e",
    "a02330a3ce834d41b7197492a41532769668cd48d80abfab16188f1d8f216939df0e6992447984f8489937b7641e464a1e85857ebf7e8b2dc10013f90c14d784"
    "e131e0ae83dbc43108adc108b7551d77083707c2c78cb8940cea7c6873a8124a41fef0ebcef01c57308d8c413a25363797ffcbb9f633e68afb86304196ece072",
    "2527b444810f5d2be1e37e451f8b48f31123d67b5f512f3eff3c432feef71b5a2fb852cf91988ae0027153d535f514b72be54a996057081ade23301aad629413"
    "2ec641e14950259695d3ee92bed3de651e6d4775bc77d90bebbaf462fc17bd75bd375debde9c30b327d5eba363ffe0b0cbcaad8b848fab0c9d2c1f2885fff5f9",
    "5f7d2a80d2", "" };

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
