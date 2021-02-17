/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_octaveCaller_info.c
 *
 * Code generation for function '_coder_octaveCaller_info'
 *
 */

/* Include files */
#include "_coder_octaveCaller_info.h"
#include "covrt.h"
#include "emlrt.h"
#include "octaveCaller_data.h"
#include "rt_nonfinite.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[10] = {
    "789ced5a4b73125914ee5851e3548dc685963b71318b294b2e62c557d5d41469928009880dc128a6a41b2e70c97d907e00ba1957b3d59fe1d2c52c6639cbf921"
    "fe10fb41f368eb166dbad326d0a78adc3ef9e8fb9d732ef7ebc34d84957c61451084abe6eb9fbf04612d2dd8f6ab3308eba3f182306b5e7c65345ef1f8ae5d14",
    "5667ee5b19f17d1cf90d467538d41d87ca048eef6c3282a84cf5cabb1e1454a831dc874d1b69210c2b88c0f2b453b43cb23d058d1d0bb2aec50e6c1c950d22a8"
    "1d6d12219e76ec7a58f62f27df559ff578c9a9c7ba07afe5f70ec44360682ac0ac216350c854f6329b404aa7d22919e88c61850d81d69155d8040dd684eae827",
    "460ab8eb5cde456611556adeade92aa2ed2419e7f121601e893979b8b81d4892a021a249379a64b9c7584b823da6ea6e3cf580f15ce6c6e320063da26c40c7f9"
    "ff1f904fe1f2cde2b57c08cb68976f6a35a7ea672ea96df3ea78cd675ede71f2fe357bbcf5f6ef3751f2b9b62c7c43ce7c7e3f9737397ceb1e7cab98cd177687",
    "bd94b173bfdfae66fbc7afd3cace248ed21c9e7971081c3faaf9eb9cfbe7d5d16bbc3a7af93e9c90cf9dfff61c3e1777f474aca479ad8c8881113d2adb0affd3"
    "f20ffa5c94e6f0b9b8cfe72224d87e7df720f4162c6afdbcf4b55b8b92cfb565e18b4a3f9f553733fd4a5e7ff63edfcd6cf7dabb1b2ff417b9c5d1cfff38f7fb",
    "ad638d33ffba07af6d1d820e2310c8ea006290650d8340aa6b409235737b67611f48990a28cbb469ed6bd6d0e53e14658ccd5d3dedbca57030f38bd1c60eeb73"
    "71634e3e2eeed167a7ef16823f974edae72ecaf7953a27ceb074e4cfeb4f0fad715974326abea874b9dacaec1b1b3db627f5496edbd09507caf397b12e9f595d",
    "ae07cce712371f077105382cbe558f3fe17390862970d6e8f27d0ac8f73b976f16af1d889b874eb209a425e4846220acdf433441a0de61cd89a23ab62cbab3e8"
    "7c51e9eafeeb62f5e14e39db2de68ef7bbed7725f941a9b140e705677d9f9ef7fed56b519d2bc4fdebe9f0b9b62c7c71ff1acefc8bbe9ffde6b1e6f127793808",
    "d2b49eac6af067f5ad9f03f2e5b87cb3b8b54e5bfece73ad8521b28e650558b5691914b8554a92a87421fd5b2ffefbd729f245a5b3c722934a0f9594f4385790"
    "9aa94ef591812bd95867cf9acec67def8ff19db5f5ab73e28cfbdef3c117f7bde1cc1ff4ff8da0c7173cef73719ffdd48feee73b94a944c6e83d149d4631acbe",
    "f422372f07419aca0621f245dd078b5cbe59fc647d30c4e605b06be4f35c3d2c9df8e5cb1f711f7c8a7c51f53dfbad0d85ee8a6c70506285e3cea3fb9ad8d584"
    "c5d1dd45dbbfe19d2f98cc2a1a9e575ddde6f2cde2c1d6c5a991b53451e9c09558574f952faa7e76d8ee6f955ebd2a0d444da9e61446e013a5b879fe75f51b73",
    "95f7ed", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 12832U, &nameCaptureInfo);
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
  xInputs = emlrtCreateLogicalMatrix(1, 0);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("octaveCaller"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(0.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (0.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/arwel/Documents/RascalDev/RAT/Sandbox/octaveCaller/octaveCaller_new/octaveCaller.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738098.48413194448));
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

/* End of code generation (_coder_octaveCaller_info.c) */
