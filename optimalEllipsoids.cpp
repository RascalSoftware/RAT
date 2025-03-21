//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// optimalEllipsoids.cpp
//
// Code generation for function 'optimalEllipsoids'
//

// Include files
#include "optimalEllipsoids.h"
#include "all.h"
#include "calcEllipsoid.h"
#include "rt_nonfinite.h"
#include "splitEllipsoid.h"
#include "coderException.hpp"
#include "coder_array.h"
#include <algorithm>

// Function Declarations
namespace RAT
{
  static void d_binary_expand_op(boolean_T in1_data[], const double in2_data[],
    const int in2_size[2], const double in3_data[], const int in3_size[2], const
    ::coder::array<double, 2U> &in4, int in1_size[2]);
}

// Function Definitions
namespace RAT
{
  static void d_binary_expand_op(boolean_T in1_data[], const double in2_data[],
    const int in2_size[2], const double in3_data[], const int in3_size[2], const
    ::coder::array<double, 2U> &in4, int in1_size[2])
  {
    int b_in2_size[2];
    int aux_0_1;
    int aux_1_1;
    int aux_2_1;
    int b_loop_ub;
    int loop_ub;
    int stride_0_0;
    int stride_0_1;
    int stride_1_0;
    int stride_1_1;
    int stride_2_0;
    int stride_2_1;
    boolean_T b_in2_data;
    if (in4.size(0) == 1) {
      if (in3_size[0] == 1) {
        loop_ub = in2_size[0];
      } else {
        loop_ub = in3_size[0];
      }
    } else {
      loop_ub = in4.size(0);
    }

    b_in2_size[0] = loop_ub;
    if (in4.size(1) == 1) {
      if (in3_size[1] == 1) {
        b_loop_ub = in2_size[1];
      } else {
        b_loop_ub = in3_size[1];
      }
    } else {
      b_loop_ub = in4.size(1);
    }

    b_in2_size[1] = b_loop_ub;
    stride_0_0 = (in2_size[0] != 1);
    stride_0_1 = (in2_size[1] != 1);
    stride_1_0 = (in3_size[0] != 1);
    stride_1_1 = (in3_size[1] != 1);
    stride_2_0 = (in4.size(0) != 1);
    stride_2_1 = (in4.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    aux_2_1 = 0;
    for (int i{0}; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        b_in2_data = (in2_data[i1 * stride_0_0 + in2_size[0] * aux_0_1] +
                      in3_data[i1 * stride_1_0 + in3_size[0] * aux_1_1] < in4[i1
                      * stride_2_0 + in4.size(0) * aux_2_1]);
      }

      aux_2_1 += stride_2_1;
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }

    coder::all((const boolean_T *)&b_in2_data, b_in2_size, in1_data, in1_size);
  }

