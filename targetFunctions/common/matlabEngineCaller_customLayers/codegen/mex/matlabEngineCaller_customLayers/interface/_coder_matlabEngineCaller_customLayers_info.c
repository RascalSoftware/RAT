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
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737469.43648148153));
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
    "789cdd53db4ac340109d8ad707a520fe8320745b15d437e30dc554a4862a8a976d3ab6c19d5dd96cb43ef9237e801fe207f8e4b39f627a498d852545b00f0e2c"
    "bb8743e6cc1c4e207750ce01c05c7cde9f0116a7a053b3dd0bf2bd7b0c7ed6209fb3dc494dc0f88fef723dbd971ef69534d8325d2002894711d550c74072c27e",
    "9bbaa2407269bca77b048da1120f58ef30b781402f2074550aec0731a0bd14d5076daafdde6ea27f771211e866f83dae4803e8f9d3ae4fcbfee343faf36cf127"
    "3fc05fec5eb2a622645c3fa2603bca8f08a5095985873e173bf8c02a8ec70cd70d347b91f44da064c87c45a424236e04afedca466ce4361702f5b51f854691cb",
    "9f5087597c81fafbde58f6991c725f5b1e66603abdfd66a2d7b2f41bd6df058b5e7e80f7551d75218843a725170581b2619a00997b67cd3158b639924af45e7f"
    "a997f4dfcfd04bf88b03f72c8e56146a26541c2456763cd7d96295e56269bdc68c52a2a65a0c4974ce52c727b69418c5ba46156874f9d8bc7a9bff70469bc7ec",
    "1cfc17bd51fd6f9e5b3ddfa0fa99764e57d75aa5952a158f0e53731c67e864cd0116fcd7fdbf00304193ab",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1856U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_matlabEngineCaller_customLayers_info.c) */
