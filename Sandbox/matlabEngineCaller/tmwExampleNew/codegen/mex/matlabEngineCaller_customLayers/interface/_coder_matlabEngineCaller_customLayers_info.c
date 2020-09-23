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
    "789ce553cb4ec240149d1a346e505cf815240ca289718980d158d0408344627468afd0380f9c4ea1ac4cfc017fc1a59fe4e7480bc5426c4a30b2f12493db93d3"
    "9973ef990cd22eaa1a426867bc5e5f107adf4201d2938232d3ba81e6b1a86b3135c4264acdedd3a67e6f536e0aaec05313c20983d94e4b309b13ae8c511f9004",
    "47d0015881f26853306c068d28a9f98c9d45a419f125ffbbd403f3a9e132247bce7787344a823c7c7cc6cc9b5a328fe7983c320b7abb72877b82012672081497"
    "85e932e0cac175e29884966180eb45033708b73ac2c38c284a3a15deb5399408a520b162c38a47589f420d863ffc706fba8e124c2723904e8e2dcce9fd72cefd",
    "843943dd1416c89c3dbe6cc909cd51e05dd58bf4f1b0621f8b88eb2344e8f7b1a25f78fe79825fa8b72ff4d6f88a5d47622ac6178aab45432f9ee27a215fc813"
    "ac84a0febd02a3c1ca0639e16c18149e0495634939ed2ed977dc3b4da3eda08ef6ae5a7e5d975f88ffe2b7aef766e8cddb1366b564f1e6e8d83b386cb27ced32",
    "d2c775824f521f2886fff5f95f6c9585fd", "" };

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
                (738045.661261574));
  xResult = emlrtCreateStructMatrix(1, 1, 4, propFieldName);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.8.0.1380330 (R2020a) Update 2"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_matlabEngineCaller_customLayers_info.c) */
