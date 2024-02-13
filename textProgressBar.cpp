//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// textProgressBar.cpp
//
// Code generation for function 'textProgressBar'
//

// Include files
#include "textProgressBar.h"
#include "RATMain_data.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sprintf.h"
#include "coder_array.h"
#include <cmath>
#include <stdio.h>

// Function Definitions
namespace RAT
{
  void lastNchar_not_empty_init()
  {
    lastNchar_not_empty = false;
  }

  void textProgressBar(real_T pct)
  {
    ::coder::array<char_T, 2U> progressmsg;
    ::coder::array<char_T, 2U> varargin_1;
    ::coder::array<char_T, 2U> varargin_2;
    real_T nDots;
    int32_T i;
    int32_T loop_ub;
    if (!lastNchar_not_empty) {
      lastNchar = 0.0;
      lastNchar_not_empty = true;
    }

    // curm = 'progress';
    nDots = std::floor(pct * 40.0);
    coder::repmat(nDots, varargin_1);
    coder::b_repmat(40.0 - nDots, varargin_2);
    progressmsg.set_size(1, (varargin_1.size(1) + varargin_2.size(1)) + 2);
    progressmsg[0] = '[';
    loop_ub = varargin_1.size(1);
    for (i = 0; i < loop_ub; i++) {
      progressmsg[i + 1] = varargin_1[i];
    }

    loop_ub = varargin_2.size(1);
    for (i = 0; i < loop_ub; i++) {
      progressmsg[(i + varargin_1.size(1)) + 1] = varargin_2[i];
    }

    progressmsg[(varargin_1.size(1) + varargin_2.size(1)) + 1] = ']';

    //  progressmsg=[183-uint16((1:40)<=(pct*40)).*(183-'*') ''];
    //  %curmtxt=sprintf('% 9.3g\n',curm(1:min(end,20),1));
    varargin_1.set_size(1, progressmsg.size(1));
    loop_ub = progressmsg.size(1) - 1;
    for (i = 0; i <= loop_ub; i++) {
      varargin_1[i] = progressmsg[i];
    }

    coder::b_sprintf(pct * 100.0, varargin_1, progressmsg);
    varargin_1.set_size(1, static_cast<int32_T>(lastNchar) + 1);
    loop_ub = static_cast<int32_T>(lastNchar);
    for (i = 0; i < loop_ub; i++) {
      varargin_1[i] = '\x08';
    }

    varargin_1[static_cast<int32_T>(lastNchar)] = '\x00';
    varargin_2.set_size(1, progressmsg.size(1) + 1);
    loop_ub = progressmsg.size(1);
    for (i = 0; i < loop_ub; i++) {
      varargin_2[i] = progressmsg[i];
    }

    varargin_2[progressmsg.size(1)] = '\x00';
    printf("%s%s", &varargin_1[0], &varargin_2[0]);
    fflush(stdout);
    lastNchar = progressmsg.size(1);
  }
}

// End of code generation (textProgressBar.cpp)
