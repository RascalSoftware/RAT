/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custlay_parallel.c
 *
 * Code generation for function 'standardTF_custlay_parallel'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_parallel.h"
#include "standardTF_custlay_parallel_emxutil.h"
#include "chiSquared.h"
#include "callReflectivity.h"
#include "shiftdata.h"
#include "resampleLayers.h"
#include "makeSLDProfiles.h"
#include "groupLayers_Mod.h"
#include "call_customLayers.h"
#include "backSort.h"

/* Function Definitions */
void standardTF_custlay_parallel(const emxArray_real_T *resam, double
  numberOfContrasts, const emxArray_char_T *geometry, const emxArray_real_T
  *nbairs, const emxArray_real_T *nbsubs, const emxArray_cell_wrap_0 *repeats,
  const emxArray_real_T *cBacks, const emxArray_real_T *cShifts, const
  emxArray_real_T *cScales, const emxArray_real_T *cNbas, const emxArray_real_T *
  cNbss, const emxArray_real_T *cRes, const emxArray_real_T *backs, const
  emxArray_real_T *shifts, const emxArray_real_T *sf, const emxArray_real_T *nba,
  const emxArray_real_T *nbs, const emxArray_real_T *res, const emxArray_real_T *
  dataPresent, const emxArray_cell_wrap_1 *allData, const emxArray_cell_wrap_0
  *dataLimits, const emxArray_cell_wrap_0 *simLimits, const emxArray_cell_wrap_0
  *repeatLayers, double nParams, const emxArray_real_T *params, const
  emxArray_cell_wrap_2 *contrastLayers, double numberOfLayers, double whichType,
  const emxArray_char_T *fileHandle, const emxArray_char_T *path,
  emxArray_real_T *outSsubs, emxArray_real_T *backgs, emxArray_real_T *qshifts,
  emxArray_real_T *sfs, emxArray_real_T *nbas, emxArray_real_T *nbss,
  emxArray_real_T *resols, emxArray_real_T *chis, emxArray_cell_wrap_3
  *reflectivity, emxArray_cell_wrap_3 *Simulation, emxArray_cell_wrap_1
  *shifted_data, emxArray_cell_wrap_1 *layerSlds, emxArray_cell_wrap_3
  *sldProfiles, emxArray_cell_wrap_4 *allLayers, emxArray_real_T *allRoughs)
{
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_real_T *shifted_dat;
  emxArray_real_T *outLayers;
  emxArray_real_T *reflect;
  emxArray_real_T *b_allData;
  int ub_loop;
  int i;
  double d0;
  double d1;
  double d2;
  double d3;
  double d4;
  double d5;
  int i0;
  int loop_ub;
  (void)contrastLayers;
  (void)numberOfLayers;
  (void)whichType;
  emxInit_real_T(&sldProfile, 2);
  emxInit_real_T(&layerSld, 2);
  emxInit_real_T(&shifted_dat, 2);
  emxInit_real_T(&outLayers, 2);
  emxInit_real_T(&reflect, 2);
  emxInit_real_T(&b_allData, 2);

  /* coder.extrinsic('callModules');             */
  /* Pre-Allocation... */
  ub_loop = backgs->size[0];
  backgs->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)backgs, ub_loop, (int)sizeof(double));
  ub_loop = qshifts->size[0];
  qshifts->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)qshifts, ub_loop, (int)sizeof(double));
  ub_loop = sfs->size[0];
  sfs->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)sfs, ub_loop, (int)sizeof(double));
  ub_loop = nbas->size[0];
  nbas->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)nbas, ub_loop, (int)sizeof(double));
  ub_loop = nbss->size[0];
  nbss->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)nbss, ub_loop, (int)sizeof(double));
  ub_loop = resols->size[0];
  resols->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)resols, ub_loop, (int)sizeof(double));
  ub_loop = allRoughs->size[0];
  allRoughs->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)allRoughs, ub_loop, (int)sizeof(double));
  ub_loop = allLayers->size[0] * allLayers->size[1];
  allLayers->size[0] = (int)numberOfContrasts;
  allLayers->size[1] = 1;
  emxEnsureCapacity_cell_wrap_4(allLayers, ub_loop);
  ub_loop = outSsubs->size[0];
  outSsubs->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)outSsubs, ub_loop, (int)sizeof(double));
  ub_loop = sldProfiles->size[0] * sldProfiles->size[1];
  sldProfiles->size[0] = (int)numberOfContrasts;
  sldProfiles->size[1] = 1;
  emxEnsureCapacity_cell_wrap_3(sldProfiles, ub_loop);
  ub_loop = layerSlds->size[0] * layerSlds->size[1];
  layerSlds->size[0] = (int)numberOfContrasts;
  layerSlds->size[1] = 1;
  emxEnsureCapacity_cell_wrap_1(layerSlds, ub_loop);
  ub_loop = shifted_data->size[0] * shifted_data->size[1];
  shifted_data->size[0] = (int)numberOfContrasts;
  shifted_data->size[1] = 1;
  emxEnsureCapacity_cell_wrap_1(shifted_data, ub_loop);
  ub_loop = reflectivity->size[0] * reflectivity->size[1];
  reflectivity->size[0] = (int)numberOfContrasts;
  reflectivity->size[1] = 1;
  emxEnsureCapacity_cell_wrap_3(reflectivity, ub_loop);
  ub_loop = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = (int)numberOfContrasts;
  Simulation->size[1] = 1;
  emxEnsureCapacity_cell_wrap_3(Simulation, ub_loop);
  ub_loop = chis->size[0];
  chis->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)chis, ub_loop, (int)sizeof(double));
  ub_loop = (int)numberOfContrasts - 1;

