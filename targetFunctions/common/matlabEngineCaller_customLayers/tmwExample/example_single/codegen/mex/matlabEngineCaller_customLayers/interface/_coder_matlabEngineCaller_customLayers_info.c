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
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
    "eCaller_customLayers.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737468.6315509259));
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.5.0.1033004 (R2018b) Update 2"));
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
    "789cc5536d4ac34010dd8a9f3f9482780aa1e317a8ff8cda52318ad4a0a2f8b14dc736b8b32bbb1b8dbf3c8027103c8007f10c9ec7d8361a032145b00e2c9bc7"
    "63e7cd3c5e586967afc4189b89cfd32363f509d6ade9dec5cafd7b84fdac2c5fcab9931a63a33fde95fa7a2f7dec2b6931b23d200289fb213551c74072c2af36",
    "2d4581e4d27a0fb7c8341a25eeb0d565ae03815e40e8aa14a80731a05a8afa029fd4e7f75607fd9bc39098ee98ef71451ab0be3fe9c5b2fb8f0ee8cf738e3fe5"
    "0c7f563d878e2204aeef51c0b6f24342690d34b8f1b9d8c63b68381e58aedb686ba1f46da0a4015f112909c4ade0cdaa6cc7466e7121505ffaa1b18a5cfe80da",
    "80a5fb6ac4e9562060efbe34816cc7b0e06585327e5ce5ec3b3ea01f797999629369773612bd28a7dfa0fecfe5e89533bcaf5aa82b411c4a2db9a808946ddb61"
    "c57b17cd91adbc39924af45e7fa997f4af17e825fcd98e7b12472f341a848a83067b8ee73a9bd0585a585c6b82554a34550448a27be6bb3ec17c6214f48caad0",
    "f0f2b171f136fbee0c378fc3ceffffe90deb7ff3dca3d3756a9d68e77865355a5c3ea285fdddd41c07053a4573b01cfcd7fd3f0010a09ce5",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1888U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_matlabEngineCaller_customLayers_info.c) */
