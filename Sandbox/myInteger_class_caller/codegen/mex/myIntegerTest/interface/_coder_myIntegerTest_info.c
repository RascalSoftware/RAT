/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_myIntegerTest_info.c
 *
 * Code generation for function '_coder_myIntegerTest_info'
 *
 */

/* Include files */
#include "_coder_myIntegerTest_info.h"
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
    "789ced5a4b73da5614963b4e9a74a6adbb4826bb9045179d4cb9d819e735d3e960611b62438978c409f118092e70f17d605d097036cdaadbf66764994517fd09"
    "fd21fd115d560fc4439d3b104b566cd099c157c79f74bf73cee57e3a08a4b55c7e4d92a46facd79fbf4ad2bf9b92635fbb83b4311abf9066cd8faf8dc6db3edf",
    "b31bd2facc756b23bedf477e8351030e0dd7a12a81e32b9b8c20aa52a37cde83920e39c37dd8749016c2b08c082c4d3b05db237b53d0d8b121fb58eec0c669c9"
    "2492dee19308f1b4e3d4c3b6bf04f9ae2f588f57827a6cf8f05aeef0483e0626d701660d15837cba7c98de01ca566a2ba5028331acb121e01d55874dd0604da8",
    "8ffe62a48187eee143641551a7d6d5dcd0116d27c9388ff701f348ccc9c3c39d4092040d114d7ad1244b3dc65a0aec31ddf0e2a9078ce74b613c2e62d253ca06"
    "749cffdf01f93421df2c5ecb85b08c4ef9a65673aa7ed6923a36af8edf2e98977f9c9c7fcb19ef9dfcf6364a3ecf56856f28986fd1f7e55d01df860fdf2d6472",
    "f983612f65ee6ff6dbd54cffeccd96b63f89a33887675e1c92c08f6afebae0fa7975f49ba88e7ebef717e4f3e6bf3f87cfc35d3d1d2b698e97103131a2a72547"
    "e13f5bfe41ef8bca1c3e0f5ff0be0809765effbb11fa0b16b57edefca75b8b92cfb355e18b4a3f5f5477d2fd72ce78f12ed74deff5da07db2f8d97d9e5d1cfa0",
    "fbb922987fc387d7768f41871108547d0031c8b0864920353850546e6def0cec03255d06259536ed7d4dce73d64e6e43fda48155ce4fac53b0b5bfc7ff2e43ee"
    "b64461bd1feeccc9c3c37dbaecf6db52f0fbd145fbdb65f99c5217c419967efcfcddf3637b5c157d8c9a2f2a3daeb6d21573bbc70e953ec9ee9986f648fbe555",
    "acc7574e8feb01f3b829ccc3453ce10d8b6fdde74ff85ca461099b3d7a7c7f04e4fb41c8378bd78ee49d6337d904e20935a199081b3f229a20d0e8b0e644495d"
    "5b15bd5976bea8f4b4f2a6507dbc5fca740bd9b34ab77d5e541f151b4bf47ce0aaefd3ebdeb7fa2daae70871df7a397c9ead0a5fdcb78633ffb2efe745f3b8e5",
    "f32779b808e2bca7ea1c7eaebef54340beac906f16b7d76977b1e7b7f6c210d5c0aa06ecdab44c0abc2a254954bab0f57d2ffebeeb12f9a2d2d9339929c5c75a"
    "4a799acd2bcd54a7fac4c4e54cacb3574d67e3bef7d3f8aedafad50571c67deff5e08bfbde70e60ffafb22e8f325df791ebe603ff5a9fbf901653a51317a0765",
    "b7510cab2fbd21cccb4510d7d92044bea8fb6059c8378b5fac0f86d83a004e8d464f8ca2d289af3efe14f7c197c81755df53696d6bf4406683a322cb9f759e6c"
    "72b9cba5e5d1dd65dbbfe13d5fb0987534bcaebaba27e49bc583ad8b5b237b69a2d281dbb1ae5e2a5f54fdecb0dddf2dbe7e5d1cc85cab663546e033adb073fd",
    "75f53fd0f5f4a4", "" };

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
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("myIntegerTest"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/arwel/Documents/RascalDev/RAT/Sandbox/myInteger_class_caller/myIntegerTest.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738144.44097222225));
  xResult = emlrtCreateStructMatrix(1, 1, 4, propFieldName);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.8.0.1380330 (R2020a) Update 2"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_myIntegerTest_info.c) */
