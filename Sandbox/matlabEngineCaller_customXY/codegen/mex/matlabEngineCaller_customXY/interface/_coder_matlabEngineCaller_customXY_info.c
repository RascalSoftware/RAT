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
#include "rt_nonfinite.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[5] = {
    "789ce5535b4ec240149d1a34fea0f8e12a48184413e367058c4440030d568991a1bdd2c679983eb07cb9045d864b7105aec7b63050482a04a33f9e64727b72d2"
    "39e7de9b414aada1208476c2f3f982d0db168a911d17949bd40d348f455d49a9129b2833f79f32f17b9d7043700f026f4c386130fdd314cce6847bdae8099003",
    "aea0433063e5c1a6a0d90cda49d28c183b4b48531249d177d902e3b1ed33e458ee2c214d92781e113e52facdac380f2b651eb905bd5bbdc396608089f30c1457"
    "84e133e09e8b5bc43508adc010b7540db70937fb22c08c7894f4ab7c607328134ac1b9377cd7134cbff94e2b30d957f0c3bef697f425754398e014ec70b90e27",
    "b440810fbca86799a3b7668e45a4e590907eef6bfac9fbcf97f849bd5babebe14a7dd7c154840bc40d55ababa7b8552a968a047b42d0688fc0687cf2f19c705e"
    "0e0a8f0735db572f25d7ee8ab9d3de65166dc775b477a947f5affc24fe8bdf5fbd37addeb93d61a6eea8d747c7c1c16187159b17891c574b7c96e54029fcb7ef",
    "ff02744882e2", "" };

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
    "matlabEngineCaller_customXY"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller_customXY/matlabEngineCaller_customXY.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738042.61982638889));
  xResult = emlrtCreateStructMatrix(1, 1, 4, propFieldName);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.8.0.1380330 (R2020a) Update 2"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_matlabEngineCaller_customXY_info.c) */
