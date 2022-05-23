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
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[5] = {
    "789ce553cb4ec240149d1a346e505cf815240ca28971590123b1a0810689c4e8d05e69e33cccb4c5b2327e817e869fe267d9168a85d8946064e34926b7a73733"
    "e7dc3319a4349a0a42682758af2f08bd6fa108f949418569dd40f358ec2b2935c626cacded53a67a6f536e08ee82ef4e08270c663b4dc16c4eb8ab8f9f004970",
    "041d8119751e6c0abacda09324ad90b1b3446b46c256f85db5c078ec780c49cbf976489324ca23c467cabcb925f33052f2282cf4fbf55b6c090698c867a0b826"
    "0c8f01771ddc268e41680d46b8adeab843b839103e66c4a56450e7439b4395500af2875f7786e7b88269640cd229b1b9b9fc5fceb59f3157dc378409b2640797",
    "2b39a1250a7ce85a091ff72bfa58449a8f18b1dec78a7af1f9e7197a71bfdfd07ac1957a8ec4540417889baaaea9a7b85d2957ca04bb42d0f01e81d16815a39c"
    "70310e0a4f822ab1ac9c7697f49df62ef3683baae3bdcb5e58d7a517e3bfe8adebbde95af7e684993da95e1f1dfb07875d566e5d247c5c65e864f94029fcafcf",
    "ff02e4ae8042", "" };

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
