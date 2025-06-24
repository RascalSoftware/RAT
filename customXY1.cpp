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
#include "makeSimulationRange.h"
#include "nullAssignment.h"
#include "processCustomFunction1.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftData.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "omp.h"

// Function Declarations
namespace RAT
{
  namespace domainsTF
  {
    static double c_contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double scalefactorIndex, double
      bulkInIndex, double bulkOutIndex, const double resolutionParamIndex_data[],
      const int resolutionParamIndex_size[2], double domainRatioIndex, const ::
      coder::array<double, 2U> &backgroundParamValues, const ::coder::array<
      double, 2U> &scalefactorValues, const ::coder::array<double, 2U>
      &bulkInValues, const ::coder::array<double, 2U> &bulkOutValues, const ::
      coder::array<double, 2U> &resolutionParamValues, const ::coder::array<
      double, 2U> &domainRatioValues, double dataPresent, const ::coder::array<
      double, 2U> &data, const double dataLimits[2], const double
      simulationLimits[2], const ::coder::array<cell_wrap_10, 2U>
      &backgroundType, const char backgroundAction_data[], const int
      backgroundAction_size[2], const char resolutionType_data[], const int
      resolutionType_size[2], const ::coder::array<cell_wrap_10, 2U>
      &customFiles, double nParams, const char parallel_data[], const int
      parallel_size[2], double numSimulationPoints, double resampleMinAngle,
      double resampleNPoints, double roughness, const ::coder::array<double, 2U>
      &sldProfile1, const ::coder::array<double, 2U> &sldProfile2, ::coder::
      array<double, 2U> &reflectivity, ::coder::array<double, 2U> &simulation, ::
      coder::array<double, 2U> &shiftedData, ::coder::array<double, 2U>
      &background, ::coder::array<double, 2U> &resolution, cell_wrap_9
      sldProfile[2], cell_wrap_64 layers[2], cell_wrap_64 resampledLayers[2],
      double &scalefactor, double &bulkIn, double &bulkOut, double &chi);
    static double c_contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double scalefactorIndex, double
      bulkInIndex, double bulkOutIndex, const double resolutionParamIndex_data[],
      const int resolutionParamIndex_size[2], double domainRatioIndex, const ::
      coder::array<double, 2U> &backgroundParamValues, const ::coder::array<
      double, 2U> &scalefactorValues, const ::coder::array<double, 2U>
      &bulkInValues, const ::coder::array<double, 2U> &bulkOutValues, const ::
      coder::array<double, 2U> &resolutionParamValues, const ::coder::array<
      double, 2U> &domainRatioValues, double dataPresent, const ::coder::array<
      double, 2U> &data, const double dataLimits[2], const double
      simulationLimits[2], const char backgroundType_data[], const int
      backgroundType_size[2], const char backgroundAction_data[], const int
      backgroundAction_size[2], const char resolutionType_data[], const int
      resolutionType_size[2], const ::coder::array<cell_wrap_10, 2U>
      &customFiles, double nParams, const char parallel_data[], const int
      parallel_size[2], double numSimulationPoints, double resampleMinAngle,
      double resampleNPoints, double roughness, const ::coder::array<double, 2U>
      &sldProfile1, const ::coder::array<double, 2U> &sldProfile2, ::coder::
      array<double, 2U> &reflectivity, ::coder::array<double, 2U> &simulation, ::
      coder::array<double, 2U> &shiftedData, ::coder::array<double, 2U>
      &background, ::coder::array<double, 2U> &resolution, cell_wrap_9
      sldProfile[2], cell_wrap_64 layers[2], cell_wrap_64 resampledLayers[2],
      double &scalefactor, double &bulkIn, double &bulkOut, double &chi);
  }
}

