//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// repmat.cpp
//
// Code generation for function 'repmat'
//

// Include files
#include "repmat.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_repmat(real_T varargin_2, ::coder::array<char_T, 2U> &b)
    {
      int32_T loop_ub_tmp;
      loop_ub_tmp = static_cast<int32_T>(varargin_2);
      b.set_size(1, loop_ub_tmp);
      for (int32_T i{0}; i < loop_ub_tmp; i++) {
        b[i] = '.';
      }
    }

    void repmat(cell_wrap_9 b[6])
    {
      cell_wrap_8 r;
      r.f1.set_size(1, 1);
      r.f1[0] = 1.0;
      for (int32_T jtilecol{0}; jtilecol < 6; jtilecol++) {
        b[jtilecol].f1.set_size(1, 1);
        b[jtilecol].f1[0] = r;
      }
    }

    void repmat(real_T varargin_1, ::coder::array<struct_T, 1U> &b)
    {
      int32_T loop_ub_tmp;
      loop_ub_tmp = static_cast<int32_T>(varargin_1);
      b.set_size(loop_ub_tmp);
      for (int32_T i{0}; i < loop_ub_tmp; i++) {
        b[i].I_nc = 0.0;
        b[i].FVr_ca = 0.0;
        b[i].I_no = 0.0;
        b[i].FVr_oa = 0.0;
      }
    }

    void repmat(const ::coder::array<real_T, 2U> &a, real_T varargin_1, ::coder::
                array<real_T, 2U> &b)
    {
      b.set_size(static_cast<int32_T>(varargin_1), a.size(1));
      if ((static_cast<int32_T>(varargin_1) != 0) && (a.size(1) != 0)) {
        int32_T na;
        na = a.size(1);
        for (int32_T k{0}; k < na; k++) {
          int32_T i;
          i = static_cast<int32_T>(varargin_1) - 1;
          for (int32_T t{0}; t <= i; t++) {
            b[t + b.size(0) * k] = a[k];
          }
        }
      }
    }

    void repmat(real_T varargin_2, ::coder::array<char_T, 2U> &b)
    {
      int32_T loop_ub_tmp;
      loop_ub_tmp = static_cast<int32_T>(varargin_2);
      b.set_size(1, loop_ub_tmp);
      for (int32_T i{0}; i < loop_ub_tmp; i++) {
        b[i] = '*';
      }
    }

    void repmat(const real_T a[2], real_T varargin_1, ::coder::array<real_T, 2U>
                &b)
    {
      b.set_size(static_cast<int32_T>(varargin_1), 2);
      if (static_cast<int32_T>(varargin_1) != 0) {
        int32_T i;
        i = static_cast<int32_T>(varargin_1) - 1;
        for (int32_T k{0}; k < 2; k++) {
          for (int32_T t{0}; t <= i; t++) {
            b[t + b.size(0) * k] = a[k];
          }
        }
      }
    }
  }
}

// End of code generation (repmat.cpp)
