/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_callOctave_main_info.c
 *
 * Code generation for function '_coder_callOctave_main_info'
 *
 */

/* Include files */
#include "_coder_callOctave_main_info.h"
#include "callOctave_main_data.h"
#include "covrt.h"
#include "emlrt.h"
#include "rt_nonfinite.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[10] = {
    "789ced5acb721a47141da564c74e551279e19477218b2c52aed048b6ec3855a9141a248125301e10962dab440f34d0a81f681e80bd8957d9269f91a5175ee413"
    "f221fe082f330f86c7b8bac01ad496606e15eab93a3373eebd4d9fb934282bb9fc8aa228df38af777f28ca8775c5b3affd41591b8c5f289316c65706e3cd901f",
    "d8356575e2ba9501df5f03bfc69985fa96ef3048d1f0ca3aa7984166955f7590622093932eaa7b48031354c61495c69d82ebd19d3168e8b8907bacb650edb464"
    "53c56899a308c9b8e3d5c3b57f05f9aece588f67827aac85f0a3dcfea17a0c6cd30084d72001f974793fbd05b48dd4460a028b73a2f33e305bd0407550e37564",
    "0cfe12ac83bbfee15dec14d160ced5a66560d64cd2611e6f22e691989247807b812429ee63960ca249963a9c3734d4e18615c4538d18cf97c2787cc466a78cf7"
    "d830ffff22f2e942be49fc28378769f4ca37369b63f573a6d4b36975fc76c6bcc2e3e8fc1bde78e7e4cf9732f9025b16bebee07eb3be2fbf13f0ad85f0ed4226",
    "97dfeb7752f6ee7ab759c974cf5e6ce8bba3388a5378a6c5a1087c59f7af0aae9f56c7b089ea18e67b734ebee0fedf4fe10b705f4f874a9a334b98da04b3d392"
    "a7f09f2dffa8cf456d0a5f80cff85c449478af8f1e84e182c9d6cfebefdb4732f9025b163e59faf9b8b295ee9673d6e3d7b9767aa7d3dcdb7c6a3dcd2e8e7e4a",
    "5bcfdbc7a0c52902d0e8210232bc6653c42c1368d0749677067581962e83126475775df39a05bb48858420e384a1de7de09c449e78ff3da1d0693243eb39eafb"
    "e1f6943c023ca4cb7ebfad447f1e9db7bf5d94cf2955419cf3d28fdf6ffd7aec8ecba28fb2f964e971a5913eb0373b7c5febd2ec8e6de9f7f427cf623dbe747a",
    "5c8d98c775611e3e1208efbcf85643fe88cf476a8eb0b963c0f77744be9f847c93f8d1a1ba75ec279bc0660226741b13eb67cc1214592d5e1f29a96fcba2378b"
    "ce274b4f0f5e142a0f764b9976217b76d06ebe2ac27bc5da02ed0f5cf6757ad5fbd6b0c9da4788fbd68be10b6c59f8e2be753ef75ff4f53c6b1e3742fe280f1f",
    "c1a6d98186893e57dffa4f44beac906f1277e7697bb6fd5b776228b408d4815b9b86cd4050a52495a50b1b3f76e2efbb2e904f96ce9ea95c2b3ed053da2fd9bc"
    "564fb52a0f6d52cec43a7bd97436ee7b3f8defb2cd5f551067dcf75e0dbeb8ef9dcffda3febe08857c25745e80cfd84f7dea7afe81718342825f23d56f14e7d5",
    "975e13e6e523d834786f8e7cb2fb6055c837899faf0f46c439005e8d063b46b274e2abb7bfc57df005f2c9ea7b0e1a9b3adb5379efb0c8f367ad87eba6da3695"
    "c5d1dd455bbff3db5f70980ddcbfaababa23e49bc4a3cd8b5f23776a64e9c0cd58572f944f563fdb6f76b78bcf9f177baaa957b23aa7e8915ed8bafabafa3f3e",
    "3ff162", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 12816U, &nameCaptureInfo);
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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("callOctave_main"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(0.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (0.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/arwel/Documents/RascalDev/RAT/Sandbox/octaveCaller_new4/callOctave_main.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738142.6681365741));
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

/* End of code generation (_coder_callOctave_main_info.c) */
