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
      void structConstructorHelper(const cell_wrap_38 *varargin_2, const
        cell_wrap_39 *varargin_4, const cell_wrap_40 *varargin_6, const
        cell_wrap_41 *varargin_8, const cell_wrap_36 *varargin_10, ::coder::
        array<cell_wrap_11, 1U> &s_reflectivity, ::coder::array<cell_wrap_11, 2U>
        &s_sld, ::coder::array<cell_wrap_12, 1U> &s_reflectivityXData, ::coder::
        array<cell_wrap_12, 2U> &s_sldXData, real_T s_sampleChi_data[], int32_T *
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
