//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// repmat.cpp
//
// Code generation for function 'repmat'
//

// Include files
#include "repmat.h"
#include "RATMain_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_repmat(const ::coder::array<double, 2U> &a, double varargin_1, ::
                  coder::array<double, 2U> &b)
    {
      b.set_size(static_cast<int>(varargin_1), a.size(1));
      if ((static_cast<int>(varargin_1) != 0) && (a.size(1) != 0)) {
        int i;
        int na;
        na = a.size(1);
        i = static_cast<int>(varargin_1) - 1;
        for (int k{0}; k < na; k++) {
          for (int t{0}; t <= i; t++) {
            b[t + b.size(0) * k] = a[k];
          }
        }
      }
    }

    void repmat(double varargin_1, ::coder::array<k_struct_T, 1U> &b)
    {
      int loop_ub_tmp;
      loop_ub_tmp = static_cast<int>(varargin_1);
      b.set_size(loop_ub_tmp);
      for (int i{0}; i < loop_ub_tmp; i++) {
        b[i].I_no = 0.0;
        b[i].FVr_oa = 0.0;
      }
    }

    void repmat(const ::coder::array<double, 2U> &a, double varargin_1, ::coder::
                array<double, 2U> &b)
    {
      int i;
      i = a.size(0) * static_cast<int>(varargin_1);
      b.set_size(i, a.size(1));
      if (i != 0) {
        int i1;
        int na;
        i = a.size(1);
        na = a.size(0);
        i1 = static_cast<int>(varargin_1) - 1;
        for (int k{0}; k < i; k++) {
          for (int t{0}; t <= i1; t++) {
            int offset;
            offset = t * na;
            for (int b_k{0}; b_k < na; b_k++) {
              b[(offset + b_k) + b.size(0) * k] = a[b_k + a.size(0) * k];
            }
          }
        }
      }
    }

    void repmat(const double a[2], double varargin_1, ::coder::array<double, 2U>
                &b)
    {
      b.set_size(static_cast<int>(varargin_1), 2);
      if (static_cast<int>(varargin_1) != 0) {
        int i;
        i = static_cast<int>(varargin_1) - 1;
        for (int k{0}; k < 2; k++) {
          for (int t{0}; t <= i; t++) {
            b[t + b.size(0) * k] = a[k];
          }
        }
      }
    }
  }
}

// End of code generation (repmat.cpp)
