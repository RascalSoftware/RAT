//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: matlabEngineCaller_customLayers.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "matlabEngineCaller_customLayers.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : const coder::array<double, 2U> *params
//                double contrast
//                const coder::array<char, 2U> *funcName
//                const coder::array<char, 2U> *funcPath
//                double bulkIn
//                double bulkOut
//                coder::array<double, 2U> *output
//                double *sRough
// Return Type  : void
//
void matlabEngineCaller_customLayers(const coder::array<double, 2U> &params,
  double contrast, const coder::array<char, 2U> &funcName, const coder::array<
  char, 2U> &funcPath, double bulkIn, double bulkOut, coder::array<double, 2U>
  &output, double *sRough)
{
  coder::array<char, 2U> funName;
  int i;
  int loop_ub;
  static const char b_cv[17] = { '[', 't', 'o', 't', 'a', 'l', ',', 'l', 'a',
    'y', 'e', 'r', 's', ']', ' ', '=', ' ' };

  static const char b_cv1[34] = { '(', 'p', 'a', 'r', 'a', 'm', 's', ',', 'b',
    'u', 'l', 'k', '_', 'i', 'n', ',', 'b', 'u', 'l', 'k', '_', 'o', 'u', 't',
    ',', 'c', 'o', 'n', 't', 'r', 'a', 's', 't', ')' };

  coder::array<char, 2U> pathCall;
  coder::array<double, 2U> b_params;
  double outp[3000];
  double nLayers;
  unsigned int rowCount;
  int colCount;

  //  dotM = strfind(funcName,'.m');
  //  if ~isempty(dotM)
  //      funcName = funcName(1:dotM-1);
  //  end
  // [path,funcName,extension] = fileparts(funcName);
  funName.set_size(1, (funcName.size(1) + 51));
  for (i = 0; i < 17; i++) {
    funName[i] = b_cv[i];
  }

  loop_ub = funcName.size(1);
  for (i = 0; i < loop_ub; i++) {
    funName[i + 17] = funcName[i];
  }

  for (i = 0; i < 34; i++) {
    funName[(i + funcName.size(1)) + 17] = b_cv1[i];
  }

  *sRough = params[0];
  pathCall.set_size(1, (funcPath.size(1) + 6));
  pathCall[0] = 'c';
  pathCall[1] = 'd';
  pathCall[2] = ' ';
  pathCall[3] = '\'';
  loop_ub = funcPath.size(1);
  for (i = 0; i < loop_ub; i++) {
    pathCall[i + 4] = funcPath[i];
  }

  pathCall[funcPath.size(1) + 4] = '\'';
  pathCall[funcPath.size(1) + 5] = ';';

  // incPath2 = '/usr/include/openmpi-x86_64';
  // source2 = 'matlabCallFun.h';
  // source1 = 'matlabCallFun.c';
  // source2 = 'matlabCallFun.h';
  // coder.cinclude(source2);
  // coder.updateBuildInfo('addSourceFiles',source2);
  // coder.updateBuildInfo('addIncludePaths',incPath2);
  // Need to reserve some meory for the referencenced variables
  b_params.set_size(1, params.size(1));
  loop_ub = params.size(0) * params.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_params[i] = params[i];
  }

  i = params.size(1);
  if (params.size(1) > 32767) {
    i = 32767;
  } else {
    if (params.size(1) < -32768) {
      i = -32768;
    }
  }

  matlabCallFun(&b_params[0], static_cast<short>(i), &funName[0], &pathCall[0],
                bulkIn, bulkOut, contrast, outp, &nLayers);
  rowCount = 1U;
  colCount = 0;

  // reshape the output to [layers * 3] array
  if (nLayers >= 1.0) {
    i = static_cast<int>(nLayers);
    output.set_size(i, 3);
    loop_ub = i * 3;
    for (i = 0; i < loop_ub; i++) {
      output[i] = 0.0;
    }

    i = static_cast<int>(nLayers * 3.0);
    for (loop_ub = 0; loop_ub < i; loop_ub++) {
      output[(static_cast<int>(rowCount) + output.size(0) * colCount) - 1] =
        outp[loop_ub];

      // Make use of Matlab linear indexing.
      rowCount++;
      if (rowCount == nLayers + 1.0) {
        rowCount = 1U;
        colCount++;
      }
    }
  } else {
    output.set_size(1, 3);
    output[0] = 1.0;
    output[1] = 1.0;
    output[2] = 1.0;
    *sRough = 1.0;
  }
}

//
// File trailer for matlabEngineCaller_customLayers.cpp
//
// [EOF]
//
