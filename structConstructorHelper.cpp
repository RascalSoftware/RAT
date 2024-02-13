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
      void structConstructorHelper(const cell_wrap_12 *varargin_2, const
        cell_wrap_9 *varargin_4, const cell_wrap_12 *varargin_8, ::coder::array<
        cell_wrap_8, 1U> &s_ref, ::coder::array<cell_wrap_8, 2U> &s_sld, real_T *
        s_chi, ::coder::array<cell_wrap_8, 1U> &s_data)
      {
        int32_T i;
        int32_T loop_ub;
        s_ref.set_size(varargin_2->f1.size(0));
        loop_ub = varargin_2->f1.size(0);
        for (i = 0; i < loop_ub; i++) {
          s_ref[i] = varargin_2->f1[i];
        }

        s_sld.set_size(varargin_4->f1.size(0), varargin_4->f1.size(1));
        loop_ub = varargin_4->f1.size(1);
        for (i = 0; i < loop_ub; i++) {
          int32_T b_loop_ub;
          b_loop_ub = varargin_4->f1.size(0);
          for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
            s_sld[i1 + s_sld.size(0) * i] = varargin_4->f1[i1 +
              varargin_4->f1.size(0) * i];
          }
        }

        s_data.set_size(varargin_8->f1.size(0));
        loop_ub = varargin_8->f1.size(0);
        for (i = 0; i < loop_ub; i++) {
          s_data[i] = varargin_8->f1[i];
        }

        *s_chi = 0.0;
      }

      void structConstructorHelper(const cell_wrap_12 *varargin_2, const
        cell_wrap_9 *varargin_4, const cell_wrap_12 *varargin_6, const
        cell_wrap_9 *varargin_8, const cell_wrap_14 *varargin_10, ::coder::array<
        cell_wrap_8, 1U> &s_refPredInts, ::coder::array<cell_wrap_8, 2U>
        &s_sldPredInts, ::coder::array<cell_wrap_8, 1U> &s_refXdata, ::coder::
        array<cell_wrap_8, 2U> &s_sldXdata, real_T s_sampleChi_data[], int32_T
        *s_sampleChi_size)
      {
        int32_T b_loop_ub;
        int32_T i;
        int32_T i1;
        int32_T loop_ub;
        s_refPredInts.set_size(varargin_2->f1.size(0));
        loop_ub = varargin_2->f1.size(0);
        for (i = 0; i < loop_ub; i++) {
          s_refPredInts[i] = varargin_2->f1[i];
        }

        s_sldPredInts.set_size(varargin_4->f1.size(0), varargin_4->f1.size(1));
        loop_ub = varargin_4->f1.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = varargin_4->f1.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            s_sldPredInts[i1 + s_sldPredInts.size(0) * i] = varargin_4->f1[i1 +
              varargin_4->f1.size(0) * i];
          }
        }

        s_refXdata.set_size(varargin_6->f1.size(0));
        loop_ub = varargin_6->f1.size(0);
        for (i = 0; i < loop_ub; i++) {
          s_refXdata[i] = varargin_6->f1[i];
        }

        s_sldXdata.set_size(varargin_8->f1.size(0), varargin_8->f1.size(1));
        loop_ub = varargin_8->f1.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = varargin_8->f1.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            s_sldXdata[i1 + s_sldXdata.size(0) * i] = varargin_8->f1[i1 +
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
