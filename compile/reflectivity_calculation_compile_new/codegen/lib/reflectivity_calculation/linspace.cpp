//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// linspace.cpp
//
// Code generation for function 'linspace'
//

// Include files
#include "linspace.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace coder {
void b_linspace(double d1, double d2, double y[50])
{
  y[49] = d2;
  y[0] = d1;
  if (d1 == -d2) {
    double delta1;
    delta1 = d2 / 49.0;
    for (int k{0}; k < 48; k++) {
      y[k + 1] = (2.0 * (static_cast<double>(k) + 2.0) - 51.0) * delta1;
    }
  } else if (((d1 < 0.0) != (d2 < 0.0)) &&
             ((std::abs(d1) > 8.9884656743115785E+307) ||
              (std::abs(d2) > 8.9884656743115785E+307))) {
    double delta1;
    double delta2;
    delta1 = d1 / 49.0;
    delta2 = d2 / 49.0;
    for (int k{0}; k < 48; k++) {
      y[k + 1] = (d1 + delta2 * (static_cast<double>(k) + 1.0)) -
                 delta1 * (static_cast<double>(k) + 1.0);
    }
  } else {
    double delta1;
    delta1 = (d2 - d1) / 49.0;
    for (int k{0}; k < 48; k++) {
      y[k + 1] = d1 + (static_cast<double>(k) + 1.0) * delta1;
    }
  }
}

void linspace(double d1, double d2, double y[100])
{
  y[99] = d2;
  y[0] = d1;
  if (d1 == -d2) {
    double delta1;
    delta1 = d2 / 99.0;
    for (int k{0}; k < 98; k++) {
      y[k + 1] = (2.0 * (static_cast<double>(k) + 2.0) - 101.0) * delta1;
    }
  } else if (((d1 < 0.0) != (d2 < 0.0)) &&
             ((std::abs(d1) > 8.9884656743115785E+307) ||
              (std::abs(d2) > 8.9884656743115785E+307))) {
    double delta1;
    double delta2;
    delta1 = d1 / 99.0;
    delta2 = d2 / 99.0;
    for (int k{0}; k < 98; k++) {
      y[k + 1] = (d1 + delta2 * (static_cast<double>(k) + 1.0)) -
                 delta1 * (static_cast<double>(k) + 1.0);
    }
  } else {
    double delta1;
    delta1 = (d2 - d1) / 99.0;
    for (int k{0}; k < 98; k++) {
      y[k + 1] = d1 + (static_cast<double>(k) + 1.0) * delta1;
    }
  }
}

} // namespace coder

// End of code generation (linspace.cpp)
