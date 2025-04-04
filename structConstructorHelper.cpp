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
    }
  }
}

// End of code generation (structConstructorHelper.cpp)
