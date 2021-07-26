//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// relop.cpp
//
// Code generation for function 'relop'
//

// Include files
#include "relop.h"
#include "isnan.h"
#include "rt_nonfinite.h"

// Function Declarations
namespace coder {
namespace internal {
static boolean_T d_relop(double a, double b);

}
} // namespace coder

// Function Definitions
namespace coder {
namespace internal {
static boolean_T d_relop(double a, double b)
{
  return a <= b;
}

boolean_T b_relop(double a, double b)
{
  boolean_T p;
  if (b_isnan(b)) {
    p = false;
  } else if (b_isnan(a)) {
    p = true;
  } else {
    p = (a > b);
  }
  return p;
}

boolean_T c_relop(double a, double b)
{
  boolean_T p;
  if (d_relop(a, b) || b_isnan(b)) {
    p = true;
  } else {
    p = false;
  }
  return p;
}

boolean_T relop(double a, double b)
{
  boolean_T p;
  if (b_isnan(b)) {
    p = false;
  } else if (b_isnan(a)) {
    p = true;
  } else {
    p = (a < b);
  }
  return p;
}

} // namespace internal
} // namespace coder

// End of code generation (relop.cpp)
