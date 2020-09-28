/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * resampleLayers.c
 *
 * Code generation for function 'resampleLayers'
 *
 */

/* Include files */
#include "resampleLayers.h"
#include "adaptive.h"
#include "any.h"
#include "eml_int_forloop_overflow_check.h"
#include "linspace.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "sldFunc.h"

/* Variable Definitions */
static emlrtRSInfo uc_emlrtRSI = { 18, /* lineNo */
  "resampleLayers",                    /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 252,/* lineNo */
  "adaptive",                          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 267,/* lineNo */
  "adaptive",                          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 281,/* lineNo */
  "adaptive",                          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 304,/* lineNo */
  "adaptive",                          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 305,/* lineNo */
  "adaptive",                          /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  289,                                 /* lineNo */
  21,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  283,                                 /* lineNo */
  25,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtDCInfo hb_emlrtDCI = { 274,/* lineNo */
  30,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo ig_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  12,                                  /* colNo */
  "layers",                            /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  18,                                  /* colNo */
  "newY",                              /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  18,                                  /* colNo */
  "newY",                              /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  18,                                  /* colNo */
  "newX",                              /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  18,                                  /* colNo */
  "newX",                              /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ng_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  10,                                  /* colNo */
  "x",                                 /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo og_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  12,                                  /* colNo */
  "x",                                 /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ib_emlrtDCI = { 23, /* lineNo */
  16,                                  /* colNo */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  4                                    /* checkKind */
};

static emlrtRTEInfo aj_emlrtRTEI = { 255,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo bj_emlrtRTEI = { 23,/* lineNo */
  1,                                   /* colNo */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pName */
};

static emlrtRTEInfo cj_emlrtRTEI = { 281,/* lineNo */
  42,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo dj_emlrtRTEI = { 282,/* lineNo */
  5,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo ej_emlrtRTEI = { 283,/* lineNo */
  5,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo fj_emlrtRTEI = { 289,/* lineNo */
  21,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo gj_emlrtRTEI = { 289,/* lineNo */
  50,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo hj_emlrtRTEI = { 281,/* lineNo */
  5,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo ij_emlrtRTEI = { 289,/* lineNo */
  3,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo jj_emlrtRTEI = { 2,/* lineNo */
  19,                                  /* colNo */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pName */
};

/* Function Definitions */
void resampleLayers(const emlrtStack *sp, const emxArray_real_T *sldProfile,
                    emxArray_real_T *newSLD)
{
  real_T newDomain[50];
  emxArray_real_T *cornerAngle;
  int32_T i;
  int32_T b_i;
  emxArray_real_T *dataPoints;
  real_T b_newDomain[100];
  real_T hiVal[50];
  int32_T nRefinements;
  emxArray_boolean_T *sharpCorners;
  emxArray_boolean_T *segmentsToSplit;
  emxArray_boolean_T *r;
  emxArray_real_T *b_dataPoints;
  boolean_T exitg1;
  boolean_T overflow;
  real_T startDomain[2];
  real_T thisLayRho;
  int32_T n;
  real_T minval_idx_0;
  real_T minval_idx_1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Function handle for adaptive resampling */
  /*  f = @(x) sldFunc(x); */
  /*   */
  if (1 > sldProfile->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, sldProfile->size[0], &og_emlrtBCI, sp);
  }

  if (sldProfile->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(sldProfile->size[0], 1, sldProfile->size[0],
      &ng_emlrtBCI, sp);
  }

  /*  Keep points and minangle as constants for now */
  /*  will fix later */
  st.site = &uc_emlrtRSI;

  /*  adaptive: evaluates a matlab function on a given range */
  /*  */
  /*  'adaptive.m' allows to sample a function using a reduced number of */
  /*  points. It works iteratively adding new points where needed. */
  /*  It is especially useful for functions which are computationally intensive */
  /*  (e.g. involve solving a differential equation). */
  /*  */
  /*  Usage: */
  /*  XY = adaptive(func, [xstart, xend]) */
  /*   evaluates 'func' in the range [xstart, xend]. Key-value arguments are */
  /*   used to control the function evaluation. If the function 'func' returns */
  /*   multiple output values, only the first one is used for the refinement */
  /*   process, but all of them are calculated and returned as additional */
  /*   columns in the output matrix. The output matrix XY contains the new */
  /*   domain points in the first column and the output values in the other */
  /*   columns. */
  /*  [x,yy] = adaptive(func, [xstart, xend]) */
  /*    as before but separately returns the array with the domain points and */
  /*    the array/matrix with the function output values. */
  /*  [x,yy] = adaptive(func, xarray, ...) */
  /*    as before but explicitly provide an initial array of domain points. */
  /*  */
  /*  Methods: */
  /*    'adaptive' provides three methods for refining the function evaluation: */
  /*    1) add more points near the sharp corners, which are found by */
  /*     considering the triangles formed by three successive points and */
  /*     measuring the central angle. */
  /*    2) measure the area of the same triangles and add more points when the */
  /*     area is bigger than a threshold. */
  /*    3) measure the length of the segments formed by pairs of successive */
  /*     and split the segments which are longer than a threshold. */
  /*    If no methods is explicitly specified, the 'angle' method is used. */
  /*  */
  /*  Input parameters */
  /*   - func: input function (function handle) */
  /*   - initialDomain: initial domain points (1D array) */
  /*  */
  /*  Optional key-value input parameters */
  /*   - 'nPoints': (default 20) */
  /*        initial number of domain points, only used if an initial domain */
  /*        array is not excplitely provided. */
  /*   - 'maxRefinements': (default 10) */
  /*        Specifies the maximum number of refinement steps. */
  /*   - 'minAngle': (default 0.8*pi) */
  /*        Refine near the  points which forms, together with their left and right */
  /*        neighbours, a triangle with central angle smaller than a given value. */
  /*   - 'maxArea': (default 5e-4) */
  /*        Refine near the points which forms, together with their left and right */
  /*        neighbours, a triangle with area larger than a threshold. The threshold */
  /*        in normalized to the area enclosing th graph: */
  /*        threshold==maxArea*(max(x)-min(x))*(max(f(x))-min(f(x))) */
  /*   - 'maxLength': (default Inf) */
  /*        Refine all the sements which are longer than a given threshold. The */
  /*        threshold is relative to the input and output ranges. Specifically, */
  /*        before applying the threshold, the data are normalized so that */
  /*        max(x)-min(x)==1 and max(f(x))-min(f(x))==1. */
  /*   - 'minLength': (default 0) */
  /*        Exclude from the refinement process the segments which are shorter */
  /*        than a given threshold. The threshold is relative to the input and */
  /*        output ranges. Specifically, before applying the threshold, the */
  /*        data are normalized so that max(x)-min(x)==1 and max(f(x))-min(f(x))==1. */
  /*   - 'minSignal': (default 0.2) */
  /*        Exclude from the refinement process the points where the function is */
  /*        below a threshold. The threshold is relative to the output range: In */
  /*        this example threshold == 0.01*(max(f(x))-min(f(x))). */
  /*   - 'vectorizable': (default false) */
  /*        Specifies whether the input function accepts arrays as input */
  /*        (e.g. f(x)==x.^2). */
  /*   - 'waitbar': (default false) */
  /*        Display a waitbar. */
  /*  */
  /*  Output parameters */
  /*   - a NxM array where N is the number of domain points and M is the number */
  /*     of output parameters of the input function. */
  /*  */
  /*  */
  /*  Examples: */
  /*  */
  /*    % Refine a function near sharp corners. The option 'minAngle' is useful */
  /*    % for having more points near the peaks of the function. */
  /*    f = @(x) exp(-x.^2/4).*sin(3*x); */
  /*    % for test-purpose also evaluate the function directly */
  /*    x2 = -10:0.01:10; */
  /*    y2 = f(x2); */
  /*    y = adaptive(f, [-5,5], 'minAngle',0.8*pi); */
  /*    figure(1); plot(x2,f(x2),'k--',y(:,1),y(:,2),'o-'); */
  /*    legend('high sampling','adaptive') */
  /*    title('y = adaptive(f, [xstart, xend], ''minAngle'',0.8*pi)') */
  /*    % as before but starting with an inital array of domain points */
  /*    x = -5:5; */
  /*    y = adaptive(f, x, 'minAngle',0.8*pi); */
  /*    figure(2); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); */
  /*    legend('initial sampling','high sampling','adaptive') */
  /*    title('y = adaptive(f, x, ''minAngle'',0.8*pi)') */
  /*  */
  /*    % Refine a function near sharp corners, but do not split segments which */
  /*    % are already shorter than 'minLength'. */
  /*    y = adaptive(f, x, 'minAngle',0.8*pi, 'minLength',0.05); */
  /*    figure(3); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); */
  /*    legend('initial sampling','high sampling','adaptive') */
  /*    title('y = adaptive(f, x, ''minAngle'',0.8*pi, ''minLength'',0.05)'); */
  /*  */
  /*    % Refine a function until the areas of the triangles formed by */
  /*    % triplets of successive points are smaller than 'maxArea'. */
  /*    y = adaptive(f, x, 'maxArea',1e-3); */
  /*    figure(4); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); */
  /*    legend('initial sampling','high sampling','adaptive') */
  /*    title('y = adaptive(f, x, ''maxArea'',1e-3)') */
  /*  */
  /*    % Refine a function until the segments formed by pairs of successive */
  /*    % points are shorter than 'maxLength'. */
  /*    y = adaptive(f, x, 'maxLength',0.1); */
  /*    figure(5); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-'); */
  /*    legend('initial sampling','high sampling','adaptive') */
  /*    title('y = adaptive(f, x, ''maxLength'',0.1)'); */
  /*  Copyright */
  /*  2017, Alberto Comin -  LMU Muenchen */
  /*  Version changes: */
  /*  */
  /*  24/01/2017: 1) new default: when no optional argument is given, use the */
  /*   'angle' method as default 2) it is now possible to provide just the */
  /*   start and the end of the function domain, instead of having to */
  /*   explicitly provide an initial array 3) a new key-word argument */
  /*   'nPoints' controls the number of initial domain points in the cases when */
  /*   the initial array is not explicitly provided. 4) it is now possible to */
  /*   return the domain points and the function values either as a single 2D */
  /*   array or as two separate arrays. */
  /*  25/01/2017: fixed defaults for the case when no method is specified */
  /*  Default settings */
  /*  units normalized to data range */
  /*  units normalized to data range */
  /*  units normalized to data range */
  /*  units normalized to data range */
  /*  Test-mode */
  /*  The test mode is activated by calling 'adaptive.m' with no input. */
  /*  if nargin==0 */
  /*    initialDomain =  -10:10; */
  /*    input_func = @(x) 100*exp(-(x+5.2).^2) + 50*exp(-5*(x-0.5).^2)+ 20*exp(-10*(x-5.8).^2); */
  /*    thresholdingAngles = true; */
  /*    minAngle = 0.8*pi; */
  /*    thresholdingLength = true; */
  /*    minLength = 0.02; */
  /*    disp('Running adaptive.m in test mode'); */
  /*    fprintf('input function: %s\n',func2str(input_func)); */
  /*    disp('Plotting the function on a initial set of points'); */
  /*    testFigureHandle = figure(); */
  /*    plot(initialDomain, input_func(initialDomain),'bs-','LineWidth',1.5); */
  /*    grid on; xlabel('x'); ylabel('y'); title('adaptive.m example'); */
  /*  end */
  /*  Processing input arguments */
  /*  assert(isa(input_func,'function_handle'),'adaptiveFunctionEvaluation:ArgChk',... */
  /*    'the first argument must be a function handle'); */
  /*  assert(isnumeric(initialDomain) && isvector(initialDomain),... */
  /*    'adaptiveFunctionEvaluation:ArgChk','initial points must be specified as a numeric vector'); */
  /*   */
  /*  if mod(nExtraArgIn,2)==1 */
  /*    error('adaptiveFunctionEvaluation:ArgChk', ... */
  /*      'At least a key or a value is missing in the key-value arguments list.'); */
  /*  end */
  /*  while n < nExtraArgIn */
  /*    switch lower(varargin{n})   */
  /*      case 'minangle' */
  /*      case 'maxarea' */
  /*        maxArea = varargin{n+1}; */
  /*        thresholdingArea = true; */
  /*        usingDefaultMethod = false; */
  /*        n = n+2; */
  /*      case 'maxlength' */
  /*        maxLength = varargin{n+1}; */
  /*        thresholdingLength = true; */
  /*        usingDefaultMethod = false; */
  /*        n = n+2; */
  /*      case 'minlength' */
  /*        minLength = varargin{n+1}; */
  /*        thresholdingLength = true; */
  /*        n = n+2; */
  /*      case 'minsignal' */
  /*        minSignal = varargin{n+1}; */
  /*        thresholdingSignal = true; */
  /*        n = n+2; */
  /*      case 'npoints' */
  /*        nPoints = varargin{n+1}; */
  /*        n = n+2; */
  /*      case 'vectorize' */
  /*        vectorizable = varargin{n+1}; */
  /*        n = n+2; */
  /*      case 'maxrefinements' */
  /*        maxRefinements = varargin{n+1}; */
  /*        n = n+2; */
  /*      case 'waitbar' */
  /*        displayWaitbar = varargin{n+1}; */
  /*        n = n+2; */
  /*      otherwise */
  /*        error('adaptiveFunctionEvaluation:ArgChk',... */
  /*          ['unknown keyword argument: ', varargin{n}]); */
  /*    end */
  /*  end */
  /*  if no method is specified use the 'angle' method as default */
  /*  Initial function evaluation */
  /*  if initialDomain only contains the start and the end points, create a new */
  /*  array with 'nPoints' points. */
  linspace(sldProfile->data[0], sldProfile->data[sldProfile->size[0] - 1],
           newDomain);

  /*  Normalize the input function: This step allows to use the same syntax for */
  /*  functions with single or multiple output parameters. */
  /*  Remove this syntax for compile - AVH */
  /* func = @(x) normalizeFunction(x,sldProfile,vectorizable); */
  /*  Evaluate the input function on the initial set of points. */
  b_st.site = &vc_emlrtRSI;

  /*  Subfunctions */
  /*  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N */
  /*  is the number of elements of x and M is the number of outputs of func. */
  /*  All the outputs of func must be scalar. */
  /*  The optional parameter 'vectorizable' (default false) allows to specify */
  /*  that the input function can be vectorized. */
  /*  Modified by AVH for use with coder */
  /* if (~exist('vectorizable','var') || isempty(vectorizable)) */
  /*  end */
  /* abs(nargout(func)); %for anonymous functions nargout<0 */
  /*  if vectorizable */
  /*    % For uniformity reasons, transform the 'x' array into a column vector. */
  /*    % In this way it does not matter if it is given as a column or a row */
  /*    % vector. */
  /*    [newValues{:}] = func(x(:)); */
  /*    y = cell2mat(newValues); */
  /*  else */
  emxInit_real_T(&b_st, &cornerAngle, 1, &hj_emlrtRTEI, true);
  for (i = 0; i < 50; i++) {
    /*  Remove cell array so no need for cell2mat */
    /*  which won't compile - AVH */
    /* [newValues{:}] = func(x(i)); */
    /* y(i,:) = cell2mat(newValues); */
    c_st.site = &bd_emlrtRSI;
    sldFunc(&c_st, newDomain[i], sldProfile, cornerAngle);
    if (1 != cornerAngle->size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(1, cornerAngle->size[0], &e_emlrtECI,
        &b_st);
    }

    hiVal[i] = cornerAngle->data[0];
  }

  /* end */
  /* dataPoints = [initialDomain(:), func(initialDomain(:))]; */
  for (b_i = 0; b_i < 50; b_i++) {
    b_newDomain[b_i] = newDomain[b_i];
    b_newDomain[b_i + 50] = hiVal[b_i];
  }

  emxInit_real_T(&st, &dataPoints, 2, &aj_emlrtRTEI, true);
  b_i = dataPoints->size[0] * dataPoints->size[1];
  dataPoints->size[0] = 50;
  dataPoints->size[1] = 2;
  emxEnsureCapacity_real_T(&st, dataPoints, b_i, &aj_emlrtRTEI);
  for (b_i = 0; b_i < 100; b_i++) {
    dataPoints->data[b_i] = b_newDomain[b_i];
  }

  /*  Iterative function refinement */
  /*  if displayWaitbar */
  /*    refinementWaitbar = waitbar(0,['Evaluating function ',func2str(func)],... */
  /*      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)'); */
  /*    setappdata(refinementWaitbar,'canceling',false) */
  /*  end */
  nRefinements = 0;
  emxInit_boolean_T(&st, &sharpCorners, 1, &dj_emlrtRTEI, true);
  emxInit_boolean_T(&st, &segmentsToSplit, 1, &ij_emlrtRTEI, true);
  emxInit_boolean_T(&st, &r, 1, &jj_emlrtRTEI, true);
  emxInit_real_T(&st, &b_dataPoints, 2, &cj_emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (nRefinements < 10)) {
    /*  calculate the box which encloses the current data points: */
    b_st.site = &wc_emlrtRSI;
    c_st.site = &mc_emlrtRSI;
    d_st.site = &nc_emlrtRSI;
    e_st.site = &oc_emlrtRSI;
    if (dataPoints->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(&e_st, &nb_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility",
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (dataPoints->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(&e_st, &mb_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    f_st.site = &jd_emlrtRSI;
    g_st.site = &kd_emlrtRSI;
    h_st.site = &ld_emlrtRSI;
    b_i = dataPoints->size[0];
    overflow = ((2 <= dataPoints->size[0]) && (dataPoints->size[0] > 2147483646));
    startDomain[0] = dataPoints->data[0];
    i_st.site = &md_emlrtRSI;
    if (overflow) {
      j_st.site = &nb_emlrtRSI;
      check_forloop_overflow_error(&j_st);
    }

    for (i = 2; i <= b_i; i++) {
      thisLayRho = dataPoints->data[i - 1];
      if ((!muDoubleScalarIsNaN(thisLayRho)) && (muDoubleScalarIsNaN
           (startDomain[0]) || (startDomain[0] < thisLayRho))) {
        startDomain[0] = thisLayRho;
      }
    }

    startDomain[1] = dataPoints->data[dataPoints->size[0]];
    i_st.site = &md_emlrtRSI;
    for (i = 2; i <= b_i; i++) {
      thisLayRho = dataPoints->data[(i + dataPoints->size[0]) - 1];
      if ((!muDoubleScalarIsNaN(thisLayRho)) && (muDoubleScalarIsNaN
           (startDomain[1]) || (startDomain[1] < thisLayRho))) {
        startDomain[1] = thisLayRho;
      }
    }

    b_st.site = &wc_emlrtRSI;
    c_st.site = &nd_emlrtRSI;
    d_st.site = &od_emlrtRSI;
    e_st.site = &pd_emlrtRSI;
    if (dataPoints->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(&e_st, &nb_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility",
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (dataPoints->size[0] < 1) {
      emlrtErrorWithMessageIdR2018a(&e_st, &mb_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    f_st.site = &jd_emlrtRSI;
    g_st.site = &kd_emlrtRSI;
    h_st.site = &ld_emlrtRSI;
    b_i = dataPoints->size[0];
    overflow = ((2 <= dataPoints->size[0]) && (dataPoints->size[0] > 2147483646));
    minval_idx_0 = dataPoints->data[0];
    i_st.site = &md_emlrtRSI;
    if (overflow) {
      j_st.site = &nb_emlrtRSI;
      check_forloop_overflow_error(&j_st);
    }

    for (i = 2; i <= b_i; i++) {
      thisLayRho = dataPoints->data[i - 1];
      if ((!muDoubleScalarIsNaN(thisLayRho)) && (muDoubleScalarIsNaN
           (minval_idx_0) || (minval_idx_0 > thisLayRho))) {
        minval_idx_0 = thisLayRho;
      }
    }

    minval_idx_1 = dataPoints->data[dataPoints->size[0]];
    i_st.site = &md_emlrtRSI;
    for (i = 2; i <= b_i; i++) {
      thisLayRho = dataPoints->data[(i + dataPoints->size[0]) - 1];
      if ((!muDoubleScalarIsNaN(thisLayRho)) && (muDoubleScalarIsNaN
           (minval_idx_1) || (minval_idx_1 > thisLayRho))) {
        minval_idx_1 = thisLayRho;
      }
    }

    /*  Each point is considered as the central corner of the triangle formed */
    /*  with its left and right hand side neighbours. The first and the last */
    /*  points are not the central corner of any triangle, so for N points */
    /*  there are only N-2 triangles. */
    if (!((real_T)dataPoints->size[0] - 2.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b((real_T)dataPoints->size[0] - 2.0,
        &hb_emlrtDCI, &st);
    }

    i = dataPoints->size[0];
    b_i = b_dataPoints->size[0] * b_dataPoints->size[1];
    b_dataPoints->size[0] = dataPoints->size[0];
    b_dataPoints->size[1] = 2;
    emxEnsureCapacity_real_T(&st, b_dataPoints, b_i, &cj_emlrtRTEI);
    for (b_i = 0; b_i < i; b_i++) {
      b_dataPoints->data[b_i] = dataPoints->data[b_i];
    }

    startDomain[0] -= minval_idx_0;
    for (b_i = 0; b_i < i; b_i++) {
      b_dataPoints->data[b_i + b_dataPoints->size[0]] = dataPoints->data[b_i +
        dataPoints->size[0]];
    }

    startDomain[1] -= minval_idx_1;
    b_st.site = &xc_emlrtRSI;
    calculateCentralAngles(&b_st, b_dataPoints, startDomain, cornerAngle);
    b_i = sharpCorners->size[0];
    sharpCorners->size[0] = cornerAngle->size[0];
    emxEnsureCapacity_boolean_T(&st, sharpCorners, b_i, &dj_emlrtRTEI);
    i = cornerAngle->size[0];
    for (b_i = 0; b_i < i; b_i++) {
      sharpCorners->data[b_i] = (cornerAngle->data[b_i] < 2.1991148575128552);
    }

    b_i = dataPoints->size[0] - 2;
    if (b_i != sharpCorners->size[0]) {
      emlrtSizeEqCheck1DR2012b(b_i, sharpCorners->size[0], &g_emlrtECI, &st);
    }

    b_i = sharpCorners->size[0];
    sharpCorners->size[0] = dataPoints->size[0] - 2;
    emxEnsureCapacity_boolean_T(&st, sharpCorners, b_i, &ej_emlrtRTEI);

    /*  For N points there are N-2 triangles and N-1 triangle sides. Each */
    /*  triangle side is a segment, which can be split or not depending on the */
    /*  refinement parameters. */
    b_i = segmentsToSplit->size[0];
    segmentsToSplit->size[0] = dataPoints->size[0] - 1;
    emxEnsureCapacity_boolean_T(&st, segmentsToSplit, b_i, &fj_emlrtRTEI);
    i = dataPoints->size[0] - 2;
    for (b_i = 0; b_i < i; b_i++) {
      segmentsToSplit->data[b_i] = sharpCorners->data[b_i];
    }

    segmentsToSplit->data[dataPoints->size[0] - 2] = false;
    b_i = r->size[0];
    r->size[0] = dataPoints->size[0] - 1;
    emxEnsureCapacity_boolean_T(&st, r, b_i, &gj_emlrtRTEI);
    r->data[0] = false;
    i = dataPoints->size[0] - 2;
    for (b_i = 0; b_i < i; b_i++) {
      r->data[b_i + 1] = sharpCorners->data[b_i];
    }

    if (segmentsToSplit->size[0] != r->size[0]) {
      emlrtSizeEqCheck1DR2012b(segmentsToSplit->size[0], r->size[0], &f_emlrtECI,
        &st);
    }

    i = segmentsToSplit->size[0];
    for (b_i = 0; b_i < i; b_i++) {
      segmentsToSplit->data[b_i] = (segmentsToSplit->data[b_i] || r->data[b_i]);
    }

    b_st.site = &yc_emlrtRSI;
    if (any(&b_st, segmentsToSplit)) {
      b_st.site = &ad_emlrtRSI;
      increaseSampling(&b_st, dataPoints, segmentsToSplit, sldProfile);

      /*  Removed waitbar for compile - AVH */
      /*    if displayWaitbar */
      /*      if getappdata(refinementWaitbar,'canceling'), break; end */
      /*      waitbar(nRefinements/maxRefinements,refinementWaitbar); */
      /*    end */
      nRefinements++;
    } else {
      exitg1 = true;
    }
  }

  emxFree_real_T(&b_dataPoints);
  emxFree_boolean_T(&r);
  emxFree_boolean_T(&segmentsToSplit);
  emxFree_boolean_T(&sharpCorners);
  emxFree_real_T(&cornerAngle);

  /*  if displayWaitbar */
  /*    delete(refinementWaitbar); */
  /*  end */
  /*  Plotting refined function */
  /*  Removed for compile - AVH */
  /*  if nargin==0 % test mode */
  /*    figure(testFigureHandle); */
  /*    hold on; */
  /*    plot(dataPoints(:,1), dataPoints(:,2),'ro-'); */
  /*    legend('initial', 'refiniment'); */
  /*  end */
  if (dataPoints->size[0] == 0) {
    i = -1;
  } else if (dataPoints->size[0] > 1) {
    i = dataPoints->size[0] - 1;
  } else {
    i = 0;
  }

  if (i < 0) {
    emlrtNonNegativeCheckR2012b(i, &ib_emlrtDCI, sp);
  }

  b_i = newSLD->size[0] * newSLD->size[1];
  newSLD->size[0] = i;
  newSLD->size[1] = 3;
  emxEnsureCapacity_real_T(sp, newSLD, b_i, &bj_emlrtRTEI);
  i *= 3;
  for (b_i = 0; b_i < i; b_i++) {
    newSLD->data[b_i] = 0.0;
  }

  /*  Now build a layer model from these resampled points */
  if (dataPoints->size[0] == 0) {
    i = -2;
  } else if (dataPoints->size[0] > 1) {
    i = dataPoints->size[0] - 2;
  } else {
    i = -1;
  }

  for (n = 0; n <= i; n++) {
    b_i = n + 1;
    if ((b_i < 1) || (b_i > dataPoints->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, dataPoints->size[0], &mg_emlrtBCI,
        sp);
    }

    b_i = (int32_T)(((real_T)n + 1.0) + 1.0);
    if ((b_i < 1) || (b_i > dataPoints->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, dataPoints->size[0], &lg_emlrtBCI,
        sp);
    }

    nRefinements = n + 1;
    if ((nRefinements < 1) || (nRefinements > dataPoints->size[0])) {
      emlrtDynamicBoundsCheckR2012b(nRefinements, 1, dataPoints->size[0],
        &kg_emlrtBCI, sp);
    }

    if (b_i > dataPoints->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, dataPoints->size[0], &jg_emlrtBCI,
        sp);
    }

    thisLayRho = dataPoints->data[(n + dataPoints->size[0]) + 1];
    if (thisLayRho > dataPoints->data[n + dataPoints->size[0]]) {
      thisLayRho = (thisLayRho - dataPoints->data[n + dataPoints->size[0]]) /
        2.0 + dataPoints->data[n + dataPoints->size[0]];
    } else {
      thisLayRho += (dataPoints->data[n + dataPoints->size[0]] - thisLayRho) /
        2.0;
    }

    b_i = n + 1;
    if ((b_i < 1) || (b_i > newSLD->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, newSLD->size[0], &ig_emlrtBCI, sp);
    }

    newSLD->data[n] = dataPoints->data[n + 1] - dataPoints->data[n];
    newSLD->data[n + newSLD->size[0]] = thisLayRho;
    newSLD->data[n + newSLD->size[0] * 2] = 2.2204460492503131E-16;
  }

  emxFree_real_T(&dataPoints);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (resampleLayers.c) */
