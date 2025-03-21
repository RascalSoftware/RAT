//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// multrnd.cpp
//
// Code generation for function 'multrnd'
//

// Include files
#include "multrnd.h"
#include "combineVectorElements.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "coderException.hpp"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const double in3_data[], int in4);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const double in3_data[], int in4)
  {
    ::coder::array<double, 2U> b_in1;
    double in3;
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    in3 = in3_data[in4];
    if (in2.size(1) == 1) {
      loop_ub = in1.size(1);
    } else {
      loop_ub = in2.size(1);
    }

    b_in1.set_size(1, loop_ub);
    stride_0_1 = (in1.size(1) != 1);
    stride_1_1 = (in2.size(1) != 1);
    for (int i{0}; i < loop_ub; i++) {
      b_in1[i] = in1[i * stride_0_1] + static_cast<double>(in2[i * stride_1_1] >
        in3);
    }

    in1.set_size(1, b_in1.size(1));
    loop_ub = b_in1.size(1);
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = b_in1[i];
    }
  }

  void multrnd(double n, const double p_data[], const int p_size[2], double
               X_data[], int X_size[2])
  {
    static const char b_cv1[29]{ 'n', ' ', 'm', 'u', 's', 't', ' ', 'b', 'e',
      ' ', 'a', ' ', 'p', 'o', 's', 'i', 't', 'i', 'v', 'e', ' ', 'i', 'n', 't',
      'e', 'g', 'e', 'r', '.' };

    ::coder::array<double, 2U> b_p_data;
    ::coder::array<double, 2U> o;
    ::coder::array<double, 2U> r;
    ::coder::array<boolean_T, 2U> b_o;
    double s_data[3];
    double P;
    int loop_ub_tmp;

    //   Created by A. Trujillo-Ortiz, R. Hernandez-Walls and A. Castro-Perez
    //              Facultad de Ciencias Marinas
    //              Universidad Autonoma de Baja California
    //              Apdo. Postal 453
    //              Ensenada, Baja California
    //              Mexico.
    //              atrujo@uabc.mx
    //   Copyright (C) January 12, 2005.
    //
    //   To cite this file, this would be an appropriate format:
    //   Trujillo-Ortiz, A., R. Hernandez-Walls and A. Castro-Perez. (2005). multrnd:
    //     Multinomial random sequence. A MATLAB file. [WWW document]. URL http://
    //     www.mathworks.com/matlabcentral/fileexchange/loadFile.do?objectId=6788
    //
    //   References:
    //
    //   Abramowitz, M. and Stegun,I. A. (1964), Handbook of Mathematical
    //            Functions, Government Printing Office, 26.1.20. Available on
    //            Internet at the URL address http://hcohl.shell42.com/as/frameindex.htm
    //
    //  Generate a multinomial random sequence of m simulations of k outcomes with p probhabilities.
    //
    //  Y = MULTRND(N,P,M) generates a random sequence of m simulations of k integers from a
    //  multinomial distribution with n trials and k outcomes, where the probability for each
    //  simulation is,
    //
    //  .. math:: \frac{n!}{n_1 ! n_2 ! ... n_k !} p_1^{n_1} p_2^{n_2} ... p_k^{n_k}
    //
    //  Then, a single sample {n1, n2,  . . .  , nk} have a multinomial joint distribution with
    //  parameters n and p1, p2,  . . .  , pk. The parameter n is called the number of trials;
    //  the parameters p1, p2,  . . .  , pk are called the category probabilities; k is called
    //  the number of categories.
    //
    //  Parameters
    //  ----------
    //  n : array
    //      The number of trials for each simulation.
    //  p : array
    //      The associated probability for each simulation.
    //  m : int
    //      The number of simulations.
    //
    //  Returns
    //  -------
    //  X : array
    //      The multinomial random deviates.
    //  Y : array
    //      The multinomial probabilities of each random deviate.
    //
    //  Examples
    //  --------
    //  >>> [X Y] = multrnd(2678, [0.1 0.06 0.7 0.14], 10)
    //   X =
    //          271         152        1873         382
    //          249         154        1890         385
    //          266         172        1862         378
    //          290         147        1882         359
    //          247         153        1873         405
    //          291         155        1842         390
    //          268         141        1900         369
    //          248         158        1899         373
    //          267         181        1855         375
    //          259         175        1884         360
    //   Y =
    //          0.1012    0.0568    0.6994    0.1426
    //          0.0930    0.0575    0.7058    0.1438
    //          0.0993    0.0642    0.6953    0.1412
    //          0.1083    0.0549    0.7028    0.1341
    //          0.0922    0.0571    0.6994    0.1512
    //          0.1087    0.0579    0.6878    0.1456
    //          0.1001    0.0527    0.7095    0.1378
    //          0.0926    0.0590    0.7091    0.1393
    //          0.0997    0.0676    0.6927    0.1400
    //          0.0967    0.0653    0.7035    0.1344
    //
    if ((std::trunc(n) != n) || (n < 0.0)) {
      char b_cv[29];

      //  Ensures a proper exception is thrown in the generated C++ code.
      //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
      //  and other parameters if message is a formatspec.
      //
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
      for (int i{0}; i < 29; i++) {
        b_cv[i] = b_cv1[i];
      }

      coderException(2.0, &b_cv[0]);
    }

    b_p_data.set((double *)&p_data[0], p_size[0], p_size[1]);
    P = coder::sum(b_p_data);

    // if P ~= 1,
    //     error('The sum of the input probabilities must be equal 1.')
    //     return,
    // end;
    loop_ub_tmp = static_cast<int>(n);
    o.set_size(1, loop_ub_tmp);
    for (int i{0}; i < loop_ub_tmp; i++) {
      o[i] = 1.0;
    }

    s_data[0] = p_data[0] / P;
    s_data[1] = p_data[1] / P;
    s_data[2] = p_data[2] / P;
    s_data[1] += s_data[0];
    s_data[2] += s_data[1];
    coder::b_rand(n, r);
    for (int j{0}; j < 3; j++) {
      loop_ub_tmp = o.size(1);
      if (o.size(1) == r.size(1)) {
        o.set_size(1, o.size(1));
        for (int i{0}; i < loop_ub_tmp; i++) {
          o[i] = o[i] + static_cast<double>(r[i] > s_data[j]);
        }
      } else {
        binary_expand_op(o, r, s_data, j);
      }
    }

    X_size[0] = 1;
    X_size[1] = 3;
    loop_ub_tmp = o.size(1);
    for (int j{0}; j < 3; j++) {
      b_o.set_size(1, o.size(1));
      for (int i{0}; i < loop_ub_tmp; i++) {
        b_o[i] = (o[i] == static_cast<double>(j) + 1.0);
      }

      X_data[j] = coder::combineVectorElements(b_o);
    }
  }
}

// End of code generation (multrnd.cpp)
