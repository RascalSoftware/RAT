//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// structConstructorHelper.cpp
//
// Code generation for function 'structConstructorHelper'
//

// Include files
#include "structConstructorHelper.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      int structConstructorHelper(const cell_wrap_45 &varargin_2, const
        cell_wrap_46 &varargin_4, const cell_wrap_49 &varargin_6, ::coder::array<
        cell_wrap_11, 1U> &s_reflectivity, ::coder::array<cell_wrap_11, 2U>
        &s_sld, double s_sampleChi_data[])
      {
        int loop_ub;
        int s_sampleChi_size;
        s_reflectivity.set_size(varargin_2.f1.size(0));
        loop_ub = varargin_2.f1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          s_reflectivity[i] = varargin_2.f1[i];
        }

        s_sld.set_size(varargin_4.f1.size(0), varargin_4.f1.size(1));
        loop_ub = varargin_4.f1.size(1);
        for (int i{0}; i < loop_ub; i++) {
          int b_loop_ub;
          b_loop_ub = varargin_4.f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            s_sld[i1 + s_sld.size(0) * i] = varargin_4.f1[i1 +
              varargin_4.f1.size(0) * i];
          }
        }

        s_sampleChi_size = varargin_6.f1.size(0);
        loop_ub = varargin_6.f1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          s_sampleChi_data[i] = varargin_6.f1[i];
        }

        return s_sampleChi_size;
      }

      void structConstructorHelper(const cell_wrap_33 &varargin_2, const
        cell_wrap_33 &varargin_4, const cell_wrap_34 &varargin_6, const
        cell_wrap_34 &varargin_8, const cell_wrap_33 &varargin_10, const
        cell_wrap_35 &varargin_12, const cell_wrap_35 &varargin_14, const
        cell_wrap_35 &varargin_16, const CalculationResults &varargin_18, const
        ContrastParams &varargin_20, const ::coder::array<double, 2U>
        &varargin_22, const cell_wrap_36 &varargin_24, Results &s)
      {
        int b_loop_ub;
        int loop_ub;
        s.reflectivity.set_size(varargin_2.f1.size(0));
        loop_ub = varargin_2.f1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          s.reflectivity[i] = varargin_2.f1[i];
        }

        s.simulation.set_size(varargin_4.f1.size(0));
        loop_ub = varargin_4.f1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          s.simulation[i] = varargin_4.f1[i];
        }

        s.shiftedData.set_size(varargin_6.f1.size(0));
        loop_ub = varargin_6.f1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          s.shiftedData[i] = varargin_6.f1[i];
        }

        s.backgrounds.set_size(varargin_8.f1.size(0));
        loop_ub = varargin_8.f1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          s.backgrounds[i] = varargin_8.f1[i];
        }

        s.resolutions.set_size(varargin_10.f1.size(0));
        loop_ub = varargin_10.f1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          s.resolutions[i] = varargin_10.f1[i];
        }

        s.sldProfiles.set_size(varargin_12.f1.size(0), varargin_12.f1.size(1));
        loop_ub = varargin_12.f1.size(1);
        for (int i{0}; i < loop_ub; i++) {
          b_loop_ub = varargin_12.f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            s.sldProfiles[i1 + s.sldProfiles.size(0) * i] = varargin_12.f1[i1 +
              varargin_12.f1.size(0) * i];
          }
        }

        s.layers.set_size(varargin_14.f1.size(0), varargin_14.f1.size(1));
        loop_ub = varargin_14.f1.size(1);
        for (int i{0}; i < loop_ub; i++) {
          b_loop_ub = varargin_14.f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            s.layers[i1 + s.layers.size(0) * i] = varargin_14.f1[i1 +
              varargin_14.f1.size(0) * i];
          }
        }

        s.resampledLayers.set_size(varargin_16.f1.size(0), varargin_16.f1.size(1));
        loop_ub = varargin_16.f1.size(1);
        for (int i{0}; i < loop_ub; i++) {
          b_loop_ub = varargin_16.f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            s.resampledLayers[i1 + s.resampledLayers.size(0) * i] =
              varargin_16.f1[i1 + varargin_16.f1.size(0) * i];
          }
        }

        s.calculationResults = varargin_18;
        s.contrastParams = varargin_20;
        s.fitParams.set_size(1, varargin_22.size(1));
        loop_ub = varargin_22.size(1);
        for (int i{0}; i < loop_ub; i++) {
          s.fitParams[i] = varargin_22[i];
        }

        s.fitNames.set_size(varargin_24.f1.size(0));
        loop_ub = varargin_24.f1.size(0);
        for (int i{0}; i < loop_ub; i++) {
          s.fitNames[i] = varargin_24.f1[i];
        }
      }
    }
  }
}

// End of code generation (structConstructorHelper.cpp)
