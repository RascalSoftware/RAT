//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// makeSLDProfile.cpp
//
// Code generation for function 'makeSLDProfile'
//

// Include files
#include "makeSLDProfile.h"
#include "blockedSummation.h"
#include "erf.h"
#include "erfcinv.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static void times(::coder::array<double, 2U> &in1, const ::coder::array<double,
                    2U> &in2, const ::coder::array<double, 2U> &in3);
}

// Function Definitions
namespace RAT
{
  static void times(::coder::array<double, 2U> &in1, const ::coder::array<double,
                    2U> &in2, const ::coder::array<double, 2U> &in3)
  {
    int aux_0_1;
    int aux_1_1;
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    in1.set_size(in2.size(0), in1.size(1));
    if (in3.size(1) == 1) {
      loop_ub = in2.size(1);
    } else {
      loop_ub = in3.size(1);
    }

    in1.set_size(in1.size(0), loop_ub);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_1 = (in3.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (int i{0}; i < loop_ub; i++) {
      int b_loop_ub;
      b_loop_ub = in2.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        in1[i1 + in1.size(0) * i] = in2[i1 + in2.size(0) * aux_0_1] *
          in3[aux_1_1];
      }

      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }
  }

  void makeSLDProfile(double bulkIn, double bulkOut, ::coder::array<double, 2U>
                      &layers, double lastRough, double nRepeats, ::coder::array<
                      double, 2U> &SLD)
  {
    ::coder::array<double, 2U> allFuncs;
    ::coder::array<double, 2U> alpha;
    ::coder::array<double, 2U> b_z;
    ::coder::array<double, 2U> c_layers;
    ::coder::array<double, 2U> d_layers;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> thisFun;
    ::coder::array<double, 2U> total;
    ::coder::array<double, 2U> totalFuncs;
    ::coder::array<double, 2U> z;
    ::coder::array<double, 1U> b_layers;
    ::coder::array<double, 1U> b_total;
    int b_loop_ub;
    int i;
    int loop_ub;

    //  Scale the SLDs...
    b_layers.set_size(layers.size(0));
    loop_ub = layers.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_layers[i] = layers[i + layers.size(0)] * 1.0E+6;
    }

    loop_ub = b_layers.size(0);
    for (i = 0; i < loop_ub; i++) {
      layers[i + layers.size(0)] = b_layers[i];
    }

    bulkIn *= 1.0E+6;
    bulkOut *= 1.0E+6;

    //  Define cdf...
    if (layers.size(0) > 0) {
      double b;
      double lastLayerSLD;
      double thisPos;
      double totalRange;
      int total_idx_0;

      //  Make a z range for the profile...
      //  Find the maximum thickness, including any long roughness tail on final layer...
      //  Find the point which covers 99% of the outer error function..
      //  We need to make sure the total SLD range includes this...
      b_layers.set_size(layers.size(0));
      loop_ub = layers.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_layers[i] = layers[i];
      }

      b = coder::erfcinv() * 1.4142135623730951 * layers[(layers.size(0) +
        layers.size(0) * 2) - 1];
      totalRange = (coder::sum(b_layers) + b) * nRepeats;

