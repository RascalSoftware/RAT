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

/* Function Definitions */
void c_standardTF_stanLay_reflectivi(const struct0_T *problemDef, const cell_4
  *problemDef_cells, const struct2_T *controls, struct4_T *problem,
  emxArray_cell_wrap_9 *reflectivity, emxArray_cell_wrap_9 *Simulation,
  emxArray_cell_wrap_1 *shifted_data, emxArray_cell_wrap_1 *layerSlds,
  emxArray_cell_wrap_9 *sldProfiles, emxArray_cell_wrap_8 *allLayers)
{
  int kstr;
  int loop_ub;
  emxArray_real_T *chis;
  int i;
  boolean_T b_bool;
  int c_bool;
  int exitg1;
  static const char cv2[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

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
  kstr = problem->ssubs->size[0];
  problem->ssubs->size[0] = 1;
  emxEnsureCapacity_real_T(problem->ssubs, kstr);
  problem->ssubs->data[0] = problemDef->params->data[0];
  kstr = problem->backgrounds->size[0];
  loop_ub = (int)problemDef->numberOfContrasts;
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

  emxInit_real_T(&chis, 1);
  kstr = chis->size[0];
  chis->size[0] = loop_ub;
  emxEnsureCapacity_real_T(chis, kstr);
  for (kstr = 0; kstr < loop_ub; kstr++) {
    chis->data[kstr] = 0.0;
  }

  kstr = problem->resolutions->size[0];
  problem->resolutions->size[0] = loop_ub;
  emxEnsureCapacity_real_T(problem->resolutions, kstr);
  for (kstr = 0; kstr < loop_ub; kstr++) {
    problem->resolutions->data[kstr] = 0.0;
  }

  kstr = problem->allSubRough->size[0];
  problem->allSubRough->size[0] = loop_ub;
  emxEnsureCapacity_real_T(problem->allSubRough, kstr);
  for (kstr = 0; kstr < loop_ub; kstr++) {
    problem->allSubRough->data[kstr] = 0.0;
  }

  kstr = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(reflectivity, kstr);
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

  /*  coder.varsize('reflectivity{:}',[Inf 2],[1 0]); */
  /*   */
  kstr = Simulation->size[0];
  Simulation->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(Simulation, kstr);
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

  /*  coder.varsize('Simulation{:}',[Inf 2],[1 0]); */
  /*   */
  kstr = shifted_data->size[0];
  shifted_data->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_1(shifted_data, kstr);
  for (i = 0; i < loop_ub; i++) {
    kstr = shifted_data->data[i].f1->size[0] * shifted_data->data[i].f1->size[1];
    shifted_data->data[i].f1->size[0] = 2;
    shifted_data->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(shifted_data->data[i].f1, kstr);
    for (kstr = 0; kstr < 6; kstr++) {
      shifted_data->data[i].f1->data[kstr] = 1.0;
    }
  }

  /*  coder.varsize('shifted_data{:}',[Inf 3],[1 0]); */
  /*   */
  kstr = layerSlds->size[0];
  layerSlds->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_1(layerSlds, kstr);
  for (i = 0; i < loop_ub; i++) {
    kstr = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
    layerSlds->data[i].f1->size[0] = 2;
    layerSlds->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(layerSlds->data[i].f1, kstr);
    for (kstr = 0; kstr < 6; kstr++) {
      layerSlds->data[i].f1->data[kstr] = 1.0;
    }
  }

  /*  coder.varsize('layerSlds{:}',[Inf 3],[1 0]); */
  /*   */
  kstr = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(sldProfiles, kstr);
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

  /*  coder.varsize('sldProfiles{:}',[Inf 2],[1 0]); */
  /*   */
  kstr = allLayers->size[0];
  allLayers->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_8(allLayers, kstr);
  for (i = 0; i < loop_ub; i++) {
    kstr = allLayers->data[i].f1->size[0];
    allLayers->data[i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(allLayers->data[i].f1, kstr);
    allLayers->data[i].f1->data[0] = 1.0;
    allLayers->data[i].f1->data[1] = 1.0;
  }

  /*  coder.varsize('allLayers{:}',[Inf 3],[1 1]); */
  b_bool = false;
  if (controls->para->size[1] == 6) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (controls->para->data[kstr] != cv2[kstr]) {
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
    c_bool = 0;
  } else {
    c_bool = -1;
  }

  switch (c_bool) {
   case 0:
    standardTF_stanlay_single(problemDef->resample,
      problemDef->numberOfContrasts, problemDef->geometry, problemDef_cells->f1,
      problemDef->contrastBacks, problemDef->contrastShifts,
      problemDef->contrastScales, problemDef->contrastNbas,
      problemDef->contrastNbss, problemDef->contrastRes, problemDef->backs,
      problemDef->shifts, problemDef->sf, problemDef->nba, problemDef->nbs,
      problemDef->res, problemDef->dataPresent, problemDef_cells->f2,
      problemDef_cells->f3, problemDef_cells->f4, problemDef->params->size[1],
      problemDef->params, problemDef_cells->f5, problemDef_cells->f6,
      problemDef->contrastBacksType, problem->ssubs, problem->backgrounds,
      problem->qshifts, problem->scalefactors, problem->nbairs, problem->nbsubs,
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

  kstr = problem->calculations.all_chis->size[0];
  problem->calculations.all_chis->size[0] = chis->size[0];
  emxEnsureCapacity_real_T(problem->calculations.all_chis, kstr);
  loop_ub = chis->size[0];
  for (kstr = 0; kstr < loop_ub; kstr++) {
    problem->calculations.all_chis->data[kstr] = chis->data[kstr];
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
