//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// eml_rand_mt19937ar.h
//
// Code generation for function 'eml_rand_mt19937ar'
//
#ifndef EML_RAND_MT19937AR_H
#define EML_RAND_MT19937AR_H

// Include files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    real_T b_eml_rand_mt19937ar(uint32_T b_state[625]);
    real_T eml_rand_mt19937ar(uint32_T b_state[625]);
    void genrand_uint32_vector(uint32_T mt[625], uint32_T u[2]);
  }
}

#endif

// End of code generation (eml_rand_mt19937ar.h)
