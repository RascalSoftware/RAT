/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * matlabEngineCaller_customLayers.c
 *
 * Code generation for function 'matlabEngineCaller_customLayers'
 *
 */

/* Include files */
#include "matlabEngineCaller_customLayers.h"
#include "matlabEngineCaller_customLayers_emxutil.h"
#include <string.h>

/* Function Definitions */
void matlabEngineCaller_customLayers(const double params[8], double contrast,
  const char funcName[10], const char funcPath[54], double bulkIn, double
  bulkOut, emxArray_real_T *output, double *sRough)
{
  int i;
  char cv[61];
  static const char cv1[17] = { '[', 't', 'o', 't', 'a', 'l', ',', 'l', 'a', 'y',
    'e', 'r', 's', ']', ' ', '=', ' ' };

  char cv2[60];
  static const char cv3[34] = { '(', 'p', 'a', 'r', 'a', 'm', 's', ',', 'b', 'u',
    'l', 'k', '_', 'i', 'n', ',', 'b', 'u', 'l', 'k', '_', 'o', 'u', 't', ',',
    'c', 'o', 'n', 't', 'r', 'a', 's', 't', ')' };

  double b_params[8];
  double outp[300];
  double nLayers;
  unsigned int rowCount;
  int colCount;
  int loop_ub;

  /*  dotM = strfind(funcName,'.m'); */
  /*  if ~isempty(dotM) */
  /*      funcName = funcName(1:dotM-1); */
  /*  end */
  /* [path,funcName,extension] = fileparts(funcName); */
  *sRough = params[0];

  /* incPath2 = '/usr/include/openmpi-x86_64'; */
  /* source2 = '/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabCallFun.h'; */
  /* source1 = 'matlabCallFun.c'; */
  /* source2 = 'matlabCallFun.h'; */
  /* coder.cinclude(source2); */
  /* coder.updateBuildInfo('addSourceFiles',source2); */
  /* coder.updateBuildInfo('addIncludePaths',incPath2); */
  /* Need to reserve some meory for the referencenced variables */
  for (i = 0; i < 17; i++) {
    cv[i] = cv1[i];
  }

  for (i = 0; i < 10; i++) {
    cv[i + 17] = funcName[i];
  }

  for (i = 0; i < 34; i++) {
    cv[i + 27] = cv3[i];
  }

  cv2[0] = 'c';
  cv2[1] = 'd';
  cv2[2] = ' ';
  cv2[3] = '\'';
  for (i = 0; i < 54; i++) {
    cv2[i + 4] = funcPath[i];
  }

  cv2[58] = '\'';
  cv2[59] = ';';
  memcpy(&b_params[0], &params[0], 8U * sizeof(double));
  matlabCallFun(b_params, 8, cv, cv2, bulkIn, bulkOut, contrast, outp, &nLayers);
  rowCount = 1U;
  colCount = 0;

  /* reshape the output to [layers * 3] array */
  if (nLayers >= 1.0) {
    i = (int)nLayers;
    loop_ub = output->size[0] * output->size[1];
    output->size[0] = i;
    output->size[1] = 3;
    emxEnsureCapacity_real_T(output, loop_ub);
    loop_ub = i * 3;
    for (i = 0; i < loop_ub; i++) {
      output->data[i] = 0.0;
    }

    i = (int)(nLayers * 3.0);
    for (loop_ub = 0; loop_ub < i; loop_ub++) {
      output->data[((int)rowCount + output->size[0] * colCount) - 1] =
        outp[loop_ub];

      /* Make use of Matlab linear indexing. */
      rowCount++;
      if (rowCount == nLayers + 1.0) {
        rowCount = 1U;
        colCount++;
      }
    }
  } else {
    i = output->size[0] * output->size[1];
    output->size[0] = 1;
    output->size[1] = 3;
    emxEnsureCapacity_real_T(output, i);
    output->data[0] = 1.0;
    output->data[1] = 1.0;
    output->data[2] = 1.0;
    *sRough = 1.0;
  }
}

/* End of code generation (matlabEngineCaller_customLayers.c) */
