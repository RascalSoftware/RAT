//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sprintf.cpp
//
// Code generation for function 'sprintf'
//

// Include files
#include "sprintf.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <algorithm>
#include <cstddef>
#include <stdio.h>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_snPrint(double varargin_1, ::coder::array<char, 2U> &str)
    {
      int nbytes;
      nbytes = snprintf(nullptr, 0, "Acceptance ratio: %1.4f, \n\n", varargin_1);
      str.set_size(1, nbytes + 1);
      snprintf(&str[0], (size_t)(nbytes + 1), "Acceptance ratio: %1.4f, \n\n",
               varargin_1);
      if (1 > nbytes) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void b_sprintf(double varargin_1, double varargin_2, ::coder::array<char, 2U>
                   &str)
    {
      int nbytes;
      nbytes = snprintf(nullptr, 0,
                        "Exiting - X satisfies termination criteria: TolX %e, TolF %e",
                        varargin_1, varargin_2);
      str.set_size(1, nbytes + 1);
      snprintf(&str[0], (size_t)(nbytes + 1),
               "Exiting - X satisfies termination criteria: TolX %e, TolF %e",
               varargin_1, varargin_2);
      if (1 > nbytes) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void b_sprintf(double varargin_1, double varargin_2, int varargin_3, int
                   varargin_4, double varargin_5, ::coder::array<char, 2U> &str)
    {
      int nbytes;
      nbytes = snprintf(nullptr, 0,
                        "log(Z): %.5e, tol = %.5e, K = %d, iteration = %d, H = %.5e\n",
                        varargin_1, varargin_2, varargin_3, varargin_4,
                        varargin_5);
      str.set_size(1, nbytes + 1);
      snprintf(&str[0], (size_t)(nbytes + 1),
               "log(Z): %.5e, tol = %.5e, K = %d, iteration = %d, H = %.5e\n",
               varargin_1, varargin_2, varargin_3, varargin_4, varargin_5);
      if (1 > nbytes) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void c_snPrint(double varargin_1, ::coder::array<char, 2U> &str)
    {
      int nbytes;
      nbytes = snprintf(nullptr, 0, "%.8g\n", varargin_1);
      str.set_size(1, nbytes + 1);
      snprintf(&str[0], (size_t)(nbytes + 1), "%.8g\n", varargin_1);
      if (1 > nbytes) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void snPrint(double varargin_1, double varargin_2, double varargin_3, const
                 char varargin_4_data[], const int varargin_4_size[2], ::coder::
                 array<char, 2U> &str)
    {
      int loop_ub;
      int nbytes;
      char b_varargin_4_data[17];
      loop_ub = varargin_4_size[1];
      if (0 <= loop_ub - 1) {
        std::copy(&varargin_4_data[0], &varargin_4_data[loop_ub],
                  &b_varargin_4_data[0]);
      }

      nbytes = snprintf(nullptr, 0,
                        " %5.0f        %5.0f     %12.6g         %s\n",
                        varargin_1, varargin_2, varargin_3, &b_varargin_4_data[0]);
      str.set_size(1, nbytes + 1);
      loop_ub = varargin_4_size[1];
      if (0 <= loop_ub - 1) {
        std::copy(&varargin_4_data[0], &varargin_4_data[loop_ub],
                  &b_varargin_4_data[0]);
      }

      snprintf(&str[0], (size_t)(nbytes + 1),
               " %5.0f        %5.0f     %12.6g         %s\n", varargin_1,
               varargin_2, varargin_3, &b_varargin_4_data[0]);
      if (1 > nbytes) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void snPrint(const ::coder::array<char, 2U> &varargin_1, ::coder::array<char,
                 2U> &str)
    {
      ::coder::array<char, 2U> b_varargin_1;
      int i;
      int loop_ub;
      int nbytes;
      b_varargin_1.set_size(1, varargin_1.size(1));
      loop_ub = varargin_1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_varargin_1[i] = varargin_1[i];
      }

      nbytes = snprintf(nullptr, 0, "\n%s\n", &b_varargin_1[0]);
      str.set_size(1, nbytes + 1);
      b_varargin_1.set_size(1, varargin_1.size(1));
      loop_ub = varargin_1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_varargin_1[i] = varargin_1[i];
      }

      snprintf(&str[0], (size_t)(nbytes + 1), "\n%s\n", &b_varargin_1[0]);
      if (1 > nbytes) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void snPrint(double varargin_1, double varargin_2, double varargin_3, double
                 varargin_4, double varargin_5, ::coder::array<char, 2U> &str)
    {
      int nbytes;
      nbytes = snprintf(nullptr, 0,
                        "Iteration: %g,  Best: %f,  fWeight: %f,  F_CR: %f,  I_NP: %g\n\n",
                        varargin_1, varargin_2, varargin_3, varargin_4,
                        varargin_5);
      str.set_size(1, nbytes + 1);
      snprintf(&str[0], (size_t)(nbytes + 1),
               "Iteration: %g,  Best: %f,  fWeight: %f,  F_CR: %f,  I_NP: %g\n\n",
               varargin_1, varargin_2, varargin_3, varargin_4, varargin_5);
      if (1 > nbytes) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void snPrint(double varargin_1, ::coder::array<char, 2U> &str)
    {
      int nbytes;
      nbytes = snprintf(nullptr, 0, "Final chi squared is %g\n", varargin_1);
      str.set_size(1, nbytes + 1);
      snprintf(&str[0], (size_t)(nbytes + 1), "Final chi squared is %g\n",
               varargin_1);
      if (1 > nbytes) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void snPrint(const char varargin_1[4], ::coder::array<char, 2U> &str)
    {
      int nbytes;
      char b_varargin_1[4];
      b_varargin_1[0] = varargin_1[0];
      b_varargin_1[1] = varargin_1[1];
      b_varargin_1[2] = varargin_1[2];
      b_varargin_1[3] = varargin_1[3];
      nbytes = snprintf(nullptr, 0, "\'%s\'\n", &b_varargin_1[0]);
      str.set_size(1, nbytes + 1);
      b_varargin_1[0] = varargin_1[0];
      b_varargin_1[1] = varargin_1[1];
      b_varargin_1[2] = varargin_1[2];
      b_varargin_1[3] = varargin_1[3];
      snprintf(&str[0], (size_t)(nbytes + 1), "\'%s\'\n", &b_varargin_1[0]);
      if (1 > nbytes) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void snPrint(const char varargin_1_data[], const int varargin_1_size[2], ::
                 coder::array<char, 2U> &str)
    {
      int loop_ub;
      int nbytes;
      char b_varargin_1_data[6];
      loop_ub = varargin_1_size[1];
      if (0 <= loop_ub - 1) {
        std::copy(&varargin_1_data[0], &varargin_1_data[loop_ub],
                  &b_varargin_1_data[0]);
      }

      nbytes = snprintf(nullptr, 0, "%s\n", &b_varargin_1_data[0]);
      str.set_size(1, nbytes + 1);
      loop_ub = varargin_1_size[1];
      if (0 <= loop_ub - 1) {
        std::copy(&varargin_1_data[0], &varargin_1_data[loop_ub],
                  &b_varargin_1_data[0]);
      }

      snprintf(&str[0], (size_t)(nbytes + 1), "%s\n", &b_varargin_1_data[0]);
      if (1 > nbytes) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void snPrint(double varargin_1, double varargin_2, const char *varargin_3, ::
                 coder::array<char, 2U> &str)
    {
      int nbytes;
      nbytes = snprintf(nullptr, 0, "[%gx%g %s]\n", varargin_1, varargin_2,
                        varargin_3);
      str.set_size(1, nbytes + 1);
      snprintf(&str[0], (size_t)(nbytes + 1), "[%gx%g %s]\n", varargin_1,
               varargin_2, varargin_3);
      if (1 > nbytes) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }
  }
}

// End of code generation (sprintf.cpp)