#pragma omp parallel \
 num_threads(omp_get_max_threads()) \
 private(b_allData,outLayers,layerSld,shifted_dat,reflect,sldProfile,d0,d1,d2,d3,d4,d5,i0,loop_ub)

  {
    emxInit_real_T(&b_allData, 2);
    emxInit_real_T(&outLayers, 2);
    emxInit_real_T(&layerSld, 2);
    emxInit_real_T(&shifted_dat, 2);
    emxInit_real_T(&reflect, 2);
    emxInit_real_T(&sldProfile, 2);

#pragma omp for nowait

    for (i = 0; i <= ub_loop; i++) {
      backSort(cBacks->data[i], cShifts->data[i], cScales->data[i], cNbas->
               data[i], cNbss->data[i], cRes->data[i], backs, shifts, sf, nba,
               nbs, res, &d5, &d4, &d3, &d2, &d1, &d0);
      backgs->data[i] = d5;
      qshifts->data[i] = d4;
      sfs->data[i] = d3;
      nbas->data[i] = d2;
      nbss->data[i] = d1;
      resols->data[i] = d0;
      call_customLayers(params, 1.0 + (double)i, fileHandle, path, nbairs->
                        data[i], nbsubs->data[i], outLayers, &d0);
      allRoughs->data[i] = d0;
      i0 = allLayers->data[i].f1->size[0] * allLayers->data[i].f1->size[1];
      allLayers->data[i].f1->size[0] = outLayers->size[0];
      allLayers->data[i].f1->size[1] = outLayers->size[1];
      emxEnsureCapacity((emxArray__common *)allLayers->data[i].f1, i0, (int)
                        sizeof(double));
      loop_ub = outLayers->size[0] * outLayers->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        allLayers->data[i].f1->data[i0] = outLayers->data[i0];
      }

      groupLayers_Mod(outLayers, allRoughs->data[i], geometry, layerSld, &d0);
      outSsubs->data[i] = d0;
      makeSLDProfiles(nbairs->data[i], nbsubs->data[i], layerSld, outSsubs->
                      data[i], repeats->data[repeats->size[0] * i].f1,
                      sldProfile);
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

      callReflectivity(nbairs->data[i], nbsubs->data[i], simLimits->
                       data[simLimits->size[0] * i].f1, repeatLayers->
                       data[repeatLayers->size[0] * i].f1, shifted_dat, layerSld,
                       outSsubs->data[i], backgs->data[i], resols->data[i],
                       reflect, sldProfile);
      i0 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
      reflectivity->data[i].f1->size[0] = reflect->size[0];
      reflectivity->data[i].f1->size[1] = 2;
      emxEnsureCapacity((emxArray__common *)reflectivity->data[i].f1, i0, (int)
                        sizeof(double));
      loop_ub = reflect->size[0] * reflect->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        reflectivity->data[i].f1->data[i0] = reflect->data[i0];
      }

      i0 = Simulation->data[i].f1->size[0] * Simulation->data[i].f1->size[1];
      Simulation->data[i].f1->size[0] = sldProfile->size[0];
      Simulation->data[i].f1->size[1] = 2;
      emxEnsureCapacity((emxArray__common *)Simulation->data[i].f1, i0, (int)
                        sizeof(double));
      loop_ub = sldProfile->size[0] * sldProfile->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        Simulation->data[i].f1->data[i0] = sldProfile->data[i0];
      }

      chis->data[i] = chiSquared(shifted_dat, reflect, nParams);
    }

    emxFree_real_T(&sldProfile);
    emxFree_real_T(&reflect);
    emxFree_real_T(&shifted_dat);
    emxFree_real_T(&layerSld);
    emxFree_real_T(&outLayers);
    emxFree_real_T(&b_allData);
  }

  emxFree_real_T(&b_allData);
  emxFree_real_T(&reflect);
  emxFree_real_T(&outLayers);
  emxFree_real_T(&shifted_dat);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);
}

/* End of code generation (standardTF_custlay_parallel.c) */
