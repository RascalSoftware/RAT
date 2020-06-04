/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custlay_single.c
 *
 * Code generation for function 'standardTF_custlay_single'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "chiSquared.h"
#include "standardTF_custlay_single_emxutil.h"
#include "callReflectivity.h"
#include "resampleLayers.h"
#include "makeSLDProfileXY.h"
#include "groupLayers_Mod.h"
#include "matlabCallFun.h"

/* Function Definitions */
void standardTF_custlay_single(const emxArray_real_T *resam, double
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
  *reflectivity, emxArray_cell_wrap_3 *Simulation, emxArray_cell_wrap_4
  *shifted_data, emxArray_cell_wrap_4 *layerSlds, emxArray_cell_wrap_3
  *sldProfiles, emxArray_cell_wrap_5 *allLayers, emxArray_real_T *allRoughs)
{
  int i0;
  int i;
  emxArray_real_T *sldProfile;
  emxArray_real_T *layerSld;
  emxArray_real_T *output;
  emxArray_real_T *b_params;
  emxArray_char_T *funName;
  emxArray_char_T *pathCall;
  int loop_ub;
  static const char cv0[17] = { '[', 't', 'o', 't', 'a', 'l', ',', 'l', 'a', 'y',
    'e', 'r', 's', ']', ' ', '=', ' ' };

  static const char cv1[34] = { '(', 'p', 'a', 'r', 'a', 'm', 's', ',', 'b', 'u',
    'l', 'k', '_', 'i', 'n', ',', 'b', 'u', 'l', 'k', '_', 'o', 'u', 't', ',',
    'c', 'o', 'n', 't', 'r', 'a', 's', 't', ')' };

  static const char cv2[5] = { 'c', 'd', '(', '\'', ' ' };

  double outp[30];
  static const char cv3[4] = { ' ', '\'', ')', ';' };

  double nLayers;
  unsigned int rowCount;
  int colCount;
  double b_qshifts;
  int b_i;
  double data[153];
  int shifted_dat_size[2];
  double shifted_dat_data[153];
  boolean_T x[51];
  signed char ii_data[51];
  boolean_T exitg2;
  boolean_T guard2 = false;
  signed char lowIndex_data[51];
  int lowIndex;
  double reflect_data[102];
  int reflect_size[2];
  boolean_T exitg1;
  boolean_T guard1 = false;
  int i1;
  int hiIndex;
  (void)contrastLayers;
  (void)numberOfLayers;
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
  emxEnsureCapacity_cell_wrap_3(sldProfiles, i0);
  i0 = layerSlds->size[0] * layerSlds->size[1];
  layerSlds->size[0] = (int)numberOfContrasts;
  layerSlds->size[1] = 1;
  emxEnsureCapacity_cell_wrap_4(layerSlds, i0);
  i0 = shifted_data->size[0] * shifted_data->size[1];
  shifted_data->size[0] = (int)numberOfContrasts;
  shifted_data->size[1] = 1;
  emxEnsureCapacity_cell_wrap_4(shifted_data, i0);
  i0 = reflectivity->size[0] * reflectivity->size[1];
  reflectivity->size[0] = (int)numberOfContrasts;
  reflectivity->size[1] = 1;
  emxEnsureCapacity_cell_wrap_3(reflectivity, i0);
  i0 = Simulation->size[0] * Simulation->size[1];
  Simulation->size[0] = (int)numberOfContrasts;
  Simulation->size[1] = 1;
  emxEnsureCapacity_cell_wrap_3(Simulation, i0);
  i0 = chis->size[0];
  chis->size[0] = (int)numberOfContrasts;
  emxEnsureCapacity((emxArray__common *)chis, i0, (int)sizeof(double));
  i = 0;
  emxInit_real_T(&sldProfile, 2);
  emxInit_real_T(&layerSld, 2);
  emxInit_real_T(&output, 2);
  emxInit_real_T(&b_params, 2);
  emxInit_char_T(&funName, 2);
  emxInit_char_T(&pathCall, 2);
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

    /* Build with....    codegen matlabEngineCaller_customLayers -o matlabEngineCaller_customLayers */
    /*  assert(isa(params,'double')); */
    /*  assert(all(size(params) == [1 inf])); */
    /*   */
    /*  assert(isa(contrast,'double')); */
    /*  assert(all(size(params) == [1 1])); */
    /*   */
    /*  assert(isa(funcName,'char')); */
    /*  assert(all(size(funcName) == [inf])); */
    /*   */
    /*  assert(isa(funcPath,'char')); */
    /*  assert(all(size(funcName) == [inf])); */
    /*   */
    /*  assert(isa(bulkIn,'double')); */
    /*  assert(all(size(bulkIn) == [1 1])); */
    /*   */
    /*  assert(isa(bulkOut,'double')); */
    /*  assert(all(size(params) == [1 1])); */
    /* pathCall = 'cd(''/home/arwel/eclipseWorkspace_new/matlabEngine_demo/src'');'; */
    /* libName = 'LinkObj.lib'; */
    /* libPath = 'c:\Link_Objects'; */
    /* coder.updateBuildInfo('addLinkObjects', libName, libPath, ... */
    /* libPriority, libPreCompiled, libLinkOnly); */
    /* coder.updateBuildInfo('addSourceFiles',filename) */
    /* matlabCallFun(params, paramsLen, funName, pathCall, bulkIn, bulkOut, contrast, s); */
    i0 = b_params->size[0] * b_params->size[1];
    b_params->size[0] = 1;
    b_params->size[1] = params->size[1];
    emxEnsureCapacity((emxArray__common *)b_params, i0, (int)sizeof(double));
    loop_ub = params->size[0] * params->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_params->data[i0] = params->data[i0];
    }

    i0 = funName->size[0] * funName->size[1];
    funName->size[0] = 1;
    funName->size[1] = 51 + fileHandle->size[1];
    emxEnsureCapacity((emxArray__common *)funName, i0, (int)sizeof(char));
    for (i0 = 0; i0 < 17; i0++) {
      funName->data[funName->size[0] * i0] = cv0[i0];
    }

    loop_ub = fileHandle->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      funName->data[funName->size[0] * (i0 + 17)] = fileHandle->data
        [fileHandle->size[0] * i0];
    }

    for (i0 = 0; i0 < 34; i0++) {
      funName->data[funName->size[0] * ((i0 + fileHandle->size[1]) + 17)] =
        cv1[i0];
    }

    i0 = pathCall->size[0] * pathCall->size[1];
    pathCall->size[0] = 1;
    pathCall->size[1] = 9 + path->size[1];
    emxEnsureCapacity((emxArray__common *)pathCall, i0, (int)sizeof(char));
    for (i0 = 0; i0 < 5; i0++) {
      pathCall->data[pathCall->size[0] * i0] = cv2[i0];
    }

    loop_ub = path->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      pathCall->data[pathCall->size[0] * (i0 + 5)] = path->data[path->size[0] *
        i0];
    }

    for (i0 = 0; i0 < 4; i0++) {
      pathCall->data[pathCall->size[0] * ((i0 + path->size[1]) + 5)] = cv3[i0];
    }

    matlabCallFun(&b_params->data[0], (double)params->size[1], &funName->data[0],
                  &pathCall->data[0], nbairs->data[i], nbsubs->data[i], 1.0 +
                  (double)i, outp, &nLayers);
    rowCount = 1U;
    colCount = 0;
    if (nLayers >= 1.0) {
      i0 = output->size[0] * output->size[1];
      output->size[0] = (int)nLayers;
      output->size[1] = 3;
      emxEnsureCapacity((emxArray__common *)output, i0, (int)sizeof(double));
      loop_ub = (int)nLayers * 3;
      for (i0 = 0; i0 < loop_ub; i0++) {
        output->data[i0] = 0.0;
      }

      b_qshifts = nLayers * 3.0;
      for (b_i = 0; b_i < (int)b_qshifts; b_i++) {
        output->data[((int)rowCount + output->size[0] * colCount) - 1] =
          outp[b_i];
        rowCount++;
        if (rowCount == nLayers + 1.0) {
          rowCount = 1U;
          colCount++;
        }
      }
    } else {
      i0 = output->size[0] * output->size[1];
      output->size[0] = 0;
      output->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)output, i0, (int)sizeof(double));
    }

    allRoughs->data[i] = params->data[0];
    i0 = allLayers->data[i].f1->size[0] * allLayers->data[i].f1->size[1];
    allLayers->data[i].f1->size[0] = output->size[0];
    allLayers->data[i].f1->size[1] = output->size[1];
    emxEnsureCapacity((emxArray__common *)allLayers->data[i].f1, i0, (int)sizeof
                      (double));
    loop_ub = output->size[0] * output->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      allLayers->data[i].f1->data[i0] = output->data[i0];
    }

    groupLayers_Mod(output, allRoughs->data[i], geometry, layerSld,
                    &outSsubs->data[i]);
    if (repeats->data[repeats->size[0] * i].f1[0] == 0.0) {
      nLayers = 1.0;
    } else {
      nLayers = repeats->data[repeats->size[0] * i].f1[1];
    }

    makeSLDProfileXY(nbairs->data[i], nbsubs->data[i], outSsubs->data[i],
                     layerSld, layerSld->size[0], nLayers, sldProfile);
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

    nLayers = sfs->data[i];
    for (i0 = 0; i0 < 153; i0++) {
      data[i0] = allData->data[allData->size[0] * i].f1[i0];
    }

    /* Shifts the data according to scale factor */
    /*  scalefac = problem.scalefactors; */
    /*  horshift = problem.qshifts; */
    /*  numberOfContrasts = problem.numberOfContrasts; */
    /*  dataPresent = problem.dataPresent; */
    /*  allData = problem.data; */
    /*  dataLimits = problem.dataLimits; */
    /* shifted_data = cell(1,numberOfContrasts); */
    switch ((int)dataPresent->data[i]) {
     case 1:
      if (sfs->data[i] == 0.0) {
        nLayers = 1.0E-30;
      }

      b_qshifts = qshifts->data[i];
      for (i0 = 0; i0 < 51; i0++) {
        data[i0] = allData->data[allData->size[0] * i].f1[i0] + b_qshifts;
      }

      for (i0 = 0; i0 < 51; i0++) {
        data[51 + i0] /= nLayers;
        data[102 + i0] /= nLayers;
      }

      nLayers = dataLimits->data[dataLimits->size[0] * i].f1[0];
      for (i0 = 0; i0 < 51; i0++) {
        x[i0] = (data[i0] < nLayers);
      }

      colCount = 0;
      b_i = 1;
      exitg2 = false;
      while ((!exitg2) && (b_i < 52)) {
        guard2 = false;
        if (x[b_i - 1]) {
          colCount++;
          ii_data[colCount - 1] = (signed char)b_i;
          if (colCount >= 51) {
            exitg2 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          b_i++;
        }
      }

      if (1 > colCount) {
        b_i = 0;
        loop_ub = 0;
      } else {
        b_i = colCount;
        loop_ub = colCount;
      }

      for (i0 = 0; i0 < loop_ub; i0++) {
        lowIndex_data[i0] = ii_data[i0];
      }

      if (!(b_i == 0)) {
        lowIndex = lowIndex_data[b_i - 1];
      } else {
        lowIndex = 1;
      }

      nLayers = dataLimits->data[dataLimits->size[0] * i].f1[1];
      for (i0 = 0; i0 < 51; i0++) {
        x[i0] = (data[i0] > nLayers);
      }

      colCount = 0;
      b_i = 1;
      exitg1 = false;
      while ((!exitg1) && (b_i < 52)) {
        guard1 = false;
        if (x[b_i - 1]) {
          colCount++;
          ii_data[colCount - 1] = (signed char)b_i;
          if (colCount >= 51) {
            exitg1 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          b_i++;
        }
      }

      if (1 > colCount) {
        loop_ub = 0;
      } else {
        loop_ub = colCount;
      }

      for (i0 = 0; i0 < loop_ub; i0++) {
        lowIndex_data[i0] = ii_data[i0];
      }

      if (1 > colCount) {
        i1 = 0;
      } else {
        i1 = colCount;
      }

      if (!(i1 == 0)) {
        hiIndex = lowIndex_data[0];
      } else {
        hiIndex = 51;
      }

      if (lowIndex > hiIndex) {
        i0 = 0;
        hiIndex = 0;
      } else {
        i0 = lowIndex - 1;
      }

      shifted_dat_size[0] = hiIndex - i0;
      shifted_dat_size[1] = 3;
      for (b_i = 0; b_i < 3; b_i++) {
        loop_ub = hiIndex - i0;
        for (colCount = 0; colCount < loop_ub; colCount++) {
          shifted_dat_data[colCount + shifted_dat_size[0] * b_i] = data[(i0 +
            colCount) + 51 * b_i];
        }
      }
      break;

     default:
      shifted_dat_size[0] = 51;
      shifted_dat_size[1] = 3;
      for (i0 = 0; i0 < 153; i0++) {
        shifted_dat_data[i0] = allData->data[allData->size[0] * i].f1[i0];
      }
      break;
    }

    /*  function Ref = makeFresnelData(problem,contrast) */
    /*   */
    /*      this_data = problem.shifted_data{contrast}; */
    /*      xdata = this_data(:,1); */
    /*      nbair = problem.nbairs(contrast); */
    /*      nbsub = problem.nbsubs(contrast); */
    /*      slds = [0 0 0]; */
    /*      resol = problem.resolution; */
    /*      resolType = problem.resolType; */
    /*      %abeles(xdata,SLDs,nbair,nbsub,ssub,nrepeats,sinter,resol) */
    /*      %Ref = abeles_new_2(xdata,slds,nbair,nbsub,s_sub,repeats, */
    /*      Ref = abeles_new_2(xdata,slds,nbair,nbsub,0,1,resolType,resol); */
    i0 = shifted_data->data[i].f1->size[0] * shifted_data->data[i].f1->size[1];
    shifted_data->data[i].f1->size[0] = shifted_dat_size[0];
    shifted_data->data[i].f1->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)shifted_data->data[i].f1, i0, (int)
                      sizeof(double));
    loop_ub = shifted_dat_size[0] * 3;
    for (i0 = 0; i0 < loop_ub; i0++) {
      shifted_data->data[i].f1->data[i0] = shifted_dat_data[i0];
    }

    callReflectivity(nbairs->data[i], nbsubs->data[i], simLimits->data
                     [simLimits->size[0] * i].f1, repeatLayers->
                     data[repeatLayers->size[0] * i].f1, shifted_dat_data,
                     shifted_dat_size, layerSld, outSsubs->data[i], backgs->
                     data[i], resols->data[i], reflect_data, reflect_size,
                     Simulation->data[i].f1);
    i0 = reflectivity->data[i].f1->size[0] * reflectivity->data[i].f1->size[1];
    reflectivity->data[i].f1->size[0] = reflect_size[0];
    reflectivity->data[i].f1->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)reflectivity->data[i].f1, i0, (int)
                      sizeof(double));
    loop_ub = reflect_size[0] * reflect_size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      reflectivity->data[i].f1->data[i0] = reflect_data[i0];
    }

    chis->data[i] = chiSquared(shifted_dat_data, shifted_dat_size, reflect_data,
      reflect_size, nParams);
    i++;
  }

  emxFree_char_T(&pathCall);
  emxFree_char_T(&funName);
  emxFree_real_T(&b_params);
  emxFree_real_T(&output);
  emxFree_real_T(&layerSld);
  emxFree_real_T(&sldProfile);
}

/* End of code generation (standardTF_custlay_single.c) */
