/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * call_StandardLayers.c
 *
 * Code generation for function 'call_StandardLayers'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_stanlay_parallel.h"
#include "call_StandardLayers.h"
#include "standardTF_stanlay_parallel_emxutil.h"

/* Function Definitions */
void call_StandardLayers(const emxArray_real_T *params, const double
  contrastLayers[2], double numberOfLayers, const emxArray_cell_wrap_2
  *layersDetails, double layersList_data[], int layersList_size[2], double
  *sRough)
{
  emxArray_real_T *layersValues;
  int i1;
  int loop_ub;
  int n;
  if (numberOfLayers == 0.0) {
    layersList_size[0] = 0;
    layersList_size[1] = 0;
  } else {
    emxInit_real_T(&layersValues, 2);
    i1 = layersValues->size[0] * layersValues->size[1];
    layersValues->size[0] = (int)numberOfLayers;
    layersValues->size[1] = 5;
    emxEnsureCapacity((emxArray__common *)layersValues, i1, (int)sizeof(double));
    loop_ub = (int)numberOfLayers * 5;
    for (i1 = 0; i1 < loop_ub; i1++) {
      layersValues->data[i1] = 0.0;
    }

    for (n = 0; n < (int)numberOfLayers; n++) {
      for (loop_ub = 0; loop_ub < 4; loop_ub++) {
        if (!rtIsNaN(layersDetails->data[layersDetails->size[0] * n]
                     .f1.data[loop_ub])) {
          layersValues->data[n + layersValues->size[0] * loop_ub] = params->
            data[(int)layersDetails->data[layersDetails->size[0] * n]
            .f1.data[loop_ub] - 1];
        } else {
          layersValues->data[n + layersValues->size[0] * loop_ub] = rtNaN;
        }
      }

      layersValues->data[n + (layersValues->size[0] << 2)] =
        (layersDetails->data[layersDetails->size[0] * n].f1.data[4] == 2.0);
    }

    layersList_size[0] = 2;
    layersList_size[1] = 5;
    memset(&layersList_data[0], 0, 10U * sizeof(double));
    for (n = 0; n < 2; n++) {
      for (i1 = 0; i1 < 5; i1++) {
        layersList_data[n + (i1 << 1)] = layersValues->data[((int)
          contrastLayers[n] + layersValues->size[0] * i1) - 1];
      }
    }

    emxFree_real_T(&layersValues);
  }

  *sRough = params->data[0];
}

/* End of code generation (call_StandardLayers.c) */
