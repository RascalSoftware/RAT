//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// makeSLDProfileXY.cpp
//
// Code generation for function 'makeSLDProfileXY'
//

// Include files
#include "makeSLDProfileXY.h"
#include "asymconvstep.h"
#include "isinf.h"
#include "isnan.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
void makeSLDProfileXY(double nbair, double nbsub, double ssub,
                      const coder::array<double, 2U> &layers,
                      double numberOfLayers, double nrepeats,
                      coder::array<double, 2U> &out)
{
  coder::array<double, 2U> Lays;
  coder::array<double, 2U> SLD;
  coder::array<double, 2U> airBox;
  coder::array<double, 2U> thisBox;
  coder::array<double, 2U> x;
  coder::array<double, 1U> b_layers;
  double subBox_data[101];
  int b_Lays;
  int i;
  int loop_ub;
  if (numberOfLayers > 0.0) {
    double d;
    double nextLayRough;
    double widths;
    loop_ub = layers.size(0);
    b_layers.set_size(layers.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_layers[i] = layers[i];
    }
    widths = coder::sum(b_layers) * nrepeats + 150.0;
    if (coder::b_isnan(widths)) {
      x.set_size(1, 1);
      x[0] = rtNaN;
    } else if (widths < 0.0) {
      x.set_size(1, 0);
    } else if (coder::b_isinf(widths) && (0.0 == widths)) {
      x.set_size(1, 1);
      x[0] = rtNaN;
    } else {
      loop_ub = static_cast<int>(std::floor(widths));
      x.set_size(1, loop_ub + 1);
      for (i = 0; i <= loop_ub; i++) {
        x[i] = i;
      }
    }
    d = numberOfLayers * nrepeats;
    Lays.set_size(x.size(1), static_cast<int>(d + 2.0));
    loop_ub = x.size(1) * static_cast<int>(d + 2.0);
    for (i = 0; i < loop_ub; i++) {
      Lays[i] = 0.0;
    }
    nextLayRough = layers[layers.size(0) * 2];
    asymconvstep(x, 100.0, 0.0, nextLayRough, nextLayRough, nbair, airBox);
    widths = 50.0;
    i = static_cast<int>(nrepeats);
    for (int n{0}; n < i; n++) {
      b_Lays = static_cast<int>(numberOfLayers);
      for (int b_i{0}; b_i < b_Lays; b_i++) {
        double thisLayThick;
        int i1;
        thisLayThick = layers[b_i];
        if (static_cast<double>(b_i) + 1.0 < numberOfLayers) {
          nextLayRough = layers[(b_i + layers.size(0) * 2) + 1];
          //              elseif (i == numberOfLayers) && (n < nrepeats)
          //                  nextLayRough = layers(1,3);
        } else {
          nextLayRough = ssub;
        }
        widths += thisLayThick / 2.0;
        asymconvstep(x, thisLayThick, widths, layers[b_i + layers.size(0) * 2],
                     nextLayRough, layers[b_i + layers.size(0)], thisBox);
        i1 = static_cast<int>((static_cast<double>(b_i) + 1.0) +
                              numberOfLayers *
                                  ((static_cast<double>(n) + 1.0) - 1.0)) -
             1;
        loop_ub = Lays.size(0);
        for (int i2{0}; i2 < loop_ub; i2++) {
          Lays[i2 + Lays.size(0) * i1] = thisBox[i2];
        }
        widths += thisLayThick / 2.0;
        // plot(x,Lays(:,i));
      }
    }
    // layers(end,3);
    asymconvstep(x, (x[x.size(1) - 1] - widths) * 2.0, x[x.size(1) - 1],
                 nextLayRough, ssub, nbsub, thisBox);
    loop_ub = Lays.size(0);
    for (i = 0; i < loop_ub; i++) {
      Lays[i + Lays.size(0) * (static_cast<int>(d + 1.0) - 1)] = thisBox[i];
    }
    // plot(x,Lays(:,(numberOfLayers*nrepeats)+1))
    loop_ub = Lays.size(0);
    for (i = 0; i < loop_ub; i++) {
      Lays[i + Lays.size(0) * (static_cast<int>(d + 2.0) - 1)] = airBox[i];
    }
    // plot(x,Lays(:,(numberOfLayers*nrepeats)+2))
    coder::sum(Lays, b_layers);
    SLD.set_size(b_layers.size(0), 1);
    loop_ub = b_layers.size(0);
    for (i = 0; i < loop_ub; i++) {
      SLD[i] = b_layers[i];
    }
  } else {
    double widths;
    x.set_size(1, 101);
    Lays.set_size(1, 101);
    for (i = 0; i < 101; i++) {
      x[i] = i;
      subBox_data[i] = i;
      Lays[i] = i;
    }
    widths = coder::internal::maximum(subBox_data);
    asymconvstep(Lays, widths, 0.0, ssub, ssub, nbair, airBox);
    Lays.set_size(1, 101);
    for (i = 0; i < 101; i++) {
      subBox_data[i] = i;
      Lays[i] = i;
    }
    asymconvstep(Lays, widths, coder::internal::maximum(subBox_data), ssub,
                 ssub, nbsub, thisBox);
    loop_ub = thisBox.size(1);
    for (i = 0; i < loop_ub; i++) {
      subBox_data[i] = thisBox[i];
    }
    SLD.set_size(1, airBox.size(1));
    loop_ub = airBox.size(1);
    for (i = 0; i < loop_ub; i++) {
      SLD[i] = airBox[i] + subBox_data[i];
    }
  }
  // plot(x,SLD)
  b_Lays = SLD.size(0) * SLD.size(1);
  out.set_size(x.size(1), 2);
  loop_ub = x.size(1);
  for (i = 0; i < loop_ub; i++) {
    out[i] = x[i];
  }
  for (i = 0; i < b_Lays; i++) {
    out[i + out.size(0)] = SLD[i];
  }
}

// End of code generation (makeSLDProfileXY.cpp)
