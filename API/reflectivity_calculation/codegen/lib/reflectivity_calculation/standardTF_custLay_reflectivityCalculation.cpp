//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_custLay_reflectivityCalculation.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "standardTF_custLay_reflectivityCalculation.h"
#include "matlabEngineCaller_customLayers.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"
#include "standardTF_custXY_reflectivityCalculation.h"
#include "standardTF_custlay_paraContrasts.h"
#include "standardTF_custlay_paraPoints.h"
#include "standardTF_custlay_single.h"
#include "standardTF_reflectivityCalculation.h"

// Function Definitions

//
// Arguments    : const struct0_T *problemDef
//                const cell_13 *problemDef_cells
//                const struct2_T *controls
//                struct4_T *problem
//                coder::array<cell_wrap_14, 1U> *reflectivity
//                coder::array<cell_wrap_8, 1U> *Simulation
//                coder::array<cell_wrap_9, 1U> *shifted_data
//                coder::array<cell_wrap_9, 1U> *layerSlds
//                coder::array<cell_wrap_8, 1U> *sldProfiles
//                coder::array<cell_wrap_15, 1U> *allLayers
// Return Type  : void
//
void c_standardTF_custLay_reflectivi(const struct0_T *problemDef, const cell_13 *
  problemDef_cells, const struct2_T *controls, struct4_T *problem, coder::array<
  cell_wrap_14, 1U> &reflectivity, coder::array<cell_wrap_8, 1U> &Simulation,
  coder::array<cell_wrap_9, 1U> &shifted_data, coder::array<cell_wrap_9, 1U>
  &layerSlds, coder::array<cell_wrap_8, 1U> &sldProfiles, coder::array<
  cell_wrap_15, 1U> &allLayers)
{
  int vlen;
  coder::array<double, 1U> chis;
  int i;
  boolean_T b_bool;
  int exitg1;
  static const char b_cv[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

  coder::array<cell_wrap_8, 1U> r;
  coder::array<cell_wrap_8, 1U> r1;
  coder::array<cell_wrap_1, 1U> b_shifted_data;
  coder::array<cell_wrap_1, 1U> b_layerSlds;
  coder::array<cell_wrap_6, 1U> b_sldProfiles;
  coder::array<cell_wrap_15, 1U> r2;
  coder::array<cell_wrap_6, 1U> b_reflectivity;
  int b_i;
  static const char b_cv1[6] = { 'p', 'o', 'i', 'n', 't', 's' };

  coder::array<cell_wrap_6, 1U> b_Simulation;
  double y;
  coder::array<cell_wrap_11, 1U> b_allLayers;

  // Extract individual parameters from problemDef
  // nbairs = problemDef.nbairs;
  // nbsubs = problemDef.nbsubs;
  // repeats = problemDef.repeatLayers;
  // allData = problemDef.allData;
  // dataLimits = problemDef.dataLimits;
  // simLimits = problemDef.simLimits;
  // repeatLayers = problemDef.repeatLayers;
  // contrastLayers = problemDef.contrastLayers;
  // layersDetails = problemDef.layersDetails;
  // Pre-allocation
  problem->ssubs.set_size(1);
  problem->ssubs[0] = problemDef->params[0];
  vlen = static_cast<int>(problemDef->numberOfContrasts);
  problem->backgrounds.set_size(vlen);
  problem->qshifts.set_size(vlen);
  problem->scalefactors.set_size(vlen);
  problem->nbairs.set_size(vlen);
  problem->nbsubs.set_size(vlen);
  chis.set_size(vlen);
  problem->resolutions.set_size(vlen);
  problem->allSubRough.set_size(vlen);
  reflectivity.set_size(vlen);
  Simulation.set_size(vlen);
  shifted_data.set_size(vlen);
  layerSlds.set_size(vlen);
  sldProfiles.set_size(vlen);
  allLayers.set_size(vlen);
  for (i = 0; i < vlen; i++) {
    problem->backgrounds[i] = 0.0;
    problem->qshifts[i] = 0.0;
    problem->scalefactors[i] = 0.0;
    problem->nbairs[i] = 0.0;
    problem->nbsubs[i] = 0.0;
    chis[i] = 0.0;
    problem->resolutions[i] = 0.0;
    problem->allSubRough[i] = 0.0;
    reflectivity[i].f1.set_size(2, 2);
    reflectivity[i].f1[0] = 1.0;
    reflectivity[i].f1[1] = 1.0;
    reflectivity[i].f1[2] = 1.0;
    reflectivity[i].f1[3] = 1.0;
    Simulation[i].f1.set_size(2, 2);
    Simulation[i].f1[0] = 1.0;
    Simulation[i].f1[1] = 1.0;
    Simulation[i].f1[2] = 1.0;
    Simulation[i].f1[3] = 1.0;
    shifted_data[i].f1.set_size(2, 3);
    layerSlds[i].f1.set_size(2, 3);
    for (b_i = 0; b_i < 6; b_i++) {
      shifted_data[i].f1[b_i] = 1.0;
      layerSlds[i].f1[b_i] = 1.0;
    }

    sldProfiles[i].f1.set_size(2, 2);
    sldProfiles[i].f1[0] = 1.0;
    sldProfiles[i].f1[1] = 1.0;
    sldProfiles[i].f1[2] = 1.0;
    sldProfiles[i].f1[3] = 1.0;
    allLayers[i].f1.set_size(2, 1);
    allLayers[i].f1[0] = 1.0;
    allLayers[i].f1[1] = 1.0;
  }

  b_bool = false;
  if (controls->para.size(1) == 6) {
    vlen = 0;
    do {
      exitg1 = 0;
      if (vlen < 6) {
        if (controls->para[vlen] != b_cv[vlen]) {
          exitg1 = 1;
        } else {
          vlen++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    vlen = 0;
  } else {
    b_bool = false;
    if (controls->para.size(1) == 6) {
      vlen = 0;
      do {
        exitg1 = 0;
        if (vlen < 6) {
          if (controls->para[vlen] != b_cv1[vlen]) {
            exitg1 = 1;
          } else {
            vlen++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      vlen = 1;
    } else {
      b_bool = false;
      if (controls->para.size(1) == 9) {
        vlen = 0;
        do {
          exitg1 = 0;
          if (vlen < 9) {
            if (controls->para[vlen] != cv[vlen]) {
              exitg1 = 1;
            } else {
              vlen++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }

      if (b_bool) {
        vlen = 2;
      } else {
        vlen = -1;
      }
    }
  }

  switch (vlen) {
   case 0:
    {
      int i1;
      standardTF_custlay_single(problemDef->resample,
        problemDef->numberOfContrasts, problemDef->geometry,
        problemDef_cells->f1, problemDef->contrastBacks,
        problemDef->contrastShifts, problemDef->contrastScales,
        problemDef->contrastNbas, problemDef->contrastNbss,
        problemDef->contrastRes, problemDef->backs, problemDef->shifts,
        problemDef->sf, problemDef->nba, problemDef->nbs, problemDef->res,
        problemDef->dataPresent, problemDef_cells->f2, problemDef_cells->f3,
        problemDef_cells->f4, static_cast<double>(problemDef->params.size(1)),
        problemDef->params, problemDef->modelFilename, problemDef->path,
        problemDef->contrastBacksType, problem->ssubs, problem->backgrounds,
        problem->qshifts, problem->scalefactors, problem->nbairs,
        problem->nbsubs, problem->resolutions, chis, r, r1, b_shifted_data,
        b_layerSlds, b_sldProfiles, r2, problem->allSubRough);
      b_reflectivity.set_size(r.size(0));
      b_i = r.size(0);
      for (i = 0; i < b_i; i++) {
        b_reflectivity[i].f1.set_size(r[i].f1.size(0), 2);
        vlen = r[i].f1.size(0) * r[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          b_reflectivity[i].f1[i1] = r[i].f1[i1];
        }
      }

      b_Simulation.set_size(r1.size(0));
      b_i = r1.size(0);
      for (i = 0; i < b_i; i++) {
        b_Simulation[i].f1.set_size(r1[i].f1.size(0), 2);
        vlen = r1[i].f1.size(0) * r1[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          b_Simulation[i].f1[i1] = r1[i].f1[i1];
        }
      }

      b_allLayers.set_size(r2.size(0));
      b_i = r2.size(0);
      for (i = 0; i < b_i; i++) {
        b_allLayers[i].f1.set_size(r2[i].f1.size(0), r2[i].f1.size(1));
        vlen = r2[i].f1.size(0) * r2[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          b_allLayers[i].f1[i1] = r2[i].f1[i1];
        }
      }

      reflectivity.set_size(b_reflectivity.size(0));
      b_i = b_reflectivity.size(0);
      for (i = 0; i < b_i; i++) {
        reflectivity[i].f1.set_size(b_reflectivity[i].f1.size(0), 2);
        vlen = b_reflectivity[i].f1.size(0) * b_reflectivity[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          reflectivity[i].f1[i1] = b_reflectivity[i].f1[i1];
        }
      }

      Simulation.set_size(b_Simulation.size(0));
      b_i = b_Simulation.size(0);
      for (i = 0; i < b_i; i++) {
        Simulation[i].f1.set_size(b_Simulation[i].f1.size(0), 2);
        vlen = b_Simulation[i].f1.size(0) * b_Simulation[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          Simulation[i].f1[i1] = b_Simulation[i].f1[i1];
        }
      }

      shifted_data.set_size(b_shifted_data.size(0));
      b_i = b_shifted_data.size(0);
      for (i = 0; i < b_i; i++) {
        shifted_data[i].f1.set_size(b_shifted_data[i].f1.size(0), 3);
        vlen = b_shifted_data[i].f1.size(0) * b_shifted_data[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          shifted_data[i].f1[i1] = b_shifted_data[i].f1[i1];
        }
      }

      layerSlds.set_size(b_layerSlds.size(0));
      b_i = b_layerSlds.size(0);
      for (i = 0; i < b_i; i++) {
        layerSlds[i].f1.set_size(b_layerSlds[i].f1.size(0), 3);
        vlen = b_layerSlds[i].f1.size(0) * b_layerSlds[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          layerSlds[i].f1[i1] = b_layerSlds[i].f1[i1];
        }
      }

      sldProfiles.set_size(b_sldProfiles.size(0));
      b_i = b_sldProfiles.size(0);
      for (i = 0; i < b_i; i++) {
        sldProfiles[i].f1.set_size(b_sldProfiles[i].f1.size(0), 2);
        vlen = b_sldProfiles[i].f1.size(0) * b_sldProfiles[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          sldProfiles[i].f1[i1] = b_sldProfiles[i].f1[i1];
        }
      }

      allLayers.set_size(b_allLayers.size(0));
      b_i = b_allLayers.size(0);
      for (i = 0; i < b_i; i++) {
        allLayers[i].f1.set_size(b_allLayers[i].f1.size(0), b_allLayers[i].
          f1.size(1));
        vlen = b_allLayers[i].f1.size(0) * b_allLayers[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          allLayers[i].f1[i1] = b_allLayers[i].f1[i1];
        }
      }
    }
    break;

   case 1:
    {
      int i1;
      standardTF_custlay_paraPoints(problemDef->resample,
        problemDef->numberOfContrasts, problemDef->geometry,
        problemDef_cells->f1, problemDef->contrastBacks,
        problemDef->contrastShifts, problemDef->contrastScales,
        problemDef->contrastNbas, problemDef->contrastNbss,
        problemDef->contrastRes, problemDef->backs, problemDef->shifts,
        problemDef->sf, problemDef->nba, problemDef->nbs, problemDef->res,
        problemDef->dataPresent, problemDef_cells->f2, problemDef_cells->f3,
        problemDef_cells->f4, static_cast<double>(problemDef->params.size(1)),
        problemDef->params, problemDef->modelFilename, problemDef->path,
        problemDef->contrastBacksType, problem->ssubs, problem->backgrounds,
        problem->qshifts, problem->scalefactors, problem->nbairs,
        problem->nbsubs, problem->resolutions, chis, r, r1, b_shifted_data,
        b_layerSlds, b_sldProfiles, r2, problem->allSubRough);
      b_reflectivity.set_size(r.size(0));
      b_i = r.size(0);
      for (i = 0; i < b_i; i++) {
        b_reflectivity[i].f1.set_size(r[i].f1.size(0), 2);
        vlen = r[i].f1.size(0) * r[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          b_reflectivity[i].f1[i1] = r[i].f1[i1];
        }
      }

      b_Simulation.set_size(r1.size(0));
      b_i = r1.size(0);
      for (i = 0; i < b_i; i++) {
        b_Simulation[i].f1.set_size(r1[i].f1.size(0), 2);
        vlen = r1[i].f1.size(0) * r1[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          b_Simulation[i].f1[i1] = r1[i].f1[i1];
        }
      }

      b_allLayers.set_size(r2.size(0));
      b_i = r2.size(0);
      for (i = 0; i < b_i; i++) {
        b_allLayers[i].f1.set_size(r2[i].f1.size(0), r2[i].f1.size(1));
        vlen = r2[i].f1.size(0) * r2[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          b_allLayers[i].f1[i1] = r2[i].f1[i1];
        }
      }

      reflectivity.set_size(b_reflectivity.size(0));
      b_i = b_reflectivity.size(0);
      for (i = 0; i < b_i; i++) {
        reflectivity[i].f1.set_size(b_reflectivity[i].f1.size(0), 2);
        vlen = b_reflectivity[i].f1.size(0) * b_reflectivity[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          reflectivity[i].f1[i1] = b_reflectivity[i].f1[i1];
        }
      }

      Simulation.set_size(b_Simulation.size(0));
      b_i = b_Simulation.size(0);
      for (i = 0; i < b_i; i++) {
        Simulation[i].f1.set_size(b_Simulation[i].f1.size(0), 2);
        vlen = b_Simulation[i].f1.size(0) * b_Simulation[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          Simulation[i].f1[i1] = b_Simulation[i].f1[i1];
        }
      }

      shifted_data.set_size(b_shifted_data.size(0));
      b_i = b_shifted_data.size(0);
      for (i = 0; i < b_i; i++) {
        shifted_data[i].f1.set_size(b_shifted_data[i].f1.size(0), 3);
        vlen = b_shifted_data[i].f1.size(0) * b_shifted_data[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          shifted_data[i].f1[i1] = b_shifted_data[i].f1[i1];
        }
      }

      layerSlds.set_size(b_layerSlds.size(0));
      b_i = b_layerSlds.size(0);
      for (i = 0; i < b_i; i++) {
        layerSlds[i].f1.set_size(b_layerSlds[i].f1.size(0), 3);
        vlen = b_layerSlds[i].f1.size(0) * b_layerSlds[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          layerSlds[i].f1[i1] = b_layerSlds[i].f1[i1];
        }
      }

      sldProfiles.set_size(b_sldProfiles.size(0));
      b_i = b_sldProfiles.size(0);
      for (i = 0; i < b_i; i++) {
        sldProfiles[i].f1.set_size(b_sldProfiles[i].f1.size(0), 2);
        vlen = b_sldProfiles[i].f1.size(0) * b_sldProfiles[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          sldProfiles[i].f1[i1] = b_sldProfiles[i].f1[i1];
        }
      }

      allLayers.set_size(b_allLayers.size(0));
      b_i = b_allLayers.size(0);
      for (i = 0; i < b_i; i++) {
        allLayers[i].f1.set_size(b_allLayers[i].f1.size(0), b_allLayers[i].
          f1.size(1));
        vlen = b_allLayers[i].f1.size(0) * b_allLayers[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          allLayers[i].f1[i1] = b_allLayers[i].f1[i1];
        }
      }
    }
    break;

   case 2:
    {
      int i1;
      c_standardTF_custlay_paraContra(problemDef->resample,
        problemDef->numberOfContrasts, problemDef->geometry,
        problemDef_cells->f1, problemDef->contrastBacks,
        problemDef->contrastShifts, problemDef->contrastScales,
        problemDef->contrastNbas, problemDef->contrastNbss,
        problemDef->contrastRes, problemDef->backs, problemDef->shifts,
        problemDef->sf, problemDef->nba, problemDef->nbs, problemDef->res,
        problemDef->dataPresent, problemDef_cells->f2, problemDef_cells->f3,
        problemDef_cells->f4, static_cast<double>(problemDef->params.size(1)),
        problemDef->params, problemDef->modelFilename, problemDef->path,
        problemDef->contrastBacksType, problem->ssubs, problem->backgrounds,
        problem->qshifts, problem->scalefactors, problem->nbairs,
        problem->nbsubs, problem->resolutions, chis, r, r1, b_shifted_data,
        b_layerSlds, b_sldProfiles, r2, problem->allSubRough);
      b_reflectivity.set_size(r.size(0));
      b_i = r.size(0);
      for (i = 0; i < b_i; i++) {
        b_reflectivity[i].f1.set_size(r[i].f1.size(0), 2);
        vlen = r[i].f1.size(0) * r[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          b_reflectivity[i].f1[i1] = r[i].f1[i1];
        }
      }

      b_Simulation.set_size(r1.size(0));
      b_i = r1.size(0);
      for (i = 0; i < b_i; i++) {
        b_Simulation[i].f1.set_size(r1[i].f1.size(0), 2);
        vlen = r1[i].f1.size(0) * r1[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          b_Simulation[i].f1[i1] = r1[i].f1[i1];
        }
      }

      b_allLayers.set_size(r2.size(0));
      b_i = r2.size(0);
      for (i = 0; i < b_i; i++) {
        b_allLayers[i].f1.set_size(r2[i].f1.size(0), r2[i].f1.size(1));
        vlen = r2[i].f1.size(0) * r2[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          b_allLayers[i].f1[i1] = r2[i].f1[i1];
        }
      }

      reflectivity.set_size(b_reflectivity.size(0));
      b_i = b_reflectivity.size(0);
      for (i = 0; i < b_i; i++) {
        reflectivity[i].f1.set_size(b_reflectivity[i].f1.size(0), 2);
        vlen = b_reflectivity[i].f1.size(0) * b_reflectivity[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          reflectivity[i].f1[i1] = b_reflectivity[i].f1[i1];
        }
      }

      Simulation.set_size(b_Simulation.size(0));
      b_i = b_Simulation.size(0);
      for (i = 0; i < b_i; i++) {
        Simulation[i].f1.set_size(b_Simulation[i].f1.size(0), 2);
        vlen = b_Simulation[i].f1.size(0) * b_Simulation[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          Simulation[i].f1[i1] = b_Simulation[i].f1[i1];
        }
      }

      shifted_data.set_size(b_shifted_data.size(0));
      b_i = b_shifted_data.size(0);
      for (i = 0; i < b_i; i++) {
        shifted_data[i].f1.set_size(b_shifted_data[i].f1.size(0), 3);
        vlen = b_shifted_data[i].f1.size(0) * b_shifted_data[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          shifted_data[i].f1[i1] = b_shifted_data[i].f1[i1];
        }
      }

      layerSlds.set_size(b_layerSlds.size(0));
      b_i = b_layerSlds.size(0);
      for (i = 0; i < b_i; i++) {
        layerSlds[i].f1.set_size(b_layerSlds[i].f1.size(0), 3);
        vlen = b_layerSlds[i].f1.size(0) * b_layerSlds[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          layerSlds[i].f1[i1] = b_layerSlds[i].f1[i1];
        }
      }

      sldProfiles.set_size(b_sldProfiles.size(0));
      b_i = b_sldProfiles.size(0);
      for (i = 0; i < b_i; i++) {
        sldProfiles[i].f1.set_size(b_sldProfiles[i].f1.size(0), 2);
        vlen = b_sldProfiles[i].f1.size(0) * b_sldProfiles[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          sldProfiles[i].f1[i1] = b_sldProfiles[i].f1[i1];
        }
      }

      allLayers.set_size(b_allLayers.size(0));
      b_i = b_allLayers.size(0);
      for (i = 0; i < b_i; i++) {
        allLayers[i].f1.set_size(b_allLayers[i].f1.size(0), b_allLayers[i].
          f1.size(1));
        vlen = b_allLayers[i].f1.size(0) * b_allLayers[i].f1.size(1);
        for (i1 = 0; i1 < vlen; i1++) {
          allLayers[i].f1[i1] = b_allLayers[i].f1[i1];
        }
      }
    }
    break;
  }

  problem->calculations.all_chis.set_size(chis.size(0));
  vlen = chis.size(0);
  for (b_i = 0; b_i < vlen; b_i++) {
    problem->calculations.all_chis[b_i] = chis[b_i];
  }

  vlen = chis.size(0);
  if (chis.size(0) == 0) {
    y = 0.0;
  } else {
    y = chis[0];
    for (i = 2; i <= vlen; i++) {
      y += chis[i - 1];
    }
  }

  problem->calculations.sum_chi = y;

  // problem.calculations.reflectivity = reflectivity;
  // problem.calculations.Simulation = Simulation;
  // problem.shifted_data = shifted_data;
  // problem.layers = layerSlds;
  // problem.calculations.slds = sldProfiles;
  // problem.allLayers = allLayers;
  //  result = cell(1,6);
  //
  //
  //
  //  %result = {{};{};{};{};{};{};{}};
  //  result{1} = reflectivity;
  //  result{2} = Simulation;
  //  result{3} = shifted_data;
  //  result{4} = layerSlds;
  //  result{5} = sldProfiles;
  //  result{6} = allLayers;
  //
  //
  //  %Result coder definitions....
  //   coder.varsize('result{1}',[Inf 1],[1 0]);           %Reflectivity
  //   coder.varsize('result{1}{:}',[Inf 2],[1 0]);
  //  %
  //   coder.varsize('result{2}',[Inf 1],[1 0]);           %Simulatin
  //   coder.varsize('result{2}{:}',[Inf 2],[1 0]);
  //  %
  //   coder.varsize('result{3}',[Inf 1],[1 0]);           %Shifted data
  //   coder.varsize('result{3}{:}',[Inf 3],[1 0]);
  //  %
  //   coder.varsize('result{4}',[Inf 1],[1 0]);           %Layers slds
  //   coder.varsize('result{4}{:}',[Inf 3],[1 0]);
  //  %
  //   coder.varsize('result{5}',[Inf 1],[1 0]);           %Sld profiles
  //   coder.varsize('results{5}{:}',[Inf 2],[1 0]);
  //  %
  //   coder.varsize('result{6}',[Inf 1],[1 0]);           %All layers
  //   coder.varsize('result{6}{:}',[Inf 1],[1 0]);
}

//
// File trailer for standardTF_custLay_reflectivityCalculation.cpp
//
// [EOF]
//
