/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanlay_single.c
 *
 * Code generation for function 'standardTF_stanlay_single'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "standardTF_stanlay_single.h"
#include "reflectivity_calculation_emxutil.h"
#include "sum.h"
#include "callReflectivity.h"
#include "shiftdata.h"
#include "resampleLayers.h"
#include "makeSLDProfiles.h"
#include "groupLayers_Mod.h"
#include "allocateParamsToLayers.h"
#include "reflectivity_calculation_rtwutil.h"

/* Function Definitions */
void standardTF_stanlay_single(const emxArray_real_T *resample, double
  numberOfContrasts, const emxArray_char_T *geometry, const emxArray_cell_wrap_0
  *repeatLayers, const emxArray_real_T *cBacks, const emxArray_real_T *cShifts,
  const emxArray_real_T *cScales, const emxArray_real_T *cNbas, const
  emxArray_real_T *cNbss, const emxArray_real_T *cRes, const emxArray_real_T
  *backs, const emxArray_real_T *shifts, const emxArray_real_T *sf, const
  emxArray_real_T *nba, const emxArray_real_T *nbs, const emxArray_real_T *res,
  const emxArray_real_T *dataPresent, const emxArray_cell_wrap_1 *allData, const
  emxArray_cell_wrap_0 *dataLimits, const emxArray_cell_wrap_0 *simLimits,
  double nParams, const emxArray_real_T *params, const emxArray_cell_wrap_0
  *contrastLayers, const emxArray_cell_wrap_2 *layersDetails, const
  emxArray_real_T *backsType, emxArray_real_T *outSsubs, emxArray_real_T *backgs,
  emxArray_real_T *qshifts, emxArray_real_T *sfs, emxArray_real_T *nbas,
  emxArray_real_T *nbss, emxArray_real_T *resols, emxArray_real_T *chis,
  emxArray_cell_wrap_9 *reflectivity, emxArray_cell_wrap_9 *Simulation,
  emxArray_cell_wrap_1 *shifted_data, emxArray_cell_wrap_1 *layerSlds,
  emxArray_cell_wrap_9 *sldProfiles, emxArray_cell_wrap_8 *allLayers,
  emxArray_real_T *allRoughs)
{
  int i0;
  int i1;
  int i;
  emxArray_cell_wrap_13 *outParameterisedLayers;
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *Simul;
  emxArray_real_T *terms;
  emxArray_real_T *n;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int b_i;
  double thisContrastLayers[10];
  double outLayers_data[6];
  int outLayers_size[2];
  double N;
  unsigned int u0;
  int nx;
  int idx;
  boolean_T exitg1;

  /* global RAT_DEBUG DEBUGVARS         */
  /* coder.extrinsic('callModules');   */
  /*  coder.varsize('backgs',[Inf,1],[1 0]);  */
  /*  coder.varsize('shifted_dat',[Inf 3],[1 0]); */
  /* Pre-Allocation... */
  /*   */
  /* coder.varsize('reflectivity{:}',[Inf 2],[1 0]); */
  /*   */
  /* coder.varsize('Simulation{:}',[Inf 2],[1 0]); */
  /*   */
  i0 = (int)numberOfContrasts;
  i1 = allLayers->size[0];
  allLayers->size[0] = i0;
  emxEnsureCapacity_cell_wrap_8(allLayers, i1);
  for (i = 0; i < i0; i++) {
    i1 = allLayers->data[i].f1->size[0];
    allLayers->data[i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(allLayers->data[i].f1, i1);
    allLayers->data[i].f1->data[0] = 1.0;
    allLayers->data[i].f1->data[1] = 1.0;
  }

  emxInit_cell_wrap_13(&outParameterisedLayers, 2);

  /*  coder.varsize('allLayers{:}',[Inf 3],[1 1]); */
  allocateParamsToLayers(params, layersDetails, outParameterisedLayers);
  i1 = backgs->size[0];
  backgs->size[0] = i0;
  emxEnsureCapacity_real_T(backgs, i1);
  i1 = qshifts->size[0];
  qshifts->size[0] = i0;
  emxEnsureCapacity_real_T(qshifts, i1);
  i1 = sfs->size[0];
  sfs->size[0] = i0;
  emxEnsureCapacity_real_T(sfs, i1);
  i1 = nbas->size[0];
  nbas->size[0] = i0;
  emxEnsureCapacity_real_T(nbas, i1);
  i1 = nbss->size[0];
  nbss->size[0] = i0;
  emxEnsureCapacity_real_T(nbss, i1);
  i1 = resols->size[0];
  resols->size[0] = i0;
  emxEnsureCapacity_real_T(resols, i1);
  i1 = allRoughs->size[0];
  allRoughs->size[0] = i0;
  emxEnsureCapacity_real_T(allRoughs, i1);
  i1 = outSsubs->size[0];
  outSsubs->size[0] = i0;
  emxEnsureCapacity_real_T(outSsubs, i1);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = i0;
  emxEnsureCapacity_cell_wrap_9(sldProfiles, i1);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = i0;
  emxEnsureCapacity_cell_wrap_1(layerSlds, i1);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = i0;
  emxEnsureCapacity_cell_wrap_1(shifted_data, i1);
  i1 = Simulation->size[0];
  Simulation->size[0] = i0;
  emxEnsureCapacity_cell_wrap_9(Simulation, i1);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = i0;
  emxEnsureCapacity_cell_wrap_9(reflectivity, i1);
  i1 = chis->size[0];
  chis->size[0] = i0;
  emxEnsureCapacity_real_T(chis, i1);
  emxInit_real_T(&sldProfile, 2);
  emxInit_real_T(&layerSld, 2);
  emxInit_real_T(&shifted_dat, 2);
  emxInit_real_T(&Simul, 2);
  emxInit_real_T(&terms, 1);
  emxInit_real_T(&n, 1);
  emxInit_boolean_T(&x, 1);
  emxInit_int32_T(&ii, 1);
  for (i = 0; i < i0; i++) {
    /* Distributes the background and shift values among the different contrasts. */
    /*  */
    /* [backgs,qshifts,sfs,nbas,nbss,resols] = backSort(nc,cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res) */
    /*  Inputs: */
    /*        nc = number of contrasts (double) */
    /*        cBacks = Which backround value is associated with each contrast? */
    /*        cShifts = Which qz_shift value is associated with each contrast? */
    /*        cScales = Which scalefactor value is associated with each contrast? */
    /*        cNba = Which NBa value is associated with each contrast? */
    /*        cNbs = Which Nbs value is associated with each contrast? */
    /*        cRes = Which resolution value is associated with each contrast? */
    /*        backs = List of all background values. */
    /*        shifts = List of all qz-shift values */
    /*        sf = List of all scalefactor values */
    /*        nba = List of all nba values */
    /*        nbs = List of all nbs values */
    /*        res = List of all resolution values */
    /*  */
    /*  Outputs: */
    /*        backgs = list of actual background values for each contrast */
    /*        qshifts = list of actual shift values for each contrast       */
    /*        sfs = list of actual shift values for each contrast      */
    /*        nbas = list of actual shift values for each contrast      */
    /*        nbss = list of actual shift values for each contrast */
    /*        nbss = list of actual shift values for each contrast   */
    /*  backgs = 0;%zeros(1,nc); */
    /*  qshifts = 0;%zeros(1,nc); */
    /*  sfs = 0;%zeros(1,nc); */
    /*  nbas = 0;%zeros(1,nc); */
    /*  nbss = 0;%zeros(1,nc); */
    /*  resols = 0;%zeros(1,nc); */
    /* for i = 1:nc */
    /* thisBack = cBacks(i); */
    backgs->data[i] = backs->data[(int)cBacks->data[i] - 1];

    /* thisShift = cShifts(i); */
    qshifts->data[i] = shifts->data[(int)cShifts->data[i] - 1];

    /* thisScale = cScales(i); */
    sfs->data[i] = sf->data[(int)cScales->data[i] - 1];

    /* thisNbair = cNbas(i); */
    nbas->data[i] = nba->data[(int)cNbas->data[i] - 1];

    /* thisNbsub = cNbss(i); */
    nbss->data[i] = nbs->data[(int)cNbss->data[i] - 1];

    /* thisResol = cRes(i); */
    resols->data[i] = res->data[(int)cRes->data[i] - 1];

    /* end */
    allRoughs->data[i] = params->data[0];

    /*  Take the layers list for a contrast and build an */
    /*  array of real valued layers  */
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < 5; i1++) {
        thisContrastLayers[b_i + (i1 << 1)] = outParameterisedLayers->data[(int)
          contrastLayers->data[i].f1[b_i] - 1].f1[i1];
      }
    }

    groupLayers_Mod(thisContrastLayers, allRoughs->data[i], geometry, nbas->
                    data[i], nbss->data[i], outLayers_data, outLayers_size,
                    &outSsubs->data[i]);
    makeSLDProfiles(nbas->data[i], nbss->data[i], outLayers_data, outSsubs->
                    data[i], repeatLayers->data[i].f1, sldProfile);
    i1 = sldProfiles->data[i].f1->size[0] * sldProfiles->data[i].f1->size[1];
    sldProfiles->data[i].f1->size[0] = sldProfile->size[0];
    sldProfiles->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sldProfiles->data[i].f1, i1);
    b_i = sldProfile->size[0] * sldProfile->size[1];
    for (i1 = 0; i1 < b_i; i1++) {
      sldProfiles->data[i].f1->data[i1] = sldProfile->data[i1];
    }

    if (resample->data[i] == 1.0) {
      resampleLayers(sldProfile, layerSld);
      i1 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
      layerSlds->data[i].f1->size[0] = layerSld->size[0];
      layerSlds->data[i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(layerSlds->data[i].f1, i1);
      b_i = layerSld->size[0] * layerSld->size[1];
      for (i1 = 0; i1 < b_i; i1++) {
        layerSlds->data[i].f1->data[i1] = layerSld->data[i1];
      }
    } else {
      i1 = layerSld->size[0] * layerSld->size[1];
      layerSld->size[0] = 2;
      layerSld->size[1] = 3;
      emxEnsureCapacity_real_T(layerSld, i1);
      for (i1 = 0; i1 < 6; i1++) {
        layerSld->data[i1] = outLayers_data[i1];
      }

      i1 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
      layerSlds->data[i].f1->size[0] = 2;
      layerSlds->data[i].f1->size[1] = 3;
      emxEnsureCapacity_real_T(layerSlds->data[i].f1, i1);
      for (i1 = 0; i1 < 6; i1++) {
        layerSlds->data[i].f1->data[i1] = outLayers_data[i1];
      }
    }

    i1 = shifted_dat->size[0] * shifted_dat->size[1];
    shifted_dat->size[0] = allData->data[i].f1->size[0];
    shifted_dat->size[1] = 3;
    emxEnsureCapacity_real_T(shifted_dat, i1);
    b_i = allData->data[i].f1->size[0] * allData->data[i].f1->size[1];
    for (i1 = 0; i1 < b_i; i1++) {
      shifted_dat->data[i1] = allData->data[i].f1->data[i1];
    }

    shiftdata(sfs->data[i], qshifts->data[i], dataPresent->data[i], shifted_dat,
              dataLimits->data[i].f1);
    callReflectivity(nbas->data[i], nbss->data[i], simLimits->data[i].f1,
                     repeatLayers->data[i].f1, shifted_dat, layerSld,
                     outSsubs->data[i], resols->data[i], sldProfile, Simul);
    switch ((int)backsType->data[i]) {
     case 1:
      /* Add background to the simulation */
      i1 = sldProfile->size[0] * sldProfile->size[1];
      b_i = sldProfile->size[0] * sldProfile->size[1];
      sldProfile->size[1] = 2;
      emxEnsureCapacity_real_T(sldProfile, b_i);
      N = backgs->data[i];
      b_i = i1 - 1;
      for (i1 = 0; i1 <= b_i; i1++) {
        sldProfile->data[i1] += N;
      }

      i1 = Simul->size[0] * Simul->size[1];
      b_i = Simul->size[0] * Simul->size[1];
      Simul->size[1] = 2;
      emxEnsureCapacity_real_T(Simul, b_i);
      N = backgs->data[i];
      b_i = i1 - 1;
      for (i1 = 0; i1 <= b_i; i1++) {
        Simul->data[i1] += N;
      }
      break;

     case 2:
      /*          %Subtract the background from the data.. */
      b_i = shifted_dat->size[0] - 1;
      N = backgs->data[i];
      i1 = n->size[0];
      n->size[0] = b_i + 1;
      emxEnsureCapacity_real_T(n, i1);
      for (i1 = 0; i1 <= b_i; i1++) {
        n->data[i1] = shifted_dat->data[i1 + shifted_dat->size[0]] - N;
      }

      b_i = n->size[0];
      for (i1 = 0; i1 < b_i; i1++) {
        shifted_dat->data[i1 + shifted_dat->size[0]] = n->data[i1];
      }

      /* shifted_dat(:,3) = shifted_dat(:,3) - backg;    */
      break;
    }

    i1 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[0] = sldProfile->size[0];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(reflectivity->data[i].f1, i1);
    b_i = sldProfile->size[0] * sldProfile->size[1];
    for (i1 = 0; i1 < b_i; i1++) {
      reflectivity->data[i].f1->data[i1] = sldProfile->data[i1];
    }

    i1 = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
    Simulation->data[i].f1->size[0] = Simul->size[0];
    Simulation->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(Simulation->data[i].f1, i1);
    b_i = Simul->size[0] * Simul->size[1];
    for (i1 = 0; i1 < b_i; i1++) {
      Simulation->data[i].f1->data[i1] = Simul->data[i1];
    }

    i1 = shifted_data->data[i].f1->size[0] * shifted_data->data[i].f1->size[1];
    shifted_data->data[i].f1->size[0] = shifted_dat->size[0];
    shifted_data->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(shifted_data->data[i].f1, i1);
    b_i = shifted_dat->size[0] * shifted_dat->size[1];
    for (i1 = 0; i1 < b_i; i1++) {
      shifted_data->data[i].f1->data[i1] = shifted_dat->data[i1];
    }

    /* chi_squared(func,data,numparams,errors) */
    /* allChis = zeros(1,numberOfContrasts); */
    /*      thisData = allData{i}; */
    /*      thisFit = allFits{i}; */
    i1 = shifted_dat->size[0];
    if (i1 < 1) {
      N = 1.0;
    } else {
      N = (unsigned int)i1;
    }

    if (N <= nParams) {
      N = nParams + 1.0;
    }

    b_i = shifted_dat->size[0];
    i1 = n->size[0];
    n->size[0] = b_i;
    emxEnsureCapacity_real_T(n, i1);
    for (i1 = 0; i1 < b_i; i1++) {
      n->data[i1] = (shifted_dat->data[i1 + shifted_dat->size[0]] -
                     sldProfile->data[i1 + sldProfile->size[0]]) /
        shifted_dat->data[i1 + (shifted_dat->size[0] << 1)];
    }

    u0 = (unsigned int)n->size[0];
    i1 = terms->size[0];
    terms->size[0] = (int)u0;
    emxEnsureCapacity_real_T(terms, i1);
    u0 = (unsigned int)n->size[0];
    nx = (int)u0;
    for (b_i = 0; b_i < nx; b_i++) {
      terms->data[b_i] = rt_powd_snf(n->data[b_i], 2.0);
    }

    i1 = x->size[0];
    x->size[0] = terms->size[0];
    emxEnsureCapacity_boolean_T(x, i1);
    b_i = terms->size[0];
    for (i1 = 0; i1 < b_i; i1++) {
      x->data[i1] = (terms->data[i1] == rtInf);
    }

    nx = x->size[0];
    idx = 0;
    i1 = ii->size[0];
    ii->size[0] = x->size[0];
    emxEnsureCapacity_int32_T(ii, i1);
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i <= nx - 1)) {
      if (x->data[b_i]) {
        idx++;
        ii->data[idx - 1] = b_i + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          b_i++;
        }
      } else {
        b_i++;
      }
    }

    if (x->size[0] == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else if (1 > idx) {
      ii->size[0] = 0;
    } else {
      i1 = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(ii, i1);
    }

    i1 = n->size[0];
    n->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(n, i1);
    b_i = ii->size[0];
    for (i1 = 0; i1 < b_i; i1++) {
      n->data[i1] = ii->data[i1];
    }

    if (n->size[0] != 0) {
      i1 = ii->size[0];
      ii->size[0] = n->size[0];
      emxEnsureCapacity_int32_T(ii, i1);
      b_i = n->size[0];
      for (i1 = 0; i1 < b_i; i1++) {
        ii->data[i1] = (int)n->data[i1];
      }

      b_i = ii->size[0];
      for (i1 = 0; i1 < b_i; i1++) {
        terms->data[ii->data[i1] - 1] = 0.0;
      }
    }

    chis->data[i] = 1.0 / (N - nParams) * sum(terms);

    /* allChis(i) = chi2; */
  }

  emxFree_int32_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&n);
  emxFree_real_T(&terms);
  emxFree_real_T(&Simul);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);
  emxFree_cell_wrap_13(&outParameterisedLayers);

  /*  if coder.target('MATLAB') */
  /*      if RAT_DEBUG */
  /*          DEBUGVARS.standardTF_stanlay_single.outSsubs = outSsubs; */
  /*          DEBUGVARS.standardTF_stanlay_single.backgs = backgs; */
  /*          DEBUGVARS.standardTF_stanlay_single.qshifts = qshifts; */
  /*          DEBUGVARS.standardTF_stanlay_single.sfs = sfs; */
  /*          DEBUGVARS.standardTF_stanlay_single.nbas = nbas; */
  /*          DEBUGVARS.standardTF_stanlay_single.nbss = nbss; */
  /*          DEBUGVARS.standardTF_stanlay_single.resols = resols; */
  /*          DEBUGVARS.standardTF_stanlay_single.chis = chis; */
  /*          DEBUGVARS.standardTF_stanlay_single.reflectivity = reflectivity; */
  /*          DEBUGVARS.standardTF_stanlay_single.Simulation = Simulation; */
  /*          DEBUGVARS.standardTF_stanlay_single.shifted_data = shifted_data; */
  /*          DEBUGVARS.standardTF_stanlay_single.layerSlds = layerSlds; */
  /*          DEBUGVARS.standardTF_stanlay_single.sldProfiles = sldProfiles; */
  /*          DEBUGVARS.standardTF_stanlay_single.allLayers = allLayers; */
  /*          DEBUGVARS.standardTF_stanlay_single.allRoughs = allRoughs; */
  /*      end */
  /*  end */
}

/* End of code generation (standardTF_stanlay_single.c) */
