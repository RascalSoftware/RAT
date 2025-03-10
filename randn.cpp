//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// randn.cpp
//
// Code generation for function 'randn'
//

// Include files
#include "randn.h"
#include "RATMain_data.h"
#include "eml_rand_mt19937ar.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void randn(double varargin_2, ::coder::array<double, 2U> &r)
    {
      int i;
      i = static_cast<int>(varargin_2);
      r.set_size(1, i);
      for (int k{0}; k < i; k++) {
        r[k] = b_eml_rand_mt19937ar(state);
      }
    }

    void randn(double varargin_1, ::coder::array<double, 1U> &r)
    {
      int i;
      i = static_cast<int>(varargin_1);
      r.set_size(i);
      for (int k{0}; k < i; k++) {
        r[k] = b_eml_rand_mt19937ar(state);
      }
    }

    void randn(double r[2])
    {
      for (int k{0}; k < 2; k++) {
        double b_r;
        unsigned int u32[2];
        int exitg1;
        int i;
        do {
          exitg1 = 0;
          genrand_uint32_vector(state, u32);
          i = static_cast<int>((u32[1] >> 24U) + 1U);
          b_r = ((static_cast<double>(u32[0] >> 3U) * 1.6777216E+7 +
                  static_cast<double>(static_cast<int>(u32[1]) & 16777215)) *
                 2.2204460492503131E-16 - 1.0) * dv[i];
          if (std::abs(b_r) <= dv[i - 1]) {
            exitg1 = 1;
          } else if (i < 256) {
            double u;
            u = eml_rand_mt19937ar(state);
            if (dv1[i] + u * (dv1[i - 1] - dv1[i]) < std::exp(-0.5 * b_r * b_r))
            {
              exitg1 = 1;
            }
          } else {
            double u;
            double x;
            do {
              u = eml_rand_mt19937ar(state);
              x = std::log(u) * 0.273661237329758;
              u = eml_rand_mt19937ar(state);
            } while (!(-2.0 * std::log(u) > x * x));

            if (b_r < 0.0) {
              b_r = x - 3.65415288536101;
            } else {
              b_r = 3.65415288536101 - x;
            }

            exitg1 = 1;
          }
        } while (exitg1 == 0);

        r[k] = b_r;
      }
    }

    void randn(double varargin_1, double varargin_2, ::coder::array<double, 2U>
               &r)
    {
      int i;
      r.set_size(static_cast<int>(varargin_1), static_cast<int>(varargin_2));
      i = static_cast<int>(varargin_1) * static_cast<int>(varargin_2);
      for (int k{0}; k < i; k++) {
        r[k] = b_eml_rand_mt19937ar(state);
      }
    }
  }
}

// End of code generation (randn.cpp)