      //  Add some extra range at the end for bulk_out...
      b_layers.set_size(layers.size(0));
      loop_ub = layers.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_layers[i] = layers[i];
      }

      if (std::isnan((coder::sum(b_layers) + b) * nRepeats + 100.0)) {
        z.set_size(1, 1);
        z[0] = rtNaN;
      } else if (totalRange + 100.0 < 0.0) {
        z.set_size(1, 0);
      } else {
        z.set_size(1, static_cast<int>(totalRange + 100.0) + 1);
        loop_ub = static_cast<int>(totalRange + 100.0);
        for (i = 0; i <= loop_ub; i++) {
          z[i] = i;
        }
      }

      //  Repeat the stack according to 'nRepeats'...
      c_layers.set_size(layers.size(0), layers.size(1));
      loop_ub = layers.size(1) - 1;
      for (i = 0; i <= loop_ub; i++) {
        b_loop_ub = layers.size(0) - 1;
        for (int i1{0}; i1 <= b_loop_ub; i1++) {
          c_layers[i1 + c_layers.size(0) * i] = layers[i1 + layers.size(0) * i];
        }
      }

      coder::repmat(c_layers, nRepeats, layers);

      //  Add an aditional 'layer' for the transition to bulk out...
      if ((layers.size(0) != 0) && (layers.size(1) != 0)) {
        b_loop_ub = layers.size(0);
      } else {
        b_loop_ub = 0;
      }

      d_layers.set_size(b_loop_ub + 1, 3);
      for (i = 0; i < 3; i++) {
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          d_layers[i1 + d_layers.size(0) * i] = layers[i1 + b_loop_ub * i];
        }
      }

      d_layers[b_loop_ub] = 0.0;
      d_layers[b_loop_ub + d_layers.size(0)] = bulkOut;
      d_layers[b_loop_ub + d_layers.size(0) * 2] = lastRough;

      //  Pre-definitions....
      allFuncs.set_size(z.size(1), d_layers.size(0));
      loop_ub = d_layers.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = z.size(1);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          allFuncs[i1 + allFuncs.size(0) * i] = 0.0;
        }
      }

      alpha.set_size(1, d_layers.size(0));
      lastLayerSLD = bulkIn;
      thisPos = 50.0;

      //  Make the profile by adding an error function for each interface
      //  (we use 'cdf' because it scales more easily than 'erf'...)
      i = d_layers.size(0);
      loop_ub = z.size(1);
      for (int b_i{0}; b_i < i; b_i++) {
        double diff;
        double nextLayerSLD;
        nextLayerSLD = d_layers[b_i + d_layers.size(0)];
        diff = nextLayerSLD - lastLayerSLD;
        b = 1.4142135623730951 * d_layers[b_i + d_layers.size(0) * 2];
        b_z.set_size(1, z.size(1));
        for (int i1{0}; i1 < loop_ub; i1++) {
          b_z[i1] = (z[i1] - thisPos) / b;
        }

        coder::b_erf(b_z, r);
        thisFun.set_size(1, r.size(1));
        b_loop_ub = r.size(1);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          thisFun[i1] = 0.5 * (r[i1] + 1.0);
        }

        if (diff < 0.0) {
          thisFun.set_size(1, thisFun.size(1));
          b_loop_ub = thisFun.size(1);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            thisFun[i1] = -thisFun[i1];
          }
        }

        b_loop_ub = allFuncs.size(0);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          allFuncs[i1 + allFuncs.size(0) * b_i] = thisFun[i1];
        }

        alpha[b_i] = std::abs(diff);
        thisPos += d_layers[b_i];
        lastLayerSLD = nextLayerSLD;
      }

      if (allFuncs.size(1) == alpha.size(1)) {
        totalFuncs.set_size(allFuncs.size(0), allFuncs.size(1));
        loop_ub = allFuncs.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = allFuncs.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            totalFuncs[i1 + totalFuncs.size(0) * i] = allFuncs[i1 +
              allFuncs.size(0) * i] * alpha[i];
          }
        }
      } else {
        times(totalFuncs, allFuncs, alpha);
      }

      coder::blockedSummation(totalFuncs, totalFuncs.size(1), b_total);
      total_idx_0 = b_total.size(0);
      total.set_size(b_total.size(0), 1);
      for (i = 0; i < total_idx_0; i++) {
        total[i] = b_total[i];
      }
    } else {
      double b;
      double diff;

      //  If we have no layers (i.e. just a bare interface), we only need one
      //  cdf...
      z.set_size(1, 101);
      diff = bulkOut - bulkIn;
      b = 1.4142135623730951 * lastRough;
      b_z.set_size(1, 101);
      for (i = 0; i < 101; i++) {
        z[i] = i;
        b_z[i] = (static_cast<double>(i) - 50.0) / b;
      }

      coder::b_erf(b_z, r);
      thisFun.set_size(1, r.size(1));
      loop_ub = r.size(1);
      for (i = 0; i < loop_ub; i++) {
        thisFun[i] = 0.5 * (r[i] + 1.0);
      }

      if (diff < 1.0) {
        thisFun.set_size(1, thisFun.size(1));
        loop_ub = thisFun.size(1);
        for (i = 0; i < loop_ub; i++) {
          thisFun[i] = -thisFun[i];
        }
      }

      b = std::abs(diff);
      total.set_size(1, thisFun.size(1));
      loop_ub = thisFun.size(1);
      for (i = 0; i < loop_ub; i++) {
        total[total.size(0) * i] = thisFun[i] * b;
      }
    }

    //  Scale the SLD's back to Angstroms...
    loop_ub = total.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = total.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        total[i1 + total.size(0) * i] = (total[i1 + total.size(0) * i] + bulkIn)
          * 1.0E-6;
      }
    }

    b_loop_ub = total.size(0) * total.size(1);
    SLD.set_size(z.size(1), 2);
    loop_ub = z.size(1);
    for (i = 0; i < loop_ub; i++) {
      SLD[i] = z[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      SLD[i + SLD.size(0)] = total[i];
    }
  }

  void makeSLDProfile(::coder::array<double, 2U> &layers, double lastRough,
                      double nRepeats, ::coder::array<double, 2U> &SLD)
  {
    ::coder::array<double, 2U> allFuncs;
    ::coder::array<double, 2U> alpha;
    ::coder::array<double, 2U> b_z;
    ::coder::array<double, 2U> c_layers;
    ::coder::array<double, 2U> d_layers;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> thisFun;
    ::coder::array<double, 2U> total;
    ::coder::array<double, 2U> totalFuncs;
    ::coder::array<double, 2U> z;
    ::coder::array<double, 1U> b_layers;
    ::coder::array<double, 1U> b_total;
    int i;
    int input_sizes_idx_0;
    int loop_ub;

    //  Scale the SLDs...
    b_layers.set_size(layers.size(0));
    loop_ub = layers.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_layers[i] = layers[i + layers.size(0)] * 1.0E+6;
    }

    loop_ub = b_layers.size(0);
    for (i = 0; i < loop_ub; i++) {
      layers[i + layers.size(0)] = b_layers[i];
    }

    //  Define cdf...
    if (layers.size(0) > 0) {
      double lastLayerSLD;
      double thisPos;
      double totalRange;
      double totalRange_tmp;

      //  Make a z range for the profile...
      //  Find the maximum thickness, including any long roughness tail on final layer...
      //  Find the point which covers 99% of the outer error function..
      //  We need to make sure the total SLD range includes this...
      b_layers.set_size(layers.size(0));
      loop_ub = layers.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_layers[i] = layers[i];
      }

      totalRange_tmp = coder::erfcinv() * 1.4142135623730951 * layers
        [(layers.size(0) + layers.size(0) * 2) - 1];
      totalRange = (coder::sum(b_layers) + totalRange_tmp) * nRepeats;

      //  Add some extra range at the end for bulk_out...
      b_layers.set_size(layers.size(0));
      loop_ub = layers.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_layers[i] = layers[i];
      }

      if (std::isnan((coder::sum(b_layers) + totalRange_tmp) * nRepeats + 100.0))
      {
        z.set_size(1, 1);
        z[0] = rtNaN;
      } else if (totalRange + 100.0 < 0.0) {
        z.set_size(1, 0);
      } else {
        z.set_size(1, static_cast<int>(totalRange + 100.0) + 1);
        loop_ub = static_cast<int>(totalRange + 100.0);
        for (i = 0; i <= loop_ub; i++) {
          z[i] = i;
        }
      }

      //  Repeat the stack according to 'nRepeats'...
      c_layers.set_size(layers.size(0), layers.size(1));
      loop_ub = layers.size(1) - 1;
      for (i = 0; i <= loop_ub; i++) {
        input_sizes_idx_0 = layers.size(0) - 1;
        for (int i1{0}; i1 <= input_sizes_idx_0; i1++) {
          c_layers[i1 + c_layers.size(0) * i] = layers[i1 + layers.size(0) * i];
        }
      }

      coder::repmat(c_layers, nRepeats, layers);

      //  Add an aditional 'layer' for the transition to bulk out...
      if ((layers.size(0) != 0) && (layers.size(1) != 0)) {
        input_sizes_idx_0 = layers.size(0);
      } else {
        input_sizes_idx_0 = 0;
      }

      d_layers.set_size(input_sizes_idx_0 + 1, 3);
      for (i = 0; i < 3; i++) {
        for (int i1{0}; i1 < input_sizes_idx_0; i1++) {
          d_layers[i1 + d_layers.size(0) * i] = layers[i1 + input_sizes_idx_0 *
            i];
        }
      }

      d_layers[input_sizes_idx_0] = 0.0;
      d_layers[input_sizes_idx_0 + d_layers.size(0)] = 0.0;
      d_layers[input_sizes_idx_0 + d_layers.size(0) * 2] = lastRough;

      //  Pre-definitions....
      allFuncs.set_size(z.size(1), d_layers.size(0));
      loop_ub = d_layers.size(0);
      for (i = 0; i < loop_ub; i++) {
        input_sizes_idx_0 = z.size(1);
        for (int i1{0}; i1 < input_sizes_idx_0; i1++) {
          allFuncs[i1 + allFuncs.size(0) * i] = 0.0;
        }
      }

      alpha.set_size(1, d_layers.size(0));
      lastLayerSLD = 0.0;
      thisPos = 50.0;

      //  Make the profile by adding an error function for each interface
      //  (we use 'cdf' because it scales more easily than 'erf'...)
      i = d_layers.size(0);
      loop_ub = z.size(1);
      for (int b_i{0}; b_i < i; b_i++) {
        double diff;
        double nextLayerSLD;
        nextLayerSLD = d_layers[b_i + d_layers.size(0)];
        diff = nextLayerSLD - lastLayerSLD;
        totalRange_tmp = 1.4142135623730951 * d_layers[b_i + d_layers.size(0) *
          2];
        b_z.set_size(1, z.size(1));
        for (int i1{0}; i1 < loop_ub; i1++) {
          b_z[i1] = (z[i1] - thisPos) / totalRange_tmp;
        }

        coder::b_erf(b_z, r);
        thisFun.set_size(1, r.size(1));
        input_sizes_idx_0 = r.size(1);
        for (int i1{0}; i1 < input_sizes_idx_0; i1++) {
          thisFun[i1] = 0.5 * (r[i1] + 1.0);
        }

        if (diff < 0.0) {
          thisFun.set_size(1, thisFun.size(1));
          input_sizes_idx_0 = thisFun.size(1);
          for (int i1{0}; i1 < input_sizes_idx_0; i1++) {
            thisFun[i1] = -thisFun[i1];
          }
        }

        input_sizes_idx_0 = allFuncs.size(0);
        for (int i1{0}; i1 < input_sizes_idx_0; i1++) {
          allFuncs[i1 + allFuncs.size(0) * b_i] = thisFun[i1];
        }

        alpha[b_i] = std::abs(diff);
        thisPos += d_layers[b_i];
        lastLayerSLD = nextLayerSLD;
      }

      if (allFuncs.size(1) == alpha.size(1)) {
        totalFuncs.set_size(allFuncs.size(0), allFuncs.size(1));
        loop_ub = allFuncs.size(1);
        for (i = 0; i < loop_ub; i++) {
          input_sizes_idx_0 = allFuncs.size(0);
          for (int i1{0}; i1 < input_sizes_idx_0; i1++) {
            totalFuncs[i1 + totalFuncs.size(0) * i] = allFuncs[i1 +
              allFuncs.size(0) * i] * alpha[i];
          }
        }
      } else {
        times(totalFuncs, allFuncs, alpha);
      }

      coder::blockedSummation(totalFuncs, totalFuncs.size(1), b_total);
      input_sizes_idx_0 = b_total.size(0);
      total.set_size(b_total.size(0), 1);
      for (i = 0; i < input_sizes_idx_0; i++) {
        total[i] = b_total[i];
      }
    } else {
      double totalRange_tmp;

      //  If we have no layers (i.e. just a bare interface), we only need one
      //  cdf...
      z.set_size(1, 101);
      totalRange_tmp = 1.4142135623730951 * lastRough;
      b_z.set_size(1, 101);
      for (i = 0; i < 101; i++) {
        z[i] = i;
        b_z[i] = (static_cast<double>(i) - 50.0) / totalRange_tmp;
      }

      coder::b_erf(b_z, r);
      total.set_size(1, r.size(1));
      loop_ub = r.size(1);
      for (i = 0; i < loop_ub; i++) {
        total[total.size(0) * i] = -(0.5 * (r[i] + 1.0)) * 0.0;
      }
    }

    //  Scale the SLD's back to Angstroms...
    loop_ub = total.size(1);
    for (i = 0; i < loop_ub; i++) {
      input_sizes_idx_0 = total.size(0);
      for (int i1{0}; i1 < input_sizes_idx_0; i1++) {
        total[i1 + total.size(0) * i] = total[i1 + total.size(0) * i] * 1.0E-6;
      }
    }

    input_sizes_idx_0 = total.size(0) * total.size(1);
    SLD.set_size(z.size(1), 2);
    loop_ub = z.size(1);
    for (i = 0; i < loop_ub; i++) {
      SLD[i] = z[i];
    }

    for (i = 0; i < input_sizes_idx_0; i++) {
      SLD[i + SLD.size(0)] = total[i];
    }
  }
}

// End of code generation (makeSLDProfile.cpp)
