//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: standardTF_custlay_paraContrasts.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "standardTF_custlay_paraContrasts.h"
#include "backSort.h"
#include "loopCppCustlayWrapper_CustLaysingle.h"
#include "loopMatalbCustlayWrapper_CustLaysingle.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_rtwutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "omp.h"

// Function Declarations
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_14, 1U> &r, ::coder::array<
                   cell_wrap_1, 1U> &r1);
}

// Function Definitions
//
// Arguments    : const ::coder::array<cell_wrap_14, 1U> &r
//                ::coder::array<cell_wrap_1, 1U> &r1
// Return Type  : void
//
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_14, 1U> &r, ::coder::array<
                   cell_wrap_1, 1U> &r1)
  {
    int32_T i;
    r1.set_size(r.size(0));
    i = r.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      r1[i1].f1.size[0] = r[i1].f1.size(0);
      loop_ub = r[i1].f1.size(1);
      r1[i1].f1.size[1] = r[i1].f1.size(1);
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = r[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          r1[i1].f1.data[i3 + r1[i1].f1.size[0] * i2] = r[i1].f1[i3 + r[i1].
            f1.size(0) * i2];
        }
      }
    }
  }

  //
  // Multi threaded version of the custom layers over reflectivity contrasts for standardTF reflectivity calculation.
  //  The function extracts the relevant parameters from the input
  //  arrays, allocates these on a pre-contrast basis, then calls the 'core'
  //  calculation (the core layers standardTf calc is shared between multiple
  //  calculation types).
  //  This differs from the other two paralellisations in that the custom model
  //  files are processed in a paralell loop (using the Matlab Paralell
  //  Computing Toolbox) outside the main loop, before the main loop is then processed
  //  in the compiled version using OpenMP.
  //
  // Arguments    : const struct0_T *problemDef
  //                const cell_18 *problemDef_cells
  //                const struct2_T *controls
  //                ::coder::array<real_T, 1U> &outSsubs
  //                ::coder::array<real_T, 1U> &backgs
  //                ::coder::array<real_T, 1U> &qshifts
  //                ::coder::array<real_T, 1U> &sfs
  //                ::coder::array<real_T, 1U> &nbas
  //                ::coder::array<real_T, 1U> &nbss
  //                ::coder::array<real_T, 1U> &resols
  //                ::coder::array<real_T, 1U> &chis
  //                ::coder::array<cell_wrap_9, 1U> &reflectivity
  //                ::coder::array<cell_wrap_9, 1U> &Simulation
  //                ::coder::array<cell_wrap_14, 1U> &shifted_data
  //                ::coder::array<cell_wrap_10, 1U> &layerSlds
  //                ::coder::array<cell_wrap_14, 1U> &sldProfiles
  //                ::coder::array<cell_wrap_1, 1U> &allLayers
  //                ::coder::array<real_T, 1U> &allRoughs
  // Return Type  : void
  //
  void standardTF_custlay_paraContrasts(const struct0_T *problemDef, const
    cell_18 *problemDef_cells, const struct2_T *controls, ::coder::array<real_T,
    1U> &outSsubs, ::coder::array<real_T, 1U> &backgs, ::coder::array<real_T, 1U>
    &qshifts, ::coder::array<real_T, 1U> &sfs, ::coder::array<real_T, 1U> &nbas,
    ::coder::array<real_T, 1U> &nbss, ::coder::array<real_T, 1U> &resols, ::
    coder::array<real_T, 1U> &chis, ::coder::array<cell_wrap_9, 1U>
    &reflectivity, ::coder::array<cell_wrap_9, 1U> &Simulation, ::coder::array<
    cell_wrap_14, 1U> &shifted_data, ::coder::array<cell_wrap_10, 1U> &layerSlds,
    ::coder::array<cell_wrap_14, 1U> &sldProfiles, ::coder::array<cell_wrap_1,
    1U> &allLayers, ::coder::array<real_T, 1U> &allRoughs)
  {
    ::coder::array<cell_wrap_1, 1U> r;
    ::coder::array<cell_wrap_14, 1U> b_allLayers;
    ::coder::array<real_T, 2U> Simul;
    ::coder::array<real_T, 2U> c_allLayers;
    ::coder::array<real_T, 2U> reflect;
    ::coder::array<real_T, 2U> resamLayers;
    ::coder::array<real_T, 2U> sldProfile;
    real_T shifted_dat_data[5000];
    real_T calcSld;
    real_T thisBackground;
    real_T thisChiSquared;
    real_T thisNba;
    real_T thisNbs;
    real_T thisQshift;
    real_T thisResol;
    real_T thisSf;
    real_T thisSsubs;
    int32_T iv[2];
    int32_T shifted_dat_size[2];
    int32_T b_index;
    int32_T b_loop_ub;
    int32_T c_i;
    int32_T c_loop_ub;
    int32_T i1;
    int32_T loop_ub;
    int32_T loop_ub_tmp;
    int32_T nParams;

    //  Extract individual cell arrays
    //  Splits up the master input list of all arrays into separate arrays
    //  The min input array 'problemDef_cells' is a master array where
    //  all the cell arrays are grouped together. There are
    //  repeatLayers      - controls repeating of the layers stack
    //  allData           - Array of all the data arrays
    //  dataLimits        - Min max limits in q for the data arrays
    //  simLimits         - Limits in Q for the reflkectivity simulations
    //  Layers details    - Master array of all available layers
    //  contrastLayers    - Which specific combination of arrays are needed for
    //                      each contrast.
    //  Custom files      - Filenames and path for any custom files used
    //  Extract individual parameters from problemDef struct
    // Extract individual parameters from problemDef
    nParams = problemDef->params.size[1];
    calcSld = controls->calcSld;

    //  Pre-Allocation of output arrays...
    loop_ub_tmp = static_cast<int32_T>(problemDef->numberOfContrasts);
    backgs.set_size(loop_ub_tmp);
    allRoughs.set_size(loop_ub_tmp);
    allLayers.set_size(loop_ub_tmp);
    for (int32_T i{0}; i < loop_ub_tmp; i++) {
      allRoughs[i] = 0.0;
      allLayers[i].f1.size[0] = 2;
      allLayers[i].f1.size[1] = 1;
      allLayers[i].f1.data[0] = 1.0;
      allLayers[i].f1.data[1] = 1.0;
    }

    //    --- End Memory Allocation ---
    //  Depending on custom layer language we change the functions used
    //  so if there are multiple language models we should have a variable that seeks what language model is being used
    if (coder::internal::j_strcmp(problemDef_cells->f14[0].f1[1].f1.data,
         problemDef_cells->f14[0].f1[1].f1.size)) {
      b_index = 0;
    } else if (coder::internal::k_strcmp(problemDef_cells->f14[0].f1[1].f1.data,
                problemDef_cells->f14[0].f1[1].f1.size)) {
      b_index = 1;
    } else {
      b_index = -1;
    }

    switch (b_index) {
     case 0:
      //  Call the Matlab parallel loop to process the custom models.....
      loopMatalbCustlayWrapper_CustLaysingle(problemDef->numberOfContrasts,
        b_allLayers, allRoughs);
      cast(b_allLayers, allLayers);
      break;

     case 1:
      loopCppCustlayWrapper_CustLaysingle(problemDef->numberOfContrasts, r,
        allRoughs);
      cast(r, b_allLayers);
      cast(b_allLayers, allLayers);
      break;
    }

    //  Multi cored over all contrasts
    outSsubs.set_size(loop_ub_tmp);
    sldProfiles.set_size(loop_ub_tmp);
    reflectivity.set_size(loop_ub_tmp);
    Simulation.set_size(loop_ub_tmp);
    shifted_data.set_size(loop_ub_tmp);
    layerSlds.set_size(loop_ub_tmp);
    chis.set_size(loop_ub_tmp);
    qshifts.set_size(loop_ub_tmp);
    sfs.set_size(loop_ub_tmp);
    nbas.set_size(loop_ub_tmp);
    nbss.set_size(loop_ub_tmp);
    resols.set_size(loop_ub_tmp);
    b_index = loop_ub_tmp - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(sldProfile,reflect,Simul,resamLayers,thisSsubs,thisChiSquared,shifted_dat_data,shifted_dat_size,thisResol,thisNbs,thisNba,thisSf,thisQshift,thisBackground,iv,loop_ub,b_loop_ub,c_loop_ub,c_i,i1) \
 firstprivate(c_allLayers)

    for (int32_T b_i = 0; b_i <= b_index; b_i++) {
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(problemDef->contrastBacks.data[b_i],
               problemDef->contrastShifts.data[b_i],
               problemDef->contrastScales.data[b_i],
               problemDef->contrastNbas.data[b_i], problemDef->
               contrastNbss.data[b_i], problemDef->contrastRes.data[b_i],
               problemDef->backs.data, problemDef->shifts.data,
               problemDef->sf.data, problemDef->nba.data, problemDef->nbs.data,
               problemDef->res.data, &thisBackground, &thisQshift, &thisSf,
               &thisNba, &thisNbs, &thisResol);

      //  Get the custom layers output for this contrast
      //  For the other parameters, we extract the correct ones from the input
      //  arrays
      //  Now call the core standardTF_stanlay reflectivity calculation
      //  In this case we are single cored, so we do not parallelise over
      //  points
      //  Call the reflectivity calculation
      c_allLayers.set(&allLayers[b_i].f1.data[0], allLayers[b_i].f1.size[0],
                      allLayers[b_i].f1.size[1]);
      iv[0] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                &problemDef_cells->f2.data[b_i].f1)->size())[0];
      iv[1] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                &problemDef_cells->f2.data[b_i].f1)->size())[1];
      standardTF_layers_core(c_allLayers, allRoughs[b_i],
        problemDef->geometry.data, problemDef->geometry.size, thisNba, thisNbs,
        problemDef->resample.data[b_i], calcSld, thisSf, thisQshift,
        problemDef->dataPresent.data[b_i], (const real_T *)((::coder::array<
        real_T, 2U> *)&problemDef_cells->f2.data[b_i].f1)->data(), iv,
        problemDef_cells->f3.data[b_i].f1, (const real_T *)((::coder::array<
        real_T, 2U> *)&problemDef_cells->f4.data[b_i].f1)->data(),
        problemDef_cells->f1.data[b_i].f1, thisBackground, thisResol,
        problemDef->contrastBacksType.data[b_i], static_cast<real_T>(nParams),
        controls->resamPars, sldProfile, reflect, Simul, shifted_dat_data,
        shifted_dat_size, layerSlds[b_i].f1, resamLayers, &thisChiSquared,
        &thisSsubs);

      //  Store returned values for this contrast in the output arrays.
      //  As well as the calculated profiles, we also store a record of
      //  the other values (background, scalefactors etc) for each contrast
      //  for future use.
      outSsubs[b_i] = thisSsubs;
      loop_ub = sldProfile.size(0);
      sldProfiles[b_i].f1.set_size(sldProfile.size(0), 2);
      b_loop_ub = reflect.size(0);
      reflectivity[b_i].f1.set_size(reflect.size(0), 2);
      c_loop_ub = Simul.size(0);
      Simulation[b_i].f1.set_size(Simul.size(0), 2);
      for (c_i = 0; c_i < 2; c_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          sldProfiles[b_i].f1[i1 + sldProfiles[b_i].f1.size(0) * c_i] =
            sldProfile[i1 + sldProfile.size(0) * c_i];
        }

        for (i1 = 0; i1 < b_loop_ub; i1++) {
          reflectivity[b_i].f1[i1 + reflectivity[b_i].f1.size(0) * c_i] =
            reflect[i1 + reflect.size(0) * c_i];
        }

        for (i1 = 0; i1 < c_loop_ub; i1++) {
          Simulation[b_i].f1[i1 + Simulation[b_i].f1.size(0) * c_i] = Simul[i1 +
            Simul.size(0) * c_i];
        }
      }

      loop_ub = shifted_dat_size[1];
      shifted_data[b_i].f1.set_size(shifted_dat_size[0], shifted_dat_size[1]);
      for (c_i = 0; c_i < loop_ub; c_i++) {
        b_loop_ub = shifted_dat_size[0];
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          shifted_data[b_i].f1[i1 + shifted_data[b_i].f1.size(0) * c_i] =
            shifted_dat_data[i1 + shifted_dat_size[0] * c_i];
        }
      }

      loop_ub = resamLayers.size(0);
      allLayers[b_i].f1.size[0] = resamLayers.size(0);
      allLayers[b_i].f1.size[1] = 3;
      for (c_i = 0; c_i < 3; c_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          allLayers[b_i].f1.data[i1 + allLayers[b_i].f1.size[0] * c_i] =
            resamLayers[i1 + resamLayers.size(0) * c_i];
        }
      }

      chis[b_i] = thisChiSquared;
      backgs[b_i] = thisBackground;
      qshifts[b_i] = thisQshift;
      sfs[b_i] = thisSf;
      nbas[b_i] = thisNba;
      nbss[b_i] = thisNbs;
      resols[b_i] = thisResol;
    }
  }
}

//
// File trailer for standardTF_custlay_paraContrasts.cpp
//
// [EOF]
//
