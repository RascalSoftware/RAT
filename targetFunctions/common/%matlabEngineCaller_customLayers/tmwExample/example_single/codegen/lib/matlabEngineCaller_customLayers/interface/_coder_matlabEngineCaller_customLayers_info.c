/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_matlabEngineCaller_customLayers_info.c
 *
 * Code generation for function 'matlabEngineCaller_customLayers'
 *
 */

/* Include files */
#include "_coder_matlabEngineCaller_customLayers_info.h"

/* Function Definitions */
const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[5] = {
    "789cc552cb4a4331104da58a2e1437fa0d82d0a982a2cbda072dd6456b0b3e1049d3b10de6a1496e5b77fe814bf1afdcf81f7e82b9f7b6359462d18d03c3dc73"
    "277366ce2424533b23de36bc5f640959f171d5fb12496d798c3381a7ffb3647d8c5fbc33ad1c8e5c9a5454229958574baea872ada7072406ad1603ec26993b2e",
    "b0c525d67500aadc035909525310a7e2ef621fd9fd792489e9db691b224290e87927df7ab273f4bc057a36c7f8ba7c037d2d11a819a28092669144e52c34a965"
    "54947000cd420b1c353d74954831c7b5b2c0b4945a81a44ed04e59f5b8c2221502cd2d8bacd3b24e9fd0587072581e51f92010308db796ab9e870b2a7332d055",
    "5da06b6b46d756723f5d3439ee2fc9282a720255cff5c77cf91ff82616f24de6182d98a33a5317e3eb5afdc2af38b20684f60b85b342ab5e3881e67e7eefb003"
    "4e6bd1d123402912df4de686ddc9e0900e9e9371ffa3a0ffca9cfee17b5d9bea797efd3cfd28fcbdfe5bff7fd72f7a07db33fb8f312bb2ab6ea3d8a8b52ff963",
    "c90d8edb0727ed4acab713f065e6f09120fef6fc17354594f0", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1128U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[4] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 4, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(xEntryPoints, 0, "Name", mxCreateString(
    "matlabEngineCaller_customLayers"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", mxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", mxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", mxCreateString("9.1.0.441655 (R2016b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_matlabEngineCaller_customLayers_info.c) */
