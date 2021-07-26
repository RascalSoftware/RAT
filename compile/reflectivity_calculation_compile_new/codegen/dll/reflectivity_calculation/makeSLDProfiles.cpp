//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// makeSLDProfiles.cpp
//
// Code generation for function 'makeSLDProfiles'
//

// Include files
#include "makeSLDProfiles.h"
#include "erf.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
void makeSLDProfiles(double nbair, double nbsub,
                     const coder::array<double, 2U> &sld, double ssub,
                     const double repeats[2],
                     coder::array<double, 2U> &sldProfile)
{
  coder::array<double, 2U> Lays;
  coder::array<double, 2U> SLD;
  coder::array<double, 2U> b_r;
  coder::array<double, 2U> b_x;
  coder::array<double, 2U> r1;
  coder::array<double, 2U> r2;
  coder::array<double, 2U> r3;
  coder::array<double, 2U> x;
  coder::array<double, 1U> b_sld;
  coder::array<double, 1U> bsum;
  double tmp_data[101];
  double nrepeats;
  int firstBlockLength;
  int hi;
  int i;
  int lastBlockLength;
  int loop_ub;
  int nblocks;
  int varargin_1;
  hi = sld.size(0);
  if (repeats[0] == 0.0) {
    nrepeats = 1.0;
  } else {
    nrepeats = repeats[1];
  }
  if (sld.size(0) > 0) {
    double a;
    double l;
    double lastBoxEdge;
    double nextLayRough;
    double r;
    double thisLayThick;
    double widths;
    int b_i;
    int b_k;
    int k;
    lastBlockLength = sld.size(0);
    b_sld.set_size(sld.size(0));
    for (i = 0; i < lastBlockLength; i++) {
      b_sld[i] = sld[i];
    }
    thisLayThick = coder::sum(b_sld) * nrepeats + 150.0;
    if (std::isnan(thisLayThick)) {
      x.set_size(1, 1);
      x[0] = rtNaN;
    } else if (thisLayThick < 0.0) {
      x.set_size(1, 0);
    } else if (std::isinf(thisLayThick) && (0.0 == thisLayThick)) {
      x.set_size(1, 1);
      x[0] = rtNaN;
    } else {
      lastBlockLength = static_cast<int>(std::floor(thisLayThick));
      x.set_size(1, lastBlockLength + 1);
      for (i = 0; i <= lastBlockLength; i++) {
        x[i] = i;
      }
    }
    firstBlockLength =
        static_cast<int>(static_cast<double>(sld.size(0)) * nrepeats + 2.0);
    Lays.set_size(x.size(1), firstBlockLength);
    for (i = 0; i < firstBlockLength; i++) {
      lastBlockLength = x.size(1);
      for (k = 0; k < lastBlockLength; k++) {
        Lays[k + Lays.size(0) * i] = 0.0;
      }
    }
    nextLayRough = sld[sld.size(0) * 2];
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
    lastBoxEdge = 1.4142135623730951 * nextLayRough;
    b_x.set_size(1, x.size(1));
    lastBlockLength = x.size(1);
    for (i = 0; i < lastBlockLength; i++) {
      b_x[i] = (x[i] - -50.0) / lastBoxEdge;
    }
    coder::b_erf(b_x, b_r);
    b_x.set_size(1, x.size(1));
    lastBlockLength = x.size(1);
    for (i = 0; i < lastBlockLength; i++) {
      b_x[i] = (x[i] - 50.0) / lastBoxEdge;
    }
    coder::b_erf(b_x, r1);
    a = nbair / 2.0;
    lastBoxEdge = 50.0;
    i = static_cast<int>(nrepeats);
    if (0 <= static_cast<int>(nrepeats) - 1) {
      varargin_1 = sld.size(0);
      loop_ub = x.size(1);
      nblocks = x.size(1);
    }
    for (firstBlockLength = 0; firstBlockLength < i; firstBlockLength++) {
      for (b_i = 0; b_i < varargin_1; b_i++) {
        thisLayThick = sld[b_i];
        if (b_i + 1 < hi) {
          nextLayRough = sld[(b_i + sld.size(0) * 2) + 1];
          //              elseif (i == numberOfLayers) && (n < nrepeats)
          //                  nextLayRough = layers(1,3);
        } else {
          nextLayRough = ssub;
        }
        widths = lastBoxEdge + thisLayThick / 2.0;
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
        lastBoxEdge = widths + thisLayThick / 2.0;
        l = widths - thisLayThick / 2.0;
        widths = 1.4142135623730951 * sld[b_i + sld.size(0) * 2];
        thisLayThick = 1.4142135623730951 * nextLayRough;
        b_x.set_size(1, x.size(1));
        for (k = 0; k < loop_ub; k++) {
          b_x[k] = (x[k] - l) / widths;
        }
        coder::b_erf(b_x, r2);
        b_x.set_size(1, x.size(1));
        for (k = 0; k < nblocks; k++) {
          b_x[k] = (x[k] - lastBoxEdge) / thisLayThick;
        }
        coder::b_erf(b_x, r3);
        thisLayThick = sld[b_i + sld.size(0)] / 2.0;
        k = static_cast<int>(
                (static_cast<double>(b_i) + 1.0) +
                static_cast<double>(hi) *
                    ((static_cast<double>(firstBlockLength) + 1.0) - 1.0)) -
            1;
        lastBlockLength = Lays.size(0);
        for (b_k = 0; b_k < lastBlockLength; b_k++) {
          Lays[b_k + Lays.size(0) * k] = thisLayThick * (r2[b_k] - r3[b_k]);
        }
        // plot(x,Lays(:,i));
      }
    }
    // layers(end,3);
    i = static_cast<int>(static_cast<double>(sld.size(0)) * nrepeats + 1.0) - 1;
    thisLayThick = (x[x.size(1) - 1] - lastBoxEdge) * 2.0;
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
    r = x[x.size(1) - 1] + thisLayThick / 2.0;
    l = x[x.size(1) - 1] - thisLayThick / 2.0;
    widths = 1.4142135623730951 * nextLayRough;
    thisLayThick = 1.4142135623730951 * ssub;
    b_x.set_size(1, x.size(1));
    lastBlockLength = x.size(1);
    for (k = 0; k < lastBlockLength; k++) {
      b_x[k] = (x[k] - l) / widths;
    }
    coder::b_erf(b_x, r2);
    b_x.set_size(1, x.size(1));
    lastBlockLength = x.size(1);
    for (k = 0; k < lastBlockLength; k++) {
      b_x[k] = (x[k] - r) / thisLayThick;
    }
    coder::b_erf(b_x, r3);
    thisLayThick = nbsub / 2.0;
    lastBlockLength = Lays.size(0);
    for (k = 0; k < lastBlockLength; k++) {
      Lays[k + Lays.size(0) * i] = thisLayThick * (r2[k] - r3[k]);
    }
    // plot(x,Lays(:,(numberOfLayers*nrepeats)+1))
    i = static_cast<int>(static_cast<double>(sld.size(0)) * nrepeats + 2.0) - 1;
    lastBlockLength = Lays.size(0);
    for (k = 0; k < lastBlockLength; k++) {
      Lays[k + Lays.size(0) * i] = a * (b_r[k] - r1[k]);
    }
    // plot(x,Lays(:,(numberOfLayers*nrepeats)+2))
    loop_ub = Lays.size(1);
    if ((Lays.size(0) == 0) || (Lays.size(1) == 0)) {
      b_sld.set_size(Lays.size(0));
      lastBlockLength = Lays.size(0);
      for (i = 0; i < lastBlockLength; i++) {
        b_sld[i] = 0.0;
      }
    } else {
      b_sld.set_size(Lays.size(0));
      bsum.set_size(Lays.size(0));
      if (Lays.size(1) <= 1024) {
        firstBlockLength = Lays.size(1);
        lastBlockLength = 0;
        nblocks = 1;
      } else {
        firstBlockLength = 1024;
        nblocks = Lays.size(1) / 1024;
        lastBlockLength = Lays.size(1) - (nblocks << 10);
        if (lastBlockLength > 0) {
          nblocks++;
        } else {
          lastBlockLength = 1024;
        }
      }
      i = Lays.size(0);
      for (b_k = 0; b_k < i; b_k++) {
        b_sld[b_k] = Lays[b_k];
      }
      for (b_k = 2; b_k <= firstBlockLength; b_k++) {
        i = Lays.size(0);
        for (k = 0; k < i; k++) {
          if (loop_ub >= 2) {
            b_sld[k] = b_sld[k] + Lays[k + Lays.size(0) * (b_k - 1)];
          }
        }
      }
      for (b_i = 2; b_i <= nblocks; b_i++) {
        firstBlockLength = (b_i - 1) << 10;
        i = Lays.size(0);
        for (b_k = 0; b_k < i; b_k++) {
          bsum[b_k] = Lays[b_k + Lays.size(0) * firstBlockLength];
        }
        if (b_i == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }
        for (b_k = 2; b_k <= hi; b_k++) {
          varargin_1 = firstBlockLength + b_k;
          i = Lays.size(0);
          for (k = 0; k < i; k++) {
            if (loop_ub >= 2) {
              bsum[k] = bsum[k] + Lays[k + Lays.size(0) * (varargin_1 - 1)];
            }
          }
        }
        i = b_sld.size(0);
        for (b_k = 0; b_k < i; b_k++) {
          b_sld[b_k] = b_sld[b_k] + bsum[b_k];
        }
      }
    }
    firstBlockLength = b_sld.size(0);
    SLD.set_size(b_sld.size(0), 1);
    for (i = 0; i < 1; i++) {
      for (k = 0; k < firstBlockLength; k++) {
        SLD[k] = b_sld[k];
      }
    }
  } else {
    double a;
    double l;
    double lastBoxEdge;
    double r;
    double thisLayThick;
    double widths;
    x.set_size(1, 101);
    for (i = 0; i < 101; i++) {
      x[i] = i;
      tmp_data[i] = i;
    }
    widths = coder::internal::maximum(tmp_data);
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
    r = widths / 2.0;
    l = 0.0 - widths / 2.0;
    lastBoxEdge = 1.4142135623730951 * ssub;
    b_x.set_size(1, 101);
    for (i = 0; i < 101; i++) {
      b_x[i] = (static_cast<double>(i) - l) / lastBoxEdge;
    }
    coder::b_erf(b_x, b_r);
    b_x.set_size(1, 101);
    for (i = 0; i < 101; i++) {
      b_x[i] = (static_cast<double>(i) - r) / lastBoxEdge;
    }
    coder::b_erf(b_x, r1);
    a = nbair / 2.0;
    for (i = 0; i < 101; i++) {
      tmp_data[i] = i;
    }
    thisLayThick = coder::internal::maximum(tmp_data);
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
    r = thisLayThick + widths / 2.0;
    l = thisLayThick - widths / 2.0;
    b_x.set_size(1, 101);
    for (i = 0; i < 101; i++) {
      b_x[i] = (static_cast<double>(i) - l) / lastBoxEdge;
    }
    coder::b_erf(b_x, r2);
    b_x.set_size(1, 101);
    for (i = 0; i < 101; i++) {
      b_x[i] = (static_cast<double>(i) - r) / lastBoxEdge;
    }
    coder::b_erf(b_x, r3);
    thisLayThick = nbsub / 2.0;
    SLD.set_size(1, b_r.size(1));
    lastBlockLength = b_r.size(1);
    for (i = 0; i < lastBlockLength; i++) {
      SLD[SLD.size(0) * i] =
          a * (b_r[i] - r1[i]) + thisLayThick * (r2[i] - r3[i]);
    }
  }
  // plot(x,SLD)
  firstBlockLength = SLD.size(0) * SLD.size(1);
  sldProfile.set_size(x.size(1), 2);
  lastBlockLength = x.size(1);
  for (i = 0; i < lastBlockLength; i++) {
    sldProfile[i] = x[i];
  }
  for (i = 0; i < firstBlockLength; i++) {
    sldProfile[i + sldProfile.size(0)] = SLD[i];
  }
}

// End of code generation (makeSLDProfiles.cpp)