// Function Definitions
namespace RAT
{
  namespace domainsTF
  {
    static double c_contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double scalefactorIndex, double
      bulkInIndex, double bulkOutIndex, const double resolutionParamIndex_data[],
      const int resolutionParamIndex_size[2], double domainRatioIndex, const ::
      coder::array<double, 2U> &backgroundParamValues, const ::coder::array<
      double, 2U> &scalefactorValues, const ::coder::array<double, 2U>
      &bulkInValues, const ::coder::array<double, 2U> &bulkOutValues, const ::
      coder::array<double, 2U> &resolutionParamValues, const ::coder::array<
      double, 2U> &domainRatioValues, double dataPresent, const ::coder::array<
      double, 2U> &data, const double dataLimits[2], const double
      simulationLimits[2], const ::coder::array<cell_wrap_10, 2U>
      &backgroundType, const char backgroundAction_data[], const int
      backgroundAction_size[2], const char resolutionType_data[], const int
      resolutionType_size[2], const ::coder::array<cell_wrap_10, 2U>
      &customFiles, double nParams, const char parallel_data[], const int
      parallel_size[2], double numSimulationPoints, double resampleMinAngle,
      double resampleNPoints, double roughness, const ::coder::array<double, 2U>
      &sldProfile1, const ::coder::array<double, 2U> &sldProfile2, ::coder::
      array<double, 2U> &reflectivity, ::coder::array<double, 2U> &simulation, ::
      coder::array<double, 2U> &shiftedData, ::coder::array<double, 2U>
      &background, ::coder::array<double, 2U> &resolution, cell_wrap_9
      sldProfile[2], cell_wrap_64 layers[2], cell_wrap_64 resampledLayers[2],
      double &scalefactor, double &bulkIn, double &bulkOut, double &chi)
    {
      ::coder::array<double, 2U> b_data;
      ::coder::array<double, 2U> b_reflectivity1;
      ::coder::array<double, 2U> b_shiftedData;
      ::coder::array<double, 2U> b_sldProfile1;
      ::coder::array<double, 2U> c_shiftedData;
      ::coder::array<double, 2U> c_sldProfile1;
      ::coder::array<double, 2U> reflectivity1;
      ::coder::array<double, 2U> reflectivity2;
      ::coder::array<double, 2U> simulation1;
      ::coder::array<double, 2U> simulation2;
      ::coder::array<double, 1U> simulationXData;
      cell_wrap_64 r;
      cell_wrap_64 r1;
      cell_wrap_9 r2;
      cell_wrap_9 r3;
      double dataIndices[2];
      double domainRatioValues_tmp;
      int b_loop_ub;
      int loop_ub;

      //  Get the domain ratio for this contrast
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(scalefactorIndex, bulkInIndex, bulkOutIndex, scalefactorValues,
               bulkInValues, bulkOutValues, scalefactor, bulkIn, bulkOut);

      //  Resample the sld profiles
      b_sldProfile1.set_size(sldProfile1.size(0), 2);
      c_sldProfile1.set_size(sldProfile1.size(0), 2);
      loop_ub = sldProfile1.size(0);
      for (int i{0}; i < 2; i++) {
        for (int i1{0}; i1 < loop_ub; i1++) {
          b_sldProfile1[i1 + b_sldProfile1.size(0) * i] = sldProfile1[i1 +
            sldProfile1.size(0) * i];
          c_sldProfile1[i1 + c_sldProfile1.size(0) * i] = sldProfile1[i1 +
            sldProfile1.size(0) * (i << 1)];
        }
      }

      resampleLayers(b_sldProfile1, c_sldProfile1, resampleMinAngle,
                     resampleNPoints, r.f1);
      b_sldProfile1.set_size(sldProfile2.size(0), 2);
      c_sldProfile1.set_size(sldProfile2.size(0), 2);
      loop_ub = sldProfile2.size(0);
      for (int i{0}; i < 2; i++) {
        for (int i1{0}; i1 < loop_ub; i1++) {
          b_sldProfile1[i1 + b_sldProfile1.size(0) * i] = sldProfile2[i1 +
            sldProfile2.size(0) * i];
          c_sldProfile1[i1 + c_sldProfile1.size(0) * i] = sldProfile2[i1 +
            sldProfile2.size(0) * (i << 1)];
        }
      }

      resampleLayers(b_sldProfile1, c_sldProfile1, resampleMinAngle,
                     resampleNPoints, r1.f1);
      layers[0] = r;
      layers[1] = r1;
      resampledLayers[0] = r;
      resampledLayers[1] = r1;
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

      shiftData(scalefactor, dataPresent, b_data, dataLimits, simulationLimits,
                numSimulationPoints, b_shiftedData);
      makeSimulationRange(b_shiftedData, simulationLimits, simulationXData,
                          dataIndices);
      constructBackground(backgroundType, backgroundParamIndex_data,
                          backgroundParamIndex_size, b_shiftedData, customFiles,
                          backgroundParamValues, simulationXData, dataIndices,
                          background);
      constructResolution(resolutionType_data, resolutionType_size,
                          resolutionParamIndex_data, resolutionParamIndex_size,
                          b_shiftedData, resolutionParamValues, simulationXData,
                          dataIndices, resolution);
      callReflectivity(bulkIn, bulkOut, simulationXData, dataIndices, r.f1,
                       roughness, resolution, parallel_data, parallel_size,
                       reflectivity1, simulation1);
      callReflectivity(bulkIn, bulkOut, simulationXData, dataIndices, r1.f1,
                       roughness, resolution, parallel_data, parallel_size,
                       reflectivity2, simulation2);
      c_shiftedData.set_size(b_shiftedData.size(0), 6);
      loop_ub = b_shiftedData.size(0) - 1;
      for (int i{0}; i < 6; i++) {
        for (int i1{0}; i1 <= loop_ub; i1++) {
          c_shiftedData[i1 + c_shiftedData.size(0) * i] = b_shiftedData[i1 +
            b_shiftedData.size(0) * i];
        }
      }

      applyBackgroundCorrection(reflectivity1, simulation1, c_shiftedData,
        background, backgroundAction_data, backgroundAction_size,
        b_reflectivity1);
      applyBackgroundCorrection(reflectivity2, simulation2, b_shiftedData,
        background, backgroundAction_data, backgroundAction_size, shiftedData);

      //  Calculate the average reflectivities
      //  Calculates the averaged reflectivity for domains samples (incoherent
      //  sum)
      if (reflectivity1.size(0) == reflectivity2.size(0)) {
        domainRatioValues_tmp = domainRatioValues[static_cast<int>
          (domainRatioIndex) - 1];
        reflectivity.set_size(reflectivity1.size(0), 2);
        loop_ub = reflectivity1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          reflectivity[i] = reflectivity1[i];
          reflectivity[i + reflectivity.size(0)] = domainRatioValues_tmp *
            reflectivity1[i + reflectivity1.size(0)] + (1.0 -
            domainRatioValues_tmp) * reflectivity2[i + reflectivity2.size(0)];
        }
      } else {
        binary_expand_op(reflectivity, reflectivity1, domainRatioValues,
                         domainRatioIndex, reflectivity2);
      }

