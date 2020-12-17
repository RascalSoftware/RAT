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
#include "emlrt.h"
#include "rt_nonfinite.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[9] = {
    "789ced5acb721241149d58312656a971a1e54e5cb8b02c6982155f559645862460022103c128a664061a68d20f320f4037ba72ab0b3fc265967e821fe2c2cf90"
    "9961788cd50566c898c0dc2ad27373983ef7dea6cf5c3a11e692a9394110ae765edf3e0ac2ef15c1b22bf6202c77c70bc2b0b9f1b9eeb8e4f21dbb28cc0fdd37",
    "d7e5fbd2f54b8ceab0addb0e9509ecdd5966045199eab9f70d28a85063b809cb16524118e61081d941276d7a646300ea3926645e8b35583acc1a44506b5a3f42"
    "3ce858f530ed0727dff931ebf18a538f65175e486eef8b07c0d054805949c62015cb6dc7d680148d442332d019c30a6b03ad26abb00c4aac0cd5ee4f8c1470df",
    "bebc8f3a455469e76e4d5711ad86492f8f4f1ef3088dc8c3c1ad40c204b5110d3bd184b30dc62a126c305577e2297a8ce712371e1b31e821652ddacbffa7473e"
    "85cb378c1792135846ab7c03ab3950bfce925a36aa8ed7c6cccb3df6dfbf688db7de7d7eeb279f63b3c2d7e6cc37eee7f226876fd985afa7e3c9d456bb113136",
    "579ad57cbc79f426aa6cf6e3c88ce0191587c0f1fd9abfc8b97f541dddc6aba39befd309f99cf96f8fe073705b4f7b4a9ad4b2881818d1c3aca5f0ff2d7fafcf"
    "4569049f838ff95c84045bafbf1e84ee82f9ad9f0bbfea053ff91c9b153ebff4f3657e2dd6cc25f5971f92f5d846a3bab5baabef26a6473f8f39f78f5bc71dce",
    "fccb2ebcb07e006a8c4020ab2d88419c950c02a9ae0149d63adb3b0e9b408ae54056a665735fb3922e37a128630cd57714b6a243bf19e86fbd7e0e6e8c88dfc1"
    "5d7a6cf7d982f7e7d049fbda69f97e52e4c43929dd7871fdd98139ce8a2efacde7970ee72bb13d63b5c1b6a526496c18baf250d97915e8f099d1e1a2c7f817b8",
    "f1db8823b893e29b77f97d3e1b297504cd1c1dbeaf1ef9ee71f986f1c2beb87660271b425a480e2906c2fa03444304ea3556ee2ba86db3a233d3cee7978eeebd"
    "49e71f6d66e3f574e268af5e7d9f911f664a53741e70d6f7e979ef57dde6d7b941d0af9e0e9f63b3c217f4ab93997fdaf7f3b8792cbafc7e1e368234ad21ab1a",
    "fc5f7deb778f7c092edf306eaed3fa78e7b5e6c21059c7b202ccda540c0a9c2a85895fba10bddb08febe758a7c7ee9ec91c8a4cc2325223d49a4a472a4967f6c"
    "e05c3cd0d9b3a6b341dffb6f7c676dfd8a9c3883bef77cf0057def64e6f7faff44d0e50baef739f898fdd4bfeee73b94a944c6e80314ed4671527de9456e5e36",
    "823495b526c8e7771f2c72f986f193f5c110772e8055a3ee89915f3a71f9f879d0079f229f5f7dcf5e6555a15b226bed6758eaa8f6784513eb9a303dba3b6dfb"
    "7772e70b1d6615b5cfabae6e70f986716feb62d7c85c1abf746029d0d553e5f3ab9f6d579beb99d7af332d5153f2098511f85449af9d7f5dfd03c962ee98",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 12800U, &nameCaptureInfo);
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
    "/home/arwel/Documents/RascalDev/RAT/Sandbox/octaveCaller_new2/octaveCaller.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738098.6285069444));
  xResult = emlrtCreateStructMatrix(1, 1, 4, propFieldName);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.8.0.1380330 (R2020a) Update 2"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_octaveCaller_info.c) */
