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
#include <string.h>
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
void standardTF_stanlay_single(const double resample[7], double
  numberOfContrasts, const char geometry[13], const cell_wrap_0 repeatLayers[7],
  const double cBacks[7], const double cNbss[7], const double backs[2], double
  shifts, double sf, double nba, const double nbs[2], const double res_data[],
  const double dataPresent[7], const cell_wrap_1 allData[7], const cell_wrap_0
  dataLimits[7], const cell_wrap_0 simLimits[7], const double params[10], const
  cell_wrap_0 contrastLayers[7], const cell_wrap_2 layersDetails[4], const
  double backsType[7], emxArray_real_T *outSsubs, emxArray_real_T *backgs,
  emxArray_real_T *qshifts, emxArray_real_T *sfs, emxArray_real_T *nbas,
  emxArray_real_T *nbss, emxArray_real_T *resols, emxArray_real_T *chis,
  emxArray_cell_wrap_11 *reflectivity, emxArray_cell_wrap_11 *Simulation,
  emxArray_cell_wrap_12 *shifted_data, emxArray_cell_wrap_12 *layerSlds,
  emxArray_cell_wrap_11 *sldProfiles, emxArray_cell_wrap_14 *allLayers,
  emxArray_real_T *allRoughs)
{
  int i0;
  int i1;
  int i;
  cell_wrap_2 outParameterisedLayers[4];
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_boolean_T *x;
  emxArray_int8_T *ii;
  int b_i;
  double thisContrastLayers[10];
  double outLayers_data[6];
  int outLayers_size[2];
  double b_allData[153];
  double shifted_dat_data[153];
  double reflect_data[102];
  int reflect_size[2];
  double b_backgs;
  double b_shifted_dat_data[51];
  int N;
  int terms_size[1];
  int nx;
  double terms_data[51];
  int idx;
  boolean_T exitg1;
  emxArray_real_T b_terms_data;
  signed char tmp_data[51];

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
  emxEnsureCapacity_cell_wrap_14(allLayers, i1);
  for (i = 0; i < i0; i++) {
    i1 = allLayers->data[i].f1->size[0];
    allLayers->data[i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(allLayers->data[i].f1, i1);
    allLayers->data[i].f1->data[0] = 1.0;
    allLayers->data[i].f1->data[1] = 1.0;
  }

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
  emxEnsureCapacity_cell_wrap_11(sldProfiles, i1);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = i0;
  emxEnsureCapacity_cell_wrap_12(layerSlds, i1);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = i0;
  emxEnsureCapacity_cell_wrap_12(shifted_data, i1);
  i1 = Simulation->size[0];
  Simulation->size[0] = i0;
  emxEnsureCapacity_cell_wrap_11(Simulation, i1);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = i0;
  emxEnsureCapacity_cell_wrap_11(reflectivity, i1);
  i1 = chis->size[0];
  chis->size[0] = i0;
  emxEnsureCapacity_real_T(chis, i1);
  emxInit_real_T(&sldProfile, 2);
  emxInit_real_T(&layerSld, 2);
  emxInit_boolean_T(&x, 1);
  emxInit_int8_T(&ii, 1);
  for (i = 0; i < i0; i++) {
    qshifts->data[i] = shifts;
    sfs->data[i] = sf;
    nbas->data[i] = nba;

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
    backgs->data[i] = backs[(int)cBacks[i] - 1];

    /* thisShift = cShifts(i); */
    /* thisScale = cScales(i); */
    /* thisNbair = cNbas(i); */
    /* thisNbsub = cNbss(i); */
    nbss->data[i] = nbs[(int)cNbss[i] - 1];

    /* thisResol = cRes(i); */
    resols->data[i] = res_data[0];

    /* end */
    allRoughs->data[i] = params[0];

    /*  Take the layers list for a contrast and build an */
    /*  array of real valued layers  */
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < 5; i1++) {
        thisContrastLayers[b_i + (i1 << 1)] = outParameterisedLayers[(int)
          contrastLayers[i].f1[b_i] - 1].f1[i1];
      }
    }

    groupLayers_Mod(thisContrastLayers, allRoughs->data[i], geometry, nbas->
                    data[i], nbss->data[i], outLayers_data, outLayers_size,
                    &outSsubs->data[i]);
    makeSLDProfiles(nbas->data[i], nbss->data[i], outLayers_data, outSsubs->
                    data[i], repeatLayers[i].f1, sldProfile);
    i1 = sldProfiles->data[i].f1->size[0] * sldProfiles->data[i].f1->size[1];
    sldProfiles->data[i].f1->size[0] = sldProfile->size[0];
    sldProfiles->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sldProfiles->data[i].f1, i1);
    b_i = sldProfile->size[0] * sldProfile->size[1];
    for (i1 = 0; i1 < b_i; i1++) {
      sldProfiles->data[i].f1->data[i1] = sldProfile->data[i1];
    }

    if (resample[i] == 1.0) {
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

    memcpy(&b_allData[0], &allData[i].f1[0], 153U * sizeof(double));
    shiftdata(sfs->data[i], qshifts->data[i], dataPresent[i], b_allData,
              dataLimits[i].f1, shifted_dat_data, outLayers_size);
    callReflectivity(nbas->data[i], nbss->data[i], simLimits[i].f1,
                     repeatLayers[i].f1, shifted_dat_data, outLayers_size,
                     layerSld, outSsubs->data[i], backgs->data[i], resols->
                     data[i], reflect_data, reflect_size, sldProfile);
    switch ((int)backsType[i]) {
     case 1:
      /* Add background to the simulation */
      i1 = reflect_size[0] * reflect_size[1];
      reflect_size[1] = 2;
      b_backgs = backgs->data[i];
      b_i = i1 - 1;
      for (i1 = 0; i1 <= b_i; i1++) {
        reflect_data[i1] += b_backgs;
      }

      i1 = sldProfile->size[0] * sldProfile->size[1];
      b_i = sldProfile->size[0] * sldProfile->size[1];
      sldProfile->size[1] = 2;
      emxEnsureCapacity_real_T(sldProfile, b_i);
      b_backgs = backgs->data[i];
      b_i = i1 - 1;
      for (i1 = 0; i1 <= b_i; i1++) {
        sldProfile->data[i1] += b_backgs;
      }
      break;

     case 2:
      /*          %Subtract the background from the data.. */
      b_i = outLayers_size[0] - 1;
      b_backgs = backgs->data[i];
      for (i1 = 0; i1 <= b_i; i1++) {
        b_shifted_dat_data[i1] = shifted_dat_data[i1 + outLayers_size[0]] -
          b_backgs;
      }

      b_i = outLayers_size[0];
      for (i1 = 0; i1 < b_i; i1++) {
        shifted_dat_data[i1 + outLayers_size[0]] = b_shifted_dat_data[i1];
      }

      /* shifted_dat(:,3) = shifted_dat(:,3) - backg;    */
      break;
    }

    i1 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[0] = reflect_size[0];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(reflectivity->data[i].f1, i1);
    b_i = reflect_size[0] * reflect_size[1];
    for (i1 = 0; i1 < b_i; i1++) {
      reflectivity->data[i].f1->data[i1] = reflect_data[i1];
    }

    i1 = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
    Simulation->data[i].f1->size[0] = sldProfile->size[0];
    Simulation->data[i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(Simulation->data[i].f1, i1);
    b_i = sldProfile->size[0] * sldProfile->size[1];
    for (i1 = 0; i1 < b_i; i1++) {
      Simulation->data[i].f1->data[i1] = sldProfile->data[i1];
    }

    i1 = shifted_data->data[i].f1->size[0] * shifted_data->data[i].f1->size[1];
    shifted_data->data[i].f1->size[0] = outLayers_size[0];
    shifted_data->data[i].f1->size[1] = 3;
    emxEnsureCapacity_real_T(shifted_data->data[i].f1, i1);
    b_i = outLayers_size[0] * outLayers_size[1];
    for (i1 = 0; i1 < b_i; i1++) {
      shifted_data->data[i].f1->data[i1] = shifted_dat_data[i1];
    }

    /* chi_squared(func,data,numparams,errors) */
    /* allChis = zeros(1,numberOfContrasts); */
    /*      thisData = allData{i}; */
    /*      thisFit = allFits{i}; */
    if ((signed char)outLayers_size[0] < 1) {
      N = 1;
    } else {
      N = (signed char)outLayers_size[0];
    }

    if (N <= 10) {
      N = 11;
    }

    b_i = outLayers_size[0];
    for (i1 = 0; i1 < b_i; i1++) {
      b_shifted_dat_data[i1] = (shifted_dat_data[i1 + outLayers_size[0]] -
        reflect_data[i1 + reflect_size[0]]) / shifted_dat_data[i1 +
        (outLayers_size[0] << 1)];
    }

    terms_size[0] = (signed char)outLayers_size[0];
    nx = (signed char)outLayers_size[0];
    for (b_i = 0; b_i < nx; b_i++) {
      terms_data[b_i] = rt_powd_snf(b_shifted_dat_data[b_i], 2.0);
    }

    i1 = x->size[0];
    x->size[0] = terms_size[0];
    emxEnsureCapacity_boolean_T(x, i1);
    b_i = terms_size[0];
    for (i1 = 0; i1 < b_i; i1++) {
      x->data[i1] = (terms_data[i1] == rtInf);
    }

    nx = x->size[0];
    idx = 0;
    i1 = ii->size[0];
    ii->size[0] = x->size[0];
    emxEnsureCapacity_int8_T(ii, i1);
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i <= nx - 1)) {
      if (x->data[b_i]) {
        idx++;
        ii->data[idx - 1] = (signed char)(b_i + 1);
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
      emxEnsureCapacity_int8_T(ii, i1);
    }

    if (ii->size[0] != 0) {
      idx = ii->size[0];
      b_i = ii->size[0];
      for (i1 = 0; i1 < b_i; i1++) {
        tmp_data[i1] = ii->data[i1];
      }

      for (i1 = 0; i1 < idx; i1++) {
        terms_data[tmp_data[i1] - 1] = 0.0;
      }
    }

    b_terms_data.data = &terms_data[0];
    b_terms_data.size = &terms_size[0];
    b_terms_data.allocatedSize = 51;
    b_terms_data.numDimensions = 1;
    b_terms_data.canFreeData = false;
    chis->data[i] = 1.0 / ((double)N - 10.0) * sum(&b_terms_data);

    /* allChis(i) = chi2; */
  }

  emxFree_int8_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);

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
