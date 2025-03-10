//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// validate_print_arguments.cpp
//
// Code generation for function 'validate_print_arguments'
//

// Include files
#include "validate_print_arguments.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void validate_print_arguments(double varargin_1, double varargin_2, double
        varargin_3, double varargin_4, double varargin_5, double
        validatedArguments[5])
      {
        validatedArguments[0] = varargin_1;
        validatedArguments[1] = varargin_2;
        validatedArguments[2] = varargin_3;
        validatedArguments[3] = varargin_4;
        validatedArguments[4] = varargin_5;
      }

      void validate_print_arguments(double varargin_1, double varargin_2, double
        varargin_3, double validatedArguments[3])
      {
        validatedArguments[0] = varargin_1;
        validatedArguments[1] = varargin_2;
        validatedArguments[2] = varargin_3;
      }
    }
  }
}

// End of code generation (validate_print_arguments.cpp)
