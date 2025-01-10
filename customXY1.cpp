//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "chiSquared.h"
#include "constructBackground.h"
#include "extractProblemParams.h"
#include "processCustomFunction3.h"
#include "resampleLayers.h"
#include "resampleLayersReIm.h"
#include "rt_nonfinite.h"
#include "shiftData.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Declarations
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_34, 2U> &b, ::coder::array<
                   cell_wrap_10, 2U> &c);
  namespace domainsTF
  {
    static void c_contrastCalculation(const real_T backgroundParamIndex_data[],
      const int32_T backgroundParamIndex_size[2], real_T qzshiftIndex, real_T
      scalefactorIndex, real_T bulkInIndex, real_T bulkOutIndex, real_T
      resolutionParamIndex, real_T domainRatioIndex, const ::coder::array<real_T,
      2U> &backgroundParams, const ::coder::array<real_T, 2U> &qzshifts, const ::
      coder::array<real_T, 2U> &scalefactors, const ::coder::array<real_T, 2U>
      &bulkIns, const ::coder::array<real_T, 2U> &bulkOuts, const ::coder::array<
      real_T, 2U> &resolutionParams, const ::coder::array<real_T, 2U>
      &domainRatios, real_T dataPresent, const ::coder::array<real_T, 2U> &data,
      const real_T dataLimits[2], const real_T simLimits[2], const real_T
      repeatLayers[2], const char_T backgroundType_data[], const int32_T
      backgroundType_size[2], const char_T backgroundAction_data[], const
      int32_T backgroundAction_size[2], const ::coder::array<cell_wrap_7, 2U>
      &customFiles, real_T nParams, const char_T parallel_data[], const int32_T
      parallel_size[2], real_T resampleMinAngle, real_T resampleNPoints,
      boolean_T useImaginary, real_T roughness, const ::coder::array<real_T, 2U>
      &sldProfile1, const ::coder::array<real_T, 2U> &sldProfile2, real_T
      *qzshiftValue, real_T *scalefactorValue, real_T *bulkInValue, real_T
      *bulkOutValue, real_T *resolutionParamValue, real_T *chi, ::coder::array<
      real_T, 2U> &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::
      array<real_T, 2U> &shiftedData, ::coder::array<real_T, 2U> &background,
      cell_wrap_10 layerSld[2], cell_wrap_10 sldProfile[2], cell_wrap_10
      resampledLayer[2]);
    static void d_contrastCalculation(const real_T backgroundParamIndex_data[],
      const int32_T backgroundParamIndex_size[2], real_T qzshiftIndex, real_T
      scalefactorIndex, real_T bulkInIndex, real_T bulkOutIndex, real_T
      resolutionParamIndex, real_T domainRatioIndex, const ::coder::array<real_T,
      2U> &backgroundParams, const ::coder::array<real_T, 2U> &qzshifts, const ::
      coder::array<real_T, 2U> &scalefactors, const ::coder::array<real_T, 2U>
      &bulkIns, const ::coder::array<real_T, 2U> &bulkOuts, const ::coder::array<
      real_T, 2U> &resolutionParams, const ::coder::array<real_T, 2U>
      &domainRatios, real_T dataPresent, const ::coder::array<real_T, 2U> &data,
      const real_T dataLimits[2], const real_T simLimits[2], const real_T
      repeatLayers[2], const ::coder::array<cell_wrap_7, 2U> &backgroundType,
      const char_T backgroundAction_data[], const int32_T backgroundAction_size
      [2], const ::coder::array<cell_wrap_7, 2U> &customFiles, real_T nParams,
      const char_T parallel_data[], const int32_T parallel_size[2], real_T
      resampleMinAngle, real_T resampleNPoints, boolean_T useImaginary, real_T
      roughness, const ::coder::array<real_T, 2U> &sldProfile1, const ::coder::
      array<real_T, 2U> &sldProfile2, real_T *qzshiftValue, real_T
      *scalefactorValue, real_T *bulkInValue, real_T *bulkOutValue, real_T
      *resolutionParamValue, real_T *chi, ::coder::array<real_T, 2U>
      &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::array<
      real_T, 2U> &shiftedData, ::coder::array<real_T, 2U> &background,
      cell_wrap_10 layerSld[2], cell_wrap_10 sldProfile[2], cell_wrap_10
      resampledLayer[2]);
  }
}

