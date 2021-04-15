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
#include "standardTF_stanlay_single.h"
#include "standardTF_stanlay_single_emxutil.h"
#include "chiSquared.h"
#include "callReflectivity.h"
#include "shiftdata.h"
#include "resampleLayers.h"
#include "makeSLDProfileXY.h"
#include "groupLayers_Mod.h"

/* Function Definitions */
void standardTF_stanlay_single(const emxArray_real_T *resam, double
  numberOfContrasts, const emxArray_char_T *geometry, const emxArray_real_T
  *nbairs, const emxArray_real_T *nbsubs, const emxArray_cell_wrap_0 *repeats,
  const emxArray_real_T *cBacks, const emxArray_real_T *cShifts, const
  emxArray_real_T *cScales, const emxArray_real_T *cNbas, const emxArray_real_T *
  cNbss, const emxArray_real_T *cRes, const emxArray_real_T *backs, const
  emxArray_real_T *shifts, const emxArray_real_T *sf, const emxArray_real_T *nba,
  const emxArray_real_T *nbs, const emxArray_real_T *res, const emxArray_real_T *
  dataPresent, const emxArray_cell_wrap_1 *allData, const emxArray_cell_wrap_2
  *dataLimits, const emxArray_cell_wrap_2 *simLimits, const emxArray_cell_wrap_2
  *repeatLayers, double nParams, const emxArray_real_T *params, const
  emxArray_cell_wrap_0 *contrastLayers, double numberOfLayers, const
  emxArray_cell_wrap_3 *layersDetails, double whichType, emxArray_real_T
  *outSsubs, emxArray_real_T *backgs, emxArray_real_T *qshifts, emxArray_real_T *
  sfs, emxArray_real_T *nbas, emxArray_real_T *nbss, emxArray_real_T *resols,
  emxArray_real_T *chis, emxArray_cell_wrap_4 *reflectivity,
  emxArray_cell_wrap_4 *Simulation, emxArray_cell_wrap_1 *shifted_data,
  emxArray_cell_wrap_1 *layerSlds, emxArray_cell_wrap_4 *sldProfiles,
  emxArray_cell_wrap_5 *allLayers, emxArray_real_T *allRoughs)
{
  int i0;
  int i;
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_real_T *shifted_dat;
  emxArray_cell_wrap_0 *b_layersDetails;
  emxArray_real_T *layersList;
  emxArray_real_T *layersValues;
  emxArray_real_T *b_allData;
  int j;
  int loop_ub;
  double reps;
  (void)whichType;

  /* coder.extrinsic('callModules');             */
  /* Pre-Allocation... */
  i0 = backgs->size[0];
  backgs->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)backgs, i0, (int)sizeof(double));
  i0 = qshifts->size[0];
  qshifts->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)qshifts, i0, (int)sizeof(double));
  i0 = sfs->size[0];
  sfs->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)sfs, i0, (int)sizeof(double));
  i0 = nbas->size[0];
  nbas->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)nbas, i0, (int)sizeof(double));
  i0 = nbss->size[0];
  nbss->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)nbss, i0, (int)sizeof(double));
  i0 = resols->size[0];
  resols->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)resols, i0, (int)sizeof(double));
  i0 = allRoughs->size[0];
  allRoughs->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)allRoughs, i0, (int)sizeof(double));
  i0 = allLayers->size[0] * allLayers->size[1];
  allLayers->size[0] = (int)numberOfContrasts;
  allLayers->size[1] = 1;
  emxEnsureCapacity_cell_wrap_5(allLayers, i0);
  i0 = outSsubs->size[0];
  outSsubs->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)outSsubs, i0, (int)sizeof(double));
  i0 = sldProfiles->size[0] * sldProfiles->size[1];
  sldProfiles->size[0] = (int)numberOfContrasts;
  sldProfiles->size[1] = 1;
  emxEnsureCapacity_cell_wrap_4(sldProfiles, i0);
  i0 = layerSlds->size[0] * layerSlds->size[1];
  layerSlds->size[0] = (int)numberOfContrasts;
  layerSlds->size[1] = 1;
  emxEnsureCapacity_cell_wrap_1(layerSlds, i0);
  i0 = shifted_data->size[0] * shifted_data->size[1];
  shifted_data->size[0] = (int)numberOfContrasts;
  shifted_data->size[1] = 1;
  emxEnsureCapacity_cell_wrap_1(shifted_data, i0);
  i0 = reflectivity->size[0] * reflectivity->size[1];
  reflectivity->size[0] = (int)numberOfContrasts;
  reflectivity->size[1] = 1;
  emxEnsureCapacity_cell_wrap_4(reflectivity, i0);
  i0 = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = (int)numberOfContrasts;
  Simulation->size[1] = 1;
  emxEnsureCapacity_cell_wrap_4(Simulation, i0);
  i0 = chis->size[0];
  chis->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)chis, i0, (int)sizeof(double));
  i = 0;
  emxInit_real_T(&sldProfile, 2);
  emxInit_real_T(&layerSld, 2);
  emxInit_real_T(&shifted_dat, 2);
  emxInit_cell_wrap_0(&b_layersDetails, 2);
  emxInit_real_T(&layersList, 2);
  emxInit_real_T(&layersValues, 2);
  emxInit_real_T(&b_allData, 2);
  while (i <= (int)numberOfContrasts - 1) {
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
    /* thisShift = cShifts(i); */
    /* thisScale = cScales(i); */
    /* thisNbair = cNbas(i); */
    /* thisNbsub = cNbss(i); */
    /* thisResol = cRes(i); */
    /* end */
    backgs->data[i] = backs->data[(int)cBacks->data[i] - 1];
    qshifts->data[i] = shifts->data[(int)cShifts->data[i] - 1];
    sfs->data[i] = sf->data[(int)cScales->data[i] - 1];
    nbas->data[i] = nba->data[(int)cNbas->data[i] - 1];
    nbss->data[i] = nbs->data[(int)cNbss->data[i] - 1];
    resols->data[i] = res->data[(int)cRes->data[i] - 1];
    i0 = b_layersDetails->size[0] * b_layersDetails->size[1];
    b_layersDetails->size[0] = 1;
    b_layersDetails->size[1] = layersDetails->size[1];
    emxEnsureCapacity_cell_wrap_0(b_layersDetails, i0);
    for (j = 0; j < layersDetails->size[1]; j++) {
      i0 = b_layersDetails->data[j].f1->size[0] * b_layersDetails->data[j]
        .f1->size[1];
      b_layersDetails->data[j].f1->size[0] = 1;
      b_layersDetails->data[j].f1->size[1] = layersDetails->data[j].f1.size[1];
      emxEnsureCapacity((emxArray__common *)b_layersDetails->data[j].f1, i0,
                        (int)sizeof(double));
      for (loop_ub = 0; loop_ub < layersDetails->data[j].f1.size[1]; loop_ub++)
      {
        b_layersDetails->data[j].f1->data[loop_ub] = layersDetails->data[j].
          f1.data[loop_ub];
      }
    }

    if (numberOfLayers == 0.0) {
      i0 = layersList->size[0] * layersList->size[1];
      layersList->size[0] = 0;
      layersList->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)layersList, i0, (int)sizeof(double));
    } else {
      i0 = layersValues->size[0] * layersValues->size[1];
      layersValues->size[0] = (int)numberOfLayers;
      layersValues->size[1] = 5;
      emxEnsureCapacity((emxArray__common *)layersValues, i0, (int)sizeof(double));
      loop_ub = (int)numberOfLayers * 5;
      for (i0 = 0; i0 < loop_ub; i0++) {
        layersValues->data[i0] = 0.0;
      }

      for (j = 0; j < (int)numberOfLayers; j++) {
        for (loop_ub = 0; loop_ub < 4; loop_ub++) {
          if (!rtIsNaN(b_layersDetails->data[b_layersDetails->size[0] * j]
                       .f1->data[loop_ub])) {
            layersValues->data[j + layersValues->size[0] * loop_ub] =
              params->data[(int)b_layersDetails->data[b_layersDetails->size[0] *
              j].f1->data[loop_ub] - 1];
          } else {
            layersValues->data[j + layersValues->size[0] * loop_ub] = rtNaN;
          }
        }

        layersValues->data[j + (layersValues->size[0] << 2)] =
          (b_layersDetails->data[b_layersDetails->size[0] * j].f1->data[4] ==
           2.0);
      }

      if (!(contrastLayers->data[contrastLayers->size[0] * i].f1->size[1] == 0))
      {
        i0 = layersList->size[0] * layersList->size[1];
        layersList->size[0] = contrastLayers->data[contrastLayers->size[0] * i].
          f1->size[1];
        layersList->size[1] = 5;
        emxEnsureCapacity((emxArray__common *)layersList, i0, (int)sizeof(double));
        loop_ub = contrastLayers->data[contrastLayers->size[0] * i].f1->size[1] *
          5;
        for (i0 = 0; i0 < loop_ub; i0++) {
          layersList->data[i0] = 0.0;
        }

        for (j = 0; j < contrastLayers->data[contrastLayers->size[0] * i]
             .f1->size[1]; j++) {
          loop_ub = (int)contrastLayers->data[contrastLayers->size[0] * i]
            .f1->data[j];
          for (i0 = 0; i0 < 5; i0++) {
            layersList->data[j + layersList->size[0] * i0] = layersValues->data
              [(loop_ub + layersValues->size[0] * i0) - 1];
          }
        }
      } else {
        i0 = layersList->size[0] * layersList->size[1];
        layersList->size[0] = 0;
        layersList->size[1] = 0;
        emxEnsureCapacity((emxArray__common *)layersList, i0, (int)sizeof(double));
      }
    }

    allRoughs->data[i] = params->data[0];
    i0 = allLayers->data[i].f1->size[0] * allLayers->data[i].f1->size[1];
    allLayers->data[i].f1->size[0] = layersList->size[0];
    allLayers->data[i].f1->size[1] = layersList->size[1];
    emxEnsureCapacity((emxArray__common *)allLayers->data[i].f1, i0, (int)sizeof
                      (double));
    loop_ub = layersList->size[0] * layersList->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      allLayers->data[i].f1->data[i0] = layersList->data[i0];
    }

    groupLayers_Mod(layersList, allRoughs->data[i], geometry, nbairs->data[i],
                    nbsubs->data[i], layerSld, &outSsubs->data[i]);
    if (repeats->data[repeats->size[0] * i].f1->data[0] == 0.0) {
      reps = 1.0;
    } else {
      reps = repeats->data[repeats->size[0] * i].f1->data[1];
    }

    makeSLDProfileXY(nbairs->data[i], nbsubs->data[i], outSsubs->data[i],
                     layerSld, layerSld->size[0], reps, sldProfile);
    i0 = sldProfiles->data[i].f1->size[0] * sldProfiles->data[i].f1->size[1];
    sldProfiles->data[i].f1->size[0] = sldProfile->size[0];
    sldProfiles->data[i].f1->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)sldProfiles->data[i].f1, i0, (int)
                      sizeof(double));
    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      sldProfiles->data[i].f1->data[i0] = sldProfile->data[i0];
    }

    if (resam->data[i] == 1.0) {
      resampleLayers(sldProfile, layerSld);
      i0 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
      layerSlds->data[i].f1->size[0] = layerSld->size[0];
      layerSlds->data[i].f1->size[1] = 3;
      emxEnsureCapacity((emxArray__common *)layerSlds->data[i].f1, i0, (int)
                        sizeof(double));
      loop_ub = layerSld->size[0] * layerSld->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        layerSlds->data[i].f1->data[i0] = layerSld->data[i0];
      }
    } else {
      i0 = layerSlds->data[i].f1->size[0] * layerSlds->data[i].f1->size[1];
      layerSlds->data[i].f1->size[0] = layerSld->size[0];
      layerSlds->data[i].f1->size[1] = 3;
      emxEnsureCapacity((emxArray__common *)layerSlds->data[i].f1, i0, (int)
                        sizeof(double));
      loop_ub = layerSld->size[0] * layerSld->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        layerSlds->data[i].f1->data[i0] = layerSld->data[i0];
      }
    }

    i0 = b_allData->size[0] * b_allData->size[1];
    b_allData->size[0] = allData->data[allData->size[0] * i].f1->size[0];
    b_allData->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)b_allData, i0, (int)sizeof(double));
    loop_ub = allData->data[allData->size[0] * i].f1->size[0] * allData->
      data[allData->size[0] * i].f1->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_allData->data[i0] = allData->data[allData->size[0] * i].f1->data[i0];
    }

    shiftdata(sfs->data[i], qshifts->data[i], dataPresent->data[i], b_allData,
              dataLimits->data[dataLimits->size[0] * i].f1, shifted_dat);
    i0 = shifted_data->data[i].f1->size[0] * shifted_data->data[i].f1->size[1];
    shifted_data->data[i].f1->size[0] = shifted_dat->size[0];
    shifted_data->data[i].f1->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)shifted_data->data[i].f1, i0, (int)
                      sizeof(double));
    loop_ub = shifted_dat->size[0] * shifted_dat->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      shifted_data->data[i].f1->data[i0] = shifted_dat->data[i0];
    }

    callReflectivity(nbairs->data[i], nbsubs->data[i], simLimits->data
                     [simLimits->size[0] * i].f1, repeatLayers->
                     data[repeatLayers->size[0] * i].f1, shifted_dat, layerSld,
                     outSsubs->data[i], backgs->data[i], resols->data[i],
                     sldProfile, Simulation->data[i].f1);
    i0 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[0] = sldProfile->size[0];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)reflectivity->data[i].f1, i0, (int)
                      sizeof(double));
    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      reflectivity->data[i].f1->data[i0] = sldProfile->data[i0];
    }

    chis->data[i] = chiSquared(shifted_dat, sldProfile, nParams);
    i++;
  }

  emxFree_real_T(&b_allData);
  emxFree_real_T(&layersValues);
  emxFree_real_T(&layersList);
  emxFree_cell_wrap_0(&b_layersDetails);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);
}

/* End of code generation (standardTF_stanlay_single.c) */
