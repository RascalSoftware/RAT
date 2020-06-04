/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanLay_reflectivityCalculation.c
 *
 * Code generation for function 'standardTF_stanLay_reflectivityCalculation'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "standardTF_stanLay_reflectivityCalculation.h"
#include "reflectivity_calculation_emxutil.h"
#include "sum.h"
#include "standardTF_stanlay_single.h"
#include <string.h>

/* Function Definitions */
void c_standardTF_stanLay_reflectivi(const struct0_T *problemDef, const cell_10 *
  problemDef_cells, const struct2_T *controls, struct4_T *problem,
  emxArray_cell_wrap_11 *reflectivity, emxArray_cell_wrap_11 *Simulation,
  emxArray_cell_wrap_12 *shifted_data, emxArray_cell_wrap_12 *layerSlds,
  emxArray_cell_wrap_11 *sldProfiles, emxArray_cell_wrap_14 *allLayers)
{
  int ret;
  int loop_ub;
  emxArray_real_T *chis;
  int i;
  char para[6];
  static const char b[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

  int b_ret;
  double problemDef_data[1];

  /*   */
  /*  global RAT_DEBUG DEBUGVARS */
  /* Extract individual parameters from problemDef */
  /* nbairs = problemDef.nbairs; */
  /* nbsubs = problemDef.nbsubs; */
  /* repeats = problemDef.repeatLayers; */
  /* allData = problemDef.allData; */
  /* dataLimits = problemDef.dataLimits; */
  /* simLimits = problemDef.simLimits; */
  /* repeatLayers = problemDef.repeatLayers; */
  /* contrastLayers = problemDef.contrastLayers; */
  /* layersDetails = problemDef.layersDetails; */
  /* Pre-allocation */
  ret = problem->ssubs->size[0];
  problem->ssubs->size[0] = 1;
  emxEnsureCapacity_real_T(problem->ssubs, ret);
  problem->ssubs->data[0] = problemDef->params[0];
  ret = problem->backgrounds->size[0];
  loop_ub = (int)problemDef->numberOfContrasts;
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

  emxInit_real_T(&chis, 1);
  ret = chis->size[0];
  chis->size[0] = loop_ub;
  emxEnsureCapacity_real_T(chis, ret);
  for (ret = 0; ret < loop_ub; ret++) {
    chis->data[ret] = 0.0;
  }

  ret = problem->resolutions->size[0];
  problem->resolutions->size[0] = loop_ub;
  emxEnsureCapacity_real_T(problem->resolutions, ret);
  for (ret = 0; ret < loop_ub; ret++) {
    problem->resolutions->data[ret] = 0.0;
  }

  ret = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = loop_ub;
  emxEnsureCapacity_real_T(problem->allSubRough, ret);
  for (ret = 0; ret < loop_ub; ret++) {
    problem->allSubRough->data[ret] = 0.0;
  }

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
  ret = allLayers->size[0];
  allLayers->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(allLayers, ret);
  for (i = 0; i < loop_ub; i++) {
    ret = allLayers->data[i].f1->size[0];
    allLayers->data[i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(allLayers->data[i].f1, ret);
    allLayers->data[i].f1->data[0] = 1.0;
    allLayers->data[i].f1->data[1] = 1.0;
  }

  /*  coder.varsize('allLayers{:}',[Inf 3],[1 1]); */
  for (ret = 0; ret < 6; ret++) {
    para[ret] = controls->para[ret];
  }

  ret = memcmp(&para[0], &b[0], 6);
  if (ret == 0) {
    b_ret = 0;
  } else {
    b_ret = -1;
  }

  switch (b_ret) {
   case 0:
    problemDef_data[0] = problemDef->res;
    standardTF_stanlay_single(problemDef->resample,
      problemDef->numberOfContrasts, problemDef->geometry, problemDef_cells->f1,
      problemDef->contrastBacks, problemDef->contrastNbss, problemDef->backs,
      problemDef->shifts, problemDef->sf, problemDef->nba, problemDef->nbs,
      problemDef_data, problemDef->dataPresent, problemDef_cells->f2,
      problemDef_cells->f3, problemDef_cells->f4, problemDef->params,
      problemDef_cells->f5, problemDef_cells->f6, problemDef->contrastBacksType,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, chis, reflectivity, Simulation, shifted_data,
      layerSlds, sldProfiles, allLayers, problem->allSubRough);

    /*      case 'multi' */
    /*          [outSsubs,... */
    /*              backgs,... */
    /*              qshifts,... */
    /*              sfs,... */
    /*              nbas,... */
    /*              nbss,... */
    /*              resols,... */
    /*              chis,... */
    /*              reflectivity,... */
    /*              Simulation,... */
    /*              shifted_data,... */
    /*              layerSlds,... */
    /*              sldProfiles,... */
    /*              allLayers,... */
    /*              allRoughs] = standardTF_stanlay_parallel(resample, ... */
    /*              numberOfContrasts, ... */
    /*              geometry, ... */
    /*              repeatLayers , ... */
    /*              cBacks , ... */
    /*              cShifts , ... */
    /*              cScales , ... */
    /*              cNbas , ... */
    /*              cNbss, ... */
    /*              cRes , ... */
    /*              backs , ... */
    /*              shifts , ... */
    /*              sf, ... */
    /*              nba , ... */
    /*              nbs , ... */
    /*              res , ... */
    /*              dataPresent , ... */
    /*              allData , ... */
    /*              dataLimits , ... */
    /*              simLimits , ... */
    /*              nParams , ... */
    /*              params , ... */
    /*              contrastLayers , ... */
    /*              numberOfLayers , ... */
    /*              layersDetails, ... */
    /*              problemDef_limits); */
    break;
  }

  ret = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = chis->size[0];
  emxEnsureCapacity_real_T(problem->calculations.all_chis, ret);
  loop_ub = chis->size[0];
  for (ret = 0; ret < loop_ub; ret++) {
    problem->calculations.all_chis->data[ret] = chis->data[ret];
  }

  problem->calculations.sum_chi = sum(chis);

  /* problem.calculations.reflectivity = reflectivity; */
  /* problem.calculations.Simulation = Simulation; */
  /* problem.shifted_data = shifted_data; */
  /* problem.layers = layerSlds; */
  /* problem.calculations.slds = sldProfiles; */
  /* problem.allLayers = allLayers; */
  /*  result = cell(1,6); */
  /*   */
  /*   */
  /*   */
  /*  %result = {{};{};{};{};{};{};{}}; */
  /*  result{1} = reflectivity; */
  /*  result{2} = Simulation; */
  /*  result{3} = shifted_data; */
  /*  result{4} = layerSlds; */
  /*  result{5} = sldProfiles; */
  /*  result{6} = allLayers; */
  /*   */
  /*   */
  /*  %Result coder definitions.... */
  /*   coder.varsize('result{1}',[Inf 1],[1 0]);           %Reflectivity */
  /*   coder.varsize('result{1}{:}',[Inf 2],[1 0]);         */
  /*  %  */
  /*   coder.varsize('result{2}',[Inf 1],[1 0]);           %Simulatin */
  /*   coder.varsize('result{2}{:}',[Inf 2],[1 0]); */
  /*  %  */
  /*   coder.varsize('result{3}',[Inf 1],[1 0]);           %Shifted data */
  /*   coder.varsize('result{3}{:}',[Inf 3],[1 0]); */
  /*  %  */
  /*   coder.varsize('result{4}',[Inf 1],[1 0]);           %Layers slds */
  /*   coder.varsize('result{4}{:}',[Inf 3],[1 0]); */
  /*  %  */
  /*   coder.varsize('result{5}',[Inf 1],[1 0]);           %Sld profiles */
  /*   coder.varsize('results{5}{:}',[Inf 2],[1 0]); */
  /*  %  */
  /*   coder.varsize('result{6}',[Inf 1],[1 0]);           %All layers  */
  /*   coder.varsize('result{6}{:}',[Inf 1],[1 0]); */
  /*  if coder.target('MATLAB') */
  /*      if RAT_DEBUG */
  /*          DEBUGVARS.standardTF_stanLay_reflectivityCalculation.problem = problem; */
  /*          DEBUGVARS.standardTF_stanLay_reflectivityCalculation.results = results; */
  /*      end */
  /*  end */
  emxFree_real_T(&chis);
}

/* End of code generation (standardTF_stanLay_reflectivityCalculation.c) */
