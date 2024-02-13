//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// matrix_to_integer_power.cpp
//
// Code generation for function 'matrix_to_integer_power'
//

// Include files
#include "matrix_to_integer_power.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static void matrix_to_large_integer_power(real_T a_data[], real_T b, real_T
      c_data[], int32_T c_size[2]);
    static void matrix_to_small_integer_power(real_T a_data[], real_T b, real_T
      c_data[], int32_T c_size[2]);
    static void nbits(int32_T n, int32_T *log2n, int32_T *nbitson);
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    static void matrix_to_large_integer_power(real_T a_data[], real_T b, real_T
      c_data[], int32_T c_size[2])
    {
      c_size[0] = 1;
      c_size[1] = 1;
      if ((!std::isinf(b)) && (!std::isnan(b))) {
        real_T e;
        boolean_T firstmult;
        e = std::abs(b);
        firstmult = true;
        real_T ed2;
        int32_T exitg1;
        do {
          exitg1 = 0;
          ed2 = std::floor(e / 2.0);
          if (2.0 * ed2 != e) {
            if (firstmult) {
              c_size[0] = 1;
              c_size[1] = 1;
              c_data[0] = a_data[0];
              firstmult = false;
            } else {
              e = c_data[0];
              c_size[0] = 1;
              c_size[1] = 1;
              c_data[0] = e * a_data[0];
            }
          }

          if (ed2 == 0.0) {
            exitg1 = 1;
          } else {
            e = ed2;
            a_data[0] *= a_data[0];
          }
        } while (exitg1 == 0);
      } else {
        c_size[0] = 1;
        c_size[1] = 1;
        c_data[0] = rtNaN;
      }
    }

    static void matrix_to_small_integer_power(real_T a_data[], real_T b, real_T
      c_data[], int32_T c_size[2])
    {
      real_T aBuffer_data;
      real_T cBuffer_data;
      int32_T n;
      int32_T nb;
      int32_T nbitson;
      cBuffer_data = std::abs(b);
      n = static_cast<int32_T>(cBuffer_data);
      nbits(static_cast<int32_T>(cBuffer_data), &nb, &nbitson);
      if (static_cast<int32_T>(cBuffer_data) <= 2) {
        if (b == 2.0) {
          c_size[0] = 1;
          c_size[1] = 1;
          c_data[0] = a_data[0] * a_data[0];
        } else if (b == 1.0) {
          c_size[0] = 1;
          c_size[1] = 1;
          c_data[0] = a_data[0];
        } else {
          c_size[0] = 1;
          c_size[1] = 1;
          c_data[0] = 1.0;
        }
      } else {
        boolean_T aBufferInUse;
        boolean_T b_first;
        boolean_T cBufferInUse;
        b_first = true;
        aBufferInUse = false;
        cBufferInUse = ((nbitson & 1) == 0);
        for (nbitson = 0; nbitson <= nb - 2; nbitson++) {
          if ((n & 1) != 0) {
            if (b_first) {
              b_first = false;
              if (cBufferInUse) {
                if (aBufferInUse) {
                  cBuffer_data = aBuffer_data;
                } else {
                  cBuffer_data = a_data[0];
                }
              } else if (aBufferInUse) {
                c_data[0] = aBuffer_data;
              } else {
                c_data[0] = a_data[0];
              }
            } else {
              if (aBufferInUse) {
                if (cBufferInUse) {
                  c_data[0] = cBuffer_data * aBuffer_data;
                } else {
                  cBuffer_data = c_data[0] * aBuffer_data;
                }
              } else if (cBufferInUse) {
                c_data[0] = cBuffer_data * a_data[0];
              } else {
                cBuffer_data = c_data[0] * a_data[0];
              }

              cBufferInUse = !cBufferInUse;
            }
          }

          n >>= 1;
          if (aBufferInUse) {
            a_data[0] = aBuffer_data * aBuffer_data;
          } else {
            aBuffer_data = a_data[0] * a_data[0];
          }

          aBufferInUse = !aBufferInUse;
        }

        if (b_first) {
          if (aBufferInUse) {
            c_size[0] = 1;
            c_size[1] = 1;
            c_data[0] = aBuffer_data;
          } else {
            c_size[0] = 1;
            c_size[1] = 1;
            c_data[0] = a_data[0];
          }
        } else if (aBufferInUse) {
          c_size[0] = 1;
          c_size[1] = 1;
          c_data[0] = cBuffer_data * aBuffer_data;
        } else {
          c_size[0] = 1;
          c_size[1] = 1;
          c_data[0] = cBuffer_data * a_data[0];
        }
      }
    }

    static void nbits(int32_T n, int32_T *log2n, int32_T *nbitson)
    {
      *nbitson = 0;
      *log2n = 0;
      while (n > 0) {
        (*log2n)++;
        if ((n & 1) != 0) {
          (*nbitson)++;
        }

        n >>= 1;
      }
    }

    void matrix_to_integer_power(const real_T a_data[], real_T b, real_T c_data[],
      int32_T c_size[2])
    {
      if (std::abs(b) <= 2.147483647E+9) {
        real_T b_a_data;
        b_a_data = a_data[0];
        matrix_to_small_integer_power((real_T *)&b_a_data, b, c_data, c_size);
      } else {
        real_T b_a_data;
        b_a_data = a_data[0];
        matrix_to_large_integer_power((real_T *)&b_a_data, b, c_data, c_size);
      }
    }
  }
}

// End of code generation (matrix_to_integer_power.cpp)
