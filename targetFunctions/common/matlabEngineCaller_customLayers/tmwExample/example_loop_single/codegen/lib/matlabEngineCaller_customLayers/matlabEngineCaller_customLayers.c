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
  const char funcName[10], const char funcPath[122], double bulkIn, double
  bulkOut, emxArray_real_T *output, double sRough_data[], int sRough_size[2])
{
  double outp[300];
  double nLayers;
  double b_params[8];
  char cv0[61];
  int i;
  static const char cv1[17] = { '[', 't', 'o', 't', 'a', 'l', ',', 'l', 'a', 'y',
    'e', 'r', 's', ']', ' ', '=', ' ' };

  char cv2[128];
  static const char cv3[34] = { '(', 'p', 'a', 'r', 'a', 'm', 's', ',', 'b', 'u',
    'l', 'k', '_', 'i', 'n', ',', 'b', 'u', 'l', 'k', '_', 'o', 'u', 't', ',',
    'c', 'o', 'n', 't', 'r', 'a', 's', 't', ')' };

  static const char cv4[4] = { 'c', 'd', ' ', '\'' };

  static const char cv5[2] = { '\'', ';' };

  unsigned int rowCount;
  int colCount;
  int loop_ub;
  double d0;
  sRough_size[0] = 1;
  sRough_size[1] = 1;
  sRough_data[0] = params[0];

  /* Need to reserve some meory for the referencenced variables */
  memcpy(&b_params[0], &params[0], sizeof(double) << 3);
  for (i = 0; i < 17; i++) {
    cv0[i] = cv1[i];
  }

  for (i = 0; i < 10; i++) {
    cv0[i + 17] = funcName[i];
  }

  for (i = 0; i < 34; i++) {
    cv0[i + 27] = cv3[i];
  }

  for (i = 0; i < 4; i++) {
    cv2[i] = cv4[i];
  }

  memcpy(&cv2[4], &funcPath[0], 122U * sizeof(char));
  for (i = 0; i < 2; i++) {
    cv2[i + 126] = cv5[i];
  }

  matlabCallFun(b_params, 8.0, cv0, cv2, bulkIn, bulkOut, contrast, outp,
                &nLayers);
  rowCount = 1U;
  colCount = 0;

  /* reshape the output to [layers * 3] array */
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
