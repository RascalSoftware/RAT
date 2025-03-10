//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// eml_rand_mt19937ar.h
//
// Code generation for function 'eml_rand_mt19937ar'
//
#ifndef EML_RAND_MT19937AR_H
#define EML_RAND_MT19937AR_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    double b_eml_rand_mt19937ar(unsigned int b_state[625]);
    double eml_rand_mt19937ar(unsigned int b_state[625]);
    void genrand_uint32_vector(unsigned int mt[625], unsigned int u[2]);
  }
}

#endif

// End of code generation (eml_rand_mt19937ar.h)
