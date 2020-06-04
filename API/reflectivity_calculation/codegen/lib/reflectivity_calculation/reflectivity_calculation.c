/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation.c
 *
 * Code generation for function 'reflectivity_calculation'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_emxutil.h"
#include "standardTF_stanLay_reflectivityCalculation.h"

/* Function Declarations */
static void b_cast(const emxArray_cell_wrap_1 *x, emxArray_cell_wrap_6 *y);
static void cast(const emxArray_cell_wrap_9 *x, emxArray_cell_wrap_5 *y);

/* Function Definitions */
static void b_cast(const emxArray_cell_wrap_1 *x, emxArray_cell_wrap_6 *y)
{
  int n;
  int j;
  int b_j;
  n = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_cell_wrap_6(y, n);
  for (j = 0; j < x->size[0]; j++) {
    n = y->data[j].f1->size[0] * y->data[j].f1->size[1];
    y->data[j].f1->size[0] = x->data[j].f1->size[0];
    y->data[j].f1->size[1] = 3;
    emxEnsureCapacity_real_T(y->data[j].f1, n);
    n = x->data[j].f1->size[0] * 3;
    for (b_j = 0; b_j < n; b_j++) {
      y->data[j].f1->data[b_j] = x->data[j].f1->data[b_j];
    }
  }
}

static void cast(const emxArray_cell_wrap_9 *x, emxArray_cell_wrap_5 *y)
{
  int n;
  int j;
  int b_j;
  n = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_cell_wrap_5(y, n);
  for (j = 0; j < x->size[0]; j++) {
    n = y->data[j].f1->size[0] * y->data[j].f1->size[1];
    y->data[j].f1->size[0] = x->data[j].f1->size[0];
    y->data[j].f1->size[1] = 2;
    emxEnsureCapacity_real_T(y->data[j].f1, n);
    n = x->data[j].f1->size[0] << 1;
    for (b_j = 0; b_j < n; b_j++) {
      y->data[j].f1->data[b_j] = x->data[j].f1->data[b_j];
    }
  }
}

