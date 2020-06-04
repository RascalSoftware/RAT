/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * allocateParamsToLayers.c
 *
 * Code generation for function 'allocateParamsToLayers'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "allocateParamsToLayers.h"
#include "reflectivity_calculation_emxutil.h"

/* Function Definitions */
void allocateParamsToLayers(const emxArray_real_T *params, const
  emxArray_cell_wrap_2 *layersDetails, emxArray_cell_wrap_13 *outLayers)
{
  int i2;
  double thisOutLayer[5];
  int i3;
  int i;
  int n;
  int b_n;

  /* This function takes the list of all layers (in terms of parameter */
  /* numbers) in layersDetails, and loops through putting in the correct */
  /* parameter value from the parameter array in each layer.  */
  for (i2 = 0; i2 < 5; i2++) {
    thisOutLayer[i2] = 0.0;
  }

  i2 = layersDetails->size[0];
  i3 = outLayers->size[0] * outLayers->size[1];
  outLayers->size[0] = 1;
  outLayers->size[1] = layersDetails->size[0];
  emxEnsureCapacity_cell_wrap_13(outLayers, i3);
  for (i = 0; i < i2; i++) {
    i3 = layersDetails->data[i].f1.size[1];
    n = 1;
    for (b_n = 0; b_n <= i3 - 2; b_n++) {
      n = b_n + 1;
      if (!rtIsNaN(layersDetails->data[i].f1.data[b_n])) {
        thisOutLayer[b_n] = params->data[(int)layersDetails->data[i].f1.data[b_n]
          - 1];
      } else {
        thisOutLayer[b_n] = rtNaN;
      }
    }

    thisOutLayer[n] = layersDetails->data[i].f1.data[layersDetails->data[i].
      f1.size[1] - 1];
    for (i3 = 0; i3 < 5; i3++) {
      outLayers->data[i].f1[i3] = thisOutLayer[i3];
    }
  }
}

/* End of code generation (allocateParamsToLayers.c) */