  void optimalEllipsoids(const ::coder::array<double, 2U> &u, double VS, ::coder::
    array<double, 2U> &Bs, ::coder::array<double, 2U> &mus, ::coder::array<
    double, 2U> &VEs, ::coder::array<double, 2U> &ns)
  {
    static const char b_cv1[76]{ 'N', 'S', ' ', 'E', 'r', 'r', 'o', 'r', ':',
      ' ', 'F', 'a', 'i', 'l', 'e', 'd', ' ', 't', 'o', ' ', 'c', 'a', 'l', 'c',
      'u', 'l', 'a', 't', 'e', ' ', 'b', 'o', 'u', 'n', 'd', 'i', 'n', 'g', ' ',
      'e', 'l', 'l', 'i', 'p', 's', 'o', 'i', 'd', '.', ' ', 'C', 'o', 'n', 's',
      'i', 'd', 'e', 'r', ' ', 'i', 'n', 'c', 'r', 'e', 'a', 's', 'i', 'n', 'g',
      ' ', 'n', 'L', 'i', 'v', 'e', '.' };

    ::coder::array<double, 2U> B1;
    ::coder::array<double, 2U> B2;
    ::coder::array<double, 2U> VE1;
    ::coder::array<double, 2U> VE2;
    ::coder::array<double, 2U> mu;
    ::coder::array<double, 2U> mu1;
    ::coder::array<double, 2U> mu2;
    ::coder::array<double, 2U> n1;
    ::coder::array<double, 2U> n2;
    ::coder::array<double, 2U> u1;
    ::coder::array<double, 2U> u2;
    double VE1_data;
    double VE2_data;
    double flag;
    double nosplit;
    int VE1_size[2];
    int VE2_size[2];
    int b_VE1_size[2];
    char b_cv[76];
    boolean_T tmp_data;

    //  Optimally partition the samples u into a set of subclusters enclosed by ellipsoids.
    //
    //  Parameters
    //  ----------
    //  u : array
    //      The points to enclose in subclusters.
    //  VS : float
    //      The minimum volume of the set of ellipsoids.
    //
    //  Returns
    //  -------
    //  Bs : array
    //      An array of bounding matrices for the ellipsoids enclosing
    //      the subclusters, scaled to have at least the minimum volume
    //      required by the subclusters. ( (K x ndims) x ndims )
    //  mus : array
    //      An array of centroids for the bounding ellipsoids. (K x ndims)
    //  VEs : array
    //      An array of volumes for the bounding ellipsoids. (K x 1)
    //  ns : array
    //      An array containing the number of points for each subcluster. (K x 1)
    //
    //  Notes
    //  -----
    //  This is Algorithm 1 in the paper:
    //    Feroz, F.; Hobson, M.P.; Bridges, M. (2008),
    //    "MULTINEST: an efficient and robust Bayesian inference tool for cosmology and particle physics".
    //    DOI: `10.1111/j.1365-2966.2009.14548.x <https://doi.org/10.1111/j.1365-2966.2009.14548.x>`_,
    //    URL: https://arxiv.org/abs/0809.3437
    //
    //  number of samples in multi-dimensional space
    //  number of dimensions
    //  calculate bounding matrix, etc. for bounding ellipsoid associated
    //  with the original set of points u
    VEs.reserve(1);
    flag = calcEllipsoid(u, VS, Bs, mu, (double *)VEs.data(), VEs.size());
    if (flag != 0.0) {
      //  Ensures a proper exception is thrown in the generated C++ code.
      //  The arguments should be the errorCode integer, error message as a char array (which can be a formatspec)
      //  and other parameters if message is a formatspec.
      //
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type is not supported')
      //  coderException(coderEnums.errorCodes.invalidOption, 'The model type "%s" is not supported', modelType)
      std::copy(&b_cv1[0], &b_cv1[76], &b_cv[0]);
      coderException(2.0, &b_cv[0]);
    }

    //  attempt to split u into two subclusters
    nosplit = splitEllipsoid(u, VS, u1, u2, (double *)&VE1_data, VE1_size,
      (double *)&VE2_data, VE2_size);
    if ((nosplit != 0.0) || (static_cast<unsigned int>(u1.size(0)) <
         static_cast<unsigned int>(u.size(1)) + 1U) || (static_cast<unsigned int>
         (u2.size(0)) < static_cast<unsigned int>(u.size(1)) + 1U)) {
      int input_sizes_idx_0;

      //  couldn't split the cluster
      mus.set_size(mu.size(0), mu.size(1));
      input_sizes_idx_0 = mu.size(1);
      for (int i{0}; i < input_sizes_idx_0; i++) {
        int loop_ub;
        loop_ub = mu.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          mus[mus.size(0) * i] = mu[mu.size(0) * i];
        }
      }

      ns.set_size(1, 1);
      ns[0] = u.size(0);
    } else {
      int tmp_size[2];
      int i;
      int i1;
      int input_sizes_idx_0;
      int loop_ub;
      boolean_T empty_non_axis_sizes;
      boolean_T guard1;

      //  check if we should keep the partitioning of S
      // if (all(VE1 + VE2 < VE) || all(VE > 2*VS))
      if (VE1_size[0] == 1) {
        i = VE2_size[0];
      } else {
        i = VE1_size[0];
      }

      if (VE1_size[1] == 1) {
        i1 = VE2_size[1];
      } else {
        i1 = VE1_size[1];
      }

      if ((VE1_size[0] == VE2_size[0]) && (VE1_size[1] == VE2_size[1]) && (i ==
           VEs.size(0)) && (i1 == VEs.size(1))) {
        b_VE1_size[0] = VE1_size[0];
        b_VE1_size[1] = VE1_size[1];
        input_sizes_idx_0 = VE1_size[1];
        for (i = 0; i < input_sizes_idx_0; i++) {
          loop_ub = VE1_size[0];
          for (i1 = 0; i1 < loop_ub; i1++) {
            empty_non_axis_sizes = (VE1_data + VE2_data < VEs[0]);
          }
        }

        coder::all((const boolean_T *)&empty_non_axis_sizes, b_VE1_size,
                   (boolean_T *)&tmp_data, tmp_size);
      } else {
        d_binary_expand_op((boolean_T *)&tmp_data, (const double *)&VE1_data,
                           VE1_size, (const double *)&VE2_data, VE2_size, VEs,
                           tmp_size);
      }

      guard1 = false;
      if (coder::b_all((const boolean_T *)&tmp_data, tmp_size)) {
        guard1 = true;
      } else {
        VE1_data = 2.0 * VS;
        b_VE1_size[0] = VEs.size(0);
        b_VE1_size[1] = VEs.size(1);
        input_sizes_idx_0 = VEs.size(1);
        for (i = 0; i < input_sizes_idx_0; i++) {
          loop_ub = VEs.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            empty_non_axis_sizes = (VEs[i1 + VEs.size(0) * i] > VE1_data);
          }
        }

        coder::all((const boolean_T *)&empty_non_axis_sizes, b_VE1_size,
                   (boolean_T *)&tmp_data, tmp_size);
        if (coder::b_all((const boolean_T *)&tmp_data, tmp_size)) {
          guard1 = true;
        } else {
          mus.set_size(mu.size(0), mu.size(1));
          input_sizes_idx_0 = mu.size(1);
          for (i = 0; i < input_sizes_idx_0; i++) {
            loop_ub = mu.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              mus[mus.size(0) * i] = mu[mu.size(0) * i];
            }
          }

          ns.set_size(1, 1);
          ns[0] = u.size(0);
        }
      }

      if (guard1) {
        int result;
        int sizes_idx_0;
        short b_input_sizes_idx_0;
        optimalEllipsoids(u1, static_cast<double>(u1.size(0)) * VS /
                          static_cast<double>(u.size(0)), B1, mu1, VE1, n1);
        optimalEllipsoids(u2, static_cast<double>(u2.size(0)) * VS /
                          static_cast<double>(u.size(0)), B2, mu2, VE2, n2);
        tmp_data = ((B1.size(0) != 0) && (B1.size(1) != 0));
        if (tmp_data) {
          result = B1.size(1);
        } else if ((B2.size(0) != 0) && (B2.size(1) != 0)) {
          result = B2.size(1);
        } else {
          result = B1.size(1);
          if (B2.size(1) > B1.size(1)) {
            result = B2.size(1);
          }
        }

        empty_non_axis_sizes = (result == 0);
        if (empty_non_axis_sizes || tmp_data) {
          input_sizes_idx_0 = B1.size(0);
        } else {
          input_sizes_idx_0 = 0;
        }

        if (empty_non_axis_sizes || ((B2.size(0) != 0) && (B2.size(1) != 0))) {
          sizes_idx_0 = B2.size(0);
        } else {
          sizes_idx_0 = 0;
        }

        Bs.set_size(input_sizes_idx_0 + sizes_idx_0, result);
        for (i = 0; i < result; i++) {
          for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
            Bs[i1 + Bs.size(0) * i] = B1[i1 + input_sizes_idx_0 * i];
          }

          for (i1 = 0; i1 < sizes_idx_0; i1++) {
            Bs[(i1 + input_sizes_idx_0) + Bs.size(0) * i] = B2[i1 + sizes_idx_0 *
              i];
          }
        }

        tmp_data = ((mu1.size(0) != 0) && (mu1.size(1) != 0));
        if (tmp_data) {
          result = mu1.size(1);
        } else if ((mu2.size(0) != 0) && (mu2.size(1) != 0)) {
          result = mu2.size(1);
        } else {
          result = mu1.size(1);
          if (mu2.size(1) > mu1.size(1)) {
            result = mu2.size(1);
          }
        }

        empty_non_axis_sizes = (result == 0);
        if (empty_non_axis_sizes || tmp_data) {
          b_input_sizes_idx_0 = static_cast<short>(mu1.size(0));
        } else {
          b_input_sizes_idx_0 = 0;
        }

        if (empty_non_axis_sizes || ((mu2.size(0) != 0) && (mu2.size(1) != 0)))
        {
          sizes_idx_0 = mu2.size(0);
        } else {
          sizes_idx_0 = 0;
        }

        loop_ub = b_input_sizes_idx_0;
        mus.set_size(b_input_sizes_idx_0 + sizes_idx_0, result);
        for (i = 0; i < result; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            mus[i1 + mus.size(0) * i] = mu1[i1 + b_input_sizes_idx_0 * i];
          }

          for (i1 = 0; i1 < sizes_idx_0; i1++) {
            mus[(i1 + b_input_sizes_idx_0) + mus.size(0) * i] = mu2[i1 +
              sizes_idx_0 * i];
          }
        }

        tmp_data = ((VE1.size(0) != 0) && (VE1.size(1) != 0));
        if (tmp_data) {
          result = VE1.size(1);
        } else if ((VE2.size(0) != 0) && (VE2.size(1) != 0)) {
          result = VE2.size(1);
        } else {
          result = VE1.size(1);
          if (VE2.size(1) > VE1.size(1)) {
            result = VE2.size(1);
          }
        }

        empty_non_axis_sizes = (result == 0);
        if (empty_non_axis_sizes || tmp_data) {
          input_sizes_idx_0 = VE1.size(0);
        } else {
          input_sizes_idx_0 = 0;
        }

        if (empty_non_axis_sizes || ((VE2.size(0) != 0) && (VE2.size(1) != 0)))
        {
          sizes_idx_0 = VE2.size(0);
        } else {
          sizes_idx_0 = 0;
        }

        VEs.set_size(input_sizes_idx_0 + sizes_idx_0, result);
        for (i = 0; i < result; i++) {
          for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
            VEs[i1 + VEs.size(0) * i] = VE1[i1 + input_sizes_idx_0 * i];
          }

          for (i1 = 0; i1 < sizes_idx_0; i1++) {
            VEs[(i1 + input_sizes_idx_0) + VEs.size(0) * i] = VE2[i1 +
              sizes_idx_0 * i];
          }
        }

        tmp_data = ((n1.size(0) != 0) && (n1.size(1) != 0));
        if (tmp_data) {
          result = n1.size(1);
        } else if ((n2.size(0) != 0) && (n2.size(1) != 0)) {
          result = n2.size(1);
        } else {
          result = (n1.size(1) > 0);
          if (n2.size(1) > result) {
            result = 1;
          }
        }

        empty_non_axis_sizes = (result == 0);
        if (empty_non_axis_sizes || tmp_data) {
          b_input_sizes_idx_0 = static_cast<short>(n1.size(0));
        } else {
          b_input_sizes_idx_0 = 0;
        }

        if (empty_non_axis_sizes || ((n2.size(0) != 0) && (n2.size(1) != 0))) {
          sizes_idx_0 = n2.size(0);
        } else {
          sizes_idx_0 = 0;
        }

        loop_ub = b_input_sizes_idx_0;
        ns.set_size(b_input_sizes_idx_0 + sizes_idx_0, result);
        for (i = 0; i < result; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            ns[i1 + ns.size(0) * i] = n1[i1 + b_input_sizes_idx_0 * i];
          }

          for (i1 = 0; i1 < sizes_idx_0; i1++) {
            ns[(i1 + b_input_sizes_idx_0) + ns.size(0) * i] = n2[i1 +
              sizes_idx_0 * i];
          }
        }
      }
    }
  }
}

// End of code generation (optimalEllipsoids.cpp)
