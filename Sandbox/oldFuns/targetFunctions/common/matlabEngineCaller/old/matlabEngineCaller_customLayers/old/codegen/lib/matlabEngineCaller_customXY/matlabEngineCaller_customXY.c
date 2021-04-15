/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * matlabEngineCaller_customXY.c
 *
 * Code generation for function 'matlabEngineCaller_customXY'
 *
 */

/* Include files */
#include "matlabEngineCaller_customXY.h"
#include "matlabEngineCaller_customXY_emxutil.h"

/* Function Definitions */
void matlabEngineCaller_customXY(const emxArray_real_T *params, double contrast,
  const emxArray_char_T *funcName, const emxArray_char_T *funcPath, double
  bulkIn, double bulkOut, emxArray_real_T *output, double *sRough)
{
  emxArray_char_T *funName;
  int i;
  int loop_ub;
  static const char cv[17] = { '[', 't', 'o', 't', 'a', 'l', ',', 'l', 'a', 'y',
    'e', 'r', 's', ']', ' ', '=', ' ' };

  emxArray_char_T *pathCall;
  static const char cv1[34] = { '(', 'p', 'a', 'r', 'a', 'm', 's', ',', 'b', 'u',
    'l', 'k', '_', 'i', 'n', ',', 'b', 'u', 'l', 'k', '_', 'o', 'u', 't', ',',
    'c', 'o', 'n', 't', 'r', 'a', 's', 't', ')' };

  emxArray_real_T *b_params;
  double outp[200];
  double nLayers;
  unsigned int rowCount;
  int colCount;
  emxInit_char_T(&funName, 2);

  /*  dotM = strfind(funcName,'.m'); */
  /*  if ~isempty(dotM) */
  /*      funcName = funcName(1:dotM-1); */
  /*  end */
  /* [path,funcName,extension] = fileparts(funcName); */
  i = funName->size[0] * funName->size[1];
  funName->size[0] = 1;
  funName->size[1] = funcName->size[1] + 51;
  emxEnsureCapacity_char_T(funName, i);
  for (i = 0; i < 17; i++) {
    funName->data[i] = cv[i];
  }

  loop_ub = funcName->size[1];
  for (i = 0; i < loop_ub; i++) {
    funName->data[i + 17] = funcName->data[i];
  }

  for (i = 0; i < 34; i++) {
    funName->data[(i + funcName->size[1]) + 17] = cv1[i];
  }

  emxInit_char_T(&pathCall, 2);
  *sRough = params->data[0];
  i = pathCall->size[0] * pathCall->size[1];
  pathCall->size[0] = 1;
  pathCall->size[1] = funcPath->size[1] + 6;
  emxEnsureCapacity_char_T(pathCall, i);
  pathCall->data[0] = 'c';
  pathCall->data[1] = 'd';
  pathCall->data[2] = ' ';
  pathCall->data[3] = '\'';
  loop_ub = funcPath->size[1];
  for (i = 0; i < loop_ub; i++) {
    pathCall->data[i + 4] = funcPath->data[i];
  }

  emxInit_real_T(&b_params, 2);
  pathCall->data[funcPath->size[1] + 4] = '\'';
  pathCall->data[funcPath->size[1] + 5] = ';';

  /* incPath2 = '/usr/include/openmpi-x86_64'; */
  /* source2 = 'matlabCallFun.h'; */
  /* source1 = 'matlabCallFun.c'; */
  /* source2 = 'matlabCallFun.h'; */
  /* coder.cinclude(source2); */
  /* coder.updateBuildInfo('addSourceFiles',source2); */
  /* coder.updateBuildInfo('addIncludePaths',incPath2); */
  /* Need to reserve some meory for the referencenced variables */
  i = b_params->size[0] * b_params->size[1];
  b_params->size[0] = 1;
  b_params->size[1] = params->size[1];
  emxEnsureCapacity_real_T(b_params, i);
  loop_ub = params->size[0] * params->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_params->data[i] = params->data[i];
  }

  i = params->size[1];
  if (params->size[1] > 32767) {
    i = 32767;
  } else {
    if (params->size[1] < -32768) {
      i = -32768;
    }
  }

  matlabCallFun(&b_params->data[0], (short)i, &funName->data[0], &pathCall->
                data[0], bulkIn, bulkOut, contrast, outp, &nLayers);
  rowCount = 1U;
  colCount = 0;

  /* reshape the output to [layers * 2] array */
  emxFree_real_T(&b_params);
  emxFree_char_T(&pathCall);
  emxFree_char_T(&funName);
  if (nLayers >= 1.0) {
    i = (int)nLayers;
    loop_ub = output->size[0] * output->size[1];
    output->size[0] = i;
    output->size[1] = 2;
    emxEnsureCapacity_real_T(output, loop_ub);
    loop_ub = i << 1;
    for (i = 0; i < loop_ub; i++) {
      output->data[i] = 0.0;
    }

    i = (int)(nLayers * 2.0);
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
    output->size[1] = 2;
    emxEnsureCapacity_real_T(output, i);
    output->data[0] = 1.0;
    output->data[1] = 1.0;
    *sRough = 1.0;
  }
}

/* End of code generation (matlabEngineCaller_customXY.c) */
