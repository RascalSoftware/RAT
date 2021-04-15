//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_stanlay_paraContrasts.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
//

// Include Files
#include "standardTF_stanlay_paraContrasts.h"
#include "allocateLayersForContrast.h"
#include "backSort.h"
#include "groupLayers_Mod.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "standardTF_stanlay_paraAll.h"

// Function Definitions

//
// Extract individual cell arrays
// Arguments    : const struct0_T *problemDef
//                const cell_14 *problemDef_cells
//                const struct2_T *controls
//                coder::array<double, 1U> *outSsubs
//                coder::array<double, 1U> *backgs
//                coder::array<double, 1U> *qshifts
//                coder::array<double, 1U> *sfs
//                coder::array<double, 1U> *nbas
//                coder::array<double, 1U> *nbss
//                coder::array<double, 1U> *resols
//                coder::array<double, 1U> *chis
//                coder::array<cell_wrap_7, 1U> *reflectivity
//                coder::array<cell_wrap_7, 1U> *Simulation
//                coder::array<cell_wrap_1, 1U> *shifted_data
//                coder::array<cell_wrap_8, 1U> *layerSlds
//                coder::array<cell_wrap_1, 1U> *sldProfiles
//                coder::array<cell_wrap_12, 1U> *allLayers
//                coder::array<double, 1U> *allRoughs
// Return Type  : void
//
void c_standardTF_stanlay_paraContra(const struct0_T *problemDef, const cell_14 *
  problemDef_cells, const struct2_T *controls, coder::array<double, 1U>
  &outSsubs, coder::array<double, 1U> &backgs, coder::array<double, 1U> &qshifts,
  coder::array<double, 1U> &sfs, coder::array<double, 1U> &nbas, coder::array<
  double, 1U> &nbss, coder::array<double, 1U> &resols, coder::array<double, 1U>
  &chis, coder::array<cell_wrap_7, 1U> &reflectivity, coder::array<cell_wrap_7,
  1U> &Simulation, coder::array<cell_wrap_1, 1U> &shifted_data, coder::array<
  cell_wrap_8, 1U> &layerSlds, coder::array<cell_wrap_1, 1U> &sldProfiles, coder::
  array<cell_wrap_12, 1U> &allLayers, coder::array<double, 1U> &allRoughs)
{
  coder::array<cell_wrap_0, 2U> repeatLayers;
  int loop_ub;
  int i;
  coder::array<cell_wrap_1, 2U> allData;
  coder::array<cell_wrap_0, 2U> dataLimits;
  coder::array<cell_wrap_0, 2U> simLimits;
  coder::array<cell_wrap_2, 2U> contrastLayers;
  coder::array<char, 2U> geometry;
  coder::array<double, 2U> cBacks;
  coder::array<double, 2U> cShifts;
  coder::array<double, 2U> cScales;
  coder::array<double, 2U> cNbas;
  coder::array<double, 2U> cNbss;
  coder::array<double, 2U> cRes;
  coder::array<double, 2U> backs;
  coder::array<double, 2U> shifts;
  coder::array<double, 2U> sf;
  coder::array<double, 2U> nba;
  coder::array<double, 2U> nbs;
  coder::array<double, 2U> res;
  coder::array<double, 2U> dataPresent;
  int nParams;
  coder::array<double, 2U> params;
  coder::array<double, 2U> resample;
  coder::array<double, 2U> backsType;
  double calcSld;
  const coder::array<cell_wrap_2, 1U> *layersDetails;
  int i1;
  coder::array<cell_wrap_15, 2U> outParameterisedLayers;
  double thisOutLayer[5];
  coder::array<double, 2U> thisContrastLayers;
  coder::array<double, 2U> sldProfile;
  coder::array<double, 2U> reflect;
  coder::array<double, 2U> Simul;
  coder::array<double, 2U> thisData;
  coder::array<double, 2U> layerSld;
  double thisSsubs;
  double thisChiSquared;
  double thisResol;
  double thisNbs;
  double thisNba;
  double thisSf;
  double thisQshift;
  double thisBackground;
  int b_loop_ub;
  int i3;
  repeatLayers.set_size(1, problemDef_cells->f1.size(1));
  loop_ub = problemDef_cells->f1.size(0) * problemDef_cells->f1.size(1);
  for (i = 0; i < loop_ub; i++) {
    repeatLayers[i] = problemDef_cells->f1[i];
  }

  allData.set_size(1, problemDef_cells->f2.size(1));
  loop_ub = problemDef_cells->f2.size(0) * problemDef_cells->f2.size(1);
  for (i = 0; i < loop_ub; i++) {
    allData[i] = problemDef_cells->f2[i];
  }

  dataLimits.set_size(1, problemDef_cells->f3.size(1));
  loop_ub = problemDef_cells->f3.size(0) * problemDef_cells->f3.size(1);
  for (i = 0; i < loop_ub; i++) {
    dataLimits[i] = problemDef_cells->f3[i];
  }

  simLimits.set_size(1, problemDef_cells->f4.size(1));
  loop_ub = problemDef_cells->f4.size(0) * problemDef_cells->f4.size(1);
  for (i = 0; i < loop_ub; i++) {
    simLimits[i] = problemDef_cells->f4[i];
  }

  contrastLayers.set_size(1, problemDef_cells->f5.size(1));
  loop_ub = problemDef_cells->f5.size(0) * problemDef_cells->f5.size(1);
  for (i = 0; i < loop_ub; i++) {
    contrastLayers[i] = problemDef_cells->f5[i];
  }

  //  Extract individual parameters from problemDef
  // Extract individual parameters from problemDef
  geometry.set_size(1, problemDef->geometry.size(1));
  loop_ub = problemDef->geometry.size(0) * problemDef->geometry.size(1);
  for (i = 0; i < loop_ub; i++) {
    geometry[i] = problemDef->geometry[i];
  }

  cBacks.set_size(1, problemDef->contrastBacks.size(1));
  loop_ub = problemDef->contrastBacks.size(0) * problemDef->contrastBacks.size(1);
  for (i = 0; i < loop_ub; i++) {
    cBacks[i] = problemDef->contrastBacks[i];
  }

  cShifts.set_size(1, problemDef->contrastShifts.size(1));
  loop_ub = problemDef->contrastShifts.size(0) * problemDef->contrastShifts.size
    (1);
  for (i = 0; i < loop_ub; i++) {
    cShifts[i] = problemDef->contrastShifts[i];
  }

  cScales.set_size(1, problemDef->contrastScales.size(1));
  loop_ub = problemDef->contrastScales.size(0) * problemDef->contrastScales.size
    (1);
  for (i = 0; i < loop_ub; i++) {
    cScales[i] = problemDef->contrastScales[i];
  }

  cNbas.set_size(1, problemDef->contrastNbas.size(1));
  loop_ub = problemDef->contrastNbas.size(0) * problemDef->contrastNbas.size(1);
  for (i = 0; i < loop_ub; i++) {
    cNbas[i] = problemDef->contrastNbas[i];
  }

  cNbss.set_size(1, problemDef->contrastNbss.size(1));
  loop_ub = problemDef->contrastNbss.size(0) * problemDef->contrastNbss.size(1);
  for (i = 0; i < loop_ub; i++) {
    cNbss[i] = problemDef->contrastNbss[i];
  }

  cRes.set_size(1, problemDef->contrastRes.size(1));
  loop_ub = problemDef->contrastRes.size(0) * problemDef->contrastRes.size(1);
  for (i = 0; i < loop_ub; i++) {
    cRes[i] = problemDef->contrastRes[i];
  }

  backs.set_size(1, problemDef->backs.size(1));
  loop_ub = problemDef->backs.size(0) * problemDef->backs.size(1);
  for (i = 0; i < loop_ub; i++) {
    backs[i] = problemDef->backs[i];
  }

  shifts.set_size(1, problemDef->shifts.size(1));
  loop_ub = problemDef->shifts.size(0) * problemDef->shifts.size(1);
  for (i = 0; i < loop_ub; i++) {
    shifts[i] = problemDef->shifts[i];
  }

  sf.set_size(1, problemDef->sf.size(1));
  loop_ub = problemDef->sf.size(0) * problemDef->sf.size(1);
  for (i = 0; i < loop_ub; i++) {
    sf[i] = problemDef->sf[i];
  }

  nba.set_size(1, problemDef->nba.size(1));
  loop_ub = problemDef->nba.size(0) * problemDef->nba.size(1);
  for (i = 0; i < loop_ub; i++) {
    nba[i] = problemDef->nba[i];
  }

  nbs.set_size(1, problemDef->nbs.size(1));
  loop_ub = problemDef->nbs.size(0) * problemDef->nbs.size(1);
  for (i = 0; i < loop_ub; i++) {
    nbs[i] = problemDef->nbs[i];
  }

  res.set_size(1, problemDef->res.size(1));
  loop_ub = problemDef->res.size(0) * problemDef->res.size(1);
  for (i = 0; i < loop_ub; i++) {
    res[i] = problemDef->res[i];
  }

  dataPresent.set_size(1, problemDef->dataPresent.size(1));
  loop_ub = problemDef->dataPresent.size(0) * problemDef->dataPresent.size(1);
  for (i = 0; i < loop_ub; i++) {
    dataPresent[i] = problemDef->dataPresent[i];
  }

  nParams = problemDef->params.size(1);
  params.set_size(1, problemDef->params.size(1));
  loop_ub = problemDef->params.size(0) * problemDef->params.size(1);
  for (i = 0; i < loop_ub; i++) {
    params[i] = problemDef->params[i];
  }

  resample.set_size(1, problemDef->resample.size(1));
  loop_ub = problemDef->resample.size(0) * problemDef->resample.size(1);
  for (i = 0; i < loop_ub; i++) {
    resample[i] = problemDef->resample[i];
  }

  backsType.set_size(1, problemDef->contrastBacksType.size(1));
  loop_ub = problemDef->contrastBacksType.size(0) *
    problemDef->contrastBacksType.size(1);
  for (i = 0; i < loop_ub; i++) {
    backsType[i] = problemDef->contrastBacksType[i];
  }

  calcSld = controls->calcSld;

  //  Allocate the memory for the output arrays before the main loop
  //    --- Begin memory allocation ---
  i = static_cast<int>(problemDef->numberOfContrasts);
  backgs.set_size(i);
  allLayers.set_size(i);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    allLayers[loop_ub].f1.set_size(2);
    allLayers[loop_ub].f1[0] = 1.0;
    allLayers[loop_ub].f1[1] = 1.0;
  }

  //    --- End memory allocation ---
  //  First we need to allocate the absolute values of the input
  //  parameters to all the layers in the layers list. This only needs
  //  to be done once, and so is done outside the contrasts loop
  layersDetails = &problemDef_cells->f6;

  // This function takes the list of all layers (in terms of parameter
  // numbers) in layersDetails, and loops through putting in the correct
  // parameter value from the parameter array in each layer.
  for (i1 = 0; i1 < 5; i1++) {
    thisOutLayer[i1] = 0.0;
  }

  outParameterisedLayers.set_size(1, problemDef_cells->f6.size(0));
  i1 = problemDef_cells->f6.size(0);
  for (loop_ub = 0; loop_ub < i1; loop_ub++) {
    int i2;
    i2 = (*layersDetails)[loop_ub].f1.size(1);
    for (int n = 0; n <= i2 - 2; n++) {
      if (!rtIsNaN((*layersDetails)[loop_ub].f1[n])) {
        thisOutLayer[n] = problemDef->params[static_cast<int>((*layersDetails)
          [loop_ub].f1[n]) - 1];
      } else {
        thisOutLayer[n] = rtNaN;
      }
    }

    thisOutLayer[(*layersDetails)[loop_ub].f1.size(1) - 1] = (*layersDetails)
      [loop_ub].f1[(*layersDetails)[loop_ub].f1.size(1) - 1];
    for (i2 = 0; i2 < 5; i2++) {
      outParameterisedLayers[loop_ub].f1[i2] = thisOutLayer[i2];
    }
  }

  outSsubs.set_size(i);
  sldProfiles.set_size(i);
  reflectivity.set_size(i);
  Simulation.set_size(i);
  shifted_data.set_size(i);
  layerSlds.set_size(i);
  chis.set_size(i);
  qshifts.set_size(i);
  sfs.set_size(i);
  nbas.set_size(i);
  nbss.set_size(i);
  resols.set_size(i);
  allRoughs.set_size(i);
  loop_ub = i - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(thisContrastLayers,sldProfile,reflect,Simul,thisData,layerSld,thisSsubs,thisChiSquared,thisResol,thisNbs,thisNba,thisSf,thisQshift,thisBackground,b_loop_ub,i3)

  for (int b_i = 0; b_i <= loop_ub; b_i++) {
    //  Parallel Loop over all the contrasts
    //  Extract the relevant parameter values for this contrast
    //  from the input arrays.
    //  First need to decide which values of the backrounds, scalefactors
    //  data shifts and bulk contrasts are associated with this contrast
    backSort(cBacks[b_i], cShifts[b_i], cScales[b_i], cNbas[b_i], cNbss[b_i],
             cRes[b_i], backs, shifts, sf, nba, nbs, res, &thisBackground,
             &thisQshift, &thisSf, &thisNba, &thisNbs, &thisResol);

    //  Also need to determine which layers from the overall layers list
    //  are required for this contrast, and put them in the correct order
    //  according to geometry
    allocateLayersForContrast(contrastLayers[b_i].f1, outParameterisedLayers,
      thisContrastLayers);

    //  For the other parameters, we extract the correct ones from the input
    //  arrays
    //  Substrate roughness is always first parameter for standard layers
    //  Now call the core standardTF_stanlay reflectivity calculation
    //  In this case we are single cored  over points.
    //  Call the calculation
    standardTF_layers_core(thisContrastLayers, params[0], geometry, thisNba,
      thisNbs, resample[b_i], calcSld, thisSf, thisQshift, dataPresent[b_i],
      allData[b_i].f1, dataLimits[b_i].f1, simLimits[b_i].f1, repeatLayers[b_i].
      f1, thisBackground, thisResol, backsType[b_i], static_cast<double>(nParams),
      sldProfile, reflect, Simul, thisData, layerSld, &thisChiSquared,
      &thisSsubs);

    //  Store returned values for this contrast in the output arrays.
    //  As well as the calculated profiles, we also store a record of
    //  the other values (background, scalefactors etc) for each contrast
    //  for future use.
    outSsubs[b_i] = thisSsubs;
    sldProfiles[b_i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
    b_loop_ub = sldProfile.size(0) * sldProfile.size(1);
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      sldProfiles[b_i].f1[i3] = sldProfile[i3];
    }

    reflectivity[b_i].f1.set_size(reflect.size(0), 2);
    b_loop_ub = reflect.size(0) * reflect.size(1);
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      reflectivity[b_i].f1[i3] = reflect[i3];
    }

    Simulation[b_i].f1.set_size(Simul.size(0), 2);
    b_loop_ub = Simul.size(0) * Simul.size(1);
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      Simulation[b_i].f1[i3] = Simul[i3];
    }

    shifted_data[b_i].f1.set_size(thisData.size(0), thisData.size(1));
    b_loop_ub = thisData.size(0) * thisData.size(1);
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      shifted_data[b_i].f1[i3] = thisData[i3];
    }

    layerSlds[b_i].f1.set_size(layerSld.size(0), 3);
    b_loop_ub = layerSld.size(0) * layerSld.size(1);
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      layerSlds[b_i].f1[i3] = layerSld[i3];
    }

    chis[b_i] = thisChiSquared;
    backgs[b_i] = thisBackground;
    qshifts[b_i] = thisQshift;
    sfs[b_i] = thisSf;
    nbas[b_i] = thisNba;
    nbss[b_i] = thisNbs;
    resols[b_i] = thisResol;
    allRoughs[b_i] = params[0];
  }
}

//
// File trailer for standardTF_stanlay_paraContrasts.cpp
//
// [EOF]
//
