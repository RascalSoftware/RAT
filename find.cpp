//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// find.cpp
//
// Code generation for function 'find'
//

// Include files
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_eml_find(const ::coder::array<boolean_T, 1U> &x, int i_data[], int
                    *i_size)
    {
      int idx;
      int ii;
      boolean_T exitg1;
      *i_size = (1 <= x.size(0));
      ii = x.size(0);
      idx = 0;
      exitg1 = false;
      while ((!exitg1) && (ii > 0)) {
        if (x[ii - 1]) {
          idx = 1;
          i_data[0] = ii;
          exitg1 = true;
        } else {
          ii--;
        }
      }

      if (*i_size == 1) {
        if (idx == 0) {
          *i_size = 0;
        }
      } else {
        *i_size = (1 <= idx);
      }
    }

    void c_eml_find(const ::coder::array<boolean_T, 1U> &x, ::coder::array<int,
                    1U> &i)
    {
      int idx;
      int ii;
      int k;
      boolean_T exitg1;
      k = (1 <= x.size(0));
      idx = 0;
      i.set_size(k);
      ii = 0;
      exitg1 = false;
      while ((!exitg1) && (ii <= x.size(0) - 1)) {
        if (x[ii]) {
          idx++;
          i[idx - 1] = ii + 1;
          if (idx >= k) {
            exitg1 = true;
          } else {
            ii++;
          }
        } else {
          ii++;
        }
      }

      if (k == 1) {
        if (idx == 0) {
          i.set_size(0);
        }
      } else {
        i.set_size(static_cast<int>(1 <= idx));
      }
    }

    void d_eml_find(const ::coder::array<double, 2U> &x, int i_data[], int
                    i_size[2])
    {
      int idx;
      int ii;
      int nx;
      boolean_T exitg1;
      nx = x.size(1);
      idx = 0;
      i_size[0] = 1;
      i_size[1] = x.size(1);
      ii = 0;
      exitg1 = false;
      while ((!exitg1) && (ii <= nx - 1)) {
        if (x[ii] != 0.0) {
          idx++;
          i_data[idx - 1] = ii + 1;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            ii++;
          }
        } else {
          ii++;
        }
      }

      if (x.size(1) == 1) {
        if (idx == 0) {
          i_size[0] = 1;
          i_size[1] = 0;
        }
      } else if (1 > idx) {
        i_size[1] = 0;
      } else {
        i_size[1] = idx;
      }
    }

    void e_eml_find(const boolean_T x[2], int i_data[], int i_size[2])
    {
      int idx;
      int ii;
      boolean_T exitg1;
      idx = 0;
      i_size[0] = 1;
      ii = 0;
      exitg1 = false;
      while ((!exitg1) && (ii < 2)) {
        if (x[ii]) {
          idx++;
          i_data[idx - 1] = ii + 1;
          if (idx >= 2) {
            exitg1 = true;
          } else {
            ii++;
          }
        } else {
          ii++;
        }
      }

      if (1 > idx) {
        i_size[1] = 0;
      } else {
        i_size[1] = idx;
      }
    }

    void eml_find(const ::coder::array<boolean_T, 1U> &x, ::coder::array<int, 1U>
                  &i)
    {
      int idx;
      int ii;
      int nx;
      boolean_T exitg1;
      nx = x.size(0);
      idx = 0;
      i.set_size(x.size(0));
      ii = 0;
      exitg1 = false;
      while ((!exitg1) && (ii <= nx - 1)) {
        if (x[ii]) {
          idx++;
          i[idx - 1] = ii + 1;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            ii++;
          }
        } else {
          ii++;
        }
      }

      if (x.size(0) == 1) {
        if (idx == 0) {
          i.set_size(0);
        }
      } else {
        if (1 > idx) {
          idx = 0;
        }

        i.set_size(idx);
      }
    }

    void f_eml_find(const ::coder::array<boolean_T, 2U> &x, ::coder::array<int,
                    1U> &i)
    {
      int idx;
      int ii;
      int nx;
      boolean_T exitg1;
      nx = x.size(0) * x.size(1);
      idx = 0;
      i.set_size(nx);
      ii = 0;
      exitg1 = false;
      while ((!exitg1) && (ii <= nx - 1)) {
        if (x[ii]) {
          idx++;
          i[idx - 1] = ii + 1;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            ii++;
          }
        } else {
          ii++;
        }
      }

      if (nx == 1) {
        if (idx == 0) {
          i.set_size(0);
        }
      } else {
        if (1 > idx) {
          idx = 0;
        }

        i.set_size(idx);
      }
    }

    void g_eml_find(const ::coder::array<boolean_T, 2U> &x, ::coder::array<int,
                    2U> &i)
    {
      int idx;
      int ii;
      int nx;
      boolean_T exitg1;
      nx = x.size(1);
      idx = 0;
      i.set_size(1, x.size(1));
      ii = 0;
      exitg1 = false;
      while ((!exitg1) && (ii <= nx - 1)) {
        if (x[ii]) {
          idx++;
          i[idx - 1] = ii + 1;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            ii++;
          }
        } else {
          ii++;
        }
      }

      if (x.size(1) == 1) {
        if (idx == 0) {
          i.set_size(1, 0);
        }
      } else {
        if (1 > idx) {
          idx = 0;
        }

        i.set_size(i.size(0), idx);
      }
    }
  }
}

// End of code generation (find.cpp)
