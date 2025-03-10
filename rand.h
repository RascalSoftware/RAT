//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// rand.h
//
// Code generation for function 'rand'
//
#ifndef RAND_H
#define RAND_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void b_rand(double r[4]);
    double b_rand();
    void b_rand(double varargin_1, double varargin_2, ::coder::array<double, 2U>
                &r);
    void b_rand(const double varargin_1[2], ::coder::array<double, 1U> &r);
    void b_rand(double varargin_1, ::coder::array<double, 1U> &r);
    void b_rand(double varargin_2, ::coder::array<double, 2U> &r);
    void c_rand(double r[1000]);
  }
}

#endif

// End of code generation (rand.h)
