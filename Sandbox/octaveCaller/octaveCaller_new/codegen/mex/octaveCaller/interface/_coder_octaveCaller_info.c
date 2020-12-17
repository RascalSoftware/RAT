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
    "789ced5a4b73125914ee5851e3548dc685963b71318b294b2e62c557d5d41469928009880dc128a6a41b2e70c97d907e00ba1957b3d5853fc2e52c6739cbf921"
    "fe10fb41f368eb166dbad326d0a78adc3ef9e8fb9d732ef7ebc34d84957c61451084abe6ebf35f82b096166cfbd51984f5d1784198352fbe321aaf787cd72e0a",
    "ab33f7ad8cf83e8efc06a33a1cea8e436502c77736194154a67ae55d0f0a2ad418eec3a68db4108615446079da295a1ed99e82c68e0559d76207368eca0611d4"
    "8e3689104f3b763d2cfb9793efaacf7abce4d463dd83d7f27b07e22130341560d6903128642a7b994d20a553e9940c74c6b0c28640ebc82a6c82066b4275f413",
    "2305dc752eef22b3882a35efd67415d176928cf3f810308fc49c3c5cdc0e2449d010d1a41b4db2dc63ac25c11e5375379e7ac0782e73e37110831e5136a0e3fc"
    "ff0fc8a770f966f15a3e8465b4cb37b59a53f53397d4b67975bce6332fef3879ff9a3dde7afbf79b28f95c5b16be21673ebf9fcb9b1cbe750fbe55cce60bbbc3",
    "5ecad8b9df6f57b3fde3d76965671247690ecfbc38048e1fd5fc75cefdf3eae8355e1dbd7c1f4ec8e7ce7f7b0e9f8b3b7a3a56d2bc5646c4c0881e956d85ff69"
    "f9077d2e4a73f85cdce77311126cbfbe7b107a0b16b57e5efadaad45c9e7dab2f045a59fcfaa9b997e25af3f7b9fef66b67beddd8d17fa8bdce2e8e77f9cfbfd",
    "d6b1c6997fdd83d7b60e4187110864750031c8b2864120d53520c99ab9bdb3b00fa44c059465dab4f6356be8721f8a32c6e6ae9e76de523898f9c5686387f5b9"
    "b831271f17f7e8b3d3770bc19f4b27ed7317e5fb4a9d1367583af2e7f5a787d6b82c3a19355f54ba5c6d65f68d8d1edb93fa24b76de8ca03e5f9cb5897cfac2e",
    "d703e673899b8f83b8021c16dfaac79ff03948c314386b74f93e05e4fb9dcb378bd70ec4cd4327d904d21272423110d6ef219a2050efb0e644511d5b16dd5974"
    "bea87475ff75b1fa70a79ced1673c7fbddf6bb92fca0d458a0f382b3be4fcf7bffeab5a8ce15e2fef574f85c5b16beb87f0d67fe45dfcf7ef358f3f8933c1c04",
    "695a4f5635f8b3fad62f01f9725cbe59dc5aa72d7fe7b9d6c21059c7b202acdab40c0adc2a254954ba90fead17fffdeb14f9a2d2d9639149a5874a4a7a9c2b48"
    "cd54a7fac8c0956cacb3674d67e3bef7c7f8cedafad53971c67deff9e08bfbde70e60ffaff46d0e30b9ef7b9b8cf7eea47f7f31dca542263f41e8a4ea318565f",
    "7a919b9783204d658310f9a2ee83452edf2c7eb23e1862f302d835f279ae1e964efcf2cf1f711f7c8a7c51f53dfbad0d85ee8a6c70506285e3cea3fb9ad8d584"
    "c5d1dd45dbbfe19d2f98cc2a1a9e575ddde6f2cde2c1d6c5a991b53451e9c09558574f952faa7e76d8ee6f955ebd2a0d444da9e61446e013a5b879fe75f51bfb",
    "d2f7ad", "" };

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