      if (simulation1.size(0) == simulation2.size(0)) {
        domainRatioValues_tmp = domainRatioValues[static_cast<int>
          (domainRatioIndex) - 1];
        simulation.set_size(simulation1.size(0), 2);
        loop_ub = simulation1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          simulation[i] = simulation1[i];
          simulation[i + simulation.size(0)] = domainRatioValues_tmp *
            simulation1[i + simulation1.size(0)] + (1.0 - domainRatioValues_tmp)
            * simulation2[i + simulation2.size(0)];
        }
      } else {
        binary_expand_op(simulation, simulation1, domainRatioValues,
                         domainRatioIndex, simulation2);
      }

      chi = chiSquared(shiftedData, reflectivity, nParams);
      return 0.0;
    }

    static double c_contrastCalculation(const double backgroundParamIndex_data[],
      const int backgroundParamIndex_size[2], double scalefactorIndex, double
      bulkInIndex, double bulkOutIndex, const double resolutionParamIndex_data[],
      const int resolutionParamIndex_size[2], double domainRatioIndex, const ::
      coder::array<double, 2U> &backgroundParamValues, const ::coder::array<
      double, 2U> &scalefactorValues, const ::coder::array<double, 2U>
      &bulkInValues, const ::coder::array<double, 2U> &bulkOutValues, const ::
      coder::array<double, 2U> &resolutionParamValues, const ::coder::array<
      double, 2U> &domainRatioValues, double dataPresent, const ::coder::array<
      double, 2U> &data, const double dataLimits[2], const double
      simulationLimits[2], const char backgroundType_data[], const int
      backgroundType_size[2], const char backgroundAction_data[], const int
      backgroundAction_size[2], const char resolutionType_data[], const int
      resolutionType_size[2], const ::coder::array<cell_wrap_10, 2U>
      &customFiles, double nParams, const char parallel_data[], const int
      parallel_size[2], double numSimulationPoints, double resampleMinAngle,
      double resampleNPoints, double roughness, const ::coder::array<double, 2U>
      &sldProfile1, const ::coder::array<double, 2U> &sldProfile2, ::coder::
      array<double, 2U> &reflectivity, ::coder::array<double, 2U> &simulation, ::
      coder::array<double, 2U> &shiftedData, ::coder::array<double, 2U>
      &background, ::coder::array<double, 2U> &resolution, cell_wrap_9
      sldProfile[2], cell_wrap_64 layers[2], cell_wrap_64 resampledLayers[2],
      double &scalefactor, double &bulkIn, double &bulkOut, double &chi)
    {
      ::coder::array<double, 2U> b_data;
      ::coder::array<double, 2U> b_reflectivity1;
      ::coder::array<double, 2U> b_shiftedData;
      ::coder::array<double, 2U> b_sldProfile1;
      ::coder::array<double, 2U> c_shiftedData;
      ::coder::array<double, 2U> c_sldProfile1;
      ::coder::array<double, 2U> reflectivity1;
      ::coder::array<double, 2U> reflectivity2;
      ::coder::array<double, 2U> simulation1;
      ::coder::array<double, 2U> simulation2;
      ::coder::array<double, 1U> simulationXData;
      cell_wrap_64 r;
      cell_wrap_64 r1;
      cell_wrap_9 r2;
      cell_wrap_9 r3;
      double dataIndices[2];
      double domainRatioValues_tmp;
      int b_loop_ub;
      int loop_ub;

      //  Get the domain ratio for this contrast
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(scalefactorIndex, bulkInIndex, bulkOutIndex, scalefactorValues,
               bulkInValues, bulkOutValues, scalefactor, bulkIn, bulkOut);

      //  Resample the sld profiles
      b_sldProfile1.set_size(sldProfile1.size(0), 2);
      c_sldProfile1.set_size(sldProfile1.size(0), 2);
      loop_ub = sldProfile1.size(0);
      for (int i{0}; i < 2; i++) {
        for (int i1{0}; i1 < loop_ub; i1++) {
          b_sldProfile1[i1 + b_sldProfile1.size(0) * i] = sldProfile1[i1 +
            sldProfile1.size(0) * i];
          c_sldProfile1[i1 + c_sldProfile1.size(0) * i] = sldProfile1[i1 +
            sldProfile1.size(0) * (i << 1)];
        }
      }

      resampleLayers(b_sldProfile1, c_sldProfile1, resampleMinAngle,
                     resampleNPoints, r.f1);
      b_sldProfile1.set_size(sldProfile2.size(0), 2);
      c_sldProfile1.set_size(sldProfile2.size(0), 2);
      loop_ub = sldProfile2.size(0);
      for (int i{0}; i < 2; i++) {
        for (int i1{0}; i1 < loop_ub; i1++) {
          b_sldProfile1[i1 + b_sldProfile1.size(0) * i] = sldProfile2[i1 +
            sldProfile2.size(0) * i];
          c_sldProfile1[i1 + c_sldProfile1.size(0) * i] = sldProfile2[i1 +
            sldProfile2.size(0) * (i << 1)];
        }
      }

      resampleLayers(b_sldProfile1, c_sldProfile1, resampleMinAngle,
                     resampleNPoints, r1.f1);
      layers[0] = r;
      layers[1] = r1;
      resampledLayers[0] = r;
      resampledLayers[1] = r1;
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

      shiftData(scalefactor, dataPresent, b_data, dataLimits, simulationLimits,
                numSimulationPoints, b_shiftedData);
      makeSimulationRange(b_shiftedData, simulationLimits, simulationXData,
                          dataIndices);
      constructBackground(backgroundType_data, backgroundType_size,
                          backgroundParamIndex_data, backgroundParamIndex_size,
                          b_shiftedData, customFiles, backgroundParamValues,
                          simulationXData, dataIndices, background);
      constructResolution(resolutionType_data, resolutionType_size,
                          resolutionParamIndex_data, resolutionParamIndex_size,
                          b_shiftedData, resolutionParamValues, simulationXData,
                          dataIndices, resolution);
      callReflectivity(bulkIn, bulkOut, simulationXData, dataIndices, r.f1,
                       roughness, resolution, parallel_data, parallel_size,
                       reflectivity1, simulation1);
      callReflectivity(bulkIn, bulkOut, simulationXData, dataIndices, r1.f1,
                       roughness, resolution, parallel_data, parallel_size,
                       reflectivity2, simulation2);
      c_shiftedData.set_size(b_shiftedData.size(0), 6);
      loop_ub = b_shiftedData.size(0) - 1;
      for (int i{0}; i < 6; i++) {
        for (int i1{0}; i1 <= loop_ub; i1++) {
          c_shiftedData[i1 + c_shiftedData.size(0) * i] = b_shiftedData[i1 +
            b_shiftedData.size(0) * i];
        }
      }

      applyBackgroundCorrection(reflectivity1, simulation1, c_shiftedData,
        background, backgroundAction_data, backgroundAction_size,
        b_reflectivity1);
      applyBackgroundCorrection(reflectivity2, simulation2, b_shiftedData,
        background, backgroundAction_data, backgroundAction_size, shiftedData);

      //  Calculate the average reflectivities
      //  Calculates the averaged reflectivity for domains samples (incoherent
      //  sum)
      if (reflectivity1.size(0) == reflectivity2.size(0)) {
        domainRatioValues_tmp = domainRatioValues[static_cast<int>
          (domainRatioIndex) - 1];
        reflectivity.set_size(reflectivity1.size(0), 2);
        loop_ub = reflectivity1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          reflectivity[i] = reflectivity1[i];
          reflectivity[i + reflectivity.size(0)] = domainRatioValues_tmp *
            reflectivity1[i + reflectivity1.size(0)] + (1.0 -
            domainRatioValues_tmp) * reflectivity2[i + reflectivity2.size(0)];
        }
      } else {
        binary_expand_op(reflectivity, reflectivity1, domainRatioValues,
                         domainRatioIndex, reflectivity2);
      }

      if (simulation1.size(0) == simulation2.size(0)) {
        domainRatioValues_tmp = domainRatioValues[static_cast<int>
          (domainRatioIndex) - 1];
        simulation.set_size(simulation1.size(0), 2);
        loop_ub = simulation1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          simulation[i] = simulation1[i];
          simulation[i + simulation.size(0)] = domainRatioValues_tmp *
            simulation1[i + simulation1.size(0)] + (1.0 - domainRatioValues_tmp)
            * simulation2[i + simulation2.size(0)];
        }
      } else {
        binary_expand_op(simulation, simulation1, domainRatioValues,
                         domainRatioIndex, simulation2);
      }

      chi = chiSquared(shiftedData, reflectivity, nParams);
      return 0.0;
    }

    void customXY(const ProblemDefinition &problemStruct, const Controls
                  *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                  array<double, 1U> &scalefactors, ::coder::array<double, 1U>
                  &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::array<
                  double, 1U> &chis, ::coder::array<cell_wrap_7, 1U>
                  &reflectivity, ::coder::array<cell_wrap_7, 1U> &simulation, ::
                  coder::array<cell_wrap_8, 1U> &shiftedData, ::coder::array<
                  cell_wrap_8, 1U> &backgrounds, ::coder::array<cell_wrap_7, 1U>
                  &resolutions, ::coder::array<cell_wrap_9, 2U>
                  &domainSldProfiles, ::coder::array<cell_wrap_9, 2U>
                  &domainLayers, ::coder::array<cell_wrap_9, 2U>
                  &domainResampledLayers, ::coder::array<double, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_63, 1U> sldProfiles;
      ::coder::array<cell_wrap_65, 1U> layers;
      ::coder::array<cell_wrap_65, 1U> resampledLayers;
      ::coder::array<cell_wrap_9, 2U> slds;
      ::coder::array<cell_wrap_9, 1U> slds1;
      ::coder::array<cell_wrap_9, 1U> slds2;
      ::coder::array<double, 2U> r;
      double dv2[2];
      double dv3[2];
      double d;
      double d1;
      double d2;
      double d3;
      double numSimulationPoints;
      double resampleMinAngle;
      double resampleNPoints;
      int iv4[2];
      int iv5[2];
      int iv6[2];
      int iv7[2];
      int iv8[2];
      int b_i;
      int b_loop_ub;
      int loop_ub;
      int nParams;
      int ub_loop;
      int unnamed_idx_0_tmp_tmp_tmp;
      boolean_T useImaginary;

      //  Extract parameters from problemStruct
      //  qzshifts are not included as a parameter in RAT, so we set up dummy
      //  values for the reflectivity calculation
      nParams = problemStruct.params.size(1);
      useImaginary = problemStruct.useImaginary;
      numSimulationPoints = controls->numSimulationPoints;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      // Pre-Allocation
      unnamed_idx_0_tmp_tmp_tmp = static_cast<int>
        (problemStruct.numberOfContrasts);
      slds1.set_size(unnamed_idx_0_tmp_tmp_tmp);
      for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
        slds1[i].f1.set_size(2, 1);
        slds1[i].f1[0] = 1.0;
        slds1[i].f1[1] = 1.0;
      }

      slds2.set_size(unnamed_idx_0_tmp_tmp_tmp);
      for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
        slds2[i].f1.set_size(2, 1);
        slds2[i].f1[0] = 1.0;
        slds2[i].f1[1] = 1.0;
      }

      b_processCustomFunction(problemStruct.contrastBulkIns,
        problemStruct.contrastBulkOuts, problemStruct.bulkIns,
        problemStruct.bulkOuts, problemStruct.contrastCustomFiles,
        problemStruct.numberOfContrasts, problemStruct.customFiles,
        problemStruct.params, problemStruct.useImaginary, slds, subRoughs);
      b_i = slds.size(0);
      for (int i{0}; i < b_i; i++) {
        loop_ub = slds[i].f1.size(1);
        slds1[i].f1.set_size(slds[i].f1.size(0), slds[i].f1.size(1));
        for (int i1{0}; i1 < loop_ub; i1++) {
          b_loop_ub = slds[i].f1.size(0);
          for (ub_loop = 0; ub_loop < b_loop_ub; ub_loop++) {
            slds1[i].f1[ub_loop + slds1[i].f1.size(0) * i1] = slds[i].f1[ub_loop
              + slds[i].f1.size(0) * i1];
          }
        }

        loop_ub = slds[i + slds.size(0)].f1.size(1);
        slds2[i].f1.set_size(slds[i + slds.size(0)].f1.size(0), slds[i +
                             slds.size(0)].f1.size(1));
        for (int i1{0}; i1 < loop_ub; i1++) {
          b_loop_ub = slds[i + slds.size(0)].f1.size(0);
          for (ub_loop = 0; ub_loop < b_loop_ub; ub_loop++) {
            slds2[i].f1[ub_loop + slds2[i].f1.size(0) * i1] = slds[i + slds.size
              (0)].f1[ub_loop + slds[i + slds.size(0)].f1.size(0) * i1];
          }
        }
      }

      if (coder::internal::o_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        layers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp_tmp);
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
        ub_loop = unnamed_idx_0_tmp_tmp_tmp - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(d,d1,d2,d3,iv4,iv5,dv2,dv3,iv6,iv7,iv8)

        for (int c_i = 0; c_i <= ub_loop; c_i++) {
          iv4[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[0];
          iv4[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastBackgroundParams[c_i].f1)->size())[1];
          iv5[0] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[0];
          iv5[1] = (*(int (*)[2])((::coder::array<double, 2U> *)
                     &problemStruct.contrastResolutionParams[c_i].f1)->size())[1];
          dv2[0] = problemStruct.dataLimits[c_i].f1[0];
          dv2[1] = problemStruct.dataLimits[c_i].f1[1];
          dv3[0] = problemStruct.simulationLimits[c_i].f1[0];
          dv3[1] = problemStruct.simulationLimits[c_i].f1[1];
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
                                problemStruct.data[c_i].f1, dv2, dv3, (const
            char *)((::coder::array<char, 2U> *)
                    &problemStruct.contrastBackgroundTypes[c_i].f1)->data(), iv6,
                                (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastBackgroundActions[c_i].f1)->data(), iv7, (
            const char *)((::coder::array<char, 2U> *)
                          &problemStruct.contrastResolutionTypes[c_i].f1)->data(),
                                iv8, problemStruct.customFiles, static_cast<
                                double>(nParams), controls->parallel.data,
                                controls->parallel.size, numSimulationPoints,
                                resampleMinAngle, resampleNPoints, subRoughs[c_i],
                                slds1[c_i].f1, slds2[c_i].f1, reflectivity[c_i].
                                f1, simulation[c_i].f1, shiftedData[c_i].f1,
                                backgrounds[c_i].f1, resolutions[c_i].f1,
                                sldProfiles[c_i].f1, layers[c_i].f1,
                                resampledLayers[c_i].f1, d3, d2, d1, d);
          qzshifts[c_i] = 0.0;
          scalefactors[c_i] = d3;
          bulkIns[c_i] = d2;
          bulkOuts[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        layers.set_size(unnamed_idx_0_tmp_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp_tmp);
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
          iv2[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[i].f1)->size())[0];
          iv2[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastBackgroundActions[i].f1)->size())[1];
          iv3[0] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[i].f1)->size())[0];
          iv3[1] = (*(int (*)[2])((::coder::array<char, 2U> *)
                     &problemStruct.contrastResolutionTypes[i].f1)->size())[1];
          c_contrastCalculation((const double *)((::coder::array<double, 2U> *)
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
                                problemStruct.data[i].f1, b_dv, b_dv1,
                                problemStruct.contrastBackgroundTypes, (const
            char *)((::coder::array<char, 2U> *)
                    &problemStruct.contrastBackgroundActions[i].f1)->data(), iv2,
                                (const char *)((::coder::array<char, 2U> *)
            &problemStruct.contrastResolutionTypes[i].f1)->data(), iv3,
                                problemStruct.customFiles, static_cast<double>
                                (problemStruct.params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                numSimulationPoints, resampleMinAngle,
                                resampleNPoints, subRoughs[i], slds1[i].f1,
                                slds2[i].f1, reflectivity[i].f1, simulation[i].
                                f1, shiftedData[i].f1, backgrounds[i].f1,
                                resolutions[i].f1, sldProfiles[i].f1, layers[i].
                                f1, resampledLayers[i].f1, d4, d5, d6, d7);
          chis[i] = d7;
          bulkOuts[i] = d6;
          bulkIns[i] = d5;
          scalefactors[i] = d4;
          qzshifts[i] = 0.0;
        }
      }

      domainSldProfiles.set_size(unnamed_idx_0_tmp_tmp_tmp, 2);
      domainLayers.set_size(unnamed_idx_0_tmp_tmp_tmp, 2);
      domainResampledLayers.set_size(unnamed_idx_0_tmp_tmp_tmp, 2);
      for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
        int c_loop_ub;
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

        loop_ub = layers[i].f1[0].f1.size(0);
        domainLayers[i].f1.set_size(layers[i].f1[0].f1.size(0), 4);
        b_loop_ub = layers[i].f1[1].f1.size(0);
        domainLayers[i + domainLayers.size(0)].f1.set_size(layers[i].f1[1].
          f1.size(0), 4);
        ub_loop = resampledLayers[i].f1[0].f1.size(0);
        domainResampledLayers[i].f1.set_size(resampledLayers[i].f1[0].f1.size(0),
          4);
        c_loop_ub = resampledLayers[i].f1[1].f1.size(0);
        domainResampledLayers[i + domainResampledLayers.size(0)].f1.set_size
          (resampledLayers[i].f1[1].f1.size(0), 4);
        for (b_i = 0; b_i < 4; b_i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            domainLayers[i].f1[i1 + domainLayers[i].f1.size(0) * b_i] = layers[i]
              .f1[0].f1[i1 + layers[i].f1[0].f1.size(0) * b_i];
          }

          for (int i1{0}; i1 < b_loop_ub; i1++) {
            domainLayers[i + domainLayers.size(0)].f1[i1 + domainLayers[i +
              domainLayers.size(0)].f1.size(0) * b_i] = layers[i].f1[1].f1[i1 +
              layers[i].f1[1].f1.size(0) * b_i];
          }

          for (int i1{0}; i1 < ub_loop; i1++) {
            domainResampledLayers[i].f1[i1 + domainResampledLayers[i].f1.size(0)
              * b_i] = resampledLayers[i].f1[0].f1[i1 + resampledLayers[i].f1[0]
              .f1.size(0) * b_i];
          }

          for (int i1{0}; i1 < c_loop_ub; i1++) {
            domainResampledLayers[i + domainResampledLayers.size(0)].f1[i1 +
              domainResampledLayers[i + domainResampledLayers.size(0)].f1.size(0)
              * b_i] = resampledLayers[i].f1[1].f1[i1 + resampledLayers[i].f1[1]
              .f1.size(0) * b_i];
          }
        }
      }

      //  Remove dummy imaginary column if present
      if (!useImaginary) {
        for (int i{0}; i < unnamed_idx_0_tmp_tmp_tmp; i++) {
          coder::internal::nullAssignment(domainSldProfiles[i].f1);
          coder::internal::nullAssignment(domainSldProfiles[i +
            domainSldProfiles.size(0)].f1);
          coder::internal::nullAssignment(domainLayers[i].f1, r);
          domainLayers[i].f1.set_size(r.size(0), 3);
          loop_ub = r.size(0);
          for (b_i = 0; b_i < 3; b_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              domainLayers[i].f1[i1 + domainLayers[i].f1.size(0) * b_i] = r[i1 +
                r.size(0) * b_i];
            }
          }

          coder::internal::nullAssignment(domainLayers[i + domainLayers.size(0)]
            .f1);
          coder::internal::nullAssignment(domainResampledLayers[i].f1, r);
          domainResampledLayers[i].f1.set_size(r.size(0), 3);
          loop_ub = r.size(0);
          for (b_i = 0; b_i < 3; b_i++) {
            for (int i1{0}; i1 < loop_ub; i1++) {
              domainResampledLayers[i].f1[i1 + domainResampledLayers[i].f1.size
                (0) * b_i] = r[i1 + r.size(0) * b_i];
            }
          }

          coder::internal::nullAssignment(domainResampledLayers[i +
            domainResampledLayers.size(0)].f1);
        }
      }
    }
  }
}

// End of code generation (customXY1.cpp)
