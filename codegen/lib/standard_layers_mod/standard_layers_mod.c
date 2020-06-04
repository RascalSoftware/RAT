/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standard_layers_mod.c
 *
 * Code generation for function 'standard_layers_mod'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standard_layers_mod.h"
#include "standard_layers_mod_emxutil.h"

/* Function Definitions */
void standard_layers_mod(const emxArray_real_T *params, const double
  contrastLayers[2], double numberOfLayers, const emxArray_cell_wrap_0
  *layersDetails, double layersOutput_data[], int layersOutput_size[2], double
  *sRoughOutput)
{
  emxArray_real_T *layersValues;
  int i0;
  int loop_ub;
  int n;
  if (numberOfLayers == 0.0) {
    layersOutput_size[0] = 0;
    layersOutput_size[1] = 0;
  } else {
    emxInit_real_T(&layersValues, 2);
    i0 = layersValues->size[0] * layersValues->size[1];
    layersValues->size[0] = (int)numberOfLayers;
    layersValues->size[1] = 5;
    emxEnsureCapacity((emxArray__common *)layersValues, i0, (int)sizeof(double));
    loop_ub = (int)numberOfLayers * 5;
    for (i0 = 0; i0 < loop_ub; i0++) {
      layersValues->data[i0] = 0.0;
    }

    for (n = 0; n < (int)numberOfLayers; n++) {
      for (loop_ub = 0; loop_ub < 4; loop_ub++) {
        if (!rtIsNaN(layersDetails->data[layersDetails->size[0] * n].f1[loop_ub]))
        {
          layersValues->data[n + layersValues->size[0] * loop_ub] = params->
            data[(int)layersDetails->data[layersDetails->size[0] * n].f1[loop_ub]
            - 1];
        } else {
          layersValues->data[n + layersValues->size[0] * loop_ub] = rtNaN;
        }
      }

      layersValues->data[n + (layersValues->size[0] << 2)] =
        (layersDetails->data[layersDetails->size[0] * n].f1[4] == 2.0);
    }

    layersOutput_size[0] = 2;
    layersOutput_size[1] = 5;
    memset(&layersOutput_data[0], 0, 10U * sizeof(double));
    for (n = 0; n < 2; n++) {
      for (i0 = 0; i0 < 5; i0++) {
        layersOutput_data[n + (i0 << 1)] = layersValues->data[((int)
          contrastLayers[n] + layersValues->size[0] * i0) - 1];
      }
    }

    emxFree_real_T(&layersValues);
  }

  *sRoughOutput = params->data[0];
}

/* End of code generation (standard_layers_mod.c) */
