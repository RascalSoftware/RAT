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
#include "standardTF_stanlay_single.h"
#include "groupLayers_Mod.h"
#include "standardTF_stanlay_single_emxutil.h"

/* Function Definitions */
void groupLayers_Mod(const emxArray_real_T *allLayers, double allRoughs, const
                     emxArray_char_T *geometry, double nbair, double nbsubs,
                     emxArray_real_T *outLayers, double *outSsubs)
{
  emxArray_real_T *layers;
  double rsub;
  int i1;
  boolean_T b_bool;
  int kstr;
  int loop_ub;
  int exitg2;
  static const char cv0[23] = { 'A', 'i', 'r', ' ', '/', ' ', 'L', 'i', 'q', 'u',
    'i', 'd', ' ', '(', 'o', 'r', ' ', 's', 'o', 'l', 'i', 'd', ')' };

  emxArray_real_T *sldss;
  int exitg1;
  unsigned int n[2];
  static const char cv1[14] = { 'S', 'o', 'l', 'i', 'd', ' ', '/', ' ', 'L', 'i',
    'q', 'u', 'i', 'd' };

  emxArray_real_T *thicks;
  double pc_add;
  emxArray_real_T *b_allLayers;
  int b_loop_ub;
  emxArray_real_T *roughs;
  emxArray_real_T *c_allLayers;
  int c_loop_ub;
  int d_loop_ub;
  emxInit_real_T(&layers, 2);

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
  rsub = allRoughs;
  i1 = layers->size[0] * layers->size[1];
  layers->size[0] = 0;
  layers->size[1] = 0;
  emxEnsureCapacity((emxArray__common *)layers, i1, (int)sizeof(double));
  if (!((allLayers->size[0] == 0) || (allLayers->size[1] == 0))) {
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
      i1 = layers->size[0] * layers->size[1];
      layers->size[0] = allLayers->size[0];
      layers->size[1] = allLayers->size[1];
      emxEnsureCapacity((emxArray__common *)layers, i1, (int)sizeof(double));
      loop_ub = allLayers->size[0] * allLayers->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        layers->data[i1] = allLayers->data[i1];
      }

      /* s_sub = rsub; */
      break;

     case 1:
      emxInit_real_T1(&sldss, 1);
      loop_ub = allLayers->size[0];
      i1 = sldss->size[0];
      sldss->size[0] = loop_ub;
      emxEnsureCapacity((emxArray__common *)sldss, i1, (int)sizeof(double));
      for (i1 = 0; i1 < loop_ub; i1++) {
        sldss->data[i1] = allLayers->data[i1 + allLayers->size[0]];
      }

      emxInit_real_T1(&thicks, 1);
      loop_ub = allLayers->size[0];
      i1 = thicks->size[0];
      thicks->size[0] = loop_ub;
      emxEnsureCapacity((emxArray__common *)thicks, i1, (int)sizeof(double));
      for (i1 = 0; i1 < loop_ub; i1++) {
        thicks->data[i1] = allLayers->data[i1];
      }

      i1 = allLayers->size[0] - 1;
      rsub = allLayers->data[i1 + (allLayers->size[0] << 1)];
      i1 = allLayers->size[0];
      if (1 > i1 - 1) {
        i1 = 0;
      } else {
        i1 = allLayers->size[0] - 1;
      }

      emxInit_real_T1(&b_allLayers, 1);
      loop_ub = allLayers->size[0];
      b_loop_ub = i1 - 1;
      kstr = b_allLayers->size[0];
      b_allLayers->size[0] = loop_ub;
      emxEnsureCapacity((emxArray__common *)b_allLayers, kstr, (int)sizeof
                        (double));
      for (kstr = 0; kstr < loop_ub; kstr++) {
        b_allLayers->data[kstr] = allLayers->data[kstr + (allLayers->size[0] <<
          1)];
      }

      emxInit_real_T1(&roughs, 1);
      kstr = roughs->size[0];
      roughs->size[0] = i1 + 1;
      emxEnsureCapacity((emxArray__common *)roughs, kstr, (int)sizeof(double));
      roughs->data[0] = allRoughs;
      for (i1 = 0; i1 <= b_loop_ub; i1++) {
        roughs->data[i1 + 1] = b_allLayers->data[i1];
      }

      emxFree_real_T(&b_allLayers);
      if (allLayers->size[1] == 5) {
        emxInit_real_T1(&c_allLayers, 1);
        loop_ub = allLayers->size[0];
        b_loop_ub = allLayers->size[0];
        c_loop_ub = allLayers->size[0];
        kstr = roughs->size[0];
        d_loop_ub = allLayers->size[0];
        i1 = c_allLayers->size[0];
        c_allLayers->size[0] = d_loop_ub;
        emxEnsureCapacity((emxArray__common *)c_allLayers, i1, (int)sizeof
                          (double));
        for (i1 = 0; i1 < d_loop_ub; i1++) {
          c_allLayers->data[i1] = allLayers->data[i1 + allLayers->size[0] * 3];
        }

        i1 = layers->size[0] * layers->size[1];
        layers->size[0] = loop_ub;
        layers->size[1] = 4;
        emxEnsureCapacity((emxArray__common *)layers, i1, (int)sizeof(double));
        for (i1 = 0; i1 < loop_ub; i1++) {
          layers->data[i1] = thicks->data[i1];
        }

        for (i1 = 0; i1 < b_loop_ub; i1++) {
          layers->data[i1 + layers->size[0]] = sldss->data[i1];
        }

        for (i1 = 0; i1 < kstr; i1++) {
          layers->data[i1 + (layers->size[0] << 1)] = roughs->data[i1];
        }

        for (i1 = 0; i1 < c_loop_ub; i1++) {
          layers->data[i1 + layers->size[0] * 3] = c_allLayers->data[i1];
        }

        emxFree_real_T(&c_allLayers);
      } else {
        loop_ub = allLayers->size[0];
        b_loop_ub = allLayers->size[0];
        kstr = roughs->size[0];
        i1 = layers->size[0] * layers->size[1];
        layers->size[0] = loop_ub;
        layers->size[1] = 3;
        emxEnsureCapacity((emxArray__common *)layers, i1, (int)sizeof(double));
        for (i1 = 0; i1 < loop_ub; i1++) {
          layers->data[i1] = thicks->data[i1];
        }

        for (i1 = 0; i1 < b_loop_ub; i1++) {
          layers->data[i1 + layers->size[0]] = sldss->data[i1];
        }

        for (i1 = 0; i1 < kstr; i1++) {
          layers->data[i1 + (layers->size[0] << 1)] = roughs->data[i1];
        }
      }

      emxFree_real_T(&thicks);
      emxFree_real_T(&sldss);
      emxFree_real_T(&roughs);
      break;
    }

    /* Deal with the %coverage if present */
    for (i1 = 0; i1 < 2; i1++) {
      n[i1] = (unsigned int)allLayers->size[i1];
    }

    if ((int)n[1] == 5) {
      for (kstr = 0; kstr < (int)n[0]; kstr++) {
        if (allLayers->data[kstr + (allLayers->size[0] << 2)] == 1.0) {
          pc_add = nbsubs;
        } else {
          pc_add = nbair;
        }

        if (!rtIsNaN(allLayers->data[kstr + allLayers->size[0] * 3])) {
          layers->data[kstr + layers->size[0]] = pc_add * (allLayers->data[kstr
            + allLayers->size[0] * 3] / 100.0) + (1.0 - allLayers->data[kstr +
            allLayers->size[0] * 3] / 100.0) * layers->data[kstr + layers->size
            [0]];
        }
      }
    }
  }

  /*      problem.layers{i} = layers; */
  /*      problem.ssubs(i) = s_sub; */
  loop_ub = layers->size[0];
  i1 = outLayers->size[0] * outLayers->size[1];
  outLayers->size[0] = loop_ub;
  outLayers->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)outLayers, i1, (int)sizeof(double));
  for (i1 = 0; i1 < 3; i1++) {
    for (kstr = 0; kstr < loop_ub; kstr++) {
      outLayers->data[kstr + outLayers->size[0] * i1] = layers->data[kstr +
        layers->size[0] * i1];
    }
  }

  emxFree_real_T(&layers);
  *outSsubs = rsub;

  /* end */
}

/* End of code generation (groupLayers_Mod.c) */
