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
#include "packParams.h"
#include "reflectivityCalculation1.h"
#include "reflectivityCalculation2.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Type Definitions
namespace RAT
{
  struct cell_wrap_38
  {
    ::coder::array<real_T, 2U> f1;
  };
}

// Function Declarations
namespace RAT
{
  static void b_cast(const ::coder::array<cell_wrap_40, 2U> &b, ::coder::array<
                     cell_wrap_10, 2U> &c);
  static void b_cast(const ::coder::array<cell_wrap_52, 2U> &b, ::coder::array<
                     cell_wrap_10, 2U> &c);
  static void cast(const ::coder::array<cell_wrap_10, 1U> &b, ::coder::array<
                   cell_wrap_40, 1U> &c);
  static void cast(const ::coder::array<cell_wrap_10, 1U> &b, ::coder::array<
                   cell_wrap_38, 1U> &c);
  static void cast(const ::coder::array<cell_wrap_8, 1U> &b, ::coder::array<
                   cell_wrap_38, 1U> &c);
  static void cast(const ::coder::array<cell_wrap_10, 1U> &b, ::coder::array<
                   cell_wrap_39, 1U> &c);
  static void cast(const ::coder::array<cell_wrap_10, 2U> &b, ::coder::array<
                   cell_wrap_40, 2U> &c);
  static void cast(const ::coder::array<cell_wrap_10, 2U> &b, ::coder::array<
                   cell_wrap_52, 2U> &c);
  static void cast(const ::coder::array<cell_wrap_10, 2U> &b, ::coder::array<
                   cell_wrap_39, 2U> &c);
  static void cast(const ::coder::array<cell_wrap_38, 1U> &b, ::coder::array<
                   cell_wrap_8, 1U> &c);
}

// Function Definitions
namespace RAT
{
  static void b_cast(const ::coder::array<cell_wrap_40, 2U> &b, ::coder::array<
                     cell_wrap_10, 2U> &c)
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

  static void b_cast(const ::coder::array<cell_wrap_52, 2U> &b, ::coder::array<
                     cell_wrap_10, 2U> &c)
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

  static void cast(const ::coder::array<cell_wrap_10, 1U> &b, ::coder::array<
                   cell_wrap_40, 1U> &c)
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

