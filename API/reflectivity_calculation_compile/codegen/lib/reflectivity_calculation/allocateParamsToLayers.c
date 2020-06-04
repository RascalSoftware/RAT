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
#include <string.h>

/* Function Definitions */
void allocateParamsToLayers(const double params[10], const cell_wrap_2
  layersDetails[4], cell_wrap_2 outLayers[4])
{
  double thisOutLayer[5];
  int i2;

  /* This function takes the list of all layers (in terms of parameter */
  /* numbers) in layersDetails, and loops through putting in the correct */
  /* parameter value from the parameter array in each layer.  */
  if (!rtIsNaN(layersDetails[0].f1[0])) {
    thisOutLayer[0] = params[(int)layersDetails[0].f1[0] - 1];
  } else {
    thisOutLayer[0] = rtNaN;
  }

  if (!rtIsNaN(layersDetails[0].f1[1])) {
    thisOutLayer[1] = params[(int)layersDetails[0].f1[1] - 1];
  } else {
    thisOutLayer[1] = rtNaN;
  }

  if (!rtIsNaN(layersDetails[0].f1[2])) {
    thisOutLayer[2] = params[(int)layersDetails[0].f1[2] - 1];
  } else {
    thisOutLayer[2] = rtNaN;
  }

  if (!rtIsNaN(layersDetails[0].f1[3])) {
    thisOutLayer[3] = params[(int)layersDetails[0].f1[3] - 1];
  } else {
    thisOutLayer[3] = rtNaN;
  }

  thisOutLayer[4] = layersDetails[0].f1[4];
  for (i2 = 0; i2 < 5; i2++) {
    outLayers[0].f1[i2] = thisOutLayer[i2];
  }

  if (!rtIsNaN(layersDetails[1].f1[0])) {
    thisOutLayer[0] = params[(int)layersDetails[1].f1[0] - 1];
  } else {
    thisOutLayer[0] = rtNaN;
  }

  if (!rtIsNaN(layersDetails[1].f1[1])) {
    thisOutLayer[1] = params[(int)layersDetails[1].f1[1] - 1];
  } else {
    thisOutLayer[1] = rtNaN;
  }

  if (!rtIsNaN(layersDetails[1].f1[2])) {
    thisOutLayer[2] = params[(int)layersDetails[1].f1[2] - 1];
  } else {
    thisOutLayer[2] = rtNaN;
  }

  if (!rtIsNaN(layersDetails[1].f1[3])) {
    thisOutLayer[3] = params[(int)layersDetails[1].f1[3] - 1];
  } else {
    thisOutLayer[3] = rtNaN;
  }

  thisOutLayer[4] = layersDetails[1].f1[4];
  for (i2 = 0; i2 < 5; i2++) {
    outLayers[1].f1[i2] = thisOutLayer[i2];
  }

  if (!rtIsNaN(layersDetails[2].f1[0])) {
    thisOutLayer[0] = params[(int)layersDetails[2].f1[0] - 1];
  } else {
    thisOutLayer[0] = rtNaN;
  }

  if (!rtIsNaN(layersDetails[2].f1[1])) {
    thisOutLayer[1] = params[(int)layersDetails[2].f1[1] - 1];
  } else {
    thisOutLayer[1] = rtNaN;
  }

  if (!rtIsNaN(layersDetails[2].f1[2])) {
    thisOutLayer[2] = params[(int)layersDetails[2].f1[2] - 1];
  } else {
    thisOutLayer[2] = rtNaN;
  }

  if (!rtIsNaN(layersDetails[2].f1[3])) {
    thisOutLayer[3] = params[(int)layersDetails[2].f1[3] - 1];
  } else {
    thisOutLayer[3] = rtNaN;
  }

  thisOutLayer[4] = layersDetails[2].f1[4];
  for (i2 = 0; i2 < 5; i2++) {
    outLayers[2].f1[i2] = thisOutLayer[i2];
  }

  if (!rtIsNaN(layersDetails[3].f1[0])) {
    thisOutLayer[0] = params[(int)layersDetails[3].f1[0] - 1];
  } else {
    thisOutLayer[0] = rtNaN;
  }

  if (!rtIsNaN(layersDetails[3].f1[1])) {
    thisOutLayer[1] = params[(int)layersDetails[3].f1[1] - 1];
  } else {
    thisOutLayer[1] = rtNaN;
  }

  if (!rtIsNaN(layersDetails[3].f1[2])) {
    thisOutLayer[2] = params[(int)layersDetails[3].f1[2] - 1];
  } else {
    thisOutLayer[2] = rtNaN;
  }

  if (!rtIsNaN(layersDetails[3].f1[3])) {
    thisOutLayer[3] = params[(int)layersDetails[3].f1[3] - 1];
  } else {
    thisOutLayer[3] = rtNaN;
  }

  thisOutLayer[4] = layersDetails[3].f1[4];
  for (i2 = 0; i2 < 5; i2++) {
    outLayers[3].f1[i2] = thisOutLayer[i2];
  }
}

/* End of code generation (allocateParamsToLayers.c) */
