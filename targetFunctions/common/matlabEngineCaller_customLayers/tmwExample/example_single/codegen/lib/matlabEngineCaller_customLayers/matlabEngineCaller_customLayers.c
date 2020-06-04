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
#include "rt_nonfinite.h"
#include "matlabEngineCaller_customLayers.h"
#include "matlabEngineCaller_customLayers_emxutil.h"
#include "matlabCallFun.h"

/* Function Definitions */
void matlabEngineCaller_customLayers(const double params[8], double contrast,
  const emxArray_char_T *funcName, const emxArray_char_T *funcPath, double
  bulkIn, double bulkOut, emxArray_real_T *output, double sRough_data[], int
  sRough_size[2])
{
  emxArray_char_T *funName;
  int i;
  int loop_ub;
  static const char cv0[17] = { '[', 't', 'o', 't', 'a', 'l', ',', 'l', 'a', 'y',
    'e', 'r', 's', ']', ' ', '=', ' ' };

  emxArray_char_T *pathCall;
  static const char cv1[34] = { '(', 'p', 'a', 'r', 'a', 'm', 's', ',', 'b', 'u',
    'l', 'k', '_', 'i', 'n', ',', 'b', 'u', 'l', 'k', '_', 'o', 'u', 't', ',',
    'c', 'o', 'n', 't', 'r', 'a', 's', 't', ')' };

  static const char cv2[4] = { 'c', 'd', ' ', '\'' };

  double outp[300];
  static const char cv3[2] = { '\'', ';' };

  double nLayers;
  double b_params[8];
  unsigned int rowCount;
  int colCount;
  double d0;
  emxInit_char_T(&funName, 2);
  sRough_size[0] = 1;
  sRough_size[1] = 1;
  sRough_data[0] = params[0];

  /* Need to reserve some meory for the referencenced variables */
  i = funName->size[0] * funName->size[1];
  funName->size[0] = 1;
  funName->size[1] = 51 + funcName->size[1];
  emxEnsureCapacity((emxArray__common *)funName, i, (int)sizeof(char));
  for (i = 0; i < 17; i++) {
    funName->data[funName->size[0] * i] = cv0[i];
  }

  loop_ub = funcName->size[1];
  for (i = 0; i < loop_ub; i++) {
    funName->data[funName->size[0] * (i + 17)] = funcName->data[funcName->size[0]
      * i];
  }

  for (i = 0; i < 34; i++) {
    funName->data[funName->size[0] * ((i + funcName->size[1]) + 17)] = cv1[i];
  }

  emxInit_char_T(&pathCall, 2);
  i = pathCall->size[0] * pathCall->size[1];
  pathCall->size[0] = 1;
  pathCall->size[1] = 6 + funcPath->size[1];
  emxEnsureCapacity((emxArray__common *)pathCall, i, (int)sizeof(char));
  for (i = 0; i < 4; i++) {
    pathCall->data[pathCall->size[0] * i] = cv2[i];
  }

  loop_ub = funcPath->size[1];
  for (i = 0; i < loop_ub; i++) {
    pathCall->data[pathCall->size[0] * (i + 4)] = funcPath->data[funcPath->size
      [0] * i];
  }

  for (i = 0; i < 2; i++) {
    pathCall->data[pathCall->size[0] * ((i + funcPath->size[1]) + 4)] = cv3[i];
  }

  memcpy(&b_params[0], &params[0], sizeof(double) << 3);
  matlabCallFun(b_params, 8.0, &funName->data[0], &pathCall->data[0], bulkIn,
                bulkOut, contrast, outp, &nLayers);
  rowCount = 1U;
  colCount = 0;

  /* reshape the output to [layers * 3] array */
  emxFree_char_T(&pathCall);
  emxFree_char_T(&funName);
  if (nLayers >= 1.0) {
    i = output->size[0] * output->size[1];
    output->size[0] = (int)nLayers;
    output->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)output, i, (int)sizeof(double));
    loop_ub = (int)nLayers * 3;
    for (i = 0; i < loop_ub; i++) {
      output->data[i] = 0.0;
    }

    d0 = nLayers * 3.0;
    for (i = 0; i < (int)d0; i++) {
      /* Make use of Matlab linear indexing. */
      output->data[((int)rowCount + output->size[0] * colCount) - 1] = outp[i];
      rowCount++;
      if (rowCount == nLayers + 1.0) {
        rowCount = 1U;
        colCount++;
      }
    }
  } else {
    i = output->size[0] * output->size[1];
    output->size[0] = 0;
    output->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)output, i, (int)sizeof(double));
    sRough_size[0] = 0;
    sRough_size[1] = 0;
  }
}

/* End of code generation (matlabEngineCaller_customLayers.c) */
