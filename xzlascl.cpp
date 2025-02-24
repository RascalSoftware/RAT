//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzlascl.cpp
//
// Code generation for function 'xzlascl'
//

// Include files
#include "xzlascl.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace reflapack
      {
        void xzlascl(double cfrom, double cto, ::coder::array<creal_T, 1U> &A)
        {
          double cfromc;
          double ctoc;
          boolean_T notdone;
          cfromc = cfrom;
          ctoc = cto;
          notdone = true;
          while (notdone) {
            double a;
            double cfrom1;
            double cto1;
            int loop_ub;
            cfrom1 = cfromc * 2.0041683600089728E-292;
            cto1 = ctoc / 4.9896007738368E+291;
            if ((std::abs(cfrom1) > std::abs(ctoc)) && (ctoc != 0.0)) {
              a = 2.0041683600089728E-292;
              cfromc = cfrom1;
            } else if (std::abs(cto1) > std::abs(cfromc)) {
              a = 4.9896007738368E+291;
              ctoc = cto1;
            } else {
              a = ctoc / cfromc;
              notdone = false;
            }

            loop_ub = A.size(0);
            for (int i{0}; i < loop_ub; i++) {
              A[i].re = a * A[i].re;
              A[i].im = a * A[i].im;
            }
          }
        }

        void xzlascl(double cfrom, double cto, ::coder::array<creal_T, 2U> &A)
        {
          double cfromc;
          double ctoc;
          boolean_T notdone;
          cfromc = cfrom;
          ctoc = cto;
          notdone = true;
          while (notdone) {
            double a;
            double cfrom1;
            double cto1;
            int loop_ub;
            cfrom1 = cfromc * 2.0041683600089728E-292;
            cto1 = ctoc / 4.9896007738368E+291;
            if ((std::abs(cfrom1) > std::abs(ctoc)) && (ctoc != 0.0)) {
              a = 2.0041683600089728E-292;
              cfromc = cfrom1;
            } else if (std::abs(cto1) > std::abs(cfromc)) {
              a = 4.9896007738368E+291;
              ctoc = cto1;
            } else {
              a = ctoc / cfromc;
              notdone = false;
            }

            loop_ub = A.size(1);
            for (int i{0}; i < loop_ub; i++) {
              int b_loop_ub;
              b_loop_ub = A.size(0);
              for (int i1{0}; i1 < b_loop_ub; i1++) {
                A[i1 + A.size(0) * i].re = a * A[i1 + A.size(0) * i].re;
                A[i1 + A.size(0) * i].im = a * A[i1 + A.size(0) * i].im;
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (xzlascl.cpp)
