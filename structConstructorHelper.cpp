//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
      void structConstructorHelper(const cell_wrap_27 *varargin_2, const
        cell_wrap_27 *varargin_4, const cell_wrap_28 *varargin_6, const
        cell_wrap_29 *varargin_8, const cell_wrap_29 *varargin_10, const
        cell_wrap_30 *varargin_12, const struct6_T *varargin_14, const
        c_struct_T *varargin_16, const ::coder::array<real_T, 2U> &varargin_18,
        const cell_wrap_31 *varargin_20, d_struct_T *s)
      {
        ::coder::array<real_T, 2U> f1;
        int32_T b_loop_ub;
        int32_T i;
        int32_T i1;
        int32_T loop_ub;
        f1.set_size(1, varargin_18.size(1));
        loop_ub = varargin_18.size(1);
        for (i = 0; i < loop_ub; i++) {
          f1[i] = varargin_18[i];
        }

        s->reflectivity.set_size(varargin_2->f1.size(0));
        loop_ub = varargin_2->f1.size(0);
        for (i = 0; i < loop_ub; i++) {
          s->reflectivity[i] = varargin_2->f1[i];
        }

        s->simulation.set_size(varargin_4->f1.size(0));
        loop_ub = varargin_4->f1.size(0);
        for (i = 0; i < loop_ub; i++) {
          s->simulation[i] = varargin_4->f1[i];
        }

        s->shiftedData.set_size(varargin_6->f1.size(0));
        loop_ub = varargin_6->f1.size(0);
        for (i = 0; i < loop_ub; i++) {
          s->shiftedData[i] = varargin_6->f1[i];
        }

        s->layerSlds.set_size(varargin_8->f1.size(0), varargin_8->f1.size(1));
        loop_ub = varargin_8->f1.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = varargin_8->f1.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            s->layerSlds[i1 + s->layerSlds.size(0) * i] = varargin_8->f1[i1 +
              varargin_8->f1.size(0) * i];
          }
        }

        s->sldProfiles.set_size(varargin_10->f1.size(0), varargin_10->f1.size(1));
        loop_ub = varargin_10->f1.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = varargin_10->f1.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            s->sldProfiles[i1 + s->sldProfiles.size(0) * i] = varargin_10->f1[i1
              + varargin_10->f1.size(0) * i];
          }
        }

        s->resampledLayers.set_size(varargin_12->f1.size(0),
          varargin_12->f1.size(1));
        loop_ub = varargin_12->f1.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = varargin_12->f1.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            s->resampledLayers[i1 + s->resampledLayers.size(0) * i] =
              varargin_12->f1[i1 + varargin_12->f1.size(0) * i];
          }
        }

        s->calculationResults = *varargin_14;
        s->contrastParams = *varargin_16;
        s->fitParams.set_size(1, f1.size(1));
        loop_ub = f1.size(1);
        for (i = 0; i < loop_ub; i++) {
          s->fitParams[i] = f1[i];
        }

        s->fitNames.set_size(varargin_20->f1.size(0));
        loop_ub = varargin_20->f1.size(0);
        for (i = 0; i < loop_ub; i++) {
          s->fitNames[i] = varargin_20->f1[i];
        }
      }

      void structConstructorHelper(const cell_wrap_34 *varargin_2, const
        cell_wrap_29 *varargin_4, const cell_wrap_34 *varargin_6, const
        cell_wrap_29 *varargin_8, const cell_wrap_35 *varargin_10, ::coder::
        array<cell_wrap_10, 1U> &s_reflectivity, ::coder::array<cell_wrap_10, 2U>
        &s_sld, ::coder::array<cell_wrap_10, 1U> &s_reflectivityXData, ::coder::
        array<cell_wrap_10, 2U> &s_sldXData, real_T s_sampleChi_data[], int32_T *
        s_sampleChi_size)
      {
        int32_T b_loop_ub;
        int32_T i;
        int32_T i1;
        int32_T loop_ub;
        s_reflectivity.set_size(varargin_2->f1.size(0));
        loop_ub = varargin_2->f1.size(0);
        for (i = 0; i < loop_ub; i++) {
          s_reflectivity[i] = varargin_2->f1[i];
        }

        s_sld.set_size(varargin_4->f1.size(0), varargin_4->f1.size(1));
        loop_ub = varargin_4->f1.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = varargin_4->f1.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            s_sld[i1 + s_sld.size(0) * i] = varargin_4->f1[i1 +
              varargin_4->f1.size(0) * i];
          }
        }

        s_reflectivityXData.set_size(varargin_6->f1.size(0));
        loop_ub = varargin_6->f1.size(0);
        for (i = 0; i < loop_ub; i++) {
          s_reflectivityXData[i] = varargin_6->f1[i];
        }

        s_sldXData.set_size(varargin_8->f1.size(0), varargin_8->f1.size(1));
        loop_ub = varargin_8->f1.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = varargin_8->f1.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            s_sldXData[i1 + s_sldXData.size(0) * i] = varargin_8->f1[i1 +
              varargin_8->f1.size(0) * i];
          }
        }

        *s_sampleChi_size = varargin_10->f1.size(0);
        loop_ub = varargin_10->f1.size(0);
        for (i = 0; i < loop_ub; i++) {
          s_sampleChi_data[i] = varargin_10->f1[i];
        }
      }
    }
  }
}

// End of code generation (structConstructorHelper.cpp)
