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
void groupLayers_Mod(const double allLayers[10], double allRoughs, const
                     emxArray_char_T *geometry, double nbair, double nbsubs,
                     double outLayers_data[], int outLayers_size[2], double
                     *outSsubs)
{
  double layers_data[10];
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv3[13] = { 'a', 'i', 'r', '/', 's', 'u', 'b', 's', 't', 'r',
    'a', 't', 'e' };

  double b_allLayers[8];
  static const char cv4[16] = { 's', 'u', 'b', 's', 't', 'r', 'a', 't', 'e', '/',
    'l', 'i', 'q', 'u', 'i', 'd' };

  double c_allLayers;
  double d_allLayers;
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
  /*      The paratt calculation procedds through the  */
  /*      z,rho,rough stack, and the parameter 'ssub' in */
  /*      callParatt is the final roughness encountered.  */
  /*      For air liquid 'ssub' is therefore the substrate roughness. */
  /*      For solid liquid, the substrate roughness is the first roughness */
  /*      encountered, and 'ssub' is then the roughness of the outermost layer. */
  /*      The rougnesses need to be arranged accordingly. */
  /*  */
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
  b_bool = false;
  if (geometry->size[1] == 13) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 13) {
        if (geometry->data[kstr] != cv3[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    kstr = 0;
  } else {
    b_bool = false;
    if (geometry->size[1] == 16) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 16) {
          if (geometry->data[kstr] != cv4[kstr]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      kstr = 1;
    } else {
      kstr = -1;
    }
  }

  switch (kstr) {
   case 0:
    memcpy(&layers_data[0], &allLayers[0], 10U * sizeof(double));

    /* s_sub = rsub; */
    break;

   case 1:
    *outSsubs = allLayers[5];
    b_allLayers[4] = allRoughs;
    b_allLayers[5] = allLayers[4];
    b_allLayers[0] = allLayers[0];
    b_allLayers[2] = allLayers[2];
    b_allLayers[6] = allLayers[6];
    b_allLayers[1] = allLayers[1];
    b_allLayers[3] = allLayers[3];
    b_allLayers[7] = allLayers[7];
    memcpy(&layers_data[0], &b_allLayers[0], sizeof(double) << 3);
    break;
  }

  /* Deal with the %coverage if present */
  if (!rtIsNaN(allLayers[6])) {
    if (allLayers[8] == 1.0) {
      c_allLayers = nbsubs;
    } else {
      c_allLayers = nbair;
    }

    layers_data[2] = c_allLayers * (allLayers[6] / 100.0) + (1.0 - allLayers[6] /
      100.0) * layers_data[2];
  }

  if (!rtIsNaN(allLayers[7])) {
    if (allLayers[9] == 1.0) {
      d_allLayers = nbsubs;
    } else {
      d_allLayers = nbair;
    }

    layers_data[3] = d_allLayers * (allLayers[7] / 100.0) + (1.0 - allLayers[7] /
      100.0) * layers_data[3];
  }

  /*      problem.layers{i} = layers; */
  /*      problem.ssubs(i) = s_sub; */
  outLayers_size[0] = 2;
  outLayers_size[1] = 3;
  for (kstr = 0; kstr < 3; kstr++) {
    outLayers_data_tmp = kstr << 1;
    outLayers_data[outLayers_data_tmp] = layers_data[outLayers_data_tmp];
    outLayers_data_tmp++;
    outLayers_data[outLayers_data_tmp] = layers_data[outLayers_data_tmp];
  }

  /* end */
}

/* End of code generation (groupLayers_Mod.c) */
