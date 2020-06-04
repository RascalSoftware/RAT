/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_standard_layers_mod_info.c
 *
 * Code generation for function 'standard_layers_mod'
 *
 */

/* Include files */
#include "_coder_standard_layers_mod_info.h"

/* Function Definitions */
const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[6] = {
    "789ce555dd6ed330147661ab0009849040425c708b34a9ee10abd2cba45d944047f7d34a7413aa9cc46b2cfcd325ced8eefa0670072fc51dbc03973c024e938e"
    "609505baaa42da918e9ccfce77f29d639f1854dc1da0ec9ef2ef7700a8aaf196f21b20b3f51c5794dfccc76c7e0ddccdf107e5bee0129fc96c912386c1cc02c1",
    "08475cf6cec718443816f41407d3956342718f30dc1105e01005985d58ba00e952fadc0ab1ffee2061200ae38bcf005a04d37c3e835ff9accdc90715f2b99fe3"
    "a3edb7b01fe32886287a8f69988c421c435f04848fe0bed9831245232ced84fb92089e2e3126388c25e2018a822145e78a3d642298375763057d4689be754d5f",
    "8a49ac6af997fcaac6af4e7723f128cef89312fe4b8d9fe223b7f34695c81c8f29f15156821db3d731ade1fef3fa66c3aba1f1184a21a827ce20661452e24186"
    "24451ec4543dc0690ab342e87954e7e8a81474dccee7953db11f7f33afc0bfeaf797c677c0e5fbf008fcbe0f293e666ec36a360c193a875b75143ac641d4b5b3",
    "78cf0af12a73e281c2b8c8fb9312bdab3a37bb253a9e6a3a52ac3a194735a27e561147b446622b2154bafc75c27044fca5f4d5c712fe40e30f16aa4fea1bd374"
    "e0c62c1fa8e7f3c7ffcd3f9c53e3c197afd7b6cfda946c22a33db25f78cdc408ba9c35ac5d67357df6bfdf5f65f57ca8e94bb1d67f14f3910cf378f54be2cdac",
    "186fa66352a2a3abf152bca47ecbf4abaa2c7e3e279f7ebcbabef798dff20f83bdd69edb1f9093b63c6df6b7acfe0aeeb19fd8042ecf",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 2808U, &nameCaptureInfo);
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
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 0, "Name", mxCreateString("standard_layers_mod"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", mxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", mxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", mxCreateString("9.1.0.441655 (R2016b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_standard_layers_mod_info.c) */
