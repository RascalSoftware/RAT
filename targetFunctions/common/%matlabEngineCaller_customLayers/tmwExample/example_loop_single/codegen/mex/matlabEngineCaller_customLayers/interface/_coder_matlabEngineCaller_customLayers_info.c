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
  emlrtSetField(xResult, 0, "CoverageInfo", covrtSerializeInstanceData
                (&emlrtCoverageInstance));
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[5] = {
    "789cc552cb4e4231102d068d2e346ef41b4c4c1835d1e8127904222e44487cc490524668ec03db5ec09d7fe0d29ddfe4c6fff013ecbd17b02144a21b2739997b"
    "3a771e675a92a99e136f1b1e57594256bc5ff55822a92d8f7926407a9e25eb63fee2c1b47238726950518964621d2db9a2ca359efa480c5a2d06d84922f75c60",
    "834bace98054b827b21c84a6240ec5df851eb287cb4812d3b3d336448424d1f34ebef564e7e8790bf46c8ef96de90e7a5a225033440145cd2289ca59a853cba8"
    "28e200eaf906386abae8ca91628e6b65816929b502499da0ed92ea7285052a049a168bacd3b2469fd0587072581a51d9170898fa96d0badfb25c75fdd982f49c",
    "4c755516e8da9ad1b595dc4f074d8efb4b328a8a9c40d575bdf19ef67ea837b1b0de64bfa305735466f2627e5bad5df91547d680d07ea1709e6fd4f2a7503fd8"
    "db3f6a83d35ab4f508508a04bbc9dcb03b191cd2c17332ee7f1cf45f99d33f7caf6b533dcfaf9f671ff9bfe77febffeffc45ef607b66ff31670576d3b9285c54",
    "9bd7fcb1e80627cdc3d36639adb713d4cbcca94702ffdbffbf001aed9713", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 1128U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_matlabEngineCaller_customLayers_info.c) */