  static void cast(const ::coder::array<cell_wrap_10, 1U> &b, ::coder::array<
                   cell_wrap_38, 1U> &c)
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
                   cell_wrap_38, 1U> &c)
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

  static void cast(const ::coder::array<cell_wrap_10, 1U> &b, ::coder::array<
                   cell_wrap_39, 1U> &c)
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

  static void cast(const ::coder::array<cell_wrap_10, 2U> &b, ::coder::array<
                   cell_wrap_40, 2U> &c)
  {
    int32_T i;
    c.set_size(b.size(0), 2);
    i = b.size(0) << 1;
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

  static void cast(const ::coder::array<cell_wrap_10, 2U> &b, ::coder::array<
                   cell_wrap_52, 2U> &c)
  {
    int32_T i;
    c.set_size(b.size(0), 2);
    i = b.size(0) << 1;
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

  static void cast(const ::coder::array<cell_wrap_10, 2U> &b, ::coder::array<
                   cell_wrap_39, 2U> &c)
  {
    int32_T i;
    c.set_size(b.size(0), 2);
    i = b.size(0) << 1;
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

  static void cast(const ::coder::array<cell_wrap_38, 1U> &b, ::coder::array<
                   cell_wrap_8, 1U> &c)
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

  void reflectivityCalculation(const f_struct_T *problemStruct, const cell_11
    *problemCells, const struct1_T *problemLimits, const struct2_T *controls,
    struct5_T *result)
  {
    ::coder::array<cell_wrap_10, 2U> b_domainLayerSlds;
    ::coder::array<cell_wrap_10, 2U> b_domainResampledLayers;
    ::coder::array<cell_wrap_10, 2U> b_domainSldProfiles;
    ::coder::array<cell_wrap_10, 2U> r;
    ::coder::array<cell_wrap_10, 1U> b_layerSlds;
    ::coder::array<cell_wrap_10, 1U> b_resampledLayers;
    ::coder::array<cell_wrap_10, 1U> b_sldProfiles;
    ::coder::array<cell_wrap_10, 1U> shiftedData;
    ::coder::array<cell_wrap_38, 1U> reflectivity;
    ::coder::array<cell_wrap_38, 1U> simulation;
    ::coder::array<cell_wrap_38, 1U> sldProfiles;
    ::coder::array<cell_wrap_39, 2U> domainResampledLayers;
    ::coder::array<cell_wrap_39, 2U> r3;
    ::coder::array<cell_wrap_39, 1U> resampledLayers;
    ::coder::array<cell_wrap_40, 2U> domainLayerSlds;
    ::coder::array<cell_wrap_40, 2U> r1;
    ::coder::array<cell_wrap_40, 1U> layerSlds;
    ::coder::array<cell_wrap_52, 2U> domainSldProfiles;
    ::coder::array<cell_wrap_52, 2U> r2;
    ::coder::array<cell_wrap_8, 1U> b_reflectivity;
    ::coder::array<cell_wrap_8, 1U> b_simulation;
    c_struct_T b_contrastParams;
    c_struct_T contrastParams;
    f_struct_T a__1;
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    int32_T loop_ub_tmp;

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
    //  For compilation, we have to preallocate memory for the output structs
    loop_ub_tmp = static_cast<int32_T>(problemStruct->numberOfContrasts);
    contrastParams.backgroundParams.set_size(loop_ub_tmp);
    contrastParams.scalefactors.set_size(loop_ub_tmp);
    contrastParams.bulkIn.set_size(loop_ub_tmp);
    contrastParams.bulkOut.set_size(loop_ub_tmp);
    contrastParams.resolutionParams.set_size(loop_ub_tmp);
    contrastParams.subRoughs.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      contrastParams.backgroundParams[i] = 0.0;
      contrastParams.scalefactors[i] = 0.0;
      contrastParams.bulkIn[i] = 0.0;
      contrastParams.bulkOut[i] = 0.0;
      contrastParams.resolutionParams[i] = 0.0;
      contrastParams.subRoughs[i] = 0.0;
    }

    result->contrastParams.resample.set_size(loop_ub_tmp, 1);
    for (i = 0; i < 1; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        result->contrastParams.resample[i1] = 0.0;
      }
    }

    result->calculationResults.chiValues.set_size(loop_ub_tmp);
    result->calculationResults.sumChi = 0.0;

    //  We also fill the results arrays to define their type and size.
    reflectivity.set_size(loop_ub_tmp);
    simulation.set_size(loop_ub_tmp);
    result->shiftedData.set_size(loop_ub_tmp);
    layerSlds.set_size(loop_ub_tmp);
    domainLayerSlds.set_size(loop_ub_tmp, 2);
    sldProfiles.set_size(loop_ub_tmp);
    domainSldProfiles.set_size(loop_ub_tmp, 2);
    resampledLayers.set_size(loop_ub_tmp);
    domainResampledLayers.set_size(loop_ub_tmp, 2);
    for (int32_T b_i{0}; b_i < loop_ub_tmp; b_i++) {
      result->calculationResults.chiValues[b_i] = 0.0;
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
      result->shiftedData[b_i].f1.set_size(2, 3);
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
      resampledLayers[b_i].f1.set_size(2, 3);
      domainResampledLayers[b_i].f1.set_size(2, 3);
      domainResampledLayers[b_i + domainResampledLayers.size(0)].f1.set_size(2,
        3);
      for (i = 0; i < 3; i++) {
        result->shiftedData[b_i].f1[result->shiftedData[b_i].f1.size(0) * i] =
          1.0;
        result->shiftedData[b_i].f1[result->shiftedData[b_i].f1.size(0) * i + 1]
          = 1.0;
        layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i] = 1.0;
        layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i + 1] = 1.0;
        domainLayerSlds[b_i].f1[domainLayerSlds[b_i].f1.size(0) * i] = 1.0;
        domainLayerSlds[b_i + domainLayerSlds.size(0)].f1[domainLayerSlds[b_i +
          domainLayerSlds.size(0)].f1.size(0) * i] = 1.0;
        domainLayerSlds[b_i].f1[domainLayerSlds[b_i].f1.size(0) * i + 1] = 1.0;
        domainLayerSlds[b_i + domainLayerSlds.size(0)].f1[domainLayerSlds[b_i +
          domainLayerSlds.size(0)].f1.size(0) * i + 1] = 1.0;
        resampledLayers[b_i].f1[resampledLayers[b_i].f1.size(0) * i] = 1.0;
        resampledLayers[b_i].f1[resampledLayers[b_i].f1.size(0) * i + 1] = 1.0;
        domainResampledLayers[b_i].f1[domainResampledLayers[b_i].f1.size(0) * i]
          = 1.0;
        domainResampledLayers[b_i + domainResampledLayers.size(0)]
          .f1[domainResampledLayers[b_i + domainResampledLayers.size(0)].f1.size
          (0) * i] = 1.0;
        domainResampledLayers[b_i].f1[domainResampledLayers[b_i].f1.size(0) * i
          + 1] = 1.0;
        domainResampledLayers[b_i + domainResampledLayers.size(0)]
          .f1[domainResampledLayers[b_i + domainResampledLayers.size(0)].f1.size
          (0) * i + 1] = 1.0;
      }
    }

    //  Decide which target function we are calling and call the relevant routines
    if (coder::internal::h_strcmp(problemStruct->TF.data, problemStruct->TF.size))
    {
      loop_ub_tmp = 0;
    } else if (coder::internal::i_strcmp(problemStruct->TF.data,
                problemStruct->TF.size)) {
      loop_ub_tmp = 1;
    } else {
      loop_ub_tmp = -1;
    }

    switch (loop_ub_tmp) {
     case 0:
      nonPolarisedTF::b_reflectivityCalculation(problemStruct, problemCells,
        controls, &contrastParams, &result->calculationResults, b_reflectivity,
        b_simulation, shiftedData, b_layerSlds, b_sldProfiles, b_resampledLayers);
      result->contrastParams.resample.set_size(1, contrastParams.resample.size(1));
      loop_ub = contrastParams.resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        result->contrastParams.resample[result->contrastParams.resample.size(0) *
          i] = contrastParams.resample[i];
      }

      cast(b_reflectivity, reflectivity);
      cast(b_simulation, simulation);
      cast(shiftedData, result->shiftedData);
      cast(b_layerSlds, layerSlds);
      cast(b_sldProfiles, sldProfiles);
      cast(b_resampledLayers, resampledLayers);

      // case coderEnums.calculationTypes.OilWater
      // contrastParams = oilWaterTFReflectivityCalculation(problemStruct,problemCells,controls);
      // case coderEnums.calculationTypes.Magnetic
      // contrastParams = polarisedTFReflectivityCalculation(problemStruct,problemCells,controls);
      break;

     case 1:
      domainsTF::b_reflectivityCalculation(problemStruct, problemCells, controls,
        &b_contrastParams, &result->calculationResults, b_reflectivity,
        b_simulation, shiftedData, b_domainLayerSlds, b_domainSldProfiles,
        b_domainResampledLayers);
      contrastParams.backgroundParams.set_size
        (b_contrastParams.backgroundParams.size(0));
      loop_ub = b_contrastParams.backgroundParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams.backgroundParams[i] = b_contrastParams.backgroundParams[i];
      }

      contrastParams.scalefactors.set_size(b_contrastParams.scalefactors.size(0));
      loop_ub = b_contrastParams.scalefactors.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams.scalefactors[i] = b_contrastParams.scalefactors[i];
      }

      contrastParams.bulkIn.set_size(b_contrastParams.bulkIn.size(0));
      loop_ub = b_contrastParams.bulkIn.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams.bulkIn[i] = b_contrastParams.bulkIn[i];
      }

      contrastParams.bulkOut.set_size(b_contrastParams.bulkOut.size(0));
      loop_ub = b_contrastParams.bulkOut.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams.bulkOut[i] = b_contrastParams.bulkOut[i];
      }

      contrastParams.resolutionParams.set_size
        (b_contrastParams.resolutionParams.size(0));
      loop_ub = b_contrastParams.resolutionParams.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams.resolutionParams[i] = b_contrastParams.resolutionParams[i];
      }

      contrastParams.subRoughs.set_size(b_contrastParams.subRoughs.size(0));
      loop_ub = b_contrastParams.subRoughs.size(0);
      for (i = 0; i < loop_ub; i++) {
        contrastParams.subRoughs[i] = b_contrastParams.subRoughs[i];
      }

      contrastParams.resample.set_size(1, b_contrastParams.resample.size(1));
      loop_ub = b_contrastParams.resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        contrastParams.resample[i] = b_contrastParams.resample[i];
      }

      result->contrastParams.resample.set_size(1, contrastParams.resample.size(1));
      loop_ub = contrastParams.resample.size(1);
      for (i = 0; i < loop_ub; i++) {
        result->contrastParams.resample[result->contrastParams.resample.size(0) *
          i] = contrastParams.resample[i];
      }

      cast(b_reflectivity, reflectivity);
      cast(b_simulation, simulation);
      cast(shiftedData, result->shiftedData);
      cast(b_domainLayerSlds, r1);
      domainLayerSlds.set_size(r1.size(0), 2);
      cast(b_domainSldProfiles, r2);
      domainSldProfiles.set_size(r2.size(0), 2);
      cast(b_domainResampledLayers, r3);
      domainResampledLayers.set_size(r3.size(0), 2);
      loop_ub = r1.size(0);
      b_loop_ub = r2.size(0);
      loop_ub_tmp = r3.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          domainLayerSlds[i1 + domainLayerSlds.size(0) * i] = r1[i1 + r1.size(0)
            * i];
        }

        for (i1 = 0; i1 < b_loop_ub; i1++) {
          domainSldProfiles[i1 + domainSldProfiles.size(0) * i] = r2[i1 +
            r2.size(0) * i];
        }

        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          domainResampledLayers[i1 + domainResampledLayers.size(0) * i] = r3[i1
            + r3.size(0) * i];
        }
      }

      //      otherwise
      //          error('The calculation type "%s" is not supported', whichTF);
      break;
    }

    //  Make the result struct
    cast(reflectivity, result->reflectivity);
    cast(simulation, result->simulation);

    //  The size of this array now varies depending on TF
    if (coder::internal::i_strcmp(problemStruct->TF.data, problemStruct->TF.size))
    {
      i = 0;
    } else {
      i = -1;
    }

    switch (i) {
     case 0:
      b_cast(domainLayerSlds, r);
      result->layerSlds.set_size(r.size(0), r.size(1));
      loop_ub = r.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = r.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          result->layerSlds[i1 + result->layerSlds.size(0) * i] = r[i1 + r.size
            (0) * i];
        }
      }

      b_cast(domainSldProfiles, r);
      result->sldProfiles.set_size(r.size(0), r.size(1));
      loop_ub = r.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = r.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          result->sldProfiles[i1 + result->sldProfiles.size(0) * i] = r[i1 +
            r.size(0) * i];
        }
      }

      result->resampledLayers.set_size(domainResampledLayers.size(0), 2);
      for (i = 0; i < 2; i++) {
        loop_ub = domainResampledLayers.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          result->resampledLayers[i1 + result->resampledLayers.size(0) * i] =
            domainResampledLayers[i1 + domainResampledLayers.size(0) * i];
        }
      }
      break;

     default:
      result->layerSlds.set_size(layerSlds.size(0), 1);
      for (i = 0; i < layerSlds.size(0); i++) {
        result->layerSlds[i].f1.set_size(layerSlds[i].f1.size(0), layerSlds[i].
          f1.size(1));
        loop_ub = layerSlds[i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1.size(0);
          for (loop_ub_tmp = 0; loop_ub_tmp < b_loop_ub; loop_ub_tmp++) {
            result->layerSlds[i].f1[loop_ub_tmp + result->layerSlds[i].f1.size(0)
              * i1] = layerSlds[i].f1[loop_ub_tmp + layerSlds[i].f1.size(0) * i1];
          }
        }
      }

      result->sldProfiles.set_size(sldProfiles.size(0), 1);
      for (i = 0; i < sldProfiles.size(0); i++) {
        result->sldProfiles[i].f1.set_size(sldProfiles[i].f1.size(0), 2);
        loop_ub = sldProfiles[i].f1.size(0);
        for (i1 = 0; i1 < 2; i1++) {
          for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
            result->sldProfiles[i].f1[loop_ub_tmp + result->sldProfiles[i].
              f1.size(0) * i1] = sldProfiles[i].f1[loop_ub_tmp + sldProfiles[i].
              f1.size(0) * i1];
          }
        }
      }

      result->resampledLayers.set_size(resampledLayers.size(0), 1);
      for (i = 0; i < resampledLayers.size(0); i++) {
        result->resampledLayers[i].f1.set_size(resampledLayers[i].f1.size(0), 3);
        loop_ub = resampledLayers[i].f1.size(0);
        for (i1 = 0; i1 < 3; i1++) {
          for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
            result->resampledLayers[i].f1[loop_ub_tmp + result->
              resampledLayers[i].f1.size(0) * i1] = resampledLayers[i]
              .f1[loop_ub_tmp + resampledLayers[i].f1.size(0) * i1];
          }
        }
      }
      break;
    }

    //  Complete the result struct
    a__1 = *problemStruct;
    packParams(&a__1, problemCells->f7, problemCells->f8, problemCells->f9,
               problemCells->f10, problemCells->f11, problemCells->f12,
               problemCells->f13, problemCells->f20, problemLimits,
               &controls->checks, result->fitNames);
    result->contrastParams.backgroundParams.set_size
      (contrastParams.backgroundParams.size(0));
    loop_ub = contrastParams.backgroundParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      result->contrastParams.backgroundParams[i] =
        contrastParams.backgroundParams[i];
    }

    result->contrastParams.scalefactors.set_size
      (contrastParams.scalefactors.size(0));
    loop_ub = contrastParams.scalefactors.size(0);
    for (i = 0; i < loop_ub; i++) {
      result->contrastParams.scalefactors[i] = contrastParams.scalefactors[i];
    }

    result->contrastParams.bulkIn.set_size(contrastParams.bulkIn.size(0));
    loop_ub = contrastParams.bulkIn.size(0);
    for (i = 0; i < loop_ub; i++) {
      result->contrastParams.bulkIn[i] = contrastParams.bulkIn[i];
    }

    result->contrastParams.bulkOut.set_size(contrastParams.bulkOut.size(0));
    loop_ub = contrastParams.bulkOut.size(0);
    for (i = 0; i < loop_ub; i++) {
      result->contrastParams.bulkOut[i] = contrastParams.bulkOut[i];
    }

    result->contrastParams.resolutionParams.set_size
      (contrastParams.resolutionParams.size(0));
    loop_ub = contrastParams.resolutionParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      result->contrastParams.resolutionParams[i] =
        contrastParams.resolutionParams[i];
    }

    result->contrastParams.subRoughs.set_size(contrastParams.subRoughs.size(0));
    loop_ub = contrastParams.subRoughs.size(0);
    for (i = 0; i < loop_ub; i++) {
      result->contrastParams.subRoughs[i] = contrastParams.subRoughs[i];
    }

    result->fitParams.set_size(problemStruct->fitParams.size(0),
      problemStruct->fitParams.size(1));
    loop_ub = problemStruct->fitParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = problemStruct->fitParams.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        result->fitParams[i1 + result->fitParams.size(0) * i] =
          problemStruct->fitParams[i1 + problemStruct->fitParams.size(0) * i];
      }
    }
  }
}

// End of code generation (reflectivityCalculation.cpp)
