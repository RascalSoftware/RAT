//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reflectivityCalculation.cpp
//
// Code generation for function 'reflectivityCalculation'
//

// Include files
#include "reflectivityCalculation.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "reflectivityCalculation1.h"
#include "reflectivityCalculation2.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Type Definitions
namespace RAT
{
  struct cell_wrap_16
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_wrap_17
  {
    ::coder::array<real_T, 2U> f1;
  };
}

// Function Declarations
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_8, 1U> &b, ::coder::array<
                   cell_wrap_18, 1U> &c);
  static void cast(const ::coder::array<cell_wrap_8, 1U> &b, ::coder::array<
                   cell_wrap_16, 1U> &c);
  static void cast(const ::coder::array<cell_wrap_20, 1U> &b, ::coder::array<
                   cell_wrap_16, 1U> &c);
  static void cast(const ::coder::array<cell_wrap_8, 1U> &b, ::coder::array<
                   cell_wrap_17, 1U> &c);
  static void cast(const ::coder::array<cell_wrap_8, 2U> &b, ::coder::array<
                   cell_wrap_18, 2U> &c);
  static void cast(const ::coder::array<cell_wrap_8, 2U> &b, ::coder::array<
                   cell_wrap_33, 2U> &c);
  static void cast(const ::coder::array<cell_wrap_8, 2U> &b, ::coder::array<
                   cell_wrap_17, 2U> &c);
}

