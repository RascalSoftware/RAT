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
#include "rt_nonfinite.h"
#include "standardTF_stanlay_parallel.h"
#include "groupLayers_Mod.h"

/* Function Definitions */
void groupLayers_Mod(const double allLayers_data[], const int allLayers_size[2],
                     double allRoughs, const emxArray_char_T *geometry, double
                     nbair, double nbsubs, double outLayers_data[], int
                     outLayers_size[2], double *outSsubs)
{
  int layers_size_idx_0;
  boolean_T b_bool;
  int kstr;
  int exitg2;
  int i2;
  static const char cv0[23] = { 'A', 'i', 'r', ' ', '/', ' ', 'L', 'i', 'q', 'u',
    'i', 'd', ' ', '(', 'o', 'r', ' ', 's', 'o', 'l', 'i', 'd', ')' };

  int exitg1;
  double layers_data[10];
  signed char n[2];
  static const char cv1[14] = { 'S', 'o', 'l', 'i', 'd', ' ', '/', ' ', 'L', 'i',
    'q', 'u', 'i', 'd' };

  double sldss_data[2];
  double thicks_data[2];
  int loop_ub;
  double b_allLayers_data[2];
  double c_allLayers_data;
  double roughs_data[2];

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
  /* outLayers = cell(1,numberOfContrasts); */
  /* outSsubs = zeros(1,numberOfContrasts); */
  /* for i = 1:numberOfContrasts */
  *outSsubs = allRoughs;
  layers_size_idx_0 = 0;
  if (!((allLayers_size[0] == 0) || (allLayers_size[1] == 0))) {
    b_bool = false;
    if (geometry->size[1] == 23) {
      kstr = 0;
      do {
        exitg2 = 0;
        if (kstr + 1 < 24) {
          if (geometry->data[kstr] != cv0[kstr]) {
            exitg2 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }

    if (b_bool) {
      kstr = 0;
    } else {
      b_bool = false;
      if (geometry->size[1] == 14) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr + 1 < 15) {
            if (geometry->data[kstr] != cv1[kstr]) {
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
      layers_size_idx_0 = allLayers_size[0];
      kstr = allLayers_size[0] * allLayers_size[1];
      for (i2 = 0; i2 < kstr; i2++) {
        layers_data[i2] = allLayers_data[i2];
      }

      /* s_sub = rsub; */
      break;

     case 1:
      kstr = allLayers_size[0];
      for (i2 = 0; i2 < kstr; i2++) {
        sldss_data[i2] = allLayers_data[i2 + allLayers_size[0]];
      }

      kstr = allLayers_size[0];
      for (i2 = 0; i2 < kstr; i2++) {
        thicks_data[i2] = allLayers_data[i2];
      }

      if (1 > allLayers_size[0] - 1) {
        kstr = -1;
      } else {
        kstr = 0;
      }

      loop_ub = allLayers_size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_allLayers_data[i2] = allLayers_data[i2 + (allLayers_size[0] << 1)];
      }

      roughs_data[0] = allRoughs;
      for (i2 = 0; i2 <= kstr; i2++) {
        roughs_data[i2 + 1] = b_allLayers_data[i2];
      }

      if (allLayers_size[1] == 5) {
        loop_ub = allLayers_size[0];
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_allLayers_data[i2] = allLayers_data[i2 + allLayers_size[0] * 3];
        }

        layers_size_idx_0 = allLayers_size[0];
        loop_ub = allLayers_size[0];
        for (i2 = 0; i2 < loop_ub; i2++) {
          layers_data[i2] = thicks_data[i2];
        }

        loop_ub = allLayers_size[0];
        for (i2 = 0; i2 < loop_ub; i2++) {
          layers_data[i2 + layers_size_idx_0] = sldss_data[i2];
        }

        kstr += 2;
        for (i2 = 0; i2 < kstr; i2++) {
          layers_data[i2 + (layers_size_idx_0 << 1)] = roughs_data[i2];
        }

        kstr = allLayers_size[0];
        for (i2 = 0; i2 < kstr; i2++) {
          layers_data[i2 + layers_size_idx_0 * 3] = b_allLayers_data[i2];
        }
      } else {
        layers_size_idx_0 = allLayers_size[0];
        loop_ub = allLayers_size[0];
        for (i2 = 0; i2 < loop_ub; i2++) {
          layers_data[i2] = thicks_data[i2];
        }

        loop_ub = allLayers_size[0];
        for (i2 = 0; i2 < loop_ub; i2++) {
          layers_data[i2 + layers_size_idx_0] = sldss_data[i2];
        }

        kstr += 2;
        for (i2 = 0; i2 < kstr; i2++) {
          layers_data[i2 + (layers_size_idx_0 << 1)] = roughs_data[i2];
        }
      }

      *outSsubs = allLayers_data[(allLayers_size[0] + (allLayers_size[0] << 1))
        - 1];
      break;
    }

    /* Deal with the %coverage if present */
    for (i2 = 0; i2 < 2; i2++) {
      n[i2] = (signed char)allLayers_size[i2];
    }

    if (n[1] == 5) {
      for (kstr = 0; kstr < n[0]; kstr++) {
        if (!rtIsNaN(allLayers_data[kstr + allLayers_size[0] * 3])) {
          if (allLayers_data[kstr + (allLayers_size[0] << 2)] == 1.0) {
            c_allLayers_data = nbsubs;
          } else {
            c_allLayers_data = nbair;
          }

          layers_data[kstr + layers_size_idx_0] = c_allLayers_data *
            (allLayers_data[kstr + allLayers_size[0] * 3] / 100.0) + (1.0 -
            allLayers_data[kstr + allLayers_size[0] * 3] / 100.0) *
            layers_data[kstr + layers_size_idx_0];
        }
      }
    }
  }

  /*      problem.layers{i} = layers; */
  /*      problem.ssubs(i) = s_sub; */
  outLayers_size[0] = layers_size_idx_0;
  outLayers_size[1] = 3;
  for (i2 = 0; i2 < 3; i2++) {
    for (kstr = 0; kstr < layers_size_idx_0; kstr++) {
      outLayers_data[kstr + layers_size_idx_0 * i2] = layers_data[kstr +
        layers_size_idx_0 * i2];
    }
  }

  /* end */
}

/* End of code generation (groupLayers_Mod.c) */
