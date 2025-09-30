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
  void makeSLDProfile(double bulkIn, double bulkOut, const ::coder::array<double,
                      2U> &layers, double ssub, double nrepeats, ::coder::array<
                      double, 2U> &SLDProfile)
  {
    ::coder::array<double, 2U> Lays;
    ::coder::array<double, 2U> SLD;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> r1;
    ::coder::array<double, 2U> r2;
    ::coder::array<double, 2U> roughnessValues;
    ::coder::array<double, 2U> x;
    ::coder::array<double, 1U> b_SLD;
    ::coder::array<double, 1U> b_layers;
    int b_loop_ub;
    int i;
    int i2;
    int loop_ub;
    if (layers.size(0) > 0) {
      double d;
      double lastBoxEdge;
      double nextLayerRoughness;
      double subsBoxCen_tmp;
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

      subsBoxCen_tmp = static_cast<double>(layers.size(0)) * nrepeats;
      Lays.set_size(x.size(1), static_cast<int>(subsBoxCen_tmp + 2.0));
      loop_ub = static_cast<int>(subsBoxCen_tmp + 2.0);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = x.size(1);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          Lays[i1 + Lays.size(0) * i] = 0.0;
        }
      }

      roughnessValues.set_size(1, layers.size(0));
      loop_ub = layers.size(0);
      for (i = 0; i < loop_ub; i++) {
        roughnessValues[i] = layers[i + layers.size(0) * 2];
      }

      roughnessValues.set_size(1, layers.size(0) + 1);
      roughnessValues[layers.size(0)] = ssub;
      nextLayerRoughness = roughnessValues[0];
      lastBoxEdge = 50.0;
      i = static_cast<int>(nrepeats);
      if (static_cast<int>(nrepeats) - 1 >= 0) {
        i2 = layers.size(0);
      }

      for (int n{0}; n < i; n++) {
        for (int b_i{0}; b_i < i2; b_i++) {
          double layerThickness;
          double thisBoxCentre;
          layerThickness = layers[b_i];
          d = roughnessValues[b_i + 1];
          nextLayerRoughness = d;
          thisBoxCentre = lastBoxEdge + 0.5 * layerThickness;
          i1 = static_cast<int>((static_cast<double>(b_i) + 1.0) + static_cast<
                                double>(layers.size(0)) * ((static_cast<double>
            (n) + 1.0) - 1.0)) - 1;
          asymconvstep(x, layerThickness, thisBoxCentre, roughnessValues[b_i], d,
                       layers[b_i + layers.size(0)], r1);
          loop_ub = Lays.size(0);
          for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
            Lays[b_loop_ub + Lays.size(0) * i1] = r1[b_loop_ub];
          }

          lastBoxEdge = thisBoxCentre + 0.5 * layerThickness;
        }
      }

      d = x[x.size(1) - 1];
      asymconvstep(x, (d - lastBoxEdge) * 2.0, d, nextLayerRoughness, ssub,
                   bulkOut, r1);
      loop_ub = Lays.size(0);
      for (i = 0; i < loop_ub; i++) {
        Lays[i + Lays.size(0) * (static_cast<int>(subsBoxCen_tmp + 1.0) - 1)] =
          r1[i];
      }

      asymconvstep(x, 100.0, 0.0, roughnessValues[0], roughnessValues[0], bulkIn,
                   r1);
      loop_ub = Lays.size(0);
      for (i = 0; i < loop_ub; i++) {
        Lays[i + Lays.size(0) * (static_cast<int>(subsBoxCen_tmp + 2.0) - 1)] =
          r1[i];
      }

      coder::blockedSummation(Lays, Lays.size(1), b_SLD);
      b_loop_ub = b_SLD.size(0);
      SLD.set_size(b_SLD.size(0), 1);
      for (i = 0; i < b_loop_ub; i++) {
        SLD[i] = b_SLD[i];
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

    b_loop_ub = SLD.size(0) * SLD.size(1);
    SLDProfile.set_size(x.size(1), 2);
    loop_ub = x.size(1);
    for (i = 0; i < loop_ub; i++) {
      SLDProfile[i] = x[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      SLDProfile[i + SLDProfile.size(0)] = SLD[i];
    }
  }

  void makeSLDProfile(const ::coder::array<double, 2U> &layers, double ssub,
                      double nrepeats, ::coder::array<double, 2U> &SLDProfile)
  {
    ::coder::array<double, 2U> Lays;
    ::coder::array<double, 2U> SLD;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> r1;
    ::coder::array<double, 2U> r2;
    ::coder::array<double, 2U> roughnessValues;
    ::coder::array<double, 2U> x;
    ::coder::array<double, 1U> b_SLD;
    ::coder::array<double, 1U> b_layers;
    int b_loop_ub;
    int i;
    int i2;
    int loop_ub;
    if (layers.size(0) > 0) {
      double d;
      double lastBoxEdge;
      double nextLayerRoughness;
      double subsBoxCen_tmp;
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

      subsBoxCen_tmp = static_cast<double>(layers.size(0)) * nrepeats;
      Lays.set_size(x.size(1), static_cast<int>(subsBoxCen_tmp + 2.0));
      loop_ub = static_cast<int>(subsBoxCen_tmp + 2.0);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = x.size(1);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          Lays[i1 + Lays.size(0) * i] = 0.0;
        }
      }

      roughnessValues.set_size(1, layers.size(0));
      loop_ub = layers.size(0);
      for (i = 0; i < loop_ub; i++) {
        roughnessValues[i] = layers[i + layers.size(0) * 2];
      }

      roughnessValues.set_size(1, layers.size(0) + 1);
      roughnessValues[layers.size(0)] = ssub;
      nextLayerRoughness = roughnessValues[0];
      lastBoxEdge = 50.0;
      i = static_cast<int>(nrepeats);
      if (static_cast<int>(nrepeats) - 1 >= 0) {
        i2 = layers.size(0);
      }

      for (int n{0}; n < i; n++) {
        for (int b_i{0}; b_i < i2; b_i++) {
          double layerThickness;
          double thisBoxCentre;
          layerThickness = layers[b_i];
          d = roughnessValues[b_i + 1];
          nextLayerRoughness = d;
          thisBoxCentre = lastBoxEdge + 0.5 * layerThickness;
          i1 = static_cast<int>((static_cast<double>(b_i) + 1.0) + static_cast<
                                double>(layers.size(0)) * ((static_cast<double>
            (n) + 1.0) - 1.0)) - 1;
          asymconvstep(x, layerThickness, thisBoxCentre, roughnessValues[b_i], d,
                       layers[b_i + layers.size(0)], r1);
          loop_ub = Lays.size(0);
          for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
            Lays[b_loop_ub + Lays.size(0) * i1] = r1[b_loop_ub];
          }

          lastBoxEdge = thisBoxCentre + 0.5 * layerThickness;
        }
      }

      d = x[x.size(1) - 1];
      asymconvstep(x, (d - lastBoxEdge) * 2.0, d, nextLayerRoughness, ssub, r1);
      loop_ub = Lays.size(0);
      for (i = 0; i < loop_ub; i++) {
        Lays[i + Lays.size(0) * (static_cast<int>(subsBoxCen_tmp + 1.0) - 1)] =
          r1[i];
      }

      asymconvstep(x, 100.0, 0.0, roughnessValues[0], roughnessValues[0], r1);
      loop_ub = Lays.size(0);
      for (i = 0; i < loop_ub; i++) {
        Lays[i + Lays.size(0) * (static_cast<int>(subsBoxCen_tmp + 2.0) - 1)] =
          r1[i];
      }

      coder::blockedSummation(Lays, Lays.size(1), b_SLD);
      b_loop_ub = b_SLD.size(0);
      SLD.set_size(b_SLD.size(0), 1);
      for (i = 0; i < b_loop_ub; i++) {
        SLD[i] = b_SLD[i];
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

    b_loop_ub = SLD.size(0) * SLD.size(1);
    SLDProfile.set_size(x.size(1), 2);
    loop_ub = x.size(1);
    for (i = 0; i < loop_ub; i++) {
      SLDProfile[i] = x[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      SLDProfile[i + SLDProfile.size(0)] = SLD[i];
    }
  }
}

// End of code generation (makeSLDProfile.cpp)
