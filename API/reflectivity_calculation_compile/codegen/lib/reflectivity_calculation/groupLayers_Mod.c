/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * groupLayers_Mod.c
 *
 * Code generation for function 'groupLayers_Mod'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "groupLayers_Mod.h"

/* Function Definitions */
void groupLayers_Mod(const double allLayers[10], double allRoughs, const char
                     geometry[13], double nbair, double nbsubs, double
                     outLayers_data[], int outLayers_size[2], double *outSsubs)
{
  double layers_data[10];
  int ret;
  static const char b[13] = { 'a', 'i', 'r', '/', 's', 'u', 'b', 's', 't', 'r',
    'a', 't', 'e' };

  int b_ret;
  double b_allLayers;
  double c_allLayers;
  int outLayers_data_tmp;

  /* Arrange layers according to geometry and apply any coberage correction. */
  /*  */
  /* [outLayers, outSsubs] = groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs) */
  /*  Inputs: */
  /*      allLayers = cell array, one for each contrast. Each cell is the  */
  /*                  list of layer values for each contrast. */
  /*                  e.g. allLayers{1} = [d1, rho1, r1, %hyd, hyd_which */
  /*                                       d2, rho2, r2, %hyd2, hyd_which_2.. */
  /*                                       etc] */
  /*      allRoughs = Double of substrate roughness for each contrast. */
  /*      numberOfContrasts = double. */
  /*      geometry =  'Air / Liquid (or solid)' or 'Solid / Liquid' */
  /*      nbairs = vector of nbair values. */
  /*      nbsubs = vector of nbsub values. */
  /*  */
  /*  Outputs: */
  /*      outLayers = cell array of layers param values for each contrast. */
  /*                  e.g. outLayers{1} = [d1 rho1 r1; */
  /*                                       d2 rho2 r2 */
  /*                                       ... etc   ] */
  /*      outSsubs = vector of substrate roughness values. */
  /*  */
  /* global RAT_DEBUG DEBUGVARS */
  /* outLayers = cell(1,numberOfContrasts); */
  /* outSsubs = zeros(1,numberOfContrasts); */
  /* for i = 1:numberOfContrasts */
  *outSsubs = allRoughs;
  memset(&layers_data[0], 0, 10U * sizeof(double));
  ret = memcmp(&geometry[0], &b[0], 13);
  if (ret == 0) {
    b_ret = 0;
  } else {
    b_ret = -1;
  }

  if (b_ret == 0) {
    memcpy(&layers_data[0], &allLayers[0], 10U * sizeof(double));

    /* s_sub = rsub; */
  }

  /* Deal with the %coverage if present */
  if (!rtIsNaN(allLayers[6])) {
    if (allLayers[8] == 1.0) {
      b_allLayers = nbsubs;
    } else {
      b_allLayers = nbair;
    }

    layers_data[2] = b_allLayers * (allLayers[6] / 100.0) + (1.0 - allLayers[6] /
      100.0) * layers_data[2];
  }

  if (!rtIsNaN(allLayers[7])) {
    if (allLayers[9] == 1.0) {
      c_allLayers = nbsubs;
    } else {
      c_allLayers = nbair;
    }

    layers_data[3] = c_allLayers * (allLayers[7] / 100.0) + (1.0 - allLayers[7] /
      100.0) * layers_data[3];
  }

  /*      problem.layers{i} = layers; */
  /*      problem.ssubs(i) = s_sub; */
  outLayers_size[0] = 2;
  outLayers_size[1] = 3;
  for (ret = 0; ret < 3; ret++) {
    outLayers_data_tmp = ret << 1;
    outLayers_data[outLayers_data_tmp] = layers_data[outLayers_data_tmp];
    outLayers_data_tmp++;
    outLayers_data[outLayers_data_tmp] = layers_data[outLayers_data_tmp];
  }

  /* end */
}

/* End of code generation (groupLayers_Mod.c) */
