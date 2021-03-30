//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: resampleLayers.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 24-Feb-2021 09:15:13
//

// Include Files
#include "resampleLayers.h"
#include "adaptive.h"
#include "chiSquared.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include "sldFunc.h"
#include "standardTF_stanLay_reflectivityCalculation.h"
#include <math.h>

// Function Definitions

//
// Function handle for adaptive resampling
//  f = @(x) sldFunc(x);
// Arguments    : const coder::array<double, 2U> *sldProfile
//                coder::array<double, 2U> *newSLD
// Return Type  : void
//
void resampleLayers(const coder::array<double, 2U> &sldProfile, coder::array<
                    double, 2U> &newSLD)
{
  double startDomain[2];
  double thisLayRho;
  double y[50];
  int k;
  double delta1;
  int i;
  coder::array<double, 2U> dataPoints;
  double b_y[100];
  coder::array<double, 1U> cornerAngle;
  coder::array<double, 2U> b_dataPoints;
  coder::array<boolean_T, 1U> trianglesToRefine;
  coder::array<boolean_T, 1U> segmentsToSplit;
  coder::array<boolean_T, 1U> r;

  //  Keep points and minangle as constants for now
  //  will fix later
  startDomain[0] = sldProfile[0];
  startDomain[1] = sldProfile[sldProfile.size(0) - 1];

  //  adaptive: evaluates a matlab function on a given range
  //
  //  'adaptive.m' allows to sample a function using a reduced number of
  //  points. It works iteratively adding new points where needed.
  //  It is especially useful for functions which are computationally intensive
  //  (e.g. involve solving a differential equation).
  //
  //  Usage:
  //  XY = adaptive(func, [xstart, xend])
  //   evaluates 'func' in the range [xstart, xend]. Key-value arguments are
  //   used to control the function evaluation. If the function 'func' returns
  //   multiple output values, only the first one is used for the refinement
  //   process, but all of them are calculated and returned as additional
  //   columns in the output matrix. The output matrix XY contains the new
  //   domain points in the first column and the output values in the other
  //   columns.
  //  [x,yy] = adaptive(func, [xstart, xend])
  //    as before but separately returns the array with the domain points and
  //    the array/matrix with the function output values.
  //  [x,yy] = adaptive(func, xarray, ...)
  //    as before but explicitly provide an initial array of domain points.
  //
  //  Methods:
  //    'adaptive' provides three methods for refining the function evaluation:
  //    1) add more points near the sharp corners, which are found by
  //     considering the triangles formed by three successive points and
  //     measuring the central angle.
  //    2) measure the area of the same triangles and add more points when the
  //     area is bigger than a threshold.
  //    3) measure the length of the segments formed by pairs of successive
  //     and split the segments which are longer than a threshold.
  //    If no methods is explicitly specified, the 'angle' method is used.
  //
  //  Input parameters
  //   - func: input function (function handle)
  //   - initialDomain: initial domain points (1D array)
  //
  //  Optional key-value input parameters
  //   - 'nPoints': (default 20)
  //        initial number of domain points, only used if an initial domain
  //        array is not excplitely provided.
  //   - 'maxRefinements': (default 10)
  //        Specifies the maximum number of refinement steps.
  //   - 'minAngle': (default 0.8*pi)
  //        Refine near the  points which forms, together with their left and right 
  //        neighbours, a triangle with central angle smaller than a given value. 
  //   - 'maxArea': (default 5e-4)
  //        Refine near the points which forms, together with their left and right 
  //        neighbours, a triangle with area larger than a threshold. The threshold 
  //        in normalized to the area enclosing th graph:
  //        threshold==maxArea*(max(x)-min(x))*(max(f(x))-min(f(x)))
  //   - 'maxLength': (default Inf)
  //        Refine all the sements which are longer than a given threshold. The
  //        threshold is relative to the input and output ranges. Specifically,
  //        before applying the threshold, the data are normalized so that
  //        max(x)-min(x)==1 and max(f(x))-min(f(x))==1.
  //   - 'minLength': (default 0)
  //        Exclude from the refinement process the segments which are shorter
  //        than a given threshold. The threshold is relative to the input and
  //        output ranges. Specifically, before applying the threshold, the
  //        data are normalized so that max(x)-min(x)==1 and max(f(x))-min(f(x))==1. 
  //   - 'minSignal': (default 0.2)
  //        Exclude from the refinement process the points where the function is 
  //        below a threshold. The threshold is relative to the output range: In 
  //        this example threshold == 0.01*(max(f(x))-min(f(x))).
  //   - 'vectorizable': (default false)
  //        Specifies whether the input function accepts arrays as input
  //        (e.g. f(x)==x.^2).
  //   - 'waitbar': (default false)
  //        Display a waitbar.
  //
  //  Output parameters
  //   - a NxM array where N is the number of domain points and M is the number
  //     of output parameters of the input function.
  //
  //
  //  Examples:
  //
  //    % Refine a function near sharp corners. The option 'minAngle' is useful
  //    % for having more points near the peaks of the function.
  //    f = @(x) exp(-x.^2/4).*sin(3*x);
  //    % for test-purpose also evaluate the function directly
  //    x2 = -10:0.01:10;
  //    y2 = f(x2);
  //    y = adaptive(f, [-5,5], 'minAngle',0.8*pi);
  //    figure(1); plot(x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('high sampling','adaptive')
  //    title('y = adaptive(f, [xstart, xend], ''minAngle'',0.8*pi)')
  //    % as before but starting with an inital array of domain points
  //    x = -5:5;
  //    y = adaptive(f, x, 'minAngle',0.8*pi);
  //    figure(2); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''minAngle'',0.8*pi)')
  //
  //    % Refine a function near sharp corners, but do not split segments which
  //    % are already shorter than 'minLength'.
  //    y = adaptive(f, x, 'minAngle',0.8*pi, 'minLength',0.05);
  //    figure(3); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''minAngle'',0.8*pi, ''minLength'',0.05)');
  //
  //    % Refine a function until the areas of the triangles formed by
  //    % triplets of successive points are smaller than 'maxArea'.
  //    y = adaptive(f, x, 'maxArea',1e-3);
  //    figure(4); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''maxArea'',1e-3)')
  //
  //    % Refine a function until the segments formed by pairs of successive
  //    % points are shorter than 'maxLength'.
  //    y = adaptive(f, x, 'maxLength',0.1);
  //    figure(5); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''maxLength'',0.1)');
  //  Copyright
  //  2017, Alberto Comin -  LMU Muenchen
  //  Version changes:
  //
  //  24/01/2017: 1) new default: when no optional argument is given, use the
  //   'angle' method as default 2) it is now possible to provide just the
  //   start and the end of the function domain, instead of having to
  //   explicitly provide an initial array 3) a new key-word argument
  //   'nPoints' controls the number of initial domain points in the cases when
  //   the initial array is not explicitly provided. 4) it is now possible to
  //   return the domain points and the function values either as a single 2D
  //   array or as two separate arrays.
  //  25/01/2017: fixed defaults for the case when no method is specified
  //  Default settings
  //  units normalized to data range
  //  units normalized to data range
  //  units normalized to data range
  //  units normalized to data range
  //  Test-mode
  //  The test mode is activated by calling 'adaptive.m' with no input.
  //  if nargin==0
  //    initialDomain =  -10:10;
  //    input_func = @(x) 100*exp(-(x+5.2).^2) + 50*exp(-5*(x-0.5).^2)+ 20*exp(-10*(x-5.8).^2); 
  //    thresholdingAngles = true;
  //    minAngle = 0.8*pi;
  //    thresholdingLength = true;
  //    minLength = 0.02;
  //    disp('Running adaptive.m in test mode');
  //    fprintf('input function: %s\n',func2str(input_func));
  //    disp('Plotting the function on a initial set of points');
  //    testFigureHandle = figure();
  //    plot(initialDomain, input_func(initialDomain),'bs-','LineWidth',1.5);
  //    grid on; xlabel('x'); ylabel('y'); title('adaptive.m example');
  //  end
  //  Processing input arguments
  //  assert(isa(input_func,'function_handle'),'adaptiveFunctionEvaluation:ArgChk',... 
  //    'the first argument must be a function handle');
  //  assert(isnumeric(initialDomain) && isvector(initialDomain),...
  //    'adaptiveFunctionEvaluation:ArgChk','initial points must be specified as a numeric vector'); 
  //
  //  if mod(nExtraArgIn,2)==1
  //    error('adaptiveFunctionEvaluation:ArgChk', ...
  //      'At least a key or a value is missing in the key-value arguments list.'); 
  //  end
  //  while n < nExtraArgIn
  //    switch lower(varargin{n})
  //      case 'minangle'
  //      case 'maxarea'
  //        maxArea = varargin{n+1};
  //        thresholdingArea = true;
  //        usingDefaultMethod = false;
  //        n = n+2;
  //      case 'maxlength'
  //        maxLength = varargin{n+1};
  //        thresholdingLength = true;
  //        usingDefaultMethod = false;
  //        n = n+2;
  //      case 'minlength'
  //        minLength = varargin{n+1};
  //        thresholdingLength = true;
  //        n = n+2;
  //      case 'minsignal'
  //        minSignal = varargin{n+1};
  //        thresholdingSignal = true;
  //        n = n+2;
  //      case 'npoints'
  //        nPoints = varargin{n+1};
  //        n = n+2;
  //      case 'vectorize'
  //        vectorizable = varargin{n+1};
  //        n = n+2;
  //      case 'maxrefinements'
  //        maxRefinements = varargin{n+1};
  //        n = n+2;
  //      case 'waitbar'
  //        displayWaitbar = varargin{n+1};
  //        n = n+2;
  //      otherwise
  //        error('adaptiveFunctionEvaluation:ArgChk',...
  //          ['unknown keyword argument: ', varargin{n}]);
  //    end
  //  end
  //  if no method is specified use the 'angle' method as default
  //  Initial function evaluation
  //  if initialDomain only contains the start and the end points, create a new
  //  array with 'nPoints' points.
  thisLayRho = startDomain[0];
  y[49] = startDomain[1];
  y[0] = startDomain[0];
  if (startDomain[0] == -startDomain[1]) {
    for (k = 0; k < 48; k++) {
      y[k + 1] = startDomain[1] * ((2.0 * (static_cast<double>(k) + 2.0) - 51.0)
        / 49.0);
    }
  } else if (((startDomain[0] < 0.0) != (startDomain[1] < 0.0)) && ((fabs
               (startDomain[0]) > 8.9884656743115785E+307) || (fabs(startDomain
                [1]) > 8.9884656743115785E+307))) {
    double delta2;
    delta1 = startDomain[0] / 49.0;
    delta2 = startDomain[1] / 49.0;
    for (k = 0; k < 48; k++) {
      y[k + 1] = (thisLayRho + delta2 * (static_cast<double>(k) + 1.0)) - delta1
        * (static_cast<double>(k) + 1.0);
    }
  } else {
    delta1 = (startDomain[1] - startDomain[0]) / 49.0;
    for (k = 0; k < 48; k++) {
      y[k + 1] = thisLayRho + (static_cast<double>(k) + 1.0) * delta1;
    }
  }

  //  Normalize the input function: This step allows to use the same syntax for
  //  functions with single or multiple output parameters.
  //  Remove this syntax for compile - AVH
  // func = @(x) normalizeFunction(x,sldProfile,vectorizable);
  //  Evaluate the input function on the initial set of points.
  //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N
  //  is the number of elements of x and M is the number of outputs of func.
  //  All the outputs of func must be scalar.
  //  The optional parameter 'vectorizable' (default false) allows to specify
  //  that the input function can be vectorized.
  //  Subfunctions
  //  Modified by AVH for use with coder
  // if (~exist('vectorizable','var') || isempty(vectorizable))
  //  end
  // abs(nargout(func)); %for anonymous functions nargout<0
  //  if vectorizable
  //    % For uniformity reasons, transform the 'x' array into a column vector.
  //    % In this way it does not matter if it is given as a column or a row
  //    % vector.
  //    [newValues{:}] = func(x(:));
  //    y = cell2mat(newValues);
  //  else
  // end
  // dataPoints = [initialDomain(:), func(initialDomain(:))];
  for (i = 0; i < 50; i++) {
    //  Remove cell array so no need for cell2mat
    //  which won't compile - AVH
    // [newValues{:}] = func(x(i));
    // y(i,:) = cell2mat(newValues);
    b_y[i] = y[i];
    sldFunc(y[i], sldProfile, cornerAngle);
    b_y[i + 50] = cornerAngle[0];
  }

  dataPoints.set_size(50, 2);
  for (i = 0; i < 100; i++) {
    dataPoints[i] = b_y[i];
  }

  //  Iterative function refinement
  //  if displayWaitbar
  //    refinementWaitbar = waitbar(0,['Evaluating function ',func2str(func)],... 
  //      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)');
  //    setappdata(refinementWaitbar,'canceling',false)
  //  end
  for (int nRefinements = 0; nRefinements < 10; nRefinements++) {
    boolean_T c_y;
    boolean_T exitg1;

    //  calculate the box which encloses the current data points:
    k = dataPoints.size(0);

    //  Each point is considered as the central corner of the triangle formed
    //  with its left and right hand side neighbours. The first and the last
    //  points are not the central corner of any triangle, so for N points
    //  there are only N-2 triangles.
    b_dataPoints.set_size(dataPoints.size(0), 2);
    startDomain[0] = dataPoints[0];
    thisLayRho = dataPoints[0];
    for (i = 2; i <= k; i++) {
      delta1 = dataPoints[i - 1];
      c_y = !rtIsNaN(delta1);
      if (c_y && (rtIsNaN(startDomain[0]) || (startDomain[0] < delta1))) {
        startDomain[0] = delta1;
      }

      if (c_y && (rtIsNaN(thisLayRho) || (thisLayRho > delta1))) {
        thisLayRho = delta1;
      }
    }

    for (i = 0; i < k; i++) {
      b_dataPoints[i] = dataPoints[i];
    }

    startDomain[0] -= thisLayRho;
    startDomain[1] = dataPoints[dataPoints.size(0)];
    thisLayRho = dataPoints[dataPoints.size(0)];
    for (i = 2; i <= k; i++) {
      delta1 = dataPoints[(i + dataPoints.size(0)) - 1];
      c_y = !rtIsNaN(delta1);
      if (c_y && (rtIsNaN(startDomain[1]) || (startDomain[1] < delta1))) {
        startDomain[1] = delta1;
      }

      if (c_y && (rtIsNaN(thisLayRho) || (thisLayRho > delta1))) {
        thisLayRho = delta1;
      }
    }

    for (i = 0; i < k; i++) {
      b_dataPoints[i + b_dataPoints.size(0)] = dataPoints[i + dataPoints.size(0)];
    }

    startDomain[1] -= thisLayRho;
    calculateCentralAngles(b_dataPoints, startDomain, cornerAngle);
    k = dataPoints.size(0);
    trianglesToRefine.set_size((dataPoints.size(0) - 2));
    for (i = 0; i <= k - 3; i++) {
      trianglesToRefine[i] = (cornerAngle[i] < 2.1991148575128552);
    }

    //  For N points there are N-2 triangles and N-1 triangle sides. Each
    //  triangle side is a segment, which can be split or not depending on the
    //  refinement parameters.
    segmentsToSplit.set_size((trianglesToRefine.size(0) + 1));
    k = trianglesToRefine.size(0);
    for (i = 0; i < k; i++) {
      segmentsToSplit[i] = trianglesToRefine[i];
    }

    segmentsToSplit[trianglesToRefine.size(0)] = false;
    r.set_size((trianglesToRefine.size(0) + 1));
    r[0] = false;
    k = trianglesToRefine.size(0);
    for (i = 0; i < k; i++) {
      r[i + 1] = trianglesToRefine[i];
    }

    k = segmentsToSplit.size(0);
    for (i = 0; i < k; i++) {
      segmentsToSplit[i] = (segmentsToSplit[i] || r[i]);
    }

    c_y = false;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (k <= segmentsToSplit.size(0))) {
      if (!segmentsToSplit[k - 1]) {
        k++;
      } else {
        c_y = true;
        exitg1 = true;
      }
    }

    if (c_y) {
      increaseSampling(dataPoints, segmentsToSplit, sldProfile);

      //    else
      //      break;
    }

    //  Removed waitbar for compile - AVH
    //    if displayWaitbar
    //      if getappdata(refinementWaitbar,'canceling'), break; end
    //      waitbar(nRefinements/maxRefinements,refinementWaitbar);
    //    end
  }

  //  if displayWaitbar
  //    delete(refinementWaitbar);
  //  end
  //  Plotting refined function
  //  Removed for compile - AVH
  //  if nargin==0 % test mode
  //    figure(testFigureHandle);
  //    hold on;
  //    plot(dataPoints(:,1), dataPoints(:,2),'ro-');
  //    legend('initial', 'refiniment');
  //  end
  if (dataPoints.size(0) == 0) {
    k = -1;
  } else if (dataPoints.size(0) > 1) {
    k = dataPoints.size(0) - 1;
  } else {
    k = 0;
  }

  newSLD.set_size(k, 3);
  k *= 3;
  for (i = 0; i < k; i++) {
    newSLD[i] = 0.0;
  }

  //  Now build a layer model from these resampled points
  if (dataPoints.size(0) == 0) {
    k = -2;
  } else if (dataPoints.size(0) > 1) {
    k = dataPoints.size(0) - 2;
  } else {
    k = -1;
  }

  for (i = 0; i <= k; i++) {
    thisLayRho = dataPoints[(i + dataPoints.size(0)) + 1];
    delta1 = dataPoints[i + dataPoints.size(0)];
    if (thisLayRho > delta1) {
      thisLayRho = (thisLayRho - delta1) / 2.0 + delta1;
    } else {
      thisLayRho += (delta1 - thisLayRho) / 2.0;
    }

    newSLD[i] = dataPoints[i + 1] - dataPoints[i];
    newSLD[i + newSLD.size(0)] = thisLayRho;
    newSLD[i + newSLD.size(0) * 2] = 2.2204460492503131E-16;
  }
}

//
// File trailer for resampleLayers.cpp
//
// [EOF]
//
