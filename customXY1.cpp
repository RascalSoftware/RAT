//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// customXY1.cpp
//
// Code generation for function 'customXY1'
//

// Include files
#include "customXY1.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "applyBackgroundCorrection.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "cat.h"
#include "chiSquared.h"
#include "constructBackground.h"
#include "constructResolution.h"
#include "extractProblemParams.h"
#include "makeSimulationRange.h"
#include "processCustomFunction3.h"
#include "resampleLayers.h"
#include "resampleLayersReIm.h"
#include "rt_nonfinite.h"
#include "shiftData.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "omp.h"

// Function Declarations
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_33, 2U> &r, ::coder::array<
                   cell_wrap_9, 2U> &r1);
  namespace domainsTF
  {
    static double c_contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double scalefactorIndex, double
      bulkInIndex, double bulkOutIndex, const double resolutionParamIndex_data[],
      const int resolutionParamIndex_size[2], double domainRatioIndex, const ::
      coder::array<double, 2U> &backgroundParams, const ::coder::array<double,
      2U> &scalefactors, const ::coder::array<double, 2U> &bulkIns, const ::
      coder::array<double, 2U> &bulkOuts, const ::coder::array<double, 2U>
      &resolutionParams, const ::coder::array<double, 2U> &domainRatios, double
      dataPresent, const ::coder::array<double, 2U> &data, const double
      dataLimits[2], const double simLimits[2], const double repeatLayers[2],
      const char backgroundType_data[], const int backgroundType_size[2], const
      char backgroundAction_data[], const int backgroundAction_size[2], const
      char resolutionType_data[], const int resolutionType_size[2], const ::
      coder::array<cell_wrap_10, 2U> &customFiles, double nParams, const char
      parallel_data[], const int parallel_size[2], double resampleMinAngle,
      double resampleNPoints, boolean_T useImaginary, double roughness, const ::
      coder::array<double, 2U> &sldProfile1, const ::coder::array<double, 2U>
      &sldProfile2, ::coder::array<double, 2U> &reflectivity, ::coder::array<
      double, 2U> &simulation, ::coder::array<double, 2U> &shiftedData, ::coder::
      array<double, 2U> &background, ::coder::array<double, 2U> &resolution,
      cell_wrap_9 layerSld[2], cell_wrap_9 sldProfile[2], cell_wrap_9
      resampledLayer[2], double &scalefactorValue, double &bulkInValue, double
      &bulkOutValue, double &chi);
    static double d_contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double scalefactorIndex, double
      bulkInIndex, double bulkOutIndex, const double resolutionParamIndex_data[],
      const int resolutionParamIndex_size[2], double domainRatioIndex, const ::
      coder::array<double, 2U> &backgroundParams, const ::coder::array<double,
      2U> &scalefactors, const ::coder::array<double, 2U> &bulkIns, const ::
      coder::array<double, 2U> &bulkOuts, const ::coder::array<double, 2U>
      &resolutionParams, const ::coder::array<double, 2U> &domainRatios, double
      dataPresent, const ::coder::array<double, 2U> &data, const double
      dataLimits[2], const double simLimits[2], const double repeatLayers[2],
      const ::coder::array<cell_wrap_10, 2U> &backgroundType, const char
      backgroundAction_data[], const int backgroundAction_size[2], const char
      resolutionType_data[], const int resolutionType_size[2], const ::coder::
      array<cell_wrap_10, 2U> &customFiles, double nParams, const char
      parallel_data[], const int parallel_size[2], double resampleMinAngle,
      double resampleNPoints, boolean_T useImaginary, double roughness, const ::
      coder::array<double, 2U> &sldProfile1, const ::coder::array<double, 2U>
      &sldProfile2, ::coder::array<double, 2U> &reflectivity, ::coder::array<
      double, 2U> &simulation, ::coder::array<double, 2U> &shiftedData, ::coder::
      array<double, 2U> &background, ::coder::array<double, 2U> &resolution,
      cell_wrap_9 layerSld[2], cell_wrap_9 sldProfile[2], cell_wrap_9
      resampledLayer[2], double &scalefactorValue, double &bulkInValue, double
      &bulkOutValue, double &chi);
  }
}

