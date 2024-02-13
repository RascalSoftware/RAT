//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// rand.cpp
//
// Code generation for function 'rand'
//

// Include files
#include "rand.h"
#include "RATMain_data.h"
#include "eml_rand_mt19937ar.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_rand(real_T r[4])
    {
      real_T b_r;
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
        genrand_uint32_vector(state, u);
        u[0] >>= 5U;
        u[1] >>= 6U;
        b_r = 1.1102230246251565E-16 * (static_cast<real_T>(u[0]) * 6.7108864E+7
          + static_cast<real_T>(u[1]));
      } while (b_r == 0.0);

      r[0] = b_r;

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
        genrand_uint32_vector(state, u);
        u[0] >>= 5U;
        u[1] >>= 6U;
        b_r = 1.1102230246251565E-16 * (static_cast<real_T>(u[0]) * 6.7108864E+7
          + static_cast<real_T>(u[1]));
      } while (b_r == 0.0);

      r[1] = b_r;

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
        genrand_uint32_vector(state, u);
        u[0] >>= 5U;
        u[1] >>= 6U;
        b_r = 1.1102230246251565E-16 * (static_cast<real_T>(u[0]) * 6.7108864E+7
          + static_cast<real_T>(u[1]));
      } while (b_r == 0.0);

      r[2] = b_r;

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
        genrand_uint32_vector(state, u);
        u[0] >>= 5U;
        u[1] >>= 6U;
        b_r = 1.1102230246251565E-16 * (static_cast<real_T>(u[0]) * 6.7108864E+7
          + static_cast<real_T>(u[1]));
      } while (b_r == 0.0);

      r[3] = b_r;
    }

    real_T b_rand()
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
        genrand_uint32_vector(state, u);
        u[0] >>= 5U;
        u[1] >>= 6U;
        r = 1.1102230246251565E-16 * (static_cast<real_T>(u[0]) * 6.7108864E+7 +
          static_cast<real_T>(u[1]));
      } while (r == 0.0);

      return r;
    }

    void b_rand(real_T varargin_1, real_T varargin_2, ::coder::array<real_T, 2U>
                &r)
    {
      int32_T i;
      r.set_size(static_cast<int32_T>(varargin_1), static_cast<int32_T>
                 (varargin_2));
      i = static_cast<int32_T>(varargin_1) * static_cast<int32_T>(varargin_2);
      for (int32_T k{0}; k < i; k++) {
        r[k] = eml_rand_mt19937ar(state);
      }
    }

    void b_rand(const real_T varargin_1[2], ::coder::array<real_T, 2U> &r)
    {
      int32_T i;
      i = static_cast<int32_T>(varargin_1[0]);
      r.set_size(i, 1);
      for (int32_T k{0}; k < i; k++) {
        r[k] = eml_rand_mt19937ar(state);
      }
    }

    void b_rand(real_T varargin_1, ::coder::array<real_T, 1U> &r)
    {
      int32_T i;
      i = static_cast<int32_T>(varargin_1);
      r.set_size(i);
      for (int32_T k{0}; k < i; k++) {
        r[k] = eml_rand_mt19937ar(state);
      }
    }

    void b_rand(int32_T varargin_1, ::coder::array<real_T, 1U> &r)
    {
      r.set_size(varargin_1);
      for (int32_T k{0}; k < varargin_1; k++) {
        r[k] = eml_rand_mt19937ar(state);
      }
    }

    void b_rand(real_T varargin_2, ::coder::array<real_T, 2U> &r)
    {
      int32_T i;
      i = static_cast<int32_T>(varargin_2);
      r.set_size(1, i);
      for (int32_T k{0}; k < i; k++) {
        r[k] = eml_rand_mt19937ar(state);
      }
    }

    void c_rand(real_T r[1000])
    {
      uint32_T u[2];
      for (int32_T k{0}; k < 1000; k++) {
        real_T b_r;

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
          genrand_uint32_vector(state, u);
          u[0] >>= 5U;
          u[1] >>= 6U;
          b_r = 1.1102230246251565E-16 * (static_cast<real_T>(u[0]) *
            6.7108864E+7 + static_cast<real_T>(u[1]));
        } while (b_r == 0.0);

        r[k] = b_r;
      }
    }
  }
}

// End of code generation (rand.cpp)
