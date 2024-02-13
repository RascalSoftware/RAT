//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// eml_rand_mt19937ar.cpp
//
// Code generation for function 'eml_rand_mt19937ar'
//

// Include files
#include "eml_rand_mt19937ar.h"
#include "RATMain_data.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    real_T b_eml_rand_mt19937ar(uint32_T b_state[625])
    {
      real_T r;
      int32_T exitg1;
      int32_T i;
      uint32_T u32[2];
      do {
        exitg1 = 0;
        genrand_uint32_vector(b_state, u32);
        i = static_cast<int32_T>((u32[1] >> 24U) + 1U);
        r = ((static_cast<real_T>(u32[0] >> 3U) * 1.6777216E+7 +
              static_cast<real_T>(static_cast<int32_T>(u32[1]) & 16777215)) *
             2.2204460492503131E-16 - 1.0) * dv[i];
        if (std::abs(r) <= dv[i - 1]) {
          exitg1 = 1;
        } else if (i < 256) {
          real_T u;
          u = eml_rand_mt19937ar(b_state);
          if (dv1[i] + u * (dv1[i - 1] - dv1[i]) < std::exp(-0.5 * r * r)) {
            exitg1 = 1;
          }
        } else {
          real_T u;
          real_T x;
          do {
            u = eml_rand_mt19937ar(b_state);
            x = std::log(u) * 0.273661237329758;
            u = eml_rand_mt19937ar(b_state);
          } while (!(-2.0 * std::log(u) > x * x));

          if (r < 0.0) {
            r = x - 3.65415288536101;
          } else {
            r = 3.65415288536101 - x;
          }

          exitg1 = 1;
        }
      } while (exitg1 == 0);

      return r;
    }

    real_T eml_rand_mt19937ar(uint32_T b_state[625])
    {
      real_T r;
      uint32_T u[2];

      // ========================= COPYRIGHT NOTICE ============================
      //  This is a uniform (0,1) pseudorandom number generator based on:
      //
      //  A C-program for MT19937, with initialization improved 2002/1/26.
      //  Coded by Takuji Nishimura and Makoto Matsumoto.
      //
      //  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
      //  All rights reserved.
      //
      //  Redistribution and use in source and binary forms, with or without
      //  modification, are permitted provided that the following conditions
      //  are met:
      //
      //    1. Redistributions of source code must retain the above copyright
      //       notice, this list of conditions and the following disclaimer.
      //
      //    2. Redistributions in binary form must reproduce the above copyright
      //       notice, this list of conditions and the following disclaimer
      //       in the documentation and/or other materials provided with the
      //       distribution.
      //
      //    3. The names of its contributors may not be used to endorse or
      //       promote products derived from this software without specific
      //       prior written permission.
      //
      //  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
      //  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
      //  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
      //  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
      //  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
      //  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
      //  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
      //  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
      //  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
      //  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
      //  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
      //
      // =============================   END   =================================
      do {
        genrand_uint32_vector(b_state, u);
        u[0] >>= 5U;
        u[1] >>= 6U;
        r = 1.1102230246251565E-16 * (static_cast<real_T>(u[0]) * 6.7108864E+7 +
          static_cast<real_T>(u[1]));
      } while (r == 0.0);

      return r;
    }

    void genrand_uint32_vector(uint32_T mt[625], uint32_T u[2])
    {
      for (int32_T j{0}; j < 2; j++) {
        uint32_T mti;
        uint32_T y;
        mti = mt[624] + 1U;
        if (mti >= 625U) {
          int32_T kk;
          for (kk = 0; kk < 227; kk++) {
            y = (mt[kk] & 2147483648U) | (mt[kk + 1] & 2147483647U);
            if ((y & 1U) == 0U) {
              y >>= 1U;
            } else {
              y = y >> 1U ^ 2567483615U;
            }

            mt[kk] = mt[kk + 397] ^ y;
          }

          for (kk = 0; kk < 396; kk++) {
            y = (mt[kk + 227] & 2147483648U) | (mt[kk + 228] & 2147483647U);
            if ((y & 1U) == 0U) {
              y >>= 1U;
            } else {
              y = y >> 1U ^ 2567483615U;
            }

            mt[kk + 227] = mt[kk] ^ y;
          }

          y = (mt[623] & 2147483648U) | (mt[0] & 2147483647U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          mt[623] = mt[396] ^ y;
          mti = 1U;
        }

        y = mt[static_cast<int32_T>(mti) - 1];
        mt[624] = mti;
        y ^= y >> 11U;
        y ^= y << 7U & 2636928640U;
        y ^= y << 15U & 4022730752U;
        u[j] = y ^ y >> 18U;
      }
    }
  }
}

// End of code generation (eml_rand_mt19937ar.cpp)
