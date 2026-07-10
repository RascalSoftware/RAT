//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// RATMain_rtwutil.cpp
//
// Code generation for function 'RATMain_rtwutil'
//

// Include files
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cfloat>
#include <cmath>

// Function Definitions
namespace RAT
{
  void cast(const b_struct_T &r, ::coder::array<cell_wrap_7, 1U>
            &t0_reflectivity, ::coder::array<cell_wrap_7, 1U> &t0_simulation, ::
            coder::array<cell_wrap_8, 1U> &t0_shiftedData, ::coder::array<
            cell_wrap_8, 1U> &t0_backgrounds, ::coder::array<cell_wrap_7, 1U>
            &t0_resolutions, ::coder::array<cell_wrap_9, 2U> &t0_sldProfiles, ::
            coder::array<cell_wrap_9, 2U> &t0_layers, ::coder::array<cell_wrap_9,
            2U> &t0_resampledLayers, ::coder::array<double, 2U> &t0_fitParams, ::
            coder::array<cell_wrap_10, 1U> &t0_fitNames, CalculationResults &
            t0_calculationResults, ContrastParams &t0_contrastParams)
  {
    int b_loop_ub;
    int i;
    int loop_ub;
    t0_reflectivity.set_size(r.reflectivity.size(0));
    loop_ub = r.reflectivity.size(0);
    for (i = 0; i < loop_ub; i++) {
      t0_reflectivity[i] = r.reflectivity[i];
    }

    t0_simulation.set_size(r.simulation.size(0));
    loop_ub = r.simulation.size(0);
    for (i = 0; i < loop_ub; i++) {
      t0_simulation[i] = r.simulation[i];
    }

    t0_shiftedData.set_size(r.shiftedData.size(0));
    loop_ub = r.shiftedData.size(0);
    for (i = 0; i < loop_ub; i++) {
      t0_shiftedData[i] = r.shiftedData[i];
    }

    t0_backgrounds.set_size(r.backgrounds.size(0));
    loop_ub = r.backgrounds.size(0);
    for (i = 0; i < loop_ub; i++) {
      t0_backgrounds[i] = r.backgrounds[i];
    }

    t0_resolutions.set_size(r.resolutions.size(0));
    loop_ub = r.resolutions.size(0);
    for (i = 0; i < loop_ub; i++) {
      t0_resolutions[i] = r.resolutions[i];
    }

    t0_sldProfiles.set_size(r.sldProfiles.size(0), r.sldProfiles.size(1));
    i = r.sldProfiles.size(0) * r.sldProfiles.size(1);
    for (int i1{0}; i1 < i; i1++) {
      loop_ub = r.sldProfiles[i1].f1.size(0);
      t0_sldProfiles[i1].f1.set_size(r.sldProfiles[i1].f1.size(0), 2);
      for (b_loop_ub = 0; b_loop_ub < 2; b_loop_ub++) {
        for (int i2{0}; i2 < loop_ub; i2++) {
          t0_sldProfiles[i1].f1[i2 + t0_sldProfiles[i1].f1.size(0) * b_loop_ub] =
            r.sldProfiles[i1].f1[i2 + r.sldProfiles[i1].f1.size(0) * b_loop_ub];
        }
      }
    }

    t0_layers.set_size(r.layers.size(0), r.layers.size(1));
    loop_ub = r.layers.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r.layers.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        t0_layers[i1 + t0_layers.size(0) * i] = r.layers[i1 + r.layers.size(0) *
          i];
      }
    }

    t0_resampledLayers.set_size(r.resampledLayers.size(0),
      r.resampledLayers.size(1));
    loop_ub = r.resampledLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r.resampledLayers.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        t0_resampledLayers[i1 + t0_resampledLayers.size(0) * i] =
          r.resampledLayers[i1 + r.resampledLayers.size(0) * i];
      }
    }

    t0_calculationResults = r.calculationResults;
    t0_contrastParams = r.contrastParams;
    t0_fitParams.set_size(1, r.fitParams.size(1));
    loop_ub = r.fitParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      t0_fitParams[i] = r.fitParams[i];
    }

    t0_fitNames.set_size(r.fitNames.size(0));
    loop_ub = r.fitNames.size(0);
    for (i = 0; i < loop_ub; i++) {
      t0_fitNames[i] = r.fitNames[i];
    }
  }

  void cast(const ::coder::array<cell_wrap_0, 1U> &r, ::coder::array<
            cell_wrap_10, 1U> &r1)
  {
    int i;
    r1.set_size(r.size(0));
    i = r.size(0);
    for (int i1{0}; i1 < i; i1++) {
      int loop_ub;
      loop_ub = r[i1].f1.size[1];
      r1[i1].f1.set_size(1, r[i1].f1.size[1]);
      for (int i2{0}; i2 < loop_ub; i2++) {
        r1[i1].f1[i2] = r[i1].f1.data[i2];
      }
    }
  }

  double rt_hypotd_snf(double u0, double u1)
  {
    double a;
    double b;
    double y;
    a = std::abs(u0);
    b = std::abs(u1);
    if (a < b) {
      a /= b;
      y = b * std::sqrt(a * a + 1.0);
    } else if (a > b) {
      b /= a;
      y = a * std::sqrt(b * b + 1.0);
    } else if (std::isnan(b)) {
      y = rtNaN;
    } else {
      y = a * 1.4142135623730951;
    }

    return y;
  }

  double rt_powd_snf(double u0, double u1)
  {
    double y;
    if (std::isnan(u0) || std::isnan(u1)) {
      y = rtNaN;
    } else {
      double d;
      double d1;
      d = std::abs(u0);
      d1 = std::abs(u1);
      if (std::isinf(u1)) {
        if (d == 1.0) {
          y = 1.0;
        } else if (d > 1.0) {
          if (u1 > 0.0) {
            y = rtInf;
          } else {
            y = 0.0;
          }
        } else if (u1 > 0.0) {
          y = 0.0;
        } else {
          y = rtInf;
        }
      } else if (d1 == 0.0) {
        y = 1.0;
      } else if (d1 == 1.0) {
        if (u1 > 0.0) {
          y = u0;
        } else {
          y = 1.0 / u0;
        }
      } else if (u1 == 2.0) {
        y = u0 * u0;
      } else if ((u1 == 0.5) && (u0 >= 0.0)) {
        y = std::sqrt(u0);
      } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
        y = rtNaN;
      } else {
        y = std::pow(u0, u1);
      }
    }

    return y;
  }

  double rt_remd_snf(double u0, double u1)
  {
    double y;
    if (std::isnan(u0) || std::isnan(u1) || std::isinf(u0)) {
      y = rtNaN;
    } else if (std::isinf(u1)) {
      y = u0;
    } else if ((u1 != 0.0) && (u1 != std::trunc(u1))) {
      double q;
      q = std::abs(u0 / u1);
      if (!(std::abs(q - std::floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = std::fmod(u0, u1);
      }
    } else {
      y = std::fmod(u0, u1);
    }

    return y;
  }
}

// End of code generation (RATMain_rtwutil.cpp)