void reflectivity_calculation(const struct0_T *problemDef, const cell_4
  *problemDef_cells, const struct1_T *problemDef_limits, const struct2_T
  *controls, struct4_T *problem, cell_7 *result)
{
  emxArray_cell_wrap_5 *reflectivity;
  int kstr;
  int loop_ub;
  int i;
  emxArray_cell_wrap_5 *Simulation;
  emxArray_cell_wrap_6 *shifted_data;
  emxArray_cell_wrap_6 *layerSlds;
  emxArray_cell_wrap_5 *sldProfiles;
  boolean_T b_bool;
  emxArray_int8_T *cell6;
  int exitg1;
  int c_bool;
  static const char cv0[10] = { 's', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'T', 'F'
  };

  emxArray_cell_wrap_5 *cell1;
  int b_loop_ub;
  emxArray_cell_wrap_6 *cell3;
  emxArray_cell_wrap_9 *b_reflectivity;
  emxArray_cell_wrap_9 *b_Simulation;
  emxArray_cell_wrap_1 *b_shifted_data;
  emxArray_cell_wrap_1 *b_layerSlds;
  emxArray_cell_wrap_9 *b_sldProfiles;
  int d_bool;
  static const char cv1[6] = { 'l', 'a', 'y', 'e', 'r', 's' };

  emxArray_cell_wrap_8 *allLayers;
  (void)problemDef_limits;
  emxInit_cell_wrap_5(&reflectivity, 1);

  /* Preallocatin of outputs */
  kstr = problem->ssubs->size[0];
  problem->ssubs->size[0] = 1;
  emxEnsureCapacity_real_T(problem->ssubs, kstr);
  problem->ssubs->data[0] = 0.0;
  kstr = problem->backgrounds->size[0];
  problem->backgrounds->size[0] = 1;
  emxEnsureCapacity_real_T(problem->backgrounds, kstr);
  problem->backgrounds->data[0] = 0.0;
  kstr = problem->qshifts->size[0];
  problem->qshifts->size[0] = 1;
  emxEnsureCapacity_real_T(problem->qshifts, kstr);
  problem->qshifts->data[0] = 0.0;
  kstr = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = 1;
  emxEnsureCapacity_real_T(problem->scalefactors, kstr);
  problem->scalefactors->data[0] = 0.0;
  kstr = problem->nbairs->size[0];
  problem->nbairs->size[0] = 1;
  emxEnsureCapacity_real_T(problem->nbairs, kstr);
  problem->nbairs->data[0] = 0.0;
  kstr = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = 1;
  emxEnsureCapacity_real_T(problem->nbsubs, kstr);
  problem->nbsubs->data[0] = 0.0;
  kstr = problem->resolutions->size[0];
  problem->resolutions->size[0] = 1;
  emxEnsureCapacity_real_T(problem->resolutions, kstr);
  problem->resolutions->data[0] = 0.0;
  kstr = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = 1;
  emxEnsureCapacity_real_T(problem->calculations.all_chis, kstr);
  problem->calculations.all_chis->data[0] = 0.0;
  problem->calculations.sum_chi = 0.0;
  kstr = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = 1;
  emxEnsureCapacity_real_T(problem->allSubRough, kstr);
  problem->allSubRough->data[0] = 0.0;
  loop_ub = (int)problemDef->numberOfContrasts;
  kstr = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_5(reflectivity, kstr);
  for (i = 0; i < loop_ub; i++) {
    kstr = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[0] = 2;
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(reflectivity->data[i].f1, kstr);
    reflectivity->data[i].f1->data[0] = 1.0;
    reflectivity->data[i].f1->data[1] = 1.0;
    reflectivity->data[i].f1->data[2] = 1.0;
    reflectivity->data[i].f1->data[3] = 1.0;
  }

  emxInit_cell_wrap_5(&Simulation, 1);
  kstr = Simulation->size[0];
  Simulation->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_5(Simulation, kstr);
  for (i = 0; i < loop_ub; i++) {
    kstr = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
    Simulation->data[i].f1->size[0] = 2;
    Simulation->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(Simulation->data[i].f1, kstr);
    Simulation->data[i].f1->data[0] = 1.0;
    Simulation->data[i].f1->data[1] = 1.0;
    Simulation->data[i].f1->data[2] = 1.0;
    Simulation->data[i].f1->data[3] = 1.0;
  }

  emxInit_cell_wrap_6(&shifted_data, 1);
  kstr = shifted_data->size[0];
  shifted_data->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_6(shifted_data, kstr);
  for (i = 0; i < loop_ub; i++) {
    kstr = shifted_data->data[i].f1->size[0] * shifted_data->data[i].f1->size[1];
    shifted_data->data[i].f1->size[0] = 2;
    shifted_data->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(shifted_data->data[i].f1, kstr);
    for (kstr = 0; kstr < 6; kstr++) {
      shifted_data->data[i].f1->data[kstr] = 1.0;
    }
  }

  emxInit_cell_wrap_6(&layerSlds, 1);
  kstr = layerSlds->size[0];
  layerSlds->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_6(layerSlds, kstr);
  for (i = 0; i < loop_ub; i++) {
    kstr = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
    layerSlds->data[i].f1->size[0] = 2;
    layerSlds->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(layerSlds->data[i].f1, kstr);
    for (kstr = 0; kstr < 6; kstr++) {
      layerSlds->data[i].f1->data[kstr] = 1.0;
    }
  }

  emxInit_cell_wrap_5(&sldProfiles, 1);
  kstr = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_5(sldProfiles, kstr);
  for (i = 0; i < loop_ub; i++) {
    kstr = sldProfiles->data[i].f1->size[0] * sldProfiles->data[i].f1->size[1];
    sldProfiles->data[i].f1->size[0] = 2;
    sldProfiles->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sldProfiles->data[i].f1, kstr);
    sldProfiles->data[i].f1->data[0] = 1.0;
    sldProfiles->data[i].f1->data[1] = 1.0;
    sldProfiles->data[i].f1->data[2] = 1.0;
    sldProfiles->data[i].f1->data[3] = 1.0;
  }

  /* Decide which target function we are calling */
  b_bool = false;
  if (problemDef->TF->size[1] == 10) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 10) {
        if (problemDef->TF->data[kstr] != cv0[kstr]) {
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

  emxInit_int8_T(&cell6, 1);
  if (b_bool) {
    c_bool = 0;
  } else {
    c_bool = -1;
  }

  switch (c_bool) {
   case 0:
    /* Decide what kind of calculation it is and call the appropriate one */
    /* result = cell(1,6); */
    kstr = problem->ssubs->size[0];
    problem->ssubs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->ssubs, kstr);
    for (kstr = 0; kstr < loop_ub; kstr++) {
      problem->ssubs->data[kstr] = 0.0;
    }

    kstr = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->backgrounds, kstr);
    for (kstr = 0; kstr < loop_ub; kstr++) {
      problem->backgrounds->data[kstr] = 0.0;
    }

    kstr = problem->qshifts->size[0];
    problem->qshifts->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->qshifts, kstr);
    for (kstr = 0; kstr < loop_ub; kstr++) {
      problem->qshifts->data[kstr] = 0.0;
    }

    kstr = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->scalefactors, kstr);
    for (kstr = 0; kstr < loop_ub; kstr++) {
      problem->scalefactors->data[kstr] = 0.0;
    }

    kstr = problem->nbairs->size[0];
    problem->nbairs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->nbairs, kstr);
    for (kstr = 0; kstr < loop_ub; kstr++) {
      problem->nbairs->data[kstr] = 0.0;
    }

    kstr = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->nbsubs, kstr);
    for (kstr = 0; kstr < loop_ub; kstr++) {
      problem->nbsubs->data[kstr] = 0.0;
    }

    kstr = problem->resolutions->size[0];
    problem->resolutions->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->resolutions, kstr);
    for (kstr = 0; kstr < loop_ub; kstr++) {
      problem->resolutions->data[kstr] = 0.0;
    }

    kstr = cell6->size[0];
    cell6->size[0] = loop_ub;
    emxEnsureCapacity_int8_T(cell6, kstr);
    for (kstr = 0; kstr < loop_ub; kstr++) {
      cell6->data[kstr] = 0;
    }

    kstr = problem->calculations.all_chis->size[0];
    problem->calculations.all_chis->size[0] = cell6->size[0];
    emxEnsureCapacity_real_T(problem->calculations.all_chis, kstr);
    b_loop_ub = cell6->size[0];
    for (kstr = 0; kstr < b_loop_ub; kstr++) {
      problem->calculations.all_chis->data[kstr] = cell6->data[kstr];
    }

    problem->calculations.sum_chi = 0.0;
    kstr = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->allSubRough, kstr);
    for (kstr = 0; kstr < loop_ub; kstr++) {
      problem->allSubRough->data[kstr] = 0.0;
    }

    emxInit_cell_wrap_9(&b_reflectivity, 1);

    /*  coder.varsize('problem.backgrounds',[Inf,1],[1 0]);  */
    /*  coder.varsize('problem.qshifts',[Inf,1],[1 0]);  */
    /*  coder.varsize('problem.scalefactors',[Inf,1],[1 0]);    */
    /*  coder.varsize('problem.nbairs',[Inf,1],[1 0]);    */
    /*  coder.varsize('problem.nbsubs',[Inf,1],[1 0]);    */
    /*  coder.varsize('problem.resolutions',[Inf,1],[1 0]);    */
    /*  coder.varsize('problem.allSubRough',[Inf,1],[1 0]);   */
    kstr = b_reflectivity->size[0];
    b_reflectivity->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_9(b_reflectivity, kstr);
    for (i = 0; i < loop_ub; i++) {
      kstr = b_reflectivity->data[i].f1->size[0] * b_reflectivity->data[i]
        .f1->size[1];
      b_reflectivity->data[i].f1->size[0] = 2;
      b_reflectivity->data[i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(b_reflectivity->data[i].f1, kstr);
      b_reflectivity->data[i].f1->data[0] = 1.0;
      b_reflectivity->data[i].f1->data[1] = 1.0;
      b_reflectivity->data[i].f1->data[2] = 1.0;
      b_reflectivity->data[i].f1->data[3] = 1.0;
    }

    emxInit_cell_wrap_9(&b_Simulation, 1);

    /*  coder.varsize('reflectivity{:}',[Inf 2],[1 0]); */
    /*   */
    kstr = b_Simulation->size[0];
    b_Simulation->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_9(b_Simulation, kstr);
    for (i = 0; i < loop_ub; i++) {
      kstr = b_Simulation->data[i].f1->size[0] * b_Simulation->data[i].f1->size
        [1];
      b_Simulation->data[i].f1->size[0] = 2;
      b_Simulation->data[i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(b_Simulation->data[i].f1, kstr);
      b_Simulation->data[i].f1->data[0] = 1.0;
      b_Simulation->data[i].f1->data[1] = 1.0;
      b_Simulation->data[i].f1->data[2] = 1.0;
      b_Simulation->data[i].f1->data[3] = 1.0;
    }

    emxInit_cell_wrap_1(&b_shifted_data, 1);

    /*  coder.varsize('Simulation{:}',[Inf 2],[1 0]); */
    /*   */
    kstr = b_shifted_data->size[0];
    b_shifted_data->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_1(b_shifted_data, kstr);
    for (i = 0; i < loop_ub; i++) {
      kstr = b_shifted_data->data[i].f1->size[0] * b_shifted_data->data[i]
        .f1->size[1];
      b_shifted_data->data[i].f1->size[0] = 2;
      b_shifted_data->data[i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(b_shifted_data->data[i].f1, kstr);
      for (kstr = 0; kstr < 6; kstr++) {
        b_shifted_data->data[i].f1->data[kstr] = 1.0;
      }
    }

    emxInit_cell_wrap_1(&b_layerSlds, 1);

    /*  coder.varsize('shifted_data{:}',[Inf 3],[1 0]); */
    /*   */
    kstr = b_layerSlds->size[0];
    b_layerSlds->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_1(b_layerSlds, kstr);
    for (i = 0; i < loop_ub; i++) {
      kstr = b_layerSlds->data[i].f1->size[0] * b_layerSlds->data[i].f1->size[1];
      b_layerSlds->data[i].f1->size[0] = 2;
      b_layerSlds->data[i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(b_layerSlds->data[i].f1, kstr);
      for (kstr = 0; kstr < 6; kstr++) {
        b_layerSlds->data[i].f1->data[kstr] = 1.0;
      }
    }

    emxInit_cell_wrap_9(&b_sldProfiles, 1);

    /*  coder.varsize('layerSlds{:}',[Inf 3],[1 0]); */
    /*   */
    kstr = b_sldProfiles->size[0];
    b_sldProfiles->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_9(b_sldProfiles, kstr);
    for (i = 0; i < loop_ub; i++) {
      kstr = b_sldProfiles->data[i].f1->size[0] * b_sldProfiles->data[i]
        .f1->size[1];
      b_sldProfiles->data[i].f1->size[0] = 2;
      b_sldProfiles->data[i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(b_sldProfiles->data[i].f1, kstr);
      b_sldProfiles->data[i].f1->data[0] = 1.0;
      b_sldProfiles->data[i].f1->data[1] = 1.0;
      b_sldProfiles->data[i].f1->data[2] = 1.0;
      b_sldProfiles->data[i].f1->data[3] = 1.0;
    }

    /*  coder.varsize('sldProfiles{:}',[Inf 2],[1 0]); */
    /*   */
    /*  coder.varsize('allLayers{:}',[Inf 3],[1 1]); */
    b_bool = false;
    if (problemDef->modelType->size[1] == 6) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 6) {
          if (problemDef->modelType->data[kstr] != cv1[kstr]) {
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
      d_bool = 0;
    } else {
      d_bool = -1;
    }

    switch (d_bool) {
     case 0:
      emxInit_cell_wrap_8(&allLayers, 1);
      c_standardTF_stanLay_reflectivi(problemDef, problemDef_cells, controls,
        problem, b_reflectivity, b_Simulation, b_shifted_data, b_layerSlds,
        b_sldProfiles, allLayers);

      /* case 'custom layers' */
      /*     [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTF_custLay_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls); */
      /* case 'custXY' */
      /* problem = standardTF_custXY_reflectivityCalculation(problemDef,problemDef_cells,controls); */
      emxFree_cell_wrap_8(&allLayers);
      break;
    }

    cast(b_reflectivity, reflectivity);
    cast(b_Simulation, Simulation);
    b_cast(b_shifted_data, shifted_data);
    b_cast(b_layerSlds, layerSlds);
    cast(b_sldProfiles, sldProfiles);

    /* case 'oilWaterTF' */
    /* problem = oilWaterTF_reflectivityCalculation(problemDef,problemDef_cells,controls);     */
    /* case 'polarisedTF' */
    /* problem = polarisedTF_reflectivityCalculation(problemDef,problemDef_cells,controls); */
    /* case 'domainsTF' */
    /* problem = domainsTF_reflectivityCalculation(problemDef,problemDef_cells,controls); */
    emxFree_cell_wrap_9(&b_sldProfiles);
    emxFree_cell_wrap_1(&b_layerSlds);
    emxFree_cell_wrap_1(&b_shifted_data);
    emxFree_cell_wrap_9(&b_Simulation);
    emxFree_cell_wrap_9(&b_reflectivity);
    break;
  }

  emxInit_cell_wrap_5(&cell1, 1);

  /* cell1Length = numberOfContrasts; */
  kstr = cell1->size[0];
  cell1->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_5(cell1, kstr);
  for (i = 0; i < loop_ub; i++) {
    kstr = cell1->data[i].f1->size[0] * cell1->data[i].f1->size[1];
    cell1->data[i].f1->size[0] = reflectivity->data[i].f1->size[0];
    cell1->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(cell1->data[i].f1, kstr);
    b_loop_ub = reflectivity->data[i].f1->size[0] * reflectivity->data[i]
      .f1->size[1];
    for (kstr = 0; kstr < b_loop_ub; kstr++) {
      cell1->data[i].f1->data[kstr] = reflectivity->data[i].f1->data[kstr];
    }
  }

  kstr = result->f1->size[0];
  result->f1->size[0] = cell1->size[0];
  emxEnsureCapacity_cell_wrap_5(result->f1, kstr);
  b_loop_ub = cell1->size[0];
  for (kstr = 0; kstr < b_loop_ub; kstr++) {
    emxCopyStruct_cell_wrap_5(&result->f1->data[kstr], &cell1->data[kstr]);
  }

  emxFree_cell_wrap_5(&cell1);

  /*  cell2Length = 7; */
  kstr = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_5(reflectivity, kstr);
  for (i = 0; i < loop_ub; i++) {
    kstr = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[0] = Simulation->data[i].f1->size[0];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(reflectivity->data[i].f1, kstr);
    b_loop_ub = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
    for (kstr = 0; kstr < b_loop_ub; kstr++) {
      reflectivity->data[i].f1->data[kstr] = Simulation->data[i].f1->data[kstr];
    }
  }

  emxFree_cell_wrap_5(&Simulation);
  kstr = result->f2->size[0];
  result->f2->size[0] = reflectivity->size[0];
  emxEnsureCapacity_cell_wrap_5(result->f2, kstr);
  b_loop_ub = reflectivity->size[0];
  for (kstr = 0; kstr < b_loop_ub; kstr++) {
    emxCopyStruct_cell_wrap_5(&result->f2->data[kstr], &reflectivity->data[kstr]);
  }

  emxInit_cell_wrap_6(&cell3, 1);

  /*   */
  /*  cell3Length = 7; */
  kstr = cell3->size[0];
  cell3->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_6(cell3, kstr);
  for (i = 0; i < loop_ub; i++) {
    kstr = cell3->data[i].f1->size[0] * cell3->data[i].f1->size[1];
    cell3->data[i].f1->size[0] = shifted_data->data[i].f1->size[0];
    cell3->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(cell3->data[i].f1, kstr);
    b_loop_ub = shifted_data->data[i].f1->size[0] * shifted_data->data[i]
      .f1->size[1];
    for (kstr = 0; kstr < b_loop_ub; kstr++) {
      cell3->data[i].f1->data[kstr] = shifted_data->data[i].f1->data[kstr];
    }
  }

  kstr = result->f3->size[0];
  result->f3->size[0] = cell3->size[0];
  emxEnsureCapacity_cell_wrap_6(result->f3, kstr);
  b_loop_ub = cell3->size[0];
  for (kstr = 0; kstr < b_loop_ub; kstr++) {
    emxCopyStruct_cell_wrap_6(&result->f3->data[kstr], &cell3->data[kstr]);
  }

  emxFree_cell_wrap_6(&cell3);

  /*   */
  /*  cell4Length = 7; */
  kstr = shifted_data->size[0];
  shifted_data->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_6(shifted_data, kstr);
  for (i = 0; i < loop_ub; i++) {
    kstr = shifted_data->data[i].f1->size[0] * shifted_data->data[i].f1->size[1];
    shifted_data->data[i].f1->size[0] = layerSlds->data[i].f1->size[0];
    shifted_data->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(shifted_data->data[i].f1, kstr);
    b_loop_ub = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
    for (kstr = 0; kstr < b_loop_ub; kstr++) {
      shifted_data->data[i].f1->data[kstr] = layerSlds->data[i].f1->data[kstr];
    }
  }

  emxFree_cell_wrap_6(&layerSlds);
  kstr = result->f4->size[0];
  result->f4->size[0] = shifted_data->size[0];
  emxEnsureCapacity_cell_wrap_6(result->f4, kstr);
  b_loop_ub = shifted_data->size[0];
  for (kstr = 0; kstr < b_loop_ub; kstr++) {
    emxCopyStruct_cell_wrap_6(&result->f4->data[kstr], &shifted_data->data[kstr]);
  }

  emxFree_cell_wrap_6(&shifted_data);

  /*   */
  /*  cell5Length = 7; */
  kstr = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_5(reflectivity, kstr);
  for (i = 0; i < loop_ub; i++) {
    kstr = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[0] = sldProfiles->data[i].f1->size[0];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(reflectivity->data[i].f1, kstr);
    b_loop_ub = sldProfiles->data[i].f1->size[0] * sldProfiles->data[i].f1->
      size[1];
    for (kstr = 0; kstr < b_loop_ub; kstr++) {
      reflectivity->data[i].f1->data[kstr] = sldProfiles->data[i].f1->data[kstr];
    }
  }

  emxFree_cell_wrap_5(&sldProfiles);
  kstr = result->f5->size[0];
  result->f5->size[0] = reflectivity->size[0];
  emxEnsureCapacity_cell_wrap_5(result->f5, kstr);
  b_loop_ub = reflectivity->size[0];
  for (kstr = 0; kstr < b_loop_ub; kstr++) {
    emxCopyStruct_cell_wrap_5(&result->f5->data[kstr], &reflectivity->data[kstr]);
  }

  emxFree_cell_wrap_5(&reflectivity);

  /*   */
  /*  cell6Length = 7; */
  kstr = cell6->size[0];
  cell6->size[0] = loop_ub;
  emxEnsureCapacity_int8_T(cell6, kstr);
  for (i = 0; i < loop_ub; i++) {
    cell6->data[i] = 0;
  }

  kstr = result->f6->size[0];
  result->f6->size[0] = cell6->size[0];
  emxEnsureCapacity_real_T(result->f6, kstr);
  loop_ub = cell6->size[0];
  for (kstr = 0; kstr < loop_ub; kstr++) {
    result->f6->data[kstr] = cell6->data[kstr];
  }

  emxFree_int8_T(&cell6);
}

/* End of code generation (reflectivity_calculation.c) */
