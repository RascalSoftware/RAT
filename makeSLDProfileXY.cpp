//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// makeSLDProfileXY.cpp
//
// Code generation for function 'makeSLDProfileXY'
//

// Include files
#include "makeSLDProfileXY.h"
#include "asymconvstep.h"
#include "blockedSummation.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void makeSLDProfileXY(double bulkIn, double bulkOut, double ssub, const ::
                        coder::array<double, 2U> &layers, double numberOfLayers,
                        double nrepeats, ::coder::array<double, 2U> &out)
  {
    ::coder::array<double, 2U> Lays;
    ::coder::array<double, 2U> SLD;
    ::coder::array<double, 2U> airBox;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> r1;
    ::coder::array<double, 2U> r2;
    ::coder::array<double, 2U> x;
    ::coder::array<double, 1U> b_layers;
    int b_loop_ub;
    int i;
    int loop_ub;
    if (numberOfLayers > 0.0) {
      double lastBoxEdge;
      double nextLayRough;
      double subsBoxCen_tmp;
      double x_tmp;
      int i1;
      b_layers.set_size(layers.size(0));
      loop_ub = layers.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_layers[i] = layers[i];
      }

      subsBoxCen_tmp = coder::sum(b_layers) * nrepeats + 150.0;
      if (std::isnan(subsBoxCen_tmp)) {
        x.set_size(1, 1);
        x[0] = rtNaN;
      } else if (subsBoxCen_tmp < 0.0) {
        x.set_size(1, 0);
      } else {
        x.set_size(1, static_cast<int>(subsBoxCen_tmp) + 1);
        loop_ub = static_cast<int>(subsBoxCen_tmp);
        for (i = 0; i <= loop_ub; i++) {
          x[i] = i;
        }
      }

      x_tmp = numberOfLayers * nrepeats;
      Lays.set_size(x.size(1), static_cast<int>(x_tmp + 2.0));
      loop_ub = static_cast<int>(x_tmp + 2.0);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = x.size(1);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          Lays[i1 + Lays.size(0) * i] = 0.0;
        }
      }

      nextLayRough = layers[layers.size(0) * 2];
      asymconvstep(x, 100.0, 0.0, nextLayRough, nextLayRough, bulkIn, airBox);
      lastBoxEdge = 50.0;
      i = static_cast<int>(nrepeats);
      for (int n{0}; n < i; n++) {
        i1 = static_cast<int>(numberOfLayers);
        for (int b_i{0}; b_i < i1; b_i++) {
          double thisBoxCentre;
          double thisLayThick;
          thisLayThick = layers[b_i];
          if (static_cast<double>(b_i) + 1.0 < numberOfLayers) {
            nextLayRough = layers[(b_i + layers.size(0) * 2) + 1];

            //              elseif (i == numberOfLayers) && (n < nrepeats)
            //                  nextLayRough = layers(1,3);
          } else {
            nextLayRough = ssub;
          }

          thisBoxCentre = lastBoxEdge + thisLayThick / 2.0;
          b_loop_ub = static_cast<int>((static_cast<double>(b_i) + 1.0) +
            numberOfLayers * ((static_cast<double>(n) + 1.0) - 1.0)) - 1;
          asymconvstep(x, thisLayThick, thisBoxCentre, layers[b_i + layers.size
                       (0) * 2], nextLayRough, layers[b_i + layers.size(0)], r1);
          loop_ub = Lays.size(0);
          for (int i2{0}; i2 < loop_ub; i2++) {
            Lays[i2 + Lays.size(0) * b_loop_ub] = r1[i2];
          }

          lastBoxEdge = thisBoxCentre + thisLayThick / 2.0;

          // plot(x,Lays(:,i));
        }
      }

      // layers(end,3);
      subsBoxCen_tmp = x[x.size(1) - 1];
      asymconvstep(x, (subsBoxCen_tmp - lastBoxEdge) * 2.0, subsBoxCen_tmp,
                   nextLayRough, ssub, bulkOut, r1);
      loop_ub = Lays.size(0);
      for (i = 0; i < loop_ub; i++) {
        Lays[i + Lays.size(0) * (static_cast<int>(x_tmp + 1.0) - 1)] = r1[i];
      }

      // plot(x,Lays(:,(numberOfLayers*nrepeats)+1))
      loop_ub = Lays.size(0);
      for (i = 0; i < loop_ub; i++) {
        Lays[i + Lays.size(0) * (static_cast<int>(x_tmp + 2.0) - 1)] = airBox[i];
      }

      // plot(x,Lays(:,(numberOfLayers*nrepeats)+2))
      coder::blockedSummation(Lays, Lays.size(1), b_layers);
      b_loop_ub = b_layers.size(0);
      SLD.set_size(b_layers.size(0), 1);
      for (i = 0; i < b_loop_ub; i++) {
        SLD[i] = b_layers[i];
      }
    } else {
      double subsBoxCen_tmp;
      x.set_size(1, 101);
      r.set_size(1, 101);
      for (i = 0; i < 101; i++) {
        x[i] = i;
        r[i] = i;
      }

      subsBoxCen_tmp = coder::internal::maximum(r);
      r.set_size(1, 101);
      for (i = 0; i < 101; i++) {
        r[i] = i;
      }

      asymconvstep(r, subsBoxCen_tmp, 0.0, ssub, ssub, bulkIn, r1);
      r.set_size(1, 101);
      for (i = 0; i < 101; i++) {
        r[i] = i;
      }

      asymconvstep(r, subsBoxCen_tmp, subsBoxCen_tmp, ssub, ssub, bulkOut, r2);
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

  void makeSLDProfileXY(double ssub, const ::coder::array<double, 2U> &layers,
                        double numberOfLayers, double nrepeats, ::coder::array<
                        double, 2U> &out)
  {
    ::coder::array<double, 2U> Lays;
    ::coder::array<double, 2U> SLD;
    ::coder::array<double, 2U> airBox;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> r1;
    ::coder::array<double, 2U> r2;
    ::coder::array<double, 2U> x;
    ::coder::array<double, 1U> b_layers;
    int b_loop_ub;
    int i;
    int loop_ub;
    if (numberOfLayers > 0.0) {
      double lastBoxEdge;
      double nextLayRough;
      double subsBoxCen_tmp;
      double x_tmp;
      int i1;
      b_layers.set_size(layers.size(0));
      loop_ub = layers.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_layers[i] = layers[i];
      }

      subsBoxCen_tmp = coder::sum(b_layers) * nrepeats + 150.0;
      if (std::isnan(subsBoxCen_tmp)) {
        x.set_size(1, 1);
        x[0] = rtNaN;
      } else if (subsBoxCen_tmp < 0.0) {
        x.set_size(1, 0);
      } else {
        x.set_size(1, static_cast<int>(subsBoxCen_tmp) + 1);
        loop_ub = static_cast<int>(subsBoxCen_tmp);
        for (i = 0; i <= loop_ub; i++) {
          x[i] = i;
        }
      }

      x_tmp = numberOfLayers * nrepeats;
      Lays.set_size(x.size(1), static_cast<int>(x_tmp + 2.0));
      loop_ub = static_cast<int>(x_tmp + 2.0);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = x.size(1);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          Lays[i1 + Lays.size(0) * i] = 0.0;
        }
      }

      nextLayRough = layers[layers.size(0) * 2];
      asymconvstep(x, 100.0, 0.0, nextLayRough, nextLayRough, airBox);
      lastBoxEdge = 50.0;
      i = static_cast<int>(nrepeats);
      for (int n{0}; n < i; n++) {
        i1 = static_cast<int>(numberOfLayers);
        for (int b_i{0}; b_i < i1; b_i++) {
          double thisBoxCentre;
          double thisLayThick;
          thisLayThick = layers[b_i];
          if (static_cast<double>(b_i) + 1.0 < numberOfLayers) {
            nextLayRough = layers[(b_i + layers.size(0) * 2) + 1];

            //              elseif (i == numberOfLayers) && (n < nrepeats)
            //                  nextLayRough = layers(1,3);
          } else {
            nextLayRough = ssub;
          }

          thisBoxCentre = lastBoxEdge + thisLayThick / 2.0;
          b_loop_ub = static_cast<int>((static_cast<double>(b_i) + 1.0) +
            numberOfLayers * ((static_cast<double>(n) + 1.0) - 1.0)) - 1;
          asymconvstep(x, thisLayThick, thisBoxCentre, layers[b_i + layers.size
                       (0) * 2], nextLayRough, layers[b_i + layers.size(0)], r1);
          loop_ub = Lays.size(0);
          for (int i2{0}; i2 < loop_ub; i2++) {
            Lays[i2 + Lays.size(0) * b_loop_ub] = r1[i2];
          }

          lastBoxEdge = thisBoxCentre + thisLayThick / 2.0;

          // plot(x,Lays(:,i));
        }
      }

      // layers(end,3);
      subsBoxCen_tmp = x[x.size(1) - 1];
      asymconvstep(x, (subsBoxCen_tmp - lastBoxEdge) * 2.0, subsBoxCen_tmp,
                   nextLayRough, ssub, r1);
      loop_ub = Lays.size(0);
      for (i = 0; i < loop_ub; i++) {
        Lays[i + Lays.size(0) * (static_cast<int>(x_tmp + 1.0) - 1)] = r1[i];
      }

      // plot(x,Lays(:,(numberOfLayers*nrepeats)+1))
      loop_ub = Lays.size(0);
      for (i = 0; i < loop_ub; i++) {
        Lays[i + Lays.size(0) * (static_cast<int>(x_tmp + 2.0) - 1)] = airBox[i];
      }

      // plot(x,Lays(:,(numberOfLayers*nrepeats)+2))
      coder::blockedSummation(Lays, Lays.size(1), b_layers);
      b_loop_ub = b_layers.size(0);
      SLD.set_size(b_layers.size(0), 1);
      for (i = 0; i < b_loop_ub; i++) {
        SLD[i] = b_layers[i];
      }
    } else {
      double subsBoxCen_tmp;
      x.set_size(1, 101);
      r.set_size(1, 101);
      for (i = 0; i < 101; i++) {
        x[i] = i;
        r[i] = i;
      }

      subsBoxCen_tmp = coder::internal::maximum(r);
      r.set_size(1, 101);
      for (i = 0; i < 101; i++) {
        r[i] = i;
      }

      asymconvstep(r, subsBoxCen_tmp, 0.0, ssub, ssub, r1);
      r.set_size(1, 101);
      for (i = 0; i < 101; i++) {
        r[i] = i;
      }

      asymconvstep(r, subsBoxCen_tmp, subsBoxCen_tmp, ssub, ssub, r2);
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

// End of code generation (makeSLDProfileXY.cpp)
