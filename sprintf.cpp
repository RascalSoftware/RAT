//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstdio>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_snPrint(double varargin_1, ::coder::array<char, 2U> &str)
    {
      int nbytes;
      nbytes = std::snprintf(nullptr, 0, "Acceptance ratio: %1.4f, \n\n",
        varargin_1);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1),
                    "Acceptance ratio: %1.4f, \n\n", varargin_1);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void b_sprintf(double varargin_3, ::coder::array<char, 2U> &str)
    {
      ::coder::array<char, 2U> b_varargin_4;
      ::coder::array<char, 2U> varargin_4;
      int nbytes;
      varargin_4.set_size(1, 1);
      varargin_4[0] = '\x00';
      b_varargin_4.set_size(1, 1);
      b_varargin_4[0] = '\x00';
      nbytes = std::snprintf(nullptr, 0,
        " %5.0f        %5.0f     %12.6g         %s\n", 0.0, 1.0, varargin_3,
        &b_varargin_4[0]);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1),
                    " %5.0f        %5.0f     %12.6g         %s\n", 0.0, 1.0,
                    varargin_3, &varargin_4[0]);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void b_sprintf(const char varargin_1_data[], const int varargin_1_size[2], ::
                   coder::array<char, 2U> &str)
    {
      int nbytes;
      char b_varargin_1_data[10001];
      char c_varargin_1_data[10001];
      nbytes = varargin_1_size[1];
      if (nbytes - 1 >= 0) {
        std::copy(&varargin_1_data[0], &varargin_1_data[nbytes],
                  &b_varargin_1_data[0]);
        std::copy(&varargin_1_data[0], &varargin_1_data[nbytes],
                  &c_varargin_1_data[0]);
      }

      b_varargin_1_data[varargin_1_size[1]] = '\x00';
      c_varargin_1_data[varargin_1_size[1]] = '\x00';
      nbytes = std::snprintf(nullptr, 0,
        "The model type \"%s\" is not supported", &c_varargin_1_data[0]);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1),
                    "The model type \"%s\" is not supported",
                    &b_varargin_1_data[0]);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void b_sprintf(const char varargin_1[3], ::coder::array<char, 2U> &str)
    {
      int nbytes;
      char b_varargin_1[4];
      char c_varargin_1[4];
      b_varargin_1[3] = '\x00';
      b_varargin_1[0] = varargin_1[0];
      c_varargin_1[0] = varargin_1[0];
      b_varargin_1[1] = varargin_1[1];
      c_varargin_1[1] = varargin_1[1];
      b_varargin_1[2] = varargin_1[2];
      c_varargin_1[2] = varargin_1[2];
      c_varargin_1[3] = '\x00';
      nbytes = std::snprintf(nullptr, 0, "\'%s\'\n", &c_varargin_1[0]);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1), "\'%s\'\n", &b_varargin_1[0]);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void b_sprintf(double varargin_1, double varargin_2, int varargin_3, int
                   varargin_4, double varargin_5, ::coder::array<char, 2U> &str)
    {
      int nbytes;
      nbytes = std::snprintf(nullptr, 0,
        "log(Z): %.5e, tol = %.5e, K = %d, iteration = %d, H = %.5e\n",
        varargin_1, varargin_2, varargin_3, varargin_4, varargin_5);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1),
                    "log(Z): %.5e, tol = %.5e, K = %d, iteration = %d, H = %.5e\n",
                    varargin_1, varargin_2, varargin_3, varargin_4, varargin_5);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void b_sprintf(const ::coder::array<char, 2U> &varargin_1, ::coder::array<
                   char, 2U> &str)
    {
      ::coder::array<char, 2U> b_varargin_1;
      ::coder::array<char, 2U> c_varargin_1;
      int nbytes;
      b_varargin_1.set_size(1, varargin_1.size(1) + 1);
      nbytes = varargin_1.size(1);
      for (int i{0}; i < nbytes; i++) {
        b_varargin_1[i] = varargin_1[i];
      }

      b_varargin_1[varargin_1.size(1)] = '\x00';
      c_varargin_1.set_size(1, varargin_1.size(1) + 1);
      nbytes = varargin_1.size(1);
      for (int i{0}; i < nbytes; i++) {
        c_varargin_1[i] = varargin_1[i];
      }

      c_varargin_1[varargin_1.size(1)] = '\x00';
      nbytes = std::snprintf(nullptr, 0, "\n%s\n", &c_varargin_1[0]);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1), "\n%s\n", &b_varargin_1[0]);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void b_sprintf(double varargin_1, double varargin_2, ::coder::array<char, 2U>
                   &str)
    {
      int nbytes;
      nbytes = std::snprintf(nullptr, 0,
        "Exiting - X satisfies termination criteria: TolX %e, TolF %e",
        varargin_1, varargin_2);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1),
                    "Exiting - X satisfies termination criteria: TolX %e, TolF %e",
                    varargin_1, varargin_2);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void b_sprintf(double varargin_1, double varargin_2, double varargin_3,
                   const char varargin_4_data[], const int varargin_4_size[2], ::
                   coder::array<char, 2U> &str)
    {
      ::coder::array<char, 2U> b_varargin_4;
      ::coder::array<char, 2U> varargin_4;
      int nbytes;
      varargin_4.set_size(1, varargin_4_size[1] + 1);
      nbytes = varargin_4_size[1];
      b_varargin_4.set_size(1, varargin_4_size[1] + 1);
      for (int i{0}; i < nbytes; i++) {
        char c;
        c = varargin_4_data[i];
        varargin_4[i] = c;
        b_varargin_4[i] = c;
      }

      varargin_4[varargin_4_size[1]] = '\x00';
      b_varargin_4[varargin_4_size[1]] = '\x00';
      nbytes = std::snprintf(nullptr, 0,
        " %5.0f        %5.0f     %12.6g         %s\n", varargin_1, varargin_2,
        varargin_3, &b_varargin_4[0]);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1),
                    " %5.0f        %5.0f     %12.6g         %s\n", varargin_1,
                    varargin_2, varargin_3, &varargin_4[0]);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void b_sprintf(double varargin_2, double varargin_3, const char
                   varargin_4_data[], ::coder::array<char, 2U> &str)
    {
      ::coder::array<char, 2U> b_varargin_4;
      ::coder::array<char, 2U> varargin_4;
      int nbytes;
      varargin_4.set_size(1, 16);
      b_varargin_4.set_size(1, 16);
      for (nbytes = 0; nbytes < 15; nbytes++) {
        char c;
        c = varargin_4_data[nbytes];
        varargin_4[nbytes] = c;
        b_varargin_4[nbytes] = c;
      }

      varargin_4[15] = '\x00';
      b_varargin_4[15] = '\x00';
      nbytes = std::snprintf(nullptr, 0,
        " %5.0f        %5.0f     %12.6g         %s\n", 1.0, varargin_2,
        varargin_3, &b_varargin_4[0]);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1),
                    " %5.0f        %5.0f     %12.6g         %s\n", 1.0,
                    varargin_2, varargin_3, &varargin_4[0]);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void c_snPrint(double varargin_1, ::coder::array<char, 2U> &str)
    {
      int nbytes;
      nbytes = std::snprintf(nullptr, 0, "%.8g\n", varargin_1);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1), "%.8g\n", varargin_1);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void c_sprintf(const char varargin_1_data[], const int varargin_1_size[2], ::
                   coder::array<char, 2U> &str)
    {
      int nbytes;
      char b_varargin_1_data[10001];
      char c_varargin_1_data[10001];
      nbytes = varargin_1_size[1];
      if (nbytes - 1 >= 0) {
        std::copy(&varargin_1_data[0], &varargin_1_data[nbytes],
                  &b_varargin_1_data[0]);
        std::copy(&varargin_1_data[0], &varargin_1_data[nbytes],
                  &c_varargin_1_data[0]);
      }

      b_varargin_1_data[varargin_1_size[1]] = '\x00';
      c_varargin_1_data[varargin_1_size[1]] = '\x00';
      nbytes = std::snprintf(nullptr, 0,
        "\"%s\" does not represent a valid contrast background action.",
        &c_varargin_1_data[0]);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1),
                    "\"%s\" does not represent a valid contrast background action.",
                    &b_varargin_1_data[0]);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void d_sprintf(const char varargin_1_data[], const int varargin_1_size[2], ::
                   coder::array<char, 2U> &str)
    {
      int nbytes;
      char b_varargin_1_data[10001];
      char c_varargin_1_data[10001];
      nbytes = varargin_1_size[1];
      if (nbytes - 1 >= 0) {
        std::copy(&varargin_1_data[0], &varargin_1_data[nbytes],
                  &b_varargin_1_data[0]);
        std::copy(&varargin_1_data[0], &varargin_1_data[nbytes],
                  &c_varargin_1_data[0]);
      }

      b_varargin_1_data[varargin_1_size[1]] = '\x00';
      c_varargin_1_data[varargin_1_size[1]] = '\x00';
      nbytes = std::snprintf(nullptr, 0,
        "The calculation type \"%s\" is not supported", &c_varargin_1_data[0]);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1),
                    "The calculation type \"%s\" is not supported",
                    &b_varargin_1_data[0]);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void e_sprintf(const char varargin_1_data[], const int varargin_1_size[2], ::
                   coder::array<char, 2U> &str)
    {
      int nbytes;
      char b_varargin_1_data[6];
      char c_varargin_1_data[6];
      nbytes = varargin_1_size[1];
      if (nbytes - 1 >= 0) {
        std::copy(&varargin_1_data[0], &varargin_1_data[nbytes],
                  &b_varargin_1_data[0]);
        std::copy(&varargin_1_data[0], &varargin_1_data[nbytes],
                  &c_varargin_1_data[0]);
      }

      b_varargin_1_data[varargin_1_size[1]] = '\x00';
      c_varargin_1_data[varargin_1_size[1]] = '\x00';
      nbytes = std::snprintf(nullptr, 0, "%s\n", &c_varargin_1_data[0]);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1), "%s\n", &b_varargin_1_data[0]);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void snPrint(double varargin_1, double varargin_2, double varargin_3, double
                 varargin_4, double varargin_5, ::coder::array<char, 2U> &str)
    {
      int nbytes;
      nbytes = std::snprintf(nullptr, 0,
        "Iteration: %g,  Best: %f,  fWeight: %f,  F_CR: %f,  I_NP: %g\n\n",
        varargin_1, varargin_2, varargin_3, varargin_4, varargin_5);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1),
                    "Iteration: %g,  Best: %f,  fWeight: %f,  F_CR: %f,  I_NP: %g\n\n",
                    varargin_1, varargin_2, varargin_3, varargin_4, varargin_5);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void snPrint(double varargin_1, ::coder::array<char, 2U> &str)
    {
      int nbytes;
      nbytes = std::snprintf(nullptr, 0, "Final chi squared is %g\n", varargin_1);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1), "Final chi squared is %g\n",
                    varargin_1);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void snPrint(double varargin_1, double varargin_2, ::coder::array<char, 2U>
                 &str)
    {
      int nbytes;
      nbytes = std::snprintf(nullptr, 0, "[%gx%g %s]\n", varargin_1, varargin_2,
        "double");
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1), "[%gx%g %s]\n", varargin_1,
                    varargin_2, "double");
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void snPrint(const ::coder::array<char, 2U> &varargin_1, const ::coder::
                 array<char, 2U> &varargin_2, ::coder::array<char, 2U> &str)
    {
      ::coder::array<char, 2U> b_varargin_1;
      ::coder::array<char, 2U> b_varargin_2;
      int loop_ub;
      int nbytes;
      b_varargin_1.set_size(1, varargin_1.size(1));
      loop_ub = varargin_1.size(1);
      for (int i{0}; i < loop_ub; i++) {
        b_varargin_1[i] = varargin_1[i];
      }

      b_varargin_2.set_size(1, varargin_2.size(1));
      loop_ub = varargin_2.size(1);
      for (int i{0}; i < loop_ub; i++) {
        b_varargin_2[i] = varargin_2[i];
      }

      nbytes = std::snprintf(nullptr, 0,
        "The procedure \"%s\" is not supported. The procedure must be one of \"%s\"",
        &b_varargin_1[0], &b_varargin_2[0]);
      str.set_size(1, nbytes + 1);
      b_varargin_1.set_size(1, varargin_1.size(1));
      loop_ub = varargin_1.size(1);
      for (int i{0}; i < loop_ub; i++) {
        b_varargin_1[i] = varargin_1[i];
      }

      b_varargin_2.set_size(1, varargin_2.size(1));
      loop_ub = varargin_2.size(1);
      for (int i{0}; i < loop_ub; i++) {
        b_varargin_2[i] = varargin_2[i];
      }

      std::snprintf(&str[0], (size_t)(nbytes + 1),
                    "The procedure \"%s\" is not supported. The procedure must be one of \"%s\"",
                    &b_varargin_1[0], &b_varargin_2[0]);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }

    void snPrint(double varargin_1, double varargin_2, double varargin_3, ::
                 coder::array<char, 2U> &str)
    {
      int nbytes;
      nbytes = std::snprintf(nullptr, 0,
        "The output of the custom function with size %.0f does not match the specified size (%.0f x %.0f).",
        varargin_1, varargin_2, varargin_3);
      str.set_size(1, nbytes + 1);
      std::snprintf(&str[0], (size_t)(nbytes + 1),
                    "The output of the custom function with size %.0f does not match the specified size (%.0f x %.0f).",
                    varargin_1, varargin_2, varargin_3);
      if (nbytes < 1) {
        nbytes = 0;
      }

      str.set_size(str.size(0), nbytes);
    }
  }
}

// End of code generation (sprintf.cpp)