// Function Definitions
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_8, 1U> &b, ::coder::array<
                   cell_wrap_18, 1U> &c)
  {
    int32_T i;
    c.set_size(b.size(0));
    i = b.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.set_size(b[i1].f1.size(0), b[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = b[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1[i3 + c[i1].f1.size(0) * i2] = b[i1].f1[i3 + b[i1].f1.size(0) *
            i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_8, 1U> &b, ::coder::array<
                   cell_wrap_16, 1U> &c)
  {
    int32_T i;
    c.set_size(b.size(0));
    i = b.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.set_size(b[i1].f1.size(0), b[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = b[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1[i3 + c[i1].f1.size(0) * i2] = b[i1].f1[i3 + b[i1].f1.size(0) *
            i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_20, 1U> &b, ::coder::array<
                   cell_wrap_16, 1U> &c)
  {
    int32_T i;
    c.set_size(b.size(0));
    i = b.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size(0);
      c[i1].f1.set_size(b[i1].f1.size(0), 2);
      for (int32_T i2{0}; i2 < 2; i2++) {
        for (int32_T i3{0}; i3 < loop_ub; i3++) {
          c[i1].f1[i3 + c[i1].f1.size(0) * i2] = b[i1].f1[i3 + b[i1].f1.size(0) *
            i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_8, 1U> &b, ::coder::array<
                   cell_wrap_17, 1U> &c)
  {
    int32_T i;
    c.set_size(b.size(0));
    i = b.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.set_size(b[i1].f1.size(0), b[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = b[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1[i3 + c[i1].f1.size(0) * i2] = b[i1].f1[i3 + b[i1].f1.size(0) *
            i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_8, 2U> &b, ::coder::array<
                   cell_wrap_18, 2U> &c)
  {
    int32_T i;
    c.set_size(b.size(0), b.size(1));
    i = b.size(0) * b.size(1);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.set_size(b[i1].f1.size(0), b[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = b[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1[i3 + c[i1].f1.size(0) * i2] = b[i1].f1[i3 + b[i1].f1.size(0) *
            i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_8, 2U> &b, ::coder::array<
                   cell_wrap_33, 2U> &c)
  {
    int32_T i;
    c.set_size(b.size(0), b.size(1));
    i = b.size(0) * b.size(1);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.set_size(b[i1].f1.size(0), b[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = b[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1[i3 + c[i1].f1.size(0) * i2] = b[i1].f1[i3 + b[i1].f1.size(0) *
            i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_8, 2U> &b, ::coder::array<
                   cell_wrap_17, 2U> &c)
  {
    int32_T i;
    c.set_size(b.size(0), b.size(1));
    i = b.size(0) * b.size(1);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.set_size(b[i1].f1.size(0), b[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = b[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1[i3 + c[i1].f1.size(0) * i2] = b[i1].f1[i3 + b[i1].f1.size(0) *
            i2];
        }
      }
    }
  }

  void reflectivityCalculation(const d_struct_T *problemStruct, const cell_11
    *problemCells, const struct2_T *controls, e_struct_T *contrastParams,
    cell_wrap_9 resultCells[6])
  {
    ::coder::array<cell_wrap_16, 1U> reflectivity;
    ::coder::array<cell_wrap_16, 1U> simulation;
    ::coder::array<cell_wrap_16, 1U> sldProfiles;
    ::coder::array<cell_wrap_17, 2U> domainAllLayers;
    ::coder::array<cell_wrap_17, 2U> r2;
    ::coder::array<cell_wrap_17, 1U> allLayers;
    ::coder::array<cell_wrap_17, 1U> shiftedData;
    ::coder::array<cell_wrap_18, 2U> domainLayerSlds;
    ::coder::array<cell_wrap_18, 2U> r;
    ::coder::array<cell_wrap_18, 1U> layerSlds;
    ::coder::array<cell_wrap_20, 1U> b_reflectivity;
    ::coder::array<cell_wrap_20, 1U> b_simulation;
    ::coder::array<cell_wrap_33, 2U> domainSldProfiles;
    ::coder::array<cell_wrap_33, 2U> r1;
    ::coder::array<cell_wrap_8, 2U> b_domainAllLayers;
    ::coder::array<cell_wrap_8, 2U> b_domainLayerSlds;
    ::coder::array<cell_wrap_8, 2U> b_domainSldProfiles;
    ::coder::array<cell_wrap_8, 2U> cell1;
    ::coder::array<cell_wrap_8, 2U> cell2;
    ::coder::array<cell_wrap_8, 2U> cell3;
    ::coder::array<cell_wrap_8, 2U> cell4;
    ::coder::array<cell_wrap_8, 2U> cell5;
    ::coder::array<cell_wrap_8, 2U> cell6;
    ::coder::array<cell_wrap_8, 1U> b_allLayers;
    ::coder::array<cell_wrap_8, 1U> b_layerSlds;
    ::coder::array<cell_wrap_8, 1U> b_shiftedData;
    ::coder::array<cell_wrap_8, 1U> b_sldProfiles;
    int32_T b_i;
    int32_T b_index;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T loop_ub;

    //  Main entry point into the reflectivity calculation for the toolbox.
    //  This is the main function that is called by any of the minimisers or
    //  analysis tools from the rest of the toolbox.
    //
    //  *The main job of this function is to decide which type of calculation
    //  (i.e. 'Target function' is required, and call the relevant routines.
    //  The types of available target functions are:*
    //
    //  * non polarised  - The main basic target function type, for non polarised neutrons (or x-rays) with non-absorbing samples. Different model types are specified in sub functions from here.
    //
    //  * oil water      - Target function for oil-water samples
    //
    //  * domains        - Target function for samples consisting of domains which are larger than the beam lateral coherence length.
    //
    //  * magnetic       - Target function for cases for polarised neutrons with polarisation analysis.
    //
    //  for compilation, we have to preallocate memory for the output arrays
    //  Setting these parameters in the struct defines them as doubles
    contrastParams->ssubs.set_size(1);
    contrastParams->ssubs[0] = 0.0;
    contrastParams->backgroundParams.set_size(1);
    contrastParams->backgroundParams[0] = 0.0;
    contrastParams->qzshifts.set_size(1);
    contrastParams->qzshifts[0] = 0.0;
    contrastParams->scalefactors.set_size(1);
    contrastParams->scalefactors[0] = 0.0;
    contrastParams->bulkIn.set_size(1);
    contrastParams->bulkIn[0] = 0.0;
    contrastParams->bulkOut.set_size(1);
    contrastParams->bulkOut[0] = 0.0;
    contrastParams->resolutionParams.set_size(1);
    contrastParams->resolutionParams[0] = 0.0;
    contrastParams->calculations.allChis.set_size(1);
    contrastParams->calculations.allChis[0] = 0.0;
    contrastParams->calculations.sumChi = 0.0;
    contrastParams->allSubRough.set_size(1);
    contrastParams->allSubRough[0] = 0.0;
    contrastParams->resample.set_size(1, 1);
    contrastParams->resample[0] = 0.0;

    //  We also foll the results arrays to define their
    //  type and size. (NOTE: at the moment we have a 'coder.varsize'
    //  pre-processor directives for the compiler here and at the
    //  end for the results block. We are unlikely to need both
    //  TODO: Find out which is necessary and tidy this up.
    i = static_cast<int32_T>(problemStruct->numberOfContrasts);
    reflectivity.set_size(i);
    simulation.set_size(i);
    shiftedData.set_size(i);
    layerSlds.set_size(i);
    domainLayerSlds.set_size(i, 2);
    sldProfiles.set_size(i);
    domainSldProfiles.set_size(i, 2);
    allLayers.set_size(i);
    domainAllLayers.set_size(i, 2);
    for (b_i = 0; b_i < i; b_i++) {
      reflectivity[b_i].f1.set_size(2, 2);
      reflectivity[b_i].f1[0] = 1.0;
      reflectivity[b_i].f1[1] = 1.0;
      reflectivity[b_i].f1[reflectivity[b_i].f1.size(0)] = 1.0;
      reflectivity[b_i].f1[reflectivity[b_i].f1.size(0) + 1] = 1.0;
      simulation[b_i].f1.set_size(2, 2);
      simulation[b_i].f1[0] = 1.0;
      simulation[b_i].f1[1] = 1.0;
      simulation[b_i].f1[simulation[b_i].f1.size(0)] = 1.0;
      simulation[b_i].f1[simulation[b_i].f1.size(0) + 1] = 1.0;
      shiftedData[b_i].f1.set_size(2, 3);
      layerSlds[b_i].f1.set_size(2, 3);
      domainLayerSlds[b_i].f1.set_size(2, 3);
      domainLayerSlds[b_i + domainLayerSlds.size(0)].f1.set_size(2, 3);
      sldProfiles[b_i].f1.set_size(2, 2);
      sldProfiles[b_i].f1[0] = 1.0;
      sldProfiles[b_i].f1[1] = 1.0;
      sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0)] = 1.0;
      sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0) + 1] = 1.0;
      domainSldProfiles[b_i].f1.set_size(2, 2);
      domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.set_size(2, 2);
      domainSldProfiles[b_i].f1[0] = 1.0;
      domainSldProfiles[b_i + domainSldProfiles.size(0)].f1[0] = 1.0;
      domainSldProfiles[b_i].f1[1] = 1.0;
      domainSldProfiles[b_i + domainSldProfiles.size(0)].f1[1] = 1.0;
      domainSldProfiles[b_i].f1[domainSldProfiles[b_i].f1.size(0)] = 1.0;
      domainSldProfiles[b_i + domainSldProfiles.size(0)]
        .f1[domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.size(0)] = 1.0;
      domainSldProfiles[b_i].f1[domainSldProfiles[b_i].f1.size(0) + 1] = 1.0;
      domainSldProfiles[b_i + domainSldProfiles.size(0)]
        .f1[domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.size(0) + 1] =
        1.0;
      allLayers[b_i].f1.set_size(2, 3);
      domainAllLayers[b_i].f1.set_size(2, 3);
      domainAllLayers[b_i + domainAllLayers.size(0)].f1.set_size(2, 3);
      for (i1 = 0; i1 < 3; i1++) {
        shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * i1] = 1.0;
        shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * i1 + 1] = 1.0;
        layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i1] = 1.0;
        layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i1 + 1] = 1.0;
        domainLayerSlds[b_i].f1[domainLayerSlds[b_i].f1.size(0) * i1] = 1.0;
        domainLayerSlds[b_i + domainLayerSlds.size(0)].f1[domainLayerSlds[b_i +
          domainLayerSlds.size(0)].f1.size(0) * i1] = 1.0;
        domainLayerSlds[b_i].f1[domainLayerSlds[b_i].f1.size(0) * i1 + 1] = 1.0;
        domainLayerSlds[b_i + domainLayerSlds.size(0)].f1[domainLayerSlds[b_i +
          domainLayerSlds.size(0)].f1.size(0) * i1 + 1] = 1.0;
        allLayers[b_i].f1[allLayers[b_i].f1.size(0) * i1] = 1.0;
        allLayers[b_i].f1[allLayers[b_i].f1.size(0) * i1 + 1] = 1.0;
        domainAllLayers[b_i].f1[domainAllLayers[b_i].f1.size(0) * i1] = 1.0;
        domainAllLayers[b_i + domainAllLayers.size(0)].f1[domainAllLayers[b_i +
          domainAllLayers.size(0)].f1.size(0) * i1] = 1.0;
        domainAllLayers[b_i].f1[domainAllLayers[b_i].f1.size(0) * i1 + 1] = 1.0;
        domainAllLayers[b_i + domainAllLayers.size(0)].f1[domainAllLayers[b_i +
          domainAllLayers.size(0)].f1.size(0) * i1 + 1] = 1.0;
      }
    }

    //  Decide which target function we are calling and call the relevant routines
    if (coder::internal::h_strcmp(problemStruct->TF.data, problemStruct->TF.size))
    {
      b_index = 0;
    } else if (coder::internal::i_strcmp(problemStruct->TF.data,
                problemStruct->TF.size)) {
      b_index = 1;
    } else {
      b_index = -1;
    }

    switch (b_index) {
     case 0:
      nonPolarisedTF::b_reflectivityCalculation(problemStruct, problemCells,
        controls, contrastParams, b_reflectivity, b_simulation, b_shiftedData,
        b_layerSlds, b_sldProfiles, b_allLayers);
      cast(b_reflectivity, reflectivity);
      cast(b_simulation, simulation);
      cast(b_shiftedData, shiftedData);
      cast(b_layerSlds, layerSlds);
      cast(b_sldProfiles, sldProfiles);
      cast(b_allLayers, allLayers);

      // case 'oil water'
      // contrastParams = oilWaterTFReflectivityCalculation(problemStruct,problemCells,controls);
      // case 'magnetic'
      // contrastParams = polarisedTFReflectivityCalculation(problemStruct,problemCells,controls);
      break;

     case 1:
      domainsTF::b_reflectivityCalculation(problemStruct, problemCells, controls,
        contrastParams, b_reflectivity, b_simulation, b_shiftedData,
        b_domainLayerSlds, b_domainSldProfiles, b_domainAllLayers);
      cast(b_reflectivity, reflectivity);
      cast(b_simulation, simulation);
      cast(b_shiftedData, shiftedData);
      cast(b_domainLayerSlds, r);
      domainLayerSlds.set_size(r.size(0), r.size(1));
      b_index = r.size(1);
      for (i1 = 0; i1 < b_index; i1++) {
        loop_ub = r.size(0);
        for (i2 = 0; i2 < loop_ub; i2++) {
          domainLayerSlds[i2 + domainLayerSlds.size(0) * i1] = r[i2 + r.size(0) *
            i1];
        }
      }

      cast(b_domainSldProfiles, r1);
      domainSldProfiles.set_size(r1.size(0), r1.size(1));
      b_index = r1.size(1);
      for (i1 = 0; i1 < b_index; i1++) {
        loop_ub = r1.size(0);
        for (i2 = 0; i2 < loop_ub; i2++) {
          domainSldProfiles[i2 + domainSldProfiles.size(0) * i1] = r1[i2 +
            r1.size(0) * i1];
        }
      }

      cast(b_domainAllLayers, r2);
      domainAllLayers.set_size(r2.size(0), r2.size(1));
      b_index = r2.size(1);
      for (i1 = 0; i1 < b_index; i1++) {
        loop_ub = r2.size(0);
        for (i2 = 0; i2 < loop_ub; i2++) {
          domainAllLayers[i2 + domainAllLayers.size(0) * i1] = r2[i2 + r2.size(0)
            * i1];
        }
      }

      //      otherwise
      //          error('The calculation type "%s" is not supported', whichTF);
      break;
    }

    cell1.set_size(i, 1);
    for (b_i = 0; b_i < i; b_i++) {
      b_index = reflectivity[b_i].f1.size(0);
      cell1[b_i].f1.set_size(reflectivity[b_i].f1.size(0), 2);
      for (i1 = 0; i1 < 2; i1++) {
        for (i2 = 0; i2 < b_index; i2++) {
          cell1[b_i].f1[i2 + cell1[b_i].f1.size(0) * i1] = reflectivity[b_i]
            .f1[i2 + reflectivity[b_i].f1.size(0) * i1];
        }
      }
    }

    resultCells[0].f1.set_size(cell1.size(0), 1);
    b_index = cell1.size(0);
    for (i1 = 0; i1 < b_index; i1++) {
      resultCells[0].f1[i1] = cell1[i1];
    }

    cell2.set_size(i, 1);
    for (b_i = 0; b_i < i; b_i++) {
      b_index = simulation[b_i].f1.size(0);
      cell2[b_i].f1.set_size(simulation[b_i].f1.size(0), 2);
      for (i1 = 0; i1 < 2; i1++) {
        for (i2 = 0; i2 < b_index; i2++) {
          cell2[b_i].f1[i2 + cell2[b_i].f1.size(0) * i1] = simulation[b_i].f1[i2
            + simulation[b_i].f1.size(0) * i1];
        }
      }
    }

    resultCells[1].f1.set_size(cell2.size(0), 1);
    b_index = cell2.size(0);
    for (i1 = 0; i1 < b_index; i1++) {
      resultCells[1].f1[i1] = cell2[i1];
    }

    cell3.set_size(i, 1);
    for (b_i = 0; b_i < i; b_i++) {
      b_index = shiftedData[b_i].f1.size(0);
      cell3[b_i].f1.set_size(shiftedData[b_i].f1.size(0), 3);
      for (i1 = 0; i1 < 3; i1++) {
        for (i2 = 0; i2 < b_index; i2++) {
          cell3[b_i].f1[i2 + cell3[b_i].f1.size(0) * i1] = shiftedData[b_i]
            .f1[i2 + shiftedData[b_i].f1.size(0) * i1];
        }
      }
    }

    resultCells[2].f1.set_size(cell3.size(0), 1);
    b_index = cell3.size(0);
    for (i1 = 0; i1 < b_index; i1++) {
      resultCells[2].f1[i1] = cell3[i1];
    }

    //  The size of this array now varies depending on TF
    if (coder::internal::i_strcmp(problemStruct->TF.data, problemStruct->TF.size))
    {
      i1 = 0;
    } else {
      i1 = -1;
    }

    switch (i1) {
     case 0:
      cell4.set_size(i, 2);
      for (b_i = 0; b_i < i; b_i++) {
        b_index = domainLayerSlds[b_i].f1.size(1);
        cell4[b_i].f1.set_size(domainLayerSlds[b_i].f1.size(0),
          domainLayerSlds[b_i].f1.size(1));
        for (i1 = 0; i1 < b_index; i1++) {
          loop_ub = domainLayerSlds[b_i].f1.size(0);
          for (i2 = 0; i2 < loop_ub; i2++) {
            cell4[b_i].f1[i2 + cell4[b_i].f1.size(0) * i1] = domainLayerSlds[b_i]
              .f1[i2 + domainLayerSlds[b_i].f1.size(0) * i1];
          }
        }

        b_index = domainLayerSlds[b_i + domainLayerSlds.size(0)].f1.size(1);
        cell4[b_i + cell4.size(0)].f1.set_size(domainLayerSlds[b_i +
          domainLayerSlds.size(0)].f1.size(0), domainLayerSlds[b_i +
          domainLayerSlds.size(0)].f1.size(1));
        for (i1 = 0; i1 < b_index; i1++) {
          loop_ub = domainLayerSlds[b_i + domainLayerSlds.size(0)].f1.size(0);
          for (i2 = 0; i2 < loop_ub; i2++) {
            cell4[b_i + cell4.size(0)].f1[i2 + cell4[b_i + cell4.size(0)].
              f1.size(0) * i1] = domainLayerSlds[b_i + domainLayerSlds.size(0)].
              f1[i2 + domainLayerSlds[b_i + domainLayerSlds.size(0)].f1.size(0) *
              i1];
          }
        }
      }

      resultCells[3].f1.set_size(cell4.size(0), 2);
      b_index = cell4.size(0);
      for (i1 = 0; i1 < 2; i1++) {
        for (i2 = 0; i2 < b_index; i2++) {
          resultCells[3].f1[i2 + resultCells[3].f1.size(0) * i1] = cell4[i2 +
            cell4.size(0) * i1];
        }
      }

      cell5.set_size(i, 2);
      for (b_i = 0; b_i < i; b_i++) {
        b_index = domainSldProfiles[b_i].f1.size(1);
        cell5[b_i].f1.set_size(domainSldProfiles[b_i].f1.size(0),
          domainSldProfiles[b_i].f1.size(1));
        for (i1 = 0; i1 < b_index; i1++) {
          loop_ub = domainSldProfiles[b_i].f1.size(0);
          for (i2 = 0; i2 < loop_ub; i2++) {
            cell5[b_i].f1[i2 + cell5[b_i].f1.size(0) * i1] =
              domainSldProfiles[b_i].f1[i2 + domainSldProfiles[b_i].f1.size(0) *
              i1];
          }
        }

        b_index = domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.size(1);
        cell5[b_i + cell5.size(0)].f1.set_size(domainSldProfiles[b_i +
          domainSldProfiles.size(0)].f1.size(0), domainSldProfiles[b_i +
          domainSldProfiles.size(0)].f1.size(1));
        for (i1 = 0; i1 < b_index; i1++) {
          loop_ub = domainSldProfiles[b_i + domainSldProfiles.size(0)].f1.size(0);
          for (i2 = 0; i2 < loop_ub; i2++) {
            cell5[b_i + cell5.size(0)].f1[i2 + cell5[b_i + cell5.size(0)].
              f1.size(0) * i1] = domainSldProfiles[b_i + domainSldProfiles.size
              (0)].f1[i2 + domainSldProfiles[b_i + domainSldProfiles.size(0)].
              f1.size(0) * i1];
          }
        }
      }

      resultCells[4].f1.set_size(cell5.size(0), 2);
      b_index = cell5.size(0);
      for (i1 = 0; i1 < 2; i1++) {
        for (i2 = 0; i2 < b_index; i2++) {
          resultCells[4].f1[i2 + resultCells[4].f1.size(0) * i1] = cell5[i2 +
            cell5.size(0) * i1];
        }
      }

      cell6.set_size(i, 2);
      for (b_i = 0; b_i < i; b_i++) {
        b_index = domainAllLayers[b_i].f1.size(0);
        cell6[b_i].f1.set_size(domainAllLayers[b_i].f1.size(0), 3);
        loop_ub = domainAllLayers[b_i + domainAllLayers.size(0)].f1.size(0);
        cell6[b_i + cell6.size(0)].f1.set_size(domainAllLayers[b_i +
          domainAllLayers.size(0)].f1.size(0), 3);
        for (i1 = 0; i1 < 3; i1++) {
          for (i2 = 0; i2 < b_index; i2++) {
            cell6[b_i].f1[i2 + cell6[b_i].f1.size(0) * i1] = domainAllLayers[b_i]
              .f1[i2 + domainAllLayers[b_i].f1.size(0) * i1];
          }

          for (i2 = 0; i2 < loop_ub; i2++) {
            cell6[b_i + cell6.size(0)].f1[i2 + cell6[b_i + cell6.size(0)].
              f1.size(0) * i1] = domainAllLayers[b_i + domainAllLayers.size(0)].
              f1[i2 + domainAllLayers[b_i + domainAllLayers.size(0)].f1.size(0) *
              i1];
          }
        }
      }

      resultCells[5].f1.set_size(cell6.size(0), 2);
      b_index = cell6.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < b_index; i1++) {
          resultCells[5].f1[i1 + resultCells[5].f1.size(0) * i] = cell6[i1 +
            cell6.size(0) * i];
        }
      }
      break;

     default:
      cell4.set_size(i, 1);
      for (b_i = 0; b_i < i; b_i++) {
        b_index = layerSlds[b_i].f1.size(1);
        cell4[b_i].f1.set_size(layerSlds[b_i].f1.size(0), layerSlds[b_i].f1.size
          (1));
        for (i1 = 0; i1 < b_index; i1++) {
          loop_ub = layerSlds[b_i].f1.size(0);
          for (i2 = 0; i2 < loop_ub; i2++) {
            cell4[b_i].f1[i2 + cell4[b_i].f1.size(0) * i1] = layerSlds[b_i]
              .f1[i2 + layerSlds[b_i].f1.size(0) * i1];
          }
        }
      }

      resultCells[3].f1.set_size(cell4.size(0), 1);
      b_index = cell4.size(0);
      for (i1 = 0; i1 < b_index; i1++) {
        resultCells[3].f1[i1] = cell4[i1];
      }

      cell5.set_size(i, 1);
      for (b_i = 0; b_i < i; b_i++) {
        b_index = sldProfiles[b_i].f1.size(0);
        cell5[b_i].f1.set_size(sldProfiles[b_i].f1.size(0), 2);
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 < b_index; i2++) {
            cell5[b_i].f1[i2 + cell5[b_i].f1.size(0) * i1] = sldProfiles[b_i]
              .f1[i2 + sldProfiles[b_i].f1.size(0) * i1];
          }
        }
      }

      resultCells[4].f1.set_size(cell5.size(0), 1);
      b_index = cell5.size(0);
      for (i1 = 0; i1 < b_index; i1++) {
        resultCells[4].f1[i1] = cell5[i1];
      }

      cell6.set_size(i, 1);
      for (b_i = 0; b_i < i; b_i++) {
        b_index = allLayers[b_i].f1.size(0);
        cell6[b_i].f1.set_size(allLayers[b_i].f1.size(0), 3);
        for (i1 = 0; i1 < 3; i1++) {
          for (i2 = 0; i2 < b_index; i2++) {
            cell6[b_i].f1[i2 + cell6[b_i].f1.size(0) * i1] = allLayers[b_i]
              .f1[i2 + allLayers[b_i].f1.size(0) * i1];
          }
        }
      }

      resultCells[5].f1.set_size(cell6.size(0), 1);
      b_index = cell6.size(0);
      for (i = 0; i < b_index; i++) {
        resultCells[5].f1[i] = cell6[i];
      }
      break;
    }

    //  Pre-processor directives for Matlab Coder
    //  to define the size of the output array
    // Result coder definitions....
    // Reflectivity
    // simulation
    // Shifted data
    //  coder.varsize('result{4}',[Inf 2],[1 1]);           %Layers slds
    //  coder.varsize('result{4}{:}',[Inf 6],[1 1]);
    //  coder.varsize('result{5}',[Inf 2],[1 1]);           %Sld profiles
    //  coder.varsize('results{5}{:}',[Inf 2],[1 2]);
    //  coder.varsize('result{6}',[Inf 2],[1 1]);           %All layers (resampled)
    //  coder.varsize('result{6}{:}',[Inf 3],[1 0]);
  }
}

// End of code generation (reflectivityCalculation.cpp)
