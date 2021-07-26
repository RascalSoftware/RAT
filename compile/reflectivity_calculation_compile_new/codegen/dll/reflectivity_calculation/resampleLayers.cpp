//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// resampleLayers.cpp
//
// Code generation for function 'resampleLayers'
//

// Include files
#include "resampleLayers.h"
#include "adaptive.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "sldFunc.h"
#include "sortrows.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
void resampleLayers(const coder::array<double, 2U> &sldProfile,
                    coder::array<double, 2U> &newSLD)
{
  coder::array<double, 2U> b_dataPoints;
  coder::array<double, 2U> dataPoints;
  coder::array<double, 2U> newDataPoints;
  coder::array<double, 1U> cornerAngle;
  coder::array<double, 1U> r3;
  coder::array<int, 1U> r1;
  coder::array<int, 1U> r2;
  coder::array<boolean_T, 1U> r;
  coder::array<boolean_T, 1U> segmentsToSplit;
  coder::array<boolean_T, 1U> trianglesToRefine;
  double b_y[2][50];
  double y[50];
  double b_dv[2];
  double startDomain[2];
  double d2scaled;
  double delta1;
  int b_i;
  int end;
  int i;
  int k;
  //  Function handle for adaptive resampling
  //  f = @(x) sldFunc(x);
  //
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
  //        Refine near the  points which forms, together with their left and
  //        right neighbours, a triangle with central angle smaller than a given
  //        value.
  //   - 'maxArea': (default 5e-4)
  //        Refine near the points which forms, together with their left and
  //        right neighbours, a triangle with area larger than a threshold. The
  //        threshold in normalized to the area enclosing th graph:
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
  //        data are normalized so that max(x)-min(x)==1 and
  //        max(f(x))-min(f(x))==1.
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
  //    input_func = @(x) 100*exp(-(x+5.2).^2) + 50*exp(-5*(x-0.5).^2)+
  //    20*exp(-10*(x-5.8).^2); thresholdingAngles = true; minAngle = 0.8*pi;
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
  //    'adaptiveFunctionEvaluation:ArgChk','initial points must be specified as
  //    a numeric vector');
  //
  //  if mod(nExtraArgIn,2)==1
  //    error('adaptiveFunctionEvaluation:ArgChk', ...
  //      'At least a key or a value is missing in the key-value arguments
  //      list.');
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
  d2scaled = startDomain[0];
  y[49] = startDomain[1];
  y[0] = startDomain[0];
  if (startDomain[0] == -startDomain[1]) {
    d2scaled = startDomain[1] / 49.0;
    for (k = 0; k < 48; k++) {
      y[k + 1] = (2.0 * (static_cast<double>(k) + 2.0) - 51.0) * d2scaled;
    }
  } else if (((startDomain[0] < 0.0) != (startDomain[1] < 0.0)) &&
             ((std::abs(startDomain[0]) > 8.9884656743115785E+307) ||
              (std::abs(startDomain[1]) > 8.9884656743115785E+307))) {
    double delta2;
    delta1 = startDomain[0] / 49.0;
    delta2 = startDomain[1] / 49.0;
    for (k = 0; k < 48; k++) {
      y[k + 1] = (d2scaled + delta2 * (static_cast<double>(k) + 1.0)) -
                 delta1 * (static_cast<double>(k) + 1.0);
    }
  } else {
    delta1 = (startDomain[1] - startDomain[0]) / 49.0;
    for (k = 0; k < 48; k++) {
      y[k + 1] = d2scaled + (static_cast<double>(k) + 1.0) * delta1;
    }
  }
  //  Normalize the input function: This step allows to use the same syntax for
  //  functions with single or multiple output parameters.
  //  Remove this syntax for compile - AVH
  // func = @(x) normalizeFunction(x,sldProfile,vectorizable);
  //  Evaluate the input function on the initial set of points.
  //  Subfunctions
  //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N
  //  is the number of elements of x and M is the number of outputs of func.
  //  All the outputs of func must be scalar.
  //  The optional parameter 'vectorizable' (default false) allows to specify
  //  that the input function can be vectorized.
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
    d2scaled = y[i];
    b_y[0][i] = d2scaled;
    sldFunc(d2scaled, sldProfile, cornerAngle);
    b_y[1][i] = cornerAngle[0];
  }
  dataPoints.set_size(50, 2);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i = 0; i < 50; i++) {
      dataPoints[i + dataPoints.size(0) * b_i] = b_y[b_i][i];
    }
  }
  //  Iterative function refinement
  //  if displayWaitbar
  //    refinementWaitbar = waitbar(0,['Evaluating function
  //    ',func2str(func)],...
  //      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)');
  //    setappdata(refinementWaitbar,'canceling',false)
  //  end
  for (int nRefinements{0}; nRefinements < 10; nRefinements++) {
    boolean_T c_y;
    boolean_T exitg1;
    //  calculate the box which encloses the current data points:
    //  Each point is considered as the central corner of the triangle formed
    //  with its left and right hand side neighbours. The first and the last
    //  points are not the central corner of any triangle, so for N points
    //  there are only N-2 triangles.
    k = dataPoints.size(0);
    b_dataPoints.set_size(dataPoints.size(0), 2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (i = 0; i < k; i++) {
        b_dataPoints[i + b_dataPoints.size(0) * b_i] =
            dataPoints[i + dataPoints.size(0) * b_i];
      }
    }
    coder::internal::maximum(b_dataPoints, startDomain);
    k = dataPoints.size(0);
    b_dataPoints.set_size(dataPoints.size(0), 2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (i = 0; i < k; i++) {
        b_dataPoints[i + b_dataPoints.size(0) * b_i] =
            dataPoints[i + dataPoints.size(0) * b_i];
      }
    }
    coder::internal::minimum(b_dataPoints, b_dv);
    k = dataPoints.size(0);
    b_dataPoints.set_size(dataPoints.size(0), 2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (i = 0; i < k; i++) {
        b_dataPoints[i + b_dataPoints.size(0) * b_i] =
            dataPoints[i + dataPoints.size(0) * b_i];
      }
      startDomain[b_i] -= b_dv[b_i];
    }
    calculateCentralAngles(b_dataPoints, startDomain, cornerAngle);
    trianglesToRefine.set_size(dataPoints.size(0) - 2);
    k = dataPoints.size(0) - 2;
    for (b_i = 0; b_i < k; b_i++) {
      trianglesToRefine[b_i] = (cornerAngle[b_i] < 2.9845130209103035);
    }
    //  For N points there are N-2 triangles and N-1 triangle sides. Each
    //  triangle side is a segment, which can be split or not depending on the
    //  refinement parameters.
    segmentsToSplit.set_size(trianglesToRefine.size(0) + 1);
    k = trianglesToRefine.size(0);
    for (b_i = 0; b_i < k; b_i++) {
      segmentsToSplit[b_i] = trianglesToRefine[b_i];
    }
    segmentsToSplit[trianglesToRefine.size(0)] = false;
    r.set_size(trianglesToRefine.size(0) + 1);
    r[0] = false;
    k = trianglesToRefine.size(0);
    for (b_i = 0; b_i < k; b_i++) {
      r[b_i + 1] = trianglesToRefine[b_i];
    }
    k = segmentsToSplit.size(0);
    for (b_i = 0; b_i < k; b_i++) {
      segmentsToSplit[b_i] = (segmentsToSplit[b_i] || r[b_i]);
    }
    c_y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= segmentsToSplit.size(0) - 1)) {
      if (!segmentsToSplit[k]) {
        k++;
      } else {
        c_y = true;
        exitg1 = true;
      }
    }
    if (c_y) {
      //  increaseSampling increase the sampling of an input function
      end = segmentsToSplit.size(0);
      k = -1;
      for (i = 0; i < end; i++) {
        if (segmentsToSplit[i]) {
          k++;
        }
      }
      newDataPoints.set_size(k + 1, 2);
      k++;
      for (b_i = 0; b_i < 2; b_i++) {
        for (i = 0; i < k; i++) {
          newDataPoints[i + newDataPoints.size(0) * b_i] = 0.0;
        }
      }
      trianglesToRefine.set_size(segmentsToSplit.size(0) + 1);
      k = segmentsToSplit.size(0);
      for (b_i = 0; b_i < k; b_i++) {
        trianglesToRefine[b_i] = segmentsToSplit[b_i];
      }
      trianglesToRefine[segmentsToSplit.size(0)] = false;
      r.set_size(segmentsToSplit.size(0) + 1);
      r[0] = false;
      k = segmentsToSplit.size(0);
      for (b_i = 0; b_i < k; b_i++) {
        r[b_i + 1] = segmentsToSplit[b_i];
      }
      end = trianglesToRefine.size(0) - 1;
      k = 0;
      for (i = 0; i <= end; i++) {
        if (trianglesToRefine[i]) {
          k++;
        }
      }
      r1.set_size(k);
      k = 0;
      for (i = 0; i <= end; i++) {
        if (trianglesToRefine[i]) {
          r1[k] = i + 1;
          k++;
        }
      }
      end = r.size(0) - 1;
      k = 0;
      for (i = 0; i <= end; i++) {
        if (r[i]) {
          k++;
        }
      }
      r2.set_size(k);
      k = 0;
      for (i = 0; i <= end; i++) {
        if (r[i]) {
          r2[k] = i + 1;
          k++;
        }
      }
      k = r1.size(0);
      for (b_i = 0; b_i < k; b_i++) {
        newDataPoints[b_i] =
            0.5 * (dataPoints[r1[b_i] - 1] + dataPoints[r2[b_i] - 1]);
      }
      //  Subfunctions
      //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where
      //  N is the number of elements of x and M is the number of outputs of
      //  func. All the outputs of func must be scalar. The optional parameter
      //  'vectorizable' (default false) allows to specify that the input
      //  function can be vectorized. Modified by AVH for use with coder
      // if (~exist('vectorizable','var') || isempty(vectorizable))
      //  end
      // abs(nargout(func)); %for anonymous functions nargout<0
      r3.set_size(newDataPoints.size(0));
      //  if vectorizable
      //    % For uniformity reasons, transform the 'x' array into a column
      //    vector. % In this way it does not matter if it is given as a column
      //    or a row % vector. [newValues{:}] = func(x(:)); y =
      //    cell2mat(newValues);
      //  else
      b_i = newDataPoints.size(0) - 1;
      for (i = 0; i <= b_i; i++) {
        //  Remove cell array so no need for cell2mat
        //  which won't compile - AVH
        // [newValues{:}] = func(x(i));
        // y(i,:) = cell2mat(newValues);
        sldFunc(newDataPoints[i], sldProfile, cornerAngle);
        r3[i] = cornerAngle[0];
      }
      // end
      k = r3.size(0);
      for (b_i = 0; b_i < k; b_i++) {
        newDataPoints[b_i + newDataPoints.size(0)] = r3[b_i];
      }
      //  For simplicity append the new points at the end and then sort.
      if (dataPoints.size(0) != 0) {
        k = dataPoints.size(0);
      } else {
        k = 0;
      }
      if (newDataPoints.size(0) != 0) {
        end = newDataPoints.size(0);
      } else {
        end = 0;
      }
      b_dataPoints.set_size(k + end, 2);
      for (b_i = 0; b_i < 2; b_i++) {
        for (i = 0; i < k; i++) {
          b_dataPoints[i + b_dataPoints.size(0) * b_i] =
              dataPoints[i + dataPoints.size(0) * b_i];
        }
      }
      for (b_i = 0; b_i < 2; b_i++) {
        for (i = 0; i < end; i++) {
          b_dataPoints[(i + k) + b_dataPoints.size(0) * b_i] =
              newDataPoints[i + newDataPoints.size(0) * b_i];
        }
      }
      dataPoints.set_size(b_dataPoints.size(0), 2);
      k = b_dataPoints.size(0);
      for (b_i = 0; b_i < 2; b_i++) {
        for (i = 0; i < k; i++) {
          dataPoints[i + dataPoints.size(0) * b_i] =
              b_dataPoints[i + b_dataPoints.size(0) * b_i];
        }
      }
      coder::sortrows(dataPoints);
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
  // , 'nPoints', 50);
  if (dataPoints.size(0) == 0) {
    k = 0;
  } else if (dataPoints.size(0) > 1) {
    k = dataPoints.size(0);
  } else {
    k = 1;
  }
  newSLD.set_size(k - 1, 3);
  k--;
  for (b_i = 0; b_i < 3; b_i++) {
    for (i = 0; i < k; i++) {
      newSLD[i + newSLD.size(0) * b_i] = 0.0;
    }
  }
  //  Now build a layer model from these resampled points
  if (dataPoints.size(0) == 0) {
    k = -2;
  } else if (dataPoints.size(0) > 1) {
    k = dataPoints.size(0) - 2;
  } else {
    k = -1;
  }
  for (end = 0; end <= k; end++) {
    d2scaled = dataPoints[(end + dataPoints.size(0)) + 1];
    delta1 = dataPoints[end + dataPoints.size(0)];
    if (d2scaled > delta1) {
      d2scaled = (d2scaled - delta1) / 2.0 + delta1;
    } else {
      d2scaled += (delta1 - d2scaled) / 2.0;
    }
    newSLD[end] = dataPoints[end + 1] - dataPoints[end];
    newSLD[end + newSLD.size(0)] = d2scaled;
    newSLD[end + newSLD.size(0) * 2] = 2.2204460492503131E-16;
  }
}

