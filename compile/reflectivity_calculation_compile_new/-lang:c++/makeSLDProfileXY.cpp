//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: makeSLDProfileXY.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "makeSLDProfileXY.h"
#include "asymconvstep.h"
#include "blockedSummation.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : real_T nbair
//                real_T nbsub
//                real_T ssub
//                const ::coder::array<real_T, 2U> &layers
//                real_T numberOfLayers
//                real_T nrepeats
//                ::coder::array<real_T, 2U> &out
// Return Type  : void
//
namespace RAT
{
  void makeSLDProfileXY(real_T nbair, real_T nbsub, real_T ssub, const ::coder::
                        array<real_T, 2U> &layers, real_T numberOfLayers, real_T
                        nrepeats, ::coder::array<real_T, 2U> &out)
  {
    ::coder::array<real_T, 2U> Lays;
    ::coder::array<real_T, 2U> SLD;
    ::coder::array<real_T, 2U> airBox;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 2U> r1;
    ::coder::array<real_T, 2U> r2;
    ::coder::array<real_T, 2U> x;
    ::coder::array<real_T, 1U> b_layers;
    int32_T b_loop_ub;
    int32_T i;
    int32_T loop_ub;
    if (numberOfLayers > 0.0) {
      real_T b;
      real_T lastBoxEdge;
      real_T nextLayRough;
      int32_T i1;
      b_layers.set_size(layers.size(0));
      loop_ub = layers.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_layers[i] = layers[i];
      }

      b = coder::sum(b_layers) * nrepeats + 150.0;
      if (std::isnan(b)) {
        x.set_size(1, 1);
        x[0] = rtNaN;
      } else if (b < 0.0) {
        x.set_size(1, 0);
      } else {
        x.set_size(1, static_cast<int32_T>(b) + 1);
        loop_ub = static_cast<int32_T>(b);
        for (i = 0; i <= loop_ub; i++) {
          x[i] = i;
        }
      }

      b = numberOfLayers * nrepeats;
      Lays.set_size(x.size(1), static_cast<int32_T>(b + 2.0));
      loop_ub = static_cast<int32_T>(b + 2.0);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = x.size(1);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          Lays[i1 + Lays.size(0) * i] = 0.0;
        }
      }

      nextLayRough = layers[layers.size(0) * 2];
      asymconvstep(x, 100.0, 0.0, nextLayRough, nextLayRough, nbair, airBox);
      lastBoxEdge = 50.0;
      i = static_cast<int32_T>(nrepeats);
      for (int32_T n{0}; n < i; n++) {
        i1 = static_cast<int32_T>(numberOfLayers);
        for (int32_T b_i{0}; b_i < i1; b_i++) {
          real_T thisBoxCentre;
          real_T thisLayThick;
          thisLayThick = layers[b_i];
          if (static_cast<real_T>(b_i) + 1.0 < numberOfLayers) {
            nextLayRough = layers[(b_i + layers.size(0) * 2) + 1];

            //              elseif (i == numberOfLayers) && (n < nrepeats)
            //                  nextLayRough = layers(1,3);
          } else {
            nextLayRough = ssub;
          }

          thisBoxCentre = lastBoxEdge + thisLayThick / 2.0;
          b_loop_ub = static_cast<int32_T>((static_cast<real_T>(b_i) + 1.0) +
            numberOfLayers * ((static_cast<real_T>(n) + 1.0) - 1.0)) - 1;
          asymconvstep(x, thisLayThick, thisBoxCentre, layers[b_i + layers.size
                       (0) * 2], nextLayRough, layers[b_i + layers.size(0)], r1);
          loop_ub = Lays.size(0);
          for (int32_T i2{0}; i2 < loop_ub; i2++) {
            Lays[i2 + Lays.size(0) * b_loop_ub] = r1[i2];
          }

          lastBoxEdge = thisBoxCentre + thisLayThick / 2.0;

          // plot(x,Lays(:,i));
        }
      }

      // layers(end,3);
      asymconvstep(x, (x[x.size(1) - 1] - lastBoxEdge) * 2.0, x[x.size(1) - 1],
                   nextLayRough, ssub, nbsub, r1);
      loop_ub = Lays.size(0);
      for (i = 0; i < loop_ub; i++) {
        Lays[i + Lays.size(0) * (static_cast<int32_T>(b + 1.0) - 1)] = r1[i];
      }

      // plot(x,Lays(:,(numberOfLayers*nrepeats)+1))
      loop_ub = Lays.size(0);
      for (i = 0; i < loop_ub; i++) {
        Lays[i + Lays.size(0) * (static_cast<int32_T>(b + 2.0) - 1)] = airBox[i];
      }

      // plot(x,Lays(:,(numberOfLayers*nrepeats)+2))
      coder::blockedSummation(Lays, Lays.size(1), b_layers);
      b_loop_ub = b_layers.size(0);
      SLD.set_size(b_layers.size(0), 1);
      for (i = 0; i < b_loop_ub; i++) {
        SLD[i] = b_layers[i];
      }
    } else {
      real_T tmp_data[101];
      real_T widths;
      x.set_size(1, 101);
      r.set_size(1, 101);
      for (i = 0; i < 101; i++) {
        x[i] = i;
        tmp_data[i] = i;
        r[i] = i;
      }

      widths = coder::internal::maximum(tmp_data);
      asymconvstep(r, widths, 0.0, ssub, ssub, nbair, r1);
      r.set_size(1, 101);
      for (i = 0; i < 101; i++) {
        tmp_data[i] = i;
        r[i] = i;
      }

      asymconvstep(r, widths, coder::internal::maximum(tmp_data), ssub, ssub,
                   nbsub, r2);
      SLD.set_size(1, r1.size(1));
      loop_ub = r1.size(1);
      for (i = 0; i < loop_ub; i++) {
        SLD[SLD.size(0) * i] = r1[i] + r2[i];
      }
    }

    // plot(x,SLD)
    b_loop_ub = SLD.size(0) * SLD.size(1);
    out.set_size(x.size(1), 2);
    loop_ub = x.size(1);
    for (i = 0; i < loop_ub; i++) {
      out[i] = x[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      out[i + out.size(0)] = SLD[i];
    }
  }
}

//
// File trailer for makeSLDProfileXY.cpp
//
// [EOF]
//