// Function Definitions
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_34, 2U> &b, ::coder::array<
                   cell_wrap_10, 2U> &c)
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

  namespace domainsTF
  {
    static void c_contrastCalculation(const real_T backgroundParamIndex_data[],
      const int32_T backgroundParamIndex_size[2], real_T qzshiftIndex, real_T
      scalefactorIndex, real_T bulkInIndex, real_T bulkOutIndex, real_T
      resolutionParamIndex, real_T domainRatioIndex, const ::coder::array<real_T,
      2U> &backgroundParams, const ::coder::array<real_T, 2U> &qzshifts, const ::
      coder::array<real_T, 2U> &scalefactors, const ::coder::array<real_T, 2U>
      &bulkIns, const ::coder::array<real_T, 2U> &bulkOuts, const ::coder::array<
      real_T, 2U> &resolutionParams, const ::coder::array<real_T, 2U>
      &domainRatios, real_T dataPresent, const ::coder::array<real_T, 2U> &data,
      const real_T dataLimits[2], const real_T simLimits[2], const real_T
      repeatLayers[2], const char_T backgroundType_data[], const int32_T
      backgroundType_size[2], const char_T backgroundAction_data[], const
      int32_T backgroundAction_size[2], const ::coder::array<cell_wrap_7, 2U>
      &customFiles, real_T nParams, const char_T parallel_data[], const int32_T
      parallel_size[2], real_T resampleMinAngle, real_T resampleNPoints,
      boolean_T useImaginary, real_T roughness, const ::coder::array<real_T, 2U>
      &sldProfile1, const ::coder::array<real_T, 2U> &sldProfile2, real_T
      *qzshiftValue, real_T *scalefactorValue, real_T *bulkInValue, real_T
      *bulkOutValue, real_T *resolutionParamValue, real_T *chi, ::coder::array<
      real_T, 2U> &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::
      array<real_T, 2U> &shiftedData, ::coder::array<real_T, 2U> &background,
      cell_wrap_10 layerSld[2], cell_wrap_10 sldProfile[2], cell_wrap_10
      resampledLayer[2])
    {
      ::coder::array<real_T, 2U> b_data;
      ::coder::array<real_T, 2U> b_reflect1;
      ::coder::array<real_T, 2U> b_shiftedData;
      ::coder::array<real_T, 2U> b_sldProfile1;
      ::coder::array<real_T, 2U> c_sldProfile1;
      ::coder::array<real_T, 2U> r;
      ::coder::array<real_T, 2U> reflect1;
      ::coder::array<real_T, 2U> reflect2;
      ::coder::array<real_T, 2U> simul1;
      ::coder::array<real_T, 2U> simul2;
      cell_wrap_10 r1;
      cell_wrap_10 r2;
      cell_wrap_10 r3;
      cell_wrap_10 r4;
      cell_wrap_10 r5;
      cell_wrap_10 r6;
      real_T domainRatios_tmp;
      int32_T b_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T loop_ub;

      //  Get the domain ratio for this contrast
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(qzshiftIndex, scalefactorIndex, bulkInIndex, bulkOutIndex,
               resolutionParamIndex, qzshifts, scalefactors, bulkIns, bulkOuts,
               resolutionParams, qzshiftValue, scalefactorValue, bulkInValue,
               bulkOutValue, resolutionParamValue);

      //  Resample the sld profiles
      if (!useImaginary) {
        b_resampleLayers(sldProfile1, resampleMinAngle, resampleNPoints, r);
        r1.f1.set_size(r.size(0), 3);
        loop_ub = r.size(0);
        for (i = 0; i < 3; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            r1.f1[i1 + r1.f1.size(0) * i] = r[i1 + r.size(0) * i];
          }
        }

        b_resampleLayers(sldProfile2, resampleMinAngle, resampleNPoints, r);
        r2.f1.set_size(r.size(0), 3);
        loop_ub = r.size(0);
        for (i = 0; i < 3; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            r2.f1[i1 + r2.f1.size(0) * i] = r[i1 + r.size(0) * i];
          }
        }
      } else {
        loop_ub = sldProfile1.size(0);
        b_sldProfile1.set_size(sldProfile1.size(0), 2);
        for (i = 0; i < 2; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_sldProfile1[i1 + b_sldProfile1.size(0) * i] = sldProfile1[i1 +
              sldProfile1.size(0) * i];
          }
        }

        loop_ub = sldProfile1.size(0);
        b_loop_ub = sldProfile1.size(0);
        c_sldProfile1.set_size(sldProfile1.size(0), 2);
        for (i = 0; i < loop_ub; i++) {
          c_sldProfile1[i] = sldProfile1[i];
        }

        for (i = 0; i < b_loop_ub; i++) {
          c_sldProfile1[i + c_sldProfile1.size(0)] = sldProfile1[i +
            sldProfile1.size(0) * 2];
        }

        resampleLayersReIm(b_sldProfile1, c_sldProfile1, resampleMinAngle,
                           resampleNPoints, r);
        r1.f1.set_size(r.size(0), 4);
        loop_ub = r.size(0);
        for (i = 0; i < 4; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            r1.f1[i1 + r1.f1.size(0) * i] = r[i1 + r.size(0) * i];
          }
        }

        loop_ub = sldProfile2.size(0);
        b_sldProfile1.set_size(sldProfile2.size(0), 2);
        for (i = 0; i < 2; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_sldProfile1[i1 + b_sldProfile1.size(0) * i] = sldProfile2[i1 +
              sldProfile2.size(0) * i];
          }
        }

        loop_ub = sldProfile2.size(0);
        b_loop_ub = sldProfile2.size(0);
        c_sldProfile1.set_size(sldProfile2.size(0), 2);
        for (i = 0; i < loop_ub; i++) {
          c_sldProfile1[i] = sldProfile2[i];
        }

        for (i = 0; i < b_loop_ub; i++) {
          c_sldProfile1[i + c_sldProfile1.size(0)] = sldProfile2[i +
            sldProfile2.size(0) * 2];
        }

        resampleLayersReIm(b_sldProfile1, c_sldProfile1, resampleMinAngle,
                           resampleNPoints, r);
        r2.f1.set_size(r.size(0), 4);
        loop_ub = r.size(0);
        for (i = 0; i < 4; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            r2.f1[i1 + r2.f1.size(0) * i] = r[i1 + r.size(0) * i];
          }
        }
      }

      layerSld[0] = r1;
      layerSld[1] = r2;
      r3.f1.set_size(r1.f1.size(0), r1.f1.size(1));
      loop_ub = r1.f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = r1.f1.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          r3.f1[i1 + r3.f1.size(0) * i] = r1.f1[i1 + r1.f1.size(0) * i];
        }
      }

      r4.f1.set_size(r2.f1.size(0), r2.f1.size(1));
      loop_ub = r2.f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = r2.f1.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          r4.f1[i1 + r4.f1.size(0) * i] = r2.f1[i1 + r2.f1.size(0) * i];
        }
      }

      resampledLayer[0] = r3;
      resampledLayer[1] = r4;
      r5.f1.set_size(sldProfile1.size(0), sldProfile1.size(1));
      loop_ub = sldProfile1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = sldProfile1.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          r5.f1[i1 + r5.f1.size(0) * i] = sldProfile1[i1 + sldProfile1.size(0) *
            i];
        }
      }

      r6.f1.set_size(sldProfile2.size(0), sldProfile2.size(1));
      loop_ub = sldProfile2.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = sldProfile2.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          r6.f1[i1 + r6.f1.size(0) * i] = sldProfile2[i1 + sldProfile2.size(0) *
            i];
        }
      }

      sldProfile[0] = r5;
      sldProfile[1] = r6;
      b_data.set_size(data.size(0), 6);
      loop_ub = data.size(0) - 1;
      for (i = 0; i < 6; i++) {
        for (i1 = 0; i1 <= loop_ub; i1++) {
          b_data[i1 + b_data.size(0) * i] = data[i1 + data.size(0) * i];
        }
      }

      shiftData(*scalefactorValue, *qzshiftValue, dataPresent, b_data,
                dataLimits, simLimits, b_shiftedData);
      constructBackground(backgroundType_data, backgroundType_size,
                          backgroundParamIndex_data, backgroundParamIndex_size,
                          b_shiftedData, customFiles, backgroundParams,
                          simLimits, background);
      callReflectivity(*bulkInValue, *bulkOutValue, simLimits, repeatLayers,
                       b_shiftedData, r1.f1, roughness, *resolutionParamValue,
                       parallel_data, parallel_size, useImaginary, reflect1,
                       simul1);
      callReflectivity(*bulkInValue, *bulkOutValue, simLimits, repeatLayers,
                       b_shiftedData, r2.f1, roughness, *resolutionParamValue,
                       parallel_data, parallel_size, useImaginary, reflect2,
                       simul2);
      b_data.set_size(b_shiftedData.size(0), 6);
      loop_ub = b_shiftedData.size(0) - 1;
      for (i = 0; i < 6; i++) {
        for (i1 = 0; i1 <= loop_ub; i1++) {
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
      domainRatios_tmp = domainRatios[static_cast<int32_T>(domainRatioIndex) - 1];
      loop_ub = reflect1.size(0);
      b_loop_ub = reflect1.size(0);
      reflectivity.set_size(reflect1.size(0), 2);
      for (i = 0; i < loop_ub; i++) {
        reflectivity[i] = reflect1[i];
      }

      for (i = 0; i < b_loop_ub; i++) {
        reflectivity[i + reflectivity.size(0)] = domainRatios_tmp * reflect1[i +
          reflect1.size(0)] + (1.0 - domainRatios_tmp) * reflect2[i +
          reflect2.size(0)];
      }

      loop_ub = simul1.size(0);
      b_loop_ub = simul1.size(0);
      simulation.set_size(simul1.size(0), 2);
      for (i = 0; i < loop_ub; i++) {
        simulation[i] = simul1[i];
      }

      for (i = 0; i < b_loop_ub; i++) {
        simulation[i + simulation.size(0)] = domainRatios_tmp * simul1[i +
          simul1.size(0)] + (1.0 - domainRatios_tmp) * simul2[i + simul2.size(0)];
      }

      if (dataPresent != 0.0) {
        *chi = chiSquared(shiftedData, reflectivity, nParams);
      } else {
        *chi = 0.0;
      }
    }

    static void d_contrastCalculation(const real_T backgroundParamIndex_data[],
      const int32_T backgroundParamIndex_size[2], real_T qzshiftIndex, real_T
      scalefactorIndex, real_T bulkInIndex, real_T bulkOutIndex, real_T
      resolutionParamIndex, real_T domainRatioIndex, const ::coder::array<real_T,
      2U> &backgroundParams, const ::coder::array<real_T, 2U> &qzshifts, const ::
      coder::array<real_T, 2U> &scalefactors, const ::coder::array<real_T, 2U>
      &bulkIns, const ::coder::array<real_T, 2U> &bulkOuts, const ::coder::array<
      real_T, 2U> &resolutionParams, const ::coder::array<real_T, 2U>
      &domainRatios, real_T dataPresent, const ::coder::array<real_T, 2U> &data,
      const real_T dataLimits[2], const real_T simLimits[2], const real_T
      repeatLayers[2], const ::coder::array<cell_wrap_7, 2U> &backgroundType,
      const char_T backgroundAction_data[], const int32_T backgroundAction_size
      [2], const ::coder::array<cell_wrap_7, 2U> &customFiles, real_T nParams,
      const char_T parallel_data[], const int32_T parallel_size[2], real_T
      resampleMinAngle, real_T resampleNPoints, boolean_T useImaginary, real_T
      roughness, const ::coder::array<real_T, 2U> &sldProfile1, const ::coder::
      array<real_T, 2U> &sldProfile2, real_T *qzshiftValue, real_T
      *scalefactorValue, real_T *bulkInValue, real_T *bulkOutValue, real_T
      *resolutionParamValue, real_T *chi, ::coder::array<real_T, 2U>
      &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::array<
      real_T, 2U> &shiftedData, ::coder::array<real_T, 2U> &background,
      cell_wrap_10 layerSld[2], cell_wrap_10 sldProfile[2], cell_wrap_10
      resampledLayer[2])
    {
      ::coder::array<real_T, 2U> b_data;
      ::coder::array<real_T, 2U> b_reflect1;
      ::coder::array<real_T, 2U> b_shiftedData;
      ::coder::array<real_T, 2U> b_sldProfile1;
      ::coder::array<real_T, 2U> c_sldProfile1;
      ::coder::array<real_T, 2U> r;
      ::coder::array<real_T, 2U> reflect1;
      ::coder::array<real_T, 2U> reflect2;
      ::coder::array<real_T, 2U> simul1;
      ::coder::array<real_T, 2U> simul2;
      cell_wrap_10 r1;
      cell_wrap_10 r2;
      cell_wrap_10 r3;
      cell_wrap_10 r4;
      cell_wrap_10 r5;
      cell_wrap_10 r6;
      real_T domainRatios_tmp;
      int32_T b_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T loop_ub;

      //  Get the domain ratio for this contrast
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(qzshiftIndex, scalefactorIndex, bulkInIndex, bulkOutIndex,
               resolutionParamIndex, qzshifts, scalefactors, bulkIns, bulkOuts,
               resolutionParams, qzshiftValue, scalefactorValue, bulkInValue,
               bulkOutValue, resolutionParamValue);

      //  Resample the sld profiles
      if (!useImaginary) {
        b_resampleLayers(sldProfile1, resampleMinAngle, resampleNPoints, r);
        r1.f1.set_size(r.size(0), 3);
        loop_ub = r.size(0);
        for (i = 0; i < 3; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            r1.f1[i1 + r1.f1.size(0) * i] = r[i1 + r.size(0) * i];
          }
        }

        b_resampleLayers(sldProfile2, resampleMinAngle, resampleNPoints, r);
        r2.f1.set_size(r.size(0), 3);
        loop_ub = r.size(0);
        for (i = 0; i < 3; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            r2.f1[i1 + r2.f1.size(0) * i] = r[i1 + r.size(0) * i];
          }
        }
      } else {
        loop_ub = sldProfile1.size(0);
        b_sldProfile1.set_size(sldProfile1.size(0), 2);
        for (i = 0; i < 2; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_sldProfile1[i1 + b_sldProfile1.size(0) * i] = sldProfile1[i1 +
              sldProfile1.size(0) * i];
          }
        }

        loop_ub = sldProfile1.size(0);
        b_loop_ub = sldProfile1.size(0);
        c_sldProfile1.set_size(sldProfile1.size(0), 2);
        for (i = 0; i < loop_ub; i++) {
          c_sldProfile1[i] = sldProfile1[i];
        }

        for (i = 0; i < b_loop_ub; i++) {
          c_sldProfile1[i + c_sldProfile1.size(0)] = sldProfile1[i +
            sldProfile1.size(0) * 2];
        }

        resampleLayersReIm(b_sldProfile1, c_sldProfile1, resampleMinAngle,
                           resampleNPoints, r);
        r1.f1.set_size(r.size(0), 4);
        loop_ub = r.size(0);
        for (i = 0; i < 4; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            r1.f1[i1 + r1.f1.size(0) * i] = r[i1 + r.size(0) * i];
          }
        }

        loop_ub = sldProfile2.size(0);
        b_sldProfile1.set_size(sldProfile2.size(0), 2);
        for (i = 0; i < 2; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_sldProfile1[i1 + b_sldProfile1.size(0) * i] = sldProfile2[i1 +
              sldProfile2.size(0) * i];
          }
        }

        loop_ub = sldProfile2.size(0);
        b_loop_ub = sldProfile2.size(0);
        c_sldProfile1.set_size(sldProfile2.size(0), 2);
        for (i = 0; i < loop_ub; i++) {
          c_sldProfile1[i] = sldProfile2[i];
        }

        for (i = 0; i < b_loop_ub; i++) {
          c_sldProfile1[i + c_sldProfile1.size(0)] = sldProfile2[i +
            sldProfile2.size(0) * 2];
        }

        resampleLayersReIm(b_sldProfile1, c_sldProfile1, resampleMinAngle,
                           resampleNPoints, r);
        r2.f1.set_size(r.size(0), 4);
        loop_ub = r.size(0);
        for (i = 0; i < 4; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            r2.f1[i1 + r2.f1.size(0) * i] = r[i1 + r.size(0) * i];
          }
        }
      }

      layerSld[0] = r1;
      layerSld[1] = r2;
      r3.f1.set_size(r1.f1.size(0), r1.f1.size(1));
      loop_ub = r1.f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = r1.f1.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          r3.f1[i1 + r3.f1.size(0) * i] = r1.f1[i1 + r1.f1.size(0) * i];
        }
      }

      r4.f1.set_size(r2.f1.size(0), r2.f1.size(1));
      loop_ub = r2.f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = r2.f1.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          r4.f1[i1 + r4.f1.size(0) * i] = r2.f1[i1 + r2.f1.size(0) * i];
        }
      }

      resampledLayer[0] = r3;
      resampledLayer[1] = r4;
      r5.f1.set_size(sldProfile1.size(0), sldProfile1.size(1));
      loop_ub = sldProfile1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = sldProfile1.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          r5.f1[i1 + r5.f1.size(0) * i] = sldProfile1[i1 + sldProfile1.size(0) *
            i];
        }
      }

      r6.f1.set_size(sldProfile2.size(0), sldProfile2.size(1));
      loop_ub = sldProfile2.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = sldProfile2.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          r6.f1[i1 + r6.f1.size(0) * i] = sldProfile2[i1 + sldProfile2.size(0) *
            i];
        }
      }

      sldProfile[0] = r5;
      sldProfile[1] = r6;
      b_data.set_size(data.size(0), 6);
      loop_ub = data.size(0) - 1;
      for (i = 0; i < 6; i++) {
        for (i1 = 0; i1 <= loop_ub; i1++) {
          b_data[i1 + b_data.size(0) * i] = data[i1 + data.size(0) * i];
        }
      }

      shiftData(*scalefactorValue, *qzshiftValue, dataPresent, b_data,
                dataLimits, simLimits, b_shiftedData);
      constructBackground(backgroundType, backgroundParamIndex_data,
                          backgroundParamIndex_size, b_shiftedData, customFiles,
                          backgroundParams, simLimits, background);
      callReflectivity(*bulkInValue, *bulkOutValue, simLimits, repeatLayers,
                       b_shiftedData, r1.f1, roughness, *resolutionParamValue,
                       parallel_data, parallel_size, useImaginary, reflect1,
                       simul1);
      callReflectivity(*bulkInValue, *bulkOutValue, simLimits, repeatLayers,
                       b_shiftedData, r2.f1, roughness, *resolutionParamValue,
                       parallel_data, parallel_size, useImaginary, reflect2,
                       simul2);
      b_data.set_size(b_shiftedData.size(0), 6);
      loop_ub = b_shiftedData.size(0) - 1;
      for (i = 0; i < 6; i++) {
        for (i1 = 0; i1 <= loop_ub; i1++) {
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
      domainRatios_tmp = domainRatios[static_cast<int32_T>(domainRatioIndex) - 1];
      loop_ub = reflect1.size(0);
      b_loop_ub = reflect1.size(0);
      reflectivity.set_size(reflect1.size(0), 2);
      for (i = 0; i < loop_ub; i++) {
        reflectivity[i] = reflect1[i];
      }

      for (i = 0; i < b_loop_ub; i++) {
        reflectivity[i + reflectivity.size(0)] = domainRatios_tmp * reflect1[i +
          reflect1.size(0)] + (1.0 - domainRatios_tmp) * reflect2[i +
          reflect2.size(0)];
      }

      loop_ub = simul1.size(0);
      b_loop_ub = simul1.size(0);
      simulation.set_size(simul1.size(0), 2);
      for (i = 0; i < loop_ub; i++) {
        simulation[i] = simul1[i];
      }

      for (i = 0; i < b_loop_ub; i++) {
        simulation[i + simulation.size(0)] = domainRatios_tmp * simul1[i +
          simul1.size(0)] + (1.0 - domainRatios_tmp) * simul2[i + simul2.size(0)];
      }

      if (dataPresent != 0.0) {
        *chi = chiSquared(shiftedData, reflectivity, nParams);
      } else {
        *chi = 0.0;
      }
    }

    void b_customXY(const e_struct_T *problemStruct, const struct4_T *controls, ::
                    coder::array<real_T, 1U> &qzshifts, ::coder::array<real_T,
                    1U> &scalefactors, ::coder::array<real_T, 1U> &bulkIns, ::
                    coder::array<real_T, 1U> &bulkOuts, ::coder::array<real_T,
                    1U> &resolutionParams, ::coder::array<real_T, 1U> &chis, ::
                    coder::array<cell_wrap_8, 1U> &reflectivity, ::coder::array<
                    cell_wrap_8, 1U> &simulation, ::coder::array<cell_wrap_9, 1U>
                    &shiftedData, ::coder::array<cell_wrap_9, 1U> &backgrounds, ::
                    coder::array<cell_wrap_10, 2U> &domainLayerSlds, ::coder::
                    array<cell_wrap_10, 2U> &domainSldProfiles, ::coder::array<
                    cell_wrap_10, 2U> &domainResampledLayers, ::coder::array<
                    real_T, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_10, 2U> inputSldProfiles;
      ::coder::array<cell_wrap_10, 1U> inputSldProfiles1;
      ::coder::array<cell_wrap_10, 1U> inputSldProfiles2;
      ::coder::array<cell_wrap_34, 2U> r;
      ::coder::array<cell_wrap_64, 1U> layerSlds;
      ::coder::array<cell_wrap_64, 1U> resampledLayers;
      ::coder::array<cell_wrap_64, 1U> sldProfiles;
      ::coder::array<real_T, 2U> r1;
      ::coder::array<real_T, 2U> r2;
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      real_T d4;
      real_T d5;
      real_T numberOfContrasts;
      real_T resampleMinAngle;
      real_T resampleNPoints;
      int32_T iv[2];
      int32_T iv1[2];
      int32_T iv2[2];
      int32_T iv3[2];
      int32_T iv4[2];
      int32_T b_i;
      int32_T b_loop_ub;
      int32_T c_i;
      int32_T c_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T i2;
      int32_T i3;
      int32_T i4;
      int32_T loop_ub;
      int32_T nParams;
      int32_T unnamed_idx_0_tmp_tmp;
      boolean_T useImaginary;

      //  Extract parameters from problemStruct
      numberOfContrasts = problemStruct->numberOfContrasts;
      nParams = problemStruct->params.size(1);
      useImaginary = problemStruct->useImaginary;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      // Pre-Allocation...
      unnamed_idx_0_tmp_tmp = static_cast<int32_T>
        (problemStruct->numberOfContrasts);
      inputSldProfiles1.set_size(unnamed_idx_0_tmp_tmp);
      inputSldProfiles2.set_size(unnamed_idx_0_tmp_tmp);
      for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
        inputSldProfiles1[i].f1.set_size(2, 1);
        inputSldProfiles1[i].f1[0] = 1.0;
        inputSldProfiles1[i].f1[1] = 1.0;
        inputSldProfiles2[i].f1.set_size(2, 1);
        inputSldProfiles2[i].f1[0] = 1.0;
        inputSldProfiles2[i].f1[1] = 1.0;
      }

      customXY::processCustomFunction(problemStruct->contrastBulkIns,
        problemStruct->contrastBulkOuts, problemStruct->bulkIns,
        problemStruct->bulkOuts, problemStruct->contrastCustomFiles,
        problemStruct->numberOfContrasts, problemStruct->customFiles,
        problemStruct->params, r, subRoughs);
      cast(r, inputSldProfiles);
      b_i = inputSldProfiles.size(0);
      for (i = 0; i < b_i; i++) {
        loop_ub = inputSldProfiles[i].f1.size(1);
        inputSldProfiles1[i].f1.set_size(inputSldProfiles[i].f1.size(0),
          inputSldProfiles[i].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = inputSldProfiles[i].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            inputSldProfiles1[i].f1[i2 + inputSldProfiles1[i].f1.size(0) * i1] =
              inputSldProfiles[i].f1[i2 + inputSldProfiles[i].f1.size(0) * i1];
          }
        }

        loop_ub = inputSldProfiles[i + inputSldProfiles.size(0)].f1.size(1);
        inputSldProfiles2[i].f1.set_size(inputSldProfiles[i +
          inputSldProfiles.size(0)].f1.size(0), inputSldProfiles[i +
          inputSldProfiles.size(0)].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = inputSldProfiles[i + inputSldProfiles.size(0)].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            inputSldProfiles2[i].f1[i2 + inputSldProfiles2[i].f1.size(0) * i1] =
              inputSldProfiles[i + inputSldProfiles.size(0)].f1[i2 +
              inputSldProfiles[i + inputSldProfiles.size(0)].f1.size(0) * i1];
          }
        }
      }

      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        resampledLayers.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        sldProfiles.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        layerSlds.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        backgrounds.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        shiftedData.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        simulation.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        reflectivity.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        qzshifts.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        scalefactors.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        bulkIns.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        bulkOuts.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        resolutionParams.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        chis.set_size(b_i);
        loop_ub = static_cast<int32_T>(problemStruct->numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r1,d,d1,d2,d3,d4,d5,iv2,c_i,iv3,iv4,c_loop_ub,i3,i4)

        for (c_i = 0; c_i <= loop_ub; c_i++) {
          iv2[0] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                     &problemStruct->contrastBackgroundParams[c_i].f1)->size())
            [0];
          iv2[1] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                     &problemStruct->contrastBackgroundParams[c_i].f1)->size())
            [1];
          iv3[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[0];
          iv3[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[1];
          iv4[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv4[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [1];
          c_contrastCalculation((const real_T *)((::coder::array<real_T, 2U> *)
            &problemStruct->contrastBackgroundParams[c_i].f1)->data(), iv2,
                                problemStruct->contrastQzshifts[c_i],
                                problemStruct->contrastScalefactors[c_i],
                                problemStruct->contrastBulkIns[c_i],
                                problemStruct->contrastBulkOuts[c_i],
                                problemStruct->contrastResolutionParams[c_i],
                                problemStruct->contrastDomainRatios[c_i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIns, problemStruct->bulkOuts,
                                problemStruct->resolutionParams,
                                problemStruct->domainRatios,
                                problemStruct->dataPresent[c_i],
                                problemStruct->data[c_i].f1,
                                problemStruct->dataLimits[c_i].f1,
                                problemStruct->simulationLimits[c_i].f1,
                                problemStruct->repeatLayers[c_i].f1, (const
            char_T *)((::coder::array<char_T, 2U> *)
                      &problemStruct->contrastBackgroundTypes[c_i].f1)->data(),
                                iv3, (const char_T *)((::coder::array<char_T, 2U>
            *)&problemStruct->contrastBackgroundActions[c_i].f1)->data(), iv4,
                                problemStruct->customFiles, static_cast<real_T>
                                (nParams), controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, subRoughs[c_i],
                                inputSldProfiles1[c_i].f1, inputSldProfiles2[c_i]
                                .f1, &d5, &d4, &d3, &d2, &d1, &d,
                                reflectivity[c_i].f1, simulation[c_i].f1, r1,
                                backgrounds[c_i].f1, layerSlds[c_i].f1,
                                sldProfiles[c_i].f1, resampledLayers[c_i].f1);
          c_loop_ub = r1.size(0);
          shiftedData[c_i].f1.set_size(r1.size(0), 3);
          for (i3 = 0; i3 < 3; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r1[i4
                + r1.size(0) * i3];
            }
          }

          qzshifts[c_i] = d5;
          scalefactors[c_i] = d4;
          bulkIns[c_i] = d3;
          bulkOuts[c_i] = d2;
          resolutionParams[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        resampledLayers.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        sldProfiles.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        layerSlds.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        backgrounds.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        shiftedData.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        simulation.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        reflectivity.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        qzshifts.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        scalefactors.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        bulkIns.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        bulkOuts.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        resolutionParams.set_size(b_i);
        b_i = static_cast<int32_T>(problemStruct->numberOfContrasts);
        chis.set_size(b_i);
        for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
          iv[0] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                    &problemStruct->contrastBackgroundParams[i].f1)->size())[0];
          iv[1] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                    &problemStruct->contrastBackgroundParams[i].f1)->size())[1];
          iv1[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[i].f1)->size())[0];
          iv1[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[i].f1)->size())[1];
          d_contrastCalculation((const real_T *)((::coder::array<real_T, 2U> *)
            &problemStruct->contrastBackgroundParams[i].f1)->data(), iv,
                                problemStruct->contrastQzshifts[i],
                                problemStruct->contrastScalefactors[i],
                                problemStruct->contrastBulkIns[i],
                                problemStruct->contrastBulkOuts[i],
                                problemStruct->contrastResolutionParams[i],
                                problemStruct->contrastDomainRatios[i],
                                problemStruct->backgroundParams,
                                problemStruct->qzshifts,
                                problemStruct->scalefactors,
                                problemStruct->bulkIns, problemStruct->bulkOuts,
                                problemStruct->resolutionParams,
                                problemStruct->domainRatios,
                                problemStruct->dataPresent[i],
                                problemStruct->data[i].f1,
                                problemStruct->dataLimits[i].f1,
                                problemStruct->simulationLimits[i].f1,
                                problemStruct->repeatLayers[i].f1,
                                problemStruct->contrastBackgroundTypes, (const
            char_T *)((::coder::array<char_T, 2U> *)
                      &problemStruct->contrastBackgroundActions[i].f1)->data(),
                                iv1, problemStruct->customFiles,
                                static_cast<real_T>(problemStruct->params.size(1)),
                                controls->parallel.data, controls->parallel.size,
                                resampleMinAngle, resampleNPoints,
                                problemStruct->useImaginary, subRoughs[i],
                                inputSldProfiles1[i].f1, inputSldProfiles2[i].f1,
                                &qzshifts[i], &scalefactors[i], &bulkIns[i],
                                &bulkOuts[i], &resolutionParams[i], &chis[i],
                                reflectivity[i].f1, simulation[i].f1, r2,
                                backgrounds[i].f1, layerSlds[i].f1,
                                sldProfiles[i].f1, resampledLayers[i].f1);
          loop_ub = r2.size(0);
          shiftedData[i].f1.set_size(r2.size(0), 3);
          for (b_i = 0; b_i < 3; b_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * b_i] = r2[i1 +
                r2.size(0) * b_i];
            }
          }
        }
      }

      b_i = static_cast<int32_T>(numberOfContrasts);
      domainSldProfiles.set_size(unnamed_idx_0_tmp_tmp, 2);
      domainLayerSlds.set_size(unnamed_idx_0_tmp_tmp, 2);
      domainResampledLayers.set_size(unnamed_idx_0_tmp_tmp, 2);
      for (i = 0; i < b_i; i++) {
        loop_ub = sldProfiles[i].f1[0].f1.size(1);
        domainSldProfiles[i].f1.set_size(sldProfiles[i].f1[0].f1.size(0),
          sldProfiles[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = sldProfiles[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainSldProfiles[i].f1[i2 + domainSldProfiles[i].f1.size(0) * i1] =
              sldProfiles[i].f1[0].f1[i2 + sldProfiles[i].f1[0].f1.size(0) * i1];
          }
        }

        loop_ub = sldProfiles[i].f1[1].f1.size(1);
        domainSldProfiles[i + domainSldProfiles.size(0)].f1.set_size
          (sldProfiles[i].f1[1].f1.size(0), sldProfiles[i].f1[1].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = sldProfiles[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainSldProfiles[i + domainSldProfiles.size(0)].f1[i2 +
              domainSldProfiles[i + domainSldProfiles.size(0)].f1.size(0) * i1] =
              sldProfiles[i].f1[1].f1[i2 + sldProfiles[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[0].f1.size(1);
        domainLayerSlds[i].f1.set_size(layerSlds[i].f1[0].f1.size(0),
          layerSlds[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i].f1[i2 + domainLayerSlds[i].f1.size(0) * i1] =
              layerSlds[i].f1[0].f1[i2 + layerSlds[i].f1[0].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[1].f1.size(1);
        domainLayerSlds[i + domainLayerSlds.size(0)].f1.set_size(layerSlds[i]
          .f1[1].f1.size(0), layerSlds[i].f1[1].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i + domainLayerSlds.size(0)].f1[i2 +
              domainLayerSlds[i + domainLayerSlds.size(0)].f1.size(0) * i1] =
              layerSlds[i].f1[1].f1[i2 + layerSlds[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[0].f1.size(1);
        domainResampledLayers[i].f1.set_size(resampledLayers[i].f1[0].f1.size(0),
          resampledLayers[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i].f1[i2 + domainResampledLayers[i].f1.size(0)
              * i1] = resampledLayers[i].f1[0].f1[i2 + resampledLayers[i].f1[0].
              f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[1].f1.size(1);
        domainResampledLayers[i + domainResampledLayers.size(0)].f1.set_size
          (resampledLayers[i].f1[1].f1.size(0), resampledLayers[i].f1[1].f1.size
           (1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i + domainResampledLayers.size(0)].f1[i2 +
              domainResampledLayers[i + domainResampledLayers.size(0)].f1.size(0)
              * i1] = resampledLayers[i].f1[1].f1[i2 + resampledLayers[i].f1[1].
              f1.size(0) * i1];
          }
        }
      }
    }

    void b_customXY(const struct0_T *problemStruct, const struct4_T *controls, ::
                    coder::array<real_T, 1U> &qzshifts, ::coder::array<real_T,
                    1U> &scalefactors, ::coder::array<real_T, 1U> &bulkIns, ::
                    coder::array<real_T, 1U> &bulkOuts, ::coder::array<real_T,
                    1U> &resolutionParams, ::coder::array<real_T, 1U> &chis, ::
                    coder::array<cell_wrap_8, 1U> &reflectivity, ::coder::array<
                    cell_wrap_8, 1U> &simulation, ::coder::array<cell_wrap_9, 1U>
                    &shiftedData, ::coder::array<cell_wrap_9, 1U> &backgrounds, ::
                    coder::array<cell_wrap_10, 2U> &domainLayerSlds, ::coder::
                    array<cell_wrap_10, 2U> &domainSldProfiles, ::coder::array<
                    cell_wrap_10, 2U> &domainResampledLayers, ::coder::array<
                    real_T, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_1, 2U> data;
      ::coder::array<cell_wrap_10, 2U> a__4;
      ::coder::array<cell_wrap_10, 2U> a__5;
      ::coder::array<cell_wrap_10, 2U> a__6;
      ::coder::array<cell_wrap_10, 2U> inputSldProfiles;
      ::coder::array<cell_wrap_10, 1U> inputSldProfiles1;
      ::coder::array<cell_wrap_10, 1U> inputSldProfiles2;
      ::coder::array<cell_wrap_2, 2U> dataLimits;
      ::coder::array<cell_wrap_2, 2U> repeatLayers;
      ::coder::array<cell_wrap_2, 2U> simLimits;
      ::coder::array<cell_wrap_34, 2U> r;
      ::coder::array<cell_wrap_48, 2U> contrastBackgroundIndices;
      ::coder::array<cell_wrap_64, 1U> layerSlds;
      ::coder::array<cell_wrap_64, 1U> resampledLayers;
      ::coder::array<cell_wrap_64, 1U> sldProfiles;
      ::coder::array<cell_wrap_7, 2U> contrastBackgroundActions;
      ::coder::array<cell_wrap_7, 2U> contrastBackgroundTypes;
      ::coder::array<cell_wrap_7, 2U> customFiles;
      ::coder::array<real_T, 2U> a__3;
      ::coder::array<real_T, 2U> backgroundParamArray;
      ::coder::array<real_T, 2U> bulkInArray;
      ::coder::array<real_T, 2U> bulkOutArray;
      ::coder::array<real_T, 2U> cCustFiles;
      ::coder::array<real_T, 2U> contrastBulkInIndices;
      ::coder::array<real_T, 2U> contrastBulkOutIndices;
      ::coder::array<real_T, 2U> contrastDomainRatioIndices;
      ::coder::array<real_T, 2U> contrastQzshiftIndices;
      ::coder::array<real_T, 2U> contrastResolutionParamIndices;
      ::coder::array<real_T, 2U> contrastScalefactorIndices;
      ::coder::array<real_T, 2U> dataPresent;
      ::coder::array<real_T, 2U> domainRatioArray;
      ::coder::array<real_T, 2U> params;
      ::coder::array<real_T, 2U> qzshiftArray;
      ::coder::array<real_T, 2U> r1;
      ::coder::array<real_T, 2U> r2;
      ::coder::array<real_T, 2U> resolutionParamArray;
      ::coder::array<real_T, 2U> scalefactorArray;
      real_T a__2;
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      real_T d4;
      real_T d5;
      real_T nParams;
      real_T numberOfContrasts;
      real_T resampleMinAngle;
      real_T resampleNPoints;
      int32_T a__1_size[2];
      int32_T iv[2];
      int32_T iv1[2];
      int32_T iv2[2];
      int32_T iv3[2];
      int32_T b_i;
      int32_T b_loop_ub;
      int32_T c_i;
      int32_T c_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T i2;
      int32_T i3;
      int32_T i4;
      int32_T loop_ub;
      int32_T unnamed_idx_0;
      int32_T unnamed_idx_0_tmp_tmp;
      char_T a__1_data[10000];
      boolean_T useImaginary;

      //  Extract parameters from problemStruct
      extractProblemParams(problemStruct, &numberOfContrasts, a__1_data,
                           a__1_size, contrastBackgroundIndices,
                           contrastQzshiftIndices, contrastScalefactorIndices,
                           contrastBulkInIndices, contrastBulkOutIndices,
                           contrastResolutionParamIndices,
                           contrastDomainRatioIndices, backgroundParamArray,
                           qzshiftArray, scalefactorArray, bulkInArray,
                           bulkOutArray, resolutionParamArray, domainRatioArray,
                           dataPresent, &nParams, params, &a__2, a__3,
                           contrastBackgroundTypes, contrastBackgroundActions,
                           cCustFiles, &useImaginary, repeatLayers, data,
                           dataLimits, simLimits, a__4, a__5, customFiles, a__6);
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      // Pre-Allocation...
      unnamed_idx_0_tmp_tmp = static_cast<int32_T>(numberOfContrasts);
      unnamed_idx_0 = static_cast<int32_T>(numberOfContrasts);
      inputSldProfiles1.set_size(unnamed_idx_0_tmp_tmp);
      inputSldProfiles2.set_size(unnamed_idx_0_tmp_tmp);
      for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
        inputSldProfiles1[i].f1.set_size(2, 1);
        inputSldProfiles1[i].f1[0] = 1.0;
        inputSldProfiles1[i].f1[1] = 1.0;
        inputSldProfiles2[i].f1.set_size(2, 1);
        inputSldProfiles2[i].f1[0] = 1.0;
        inputSldProfiles2[i].f1[1] = 1.0;
      }

      customXY::processCustomFunction(contrastBulkInIndices,
        contrastBulkOutIndices, bulkInArray, bulkOutArray, cCustFiles,
        numberOfContrasts, customFiles, params, r, subRoughs);
      cast(r, inputSldProfiles);
      b_i = inputSldProfiles.size(0);
      for (i = 0; i < b_i; i++) {
        loop_ub = inputSldProfiles[i].f1.size(1);
        inputSldProfiles1[i].f1.set_size(inputSldProfiles[i].f1.size(0),
          inputSldProfiles[i].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = inputSldProfiles[i].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            inputSldProfiles1[i].f1[i2 + inputSldProfiles1[i].f1.size(0) * i1] =
              inputSldProfiles[i].f1[i2 + inputSldProfiles[i].f1.size(0) * i1];
          }
        }

        loop_ub = inputSldProfiles[i + inputSldProfiles.size(0)].f1.size(1);
        inputSldProfiles2[i].f1.set_size(inputSldProfiles[i +
          inputSldProfiles.size(0)].f1.size(0), inputSldProfiles[i +
          inputSldProfiles.size(0)].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = inputSldProfiles[i + inputSldProfiles.size(0)].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            inputSldProfiles2[i].f1[i2 + inputSldProfiles2[i].f1.size(0) * i1] =
              inputSldProfiles[i + inputSldProfiles.size(0)].f1[i2 +
              inputSldProfiles[i + inputSldProfiles.size(0)].f1.size(0) * i1];
          }
        }
      }

      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp);
        resolutionParams.set_size(unnamed_idx_0_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp);
        unnamed_idx_0_tmp_tmp = static_cast<int32_T>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r1,d,d1,d2,d3,d4,d5,iv1,c_i,iv2,iv3,c_loop_ub,i3,i4)

        for (c_i = 0; c_i <= unnamed_idx_0_tmp_tmp; c_i++) {
          iv1[0] = (*(int32_T (*)[2])contrastBackgroundIndices[c_i].f1.size())[0];
          iv1[1] = (*(int32_T (*)[2])contrastBackgroundIndices[c_i].f1.size())[1];
          iv2[0] = (*(int32_T (*)[2])contrastBackgroundTypes[c_i].f1.size())[0];
          iv2[1] = (*(int32_T (*)[2])contrastBackgroundTypes[c_i].f1.size())[1];
          iv3[0] = (*(int32_T (*)[2])contrastBackgroundActions[c_i].f1.size())[0];
          iv3[1] = (*(int32_T (*)[2])contrastBackgroundActions[c_i].f1.size())[1];
          c_contrastCalculation((const real_T *)contrastBackgroundIndices[c_i].
                                f1.data(), iv1, contrastQzshiftIndices[c_i],
                                contrastScalefactorIndices[c_i],
                                contrastBulkInIndices[c_i],
                                contrastBulkOutIndices[c_i],
                                contrastResolutionParamIndices[c_i],
                                contrastDomainRatioIndices[c_i],
                                backgroundParamArray, qzshiftArray,
                                scalefactorArray, bulkInArray, bulkOutArray,
                                resolutionParamArray, domainRatioArray,
                                dataPresent[c_i], data[c_i].f1, dataLimits[c_i].
                                f1, simLimits[c_i].f1, repeatLayers[c_i].f1, (
            const char_T *)contrastBackgroundTypes[c_i].f1.data(), iv2, (const
            char_T *)contrastBackgroundActions[c_i].f1.data(), iv3, customFiles,
                                nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, subRoughs[c_i],
                                inputSldProfiles1[c_i].f1, inputSldProfiles2[c_i]
                                .f1, &d5, &d4, &d3, &d2, &d1, &d,
                                reflectivity[c_i].f1, simulation[c_i].f1, r1,
                                backgrounds[c_i].f1, layerSlds[c_i].f1,
                                sldProfiles[c_i].f1, resampledLayers[c_i].f1);
          c_loop_ub = r1.size(0);
          shiftedData[c_i].f1.set_size(r1.size(0), 3);
          for (i3 = 0; i3 < 3; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r1[i4
                + r1.size(0) * i3];
            }
          }

          qzshifts[c_i] = d5;
          scalefactors[c_i] = d4;
          bulkIns[c_i] = d3;
          bulkOuts[c_i] = d2;
          resolutionParams[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        resampledLayers.set_size(unnamed_idx_0_tmp_tmp);
        sldProfiles.set_size(unnamed_idx_0_tmp_tmp);
        layerSlds.set_size(unnamed_idx_0_tmp_tmp);
        backgrounds.set_size(unnamed_idx_0_tmp_tmp);
        shiftedData.set_size(unnamed_idx_0_tmp_tmp);
        simulation.set_size(unnamed_idx_0_tmp_tmp);
        reflectivity.set_size(unnamed_idx_0_tmp_tmp);
        qzshifts.set_size(unnamed_idx_0_tmp_tmp);
        scalefactors.set_size(unnamed_idx_0_tmp_tmp);
        bulkIns.set_size(unnamed_idx_0_tmp_tmp);
        bulkOuts.set_size(unnamed_idx_0_tmp_tmp);
        resolutionParams.set_size(unnamed_idx_0_tmp_tmp);
        chis.set_size(unnamed_idx_0_tmp_tmp);
        for (i = 0; i < unnamed_idx_0_tmp_tmp; i++) {
          a__1_size[0] = (*(int32_T (*)[2])contrastBackgroundIndices[i].f1.size())
            [0];
          a__1_size[1] = (*(int32_T (*)[2])contrastBackgroundIndices[i].f1.size())
            [1];
          iv[0] = (*(int32_T (*)[2])contrastBackgroundActions[i].f1.size())[0];
          iv[1] = (*(int32_T (*)[2])contrastBackgroundActions[i].f1.size())[1];
          d_contrastCalculation((const real_T *)contrastBackgroundIndices[i].
                                f1.data(), a__1_size, contrastQzshiftIndices[i],
                                contrastScalefactorIndices[i],
                                contrastBulkInIndices[i],
                                contrastBulkOutIndices[i],
                                contrastResolutionParamIndices[i],
                                contrastDomainRatioIndices[i],
                                backgroundParamArray, qzshiftArray,
                                scalefactorArray, bulkInArray, bulkOutArray,
                                resolutionParamArray, domainRatioArray,
                                dataPresent[i], data[i].f1, dataLimits[i].f1,
                                simLimits[i].f1, repeatLayers[i].f1,
                                contrastBackgroundTypes, (const char_T *)
                                contrastBackgroundActions[i].f1.data(), iv,
                                customFiles, nParams, controls->parallel.data,
                                controls->parallel.size, resampleMinAngle,
                                resampleNPoints, useImaginary, subRoughs[i],
                                inputSldProfiles1[i].f1, inputSldProfiles2[i].f1,
                                &qzshifts[i], &scalefactors[i], &bulkIns[i],
                                &bulkOuts[i], &resolutionParams[i], &chis[i],
                                reflectivity[i].f1, simulation[i].f1, r2,
                                backgrounds[i].f1, layerSlds[i].f1,
                                sldProfiles[i].f1, resampledLayers[i].f1);
          loop_ub = r2.size(0);
          shiftedData[i].f1.set_size(r2.size(0), 3);
          for (b_i = 0; b_i < 3; b_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * b_i] = r2[i1 +
                r2.size(0) * b_i];
            }
          }
        }
      }

      b_i = static_cast<int32_T>(numberOfContrasts);
      domainSldProfiles.set_size(unnamed_idx_0, 2);
      domainLayerSlds.set_size(unnamed_idx_0, 2);
      domainResampledLayers.set_size(unnamed_idx_0, 2);
      for (i = 0; i < b_i; i++) {
        loop_ub = sldProfiles[i].f1[0].f1.size(1);
        domainSldProfiles[i].f1.set_size(sldProfiles[i].f1[0].f1.size(0),
          sldProfiles[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = sldProfiles[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainSldProfiles[i].f1[i2 + domainSldProfiles[i].f1.size(0) * i1] =
              sldProfiles[i].f1[0].f1[i2 + sldProfiles[i].f1[0].f1.size(0) * i1];
          }
        }

        loop_ub = sldProfiles[i].f1[1].f1.size(1);
        domainSldProfiles[i + domainSldProfiles.size(0)].f1.set_size
          (sldProfiles[i].f1[1].f1.size(0), sldProfiles[i].f1[1].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = sldProfiles[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainSldProfiles[i + domainSldProfiles.size(0)].f1[i2 +
              domainSldProfiles[i + domainSldProfiles.size(0)].f1.size(0) * i1] =
              sldProfiles[i].f1[1].f1[i2 + sldProfiles[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[0].f1.size(1);
        domainLayerSlds[i].f1.set_size(layerSlds[i].f1[0].f1.size(0),
          layerSlds[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i].f1[i2 + domainLayerSlds[i].f1.size(0) * i1] =
              layerSlds[i].f1[0].f1[i2 + layerSlds[i].f1[0].f1.size(0) * i1];
          }
        }

        loop_ub = layerSlds[i].f1[1].f1.size(1);
        domainLayerSlds[i + domainLayerSlds.size(0)].f1.set_size(layerSlds[i]
          .f1[1].f1.size(0), layerSlds[i].f1[1].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = layerSlds[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainLayerSlds[i + domainLayerSlds.size(0)].f1[i2 +
              domainLayerSlds[i + domainLayerSlds.size(0)].f1.size(0) * i1] =
              layerSlds[i].f1[1].f1[i2 + layerSlds[i].f1[1].f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[0].f1.size(1);
        domainResampledLayers[i].f1.set_size(resampledLayers[i].f1[0].f1.size(0),
          resampledLayers[i].f1[0].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[0].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i].f1[i2 + domainResampledLayers[i].f1.size(0)
              * i1] = resampledLayers[i].f1[0].f1[i2 + resampledLayers[i].f1[0].
              f1.size(0) * i1];
          }
        }

        loop_ub = resampledLayers[i].f1[1].f1.size(1);
        domainResampledLayers[i + domainResampledLayers.size(0)].f1.set_size
          (resampledLayers[i].f1[1].f1.size(0), resampledLayers[i].f1[1].f1.size
           (1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = resampledLayers[i].f1[1].f1.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            domainResampledLayers[i + domainResampledLayers.size(0)].f1[i2 +
              domainResampledLayers[i + domainResampledLayers.size(0)].f1.size(0)
              * i1] = resampledLayers[i].f1[1].f1[i2 + resampledLayers[i].f1[1].
              f1.size(0) * i1];
          }
        }
      }
    }
  }
}

// End of code generation (customXY1.cpp)