// Function Definitions
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_33, 2U> &r, ::coder::array<
                   cell_wrap_9, 2U> &r1)
  {
    int i;
    r1.set_size(r.size(0), 2);
    i = r.size(0) << 1;
    for (int i1{0}; i1 < i; i1++) {
      int loop_ub;
      loop_ub = r[i1].f1.size(1);
      r1[i1].f1.set_size(r[i1].f1.size(0), r[i1].f1.size(1));
      for (int i2{0}; i2 < loop_ub; i2++) {
        int b_loop_ub;
        b_loop_ub = r[i1].f1.size(0);
        for (int i3{0}; i3 < b_loop_ub; i3++) {
          r1[i1].f1[i3 + r1[i1].f1.size(0) * i2] = r[i1].f1[i3 + r[i1].f1.size(0)
            * i2];
        }
      }
    }
  }

  namespace domainsTF
  {
    static double c_contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double scalefactorIndex, double
      bulkInIndex, double bulkOutIndex, const double resolutionParamIndex_data[],
      const int resolutionParamIndex_size[2], double domainRatioIndex, const ::
      coder::array<double, 2U> &backgroundParams, const ::coder::array<double,
      2U> &scalefactors, const ::coder::array<double, 2U> &bulkIns, const ::
      coder::array<double, 2U> &bulkOuts, const ::coder::array<double, 2U>
      &resolutionParams, const ::coder::array<double, 2U> &domainRatios, double
      dataPresent, const ::coder::array<double, 2U> &data, const double
      dataLimits[2], const double simLimits[2], const double repeatLayers[2],
      const char backgroundType_data[], const int backgroundType_size[2], const
      char backgroundAction_data[], const int backgroundAction_size[2], const
      char resolutionType_data[], const int resolutionType_size[2], const ::
      coder::array<cell_wrap_10, 2U> &customFiles, double nParams, const char
      parallel_data[], const int parallel_size[2], double resampleMinAngle,
      double resampleNPoints, boolean_T useImaginary, double roughness, const ::
      coder::array<double, 2U> &sldProfile1, const ::coder::array<double, 2U>
      &sldProfile2, ::coder::array<double, 2U> &reflectivity, ::coder::array<
      double, 2U> &simulation, ::coder::array<double, 2U> &shiftedData, ::coder::
      array<double, 2U> &background, ::coder::array<double, 2U> &resolution,
      cell_wrap_9 layerSld[2], cell_wrap_9 sldProfile[2], cell_wrap_9
      resampledLayer[2], double &scalefactorValue, double &bulkInValue, double
      &bulkOutValue, double &chi)
    {
      ::coder::array<double, 2U> b_data;
      ::coder::array<double, 2U> b_reflect1;
      ::coder::array<double, 2U> b_shiftedData;
      ::coder::array<double, 2U> b_sldProfile1;
      ::coder::array<double, 2U> c_sldProfile1;
      ::coder::array<double, 2U> reflect1;
      ::coder::array<double, 2U> reflect2;
      ::coder::array<double, 2U> simul1;
      ::coder::array<double, 2U> simul2;
      ::coder::array<double, 1U> simulationXData;
      cell_wrap_9 r;
      cell_wrap_9 r1;
      cell_wrap_9 r2;
      cell_wrap_9 r3;
      double dataIndices[2];
      double domainRatios_tmp;
      int b_loop_ub;
      int loop_ub;

      //  Get the domain ratio for this contrast
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(scalefactorIndex, bulkInIndex, bulkOutIndex, scalefactors,
               bulkIns, bulkOuts, scalefactorValue, bulkInValue, bulkOutValue);

      //  Resample the sld profiles
      if (!useImaginary) {
        b_resampleLayers(sldProfile1, resampleMinAngle, resampleNPoints, r.f1);
        r1.f1.set_size(r.f1.size(0), 3);
        for (int i{0}; i < 3; i++) {
          loop_ub = r.f1.size(0);
          for (int i1{0}; i1 < loop_ub; i1++) {
            r1.f1[i1 + r1.f1.size(0) * i] = r.f1[i1 + r.f1.size(0) * i];
          }
        }

        b_resampleLayers(sldProfile2, resampleMinAngle, resampleNPoints, r.f1);
      } else {
        b_sldProfile1.set_size(sldProfile1.size(0), 2);
        loop_ub = sldProfile1.size(0);
        for (int i{0}; i < 2; i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_sldProfile1[i1 + b_sldProfile1.size(0) * i] = sldProfile1[i1 +
              sldProfile1.size(0) * i];
          }
        }

        c_sldProfile1.set_size(sldProfile1.size(0), 2);
        loop_ub = sldProfile1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          c_sldProfile1[i] = sldProfile1[i];
          c_sldProfile1[i + c_sldProfile1.size(0)] = sldProfile1[i +
            sldProfile1.size(0) * 2];
        }

        resampleLayersReIm(b_sldProfile1, c_sldProfile1, resampleMinAngle,
                           resampleNPoints, r.f1);
        r1.f1.set_size(r.f1.size(0), 4);
        for (int i{0}; i < 4; i++) {
          loop_ub = r.f1.size(0);
          for (int i1{0}; i1 < loop_ub; i1++) {
            r1.f1[i1 + r1.f1.size(0) * i] = r.f1[i1 + r.f1.size(0) * i];
          }
        }

        b_sldProfile1.set_size(sldProfile2.size(0), 2);
        loop_ub = sldProfile2.size(0);
        for (int i{0}; i < 2; i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_sldProfile1[i1 + b_sldProfile1.size(0) * i] = sldProfile2[i1 +
              sldProfile2.size(0) * i];
          }
        }

        c_sldProfile1.set_size(sldProfile2.size(0), 2);
        loop_ub = sldProfile2.size(0);
        for (int i{0}; i < loop_ub; i++) {
          c_sldProfile1[i] = sldProfile2[i];
          c_sldProfile1[i + c_sldProfile1.size(0)] = sldProfile2[i +
            sldProfile2.size(0) * 2];
        }

        resampleLayersReIm(b_sldProfile1, c_sldProfile1, resampleMinAngle,
                           resampleNPoints, r.f1);
      }

      layerSld[0] = r1;
      layerSld[1] = r;
      resampledLayer[0] = r1;
      resampledLayer[1] = r;
      r2.f1.set_size(sldProfile1.size(0), sldProfile1.size(1));
      loop_ub = sldProfile1.size(1);
      for (int i{0}; i < loop_ub; i++) {
        b_loop_ub = sldProfile1.size(0);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          r2.f1[i1 + r2.f1.size(0) * i] = sldProfile1[i1 + sldProfile1.size(0) *
            i];
        }
      }

      r3.f1.set_size(sldProfile2.size(0), sldProfile2.size(1));
      loop_ub = sldProfile2.size(1);
      for (int i{0}; i < loop_ub; i++) {
        b_loop_ub = sldProfile2.size(0);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          r3.f1[i1 + r3.f1.size(0) * i] = sldProfile2[i1 + sldProfile2.size(0) *
            i];
        }
      }

      sldProfile[0] = r2;
      sldProfile[1] = r3;
      b_data.set_size(data.size(0), 6);
      for (int i{0}; i < 6; i++) {
        loop_ub = data.size(0) - 1;
        for (int i1{0}; i1 <= loop_ub; i1++) {
          b_data[i1 + b_data.size(0) * i] = data[i1 + data.size(0) * i];
        }
      }

      shiftData(scalefactorValue, dataPresent, b_data, dataLimits, simLimits,
                b_shiftedData);
      makeSimulationRange(b_shiftedData, simLimits, simulationXData, dataIndices);
      constructBackground(backgroundType_data, backgroundType_size,
                          backgroundParamIndex_data, backgroundParamIndex_size,
                          b_shiftedData, customFiles, backgroundParams,
                          simulationXData, dataIndices, background);
      constructResolution(resolutionType_data, resolutionType_size,
                          resolutionParamIndex_data, resolutionParamIndex_size,
                          b_shiftedData, resolutionParams, simulationXData,
                          dataIndices, resolution);
      callReflectivity(bulkInValue, bulkOutValue, simulationXData, dataIndices,
                       repeatLayers, r1.f1, roughness, resolution, parallel_data,
                       parallel_size, useImaginary, reflect1, simul1);
      callReflectivity(bulkInValue, bulkOutValue, simulationXData, dataIndices,
                       repeatLayers, r.f1, roughness, resolution, parallel_data,
                       parallel_size, useImaginary, reflect2, simul2);
      b_data.set_size(b_shiftedData.size(0), 6);
      loop_ub = b_shiftedData.size(0) - 1;
      for (int i{0}; i < 6; i++) {
        for (int i1{0}; i1 <= loop_ub; i1++) {
          b_data[i1 + b_data.size(0) * i] = b_shiftedData[i1 +
            b_shiftedData.size(0) * i];
        }
      }

      applyBackgroundCorrection(reflect1, simul1, b_data, background,
        backgroundAction_data, backgroundAction_size, b_reflect1);
      applyBackgroundCorrection(reflect2, simul2, b_shiftedData, background,
        backgroundAction_data, backgroundAction_size, shiftedData);

      //  Calculate the average reflectivities....
      //  Calculates the averaged reflectivity for domains samples (incoherent
      //  sum)
      if (reflect1.size(0) == reflect2.size(0)) {
        domainRatios_tmp = domainRatios[static_cast<int>(domainRatioIndex) - 1];
        reflectivity.set_size(reflect1.size(0), 2);
        loop_ub = reflect1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          reflectivity[i] = reflect1[i];
          reflectivity[i + reflectivity.size(0)] = domainRatios_tmp * reflect1[i
            + reflect1.size(0)] + (1.0 - domainRatios_tmp) * reflect2[i +
            reflect2.size(0)];
        }
      } else {
        binary_expand_op(reflectivity, reflect1, domainRatios, domainRatioIndex,
                         reflect2);
      }

      if (simul1.size(0) == simul2.size(0)) {
        domainRatios_tmp = domainRatios[static_cast<int>(domainRatioIndex) - 1];
        simulation.set_size(simul1.size(0), 2);
        loop_ub = simul1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          simulation[i] = simul1[i];
          simulation[i + simulation.size(0)] = domainRatios_tmp * simul1[i +
            simul1.size(0)] + (1.0 - domainRatios_tmp) * simul2[i + simul2.size
            (0)];
        }
      } else {
        binary_expand_op(simulation, simul1, domainRatios, domainRatioIndex,
                         simul2);
      }

      if (dataPresent != 0.0) {
        chi = chiSquared(shiftedData, reflectivity, nParams);
      } else {
        chi = 0.0;
      }

      return 0.0;
    }

    static double d_contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double scalefactorIndex, double
      bulkInIndex, double bulkOutIndex, const double resolutionParamIndex_data[],
      const int resolutionParamIndex_size[2], double domainRatioIndex, const ::
      coder::array<double, 2U> &backgroundParams, const ::coder::array<double,
      2U> &scalefactors, const ::coder::array<double, 2U> &bulkIns, const ::
      coder::array<double, 2U> &bulkOuts, const ::coder::array<double, 2U>
      &resolutionParams, const ::coder::array<double, 2U> &domainRatios, double
      dataPresent, const ::coder::array<double, 2U> &data, const double
      dataLimits[2], const double simLimits[2], const double repeatLayers[2],
      const ::coder::array<cell_wrap_10, 2U> &backgroundType, const char
      backgroundAction_data[], const int backgroundAction_size[2], const char
      resolutionType_data[], const int resolutionType_size[2], const ::coder::
      array<cell_wrap_10, 2U> &customFiles, double nParams, const char
      parallel_data[], const int parallel_size[2], double resampleMinAngle,
      double resampleNPoints, boolean_T useImaginary, double roughness, const ::
      coder::array<double, 2U> &sldProfile1, const ::coder::array<double, 2U>
      &sldProfile2, ::coder::array<double, 2U> &reflectivity, ::coder::array<
      double, 2U> &simulation, ::coder::array<double, 2U> &shiftedData, ::coder::
      array<double, 2U> &background, ::coder::array<double, 2U> &resolution,
      cell_wrap_9 layerSld[2], cell_wrap_9 sldProfile[2], cell_wrap_9
      resampledLayer[2], double &scalefactorValue, double &bulkInValue, double
      &bulkOutValue, double &chi)
    {
      ::coder::array<double, 2U> b_data;
      ::coder::array<double, 2U> b_reflect1;
      ::coder::array<double, 2U> b_shiftedData;
      ::coder::array<double, 2U> b_sldProfile1;
      ::coder::array<double, 2U> c_sldProfile1;
      ::coder::array<double, 2U> reflect1;
      ::coder::array<double, 2U> reflect2;
      ::coder::array<double, 2U> simul1;
      ::coder::array<double, 2U> simul2;
      ::coder::array<double, 1U> simulationXData;
      cell_wrap_9 r;
      cell_wrap_9 r1;
      cell_wrap_9 r2;
      cell_wrap_9 r3;
      double dataIndices[2];
      double domainRatios_tmp;
      int b_loop_ub;
      int loop_ub;

      //  Get the domain ratio for this contrast
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(scalefactorIndex, bulkInIndex, bulkOutIndex, scalefactors,
               bulkIns, bulkOuts, scalefactorValue, bulkInValue, bulkOutValue);

      //  Resample the sld profiles
      if (!useImaginary) {
        b_resampleLayers(sldProfile1, resampleMinAngle, resampleNPoints, r.f1);
        r1.f1.set_size(r.f1.size(0), 3);
        for (int i{0}; i < 3; i++) {
          loop_ub = r.f1.size(0);
          for (int i1{0}; i1 < loop_ub; i1++) {
            r1.f1[i1 + r1.f1.size(0) * i] = r.f1[i1 + r.f1.size(0) * i];
          }
        }

        b_resampleLayers(sldProfile2, resampleMinAngle, resampleNPoints, r.f1);
      } else {
        b_sldProfile1.set_size(sldProfile1.size(0), 2);
        loop_ub = sldProfile1.size(0);
        for (int i{0}; i < 2; i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_sldProfile1[i1 + b_sldProfile1.size(0) * i] = sldProfile1[i1 +
              sldProfile1.size(0) * i];
          }
        }

        c_sldProfile1.set_size(sldProfile1.size(0), 2);
        loop_ub = sldProfile1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          c_sldProfile1[i] = sldProfile1[i];
          c_sldProfile1[i + c_sldProfile1.size(0)] = sldProfile1[i +
            sldProfile1.size(0) * 2];
        }

        resampleLayersReIm(b_sldProfile1, c_sldProfile1, resampleMinAngle,
                           resampleNPoints, r.f1);
        r1.f1.set_size(r.f1.size(0), 4);
        for (int i{0}; i < 4; i++) {
          loop_ub = r.f1.size(0);
          for (int i1{0}; i1 < loop_ub; i1++) {
            r1.f1[i1 + r1.f1.size(0) * i] = r.f1[i1 + r.f1.size(0) * i];
          }
        }

        b_sldProfile1.set_size(sldProfile2.size(0), 2);
        loop_ub = sldProfile2.size(0);
        for (int i{0}; i < 2; i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_sldProfile1[i1 + b_sldProfile1.size(0) * i] = sldProfile2[i1 +
              sldProfile2.size(0) * i];
          }
        }

        c_sldProfile1.set_size(sldProfile2.size(0), 2);
        loop_ub = sldProfile2.size(0);
        for (int i{0}; i < loop_ub; i++) {
          c_sldProfile1[i] = sldProfile2[i];
          c_sldProfile1[i + c_sldProfile1.size(0)] = sldProfile2[i +
            sldProfile2.size(0) * 2];
        }

        resampleLayersReIm(b_sldProfile1, c_sldProfile1, resampleMinAngle,
                           resampleNPoints, r.f1);
      }

      layerSld[0] = r1;
      layerSld[1] = r;
      resampledLayer[0] = r1;
      resampledLayer[1] = r;
      r2.f1.set_size(sldProfile1.size(0), sldProfile1.size(1));
      loop_ub = sldProfile1.size(1);
      for (int i{0}; i < loop_ub; i++) {
        b_loop_ub = sldProfile1.size(0);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          r2.f1[i1 + r2.f1.size(0) * i] = sldProfile1[i1 + sldProfile1.size(0) *
            i];
        }
      }

      r3.f1.set_size(sldProfile2.size(0), sldProfile2.size(1));
      loop_ub = sldProfile2.size(1);
      for (int i{0}; i < loop_ub; i++) {
        b_loop_ub = sldProfile2.size(0);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          r3.f1[i1 + r3.f1.size(0) * i] = sldProfile2[i1 + sldProfile2.size(0) *
            i];
        }
      }

      sldProfile[0] = r2;
      sldProfile[1] = r3;
      b_data.set_size(data.size(0), 6);
      for (int i{0}; i < 6; i++) {
        loop_ub = data.size(0) - 1;
        for (int i1{0}; i1 <= loop_ub; i1++) {
          b_data[i1 + b_data.size(0) * i] = data[i1 + data.size(0) * i];
        }
      }

      shiftData(scalefactorValue, dataPresent, b_data, dataLimits, simLimits,
                b_shiftedData);
      makeSimulationRange(b_shiftedData, simLimits, simulationXData, dataIndices);
      constructBackground(backgroundType, backgroundParamIndex_data,
                          backgroundParamIndex_size, b_shiftedData, customFiles,
                          backgroundParams, simulationXData, dataIndices,
                          background);
      constructResolution(resolutionType_data, resolutionType_size,
                          resolutionParamIndex_data, resolutionParamIndex_size,
                          b_shiftedData, resolutionParams, simulationXData,
                          dataIndices, resolution);
      callReflectivity(bulkInValue, bulkOutValue, simulationXData, dataIndices,
                       repeatLayers, r1.f1, roughness, resolution, parallel_data,
                       parallel_size, useImaginary, reflect1, simul1);
      callReflectivity(bulkInValue, bulkOutValue, simulationXData, dataIndices,
                       repeatLayers, r.f1, roughness, resolution, parallel_data,
                       parallel_size, useImaginary, reflect2, simul2);
      b_data.set_size(b_shiftedData.size(0), 6);
      loop_ub = b_shiftedData.size(0) - 1;
      for (int i{0}; i < 6; i++) {
        for (int i1{0}; i1 <= loop_ub; i1++) {
          b_data[i1 + b_data.size(0) * i] = b_shiftedData[i1 +
            b_shiftedData.size(0) * i];
        }
      }

      applyBackgroundCorrection(reflect1, simul1, b_data, background,
        backgroundAction_data, backgroundAction_size, b_reflect1);
      applyBackgroundCorrection(reflect2, simul2, b_shiftedData, background,
        backgroundAction_data, backgroundAction_size, shiftedData);

      //  Calculate the average reflectivities....
      //  Calculates the averaged reflectivity for domains samples (incoherent
      //  sum)
      if (reflect1.size(0) == reflect2.size(0)) {
        domainRatios_tmp = domainRatios[static_cast<int>(domainRatioIndex) - 1];
        reflectivity.set_size(reflect1.size(0), 2);
        loop_ub = reflect1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          reflectivity[i] = reflect1[i];
          reflectivity[i + reflectivity.size(0)] = domainRatios_tmp * reflect1[i
            + reflect1.size(0)] + (1.0 - domainRatios_tmp) * reflect2[i +
            reflect2.size(0)];
        }
      } else {
        binary_expand_op(reflectivity, reflect1, domainRatios, domainRatioIndex,
                         reflect2);
      }

      if (simul1.size(0) == simul2.size(0)) {
        domainRatios_tmp = domainRatios[static_cast<int>(domainRatioIndex) - 1];
        simulation.set_size(simul1.size(0), 2);
        loop_ub = simul1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          simulation[i] = simul1[i];
          simulation[i + simulation.size(0)] = domainRatios_tmp * simul1[i +
            simul1.size(0)] + (1.0 - domainRatios_tmp) * simul2[i + simul2.size
            (0)];
        }
      } else {
        binary_expand_op(simulation, simul1, domainRatios, domainRatioIndex,
                         simul2);
      }

      if (dataPresent != 0.0) {
        chi = chiSquared(shiftedData, reflectivity, nParams);
      } else {
        chi = 0.0;
      }

      return 0.0;
    }

    void b_customXY(const ProblemDefinition &problemStruct, const Controls
                    *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                    array<double, 1U> &scalefactors, ::coder::array<double, 1U>
                    &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::
                    array<double, 1U> &chis, ::coder::array<cell_wrap_7, 1U>
                    &reflectivity, ::coder::array<cell_wrap_7, 1U> &simulation, ::
                    coder::array<cell_wrap_8, 1U> &shiftedData, ::coder::array<
                    cell_wrap_8, 1U> &backgrounds, ::coder::array<cell_wrap_7,
                    1U> &resolutions, ::coder::array<cell_wrap_9, 2U>
                    &domainLayerSlds, ::coder::array<cell_wrap_9, 2U>
                    &domainSldProfiles, ::coder::array<cell_wrap_9, 2U>
                    &domainResampledLayers, ::coder::array<double, 1U>
                    &subRoughs)
    {
      ::coder::array<cell_wrap_33, 2U> r;
      ::coder::array<cell_wrap_64, 1U> layerSlds;
      ::coder::array<cell_wrap_64, 1U> resampledLayers;
      ::coder::array<cell_wrap_64, 1U> sldProfiles;
      ::coder::array<cell_wrap_9, 2U> inputSldProfiles;
      ::coder::array<cell_wrap_9, 1U> inputSldProfiles1;
      ::coder::array<cell_wrap_9, 1U> inputSldProfiles2;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> r2;
      double dv3[2];
      double dv4[2];
      double dv5[2];
      double d;
      double d1;
      double d2;
      double d3;
      double resampleMinAngle;
      double resampleNPoints;
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int iv7[2];
      int iv8[2];
      int b_i;
      int b_loop_ub;
      int c_loop_ub;
      int i3;
      int i4;
      int loop_ub;
      int nParams;
      int unnamed_idx_0_tmp_tmp_tmp;
      boolean_T useImaginary;

      //  Extract parameters from problemStruct
      //  qzshifts are not included as a parameter in RAT, so we set up dummy
      //  values for the reflectivity calculation
      nParams = problemStruct.params.size(1);
      useImaginary = problemStruct.useImaginary;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      // Pre-Allocation...
      unnamed_idx_0_tmp_tmp_tmp = static_cast<int>
        (problemStruct.numberOfContrasts);
      inputSldProfiles1.set_size(unnamed_idx_0_tmp_tmp_tmp);
      for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
        inputSldProfiles1[i].f1.set_size(2, 1);
        inputSldProfiles1[i].f1[0] = 1.0;
        inputSldProfiles1[i].f1[1] = 1.0;
      }

      inputSldProfiles2.set_size(unnamed_idx_0_tmp_tmp_tmp);
      for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
        inputSldProfiles2[i].f1.set_size(2, 1);
        inputSldProfiles2[i].f1[0] = 1.0;
        inputSldProfiles2[i].f1[1] = 1.0;
      }

      customXY::processCustomFunction(problemStruct.contrastBulkIns,
        problemStruct.contrastBulkOuts, problemStruct.bulkIns,
        problemStruct.bulkOuts, problemStruct.contrastCustomFiles,
        problemStruct.numberOfContrasts, problemStruct.customFiles,
        problemStruct.params, r, subRoughs);
      cast(r, inputSldProfiles);
      b_i = inputSldProfiles.size(0);
      for (int i{0}; i < b_i; i++) {
        loop_ub = inputSldProfiles[i].f1.size(1);
        inputSldProfiles1[i].f1.set_size(inputSldProfiles[i].f1.size(0),
          inputSldProfiles[i].f1.size(1));
        for (int i1{0}; i1 < loop_ub; i1++) {
          b_loop_ub = inputSldProfiles[i].f1.size(0);
          for (int i2{0}; i2 < b_loop_ub; i2++) {
            inputSldProfiles1[i].f1[i2 + inputSldProfiles1[i].f1.size(0) * i1] =
              inputSldProfiles[i].f1[i2 + inputSldProfiles[i].f1.size(0) * i1];
          }
        }

        loop_ub = inputSldProfiles[i + inputSldProfiles.size(0)].f1.size(1);
        inputSldProfiles2[i].f1.set_size(inputSldProfiles[i +
          inputSldProfiles.size(0)].f1.size(0), inputSldProfiles[i +
          inputSldProfiles.size(0)].f1.size(1));
        for (int i1{0}; i1 < loop_ub; i1++) {
          b_loop_ub = inputSldProfiles[i + inputSldProfiles.size(0)].f1.size(0);
          for (int i2{0}; i2 < b_loop_ub; i2++) {
            inputSldProfiles2[i].f1[i2 + inputSldProfiles2[i].f1.size(0) * i1] =
              inputSldProfiles[i + inputSldProfiles.size(0)].f1[i2 +
              inputSldProfiles[i + inputSldProfiles.size(0)].f1.size(0) * i1];
          }
        }
      }

      if (coder::internal::n_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp_tmp);
        resolutions.set_size(unnamed_idx_0_tmp_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp_tmp);
        loop_ub = unnamed_idx_0_tmp_tmp_tmp - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r1,d,d1,d2,d3,iv4,iv5,dv3,dv4,dv5,iv6,iv7,iv8,c_loop_ub,i3,i4)

        for (int c_i = 0; c_i <= loop_ub; c_i++) {
          iv4[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[0];
          iv4[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[1];
          iv5[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[0];
          iv5[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[1];
          dv3[0] = problemStruct.dataLimits[c_i].f1[0];
          dv3[1] = problemStruct.dataLimits[c_i].f1[1];
          dv4[0] = problemStruct.simulationLimits[c_i].f1[0];
          dv4[1] = problemStruct.simulationLimits[c_i].f1[1];
          dv5[0] = problemStruct.repeatLayers[c_i].f1[0];
          dv5[1] = problemStruct.repeatLayers[c_i].f1[1];
          iv6[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[0];
          iv6[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundTypes[c_i].f1)->size())[1];
          iv7[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv7[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[c_i].f1)->size())
            [1];
          iv8[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[0];
          iv8[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[c_i].f1)->size())[1];
          c_contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastBackgroundParams[c_i].f1)->data(), iv4,
                                problemStruct.contrastScalefactors[c_i],
                                problemStruct.contrastBulkIns[c_i],
                                problemStruct.contrastBulkOuts[c_i], (const
            double *)((::coder::array<double, 2U> *)
                      &problemStruct.contrastResolutionParams[c_i].f1)->data(),
                                iv5, problemStruct.contrastDomainRatios[c_i],
                                problemStruct.backgroundParams,
                                problemStruct.scalefactors,
                                problemStruct.bulkIns, problemStruct.bulkOuts,
                                problemStruct.resolutionParams,
                                problemStruct.domainRatios,
                                problemStruct.dataPresent[c_i],
                                problemStruct.data[c_i].f1, dv3, dv4, dv5, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastBackgroundTypes[c_i].f1)->data(),
                                iv6, (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[c_i].f1)->data(), iv7, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastResolutionTypes[c_i].f1)->data(),
                                iv8, problemStruct.customFiles, static_cast<
                                double>(nParams), controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, subRoughs[c_i],
                                inputSldProfiles1[c_i].f1, inputSldProfiles2[c_i]
                                .f1, reflectivity[c_i].f1, simulation[c_i].f1,
                                r1, backgrounds[c_i].f1, resolutions[c_i].f1,
                                layerSlds[c_i].f1, sldProfiles[c_i].f1,
                                resampledLayers[c_i].f1, d3, d2, d1, d);
          c_loop_ub = r1.size(0);
          shiftedData[c_i].f1.set_size(r1.size(0), 3);
          for (i3 = 0; i3 < 3; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r1[i4
                + r1.size(0) * i3];
            }
          }

          qzshifts[c_i] = 0.0;
          scalefactors[c_i] = d3;
          bulkIns[c_i] = d2;
          bulkOuts[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp_tmp);
        resolutions.set_size(unnamed_idx_0_tmp_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp_tmp);
        for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
          double b_dv[2];
          double b_dv1[2];
          double dv2[2];
          double d4;
          double d5;
          double d6;
          double d7;
          int iv[2];
          int iv1[2];
          int iv2[2];
          int iv3[2];
          iv[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastBackgroundParams[i].f1)->size())[0];
          iv[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                    &problemStruct.contrastBackgroundParams[i].f1)->size())[1];
          iv1[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[i].f1)->size())[0];
          iv1[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[i].f1)->size())[1];
          b_dv[0] = problemStruct.dataLimits[i].f1[0];
          b_dv[1] = problemStruct.dataLimits[i].f1[1];
          b_dv1[0] = problemStruct.simulationLimits[i].f1[0];
          b_dv1[1] = problemStruct.simulationLimits[i].f1[1];
          dv2[0] = problemStruct.repeatLayers[i].f1[0];
          dv2[1] = problemStruct.repeatLayers[i].f1[1];
          iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[i].f1)->size())[0];
          iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[i].f1)->size())[1];
          iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[i].f1)->size())[0];
          iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[i].f1)->size())[1];
          d_contrastCalculation((const double *)((::coder::array<double, 2U> *)
            &problemStruct.contrastBackgroundParams[i].f1)->data(), iv,
                                problemStruct.contrastScalefactors[i],
                                problemStruct.contrastBulkIns[i],
                                problemStruct.contrastBulkOuts[i], (const double
            *)((::coder::array<double, 2U> *)
               &problemStruct.contrastResolutionParams[i].f1)->data(), iv1,
                                problemStruct.contrastDomainRatios[i],
                                problemStruct.backgroundParams,
                                problemStruct.scalefactors,
                                problemStruct.bulkIns, problemStruct.bulkOuts,
                                problemStruct.resolutionParams,
                                problemStruct.domainRatios,
                                problemStruct.dataPresent[i],
                                problemStruct.data[i].f1, b_dv, b_dv1, dv2,
                                problemStruct.contrastBackgroundTypes, (const
            char *)((::coder::array<char, 2U> *)
                    &problemStruct.contrastBackgroundActions[i].f1)->data(), iv2,
                                (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastResolutionTypes[i].f1)->data(), iv3,
                                problemStruct.customFiles, static_cast<double>
                                (problemStruct.params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                resampleMinAngle, resampleNPoints,
                                problemStruct.useImaginary, subRoughs[i],
                                inputSldProfiles1[i].f1, inputSldProfiles2[i].f1,
                                reflectivity[i].f1, simulation[i].f1, r2,
                                backgrounds[i].f1, resolutions[i].f1,
                                layerSlds[i].f1, sldProfiles[i].f1,
                                resampledLayers[i].f1, d4, d5, d6, d7);
          chis[i] = d7;
          bulkOuts[i] = d6;
          bulkIns[i] = d5;
          scalefactors[i] = d4;
          loop_ub = r2.size(0);
          shiftedData[i].f1.set_size(r2.size(0), 3);
          for (b_i = 0; b_i < 3; b_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * b_i] = r2[i1 +
                r2.size(0) * b_i];
            }
          }

          qzshifts[i] = 0.0;
        }
      }

      domainSldProfiles.set_size(unnamed_idx_0_tmp_tmp_tmp, 2);
      domainLayerSlds.set_size(unnamed_idx_0_tmp_tmp_tmp, 2);
      domainResampledLayers.set_size(unnamed_idx_0_tmp_tmp_tmp, 2);
      for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
        loop_ub = sldProfiles[i].f1[0].f1.size(1);
        domainSldProfiles[i].f1.set_size(sldProfiles[i].f1[0].f1.size(0),
          sldProfiles[i].f1[0].f1.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = sldProfiles[i].f1[0].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainSldProfiles[i].f1[i1 + domainSldProfiles[i].f1.size(0) * b_i] =
              sldProfiles[i].f1[0].f1[i1 + sldProfiles[i].f1[0].f1.size(0) * b_i];
          }
        }

        loop_ub = sldProfiles[i].f1[1].f1.size(1);
        domainSldProfiles[i + domainSldProfiles.size(0)].f1.set_size
          (sldProfiles[i].f1[1].f1.size(0), sldProfiles[i].f1[1].f1.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = sldProfiles[i].f1[1].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainSldProfiles[i + domainSldProfiles.size(0)].f1[i1 +
              domainSldProfiles[i + domainSldProfiles.size(0)].f1.size(0) * b_i]
              = sldProfiles[i].f1[1].f1[i1 + sldProfiles[i].f1[1].f1.size(0) *
              b_i];
          }
        }

        loop_ub = layerSlds[i].f1[0].f1.size(1);
        domainLayerSlds[i].f1.set_size(layerSlds[i].f1[0].f1.size(0),
          layerSlds[i].f1[0].f1.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = layerSlds[i].f1[0].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainLayerSlds[i].f1[i1 + domainLayerSlds[i].f1.size(0) * b_i] =
              layerSlds[i].f1[0].f1[i1 + layerSlds[i].f1[0].f1.size(0) * b_i];
          }
        }

        loop_ub = layerSlds[i].f1[1].f1.size(1);
        domainLayerSlds[i + domainLayerSlds.size(0)].f1.set_size(layerSlds[i]
          .f1[1].f1.size(0), layerSlds[i].f1[1].f1.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = layerSlds[i].f1[1].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainLayerSlds[i + domainLayerSlds.size(0)].f1[i1 +
              domainLayerSlds[i + domainLayerSlds.size(0)].f1.size(0) * b_i] =
              layerSlds[i].f1[1].f1[i1 + layerSlds[i].f1[1].f1.size(0) * b_i];
          }
        }

        loop_ub = resampledLayers[i].f1[0].f1.size(1);
        domainResampledLayers[i].f1.set_size(resampledLayers[i].f1[0].f1.size(0),
          resampledLayers[i].f1[0].f1.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = resampledLayers[i].f1[0].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainResampledLayers[i].f1[i1 + domainResampledLayers[i].f1.size(0)
              * b_i] = resampledLayers[i].f1[0].f1[i1 + resampledLayers[i].f1[0]
              .f1.size(0) * b_i];
          }
        }

        loop_ub = resampledLayers[i].f1[1].f1.size(1);
        domainResampledLayers[i + domainResampledLayers.size(0)].f1.set_size
          (resampledLayers[i].f1[1].f1.size(0), resampledLayers[i].f1[1].f1.size
           (1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = resampledLayers[i].f1[1].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainResampledLayers[i + domainResampledLayers.size(0)].f1[i1 +
              domainResampledLayers[i + domainResampledLayers.size(0)].f1.size(0)
              * b_i] = resampledLayers[i].f1[1].f1[i1 + resampledLayers[i].f1[1]
              .f1.size(0) * b_i];
          }
        }
      }
    }

    void b_customXY(const b_ProblemDefinition *problemStruct, const Controls
                    *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                    array<double, 1U> &scalefactors, ::coder::array<double, 1U>
                    &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::
                    array<double, 1U> &chis, ::coder::array<cell_wrap_7, 1U>
                    &reflectivity, ::coder::array<cell_wrap_7, 1U> &simulation, ::
                    coder::array<cell_wrap_8, 1U> &shiftedData, ::coder::array<
                    cell_wrap_8, 1U> &backgrounds, ::coder::array<cell_wrap_7,
                    1U> &resolutions, ::coder::array<cell_wrap_9, 2U>
                    &domainLayerSlds, ::coder::array<cell_wrap_9, 2U>
                    &domainSldProfiles, ::coder::array<cell_wrap_9, 2U>
                    &domainResampledLayers, ::coder::array<double, 1U>
                    &subRoughs)
    {
      ::coder::array<cell_wrap_1, 2U> data;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundActions;
      ::coder::array<cell_wrap_10, 2U> contrastBackgroundTypes;
      ::coder::array<cell_wrap_10, 2U> contrastResolutionTypes;
      ::coder::array<cell_wrap_10, 2U> customFiles;
      ::coder::array<cell_wrap_2, 2U> dataLimits;
      ::coder::array<cell_wrap_2, 2U> repeatLayers;
      ::coder::array<cell_wrap_2, 2U> simLimits;
      ::coder::array<cell_wrap_33, 2U> r;
      ::coder::array<cell_wrap_47, 2U> contrastBackgroundIndices;
      ::coder::array<cell_wrap_64, 1U> layerSlds;
      ::coder::array<cell_wrap_64, 1U> resampledLayers;
      ::coder::array<cell_wrap_64, 1U> sldProfiles;
      ::coder::array<cell_wrap_9, 2U> a__4;
      ::coder::array<cell_wrap_9, 2U> a__5;
      ::coder::array<cell_wrap_9, 2U> a__6;
      ::coder::array<cell_wrap_9, 2U> contrastResolutionIndices;
      ::coder::array<cell_wrap_9, 2U> inputSldProfiles;
      ::coder::array<cell_wrap_9, 1U> inputSldProfiles1;
      ::coder::array<cell_wrap_9, 1U> inputSldProfiles2;
      ::coder::array<double, 2U> a__3;
      ::coder::array<double, 2U> backgroundParamArray;
      ::coder::array<double, 2U> bulkInArray;
      ::coder::array<double, 2U> bulkOutArray;
      ::coder::array<double, 2U> cCustFiles;
      ::coder::array<double, 2U> contrastBulkInIndices;
      ::coder::array<double, 2U> contrastBulkOutIndices;
      ::coder::array<double, 2U> contrastDomainRatioIndices;
      ::coder::array<double, 2U> contrastQzshiftIndices;
      ::coder::array<double, 2U> contrastScalefactorIndices;
      ::coder::array<double, 2U> dataPresent;
      ::coder::array<double, 2U> domainRatioArray;
      ::coder::array<double, 2U> params;
      ::coder::array<double, 2U> r1;
      ::coder::array<double, 2U> r2;
      ::coder::array<double, 2U> resolutionParamArray;
      ::coder::array<double, 2U> scalefactorArray;
      double dv3[2];
      double dv4[2];
      double dv5[2];
      double a__2;
      double d;
      double d1;
      double d2;
      double d3;
      double nParams;
      double numberOfContrasts;
      double resampleMinAngle;
      double resampleNPoints;
      int a__1_size[2];
      int iv3[2];
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int iv7[2];
      int b_i;
      int b_loop_ub;
      int c_loop_ub;
      int i3;
      int i4;
      int loop_ub;
      int unnamed_idx_0;
      int unnamed_idx_0_tmp;
      int unnamed_idx_0_tmp_tmp_tmp;
      char a__1_data[10000];
      boolean_T useImaginary;

      //  Extract parameters from problemStruct
      numberOfContrasts = extractProblemParams(problemStruct, a__1_data,
        a__1_size, contrastBackgroundIndices, contrastQzshiftIndices,
        contrastScalefactorIndices, contrastBulkInIndices,
        contrastBulkOutIndices, contrastResolutionIndices,
        contrastDomainRatioIndices, backgroundParamArray, scalefactorArray,
        bulkInArray, bulkOutArray, resolutionParamArray, domainRatioArray,
        dataPresent, params, a__3, contrastBackgroundTypes,
        contrastBackgroundActions, contrastResolutionTypes, cCustFiles,
        repeatLayers, data, dataLimits, simLimits, a__4, a__5, customFiles, a__6,
        nParams, a__2, useImaginary);
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      // Pre-Allocation...
      unnamed_idx_0_tmp_tmp_tmp = static_cast<int>(numberOfContrasts);
      unnamed_idx_0_tmp = static_cast<int>(numberOfContrasts);
      unnamed_idx_0 = static_cast<int>(numberOfContrasts);
      inputSldProfiles1.set_size(unnamed_idx_0_tmp_tmp_tmp);
      for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
        inputSldProfiles1[i].f1.set_size(2, 1);
        inputSldProfiles1[i].f1[0] = 1.0;
        inputSldProfiles1[i].f1[1] = 1.0;
      }

      inputSldProfiles2.set_size(unnamed_idx_0_tmp_tmp_tmp);
      for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
        inputSldProfiles2[i].f1.set_size(2, 1);
        inputSldProfiles2[i].f1[0] = 1.0;
        inputSldProfiles2[i].f1[1] = 1.0;
      }

      customXY::processCustomFunction(contrastBulkInIndices,
        contrastBulkOutIndices, bulkInArray, bulkOutArray, cCustFiles,
        numberOfContrasts, customFiles, params, r, subRoughs);
      cast(r, inputSldProfiles);
      b_i = inputSldProfiles.size(0);
      for (int i{0}; i < b_i; i++) {
        loop_ub = inputSldProfiles[i].f1.size(1);
        inputSldProfiles1[i].f1.set_size(inputSldProfiles[i].f1.size(0),
          inputSldProfiles[i].f1.size(1));
        for (int i1{0}; i1 < loop_ub; i1++) {
          b_loop_ub = inputSldProfiles[i].f1.size(0);
          for (int i2{0}; i2 < b_loop_ub; i2++) {
            inputSldProfiles1[i].f1[i2 + inputSldProfiles1[i].f1.size(0) * i1] =
              inputSldProfiles[i].f1[i2 + inputSldProfiles[i].f1.size(0) * i1];
          }
        }

        loop_ub = inputSldProfiles[i + inputSldProfiles.size(0)].f1.size(1);
        inputSldProfiles2[i].f1.set_size(inputSldProfiles[i +
          inputSldProfiles.size(0)].f1.size(0), inputSldProfiles[i +
          inputSldProfiles.size(0)].f1.size(1));
        for (int i1{0}; i1 < loop_ub; i1++) {
          b_loop_ub = inputSldProfiles[i + inputSldProfiles.size(0)].f1.size(0);
          for (int i2{0}; i2 < b_loop_ub; i2++) {
            inputSldProfiles2[i].f1[i2 + inputSldProfiles2[i].f1.size(0) * i1] =
              inputSldProfiles[i + inputSldProfiles.size(0)].f1[i2 +
              inputSldProfiles[i + inputSldProfiles.size(0)].f1.size(0) * i1];
          }
        }
      }

      if (coder::internal::n_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp_tmp);
        resolutions.set_size(unnamed_idx_0_tmp_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp_tmp);
        unnamed_idx_0_tmp_tmp_tmp = static_cast<int>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r1,d,d1,d2,d3,iv3,iv4,dv3,dv4,dv5,iv5,iv6,iv7,c_loop_ub,i3,i4)

        for (int c_i = 0; c_i <= unnamed_idx_0_tmp_tmp_tmp; c_i++) {
          iv3[0] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[0];
          iv3[1] = (*(int (*)[2])contrastBackgroundIndices[c_i].f1.size())[1];
          iv4[0] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[0];
          iv4[1] = (*(int (*)[2])contrastResolutionIndices[c_i].f1.size())[1];
          dv3[0] = dataLimits[c_i].f1[0];
          dv3[1] = dataLimits[c_i].f1[1];
          dv4[0] = simLimits[c_i].f1[0];
          dv4[1] = simLimits[c_i].f1[1];
          dv5[0] = repeatLayers[c_i].f1[0];
          dv5[1] = repeatLayers[c_i].f1[1];
          iv5[0] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[0];
          iv5[1] = (*(int (*)[2])contrastBackgroundTypes[c_i].f1.size())[1];
          iv6[0] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[0];
          iv6[1] = (*(int (*)[2])contrastBackgroundActions[c_i].f1.size())[1];
          iv7[0] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[0];
          iv7[1] = (*(int (*)[2])contrastResolutionTypes[c_i].f1.size())[1];
          c_contrastCalculation((const double *)contrastBackgroundIndices[c_i].
                                f1.data(), iv3, contrastScalefactorIndices[c_i],
                                contrastBulkInIndices[c_i],
                                contrastBulkOutIndices[c_i], (const double *)
                                contrastResolutionIndices[c_i].f1.data(), iv4,
                                contrastDomainRatioIndices[c_i],
                                backgroundParamArray, scalefactorArray,
                                bulkInArray, bulkOutArray, resolutionParamArray,
                                domainRatioArray, dataPresent[c_i], data[c_i].f1,
                                dv3, dv4, dv5, (const char *)
                                contrastBackgroundTypes[c_i].f1.data(), iv5, (
            const char *)contrastBackgroundActions[c_i].f1.data(), iv6, (const
            char *)contrastResolutionTypes[c_i].f1.data(), iv7, customFiles,
                                nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, subRoughs[c_i],
                                inputSldProfiles1[c_i].f1, inputSldProfiles2[c_i]
                                .f1, reflectivity[c_i].f1, simulation[c_i].f1,
                                r1, backgrounds[c_i].f1, resolutions[c_i].f1,
                                layerSlds[c_i].f1, sldProfiles[c_i].f1,
                                resampledLayers[c_i].f1, d3, d2, d1, d);
          c_loop_ub = r1.size(0);
          shiftedData[c_i].f1.set_size(r1.size(0), 3);
          for (i3 = 0; i3 < 3; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r1[i4
                + r1.size(0) * i3];
            }
          }

          qzshifts[c_i] = 0.0;
          scalefactors[c_i] = d3;
          bulkIns[c_i] = d2;
          bulkOuts[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp_tmp);
        resolutions.set_size(unnamed_idx_0_tmp_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp_tmp);
        for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
          double b_dv[2];
          double b_dv1[2];
          double dv2[2];
          double d4;
          double d5;
          double d6;
          double d7;
          int iv[2];
          int iv1[2];
          int iv2[2];
          a__1_size[0] = (*(int (*)[2])contrastBackgroundIndices[i].f1.size())[0];
          a__1_size[1] = (*(int (*)[2])contrastBackgroundIndices[i].f1.size())[1];
          iv[0] = (*(int (*)[2])contrastResolutionIndices[i].f1.size())[0];
          iv[1] = (*(int (*)[2])contrastResolutionIndices[i].f1.size())[1];
          b_dv[0] = dataLimits[i].f1[0];
          b_dv[1] = dataLimits[i].f1[1];
          b_dv1[0] = simLimits[i].f1[0];
          b_dv1[1] = simLimits[i].f1[1];
          dv2[0] = repeatLayers[i].f1[0];
          dv2[1] = repeatLayers[i].f1[1];
          iv1[0] = (*(int (*)[2])contrastBackgroundActions[i].f1.size())[0];
          iv1[1] = (*(int (*)[2])contrastBackgroundActions[i].f1.size())[1];
          iv2[0] = (*(int (*)[2])contrastResolutionTypes[i].f1.size())[0];
          iv2[1] = (*(int (*)[2])contrastResolutionTypes[i].f1.size())[1];
          d_contrastCalculation((const double *)contrastBackgroundIndices[i].
                                f1.data(), a__1_size,
                                contrastScalefactorIndices[i],
                                contrastBulkInIndices[i],
                                contrastBulkOutIndices[i], (const double *)
                                contrastResolutionIndices[i].f1.data(), iv,
                                contrastDomainRatioIndices[i],
                                backgroundParamArray, scalefactorArray,
                                bulkInArray, bulkOutArray, resolutionParamArray,
                                domainRatioArray, dataPresent[i], data[i].f1,
                                b_dv, b_dv1, dv2, contrastBackgroundTypes, (
            const char *)contrastBackgroundActions[i].f1.data(), iv1, (const
            char *)contrastResolutionTypes[i].f1.data(), iv2, customFiles,
                                nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, subRoughs[i],
                                inputSldProfiles1[i].f1, inputSldProfiles2[i].f1,
                                reflectivity[i].f1, simulation[i].f1, r2,
                                backgrounds[i].f1, resolutions[i].f1,
                                layerSlds[i].f1, sldProfiles[i].f1,
                                resampledLayers[i].f1, d4, d5, d6, d7);
          chis[i] = d7;
          bulkOuts[i] = d6;
          bulkIns[i] = d5;
          scalefactors[i] = d4;
          loop_ub = r2.size(0);
          shiftedData[i].f1.set_size(r2.size(0), 3);
          for (b_i = 0; b_i < 3; b_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * b_i] = r2[i1 +
                r2.size(0) * b_i];
            }
          }

          qzshifts[i] = 0.0;
        }
      }

      domainSldProfiles.set_size(unnamed_idx_0, 2);
      domainLayerSlds.set_size(unnamed_idx_0, 2);
      domainResampledLayers.set_size(unnamed_idx_0, 2);
      for (int i{0}; i < unnamed_idx_0_tmp; i++) {
        loop_ub = sldProfiles[i].f1[0].f1.size(1);
        domainSldProfiles[i].f1.set_size(sldProfiles[i].f1[0].f1.size(0),
          sldProfiles[i].f1[0].f1.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = sldProfiles[i].f1[0].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainSldProfiles[i].f1[i1 + domainSldProfiles[i].f1.size(0) * b_i] =
              sldProfiles[i].f1[0].f1[i1 + sldProfiles[i].f1[0].f1.size(0) * b_i];
          }
        }

        loop_ub = sldProfiles[i].f1[1].f1.size(1);
        domainSldProfiles[i + domainSldProfiles.size(0)].f1.set_size
          (sldProfiles[i].f1[1].f1.size(0), sldProfiles[i].f1[1].f1.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = sldProfiles[i].f1[1].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainSldProfiles[i + domainSldProfiles.size(0)].f1[i1 +
              domainSldProfiles[i + domainSldProfiles.size(0)].f1.size(0) * b_i]
              = sldProfiles[i].f1[1].f1[i1 + sldProfiles[i].f1[1].f1.size(0) *
              b_i];
          }
        }

        loop_ub = layerSlds[i].f1[0].f1.size(1);
        domainLayerSlds[i].f1.set_size(layerSlds[i].f1[0].f1.size(0),
          layerSlds[i].f1[0].f1.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = layerSlds[i].f1[0].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainLayerSlds[i].f1[i1 + domainLayerSlds[i].f1.size(0) * b_i] =
              layerSlds[i].f1[0].f1[i1 + layerSlds[i].f1[0].f1.size(0) * b_i];
          }
        }

        loop_ub = layerSlds[i].f1[1].f1.size(1);
        domainLayerSlds[i + domainLayerSlds.size(0)].f1.set_size(layerSlds[i]
          .f1[1].f1.size(0), layerSlds[i].f1[1].f1.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = layerSlds[i].f1[1].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainLayerSlds[i + domainLayerSlds.size(0)].f1[i1 +
              domainLayerSlds[i + domainLayerSlds.size(0)].f1.size(0) * b_i] =
              layerSlds[i].f1[1].f1[i1 + layerSlds[i].f1[1].f1.size(0) * b_i];
          }
        }

        loop_ub = resampledLayers[i].f1[0].f1.size(1);
        domainResampledLayers[i].f1.set_size(resampledLayers[i].f1[0].f1.size(0),
          resampledLayers[i].f1[0].f1.size(1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = resampledLayers[i].f1[0].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainResampledLayers[i].f1[i1 + domainResampledLayers[i].f1.size(0)
              * b_i] = resampledLayers[i].f1[0].f1[i1 + resampledLayers[i].f1[0]
              .f1.size(0) * b_i];
          }
        }

        loop_ub = resampledLayers[i].f1[1].f1.size(1);
        domainResampledLayers[i + domainResampledLayers.size(0)].f1.set_size
          (resampledLayers[i].f1[1].f1.size(0), resampledLayers[i].f1[1].f1.size
           (1));
        for (b_i = 0; b_i < loop_ub; b_i++) {
          b_loop_ub = resampledLayers[i].f1[1].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainResampledLayers[i + domainResampledLayers.size(0)].f1[i1 +
              domainResampledLayers[i + domainResampledLayers.size(0)].f1.size(0)
              * b_i] = resampledLayers[i].f1[1].f1[i1 + resampledLayers[i].f1[1]
              .f1.size(0) * b_i];
          }
        }
      }
    }
  }
}

// End of code generation (customXY1.cpp)
