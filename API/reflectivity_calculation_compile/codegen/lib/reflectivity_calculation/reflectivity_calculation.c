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
#include <string.h>

/* Function Definitions */
void reflectivity_calculation(const struct0_T *problemDef, const cell_10
  *problemDef_cells, const struct1_T *problemDef_limits, const struct2_T
  *controls, struct4_T *problem, cell_13 *result)
{
  emxArray_cell_wrap_11 *reflectivity;
  int ret;
  int loop_ub;
  int i;
  emxArray_cell_wrap_11 *Simulation;
  emxArray_cell_wrap_12 *shifted_data;
  emxArray_cell_wrap_12 *layerSlds;
  emxArray_cell_wrap_11 *sldProfiles;
  char whichTF[10];
  static const char b[10] = { 's', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'T', 'F' };

  emxArray_int8_T *cell6;
  int b_ret;
  emxArray_cell_wrap_11 *cell1;
  char type[6];
  int b_loop_ub;
  emxArray_cell_wrap_12 *cell3;
  static const char b_b[6] = { 'l', 'a', 'y', 'e', 'r', 's' };

  int c_ret;
  emxArray_cell_wrap_14 *allLayers;
  (void)problemDef_limits;
  emxInit_cell_wrap_11(&reflectivity, 1);

  /*  global RAT_DEBUG DEBUGVARS */
  /*  if coder.target('MATLAB') */
  /*      RAT_DEBUG = 0; DEBUGVARS = 0; */
  /*  end */
  /* Preallocatin of outputs */
  ret = problem->ssubs->size[0];
  problem->ssubs->size[0] = 1;
  emxEnsureCapacity_real_T(problem->ssubs, ret);
  problem->ssubs->data[0] = 0.0;
  ret = problem->backgrounds->size[0];
  problem->backgrounds->size[0] = 1;
  emxEnsureCapacity_real_T(problem->backgrounds, ret);
  problem->backgrounds->data[0] = 0.0;
  ret = problem->qshifts->size[0];
  problem->qshifts->size[0] = 1;
  emxEnsureCapacity_real_T(problem->qshifts, ret);
  problem->qshifts->data[0] = 0.0;
  ret = problem->scalefactors->size[0];
  problem->scalefactors->size[0] = 1;
  emxEnsureCapacity_real_T(problem->scalefactors, ret);
  problem->scalefactors->data[0] = 0.0;
  ret = problem->nbairs->size[0];
  problem->nbairs->size[0] = 1;
  emxEnsureCapacity_real_T(problem->nbairs, ret);
  problem->nbairs->data[0] = 0.0;
  ret = problem->nbsubs->size[0];
  problem->nbsubs->size[0] = 1;
  emxEnsureCapacity_real_T(problem->nbsubs, ret);
  problem->nbsubs->data[0] = 0.0;
  ret = problem->resolutions->size[0];
  problem->resolutions->size[0] = 1;
  emxEnsureCapacity_real_T(problem->resolutions, ret);
  problem->resolutions->data[0] = 0.0;
  ret = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = 1;
  emxEnsureCapacity_real_T(problem->calculations.all_chis, ret);
  problem->calculations.all_chis->data[0] = 0.0;
  problem->calculations.sum_chi = 0.0;
  ret = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = 1;
  emxEnsureCapacity_real_T(problem->allSubRough, ret);
  problem->allSubRough->data[0] = 0.0;
  loop_ub = (int)problemDef->numberOfContrasts;
  ret = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_11(reflectivity, ret);
  for (i = 0; i < loop_ub; i++) {
    ret = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[0] = 2;
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(reflectivity->data[i].f1, ret);
    reflectivity->data[i].f1->data[0] = 1.0;
    reflectivity->data[i].f1->data[1] = 1.0;
    reflectivity->data[i].f1->data[2] = 1.0;
    reflectivity->data[i].f1->data[3] = 1.0;
  }

  emxInit_cell_wrap_11(&Simulation, 1);
  ret = Simulation->size[0];
  Simulation->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_11(Simulation, ret);
  for (i = 0; i < loop_ub; i++) {
    ret = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
    Simulation->data[i].f1->size[0] = 2;
    Simulation->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(Simulation->data[i].f1, ret);
    Simulation->data[i].f1->data[0] = 1.0;
    Simulation->data[i].f1->data[1] = 1.0;
    Simulation->data[i].f1->data[2] = 1.0;
    Simulation->data[i].f1->data[3] = 1.0;
  }

  emxInit_cell_wrap_12(&shifted_data, 1);
  ret = shifted_data->size[0];
  shifted_data->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_12(shifted_data, ret);
  for (i = 0; i < loop_ub; i++) {
    ret = shifted_data->data[i].f1->size[0] * shifted_data->data[i].f1->size[1];
    shifted_data->data[i].f1->size[0] = 2;
    shifted_data->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(shifted_data->data[i].f1, ret);
    for (ret = 0; ret < 6; ret++) {
      shifted_data->data[i].f1->data[ret] = 1.0;
    }
  }

  emxInit_cell_wrap_12(&layerSlds, 1);
  ret = layerSlds->size[0];
  layerSlds->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_12(layerSlds, ret);
  for (i = 0; i < loop_ub; i++) {
    ret = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
    layerSlds->data[i].f1->size[0] = 2;
    layerSlds->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(layerSlds->data[i].f1, ret);
    for (ret = 0; ret < 6; ret++) {
      layerSlds->data[i].f1->data[ret] = 1.0;
    }
  }

  emxInit_cell_wrap_11(&sldProfiles, 1);
  ret = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_11(sldProfiles, ret);
  for (i = 0; i < loop_ub; i++) {
    ret = sldProfiles->data[i].f1->size[0] * sldProfiles->data[i].f1->size[1];
    sldProfiles->data[i].f1->size[0] = 2;
    sldProfiles->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sldProfiles->data[i].f1, ret);
    sldProfiles->data[i].f1->data[0] = 1.0;
    sldProfiles->data[i].f1->data[1] = 1.0;
    sldProfiles->data[i].f1->data[2] = 1.0;
    sldProfiles->data[i].f1->data[3] = 1.0;
  }

  /* Decide which target function we are calling */
  for (ret = 0; ret < 10; ret++) {
    whichTF[ret] = problemDef->TF[ret];
  }

  ret = memcmp(&whichTF[0], &b[0], 10);
  emxInit_int8_T(&cell6, 1);
  if (ret == 0) {
    b_ret = 0;
  } else {
    b_ret = -1;
  }

  switch (b_ret) {
   case 0:
    /* Decide what kind of calculation it is and call the appropriate one */
    for (ret = 0; ret < 6; ret++) {
      type[ret] = problemDef->modelType[ret];
    }

    /* result = cell(1,6); */
    ret = problem->ssubs->size[0];
    problem->ssubs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->ssubs, ret);
    for (ret = 0; ret < loop_ub; ret++) {
      problem->ssubs->data[ret] = 0.0;
    }

    ret = problem->backgrounds->size[0];
    problem->backgrounds->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->backgrounds, ret);
    for (ret = 0; ret < loop_ub; ret++) {
      problem->backgrounds->data[ret] = 0.0;
    }

    ret = problem->qshifts->size[0];
    problem->qshifts->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->qshifts, ret);
    for (ret = 0; ret < loop_ub; ret++) {
      problem->qshifts->data[ret] = 0.0;
    }

    ret = problem->scalefactors->size[0];
    problem->scalefactors->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->scalefactors, ret);
    for (ret = 0; ret < loop_ub; ret++) {
      problem->scalefactors->data[ret] = 0.0;
    }

    ret = problem->nbairs->size[0];
    problem->nbairs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->nbairs, ret);
    for (ret = 0; ret < loop_ub; ret++) {
      problem->nbairs->data[ret] = 0.0;
    }

    ret = problem->nbsubs->size[0];
    problem->nbsubs->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->nbsubs, ret);
    for (ret = 0; ret < loop_ub; ret++) {
      problem->nbsubs->data[ret] = 0.0;
    }

    ret = problem->resolutions->size[0];
    problem->resolutions->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->resolutions, ret);
    for (ret = 0; ret < loop_ub; ret++) {
      problem->resolutions->data[ret] = 0.0;
    }

    ret = cell6->size[0];
    cell6->size[0] = loop_ub;
    emxEnsureCapacity_int8_T(cell6, ret);
    for (ret = 0; ret < loop_ub; ret++) {
      cell6->data[ret] = 0;
    }

    ret = problem->calculations.all_chis->size[0];
    problem->calculations.all_chis->size[0] = cell6->size[0];
    emxEnsureCapacity_real_T(problem->calculations.all_chis, ret);
    b_loop_ub = cell6->size[0];
    for (ret = 0; ret < b_loop_ub; ret++) {
      problem->calculations.all_chis->data[ret] = cell6->data[ret];
    }

    problem->calculations.sum_chi = 0.0;
    ret = problem->allSubRough->size[0];
    problem->allSubRough->size[0] = loop_ub;
    emxEnsureCapacity_real_T(problem->allSubRough, ret);
    for (ret = 0; ret < loop_ub; ret++) {
      problem->allSubRough->data[ret] = 0.0;
    }

    /*  coder.varsize('problem.backgrounds',[Inf,1],[1 0]);  */
    /*  coder.varsize('problem.qshifts',[Inf,1],[1 0]);  */
    /*  coder.varsize('problem.scalefactors',[Inf,1],[1 0]);    */
    /*  coder.varsize('problem.nbairs',[Inf,1],[1 0]);    */
    /*  coder.varsize('problem.nbsubs',[Inf,1],[1 0]);    */
    /*  coder.varsize('problem.resolutions',[Inf,1],[1 0]);    */
    /*  coder.varsize('problem.allSubRough',[Inf,1],[1 0]);   */
    ret = reflectivity->size[0];
    reflectivity->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_11(reflectivity, ret);
    for (i = 0; i < loop_ub; i++) {
      ret = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
      reflectivity->data[i].f1->size[0] = 2;
      reflectivity->data[i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(reflectivity->data[i].f1, ret);
      reflectivity->data[i].f1->data[0] = 1.0;
      reflectivity->data[i].f1->data[1] = 1.0;
      reflectivity->data[i].f1->data[2] = 1.0;
      reflectivity->data[i].f1->data[3] = 1.0;
    }

    /*  coder.varsize('reflectivity{:}',[Inf 2],[1 0]); */
    /*   */
    ret = Simulation->size[0];
    Simulation->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_11(Simulation, ret);
    for (i = 0; i < loop_ub; i++) {
      ret = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
      Simulation->data[i].f1->size[0] = 2;
      Simulation->data[i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(Simulation->data[i].f1, ret);
      Simulation->data[i].f1->data[0] = 1.0;
      Simulation->data[i].f1->data[1] = 1.0;
      Simulation->data[i].f1->data[2] = 1.0;
      Simulation->data[i].f1->data[3] = 1.0;
    }

    /*  coder.varsize('Simulation{:}',[Inf 2],[1 0]); */
    /*   */
    ret = shifted_data->size[0];
    shifted_data->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_12(shifted_data, ret);
    for (i = 0; i < loop_ub; i++) {
      ret = shifted_data->data[i].f1->size[0] * shifted_data->data[i].f1->size[1];
      shifted_data->data[i].f1->size[0] = 2;
      shifted_data->data[i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(shifted_data->data[i].f1, ret);
      for (ret = 0; ret < 6; ret++) {
        shifted_data->data[i].f1->data[ret] = 1.0;
      }
    }

    /*  coder.varsize('shifted_data{:}',[Inf 3],[1 0]); */
    /*   */
    ret = layerSlds->size[0];
    layerSlds->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_12(layerSlds, ret);
    for (i = 0; i < loop_ub; i++) {
      ret = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
      layerSlds->data[i].f1->size[0] = 2;
      layerSlds->data[i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(layerSlds->data[i].f1, ret);
      for (ret = 0; ret < 6; ret++) {
        layerSlds->data[i].f1->data[ret] = 1.0;
      }
    }

    /*  coder.varsize('layerSlds{:}',[Inf 3],[1 0]); */
    /*   */
    ret = sldProfiles->size[0];
    sldProfiles->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_11(sldProfiles, ret);
    for (i = 0; i < loop_ub; i++) {
      ret = sldProfiles->data[i].f1->size[0] * sldProfiles->data[i].f1->size[1];
      sldProfiles->data[i].f1->size[0] = 2;
      sldProfiles->data[i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(sldProfiles->data[i].f1, ret);
      sldProfiles->data[i].f1->data[0] = 1.0;
      sldProfiles->data[i].f1->data[1] = 1.0;
      sldProfiles->data[i].f1->data[2] = 1.0;
      sldProfiles->data[i].f1->data[3] = 1.0;
    }

    /*  coder.varsize('sldProfiles{:}',[Inf 2],[1 0]); */
    /*   */
    /*  coder.varsize('allLayers{:}',[Inf 3],[1 1]); */
    ret = memcmp(&type[0], &b_b[0], 6);
    if (ret == 0) {
      c_ret = 0;
    } else {
      c_ret = -1;
    }

    switch (c_ret) {
     case 0:
      emxInit_cell_wrap_14(&allLayers, 1);
      c_standardTF_stanLay_reflectivi(problemDef, problemDef_cells, controls,
        problem, reflectivity, Simulation, shifted_data, layerSlds, sldProfiles,
        allLayers);

      /* case 'custom layers' */
      /*     [problem,reflectivity,Simulation,shifted_data,layerSlds,sldProfiles,allLayers] = standardTF_custLay_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls); */
      /* case 'custXY' */
      /* problem = standardTF_custXY_reflectivityCalculation(problemDef,problemDef_cells,controls); */
      emxFree_cell_wrap_14(&allLayers);
      break;
    }

    /* case 'oilWaterTF' */
    /* problem = oilWaterTF_reflectivityCalculation(problemDef,problemDef_cells,controls);     */
    /* case 'polarisedTF' */
    /* problem = polarisedTF_reflectivityCalculation(problemDef,problemDef_cells,controls); */
    /* case 'domainsTF' */
    /* problem = domainsTF_reflectivityCalculation(problemDef,problemDef_cells,controls); */
    break;
  }

  emxInit_cell_wrap_11(&cell1, 1);

  /* cell1Length = numberOfContrasts; */
  ret = cell1->size[0];
  cell1->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_11(cell1, ret);
  for (i = 0; i < loop_ub; i++) {
    ret = cell1->data[i].f1->size[0] * cell1->data[i].f1->size[1];
    cell1->data[i].f1->size[0] = reflectivity->data[i].f1->size[0];
    cell1->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(cell1->data[i].f1, ret);
    b_loop_ub = reflectivity->data[i].f1->size[0] * reflectivity->data[i]
      .f1->size[1];
    for (ret = 0; ret < b_loop_ub; ret++) {
      cell1->data[i].f1->data[ret] = reflectivity->data[i].f1->data[ret];
    }
  }

  ret = result->f1->size[0];
  result->f1->size[0] = cell1->size[0];
  emxEnsureCapacity_cell_wrap_11(result->f1, ret);
  b_loop_ub = cell1->size[0];
  for (ret = 0; ret < b_loop_ub; ret++) {
    emxCopyStruct_cell_wrap_11(&result->f1->data[ret], &cell1->data[ret]);
  }

  emxFree_cell_wrap_11(&cell1);

  /*  cell2Length = 7; */
  ret = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_11(reflectivity, ret);
  for (i = 0; i < loop_ub; i++) {
    ret = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[0] = Simulation->data[i].f1->size[0];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(reflectivity->data[i].f1, ret);
    b_loop_ub = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
    for (ret = 0; ret < b_loop_ub; ret++) {
      reflectivity->data[i].f1->data[ret] = Simulation->data[i].f1->data[ret];
    }
  }

  emxFree_cell_wrap_11(&Simulation);
  ret = result->f2->size[0];
  result->f2->size[0] = reflectivity->size[0];
  emxEnsureCapacity_cell_wrap_11(result->f2, ret);
  b_loop_ub = reflectivity->size[0];
  for (ret = 0; ret < b_loop_ub; ret++) {
    emxCopyStruct_cell_wrap_11(&result->f2->data[ret], &reflectivity->data[ret]);
  }

  emxInit_cell_wrap_12(&cell3, 1);

  /*   */
  /*  cell3Length = 7; */
  ret = cell3->size[0];
  cell3->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_12(cell3, ret);
  for (i = 0; i < loop_ub; i++) {
    ret = cell3->data[i].f1->size[0] * cell3->data[i].f1->size[1];
    cell3->data[i].f1->size[0] = shifted_data->data[i].f1->size[0];
    cell3->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(cell3->data[i].f1, ret);
    b_loop_ub = shifted_data->data[i].f1->size[0] * shifted_data->data[i]
      .f1->size[1];
    for (ret = 0; ret < b_loop_ub; ret++) {
      cell3->data[i].f1->data[ret] = shifted_data->data[i].f1->data[ret];
    }
  }

  ret = result->f3->size[0];
  result->f3->size[0] = cell3->size[0];
  emxEnsureCapacity_cell_wrap_12(result->f3, ret);
  b_loop_ub = cell3->size[0];
  for (ret = 0; ret < b_loop_ub; ret++) {
    emxCopyStruct_cell_wrap_12(&result->f3->data[ret], &cell3->data[ret]);
  }

  emxFree_cell_wrap_12(&cell3);

  /*   */
  /*  cell4Length = 7; */
  ret = shifted_data->size[0];
  shifted_data->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_12(shifted_data, ret);
  for (i = 0; i < loop_ub; i++) {
    ret = shifted_data->data[i].f1->size[0] * shifted_data->data[i].f1->size[1];
    shifted_data->data[i].f1->size[0] = layerSlds->data[i].f1->size[0];
    shifted_data->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(shifted_data->data[i].f1, ret);
    b_loop_ub = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
    for (ret = 0; ret < b_loop_ub; ret++) {
      shifted_data->data[i].f1->data[ret] = layerSlds->data[i].f1->data[ret];
    }
  }

  emxFree_cell_wrap_12(&layerSlds);
  ret = result->f4->size[0];
  result->f4->size[0] = shifted_data->size[0];
  emxEnsureCapacity_cell_wrap_12(result->f4, ret);
  b_loop_ub = shifted_data->size[0];
  for (ret = 0; ret < b_loop_ub; ret++) {
    emxCopyStruct_cell_wrap_12(&result->f4->data[ret], &shifted_data->data[ret]);
  }

  emxFree_cell_wrap_12(&shifted_data);

  /*   */
  /*  cell5Length = 7; */
  ret = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_11(reflectivity, ret);
  for (i = 0; i < loop_ub; i++) {
    ret = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[0] = sldProfiles->data[i].f1->size[0];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(reflectivity->data[i].f1, ret);
    b_loop_ub = sldProfiles->data[i].f1->size[0] * sldProfiles->data[i].f1->
      size[1];
    for (ret = 0; ret < b_loop_ub; ret++) {
      reflectivity->data[i].f1->data[ret] = sldProfiles->data[i].f1->data[ret];
    }
  }

  emxFree_cell_wrap_11(&sldProfiles);
  ret = result->f5->size[0];
  result->f5->size[0] = reflectivity->size[0];
  emxEnsureCapacity_cell_wrap_11(result->f5, ret);
  b_loop_ub = reflectivity->size[0];
  for (ret = 0; ret < b_loop_ub; ret++) {
    emxCopyStruct_cell_wrap_11(&result->f5->data[ret], &reflectivity->data[ret]);
  }

  emxFree_cell_wrap_11(&reflectivity);

  /*   */
  /*  cell6Length = 7; */
  ret = cell6->size[0];
  cell6->size[0] = loop_ub;
  emxEnsureCapacity_int8_T(cell6, ret);
  for (i = 0; i < loop_ub; i++) {
    cell6->data[i] = 0;
  }

  ret = result->f6->size[0];
  result->f6->size[0] = cell6->size[0];
  emxEnsureCapacity_real_T(result->f6, ret);
  loop_ub = cell6->size[0];
  for (ret = 0; ret < loop_ub; ret++) {
    result->f6->data[ret] = cell6->data[ret];
  }

  emxFree_int8_T(&cell6);

  /*  coder.varsize('problem.ssubs',[Inf 1],[1 0]); */
  /*  coder.varsize('problem.backgrounds',[Inf 1],[1 0]); */
  /*  coder.varsize('problem.qshifts',[Inf 1],[1 0]); */
  /*  coder.varsize('problem.scalefactors',[Inf 1],[1 0]); */
  /*  coder.varsize('problem.nbairs',[Inf 1],[1 0]); */
  /*  coder.varsize('problem.nbsubs',[Inf 1],[1 0]); */
  /*  coder.varsize('problem.resolutions',[Inf 1],[1 0]); */
  /*  coder.varsize('problem.ssubs',[Inf 1],[1 0]); */
  /*  coder.varsize('problem.calculations.all_chis',[Inf 1],[1 0]); */
  /*  coder.varsize('problem.calculations.sum_chi',[1 1],[0 0]); */
  /*  coder.varsize('problem.allSubRough',[Inf 1],[1 0]); */
  /*  if coder.target('MATLAB') */
  /*      if RAT_DEBUG */
  /*          DEBUGVARS.reflectivity_calculation.problem = problem; */
  /*          DEBUGVARS.reflectivity_calculation.result = result; */
  /*      end */
  /*  end */
}

/* End of code generation (reflectivity_calculation.c) */
