/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * call_customLayers.c
 *
 * Code generation for function 'call_customLayers'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_parallel.h"
#include "call_customLayers.h"
#include "standardTF_custlay_parallel_emxutil.h"
#include "matlabCallFun.h"

/* Function Definitions */
void call_customLayers(const emxArray_real_T *params, double contrast, const
  emxArray_char_T *file, const emxArray_char_T *callPath, double bulkIn, double
  bulkOut, emxArray_real_T *output, double *sRough)
{
  emxArray_real_T *b_params;
  int i;
  int loop_ub;
  emxArray_char_T *funName;
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
  unsigned int rowCount;
  int colCount;
  double d6;
  emxInit_real_T(&b_params, 2);

  /* Build with....    codegen matlabEngineCaller_customLayers -o matlabEngineCaller_customLayers */
  /* Need to reserve some meory for the referencenced variables */
  i = b_params->size[0] * b_params->size[1];
  b_params->size[0] = 1;
  b_params->size[1] = params->size[1];
  emxEnsureCapacity((emxArray__common *)b_params, i, (int)sizeof(double));
  loop_ub = params->size[0] * params->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_params->data[i] = params->data[i];
  }

  emxInit_char_T(&funName, 2);
  i = funName->size[0] * funName->size[1];
  funName->size[0] = 1;
  funName->size[1] = 51 + file->size[1];
  emxEnsureCapacity((emxArray__common *)funName, i, (int)sizeof(char));
  for (i = 0; i < 17; i++) {
    funName->data[funName->size[0] * i] = cv0[i];
  }

  loop_ub = file->size[1];
  for (i = 0; i < loop_ub; i++) {
    funName->data[funName->size[0] * (i + 17)] = file->data[file->size[0] * i];
  }

  for (i = 0; i < 34; i++) {
    funName->data[funName->size[0] * ((i + file->size[1]) + 17)] = cv1[i];
  }

  emxInit_char_T(&pathCall, 2);
  i = pathCall->size[0] * pathCall->size[1];
  pathCall->size[0] = 1;
  pathCall->size[1] = 6 + callPath->size[1];
  emxEnsureCapacity((emxArray__common *)pathCall, i, (int)sizeof(char));
  for (i = 0; i < 4; i++) {
    pathCall->data[pathCall->size[0] * i] = cv2[i];
  }

  loop_ub = callPath->size[1];
  for (i = 0; i < loop_ub; i++) {
    pathCall->data[pathCall->size[0] * (i + 4)] = callPath->data[callPath->size
      [0] * i];
  }

  for (i = 0; i < 2; i++) {
    pathCall->data[pathCall->size[0] * ((i + callPath->size[1]) + 4)] = cv3[i];
  }

  matlabCallFun(&b_params->data[0], (double)params->size[1], &funName->data[0],
                &pathCall->data[0], bulkIn, bulkOut, contrast, outp, &nLayers);
  rowCount = 1U;
  colCount = 0;
  emxFree_char_T(&pathCall);
  emxFree_char_T(&funName);
  emxFree_real_T(&b_params);
  if (nLayers >= 1.0) {
    i = output->size[0] * output->size[1];
    output->size[0] = (int)nLayers;
    output->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)output, i, (int)sizeof(double));
    loop_ub = (int)nLayers * 3;
    for (i = 0; i < loop_ub; i++) {
      output->data[i] = 0.0;
    }

    d6 = nLayers * 3.0;
    for (i = 0; i < (int)d6; i++) {
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
  }

  *sRough = params->data[0];
}

/* End of code generation (call_customLayers.c) */