void resampleLayers(coder::array<double, 2U> &newSLD)
{
  static const double initialDomain[50]{10.0,
                                        11.836734693877551,
                                        13.673469387755102,
                                        15.510204081632654,
                                        17.346938775510203,
                                        19.183673469387756,
                                        21.020408163265309,
                                        22.857142857142858,
                                        24.693877551020407,
                                        26.530612244897959,
                                        28.367346938775512,
                                        30.204081632653061,
                                        32.040816326530617,
                                        33.877551020408163,
                                        35.714285714285715,
                                        37.551020408163268,
                                        39.387755102040813,
                                        41.224489795918373,
                                        43.061224489795919,
                                        44.897959183673471,
                                        46.734693877551024,
                                        48.571428571428569,
                                        50.408163265306122,
                                        52.244897959183675,
                                        54.081632653061227,
                                        55.91836734693878,
                                        57.755102040816325,
                                        59.591836734693878,
                                        61.428571428571431,
                                        63.265306122448983,
                                        65.102040816326536,
                                        66.938775510204081,
                                        68.775510204081627,
                                        70.612244897959187,
                                        72.448979591836746,
                                        74.285714285714292,
                                        76.122448979591837,
                                        77.959183673469383,
                                        79.795918367346943,
                                        81.632653061224488,
                                        83.469387755102048,
                                        85.3061224489796,
                                        87.142857142857139,
                                        88.9795918367347,
                                        90.816326530612244,
                                        92.6530612244898,
                                        94.489795918367349,
                                        96.3265306122449,
                                        98.163265306122454,
                                        100.0};
  coder::array<double, 2U> b_dataPoints;
  coder::array<double, 2U> dataPoints;
  coder::array<double, 2U> newDataPoints;
  coder::array<double, 1U> cornerAngle;
  coder::array<double, 1U> r3;
  coder::array<int, 1U> r1;
  coder::array<int, 1U> r2;
  coder::array<boolean_T, 1U> r;
  coder::array<boolean_T, 1U> segmentsToSplit;
  coder::array<boolean_T, 1U> trianglesToRefine;
  double b_initialDomain[2][50];
  double tmp_data[3];
  double b_dv[2];
  double dv1[2];
  double thisLayRho;
  int b_i;
  int end;
  int i;
  int tmp_size;
  int trueCount;
  //  Function handle for adaptive resampling
  //  f = @(x) sldFunc(x);
  //
  //  Keep points and minangle as constants for now
  //  will fix later
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
  //        Refine near the  points which forms, together with their left and
  //        right neighbours, a triangle with central angle smaller than a given
  //        value.
  //   - 'maxArea': (default 5e-4)
  //        Refine near the points which forms, together with their left and
  //        right neighbours, a triangle with area larger than a threshold. The
  //        threshold in normalized to the area enclosing th graph:
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
  //        data are normalized so that max(x)-min(x)==1 and
  //        max(f(x))-min(f(x))==1.
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
  //    input_func = @(x) 100*exp(-(x+5.2).^2) + 50*exp(-5*(x-0.5).^2)+
  //    20*exp(-10*(x-5.8).^2); thresholdingAngles = true; minAngle = 0.8*pi;
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
  //    'adaptiveFunctionEvaluation:ArgChk','initial points must be specified as
  //    a numeric vector');
  //
  //  if mod(nExtraArgIn,2)==1
  //    error('adaptiveFunctionEvaluation:ArgChk', ...
  //      'At least a key or a value is missing in the key-value arguments
  //      list.');
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
  //  Normalize the input function: This step allows to use the same syntax for
  //  functions with single or multiple output parameters.
  //  Remove this syntax for compile - AVH
  // func = @(x) normalizeFunction(x,sldProfile,vectorizable);
  //  Evaluate the input function on the initial set of points.
  //  Subfunctions
  //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N
  //  is the number of elements of x and M is the number of outputs of func.
  //  All the outputs of func must be scalar.
  //  The optional parameter 'vectorizable' (default false) allows to specify
  //  that the input function can be vectorized.
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
    thisLayRho = initialDomain[i];
    b_initialDomain[0][i] = thisLayRho;
    sldFunc(thisLayRho, tmp_data, &tmp_size);
    b_initialDomain[1][i] = tmp_data[0];
  }
  dataPoints.set_size(50, 2);
  for (b_i = 0; b_i < 2; b_i++) {
    for (end = 0; end < 50; end++) {
      dataPoints[end + dataPoints.size(0) * b_i] = b_initialDomain[b_i][end];
    }
  }
  //  Iterative function refinement
  //  if displayWaitbar
  //    refinementWaitbar = waitbar(0,['Evaluating function
  //    ',func2str(func)],...
  //      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)');
  //    setappdata(refinementWaitbar,'canceling',false)
  //  end
  for (int nRefinements{0}; nRefinements < 10; nRefinements++) {
    boolean_T exitg1;
    boolean_T y;
    //  calculate the box which encloses the current data points:
    //  Each point is considered as the central corner of the triangle formed
    //  with its left and right hand side neighbours. The first and the last
    //  points are not the central corner of any triangle, so for N points
    //  there are only N-2 triangles.
    tmp_size = dataPoints.size(0);
    b_dataPoints.set_size(dataPoints.size(0), 2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (end = 0; end < tmp_size; end++) {
        b_dataPoints[end + b_dataPoints.size(0) * b_i] =
            dataPoints[end + dataPoints.size(0) * b_i];
      }
    }
    coder::internal::maximum(b_dataPoints, b_dv);
    tmp_size = dataPoints.size(0);
    b_dataPoints.set_size(dataPoints.size(0), 2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (end = 0; end < tmp_size; end++) {
        b_dataPoints[end + b_dataPoints.size(0) * b_i] =
            dataPoints[end + dataPoints.size(0) * b_i];
      }
    }
    coder::internal::minimum(b_dataPoints, dv1);
    tmp_size = dataPoints.size(0);
    b_dataPoints.set_size(dataPoints.size(0), 2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (end = 0; end < tmp_size; end++) {
        b_dataPoints[end + b_dataPoints.size(0) * b_i] =
            dataPoints[end + dataPoints.size(0) * b_i];
      }
      b_dv[b_i] -= dv1[b_i];
    }
    calculateCentralAngles(b_dataPoints, b_dv, cornerAngle);
    trianglesToRefine.set_size(dataPoints.size(0) - 2);
    tmp_size = dataPoints.size(0) - 2;
    for (b_i = 0; b_i < tmp_size; b_i++) {
      trianglesToRefine[b_i] = (cornerAngle[b_i] < 2.9845130209103035);
    }
    //  For N points there are N-2 triangles and N-1 triangle sides. Each
    //  triangle side is a segment, which can be split or not depending on the
    //  refinement parameters.
    segmentsToSplit.set_size(trianglesToRefine.size(0) + 1);
    tmp_size = trianglesToRefine.size(0);
    for (b_i = 0; b_i < tmp_size; b_i++) {
      segmentsToSplit[b_i] = trianglesToRefine[b_i];
    }
    segmentsToSplit[trianglesToRefine.size(0)] = false;
    r.set_size(trianglesToRefine.size(0) + 1);
    r[0] = false;
    tmp_size = trianglesToRefine.size(0);
    for (b_i = 0; b_i < tmp_size; b_i++) {
      r[b_i + 1] = trianglesToRefine[b_i];
    }
    tmp_size = segmentsToSplit.size(0);
    for (b_i = 0; b_i < tmp_size; b_i++) {
      segmentsToSplit[b_i] = (segmentsToSplit[b_i] || r[b_i]);
    }
    y = false;
    tmp_size = 0;
    exitg1 = false;
    while ((!exitg1) && (tmp_size <= segmentsToSplit.size(0) - 1)) {
      if (!segmentsToSplit[tmp_size]) {
        tmp_size++;
      } else {
        y = true;
        exitg1 = true;
      }
    }
    if (y) {
      //  increaseSampling increase the sampling of an input function
      end = segmentsToSplit.size(0);
      trueCount = -1;
      for (i = 0; i < end; i++) {
        if (segmentsToSplit[i]) {
          trueCount++;
        }
      }
      newDataPoints.set_size(trueCount + 1, 2);
      tmp_size = trueCount + 1;
      for (b_i = 0; b_i < 2; b_i++) {
        for (end = 0; end < tmp_size; end++) {
          newDataPoints[end + newDataPoints.size(0) * b_i] = 0.0;
        }
      }
      trianglesToRefine.set_size(segmentsToSplit.size(0) + 1);
      tmp_size = segmentsToSplit.size(0);
      for (b_i = 0; b_i < tmp_size; b_i++) {
        trianglesToRefine[b_i] = segmentsToSplit[b_i];
      }
      trianglesToRefine[segmentsToSplit.size(0)] = false;
      r.set_size(segmentsToSplit.size(0) + 1);
      r[0] = false;
      tmp_size = segmentsToSplit.size(0);
      for (b_i = 0; b_i < tmp_size; b_i++) {
        r[b_i + 1] = segmentsToSplit[b_i];
      }
      end = trianglesToRefine.size(0) - 1;
      trueCount = 0;
      for (i = 0; i <= end; i++) {
        if (trianglesToRefine[i]) {
          trueCount++;
        }
      }
      r1.set_size(trueCount);
      tmp_size = 0;
      for (i = 0; i <= end; i++) {
        if (trianglesToRefine[i]) {
          r1[tmp_size] = i + 1;
          tmp_size++;
        }
      }
      end = r.size(0) - 1;
      trueCount = 0;
      for (i = 0; i <= end; i++) {
        if (r[i]) {
          trueCount++;
        }
      }
      r2.set_size(trueCount);
      tmp_size = 0;
      for (i = 0; i <= end; i++) {
        if (r[i]) {
          r2[tmp_size] = i + 1;
          tmp_size++;
        }
      }
      tmp_size = r1.size(0);
      for (b_i = 0; b_i < tmp_size; b_i++) {
        newDataPoints[b_i] =
            0.5 * (dataPoints[r1[b_i] - 1] + dataPoints[r2[b_i] - 1]);
      }
      //  Subfunctions
      //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where
      //  N is the number of elements of x and M is the number of outputs of
      //  func. All the outputs of func must be scalar. The optional parameter
      //  'vectorizable' (default false) allows to specify that the input
      //  function can be vectorized. Modified by AVH for use with coder
      // if (~exist('vectorizable','var') || isempty(vectorizable))
      //  end
      // abs(nargout(func)); %for anonymous functions nargout<0
      r3.set_size(newDataPoints.size(0));
      //  if vectorizable
      //    % For uniformity reasons, transform the 'x' array into a column
      //    vector. % In this way it does not matter if it is given as a column
      //    or a row % vector. [newValues{:}] = func(x(:)); y =
      //    cell2mat(newValues);
      //  else
      b_i = newDataPoints.size(0) - 1;
      for (i = 0; i <= b_i; i++) {
        //  Remove cell array so no need for cell2mat
        //  which won't compile - AVH
        // [newValues{:}] = func(x(i));
        // y(i,:) = cell2mat(newValues);
        sldFunc(newDataPoints[i], tmp_data, &tmp_size);
        r3[i] = tmp_data[0];
      }
      // end
      tmp_size = r3.size(0);
      for (b_i = 0; b_i < tmp_size; b_i++) {
        newDataPoints[b_i + newDataPoints.size(0)] = r3[b_i];
      }
      //  For simplicity append the new points at the end and then sort.
      if (dataPoints.size(0) != 0) {
        tmp_size = dataPoints.size(0);
      } else {
        tmp_size = 0;
      }
      if (newDataPoints.size(0) != 0) {
        trueCount = newDataPoints.size(0);
      } else {
        trueCount = 0;
      }
      b_dataPoints.set_size(tmp_size + trueCount, 2);
      for (b_i = 0; b_i < 2; b_i++) {
        for (end = 0; end < tmp_size; end++) {
          b_dataPoints[end + b_dataPoints.size(0) * b_i] =
              dataPoints[end + dataPoints.size(0) * b_i];
        }
      }
      for (b_i = 0; b_i < 2; b_i++) {
        for (end = 0; end < trueCount; end++) {
          b_dataPoints[(end + tmp_size) + b_dataPoints.size(0) * b_i] =
              newDataPoints[end + newDataPoints.size(0) * b_i];
        }
      }
      dataPoints.set_size(b_dataPoints.size(0), 2);
      tmp_size = b_dataPoints.size(0);
      for (b_i = 0; b_i < 2; b_i++) {
        for (end = 0; end < tmp_size; end++) {
          dataPoints[end + dataPoints.size(0) * b_i] =
              b_dataPoints[end + b_dataPoints.size(0) * b_i];
        }
      }
      coder::sortrows(dataPoints);
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
  // , 'nPoints', 50);
  if (dataPoints.size(0) == 0) {
    tmp_size = 0;
  } else if (dataPoints.size(0) > 1) {
    tmp_size = dataPoints.size(0);
  } else {
    tmp_size = 1;
  }
  newSLD.set_size(tmp_size - 1, 3);
  tmp_size--;
  for (b_i = 0; b_i < 3; b_i++) {
    for (end = 0; end < tmp_size; end++) {
      newSLD[end + newSLD.size(0) * b_i] = 0.0;
    }
  }
  //  Now build a layer model from these resampled points
  if (dataPoints.size(0) == 0) {
    tmp_size = -2;
  } else if (dataPoints.size(0) > 1) {
    tmp_size = dataPoints.size(0) - 2;
  } else {
    tmp_size = -1;
  }
  for (trueCount = 0; trueCount <= tmp_size; trueCount++) {
    double d;
    thisLayRho = dataPoints[(trueCount + dataPoints.size(0)) + 1];
    d = dataPoints[trueCount + dataPoints.size(0)];
    if (thisLayRho > d) {
      thisLayRho = (thisLayRho - d) / 2.0 + d;
    } else {
      thisLayRho += (d - thisLayRho) / 2.0;
    }
    newSLD[trueCount] = dataPoints[trueCount + 1] - dataPoints[trueCount];
    newSLD[trueCount + newSLD.size(0)] = thisLayRho;
    newSLD[trueCount + newSLD.size(0) * 2] = 2.2204460492503131E-16;
  }
}

// End of code generation (resampleLayers.cpp)
