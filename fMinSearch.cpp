//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// fMinSearch.cpp
//
// Code generation for function 'fMinSearch'
//

// Include files
#include "fMinSearch.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "abs.h"
#include "blockedSummation.h"
#include "eps.h"
#include "ifWhileCond.h"
#include "isRATStopped.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "simplexIntrafun.h"
#include "sort.h"
#include "sprintf.h"
#include "strcmp.h"
#include "triggerEvent.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cmath>

// Variable Definitions
namespace RAT
{
  static const char cv3[33]{ 'N', 'e', 'l', 'd', 'e', 'r', '-', 'M', 'e', 'a',
    'd', ' ', 's', 'i', 'm', 'p', 'l', 'e', 'x', ' ', 'd', 'i', 'r', 'e', 'c',
    't', ' ', 's', 'e', 'a', 'r', 'c', 'h' };
}

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const ::coder::array<double, 2U> &in3);
  static void c_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, int in3, int in4, int in5);
  static void c_binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const ::coder::array<double, 2U> &in3);
  static double cleanUpInterrupt(double optVal, double iteration, double
    funccount, double display, double &output_iterations, double
    &output_funcCount, char output_algorithm[33], char output_message[31]);
  static void f_binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const ::coder::array<double, 2U> &in3);
  static void g_binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const ::coder::array<double, 2U> &in3);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const ::coder::array<double, 2U> &in3)
  {
    int b_in3;
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    b_in3 = in3.size(1);
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    in1.set_size(loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in3.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = 3.0 * in2[i * stride_0_0] - 2.0 * in3[i * stride_1_0 + in3.size(0)
        * (b_in3 - 1)];
    }
  }

  static void c_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, int in3, int in4, int in5)
  {
    ::coder::array<double, 2U> b_in2;
    int aux_0_1;
    int i;
    int loop_ub;
    int stride_0_1;
    i = (in4 - in3) + 1;
    if (in5 == 1) {
      loop_ub = i;
    } else {
      loop_ub = in5;
    }

    b_in2.set_size(in2.size(0), loop_ub);
    stride_0_1 = (i != 1);
    aux_0_1 = 0;
    for (i = 0; i < loop_ub; i++) {
      int b_loop_ub;
      b_loop_ub = in2.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        b_in2[i1 + b_in2.size(0) * i] = in2[i1 + in2.size(0) * (in3 + aux_0_1)]
          - in2[i1];
      }

      aux_0_1 += stride_0_1;
    }

    coder::c_abs(b_in2, in1);
  }

  static void c_binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const ::coder::array<double, 2U> &in3)
  {
    int b_in3;
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    b_in3 = in3.size(1);
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    in1.set_size(loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in3.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = 1.5 * in2[i * stride_0_0] - 0.5 * in3[i * stride_1_0 + in3.size(0)
        * (b_in3 - 1)];
    }
  }

  static double cleanUpInterrupt(double optVal, double iteration, double
    funccount, double display, double &output_iterations, double
    &output_funcCount, char output_algorithm[33], char output_message[31])
  {
    static const char b_cv[31]{ 'O', 'p', 't', 'i', 'm', 'i', 's', 'a', 't', 'i',
      'o', 'n', ' ', 't', 'e', 'r', 'm', 'i', 'n', 'a', 't', 'e', 'd', ' ', 'b',
      'y', ' ', 'u', 's', 'e', 'r' };

    double fval;

    // --------------------------------------------------------------------------
    //  function [xOutputfcn, optimValues, stop] = callOutputAndPlotFcns(outputfcn,plotfcns,x,xOutputfcn,state,iter,...
    //      numf,how,f,varargin)
    //  CALLOUTPUTANDPLOTFCNS assigns values to the struct OptimValues and then calls the
    //  outputfcn/plotfcns.
    //
    //  state - can have the values 'init','iter', or 'done'.
    //  For the 'done' state we do not check the value of 'stop' because the
    //  optimization is already done.
    //  optimValues.iteration = iter;
    //  optimValues.funccount = numf;
    //  optimValues.fval = f;
    //  optimValues.procedure = how;
    //  xOutputfcn(:) = x;  % Set x to have user expected size
    //  stop = false;
    //  state = char(state);
    //  Call output functions
    //  ---- Remove these from function for compile - AVH
    //  if ~isempty(outputfcn)
    //      switch state
    //          case {'iter','init'}
    //              stop = callAllOptimOutputFcns(outputfcn,xOutputfcn,optimValues,state,varargin{:}) || stop;
    //          case 'done'
    //              callAllOptimOutputFcns(outputfcn,xOutputfcn,optimValues,state,varargin{:});
    //      end
    //  end
    //  % Call plot functions
    //  if ~isempty(plotfcns)
    //      switch state
    //          case {'iter','init'}
    //              stop = callAllOptimPlotFcns(plotfcns,xOutputfcn,optimValues,state,varargin{:}) || stop;
    //          case 'done'
    //              callAllOptimPlotFcns(plotfcns,xOutputfcn,optimValues,state,varargin{:});
    //      end
    //  end
    //  -----------------------------------
    // --------------------------------------------------------------------------
    fval = optVal;
    output_iterations = iteration;
    output_funcCount = funccount;
    for (int i{0}; i < 33; i++) {
      output_algorithm[i] = cv3[i];
    }

    for (int i{0}; i < 31; i++) {
      output_message[i] = b_cv[i];
    }

    if (display > 0.0) {
      c_triggerEvent();
    }

    return fval;
  }

  static void f_binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const ::coder::array<double, 2U> &in3)
  {
    int b_in3;
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    b_in3 = in3.size(1);
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    in1.set_size(loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in3.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = 0.5 * in2[i * stride_0_0] + 0.5 * in3[i * stride_1_0 + in3.size(0)
        * (b_in3 - 1)];
    }
  }

  static void g_binary_expand_op(::coder::array<double, 1U> &in1, const ::coder::
    array<double, 1U> &in2, const ::coder::array<double, 2U> &in3)
  {
    int b_in3;
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    b_in3 = in3.size(1);
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    in1.set_size(loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in3.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = 2.0 * in2[i * stride_0_0] - in3[i * stride_1_0 + in3.size(0) *
        (b_in3 - 1)];
    }
  }

  double fMinSearch(::coder::array<double, 1U> &x, double options_MaxIter,
                    double options_MaxFunEvals, double options_TolX, double
                    options_TolFun, const char dis_data[], const int dis_size[2],
                    const ProblemDefinition &varargin_1, const char
                    varargin_2_parallel_data[], const int
                    varargin_2_parallel_size[2], boolean_T
                    varargin_2_calcSldDuringFit, double
                    varargin_2_resampleMinAngle, double
                    varargin_2_resampleNPoints, double varargin_2_updateFreq,
                    double varargin_2_updatePlotFreq, const char
                    varargin_2_IPCFilePath_data[], const int
                    varargin_2_IPCFilePath_size[2], const i_struct_T &varargin_3,
                    g_struct_T &output, double &exitflag)
  {
    static const char cv6[35]{ 'E', 'x', 'i', 't', 'i', 'n', 'g', ':', ' ', 'M',
      'a', 'x', ' ', 'f', 'u', 'n', 'c', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'a',
      'l', 's', ' ', 'r', 'e', 'a', 'c', 'h', 'e', 'd' };

    static const char cv7[31]{ 'E', 'x', 'i', 't', 'i', 'n', 'g', ':', ' ', 'M',
      'a', 'x', ' ', 'i', 't', 'e', 'r', 'a', 't', 'i', 'o', 'n', 's', ' ', 'r',
      'e', 'a', 'c', 'h', 'e', 'd' };

    static const char cv12[16]{ 'c', 'o', 'n', 't', 'r', 'a', 'c', 't', ' ', 'o',
      'u', 't', 's', 'i', 'd', 'e' };

    static const char cv11[15]{ 'c', 'o', 'n', 't', 'r', 'a', 'c', 't', ' ', 'i',
      'n', 's', 'i', 'd', 'e' };

    static const char cv5[15]{ 'i', 'n', 'i', 't', 'i', 'a', 'l', ' ', 's', 'i',
      'm', 'p', 'l', 'e', 'x' };

    static const char cv8[7]{ 'r', 'e', 'f', 'l', 'e', 'c', 't' };

    static const char b_cv[6]{ 'n', 'o', 't', 'i', 'f', 'y' };

    static const char cv10[6]{ 's', 'h', 'r', 'i', 'n', 'k' };

    static const char cv9[6]{ 'e', 'x', 'p', 'a', 'n', 'd' };

    static const char cv4[5]{ 'f', 'i', 'n', 'a', 'l' };

    static const char b_cv1[4]{ 'n', 'o', 'n', 'e' };

    static const char b_cv3[4]{ 'i', 't', 'e', 'r' };

    static const char b_cv2[3]{ 'o', 'f', 'f' };

    ::coder::array<double, 2U> b_v;
    ::coder::array<double, 2U> c_fv;
    ::coder::array<double, 2U> fv;
    ::coder::array<double, 2U> r1;
    ::coder::array<double, 2U> r2;
    ::coder::array<double, 2U> v;
    ::coder::array<double, 1U> c_v;
    ::coder::array<double, 1U> xbar;
    ::coder::array<double, 1U> xc;
    ::coder::array<double, 1U> xcc;
    ::coder::array<double, 1U> xe;
    ::coder::array<double, 1U> xr;
    ::coder::array<double, 1U> y;
    ::coder::array<int, 2U> iidx;
    ::coder::array<char, 2U> r;
    ::coder::array<boolean_T, 1U> b_tmp_data;
    ::coder::array<boolean_T, 1U> c_tmp_data;
    ProblemDefinition b_varargin_1;
    Results result;
    double b_fv;
    double func_evals;
    double fval;
    double itercount;
    double output_funcCount;
    int how_size[2];
    int b_index;
    int i;
    int i1;
    int n;
    int prnt;
    int x_idx_1_tmp;
    char how_data[16];
    boolean_T tmp_data;

    // FMINSEARCH Multidimensional unconstrained nonlinear minimization (Nelder-Mead).
    //    X = FMINSEARCH(FUN,X0) starts at X0 and attempts to find a local minimizer
    //    X of the function FUN.  FUN is a function handle.  FUN accepts input X and
    //    returns a scalar function value F evaluated at X. X0 can be a scalar, vector
    //    or matrix.
    //
    //    X = FMINSEARCH(FUN,X0,OPTIONS)  minimizes with the default optimization
    //    parameters replaced by values in the structure OPTIONS, created
    //    with the OPTIMSET function.  See OPTIMSET for details.  FMINSEARCH uses
    //    these options: Display, TolX, TolFun, MaxFunEvals, MaxIter, FunValCheck,
    //    PlotFcns, and OutputFcn.
    //
    //    X = FMINSEARCH(PROBLEM) finds the minimum for PROBLEM. PROBLEM is a
    //    structure with the function FUN in PROBLEM.objective, the start point
    //    in PROBLEM.x0, the options structure in PROBLEM.options, and solver
    //    name 'fminsearch' in PROBLEM.solver.
    //
    //    [X,FVAL]= FMINSEARCH(...) returns the value of the objective function,
    //    described in FUN, at X.
    //
    //    [X,FVAL,EXITFLAG] = FMINSEARCH(...) returns an EXITFLAG that describes
    //    the exit condition. Possible values of EXITFLAG and the corresponding
    //    exit conditions are
    //
    //     1  Maximum coordinate difference between current best point and other
    //        points in simplex is less than or equal to TolX, and corresponding
    //        difference in function values is less than or equal to TolFun.
    //     0  Maximum number of function evaluations or iterations reached.
    //    -1  Algorithm terminated by the output function.
    //
    //    [X,FVAL,EXITFLAG,OUTPUT] = FMINSEARCH(...) returns a structure
    //    OUTPUT with the number of iterations taken in OUTPUT.iterations, the
    //    number of function evaluations in OUTPUT.funcCount, the algorithm name
    //    in OUTPUT.algorithm, and the exit message in OUTPUT.message.
    //
    //    Examples
    //      FUN can be specified using @:
    //         X = fminsearch(@sin,3)
    //      finds a minimum of the SIN function near 3.
    //      In this case, SIN is a function that returns a scalar function value
    //      SIN evaluated at X.
    //
    //      FUN can be an anonymous function:
    //         X = fminsearch(@(x) norm(x),[1;2;3])
    //      returns a point near the minimizer [0;0;0].
    //
    //      FUN can be a parameterized function. Use an anonymous function to
    //      capture the problem-dependent parameters:
    //         f = @(x,c) x(1).^2+c.*x(2).^2;  % The parameterized function.
    //         c = 1.5;                        % The parameter.
    //         X = fminsearch(@(x) f(x,c),[0.3;1])
    //
    //    FMINSEARCH uses the Nelder-Mead simplex (direct search) method.
    //
    //    See also OPTIMSET, FMINBND, FUNCTION_HANDLE.
    //    Reference: Jeffrey C. Lagarias, James A. Reeds, Margaret H. Wright,
    //    Paul E. Wright, "Convergence Properties of the Nelder-Mead Simplex
    //    Method in Low Dimensions", SIAM Journal of Optimization, 9(1):
    //    p.112-147, 1998.
    //    Copyright 1984-2018 The MathWorks, Inc.
    //  If just 'defaults' passed in, return the default options in X
    //  -------- Inputs are standardised for RAT, so no need to check ---------
    //  Detect problem structure input
    //  if nargin == 1
    //      if isa(funfcn,'struct')
    //          [funfcn,x,options] = separateOptimStruct(funfcn);
    //      else % Single input and non-structure
    //          error('MATLAB:fminsearch:InputArg',...
    //              sprintf('MATLAB:optimfun:fminsearch:InputArg'));
    //      end
    //  end
    //
    //  if nargin == 0
    //      error('MATLAB:fminsearch:NotEnoughInputs',...
    //          sprintf('MATLAB:optimfun:fminsearch:NotEnoughInputs'));
    //  end
    //
    //  % Check for non-double inputs
    //  if ~isa(x,'double')
    //    error('MATLAB:fminsearch:NonDoubleInput',...
    //      sprintf('MATLAB:optimfun:fminsearch:NonDoubleInput'));
    //  end
    //  -------------------------------------------------------------------
    //  n = numel(x);
    //  numberOfVariables = n;
    //  ------------- Check is done upstream ----------------
    //  Check that options is a struct
    //  if ~isempty(options) && ~isa(options,'struct')
    //      error('MATLAB:fminsearch:ArgNotStruct',...
    //          getString(message('MATLAB:optimfun:commonMessages:ArgNotStruct', 3)));
    //  end
    //  ------------------- AVH -----------------------------
    //  printtype = optimget(options,'Display',defaultopt,'fast');
    //  In case the defaults were gathered from calling: optimset('fminsearch'):
    //  if ischar(maxfun) || isstring(maxfun)
    //      if strcmpi(maxfun,'200*numberofvariables')
    //          maxfun = 200*numberOfVariables;
    //      else
    //          error('MATLAB:fminsearch:OptMaxFunEvalsNotInteger',...
    //              getString(message('MATLAB:optimfun:fminsearch:OptMaxFunEvalsNotInteger')));
    //      end
    //  end
    //  if ischar(maxiter) || isstring(maxiter)
    //      if strcmpi(maxiter,'200*numberofvariables')
    //          maxiter = 200*numberOfVariables;
    //      else
    //          error('MATLAB:fminsearch:OptMaxIterNotInteger',...
    //              getString(message('MATLAB:optimfun:fminsearch:OptMaxIterNotInteger')));
    //      end
    //  end
    if (coder::internal::b_strcmp(dis_data, dis_size, b_cv)) {
      b_index = 0;
    } else if (coder::internal::c_strcmp(dis_data, dis_size, b_cv1)) {
      b_index = 1;
    } else if (coder::internal::d_strcmp(dis_data, dis_size, b_cv2)) {
      b_index = 1;
    } else if (coder::internal::c_strcmp(dis_data, dis_size, b_cv3)) {
      b_index = 2;
    } else if (coder::internal::e_strcmp(dis_data, dis_size, cv4)) {
      b_index = 3;
    } else {
      b_index = -1;
    }

    switch (b_index) {
     case 0:
      //  Changed from TMW fminsearch
      prnt = 1;
      break;

     case 1:
      prnt = 0;
      break;

     case 2:
      prnt = 3;
      break;

     case 3:
      prnt = 2;

      //      case 'simplex'
      //          prnt = 4;
      break;

     default:
      prnt = 1;
      break;
    }

    //  ----------------- Not using output functions for RAT ---------
    //  % Handle the output
    //  outputfcn = optimget(options,'OutputFcn',defaultopt,'fast');
    //  if isempty(outputfcn)
    //      haveoutputfcn = false;
    //  else
    //      haveoutputfcn = true;
    //      xOutputfcn = x; % Last x passed to outputfcn; has the input x's shape
    //      % Parse OutputFcn which is needed to support cell array syntax for OutputFcn.
    //      outputfcn = createCellArrayOfFunctions(outputfcn,'OutputFcn');
    //  end
    //
    //  % Handle the plot
    //  plotfcns = optimget(options,'PlotFcns',defaultopt,'fast');
    //  if isempty(plotfcns)
    //      haveplotfcn = false;
    //  else
    //      haveplotfcn = true;
    //      xOutputfcn = x; % Last x passed to plotfcns; has the input x's shape
    //      % Parse PlotFcns which is needed to support cell array syntax for PlotFcns.
    //      plotfcns = createCellArrayOfFunctions(plotfcns,'PlotFcns');
    //  end
    //  ---------------------- AVH ------------------------------
    //  Convert to function handle as needed.
    //  funfcn = fcnchk(funfcn,length(varargin));
    //  Add a wrapper function to check for Inf/NaN/complex values
    //
    n = x.size(0);

    //  Initialize parameters
    //  two2np1 = 2:n+1;
    //  one2n = 1:n;
    //  Set up a simplex near the initial guess.
    //  Force xin to be a column vector
    b_index = x.size(0);
    x_idx_1_tmp = x.size(0) + 1;
    v.set_size(b_index, x_idx_1_tmp);
    fv.set_size(1, x_idx_1_tmp);
    for (i = 0; i < x_idx_1_tmp; i++) {
      for (i1 = 0; i1 < b_index; i1++) {
        v[i1 + v.size(0) * i] = 0.0;
      }

      fv[i] = 0.0;
    }

    x_idx_1_tmp = x.size(0);
    for (i = 0; i < x_idx_1_tmp; i++) {
      v[i] = x[i];
    }

    //  Place input guess in the simplex! (credit L.Pfeffer at Stanford)
    //  Change x to the form expected by funfcn
    b_varargin_1 = varargin_1;
    fv[0] = simplexIntrafun(x, b_varargin_1, varargin_2_parallel_data,
      varargin_2_parallel_size, varargin_2_calcSldDuringFit,
      varargin_2_resampleMinAngle, varargin_2_resampleNPoints, varargin_3.LB,
      varargin_3.UB, varargin_3.BoundClass, result);

    //  Initial simplex setup continues later
    //  Initialize the output and plot functions.
    //
    //  ----------------------------------------
    //  RAT doesn't use output or plot functions...
    //
    //  --------------------- AVH -----------
    //  if haveoutputfcn || haveplotfcn
    //      [xOutputfcn, optimValues, stop] = callOutputAndPlotFcns(outputfcn,plotfcns,v(:,1),xOutputfcn,'init',itercount, ...
    //          func_evals, how, fv(:,1),varargin{:});
    //      if stop
    //          [x,fval,exitflag,output] = cleanUpInterrupt(xOutputfcn,optimValues);
    //          if  prnt > 0
    //              fprintf('%s \n', output.message)
    //          end
    //          return;
    //      end
    //  end
    //  Print out initial f(x) as 0th iteration
    if (prnt == 3) {
      b_triggerEvent();
      coder::b_sprintf(fv[0], r);
      triggerEvent(r);

      //  elseif prnt == 4
      //  Option never used in RAT
      //      formatsave.format = get(0,'format');
      //      formatsave.formatspacing = get(0,'formatspacing');
      //      % reset format when done
      //      oc1 = onCleanup(@()set(0,'format',formatsave.format));
      //      oc2 = onCleanup(@()set(0,'formatspacing',formatsave.formatspacing));
      //      format compact
      //      format short e
      //      fprintf('%s \n', ' ')
      //      fprintf('%s \n', how)
      //      fprintf('%s \n', 'v = ')
      //      fprintf('%g \n', v)
      //      fprintf('%s \n', 'fv = ')
      //      fprintf('%g \n', fv)
      //      fprintf('%s \n', 'func_evals = ')
      //      fprintf('%g \n', func_evals)
    }

    triggerEvent(result, varargin_1.TF.data, varargin_1.TF.size,
                 varargin_1.resample, varargin_1.dataPresent,
                 varargin_1.modelType.data, varargin_1.modelType.size,
                 varargin_1.names.contrasts);

    //  OutputFcn and PlotFcns call
    //  if haveoutputfcn || haveplotfcn
    //      [xOutputfcn, optimValues, stop] = callOutputAndPlotFcns(outputfcn,plotfcns,v(:,1),xOutputfcn,'iter',itercount, ...
    //          func_evals, how, fv(:,1),varargin{:});
    //      if stop  % Stop per user request.
    //          [x,fval,exitflag,output] = cleanUpInterrupt(xOutputfcn,optimValues);
    //          if  prnt > 0
    //              fprintf('%s \n', output.message)
    //          end
    //          return;
    //      end
    //  end
    //  Continue setting up the initial simplex.
    //  Following improvement suggested by L.Pfeffer at Stanford
    //  5 percent deltas for non-zero terms
    //  Even smaller delta for zero elements of x
    i = x.size(0);
    for (int j{0}; j < i; j++) {
      x_idx_1_tmp = x.size(0);
      y.set_size(x_idx_1_tmp);
      for (i1 = 0; i1 < x_idx_1_tmp; i1++) {
        y[i1] = x[i1];
      }

      if (x[j] != 0.0) {
        y[j] = 1.05 * x[j];
      } else {
        y[j] = 0.00025;
      }

      x_idx_1_tmp = v.size(0);
      for (i1 = 0; i1 < x_idx_1_tmp; i1++) {
        v[i1 + v.size(0) * (j + 1)] = y[i1];
      }

      b_varargin_1 = varargin_1;
      fv[j + 1] = simplexIntrafun(y, b_varargin_1, varargin_2_parallel_data,
        varargin_2_parallel_size, varargin_2_calcSldDuringFit,
        varargin_2_resampleMinAngle, varargin_2_resampleNPoints, varargin_3.LB,
        varargin_3.UB, varargin_3.BoundClass, result);
    }

    //  sort so v(1,:) has the lowest function value
    coder::internal::sort(fv, iidx);
    b_index = v.size(0);
    b_v.set_size(v.size(0), iidx.size(1));
    x_idx_1_tmp = iidx.size(1);
    for (i = 0; i < x_idx_1_tmp; i++) {
      for (i1 = 0; i1 < b_index; i1++) {
        b_v[i1 + b_v.size(0) * i] = v[i1 + v.size(0) * (iidx[i] - 1)];
      }
    }

    v.set_size(b_v.size(0), b_v.size(1));
    x_idx_1_tmp = b_v.size(1);
    for (i = 0; i < x_idx_1_tmp; i++) {
      b_index = b_v.size(0);
      for (i1 = 0; i1 < b_index; i1++) {
        v[i1 + v.size(0) * i] = b_v[i1 + b_v.size(0) * i];
      }
    }

    how_size[0] = 1;
    how_size[1] = 15;
    for (i = 0; i < 15; i++) {
      how_data[i] = cv5[i];
    }

    itercount = 1.0;
    func_evals = static_cast<double>(x.size(0)) + 1.0;
    if ((prnt == 3) && (rt_remd_snf(1.0, varargin_2_updateFreq) == 0.0)) {
      coder::b_sprintf(static_cast<double>(x.size(0)) + 1.0, fv[0], how_data, r);
      triggerEvent(r);

      //  elseif prnt == 4
      //      fprintf('%s \n', ' ')
      //      fprintf('%s \n', how)
      //      fprintf('%s \n', 'v = ')
      //      fprintf('%g \n', v)
      //      fprintf('%s \n', 'fv = ')
      //      fprintf('%g \n', fv)
      //      fprintf('%s \n', 'func_evals = ')
      //      fprintf('%g \n', func_evals)
    }

    if (rt_remd_snf(1.0, varargin_2_updatePlotFreq) == 0.0) {
      triggerEvent(result, varargin_1.TF.data, varargin_1.TF.size,
                   varargin_1.resample, varargin_1.dataPresent,
                   varargin_1.modelType.data, varargin_1.modelType.size,
                   varargin_1.names.contrasts);
    }

    b_index = isRATStopped(varargin_2_IPCFilePath_data,
      varargin_2_IPCFilePath_size, (boolean_T *)&tmp_data);
    b_tmp_data.set(&tmp_data, b_index);
    if (coder::internal::ifWhileCond(b_tmp_data)) {
      char output_message[31];
      x.set_size(v.size(0));
      x_idx_1_tmp = v.size(0);
      for (i = 0; i < x_idx_1_tmp; i++) {
        x[i] = v[i];
      }

      fval = cleanUpInterrupt(fv[0], 1.0, static_cast<double>(n) + 1.0,
        static_cast<double>(prnt), b_fv, output_funcCount, output.algorithm,
        output_message);
      b_index = -1;
      output.iterations = b_fv;
      output.funcCount = output_funcCount;
      output.message.set_size(1, 31);
      for (i = 0; i < 31; i++) {
        output.message[i] = output_message[i];
      }
    } else {
      boolean_T guard1;

      //  OutputFcn and PlotFcns call
      //  if haveoutputfcn || haveplotfcn
      //      [xOutputfcn, optimValues, stop] = callOutputAndPlotFcns(outputfcn,plotfcns,v(:,1),xOutputfcn,'iter',itercount, ...
      //          func_evals, how, fv(:,1),varargin{:});
      //      if stop  % Stop per user request.
      //          [x,fval,exitflag,output] = cleanUpInterrupt(xOutputfcn,optimValues);
      //          if  prnt > 0
      //              fprintf('%s \n', output.message)
      //          end
      //          return;
      //      end
      //  end
      //  exitflag = 1;
      //  Main algorithm: iterate until
      //  (a) the maximum coordinate difference between the current best point and the
      //  other points in the simplex is less than or equal to TolX. Specifically,
      //  until max(||v2-v1||,||v3-v1||,...,||v(n+1)-v1||) <= TolX,
      //  where ||.|| is the infinity-norm, and v1 holds the
      //  vertex with the current lowest value; AND
      //  (b) the corresponding difference in function values is less than or equal
      //  to TolFun. (Cannot use OR instead of AND.)
      //  The iteration stops if the maximum number of iterations or function evaluations
      //  are exceeded
      guard1 = false;
      int exitg1;
      do {
        exitg1 = 0;
        if ((func_evals < options_MaxFunEvals) && (itercount < options_MaxIter))
        {
          boolean_T b_guard1;
          if (static_cast<unsigned int>(n) + 1U < 2U) {
            i = 0;
            i1 = -1;
          } else {
            i = 1;
            i1 = n;
          }

          b_fv = fv[0];
          x_idx_1_tmp = i1 - i;
          c_fv.set_size(1, x_idx_1_tmp + 1);
          for (i1 = 0; i1 <= x_idx_1_tmp; i1++) {
            c_fv[i1] = b_fv - fv[i + i1];
          }

          coder::b_abs(c_fv, r1);
          b_guard1 = false;
          if (coder::internal::maximum(r1) <= std::fmax(options_TolFun, 10.0 *
               coder::eps(fv[0]))) {
            if (static_cast<unsigned int>(n) + 1U < 2U) {
              i = 0;
              i1 = -1;
            } else {
              i = 1;
              i1 = n;
            }

            x_idx_1_tmp = i1 - i;
            if (x_idx_1_tmp + 1 == n) {
              b_v.set_size(v.size(0), x_idx_1_tmp + 1);
              for (i1 = 0; i1 <= x_idx_1_tmp; i1++) {
                b_index = v.size(0);
                for (int i2{0}; i2 < b_index; i2++) {
                  b_v[i2 + b_v.size(0) * i1] = v[i2 + v.size(0) * (i + i1)] -
                    v[i2];
                }
              }

              coder::c_abs(b_v, r2);
            } else {
              c_binary_expand_op(r2, v, i, i1, n);
            }

            c_v.set_size(v.size(0));
            x_idx_1_tmp = v.size(0);
            for (i = 0; i < x_idx_1_tmp; i++) {
              c_v[i] = v[i];
            }

            coder::internal::maximum(r2, r1);
            if (coder::internal::maximum(r1) <= std::fmax(options_TolX, 10.0 *
                 coder::eps(coder::internal::maximum(c_v)))) {
              guard1 = true;
              exitg1 = 1;
            } else {
              b_guard1 = true;
            }
          } else {
            b_guard1 = true;
          }

          if (b_guard1) {
            double fxr;

            //  Compute the reflection point
            //  xbar = average of the n (NOT n+1) best points
            if (n < 1) {
              x_idx_1_tmp = 0;
            } else {
              x_idx_1_tmp = n;
            }

            b_v.set_size(v.size(0), x_idx_1_tmp);
            for (i = 0; i < x_idx_1_tmp; i++) {
              b_index = v.size(0);
              for (i1 = 0; i1 < b_index; i1++) {
                b_v[i1 + b_v.size(0) * i] = v[i1 + v.size(0) * i];
              }
            }

            coder::blockedSummation(b_v, x_idx_1_tmp, c_v);
            xbar.set_size(c_v.size(0));
            x_idx_1_tmp = c_v.size(0);
            for (i = 0; i < x_idx_1_tmp; i++) {
              xbar[i] = c_v[i] / static_cast<double>(n);
            }

            if (xbar.size(0) == v.size(0)) {
              xr.set_size(xbar.size(0));
              x_idx_1_tmp = xbar.size(0);
              for (i = 0; i < x_idx_1_tmp; i++) {
                xr[i] = 2.0 * xbar[i] - v[i + v.size(0) * (v.size(1) - 1)];
              }
            } else {
              g_binary_expand_op(xr, xbar, v);
            }

            b_varargin_1 = varargin_1;
            fxr = simplexIntrafun(xr, b_varargin_1, varargin_2_parallel_data,
                                  varargin_2_parallel_size,
                                  varargin_2_calcSldDuringFit,
                                  varargin_2_resampleMinAngle,
                                  varargin_2_resampleNPoints, varargin_3.LB,
                                  varargin_3.UB, varargin_3.BoundClass, result);
            func_evals++;
            if (fxr < fv[0]) {
              double fxe;

              //  Calculate the expansion point
              if (xbar.size(0) == v.size(0)) {
                xe.set_size(xbar.size(0));
                x_idx_1_tmp = xbar.size(0);
                for (i = 0; i < x_idx_1_tmp; i++) {
                  xe[i] = 3.0 * xbar[i] - 2.0 * v[i + v.size(0) * (v.size(1) - 1)];
                }
              } else {
                binary_expand_op(xe, xbar, v);
              }

              b_varargin_1 = varargin_1;
              fxe = simplexIntrafun(xe, b_varargin_1, varargin_2_parallel_data,
                                    varargin_2_parallel_size,
                                    varargin_2_calcSldDuringFit,
                                    varargin_2_resampleMinAngle,
                                    varargin_2_resampleNPoints, varargin_3.LB,
                                    varargin_3.UB, varargin_3.BoundClass, result);
              func_evals++;
              if (fxe < fxr) {
                x_idx_1_tmp = v.size(0);
                for (i = 0; i < x_idx_1_tmp; i++) {
                  v[i + v.size(0) * (v.size(1) - 1)] = xe[i];
                }

                fv[fv.size(1) - 1] = fxe;
                how_size[0] = 1;
                how_size[1] = 6;
                for (i = 0; i < 6; i++) {
                  how_data[i] = cv9[i];
                }
              } else {
                x_idx_1_tmp = v.size(0);
                for (i = 0; i < x_idx_1_tmp; i++) {
                  v[i + v.size(0) * (v.size(1) - 1)] = xr[i];
                }

                fv[fv.size(1) - 1] = fxr;
                how_size[0] = 1;
                how_size[1] = 7;
                for (i = 0; i < 7; i++) {
                  how_data[i] = cv8[i];
                }
              }

              //  fv(:,1) <= fxr
            } else if (fxr < fv[n - 1]) {
              x_idx_1_tmp = v.size(0);
              for (i = 0; i < x_idx_1_tmp; i++) {
                v[i + v.size(0) * (v.size(1) - 1)] = xr[i];
              }

              fv[fv.size(1) - 1] = fxr;
              how_size[0] = 1;
              how_size[1] = 7;
              for (i = 0; i < 7; i++) {
                how_data[i] = cv8[i];
              }
            } else {
              //  fxr >= fv(:,n)
              //  Perform contraction
              b_fv = fv[fv.size(1) - 1];
              if (fxr < b_fv) {
                double fxc;

                //  Perform an outside contraction
                if (xbar.size(0) == v.size(0)) {
                  xc.set_size(xbar.size(0));
                  x_idx_1_tmp = xbar.size(0);
                  for (i = 0; i < x_idx_1_tmp; i++) {
                    xc[i] = 1.5 * xbar[i] - 0.5 * v[i + v.size(0) * (v.size(1) -
                      1)];
                  }
                } else {
                  c_binary_expand_op(xc, xbar, v);
                }

                b_varargin_1 = varargin_1;
                fxc = simplexIntrafun(xc, b_varargin_1, varargin_2_parallel_data,
                                      varargin_2_parallel_size,
                                      varargin_2_calcSldDuringFit,
                                      varargin_2_resampleMinAngle,
                                      varargin_2_resampleNPoints, varargin_3.LB,
                                      varargin_3.UB, varargin_3.BoundClass,
                                      result);
                func_evals++;
                if (fxc <= fxr) {
                  x_idx_1_tmp = v.size(0);
                  for (i = 0; i < x_idx_1_tmp; i++) {
                    v[i + v.size(0) * (v.size(1) - 1)] = xc[i];
                  }

                  fv[fv.size(1) - 1] = fxc;
                  how_size[0] = 1;
                  how_size[1] = 16;
                  for (i = 0; i < 16; i++) {
                    how_data[i] = cv12[i];
                  }
                } else {
                  //  perform a shrink
                  how_size[0] = 1;
                  how_size[1] = 6;
                  for (i = 0; i < 6; i++) {
                    how_data[i] = cv10[i];
                  }
                }
              } else {
                double fxcc;

                //  Perform an inside contraction
                if (xbar.size(0) == v.size(0)) {
                  xcc.set_size(xbar.size(0));
                  x_idx_1_tmp = xbar.size(0);
                  for (i = 0; i < x_idx_1_tmp; i++) {
                    xcc[i] = 0.5 * xbar[i] + 0.5 * v[i + v.size(0) * (v.size(1)
                      - 1)];
                  }
                } else {
                  f_binary_expand_op(xcc, xbar, v);
                }

                b_varargin_1 = varargin_1;
                fxcc = simplexIntrafun(xcc, b_varargin_1,
                  varargin_2_parallel_data, varargin_2_parallel_size,
                  varargin_2_calcSldDuringFit, varargin_2_resampleMinAngle,
                  varargin_2_resampleNPoints, varargin_3.LB, varargin_3.UB,
                  varargin_3.BoundClass, result);
                func_evals++;
                if (fxcc < b_fv) {
                  x_idx_1_tmp = v.size(0);
                  for (i = 0; i < x_idx_1_tmp; i++) {
                    v[i + v.size(0) * (v.size(1) - 1)] = xcc[i];
                  }

                  fv[fv.size(1) - 1] = fxcc;
                  how_size[0] = 1;
                  how_size[1] = 15;
                  for (i = 0; i < 15; i++) {
                    how_data[i] = cv11[i];
                  }
                } else {
                  //  perform a shrink
                  how_size[0] = 1;
                  how_size[1] = 6;
                  for (i = 0; i < 6; i++) {
                    how_data[i] = cv10[i];
                  }
                }
              }

              if (coder::internal::bb_strcmp(how_data, how_size)) {
                for (int j{0}; j < n; j++) {
                  c_v.set_size(v.size(0));
                  x_idx_1_tmp = v.size(0);
                  for (i = 0; i < x_idx_1_tmp; i++) {
                    b_fv = v[i];
                    c_v[i] = b_fv + 0.5 * (v[i + v.size(0) * (j + 1)] - b_fv);
                  }

                  x_idx_1_tmp = c_v.size(0);
                  for (i = 0; i < x_idx_1_tmp; i++) {
                    v[i + v.size(0) * (j + 1)] = c_v[i];
                  }

                  x_idx_1_tmp = v.size(0);
                  c_v.set_size(v.size(0));
                  for (i = 0; i < x_idx_1_tmp; i++) {
                    c_v[i] = v[i + v.size(0) * (j + 1)];
                  }

                  b_varargin_1 = varargin_1;
                  fv[j + 1] = simplexIntrafun(c_v, b_varargin_1,
                    varargin_2_parallel_data, varargin_2_parallel_size,
                    varargin_2_calcSldDuringFit, varargin_2_resampleMinAngle,
                    varargin_2_resampleNPoints, varargin_3.LB, varargin_3.UB,
                    varargin_3.BoundClass, result);
                }

                func_evals += static_cast<double>(n);
              }
            }

            coder::internal::sort(fv, iidx);
            b_index = v.size(0);
            b_v.set_size(v.size(0), iidx.size(1));
            x_idx_1_tmp = iidx.size(1);
            for (i = 0; i < x_idx_1_tmp; i++) {
              for (i1 = 0; i1 < b_index; i1++) {
                b_v[i1 + b_v.size(0) * i] = v[i1 + v.size(0) * (iidx[i] - 1)];
              }
            }

            v.set_size(b_v.size(0), b_v.size(1));
            x_idx_1_tmp = b_v.size(1);
            for (i = 0; i < x_idx_1_tmp; i++) {
              b_index = b_v.size(0);
              for (i1 = 0; i1 < b_index; i1++) {
                v[i1 + v.size(0) * i] = b_v[i1 + b_v.size(0) * i];
              }
            }

            itercount++;
            if ((prnt == 3) && (rt_remd_snf(itercount, varargin_2_updateFreq) ==
                                0.0)) {
              coder::b_sprintf(itercount, func_evals, fv[0], how_data, how_size,
                               r);
              triggerEvent(r);

              //      elseif prnt == 4
              //          fprintf('%s \n', ' ')
              //          fprintf('%s \n', num2str(how))
              //          fprintf('%s \n', 'v = ')
              //          fprintf('%s \n', v)
              //          fprintf('%s \n', 'fv = ')
              //          fprintf('%s \n', fv)
              //          fprintf('%s \n', 'func_evals = ')
              //          fprintf('%s \n', num2str(func_evals))
            }

            if (rt_remd_snf(itercount, varargin_2_updatePlotFreq) == 0.0) {
              triggerEvent(result, varargin_1.TF.data, varargin_1.TF.size,
                           varargin_1.resample, varargin_1.dataPresent,
                           varargin_1.modelType.data, varargin_1.modelType.size,
                           varargin_1.names.contrasts);
            }

            b_index = isRATStopped(varargin_2_IPCFilePath_data,
              varargin_2_IPCFilePath_size, (boolean_T *)&tmp_data);
            c_tmp_data.set(&tmp_data, b_index);
            if (coder::internal::ifWhileCond(c_tmp_data)) {
              char output_message[31];
              x.set_size(v.size(0));
              x_idx_1_tmp = v.size(0);
              for (i = 0; i < x_idx_1_tmp; i++) {
                x[i] = v[i];
              }

              fval = cleanUpInterrupt(fv[0], itercount, func_evals, static_cast<
                double>(prnt), b_fv, output_funcCount, output.algorithm,
                output_message);
              b_index = -1;
              output.iterations = b_fv;
              output.funcCount = output_funcCount;
              output.message.set_size(1, 31);
              for (i = 0; i < 31; i++) {
                output.message[i] = output_message[i];
              }

              exitg1 = 1;
            } else {
              //  OutputFcn and PlotFcns call
              //      if haveoutputfcn || haveplotfcn
              //          [xOutputfcn, optimValues, stop] = callOutputAndPlotFcns(outputfcn,plotfcns,v(:,1),xOutputfcn,'iter',itercount, ...
              //              func_evals, how, fv(:,1),varargin{:});
              //          if stop  % Stop per user request.
              //              [x,fval,exitflag,output] = cleanUpInterrupt(xOutputfcn,optimValues);
              //              if  prnt > 0
              //                  fprintf('%s \n', output.message)
              //              end
              //              return;
              //          end
              //      end
              guard1 = false;
            }
          }
        } else {
          guard1 = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);

      if (guard1) {
        boolean_T printMsg;

        //  while
        x.set_size(v.size(0));
        x_idx_1_tmp = v.size(0);
        for (i = 0; i < x_idx_1_tmp; i++) {
          x[i] = v[i];
        }

        fval = fv[0];
        if ((prnt == 3) && (rt_remd_snf(itercount, varargin_2_updateFreq) != 0.0))
        {
          //  This should ensure the final result is printed at the end of a run irrespective of update frequency
          coder::b_sprintf(itercount, func_evals, fv[0], how_data, how_size, r);
          triggerEvent(r);
        }

        if (rt_remd_snf(itercount, varargin_2_updatePlotFreq) != 0.0) {
          //  This should ensure the final result is always plotted irrespective of update frequency
          triggerEvent(result, varargin_1.TF.data, varargin_1.TF.size,
                       varargin_1.resample, varargin_1.dataPresent,
                       varargin_1.modelType.data, varargin_1.modelType.size,
                       varargin_1.names.contrasts);
        }

        //  OutputFcn and PlotFcns call
        //  if haveoutputfcn || haveplotfcn
        //      callOutputAndPlotFcns(outputfcn,plotfcns,x,xOutputfcn,'done',itercount, func_evals, how, fval, varargin{:});
        //  end
        if (func_evals >= options_MaxFunEvals) {
          printMsg = (prnt > 0);

          // msg = getString(message('MATLAB:optimfun:fminsearch:ExitingMaxFunctionEvals', sprintf('%f',fval)));
          output.message.set_size(1, 35);
          for (i = 0; i < 35; i++) {
            output.message[i] = cv6[i];
          }

          b_index = 0;
        } else if (itercount >= options_MaxIter) {
          printMsg = (prnt > 0);

          // msg = getString(message('MATLAB:optimfun:fminsearch:ExitingMaxIterations', sprintf('%f',fval)));
          output.message.set_size(1, 31);
          for (i = 0; i < 31; i++) {
            output.message[i] = cv7[i];
          }

          b_index = 0;
        } else {
          printMsg = (prnt > 1);
          coder::b_sprintf(options_TolX, options_TolFun, output.message);
          b_index = 1;
        }

        output.iterations = itercount;
        output.funcCount = func_evals;
        for (i = 0; i < 33; i++) {
          output.algorithm[i] = cv3[i];
        }

        if (printMsg) {
          coder::b_sprintf(output.message, r);
          triggerEvent(r);
        }
      }
    }

    exitflag = b_index;
    return fval;
  }
}

// End of code generation (fMinSearch.cpp)
