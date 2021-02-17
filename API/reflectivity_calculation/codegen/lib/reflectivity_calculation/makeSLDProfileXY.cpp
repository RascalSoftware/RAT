//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: makeSLDProfileXY.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "makeSLDProfileXY.h"
#include "applyScalarFunction.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include "standardTF_custXY_reflectivityCalculation.h"
#include <math.h>

// Function Definitions

//
// Arguments    : double nbair
//                double nbsub
//                double ssub
//                const coder::array<double, 2U> *layers
//                double numberOfLayers
//                double nrepeats
//                coder::array<double, 2U> *out
// Return Type  : void
//
void makeSLDProfileXY(double nbair, double nbsub, double ssub, const coder::
                      array<double, 2U> &layers, double numberOfLayers, double
                      nrepeats, coder::array<double, 2U> &out)
{
  coder::array<double, 2U> x;
  int i;
  double l;
  int vstride;
  int vlen;
  coder::array<double, 2U> Lays;
  coder::array<double, 2U> SLD;
  coder::array<double, 2U> r;
  coder::array<double, 2U> r1;
  coder::array<double, 2U> r2;
  coder::array<double, 2U> r3;
  coder::array<double, 1U> b_SLD;
  if (numberOfLayers > 0.0) {
    int k;
    double d;
    double nextLayRough;
    double aFactor;
    double bFactor;
    double a;
    double lastBoxEdge;
    int xoffset;
    int j;
    double b_r;
    i = layers.size(0);
    if (layers.size(0) == 0) {
      l = 0.0;
    } else {
      l = layers[0];
      for (k = 2; k <= i; k++) {
        l += layers[k - 1];
      }
    }

    l = l * nrepeats + 150.0;
    if (rtIsNaN(l)) {
      x.set_size(1, 1);
      x[0] = rtNaN;
    } else if (l < 0.0) {
      x.set_size(1, 0);
    } else if (rtIsInf(l) && (0.0 == l)) {
      x.set_size(1, 1);
      x[0] = rtNaN;
    } else {
      vstride = static_cast<int>(floor(l));
      x.set_size(1, (vstride + 1));
      for (i = 0; i <= vstride; i++) {
        x[i] = i;
      }
    }

    d = numberOfLayers * nrepeats;
    i = static_cast<int>(d + 2.0);
    Lays.set_size(x.size(1), i);
    vstride = x.size(1) * i;
    for (vlen = 0; vlen < vstride; vlen++) {
      Lays[vlen] = 0.0;
    }

    nextLayRough = layers[layers.size(0) * 2];

    //  Produces a step function convoluted with differnt error functions
    //  on each side.
    //  Convstep (x,xw,xcen,s1,s2,h)
    //        x = vector of x values
    //       xw = Width of step function
    //     xcen = Centre point of step function
    //        s1 = Roughness parameter of left side
    //        s2 = Roughness parameter of right side
    //        h = Height of step function.
    //  if length(xw) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               'xw must be single value');
    //      throw(ME);
    //  end
    //
    //  if length(xcen) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               'xcen must be single value');
    //      throw(ME);
    //  end
    //
    //  if length(s1) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               's1 must be single value');
    //      throw(ME);
    //  end
    //
    //  if length(s2) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               's2 must be single value');
    //      throw(ME);
    //  end
    aFactor = 1.4142135623730951 * nextLayRough;
    bFactor = 1.4142135623730951 * nextLayRough;
    SLD.set_size(1, x.size(1));
    vstride = x.size(0) * x.size(1);
    for (vlen = 0; vlen < vstride; vlen++) {
      SLD[vlen] = (x[vlen] - -50.0) / aFactor;
    }

    applyScalarFunction(SLD, r);
    SLD.set_size(1, x.size(1));
    vstride = x.size(0) * x.size(1);
    for (vlen = 0; vlen < vstride; vlen++) {
      SLD[vlen] = (x[vlen] - 50.0) / bFactor;
    }

    applyScalarFunction(SLD, r1);
    a = nbair / 2.0;
    lastBoxEdge = 50.0;
    vlen = static_cast<int>(nrepeats);
    for (xoffset = 0; xoffset < vlen; xoffset++) {
      j = static_cast<int>(numberOfLayers);
      for (k = 0; k < j; k++) {
        int i1;
        l = layers[k];
        if (static_cast<double>(k) + 1.0 < numberOfLayers) {
          nextLayRough = layers[(k + layers.size(0) * 2) + 1];

          //              elseif (i == numberOfLayers) && (n < nrepeats)
          //                  nextLayRough = layers(1,3);
        } else {
          nextLayRough = ssub;
        }

        b_r = lastBoxEdge + l / 2.0;

        //  Produces a step function convoluted with differnt error functions
        //  on each side.
        //  Convstep (x,xw,xcen,s1,s2,h)
        //        x = vector of x values
        //       xw = Width of step function
        //     xcen = Centre point of step function
        //        s1 = Roughness parameter of left side
        //        s2 = Roughness parameter of right side
        //        h = Height of step function.
        //  if length(xw) > 1
        //      ME = MException('VerifyOutput:OutOfBounds', ...
        //               'xw must be single value');
        //      throw(ME);
        //  end
        //
        //  if length(xcen) > 1
        //      ME = MException('VerifyOutput:OutOfBounds', ...
        //               'xcen must be single value');
        //      throw(ME);
        //  end
        //
        //  if length(s1) > 1
        //      ME = MException('VerifyOutput:OutOfBounds', ...
        //               's1 must be single value');
        //      throw(ME);
        //  end
        //
        //  if length(s2) > 1
        //      ME = MException('VerifyOutput:OutOfBounds', ...
        //               's2 must be single value');
        //      throw(ME);
        //  end
        lastBoxEdge = b_r + l / 2.0;
        l = b_r - l / 2.0;
        aFactor = 1.4142135623730951 * layers[k + layers.size(0) * 2];
        bFactor = 1.4142135623730951 * nextLayRough;
        SLD.set_size(1, x.size(1));
        vstride = x.size(0) * x.size(1);
        for (i1 = 0; i1 < vstride; i1++) {
          SLD[i1] = (x[i1] - l) / aFactor;
        }

        applyScalarFunction(SLD, r2);
        SLD.set_size(1, x.size(1));
        vstride = x.size(0) * x.size(1);
        for (i1 = 0; i1 < vstride; i1++) {
          SLD[i1] = (x[i1] - lastBoxEdge) / bFactor;
        }

        applyScalarFunction(SLD, r3);
        l = layers[k + layers.size(0)] / 2.0;
        i1 = static_cast<int>((static_cast<double>(k) + 1.0) + numberOfLayers *
                              ((static_cast<double>(xoffset) + 1.0) - 1.0)) - 1;
        vstride = Lays.size(0);
        for (int i2 = 0; i2 < vstride; i2++) {
          Lays[i2 + Lays.size(0) * i1] = l * (r2[i2] - r3[i2]);
        }

        // plot(x,Lays(:,i));
      }
    }

    // layers(end,3);
    vlen = static_cast<int>(d + 1.0) - 1;
    l = (x[x.size(1) - 1] - lastBoxEdge) * 2.0;

    //  Produces a step function convoluted with differnt error functions
    //  on each side.
    //  Convstep (x,xw,xcen,s1,s2,h)
    //        x = vector of x values
    //       xw = Width of step function
    //     xcen = Centre point of step function
    //        s1 = Roughness parameter of left side
    //        s2 = Roughness parameter of right side
    //        h = Height of step function.
    //  if length(xw) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               'xw must be single value');
    //      throw(ME);
    //  end
    //
    //  if length(xcen) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               'xcen must be single value');
    //      throw(ME);
    //  end
    //
    //  if length(s1) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               's1 must be single value');
    //      throw(ME);
    //  end
    //
    //  if length(s2) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               's2 must be single value');
    //      throw(ME);
    //  end
    b_r = x[x.size(1) - 1] + l / 2.0;
    l = x[x.size(1) - 1] - l / 2.0;
    aFactor = 1.4142135623730951 * nextLayRough;
    bFactor = 1.4142135623730951 * ssub;
    SLD.set_size(1, x.size(1));
    vstride = x.size(0) * x.size(1);
    for (j = 0; j < vstride; j++) {
      SLD[j] = (x[j] - l) / aFactor;
    }

    applyScalarFunction(SLD, r2);
    SLD.set_size(1, x.size(1));
    vstride = x.size(0) * x.size(1);
    for (j = 0; j < vstride; j++) {
      SLD[j] = (x[j] - b_r) / bFactor;
    }

    applyScalarFunction(SLD, r3);
    l = nbsub / 2.0;
    vstride = Lays.size(0);
    for (j = 0; j < vstride; j++) {
      Lays[j + Lays.size(0) * vlen] = l * (r2[j] - r3[j]);
    }

    // plot(x,Lays(:,(numberOfLayers*nrepeats)+1))
    i--;
    vstride = Lays.size(0);
    for (vlen = 0; vlen < vstride; vlen++) {
      Lays[vlen + Lays.size(0) * i] = a * (r[vlen] - r1[vlen]);
    }

    // plot(x,Lays(:,(numberOfLayers*nrepeats)+2))
    vlen = Lays.size(1);
    if ((Lays.size(0) == 0) || (Lays.size(1) == 0)) {
      unsigned int sz_idx_0;
      sz_idx_0 = static_cast<unsigned int>(Lays.size(0));
      b_SLD.set_size((static_cast<int>(sz_idx_0)));
      vstride = static_cast<int>(sz_idx_0);
      for (i = 0; i < vstride; i++) {
        b_SLD[i] = 0.0;
      }
    } else {
      vstride = Lays.size(0);
      b_SLD.set_size(Lays.size(0));
      for (j = 0; j < vstride; j++) {
        b_SLD[j] = Lays[j];
      }

      for (k = 2; k <= vlen; k++) {
        xoffset = (k - 1) * vstride;
        for (j = 0; j < vstride; j++) {
          b_SLD[j] = b_SLD[j] + Lays[xoffset + j];
        }
      }
    }

    SLD.set_size(b_SLD.size(0), 1);
    vstride = b_SLD.size(0);
    for (i = 0; i < vstride; i++) {
      SLD[i] = b_SLD[i];
    }
  } else {
    double aFactor;
    double bFactor;
    double a;
    double b_r;
    x.set_size(1, 101);
    for (i = 0; i < 101; i++) {
      x[i] = i;
    }

    vstride = 0;
    vlen = 0;
    for (int k = 0; k < 100; k++) {
      if (vstride < k + 1) {
        vstride = k + 1;
      }

      if (vlen < k + 1) {
        vlen = k + 1;
      }
    }

    //  Produces a step function convoluted with differnt error functions
    //  on each side.
    //  Convstep (x,xw,xcen,s1,s2,h)
    //        x = vector of x values
    //       xw = Width of step function
    //     xcen = Centre point of step function
    //        s1 = Roughness parameter of left side
    //        s2 = Roughness parameter of right side
    //        h = Height of step function.
    //  if length(xw) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               'xw must be single value');
    //      throw(ME);
    //  end
    //
    //  if length(xcen) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               'xcen must be single value');
    //      throw(ME);
    //  end
    //
    //  if length(s1) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               's1 must be single value');
    //      throw(ME);
    //  end
    //
    //  if length(s2) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               's2 must be single value');
    //      throw(ME);
    //  end
    l = static_cast<double>(vlen) / 2.0;
    aFactor = 1.4142135623730951 * ssub;
    bFactor = 1.4142135623730951 * ssub;
    SLD.set_size(1, 101);
    for (i = 0; i < 101; i++) {
      SLD[i] = (static_cast<double>(i) - (0.0 - l)) / aFactor;
    }

    applyScalarFunction(SLD, r);
    SLD.set_size(1, 101);
    for (i = 0; i < 101; i++) {
      SLD[i] = (static_cast<double>(i) - l) / bFactor;
    }

    applyScalarFunction(SLD, r1);
    a = nbair / 2.0;

    //  Produces a step function convoluted with differnt error functions
    //  on each side.
    //  Convstep (x,xw,xcen,s1,s2,h)
    //        x = vector of x values
    //       xw = Width of step function
    //     xcen = Centre point of step function
    //        s1 = Roughness parameter of left side
    //        s2 = Roughness parameter of right side
    //        h = Height of step function.
    //  if length(xw) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               'xw must be single value');
    //      throw(ME);
    //  end
    //
    //  if length(xcen) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               'xcen must be single value');
    //      throw(ME);
    //  end
    //
    //  if length(s1) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               's1 must be single value');
    //      throw(ME);
    //  end
    //
    //  if length(s2) > 1
    //      ME = MException('VerifyOutput:OutOfBounds', ...
    //               's2 must be single value');
    //      throw(ME);
    //  end
    b_r = static_cast<double>(vstride) + l;
    l = static_cast<double>(vstride) - l;
    aFactor = 1.4142135623730951 * ssub;
    bFactor = 1.4142135623730951 * ssub;
    SLD.set_size(1, 101);
    for (i = 0; i < 101; i++) {
      SLD[i] = (static_cast<double>(i) - l) / aFactor;
    }

    applyScalarFunction(SLD, r2);
    SLD.set_size(1, 101);
    for (i = 0; i < 101; i++) {
      SLD[i] = (static_cast<double>(i) - b_r) / bFactor;
    }

    applyScalarFunction(SLD, r3);
    l = nbsub / 2.0;
    SLD.set_size(1, r.size(1));
    vstride = r.size(0) * r.size(1);
    for (i = 0; i < vstride; i++) {
      SLD[i] = a * (r[i] - r1[i]) + l * (r2[i] - r3[i]);
    }
  }

  // plot(x,SLD)
  vlen = SLD.size(0) * SLD.size(1);
  out.set_size(x.size(1), 2);
  vstride = x.size(1);
  for (i = 0; i < vstride; i++) {
    out[i] = x[i];
  }

  for (i = 0; i < vlen; i++) {
    out[i + out.size(0)] = SLD[i];
  }
}

//
// File trailer for makeSLDProfileXY.cpp
//
// [EOF]
//
