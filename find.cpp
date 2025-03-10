//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
  void binary_expand_op(::coder::array<int, 1U> &in1, const ::coder::array<
                        double, 1U> &in2, const ::coder::array<double, 1U> &in3)
  {
    ::coder::array<boolean_T, 1U> b_in2;
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    b_in2.set_size(loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in3.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      b_in2[i] = (in2[i * stride_0_0] > in3[i * stride_1_0]);
    }

    coder::eml_find(b_in2, in1);
  }

  void binary_expand_op(::coder::array<int, 1U> &in1, const ::coder::array<
                        double, 2U> &in2, const ::coder::array<double, 2U> &in3)
  {
    ::coder::array<boolean_T, 2U> b_in2;
    int aux_0_1;
    int aux_1_1;
    int b_loop_ub;
    int loop_ub;
    int stride_0_0;
    int stride_0_1;
    int stride_1_0;
    int stride_1_1;
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    if (in3.size(1) == 1) {
      b_loop_ub = in2.size(1);
    } else {
      b_loop_ub = in3.size(1);
    }

    b_in2.set_size(loop_ub, b_loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_0 = (in3.size(0) != 1);
    stride_1_1 = (in3.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (int i{0}; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        b_in2[i1 + b_in2.size(0) * i] = (in2[i1 * stride_0_0 + in2.size(0) *
          aux_0_1] > in3[i1 * stride_1_0 + in3.size(0) * aux_1_1]);
      }

      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }

    coder::f_eml_find(b_in2, in1);
  }

  void c_binary_expand_op(::coder::array<int, 1U> &in1, const ::coder::array<
    double, 2U> &in2, const ::coder::array<double, 2U> &in3)
  {
    ::coder::array<boolean_T, 2U> b_in2;
    int aux_0_1;
    int aux_1_1;
    int b_loop_ub;
    int loop_ub;
    int stride_0_0;
    int stride_0_1;
    int stride_1_0;
    int stride_1_1;
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    if (in3.size(1) == 1) {
      b_loop_ub = in2.size(1);
    } else {
      b_loop_ub = in3.size(1);
    }

    b_in2.set_size(loop_ub, b_loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_0 = (in3.size(0) != 1);
    stride_1_1 = (in3.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (int i{0}; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        b_in2[i1 + b_in2.size(0) * i] = (in2[i1 * stride_0_0 + in2.size(0) *
          aux_0_1] < in3[i1 * stride_1_0 + in3.size(0) * aux_1_1]);
      }

      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }

    coder::f_eml_find(b_in2, in1);
  }

  namespace coder
  {
    int b_eml_find(const ::coder::array<boolean_T, 1U> &x, int i_data[])
    {
      int i_size;
      int idx;
      int ii;
      boolean_T exitg1;
      i_size = (x.size(0) >= 1);
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

      if (i_size == 1) {
        if (idx == 0) {
          i_size = 0;
        }
      } else {
        i_size = (idx >= 1);
      }

      return i_size;
    }

    void c_eml_find(const ::coder::array<boolean_T, 1U> &x, ::coder::array<int,
                    1U> &i)
    {
      int idx;
      int ii;
      int k;
      boolean_T exitg1;
      k = (x.size(0) >= 1);
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
        i.set_size(static_cast<int>(idx >= 1));
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
      } else if (idx < 1) {
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

      if (idx < 1) {
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
        if (idx < 1) {
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
      int nx_tmp;
      boolean_T exitg1;
      nx_tmp = x.size(0) * x.size(1);
      idx = 0;
      i.set_size(nx_tmp);
      ii = 0;
      exitg1 = false;
      while ((!exitg1) && (ii <= nx_tmp - 1)) {
        if (x[ii]) {
          idx++;
          i[idx - 1] = ii + 1;
          if (idx >= nx_tmp) {
            exitg1 = true;
          } else {
            ii++;
          }
        } else {
          ii++;
        }
      }

      if (nx_tmp == 1) {
        if (idx == 0) {
          i.set_size(0);
        }
      } else {
        if (idx < 1) {
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
        if (idx < 1) {
          idx = 0;
        }

        i.set_size(i.size(0), idx);
      }
    }
  }
}

// End of code generation (find.cpp)
